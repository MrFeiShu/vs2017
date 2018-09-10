#ifndef _ES_CRITICAL_H_
#define _ES_CRITICAL_H_

#ifdef __cplusplus
extern "C" 
{
#endif

	void CALL_TYPE EsCriticalSectionCreate();
	void CALL_TYPE EsCriticalSectionDestory();
	void CALL_TYPE EsCriticalSectionEnter();
	void CALL_TYPE EsCriticalSectionLeave();

#ifdef __cplusplus
};
#endif

#endif
