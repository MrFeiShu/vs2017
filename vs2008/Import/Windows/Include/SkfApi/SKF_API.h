#ifndef _SKF_API_H
#define _SKF_API_H


#define MAX_IV_LEN						32
#define ECC_MAX_XCOORDINATE_BITS_LEN	512
#define ECC_MAX_YCOORDINATE_BITS_LEN	512
#define ECC_MAX_MODULUS_BITS_LEN		512
#define MAX_RSA_MODULUS_LEN				256
#define MAX_RSA_EXPONENT_LEN			4
// BOOL
#undef TRUE
#undef FALSE
#define TRUE			0x00000001	//布尔值为真
#define FALSE			0x00000000	//布尔值为假

// Call Type
#define DEVAPI __stdcall

// Pin Type
#define ADMIN_TYPE		0			//管理员PIN类型
#define USER_TYPE		1			//用户PIN类型

// block cipher
#define SGD_DES_ECB     0xF1000001  //DES算法ECB加密模式
#define SGD_DES_CBC     0xF1000002  //DES算法CBC加密模式
#define SGD_DES_CFB     0xF1000004  //DES算法CFB加密模式
#define SGD_DES_OFB     0xF1000008  //DES算法OFB加密模式
#define SGD_DES_MAC     0xF1000010  //DES算法MAC加密模式
#define SGD_TDES_ECB    0xF2000001  //TDES算法ECB加密模式
#define SGD_TDES_CBC    0xF2000002  //TDES算法CBC加密模式
#define SGD_TDES_CFB    0xF2000004  //TDES算法CFB加密模式
#define SGD_TDES_OFB    0xF2000008  //TDES算法OFB加密模式
#define SGD_TDES_MAC    0xF2000010  //TDES算法MAC加密模式

#define SGD_3DES_ECB    0x00000001  //3DES算法ECB加密模式
#define SGD_3DES_CBC    0x00000002  //3DES算法CBC加密模式
#define SGD_3DES_CFB    0x00000004  //3DES算法CFB加密模式
#define SGD_3DES_OFB    0x00000008  //3DES算法OFB加密模式
#define SGD_3DES_MAC    0x00000010  //3DES算法MAC加密模式
#define SGD_SM1_ECB		0x00000101	//SM1算法ECB加密模式
#define SGD_SM1_CBC		0x00000102	//SM1算法CBC加密模式
#define SGD_SM1_CFB		0x00000104	//SM1算法CFB加密模式
#define SGD_SM1_OFB		0x00000108	//SM1算法OFB加密模式
#define SGD_SM1_MAC		0x00000110	//SM1算法MAC运算
#define SGD_SSF33_ECB	0x00000201	//SSF33算法ECB加密模式
#define SGD_SSF33_CBC	0x00000202	//SSF33算法CBC加密模式
#define SGD_SSF33_CFB	0x00000204	//SSF33算法CFB加密模式
#define SGD_SSF33_OFB	0x00000208	//SSF33算法OFB加密模式
#define SGD_SSF33_MAC	0x00000210	//SSF33算法MAC运算
#define SGD_SMS4_ECB	0x00000401	//SMS4算法ECB加密模式
#define SGD_SMS4_CBC	0x00000402	//SMS4算法CBC加密模式
#define SGD_SMS4_CFB	0x00000404	//SMS4算法CFB加密模式
#define SGD_SMS4_OFB	0x00000408	//SMS4算法OFB加密模式
#define SGD_SMS4_MAC	0x00000410	//SMS4算法MAC运算
// public key cipher
#define SGD_RSA			0x00010000	//RSA算法
#define SGD_SM2_1		0x00020100	//椭圆曲线签名算法
#define SGD_SM2_2		0x00020200	//椭圆曲线密钥交换协议
#define SGD_SM2_3		0x00020400	//椭圆曲线加密算法
// hash
#define SGD_SM3			0x00000001	//SM3杂凑算法
#define SGD_SHA1		0x00000002	//SHA1杂凑算法
#define SGD_SHA256		0x00000004	//SHA256杂凑算法
//////////////////////////// 20111101 -by lj /////////////////////////////////////////
// 0x00000010～0x000000FF  为其它密码杂凑算法预留
#define SGD_SHA384		0x00000010	//SHA384杂凑算法
#define SGD_SHA512		0x00000020	//SHA512杂凑算法
//////////////////////////// 20111101 -by lj /////////////////////////////////////////
// device state 
#define DEV_ABSENT_STATE			0x00000000
#define DEV_PRESENT_STATE			0x00000001
#define DEV_UNKNOW_STATE			0x00000002
// file security
#define SECURE_NEVER_ACCOUNT		0x00000000	//不允许
#define SECURE_ADM_ACCOUNT			0x00000001	//管理员权限
#define SECURE_USER_ACCOUNT			0x00000010	//用户权限
#define SECURE_ANYONE_ACCOUNT		0x000000FF	//任何人

