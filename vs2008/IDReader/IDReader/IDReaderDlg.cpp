
// IDReaderDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "IDReader.h"
#include "IDReaderDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

typedef int (*readcard)( char * c_id, char * reqID,char *errMsg);
typedef int (*getInfo)(char *app_id,char *appkey, char * cid_reqID,char * biz_sequence_id,char* info, char *dn, char *appeidcode, char * errMsg);

readcard g_FunReadCard;
getInfo g_FunGetInfo;

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
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

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CIDReaderDlg �Ի���




CIDReaderDlg::CIDReaderDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CIDReaderDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CIDReaderDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CIDReaderDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON_READER, &CIDReaderDlg::OnBnClickedButtonReader)
	ON_BN_CLICKED(IDC_BUTTON1, &CIDReaderDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CIDReaderDlg ��Ϣ�������

BOOL CIDReaderDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

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
	LoadDll();

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CIDReaderDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CIDReaderDlg::OnPaint()
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
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CIDReaderDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CIDReaderDlg::OnBnClickedButtonReader()
{
	// TODO: Add your control notification handler code here
	char app_id[21] = "BEIPZismNDnBL0czCOPv";
	char appkey[40] = "B9DD6224246C1EF568BD95067F430A37";
	char cid[60] = "1220600";
	char errMsg[50] = {0};
	char reqID[26] = {0};
	char info[500] = {0};
	char appeidcode[50] = {0};
	char dn[35] = {0};

	//���ö���������ȡ����Ϣ
	int res = g_FunReadCard(cid, reqID,errMsg);
	if (res == 0){
		memcpy(&cid[strlen(cid)], reqID, strlen(reqID));
		//���ò�ѯ�ӿ�
		res = g_FunGetInfo(app_id, appkey,cid,"jWEeQkfogZSJvrS2iDZ",info, dn, appeidcode,errMsg);
		if (res >= 0 && strlen(info)){
			//info Ϊ�����Ϣ�����ʹ���˹�Կ���ܣ�������ӽ��ܴ���
		}
	}
}

void CIDReaderDlg::LoadDll()
{
	HRESULT	hRet;
	CString str;
	HMODULE hMod = NULL;
	g_FunGetInfo = NULL;
	g_FunReadCard = NULL;

	hMod = LoadLibrary(_T("E:\\code\\vs2008\\IDReader\\Debug\\JLReadCarder.dll"));
	if ( NULL == hMod )
	{
		hRet = GetLastError();
		str.Format(_T("Load JLReadCarder.dll failed!!!, lasterr=0x%08x"), hRet);
		MessageBox(str);
		return;
	}

	g_FunReadCard = (readcard)GetProcAddress(hMod, "readcard");
	g_FunGetInfo = (getInfo)GetProcAddress(hMod, "getInfo");
	if ( NULL == g_FunReadCard || NULL == g_FunGetInfo )
	{
		hRet = GetLastError();
		str.Format(_T("GetProcAddress failed!!!, lasterr=0x%08x"), hRet);
		MessageBox(str);
		return;
	}
}

void ConvertGBKToUtf8(char* pszGBK, char* pszUTF_8)
{
	int len=MultiByteToWideChar(CP_ACP, 0, pszGBK, -1, NULL,0);
	wchar_t * wszUtf8 = new wchar_t [len];
	memset(wszUtf8, 0, len);
	MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)pszGBK, -1, wszUtf8, len);
	len = WideCharToMultiByte(CP_UTF8, 0, wszUtf8, -1, NULL, 0, NULL, NULL);
	char *szUtf8=new char[len + 1];
	memset(szUtf8, 0, len + 1);
	WideCharToMultiByte (CP_UTF8, 0, wszUtf8, -1, pszUTF_8, len, NULL,NULL);
	delete[] wszUtf8;
}

void CIDReaderDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	char*		pszGBK = "����˭";
	char		pszUTF_8[0x20] = {0};

	ConvertGBKToUtf8(pszGBK, pszUTF_8);

	int len=MultiByteToWideChar(CP_UTF8, 0, pszUTF_8, -1, NULL,0);
	wchar_t * wszUtf8 = new wchar_t [len];
	memset(wszUtf8, 0, len);
	MultiByteToWideChar(CP_UTF8, 0, (LPCTSTR)pszUTF_8, -1, wszUtf8, len);

}
