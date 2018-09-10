///////////////////////////////////////////////////////////////////////////////

#include "StdAfx.h"
#include <xImageOperation.h>
#include <XColorStatic.h>
#include <EsCommon/EsCommon.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

///////////////////////////////////////////////////////////////////////////////
// CXColorStatic

BEGIN_MESSAGE_MAP(CXColorStatic, CStatic)
	//{{AFX_MSG_MAP(CXColorStatic)
	ON_WM_PAINT()
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CXColorStatic::CXColorStatic()
{
	m_crText = GetSysColor(COLOR_BTNTEXT);
// 	m_rgbBackground = GetSysColor(COLOR_BTNFACE);
// 	m_pBrush        = new CBrush(m_rgbBackground);
	m_bBold = FALSE;
	m_hIcon = NULL;
	m_nXMargin = m_nYMargin = 0;
	m_bTransparent = TRUE;
	m_pFontName	= CGetFontName::GetSingleInstance();
}

CXColorStatic::~CXColorStatic()
{
	if (m_font.GetSafeHandle())
	{
		m_font.DeleteObject();
	}

	if (m_bkBrush.GetSafeHandle())
	{
		m_bkBrush.DeleteObject();
	}
}

void CXColorStatic::PreSubclassWindow() 
{
	CStatic::PreSubclassWindow();

	// get current font
	CFont* pFont = GetFont();
	if (!pFont)
	{
		HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
		if ( NULL == hFont )
		{
			hFont = (HFONT) GetStockObject(ANSI_VAR_FONT);
		}
		if (hFont)
		{
			pFont = CFont::FromHandle(hFont);
		}
	}
	ASSERT(pFont);
	ASSERT(pFont->GetSafeHandle());

	// create the font for this control
	pFont->GetLogFont(&m_lf);
	if ( NULL != m_pFontName)
	{
		CString strFontName;
		m_pFontName->GetFontName(strFontName);
		_tcsncpy(m_lf.lfFaceName, strFontName, sizeof(m_lf.lfFaceName)/sizeof(TCHAR)-1);
	}
	m_font.CreateFontIndirect(&m_lf);
	
	CStatic::GetWindowText(m_strText);
}

///////////////////////////////////////////////////////////////////////////////
// OnPaint
void CXColorStatic::OnPaint() 
{
	CPaintDC	dc(this); // device context for painting
	
	Draw();
}

///////////////////////////////////////////////////////////////////////////////
// SetFont
void CXColorStatic::SetFont(LOGFONT *pLogFont)
{
	ASSERT(pLogFont);
	if (!pLogFont)
		return;

	if (m_font.GetSafeHandle())
		m_font.DeleteObject();

	m_lf = *pLogFont;

	m_lf.lfWeight = m_bBold ? FW_BOLD : FW_NORMAL;

	m_font.CreateFontIndirect(&m_lf);

	RefreshSelf();
}

///////////////////////////////////////////////////////////////////////////////
// SetFont
void CXColorStatic::SetFont(UINT nSize)
{
	// null face name is ok - we will use current font
	memset(&m_lf, 0, sizeof(m_lf));

	if ( NULL == m_pFontName )
	{
		ASSERT(m_font.GetSafeHandle());
		m_font.GetLogFont(&m_lf);
	}
	else
	{
		CString strFontName;
		m_pFontName->GetFontName(strFontName);
		_tcsncpy(m_lf.lfFaceName, strFontName, sizeof(m_lf.lfFaceName)/sizeof(TCHAR)-1);
	}
	m_lf.lfHeight = (-1*nSize);

	SetFont(&m_lf);
}

///////////////////////////////////////////////////////////////////////////////
// SetFont
void CXColorStatic::SetFont(CFont *pFont)
{
	ASSERT(pFont);
	if (!pFont)
		return;

	memset(&m_lf, 0, sizeof(m_lf));

	pFont->GetLogFont(&m_lf);

	if ( NULL != m_pFontName)
	{
		CString strFontName;
		m_pFontName->GetFontName(strFontName);
		_tcsncpy(m_lf.lfFaceName, strFontName, sizeof(m_lf.lfFaceName)/sizeof(TCHAR)-1);
	}
	SetFont(&m_lf);
}

void CXColorStatic::SetFontItalic(BOOL bItalic)
{
	
	memset(&m_lf, 0, sizeof(m_lf));
	m_font.GetLogFont(&m_lf);
	
	if ( bItalic )
	{
		m_lf.lfItalic = 1;
	}
	else
	{
		m_lf.lfItalic = 0;
	}
	
	SetFont(&m_lf);
}

