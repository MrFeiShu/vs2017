// AcceleratorTest.h : main header file for the ACCELERATORTEST application
//

#if !defined(AFX_ACCELERATORTEST_H__84E850FE_A222_4E4C_BC84_9D690436E87B__INCLUDED_)
#define AFX_ACCELERATORTEST_H__84E850FE_A222_4E4C_BC84_9D690436E87B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAcceleratorTestApp:
// See AcceleratorTest.cpp for the implementation of this class
//

class CAcceleratorTestApp : public CWinApp
{
public:
	CAcceleratorTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAcceleratorTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAcceleratorTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ACCELERATORTEST_H__84E850FE_A222_4E4C_BC84_9D690436E87B__INCLUDED_)
