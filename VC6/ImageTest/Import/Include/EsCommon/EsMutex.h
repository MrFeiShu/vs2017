#ifndef _ES_MUTEX_H_
#define _ES_MUTEX_H_

#ifdef __cplusplus
extern "C" 
{
#endif

	u4 CALL_TYPE EsMutexCreate(const char* szMutexName, ESHANDLE* phMutex); // szMutexName can be NULL
	u4 CALL_TYPE EsMutexOpen(const char* szMutexName, ESHANDLE* phMutex);
	u4 CALL_TYPE EsMutexWait(ESHANDLE hMutex, u4 u4TimeOut);
	u4 CALL_TYPE EsMutexRelease(ESHANDLE hMutex);
	u4 CALL_TYPE EsMutexDestroy(ESHANDLE hMutex);

#ifdef __cplusplus
};
#endif

#endif

	