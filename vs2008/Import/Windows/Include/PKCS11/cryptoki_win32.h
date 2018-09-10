/******************************************************************************
** 
**  $Id: cryptoki_win32.h,v 1.1.1.1 2005/08/05 03:30:11 administrator Exp $
**
**  Package: PKCS-11
**  Author : Chris Osgood <oznet@mac.com>
**  License: Copyright (C) 2002 Schlumberger Network Solutions
**           <http://www.slb.com/sns>
**  Purpose: WIN32 specific cryptoki definitions
** 
******************************************************************************/

#ifndef __CRYPTOKI_WIN32_H__
#define __CRYPTOKI_WIN32_H__



#ifdef WIN32
#pragma pack(push, cryptoki, 1)

/* Specifies that the function is a DLL entry point. */
#ifdef CRYPTOKI_LOADLIBRARY
	#define CK_IMPORT_SPEC
#else
	#define CK_IMPORT_SPEC __declspec(dllimport)
#endif

/* Define CRYPTOKI_EXPORTS during the build of cryptoki libraries. Do
 * not define it in applications.
 */
#ifdef CRYPTOKI_EXPORTS
/* Specified that the function is an exported DLL entry point. */
    #define CK_EXPORT_SPEC __declspec(dllexport) 
#else
    #define CK_EXPORT_SPEC CK_IMPORT_SPEC 
#endif

/* Ensures the calling convention for Win32 builds */
#define CK_CALL_SPEC __cdecl

#define CK_PTR *
#define CK_DEFINE_FUNCTION(returnType, name) \
  returnType CK_EXPORT_SPEC CK_CALL_SPEC name

#define CK_DECLARE_FUNCTION(returnType, name) \
  returnType CK_EXPORT_SPEC CK_CALL_SPEC name

#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
  returnType CK_IMPORT_SPEC (CK_CALL_SPEC CK_PTR name)

#define CK_CALLBACK_FUNCTION(returnType, name) \
  returnType (CK_CALL_SPEC CK_PTR name)

#ifndef NULL_PTR
#define NULL_PTR 0
#endif

#include "pkcs11.h"

#pragma pack(pop,cryptoki)

#else

#ifdef CGB_VERSION
#pragma pack(push, cryptoki, 1)
#endif

#define	CK_ENTRY
#define CK_IMPORT_SPEC
#define CK_EXPORT_SPEC 
#define CK_CALL_SPEC
#define CK_PTR *

#define CK_DEFINE_FUNCTION(returnType, name) \
  returnType CK_EXPORT_SPEC CK_CALL_SPEC name

#define CK_DECLARE_FUNCTION(returnType, name) \
  returnType CK_EXPORT_SPEC CK_CALL_SPEC name

#define CK_DECLARE_FUNCTION_POINTER(returnType, name) \
  returnType CK_IMPORT_SPEC (CK_CALL_SPEC CK_PTR name)

#define CK_CALLBACK_FUNCTION(returnType, name) \
  returnType (CK_CALL_SPEC CK_PTR name)

#ifndef NULL_PTR
#define NULL_PTR 0
#endif

#include "pkcs11.h"

#ifdef CGB_VERSION
#pragma pack(pop,cryptoki)
#endif


#endif


#endif /* __CRYPTOKI_WIN32_H__ */
