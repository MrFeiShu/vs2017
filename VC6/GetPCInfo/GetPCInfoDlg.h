// GetPCInfoDlg.h : header file
//

#if !defined(AFX_GETPCINFODLG_H__5C6B817D_785D_4603_A912_84A05A3C6BD5__INCLUDED_)
#define AFX_GETPCINFODLG_H__5C6B817D_785D_4603_A912_84A05A3C6BD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGetPCInfoDlg dialog

class CGetPCInfoDlg : public CDialog
{
// Construction
public:
	CGetPCInfoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGetPCInfoDlg)
	enum { IDD = IDD_GETPCINFO_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPCInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGetPCInfoDlg)
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

#endif // !defined(AFX_GETPCINFODLG_H__5C6B817D_785D_4603_A912_84A05A3C6BD5__INCLUDED_)
