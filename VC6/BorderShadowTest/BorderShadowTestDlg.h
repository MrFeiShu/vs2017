// BorderShadowTestDlg.h : header file
//

#if !defined(AFX_BORDERSHADOWTESTDLG_H__7C6E8108_158B_4132_A0F3_8CBAC293F53A__INCLUDED_)
#define AFX_BORDERSHADOWTESTDLG_H__7C6E8108_158B_4132_A0F3_8CBAC293F53A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CBorderShadowTestDlg dialog

class CBorderShadowTestDlg : public CDialog
{
// Construction
public:
	CBorderShadowTestDlg(CWnd* pParent = NULL);	// standard constructor
	~CBorderShadowTestDlg();

// Dialog Data
	//{{AFX_DATA(CBorderShadowTestDlg)
	enum { IDD = IDD_BORDERSHADOWTEST_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorderShadowTestDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CBorderShadowTestDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	char* m_pMem;
	static UINT ThreadProc(LPVOID pParam);

private:
	CRect m_rtClient;
	Image* m_pImage;
	//gdi+用到的两个变量
    GdiplusStartupInput m_gdiplusStartupInput;
    ULONG_PTR m_pGdiToken;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORDERSHADOWTESTDLG_H__7C6E8108_158B_4132_A0F3_8CBAC293F53A__INCLUDED_)
