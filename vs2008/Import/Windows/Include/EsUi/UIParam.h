///////////////////////////////////////////////////////////
//  UIParam.h
//  Implementation of the Class UIParam
//  Created on:      27-十月-2012 21:33:17
//  Original author: Simon
///////////////////////////////////////////////////////////

#if !defined(EA_864B3AB2_5E94_48c4_A390_0CBDEA639E69__INCLUDED_)
#define EA_864B3AB2_5E94_48c4_A390_0CBDEA639E69__INCLUDED_

// 本头文件定义的各种数据类型可以被客户端类和服务器类同时使用，也可以也客户代码使用。
// 也就是说，这些数据类型是开放的。
#include <EsTypeDef.h>

// 按固定的字节数（一字节）对齐，这点很重要，特别是在32位64位交叉编程环境下
#pragma pack(push,1)

// UI类型
typedef enum EnUIType
{
	UI_TYPE_UNKONOW		= 0,	// 无法识别的类型
	UI_TYPE_PROMPT_MSG,			// 弹出普通的消息
	UI_TYPE_PROMPT_CONFIRM_TIP, // 弹出确认框
	UI_TYPE_GET_PIN,			// 获取PIN信息界面
	UI_TYPE_GET_MODIFY_PIN,		// 获取修改PIN信息界面
	UI_TYPE_CHANGE_LABEL,		// 修改标签
	UI_TYPE_SELECT_KEY,			// 多Key选择框
	UI_TYPE_SET_LANG,			// 选择语言
	UI_TYPE_GET_PIN_CONFIRM,
	UI_TYPE_UPDATE,				// 更新数据
	UI_TYPE_TERMINATE,			// 结束界面
	UI_TYPE_GET_STATUS,		// 获取交互状态
	UI_TYPE_GET_PIN_CONFIRM_ASYNC, // 异步的方式获取PIN（有确认输入）
	UI_TYPE_UNBLOCK_PIN,         // 解锁Pin码
	UI_TYPE_GET_FIRST_MODIFY_PIN,  // 初始化之后第一次修改密码
	UI_TYPE_GET_PIN_ASYNC,	// 异步的方式获取PIN
	UI_TYPE_CHANGE_LABEL_ASYNC, 
	UI_TYPE_GET_MODIFY_PIN_ASYNC,
	UI_TYPE_SELECT_KEY_ASYNC,
	UI_TYPE_UNBLOCK_PIN_ASYNC,
	UI_TYPE_GET_FIRST_MODIFY_PIN_ASYNC,
    UI_TYPE_PROMPT_MSG_ASYNC
}EnUIType;

// UI交互结果
typedef enum EnInteractionResult
{
	INTERACTION_RESULT_NOT_PROCESSED		= 0,	// 未经处理
	INTERACTION_RESULT_FAILED,						// 处理失败
	INTERACTION_RESULT_FINISHED,					// 处理完成
	INTERACTION_RESULT_PREPARED,					// 已经准备好	
	INTERACTION_RESULT_PROCESSING,					// UI请求已经成功提交，但UI交互尚未完成
	INTERACTION_RESULT_USER_CANCELED,				// 用户取消
	INTERACTION_RESULT_TIMEOUT,						// 操作已经超时
	INTERACTION_RESULT_INVALID_INTERACTION			// 无效的交互会话
}EnInteractionResult;
// UI结构类型定义

