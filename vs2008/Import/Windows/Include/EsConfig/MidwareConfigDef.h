//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2013,�������Ķ������ݰ�ȫ���޹�˾
// All rights reserved.
// 
// �ļ����ƣ�
//		MidwareConfigDef.h
//
// �ļ���ʶ��
//
// ժ   Ҫ��
//		Ϊ�м�����������������ݽṹ���塣
// 
// ��ǰ�汾��
//		1.0
//
// ��   �ߣ�
//		������
//
// ������ڣ�
//		2013��06��06��
//////////////////////////////////////////////////////////////////////////
#ifndef _MIDWARE_CONFIG_DEF_H_
#define _MIDWARE_CONFIG_DEF_H_

#if defined (_OS_IOS_) | defined (_OS_ANDROID_) | defined (_OS_MAC_OSX_)
#include <stdlib.h> //for wchar_t
#endif

#define MAX_PATH_LEN				260
#define MAX_WINDOW_TITLE_LEN		256
#define MAX_WINDOW_NAME_LEN			128
#define MAX_STATIC_TEXT_LEN			256
#define MAX_FAT_STATIC_TEXT_LEN		2048
#define MAX_EDIT_TEXT_LEN			2048
#define MAX_BUTTON_TEXT_LEN			20

typedef enum EN_CFGTYPE
{
	CFGTYPE_NODE_BEGIN = 0x40000000,
	CFGTYPE_NODE_END = 0x40000001,
	CFGTYPE_END = 0x40000002,
	CFGTYPE_INVALID = 0x00,

	CFGTYPE_BOOL,		// 0x01
	CFGTYPE_DWORD,
	CFGTYPE_STRINGA,
	CFGTYPE_STRINGW,
	CFGTYPE_BINARY,  // 0x05
	CFGTYPE_IMAGE,
	CFGTYPE_SIZE,
	CFGTYPE_POSITION,
	CFGTYPE_MAINFRAME,
	CFGTYPE_BUTTON, // 0x0A
	CFGTYPE_STATIC,
	CFGTYPE_PICTURE,
	CFGTYPE_COMBOX,
	CFGTYPE_TAB,
	CFGTYPE_EDIT, // 0x0F
	CFGTYPE_TREE,
	CFGTYPE_GRID,
	CFGTYPE_GROUPBOX,
	CFGTYPE_SOFTKEYBOARD,
	CFGTYPE_STRINGA_FIXED, // 0x14
	CFGTYPE_STRINGW_FIXED,
	CFGTYPE_LIST_DWORD,
	CFGTYPE_LIST_STRING_FIXED,
}EN_CFGTYPE;

typedef enum EN_LANG_ID
{
	LANG_ID_IMPOSSIBLE				= 0,
	LANG_ID_CN						= 2052,
	LANG_ID_TC						= 1028,
	LANG_ID_EN						= 1033,
	LANG_ID_MAX_VALUE
}EN_LANG_ID;

#pragma pack(push,1)
// BOOL��DWORD���Ͳ���Ҫ�ṹ
typedef struct BlkCfgStringTag
{
	u4		m_u4Len;
	wchar_t*m_pszData;
}BlkCfgString;

typedef struct BlkCfgBinaryTag
{
	u4		m_u4Len;
	u1*		m_pu1Data;
}BlkCfgBinary;

typedef struct BlkCfgImageTag
{
	u4		m_u4Len;
	wchar_t*m_pszImagePath; // ��ʽ��"jpg;excelsecu_icbc\softkeyboard.jpg"
}BlkCfgImage;

// λ��
typedef struct BlkCfgPositionTag
{
	u4	m_u4X;
	u4	m_u4Y;
}BlkCfgPosition;

// �ߴ�
typedef struct BlkCfgSizeTag
{
	u4	m_u4Width;
	u4	m_u4Height;
}BlkCfgSize;

// �����䳤�ַ���
typedef struct BlkCfgEditTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
}BlkCfgEdit, BlkCfgSoftkeyBoard;

// ����һ���䳤�ַ���
typedef struct BlkCfgStaticTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
	BlkCfgString	m_blkText;
}BlkCfgPicture, BlkCfgStatic, BlkCfgTree, BlkCfgGroupBox;

// ���������䳤�ַ���
typedef struct BlkCfgMainFrameTag
{
	BlkCfgSize	m_blkSize;
	u4			m_u4IconLen;
	wchar_t*	m_pszIcon;
	u4			m_u4TitleLen;
	wchar_t*	m_pszTitle;
}BlkCfgMainFrame;

// ���������䳤�ַ���
typedef struct BlkCfgButtonTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;

	u4				m_u4TextLen;
	wchar_t*		m_pszText;
	u4				m_u4ImageLen;
	wchar_t*		m_pszImage;
	u4				m_u4FunctionLen;
	wchar_t*		m_pszFunction;
}BlkCfgButton;

