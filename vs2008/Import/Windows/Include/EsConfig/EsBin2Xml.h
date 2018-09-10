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
 * 读取BIN配置文件
 * @param[in] pszFilePath 文件路径
 * @param[out] pu1CfgData 解密后的数据
 * @param[in, out] pu4CfgDataLen 数据长度
 * @return ESTRUE - 成功 ESFALSE - 失败
**/
ESBOOL CfgReadBinFile(IN const char* pszFilePath, OUT u1* pu1CfgData, IN OUT u4* pu4CfgDataLen);

/**
 * 读取嵌入到可执行文件内部的配置，如果是xml配置，以xml字符串形式返回，这个接口由项目实现，中间件不实现
 * @param[in] u4CfgId 一个标识配置数据块的ID
 * @param[out] pu1Data 配置值，如果是bin配置，返回的xml字符串（不含'\0'），为NULL时，pu4DataLen返回长度
 * @param[in, out] pu4DataLen 数据长度
 * @return 0 - 成功 others - 错误码
**/
u4 EsGetResourceById(IN u4 u4CfgId, OUT u1* pu1Data, IN OUT u4* pu4DataLen);

/**
 * 供项目上的配置模块去解密BIN数据块
 * @param[in] pszFilePath 文件路径，BIN校验需要文件路径
 * @param[in] pu1BinData BIN数据
 * @param[in] u4BinDataLen 数据长度
 * @param[out] pu1CfgData 解密得到的数据
 * @param[in,out] pu4CfgDataLen 解密数据长度
 * @return ESTRUE - 成功 ESFALSE - 错误码
**/
ESBOOL CfgDecryptBinData(IN const char* pszFilePath, IN const u1* pu1BinData, u4 u4BinDataLen, OUT u1* pu1CfgData, IN OUT u4* pu4CfgDataLen);

#ifdef __cplusplus
}
#endif

#endif // _ES_BIN_2_XML_H_