
// CurPath.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCurPathApp:
// See CurPath.cpp for the implementation of this class
//

class CCurPathApp : public CWinApp
{
public:
	CCurPathApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCurPathApp theApp;