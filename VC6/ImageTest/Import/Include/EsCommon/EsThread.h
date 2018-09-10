#ifndef _ES_THREAD_H_
#define _ES_THREAD_H_

#ifdef __cplusplus
extern "C" 
{
#endif

	typedef enum EnThreadState
	{
		ESTHREAD_STATE_RUNNING          = 1,
		ESTHREAD_STATE_TO_BE_EXITED     = 2,
		ESTHREAD_STATE_EXITED           = 3
	}EnThreadState;

	
	typedef u4 (CALL_TYPE *FunThreadCallBack)(void*);
	// ����һ���߳�
	u4 CALL_TYPE EsThreadBegin(FunThreadCallBack funCallBack, void* pvParam, ESHANDLE* phThread);
	// �̺߳����ж��Ƿ����߳�Ҫ���Լ��˳�
	ESBOOL CALL_TYPE EsThreadShouldExit(ESHANDLE hThread);
	// �ⲿҪ���߳̽������ȴ��߳��˳�
	u4 CALL_TYPE EsThreadEnd(ESHANDLE hThread);
	// �ر��߳̾�������ͷž�������ȴ��߳��˳���
	u4 CALL_TYPE EsThreadCloseHandle(ESHANDLE hThread);
	u4 CALL_TYPE EsThreadGetState(ESHANDLE hThread);
	u4 CALL_TYPE EsThreadSetState(ESHANDLE hThread, u4 u4State);

#ifdef __cplusplus
};
#endif

#endif