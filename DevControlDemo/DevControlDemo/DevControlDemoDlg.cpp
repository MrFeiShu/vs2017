
// DevControlDemoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DevControlDemo.h"
#include "DevControlDemoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

BlkDevData g_blkDev[5][18] = {
		{
			{1, L"fuck benkai 1", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
			{1, L"fuck benkai 1", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
			{1, L"fuck benkai 1", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
			{1, L"fuck benkai 1", L"App1", L"Cnt3", L"", L"", NULL},
			{1, L"fuck benkai 1", L"App2", L"", L"", L"", NULL},
			{1, L"fuck benkai 1", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
			{1, L"fuck benkai 1", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
			{1, L"fuck benkai 1", L"App3", L"Cnt3", L"cert1", L"exch", NULL}
		},
		{
			{2, L"fuck benkai 2", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
			{2, L"fuck benkai 2", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App1", L"Cnt2", L"cert2", L"sign", NULL},
			{2, L"fuck benkai 2", L"App1", L"Cnt3", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App1", L"Cnt3", L"cert2", L"sign", NULL},
			{2, L"fuck benkai 2", L"App2", L"Cnt1", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App2", L"Cnt1", L"cert2", L"sign", NULL},
			{2, L"fuck benkai 2", L"App2", L"Cnt2", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App2", L"Cnt2", L"cert2", L"sign", NULL},
			{2, L"fuck benkai 2", L"App2", L"Cnt3", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App2", L"Cnt3", L"cert2", L"sign", NULL},
			{2, L"fuck benkai 2", L"App3", L"Cnt1", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
			{2, L"fuck benkai 2", L"App3", L"Cnt2", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
			{2, L"fuck benkai 2", L"App3", L"Cnt3", L"cert1", L"exch", NULL},
			{2, L"fuck benkai 2", L"App3", L"Cnt3", L"cert2", L"sign", NULL}
		},
		{
			{3, L"fuck benkai 3", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
			{3, L"fuck benkai 3", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App1", L"Cnt2", L"cert2", L"sign", NULL},
			{3, L"fuck benkai 3", L"App1", L"Cnt3", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App1", L"Cnt3", L"cert2", L"sign", NULL},
			{3, L"fuck benkai 3", L"App2", L"Cnt1", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App2", L"Cnt1", L"cert2", L"sign", NULL},
			{3, L"fuck benkai 3", L"App2", L"Cnt2", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App2", L"Cnt2", L"cert2", L"sign", NULL},
			{3, L"fuck benkai 3", L"App2", L"Cnt3", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App2", L"Cnt3", L"cert2", L"sign", NULL},
			{3, L"fuck benkai 3", L"App3", L"Cnt1", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
			{3, L"fuck benkai 3", L"App3", L"Cnt2", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
			{3, L"fuck benkai 3", L"App3", L"Cnt3", L"cert1", L"exch", NULL},
			{3, L"fuck benkai 3", L"App3", L"Cnt3", L"cert2", L"sign", NULL}
		},
		{
			{4, L"fuck benkai 4", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
			{4, L"fuck benkai 4", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App1", L"Cnt2", L"cert2", L"sign", NULL},
			{4, L"fuck benkai 4", L"App1", L"Cnt3", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App1", L"Cnt3", L"cert2", L"sign", NULL},
			{4, L"fuck benkai 4", L"App2", L"Cnt1", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App2", L"Cnt1", L"cert2", L"sign", NULL},
			{4, L"fuck benkai 4", L"App2", L"Cnt2", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App2", L"Cnt2", L"cert2", L"sign", NULL},
			{4, L"fuck benkai 4", L"App2", L"Cnt3", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App2", L"Cnt3", L"cert2", L"sign", NULL},
			{4, L"fuck benkai 4", L"App3", L"Cnt1", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
			{4, L"fuck benkai 4", L"App3", L"Cnt2", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
			{4, L"fuck benkai 4", L"App3", L"Cnt3", L"cert1", L"exch", NULL},
			{4, L"fuck benkai 4", L"App3", L"Cnt3", L"cert2", L"sign", NULL}
		},
		{
			{5, L"fuck benkai 5", L"App1", L"Cnt1", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App1", L"Cnt1", L"cert2", L"sign", NULL},
			{5, L"fuck benkai 5", L"App1", L"Cnt2", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App1", L"Cnt2", L"cert2", L"sign", NULL},
			{5, L"fuck benkai 5", L"App1", L"Cnt3", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App1", L"Cnt3", L"cert2", L"sign", NULL},
			{5, L"fuck benkai 5", L"App2", L"Cnt1", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App2", L"Cnt1", L"cert2", L"sign", NULL},
			{5, L"fuck benkai 5", L"App2", L"Cnt2", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App2", L"Cnt2", L"cert2", L"sign", NULL},
			{5, L"fuck benkai 5", L"App2", L"Cnt3", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App2", L"Cnt3", L"cert2", L"sign", NULL},
			{5, L"fuck benkai 5", L"App3", L"Cnt1", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App3", L"Cnt1", L"cert2", L"sign", NULL},
			{5, L"fuck benkai 5", L"App3", L"Cnt2", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App3", L"Cnt2", L"cert2", L"sign", NULL},
			{5, L"fuck benkai 5", L"App3", L"Cnt3", L"cert1", L"exch", NULL},
			{5, L"fuck benkai 5", L"App3", L"Cnt3", L"cert2", L"sign", NULL}
		}
};

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDevControlDemoDlg dialog



CDevControlDemoDlg::CDevControlDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DEVCONTROLDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDevControlDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_check1);
	DDX_Control(pDX, IDC_CHECK2, m_check2);
	DDX_Control(pDX, IDC_CHECK3, m_check3);
	DDX_Control(pDX, IDC_CHECK4, m_check4);
	DDX_Control(pDX, IDC_CHECK5, m_check5);
}

BEGIN_MESSAGE_MAP(CDevControlDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK1, &CDevControlDemoDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CDevControlDemoDlg::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CDevControlDemoDlg::OnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CDevControlDemoDlg::OnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CDevControlDemoDlg::OnClickedCheck5)
	ON_BN_CLICKED(IDC_BUTTON1, &CDevControlDemoDlg::OnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CDevControlDemoDlg::OnClickedButton2)
END_MESSAGE_MAP()


// CDevControlDemoDlg message handlers

BOOL CDevControlDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	InitShareMem();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDevControlDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDevControlDemoDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDevControlDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

BOOL CDevControlDemoDlg::InitShareMem()
{
	LRESULT	lRet;
	m_hShareMem = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, 4000, _T("DevData098098098123123123345635"));
	if ( NULL == m_hShareMem )
	{
		lRet = GetLastError();
		return FALSE;
	}

	m_pView = MapViewOfFile(m_hShareMem, FILE_MAP_ALL_ACCESS, 0, 0, 2000);
	if ( NULL == m_pView)
	{
		lRet = GetLastError();
		return FALSE;
	}

	memset(m_pView, 0x01, 2000); // 初始化共享内存数据

	return TRUE;
}

void CDevControlDemoDlg::OnBnClickedCheck1()
{
	// TODO: Add your control notification handler code here
	m_s4SlotId = 1;

	if ( BST_CHECKED == m_check1.GetCheck() )
	{
		InsertDev(m_s4SlotId);
	}
	else
	{
		RemoveDev(m_s4SlotId);
	}
}


void CDevControlDemoDlg::OnBnClickedCheck2()
{
	// TODO: Add your control notification handler code here
	m_s4SlotId = 2;
	if (BST_CHECKED == m_check2.GetCheck())
	{
		InsertDev(m_s4SlotId);
	}
	else
	{
		RemoveDev(m_s4SlotId);
	}
}


void CDevControlDemoDlg::OnClickedCheck3()
{
	// TODO: Add your control notification handler code here
	m_s4SlotId = 3;
	if (BST_CHECKED == m_check3.GetCheck())
	{
		InsertDev(m_s4SlotId);
	}
	else
	{
		RemoveDev(m_s4SlotId);
	}
}


void CDevControlDemoDlg::OnClickedCheck4()
{
	// TODO: Add your control notification handler code here
	m_s4SlotId = 4;
	if (BST_CHECKED == m_check4.GetCheck())
	{
		InsertDev(m_s4SlotId);
	}
	else
	{
		RemoveDev(m_s4SlotId);
	}
}


void CDevControlDemoDlg::OnClickedCheck5()
{
	// TODO: Add your control notification handler code here
	m_s4SlotId = 5;
	if (BST_CHECKED == m_check5.GetCheck())
	{
		InsertDev(m_s4SlotId);
	}
	else
	{
		RemoveDev(m_s4SlotId);
	}
}


void CDevControlDemoDlg::OnClickedButton1()
{
	// TODO: Add your control notification handler code here
	for ( int i = 0; i < 5; i++ )
	{
		InsertDev(i + 1);
	}
}


void CDevControlDemoDlg::OnClickedButton2()
{
	// TODO: Add your control notification handler code here
	for ( int i = 0; i < 5; i++ )
	{
		RemoveDev(i + 1);
	}
}

BOOL CDevControlDemoDlg::InsertDev(int s4SlotId)
{
	BlkTransProtocol	blkData;
	int i = 0;

	while ( i < 18)
	{
		if ( 0 != memcmp("\x66\x75\x63\x6b", m_pView, 4) )
		{
			blkData.m_s4OpCode = OP_CODE_INSERT;
			memcpy(&blkData.m_blkDevData, &g_blkDev[s4SlotId - 1][i], sizeof(BlkDevData));

			memcpy(m_pView, &blkData, sizeof(BlkTransProtocol));

			i++;
		}
	}
	return TRUE;
}

BOOL CDevControlDemoDlg::RemoveDev(int s4SlotId)
{
	BlkTransProtocol	blkData;
	BOOL bOut;

	bOut = FALSE;
	while ( !bOut )
	{
		if ( 0 != memcpy("\x66\x75\x63\x6b", m_pView, 4) )
		{
			blkData.m_s4OpCode = OP_CODE_REMOVE;
			memcpy(&blkData.m_blkDevData, &g_blkDev[s4SlotId - 1][0], sizeof(BlkDevData));

			memcpy(m_pView, &blkData, sizeof(BlkTransProtocol));
			bOut = TRUE;
		}
	}
	return TRUE;
}

UINT StartClientThreadProc(LPVOID)
{
	//初始化WSA windows自带的socket
	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA data;
	if (WSAStartup(sockVersion, &data) != 0)
	{
		return 0;
	}

	//创建客户端套接字
	while (true)
	{
		SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //客户端套接字
		if (sclient == INVALID_SOCKET)
		{
			printf("invalid socket!");
			return 0;
		}

		sockaddr_in serAddr;
		serAddr.sin_family = AF_INET;
		serAddr.sin_port = htons(8888);
		inet_pton(AF_INET, "127.0.0.1", (void*)&serAddr.sin_addr.S_un.S_addr);
		if (connect(sclient, (sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR) //与指定IP地址和端口的服务端连接
		{
			printf("connect error !");
			closesocket(sclient);
			return 0;
		}

		printf("输入你想传输的英文： \n");
		string data;
		cin >> data;
		const char * sendData2;
		sendData2 = data.c_str(); //string转const char*
		send(sclient, sendData2, strlen(sendData2), 0);


		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret > 0) {
			recData[ret] = 0x00;
			printf(recData);
		}
		closesocket(sclient);

	}
	WSACleanup();
	return 0;
}

void CDevControlDemoDlg::CreateClient()
{

}