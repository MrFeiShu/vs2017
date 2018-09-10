// CwcaKGOcxDemo.cpp : Implementation of CCwcaKGOcxDemoApp and DLL registration.

#include "stdafx.h"
#include "CwcaKGOcxDemo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CCwcaKGOcxDemoApp theApp;

const GUID CDECL BASED_CODE _tlid =
		{ 0x96D09F07, 0xCEF9, 0x4697, { 0x85, 0xB6, 0x1A, 0x8E, 0xA6, 0xAD, 0x6D, 0x42 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CCwcaKGOcxDemoApp::InitInstance - DLL initialization

BOOL CCwcaKGOcxDemoApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: Add your own module initialization code here.
	}

	return bInit;
}



// CCwcaKGOcxDemoApp::ExitInstance - DLL termination

int CCwcaKGOcxDemoApp::ExitInstance()
{
	// TODO: Add your own module termination code here.

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
