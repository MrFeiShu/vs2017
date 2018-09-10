// CwcaKGOcxDemoCtrl.cpp : Implementation of the CCwcaKGOcxDemoCtrl ActiveX Control class.

#include "stdafx.h"
#include "CwcaKGOcxDemo.h"
#include "CwcaKGOcxDemoCtrl.h"
#include "CwcaKGOcxDemoPropPage.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


IMPLEMENT_DYNCREATE(CCwcaKGOcxDemoCtrl, COleControl)



// Message map

BEGIN_MESSAGE_MAP(CCwcaKGOcxDemoCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()



// Dispatch map

BEGIN_DISPATCH_MAP(CCwcaKGOcxDemoCtrl, COleControl)
	DISP_FUNCTION_ID(CCwcaKGOcxDemoCtrl, "GenerateCertRequest", dispidGenerateCertRequest, GenerateCertRequest, VT_BSTR, VTS_BSTR VTS_BSTR VTS_BSTR VTS_I4)
	DISP_FUNCTION_ID(CCwcaKGOcxDemoCtrl, "ImportSignCert", dispidImportSignCert, ImportSignCert, VT_I4, VTS_BSTR)
	DISP_FUNCTION_ID(CCwcaKGOcxDemoCtrl, "GenerateTempPubKey", dispidGenerateTempPubKey, GenerateTempPubKey, VT_BSTR, VTS_BSTR VTS_I4)
	DISP_FUNCTION_ID(CCwcaKGOcxDemoCtrl, "ImportCryptoCertAndKey", dispidImportCryptoCertAndKey, ImportCryptoCertAndKey, VT_I4, VTS_BSTR VTS_I4 VTS_BSTR VTS_BSTR VTS_BSTR)
END_DISPATCH_MAP()



// Event map

BEGIN_EVENT_MAP(CCwcaKGOcxDemoCtrl, COleControl)
END_EVENT_MAP()



// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CCwcaKGOcxDemoCtrl, 1)
	PROPPAGEID(CCwcaKGOcxDemoPropPage::guid)
END_PROPPAGEIDS(CCwcaKGOcxDemoCtrl)



// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CCwcaKGOcxDemoCtrl, "CWCAKGOCXDEMO.CwcaKGOcxDemoCtrl.1",
	0xd9591504, 0xf4fa, 0x4dfc, 0x86, 0x2d, 0x14, 0x19, 0x82, 0x36, 0, 0x7d)



// Type library ID and version

IMPLEMENT_OLETYPELIB(CCwcaKGOcxDemoCtrl, _tlid, _wVerMajor, _wVerMinor)



// Interface IDs

const IID BASED_CODE IID_DCwcaKGOcxDemo =
		{ 0x18A1842A, 0x7961, 0x4677, { 0x82, 0x9D, 0x3E, 0x15, 0xF4, 0x69, 0x9E, 0x91 } };
const IID BASED_CODE IID_DCwcaKGOcxDemoEvents =
		{ 0xD5455F22, 0x60A4, 0x441F, { 0x97, 0x4, 0x47, 0x24, 0x11, 0x98, 0xF7, 0xC7 } };



// Control type information

static const DWORD BASED_CODE _dwCwcaKGOcxDemoOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CCwcaKGOcxDemoCtrl, IDS_CWCAKGOCXDEMO, _dwCwcaKGOcxDemoOleMisc)



// CCwcaKGOcxDemoCtrl::CCwcaKGOcxDemoCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CCwcaKGOcxDemoCtrl

BOOL CCwcaKGOcxDemoCtrl::CCwcaKGOcxDemoCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_CWCAKGOCXDEMO,
			IDB_CWCAKGOCXDEMO,
			afxRegApartmentThreading,
			_dwCwcaKGOcxDemoOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}



// CCwcaKGOcxDemoCtrl::CCwcaKGOcxDemoCtrl - Constructor

CCwcaKGOcxDemoCtrl::CCwcaKGOcxDemoCtrl()
{
	InitializeIIDs(&IID_DCwcaKGOcxDemo, &IID_DCwcaKGOcxDemoEvents);
	// TODO: Initialize your control's instance data here.
}



// CCwcaKGOcxDemoCtrl::~CCwcaKGOcxDemoCtrl - Destructor

CCwcaKGOcxDemoCtrl::~CCwcaKGOcxDemoCtrl()
{
	// TODO: Cleanup your control's instance data here.
}



// CCwcaKGOcxDemoCtrl::OnDraw - Drawing function

void CCwcaKGOcxDemoCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	if (!pdc)
		return;

	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}



// CCwcaKGOcxDemoCtrl::DoPropExchange - Persistence support

void CCwcaKGOcxDemoCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.
}



// CCwcaKGOcxDemoCtrl::OnResetState - Reset control to default state

void CCwcaKGOcxDemoCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}



// CCwcaKGOcxDemoCtrl message handlers

BSTR CCwcaKGOcxDemoCtrl::GenerateCertRequest(LPCTSTR DN, LPCTSTR Alg, LPCTSTR keySpec, LONG keyLen)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here

	return strResult.AllocSysString();
}

LONG CCwcaKGOcxDemoCtrl::ImportSignCert(LPCTSTR p7b)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here

	return 0;
}

BSTR CCwcaKGOcxDemoCtrl::GenerateTempPubKey(LPCTSTR Alg, LONG keyLen)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: Add your dispatch handler code here

	return strResult.AllocSysString();
}

LONG CCwcaKGOcxDemoCtrl::ImportCryptoCertAndKey(LPCTSTR p7bCert, LONG keySpec, LPCTSTR encSessionKey, LPCTSTR flg, LPCTSTR encPriKey)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	// TODO: Add your dispatch handler code here

	return 0;
}
