
// CheckTool.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CCheckToolApp:
// �йش����ʵ�֣������ CheckTool.cpp
//

class CCheckToolApp : public CWinAppEx
{
public:
	CCheckToolApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CCheckToolApp theApp;