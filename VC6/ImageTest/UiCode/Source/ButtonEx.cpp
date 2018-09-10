// ButtonEx.cpp : implementation file
//
#include "Stdafx.h"
#include <ButtonEx.h>
#include <Image.h>
#include <Global.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define BTN_MAJOR								0					// 主按钮
#define BTN_MINOR								1					// 次按钮
#define BTN_CLOSE								2					// 关闭按钮
#define BTN_UNINSTALL							3					// 卸载按钮

#define BTN_STATE_NORMAL						0					//正常
#define BTN_STATE_HOVER							1					//划过
#define BTN_STATE_ACTIVE						2					//点击
#define BTN_STATE_SELECTED						3					//选择
#define BTN_STATE_DISABLE						4					//禁止

const COLORREF g_DLGBK_COLOR_1[5] = {RGB(0, 194, 194), RGB(51, 205, 205), RGB(0, 184, 184), RGB(51, 205, 205), RGB(227, 227, 227)};
const COLORREF g_DLGBK_COLOR_2[5] = {RGB(255,255,255), RGB(204,243,243), RGB(153, 231, 231), RGB(204,243,243), RGB(227, 227, 227)};
const COLORREF g_DLGBK_COLOR_3[5] = {RGB(250,253,254), RGB(250,253,254), RGB(250, 253, 254), RGB(250,253,254), RGB(250, 253, 254)};
const COLORREF g_DLGBK_COLOR_1_BORDER[5] = {RGB(0, 194, 194), RGB(51, 205, 205), RGB(0, 184, 184), RGB(51, 205, 205), RGB(227, 227, 227)};
const COLORREF g_DLGBK_COLOR_2_BORDER[5] = {RGB(0,194,194), RGB(0,214,214), RGB(0, 162, 162), RGB(0, 162, 162), RGB(227, 227, 227)};
const COLORREF g_DLGBK_COLOR_3_BORDER[5] = {RGB(250,253,254), RGB(250,253,254), RGB(250, 253, 254), RGB(250,253,254), RGB(250, 253, 254)};
const COLORREF g_DLGBK_COLOR_1_TEXT[5] = {RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255), RGB(255, 255, 255)};
const COLORREF g_DLGBK_COLOR_2_TEXT[5] = {RGB(0, 194, 194), RGB(0, 194, 194), RGB(0, 194, 194), RGB(0, 194, 194), RGB(255, 255, 255)};
const COLORREF g_DLGBK_COLOR_3_TEXT[5] = {RGB(162, 163, 165), RGB(130, 130, 130), RGB(162, 163, 165), RGB(130, 130, 130), RGB(162, 163, 165)};
// 边框宽度
#define BORDER_WIDTH 1	
// 圆角宽度
#define CORNER_WIDTH 2
/////////////////////////////////////////////////////////////////////////////
// CButtonEx

CButtonEx::CButtonEx()
{
	FreeResources(FALSE);

	m_DownTime = 0;

	m_u4BtnStateIndex = 0;
	m_nBtnType = BTN_MAJOR;

	m_bEnable = TRUE;
	m_bOver = m_bSelected = m_bTracking = m_bFocus = m_bDown = FALSE;
	m_bSetBitmap = FALSE;

	m_pFontName	= CGetFontName::GetSingleInstance();
	m_pFont = new CFont;

	m_bBtnEnable = TRUE;

}

CButtonEx::~CButtonEx()
{
	if ( m_Bitmaps[0].hBitmap)
	{
		DeleteObject(m_Bitmaps[0].hBitmap);
	}
	if (m_Bitmaps[1].hBitmap)
	{
		DeleteObject(m_Bitmaps[1].hBitmap);
	}
	if (NULL != m_pFont)
	{
		if (m_pFont->GetSafeHandle())
		{
			m_pFont->DeleteObject();
		}
		delete	m_pFont;
		m_pFont = NULL;
	}
}

