// AcceleratorDlg.h : header file
//

#if !defined(AFX_ACCELERATORDLG_H__A4062A61_39FC_4D5B_AF6A_399124C1D040__INCLUDED_)
#define AFX_ACCELERATORDLG_H__A4062A61_39FC_4D5B_AF6A_399124C1D040__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAcceleratorDlg dialog

class CAcceleratorDlg : public CDialog
{
// Construction
public:
	CAcceleratorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAcceleratorDlg)
	enum { IDD = IDD_ACCELERATOR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcceleratorDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAcceleratorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	HACCEL m_hAccel;
	BOOL	m_bShow;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCELERATORDLG_H__A4062A61_39FC_4D5B_AF6A_399124C1D040__INCLUDED_)