// 确认界面的类型
typedef enum EnComfirmTipType
{
	CONFIRM_TIP_TYPE_UNKNOWN	= 0,	// 不可能的值
	CONFIRM_TIP_TYPE_2G_SIGN,			// 二代签名
	CONFIRM_TIP_TYPE_INITIALIZE_KEY,	// 初始化
	CONFIRM_TIP_TYPE_VEFIFY_PIN,		// 验证PIN
	CONFIRM_TIP_TYPE_CHANGE_PIN,		// 修改PIN
	CONFIRM_TIP_TYPE_ERASE_CERT,		// 擦除证书
	CONFIRM_TIP_TYPE_UPDATE_PROTECT_KEY, // 更新保护密钥
	CONFIRM_TIP_TYPE_COMMON, // 普通确认框
	CONFIRM_TIP_TYPE_CHANGE_PIN_WARNING, // 剩余特定重试次数时修改PIN的特殊警告信息
	CONFIRM_TIP_TYPE_VERIFY_PIN_ON_KEY,	// 在Key上验证密码
	CONFIRM_TIP_TYPE_CHANGE_PIN_ON_KEY,	// 在Key上修改密码
	COMFIRM_TIP_TYPE_UNBLOCK_PIN,
	CONFIRM_TIP_TYPE_GEN_KEY,		// 生成密钥对
	CONFIRM_TIP_TYPE_CHANGE_SECURITY_SETTING, // 修改安全设置
}EnComfirmTipType;

// 获取验证PIN信息的数据结构
typedef struct tagBlkPIN
{
	// u4MinPinLen，u4MaxPinLen为输入数据
	u4 u4MinPinLen; // PIN码最小长度
	u4 u4MaxPinLen; // PIN码最大长度
	// 32个字符作为PIN码从目前来看绰绰有余
	// 为了安全，这里存放的最好是摘要值
	u1 pu1PIN[33]; 
	
}BlkPIN;

// 修改标签
// 获取验证PIN信息的数据结构
typedef struct tagBlkModLabel
{
	// u4MinPinLen，u4MaxPinLen为输入数据
	u4 u4MinPinLen; // PIN码最小长度
	u4 u4MaxPinLen; // PIN码最大长度
	u4 u4MinLabelLen; // 名字最小长度
	u4 u4MaxLabelLen; // 名字最大长度
	// 32个字符作为PIN码从目前来看绰绰有余
	// 为了安全，这里存放的最好是摘要值
	char szLabel[65];
	u1 pu1PIN[33]; 
	
}BlkModLabel;

// 获取修改PIN信息的数据结构
typedef struct tagBlkModPIN
{
	u4 u4PinType; //管理员或者用户
	// u4MinPinLen，u4MaxPinLen为输入数据
	u4 u4MinPinLen; // PIN码最小长度
	u4 u4MaxPinLen; // PIN码最大长度
	// 为了安全，这里存放的最好是摘要值
	u1									pu1OrgPIN[33];
	u1									pu1NewPIN[33];
}BlkModPIN;

// 获取修改PIN信息的数据结构
typedef struct tagBlkUnblockPIN
{
	// u4MinPinLen，u4MaxPinLen为输入数据
	u4 u4MinPinLen; // PIN码最小长度
	u4 u4MaxPinLen; // PIN码最大长度
	// 为了安全，这里存放的最好是摘要值
	u1									pu1SoPIN[33];
	u1									pu1NewUserPIN[33];
}BlkUnblockPIN;
// 确认框

// 提示消息
typedef enum CommonMsgReturnCode
{
	CMRC_NONE = 0,
	CMRC_YES,
	CMRC_NO
}CommonMsgReturnCode;

typedef struct tagBlkCommonMsg
{
	u4									u4MsgId;		 // 见 EsError.h
	u4									u4MsgParam; // 消息参数
	u1									pu1MsgExtraParam[1024]; 
	u4									u4MsgExtraParamLen;
	CommonMsgReturnCode	enRetCode;
}BlkCommonMsg;

typedef struct tagBlkChangePinTipParam
{
	u4									u4RemainedRetryTimes;
}BlkChangePinTipParam;

typedef struct tagBlkVerifyPinTipParam
{
	u4									u4RemainedRetryTimes;
}BlkVerifyPinTipParam;

typedef struct tagBlkUnblockPinTipParam
{
	u4									u4RemainedRetryTimes;
}BlkUnblockPinTipParam;


