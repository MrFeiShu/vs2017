// AcceleratorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Accelerator.h"
#include "AcceleratorDlg.h"

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
// CAcceleratorDlg dialog

CAcceleratorDlg::CAcceleratorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAcceleratorDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAcceleratorDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_hAccel = ::LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_ACCELERATOR_HIDE));
	m_bShow = FALSE;
}

void CAcceleratorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAcceleratorDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAcceleratorDlg, CDialog)
	//{{AFX_MSG_MAP(CAcceleratorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAcceleratorDlg message handlers

BOOL CAcceleratorDlg::OnInitDialog()
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
	((CButton*)GetDlgItem(IDC_BUTTON1))->ShowWindow(SW_HIDE);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAcceleratorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAcceleratorDlg::OnPaint() 
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
HCURSOR CAcceleratorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

BOOL CAcceleratorDlg::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	
// 	if ( m_hAccel )
// 	{
// 		if ( ::TranslateAccelerator(m_hWnd, m_hAccel, pMsg) )
// 		{
// 			return TRUE;
// 		}
// 	}

	if(pMsg->message==WM_KEYDOWN)   
    {   
        BOOL bCtrl=::GetKeyState(VK_CONTROL)&0x8000;   
        BOOL bShift=::GetKeyState(VK_SHIFT)&0x8000;   
        BOOL bAlt=::GetKeyState(VK_MENU)&0x8000;   
        switch(pMsg->wParam)   
        {   
        case VK_DELETE:   
            if(bCtrl&&bAlt&&bShift)   
                MessageBox("你按下的是Ctrl+Shift+Alt+Delete组合键","信息提示",MB_OK);   
            else if(bCtrl&&bShift)   
                MessageBox("你按下的是Ctrl+Shift+Delete组合键","信息提示",MB_OK);   
            else if(bCtrl)   
                MessageBox("你按下的是Ctrl+Delete组合键","信息提示",MB_OK);   
            return TRUE;   
        case VK_INSERT:   
            if(bCtrl&&bAlt&&bShift)   
                MessageBox("你按下的是Ctrl+Shift+Alt+Insert组合键","信息提示",MB_OK);   
            else if(bCtrl&&bAlt)   
                MessageBox("你按下的是Ctrl+Alt+Insert组合键","信息提示",MB_OK);   
            else if(bCtrl)   
                MessageBox("你按下的是Ctrl+Insert组合键","信息提示",MB_OK);   
            return TRUE;   
		case VK_F5:
			if ( bCtrl&&bAlt )
			{
				MessageBox("你按下的是Ctrl+Alt+F5组合键","信息提示",MB_OK);
			}
			return TRUE;
        } 
	}
	return CDialog::PreTranslateMessage(pMsg);
}

BOOL CAcceleratorDlg::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	// TODO: Add your specialized code here and/or call the base class
	if ( IDC_BUTTON1 == LOWORD(wParam) )
	{
		int a = 5;
	}

	return CDialog::OnCommand(wParam, lParam);
}

void CAcceleratorDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here

	
	((CButton*)GetDlgItem(IDC_BUTTON1))->ShowWindow(SW_SHOW);

	MessageBox(_T("BTN:Ctrl+Alt+F5"));
	((CButton*)GetDlgItem(IDC_BUTTON1))->ShowWindow(SW_HIDE);
}

void CAcceleratorDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	
	MessageBox(_T("BTN:fuck"));
}
