//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2013,深圳市文鼎创数据安全有限公司
// All rights reserved.
// 
// 文件名称：
//		EsCommunication.h
//
// 文件标识：
//
// 摘   要：
//		通讯接口。本接口提供一组接口，这一组接口实现的功能是实现跨进程通信、网络通讯功能。
//		这组接口具有如下特征：
//		1）透明
//		使用者无需关心具体通讯协议及其实现细节；
//		2）方便
//		提供非常人性化的接口原型，使得其非常直观易用。
//		本接口的设计理念采用的是点对点模式，而非C/S模式。
// 
// 当前版本：
//		1.0
//
// 作   者：
//		伍友良
//
// 完成日期：
//		2013年07月02日
//////////////////////////////////////////////////////////////////////////

#ifndef _ES_COMMUNICATION_H_
#define _ES_COMMUNICATION_H_

#include "./EsTypeDef.h"
#include "./EsError.h"

#define MAX_MODULE_PATH_LEN			260
#define MAX_SESSION_NAME_LEN	260

typedef enum EN_COMM_PROTOCAL
{
	PROTOCAL_IMPOSSIBLE = 0, // 未初始化的值，不可用
	PROTOCAL_SHARE_MEM,
	PROTOCAL_SOCKET,
	PROTOCAL_MAX_VALUE // 哨兵，超过此值，表示无效值
}EN_COMM_SIGNAL;


typedef struct BlkCommShmInitParamTag 
{
	ESBOOL	m_bAutoStartOtherSide; // 如果另一方没有启动，是否自动启动之
	char	m_szOtherSidePath[MAX_MODULE_PATH_LEN]; // 另一方的路径，如果m_bAutoStartOtherSide为ESFALSE，此字段忽略
	char	m_szSessionName[MAX_SESSION_NAME_LEN]; // 会话名称
	u4		m_u4ShmSize; // 共享内存的大小，以字节计算
}BlkCommShmInitParam;


typedef struct BlkCommInitParamTag 
{
	EN_COMM_PROTOCAL m_enProtocal;
	union
	{
		// 共享内存协议初始化参数
		BlkCommShmInitParam m_blkShmInitParam;
		// 暂不支持socket协议
	}m_unData;
	
}BlkCommInitParam;



typedef enum EN_COMMUNICATION_SIGNAL
{
	SIGNAL_IMPOSSIBLE = 0, // 未初始化的值，不可用
	SIGNAL_CONNECTED, // 作为服务器的一方设置此信号，而另一方如果等到此信号说明对方已经建立好连接
	SIGNAL_COMMITED, // 需要提交数据的一方设置此信号，而另一方如果等到此信号说明对方已经提交了数据
	SIGNAL_FINISHED, // 完成数据处理的一方设置此信号，而另一方如果等到此信号说明对方已经完成了数据处理
	SIGNAL_CANCELED, // 取消数据处理的一方设置此信号，而另一方如果等到此信号说明对方已经取消了数据处理
	SIGNAL_TERMINATED, 
	SIGNAL_UPDATED,
	SIGNAL_MAX_VALUE // 哨兵，超过此值，表示无效值
}EN_COMMUNICATION_SIGNAL;

typedef struct BlkCommNotifyDataTag
{
	EN_COMMUNICATION_SIGNAL		m_enSignal;
	u1*							m_pu1Data;
	u4							m_u4DataLen;
}BlkCommNotifyData;