///////////////////////////////////////////////////////////////////////////////
// SetTextColor
void CXColorStatic::SetTextColor(COLORREF rgb) 
{ 
	m_crText = rgb; 
	RefreshSelf();
}

///////////////////////////////////////////////////////////////////////////////
// SetBold
void CXColorStatic::SetBold(BOOL bFlag)
{ 
	m_bBold = bFlag;

	memset(&m_lf, 0, sizeof(m_lf));

	CFont *pFont = GetFont();
	ASSERT(pFont);
	pFont->GetLogFont(&m_lf);

	m_lf.lfWeight = m_bBold ? FW_BOLD : FW_NORMAL;

	SetFont(&m_lf);
}

///////////////////////////////////////////////////////////////////////////////
// SetBackgroundColor
void CXColorStatic::SetBkColor(COLORREF rgb, BOOL bTransparent/* = TRUE*/) 
{
	m_bTransparent = bTransparent;
	if (m_bkBrush.GetSafeHandle())
	{
		m_bkBrush.DeleteObject();
	}
	if ( !bTransparent )
	{
		m_bkBrush.CreateSolidBrush(rgb);
	}

 	RefreshSelf();
}

///////////////////////////////////////////////////////////////////////////////
// SetIcon
void CXColorStatic::SetIcon(HICON hIcon)
{
	if ( NULL == hIcon )
	{
		DestroyIcon(m_hIcon);
		m_hIcon = NULL;
	}
	else
	{
		m_hIcon = hIcon;
		m_strImageFileName = _T("");
	}
	RefreshSelf();
}

// SetImage
void CXColorStatic::SetImage(const CString& strName)
{
	m_strImageFileName = strName;
	if ( m_strImageFileName.GetLength() > 0 )
	{
		if ( m_hIcon != NULL )
		{
			DestroyIcon(m_hIcon);
			m_hIcon = NULL;
		}
	}

	RefreshSelf();
}

void CXColorStatic::SetMargins(int x, int y)
{
	m_nXMargin = x;
	m_nYMargin = y;
	RefreshSelf();
}

// 貌似可以等同于strText.GetLength()
// 先留着吧
int CXColorStatic::GetCStringCharCount(CString& strText)
{
#ifdef UNICODE
	return strText.GetLength();
#else
	if ( 0 == strText.GetLength() )
	{
		return 0;
	}

	// > 0
	int			nCount = 0;
	BYTE		u1Char = 0;
	const char*	pszText = strText.GetBuffer(strText.GetLength());

	if ( NULL == pszText )
	{
		return 0;
	}
	
	u1Char = *(BYTE*)pszText;
	while (u1Char!=0x00)
	{
		if ( ::IsDBCSLeadByte(u1Char) )
		{
			nCount+=2;
			pszText+=2;
		}
		else
		{
			nCount++;
			pszText++;
		}
		u1Char = *(BYTE*)pszText;
	}

	strText.ReleaseBuffer();

	return nCount;
#endif
}

LRESULT CXColorStatic::DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
	case WM_MOVE:
		RefreshSelf();
		break;
	case WM_SETTEXT:
		{
			// 上层额外维护text
			m_strText = ( NULL == lParam ) ? _T("") : (LPCTSTR)lParam;
			RefreshSelf();

			return 0;
		}
		break;
	case WM_GETTEXTLENGTH:
		return GetCStringCharCount(m_strText); // 返回字符个数。挺坑的，UNICODE下两字节才是一个字符，ANSI下一字节一个字符
	case WM_GETTEXT:
		{
			if ( NULL == lParam || (long)wParam <= m_strText.GetLength() )
			{
				return -1;
			}
			
			// 自行维护text
			_tcscpy((LPTSTR)lParam, m_strText);
			return 0;
		}
		break;
 	}
	
	return CStatic::DefWindowProc(message, wParam, lParam);
}

BOOL CXColorStatic::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	pDC = pDC; // set unused
	return TRUE;//CStatic::OnEraseBkgnd(pDC);
}

// 1. 刷新父窗口对应的区域是一种方法
// 2. 自身隐藏再显示也能让父窗口重绘这片区域
// 3. 两种方法各有利弊
// 4. 当然，如果是非透明背景，那就刷新自己就行啦
// 5. 如果自己是隐藏的，还刷新个鬼啊
void CXColorStatic::RefreshSelf()
{
	if ( !IsWindowVisible() )
	{
		return;
	}

	if ( !m_bTransparent )
	{
		Invalidate(FALSE);
		return;
	}

#ifdef REFRESH_BY_INVALIDATE_PARENT
	CRect	rect;
	CWnd*	pParent = GetParent();
	
	if (  pParent )
	{
		GetWindowRect(&rect);			
		pParent->ScreenToClient(&rect); // 调用父窗口的ScreenToClient
		pParent->InvalidateRect(&rect, TRUE);
		
		return;
	}
	
	Invalidate(FALSE);
#else
	ShowWindow(SW_HIDE);
	ShowWindow(SW_SHOW);
#endif
	
	return;
}

