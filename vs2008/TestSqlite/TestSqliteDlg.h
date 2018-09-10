// TestSqliteDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include <EsCommon\EsCommon.h>

// CTestSqliteDlg 对话框
class CTestSqliteDlg : public CDialog
{
// 构造
public:
	CTestSqliteDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TESTSQLITE_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
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
