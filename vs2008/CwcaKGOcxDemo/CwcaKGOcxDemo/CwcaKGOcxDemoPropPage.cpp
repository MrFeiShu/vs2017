// CwcaKGOcxDemoPropPage.cpp : Implementation of the CCwcaKGOcxDemoPropPage property page class.

#include "stdafx.h"
#include "CwcaKGOcxDemo.h"
#include "CwcaKGOcxDemoPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CCwcaKGOcxDemoPropPage, COlePropertyPage)



// Message map

BEGIN_MESSAGE_MAP(CCwcaKGOcxDemoPropPage, COlePropertyPage)
END_MESSAGE_MAP()



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CCwcaKGOcxDemoPropPage, "CWCAKGOCXDEMO.CwcaKGOcxDemoPropPage.1",
	0x9af1a75c, 0x8d75, 0x4573, 0x89, 0x69, 0xc, 0x39, 0x7f, 0x74, 0x63, 0xd9)



// CCwcaKGOcxDemoPropPage::CCwcaKGOcxDemoPropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CCwcaKGOcxDemoPropPage

BOOL CCwcaKGOcxDemoPropPage::CCwcaKGOcxDemoPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_CWCAKGOCXDEMO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}



// CCwcaKGOcxDemoPropPage::CCwcaKGOcxDemoPropPage - Constructor

CCwcaKGOcxDemoPropPage::CCwcaKGOcxDemoPropPage() :
	COlePropertyPage(IDD, IDS_CWCAKGOCXDEMO_PPG_CAPTION)
{
}



// CCwcaKGOcxDemoPropPage::DoDataExchange - Moves data between page and properties

void CCwcaKGOcxDemoPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}



// CCwcaKGOcxDemoPropPage message handlers
