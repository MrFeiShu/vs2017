// DialogEx.cpp : implementation file
//

#include "stdafx.h"
#include <DialogEx.h>
#include <Global.h>
#include <xImageOperation.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define RES_PIC_BACKGROUND				"Background_Normal.bmp"
#define RES_PIC_LOGO					"Logo.png"
#define RES_PIC_LOGO_PURE				"Logo_Pure.png"
#define RES_PIC_CLOSE_NORMAL_NEXT		"Close_Normal_Next.png"
#define RES_PIC_CLOSE_NORMAL_MAIN		"Close_Normal_Main.png"
#define RES_PIC_CLOSE_HOVER_NEXT		"Close_Hover_Next.png"
#define RES_PIC_CLOSE_HOVER_MAIN		"Close_Hover_Main.png"

#define TEXT_HELP						"帮助"
#define TEXT_TITLE						"网银助手"

#define BORDER_WIDTH					1					//画笔的长度

/////////////////////////////////////////////////////////////////////////////
// CDialogEx dialog
#define TIMER_ID_SET_ACTIVE_WINDOW (1)

CDialogEx::CDialogEx(UINT nIDTemplate, CWnd* pParent /* = NULL */)
: CDialog(nIDTemplate, pParent)
{
	//{{AFX_DATA_INIT(CDialogEx)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_dWidgetType		= WIDGET_TYPE_ALL;   //默认标题栏全部出现：图标(2)、关闭按钮(1)
	m_bEnableEsc		= FALSE;
	m_bDrawClosePic		= FALSE;
	m_bEnableAltF4		= FALSE;
	m_bVirtualDlgExist	= FALSE;

#ifdef _ES_SETUP_
	m_bLogoType		= FALSE;
	m_strImgPath = TEXT(RES_PIC_BACKGROUND); //默认打开首页
#endif
#ifdef _ES_MANAGER_
	m_bLogoType		= TRUE;
#endif
#ifdef _ES_UI_
	m_bLogoType		= TRUE;
	m_bActiveWindow	= TRUE;
	m_bEnableMoved	= TRUE;
#endif
}

CDialogEx::~CDialogEx()
{
	m_LabelHelp.DestroyWindow();
	m_LabelTitle.DestroyWindow();
}

void CDialogEx::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDialogEx)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDialogEx, CDialog)
	//{{AFX_MSG_MAP(CDialogEx)
	ON_WM_ERASEBKGND()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_HELPINFO()	
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
#ifdef _ES_MANAGER_
	ON_WM_CLOSE()
	ON_WM_PAINTCLIPBOARD()
#endif
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDialogEx message handlers
BOOL CDialogEx::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
#ifdef _ES_UI_
	if (m_bActiveWindow)
	{
		SetTimer(TIMER_ID_SET_ACTIVE_WINDOW, 500, NULL);
	}
#endif
	return FALSE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