// ����ѡ���Ԫ��
typedef struct BlkCfgComboxTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
	u4				m_u4TextLen;	// �ַ���
	wchar_t*		m_pszText;		// �洢������Ϊ item1Text;item2Text ...;itemnText
	u4				m_u4ItemCount;	// �����洢����Ŀ��
	u4*				m_pu4ItemData;	// �洢������Ϊ item1Data item2Data...itemnData
}BlkCfgCombox;

// TabԪ��
typedef struct BlkCfgTabTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
	u4				m_u4TextLen;	// 
	wchar_t*		m_pszText;		// �洢������Ϊ tab1Text tab2Text ... tabnText
	u4				m_u4TabCount;	// tabҳ�����Ŀ
}BlkCfgTab;

// gridԪ��
typedef struct BlkCfgGridTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
	u4				m_u4TextLen;	// Ϊ����pszText������ڴ��С���������һ���ֽڵ�0
	wchar_t*		m_pszText;		// �洢������Ϊ col1Text col2Text ... colnText
	u4				m_u4ColCount;	// ���������
	u4*				m_pu4ColSize;	// ÿ���еĿ��
}BlkCfgGrid;
#pragma pack(pop)

// ����Ϊ�ṹ�嶨�壬δ���
// ���̶����ֽ�����һ�ֽڣ�����
#pragma pack(push,1)

#include <EsDriver/EsDriver.h>

#define CUSTOMER_ID_ICBC	0x49434243
#define CUSTOMER_ID_BOC		0x00424F43
#define CUSTOMER_ID_SCNXY	0x53434E58
#define CUSTOMER_ID_JNNXY	0x4A4E4E58
#define CUSTOMER_ID_NRCB	0x4E524342
#define CUSTOMER_ID_CMBC	0x434D4243
#define CUSTOMER_ID_ESSTD	0x45535354
#define CUSTOMER_ID_CNCB	0x434E4342
#define CUSTOMER_ID_CDRCB	0x43445243
#define CUSTOMER_ID_BOGY	0x424F4759
#define CUSTOMER_ID_CQCB	0x43514342
#define CUSTOMER_ID_CCBC	0x43434243
#define CUSTOMER_ID_BOCOMM	        0x42434F4D  // ����key cos�����customer id������key���ǻ�����һ�£�
#define CUSTOMER_ID_BOCOMM_SMART    0x42434F4D  // �����ǻ����������ļ������customer id����cosһ�£�
#define CUSTOMER_ID_BOCOMM_2G       0x424F4332  // ���ж���key�����ļ������customer id����cos��һ�£�
#define CUSTOMER_ID_BOCOMM_EN       0x4A545951  // ��������ֱ��key�����ļ������customer id����cos��һ�£�
#define CUSTOMER_ID_HRXJ	0x4852584A
#define CUSTOMER_ID_CMB     0x20434D42

#define CUSTOMER_ID_CGB     0x00434742          
//////////////////////////////////////////////////////////////////////////
// Token������
//////////////////////////////////////////////////////////////////////////

#define MAX_PIN_LENGTH				32

typedef enum EnBusinessSnType
{
	BUSINESS_SN_TYPE_CHIPSN		= 0,
	BUSINESS_SN_TYPE_MEDIAID	= 1,
}EnBusinessSnType;

// XXX_MODE_DEV������:
//	(1) �Ǹ����ܽӿڵ��豸��֤��Կʹ�ã�SKF_DevAuth��SKF_ChangeDevAuthKey
//	(2) �������ӿ��У���֤��ʱ�򣬿ͻ��ǵ��� SKF_GenRandom �Ȼ�ȡ16�ֽ��������Ȼ���ⲿ����������γ���֤���ģ��ٵ���SKF_DevAuth��������SlotApi�ӿ�������֤��ʱ����ȡ�����
//	(3) SKF_ChangeDevAuthKey�ӿ��У�û�о���Կ�����������������Կ������������Կ����+MACֵ��ͨ���������ж�
//	(4) �ڲ�����Ҫ�������������ת������֤�����в���Ҫ��ȡ��������޸Ĺ��������⴦��
typedef enum EnPinConvertMode
{
	PIN_CONVERT_MODE_MD5	= 0x00,
	PIN_CONVERT_MODE_SHA	= 0x01,
	PIN_CONVERT_MODE_SM3SM4 = 0x02,
	PIN_CONVERT_MODE_CFCA	= 0x03,
	PIN_CONVERT_MODE_SM3	= 0x04,
	PIN_CONVERT_MODE_ON_KEY	= 0x05,
	PIN_CONVERT_MODE_DEV    = 0x06,
}EnPinConvertMode;

typedef enum EnPinExtAuthMode
{
	EXT_AUTH_MODE_3DES112_OLD = 0x00,
	EXT_AUTH_MODE_3DES112_STD = 0x01,
	EXT_AUTH_MODE_SM4		  = 0x02,
	EXT_AUTH_MODE_ON_KEY	  = 0x05,
	EXT_AUTH_MODE_DEV		  = 0x06,
}EnPinExtAuthMode;

