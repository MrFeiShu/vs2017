
// test_doc_paint.h : main header file for the test_doc_paint application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// Ctest_doc_paintApp:
// See test_doc_paint.cpp for the implementation of this class
//

class Ctest_doc_paintApp : public CWinAppEx
{
public:
	Ctest_doc_paintApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ctest_doc_paintApp theApp;