// draw title bar
void CDialogEx::DrawTitleBar(CDC* pDC, BOOL bCalcRect)
{
	CRect		rtClient(0, 0, 0, 0);
	CRect		rtLogo(0, 0, 0, 0);
	CRect		rtClose(0, 0, 0, 0);
	CRect		rtHelp(0, 0, 0, 0);
	CRect		rtTitleText(0, 0, 0, 0);
	const int	nLeftOffset = 8;
	const int	nRightOffset = 10;
	const int	nTopOffset = 16;
	
	if ( NULL == pDC )
	{
		return;
	}
	
	if (!::IsWindow(m_hWnd))
	{
		return;
	}

	GetClientRect(&rtClient);
 	
	// 重画Logo
	const int nWidth = 108;
	const int nHeight = 18;

	rtLogo.left =  rtClient.left + nLeftOffset;
	rtLogo.top = rtClient.top + nTopOffset;
	rtLogo.right = rtLogo.left + nWidth;
	rtLogo.bottom = rtLogo.top +nHeight;
	if (!m_bVirtualDlgExist)
	{
		if ( !bCalcRect )
		{
			CString imgPath;
			if (m_bLogoType)
			{
				imgPath = TEXT(RES_PIC_LOGO);
			}
			else
			{
				imgPath = TEXT(RES_PIC_LOGO_PURE);
			}
#ifdef _ES_SETUP_
			imgPath = m_strUninstallTempPath + imgPath;
#endif
			DrawPicture(pDC, rtLogo, imgPath);
		}
	}
	
	// close
	if ( 0 != (m_dWidgetType & WIDGET_TYPE_CLOSE))
	{
		const int nWidth = 16;
		const int nHeight = 16;

		rtClose.right = rtClient.right - nRightOffset;
		rtClose.left = rtClose.right - nWidth;
		rtClose.top = rtClient.top + nTopOffset;
		rtClose.bottom = rtClose.top + nHeight;

		if ( !bCalcRect )
		{
			CString imgPath;
			if (m_bLogoType)
			{
				// 白色背景下
				imgPath = TEXT(RES_PIC_CLOSE_NORMAL_NEXT);
			}
			else
			{
				imgPath = TEXT(RES_PIC_CLOSE_NORMAL_MAIN);
			}

			if (m_bDrawClosePic)
			{
				if (m_bLogoType)
				{
					// 白色背景下
					imgPath = TEXT(RES_PIC_CLOSE_HOVER_NEXT);
				}
				else
				{
					imgPath = TEXT(RES_PIC_CLOSE_HOVER_MAIN);
				}	
			}

#ifdef _ES_SETUP_
			imgPath = m_strUninstallTempPath + imgPath;
#endif
			DrawPicture(pDC, rtClose, imgPath);
		}
	}
	
	// help
	if ( 0 != (m_dWidgetType & WIDGET_TYPE_HELP))
	{
		const int nWidth = 32;
		const int nHeight = 18;

		if ( rtClose.Width() > 0 )
		{
			rtHelp.right = rtClient.right - rtClose.Width() - nRightOffset - 20; // 20 是间隔
		}
		else
		{
			rtHelp.right = rtClient.right - nRightOffset;
		}
		rtHelp.top = rtClient.top + nTopOffset;
		rtHelp.left = rtHelp.right - nWidth;
		rtHelp.bottom = rtHelp.top + nHeight;

#ifndef _ES_MANAGER_
		m_LabelHelp.SetWindowText(_T(TEXT_HELP));
#endif
		m_LabelHelp.MoveWindow(rtHelp);
	}
	 
	// title
	if ( 0 != (m_dWidgetType & WIDGET_TYPE_TITLE))
	{
		const int	nHeight = 18;
		
		rtTitleText.top = rtClient.top + nTopOffset;
		rtTitleText.bottom = rtTitleText.top + nHeight;
		if ( rtLogo.Width() > 0 )
		{
			rtTitleText.left = rtClient.left + rtLogo.right + 4;
		}
		else
		{
			rtTitleText.left = rtClient.left + nLeftOffset;
		}

		if ( rtHelp.Width() > 0 )
		{
			rtTitleText.right = rtHelp.left - 6;
		}
		else
		{
			if ( rtClose.Width() > 0 )
			{
				rtTitleText.right = rtClose.left - 6;
			}
			else
			{
				rtTitleText.right = rtClient.right - nRightOffset;
			}
		}

		m_LabelTitle.MoveWindow(rtTitleText);
	}

	m_rectClose = rtClose;
	m_rectHelp = rtHelp;
}

void CDialogEx::SetBackground(const CString &imagePath, BOOL bInvalidate)  // 设置背景
{
	if (imagePath.GetLength() > 0)
	{
		m_strImgPath = imagePath;
	}
	else
	{
		m_strImgPath = TEXT("");
	}
	if ( bInvalidate )
	{
		Invalidate(FALSE);
	}
}

void CDialogEx::SetTitle(const CString& strTitle)        //设置标题
{
	SetWindowText(strTitle);
	m_LabelTitle.SetWindowText(strTitle);
}

