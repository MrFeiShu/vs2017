
// ListCtrlDemo.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CListCtrlDemoApp:
// �йش����ʵ�֣������ ListCtrlDemo.cpp
//

class CListCtrlDemoApp : public CWinAppEx
{
public:
	CListCtrlDemoApp();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CListCtrlDemoApp theApp;