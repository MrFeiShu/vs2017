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
#define TRUE			0x00000001	//����ֵΪ��
#define FALSE			0x00000000	//����ֵΪ��

// Call Type
#define DEVAPI __stdcall

// Pin Type
#define ADMIN_TYPE		0			//����ԱPIN����
#define USER_TYPE		1			//�û�PIN����

// block cipher
#define SGD_DES_ECB     0xF1000001  //DES�㷨ECB����ģʽ
#define SGD_DES_CBC     0xF1000002  //DES�㷨CBC����ģʽ
#define SGD_DES_CFB     0xF1000004  //DES�㷨CFB����ģʽ
#define SGD_DES_OFB     0xF1000008  //DES�㷨OFB����ģʽ
#define SGD_DES_MAC     0xF1000010  //DES�㷨MAC����ģʽ
#define SGD_TDES_ECB    0xF2000001  //TDES�㷨ECB����ģʽ
#define SGD_TDES_CBC    0xF2000002  //TDES�㷨CBC����ģʽ
#define SGD_TDES_CFB    0xF2000004  //TDES�㷨CFB����ģʽ
#define SGD_TDES_OFB    0xF2000008  //TDES�㷨OFB����ģʽ
#define SGD_TDES_MAC    0xF2000010  //TDES�㷨MAC����ģʽ

#define SGD_3DES_ECB    0x00000001  //3DES�㷨ECB����ģʽ
#define SGD_3DES_CBC    0x00000002  //3DES�㷨CBC����ģʽ
#define SGD_3DES_CFB    0x00000004  //3DES�㷨CFB����ģʽ
#define SGD_3DES_OFB    0x00000008  //3DES�㷨OFB����ģʽ
#define SGD_3DES_MAC    0x00000010  //3DES�㷨MAC����ģʽ
#define SGD_SM1_ECB		0x00000101	//SM1�㷨ECB����ģʽ
#define SGD_SM1_CBC		0x00000102	//SM1�㷨CBC����ģʽ
#define SGD_SM1_CFB		0x00000104	//SM1�㷨CFB����ģʽ
#define SGD_SM1_OFB		0x00000108	//SM1�㷨OFB����ģʽ
#define SGD_SM1_MAC		0x00000110	//SM1�㷨MAC����
#define SGD_SSF33_ECB	0x00000201	//SSF33�㷨ECB����ģʽ
#define SGD_SSF33_CBC	0x00000202	//SSF33�㷨CBC����ģʽ
#define SGD_SSF33_CFB	0x00000204	//SSF33�㷨CFB����ģʽ
#define SGD_SSF33_OFB	0x00000208	//SSF33�㷨OFB����ģʽ
#define SGD_SSF33_MAC	0x00000210	//SSF33�㷨MAC����
#define SGD_SMS4_ECB	0x00000401	//SMS4�㷨ECB����ģʽ
#define SGD_SMS4_CBC	0x00000402	//SMS4�㷨CBC����ģʽ
#define SGD_SMS4_CFB	0x00000404	//SMS4�㷨CFB����ģʽ
#define SGD_SMS4_OFB	0x00000408	//SMS4�㷨OFB����ģʽ
#define SGD_SMS4_MAC	0x00000410	//SMS4�㷨MAC����
// public key cipher
#define SGD_RSA			0x00010000	//RSA�㷨
#define SGD_SM2_1		0x00020100	//��Բ����ǩ���㷨
#define SGD_SM2_2		0x00020200	//��Բ������Կ����Э��
#define SGD_SM2_3		0x00020400	//��Բ���߼����㷨
// hash
#define SGD_SM3			0x00000001	//SM3�Ӵ��㷨
#define SGD_SHA1		0x00000002	//SHA1�Ӵ��㷨
#define SGD_SHA256		0x00000004	//SHA256�Ӵ��㷨
//////////////////////////// 20111101 -by lj /////////////////////////////////////////
// 0x00000010��0x000000FF  Ϊ���������Ӵ��㷨Ԥ��
#define SGD_SHA384		0x00000010	//SHA384�Ӵ��㷨
#define SGD_SHA512		0x00000020	//SHA512�Ӵ��㷨
//////////////////////////// 20111101 -by lj /////////////////////////////////////////
// device state 
#define DEV_ABSENT_STATE			0x00000000
#define DEV_PRESENT_STATE			0x00000001
#define DEV_UNKNOW_STATE			0x00000002
// file security
#define SECURE_NEVER_ACCOUNT		0x00000000	//������
#define SECURE_ADM_ACCOUNT			0x00000001	//����ԱȨ��
#define SECURE_USER_ACCOUNT			0x00000010	//�û�Ȩ��
#define SECURE_ANYONE_ACCOUNT		0x000000FF	//�κ���

#define MAX_APPNAME_LEN					0x20
#define MAX_FILENAME_LEN				0x20
#define MAX_CNTNAME_LEN					0x40

// base type
typedef signed char		INT8;	//�з���8λ����	
typedef short			INT16;	//�з���16λ����	
typedef int				INT32;	//�з���32λ����	
typedef unsigned char	UINT8;	//�޷���8λ����	
typedef unsigned short	UINT16;	//�޷���16λ����	
typedef unsigned int	UINT32;	//�޷���32λ����	
typedef int				BOOL;	//�������ͣ�ȡֵΪTRUE��FALSE	
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
	CHAR		Manufacturer[64];		//�豸������Ϣ
	CHAR		Issuer[64];				//���г�����Ϣ
	CHAR		Label[32];				//�豸��ǩ
	CHAR		SerialNumber[32];		//���к�
	VERSION		HWVersion;				//�豸Ӳ���汾
	VERSION		FirmwareVersion;		//�豸����̼��汾
	ULONG		AlgSymCap;				//���������㷨��ʶ
	ULONG		AlgAsymCap;				//�ǶԳ������㷨��ʶ
	ULONG		AlgHashCap;				//�����Ӵ��㷨��ʶ
	ULONG		DevAuthAlgId;			//�豸��֤ʹ�õķ��������㷨��ʶ
	ULONG		TotalSpace;				//�豸�ܿռ��С
	ULONG		FreeSpace;				//�û����ÿռ��С
	ULONG		MaxECCBufferSize;		//�ܹ������ECC�������ݴ�С
	ULONG		MaxBufferSize;			//�ܹ�����ķ���������Ӵ���������ݴ�С
	BYTE		Reserved[64];			//������չ
}DEVINFO,*PDEVINFO;

// typedef struct BlkDevInfoTag{
// 	BlkVersion		m_blkStructVersion;			// �ṹ�汾
// 	BlkVersion		m_blkSpecificationVersion;	// ����汾
// 	u1				m_pu1Manufacturer[64];		// �豸������Ϣ
// 	u1				m_pu1Issuer[64];			// ���г�����Ϣ
// 	u1				m_pu1Label[32];				// �豸��ǩ
// 	u1				m_pu1SerialNumber[32];		// ���к�
// 	BlkVersion		m_blkHWVersion;				// �豸Ӳ���汾
// 	BlkVersion		m_blkFirmwareVersion;		// �豸����̼��汾
// 	u4				m_u4AlgSymCap;				// ���������㷨��ʶ
// 	u4				m_u4AlgAsymCap;				// �ǶԳ������㷨��ʶ
// 	u4				m_u4AlgHashCap;				// �����Ӵ��㷨��ʶ
// 	u4				m_u4DevAuthAlgId;			// �豸��֤ʹ�õķ��������㷨��ʶ
// 	u4				m_u4TotalSpace;				// �豸�ܿռ��С
// 	u4				m_u4FreeSpace;				// �û����ÿռ��С
// 	u2				m_u2ApduDataLen;
// 	u2				m_u2UserAuthMethod;
// 	u2				m_u2DeviceType;
// 	u1				m_u1MaxContainerNum;
// 	u1				m_u1MaxCertNum;
// 	u2				m_u2MaxFileNum;
// 	u1  			m_pu1Reserved[54];			// ������չ
// }BlkDevInfo;

// ��˽Կ��Ч���ݷ��ں���
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
	BYTE  XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8]; //SM2�����㷨���������C1��X����ֵ����λ�������豸��ǩ����Կ��λ�������
	BYTE  YCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8]; //SM2�����㷨���������C1��Y����ֵ����λ�������豸��ǩ����Կ��λ�������
	BYTE  HASH[32]; //SM2�����㷨��������еĲ���C3
	ULONG CipherLen; //SM2�����㷨��������в���C2�ĳ���
	BYTE  Cipher[0x01]; //SM2�����㷨��������в���C2��ֵ
} ECCCIPHERBLOB, *PECCCIPHERBLOB;