BEGIN_MESSAGE_MAP(CButtonEx, CButton)
	//{{AFX_MSG_MAP(CButtonEx)
	ON_WM_MOUSEMOVE()
	ON_MESSAGE(WM_MOUSELEAVE, OnMouseLeave)
	ON_MESSAGE(WM_MOUSEHOVER, OnMouseHover)
	ON_WM_ERASEBKGND()
	ON_WM_TIMER()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CButtonEx message handlers

//添加Owner Draw属性
void CButtonEx::PreSubclassWindow() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	CButton::PreSubclassWindow();
	ModifyStyle(0, BS_OWNERDRAW);
	//设置按钮的有效区域,去掉残角
	if ( !m_bSetBitmap)
	{
		CRgn rgn;
		CRect rc;
		GetClientRect(&rc);
		
		//有效区域为一个角半径为2的圆角矩形
		rgn.CreateRoundRectRgn(rc.left,rc.top,rc.right,rc.bottom,CORNER_WIDTH,CORNER_WIDTH);
		
		SetWindowRgn(rgn,TRUE);
		rgn.DeleteObject();
	}
}

void CButtonEx::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if (!m_bTracking)
	{
		TRACKMOUSEEVENT tme;
		tme.cbSize = sizeof(tme);
		tme.hwndTrack = m_hWnd;
		tme.dwFlags = TME_LEAVE | TME_HOVER;
		tme.dwHoverTime = 1;
		m_bTracking = _TrackMouseEvent(&tme);
	}
	
	CButton::OnMouseMove(nFlags, point);
}

LRESULT CButtonEx::OnMouseLeave(WPARAM wParam, LPARAM lParam)
{
	m_bOver = FALSE;
	m_bTracking = FALSE;
	if (m_bFocus || !m_bBtnEnable)
	{
		return 0;
	}
	InvalidateRect(NULL, FALSE);

	return 0;
}

LRESULT CButtonEx::OnMouseHover(WPARAM wParam, LPARAM lParam)
{
	m_bOver = TRUE;
	if (m_bFocus || !m_bBtnEnable)
	{
		return 0;
	}
	InvalidateRect(NULL, FALSE);

	return 0;
}