#define MAX_APPNAME_LEN					0x20
#define MAX_FILENAME_LEN				0x20
#define MAX_CNTNAME_LEN					0x40

// base type
typedef signed char		INT8;	//有符号8位整数	
typedef short			INT16;	//有符号16位整数	
typedef int				INT32;	//有符号32位整数	
typedef unsigned char	UINT8;	//无符号8位整数	
typedef unsigned short	UINT16;	//无符号16位整数	
typedef unsigned int	UINT32;	//无符号32位整数	
typedef int				BOOL;	//布尔类型，取值为TRUE或FALSE	
typedef UINT8			BYTE;
typedef char			CHAR;
typedef INT16			SHORT;
typedef UINT16			USHORT;
typedef long			LONG;
typedef unsigned long	ULONG;
typedef UINT32			UINT;
typedef UINT16			WORD;
typedef unsigned long	DWORD;
typedef UINT32			FLAGS;
typedef CHAR *			LPSTR;
typedef void *			HANDLE;
typedef HANDLE			DEVHANDLE;
typedef HANDLE			HAPPLICATION;
typedef HANDLE			HCONTAINER;

//#pragma pack(push, 1)
// structure
typedef struct Struct_Version{
	BYTE major;
	BYTE minor;
}VERSION;

typedef struct Struct_DEVINFO{
	VERSION		Version;				//1.0
	CHAR		Manufacturer[64];		//设备厂商信息
	CHAR		Issuer[64];				//发行厂商信息
	CHAR		Label[32];				//设备标签
	CHAR		SerialNumber[32];		//序列号
	VERSION		HWVersion;				//设备硬件版本
	VERSION		FirmwareVersion;		//设备本身固件版本
	ULONG		AlgSymCap;				//分组密码算法标识
	ULONG		AlgAsymCap;				//非对称密码算法标识
	ULONG		AlgHashCap;				//密码杂凑算法标识
	ULONG		DevAuthAlgId;			//设备认证使用的分组密码算法标识
	ULONG		TotalSpace;				//设备总空间大小
	ULONG		FreeSpace;				//用户可用空间大小
	ULONG		MaxECCBufferSize;		//能够处理的ECC加密数据大小
	ULONG		MaxBufferSize;			//能够处理的分组运算和杂凑运算的数据大小
	BYTE		Reserved[64];			//保留扩展
}DEVINFO,*PDEVINFO;

// typedef struct BlkDevInfoTag{
// 	BlkVersion		m_blkStructVersion;			// 结构版本
// 	BlkVersion		m_blkSpecificationVersion;	// 特殊版本
// 	u1				m_pu1Manufacturer[64];		// 设备厂商信息
// 	u1				m_pu1Issuer[64];			// 发行厂商信息
// 	u1				m_pu1Label[32];				// 设备标签
// 	u1				m_pu1SerialNumber[32];		// 序列号
// 	BlkVersion		m_blkHWVersion;				// 设备硬件版本
// 	BlkVersion		m_blkFirmwareVersion;		// 设备本身固件版本
// 	u4				m_u4AlgSymCap;				// 分组密码算法标识
// 	u4				m_u4AlgAsymCap;				// 非对称密码算法标识
// 	u4				m_u4AlgHashCap;				// 密码杂凑算法标识
// 	u4				m_u4DevAuthAlgId;			// 设备认证使用的分组密码算法标识
// 	u4				m_u4TotalSpace;				// 设备总空间大小
// 	u4				m_u4FreeSpace;				// 用户可用空间大小
// 	u2				m_u2ApduDataLen;
// 	u2				m_u2UserAuthMethod;
// 	u2				m_u2DeviceType;
// 	u1				m_u1MaxContainerNum;
// 	u1				m_u1MaxCertNum;
// 	u2				m_u2MaxFileNum;
// 	u1  			m_pu1Reserved[54];			// 保留扩展
// }BlkDevInfo;

// 公私钥有效数据放在后面
typedef struct Struct_RSAPUBLICKEYBLOB{
	ULONG	AlgID;
	ULONG	BitLen;
	BYTE	Modulus[MAX_RSA_MODULUS_LEN];
	BYTE	PublicExponent[MAX_RSA_EXPONENT_LEN];
}RSAPUBLICKEYBLOB, *PRSAPUBLICKEYBLOB;

