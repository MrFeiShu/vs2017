#ifndef _ESDER_H_
#define _ESDER_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "EsBer.h"

#ifndef szOID_SM2
#	define szOID_SM2			"1.2.156.10197.1.301"
#	define szOID_SM3			"1.2.156.10197.1.401"
#	define szOID_SM2_ENCRYPT	"1.2.156.10197.1.301.3"
#	define szOID_SM2_SM3		"1.2.156.10197.1.501"
#	define szOID_RSA_SM3		"1.2.156.10197.1.504"
#endif

#ifndef	szOID_ECC_PUBLIC_KEY
#	define szOID_ECC_PUBLIC_KEY "1.2.840.10045.2.1"
#endif
#ifndef	szOID_RSA_SHA256RSA
#	define szOID_RSA_SHA256RSA  "1.2.840.113549.1.1.11"
#endif
#ifndef	szOID_RSA_SHA384RSA
#	define szOID_RSA_SHA384RSA  "1.2.840.113549.1.1.12"
#endif
#ifndef	szOID_RSA_SHA512RSA
#	define szOID_RSA_SHA512RSA  "1.2.840.113549.1.1.13"
#endif
#ifndef	szOID_3DES168
#	define szOID_3DES168        "1.3.6.1.4.1.4929.1.7"
#endif
#ifndef szOID_RSA_RSA 
#   define szOID_RSA_RSA        "1.2.840.113549.1.1.1"
#endif
#ifndef szOID_RSA_SHA1RSA
#   define szOID_RSA_SHA1RSA    "1.2.840.113549.1.1.5"
#endif
#ifndef szOID_RSA_MD5RSA
#   define szOID_RSA_MD5RSA     "1.2.840.113549.1.1.4"
#endif
#ifndef szOID_OIWSEC_sha1
#   define szOID_OIWSEC_sha1    "1.3.14.3.2.26"
#endif
#ifndef szOID_RSA_data
#   define szOID_RSA_data       "1.2.840.113549.1.7.1"
#endif
#ifndef szOID_PKCS_7_DATA
#   define szOID_PKCS_7_DATA       "1.2.840.113549.1.7.1"
#endif
#ifndef szOID_PKCS_7_SIGNED
#   define szOID_PKCS_7_SIGNED       "1.2.840.113549.1.7.2"
#endif
#ifndef szOID_SUBJECT_KEY_IDENTIFIER
#   define szOID_SUBJECT_KEY_IDENTIFIER "2.5.29.14"
#endif
#ifndef szOID_RSA_challengePwd
#   define szOID_RSA_challengePwd   "1.2.840.113549.1.9.7"
#endif
#ifndef szOID_OIWSEC_sha1RSASign
#   define szOID_OIWSEC_sha1RSASign "1.3.14.3.2.29"
#endif
#ifndef szOID_KEY_USAGE
#   define szOID_KEY_USAGE      "2.5.29.15"
#endif

typedef BlkBer		BlkDer;
typedef BlkBerTree	BlkDerTree;

u4 CALL_TYPE EsDerOidStr2Hex(const char* pszOidStr, u1* pu1OidDer, u4* pu4OidDerLen);
u4 CALL_TYPE EsDerEncodeAlg(const char* pszAlg, const u1* pu1DerParam, u4 u4DerParamLen, u1* pu1DerOid, u4* pu4DerOidLen);
u4 CALL_TYPE EsDerOidHex2Str(const u1* pu1HexOid, char* pszStrOid);
u4 CALL_TYPE EsDerOid2Str(const BlkBer* pblkBerOid, char* pszOid);
u4 CALL_TYPE EsDerOid2EsAlgId(const BlkBer* pblkBerOid, u4* pu4SignAlgId, u4* pu4HashAlgId);
u4 CALL_TYPE EsDerGetAlgIdFromAlgSequence(const BlkBerTree* pblkBerTree, u4* pu4SignAlgId, u4* pu4HashAlgId);
u4 CALL_TYPE EsDerTreeGetDnFromSubject(const BlkBerTree* pblkBerTree, char* pszDn, u4* pu4DnLen);
u4 CALL_TYPE EsDerTreeGetPublicKey(const BlkBerTree* pblkBerTree, BlkAsymKey* pblkAsymKey);
u4 CALL_TYPE EsDerTreeGetTempPublicKey(const BlkBerTree* pblkBerTree, BlkAsymKey* pblkAsymKey);

u4 CALL_TYPE EsDerDecodeSm2Signature(const u1* pu1DerSignature, u4 u4DerSignatureLen, u1* pu1Signature, u4* pu4SignatureLen);
u4 CALL_TYPE EsDerGetTagAndLen(const u1* pu1DerData, u4 u4DerDataLen, u2* pu2Tag, u4* pu4ValueLen, u4* pu4TagLenSize);
u4 CALL_TYPE EsDerSkipTlv(u1** ppu1Data, u4* pu4DataLen, u2 u2ExpectTag);
u4 CALL_TYPE EsDerGetPubKeyViaSequence(const u1* pu1Sequence, u4 u4SequenceLen, BlkAsymKey* pblkAsymKey);

u4 CALL_TYPE EsDerTreeGetSignature(const BlkBerTree* pblkBerTree, u4 u4SignAlgId, u1* pu1Signature, u4* pu4SignatureLen);

void CALL_TYPE EsDerTreeFree(BlkDerTree** ppblkDerTree);

u4 CALL_TYPE EsDerTreeNew(u2 u2Tag, const void* pvData, u4 u4DataLen, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewBigInt(const u1* pu1Value, u4 u4ValueLen, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewInteger(u4 u4Integer, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewBitString(const u1* pu1HexData, u4 u4HexDataLen, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewOctString(const u1* pu1HexData, u4 u4HexDataLen, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewNull(BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewOid(const char* pszOid, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewUtf8(const u1* pu1Utf8, u4 u4Utf8Len, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewSequence(BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewSet(BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewPrintableString(const char* pszString, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewUtc(const char* pszTime, BlkDerTree** ppblkDerTree);

u4 CALL_TYPE EsDerTreeNewSequenceOid(const char* pszOid, BlkDerTree* pblkDerTreeOidParam, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewSignOid(u4 u4AsymAlgId, u4 u4HashAlgId, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewPubKey(const BlkAsymKey* pblkAsymKey, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewParent(u2 u2Tag, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewParent2(u2 u2Tag, BlkDerTree** pblkDerTree1, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewSubject(const char* pszSubjectName, u4 u4SubjectNameLen, const char* pszSubjectValue, BlkDerTree** ppblkDerTree);
u4 CALL_TYPE EsDerTreeNewSubjectSequence(const char* pszDn, u4 u4DnLen, BlkBerTree** ppblkDerTree);

#define EsDerCalcTagLenSize(pblkDerTree)								EsBerCalcTagLenSize((BlkBerTree*)(pblkDerTree))
#define EsDerTreeDeflat(pu1DerData, u4DerDataLen, ppblkDerTree)			EsBerTreeDeflat(pu1DerData, u4DerDataLen, (BlkBerTree**)(ppblkDerTree))
#define EsDerTreeFlat(pblkDerTree, pu1DerData, pu4DerDataLen)			EsBerTreeFlat((BlkBerTree*)(pblkDerTree), pu1DerData, pu4DerDataLen)
#define EsDerTreeAddChild(pblkBerTreeParent, pblkBerTreeChild)			EsBerTreeAddChild((BlkBerTree*)(pblkBerTreeParent), (BlkBerTree*)(pblkBerTreeChild));
#define EsDerTreeMerge(u2Tag, pblkDerTree1, pblkDerTree2, ppblkDerTree)	EsBerTreeMerge(u2Tag, (BlkBerTree*)(pblkDerTree1), (BlkBerTree*)(pblkDerTree2), (BlkBerTree**)(ppblkDerTree))

#ifdef __cplusplus
};
#endif

#endif