#ifdef __cplusplus
extern "C"
{
#endif
	//////////////////////////////////////////////////////////////////////////
	//	函数说明:  
	//		建立通讯会话。
	//
	//	函数参数：
	//		[in]pblkParam:				通讯会话的初始化参数
	//		[out]phSession:				通讯会话的句柄
	//
	// 返回值:
	//		见错误码定义
	//
	// 作者:
	//		伍友良
	// 日期:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommConnect(IN const BlkCommInitParam* pblkParam, IN u4 u4TimeOutMilSecs, OUT ESHANDLE* phSession);

	//////////////////////////////////////////////////////////////////////////
	//	函数说明:  
	//		以服务器身份建立通讯会话。
	//
	//	函数参数：
	//		[in]pblkParam:				通讯会话的初始化参数
	//		[out]phSession:				通讯会话的句柄
	//
	// 返回值:
	//		见错误码定义
	//
	// 作者:
	//		伍友良
	// 日期:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommConnectAsServer(IN const BlkCommInitParam* pblkParam, OUT ESHANDLE* phSession);

	//////////////////////////////////////////////////////////////////////////
	//	函数说明:  
	//		断开通讯会话。
	//
	//	函数参数：
	//		[in]hSession:				通讯会话的句柄
	//
	// 返回值:
	//		见错误码定义
	//
	// 作者:
	//		伍友良
	// 日期:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommDisconnect(IN ESHANDLE hSession);

	//////////////////////////////////////////////////////////////////////////
	//	函数说明:  
	//		判断通讯会话是否已经连接。
	//
	//	函数参数：
	//		[in]hSession:				通讯会话的句柄
	//
	// 返回值:
	//		见错误码定义
	//
	// 作者:
	//		伍友良
	// 日期:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommIsConnected(IN ESHANDLE hSession, ESBOOL* pbConnected);

	//////////////////////////////////////////////////////////////////////////
	//	函数说明:  
	//		侦听通讯会话的数据。作为服务器的一方，应该在死循环中不断地调用“EsCommListen”，
	//		以保证服务能对客户端的请求即时感知。
	//
	//	函数参数：
	//		[in]hSession:				通讯会话的句柄
	//		[in]pu1Data:				指针，指向提交的数据
	//		[in|out]pu4DataLen:			存放侦听到的数据的缓冲区的长度，如果使用共享内存通讯，建议总是传入共享内存大小
	//
	// 返回值:
	//		见错误码定义
	//
	// 作者:
	//		伍友良
	// 日期:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommListen(IN ESHANDLE hSession, IN u1* pu1Data, IN u4* pu4DataLen);

	//////////////////////////////////////////////////////////////////////////
	//	函数说明:  
	//		向通讯会话的另一端提交数据。
	//
	//	函数参数：
	//		[in]hSession:				通讯会话的句柄
	//		[in]pu1Data:				指针，指向提交的数据
	//		[in]u4DataLen:				提交的数据的长度
	//
	// 返回值:
	//		见错误码定义
	//
	// 作者:
	//		伍友良
	// 日期:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommCommit(IN ESHANDLE hSession, IN const u1* pu1Data, IN u4 u4DataLen, OUT u1* pu1DataRes, IN u4 u4DataResLen);

	//////////////////////////////////////////////////////////////////////////
	//	函数说明:  
	//		向通讯会话的另一端发送通知。
	//
	//	函数参数：
	//		[in]hSession:				通讯会话的句柄
	//		[in]pblkNotifyData:			通知所附带的数据
	//
	// 返回值:
	//		见错误码定义
	//
	// 作者:
	//		伍友良
	// 日期:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommNotify(IN ESHANDLE hSession, IN const BlkCommNotifyData* pblkNotifyData);

	//////////////////////////////////////////////////////////////////////////
	//	函数说明:  
	//		等待通讯会话的另一端发出的信号通知。
	//
	//	函数参数：
	//		[in]hSession:				通讯会话的句柄
	//		[in]enSignal:				等待的信号
	//		[in]u4TimeOutMiliSecs:		等待的超时时间，以毫秒计
	// 返回值:
	//		见错误码定义
	//
	// 作者:
	//		伍友良
	// 日期:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommWaitForSignal(IN ESHANDLE hSession, 
		IN EN_COMMUNICATION_SIGNAL enSignal, 
		IN u4 u4TimeOutMiliSecs, 
		OUT u1* pu1Data, 
		IN u4 u4DataBufLen);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif 