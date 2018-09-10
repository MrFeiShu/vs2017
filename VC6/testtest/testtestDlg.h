// testtestDlg.h : header file
//

#if !defined(AFX_TESTTESTDLG_H__8BD601A5_9F09_422A_8A97_353CB3045D0E__INCLUDED_)
#define AFX_TESTTESTDLG_H__8BD601A5_9F09_422A_8A97_353CB3045D0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTesttestDlg dialog

class CTesttestDlg : public CDialog
{
// Construction
public:
	CTesttestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTesttestDlg)
	enum { IDD = IDD_TESTTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesttestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTesttestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTTESTDLG_H__8BD601A5_9F09_422A_8A97_353CB3045D0E__INCLUDED_)
