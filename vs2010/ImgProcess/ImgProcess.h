
// ImgProcess.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CImgProcessApp:
// �йش����ʵ�֣������ ImgProcess.cpp
//

class CImgProcessApp : public CWinApp
{
public:
	CImgProcessApp();

// ��д
public:
	virtual BOOL InitInstance();

	GdiplusStartupInput    m_Gdistart; 
	ULONG_PTR    m_GdiplusToken; 

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CImgProcessApp theApp;