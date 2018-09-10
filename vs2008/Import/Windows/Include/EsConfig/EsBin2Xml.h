#ifndef _ES_BIN_2_XML_H_
#define _ES_BIN_2_XML_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <EsTypeDef.h>
#include <EsCommon/EsCommon.h>

#if defined(_OS_WINDOWS_)
#include <Windows.h>
#endif

typedef enum EnCfgId
{
    CFG_ID_MIDWARE     =   0x00,
}EnCfgId;

typedef enum EnEncAlg
{
	ENC_ALG_RC4 = 0x00,

}EnEncAlg;

typedef enum EnSignAlg
{
	SIGN_ALG_RSA1024_SHA1 = 0x00,

}EnSignAlg;

typedef struct BlkCfgFileHeadTag
{
	u4			m_u4Version;
	EnEncAlg	m_enEncAlg;
	u1			m_pu1EncKey[0x20];
	u4			m_u4EncKeyLen;
	EnSignAlg	m_enSignAlg;

	u4			m_u4FileSizePlain;
	u4			m_u4FileSizeEnc;
#if defined(_OS_WINDOWS_)
	FILETIME	m_FileTime;
#endif
	u1			m_pu1RFU[0x100-0x30-0x10];
}BlkCfgFileHead;

extern u1 g_pu1N[0x100];

/**
 * ��ȡBIN�����ļ�
 * @param[in] pszFilePath �ļ�·��
 * @param[out] pu1CfgData ���ܺ������
 * @param[in, out] pu4CfgDataLen ���ݳ���
 * @return ESTRUE - �ɹ� ESFALSE - ʧ��
**/
ESBOOL CfgReadBinFile(IN const char* pszFilePath, OUT u1* pu1CfgData, IN OUT u4* pu4CfgDataLen);

/**
 * ��ȡǶ�뵽��ִ���ļ��ڲ������ã������xml���ã���xml�ַ�����ʽ���أ�����ӿ�����Ŀʵ�֣��м����ʵ��
 * @param[in] u4CfgId һ����ʶ�������ݿ��ID
 * @param[out] pu1Data ����ֵ�������bin���ã����ص�xml�ַ���������'\0'����ΪNULLʱ��pu4DataLen���س���
 * @param[in, out] pu4DataLen ���ݳ���
 * @return 0 - �ɹ� others - ������
**/
u4 EsGetResourceById(IN u4 u4CfgId, OUT u1* pu1Data, IN OUT u4* pu4DataLen);

/**
 * ����Ŀ�ϵ�����ģ��ȥ����BIN���ݿ�
 * @param[in] pszFilePath �ļ�·����BINУ����Ҫ�ļ�·��
 * @param[in] pu1BinData BIN����
 * @param[in] u4BinDataLen ���ݳ���
 * @param[out] pu1CfgData ���ܵõ�������
 * @param[in,out] pu4CfgDataLen �������ݳ���
 * @return ESTRUE - �ɹ� ESFALSE - ������
**/
ESBOOL CfgDecryptBinData(IN const char* pszFilePath, IN const u1* pu1BinData, u4 u4BinDataLen, OUT u1* pu1CfgData, IN OUT u4* pu4CfgDataLen);

#ifdef __cplusplus
}
#endif

#endif // _ES_BIN_2_XML_H_