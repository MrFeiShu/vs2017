// testtest.h : main header file for the TESTTEST application
//

#if !defined(AFX_TESTTEST_H__45FD475D_811E_46B0_9EB1_91DCDA6B5B61__INCLUDED_)
#define AFX_TESTTEST_H__45FD475D_811E_46B0_9EB1_91DCDA6B5B61__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTesttestApp:
// See testtest.cpp for the implementation of this class
//

class CTesttestApp : public CWinApp
{
public:
	CTesttestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTesttestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTesttestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTTEST_H__45FD475D_811E_46B0_9EB1_91DCDA6B5B61__INCLUDED_)
