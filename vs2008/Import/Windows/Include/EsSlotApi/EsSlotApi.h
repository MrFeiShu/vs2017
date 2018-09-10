#ifndef _ES_SLOT_API_H_
#define _ES_SLOT_API_H_

#define SLOTAPI_VERSION					0x0002		// 目前的接口版本号，调用SlotGetFunctionList的时候要设置此版本号

#define MAX_SLOT_NUM					0x20

// 密钥对类型：交换还是签名
#define KEYSPEC_KEYEXCHANGE				0x01
#define KEYSPEC_SIGNATURE			    0x02

// 容器对象类型，可与"密钥对类型"以或的形式组合(用于删除容器时的FLAG参数)
#define AT_CERT							0x10
#define AT_KEYPAIR						0x20

#define AT_CONTAINER_SIGNATURE			(AT_CERT|AT_KEYPAIR|KEYSPEC_SIGNATURE)
#define AT_CONTAINER_KEYEXCHANGE		(AT_CERT|AT_KEYPAIR|KEYSPEC_KEYEXCHANGE)
#define AT_CONTAINER					(AT_CONTAINER_SIGNATURE|AT_CONTAINER_KEYEXCHANGE)

// 算法标识--非对称算法
#define SLOT_ALGID_SM2					0x02
#define SLOT_ALGID_RSA					0x01

// 算法标识--对称算法
// 更新为与ES_SYMM_ALG_DES等保持值一致  diff.
#define SLOT_ALGID_DES					0x0001	// 64比特密钥
#define SLOT_ALGID_3DES2				0x0002	// 128比特密钥
#define SLOT_ALGID_3DES3				0x0004	// 192比特密钥
#define SLOT_ALGID_SSF33				0x0100
#define SLOT_ALGID_SM1					0x0200
#define SLOT_ALGID_SM4					0x0400

// 算法标识--哈希算法
#define SLOT_ALGID_MD5					0x80000001
#define SLOT_ALGID_SHA1					0x80000002
#define SLOT_ALGID_SHA256				0x80000003
#define SLOT_ALGID_SHA384				0x80000004
#define SLOT_ALGID_SHA512				0x80000005
#define SLOT_ALGID_SM3					0x80000006
#define SLOT_ALGID_MD5SHA1				0x80000007
#define SLOT_ALGID_HASHSET				0x800000FF
// 算法标识--硬件哈希算法
#define SLOT_HWALGID_MD5				0x00000001
#define	SLOT_HWALGID_SHA1				0x00000002
#define SLOT_HWALGID_SHA256				0x00000003
#define SLOT_HWALGID_SHA384				0x00000004
#define SLOT_HWALGID_SHA512				0x00000005
#define SLOT_HWALGID_SM3				0x00000006

// 口令类型
#define	SLOT_PIN_TYPE_USER				0x01
#define SLOT_PIN_TYPE_SO				0x02
#define SLOT_PIN_TYPE_CFCA				0x03 // YuZhi-cfca专用
#define SLOT_PIN_TYPE_YUZHI				0x03
#define SLOT_PIN_TYPE_DEV               0X04
#define SLOT_PIN_ASSURE_ORGPIN_MODIFY	0x8000 //修改原始密码

#define PIN_MAX_LEN						0x40

typedef enum EnInitTokenParamVersion
{
	INIT_TOKEN_PARAM_VERSION_1 = 0,
	INIT_TOKEN_PARAM_VERSION_2,     // Icbc-GM
	INIT_TOKEN_PARAM_VERSION_3,
}EnInitTokenParamVersion;

typedef struct BlkInitTokenParamV1Tag
{
	char	m_szTokenName[0x40];
	u4		m_u4TokenNameLen;
	u1		m_pu1UserPin[PIN_MAX_LEN];
	u4		m_u4UserPinLen;
	u1		m_u1UserPinRetry; 
}BlkInitTokenParamV1;

typedef struct BlkInitTokenParamV2Tag
{
	char	m_szTokenName[0x40];
	u4		m_u4TokenNameLen;
	u1		m_pu1UserPin[PIN_MAX_LEN];
	u4		m_u4UserPinLen;
	u1		m_u1UserPinRetry; 

	ESBOOL	m_bCachePin;			// 工行高柜版本要求格式化缓存PIN，工行普通版本不缓存PIN
	u1		m_pu1ServerRand[0x0F];
	u4		m_u4EncSnLen;			// 0x00:Icbc-old >0x00:Icbc-GM
	u1		m_pu1EncSn[0x20];
}BlkInitTokenParamV2;

typedef struct BlkInitTokenParamV3Tag
{
	u1					__[0x04];	// 不用赋值
}BlkInitTokenParamV3;

typedef struct BlkInitTokenParamTag
{
	EnInitTokenParamVersion		m_enVersion;
	union
	{
		BlkInitTokenParamV1 m_v1;		// 标准结构
		BlkInitTokenParamV2	m_v2;		// 工行结构（含工行旧盾/国密盾）
		BlkInitTokenParamV3	m_v3;		// 不修改用户PIN的格式化
		u1					__[0x180];
	}u;
}BlkInitTokenParam;

#define CNT_PUBKEY_EXIST				0x01
#define CNT_PRIKEY_EXIST				0x02
#define CNT_CERT_EXIST					0x04

