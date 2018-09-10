#ifndef _COMMON_LOG_H_
#define _COMMON_LOG_H_
#include "../EsTypeDef.h"
#include "EsCommon.h"
#include <wchar.h>
#ifdef __cplusplus
extern "C"
{
#endif
	#define LOG_TYPE_INFORMATION	1
	#define LOG_TYPE_WARNING		2
	#define LOG_TYPE_ERROR			3
	#define FILE_AND_LINE __FILE__, __LINE__
	// 使用示例： ES_LOG((LOG_TYPE_ERROR, FILE_AND_LINE, "My Name is %s!", "Simon")); // 注意连续有两对小括号，
	// 类似驱动开发库的DebugPrint的定义，有兴趣的可以参考
#ifdef _LOG_
	#define ES_LOG(x) EsLogEx x
	#define ES_LOG_W(x) EsLogExW x
	#define ES_LOG_BYTE_ARRAY(x) EsLogByteArrayEx x
#else
	#define ES_LOG(x) 
	#define ES_LOG_W(x) 
	#define ES_LOG_BYTE_ARRAY(x) 
#endif

	extern void EsLogEx(u4 u4LogType, const char* szFile, u4 u4Line, const char *szMsgFormat, ...);
	extern void EsLogExW(u4 u4LogType, const char* szFile, u4 u4Line, const wchar_t *szMsgFormat, ...);
	extern void EsLogByteArrayEx(u4 u4LogType, const char* szFile, u4 u4Line, const u1* pu1Data, u4 u4DataLen);
#ifdef __cplusplus
}
#endif	
#endif