typedef enum EnPinChangeMode
{
	CHANGE_PIN_MODE_3DES112_CM1 = 0x00, // C:change M:mac V:verify
	CHANGE_PIN_MODE_3DES112_CM2 = 0x01,
	CHANGE_PIN_MODE_3DES112_VC	= 0x02,
	CHANGE_PIN_MODE_SM4_VC		= 0x03, // this only for minsheng bank
    CHANGE_PIN_MODE_SM4_STD     = 0X04, // this is standard sm4 process
	CHANGE_PIN_MODE_ON_KEY		= 0x05,
	CHANGE_PIN_MODE_DEV		    = 0x06,
}EnPinChangeMode;

typedef enum EnPinCacheMode
{
	PIN_CACHE_MODE_NONE		= 0,
	PIN_CACHE_MODE_PROCESS	= 1,
	PIN_CACHE_MODE_PC		= 2,
}EnPinCacheMode;

typedef enum EnOprPermission
{
	PERMISSION_PIN_NONEED			= 0, // ����Ҫ��֤PIN
	PERMISSION_PIN_NEED_CACHEPIN	= 1, // ��Ҫ��֤PIN������ʹ�û���PIN
	PERMISSION_PIN_NEED_NO_CACHEPIN	= 2, // ��Ҫ��֤PIN������ʹ�û���PIN
}EnOprPermission;

typedef struct BlkOprPermissionTag
{
	EnOprPermission		m_enGenKey;
	EnOprPermission		m_enDec;
	EnOprPermission		m_enSign1G;
	EnOprPermission		m_enSign2G;
	EnOprPermission		m_enDelCnt;
}BlkOprPermission;

typedef struct BlkTokenPinConfigTag
{
	char				m_szDefaultPin[MAX_PIN_LENGTH+1];
	u4					m_u4MinLen;
	u4					m_u4MaxLen;

	ESBOOL				m_bPinModeValid; // ΪTRUE������3��ģʽ����Ч
	EnPinConvertMode	m_enConvertMode;
	EnPinExtAuthMode	m_enExtAuthMode;
	EnPinChangeMode		m_enChangeMode;

	EnPinCacheMode		m_enCacheMode;

	BlkOprPermission	m_blkOprPermission;
}BlkTokenPinConfig;

typedef enum En2GSignMsgType
{
	DISPLAY_SIGN_MSG_TYPE_ICBC	= 0,
	DISPLAY_SIGN_MSG_TYPE_BOC	= 1,
	DISPLAY_SIGN_MSG_TYPE_NXY	= 2,
	DISPLAY_SIGN_MSG_TYPE_CMBC	= 3,
	DISPLAY_SIGN_MSG_TYPE_NRCB	= 4,
	DISPLAY_SIGN_MSG_TYPE_ALIPAY = 5,
	DISPLAY_SIGN_MSG_TYPE_CCBCC = 6,
	DISPLAY_SIGN_MSG_TYPE_CCB	= 7,
	DISPLAY_SIGN_MSG_TYPE_CDRCB = 8,
	DISPLAY_SIGN_MSG_TYPE_CGB	= 9,
	DISPLAY_SIGN_MSG_TYPE_BOCOM = 0x0A,
	DISPLAY_SIGN_MSG_TYPE_CQCB	= 0x0B,
	DISPLAY_SIGN_MSG_TYPE_HRXJ	= 0x0C,
	DISPLAY_SIGN_MSG_TYPE_CMB	= 0x0D,
    DISPLAY_SIGN_MSG_TYPE_SPDB  = 0x0F,
    DISPLAY_SIGN_MSG_TYPE_BOGY  = 0x10,
	DISPLAY_SIGN_MSG_TYPE_NONE	= 0xFF, // ��֧��2��ǩ����1��KEY��
}En2GSignMsgType;

typedef enum En2GSignRsaMode
{
	DISPLAY_SIGN_RSA_MODE_ICBC			= 0, // ����ɢ���㷨��HASH����
	DISPLAY_SIGN_RSA_MODE_SHA1_STD		= 1, // ����SHA1������ǩ�����ñ�׼�㷨
	DISPLAY_SIGN_RSA_MODE_SHA256_STD	= 2, // ����SHA256������ǩ�����ñ�׼�㷨
	DISPLAY_SIGN_RSA_MODE_ANY_0009		= 3, // ����ɢ���㷨������ǩ������0009����
}En2GSignRsaMode;

typedef enum En2GSignSm2Mode
{
	DISPLAY_SIGN_SM2_MODE_STD			= 0, // ����SM3��ǩ��һ��
	DISPLAY_SIGN_SM2_MODE_CMBC			= 1, // ����SM3/SHA256��ǩ������
}En2GSignSm2Mode;