void CButtonEx::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	//从lpDrawItemStruct获取控件的相关信息
	CRect	rect =  lpDrawItemStruct->rcItem;
	CDC*	pDC=CDC::FromHandle(lpDrawItemStruct->hDC);
	int		nSaveDC = pDC->SaveDC();
	UINT	state = lpDrawItemStruct->itemState;
	TCHAR	tszText[MAX_PATH+1];

	::GetWindowText(m_hWnd, tszText, MAX_PATH);

	//获取按钮的状态
    m_bEnable = ( state & ODS_DISABLED ) ? FALSE : TRUE;
	if (state & ODS_FOCUS)
	{
		m_bFocus = TRUE;
		m_bSelected = TRUE;
	}
	else
	{
		m_bFocus = FALSE;
		m_bSelected = FALSE;
	}
	
	if (state & ODS_SELECTED || state & ODS_DEFAULT)
	{
		m_bFocus = TRUE;
	}
	
	//获取按钮状态
	GetBtnState();
	
	if ( !m_bBtnEnable )
	{
		m_u4BtnStateIndex = BTN_STATE_DISABLE;
	}

	if ( !m_bSetBitmap )
	{
		rect.DeflateRect(CSize(GetSystemMetrics(SM_CXEDGE), GetSystemMetrics(SM_CYEDGE)));

		//根据按钮的状态填充按钮的底色
		DoGradientFill(pDC, &rect);
	}
	else
	{
		rect = lpDrawItemStruct->rcItem;
		pDC->SetBkMode(TRANSPARENT);
		CRect rcTmp = rect;
		if ( m_bOver || m_bTracking)
		{
			//DrawBitmapBK(pDC, rcTmp, m_crColors[0]);
			DrawBK(pDC, rcTmp);
			DrawBitmaps(pDC, rcTmp, 0, m_Bitmaps[0].dwWidth, m_Bitmaps[0].dwHeight);
			// 画周围的虚框
		
			rcTmp = rect;
			rcTmp.right = rect.left +1;
			DrawBitmapBK(pDC, rcTmp, RGB(175,222,248));  // 左

			rcTmp = rect;
			rcTmp.bottom = rect.top +1;
			DrawBitmapBK(pDC, rcTmp, RGB(175,222,248));  // 上

			rcTmp = rect;
			rcTmp.left = rect.right -1;
			DrawBitmapBK(pDC, rcTmp, RGB(175,222,248));  // 右
			
			rcTmp = rect;
			rcTmp.top = rect.bottom -1;
			DrawBitmapBK(pDC, rcTmp, RGB(175,222,248));  // 下RGB(210,210,210)			
		}
		else
		{
			//DrawBitmapBK(pDC, rect, m_crColors[1]);
			if ( m_Bitmaps[1].hBitmap )
			{
				DrawBitmaps(pDC, rect, 1, m_Bitmaps[1].dwWidth, m_Bitmaps[1].dwHeight);
			}
		}
	}
	//显示按钮的文本
	if (tszText!=NULL)
	{
		rect = lpDrawItemStruct->rcItem;
		CFont*	hFont = GetFont();
		CFont*	hOldFont = pDC->SelectObject(hFont);
		SIZE	sizeExtent;
		COLORREF clrText;

		if ( BTN_MAJOR == m_nBtnType )
		{
			clrText = g_DLGBK_COLOR_1_TEXT[m_u4BtnStateIndex];
		} 
		else if ( BTN_MINOR == m_nBtnType)
		{
			clrText = g_DLGBK_COLOR_2_TEXT[m_u4BtnStateIndex];
		}
		else
		{
			clrText = g_DLGBK_COLOR_3_TEXT[m_u4BtnStateIndex];
		}
		pDC->SetTextColor(clrText);

		GetTextExtentPoint32(pDC->m_hDC, tszText, lstrlen(tszText), &sizeExtent);
		CPoint pt( (rect.Width() - sizeExtent.cx) / 2, (rect.Height() - sizeExtent.cy) / 2);
		if (m_bDown) 
			pt.Offset(1, 1);
		int nMode = pDC->SetBkMode(TRANSPARENT);
		if (state & ODS_DISABLED)
		{
			pDC->DrawState(pt, sizeExtent, tszText, DSS_DISABLED, TRUE, 0, (HBRUSH)NULL);
		}
		else
		{
			pDC->DrawState(pt, sizeExtent, tszText, DSS_NORMAL, TRUE, 0, (HBRUSH)NULL);
		}
		pDC->SelectObject(hOldFont);
		pDC->SetBkMode(nMode);
	}
	
	pDC->RestoreDC(nSaveDC);
}

// 绘制位图
void CButtonEx::DrawBitmaps(CDC* pDC, CRect rtBtn, int nIndex, DWORD dwWidth, DWORD dwHeight)
{
	HDC			hdcBmpMem	= NULL;
	HBITMAP		hbmOldBmp	= NULL;
	HDC			hdcMem		= NULL;
	HBITMAP		hbmT		= NULL;
	
	hdcBmpMem = ::CreateCompatibleDC(pDC->m_hDC);
	hbmOldBmp = (HBITMAP)::SelectObject(hdcBmpMem, m_Bitmaps[nIndex].hBitmap);
	hdcMem = ::CreateCompatibleDC(NULL);
	hbmT = (HBITMAP)::SelectObject(hdcMem, m_Bitmaps[nIndex].hMask);

	pDC->SetStretchBltMode(HALFTONE);
	pDC->SetBrushOrg(0, 0);

	::StretchBlt(pDC->m_hDC, rtBtn.left+1, rtBtn.top+1, rtBtn.Width()-2, rtBtn.Height()-2, hdcMem, 0, 0, dwWidth, dwHeight, SRCAND);
	::StretchBlt(pDC->m_hDC, rtBtn.left+1, rtBtn.top+1, rtBtn.Width()-2, rtBtn.Height()-2, hdcBmpMem, 0, 0, dwWidth, dwHeight, SRCPAINT);

// 	::BitBlt(pDC->m_hDC, rtBtn.left, rtBtn.top, rtBtn.Width(), rtBtn.Height(), hdcMem, 0, 0, SRCAND);
// 	::BitBlt(pDC->m_hDC, rtBtn.left, rtBtn.top, rtBtn.Width(), rtBtn.Height(), hdcBmpMem, 0, 0, SRCPAINT);

	::SelectObject(hdcMem, hbmT);
	::DeleteDC(hdcMem);
	
	::SelectObject(hdcBmpMem, hbmOldBmp);
	::DeleteDC(hdcBmpMem);

}

