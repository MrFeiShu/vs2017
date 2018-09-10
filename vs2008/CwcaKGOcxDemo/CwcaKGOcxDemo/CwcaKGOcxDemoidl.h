

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Sat May 19 17:13:51 2018
 */
/* Compiler settings for .\CwcaKGOcxDemo.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __CwcaKGOcxDemoidl_h__
#define __CwcaKGOcxDemoidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DCwcaKGOcxDemo_FWD_DEFINED__
#define ___DCwcaKGOcxDemo_FWD_DEFINED__
typedef interface _DCwcaKGOcxDemo _DCwcaKGOcxDemo;
#endif 	/* ___DCwcaKGOcxDemo_FWD_DEFINED__ */


#ifndef ___DCwcaKGOcxDemoEvents_FWD_DEFINED__
#define ___DCwcaKGOcxDemoEvents_FWD_DEFINED__
typedef interface _DCwcaKGOcxDemoEvents _DCwcaKGOcxDemoEvents;
#endif 	/* ___DCwcaKGOcxDemoEvents_FWD_DEFINED__ */


#ifndef __CwcaKGOcxDemo_FWD_DEFINED__
#define __CwcaKGOcxDemo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CwcaKGOcxDemo CwcaKGOcxDemo;
#else
typedef struct CwcaKGOcxDemo CwcaKGOcxDemo;
#endif /* __cplusplus */

#endif 	/* __CwcaKGOcxDemo_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __CwcaKGOcxDemoLib_LIBRARY_DEFINED__
#define __CwcaKGOcxDemoLib_LIBRARY_DEFINED__

/* library CwcaKGOcxDemoLib */
/* [control][helpstring][helpfile][version][uuid] */ 


EXTERN_C const IID LIBID_CwcaKGOcxDemoLib;

#ifndef ___DCwcaKGOcxDemo_DISPINTERFACE_DEFINED__
#define ___DCwcaKGOcxDemo_DISPINTERFACE_DEFINED__

/* dispinterface _DCwcaKGOcxDemo */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DCwcaKGOcxDemo;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("18A1842A-7961-4677-829D-3E15F4699E91")
    _DCwcaKGOcxDemo : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DCwcaKGOcxDemoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DCwcaKGOcxDemo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DCwcaKGOcxDemo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DCwcaKGOcxDemo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DCwcaKGOcxDemo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DCwcaKGOcxDemo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DCwcaKGOcxDemo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DCwcaKGOcxDemo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DCwcaKGOcxDemoVtbl;

    interface _DCwcaKGOcxDemo
    {
        CONST_VTBL struct _DCwcaKGOcxDemoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DCwcaKGOcxDemo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DCwcaKGOcxDemo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DCwcaKGOcxDemo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DCwcaKGOcxDemo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DCwcaKGOcxDemo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DCwcaKGOcxDemo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DCwcaKGOcxDemo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DCwcaKGOcxDemo_DISPINTERFACE_DEFINED__ */


#ifndef ___DCwcaKGOcxDemoEvents_DISPINTERFACE_DEFINED__
#define ___DCwcaKGOcxDemoEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DCwcaKGOcxDemoEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__DCwcaKGOcxDemoEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("D5455F22-60A4-441F-9704-47241198F7C7")
    _DCwcaKGOcxDemoEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DCwcaKGOcxDemoEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DCwcaKGOcxDemoEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DCwcaKGOcxDemoEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DCwcaKGOcxDemoEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DCwcaKGOcxDemoEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DCwcaKGOcxDemoEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DCwcaKGOcxDemoEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DCwcaKGOcxDemoEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DCwcaKGOcxDemoEventsVtbl;

    interface _DCwcaKGOcxDemoEvents
    {
        CONST_VTBL struct _DCwcaKGOcxDemoEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DCwcaKGOcxDemoEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DCwcaKGOcxDemoEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DCwcaKGOcxDemoEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DCwcaKGOcxDemoEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DCwcaKGOcxDemoEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DCwcaKGOcxDemoEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DCwcaKGOcxDemoEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DCwcaKGOcxDemoEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CwcaKGOcxDemo;

#ifdef __cplusplus

class DECLSPEC_UUID("BB19C61F-5D34-4e6d-9A2B-5A93D6613097")
CwcaKGOcxDemo;
#endif
#endif /* __CwcaKGOcxDemoLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


