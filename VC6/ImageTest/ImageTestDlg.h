// ImageTestDlg.h : header file
//

#if !defined(AFX_IMAGETESTDLG_H__3650D72D_F963_499D_B124_1D32EEB9E1BA__INCLUDED_)
#define AFX_IMAGETESTDLG_H__3650D72D_F963_499D_B124_1D32EEB9E1BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <ImageEx.h>

/////////////////////////////////////////////////////////////////////////////
// CImageTestDlg dialog

class CImageTestDlg : public CDialog
{
// Construction
public:
	CImageTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CImageTestDlg)
	enum { IDD = IDD_IMAGETEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CImageTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	CxImageEx m_ImageEx;
	void GetZoomRect(CRect* pRect);
	void Display(CRect rect, int s4Count, int s4Flag);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETESTDLG_H__3650D72D_F963_499D_B124_1D32EEB9E1BA__INCLUDED_)
