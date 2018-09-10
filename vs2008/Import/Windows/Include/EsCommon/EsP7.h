#ifndef _ESP7_H_
#define _ESP7_H_
#ifdef __cplusplus
extern "C"
{
#endif
u4 CALL_TYPE EsCfcaEnvelopData(const BlkAsymKey* pblkAsymKeyTemp, u4 u4SymmAlgId, const BlkAsymKey* pblkAsymKey, u1** ppu1EnvelopData, u4* pu4EnvelopDataLen);

#define ESP7_TYPE_DATA				0x01
#define ESP7_TYPE_SIGNED_DATA		0x02
#define ESP7_TYPE_ENV_DATA			0x03
#define ESP7_TYPE_SIGNED_ENV_DATA	0x04
#define ESP7_TYPE_DIGESTED_DATA		0x05
#define ESP7_TYPE_ENCRYPTED_DATA	0x06
u4 CALL_TYPE EsP7EncodeData(const void* pvData, u4 u4DataLen, u1** ppu1EncodeData, u4* pu4EncodeDataLen);
u4 CALL_TYPE EsP7EncodeSignedData(u4 u4AsymAlgId, u4 u4HashAlgId, const u1* pu1Content, u4 u4ContentLen, const u1* pu1SignerCert, const u1* pu1Signature, u4 u4SignatureLen, u1** ppu1EncodeData, u4* pu4EncodeDataLen);
u4 CALL_TYPE EsP7DecodeSignedData(void* pvP7, u4 u4P7Len, void* pu1Content, u4* u4ContentLen, void* pu1SignerCert, u4* pu4CertCount, u4* pu4SignAlgId, u4* pu4HashAlgId, u1* pu1Signature, u4* pu4SignatureLen);

u4 CALL_TYPE EsP7Encode(u4 u4EncodeType, const void* pvData, u4 u4DataLen, u1** ppu1EncodeData, u4* pu4EncodeDataLen);
u4 CALL_TYPE EsP7Decode(const void* pvP7Data, u4 u4P7DataLen, u1** ppu1Data, u4* pu4DataLen);
u4 CALL_TYPE EsGetAsymKeyFromPfx(const char* pszPfxFileName, const char* pszPfxPassword, BlkAsymKey* pblkAsymKey);

typedef struct BlkCertInfoTag
{
	u4			m_u4Version;
	u1*			m_pu1DerIssure;				// �䷢��
	u4			m_u4DerIssureLen;
	u1*			m_pu1DerSubject;			// �䷢��
	u4			m_u4DerSubjectLen;
	u1*			m_pu1DerSn;
	u4			m_u4DerSnLen;
    u1*         m_pu1DerValidity;              // ��Ч��
    u4          m_u4DerValidityLen;
// 	u4			m_u4SignAsymAlg;			// ��֤��ǩ�����õķǶԳ��㷨
// 	u4			m_u4SignHashAlg;			// ��֤��ǩ�����õĹ�ϣ�㷨
// 	u1			m_pu1Signature[0x200];		// ֤���ǩ��ֵ
// 	u4			m_u4SignatureLen;
// 	u1			m_pu1HashValue[0x80];		// ֤������Ĺ�ϣֵ
	BlkAsymKey	m_blkPubKey;				// ֤�鹫Կ
}BlkCertInfo;

// pblkAsymKeyCa:	���ΪNULL����ʾ����Ҫ��֤֤��ǩ��
u4 CALL_TYPE EsCertParse(const void* pvCertData, u4 u4CertDataLen, const BlkAsymKey* pblkAsymKeyCa, ESBOOL bCalcZa, BlkCertInfo* pblkCertInfo);
u4 CALL_TYPE EsCertParseDn(const void* pvDerDn, u4 u4DerDnLen, char* pszDn, u4* pu4DnLen);
u4 CALL_TYPE EsCertParseValidity(const void* pvDerValidity, u4 u4DerLen, char* pszNotBefore, u4* pu4NotBeforeLen, char* pszNotAfter, u4* pu4NotAfterLen);
u4 CALL_TYPE EsCaSetParam(const BlkAsymKey* pblkAsymKey, const char* pszDnCa, u4 u4DnCaLen);
u4 CALL_TYPE EsCfcaEnvelopDataDecode(const u1* pu1EnvelopData, u4 u4EnvelopDataLen,
									 u4* pu4AsymAlgId, u4* pu4SymmAlgId, 
									 u1** ppu1EncSymmKey, u4* pu4EncSymmKeyLen,
									 u1** ppu1EncAsymKey, u4* pu4EncAsymKeyLen);


//Ĭ�������㷨��֧��
#define ESCERT_TYPE_EXCHANGE	0x01
#define ESCERT_TYPE_SIGNATURE	0x02
#define ESCERT_TYPE_SIG_EX      0x03
u4 CALL_TYPE EsCertConstruct(const BlkAsymKey* pblkAsymKey, const char* pszDn, u4 u4DnLen, u4 u4CertType, void* pvDerCert, u4* pu4DerCertLen);
#ifdef __cplusplus
}
#endif
#endif