typedef struct BlkTokenSign2GConfigTag
{
	En2GSignMsgType	m_enMsgType;		// ǩ����Ϣ��ʽ
	En2GSignRsaMode	m_enSignRsaMode;	// RSAǩ��ģʽ
	En2GSignSm2Mode	m_enSignSm2Mode;    // SM2ǩ��ģʽ
}BlkTokenSign2GConfig;

typedef struct BlkTimeoutCfgItemTag
{
	u4		m_u4TimeoutSeconds; // Ĭ�ϳ�ʱʱ�䣬����Ϊ��λ
	ESBOOL	m_bChangeable;		// ������޸ģ�����Ҫͨ��������ʽ���緢ָ���ȡ���µĳ�ʱʱ��
}BlkTimeoutCfgItem;

typedef struct BlkTokenTimeoutConfigTag
{
	BlkTimeoutCfgItem m_blkFormat;	
	BlkTimeoutCfgItem m_blkVerifyPin;
	BlkTimeoutCfgItem m_blkChangePin;
	BlkTimeoutCfgItem m_blkSign2G;	
	BlkTimeoutCfgItem m_blkEraseCert;
	BlkTimeoutCfgItem m_blkGenKey;
	BlkTimeoutCfgItem m_blkUnblockPin;
}BlkTokenTimeoutConfig;

typedef struct BlkSoftCancelConfigTag
{
	ESBOOL	m_bSupportAtFormat;
	ESBOOL	m_bSupportAtVerifyPin;
	ESBOOL	m_bSupportAtChangePin;
	ESBOOL	m_bSupportAtSign2G;
	ESBOOL	m_bSupportAtEraseCert;
	ESBOOL	m_bSupportAtGenKey;
	ESBOOL  m_bSupportAtUnblockPin;
}BlkSoftCancelConfig;

typedef struct BlkTokenConfigTag
{
	u4						m_u4MaxTokenCount;
	ESBOOL					m_bNoUi;					 // CFCAԤ�ƺ�һ��KEY����������ΪESTRUE
	ESBOOL					m_bEndUiWhenDevRemoved;		 // �ε�Key֮�󣬽����Ƿ����
	wchar_t					m_szUiModulePath[260];
	EnBusinessSnType		m_enBusinessSnType;
	ESBOOL					m_bSupportChangePinAtFormat; // �ڸ�ʽ��ָ���а����޸�PINָ��������Լ���һ�ΰ���--Ŀǰ�����и߰汾COS֧��
	ESBOOL					m_bAlwaysGenSignKey;		 // GenKey����ǩ�����ǽ�������������ǩ����Կ�ԣ�����˽Կ�ſ���ִ�н��ܲ���
	u4						m_u4MinLabelLen;
	u4						m_u4MaxLabelLen;

	BlkTokenPinConfig		m_blkPinCfg;
	BlkTokenSign2GConfig	m_blkSign2GCfg;
	BlkTokenTimeoutConfig	m_blkTimeoutCfg;
	BlkSoftCancelConfig		m_blkSoftCancelCfg;
}BlkTokenConfig;

//////////////////////////////////////////////////////////////////////////


typedef struct BlkSlotApiConfigTag
{
	u4 m_u4SlotApiCfg;
}BlkSlotApiConfig;

//////////////////////////////////////////////////////////////////////////
// CSP������
//////////////////////////////////////////////////////////////////////////

typedef struct BlkOrgPinLimitationTag
{
	ESBOOL	m_bCreateCnt; 
	ESBOOL	m_bDeleteCnt;
	ESBOOL	m_bGenKey;
	ESBOOL	m_bDecrypt;
	ESBOOL	m_bSign1G;
	ESBOOL	m_bSign2G;
}BlkOrgPinLimitation;

typedef enum EnDelCntMode
{
	DEL_CNT_MODE_NORMAL				= 0, // �������⴦��
	DEL_CNT_MODE_DEL_EMPTY_CNT		= 1, // ɾ��������
	DEL_CNT_MODE_DEL_INVALID_CNT	= 2, // ɾ����Ч������û��֤�������
    DEL_CNT_MODE_FULL_OR_SAME_NAME  = 3  // ����������ͬ����������������ʱ��ɾ�����������Ƚ�����������������֤��ĳ����£�ģʽ1��2����ɾ��һ������
}EnDelCntMode;

typedef enum EnWriteCertMode
{
	WRITE_CERT_MODE_NORMAL				= 0, // �������⴦��
	WRITE_CERT_MODE_DEL_SAME_DN_CERT	= 1, // ɾ��ͬDN��֤��
	WRITE_CERT_MODE_DEL_OTHER_CERT		= 2, // ɾ������֤��
}EnWriteCertMode;

typedef enum EnImportKeyPairMode
{
	IMPORT_KEYPAIR_FORMAT_PLAIN	= 0,
	IMPORT_KEYPAIR_FORMAT_CFCA,
}EnImportKeyPairMode;