void CDialogEx::DrawPicture(CDC* pDC, CRect &rect, CString &imgPath)
{
	CImageOperation objImgOp;	
#if 1
#ifdef _ES_SETUP_
	objImgOp.DrawImage(pDC, rect, imgPath, 0, FALSE);
#else
	objImgOp.DrawImage(pDC, rect, imgPath, 0, TRUE);
#endif
#else
	CDC		BKdc;
	CBitmap BmpMem, *pOldBmp;
	CRect	rectTemp;
	
	// 拷贝窗口所在区域的背景
	BKdc.CreateCompatibleDC(pDC);
	BmpMem.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBmp = (CBitmap*)BKdc.SelectObject(&BmpMem);
	BKdc.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, rect.left, rect.top, SRCCOPY);
	
	rectTemp.left = rectTemp.top = 0;
	rectTemp.bottom = rect.Height();
	rectTemp.right = rect.Width();
	objImgOp.DrawImage(&BKdc, rectTemp, imgPath, 0, FALSE);
		
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &BKdc, 0, 0, rect.Width(), rect.Height(), SRCCOPY);
	BKdc.SelectObject(pOldBmp);
	BmpMem.DeleteObject();
	BKdc.DeleteDC();

#endif
}

BOOL CDialogEx::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CImageOperation		objImgOp;
	CxImageOperation	objxImgOp;
	CRect				rect;
	GetClientRect(&rect);
	if ( m_strImgPath.GetLength() > 0 )
	{
		if (m_bVirtualDlgExist)
		{
			
			objxImgOp.DrawImage(pDC, rect, m_strImgPath, ImageModeScaleAspectFill);
			return TRUE;
		}
#ifdef _ES_SETUP_
		objImgOp.DrawImage(pDC, rect, m_strImgPath, 0, FALSE);
#else
		objImgOp.DrawImage(pDC, rect, m_strImgPath, 0, TRUE);
#endif
	}
	else
	{
		CPen			pen;
		CPen*			pOldPen;
		const int		nPenWidth = BORDER_WIDTH;
		
		pen.CreatePen(PS_INSIDEFRAME | PS_SOLID, nPenWidth, RGB(153, 153, 153));
		pOldPen = (CPen*)pDC->SelectObject(&pen);
		
		RoundRect(pDC->GetSafeHdc(), rect.left, rect.top, rect.right, rect.bottom, 0, 0);
		pDC->SelectObject(pOldPen);
		pen.DeleteObject();
		
		// 减去边框的大小
		rect.DeflateRect(nPenWidth, nPenWidth);
		pDC->FillSolidRect(rect.left, rect.top, rect.Width(), rect.Height(), RGB(250, 250, 250));

		pOldPen->DeleteObject();
	}

	DrawTitleBar(pDC, FALSE);

	return TRUE;
}

void CDialogEx::OnPaintClipboard(CWnd* pClipAppWnd, HGLOBAL hPaintStruct) 
{
	// TODO: Add your message handler code here and/or call default
	
	CDialog::OnPaintClipboard(pClipAppWnd, hPaintStruct);
}

void CDialogEx::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	static BOOL bFlag = FALSE;

	// 关闭button
	if ( 0 != (m_dWidgetType & WIDGET_TYPE_CLOSE))
	{
		if (m_rectClose.PtInRect(point))
		{
			m_bDrawClosePic = TRUE;
		}
		else
		{
			m_bDrawClosePic = FALSE;
		}
		
		if ( (m_bDrawClosePic&&!bFlag) || (!m_bDrawClosePic&&bFlag) )
		{
			CRect rtTemp = m_rectClose;
			InvalidateRect(&rtTemp, TRUE);
		}
		bFlag = m_bDrawClosePic;
	}
}

