#ifndef _ES_TYPEDEF_H_
#define _ES_TYPEDEF_H_

#ifndef IN
#	define	IN
#endif

#ifndef OUT
#	define	OUT
#endif
#ifndef INOUT
#	define	INOUT
#endif

#ifdef _WIN32_WINNT
#	undef	_WIN32_WINNT
#endif
#define _WIN32_WINNT 0x0501

#if defined(_WINDOWS)||defined(WIN32)
	#ifdef _WP
		#define	_OS_WPHONE_
	#else
		#define	_OS_WINDOWS_
	#endif
#endif


#ifndef _U1U2U4_
#define _U1U2U4_
typedef unsigned char		u1;
typedef unsigned short		u2;
typedef signed char			s1;
typedef signed short		s2;

#if defined(_OS_WINDOWS_) || defined(_OS_WPHONE_)
	typedef unsigned long	u4;
	typedef signed long		s4;
	typedef unsigned __int64 u8;
	typedef signed __int64	 s8;
#else
	typedef unsigned int	u4;
	typedef signed int		s4;
	typedef unsigned long long	u8;
	typedef signed long long	s8;
#endif
#endif	// END _U1U2U4_

typedef void*				ESHANDLE;

#ifndef ES_PTR
#define ES_PTR *
#endif // END ES_PTR

#ifndef NULL
#define NULL 0
#endif

#ifndef _ES_UTFCHAR_
#define _ES_UTFCHAR_
typedef char ES_UTF8CHAR;
typedef ES_UTF8CHAR ES_PTR ES_UTF8CHAR_PTR;
#endif // END _ES_UTFCHAR_

typedef enum EnBool
{
	ESFALSE = 0,
	ESTRUE = 1,
}ESBOOL;

// KEY charset & language
typedef enum EnCharSet
{
	CHAR_SET_UNKNOWN	= -1,
	CHAR_SET_UTF8		= 0,
	CHAR_SET_GBK		= 1,
	CHAR_SET_GB18030	= 2,
	CHAR_SET_GB2312		= 3,
}EnCharSet;

typedef enum EnLangId
{
	LANGUAGE_ID_UNKNOWN				= -1,
	LANGUAGE_ID_SIMPLIFIED_CHINESE	= 0,
	LANGUAGE_ID_ENGLISH				= 1,
	LANGUAGE_ID_TRADITIONAL_CHINESE = 2,
	LANGUAGE_ID_FRENCH				= 3,
	LANGUAGE_ID_RUSSIAN				= 4,
	LANGUAGE_ID_JAPANESE			= 5,
	LANGUAGE_ID_INDONESIAN			= 6,
	LANGUAGE_ID_GERMAN				= 7,
	LANGUAGE_ID_ARABIC				= 8,
	LANGUAGE_ID_KOREAN				= 9,
	LANGUAGE_ID_KAZAKH				= 10,
	LANGUAGE_ID_THAI				= 11,
	LANGUAGE_ID_POLISH				= 12,
}EnLangId;



#ifdef _OS_WINDOWS_
	#define CALL_TYPE			__stdcall
#else
	#define CALL_TYPE
#endif


//#include <EsCommon/EsCommonLog.h>
//#define IF_ERROR_GOTO_END()			do{if( 0 != u4Result ) {ES_LOG((LOG_TYPE_INFORMATION, FILE_AND_LINE, "u4Result = %08X", u4Result));goto END;}}while(0)

// #define IF_ERROR_GOTO_END()			do{if( 0 != u4Result ) {goto END;}}while(0)

// #ifndef _OS_WINDOWS_
//     #define stricmp strcasecmp
// #endif

//#if defined(_OS_MAC_OSX_)||defined(_OS_IOS_)||defined(_OS_ANDROID_)
// #   define  INFINITE	0xFFFFFFFF
// #   define MAX_PATH     260
// #   define memicmp		strncasecmp
// #   define _memicmp		memicmp
// #   define _stricmp		stricmp
//#endif //_OS_MAC_OSX_

#endif // _ES_TYPEDEF_H_
