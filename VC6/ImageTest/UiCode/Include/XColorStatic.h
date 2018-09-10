// XColorStatic.h  Version 1.0
//
// Author:  Hans Dietrich
//          hdietrich2@hotmail.com
//
// This software is released into the public domain.
// You are free to use it in any way you like.
//
// This software is provided "as is" with no expressed
// or implied warranty.  I accept no liability for any
// damage or loss of business that this software may cause.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef XCOLORSTATIC_H
#define XCOLORSTATIC_H

/////////////////////////////////////////////////////////////////////////////
// CXColorStatic window
#include "GetFontName.h"

class CXColorStatic : public CStatic
{
// Construction
public:
	CXColorStatic();
	virtual ~CXColorStatic();

// Attributes
public:
	void SetBkColor(COLORREF rgb, BOOL bTransparent = FALSE);
	void SetTextColor(COLORREF rgb);
	void SetBold(BOOL bFlag);
	void SetFont(UINT nSize);
	void SetFont(LOGFONT * pLogFont);
	void SetFont(CFont *pFont);
	void SetFontItalic(BOOL bItalic);
	void SetIcon(HICON hIcon);
	void SetImage(const CString& strName);
	void SetMargins(int x, int y);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXColorStatic)
public:
	virtual BOOL ModifyStyle(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0);
	virtual BOOL ModifyStyleEx(DWORD dwRemove, DWORD dwAdd, UINT nFlags = 0);
protected:
    virtual void PreSubclassWindow();
	virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	LOGFONT		m_lf;
	CFont		m_font;
	COLORREF	m_crText;
	CBrush		m_bkBrush;
	BOOL		m_bBold;
	int			m_nXMargin;
	int			m_nYMargin;
	HICON		m_hIcon;
	CString		m_strText;
	CString		m_strImageFileName;
	BOOL		m_bTransparent;
	
	// Generated message map functions
protected:
	//{{AFX_MSG(CXColorStatic)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

private:
	CGetFontName*	m_pFontName;
	void RefreshSelf();
	BOOL Draw();
	int GetCStringCharCount(CString& strText);
	int GetTextLine(HDC hDC, const CString& str, SIZE& maxSize);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif //XCOLORSTATIC_H
