
// DialogDemo1.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDialogDemo1App:
// �йش����ʵ�֣������ DialogDemo1.cpp
//

class CDialogDemo1App : public CWinAppEx
{
public:
	CDialogDemo1App();

// ��д
	public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CDialogDemo1App theApp;