///////////////////////////////////////////////////////////
//  UIProxy.h
//  Implementation of the Class CUIProxy
//  Created on:      27-十月-2012 21:33:16
//  Original author: Simon
///////////////////////////////////////////////////////////

#if !defined(EA_12C308AF_A795_4b76_811D_99B3D72A1751__INCLUDED_)
#define EA_12C308AF_A795_4b76_811D_99B3D72A1751__INCLUDED_

#include "UI.h"

enum EnUIMode
{
	UI_MODE_UNKNOWN			= 0,
	UI_MODE_INNER_DLL		= 1,
	UI_MODE_OUTER_DLL		= 2,
	UI_MODE_INTER_PROCESS	= 3
};

class CUIProxy : public IUI
{

public:
	CUIProxy();
	CUIProxy(EnUIMode enUIMode, const char* lpszSessionName, const char* pszUiModulePath);
	virtual ~CUIProxy();
	void Initialize(EnUIMode enUIMode, const char* lpszSessionName, const char* pszUiModulePath);
	void Finalize();

	// PromptUI用于同步情形
	virtual bool PromptUI(BlkUIParam& blkUIParam);

	// PreparePromptingUI、ShowPromptingUI、WaitPromptingUI、EndPromptUI用于异步情形，不要与PromptUI搭配使用
	virtual bool PreparePromptingUI(BlkUIParam& blkUIParam);
	virtual bool ShowPromptingUI(BlkUIParam& blkUIParam);
	virtual bool WaitPromptingUI(BlkUIParam& blkUIParam, unsigned int uMilliSeconds = 0xFFFFFFFF);
	virtual bool EndPromptingUI(BlkUIParam& blkUIParam);

private:
	EnUIMode			__enUIMode;
	IUI*				__pUI;
	CUIInnerDll			__objUIInnerDll;
	CUIOuterDll			__objUIOuterDll;
#ifndef _OS_MAC_OSX_
	CUIInterProcess		__objUIInterProcess;
#endif // !defined _OS_MAC_OSX_

};


#endif // !defined(EA_12C308AF_A795_4b76_811D_99B3D72A1751__INCLUDED_)