typedef struct BlkCntAttrTag
{
	u4		m_u4ExistFlag;				// 公钥、私钥、证书存在标志，参见宏CNT_XXX_EXIST
	u4		m_u4KeyType;				// 密钥类型 RSA(0x00)、SM2(0x01)
	u4		m_u4ModBits;				// 模长 RSA1024(0x400) RSA2048(0x800) SM2(0x100)
	u4		m_u4CertFileSize;			// 证书文件大小
	u4		m_u4PubKeyAttrSize;			// 公钥属性文件大小
	u4		m_u4PriKeyAttrSize;			// 私钥属性文件大小
	u4		m_u4CertAttrSize;			// 证书属性文件大小
}BlkCntAttr;

typedef struct BlkCntInfoTag
{
	char		m_szCntName[65];		// 容器名称
	u4			m_u4CntNameLen;			// 容器名称长度
	u1			m_u1CntIndex;			// 容器索引，从1开始计数
	BlkCntAttr	m_blkAttrSign;			// 签名密钥属性
	BlkCntAttr	m_blkAttrExch;			// 交换密钥属性
}BlkCntInfo;

#define TIF_TOKEN_INITIALIZED			0x00000400
#define TIF_USER_PIN_TO_BE_CHANGED		0x00080000
#define TIF_SO_PIN_TO_BE_CHANGED		0x00800000
#define TIF_USER_PIN_INITIALIZED		0x00000008
#define TIF_LOGIN_REQUIRED				0x00000004
#define TIF_RNG							0x00000001
#define TIF_NOT_ACTIVATED				0x10000000

typedef struct BlkTokenInfoTag
{
	u4		m_u4Size;				// 结构的大小，包括自身的大小
	u4		m_u4Version;			// 结构版本号
	char	m_szTokenName[32];		// 设备名称
	u4		m_u4TokenNameLen;		// 设备名称长度
	char	m_szTokenSn[32];		// 设备序列号
	u4		m_u4TokenSnLen;			// 设备序列号长度
	u4		m_u4SupportAlgFlag;		// 设备支持的算法标志

	u4		m_u4MinPinLen;			// PIN的最小长度
	u4		m_u4MaxPinLen;			// PIN的最大长度
	u4		m_u4PinMaxRetryNum;		// PIN码最大重试次数
	u4		m_u4PinLeftRetryNum;	// PIN码剩余重试次数

	u4		m_u4TotalMemory;		// 总空间容量
	u4		m_u4FreeMemory;			// 剩余空间容量
	u4		m_u4TotalPubMemory;		// 总的公用空间容量
	u4		m_u4TotalPriMemory;		// 总的私有空间容量
	u4		m_u4FreePubMemory;		// 剩余公用空间容量
	u4		m_u4FreePriMemory;		// 剩余私有空间容量
	u4		m_u4MaxContainerNum;	// 最大容器数目

	u4		m_u4Flags;				// 一些标志位，参考宏TIF_XXX
	char	m_szPathName[260];		// 设备的符号链接名称，驱动层返回
}BlkTokenInfo;

typedef struct BlkSlotInfoTag
{
	u4		m_u4Version;			// 0
	u4		m_u4SlotState;			// B0:本端口是否存在设备
	char	m_szPathName[260];		// 设备的符号链接名称，驱动层返回
}BlkSlotInfo;

#ifndef _BLK_SM2_INFO_
#define _BLK_SM2_INFO_
typedef struct BlkSM2InfoTag
{
	u4	m_u4State;			// 0x00 没有发送第一个分组
	// 0x01 已经发送过第一个分组
	u1	m_pu1Data[0x60];	// 缓存的密文数据
}BlkSM2Info;
#endif // _BLK_SM2_INFO_

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

typedef struct BlkCommUiMsgTag
{
    u4      u4Size;
    ESBOOL  bCloseWhenRemoved;
    u4      u4SlotId;
    u4      u4MsgId;
    u4      u4Param;
    u1*     pu1ExtraParam;
    u4      u4ExtraParamLen;
}BlkCommUiMsg;

#ifndef _BLK_ENV_ASYMKEY_
#define _BLK_ENV_ASYMKEY_

#define ENV_SYMMALG_PLAIN	0x00
#define ENV_SYMMALG_3DES168	0x01    // 24=168/7字节密钥
#define ENV_SYMMALG_3DES112	0x02    // 16=112/7字节密钥
#define ENV_SYMMALG_SSF33	0x03
#define ENV_SYMMALG_SM1		0x04
#define ENV_SYMMALG_AES128	0x05
#define ENV_SYMMALG_AES192	0x06
#define ENV_SYMMALG_AES256	0x07
#define ENV_SYMMALG_SM4		0x08

#define ENV_ASYMALG_RSA1024	0x00
#define ENV_ASYMALG_RSA2048	0x01
#define ENV_ASYMALG_SM2		0x80

typedef struct BlkEnvAsymKeyTag
{
	u4	m_u4EncType;
	u4	m_u4AsymAlg;
	u1* m_pu1EncSymmKey;
	u4	m_u4EncSymmKeyLen;
	u1* m_pu1EncAsymKey;
	u4	m_u4EncAsymKeyLen;
}BlkEnvAsymKey;
#endif // _BLK_ENV_ASYMKEY_

