//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2012,�������Ķ������ݰ�ȫ���޹�˾
// All rights reserved.
// 
// �ļ����ƣ�
//		UI.h
//
// �ļ���ʶ��
//
// ժ   Ҫ��
//		�������ӿ��Լ����ֽ���ʵ���ࡣ����CUIInnerDll��CUIOuterDll�ݲ�ʵ�֣�Ϊ�Ժ�Ԥ����
//		CUIInterProcessΪ����̽����࣬����Ŀǰʵ��ʹ�õľ��Ǹ��ࡣ
// 
// ��ǰ�汾��
//		1.0
//
// ��   �ߣ�
//		������
//
// ������ڣ�
//		2012��12��04��
//////////////////////////////////////////////////////////////////////////


#if !defined(EA_04E4A078_408F_43dd_A156_3D49F2A004E8__INCLUDED_)
#define EA_04E4A078_408F_43dd_A156_3D49F2A004E8__INCLUDED_

#include <EsUi/UIParam.h>

#define ENABLE_VIRTUAL_DESKTOP
// ����ӿ�
class IUI
{
public:
	virtual bool PromptUI(BlkUIParam& blkUIParam) =0;
	virtual bool PreparePromptingUI(BlkUIParam& blkUIParam) = 0;
	virtual bool ShowPromptingUI(BlkUIParam& blkUIParam) = 0;
	virtual bool WaitPromptingUI(BlkUIParam& blkUIParam, unsigned int uMilliSeconds = 0xFFFFFFFF) = 0;
	virtual bool EndPromptingUI(BlkUIParam& blkUIParam) = 0;
};

// ģ���ڽ�����ʵ�֣��ݲ�ʵ�֣�Ϊ����Ԥ��
class CUIInnerDll : public IUI
{	
public:
	CUIInnerDll();
	virtual ~CUIInnerDll();
	virtual bool PromptUI(BlkUIParam& blkUIParam);
	virtual bool PreparePromptingUI(BlkUIParam& blkUIParam);
	virtual bool ShowPromptingUI(BlkUIParam& blkUIParam);
	virtual bool WaitPromptingUI(BlkUIParam& blkUIParam, unsigned int uMilliSeconds = 0xFFFFFFFF);
	virtual bool EndPromptingUI(BlkUIParam& blkUIParam);
};

// ��ҽ�����ʵ�֣��ݲ�ʵ�֣�Ϊ����Ԥ��
class CUIOuterDll : public IUI
{	
public:
	CUIOuterDll();
	virtual ~CUIOuterDll();
	
	virtual bool PromptUI(BlkUIParam& blkUIParam);

	virtual bool PreparePromptingUI(BlkUIParam& blkUIParam);
	virtual bool ShowPromptingUI(BlkUIParam& blkUIParam);
	virtual bool WaitPromptingUI(BlkUIParam& blkUIParam, unsigned int uMilliSeconds = 0xFFFFFFFF);
	virtual bool EndPromptingUI(BlkUIParam& blkUIParam);
};

#ifndef _OS_MAC_OSX_
// ����̽�����ʵ��
#include "../include/UIManagementClient.h"
class CUIInterProcess : public IUI
{	
public:
	CUIInterProcess();
	virtual ~CUIInterProcess();
	bool Initialize(const char* lpszSessionName, const char* pszUiModulePath);
	bool Finialize();

	// ʵ��IUI�ӿڷ���
	virtual bool PromptUI(BlkUIParam& blkUIParam);
	virtual bool PreparePromptingUI(BlkUIParam& blkUIParam);
	virtual bool ShowPromptingUI(BlkUIParam& blkUIParam);
	virtual bool WaitPromptingUI(BlkUIParam& blkUIParam, unsigned int uMilliSeconds = 0xFFFFFFFF);
	virtual bool EndPromptingUI(BlkUIParam& blkUIParam);
protected:
	void SelectUiClient(const BlkUIParam& blkUIParam, CUIManagementClient** ppUIClient);
private:	
	CUIManagementClient* __pUIClient;
	CUIManagementClient* __pUIClientVirtualDesktop;
	bool __bInitializationOk;
	char __szSessionName[256];
};
#endif // !defined _OS_MAC_OSX_
#endif // !defined(EA_04E4A078_408F_43dd_A156_3D49F2A004E8__INCLUDED_)