typedef struct Struct_RSAPRIVATEKEYBLOB{
	ULONG	AlgID;
	ULONG	BitLen;
	BYTE	Modulus[MAX_RSA_MODULUS_LEN];
	BYTE	PublicExponent[MAX_RSA_EXPONENT_LEN];
	BYTE	PrivateExponent[MAX_RSA_MODULUS_LEN];
	BYTE	Prime1[MAX_RSA_MODULUS_LEN/2];
	BYTE	Prime2[MAX_RSA_MODULUS_LEN/2];
	BYTE	Prime1Exponent[MAX_RSA_MODULUS_LEN/2];
	BYTE	Prime2Exponent[MAX_RSA_MODULUS_LEN/2];
	BYTE	Coefficient[MAX_RSA_MODULUS_LEN/2];
}RSAPRIVATEKEYBLOB, *PRSAPRIVATEKEYBLOB;

typedef struct Struct_ECCCIPHERBLOB{
	BYTE  XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8]; //SM2加密算法输出密文中C1的X坐标值，其位长度与设备中签名公钥的位长度相等
	BYTE  YCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8]; //SM2加密算法输出密文中C1的Y坐标值，其位长度与设备中签名公钥的位长度相等
	BYTE  HASH[32]; //SM2加密算法输出密文中的参数C3
	ULONG CipherLen; //SM2加密算法输出密文中参数C2的长度
	BYTE  Cipher[0x01]; //SM2加密算法输出密文中参数C2的值
} ECCCIPHERBLOB, *PECCCIPHERBLOB;

typedef struct Struct_ECCPUBLICKEYBLOB{
	ULONG	BitLen;											//模数的实际位长度,必须是8的倍数
	BYTE	XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];	//曲线上点的X座标,有限域上的整数 #define ECC_MAX_XCOORDINATE_BITS_LEN 512	
	BYTE	YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];	//曲线上点的X座标,有限域上的整数 #define ECC_MAX_XCOORDINATE_BITS_LEN 512
}ECCPUBLICKEYBLOB, *PECCPUBLICKEYBLOB;

typedef struct Struct_ECCPRIVATEKEYBLOB{
	ULONG	BitLen;									//模数的实际位长度,必须是8的倍数
	BYTE	PrivateKey[ECC_MAX_MODULUS_BITS_LEN/8];	//有限域上的整数 #define ECC_MAX_MODULUS_BITS_LEN 512
}ECCPRIVATEKEYBLOB, *PECCPRIVATEKEYBLOB;

typedef struct SKF_ENVELOPEDKEYBLOB{
	ULONG				Version;					// 当前版本为 1
	ULONG				ulSymmAlgID;				// 用于加密待导入ECC密钥对的对称算法标识，限定为采用ECB模式对密钥对数据进行加密
	ULONG				ulBits;						// 待导入加密密钥对的密钥位长度
	BYTE				pbEncryptedPriKey[64];		// 待导入加密密钥对私钥的密文
	ECCPUBLICKEYBLOB	PubKey;						// 待导入加密密钥对的公钥
	ECCCIPHERBLOB		ECCCipherBlob;				// 用保护公钥加密的对称密钥密文。
}ENVELOPEDKEYBLOB, *PENVELOPEDKEYBLOB;

typedef struct Struct_BLOCKCIPHERPARAM{
	BYTE	IV[MAX_IV_LEN];	//初始向量，MAX_IV_LEN为初始化向量的最大长度#define MAX_IV_LEN 32
	ULONG	IVLen;			//初始向量实际长度（按字节计算）
	ULONG	PaddingType;	//填充方式，0表示不填充，1表示按照PKCS#5方式进行填充
	ULONG	FeedBitLen;		//反馈值的位长度（按位计算）
} BLOCKCIPHERPARAM, *PBLOCKCIPHERPARAM;

typedef struct Struct_FILEATTRIBUTE{
	CHAR	FileName[MAX_FILENAME_LEN];	//文件名,ASCIIZ字符串，最大长度为32；
	ULONG	FileSize;		//文件大小
	ULONG	ReadRights;		//读取文件需要的权限
	ULONG	WriteRights;	//写入文件需要的权限
} FILEATTRIBUTE, *PFILEATTRIBUTE;

typedef struct Struct_ECCSIGNATUREBLOB{
	BYTE r[ECC_MAX_XCOORDINATE_BITS_LEN/8];
	BYTE s[ECC_MAX_XCOORDINATE_BITS_LEN/8];
} ECCSIGNATUREBLOB, *PECCSIGNATUREBLOB;

