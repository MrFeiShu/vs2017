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
	// 启动一个线程
	u4 CALL_TYPE EsThreadBegin(FunThreadCallBack funCallBack, void* pvParam, ESHANDLE* phThread);
	// 线程函数判断是否有线程要求自己退出
	ESBOOL CALL_TYPE EsThreadShouldExit(ESHANDLE hThread);
	// 外部要求线程结束并等待线程退出
	u4 CALL_TYPE EsThreadEnd(ESHANDLE hThread);
	// 关闭线程句柄（仅释放句柄，不等待线程退出）
	u4 CALL_TYPE EsThreadCloseHandle(ESHANDLE hThread);
	u4 CALL_TYPE EsThreadGetState(ESHANDLE hThread);
	u4 CALL_TYPE EsThreadSetState(ESHANDLE hThread, u4 u4State);

#ifdef __cplusplus
};
#endif

#endif