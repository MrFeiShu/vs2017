// testWSDlg.h : header file
//

#if !defined(AFX_TESTWSDLG_H__000EFEFF_9849_4140_87FF_C7AACEA315CA__INCLUDED_)
#define AFX_TESTWSDLG_H__000EFEFF_9849_4140_87FF_C7AACEA315CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CTestWSDlg dialog

class CTestWSDlg : public CDialog
{
// Construction
public:
	CTestWSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CTestWSDlg)
	enum { IDD = IDD_TESTWS_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestWSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CTestWSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	static UINT ThreadProc1(LPVOID pParam);
	static UINT ThreadProc2(LPVOID pParam);
	static UINT ThreadProc3(LPVOID pParam);
	static UINT ThreadProc4(LPVOID pParam);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTWSDLG_H__000EFEFF_9849_4140_87FF_C7AACEA315CA__INCLUDED_)
