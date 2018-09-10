#ifndef _ES_ENCODE_DECODE_H_
#define _ES_ENCODE_DECODE_H_

#ifdef __cplusplus
extern "C" {
#endif

	// Base64
	// 返回编码后的长度
	u4 CALL_TYPE EsBase64Encode(const u1* pu1Src, u4 u4SrcLen, char * pszBase64code, u4 u4Base64BufLen);
	// 返回解码后的长度
	u4 CALL_TYPE EsBase64Decode(const char * pszBase64code, u4 u4Base64CodeLen, u1 * pu1Buf);

	// Der 
	// 返回编码后的长度（含TLV）
	// 编码OID时忽略参数u4ValueLen
	u4 CALL_TYPE EsDerEncode(u4 u4Tag, const void* pvValue, u4 u4ValueLen, u1* pu1Der);
	// 返回元素的大小（含TLV）
	u4 CALL_TYPE EsDerGetElementLen(u1* pu1Der, u4* pu4LenLen);
	u4 CALL_TYPE EsDerGetTagAndLen(const u1* pu1DerData, u4 u4DerDataLen, u2* pu2Tag, u4* pu4ValueLen, u4* pu4TagLenSize);
	u4 CALL_TYPE EsDerSkipTlv(u1** ppu1Data, u4* pu4DataLen, u2 u2ExpectTag);
	void CALL_TYPE EsDerEncodePubKey(const BlkAsymKey *pblkAsymPubKey, u1* pu1PubKeyEncoded, u4 * pu4PubKeyEncodedLen);
	u4 CALL_TYPE EsDerDecodePubKey(const u1* pu1PubKeyEncoded, u4 u4PubKeyEncodedLen, BlkAsymKey * pblkAsymKey);
	void CALL_TYPE EsDerEncodePriKey(const BlkAsymKey* pblkAsymKey, u1* pu1DerPriKey, u4* pu4DerPriKeyLen);
	u4 CALL_TYPE EsDerDecodePriKey(const u1* pu1DerPriKey, u4 u4DerPriKeyLen, BlkAsymKey* pblkAsymKey);
	u4 CALL_TYPE EsDerEncodeSm2Signature(const u1* pu1Sm2Signature, u4 u4SignatureLen, u1* pu1DerSignature, u4* pu4DerSignatureLen);
	u4 CALL_TYPE EsDerDecodeSm2Signature(const u1* pu1DerSignature, u4 u4DerSignatureLen, u1* pu1Signature, u4* pu4SignatureLen);

	// Cert
	typedef enum EN_CERT_PARAM
	{
		CERT_PARAM_VALID_TIME_BEGIN = 0,	// YYMMDDHHMMSS
		CERT_PARAM_VALID_TIME_END = 1,		// YYMMDDHHMMSS
		CERT_PARAM_SIGN_ALG = 2,			// [4] ES_ASYM_ALG_XXX
	}EN_CERT_PARAM;

	// pu4ValueLen IN OUT
	u4 CALL_TYPE EsCertGetParam(const u1* pu1Cert, EN_CERT_PARAM enCertParam, u1* pu1Value, u4* pu4ValueLen);

#ifdef __cplusplus
};
#endif

#endif