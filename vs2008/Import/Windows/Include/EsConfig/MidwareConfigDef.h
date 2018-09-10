//////////////////////////////////////////////////////////////////////////
// Copyright (c) 2013,深圳市文鼎创数据安全有限公司
// All rights reserved.
// 
// 文件名称：
//		MidwareConfigDef.h
//
// 文件标识：
//
// 摘   要：
//		为中间件及管理工具配置数据结构定义。
// 
// 当前版本：
//		1.0
//
// 作   者：
//		伍友良
//
// 完成日期：
//		2013年06月06日
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
// BOOL和DWORD类型不需要结构
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
	wchar_t*m_pszImagePath; // 格式："jpg;excelsecu_icbc\softkeyboard.jpg"
}BlkCfgImage;

// 位置
typedef struct BlkCfgPositionTag
{
	u4	m_u4X;
	u4	m_u4Y;
}BlkCfgPosition;

// 尺寸
typedef struct BlkCfgSizeTag
{
	u4	m_u4Width;
	u4	m_u4Height;
}BlkCfgSize;

// 不含变长字符串
typedef struct BlkCfgEditTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
}BlkCfgEdit, BlkCfgSoftkeyBoard;

// 包含一个变长字符串
typedef struct BlkCfgStaticTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
	BlkCfgString	m_blkText;
}BlkCfgPicture, BlkCfgStatic, BlkCfgTree, BlkCfgGroupBox;

// 包含两个变长字符串
typedef struct BlkCfgMainFrameTag
{
	BlkCfgSize	m_blkSize;
	u4			m_u4IconLen;
	wchar_t*	m_pszIcon;
	u4			m_u4TitleLen;
	wchar_t*	m_pszTitle;
}BlkCfgMainFrame;

// 包含三个变长字符串
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

// 复合选择框元素
typedef struct BlkCfgComboxTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
	u4				m_u4TextLen;	// 字符数
	wchar_t*		m_pszText;		// 存储的内容为 item1Text;item2Text ...;itemnText
	u4				m_u4ItemCount;	// 整个存储的条目数
	u4*				m_pu4ItemData;	// 存储的内容为 item1Data item2Data...itemnData
}BlkCfgCombox;

// Tab元素
typedef struct BlkCfgTabTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
	u4				m_u4TextLen;	// 
	wchar_t*		m_pszText;		// 存储的内容为 tab1Text tab2Text ... tabnText
	u4				m_u4TabCount;	// tab页面的数目
}BlkCfgTab;

// grid元素
typedef struct BlkCfgGridTag
{
	BlkCfgPosition	m_blkPosition;
	BlkCfgSize		m_blkSize;
	u4				m_u4TextLen;	// 为整个pszText分配的内存大小，包括最后一个字节的0
	wchar_t*		m_pszText;		// 存储的内容为 col1Text col2Text ... colnText
	u4				m_u4ColCount;	// 网格的列数
	u4*				m_pu4ColSize;	// 每个列的宽度
}BlkCfgGrid;
#pragma pack(pop)

// 以下为结构体定义，未完成
// 按固定的字节数（一字节）对齐
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
#define CUSTOMER_ID_BOCOMM	        0x42434F4D  // 交行key cos里面的customer id（二代key，智慧网盾一致）
#define CUSTOMER_ID_BOCOMM_SMART    0x42434F4D  // 交行智慧网盾配置文件里面的customer id（与cos一致）
#define CUSTOMER_ID_BOCOMM_2G       0x424F4332  // 交行二代key配置文件里面的customer id（与cos不一致）
#define CUSTOMER_ID_BOCOMM_EN       0x4A545951  // 交行银企直连key配置文件里面的customer id（与cos不一致）
#define CUSTOMER_ID_HRXJ	0x4852584A
#define CUSTOMER_ID_CMB     0x20434D42

#define CUSTOMER_ID_CGB     0x00434742          
//////////////////////////////////////////////////////////////////////////
// Token层配置
//////////////////////////////////////////////////////////////////////////

#define MAX_PIN_LENGTH				32

typedef enum EnBusinessSnType
{
	BUSINESS_SN_TYPE_CHIPSN		= 0,
	BUSINESS_SN_TYPE_MEDIAID	= 1,
}EnBusinessSnType;

