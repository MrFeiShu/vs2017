#ifndef _ESCOMMCLIENT_H_
#define _ESCOMMCLIENT_H_

#ifndef TCP_COMMUNICATION_TYPE
	#define TCP_COMMUNICATION_TYPE		0x00
#endif

#ifndef UDP_COMMUNICATION_TYPE
	#define UDP_COMMUNICATION_TYPE		0x01
#endif

#ifndef MAX_SEND_LEN
	#define MAX_SEND_LEN				0x8000
#endif

#ifndef EN_COMM_PARAM
	#define EN_COMM_PARAM
	typedef enum EnCommParam_Tag
	{
		ES_COMM_RECV_TIMEOUT = 0x01,	// 接收时间
		ES_COMM_SEND_TIMEOUT = 0x02,	// 发送时间
	}EnCommParam;
	typedef struct BlkConnectedInfoTag 
	{
		char*	m_pszIp;			// "192.168.0.1"格式
		u2		m_u2Port;
	}BlkConnectedInfo;
#endif

typedef struct BlkCommClientParamTag 
{
	char*	m_pszIp;		// "192.168.0.1"格式
	u2		m_u2Port;		// 端口
}BlkCommClientParam;

#ifdef __cplusplus
extern "C"
{
#endif

	////////////////////////////////////////////////////
	// 函数名称：EsCommClientInit
	// 函数功能
	//  初始化客户端
	// 参数说明： 
	//	u4Type:			[IN] 客户端类型，00:tcp, 01: udp；
	//	pvParam:		[IN] 客户端参数，IP, PORT；参见  BlkCommClientParam
	//  phHandle:		[OUT] 客户端句柄；	
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientInit(u4 u4Type, const void* pvParam, ESHANDLE* phHandle);

	////////////////////////////////////////////////////
	// 函数名称：EsCommClientMulticast
	// 函数功能
	//  加入多播组
	// 参数说明： 
	//	hHandle:		[IN] 客户端句柄；
	//	pszMuticastIp:	[IN] 多播组的IP；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientMulticast(ESHANDLE hHandle, const char* pszMuticastIp);

	////////////////////////////////////////////////////
	// 函数名称：EsCommClientGetServerInfo
	// 函数功能
	//	 获取连接的服务器的信息
	// 参数说明： 
	//	hHandle:					[IN] 通讯句柄；
	//	pblkConnectedInfo:			[OUT] 连接上的服务器的信息结构体；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientGetServerInfo(ESHANDLE hHandle, BlkConnectedInfo* pblkConnectedInfo);
	
	////////////////////////////////////////////////////
	// 函数名称：EsCommClientSetParam
	// 函数功能
	//	设置客户端通讯端口参数
	// 参数说明： 
	//	hHandle:			[IN] 客户端句柄；
	//	enType:				[IN] 参数类型： 接收：0x01， 发送：0x02；
	//	pvParam:			[IN] 参数数据，目前支持超时参数，超时参数以秒为单位；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientSetParam(ESHANDLE hHandle, EnCommParam enType, const void* pvParam);

	////////////////////////////////////////////////////
	// 函数名称：EsCommClientGetParam
	// 函数功能
	//	获取客户端通讯端口参数
	// 参数说明： 
	//	hHandle:			[IN] 客户端句柄；
	//	enType:				[IN] 参数类型： 接收：0x01， 发送：0x02；
	//	pvParam:			[OUT] 参数数据；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientGetParam(ESHANDLE hHandle, EnCommParam enType, void* pvParam);

	////////////////////////////////////////////////////
	// 函数名称：EsCommClientSendData
	// 函数功能
	//   客户端发送数据
	// 参数说明： 
	//  hHandle:		[IN] 客户端句柄；
	//	pvData:			[IN] 待发送数据；
	//	u4DataLen:		[IN] 待发送数据长度；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientSendData(ESHANDLE hHandle, const void* pvData, u4 u4DataLen);

	////////////////////////////////////////////////////
	// 函数名称：EsCommClientRecvData
	// 函数功能
	//  客户端接收数据
	// 参数说明： 
	//  hHandle:		[IN] 客户端句柄；
	//	pvData:			[OUT] 接收数据；
	//	pu4DataLen:		[IN/OUT] 接收数据长度；
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientRecvData(ESHANDLE hHandle, void* pvData, u4* pu4DataLen);

	////////////////////////////////////////////////////
	// 函数名称：EsCommClientRelease
	// 函数功能
	//  初始化服务器
	// 参数说明： 
	//  phHandle:		[IN] 客户端句柄；	
	// 返回值：		
	//  0x00: 成功；
	//	其他：见错误码。
	// 备注：
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientRelease(ESHANDLE* phHandle);

#ifdef __cplusplus
}
#endif

#endif
