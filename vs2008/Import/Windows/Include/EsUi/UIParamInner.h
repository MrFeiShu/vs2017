///////////////////////////////////////////////////////////
//  UIParamInner.h
//  Some type definitions
//  Created on:      27-十月-2012 21:33:15
//  Original author: Simon
///////////////////////////////////////////////////////////

#if !defined(EA_37552088_CC47_4b76_8933_04ECD020300A__INCLUDED_)
#define EA_37552088_CC47_4b76_8933_04ECD020300A__INCLUDED_

// 本头文件定义的各种数据类型可以被客户端类和服务器类同时使用，但不能被客户代码使用。
// 也就是说，这些数据类型是不对外开放的。


// UIParamInner定义了客户端与服务的内部通讯协议
typedef struct tagUIParamInner
{
	enum EnUIPIType
	{
		UIPIT_UNKNOWN				= 0,				// 无效的值
		UIPIT_CONNECT_INTERACTION	= 1,				// 连接一个会话
		UIPIT_FINISH_INTERACTION	= 2,				// 结束会话 
	}type;

	enum EnUIPIResult
	{
		UIPIR_NOT_PROCESSED			= 0,
		UIPIR_FAILURE				= 1,
		UIPIR_SUCCESS				= 2
	}result;

	struct UIPIData
	{
		// 交互会话ID
		unsigned int		uInteractionID;
		// 当type为UIPIT_CONNECT_INTERACTION的时候，szTokenName若不为空，则以此名字创建交互会话，
		// 否则，服务器自动生成一个名字(UUID)创建交互会话，并将生成的名字回填至szTokenName
		wchar_t				szSessionName[256];
		unsigned int		uServerPid; // UI服务器的PID
	}data;

}BlkUIParamInner;

#endif // !defined(EA_37552088_CC47_4b76_8933_04ECD020300A__INCLUDED_)