// XXX_MODE_DEV的特性:
//	(1) 是给国密接口的设备认证密钥使用，SKF_DevAuth、SKF_ChangeDevAuthKey
//	(2) 这两个接口中，认证的时候，客户是调用 SKF_GenRandom 先获取16字节随机数，然后外部加密随机数形成认证密文，再调用SKF_DevAuth，所以在SlotApi接口中做认证的时候不能取随机数
//	(3) SKF_ChangeDevAuthKey接口中，没有旧密钥，输入的是明文新密钥，或者是新密钥密文+MAC值，通过长度来判断
//	(4) 内部不需要对输入的数据做转换，认证过程中不需要获取随机数，修改过程中特殊处理
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
	PERMISSION_PIN_NONEED			= 0, // 不需要验证PIN
	PERMISSION_PIN_NEED_CACHEPIN	= 1, // 需要验证PIN，可以使用缓存PIN
	PERMISSION_PIN_NEED_NO_CACHEPIN	= 2, // 需要验证PIN，不可使用缓存PIN
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

	ESBOOL				m_bPinModeValid; // 为TRUE，后面3种模式才有效
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
	DISPLAY_SIGN_MSG_TYPE_NONE	= 0xFF, // 不支持2代签名（1代KEY）
}En2GSignMsgType;

typedef enum En2GSignRsaMode
{
	DISPLAY_SIGN_RSA_MODE_ICBC			= 0, // 不限散列算法，HASH两次
	DISPLAY_SIGN_RSA_MODE_SHA1_STD		= 1, // 仅限SHA1，二代签名采用标准算法
	DISPLAY_SIGN_RSA_MODE_SHA256_STD	= 2, // 仅限SHA256，二代签名采用标准算法
	DISPLAY_SIGN_RSA_MODE_ANY_0009		= 3, // 不限散列算法，二代签名采用0009补足
}En2GSignRsaMode;

typedef enum En2GSignSm2Mode
{
	DISPLAY_SIGN_SM2_MODE_STD			= 0, // 仅限SM3，签名一次
	DISPLAY_SIGN_SM2_MODE_CMBC			= 1, // 仅限SM3/SHA256，签名两次
}En2GSignSm2Mode;

typedef struct BlkTokenSign2GConfigTag
{
	En2GSignMsgType	m_enMsgType;		// 签名消息格式
	En2GSignRsaMode	m_enSignRsaMode;	// RSA签名模式
	En2GSignSm2Mode	m_enSignSm2Mode;    // SM2签名模式
}BlkTokenSign2GConfig;

typedef struct BlkTimeoutCfgItemTag
{
	u4		m_u4TimeoutSeconds; // 默认超时时间，以秒为单位
	ESBOOL	m_bChangeable;		// 如果可修改，则需要通过其他方式（如发指令）获取最新的超时时间
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
	ESBOOL					m_bNoUi;					 // CFCA预制和一代KEY，此项配置为ESTRUE
	ESBOOL					m_bEndUiWhenDevRemoved;		 // 拔掉Key之后，界面是否结束
	wchar_t					m_szUiModulePath[260];
	EnBusinessSnType		m_enBusinessSnType;
	ESBOOL					m_bSupportChangePinAtFormat; // 在格式化指令中包含修改PIN指令，这样可以减少一次按键--目前仅工行高版本COS支持
	ESBOOL					m_bAlwaysGenSignKey;		 // GenKey无论签名还是交换，总是生成签名密钥对，这样私钥才可以执行解密操作
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
// CSP层配置
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
	DEL_CNT_MODE_NORMAL				= 0, // 无需特殊处理
	DEL_CNT_MODE_DEL_EMPTY_CNT		= 1, // 删除空容器
	DEL_CNT_MODE_DEL_INVALID_CNT	= 2, // 删除无效容器，没有证书的容器
    DEL_CNT_MODE_FULL_OR_SAME_NAME  = 3  // 容器名字相同或者容器数量已满时才删除容器，在先建立两个容器在下载证书的场景下，模式1、2会误删第一个容器
}EnDelCntMode;