DWORD CButtonEx::DrawBitmapBK(CDC* pDC, LPCRECT pRect, COLORREF crColor)
{
	CBrush		brBackground(crColor);
	
	pDC->FillRect(pRect, &brBackground);
	
	return BTN_OK;
} // End of OnDrawBackground

//绘制按钮的底色
void CButtonEx::DoGradientFill(CDC *pDC, CRect* pRect)
{
	//绘制按钮背景
	CBrush brBorder, brBK, *pOldBrush;
	CPen cpBorder, cpBK, *pOldPen;
	CRect rct;
	int iZoom = 1;
	COLORREF clrBK, clrBorder;

	rct.left = pRect->left + iZoom;
	rct.right = pRect->right - iZoom;
	rct.top = pRect->top + iZoom;
	rct.bottom = pRect->bottom - iZoom;

	if ( BTN_MAJOR == m_nBtnType )
	{
		clrBorder = g_DLGBK_COLOR_1_BORDER[m_u4BtnStateIndex];
		clrBK = g_DLGBK_COLOR_1[m_u4BtnStateIndex];
	}
	else if ( BTN_MINOR == m_nBtnType)
	{
		clrBorder = g_DLGBK_COLOR_2_BORDER[m_u4BtnStateIndex];
		clrBK = g_DLGBK_COLOR_2[m_u4BtnStateIndex];
	}
	else
	{
		clrBorder = g_DLGBK_COLOR_3_BORDER[m_u4BtnStateIndex];
		clrBK = g_DLGBK_COLOR_3[m_u4BtnStateIndex];
 		//return;   //直接返回时，按钮将以界面的背景为背景
	}

	// 画一个边框颜色的圆角矩形框
	cpBorder.CreatePen(PS_INSIDEFRAME | PS_SOLID, BORDER_WIDTH, clrBorder);
	pOldPen = pDC->SelectObject(&cpBorder);
	brBorder.CreateSolidBrush(clrBorder);
	pOldBrush = pDC->SelectObject(&brBorder);
	pDC->RoundRect(pRect, CPoint(CORNER_WIDTH, CORNER_WIDTH));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

	// 再画一个小iZoom个点的圆角矩形框，两个框叠在一起，小框没有遮住大框的部分作为边框
	cpBK.CreatePen(PS_INSIDEFRAME | PS_SOLID, BORDER_WIDTH, clrBK);
	pOldPen = pDC->SelectObject(&cpBK);
	brBK.CreateSolidBrush(clrBK);	
	pOldBrush = pDC->SelectObject(&brBK);
	pDC->RoundRect(&rct, CPoint(CORNER_WIDTH, CORNER_WIDTH));
	pDC->SelectObject(pOldPen);
	pDC->SelectObject(pOldBrush);

	brBorder.DeleteObject();
	brBK.DeleteObject();
	cpBorder.DeleteObject();
	cpBK.DeleteObject();

}

void CButtonEx::SetBtnType(UINT nBtnType)
{
	m_nBtnType = nBtnType;
	
	if( BTN_CLOSE == nBtnType )
	{
		m_bSetBitmap = TRUE;
	}
	else
	{
		m_bSetBitmap = FALSE;
	}
}

BOOL CButtonEx::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	return TRUE;
}

