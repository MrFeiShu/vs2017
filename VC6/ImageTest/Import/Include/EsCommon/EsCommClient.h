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
		ES_COMM_RECV_TIMEOUT = 0x01,	// ����ʱ��
		ES_COMM_SEND_TIMEOUT = 0x02,	// ����ʱ��
	}EnCommParam;
	typedef struct BlkConnectedInfoTag 
	{
		char*	m_pszIp;			// "192.168.0.1"��ʽ
		u2		m_u2Port;
	}BlkConnectedInfo;
#endif

typedef struct BlkCommClientParamTag 
{
	char*	m_pszIp;		// "192.168.0.1"��ʽ
	u2		m_u2Port;		// �˿�
}BlkCommClientParam;

#ifdef __cplusplus
extern "C"
{
#endif

	////////////////////////////////////////////////////
	// �������ƣ�EsCommClientInit
	// ��������
	//  ��ʼ���ͻ���
	// ����˵���� 
	//	u4Type:			[IN] �ͻ������ͣ�00:tcp, 01: udp��
	//	pvParam:		[IN] �ͻ��˲�����IP, PORT���μ�  BlkCommClientParam
	//  phHandle:		[OUT] �ͻ��˾����	
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientInit(u4 u4Type, const void* pvParam, ESHANDLE* phHandle);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommClientMulticast
	// ��������
	//  ����ಥ��
	// ����˵���� 
	//	hHandle:		[IN] �ͻ��˾����
	//	pszMuticastIp:	[IN] �ಥ���IP��
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientMulticast(ESHANDLE hHandle, const char* pszMuticastIp);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommClientGetServerInfo
	// ��������
	//	 ��ȡ���ӵķ���������Ϣ
	// ����˵���� 
	//	hHandle:					[IN] ͨѶ�����
	//	pblkConnectedInfo:			[OUT] �����ϵķ���������Ϣ�ṹ�壻
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientGetServerInfo(ESHANDLE hHandle, BlkConnectedInfo* pblkConnectedInfo);
	
	////////////////////////////////////////////////////
	// �������ƣ�EsCommClientSetParam
	// ��������
	//	���ÿͻ���ͨѶ�˿ڲ���
	// ����˵���� 
	//	hHandle:			[IN] �ͻ��˾����
	//	enType:				[IN] �������ͣ� ���գ�0x01�� ���ͣ�0x02��
	//	pvParam:			[IN] �������ݣ�Ŀǰ֧�ֳ�ʱ��������ʱ��������Ϊ��λ��
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientSetParam(ESHANDLE hHandle, EnCommParam enType, const void* pvParam);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommClientGetParam
	// ��������
	//	��ȡ�ͻ���ͨѶ�˿ڲ���
	// ����˵���� 
	//	hHandle:			[IN] �ͻ��˾����
	//	enType:				[IN] �������ͣ� ���գ�0x01�� ���ͣ�0x02��
	//	pvParam:			[OUT] �������ݣ�
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientGetParam(ESHANDLE hHandle, EnCommParam enType, void* pvParam);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommClientSendData
	// ��������
	//   �ͻ��˷�������
	// ����˵���� 
	//  hHandle:		[IN] �ͻ��˾����
	//	pvData:			[IN] ���������ݣ�
	//	u4DataLen:		[IN] ���������ݳ��ȣ�
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientSendData(ESHANDLE hHandle, const void* pvData, u4 u4DataLen);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommClientRecvData
	// ��������
	//  �ͻ��˽�������
	// ����˵���� 
	//  hHandle:		[IN] �ͻ��˾����
	//	pvData:			[OUT] �������ݣ�
	//	pu4DataLen:		[IN/OUT] �������ݳ��ȣ�
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientRecvData(ESHANDLE hHandle, void* pvData, u4* pu4DataLen);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommClientRelease
	// ��������
	//  ��ʼ��������
	// ����˵���� 
	//  phHandle:		[IN] �ͻ��˾����	
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommClientRelease(ESHANDLE* phHandle);

#ifdef __cplusplus
}
#endif

#endif
