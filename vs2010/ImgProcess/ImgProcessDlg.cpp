
// ImgProcessDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "ImgProcess.h"
#include "ImgProcessDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CImgProcessDlg �Ի���




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


// CImgProcessDlg ��Ϣ�������

BOOL CImgProcessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//LoadImg();
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CImgProcessDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
