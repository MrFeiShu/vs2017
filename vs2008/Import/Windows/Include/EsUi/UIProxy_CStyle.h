#ifndef _UI_PROXY_C_STYLE_H_
#define _UI_PROXY_C_STYLE_H_

#include "UIParam.h"
#define UI_WAIT_INTERVAL 200 // “‘∫¡√Îº∆
#ifdef __cplusplus
extern "C"
{
#endif	
	extern ESBOOL UiInit(ESBOOL bNoUi, u4 u4SessionId, const char* pszUiModulePath);
	extern ESBOOL UiFinal();
	extern ESBOOL UiPrompt(BlkUIParam* pblkUIParam);
	extern ESBOOL UiPreparePrompting(BlkUIParam* pblkUIParam);
	extern ESBOOL UiShowPrompting(BlkUIParam* pblkUIParam);
	extern ESBOOL UiWaitPrompting(BlkUIParam* pblkUIParam, u4 u4MilliSeconds);
	extern ESBOOL UiEndPrompting(BlkUIParam* pblkUIParam);
	extern ESHANDLE UiGetCurrentModuleHandle();
#ifdef __cplusplus
}
#endif	
#endif