//#pragma pack(pop)

#define DEVAPI __stdcall

#ifdef __cplusplus
extern "C"{
#endif
//-------------------------
//7.1	设备管理
//-------------------------

ULONG DEVAPI SKF_WaitForDevEvent(LPSTR szDevName,ULONG *pulDevNameLen, ULONG *pulEvent);
ULONG DEVAPI SKF_CancelWaitForDevEvent(void);
ULONG DEVAPI SKF_EnumDev(BOOL bPresent, LPSTR szNameList, ULONG *pulSize);
ULONG DEVAPI SKF_ConnectDev (LPSTR szName, DEVHANDLE *phDev);
ULONG DEVAPI SKF_DisConnectDev (DEVHANDLE hDev);
ULONG DEVAPI SKF_GetDevState(LPSTR szDevName, ULONG *pulDevState);
ULONG DEVAPI SKF_SetLabel (DEVHANDLE hDev, LPSTR szLabel);
ULONG DEVAPI SKF_GetDevInfo (DEVHANDLE hDev, DEVINFO *pDevInfo);
ULONG DEVAPI SKF_LockDev (DEVHANDLE hDev, ULONG ulTimeOut);
ULONG DEVAPI SKF_UnlockDev (DEVHANDLE hDev);
ULONG DEVAPI SKF_Transmit(DEVHANDLE hDev, BYTE* pbCommand, ULONG ulCommandLen,BYTE* pbData, ULONG* pulDataLen);
//-------------------------
//7.2	访问控制
//-------------------------
ULONG DEVAPI SKF_ChangeDevAuthKey (DEVHANDLE hDev, BYTE *pbKeyValue, ULONG ulKeyLen);
ULONG DEVAPI SKF_DevAuth (DEVHANDLE hDev, BYTE *pbAuthData, ULONG ulLen);
ULONG DEVAPI SKF_ChangePIN (HAPPLICATION hApplication, ULONG ulPINType, LPSTR szOldPin, LPSTR szNewPin, ULONG *pulRetryCount);
ULONG DEVAPI SKF_GetPINInfo(HAPPLICATION hApplication, ULONG  ulPINType, ULONG *pulMaxRetryCount, ULONG *pulRemainRetryCount, BOOL *pbDefaultPin);
ULONG DEVAPI SKF_VerifyPIN (HAPPLICATION hApplication, ULONG  ulPINType, LPSTR szPIN, ULONG *pulRetryCount);
ULONG DEVAPI SKF_UnblockPIN (HAPPLICATION hApplication, LPSTR szAdminPIN, LPSTR szNewUserPIN,  ULONG *pulRetryCount);
ULONG DEVAPI SKF_ClearSecureState (HAPPLICATION hApplication);
ULONG DEVAPI SKF_Ex_ChangeDevAuthKey(DEVHANDLE hDev, BYTE *pbOldDevKey, ULONG ulOldDevLen, BYTE* pbNewDevKey, ULONG ulNewDevLen);
//-------------------------
//7.3	应用管理
//-------------------------
ULONG DEVAPI SKF_CreateApplication(DEVHANDLE hDev, LPSTR szAppName, LPSTR szAdminPin, DWORD dwAdminPinRetryCount,LPSTR szUserPin, DWORD dwUserPinRetryCount,DWORD dwCreateFileRights, HAPPLICATION *phApplication); 
ULONG DEVAPI SKF_EnumApplication(DEVHANDLE hDev, LPSTR szAppName,ULONG *pulSize);
ULONG DEVAPI SKF_DeleteApplication(DEVHANDLE hDev, LPSTR szAppName);
ULONG DEVAPI SKF_OpenApplication(DEVHANDLE hDev, LPSTR szAppName, HAPPLICATION *phApplication);
ULONG DEVAPI SKF_CloseApplication(HAPPLICATION hApplication);
//-------------------------
//7.4	文件管理
//-------------------------
ULONG DEVAPI SKF_CreateFile(HAPPLICATION hApplication, LPSTR szFileName, ULONG ulFileSize, ULONG ulReadRights, ULONG ulWriteRights);
ULONG DEVAPI SKF_DeleteFile(HAPPLICATION hApplication, LPSTR szFileName);
ULONG DEVAPI SKF_EnumFiles(HAPPLICATION hApplication, LPSTR szFileList, ULONG *pulSize);
ULONG DEVAPI SKF_GetFileInfo(HAPPLICATION hApplication, LPSTR szFileName, FILEATTRIBUTE *pFileInfo);
ULONG DEVAPI SKF_ReadFile(HAPPLICATION hApplication, LPSTR szFileName, ULONG ulOffset, ULONG ulSize, BYTE * pbOutData, ULONG *pulOutLen);
ULONG DEVAPI SKF_WriteFile(HAPPLICATION hApplication, LPSTR szFileName, ULONG  ulOffset, BYTE *pbData, ULONG ulSize);
//-------------------------
//7.5	容器管理函数
//-------------------------
ULONG DEVAPI SKF_CreateContainer(HAPPLICATION hApplication, LPSTR szContainerName, HCONTAINER *phContainer);
ULONG DEVAPI SKF_DeleteContainer(HAPPLICATION hApplication, LPSTR szContainerName);
ULONG DEVAPI SKF_OpenContainer(HAPPLICATION hApplication, LPSTR szContainerName, HCONTAINER *phContainer);
ULONG DEVAPI SKF_CloseContainer(HCONTAINER hContainer);
ULONG DEVAPI SKF_EnumContainer(HAPPLICATION hApplication, LPSTR szContainerName,ULONG *pulSize);
ULONG DEVAPI SKF_GetContainerType(HCONTAINER hContainer, ULONG* pulContainerType);
ULONG DEVAPI SKF_ImportCertificate(HCONTAINER hContainer, BOOL bSignFlag, BYTE* pbCert, ULONG ulCertLen);
ULONG DEVAPI SKF_ExportCertificate(HCONTAINER hContainer, BOOL bSignFlag, BYTE* pbCert, ULONG* pulCertLen);
//-------------------------
//7.6	密码服务
//-------------------------
// 1
ULONG DEVAPI SKF_GenRandom (DEVHANDLE hDev, BYTE *pbRandom,ULONG ulRandomLen);
// 2
ULONG DEVAPI SKF_GenExtRSAKey (DEVHANDLE hDev, ULONG ulBitsLen, RSAPRIVATEKEYBLOB *pBlob);
ULONG DEVAPI SKF_GenRSAKeyPair (HCONTAINER hContainer, ULONG ulBitsLen, RSAPUBLICKEYBLOB *pBlob);
ULONG DEVAPI SKF_ImportRSAKeyPair (
								HCONTAINER hContainer, ULONG ulSymAlgId, 
								BYTE *pbWrappedKey, ULONG ulWrappedKeyLen,
								BYTE *pbEncryptedData, ULONG ulEncryptedDataLen);

//ULONG DEVAPI SKF_ImportRSAKeyPair (HCONTAINER hContainer, BYTE *pbWrapedData, ULONG ulWrapedLen);
ULONG DEVAPI SKF_RSASignData(HCONTAINER hContainer, BYTE *pbData, ULONG  ulDataLen, BYTE *pbSignature, ULONG *pulSignLen);
ULONG DEVAPI SKF_RSAVerify (DEVHANDLE hDev , RSAPUBLICKEYBLOB* pRSAPubKeyBlob, BYTE *pbData, ULONG  ulDataLen, BYTE *pbSignature, ULONG ulSignLen);
ULONG DEVAPI SKF_RSAExportSessionKey (HCONTAINER hContainer, ULONG ulAlgId, RSAPUBLICKEYBLOB *pPubKey, BYTE *pbData, ULONG  *pulDataLen, HANDLE *phSessionKey);
ULONG DEVAPI SKF_ExtRSAPubKeyOperation (DEVHANDLE hDev, RSAPUBLICKEYBLOB* pRSAPubKeyBlob,BYTE* pbInput, ULONG ulInputLen, BYTE* pbOutput, ULONG* pulOutputLen);
ULONG DEVAPI SKF_ExtRSAPriKeyOperation (DEVHANDLE hDev, RSAPRIVATEKEYBLOB* pRSAPriKeyBlob,BYTE* pbInput, ULONG ulInputLen, BYTE* pbOutput, ULONG* pulOutputLen);
//10
ULONG DEVAPI SKF_GenECCKeyPair (HCONTAINER hContainer, ULONG ulAlgId, ECCPUBLICKEYBLOB *pBlob);
ULONG DEVAPI SKF_ImportECCKeyPair (IN HCONTAINER hContainer, IN PENVELOPEDKEYBLOB pEnvelopedKeyBlob);
//ULONG DEVAPI SKF_ImportECCKeyPair (HCONTAINER hContainer, BYTE *pbWrapedData, ULONG ulWrapedLen);
ULONG DEVAPI SKF_ECCSignData (HCONTAINER hContainer, BYTE *pbData, ULONG  ulDataLen, PECCSIGNATUREBLOB pSignature);
ULONG DEVAPI SKF_ECCVerify (DEVHANDLE hDev , ECCPUBLICKEYBLOB* pECCPubKeyBlob, BYTE *pbData, ULONG  ulDataLen,PECCSIGNATUREBLOB pSignature);
ULONG DEVAPI SKF_ECCExportSessionKey (HCONTAINER hContainer, ULONG ulAlgId, ECCPUBLICKEYBLOB *pPubKey,  PECCCIPHERBLOB pData, HANDLE *phSessionKey);
ULONG DEVAPI SKF_ExtECCEncrypt (DEVHANDLE hDev, ECCPUBLICKEYBLOB*  pECCPubKeyBlob,BYTE* pbPlainText, ULONG ulPlainTextLen, PECCCIPHERBLOB pCipherText);
ULONG DEVAPI SKF_ExtECCDecrypt (DEVHANDLE hDev, ECCPRIVATEKEYBLOB*  pECCPriKeyBlob,  PECCCIPHERBLOB  pCipherText, BYTE* pbPlainText, ULONG* pulPlainTextLen);
ULONG DEVAPI SKF_ExtECCSign (DEVHANDLE hDev, ECCPRIVATEKEYBLOB* pECCPriKeyBlob, BYTE* pbData, ULONG ulDataLen, PECCSIGNATUREBLOB pSignature);
ULONG DEVAPI SKF_ExtECCVerify (DEVHANDLE hDev, ECCPUBLICKEYBLOB*  pECCPubKeyBlob,BYTE* pbData, ULONG ulDataLen, PECCSIGNATUREBLOB pSignature);
ULONG DEVAPI SKF_GenerateAgreementDataWithECC (HCONTAINER hContainer, 
											   ULONG ulAlgId,
											   ECCPUBLICKEYBLOB*  pTempECCPubKeyBlob,
											   BYTE* pbID, 
											   ULONG ulIDLen,
											   HANDLE *phAgreementHandle);
ULONG DEVAPI SKF_GenerateKeyWithECC (HANDLE hAgreementHandle,
									 ECCPUBLICKEYBLOB*  pECCPubKeyBlob,
									 ECCPUBLICKEYBLOB*  pTempECCPubKeyBlob,
									 BYTE* pbID, 
									 ULONG ulIDLen, 
									 HANDLE *phKeyHandle);
ULONG DEVAPI SKF_GenerateAgreementDataAndKeyWithECC(HANDLE hContainer, ULONG ulAlgId,
													ECCPUBLICKEYBLOB*  pSponsorECCPubKeyBlob,
													ECCPUBLICKEYBLOB*  pSponsorTempECCPubKeyBlob,
													ECCPUBLICKEYBLOB*  pTempECCPubKeyBlob,
													BYTE* pbID, ULONG ulIDLen, 
													BYTE *pbSponsorID, ULONG ulSponsorIDLen,
													HANDLE *phKeyHandle);

// 22
ULONG DEVAPI SKF_ExportPublicKey (HCONTAINER hContainer, BOOL bSignFlag, BYTE* pbBlob, ULONG* pulBlobLen);
ULONG DEVAPI SKF_ImportSessionKey (HCONTAINER hContainer, ULONG ulAlgId,BYTE *pbWrapedData,ULONG ulWrapedLen,HANDLE *phKey);
ULONG DEVAPI SKF_SetSymmKey (DEVHANDLE hDev, BYTE* pbKey, ULONG ulAlgID, HANDLE* phKey);
ULONG DEVAPI SKF_EncryptInit (HANDLE hKey, BLOCKCIPHERPARAM EncryptParam);
ULONG DEVAPI SKF_Encrypt(HANDLE hKey, BYTE * pbData, ULONG ulDataLen, BYTE *pbEncryptedData, ULONG *pulEncryptedLen);
ULONG DEVAPI SKF_EncryptUpdate(HANDLE hKey, BYTE * pbData, ULONG ulDataLen, BYTE *pbEncryptedData, ULONG *pulEncryptedLen);
ULONG DEVAPI SKF_EncryptFinal (HANDLE hKey, BYTE *pbEncryptedData, ULONG *ulEncryptedDataLen );
ULONG DEVAPI SKF_DecryptInit (HANDLE hKey, BLOCKCIPHERPARAM DecryptParam);
ULONG DEVAPI SKF_Decrypt(HANDLE hKey, BYTE * pbEncryptedData, ULONG ulEncryptedLen, BYTE * pbData, ULONG * pulDataLen);
ULONG DEVAPI SKF_DecryptUpdate(HANDLE hKey, BYTE * pbEncryptedData, ULONG ulEncryptedLen, BYTE * pbData, ULONG * pulDataLen);
ULONG DEVAPI SKF_DecryptFinal (HANDLE hKey, BYTE *pbPlainText, ULONG *pulPlainTextLen);
ULONG DEVAPI SKF_DigestInit (DEVHANDLE hDev, ULONG ulAlgID, ECCPUBLICKEYBLOB * pPubBlob, BYTE* pbId, ULONG ulIdLen, HANDLE *phHash);
ULONG DEVAPI SKF_Digest (HANDLE hHash, BYTE *pbData, ULONG ulDataLen, BYTE *pbHashData, ULONG *pulHashLen);
ULONG DEVAPI SKF_DigestUpdate (HANDLE hHash, BYTE *pbData, ULONG  ulDataLen);
ULONG DEVAPI SKF_DigestFinal (HANDLE hHash, BYTE *pHashData, ULONG  *pulHashLen);
ULONG DEVAPI SKF_MacInit (HANDLE hKey, BLOCKCIPHERPARAM* pMacParam, HANDLE *phMac);
ULONG DEVAPI SKF_Mac(HANDLE hMac, BYTE* pbData, ULONG ulDataLen, BYTE *pbMacData, ULONG *pulMacLen);
ULONG DEVAPI SKF_MacUpdate(HANDLE hMac, BYTE * pbData, ULONG ulDataLen);
ULONG DEVAPI SKF_MacFinal (HANDLE hMac, BYTE *pbMacData, ULONG *pulMacDataLen);
ULONG DEVAPI SKF_CloseHandle(HANDLE hHandle);//关闭会话密钥、杂凑、消息认证码句柄。

// 扩充接口
ULONG DEVAPI SKF_RSASignHash(HCONTAINER hContainer, BOOL bSign, HANDLE hHash, BYTE* pbSignature, ULONG* pulSignatureLen);
ULONG DEVAPI SKF_ECCSignHash(HCONTAINER hContainer, BOOL bSign, HANDLE hHash, PECCSIGNATUREBLOB pblkEccSignaure);
ULONG DEVAPI SKF_ECCDecrypt(HCONTAINER hContainer, BOOL bSign, const ECCCIPHERBLOB* pCipherText, BYTE *pbData, ULONG *pdwDataLen);
ULONG DEVAPI SKF_RSADecrypt(HCONTAINER hContainer, BOOL bSign, const BYTE *pCipherData, ULONG ulCipherDataLen, BYTE *pbData, ULONG *pulDataLen);

#ifdef __cplusplus
}
#endif