typedef enum EnWriteCertMode
{
	WRITE_CERT_MODE_NORMAL				= 0, // 无需特殊处理
	WRITE_CERT_MODE_DEL_SAME_DN_CERT	= 1, // 删除同DN的证书
	WRITE_CERT_MODE_DEL_OTHER_CERT		= 2, // 删除其他证书
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
	EnDelCntMode		m_enDeleteCntMode; // 0: 默认，1：删除空容器，2：删除无证书容器
	EnWriteCertMode		m_enWriteCertMode;
	EnImportKeyPairMode m_enImportKeyPairMode;
	BlkGmAlgConfig		m_blkGmAlgCfg;
}BlkCspConfig;

//////////////////////////////////////////////////////////////////////////
// UI层配置
//////////////////////////////////////////////////////////////////////////

typedef struct BlkUiPinLimitationTag
{
	u4		m_u4MinLen; // PIN最小长度
	u4		m_u4MaxLen; // PIN最大长度
	u4		m_u4SpecialCharSupportType; // 除字母与数字以外的字符都被看成特殊字符, 0x00：支持特殊字符， 0x01：不支持特殊字符
	// checkMethod，弱PIN检查方式，我们可以定义几种弱PIN检测方式，但具体如何定义则需要讨论。
	// 弱PIN检查考虑的因素有：
	// 1）是否全数字或者全字母，此因素占第一个比特位
	// 2）是否包含连续字符，如000000,123456,897654,abcdef都属于包含连续字符的密码，此因素占第2个比特位
	// 3）是否是普遍使用的密码，如password，此因素占第3个比特位
	// 4）是否是键盘邻近字符，如1q2w3e4r，此因素占第4个比特位
	u4		m_u4WeakPinCheckMethod; 
	// 弱密码支持模式。0:不支持，1：支持但提出警告，2：支持 
	u4		m_u4WeakPinSupportType;
}BlkUiPinLimitation;

// UI基本配置
typedef struct BlkCfgUiGeneralTag
{
	u4						m_u4Mode;			// 0x01: 动态库内弹出界面, 0x02: 加载外部动态弹出界面, 0x03: 使用跨进程通讯方式弹出界面（目前只支持这种）
	u4						m_u4BkgndColor;		// 背景色
	BlkUiPinLimitation		m_blkPinLimitation; // PIN限制（合法性检查以及输入限制时有用）
	BlkCfgString			m_blkUiPath;		// UI模块的路径，此配置指示使用跨进程通讯方式时exe文件的路径
}BlkCfgUiGeneral;


//////////////////////////////////////////////////////////////////////////
// 界面元素定义
//////////////////////////////////////////////////////////////////////////

typedef struct BlkCfgUiChangeLabelTag
{
	BlkCfgMainFrame		m_blkMainFrame;
	BlkCfgPicture		m_blkPictureLogo;			// LOGO
	BlkCfgStatic		m_blkStaticNewLabel;		// Label输入位置提示
	BlkCfgEdit			m_blkEditLabel;				// Label输入框
	BlkCfgStatic		m_blkStaticInputPin;		// PIN输入位置提示
	BlkCfgEdit			m_blkEditInputPin;			// PIN输入框
	BlkCfgButton		m_blkButtonSoftKeyboard;	// 软键盘BUTTON，点击即实现展开收起软键盘
	BlkCfgStatic		m_blkStaticPinNumTip;		// PIN输入字符数提示
	BlkCfgButton		m_blkButtonOk;				// 确认按钮
	BlkCfgButton		m_blkButtonCancel;			// 取消按钮
	BlkCfgSoftkeyBoard	m_blkSoftkeyBoard;			// 软键盘
}BlkCfgUiChangeLabel;

// 对话框元素
typedef struct BlkDialogTag
{
	char		m_szTitle[MAX_WINDOW_TITLE_LEN];
	BlkCfgSize		m_blkSize;
	BlkCfgSize		m_blkSizeWithKbd;
}BlkDialog;

// 贴图元素
typedef struct BlkCtrlPictureTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN];
	char		m_szImgPath[MAX_PATH_LEN];
	BlkCfgPosition	m_blkPosition;
}BlkCtrlPicture;

// 静态文本元素
typedef struct BlkCtrlStaticTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN]; // 名称
	char		m_szText[MAX_STATIC_TEXT_LEN]; // 文字
	BlkCfgPosition	m_blkPosition; // 位置
}BlkCtrlStatic;

