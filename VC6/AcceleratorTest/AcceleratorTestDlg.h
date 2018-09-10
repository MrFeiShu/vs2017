// AcceleratorTestDlg.h : header file
//

#if !defined(AFX_ACCELERATORTESTDLG_H__9A241805_4D15_4334_BA9A_CF3330A2B783__INCLUDED_)
#define AFX_ACCELERATORTESTDLG_H__9A241805_4D15_4334_BA9A_CF3330A2B783__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAcceleratorTestDlg dialog

class CAcceleratorTestDlg : public CDialog
{
// Construction
public:
	CAcceleratorTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAcceleratorTestDlg)
	enum { IDD = IDD_ACCELERATORTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcceleratorTestDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAcceleratorTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	HACCEL m_hAccel;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCELERATORTESTDLG_H__9A241805_4D15_4334_BA9A_CF3330A2B783__INCLUDED_)
