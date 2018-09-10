#ifndef _ESCONFIG_H_
#define _ESCONFIG_H_

#if defined(__cplusplus)
extern "C"
{
#endif

u4 CALL_TYPE EsCfgGetChild(ESHANDLE hParent, const char* pszChildName, ESHANDLE* phChild, u4* pu4ChildCount);
u4 CALL_TYPE EsCfgSetLanguage(u4 u4LanguageId);
u4 CALL_TYPE EsCfgGetLanguage(u4* pu4LanguageId);
u4 CALL_TYPE EsCfgRelease(void);
u4 CALL_TYPE EsCfgInit(const char* szCfgFileName);
u4 CALL_TYPE EsCfgGetData(ESHANDLE hNode, EN_CFGTYPE enCfgType, void* pvValue, u4* pu4ValueLen);
u4 CALL_TYPE EsCfgGetDataWithAlloc(ESHANDLE hNode, EN_CFGTYPE enCfgType, void** ppvValue, u4* pu4ValueLen);
u4 CALL_TYPE EsCfgFreeData(void* pvData);

#if defined(__cplusplus)
};
#endif

#endif
