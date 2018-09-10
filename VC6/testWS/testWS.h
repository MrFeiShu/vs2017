// testWS.h : main header file for the TESTWS application
//

#if !defined(AFX_TESTWS_H__1D26E1EF_9D20_4946_9FB9_BECD9DCA2851__INCLUDED_)
#define AFX_TESTWS_H__1D26E1EF_9D20_4946_9FB9_BECD9DCA2851__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestWSApp:
// See testWS.cpp for the implementation of this class
//

class CTestWSApp : public CWinApp
{
public:
	CTestWSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestWSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTestWSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTWS_H__1D26E1EF_9D20_4946_9FB9_BECD9DCA2851__INCLUDED_)