typedef u4 (CALL_TYPE *FunSlotLibInit)(void);
typedef u4 (CALL_TYPE *FunSlotLibFinal)(void);

#define SLOT_LIST_ONLY_EXIST     0x01
#define SLOT_LIST_ALL_SUPPORT    0x00

typedef u4 (CALL_TYPE *FunSlotList)(u4 u4ListType, u4 *pu4SlotIdList, u4* pu4SlotIdCount);
typedef u4 (CALL_TYPE *FunSlotLock)(u4 u4SlotId);
typedef u4 (CALL_TYPE *FunSlotLockTimeout)(u4 u4SlotId, u4 u4Timeout);
typedef u4 (CALL_TYPE *FunSlotUnlock)(u4 u4SlotId);
typedef u4 (CALL_TYPE *FunSlotInitToken)(u4 u4SlotId, const BlkInitTokenParam* pblkInitTokenParam);
typedef u4 (CALL_TYPE *FunSlotGetInfo)(u4 u4SlotId, BlkSlotInfo *pblkSlotInfo);
typedef u4 (CALL_TYPE *FunSlotGetTokenInfo)(u4 u4SlotId, BlkTokenInfo* pblkTokenInfo);
typedef u4 (CALL_TYPE *FunSlotGetMediaId)(IN u4 u4SlotId, OUT u1* pu1MediaId, OUT u4* pu4MediaIdLen);

typedef u4 (CALL_TYPE *FunSlotGetCharSetList)(u4 u4SlotId, EnCharSet * pEnCharSetList, u4* pu4CharSetCount);
typedef u4 (CALL_TYPE *FunSlotGetCharSet)(u4 u4SlotId, EnCharSet * pEnCharSet);
typedef u4 (CALL_TYPE *FunSlotSetCharSet)(u4 u4SlotId, EnCharSet enCharSet);
#define MAX_LANG_ID_COUNT 200 // 最多支持的语言种类为200
typedef u4 (CALL_TYPE *FunSlotGetLangIdList)(u4 u4SlotId, EnLangId * pEnLangIdList, u4* pu4LangIdCount);
typedef u4 (CALL_TYPE *FunSlotGetLangId)(u4 u4SlotId, EnLangId * pEnLangId);
typedef u4 (CALL_TYPE *FunSlotSetLangId)(u4 u4SlotId, EnLangId enLangId);

// event
#define SLOT_EVENT_INSERT		0x01
#define SLOT_EVENT_REMOVE		0x02
#define SLOT_EVENT_SLEEP_RESUME	0x03
#define SLOT_EVENT_FORMAT		0x04
#define SLOT_EVENT_DATA_CHANGE	0x05
#define SLOT_EVENT_PIN_CHANGE	0x06
#define SLOT_EVENT_GEN_KEY		0x07
#define SLOT_EVENT_GEN_CERT		0x08
#define SLOT_EVENT_GEN_CERT_FINISH	0x09
#define SLOT_EVENT_DEV_DISCONNECTED 0x0A
typedef u4 (CALL_TYPE *FunSlotEventRoutine)(u4 u4SlotId, u4 u4EventType);
// u4RegType 类别
#define REG_EVENT_CSP			1	// CSP注册
#define REG_EVENT_PKCS11		2	// PKCS11注册
#define REG_EVENT_BROWSER		3	// 控件注册
#define REG_EVENT_MANAGETOOL	4	// 管理工具注册
#define REG_EVENT_SKF           5   // 国密接口注册
typedef u4 (CALL_TYPE *FunSlotRegDevEventCallback)(u4 u4RegType, ESBOOL bIsResister, FunSlotEventRoutine funSlotEnventRoutine);

typedef u4 (CALL_TYPE *FunSlotCntFind)(u4 u4SlotId, const char* szCntName, u4* pu4CntId);
typedef u4 (CALL_TYPE *FunSlotCntCreate)(u4 u4SlotId, const char* szCntName, u4* pu4CntId);
typedef u4 (CALL_TYPE *FunSlotCntDelete)(u4 u4CntId, u4 u4DeleteFlag);
typedef u4 (CALL_TYPE *FunSlotCntList)(u4 u4SlotId, u4* pu4CntList, u4* pu4CntNum);

#define KEY_PAIR_USE_LIMIT_SIGN_1G 0x00000001
#define KEY_PAIR_USE_LIMIT_SIGN_2G 0x00000002
typedef u4 (CALL_TYPE *FunSlotCntGenKey)(u4 u4CntId, u4 u4KeySpec, u4 u4AlgId, u4 u4ModBits, u4 u4KeyPairUseLimit);
typedef u4 (CALL_TYPE *FunSlotCntWriteCert)(u4 u4CntId, u4 u4KeySpec, const u1* pu1Cert, u4 u4CertLen);
typedef u4 (CALL_TYPE *FunSlotCntReadCert)(u4 u4CntId, u4 u4KeySpec, u1* pu1Cert, u4* pu4CertLen);
typedef u4 (CALL_TYPE *FunSlotCntGetInfo)(u4 u4CntId, BlkCntInfo *pblkCntInfo);
typedef u4 (CALL_TYPE *FunSlotCntReadPubKey)(u4 u4CntId, u4 u4KeySpec, BlkAsymKey* pblkAsymKey);
typedef u4 (CALL_TYPE *FunSlotCntWritePubKey)(u4 u4CntId, u4 u4KeySpec, const BlkAsymKey* pblkAsymKey);
typedef u4 (CALL_TYPE *FunSlotCntWritePriKey)(u4 u4CntId, u4 u4KeySpec, const BlkAsymKey* pblkAsymKey);

