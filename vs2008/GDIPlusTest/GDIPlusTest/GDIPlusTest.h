
// GDIPlusTest.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CGDIPlusTestApp:
// See GDIPlusTest.cpp for the implementation of this class
//

class CGDIPlusTestApp : public CWinAppEx
{
public:
	CGDIPlusTestApp();

// Overrides
	public:
	virtual BOOL InitInstance();

public:
	ULONG_PTR m_gdiplusToken; 

// Implementation

	DECLARE_MESSAGE_MAP()

	virtual int ExitInstance();
};

extern CGDIPlusTestApp theApp;