// TestSqlite.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestSqliteApp:
// �йش����ʵ�֣������ TestSqlite.cpp
//

class CTestSqliteApp : public CWinApp
{
public:
	CTestSqliteApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestSqliteApp theApp;