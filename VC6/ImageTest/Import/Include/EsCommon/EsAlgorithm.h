#ifndef _ES_ALGORITHM_H_
#define _ES_ALGORITHM_H_

#ifdef __cplusplus
extern "C" 
{
#endif

	// HASH Alg
	#define	ES_HASH_ALG_MD5		 0x80000001
	#define	ES_HASH_ALG_SHA1	 0x80000002
	#define	ES_HASH_ALG_SHA256	 0x80000003
	#define	ES_HASH_ALG_SHA384   0x80000004
	#define	ES_HASH_ALG_SHA512   0x80000005
	#define	ES_HASH_ALG_SM3		 0x80000006
	#define	ES_HASH_ALG_MD5SHA1	 0x80000007
	#define ES_HASH_ALG_SET		 0x800000FF		// 只能通过设置接口设置哈希值

	// pvIv can be NULL
	u4 CALL_TYPE EsHashInit(ESHANDLE* phHash, const void* pvIv, u4 u4HashAlgId);
	u4 CALL_TYPE EsHashUpdate(ESHANDLE hHash, const void *pvInput, u4 u4InputLen);
	u4 CALL_TYPE EsHashFinal(ESHANDLE hHash, void* pvHashValue);
	u4 CALL_TYPE EsHashRelease(ESHANDLE hHash);
	u4 CALL_TYPE EsHashGetInfo(ESHANDLE hHash, u4* pu4BlockSize, u4* pu4IvSize, u4* pu4ValueSize);
	u4 CALL_TYPE EsHashGetMidValue(ESHANDLE hHash, void* pvHashValue, u4* pu4DataLen); // pu4DataLen can be NULL
	u4 CALL_TYPE EsHashSetMidValue(ESHANDLE hHash, const void* pvHashValue, u4 u4DataLen);

	u1	 CALL_TYPE EsHashGetOid(u4 u4AlgId, u1* pu1Oid);
	u1	 CALL_TYPE EsHashData(u4 u4HashAlgId, const void* pvMsg, u4 u4MsgLen, void* pvHashValue);

	// Symm Alg
	#define	ES_SYMM_ALG_DES		    0x0001
	#define ES_SYMM_ALG_3DES112	    0x0002
	#define ES_SYMM_ALG_3DES168		0x0004
	#define ES_SYMM_ALG_AES128		0x0008
	#define ES_SYMM_ALG_AES192		0x0010
	#define ES_SYMM_ALG_AES256		0x0020
	#define ES_SYMM_ALG_SSF33		0x0100
	#define ES_SYMM_ALG_SM1			0x0200
	#define ES_SYMM_ALG_SM4		    0x0400
	#define ES_SYMM_ALG_RC4			0x0800	
	//---------------------------------------------------------------------------------
	// no padding

	// 分组算法
	u4 CALL_TYPE EsSymmGetInfo(u4 u4AlgId, u4* pu4BlockLen, u4* pu4KeyLen);
	u4 CALL_TYPE EsSymmEncEcb(u4 u4AlgId, const void* pvKey, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	u4 CALL_TYPE EsSymmDecEcb(u4 u4AlgId, const void* pvKey, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	u4 CALL_TYPE EsSymmEncCbc(u4 u4AlgId, const void* pvKey, const void* pvIv, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	u4 CALL_TYPE EsSymmDecCbc(u4 u4AlgId, const void* pvKey, const void* pvIv, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	u4 CALL_TYPE EsSymmMac(u4 u4AlgId, const void* pvKey, const void* pvIv, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);

	//---------------------------------------------------------------------------------
	// 本套接口主要按照PKCS11的接口形式提供，CSP可以在此接口上封装实现。
	// SymCipher for PKCS11

	#define ES_PADDING_PKCS5	1
	#define ES_PADDING_NONE		0
	#define ES_MODE_CBC			1
	#define ES_MODE_ECB			0
	#define ES_MODE_ENC			1
	#define ES_MODE_DEC			0

	u4 CALL_TYPE EsSymmCipherInit(u4 u4SlotId, u4 u4AlgId, u4 u4BlockSize,
								 const u1* pu1Key, u4 u4KeyLen, const u1 *pu1IV, u4 u4IVLen,
								 u4	u4Mode, u4 u4Padding, ESHANDLE* phEsCipher);
	u4 CALL_TYPE EsSymmCipherRelease(ESHANDLE hEsCipher);
	u4 CALL_TYPE EsSymmCipherOperation(ESHANDLE hEsCipher, u4 u4OperationType, u1* pu1Out, u4* pu4OutLen, const u1* pu1In, u4 u4InLen);
	u4 CALL_TYPE EsSymmCipherUpdate(ESHANDLE hEsCipher,u4 u4OperationType, u1* pu1Out, u4* pu4OutLen, const u1* pu1In, u4 u4InLen);
	u4 CALL_TYPE EsSymmCipherFinal(ESHANDLE hEsCipher,u4 u4OperationType, u1* pu1Out, u4* pu4OutLen);

	// 这两个接口主要是CSP调用，为了在上层调用为取长度和上层缓冲区长度不足时不进行实质性的运算，特提供以下两个接口
	// EsSymCipherEncryptGetOutLen,EsSymCipherDecryptGetOutLen are for CSP convenience
	u4 CALL_TYPE EsSymCipherEncryptGetOutLen(ESHANDLE hEsCipher, u4* pu4OutLen, u4 u4InLen, u4 u4FinalFlag);
	u4 CALL_TYPE EsSymCipherDecryptGetOutLen(ESHANDLE hEsCipher, u4* pu4OutLen, u4 u4InLen, u4 u4FinalFlag);
	//---------------------------------------------------------------------------------

	#define	ES_ASYM_ALG_RSA		 0x01
	#define	ES_ASYM_ALG_SM2		 0x02
	#ifndef _BLKASYMKEY_
	#define _BLKASYMKEY_
	typedef struct BlkRsaKeyTag
	{
		u4				m_u4ELen;
		u1				m_pu1E[256];
		u1				m_pu1N[256];
		u1				m_pu1D[256];
		u1				m_pu1P[128];
		u1				m_pu1Q[128];
		u1				m_pu1Dp[128];
		u1				m_pu1Dq[128];
		u1				m_pu1Qinv[128];
	}BlkRsaKey;
	typedef struct BlkSm2KeyTag
	{
		u1				m_pu1PubKeyX[32];
		u1				m_pu1PubKeyY[32];
		u1				m_pu1PriKeyD[32];
	}BlkSm2Key;
	typedef union UnionAsymKeyTag
	{
		BlkRsaKey		m_blkRsaKey;
		BlkSm2Key		m_blkSm2Key;
	}UnionAsymKey;
	typedef struct BlkAsymKeyTag
	{
		u4				m_u4AlgId;
		u4				m_u4ModLen;
		UnionAsymKey	m_unionAsymKey;
	}BlkAsymKey;
	#endif

	// Asym alg -- RSA
	// for big number, MSB first
	// pvPubKeyE 4 bytes
	u4 CALL_TYPE EsRsaGen(int iModBitLen, void*	pvPubKeyN, void* pvPubKeyE, void* pvPriKeyD,void* pvPriKeyP, void* pvPriKeyQ, void* pvPriKeyDP, void* pvPriKeyDQ, void*	pvPriKeyQInv);
	u4 CALL_TYPE EsRsaEnc(u2 u2ModLen, const void* pvPubKeyN, const void* pvPubKeyE, u4 u4ELen, const void* pvInput, void* pvOutput);
	u4 CALL_TYPE EsRsaSign(const BlkAsymKey* pblkAsymKey, u4 u4HashAlgId, const void* pvHashValue, void* pvSignature, u4* pu4SignatureLen);
	u4 CALL_TYPE EsRsaVerify(u2 u2ModLen, const void* pvPubKeyN, const void* pvPubKeyE, u4 u4ELen,const void* pvHashValue, u4 u4HashValueLen, const void* pvSignature, u4 u4SignatureLen);
	u4 CALL_TYPE EsRsaDecD(u2 u2ModLen, const void* pvPriKeyN, const void* pvPriKeyD, const void* pvInput, void* pvOutput);
	u4 CALL_TYPE EsRsaDec(u2 u2ModLen, const void* pvPriKeyP, const void* pvPriKeyQ, const void* pvPriKeyDP, const void* pvPriKeyDQ, const void* pvPriKeyQinv, const void* pvInput, void* pvOutput);

	// Asym alg -- SM2
	// for big number, MSB first
	u4 CALL_TYPE EsSm2GenKey(u1* pu1PriKeyD, u1* pu1PubKeyQx, u1* pu1PubKeyQy);
	u4 CALL_TYPE EsSm2Sign(const u1* pu1PriKeyD, const u1* pu1HashValue, u1* pu1SignatureR, u1* pu1SignatureS);
	u4 CALL_TYPE EsSm2Verify(const u1* pu1PubKeyQx, const u1* pu1PubKeyQy, const u1* pu1HashValue, const u1* pu1SignatureR, const u1* pu1SignatureS);
	u4 CALL_TYPE EsSm2GetZa(const char* pszID, const u1* pu1PubKeyQx, const u1* pu1PubKeyQy, u1 * pu1Za);
	u4 CALL_TYPE EsSm2Enc(const u1 * pu1PubKeyQx, const u1 * pu1PubKeyQy, const u1 * pu1Plain, u4 u4PlainLen, u1 * pu1Cipher, u4 * pu4CipherLen);
	u4 CALL_TYPE EsSm2Dec(const u1* pu1PriKeyD, const u1* pu1Cipher, u4 u4CipherLen, u1* pu1Plain, u4* pu4PlainLen);

	u1 CALL_TYPE EsSm3Hash(ESBOOL bCalcZa, const BlkAsymKey* pblkAsymKey, const void* pvMsg, u4 u4MsgLen, u1* pu1HashValue);
	u4 CALL_TYPE EsAsymGenKeyPair(BlkAsymKey* pblkAsymKey);
	u4 CALL_TYPE EsAsymSign(const BlkAsymKey* pblkAsymKey, const void* pvSignData, void* pvSignature, u4* pu4SignatureLen);
	u4 CALL_TYPE EsAsymEnc(const BlkAsymKey* pblkAsymKey, const void* pvPlainText, u4 u4PlainTextLen, void* pvCipherText, u4* pu4CipherTextLen);
	u4 CALL_TYPE EsAsymDec(const BlkAsymKey* pblkAsymKey, const void* pvCipherText, u4 u4CipherTextLen, void* pvPlainText, u4* pu4PlainTextLen);
	u4 CALL_TYPE EsAsymVerifySignature(const BlkAsymKey* pblkAsymKey, u4 u4HashAlgId, const void* pvHashValue, const void* pvSignature, u4 u4SignatureLen);
	u4 CALL_TYPE EsAsymVerifySignatureMsg(const BlkAsymKey* pblkAsymKey, ESBOOL bCalcZa, u4 u4HashAlgId, const void* pvMsg, u4 u4MsgLen, const void* pvSignature, u4 u4SignatureLen);
	u4 CALL_TYPE EsAsymSignMsg(const BlkAsymKey* pblkAsymKey, u4 u4HashAlgId, const void* pvMsg, u4 u4MsgLen, void* pvSignature, u4* pu4SignatureLen);


	typedef struct BlkSm2CtxTag
	{
		u4 m_u4State;					// 0x00 未计算过C1, 0x01 已经计算过C1
		u1 m_pu1RFU[0x40+0x04+0x68];    // 函数内部使用的结构，调用者不用关心
	}BlkSm2Ctx;
	// u4FinalFlag = 0x00 数据长度必须是0x40的整数倍
	// u4FinalFlag = 0x01 数据长度任意
	u4 CALL_TYPE EsSm2EncEx(const u1 * pu1PubKeyQx, const u1 * pu1PubKeyQy, u4 u4FinalFlag, BlkSm2Ctx* pblkSm2Ctx, const u1 * pu1Plain, u4 u4PlainLen, u1 * pu1Cipher, u4 * pu4CipherLen);


	// 先要设置好结构中的AlgId和ModLen
	u4 CALL_TYPE EsAsymGenKeyPair(BlkAsymKey* pblkAsymKey);

	#	define	PADDING_TYPE_ZERO		0x00	// padding 00
	#	define	PADDING_TYPE_PKCS_1		0x01	// padding fmt: 00 01 FF...FF 00 Data
	#	define	PADDING_TYPE_PKCS_2		0x02	// padding fmt: 00 02 PS 00 Data
	#	define	PADDING_TYPE_PKCS_5		0x05	// padding fmt: XX[XX]
	#	define	PADDING_TYPE_PKCS_9		0x09	// padding fmt: 00 09 FF...FF 00 Data
	#	define	PADDING_TYPE_7816		0x80	// padding fmt: Data 80 00..00，如果Data是满分组，就不补足
	u4 CALL_TYPE EsPadding(const void* pvOrgData, u4 u4OrgDataLen, u4 u4PaddingType, u4 u4ModOrBlockLen, void* pvOutData, u4* pu4OutDataLen);
	u4 CALL_TYPE EsPaddingRemove(const void* pvOrgData, u4 u4OrgDataLen, u4 u4PaddingType, u4 u4ModOrBlockLen, void* pvOutData, u4 *pu4OutDataLen);

#ifdef __cplusplus
};
#endif

#endif