int CXColorStatic::GetTextLine(HDC hDC, const CString& str, SIZE& maxSize)
{
	// 思路，查找分行符，如果只有一行，则直接返回
	int		i;
	int		j;
	int		nRet;
	int		nLen;
	int		n;
	int		nMaxLen;
	CString strTemp;
	SIZE	sizeTemp;
	
	i = 0;
	j = 0;
	nRet = 1;
	nLen = str.GetLength();
	if ( 0 == nLen ) // 没有数据
	{
		return 0;
	}
	n = str.Find(_T("\n"), 0);
	
	if ( n == -1 )
	{
		nMaxLen = nLen;
		GetTextExtentPoint32(hDC, str, nMaxLen, &maxSize);
		return nRet;
	}
	nRet++;
	nMaxLen = n;
	AfxExtractSubString(strTemp, str, nRet - 2, '\n');     // 获取每行字符串
	GetTextExtentPoint32(hDC, strTemp, nMaxLen, &maxSize);  
	sizeTemp.cx = maxSize.cx;
	sizeTemp.cy = maxSize.cy;
	
	for ( i = n; i < nLen;)
	{
		j = str.Find(_T("\n"), i+1);
		if ( -1 == j )
		{
			if ( nMaxLen < nLen - n - 2 + nRet)
			{
				nMaxLen = nLen - n - 2 + nRet;
			}
			AfxExtractSubString(strTemp, str, nRet - 1, '\n');     // 获取每行字符串
			GetTextExtentPoint32(hDC, strTemp, nMaxLen, &sizeTemp); 
			goto END;
		}
		if ( j - n - 2 + nRet > nMaxLen )
		{
			nMaxLen = j - n - 2 + nRet;
		}
		nRet++;
		n = j;
		i = j;
		
		AfxExtractSubString(strTemp, str, nRet - 2, '\n');     // 获取每行字符串
		GetTextExtentPoint32(hDC, strTemp, nMaxLen, &sizeTemp); 
		if ( sizeTemp.cx > maxSize.cx )
		{
			maxSize.cx = sizeTemp.cx;
		}
		if ( maxSize.cy < sizeTemp.cy )
		{
			maxSize.cy = sizeTemp.cy;
		}
	}
END:
	if ( sizeTemp.cx > maxSize.cx )
	{
		maxSize.cx = sizeTemp.cx;
	}
	if ( maxSize.cy < sizeTemp.cy )
	{
		maxSize.cy = sizeTemp.cy;
	}
	return nRet;
}

