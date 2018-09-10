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

	// ��Windowsϵͳ�£���DllMain���Զ�����EsMiniCaInit/EsMiniCaFinal
	// ����ƽ̨����Ҫ�û��ڵ����������ܽӿ�֮ǰ����EsMiniCaInit
	void EsMiniCaInit();
	void EsMiniCaFinal();

typedef enum EnKeyPairType
{
	KEY_PAIR_RSA = 0,
	KEY_PAIR_SM2,
}EnKeyPairType;

unsigned long ConstructP10Info(IN char*				szName,		// szName  = "CN=...,OU=..."
							   IN EnKeyPairType		enKeyPairType,
							   IN unsigned char*	pbPubKey,	// RSA��N��SM2��Qx || Qy��MSB ��ǰ��
							   IN u4				u4ModLen,	// ��Կģ�����ֽ�Ϊ��λ��
							   OUT void**			ppvP10Info, // p10����ǰ�沿�֣���ǩ�����ݣ�
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

unsigned long ConstructP10(IN void**			ppvP10Info,  // p10����ǰ�沿�֣���ǩ�����ݣ�
						   IN u4				u4P10InfoLen,
						   IN EnSignAlg			enSignAlg,   // ǩ���㷨
						   IN unsigned char*	pbSignature, // ǩ��ֵ��MSB ��ǰ�������SM2������R || S��
						   IN u4				u4ModLen,	 // ģ�����ֽڣ���Ŀǰ֧��0x80,0x100,0x20
						   OUT unsigned char*	pbP10,       // p10��
						   OUT u4*				pu4P10Len
						   );

unsigned long P10Verify(
						IN void*			pvP10,		// P10�����
						IN u4				u4P10Len,
						IN unsigned char	bCalZa,		// �Ƿ���ZA����
						IN EnSignAlg*		pEnSignAlg, // ǩ���㷨
						OUT unsigned char*	pbPubKey,	// ��Կ��RSA:E[0x04] N[modLen]��SM2:Qx[ModLen] Qy[ModLen] 
						OUT u4*				pu4ModLen
						);

unsigned long ConstructX509Cert(
								IN void*			pvP10,			// P10�����
								IN u4				u4P10Len,
								IN char*			pszPfxPath,		// PFX�ļ���·����RSA��Ч��
								IN char*			pszPfxPassword,	// PFX�ļ������루RSA��Ч��
								IN unsigned char	bCalZa,         // �Ƿ���ZA���㣨SM2��Ч��
								OUT unsigned char*	pbCert,			// x509֤��
								OUT u4*				pu4CertLen
								);


// P7-ǩ���� 
unsigned long ConstructP7SignedData(
									IN void*			pvData2Sign,   // p7���Ĵ�ǩ������
									IN u4				u4Data2SignLen,// ����Ϊ0����ʾ����Detachǩ������������Attachǩ����
									IN void*			pvX509Cert,    // ǩ���ߵ�֤��
									IN EnSignAlg		enSignAlg,     // ǩ���㷨
									IN unsigned char*	pbSignature,   // ǩ��ֵ
									IN u4				u4SignatureLen,// ǩ��ֵ�ĳ���
									OUT void*			pvP7,          // �����P7��
									OUT	u4*				pu4P7Len
									);

unsigned long P7SignedDataVerify(IN void*	pvP7,          // P7��-ǩ���������ͣ������Detached��ǩ��ԭ�Ĳ���Ϊ�գ�
								 IN u4		u4P7Len,
								 IN void*	pvData2Sign,   // ǩ��ԭ�ģ�����Ϊ��
								 IN u4		u4Data2SignLen
								 );

unsigned long ParseP7SignedData(
								IN void*			pvP7,			// P7��-ǩ����������
								IN	u4				u4P7Len,
								OUT void*			pvData2Sign,    // p7���Ĵ�ǩ������
								OUT u4*				pu4Data2SignLen,
								OUT void*			pvX509Cert,		// ǩ���ߵ�֤��
								OUT EnSignAlg*		pEnSignAlg,		// ǩ���㷨
								OUT unsigned char*	pbSignature,	// ǩ��ֵ
								OUT u4*				pu4SignatureLen	// ǩ��ֵ�ĳ���
								);

unsigned long ParseP7SignedDataEx(
								  IN void*			pvP7,			// P7��-ǩ����������
								  IN u4				u4P7Len,
								  OUT void*			pvData2Sign,    // p7���Ĵ�ǩ������
								  OUT u4*			pu4Data2SignLen,// ǩ�����ݵĳ��ȣ�����Ϊ0��
								  OUT void*			pvX509Cert,		// ֤���б���һ��֤�����ǰһ��֤�飩
								  OUT u4*			pu4CertCount,	// ֤�����Ŀ
								  OUT EnSignAlg*	pEnSignAlg,		// ǩ���㷨
								  OUT unsigned char*pbSignature,	// ǩ��ֵ
								  OUT u4*			pu4SignatureLen	// ǩ��ֵ�ĳ��ȣ�����Ϊ0��
								  );

unsigned long ConstructX509CertViaPubKey(
								IN BlkAsymKey*		pblkAsymKey,
								IN const char*		szDnName,
								IN char*			pszPfxPath,		// PFX�ļ���·��
								IN char*			pszPfxPassword,	// PFX�ļ�������
								OUT unsigned char*	pbCert,			// x509֤��
								OUT unsigned long*	pulCertLen
								);

#if defined(__cplusplus)
}
#endif
#endif