// 二代签名确认提示框参数
typedef struct tagBlk2GSignConfirmParam
{
	ESBOOL								bShowDetail; // 是否显示交易明细
	// 警告信息
	char								szWarning[1024];

	// 交易数据显示格式
	// 是否居中
	ESBOOL								bCenter;
	// 是否冒号对齐
	ESBOOL								bColonAligned;
	// 超时时间，在这个时间点，确认操作超时，确认框退出，取消事件被设置
	// 如果u4TimeOutTickCnt为0或者0xFFFFFFFF，表示不使用倒计时
	
	// 交易详情
	// szSignDetail符合一定的格式，被<B></B>修饰的数据表示要大写显示。示例：付款人姓名:明华公司\n<B>收款帐号:95588202000099999999</B>\n<B>总金额:100000.00RMB</B>
	char								szSignDataDetail[2048];
}Blk2GSignConfirmParam;

typedef struct tagBlkUpdateProtectKeyTipParam
{
	u4									u4RemainedRetryTimes;
}BlkUpdateProtectKeyTipParam;

typedef struct tagBlkConfirmTip
{
	EnComfirmTipType				enCTT;
	ESBOOL								bUserCanCloseUI; // 用户是否能够关闭UI
	u4											u4TimeOutTickCnt; 
	union Data
	{
		BlkChangePinTipParam			blkChgPinParam;
		BlkVerifyPinTipParam			blkVerPinParam;
		Blk2GSignConfirmParam			blk2GSignParam;
		BlkUpdateProtectKeyTipParam		blkUpdataPrtKeyParam;
		BlkUnblockPinTipParam			blkUnblockPinTipParam;
	}unDataIn;
    u4                                  u4KeyType;  // KEY类型，用于区分同一客户的多种KEY（确认框弹不同图片）
}BlkConfirmTip;

typedef struct tagBlkKeySelection
{
	char								szKeyList[2048];
	char								szSelectedKey[260];
}BlkKeySelection;

typedef struct tagBlkLangSetting
{
	u4 u4LangId;
}BlkLangSetting;

typedef struct tagBlkUIParamHeader
{
	EnUIType							enUiType;		// 用户指定
	u4									u4InteractionID; // 用户指定，一般为客户端提交UI请求的线程的ID

	// 以下字段不需用户指定，而为内部使用
	// 会话密钥种子,16个字节，最好为一个经常变化的随机数
	u1									pu13Des168SessionKeySeed[16];
	// 认证参数，该字段采用两个TLV的格式进行组织，整个字段最大长度为256字节
	// 其格式为 T（随机数类型）|L（随机数长度）|V（随机数）|
	// T（密文数据类型）|L（密文数据长度）|V（密文数据）
	// 由随机数按照一定算法生成解密密钥，可对紧接其后的密文数据进行解密
	u1									pu1AuthParam[256]; 
	ESBOOL								bDataEncrypted; //数据段是否已经加密
	u8							u8HWndParant; // 父窗口句柄
	// 标识父窗口是否已经阻塞，如果父窗口已经阻塞，那么服务器不再对父窗口进行阻塞
	ESBOOL								bParentBlocked; 
	ESBOOL								bShowOnVirtualDesktop; // 在虚拟桌面显示
}BlkUIParamHeader;

typedef union
{
	BlkCommonMsg						blkMsg;
	BlkConfirmTip						blkConfirmTip;
	BlkPIN								blkPIN;
	BlkModLabel							blkModLabel;
	BlkModPIN							blkModPIN;
	BlkUnblockPIN						blkUnblockPIN;
	BlkKeySelection						blkKeySelection;
	BlkLangSetting						blkLangSetting;
}UnUIData;

#define MAX_UI_PARAM_LEN (4*1024)
// UIParam 定长为4K
typedef struct tagBlkUIParam
{
	EnInteractionResult					enRes;
	BlkUIParamHeader					blkHeader;
	UnUIData							unUIData;
	// Data域一定要紧跟保留字节，虽然保留字节不具有实际意义，
	// 但在对Data域加密解密的过程中，保留字节起到了天然的补足作用
	u1								pbReserved[MAX_UI_PARAM_LEN-sizeof(EnInteractionResult)-sizeof(BlkUIParamHeader)-sizeof(UnUIData)-sizeof(u4)];
	u4								u4CheckSum;
}BlkUIParam;


#pragma pack(pop)

#endif // !defined(EA_864B3AB2_5E94_48c4_A390_0CBDEA639E69__INCLUDED_)
