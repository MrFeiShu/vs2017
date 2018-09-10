// testWSDlg.cpp : implementation file
//

#include "stdafx.h"
#include "testWS.h"
#include "testWSDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestWSDlg dialog

CTestWSDlg::CTestWSDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestWSDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTestWSDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestWSDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CTestWSDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CTestWSDlg, CDialog)
	//{{AFX_MSG_MAP(CTestWSDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestWSDlg message handlers

BOOL CTestWSDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	DWORD dwStyle = GetWindowLong(this->GetSafeHwnd(), GWL_STYLE);
	DWORD dwExStyle = GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE);
	dwStyle |= WS_CAPTION | WS_POPUP | WS_SYSMENU | WS_CLIPSIBLINGS | DS_MODALFRAME;
	dwExStyle |= WS_EX_WINDOWEDGE;
	SetWindowLong(this->GetSafeHwnd(), GWL_STYLE, dwStyle);
	SetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE, dwExStyle);

	
	dwStyle = GetWindowLong(this->GetSafeHwnd(), GWL_STYLE);
	dwExStyle = GetWindowLong(this->GetSafeHwnd(), GWL_EXSTYLE);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CTestWSDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CTestWSDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CTestWSDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CTestWSDlg::OnOK() 
{
	// TODO: Add extra validation here
	
// 	AfxBeginThread(ThreadProc1, NULL);
// 	AfxBeginThread(ThreadProc2, NULL);
// 	AfxBeginThread(ThreadProc3, NULL);
// 	AfxBeginThread(ThreadProc4, NULL);
}

UINT CTestWSDlg::ThreadProc1(LPVOID pParam)
{
	while(1)
	{
		NULL;
	}

	return 0;
}

UINT CTestWSDlg::ThreadProc2(LPVOID pParam)
{
	while(1)
	{
		NULL;
	}
	
	return 0;
}

UINT CTestWSDlg::ThreadProc3(LPVOID pParam)
{
	while(1)
	{
		NULL;
	}
	
	return 0;
}

UINT CTestWSDlg::ThreadProc4(LPVOID pParam)
{
	while(1)
	{
		NULL;
	}
	
	return 0;
}