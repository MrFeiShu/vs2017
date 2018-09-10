#pragma once

// CwcaKGOcxDemo.h : main header file for CwcaKGOcxDemo.DLL

#if !defined( __AFXCTL_H__ )
#error "include 'afxctl.h' before including this file"
#endif

#include "resource.h"       // main symbols


// CCwcaKGOcxDemoApp : See CwcaKGOcxDemo.cpp for implementation.

class CCwcaKGOcxDemoApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