void CDialogEx::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (
#ifdef _ES_UI_
	m_bEnableMoved && 
#endif
	!m_rectClose.PtInRect(point) && !m_rectHelp.PtInRect(point))
	{
		CRect rc;
		
		GetClientRect(&rc);
		if ( rc.bottom > TITLEBAR_HEIGHT )	// 限制只有标题栏区域可以移动
		{
			rc.bottom = TITLEBAR_HEIGHT;
		}
		if ( rc.PtInRect(point) )
		{
			// 让虚拟的标题栏区域能响应鼠标移动
			ReleaseCapture();
			SendMessage(WM_NCLBUTTONDOWN, HTCAPTION, 0); //SendMessage(WM_SYSCOMMAND, 0xF012, 0);
		}
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CDialogEx::OpenHelpLink()
{
	CString str = L"https://www.mybank.cn/index.htm";
	LPTSTR strPtr = (LPTSTR)(LPCTSTR)str;
	STARTUPINFO si = {sizeof(si)};
	PROCESS_INFORMATION pi;
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = 1;
	BOOL bRect = ::CreateProcess(NULL, strPtr, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	if(bRect)
	{
		::CloseHandle(pi.hProcess);
		::CloseHandle(pi.hThread);
	}
}

void CDialogEx::SetFocusInput()
{

}

int CDialogEx::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;
	// TODO: Add your specialized creation code here
	m_LabelHelp.Create(TEXT(TEXT_HELP), WS_VISIBLE|SS_CENTERIMAGE|SS_RIGHT, CRect(0,0,0,0), this);
	m_LabelHelp.SetFont(15);
	m_LabelHelp.SetTextColor(RGB(255, 255, 255));

	m_LabelTitle.Create(TEXT(TEXT_TITLE), WS_VISIBLE|SS_CENTERIMAGE|SS_LEFT, CRect(0,0,0,0), this);
	m_LabelTitle.SetFont(16);
	m_LabelTitle.SetTextColor(RGB(255, 255, 255));
	if ( m_bLogoType )
	{
		m_LabelTitle.SetTextColor(RGB(0, 0, 0));
	}
	return 0;
}

BOOL CDialogEx::OnHelpInfo(HELPINFO* pHelpInfo) 
{
	// TODO: Add your message handler code here and/or call default
	
	return TRUE;
}

void CDialogEx::ShowDialog(int nCmdShow)
{
	ShowWindow(nCmdShow);
}

BOOL CDialogEx::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(WM_KEYDOWN == pMsg->message)
	{
		if(pMsg->wParam == VK_RETURN)
		{
			CWnd *wnd = GetFocus();
			SendMessage(WM_COMMAND, wnd->GetDlgCtrlID(), (LPARAM)wnd->m_hWnd);
			return TRUE;
		}
		if ( VK_ESCAPE == pMsg->wParam && !m_bEnableEsc )
		{
			return TRUE;
		}
	}
	if (WM_SYSKEYDOWN == pMsg->message)
	{
		if ( VK_F4 == pMsg->wParam && !m_bEnableAltF4)
		{
			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}

void CDialogEx::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (m_rectClose.PtInRect(point))
	{
		if( 0 != (m_dWidgetType & WIDGET_TYPE_CLOSE))
		{
			if( 0 != (m_dWidgetType & WIDGET_TYPE_CLOSE))
			{		
#ifndef _ES_MANAGER_
				PostMessage(WM_CLOSE);
#else
#ifdef _DEBUG
				PostMessage(WM_CLOSE);
#else
				ShowDialog(SW_HIDE);
				m_bDrawClosePic = FALSE;
#endif
#endif
			}
		}
	}
	else if(m_rectHelp.PtInRect(point))
	{
		if(0 != (m_dWidgetType & WIDGET_TYPE_HELP))
		{
			OpenHelpLink();
		}
	}
	CDialog::OnLButtonUp(nFlags, point);
}

void CDialogEx::OnTimer(UINT nIDEvent)
{
#ifdef _ES_UI_
	switch (nIDEvent)
	{
	case TIMER_ID_SET_ACTIVE_WINDOW:
		{
			SetActiveWindow();
			KillTimer(TIMER_ID_SET_ACTIVE_WINDOW);
		}
		break;
	}
#endif
	CDialog::OnTimer(nIDEvent);
}

// 窗口居中显示
void CDialogEx::CenterDialog()
{
	CRect	rtWorkArea;
	int		s4X = 0;
	int		s4Y = 0;
	
	if ( SystemParametersInfo(SPI_GETWORKAREA, NULL, &rtWorkArea, NULL) )
	{
		CRect	rtApp;
		GetClientRect(&rtApp);
		s4X = ( rtWorkArea.Width() - rtApp.Width() ) / 2;
		s4Y = ( rtWorkArea.Height() - rtApp.Height() ) / 2;
		
		::SetWindowPos( GetSafeHwnd(), HWND_TOPMOST, s4X,s4Y,0,0, SWP_NOSIZE|SWP_NOZORDER );
	}
}