#ifndef _BLK_PROTECT_MODE_DEFINED
#define _BLK_PROTECT_MODE_DEFINED
#pragma pack(push,1)
typedef enum EnProtectMode
{
	PROTECT_MODE_OLD = 0,
	PROTECT_MODE_NEW,
}EnProtectMode;
typedef enum EnReadPubKeyMode
{
	READ_PUBKEY_MODE_USAGE = 0x0000,  // 读取公钥用途
	READ_PUBKEY_MODE_CERTREQUEST = 0x3031,
	READ_PUBKEY_MODE_SIGN = 0x3032,
}EnReadPubKeyMode;
typedef struct BlkReadEncryptedPubKeyParamTag
{
	EnProtectMode		m_enProtectMode;
	EnReadPubKeyMode	m_enReadPubKeyMode;   // 仅在新保护模式下有效
	u1					m_pu1ServerRand[0x0F];// 仅在新保护模式下有效
}BlkReadEncryptedPubKeyParam;

typedef struct BlkUpdateProtectKeyParamTag
{
	EnProtectMode	m_enProtectMode;
	u4				m_u4UpdataDataLen;
	u1				m_pu1UpdateData[0x3A];
}BlkUpdateProtectKeyParam;

typedef struct BlkProtectKeyInfoTag
{
	u2	m_u2No;				// "00" ~ "99"
	u2	m_u2Alg;			// "00" 3DES "01" AES256 "02" SM4
	u1	m_pu1Time[0x0E];    // YYYYMMDDhhmmss
	u1	m_pu1RandServer[0x04];
	u1	m_pu1ErrorCount[0x02]; // "FF"
}BlkProtectKeyInfo;
#pragma pack(pop)
#endif // _BLK_PROTECT_MODE_DEFINED
typedef struct BlkPubKeyItemTag
{
	u4 m_u4CntIndex; // BlkCntInfo中的m_u1CntIndex
	u4 m_u4KeySpec;
}BlkPubKeyItem;
typedef struct BlkPubKeyListTag
{
	u4				m_u4Count;
	BlkPubKeyItem	pblkPubKeyItem[0x06 * 2];
}BlkPubKeyList;

typedef u4 (CALL_TYPE *FunSlotCntReadEncPubKey)(u4 u4SlotId, BlkPubKeyList* pblkPubKeyList, BlkReadEncryptedPubKeyParam* pblkReadParam, u1* pu1EncryptedPubKey, u4* pu4EncryptedPubKeyLen);

typedef u4 (CALL_TYPE *FunSlotCntEnc)(u4 u4CntId, u4 u4KeySpec, u4 u4FinalFlag, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
typedef u4 (CALL_TYPE *FunSlotCntDec)(u4 u4CntId, u4 u4KeySpec, u4 u4FinalFlag, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);

#define SLOT_SIGN_FLAG_RSA_NO_OID	0x01
#define SLOT_SIGN_FLAG_SM2_NO_ZA	0x02

typedef u4 (CALL_TYPE *FunSlotCntSignHash)(u4 u4CntId, u4 u4KeySpec, u4 u4HashHandle, void* pvSignature, u4* pu4SignatureLen);
typedef u4 (CALL_TYPE *FunSlotVerifySignHash)(u4 u4SlotId, BlkAsymKey *pblkAsymKey, u4 u4HashHandle, const void* pvSignature, u4 u4SignatureLen);

typedef u4 (CALL_TYPE *FunSlotVerifyPin)(u4 u4SlotId, u4 u4PinType, const u1* pu1Pin, u4 u4PinLen);
typedef u4 (CALL_TYPE *FunSlotChangePin)(u4 u4SlotId, u4 u4PinType, const u1 *pu1OldPin, u4 u4OldPinLen, const u1 *pu1NewPin, u4 u4NewPinLen);
typedef u4 (CALL_TYPE *FunSlotCachePinSet)(IN u4 u4SlotId, IN const u1* pu1Pin, IN u4 u4PinLen);
typedef u4 (CALL_TYPE *FunSlotCachePinVerify)(IN u4 u4SlotId);
typedef u4 (CALL_TYPE *FunSlotUnblockPin)(u4 u4SlotId, const u1* pu1AdminPin, u4 u4AdminPinLen, const u1* pu1UserPin, u4 u4UserPinLen);
typedef u4 (CALL_TYPE *FunSlotGetPinInfo)(IN u4 u4SlotId, u4 u4PinType, u4* pu4MaxRetryCount, u4* pu4LeftRetryCount, ESBOOL* pbDefault);
typedef u4 (CALL_TYPE *FunSlotUiUnblockPin)(u4 u4SlotId);

typedef u4 (CALL_TYPE *FunSlotHashInit)(u4 u4SlotId, u4 u4HashAlgId, u4* pu4HashHandle);
typedef u4 (CALL_TYPE *FunSlotHashData)(u4 u4HashHandle, const void* pvData, u4 u4DataLen, u4 u4FinalFlag);
typedef u4 (CALL_TYPE *FunSlotHashGetValue)(u4 u4HashHandle, void* pvHashValue, u4* pu4HashValueLen);
typedef u4 (CALL_TYPE *FunSlotHashSetValue)(u4 u4HashHandle, void* pvHashValue);
#define DATA_TYPE_1G 0x01
#define DATA_TYPE_2G 0x02
typedef u4 (CALL_TYPE *FunSlotHashGetDataType)(u4 u4HashHandle, u4* pu4HashDataType);
typedef u4 (CALL_TYPE *FunSlotHashRelease)(u4 u4HashHandle);

typedef u4 (CALL_TYPE *FunSlotGenRand)(u4 u4SlotId, void* pvRand, u4 u4Len);
typedef u4 (CALL_TYPE *FunSlotGetProtectKeyInfo)(u4 u4SlotId, BlkProtectKeyInfo* pblkProtectKeyInfo);
typedef u4 (CALL_TYPE *FunSlotUpdateProtectKey)(u4 u4SlotId, BlkUpdateProtectKeyParam* pblkUpdataProtectKeyParam);
typedef u4 (CALL_TYPE *FunSlotChangeLabel)(IN u4 u4SlotId, IN const char* pszLabel);

typedef struct BlkFileInfoTag
{
	u4	m_u4FileType;
	u4	m_u4FileSize;
	u2	m_u2FileId;
	u2	m_u2Reserve;
}BlkFileInfo;
#define SLOT_FILE_TYPE_PUBLIC	1
#define SLOT_FILE_TYPE_PRIVATE	2

typedef u4 (CALL_TYPE *FunSlotFileCreateViaName)(u4 u4SlotId, const char* szFileName, u4 u4FileSize, u4 u4FileType, u4* pu4FileHandle);
typedef u4 (CALL_TYPE *FunSlotFileEnum)(u4 u4SlotId, u4 u4FileType, u4* pu4FileHandleList, u4* pu4FileNum);
typedef u4 (CALL_TYPE *FunSlotFileGetName)(u4 u4SlotId, u4 u4FileHandle, char* szFileName, u4* pu4FileNameLen);

typedef u4 (CALL_TYPE *FunSlotFileCreate)(u4 u4SlotId, const BlkFileInfo* pblkFileInfo, u4* pu4FileHandle);
typedef u4 (CALL_TYPE *FunSlotFileDelete)(u4 u4SlotId, u4 u4FileHandle);
typedef u4 (CALL_TYPE *FunSlotFileFind)(u4 u4SlotId, u2 u2FileId, u4* pu4FileHandle);
typedef u4 (CALL_TYPE *FunSlotFileGetAttr)(u4 u4SlotId, u4 u4FileHandle, BlkFileInfo* pblkFileInfo);
typedef u4 (CALL_TYPE *FunSlotFileRead)(u4 u4SlotId, u4 u4FileHandle, void* pvData, u4 u4Offset, u4 u4ReadSize);
typedef u4 (CALL_TYPE *FunSlotFileWrite)(u4 u4SlotId, u4 u4FileHandle, const void* pvData, u4 u4Offset, u4 u4WriteSize);

// ui
typedef u4 (CALL_TYPE *FunSlotUiGetPin)(u4 u4SlotId, u4 u4PinType, ESBOOL bNeedConfirm, u1* pu1Pin, u4 * pu4PinLen);
typedef enum EnSnType
{
	SN_TYPE_DEFAULT		= 0,
	SN_TYPE_ENTERPRISE	= 1,
}EnSnType;
typedef enum EnVerifyPinSituation
{
	VERIFY_PIN_DEFAULT	= 0,
	VERIFY_PIN_SITUATION_GEN_KEY,
	VERIFY_PIN_SITUATION_DEC,
	VERIFY_PIN_SITUATION_SIGN_1G,
	VERIFY_PIN_SITUATION_SIGN_2G,
}EnVerifyPinSituation;
typedef struct BlkVerifyPinContextTag
{
	EnSnType				m_enSnType;
	EnVerifyPinSituation	m_enVerifyPinSituation;
}BlkVerifyPinContext;
typedef u4 (CALL_TYPE *FunSlotUiVerifyPin)(u4 u4SlotId, u4 u4PinType, BlkVerifyPinContext* pblkVerifyPinContext);
typedef u4 (CALL_TYPE *FunSlotUiChangePin)(u4 u4SlotId, u4 u4PinType);
typedef u4 (CALL_TYPE *FunSlotUiChangeLabel)(u4 u4SlotId);
typedef u4 (CALL_TYPE *FunSlotUiPrompt)(u4 u4PromtMsgID, u4 u4Param, u1* pu1ExtraParam, u4 u4ExtraParamLen);
typedef u4 (CALL_TYPE *FunSlotUiSelToken)(IN u4* pu4SelSlotId);
typedef u4 (CALL_TYPE *FunSlotUiSetLang)(u4 u4LangId);

// 设置警告信息
typedef u4 (CALL_TYPE *FunSlotSetWarningMsg)(IN u4 u4SlotId, IN const char *szWarningMsg);

// YuZhi-cfca 
typedef u4 (CALL_TYPE *FunSlotGetCfcaId)(u4 u4SlotId, u1* pu1CfcaId, u4* pu4CfcaIdLen);
typedef u4 (CALL_TYPE *FunSlotGetChipSn)(u4 u4SlotId, u1* pu1ChipSn, u4* pu4ChipSnLen);
typedef u4 (CALL_TYPE *FunSlotGenTempAsymKey)(u4 u4SlotId, u4 u4AlgId, u4 u4ModBits, BlkAsymKey* pblkAsymPubKey);
typedef u4 (CALL_TYPE *FunSlotCntEnvImportAsymKey)(u4 u4CntId, u4 u4ProKeyType, BlkEnvAsymKey* pblkEnvAsymKey, const BlkAsymKey* pblkAsymPubKey);

// SymmAlg
#define SLOT_SYMM_MODE_ECB 0x00
#define SLOT_SYMM_MODE_CBC 0x01
#define SLOT_SYMM_MODE_MAC 0x04

#define SLOT_SYMM_PADDING_NO	0x00
#define SLOT_SYMM_PADDING_PKCS5 0x01

typedef struct BlkSymmAlgInitTag
{
	u4		m_u4AlgId;       // SLOT_ALGID_xxx
	ESBOOL	m_bEncrypt;
	u4		m_u4BlockMode;   // SLOT_SYMM_MODE_xxx
	u4		m_u4PaddingMode; // SLOT_SYMM_PADDING_xxx
	u4		m_u4KeyLen;
	u1		m_pu1Key[0x40];
	u4		m_u4IvLen;
	u1		m_pu1Iv[0x40];
}BlkSymmAlgInit;

typedef u4 (CALL_TYPE *FunSlotSymmInit)(u4 u4SlotId, BlkSymmAlgInit* pblkSymmAlgInit);

typedef u4 (CALL_TYPE *FunSlotSymmUpdate)(u4 u4SlotId, const u1* pu1DataIn, u4 u4DataInLen, u1* pu1DataOut, u4* pu4DataOutLen);

typedef u4 (CALL_TYPE *FunSlotSymmFinal)(u4 u4SlotId, u1* pu1DataOut, u4* pu4DataOutLen);

typedef enum EnFontType
{
	FONT_TYPE_16 = 16,
	FONT_TYPE_24 = 24,
}EnFontType;

typedef u4 (CALL_TYPE *FunSlotSetFontType)(u4 u4SlotId, EnFontType enFontType);
typedef u4 (CALL_TYPE *FunSlotGetFontType)(u4 u4SlotId, EnFontType* pEnFontType);

#ifndef _BLK_SIGN_1G_HASHSUPPORTS_DEFINED
#define _BLK_SIGN_1G_HASHSUPPORTS_DEFINED
typedef struct BlkSign1GHashSupportsTag
{
	ESBOOL	m_bSupportMd5;
	ESBOOL	m_bSupportSha1;
	ESBOOL	m_bSupportSha256;
	ESBOOL	m_bSupportSha384;
	ESBOOL	m_bSupportSha512;
	ESBOOL	m_bSupportSm3;
	ESBOOL	m_bSupportSha224;
	ESBOOL	m_bSupportSha512_224;

	ESBOOL	m_bSupportSha512_256;

	ESBOOL  __[7];
}BlkSign1GHashSupports;
#endif // _BLK_SIGN_1G_HASHSUPPORTS_DEFINED
#ifndef _BLK_CFCA_PRE_PLANT_FEATURES_DEFINED
#define _BLK_CFCA_PRE_PLANT_FEATURES_DEFINED
typedef struct BlkCfcarePlantCosVersionTag
{
	u1		m_u1MajorVesion;
	u1		m_u1MinorVesion;
}BlkCfcarePlantCosVersion;

typedef struct BlkCfcaPrePlantFeaturesTag
{
	u4 m_u4BankId;
	u1 m_u1Rsa1024CertFlag;
	u1 m_u1Rsa2048CertFlag;
	u1 m_u1Sm2CertFlag;
	u1 m_u1CertType; // 0: 签名密钥对，其他：交换密钥对
	BlkCfcarePlantCosVersion m_blkCfcarePlantCosVersion; // CFCA预植COS版本
}BlkCfcaPrePlantFeatures;
#endif // _BLK_CFCA_PRE_PLANT_FEATURES_DEFINED

typedef struct BlkCosFeatures
{
	u4						m_u4Version;
	BlkSign1GHashSupports	m_blkSign1GRsa1024HashSupports;
	BlkSign1GHashSupports	m_blkSign1GRsa2048HashSupports;
	BlkSign1GHashSupports	m_blkSign1GSm2HashSupports;
	BlkCfcaPrePlantFeatures	m_blkCfcaPrePlantFeatures;
	// m_u4Version=0x01时，以下字段才有效
	// 保留字段，修改其他字段请相应地修改保留字段
	// 总大小扩大了，原来总大小为256字节，但是已经用了192字节，所以趁该结构体尚未进入到实际项目，加大到512字节
	u1						__[512-4-sizeof(BlkSign1GHashSupports)*3-sizeof(BlkCfcaPrePlantFeatures)];
}BlkCosFeatures;
typedef u4 (CALL_TYPE *FunSlotGetCosFeatures)(IN u4 u4SlotId, OUT BlkCosFeatures* pblkCosFeatures);

typedef struct BlkDevSignParamTag
{
	u4		m_u4DevCertIndex;		// 设备证书索引
	u4		m_u4HashAlgId;			// 用户私钥签名时使用的哈希算法
	u4		m_u4DevHashAlgId;		// 设备私钥签名时使用的哈希算法
	u4		m_pu4Rfu[0x05];			// 保留
	u1*		m_pu1P10Info;
	u4		m_u4P10InfoLen;
	u1*		m_pu1HashAlgSequence;	// DER编码后的哈希算法标识
	u4		m_u4HashAlgSequenceLen;
	u4		m_u4SignatureLen;		// 输出: 用户私钥签名值长度
	u4		m_u4DevSignatureLen;	// 输出: 设备私钥签名值长度
	u1		m_pu1Signature[256];	// 输出: 用户私钥签名值
	u1		m_pu1DevSignature[256];	// 输出: 设备私钥签名值
	u1		m_pu1DevCert[0x800];	// 输出: 设备证书
	u4		m_u4DevCertLen;			// 输出: 设备证书长度
}BlkDevSignParam;

typedef u4 (CALL_TYPE* FunSlotCntGetDevSignature)(IN u4 u4CntId, IN u4 u4KeySpec, INOUT BlkDevSignParam* pblkDevSignParam);
// pkcs11
#define SLOT_CNT_OBJ_CERT		1
#define SLOT_CNT_OBJ_PUBKEY		2
#define SLOT_CNT_OBJ_PRIKEY		3
typedef u4 (CALL_TYPE *FunSlotObjectList)(IN u4 u4SlotId, IN ESBOOL bPrivate, OUT u4* pu4ObjectIdList, INOUT u4* pu4ObjectNum);
typedef u4 (CALL_TYPE *FunSlotObjectRead)(IN u4 u4SlotId, IN u4 u4ObjectId, OUT u1* pu1ObjectAttr, INOUT u4* pu4ObjectAttrLen);
typedef u4 (CALL_TYPE *FunSlotObjectWrite)(IN u4 u4SlotId, IN u4 u4ObjectId, IN const u1* pu1ObjectAttr, IN u4 u4ObjectAttrLen);
typedef u4 (CALL_TYPE *FunSlotObjectCreate)(IN u4 u4SlotId, IN u4 u4ObjectType, IN u4 u4ObjectAttrLen, OUT u4* pu4ObjectId);
typedef u4 (CALL_TYPE *FunSlotObjectDelete)(IN u4 u4SlotId, IN u4 u4ObjectId);
typedef u4 (CALL_TYPE *FunSlotObjectGetKeyPairId)(IN u4 u4CntId, IN u4 u4KeySpec,OUT u4* pu4ObjectIdPubKey, OUT u4* pu4ObjectIdPriKey, OUT u4* pu4ObjectIdCert);

// 总共256字节
#pragma pack(push,1)
typedef struct BlkSlotParamTag
{
	u4 m_u4Ver; // 从0x00开始
	// 0x00;
	u4 m_u4OpenWebPageFlag; // 打开网银页面标记
	u4 m_u4VirtualDestopFlag; // 虚拟桌面标记

	u1 m_u1Reserved[256-12];

}BlkSlotParam;
#pragma pack(pop)

typedef u4 (CALL_TYPE *FunSlotSetParam)(IN u4 u4SlotId, IN const BlkSlotParam* blkSlotParam);
typedef u4 (CALL_TYPE *FunSlotGetParam)(IN u4 u4SlotId, OUT BlkSlotParam* blkSlotParam);

#pragma pack(push,1)
typedef struct BlkSlotFunTag
{
	u4							m_u4Size;			// 整个结构的大小，包括自身
	u4							m_u4Version;		// 版本号，目前为 SLOTAPI_VERSION

	FunSlotLibInit				m_funSlotLibInit;
	FunSlotLibFinal				m_funSlotLibFinal;

	FunSlotList					m_funSlotList;
	FunSlotLock					m_funSlotLock;
	FunSlotUnlock				m_funSlotUnlock;
	FunSlotInitToken			m_funSlotInitToken;
	FunSlotGetInfo				m_funSlotGetInfo;
	FunSlotGetTokenInfo			m_funSlotGetTokenInfo;

	FunSlotGenRand				m_funSlotGenRand;
	FunSlotGetProtectKeyInfo	m_funSlotGetProtectKeyInfo;
	FunSlotUpdateProtectKey		m_funSlotUpdateProtectKey;
	FunSlotChangeLabel			m_funSlotChangeLabel;

	// Charset & LangId
	FunSlotGetCharSetList		m_funSlotGetCharSetList;
	FunSlotGetCharSet			m_funSlotGetCharSet;
	FunSlotSetCharSet			m_funSlotSetCharSet;
	FunSlotGetLangIdList		m_funSlotGetLangIdList;
	FunSlotGetLangId			m_funSlotGetLangId;
	FunSlotSetLangId			m_funSlotSetLangId;

	// event
	FunSlotRegDevEventCallback	m_funSlotRegDevEventCallback;

	FunSlotCntFind				m_funSlotCntFind;
	FunSlotCntCreate			m_funSlotCntCreate;
	FunSlotCntDelete			m_funSlotCntDelete;
	FunSlotCntList				m_funSlotCntList;

	FunSlotCntGenKey			m_funSlotCntGenKey;
	FunSlotCntWriteCert			m_funSlotCntWriteCert;
	FunSlotCntReadCert			m_funSlotCntReadCert;
	FunSlotCntGetInfo			m_funSlotCntGetInfo;
	FunSlotCntReadPubKey		m_funSlotCntReadPubKey;
	FunSlotCntReadEncPubKey		m_funSlotCntReadEncryptedPubKey;
	FunSlotCntWritePubKey		m_funSlotCntWritePubKey;
	FunSlotCntWritePriKey		m_funSlotCntWritePriKey;

	FunSlotCntEnc				m_funSlotCntEnc;
	FunSlotCntDec				m_funSlotCntDec;
	FunSlotCntSignHash			m_funSlotCntSignHash;
	FunSlotVerifySignHash		m_funSlotVerifySignHash;

	FunSlotVerifyPin			m_funSlotVerifyPin;
	FunSlotChangePin			m_funSlotChangePin;
	FunSlotCachePinSet          m_funSlotCachePinSet;
	FunSlotCachePinVerify       m_funSlotCachePinVerify;
	FunSlotHashInit				m_funSlotHashInit;
	FunSlotHashData				m_funSlotHashData;
	FunSlotHashGetValue			m_funSlotHashGetValue;
	FunSlotHashSetValue			m_funSlotHashSetValue;
	FunSlotHashGetDataType		m_funSlotHashGetDataType;
	FunSlotHashRelease			m_funSlotHashRelease;

	FunSlotFileCreate			m_funSlotFileCreate;
	FunSlotFileDelete			m_funSlotFileDelete;
	FunSlotFileFind				m_funSlotFileFind;
	FunSlotFileGetAttr			m_funSlotFileGetAttr;
	FunSlotFileRead				m_funSlotFileRead;
	FunSlotFileWrite			m_funSlotFileWrite;

	// ui
	FunSlotUiGetPin				m_funSlotUiGetPin;
	FunSlotUiVerifyPin			m_funSlotUiVerifyPin;
	FunSlotUiChangePin			m_funSlotUiChangePin;
	FunSlotUiChangeLabel		m_funSlotUiChangeLabel;
	FunSlotUiPrompt				m_funSlotUiPrompt;
	FunSlotUiSelToken			m_funSlotUiSelToken;
	FunSlotUiSetLang			m_funSlotUiSetLang;

	// YuZhi-cfca
	FunSlotGetCfcaId			m_funSlotGetCfcaId;
	FunSlotGetChipSn			m_funSlotGetChipSn;
	FunSlotGenTempAsymKey		m_funSlotGenTempAsymKey;
	FunSlotCntEnvImportAsymKey	m_funSlotCntEnvImportAsymKey;


	FunSlotObjectRead			m_funSlotObjectRead;
	FunSlotObjectWrite			m_funSlotObjectWrite;

	FunSlotSetWarningMsg		m_funSlotSetWarningMsg; // 设置警告信息

	// 版本V2才支持的函数接口
	FunSlotGetCosFeatures		m_funSlotGetCosFeature;

	FunSlotSymmInit				m_funSlotSymmInit;
	FunSlotSymmUpdate			m_funSlotSymmUpdate;
	FunSlotSymmFinal			m_funSlotSymmFinal;

	FunSlotFileCreateViaName	m_funSlotFileCreateViaName;
	FunSlotFileEnum				m_funSlotFileEnum;
	FunSlotFileGetName			m_funSlotFileGetName;
	FunSlotObjectList			m_funSlotObjectList;
	FunSlotObjectCreate			m_funSlotObjectCreate;
	FunSlotObjectDelete			m_funSlotObjectDelete;
	FunSlotObjectGetKeyPairId	m_funSlotObjectGetKeyPairId;
	FunSlotUnblockPin			m_funSlotUnblockPin;
	FunSlotUiUnblockPin			m_funSlotUiUnblockPin;
	FunSlotLockTimeout			m_funSlotLockTimeout;
	FunSlotGetMediaId			m_funSlotGetMediaId;
	FunSlotGetPinInfo			m_funSlotGetPinInfo;
	FunSlotCntGetDevSignature	m_funSlotCntGetDevSignature;

	FunSlotSetFontType			m_funSlotSetFontType;
	FunSlotGetFontType			m_funSlotGetFontType;

	FunSlotSetParam				m_funSlotSetParam;
	FunSlotGetParam				m_funSlotGetParam;
	void*						m_pvRfu[0x0D];
}BlkSlotFun;

#pragma pack(pop)
#if defined(__cplusplus)
extern "C"
{
#endif
	// 调用前要设置 m_u4Size 和 m_u4Version 两个成员变量的值，其中 m_u4Version 的值要设置为：SLOTAPI_VERSION
	u4 CALL_TYPE SlotGetFunctionList(INOUT BlkSlotFun* pblkSlotFun);
	void* CALL_TYPE SlotGetFunction(const char* pszFunctionName);

#if defined(__cplusplus)
};
#endif

#endif // _ES_SLOT_API_H_
