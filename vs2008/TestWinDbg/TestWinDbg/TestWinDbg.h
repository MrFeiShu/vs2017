
// TestWinDbg.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CTestWinDbgApp:
// �йش����ʵ�֣������ TestWinDbg.cpp
//

class CTestWinDbgApp : public CWinAppEx
{
public:
	CTestWinDbgApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CTestWinDbgApp theApp;