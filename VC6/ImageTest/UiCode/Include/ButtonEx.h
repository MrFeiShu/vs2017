#if !defined(AFX_BUTTONEX_H__44CD5B2A_756E_4939_9261_E0034E0F2DEF__INCLUDED_)
#define AFX_BUTTONEX_H__44CD5B2A_756E_4939_9261_E0034E0F2DEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ButtonEx.h : header file
//
// Return values
#ifndef	BTN_OK
#define	BTN_OK						0
#endif
#ifndef	BTN_INVALIDRESOURCE
#define	BTN_INVALIDRESOURCE			1
#endif
#ifndef	BTN_FAILEDMASK
#define	BTN_FAILEDMASK				2
#endif
#ifndef	BTN_INVALIDINDEX
#define	BTN_INVALIDINDEX				3
#endif
#ifndef	BTN_INVALIDALIGN
#define	BTN_INVALIDALIGN				4
#endif
#ifndef	BTN_BADPARAM
#define	BTN_BADPARAM					5
#endif

/////////////////////////////////////////////////////////////////////////////
// CButtonEx window
#include "GetFontName.h"

class CButtonEx : public CButton
{
// Construction
public:
	CButtonEx();

	// Attributes
protected:

	//按钮的状态
	BOOL m_bOver;	//鼠标位于按钮之上时该值为true，反之为flase
	BOOL m_bTracking;	//在鼠标按下没有释放时该值为true
	BOOL m_bSelected;	//按钮被按下是该值为true
	BOOL m_bFocus;	//按钮为当前焦点所在时该值为true
	BOOL m_bEnable; // 按钮为使能状态时该值为true
	BOOL m_bDown;

	UINT m_u4BtnStateIndex;
	UINT m_nBtnType; // button类型

	// 是否只显示位图
	BOOL m_bSetBitmap;
	// 颜色
	COLORREF m_crColors[2];	// Colors to be used

	int		m_DownTime;
	CString	m_strText;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CButtonEx)
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void DoGradientFill(CDC *pDC, CRect* pRect);
	virtual ~CButtonEx();
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CButtonEx)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMouseLeave(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnMouseHover(WPARAM wParam, LPARAM lParam);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	void GetBtnState();
	CGetFontName*	m_pFontName;
	CFont*			m_pFont;
	BOOL			m_bBtnEnable;

public:
	void FreeResources(BOOL bCheckForNULL = TRUE);
	DWORD SetBitmaps(int nBitmapIn, COLORREF crTransColorIn, int nBitmapOut, COLORREF crTransColorOut);
	DWORD SetBitmaps(HBITMAP nBitmapIn, COLORREF crTransColorIn, HBITMAP nBitmapOut, COLORREF crTransColorOut);
	void DrawBitmaps(CDC* pDC, CRect rtBtn, int nIndex, DWORD dwWidth, DWORD dwHeight);
	HBITMAP CreateBitmapMask(HBITMAP hSourceBitmap, DWORD dwWidth, DWORD dwHeight, COLORREF crTransColor);
	DWORD DrawBitmapBK(CDC* pDC, LPCRECT pRect, COLORREF crColor);
	void SetColor(COLORREF crColorIn, COLORREF crColorOut);
	void DrawBK(CDC* pDC, CRect rect);
	void SetBtnType(UINT nBtnType);
	void SetFontSize(int size);
	void SetBtnEnable(BOOL bEnable = TRUE); // TRUE:enable FALSE:disable

#pragma pack(1)
	typedef struct _STRUCT_BITMAPS
	{
		HBITMAP		hBitmap;		// Handle to bitmap
		DWORD		dwWidth;		// Width of bitmap
		DWORD		dwHeight;		// Height of bitmap
		HBITMAP		hMask;			// Handle to mask bitmap
		COLORREF	crTransparent;	// Transparent color
	} STRUCT_BITMAPS;
#pragma pack()
	STRUCT_BITMAPS	m_Bitmaps[2];

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BUTTONEX_H__44CD5B2A_756E_4939_9261_E0034E0F2DEF__INCLUDED_)
