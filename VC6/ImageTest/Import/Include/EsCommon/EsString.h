#ifndef _ES_STRING_H_
#define _ES_STRING_H_

#ifdef __cplusplus
extern "C" {
#endif

	// 为字符串定义一种调用约定。CALL_TYPE（__stdcall）是不适合变参的API定义的，字符串API参数存在变参的情况，所以必须另外定义。
//	#	define STR_CALL_TYPE __cdecl
	#	define STR_CALL_TYPE


	ESBOOL STR_CALL_TYPE EsStrCopy(char* pszDest, size_t cchDest, const char* pszSrc);
	ESBOOL STR_CALL_TYPE EsWcsCopy(wchar_t* pszDest, size_t cchDest, const wchar_t* pszSrc);

	ESBOOL STR_CALL_TYPE EsStrCat(char* pszDest, size_t cchDest, const char* pszSrc);
	ESBOOL STR_CALL_TYPE EsWcsCat(wchar_t* pszDest, size_t cchDest, const wchar_t* pszSrc);

	ESBOOL STR_CALL_TYPE EsStrPrintf(char * pszDest, size_t cchDest, const char * pszFormat, ...);
	ESBOOL STR_CALL_TYPE EsWcsPrintf(wchar_t * pszDest, size_t cchDest, const wchar_t * pszFormat, ...);

#ifndef _OS_ANDROID_
 	ESBOOL STR_CALL_TYPE EsStrVPrintf(char * pszDest, size_t cchDest, const char * pszFormat, va_list argList);
	ESBOOL STR_CALL_TYPE EsWcsVPrintf(wchar_t * pszDest, size_t cchDest, const wchar_t * pszFormat, va_list argList);
#endif


	s4 STR_CALL_TYPE EsStrICmp(const char* str1, const char* str2);
	s4 STR_CALL_TYPE EsWcsICmp(const wchar_t* str1, const wchar_t* str2);
	char * STR_CALL_TYPE EsStrLower(char *str, size_t len);
    
    ESBOOL CALL_TYPE EsStrMatchLen(const char *pszPattern, u4 u4PatternLen,
				   const char *pszString, u4 u4StringLen, ESBOOL bNoCase);
    ESBOOL CALL_TYPE EsStrMatch(const char *pszPattern, const char *pszString, ESBOOL bNoCase);

	#ifdef UNICODE
	#	define EsTcsCopy EsWcsCopy
	#	define EsTcsCat EsWcsCat
	#	define EsTcsPrintf EsWcsPrintf
	#	define EsTcsVPrintf EsWcsVPrintf
	#else
	#	define EsTcsCopy EsStrCopy
	#	define EsTcsCat EsStrCat
	#	define EsTcsPrintf EsStrPrintf
	#	define EsTcsVPrintf EsStrVPrintf
	#endif

#ifdef __cplusplus
};
#endif

#endif