typedef struct Struct_ECCPUBLICKEYBLOB{
	ULONG	BitLen;											//ģ����ʵ��λ����,������8�ı���
	BYTE	XCoordinate[ECC_MAX_XCOORDINATE_BITS_LEN/8];	//�����ϵ��X����,�������ϵ����� #define ECC_MAX_XCOORDINATE_BITS_LEN 512	
	BYTE	YCoordinate[ECC_MAX_YCOORDINATE_BITS_LEN/8];	//�����ϵ��X����,�������ϵ����� #define ECC_MAX_XCOORDINATE_BITS_LEN 512
}ECCPUBLICKEYBLOB, *PECCPUBLICKEYBLOB;

typedef struct Struct_ECCPRIVATEKEYBLOB{
	ULONG	BitLen;									//ģ����ʵ��λ����,������8�ı���
	BYTE	PrivateKey[ECC_MAX_MODULUS_BITS_LEN/8];	//�������ϵ����� #define ECC_MAX_MODULUS_BITS_LEN 512
}ECCPRIVATEKEYBLOB, *PECCPRIVATEKEYBLOB;

typedef struct SKF_ENVELOPEDKEYBLOB{
	ULONG				Version;					// ��ǰ�汾Ϊ 1
	ULONG				ulSymmAlgID;				// ���ڼ��ܴ�����ECC��Կ�ԵĶԳ��㷨��ʶ���޶�Ϊ����ECBģʽ����Կ�����ݽ��м���
	ULONG				ulBits;						// �����������Կ�Ե���Կλ����
	BYTE				pbEncryptedPriKey[64];		// �����������Կ��˽Կ������
	ECCPUBLICKEYBLOB	PubKey;						// �����������Կ�ԵĹ�Կ
	ECCCIPHERBLOB		ECCCipherBlob;				// �ñ�����Կ���ܵĶԳ���Կ���ġ�
}ENVELOPEDKEYBLOB, *PENVELOPEDKEYBLOB;

typedef struct Struct_BLOCKCIPHERPARAM{
	BYTE	IV[MAX_IV_LEN];	//��ʼ������MAX_IV_LENΪ��ʼ����������󳤶�#define MAX_IV_LEN 32
	ULONG	IVLen;			//��ʼ����ʵ�ʳ��ȣ����ֽڼ��㣩
	ULONG	PaddingType;	//��䷽ʽ��0��ʾ����䣬1��ʾ����PKCS#5��ʽ�������
	ULONG	FeedBitLen;		//����ֵ��λ���ȣ���λ���㣩
} BLOCKCIPHERPARAM, *PBLOCKCIPHERPARAM;

