//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2013,�������Ķ������ݰ�ȫ���޹�˾
// All rights reserved.
// 
// �ļ����ƣ�
//		EsCommunication.h
//
// �ļ���ʶ��
//
// ժ   Ҫ��
//		ͨѶ�ӿڡ����ӿ��ṩһ��ӿڣ���һ��ӿ�ʵ�ֵĹ�����ʵ�ֿ����ͨ�š�����ͨѶ���ܡ�
//		����ӿھ�������������
//		1��͸��
//		ʹ����������ľ���ͨѶЭ�鼰��ʵ��ϸ�ڣ�
//		2������
//		�ṩ�ǳ����Ի��Ľӿ�ԭ�ͣ�ʹ����ǳ�ֱ�����á�
//		���ӿڵ����������õ��ǵ�Ե�ģʽ������C/Sģʽ��
// 
// ��ǰ�汾��
//		1.0
//
// ��   �ߣ�
//		������
//
// ������ڣ�
//		2013��07��02��
//////////////////////////////////////////////////////////////////////////

#ifndef _ES_COMMUNICATION_H_
#define _ES_COMMUNICATION_H_

#include "./EsTypeDef.h"
#include "./EsError.h"

#define MAX_MODULE_PATH_LEN			260
#define MAX_SESSION_NAME_LEN	260

typedef enum EN_COMM_PROTOCAL
{
	PROTOCAL_IMPOSSIBLE = 0, // δ��ʼ����ֵ��������
	PROTOCAL_SHARE_MEM,
	PROTOCAL_SOCKET,
	PROTOCAL_MAX_VALUE // �ڱ���������ֵ����ʾ��Чֵ
}EN_COMM_SIGNAL;


typedef struct BlkCommShmInitParamTag 
{
	ESBOOL	m_bAutoStartOtherSide; // �����һ��û���������Ƿ��Զ�����֮
	char	m_szOtherSidePath[MAX_MODULE_PATH_LEN]; // ��һ����·�������m_bAutoStartOtherSideΪESFALSE�����ֶκ���
	char	m_szSessionName[MAX_SESSION_NAME_LEN]; // �Ự����
	u4		m_u4ShmSize; // �����ڴ�Ĵ�С�����ֽڼ���
}BlkCommShmInitParam;


typedef struct BlkCommInitParamTag 
{
	EN_COMM_PROTOCAL m_enProtocal;
	union
	{
		// �����ڴ�Э���ʼ������
		BlkCommShmInitParam m_blkShmInitParam;
		// �ݲ�֧��socketЭ��
	}m_unData;
	
}BlkCommInitParam;



typedef enum EN_COMMUNICATION_SIGNAL
{
	SIGNAL_IMPOSSIBLE = 0, // δ��ʼ����ֵ��������
	SIGNAL_CONNECTED, // ��Ϊ��������һ�����ô��źţ�����һ������ȵ����ź�˵���Է��Ѿ�����������
	SIGNAL_COMMITED, // ��Ҫ�ύ���ݵ�һ�����ô��źţ�����һ������ȵ����ź�˵���Է��Ѿ��ύ������
	SIGNAL_FINISHED, // ������ݴ����һ�����ô��źţ�����һ������ȵ����ź�˵���Է��Ѿ���������ݴ���
	SIGNAL_CANCELED, // ȡ�����ݴ����һ�����ô��źţ�����һ������ȵ����ź�˵���Է��Ѿ�ȡ�������ݴ���
	SIGNAL_TERMINATED, 
	SIGNAL_UPDATED,
	SIGNAL_MAX_VALUE // �ڱ���������ֵ����ʾ��Чֵ
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
	//	����˵��:  
	//		����ͨѶ�Ự��
	//
	//	����������
	//		[in]pblkParam:				ͨѶ�Ự�ĳ�ʼ������
	//		[out]phSession:				ͨѶ�Ự�ľ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommConnect(IN const BlkCommInitParam* pblkParam, IN u4 u4TimeOutMilSecs, OUT ESHANDLE* phSession);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		�Է�������ݽ���ͨѶ�Ự��
	//
	//	����������
	//		[in]pblkParam:				ͨѶ�Ự�ĳ�ʼ������
	//		[out]phSession:				ͨѶ�Ự�ľ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommConnectAsServer(IN const BlkCommInitParam* pblkParam, OUT ESHANDLE* phSession);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		�Ͽ�ͨѶ�Ự��
	//
	//	����������
	//		[in]hSession:				ͨѶ�Ự�ľ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommDisconnect(IN ESHANDLE hSession);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		�ж�ͨѶ�Ự�Ƿ��Ѿ����ӡ�
	//
	//	����������
	//		[in]hSession:				ͨѶ�Ự�ľ��
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommIsConnected(IN ESHANDLE hSession, ESBOOL* pbConnected);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		����ͨѶ�Ự�����ݡ���Ϊ��������һ����Ӧ������ѭ���в��ϵص��á�EsCommListen����
	//		�Ա�֤�����ܶԿͻ��˵�����ʱ��֪��
	//
	//	����������
	//		[in]hSession:				ͨѶ�Ự�ľ��
	//		[in]pu1Data:				ָ�룬ָ���ύ������
	//		[in|out]pu4DataLen:			��������������ݵĻ������ĳ��ȣ����ʹ�ù����ڴ�ͨѶ���������Ǵ��빲���ڴ��С
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommListen(IN ESHANDLE hSession, IN u1* pu1Data, IN u4* pu4DataLen);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		��ͨѶ�Ự����һ���ύ���ݡ�
	//
	//	����������
	//		[in]hSession:				ͨѶ�Ự�ľ��
	//		[in]pu1Data:				ָ�룬ָ���ύ������
	//		[in]u4DataLen:				�ύ�����ݵĳ���
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommCommit(IN ESHANDLE hSession, IN const u1* pu1Data, IN u4 u4DataLen, OUT u1* pu1DataRes, IN u4 u4DataResLen);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		��ͨѶ�Ự����һ�˷���֪ͨ��
	//
	//	����������
	//		[in]hSession:				ͨѶ�Ự�ľ��
	//		[in]pblkNotifyData:			֪ͨ������������
	//
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
	//		2013.07.02
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE EsCommNotify(IN ESHANDLE hSession, IN const BlkCommNotifyData* pblkNotifyData);

	//////////////////////////////////////////////////////////////////////////
	//	����˵��:  
	//		�ȴ�ͨѶ�Ự����һ�˷������ź�֪ͨ��
	//
	//	����������
	//		[in]hSession:				ͨѶ�Ự�ľ��
	//		[in]enSignal:				�ȴ����ź�
	//		[in]u4TimeOutMiliSecs:		�ȴ��ĳ�ʱʱ�䣬�Ժ����
	// ����ֵ:
	//		�������붨��
	//
	// ����:
	//		������
	// ����:    
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