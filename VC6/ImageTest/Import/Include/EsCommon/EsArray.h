#ifndef _ES_ARRAY_H_
#define _ES_ARRAY_H_

#ifdef __cplusplus
extern "C"
{
#endif

	u4 CALL_TYPE EsArrayInit(ESHANDLE* phHandle);
	u4 CALL_TYPE EsArrayAppend(ESHANDLE hHandle, const void* pvData, u4 u4DataSize);
	void* CALL_TYPE EsArrayGetData(ESHANDLE hHandle);
	u4 CALL_TYPE EsArrayGetSize(ESHANDLE hHandle);
	u4 CALL_TYPE EsArrayRelease(ESHANDLE hHandle);

#ifdef __cplusplus
};
#endif


#endif