typedef struct Struct_FILEATTRIBUTE{
	CHAR	FileName[MAX_FILENAME_LEN];	//�ļ���,ASCIIZ�ַ�������󳤶�Ϊ32��
	ULONG	FileSize;		//�ļ���С
	ULONG	ReadRights;		//��ȡ�ļ���Ҫ��Ȩ��
	ULONG	WriteRights;	//д���ļ���Ҫ��Ȩ��
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
//7.1	�豸����
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
//7.2	���ʿ���
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
//7.3	Ӧ�ù���
//-------------------------
ULONG DEVAPI SKF_CreateApplication(DEVHANDLE hDev, LPSTR szAppName, LPSTR szAdminPin, DWORD dwAdminPinRetryCount,LPSTR szUserPin, DWORD dwUserPinRetryCount,DWORD dwCreateFileRights, HAPPLICATION *phApplication); 
ULONG DEVAPI SKF_EnumApplication(DEVHANDLE hDev, LPSTR szAppName,ULONG *pulSize);
ULONG DEVAPI SKF_DeleteApplication(DEVHANDLE hDev, LPSTR szAppName);
ULONG DEVAPI SKF_OpenApplication(DEVHANDLE hDev, LPSTR szAppName, HAPPLICATION *phApplication);
ULONG DEVAPI SKF_CloseApplication(HAPPLICATION hApplication);
//-------------------------
//7.4	�ļ�����
//-------------------------
ULONG DEVAPI SKF_CreateFile(HAPPLICATION hApplication, LPSTR szFileName, ULONG ulFileSize, ULONG ulReadRights, ULONG ulWriteRights);
ULONG DEVAPI SKF_DeleteFile(HAPPLICATION hApplication, LPSTR szFileName);
ULONG DEVAPI SKF_EnumFiles(HAPPLICATION hApplication, LPSTR szFileList, ULONG *pulSize);
ULONG DEVAPI SKF_GetFileInfo(HAPPLICATION hApplication, LPSTR szFileName, FILEATTRIBUTE *pFileInfo);
ULONG DEVAPI SKF_ReadFile(HAPPLICATION hApplication, LPSTR szFileName, ULONG ulOffset, ULONG ulSize, BYTE * pbOutData, ULONG *pulOutLen);
ULONG DEVAPI SKF_WriteFile(HAPPLICATION hApplication, LPSTR szFileName, ULONG  ulOffset, BYTE *pbData, ULONG ulSize);
//-------------------------
//7.5	����������
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
//7.6	�������
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
ULONG DEVAPI SKF_CloseHandle(HANDLE hHandle);//�رջỰ��Կ���Ӵա���Ϣ��֤������

// ����ӿ�
ULONG DEVAPI SKF_RSASignHash(HCONTAINER hContainer, BOOL bSign, HANDLE hHash, BYTE* pbSignature, ULONG* pulSignatureLen);
ULONG DEVAPI SKF_ECCSignHash(HCONTAINER hContainer, BOOL bSign, HANDLE hHash, PECCSIGNATUREBLOB pblkEccSignaure);
ULONG DEVAPI SKF_ECCDecrypt(HCONTAINER hContainer, BOOL bSign, const ECCCIPHERBLOB* pCipherText, BYTE *pbData, ULONG *pdwDataLen);
ULONG DEVAPI SKF_RSADecrypt(HCONTAINER hContainer, BOOL bSign, const BYTE *pCipherData, ULONG ulCipherDataLen, BYTE *pbData, ULONG *pulDataLen);

#ifdef __cplusplus
}
#endif

