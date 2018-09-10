// ImageTest.h : main header file for the IMAGETEST application
//

#if !defined(AFX_IMAGETEST_H__DE956797_1155_4B9B_ADC6_92DD38AE5E98__INCLUDED_)
#define AFX_IMAGETEST_H__DE956797_1155_4B9B_ADC6_92DD38AE5E98__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CImageTestApp:
// See ImageTest.cpp for the implementation of this class
//

class CImageTestApp : public CWinApp
{
public:
	CImageTestApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageTestApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CImageTestApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGETEST_H__DE956797_1155_4B9B_ADC6_92DD38AE5E98__INCLUDED_)