#define SAR_OK							0x00000000	// 成功
#define SAR_FAIL						0x0A000001	// 失败
#define SAR_UNKNOWNERR					0x0A000002	// 异常错误
#define SAR_NOTSUPPORTYETERR			0x0A000003	// 不支持的服务
#define SAR_FILEERR						0x0A000004	// 文件操作错误
#define SAR_INVALIDHANDLEERR			0x0A000005	// 无效的句柄
#define SAR_INVALIDPARAMERR				0x0A000006	// 无效的参数
#define SAR_READFILEERR					0x0A000007	// 读文件错误
#define SAR_WRITEFILEERR				0x0A000008	// 写文件错误
#define SAR_NAMELENERR					0x0A000009	// 名称长度错误
#define SAR_KEYUSAGEERR					0x0A00000A	// 密钥用途错误
#define SAR_MODULUSLENERR				0x0A00000B	// 模的长度错误
#define SAR_NOTINITIALIZEERR			0x0A00000C	// 未初始化
#define SAR_OBJERR						0x0A00000D	// 对象错误
#define SAR_MEMORYERR					0x0A00000E	// 内存错误
#define SAR_TIMEOUTERR					0x0A00000F	// 超时
#define SAR_INDATALENERR				0x0A000010	// 输入数据长度错误
#define SAR_INDATAERR					0x0A000011	// 输入数据错误
#define SAR_GENRANDERR					0x0A000012	// 生成随机数错误
#define SAR_HASHOBJERR					0x0A000013	// HASH对象错
#define SAR_HASHERR						0x0A000014	// HASH运算错误
#define SAR_GENRSAKEYERR				0x0A000015	// 产生RSA密钥错
#define SAR_RSAMODULUSLENERR			0x0A000016	// RSA密钥模长错误
#define SAR_CSPIMPRTPUBKEYERR			0x0A000017	// CSP服务导入公钥错误
#define SAR_RSAENCERR					0x0A000018	// RSA加密错误
#define SAR_RSADECERR					0x0A000019	// RSA解密错误
#define SAR_HASHNOTEQUALERR				0x0A00001A	// HASH值不相等
#define SAR_KEYNOTFOUNTERR				0x0A00001B	// 密钥未发现
#define SAR_CERTNOTFOUNTERR				0x0A00001C	// 证书未发现
#define SAR_NOTEXPORTERR				0x0A00001D	// 对象未导出
#define SAR_DECRYPTPADERR				0x0A00001E	// 解密时做补丁错误
#define SAR_MACLENERR					0x0A00001F	// MAC长度错误
#define SAR_BUFFER_TOO_SMALL			0x0A000020	// 缓冲区不足
#define SAR_KEYINFOTYPEERR				0x0A000021	// 密钥类型错误
#define SAR_NOT_EVENTERR				0x0A000022	// 无事件错误
#define SAR_DEVICE_REMOVED				0x0A000023	// 设备已移除
#define SAR_PIN_INCORRECT				0x0A000024	// PIN不正确
#define SAR_PIN_LOCKED					0x0A000025	// PIN被锁死
#define SAR_PIN_INVALID					0x0A000026	// PIN无效
#define SAR_PIN_LEN_RANGE				0x0A000027	// PIN长度错误
#define SAR_USER_ALREADY_LOGGED_IN		0x0A000028	// 用户已经登录
#define SAR_USER_PIN_NOT_INITIALIZED	0x0A000029	// 没有初始化用户口令
#define SAR_USER_TYPE_INVALID			0x0A00002A	// PIN类型错误
#define SAR_APPLICATION_NAME_INVALID	0x0A00002B	// 应用名称无效
#define SAR_APPLICATION_EXISTS			0x0A00002C	// 应用已经存在
#define SAR_USER_NOT_LOGGED_IN			0x0A00002D	// 用户没有登录
#define SAR_APPLICATION_NOT_EXISTS		0x0A00002E	// 应用不存在
#define SAR_FILE_ALREADY_EXIST			0x0A00002F	// 文件已经存在
#define SAR_NO_ROOM						0x0A000030	// 空间不足
#define SAR_FILE_NOT_EXIST				0x0A000031	// 文件不存在
#define SAR_REACH_MAX_CONTAINER_COUNT   0x0A000032	// 已达到最大可管理容器数
// added vendor
#define SAR_CONTAINER_EXISTS			0x0A100001	// 
#define SAR_NOTEXIST					0x0A100002	// 
#define SAR_IVLENERR					0x0A100003	// 
#define SAR_BAD_LEN						0x0A100004	//
#define SAR_RETRY_COUNT_OUT				0x0a100005	// 重复次数已到
#define SAR_RETRY_COUNT_ERR				0x0a100006	// 重复次数异常
#define SAR_FILENAME_LEN_ERR			0x0a100007	// 文件名长度出错
#define SAR_CONTAINER_NAME_INVALID		0x0a100008	// 容器名称无效

