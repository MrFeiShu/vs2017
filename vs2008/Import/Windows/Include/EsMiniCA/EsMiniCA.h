#ifndef _ESMINICA_H_
#define _ESMINICA_H_
#include <EsCommon/EsCommon.h>
#if defined(__cplusplus)
extern "C"
{
#endif

#ifndef IN
#define IN
#endif

#ifndef OUT
#define OUT
#endif

#define szOID_SM2		"1.2.156.10197.1.301"
#define szOID_SM3		"1.2.156.10197.1.401"
#define szOID_SM2_SM3	"1.2.156.10197.1.501"
#define szOID_RSA_SM3	"1.2.156.10197.1.504"
    
#ifndef _OS_WINDOWS_
#define szOID_RSA_RSA "1.2.840.113549.1.1.1"
#define szOID_RSA_SHA1RSA "1.2.840.113549.1.1.5"
#define szOID_RSA_SHA256RSA "1.2.840.113549.1.1.11"
#define szOID_RSA_SHA384RSA "1.2.840.113549.1.1.12"
#define szOID_RSA_SHA512RSA "1.2.840.113549.1.1.13"
#define szOID_RSA_MD5RSA "1.2.840.113549.1.1.4"
#endif

	// 在Windows系统下，在DllMain中自动调用EsMiniCaInit/EsMiniCaFinal
	// 其他平台，需要用户在调用其他功能接口之前调用EsMiniCaInit
	void EsMiniCaInit();
	void EsMiniCaFinal();

typedef enum EnKeyPairType
{
	KEY_PAIR_RSA = 0,
	KEY_PAIR_SM2,
}EnKeyPairType;

unsigned long ConstructP10Info(IN char*				szName,		// szName  = "CN=...,OU=..."
							   IN EnKeyPairType		enKeyPairType,
							   IN unsigned char*	pbPubKey,	// RSA：N，SM2：Qx || Qy（MSB 在前）
							   IN u4				u4ModLen,	// 公钥模长（字节为单位）
							   OUT void**			ppvP10Info, // p10包的前面部分（待签名数据）
							   OUT u4*				pu4P10InfoLen
							   );

void P10FreeMemory(void* pvP10);

typedef enum EnSignAlg
{
	SIGN_ALG_RSA_MD5 = 0,
	SIGN_ALG_RSA_SHA,
	SIGN_ALG_RSA_SHA256,
	SIGN_ALG_RSA_SHA384,
	SIGN_ALG_RSA_SHA512,
	SIGN_ALG_SM2_SM3,
}EnSignAlg;

unsigned long ConstructP10(IN void**			ppvP10Info,  // p10包的前面部分（待签名数据）
						   IN u4				u4P10InfoLen,
						   IN EnSignAlg			enSignAlg,   // 签名算法
						   IN unsigned char*	pbSignature, // 签名值，MSB 在前（如果是SM2，则是R || S）
						   IN u4				u4ModLen,	 // 模长（字节）：目前支持0x80,0x100,0x20
						   OUT unsigned char*	pbP10,       // p10包
						   OUT u4*				pu4P10Len
						   );

unsigned long P10Verify(
						IN void*			pvP10,		// P10请求包
						IN u4				u4P10Len,
						IN unsigned char	bCalZa,		// 是否有ZA计算
						IN EnSignAlg*		pEnSignAlg, // 签名算法
						OUT unsigned char*	pbPubKey,	// 公钥，RSA:E[0x04] N[modLen]，SM2:Qx[ModLen] Qy[ModLen] 
						OUT u4*				pu4ModLen
						);

unsigned long ConstructX509Cert(
								IN void*			pvP10,			// P10请求包
								IN u4				u4P10Len,
								IN char*			pszPfxPath,		// PFX文件的路径（RSA有效）
								IN char*			pszPfxPassword,	// PFX文件的密码（RSA有效）
								IN unsigned char	bCalZa,         // 是否有ZA计算（SM2有效）
								OUT unsigned char*	pbCert,			// x509证书
								OUT u4*				pu4CertLen
								);


// P7-签名包 
unsigned long ConstructP7SignedData(
									IN void*			pvData2Sign,   // p7包的待签名数据
									IN u4				u4Data2SignLen,// 长度为0，表示构造Detach签名包，否则构造Attach签名包
									IN void*			pvX509Cert,    // 签名者的证书
									IN EnSignAlg		enSignAlg,     // 签名算法
									IN unsigned char*	pbSignature,   // 签名值
									IN u4				u4SignatureLen,// 签名值的长度
									OUT void*			pvP7,          // 输出的P7包
									OUT	u4*				pu4P7Len
									);

unsigned long P7SignedDataVerify(IN void*	pvP7,          // P7包-签名数据类型（如果是Detached，签名原文不能为空）
								 IN u4		u4P7Len,
								 IN void*	pvData2Sign,   // 签名原文，可以为空
								 IN u4		u4Data2SignLen
								 );

unsigned long ParseP7SignedData(
								IN void*			pvP7,			// P7包-签名数据类型
								IN	u4				u4P7Len,
								OUT void*			pvData2Sign,    // p7包的待签名数据
								OUT u4*				pu4Data2SignLen,
								OUT void*			pvX509Cert,		// 签名者的证书
								OUT EnSignAlg*		pEnSignAlg,		// 签名算法
								OUT unsigned char*	pbSignature,	// 签名值
								OUT u4*				pu4SignatureLen	// 签名值的长度
								);

unsigned long ParseP7SignedDataEx(
								  IN void*			pvP7,			// P7包-签名数据类型
								  IN u4				u4P7Len,
								  OUT void*			pvData2Sign,    // p7包的待签名数据
								  OUT u4*			pu4Data2SignLen,// 签名数据的长度（可能为0）
								  OUT void*			pvX509Cert,		// 证书列表（后一张证书紧跟前一张证书）
								  OUT u4*			pu4CertCount,	// 证书的数目
								  OUT EnSignAlg*	pEnSignAlg,		// 签名算法
								  OUT unsigned char*pbSignature,	// 签名值
								  OUT u4*			pu4SignatureLen	// 签名值的长度（可能为0）
								  );

unsigned long ConstructX509CertViaPubKey(
								IN BlkAsymKey*		pblkAsymKey,
								IN const char*		szDnName,
								IN char*			pszPfxPath,		// PFX文件的路径
								IN char*			pszPfxPassword,	// PFX文件的密码
								OUT unsigned char*	pbCert,			// x509证书
								OUT unsigned long*	pulCertLen
								);

#if defined(__cplusplus)
}
#endif
#endif