BOOL CXColorStatic::Draw()
{
	CDC*		pDC = GetDC();
	CDC			memDC;
	CBitmap		memBmp;
	CBitmap*	pOldBmp;
	CRect		rect;
	int			nSaveDC;
	DWORD		dwStyle = GetStyle();
	CString		strText = m_strText;
	CRect		rectText;
	UINT		nFormat = 0;

	if ( NULL == pDC )
	{
		return FALSE;
	}

	nSaveDC = pDC->SaveDC();
	
	GetClientRect(rect); 
	
	memDC.CreateCompatibleDC(pDC);
	memBmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	pOldBmp = (CBitmap*)memDC.SelectObject(&memBmp);
	memDC.PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY); // 清除背景
	memDC.BitBlt(0, 0, rect.Width(), rect.Height(), pDC, rect.left, rect.top, SRCCOPY); // 拷贝父窗口对应位置的内容
	
	memDC.SetTextColor(m_crText);
	memDC.SetBkMode(TRANSPARENT);
	
	if ( !m_bTransparent && m_bkBrush.GetSafeHandle() )
	{
		memDC.FillRect(rect, &m_bkBrush);
	}

	// cannot have both an icon and text
	
	if ( m_hIcon != NULL || m_strImageFileName.GetLength() > 0 )
	{
		const int nOffsetX = 2;
		const int nOffsetY = 2;
		rectText = CRect(0,0,0,0);

		if ( m_strText.GetLength() > 0 && (dwStyle & SS_CENTERIMAGE) )
		{
			// 居中单行模式才画
			memDC.SelectObject(&m_font);
			
			m_nXMargin = m_nYMargin = 0;

			SIZE	maxSize;
			int		nIconX;
			int		nIconY;
			POINT	pt = {0,0};

			GetTextLine(memDC.GetSafeHdc(), strText, maxSize);
			nIconX = (maxSize.cy * 5)/4;
			if ( nIconX > rect.Height() )
			{
				nIconX = rect.Height();
			}
			nIconY = nIconX;

			rectText = rect;
			if (dwStyle & SS_CENTER)
			{
				// 居中对齐: 图标+文字
				dwStyle &= ~SS_CENTER;
				dwStyle |= SS_LEFT;
				if ( maxSize.cx > (rect.Width()-2*nOffsetX-nIconX) )
				{
					// 超出
					pt.x = nOffsetX;
					pt.y = rect.top + (rect.Height() - nIconY) / 2 + nOffsetY;
					
					rectText.left = rect.left + pt.x + nIconX + nOffsetX;
				}
				else
				{
					pt.x = rect.left + (rect.Width() - maxSize.cx - nOffsetX - nIconX)/2;
					pt.y = rect.top + (rect.Height() - nIconY) / 2 + nOffsetY;

					rectText.left = pt.x + nOffsetX + nIconX;
				}
			}
			else if (dwStyle & SS_RIGHT)
			{
				// 右对齐: 文字+图标
				pt.x = rect.right - nOffsetX - nIconX;
				pt.y = rect.top + (rect.Height() - nIconY) / 2 + nOffsetY;

				rectText.right = pt.x - nOffsetX;
			}
			else
			{
				// 左对齐: 图标+文字
				pt.x = nOffsetX;
				pt.y = rect.top + (rect.Height() - nIconY) / 2 + nOffsetY;
				
				rectText.left = rect.left + pt.x + nIconX + nOffsetX;
			}
			if ( m_hIcon != NULL )
			{
				DrawIconEx(memDC.GetSafeHdc(), pt.x, pt.y, m_hIcon, nIconX, nIconY, 0, NULL, DI_NORMAL);
			}
			else
			{
				CxImageOperation img;
				CRect rt(pt.x,pt.y,pt.x+nIconX,pt.y+nIconY);
				img.DrawImage(&memDC, rt, m_strImageFileName, ImageModeZoomOutAspectFit);
			}
		}
		else
		{
			int		nIconX = ::GetSystemMetrics(SM_CXICON);
			int		nIconY = ::GetSystemMetrics(SM_CYICON);
			POINT	pt = {0,0};
			
			pt.x = rect.left + (rect.Width() - nIconX) / 2;
			pt.y = rect.top + (rect.Height() - nIconY) / 2;
			
			memDC.DrawIcon(pt, m_hIcon);
		}
	}
	else
	{
		rectText = rect;
	}

	if ( rectText.Width() > 0 && rectText.Height() > 0 && strText.GetLength() > 0 )
	{
		memDC.SelectObject(&m_font);
		
		// set DrawText format from static style settings
		if (dwStyle & SS_CENTERIMAGE)	// vertical centering ==> single line only
		{
			nFormat |= DT_VCENTER | DT_SINGLELINE;
		}
		else
		{
			nFormat |= DT_WORDBREAK;
		}
		if (dwStyle & SS_CENTER)
		{
			nFormat |= DT_CENTER;
		}
		else if (dwStyle & SS_RIGHT)
		{
			nFormat |= DT_RIGHT;
		}
		else
		{
			nFormat |= DT_LEFT;
		}
		
		rectText.left += m_nXMargin;
		rectText.top  += m_nYMargin;
		
		memDC.DrawText(strText, rectText, nFormat);
	}
	
	// 复制到真实DC中
	pDC->StretchBlt(rect.left, rect.top, rect.Width(), rect.Height(), &memDC, 0, 0, rect.Width(), rect.Height(), SRCCOPY);
	pDC->RestoreDC(nSaveDC);
	
	// 清理
	memDC.SelectObject(pOldBmp);
	memDC.DeleteDC();
	memBmp.DeleteObject();

	ReleaseDC(pDC);

	return TRUE;
}


BOOL CXColorStatic::ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags/* = 0*/)
{
	if ( !CStatic::ModifyStyle(dwRemove, dwAdd, nFlags|SWP_DRAWFRAME) )
	{
		return FALSE;
	}
	
	RefreshSelf();
	return TRUE;
}

BOOL CXColorStatic::ModifyStyleEx(DWORD dwRemove, DWORD dwAdd, UINT nFlags/* = 0*/)
{
	if ( !CStatic::ModifyStyleEx(dwRemove, dwAdd, nFlags|SWP_DRAWFRAME) )
	{
		return FALSE;
	}
	
	RefreshSelf();
	return TRUE;
}

int CXColorStatic::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	if ( NULL == lpCreateStruct || NULL == lpCreateStruct->lpszName )
	{
		m_strText = _T("");
	}
	else
	{
		m_strText = lpCreateStruct->lpszName;
	}

	return 0;
}