DWORD CButtonEx::SetBitmaps(int nBitmapIn, COLORREF crTransColorIn, int nBitmapOut, COLORREF crTransColorOut)
{
	HBITMAP		hBitmapIn		= NULL;
	HBITMAP		hBitmapOut		= NULL;
	HINSTANCE	hInstResource	= NULL;
	
	// Find correct resource handle
	hInstResource = AfxFindResourceHandle(MAKEINTRESOURCE(nBitmapIn), RT_BITMAP);
	
	// Load bitmap In
	hBitmapIn = (HBITMAP)::LoadImage(hInstResource, MAKEINTRESOURCE(nBitmapIn), IMAGE_BITMAP, 0, 0, 0);
	
	// Load bitmap Out
	if (nBitmapOut)
		hBitmapOut = (HBITMAP)::LoadImage(hInstResource, MAKEINTRESOURCE(nBitmapOut), IMAGE_BITMAP, 0, 0, 0);
	
	return SetBitmaps(hBitmapIn, crTransColorIn, hBitmapOut, crTransColorOut);
}

DWORD CButtonEx::SetBitmaps(HBITMAP hBitmapIn, COLORREF crTransColorIn, HBITMAP hBitmapOut, COLORREF crTransColorOut)
{
	int		nRetValue;
	BITMAP	csBitmapSize;
	
	// Free any loaded resource
	FreeResources();
	m_bSetBitmap = FALSE;
	if (hBitmapIn)
	{
		m_Bitmaps[0].hBitmap = hBitmapIn;
		m_Bitmaps[0].crTransparent = crTransColorIn;
		// Get bitmap size
		nRetValue = ::GetObject(hBitmapIn, sizeof(csBitmapSize), &csBitmapSize);
		if (nRetValue == 0)
		{
			FreeResources();
			return BTN_INVALIDRESOURCE;
		} // if
		m_Bitmaps[0].dwWidth = (DWORD)csBitmapSize.bmWidth;
		m_Bitmaps[0].dwHeight = (DWORD)csBitmapSize.bmHeight;
		
		// Create mask for bitmap In
		m_Bitmaps[0].hMask = CreateBitmapMask(hBitmapIn, m_Bitmaps[0].dwWidth, m_Bitmaps[0].dwHeight, crTransColorIn);
		if (m_Bitmaps[0].hMask == NULL)
		{
			FreeResources();
			return BTN_FAILEDMASK;
		} // if

		if (hBitmapOut)
		{
			m_Bitmaps[1].hBitmap = hBitmapOut;
			m_Bitmaps[1].crTransparent = crTransColorOut;
			// Get bitmap size
			nRetValue = ::GetObject(hBitmapOut, sizeof(csBitmapSize), &csBitmapSize);
			if (nRetValue == 0)
			{
				FreeResources();
				return BTN_INVALIDRESOURCE;
			} // if
			m_Bitmaps[1].dwWidth = (DWORD)csBitmapSize.bmWidth;
			m_Bitmaps[1].dwHeight = (DWORD)csBitmapSize.bmHeight;
			// Create mask for bitmap Out
			m_Bitmaps[1].hMask = CreateBitmapMask(hBitmapOut, m_Bitmaps[1].dwWidth, m_Bitmaps[1].dwHeight, crTransColorOut);
			if (m_Bitmaps[1].hMask == NULL)
			{
				FreeResources();
				return BTN_FAILEDMASK;
			} // if
		} // if
	} // if

	m_bSetBitmap = TRUE;
	Invalidate();
	
	return BTN_OK;
} // End of SetBitmaps

void CButtonEx::FreeResources(BOOL bCheckForNULL)
{
	if (bCheckForNULL)
	{
		// Destroy bitmaps
		if (m_Bitmaps[0].hBitmap)
		{
			::DeleteObject(m_Bitmaps[0].hBitmap);
		}
		if (m_Bitmaps[1].hBitmap)
		{
			::DeleteObject(m_Bitmaps[1].hBitmap);
		}
	} // if
	
	::ZeroMemory(&m_Bitmaps, sizeof(m_Bitmaps));
} // End of FreeResources