// 胖静态文本元素，比BlkCtrlStatic能容纳更多的文本
typedef struct BlkCtrlFatStaticTag
{
	char		m_szName[MAX_WINDOW_NAME_LEN]; // 名称
	char		m_szText[MAX_FAT_STATIC_TEXT_LEN]; // 文字
	BlkCfgPosition	m_blkPosition; // 位置
}BlkCtrlFatStatic;

// 编辑框元素
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

// 按钮元素
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
	BlkDialog			m_blkDlgMainFrame; // 主窗口

	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO

	BlkCtrlStatic		m_blkCtrlPinInputPosTip; // PIN输入位置提示
	BlkCtrlEdit			m_blkCtrlEditPin; // PIN输入框
	BlkCtrlButton		m_blkCtrIcoBtnKbd; // 软键盘图标，点击即实现展开收起软键盘
	BlkCtrlStatic		m_blkCtrlPinInputCharNumTip; // PIN输入字符数提示

	BlkCtrlButton		m_blkCtrBtnOk; // 确认按钮
	BlkCtrlButton		m_blkCtrBtnCancel; // 取消按钮
	BlkCtrlKeyboard		m_blkCtrlSoftKbd; // 软键盘
}BlkUiVerifyPinConfig;

typedef struct BlkUiChangePinConfigTag
{
	BlkDialog			m_blkDlgMainFrame; // 主窗口
	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO

	BlkCtrlStatic		m_blkCtrlOldPinInputPosTip; // 旧PIN输入位置提示
	BlkCtrlEdit			m_blkCtrlEditOldPin; // 旧PIN输入框
	BlkCtrlButton		m_blkCtrIcoBtnKbdOldPin; // 旧PIN输入软键盘图标，点击即实现展开收起软键盘
	BlkCtrlStatic		m_blkCtrlOldPinInputCharNumTip; // 旧PIN输入字符数提示

	BlkCtrlStatic		m_blkCtrlNewPinInputPosTip; // 新PIN输入位置提示
	BlkCtrlEdit			m_blkCtrlEditNewPin; // 新PIN输入框
	BlkCtrlButton		m_blkCtrIcoBtnKbdNewPin; // 新PIN输入软键盘图标，点击即实现展开收起软键盘
	BlkCtrlStatic		m_blkCtrlNewPinInputCharNumTip; // 新PIN输入字符数提示

	BlkCtrlStatic		m_blkCtrlNewConfirmPinInputPosTip; // 新PIN确认输入位置提示
	BlkCtrlEdit			m_blkCtrlEditNewConfirmPin; // 新PIN确认输入框
	BlkCtrlButton		m_blkCtrIcoBtnKbdNewConfirmPin; // 新PIN确认输入软键盘图标，点击即实现展开收起软键盘
	BlkCtrlStatic		m_blkCtrlNewConfirmPinInputCharNumTip; // 新PIN确认输入字符数提示

	BlkCtrlButton		m_blkCtrBtnOk; // 确认按钮
	BlkCtrlButton		m_blkCtrBtnCancel; // 取消按钮
	BlkCtrlKeyboard		m_blkCtrlSoftKbd; // 软键盘
}BlkUiChangePinConfig;

// typedef struct BlkUiChangeLabelConfigTag
// {
// 	BlkDialog			m_blkDlgMainFrame; // 主窗口
// 
// 	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO
// 
// 	BlkCtrlStatic		m_blkCtrlLabelInputPosTip; // Label输入位置提示
// 	BlkCtrlEdit			m_blkCtrlEditLabel; // Label输入框
// 
// 	BlkCtrlStatic		m_blkCtrlPinInputPosTip; // PIN输入位置提示
// 	BlkCtrlEdit			m_blkCtrlEditPin; // PIN输入框
// 	BlkCtrlButton		m_blkCtrIcoBtnKbd; // 软键盘图标，点击即实现展开收起软键盘
// 	BlkCtrlStatic		m_blkCtrlPinInputCharNumTip; // PIN输入字符数提示
// 
// 	BlkCtrlButton		m_blkCtrBtnOk; // 确认按钮
// 	BlkCtrlButton		m_blkCtrBtnCancel; // 取消按钮
// 	BlkCtrlKeyboard		m_blkCtrlSoftKbd; // 软键盘
// }BlkUiChangeLabelConfig;

