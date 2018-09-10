#ifndef _ES_SHARE_MEM_H_
#define _ES_SHARE_MEM_H_

#ifdef __cplusplus
extern "C" 
{
#endif

	u4 CALL_TYPE EsShareMemOpen(const char* szMapName, u4 u4Size, ESHANDLE* phMap);
	u4 CALL_TYPE EsShareMemClose(ESHANDLE hMap);
	u4 CALL_TYPE EsShareMemGetData(ESHANDLE hMap, void** ppvMap);
	u4 CALL_TYPE EsShareMemLock(ESHANDLE hMap);
	u4 CALL_TYPE EsShareMemUnlock(ESHANDLE hMap);

	u4 CALL_TYPE EsShareMemGetSize(ESHANDLE hMap, u4* pu4Size);
	u4 CALL_TYPE EsShareMemGetAttachCount(ESHANDLE hMap, u4*pu4Count);
	u4 CALL_TYPE EsShareMemRead(ESHANDLE hMap, u4 u4Offset, void* pvData, u4 u4DataLen); // only for windows now
	u4 CALL_TYPE EsShareMemWrite(ESHANDLE hMap, u4 u4Offset, const void* pvData, u4 u4DataLen); // only for windows now

#ifdef __cplusplus
};
#endif

#endif