#define SAR_OK							0x00000000	// �ɹ�
#define SAR_FAIL						0x0A000001	// ʧ��
#define SAR_UNKNOWNERR					0x0A000002	// �쳣����
#define SAR_NOTSUPPORTYETERR			0x0A000003	// ��֧�ֵķ���
#define SAR_FILEERR						0x0A000004	// �ļ���������
#define SAR_INVALIDHANDLEERR			0x0A000005	// ��Ч�ľ��
#define SAR_INVALIDPARAMERR				0x0A000006	// ��Ч�Ĳ���
#define SAR_READFILEERR					0x0A000007	// ���ļ�����
#define SAR_WRITEFILEERR				0x0A000008	// д�ļ�����
#define SAR_NAMELENERR					0x0A000009	// ���Ƴ��ȴ���
#define SAR_KEYUSAGEERR					0x0A00000A	// ��Կ��;����
#define SAR_MODULUSLENERR				0x0A00000B	// ģ�ĳ��ȴ���
#define SAR_NOTINITIALIZEERR			0x0A00000C	// δ��ʼ��
#define SAR_OBJERR						0x0A00000D	// �������
#define SAR_MEMORYERR					0x0A00000E	// �ڴ����
#define SAR_TIMEOUTERR					0x0A00000F	// ��ʱ
#define SAR_INDATALENERR				0x0A000010	// �������ݳ��ȴ���
#define SAR_INDATAERR					0x0A000011	// �������ݴ���
#define SAR_GENRANDERR					0x0A000012	// �������������
#define SAR_HASHOBJERR					0x0A000013	// HASH�����
#define SAR_HASHERR						0x0A000014	// HASH�������
#define SAR_GENRSAKEYERR				0x0A000015	// ����RSA��Կ��
#define SAR_RSAMODULUSLENERR			0x0A000016	// RSA��Կģ������
#define SAR_CSPIMPRTPUBKEYERR			0x0A000017	// CSP�����빫Կ����
#define SAR_RSAENCERR					0x0A000018	// RSA���ܴ���
#define SAR_RSADECERR					0x0A000019	// RSA���ܴ���
#define SAR_HASHNOTEQUALERR				0x0A00001A	// HASHֵ�����
#define SAR_KEYNOTFOUNTERR				0x0A00001B	// ��Կδ����
#define SAR_CERTNOTFOUNTERR				0x0A00001C	// ֤��δ����
#define SAR_NOTEXPORTERR				0x0A00001D	// ����δ����
#define SAR_DECRYPTPADERR				0x0A00001E	// ����ʱ����������
#define SAR_MACLENERR					0x0A00001F	// MAC���ȴ���
#define SAR_BUFFER_TOO_SMALL			0x0A000020	// ����������
#define SAR_KEYINFOTYPEERR				0x0A000021	// ��Կ���ʹ���
#define SAR_NOT_EVENTERR				0x0A000022	// ���¼�����
#define SAR_DEVICE_REMOVED				0x0A000023	// �豸���Ƴ�
#define SAR_PIN_INCORRECT				0x0A000024	// PIN����ȷ
#define SAR_PIN_LOCKED					0x0A000025	// PIN������
#define SAR_PIN_INVALID					0x0A000026	// PIN��Ч
#define SAR_PIN_LEN_RANGE				0x0A000027	// PIN���ȴ���
#define SAR_USER_ALREADY_LOGGED_IN		0x0A000028	// �û��Ѿ���¼
#define SAR_USER_PIN_NOT_INITIALIZED	0x0A000029	// û�г�ʼ���û�����
#define SAR_USER_TYPE_INVALID			0x0A00002A	// PIN���ʹ���
#define SAR_APPLICATION_NAME_INVALID	0x0A00002B	// Ӧ��������Ч
#define SAR_APPLICATION_EXISTS			0x0A00002C	// Ӧ���Ѿ�����
#define SAR_USER_NOT_LOGGED_IN			0x0A00002D	// �û�û�е�¼
#define SAR_APPLICATION_NOT_EXISTS		0x0A00002E	// Ӧ�ò�����
#define SAR_FILE_ALREADY_EXIST			0x0A00002F	// �ļ��Ѿ�����
#define SAR_NO_ROOM						0x0A000030	// �ռ䲻��
#define SAR_FILE_NOT_EXIST				0x0A000031	// �ļ�������
#define SAR_REACH_MAX_CONTAINER_COUNT   0x0A000032	// �Ѵﵽ���ɹ���������
// added vendor
#define SAR_CONTAINER_EXISTS			0x0A100001	// 
#define SAR_NOTEXIST					0x0A100002	// 
#define SAR_IVLENERR					0x0A100003	// 
#define SAR_BAD_LEN						0x0A100004	//
#define SAR_RETRY_COUNT_OUT				0x0a100005	// �ظ������ѵ�
#define SAR_RETRY_COUNT_ERR				0x0a100006	// �ظ������쳣
#define SAR_FILENAME_LEN_ERR			0x0a100007	// �ļ������ȳ���
#define SAR_CONTAINER_NAME_INVALID		0x0a100008	// ����������Ч

#define SAR_DRIVER_UNFOUND				0x0A100009	// ����û���ҵ�
#define SAR_DEV_UNSUPPORT				0x0A10000A	// �豸��֧��
#define SAR_TOO_MORE_DEVICE				0x0A10000B	// �豸̫��
#define SAR_STRUCTVER_UNSUPPORT			0x0A10000C	// ��֧�ֵĽṹ
#define SAR_DEV_NAME					0x0A10000D	// �豸���ƴ���
#define SAR_ASYMSIGNERR					0x0A10000F	// �ǶԳ��㷨ǩ������
#define SAR_ASYMVERIFYERR				0x0A100010	// �ǶԳ��㷨��ǩ����
#define SAR_OBJECT_UNFOUND				0x0A100011	// ����δ�ҵ�
#define SAR_CONTAINER_UNFOUND			0x0A100012	// ����������
#define SAR_CONTAINER_EXIST				0x0A100013	// �����Ѿ�����
#define SAR_CERT_SIZE					0x0A100014	// ֤�鳤�ȴ���
#define SAR_NEED_PADDING				0x0A100015	// �㷨��Ҫ����
#define SAR_ACCESS_DENIED				0x0A100016	// �ܾ�����
#define SAR_DEV_DISCONNECT				0x0A100017	// �豸û������
#define SAR_UNHANDLED_EXCEPTION			0x0A100018	// ���ֿɵ��³���������쳣�����Ѿ�����

#endif