typedef struct BlkUiCommonConfirmTag
{
	BlkDialog			m_blkDlgMainFrame; // 主窗口

	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO
	BlkCtrlPicture		m_blkCtrlPicIllustration; // 按键演示
	BlkCtrlStatic		m_blkCtrlWarning; // 经过信息
	BlkCtrlStatic		m_blkCtrlDetailTip; // 提示详情
	BlkCtrlStatic		m_blkCtrlCountDownTip;// 倒计时提示
}BlkUiCommonConfirm;

typedef struct BlkUiSign2GConfirmTag
{
	BlkDialog			m_blkDlgMainFrame; // 主窗口

	BlkCtrlPicture		m_blkCtrlPicLogo; // LOGO
	BlkCtrlPicture		m_blkCtrlPicIllustration; // 按键演示
	BlkCtrlStatic		m_blkCtrlWarning; // 警告信息
	BlkCtrlStatic		m_blkCtrlTip; // 简单提示
	BlkCtrlStatic		m_blkCtrlDetailTip; // 签名详情显示
	BlkCtrlStatic		m_blkCtrlCountDownTip; // 倒计时提示
}BlkUiSign2GConfirm;

typedef struct BlkUiConfirmTag
{	
	BlkUiCommonConfirm	m_blkUiCommonConfirmCfg; // 普通操作确认提示框配置
	BlkUiSign2GConfirm	m_blkUiSign2GConfirmCfg; // 二代签名操作确认提示框配置
}BlkUiConfirm;

typedef struct BlkUiConfigTag
{
	BlkCfgUiGeneral			m_blkCfgUiGeneral;		// 基本配置
	BlkCfgUiChangeLabel		m_blkCfgUiChangeLabel;	// 修改Label界面配置
// 	BlkUiVerifyPinConfig	m_blkUiVerifyPinCfg; // 验证PIN界面配置
// 	BlkUiChangePinConfig	m_blkUiChangePinCfg; // 修改PIN界面配置
// 	BlkUiConfirm			m_blkUiConfirmCfg; // 确认提示框界面配置，包含一般的确认提示框以及二代签名确认提示框
	u1*						m_pu1AllocData;
}BlkUiConfig;

typedef enum EN_MAN_TOOL_STYLE
{
	MAN_TOOL_STYLE_UNITIALIZED,
	MAN_TOOL_STYLE_ONE, // 样式1，工行样式
	MAN_TOOL_STYLE_TWO, // 样式2，中行样式
	MAN_TOOL_STYLE_MAX_VALUE,
}EN_MAN_TOOL_STYLE;

// 使用者类型
typedef enum EN_MAN_TOOL_USER_TYPE
{
	MAN_TOOL_USER_TYPE_UNITIALIZED,
	MAN_TOOL_USER_TYPE_MANAGER, // 管理员使用
	MAN_TOOL_USER_TYPE_NORMAL, // 普通用户使用
	MAN_TOOL_USER_TYPE_MAX_VALUE,
}EN_MAN_TOOL_USER_TYPE;

typedef struct BlkManToolGeneralConfigTag
{
	EN_MAN_TOOL_STYLE		m_enStyle;
	EN_MAN_TOOL_USER_TYPE	m_enUserType;
}BlkManToolGeneralConfig;

// 对用户类似挑剔的按钮。之所以说它挑剔，是因为它是根据用户类型决定隐藏还是显示的。
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
	BlkDialog			m_blkDlgMainFrame; // 主窗口
	BlkCtrlStatic		m_blkCtrlSelectKeyTip; // 选择USBKey位置提示
	BlkCtrlCbxUSBKey	m_blkCtrlCbxUKey; // USBKey列表（组合框）
	BlkCtrlStatic		m_blkCtrlSelectLangTip; // 选择语言位置提示
	BlkCtrlCbxLang		m_blkCtrlLang;// 可选语言列表（组合框）
	BlkCtrlTabManTool	m_blkCtrlTab;			

}BlkManToolStyleOneConfig;

typedef struct BlkCtrlUSBKeyTreeViewTag
{
	BlkCfgPosition			m_blkPosition;
}BlkCtrlUSBKeyTreeView;

typedef struct BlkManToolStyleTwoConfigTag
{
	BlkDialog				m_blkDlgMainFrame; // 主窗口
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