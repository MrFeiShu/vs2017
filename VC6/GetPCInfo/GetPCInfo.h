// GetPCInfo.h : main header file for the GETPCINFO application
//

#if !defined(AFX_GETPCINFO_H__F06B6B3C_0282_49C1_9925_FA841DAFF765__INCLUDED_)
#define AFX_GETPCINFO_H__F06B6B3C_0282_49C1_9925_FA841DAFF765__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetPCInfoApp:
// See GetPCInfo.cpp for the implementation of this class
//

class CGetPCInfoApp : public CWinApp
{
public:
	CGetPCInfoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetPCInfoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetPCInfoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPCINFO_H__F06B6B3C_0282_49C1_9925_FA841DAFF765__INCLUDED_)
