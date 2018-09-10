
// Music_Player.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMusic_PlayerApp:
// See Music_Player.cpp for the implementation of this class
//

class CMusic_PlayerApp : public CWinApp
{
public:
	CMusic_PlayerApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMusic_PlayerApp theApp;