typedef enum EnSm2PubKeyFormat
{
	SM2_PUBKEY_FORMAT_CFCA	= 0,
}EnSm2PubKeyFormat;

typedef struct BlkGmAlgConfigTag
{
	u4					m_u4AlgIdSign;
	u4					m_u4AlgIdKeyx;
	u4					m_u4AlgIdSm3;
	EnSm2PubKeyFormat	m_enSm2PubKeyFormat;
	u4					m_u4AlgIdSm1;
	u4					m_u4AlgIdSm4;
	u4					m_u4AlgIdSsf33;
}BlkGmAlgConfig;

typedef struct BlkCspConfigTag
{
	char				m_szCspName[64];
	BlkOrgPinLimitation	m_blkOrgPinLimitation;
	EnDelCntMode		m_enDeleteCntMode; // 0: Ĭ�ϣ�1��ɾ����������2��ɾ����֤������
	EnWriteCertMode		m_enWriteCertMode;
	EnImportKeyPairMode m_enImportKeyPairMode;
	BlkGmAlgConfig		m_blkGmAlgCfg;
}BlkCspConfig;

//////////////////////////////////////////////////////////////////////////
// UI������
//////////////////////////////////////////////////////////////////////////

typedef struct BlkUiPinLimitationTag
{
	u4		m_u4MinLen; // PIN��С����
	u4		m_u4MaxLen; // PIN��󳤶�
	u4		m_u4SpecialCharSupportType; // ����ĸ������������ַ��������������ַ�, 0x00��֧�������ַ��� 0x01����֧�������ַ�
	// checkMethod����PIN��鷽ʽ�����ǿ��Զ��弸����PIN��ⷽʽ����������ζ�������Ҫ���ۡ�
	// ��PIN��鿼�ǵ������У�
	// 1���Ƿ�ȫ���ֻ���ȫ��ĸ��������ռ��һ������λ
	// 2���Ƿ���������ַ�����000000,123456,897654,abcdef�����ڰ��������ַ������룬������ռ��2������λ
	// 3���Ƿ����ձ�ʹ�õ����룬��password��������ռ��3������λ
	// 4���Ƿ��Ǽ����ڽ��ַ�����1q2w3e4r��������ռ��4������λ
	u4		m_u4WeakPinCheckMethod; 
	// ������֧��ģʽ��0:��֧�֣�1��֧�ֵ�������棬2��֧�� 
	u4		m_u4WeakPinSupportType;
}BlkUiPinLimitation;

// UI��������
typedef struct BlkCfgUiGeneralTag
{
	u4						m_u4Mode;			// 0x01: ��̬���ڵ�������, 0x02: �����ⲿ��̬��������, 0x03: ʹ�ÿ����ͨѶ��ʽ�������棨Ŀǰֻ֧�����֣�
	u4						m_u4BkgndColor;		// ����ɫ
	BlkUiPinLimitation		m_blkPinLimitation; // PIN���ƣ��Ϸ��Լ���Լ���������ʱ���ã�
	BlkCfgString			m_blkUiPath;		// UIģ���·����������ָʾʹ�ÿ����ͨѶ��ʽʱexe�ļ���·��
}BlkCfgUiGeneral;


//////////////////////////////////////////////////////////////////////////
// ����Ԫ�ض���
//////////////////////////////////////////////////////////////////////////

typedef struct BlkCfgUiChangeLabelTag
{
	BlkCfgMainFrame		m_blkMainFrame;
	BlkCfgPicture		m_blkPictureLogo;			// LOGO
	BlkCfgStatic		m_blkStaticNewLabel;		// Label����λ����ʾ
	BlkCfgEdit			m_blkEditLabel;				// Label�����
	BlkCfgStatic		m_blkStaticInputPin;		// PIN����λ����ʾ
	BlkCfgEdit			m_blkEditInputPin;			// PIN�����
	BlkCfgButton		m_blkButtonSoftKeyboard;	// �����BUTTON�������ʵ��չ�����������
	BlkCfgStatic		m_blkStaticPinNumTip;		// PIN�����ַ�����ʾ
	BlkCfgButton		m_blkButtonOk;				// ȷ�ϰ�ť
	BlkCfgButton		m_blkButtonCancel;			// ȡ����ť
	BlkCfgSoftkeyBoard	m_blkSoftkeyBoard;			// �����
}BlkCfgUiChangeLabel;

// �Ի���Ԫ��
typedef struct BlkDialogTag
{
	char		m_szTitle[MAX_WINDOW_TITLE_LEN];
	BlkCfgSize		m_blkSize;
	BlkCfgSize		m_blkSizeWithKbd;
}BlkDialog;

// ��ͼԪ��
typedef struct BlkCtrlPictureTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN];
	char		m_szImgPath[MAX_PATH_LEN];
	BlkCfgPosition	m_blkPosition;
}BlkCtrlPicture;

