#ifndef _ES_EVENT_H_
#define _ES_EVENT_H_

#ifdef __cplusplus
extern "C" 
{
#endif

	u4 CALL_TYPE EsEventCreate(const char* szEventName, ESHANDLE* phEvent);
	u4 CALL_TYPE EsEventOpen(const char* szEventName, ESHANDLE* phEvent);
	u4 CALL_TYPE EsEventClose(ESHANDLE hEvent);
	u4 CALL_TYPE EsEventSet(ESHANDLE hEvent);
	u4 CALL_TYPE EsEventReset(ESHANDLE hEvent);
	
#define ES_WAIT_OBJ_0 0
	u4 CALL_TYPE EsEventWait(ESHANDLE hEvent, u4 u4Timeout);

#ifdef __cplusplus
};
#endif
	
#endif