//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2012,深圳市文鼎创数据安全有限公司
// All rights reserved.
// 
// 文件名称：
//		UI.h
//
// 文件标识：
//
// 摘   要：
//		定义界面接口以及多种界面实现类。其中CUIInnerDll，CUIOuterDll暂不实现，为以后预留。
//		CUIInterProcess为跨进程界面类，我们目前实际使用的就是该类。
// 
// 当前版本：
//		1.0
//
// 作   者：
//		伍友良
//
// 完成日期：
//		2012年12月04日
//////////////////////////////////////////////////////////////////////////


#if !defined(EA_04E4A078_408F_43dd_A156_3D49F2A004E8__INCLUDED_)
#define EA_04E4A078_408F_43dd_A156_3D49F2A004E8__INCLUDED_

#include <EsUi/UIParam.h>

#define ENABLE_VIRTUAL_DESKTOP
// 界面接口
class IUI
{
public:
	virtual bool PromptUI(BlkUIParam& blkUIParam) =0;
	virtual bool PreparePromptingUI(BlkUIParam& blkUIParam) = 0;
	virtual bool ShowPromptingUI(BlkUIParam& blkUIParam) = 0;
	virtual bool WaitPromptingUI(BlkUIParam& blkUIParam, unsigned int uMilliSeconds = 0xFFFFFFFF) = 0;
	virtual bool EndPromptingUI(BlkUIParam& blkUIParam) = 0;
};

// 模块内界面类实现，暂不实现，为将来预留
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

// 外挂界面类实现，暂不实现，为将来预留
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
// 跨进程界面类实现
#include "../include/UIManagementClient.h"
class CUIInterProcess : public IUI
{	
public:
	CUIInterProcess();
	virtual ~CUIInterProcess();
	bool Initialize(const char* lpszSessionName, const char* pszUiModulePath);
	bool Finialize();

	// 实现IUI接口方法
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