HBITMAP CButtonEx::CreateBitmapMask(HBITMAP hSourceBitmap, DWORD dwWidth, DWORD dwHeight, COLORREF crTransColor)
{
	HBITMAP		hMask		= NULL;
	HDC			hdcSrc		= NULL;
	HDC			hdcDest		= NULL;
	HBITMAP		hbmSrcT		= NULL;
	HBITMAP		hbmDestT	= NULL;
	COLORREF	crSaveBk;
	COLORREF	crSaveDestText;
	
	hMask = ::CreateBitmap(dwWidth, dwHeight, 1, 1, NULL);
	if (hMask == NULL)	return NULL;
	
	hdcSrc	= ::CreateCompatibleDC(NULL);
	hdcDest	= ::CreateCompatibleDC(NULL);
	
	hbmSrcT = (HBITMAP)::SelectObject(hdcSrc, hSourceBitmap);
	hbmDestT = (HBITMAP)::SelectObject(hdcDest, hMask);
	
	crSaveBk = ::SetBkColor(hdcSrc, crTransColor);
	
	::BitBlt(hdcDest, 0, 0, dwWidth, dwHeight, hdcSrc, 0, 0, SRCCOPY);
	
	crSaveDestText = ::SetTextColor(hdcSrc, RGB(255, 255, 255));
	::SetBkColor(hdcSrc,RGB(0, 0, 0));
	
	::BitBlt(hdcSrc, 0, 0, dwWidth, dwHeight, hdcDest, 0, 0, SRCAND);
	
	SetTextColor(hdcDest, crSaveDestText);
	
	::SetBkColor(hdcSrc, crSaveBk);
	::SelectObject(hdcSrc, hbmSrcT);
	::SelectObject(hdcDest, hbmDestT);
	
	::DeleteDC(hdcSrc);
	::DeleteDC(hdcDest);
	
	return hMask;
} // End of CreateBitmapMask


void CButtonEx::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if ( 1 == nIDEvent )
	{
		CString	strText(m_strText);
		CString	strTemp;
		
		strTemp.Format(_T("(%d)"), m_DownTime);
		strText += strTemp;
		SetWindowText(strText);
		m_DownTime--;
		if ( m_DownTime <= 0 )
		{
			KillTimer(1);
		}
	}
	CButton::OnTimer(nIDEvent);
}

void CButtonEx::DrawBK(CDC* pDC, CRect rect)
{ 
	CString strBitmapName = _T("ok.bmp");
	CImageOperation objImgOp;
	objImgOp.DrawImage(pDC, rect, strBitmapName);
}

void CButtonEx::GetBtnState()
{
	if ( m_bEnable )
	{		
		if ( m_bDown )
		{
			m_u4BtnStateIndex = BTN_STATE_ACTIVE;
		}
		else
		{
			if ( m_bFocus )
			{
				if ( m_bOver )
				{
					m_u4BtnStateIndex = BTN_STATE_HOVER;
				}
				else
				{
					m_u4BtnStateIndex = BTN_STATE_HOVER; // m_u4StateIndex = BTN_STATE_SELECT; 
				}
				
			}
			else
			{
				if ( m_bOver )
				{
					m_u4BtnStateIndex = BTN_STATE_HOVER;
				} 
				else
				{
					m_u4BtnStateIndex = BTN_STATE_NORMAL;
				}
			}
		}
	}
	else
	{
		m_u4BtnStateIndex = BTN_STATE_DISABLE;
	}
}

void CButtonEx::SetFontSize(int size)
{
	if (m_pFont->GetSafeHandle())
	{
		m_pFont->DeleteObject();
	}
	size *= -1;
	CString strFontName;
	if ( NULL == m_pFontName)
	{
		strFontName = _T("Tahoma");
	}
	else
	{
		m_pFontName->GetFontName(strFontName);
	}
	m_pFont->CreateFont(size, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, GB2312_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, strFontName);
	if (NULL != m_pFont)
	{
		SetFont(m_pFont);
	}
}

void CButtonEx::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if ( !m_bBtnEnable )
	{
		return;
	}
	
	m_bDown = TRUE;
	CButton::OnLButtonDown(nFlags, point);
}

void CButtonEx::SetBtnEnable(BOOL bEnable /* = TRUE */)
{
	m_bBtnEnable = bEnable;
	Invalidate(FALSE);
}

void CButtonEx::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if ( !m_bBtnEnable )
	{
		return;
	}
	
	m_bDown = FALSE;
	CButton::OnLButtonUp(nFlags, point);
}
