// ShareMemoryUtil.h: interface for the ShareMemoryUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(ES_COMMON_IPC__INCLUDED_)
#define ES_COMMON_IPC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Windows.h>

// 共享内存数据
typedef struct tagShareMemoryData
{
	// 共享内存数据句柄，同一共享内存数据在不同的进程的句柄一般是不一致的
	HANDLE hMapFile;
	
	// 这里打算（还未确定）引入一种机制：共享内存数据的第4k-1（从0计数）个字节存放一些标记，
	LPVOID pvMapFile;
	
	// 用于同步共享内存数据
	HANDLE hMutex;
	
	// 有信号表示有共享内存数据待处理 客户端设置此事件
	HANDLE hEventBegin;
	
	// 有信号表示共享内存数据处理完毕 服务器设置此事件
	HANDLE hEventEnd;

	// 以下两个事件用于异步UI处理
	// 在异步情况下，hEventEnd迅速被服务器设置，表示服务器接受了UI请求，并做出了妥善处理，
	//	但界面交互过程并未完成（界面还在），因此依赖于以下两个事件得到最终的交互结果
	
	// 有信号表示交互结束，客户端服务器均可设置此事件
	HANDLE hEventFinish;

	// 有信号表示交互取消，服务器客户端均可设置此事件，但一般由服务器设置（软取消），客户端等待此事件
	HANDLE hEventCancel;
	
}BlkUIShmData;

// WYL 2012.10.28 
// 共享内存是复用老代码，这些代码逻辑比较糟糕，姑且用之，后续改进
namespace ShareMemoryUtil2
{
#if defined(__cplusplus)
extern "C"
{
#endif

// 共享内存的大小
#define MAX_SHARE_MEMORY_SIZE		(1024*64)
	
long __stdcall CreateShareMemory(BlkUIShmData* pblkUIShmData, const char* szTokenName);
long __stdcall OpenShareMemory(BlkUIShmData* pblkUIShmData, const char* szTokenName);
long __stdcall CloseShareMemory(BlkUIShmData* pblkUIShmData); 
		
#if defined(__cplusplus)
};
#endif
}

#endif // !defined(AFX_SHAREMEMORYUTIL_H__2953D628_9592_4FCC_AEA2_A97D4BABA8AE__INCLUDED_)
