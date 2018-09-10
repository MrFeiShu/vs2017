#ifndef _ESCOMMSERVER_H_
#define _ESCOMMSERVER_H_

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

typedef struct BlkCommServerParamTag 
{
	char*	m_pszIp;			// "192.168.0.1"��ʽ
	u2		m_u2Port;
	u4		m_u4MaxConnectCount;
}BlkCommServerParam;

#ifdef __cplusplus
extern "C"
{
#endif

	////////////////////////////////////////////////////
	// �������ƣ�EsCommServerInit
	// ��������
	//  ��ʼ��������
	// ����˵���� 
	//	u4Type:			[IN] ���������ͣ�00:tcp, 01: udp��
	//	pvParam:		[IN] ������������IP, PORT, MAXCOUNT���μ� BlkCommServerParam
	//  phHandle:		[OUT] �����������	
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerInit(u4 u4Type, const void* pvParam, ESHANDLE* phHandle);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommServerWaitConnect
	// ��������
	//		�ȴ��ͻ������ӷ�����
	// ����˵���� 
	//	hHandle:					[IN] �����������
	//	phClientHandle:				[OUT] �����Ͽͻ��˺��ͨѶ�����
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerWaitConnect(IN ESHANDLE hHandle, OUT ESHANDLE* phClientHandle);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommServerGetClientInfo
	// ��������
	//	 ��ȡ�����ͻ��˵���Ϣ
	// ����˵���� 
	//	hHandle:					[IN] ͨѶ�����
	//	pblkConnectedInfo:			[OUT] �����ϵĿͻ��˵���Ϣ�ṹ�壻
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerGetClientInfo(ESHANDLE hHandle, BlkConnectedInfo* pblkConnectedInfo);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommServerSetParam
	// ��������
	//	���÷�����ͨѶ�˿ڲ���
	// ����˵���� 
	//	hHandle:			[IN] �����������
	//	enType:				[IN] �������ͣ����գ�0x01�� ���ͣ�0x02��
	//	pvParam:			[IN] �������ݣ�Ŀǰ֧�ֳ�ʱ��������ʱ��������Ϊ��λ��
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerSetParam(ESHANDLE hHandle, EnCommParam enType, const void* pvParam);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommServerGetParam
	// ��������
	//	��ȡ������ͨѶ�˿ڲ���
	// ����˵���� 
	//	hHandle:			[IN] �����������
	//	enType:				[IN] �������ͣ����գ�0x01�� ���ͣ�0x02��
	//	pvParam:			[OUT] �������ݣ�
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerGetParam(ESHANDLE hHandle, EnCommParam enType, void* pvParam);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommServerSendData
	// ��������
	//  ����˷��ͱ�������
	// ����˵���� 
	//  hHandle:		[IN] �����������
	//	pvData:			[IN] ���������ݣ�
	//	u4DataLen:		[IN] ���������ݳ��ȣ�
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerSendData(ESHANDLE hHandle, const void* pvData, u4 u4DataLen);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommServerRecvData
	// ��������
	//  ����˽��ձ�������
	// ����˵���� 
	//  hHandle:		[IN] �����������	
	//	pvData:			[OUT] �������ݣ�
	//	u4DataLen:		[IN/OUT] �������ݳ��ȣ�
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerRecvData(ESHANDLE hHandle, void* pvData, u4* pu4DataLen);

	////////////////////////////////////////////////////
	// �������ƣ�EsCommServerRelease
	// ��������
	//  �رշ�����
	// ����˵���� 
	//  phHandle:		[IN] �����������
	// ����ֵ��		
	//  0x00: �ɹ���
	//	�������������롣
	// ��ע��
	////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommServerRelease(ESHANDLE* phHandle);

#ifdef __cplusplus
}
#endif

#endif
