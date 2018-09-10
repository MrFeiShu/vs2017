
// WebBrowser.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "WebBrowser.h"
#include "WebBrowserDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWebBrowserApp

BEGIN_MESSAGE_MAP(CWebBrowserApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CWebBrowserApp ����

CWebBrowserApp::CWebBrowserApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CWebBrowserApp ����

CWebBrowserApp theApp;


// CWebBrowserApp ��ʼ��

#define _DISABLE_BUSY_DIALOG_

BOOL CWebBrowserApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControlsEx()�����򣬽��޷��������ڡ�
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// ��������Ϊ��������Ҫ��Ӧ�ó�����ʹ�õ�
	// �����ؼ��ࡣ
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

#ifdef _DISABLE_BUSY_DIALOG_
		// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(_T("OLE Init Failed"));
		return FALSE;
	}
	//********************************************************************************************
	// �������Excel VBA��ʱ�򵯳� ��������һ��������������...��
	AfxOleGetMessageFilter()-> EnableBusyDialog(FALSE);
	AfxOleGetMessageFilter()-> SetBusyReply(SERVERCALL_RETRYLATER);
	AfxOleGetMessageFilter()-> EnableNotRespondingDialog(TRUE); 
	AfxOleGetMessageFilter()-> SetMessagePendingDelay(-1);
#endif

	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));

	CWebBrowserDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȷ�������رնԻ���Ĵ���
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: �ڴ˷��ô����ʱ��
		//  ��ȡ�������رնԻ���Ĵ���
	}

	// ���ڶԻ����ѹرգ����Խ����� FALSE �Ա��˳�Ӧ�ó���
	//  ����������Ӧ�ó������Ϣ�á�
	return FALSE;
}