// ��̬�ı�Ԫ��
typedef struct BlkCtrlStaticTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN]; // ����
	char		m_szText[MAX_STATIC_TEXT_LEN]; // ����
	BlkCfgPosition	m_blkPosition; // λ��
}BlkCtrlStatic;

// �־�̬�ı�Ԫ�أ���BlkCtrlStatic�����ɸ�����ı�
typedef struct BlkCtrlFatStaticTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN]; // ����
	char		m_szText[MAX_FAT_STATIC_TEXT_LEN]; // ����
	BlkCfgPosition	m_blkPosition; // λ��
}BlkCtrlFatStatic;

// �༭��Ԫ��
typedef struct BlkCtrlEditTag
{
	char*		m_pszName;
	char*		m_pszText;
	char		m_szName[MAX_WINDOW_NAME_LEN];
	char		m_szText[MAX_EDIT_TEXT_LEN];
	BlkCfgPosition	m_blkPosition;
	ESBOOL		m_bPassword;
	ESBOOL		m_bReadOnly;
}BlkCtrlEdit;

// ��ťԪ��
typedef struct BlkCtrlButtonTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN];
	char		m_szText[MAX_EDIT_TEXT_LEN];
	BlkCfgPosition	m_blkPosition;
	ESBOOL		m_bSkined;
	char		m_szSkinImgPath[MAX_PATH_LEN];	
}BlkCtrlButton;

typedef struct BlkCtrlGrupBoxTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN];
	char		m_szText[MAX_STATIC_TEXT_LEN];
	BlkCfgPosition	m_blkPosition;
}BlkCtrlGrupBox;

typedef struct BlkCtrlKeyboardTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN];
	BlkCfgPosition	m_blkPosition;
}BlkCtrlKeyboard;

typedef struct BlkUiVerifyPinConfigTag
{
	BlkDialog			m_blkDlgMainFrame; // ������

	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO

	BlkCtrlStatic		m_blkCtrlPinInputPosTip; // PIN����λ����ʾ
	BlkCtrlEdit			m_blkCtrlEditPin; // PIN�����
	BlkCtrlButton		m_blkCtrIcoBtnKbd; // �����ͼ�꣬�����ʵ��չ�����������
	BlkCtrlStatic		m_blkCtrlPinInputCharNumTip; // PIN�����ַ�����ʾ

	BlkCtrlButton		m_blkCtrBtnOk; // ȷ�ϰ�ť
	BlkCtrlButton		m_blkCtrBtnCancel; // ȡ����ť
	BlkCtrlKeyboard		m_blkCtrlSoftKbd; // �����
}BlkUiVerifyPinConfig;

typedef struct BlkUiChangePinConfigTag
{
	BlkDialog			m_blkDlgMainFrame; // ������
	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO

	BlkCtrlStatic		m_blkCtrlOldPinInputPosTip; // ��PIN����λ����ʾ
	BlkCtrlEdit			m_blkCtrlEditOldPin; // ��PIN�����
	BlkCtrlButton		m_blkCtrIcoBtnKbdOldPin; // ��PIN���������ͼ�꣬�����ʵ��չ�����������
	BlkCtrlStatic		m_blkCtrlOldPinInputCharNumTip; // ��PIN�����ַ�����ʾ

	BlkCtrlStatic		m_blkCtrlNewPinInputPosTip; // ��PIN����λ����ʾ
	BlkCtrlEdit			m_blkCtrlEditNewPin; // ��PIN�����
	BlkCtrlButton		m_blkCtrIcoBtnKbdNewPin; // ��PIN���������ͼ�꣬�����ʵ��չ�����������
	BlkCtrlStatic		m_blkCtrlNewPinInputCharNumTip; // ��PIN�����ַ�����ʾ

	BlkCtrlStatic		m_blkCtrlNewConfirmPinInputPosTip; // ��PINȷ������λ����ʾ
	BlkCtrlEdit			m_blkCtrlEditNewConfirmPin; // ��PINȷ�������
	BlkCtrlButton		m_blkCtrIcoBtnKbdNewConfirmPin; // ��PINȷ�����������ͼ�꣬�����ʵ��չ�����������
	BlkCtrlStatic		m_blkCtrlNewConfirmPinInputCharNumTip; // ��PINȷ�������ַ�����ʾ

	BlkCtrlButton		m_blkCtrBtnOk; // ȷ�ϰ�ť
	BlkCtrlButton		m_blkCtrBtnCancel; // ȡ����ť
	BlkCtrlKeyboard		m_blkCtrlSoftKbd; // �����
}BlkUiChangePinConfig;

