
// ImgProcessDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "ImgProcessDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CImgProcessDlg 对话框




CImgProcessDlg::CImgProcessDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CImgProcessDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CImgProcessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CImgProcessDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_ERASEBKGND()
	ON_BN_CLICKED(IDC_BUTTON1, &CImgProcessDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CImgProcessDlg 消息处理程序

BOOL CImgProcessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//LoadImg();
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CImgProcessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CImgProcessDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CImgProcessDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CImgProcessDlg::LoadImg()
{
	HBITMAP		hBitMap;
	CBitmap		bitmap;

	CDC*	pDC = GetDC();

	hBitMap = (HBITMAP)LoadImage(NULL, _T("E:\\code\\vs2010\\ImgProcess\\res\\xue.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE|LR_DEFAULTSIZE|LR_CREATEDIBSECTION);

	CRect		rect;

	GetClientRect(&rect);

	int			showX = 0, showY = 0;
	int			nWidth = rect.right - rect.left;
	int			nHeight = rect.bottom - rect.top;

	CDC			dcBmp;
	
	if ( !dcBmp.CreateCompatibleDC(pDC) )
	{
		return;
	}
	
	BITMAP	bmp;
	bitmap.GetBitmap(&bmp);

	CBitmap* oldMap = NULL;
	dcBmp.SelectObject(&bitmap);

	pDC->StretchBlt(0, 0, bmp.bmWidth, bmp.bmHeight, &dcBmp, 0, 0, bmp.bmWidth, bmp.bmHeight, SRCCOPY);

	dcBmp.SelectObject(oldMap);
	DeleteObject(&bitmap);
	dcBmp.DeleteDC();
}

BOOL CImgProcessDlg::OnEraseBkgnd(CDC* pDC)
{
	// TODO: Add your message handler code here and/or call default
	CRect rect;
	BOOL bRet = TRUE;
	long lRet = 0;
	TCHAR* ptzPath = _T(".\\res\\ha.bmp");
	GetClientRect(&rect);

	CBitmap cbmp;
//	bRet = bmp.LoadBitmap(IDB_BITMAP2);
	HBITMAP hBmp;
	hBmp = (HBITMAP)LoadImage(NULL, ptzPath, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	cbmp.Attach(hBmp);
// 	BITMAP bitmap;
// 	cbmp.GetBitmap(&bitmap);

	if ( !bRet )
	{
		lRet = GetLastError();
	}
	CDC dcCompatible;
	dcCompatible.CreateCompatibleDC(pDC);
	dcCompatible.SelectObject(&cbmp);
	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0, SRCCOPY);
	//pDC->StretchBlt(0, 0, rect.Width(), rect.Height(), &dcCompatible, 0, 0,bitmap.bmWidth, bitmap.bmHeight, SRCCOPY);

	return TRUE;
}


void CImgProcessDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here

	CFile file(_T(".\\res\\ha.bmp"));

	file.
}
