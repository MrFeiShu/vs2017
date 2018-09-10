#ifndef _ES_OUTPUT_STR_H_
#define _ES_OUTPUT_STR_H_

#ifdef __cplusplus
extern "C"
{
#endif

#if 0
#		define OutputDebugStr_Str(szTitle)								_OutputDebugStr_Str(szTitle)
#		define OutputDebugStr_DWORD(szTitle, dwData)					_OutputDebugStr_DWORD(szTitle, dwData)
#		define OutputDebugStr_BOOL(szTitle, bValue)						_OutputDebugStr_BOOL(szTitle, bValue)
#		define OutputDebugStr_ByteArray(szTitle, pbData, dwDataLen)		_OutputDebugStr_ByteArray(szTitle, pbData, dwDataLen)
//#		define OutputDebugStr_Fmt(szFmt, ...)							_OutputDebugStr_Fmt(szFmt, __VA_ARGS__)
#else
#		define OutputDebugStr_Str(szTitle)
#		define OutputDebugStr_DWORD(szTitle, dwData)
#		define OutputDebugStr_BOOL(szTitle, bValue)
#		define OutputDebugStr_ByteArray(szTitle, pbData, dwDataLen)
//#		define OutputDebugStr_Fmt(szFmt, ...)
#endif
	void _OutputDebugStr_Str(char* szTitle);	
	void _OutputDebugStr_DWORD(char* szTitle, u4 dwData);
	void _OutputDebugStr_BOOL(char* szTitle, int bValue);
	void _OutputDebugStr_ByteArray(char* szTitle, u1* pbData, u4 dwDataLen);
	void _OutputDebugStr_Fmt(char* szFmt, ...);

#ifdef __cplusplus
}
#endif

#endif