#define SAR_DRIVER_UNFOUND				0x0A100009	// 驱动没有找到
#define SAR_DEV_UNSUPPORT				0x0A10000A	// 设备不支持
#define SAR_TOO_MORE_DEVICE				0x0A10000B	// 设备太多
#define SAR_STRUCTVER_UNSUPPORT			0x0A10000C	// 不支持的结构
#define SAR_DEV_NAME					0x0A10000D	// 设备名称错误
#define SAR_ASYMSIGNERR					0x0A10000F	// 非对称算法签名错误
#define SAR_ASYMVERIFYERR				0x0A100010	// 非对称算法验签错误
#define SAR_OBJECT_UNFOUND				0x0A100011	// 对象未找到
#define SAR_CONTAINER_UNFOUND			0x0A100012	// 容器不存在
#define SAR_CONTAINER_EXIST				0x0A100013	// 容器已经存在
#define SAR_CERT_SIZE					0x0A100014	// 证书长度错误
#define SAR_NEED_PADDING				0x0A100015	// 算法需要补足
#define SAR_ACCESS_DENIED				0x0A100016	// 拒绝访问
#define SAR_DEV_DISCONNECT				0x0A100017	// 设备没有连接
#define SAR_UNHANDLED_EXCEPTION			0x0A100018	// 出现可导致程序崩溃的异常，且已经捕获

#endif