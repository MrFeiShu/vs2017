// ImageTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include <WINDOWS.H>
#include "ImageTest.h"
#include "ImageTestDlg.h"

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
// CImageTestDlg dialog

CImageTestDlg::CImageTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CImageTestDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CImageTestDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImageTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CImageTestDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CImageTestDlg, CDialog)
	//{{AFX_MSG_MAP(CImageTestDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CImageTestDlg message handlers

BOOL CImageTestDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CImageTestDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CImageTestDlg::OnPaint() 
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
HCURSOR CImageTestDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL CImageTestDlg::OnEraseBkgnd(CDC* pDC) 
{
	// TODO: Add your message handler code here and/or call default
	CDialog::OnEraseBkgnd(pDC);
	static int s4Count = 0;
	s4Count++;
	CRect	rect1(96, 0, 313, 216);
	Display(rect1, s4Count, 1);
	GetZoomRect(&rect1);
	Display(rect1, s4Count, 2);
	m_ImageEx.DrawImage(pDC, &rect1, _T("123.png"));

	return FALSE;
}

long	lDpiX;
long	lDpiY;
void CImageTestDlg::GetZoomRect(CRect* pRect)
{	
	CRect	rect;
	pRect->left = pRect->left * lDpiX / 96;
	pRect->top = pRect->top * lDpiX / 96;
	pRect->right = pRect->right * lDpiX / 96;
	pRect->bottom = pRect->bottom * lDpiX / 96;
}

void CImageTestDlg::Display(CRect rect, int s4Count, int s4Flag)
{
	CString str;
	CDC*	pDC;
	long	horzsize;
	long	vertsize;
	long	horzres;
	long	vertres;

	pDC = GetDC();

	SetProcessDPIAware();
	lDpiX = GetDeviceCaps(pDC->m_hDC, LOGPIXELSX);
	lDpiY = GetDeviceCaps(pDC->m_hDC, LOGPIXELSY);
	horzsize = GetDeviceCaps(pDC->m_hDC, HORZSIZE);
	vertsize = GetDeviceCaps(pDC->m_hDC, VERTSIZE);
	horzres = GetDeviceCaps(pDC->m_hDC, HORZRES);
	vertres = GetDeviceCaps(pDC->m_hDC, VERTRES);

	str.Format(_T("%d %d"), s4Count, lDpiX);
	SetDlgItemText(IDC_EDIT3, str);
	str.Format(_T("%d %d %d %d %d %d %d %d"), rect.left, rect.top, rect.right, rect.bottom, horzsize, vertsize, horzres, vertres);
	if ( 1 == s4Flag )
	{
		SetDlgItemText(IDC_EDIT1, str);
	}
	else
	{
		SetDlgItemText(IDC_EDIT2, str);
	}
}