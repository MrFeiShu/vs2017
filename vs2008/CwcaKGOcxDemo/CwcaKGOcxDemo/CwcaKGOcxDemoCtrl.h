#pragma once

// CwcaKGOcxDemoCtrl.h : Declaration of the CCwcaKGOcxDemoCtrl ActiveX Control class.


// CCwcaKGOcxDemoCtrl : See CwcaKGOcxDemoCtrl.cpp for implementation.

class CCwcaKGOcxDemoCtrl : public COleControl
{
	DECLARE_DYNCREATE(CCwcaKGOcxDemoCtrl)

// Constructor
public:
	CCwcaKGOcxDemoCtrl();

// Overrides
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// Implementation
protected:
	~CCwcaKGOcxDemoCtrl();

	DECLARE_OLECREATE_EX(CCwcaKGOcxDemoCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CCwcaKGOcxDemoCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CCwcaKGOcxDemoCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CCwcaKGOcxDemoCtrl)		// Type name and misc status

// Message maps
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	DECLARE_DISPATCH_MAP()

// Event maps
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
		dispidImportCryptoCertAndKey = 4L,
		dispidGenerateTempPubKey = 3L,
		dispidImportSignCert = 2L,
		dispidGenerateCertRequest = 1L
	};
protected:
	BSTR GenerateCertRequest(LPCTSTR DN, LPCTSTR Alg, LPCTSTR keySpec, LONG keyLen);
	LONG ImportSignCert(LPCTSTR p7b);
	BSTR GenerateTempPubKey(LPCTSTR Alg, LONG keyLen);
	LONG ImportCryptoCertAndKey(LPCTSTR p7bCert, LONG keySpec, LPCTSTR encSessionKey, LPCTSTR flg, LPCTSTR encPriKey);
};

