// ShareMemoryUtil.h: interface for the ShareMemoryUtil class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(ES_COMMON_IPC__INCLUDED_)
#define ES_COMMON_IPC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <Windows.h>

// �����ڴ�����
typedef struct tagShareMemoryData
{
	// �����ڴ����ݾ����ͬһ�����ڴ������ڲ�ͬ�Ľ��̵ľ��һ���ǲ�һ�µ�
	HANDLE hMapFile;
	
	// ������㣨��δȷ��������һ�ֻ��ƣ������ڴ����ݵĵ�4k-1����0���������ֽڴ��һЩ��ǣ�
	LPVOID pvMapFile;
	
	// ����ͬ�������ڴ�����
	HANDLE hMutex;
	
	// ���źű�ʾ�й����ڴ����ݴ����� �ͻ������ô��¼�
	HANDLE hEventBegin;
	
	// ���źű�ʾ�����ڴ����ݴ������ ���������ô��¼�
	HANDLE hEventEnd;

	// ���������¼������첽UI����
	// ���첽����£�hEventEndѸ�ٱ����������ã���ʾ������������UI���󣬲����������ƴ���
	//	�����潻�����̲�δ��ɣ����滹�ڣ���������������������¼��õ����յĽ������
	
	// ���źű�ʾ�����������ͻ��˷������������ô��¼�
	HANDLE hEventFinish;

	// ���źű�ʾ����ȡ�����������ͻ��˾������ô��¼�����һ���ɷ��������ã���ȡ�������ͻ��˵ȴ����¼�
	HANDLE hEventCancel;
	
}BlkUIShmData;

// WYL 2012.10.28 
// �����ڴ��Ǹ����ϴ��룬��Щ�����߼��Ƚ���⣬������֮�������Ľ�
namespace ShareMemoryUtil2
{
#if defined(__cplusplus)
extern "C"
{
#endif

// �����ڴ�Ĵ�С
#define MAX_SHARE_MEMORY_SIZE		(1024*64)
	
long __stdcall CreateShareMemory(BlkUIShmData* pblkUIShmData, const char* szTokenName);
long __stdcall OpenShareMemory(BlkUIShmData* pblkUIShmData, const char* szTokenName);
long __stdcall CloseShareMemory(BlkUIShmData* pblkUIShmData); 
		
#if defined(__cplusplus)
};
#endif
}

#endif // !defined(AFX_SHAREMEMORYUTIL_H__2953D628_9592_4FCC_AEA2_A97D4BABA8AE__INCLUDED_)
