
// DevControlDemoDlg.h : header file
//

#pragma once

#define OP_CODE_WAIT			0
#define OP_CODE_INSERT			1
#define OP_CODE_REMOVE			2


typedef struct BLKDEVDATATAG
{
	int				m_u4SlotId;
	wchar_t			m_pszLabel[64];
	wchar_t			m_pszApp[32];
	wchar_t			m_pszCnt[64];
	wchar_t			m_pszCert[64];
	wchar_t			m_pszType[10];
	unsigned char*	m_pu1Cert;
}BlkDevData;

typedef struct BLKTRANSPROTOCOLTAG
{
	int			m_s4OpCode;
	BlkDevData	m_blkDevData;
}BlkTransProtocol;

// CDevControlDemoDlg dialog
class CDevControlDemoDlg : public CDialogEx
{
// Construction
public:
	CDevControlDemoDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DEVCONTROLDEMO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	HANDLE	m_hShareMem;
	void*	m_pView;
	int		m_s4SlotId;

public:
	BOOL InitShareMem();
	BOOL InsertDev(int s4SlotId);
	BOOL RemoveDev(int s4SlotId);
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnClickedCheck3();
	afx_msg void OnClickedCheck4();
	afx_msg void OnClickedCheck5();
	afx_msg void OnClickedButton1();
	afx_msg void OnClickedButton2();
	CButton m_check1;
	CButton m_check2;
	CButton m_check3;
	CButton m_check4;
	CButton m_check5;
};
