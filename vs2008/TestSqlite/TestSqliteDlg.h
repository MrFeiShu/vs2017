// TestSqliteDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include <EsCommon\EsCommon.h>

// CTestSqliteDlg �Ի���
class CTestSqliteDlg : public CDialog
{
// ����
public:
	CTestSqliteDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTSQLITE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CEdit m_CEdit1;
	// hehehe
	CEdit m_CEdit2;
	// asdf
	CEdit m_CEdit3;

	void Initialize();

};
