#pragma once

// CwcaKGOcxDemoPropPage.h : Declaration of the CCwcaKGOcxDemoPropPage property page class.


// CCwcaKGOcxDemoPropPage : See CwcaKGOcxDemoPropPage.cpp for implementation.

class CCwcaKGOcxDemoPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CCwcaKGOcxDemoPropPage)
	DECLARE_OLECREATE_EX(CCwcaKGOcxDemoPropPage)

// Constructor
public:
	CCwcaKGOcxDemoPropPage();

// Dialog Data
	enum { IDD = IDD_PROPPAGE_CWCAKGOCXDEMO };

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	DECLARE_MESSAGE_MAP()
};