// typedef struct BlkUiChangeLabelConfigTag
// {
// 	BlkDialog			m_blkDlgMainFrame; // ������
// 
// 	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO
// 
// 	BlkCtrlStatic		m_blkCtrlLabelInputPosTip; // Label����λ����ʾ
// 	BlkCtrlEdit			m_blkCtrlEditLabel; // Label�����
// 
// 	BlkCtrlStatic		m_blkCtrlPinInputPosTip; // PIN����λ����ʾ
// 	BlkCtrlEdit			m_blkCtrlEditPin; // PIN�����
// 	BlkCtrlButton		m_blkCtrIcoBtnKbd; // �����ͼ�꣬�����ʵ��չ�����������
// 	BlkCtrlStatic		m_blkCtrlPinInputCharNumTip; // PIN�����ַ�����ʾ
// 
// 	BlkCtrlButton		m_blkCtrBtnOk; // ȷ�ϰ�ť
// 	BlkCtrlButton		m_blkCtrBtnCancel; // ȡ����ť
// 	BlkCtrlKeyboard		m_blkCtrlSoftKbd; // �����
// }BlkUiChangeLabelConfig;

typedef struct BlkUiCommonConfirmTag
{
	BlkDialog			m_blkDlgMainFrame; // ������

	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO
	BlkCtrlPicture		m_blkCtrlPicIllustration; // ������ʾ
	BlkCtrlStatic		m_blkCtrlWarning; // ������Ϣ
	BlkCtrlStatic		m_blkCtrlDetailTip; // ��ʾ����
	BlkCtrlStatic		m_blkCtrlCountDownTip;// ����ʱ��ʾ
}BlkUiCommonConfirm;

typedef struct BlkUiSign2GConfirmTag
{
	BlkDialog			m_blkDlgMainFrame; // ������

	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO
	BlkCtrlPicture		m_blkCtrlPicIllustration; // ������ʾ
	BlkCtrlStatic		m_blkCtrlWarning; // ������Ϣ
	BlkCtrlStatic		m_blkCtrlTip; // ����ʾ
	BlkCtrlStatic		m_blkCtrlDetailTip; // ǩ��������ʾ
	BlkCtrlStatic		m_blkCtrlCountDownTip; // ����ʱ��ʾ
}BlkUiSign2GConfirm;

typedef struct BlkUiConfirmTag
{	
	BlkUiCommonConfirm	m_blkUiCommonConfirmCfg; // ��ͨ����ȷ����ʾ������
	BlkUiSign2GConfirm	m_blkUiSign2GConfirmCfg; // ����ǩ������ȷ����ʾ������
}BlkUiConfirm;

typedef struct BlkUiConfigTag
{
	BlkCfgUiGeneral			m_blkCfgUiGeneral;		// ��������
	BlkCfgUiChangeLabel		m_blkCfgUiChangeLabel;	// �޸�Label��������
// 	BlkUiVerifyPinConfig	m_blkUiVerifyPinCfg; // ��֤PIN��������
// 	BlkUiChangePinConfig	m_blkUiChangePinCfg; // �޸�PIN��������
// 	BlkUiConfirm			m_blkUiConfirmCfg; // ȷ����ʾ��������ã�����һ���ȷ����ʾ���Լ�����ǩ��ȷ����ʾ��
	u1*						m_pu1AllocData;
}BlkUiConfig;

typedef enum EN_MAN_TOOL_STYLE
{
	MAN_TOOL_STYLE_UNITIALIZED,
	MAN_TOOL_STYLE_ONE, // ��ʽ1��������ʽ
	MAN_TOOL_STYLE_TWO, // ��ʽ2��������ʽ
	MAN_TOOL_STYLE_MAX_VALUE,
}EN_MAN_TOOL_STYLE;

// ʹ��������
typedef enum EN_MAN_TOOL_USER_TYPE
{
	MAN_TOOL_USER_TYPE_UNITIALIZED,
	MAN_TOOL_USER_TYPE_MANAGER, // ����Աʹ��
	MAN_TOOL_USER_TYPE_NORMAL, // ��ͨ�û�ʹ��
	MAN_TOOL_USER_TYPE_MAX_VALUE,
}EN_MAN_TOOL_USER_TYPE;

typedef struct BlkManToolGeneralConfigTag
{
	EN_MAN_TOOL_STYLE		m_enStyle;
	EN_MAN_TOOL_USER_TYPE	m_enUserType;
}BlkManToolGeneralConfig;

// ���û��������޵İ�ť��֮����˵�����ޣ�����Ϊ���Ǹ����û����;������ػ�����ʾ�ġ�
typedef struct BlkCtrlButtonUserTypeTag
{
	BlkCtrlButton	m_blkBtnCfg;
	ESBOOL			m_bHideForNormalUser;
}BlkCtrlButtonUserType;


typedef struct BlkCtrlCbxUSBKeyTag
{
	BlkCfgPosition	m_blkPosition;
}BlkCtrlCbxUSBKey;


typedef struct BlkCtrlCbxLangTag
{
	BlkCfgPosition	m_blkPosition;
}BlkCtrlCbxLang;

