// BorderShadowTest.h : main header file for the BORDERSHADOWTEST application
//

#if !defined(AFX_BORDERSHADOWTEST_H__8AE2EE90_9B70_402E_AA5A_2A26F93DA435__INCLUDED_)
#define AFX_BORDERSHADOWTEST_H__8AE2EE90_9B70_402E_AA5A_2A26F93DA435__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBorderShadowTestApp:
// See BorderShadowTest.cpp for the implementation of this class
//

class CBorderShadowTestApp : public CWinApp
{
public:
	CBorderShadowTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorderShadowTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBorderShadowTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORDERSHADOWTEST_H__8AE2EE90_9B70_402E_AA5A_2A26F93DA435__INCLUDED_)