typedef struct BlkCtrlUSBKeyBasicInfoTag
{
	BlkCfgPosition	m_blkPosition;
}BlkCtrlUSBKeyBasicInfo;

typedef struct BlkCtrlCertInfoTag
{
	BlkCfgPosition	m_blkPosition;
}BlkCtrlCertInfo;

typedef struct BlkCtrlTabPage1ManToolTag
{
	char					m_szName[MAX_WINDOW_NAME_LEN];
	char					m_szText[MAX_STATIC_TEXT_LEN];
	BlkCfgSize				m_blkSize;
	BlkCtrlGrupBox			m_blkCtrlGrupBoxUKeyOperation;

	BlkCtrlButtonUserType	m_blkCtrlBtnChangePin;
	BlkCtrlButtonUserType	m_blkCtrlBtnChangeLabel;
	BlkCtrlButtonUserType	m_blkCtrlBtnViewBasicInfo;
	BlkCtrlButtonUserType	m_blkCtrlBtnFormat;
	BlkCtrlButtonUserType	m_blkCtrlBtnHelp;
	BlkCtrlPicture			m_blkLogo;
	BlkCtrlUSBKeyBasicInfo	m_blkBasicInfo;

}BlkCtrlTabPage1ManTool;

typedef struct BlkCtrlTabPage2ManToolTag
{
	char					m_szName[MAX_WINDOW_NAME_LEN];
	char					m_szText[MAX_STATIC_TEXT_LEN];
	BlkCfgSize				m_blkSize;
	BlkCtrlCertInfo			m_blkCtrlCertInfo;
	BlkCtrlButtonUserType	m_blkCtrlBtnExportCert;
	BlkCtrlButtonUserType	m_blkCtrlBtnDeleteCert;
	BlkCtrlButtonUserType	m_blkCtrlBtnViewCert;
	BlkCtrlButtonUserType	m_blkCtrlBtnRegisterCert;
	BlkCtrlButtonUserType	m_blkCtrlBtnUnregisterCert;

}BlkCtrlTabPage2ManTool;

typedef struct BlkCtrlTabPage3ManToolTag
{
	char					m_szName[MAX_WINDOW_NAME_LEN];
	char					m_szText[MAX_STATIC_TEXT_LEN];
	BlkCfgSize				m_blkSize;
	BlkCtrlFatStatic		m_blkCtrlWarmTips;
}BlkCtrlTabPage3ManTool;


typedef struct BlkCtrlTabManToolTag
{
	BlkCfgPosition			m_blkPosition;
	BlkCtrlTabPage1ManTool	m_blkTabPage1;
	BlkCtrlTabPage2ManTool	m_blkTabPage2;
	BlkCtrlTabPage3ManTool	m_blkTabPage3;
}BlkCtrlTabManTool;

typedef struct BlkManToolStyleOneConfigTag
{
	BlkDialog			m_blkDlgMainFrame; // ������
	BlkCtrlStatic		m_blkCtrlSelectKeyTip; // ѡ��USBKeyλ����ʾ
	BlkCtrlCbxUSBKey	m_blkCtrlCbxUKey; // USBKey�б���Ͽ�
	BlkCtrlStatic		m_blkCtrlSelectLangTip; // ѡ������λ����ʾ
	BlkCtrlCbxLang		m_blkCtrlLang;// ��ѡ�����б���Ͽ�
	BlkCtrlTabManTool	m_blkCtrlTab;			

}BlkManToolStyleOneConfig;

typedef struct BlkCtrlUSBKeyTreeViewTag
{
	BlkCfgPosition			m_blkPosition;
}BlkCtrlUSBKeyTreeView;

typedef struct BlkManToolStyleTwoConfigTag
{
	BlkDialog				m_blkDlgMainFrame; // ������
	BlkCtrlPicture			blkCtrlPicLogo; // LOGO
	BlkCtrlGrupBox			m_blkCtrlGrupBoxUKeyTreeView;
	BlkCtrlUSBKeyTreeView	m_blkUKeyTreeView;

	BlkCtrlButtonUserType	m_blkCtrlBtnChangePin;
	BlkCtrlButtonUserType	m_blkCtrlBtnChangeLabel;
	BlkCtrlButtonUserType	m_blkCtrlBtnViewBasicInfo;
	BlkCtrlButtonUserType	m_blkCtrlBtnViewCert;
	BlkCtrlButtonUserType	m_blkCtrlBtnFormat;
	BlkCtrlButtonUserType	m_blkCtrlBtnHelp;

}BlkManToolStyleTwoConfig;

typedef struct BlkManToolConfigTag
{
	BlkManToolGeneralConfig		m_blkGeneralCfg;
	BlkManToolStyleOneConfig	m_blkS1Cfg;
	BlkManToolStyleTwoConfig	m_blkS2Cfg;
}BlkManToolConfig;

//////////////////////////////////////////////////////////////////////////

#pragma pack(pop)
#endif