///////////////////////////////////////////////////////////
//  UIParam.h
//  Implementation of the Class UIParam
//  Created on:      27-ʮ��-2012 21:33:17
//  Original author: Simon
///////////////////////////////////////////////////////////

#if !defined(EA_864B3AB2_5E94_48c4_A390_0CBDEA639E69__INCLUDED_)
#define EA_864B3AB2_5E94_48c4_A390_0CBDEA639E69__INCLUDED_

// ��ͷ�ļ�����ĸ����������Ϳ��Ա��ͻ�����ͷ�������ͬʱʹ�ã�Ҳ����Ҳ�ͻ�����ʹ�á�
// Ҳ����˵����Щ���������ǿ��ŵġ�
#include <EsTypeDef.h>

// ���̶����ֽ�����һ�ֽڣ����룬������Ҫ���ر�����32λ64λ�����̻�����
#pragma pack(push,1)

// UI����
typedef enum EnUIType
{
	UI_TYPE_UNKONOW		= 0,	// �޷�ʶ�������
	UI_TYPE_PROMPT_MSG,			// ������ͨ����Ϣ
	UI_TYPE_PROMPT_CONFIRM_TIP, // ����ȷ�Ͽ�
	UI_TYPE_GET_PIN,			// ��ȡPIN��Ϣ����
	UI_TYPE_GET_MODIFY_PIN,		// ��ȡ�޸�PIN��Ϣ����
	UI_TYPE_CHANGE_LABEL,		// �޸ı�ǩ
	UI_TYPE_SELECT_KEY,			// ��Keyѡ���
	UI_TYPE_SET_LANG,			// ѡ������
	UI_TYPE_GET_PIN_CONFIRM,
	UI_TYPE_UPDATE,				// ��������
	UI_TYPE_TERMINATE,			// ��������
	UI_TYPE_GET_STATUS,		// ��ȡ����״̬
	UI_TYPE_GET_PIN_CONFIRM_ASYNC, // �첽�ķ�ʽ��ȡPIN����ȷ�����룩
	UI_TYPE_UNBLOCK_PIN,         // ����Pin��
	UI_TYPE_GET_FIRST_MODIFY_PIN,  // ��ʼ��֮���һ���޸�����
	UI_TYPE_GET_PIN_ASYNC,	// �첽�ķ�ʽ��ȡPIN
	UI_TYPE_CHANGE_LABEL_ASYNC, 
	UI_TYPE_GET_MODIFY_PIN_ASYNC,
	UI_TYPE_SELECT_KEY_ASYNC,
	UI_TYPE_UNBLOCK_PIN_ASYNC,
	UI_TYPE_GET_FIRST_MODIFY_PIN_ASYNC,
    UI_TYPE_PROMPT_MSG_ASYNC
}EnUIType;

// UI�������
typedef enum EnInteractionResult
{
	INTERACTION_RESULT_NOT_PROCESSED		= 0,	// δ������
	INTERACTION_RESULT_FAILED,						// ����ʧ��
	INTERACTION_RESULT_FINISHED,					// �������
	INTERACTION_RESULT_PREPARED,					// �Ѿ�׼����	
	INTERACTION_RESULT_PROCESSING,					// UI�����Ѿ��ɹ��ύ����UI������δ���
	INTERACTION_RESULT_USER_CANCELED,				// �û�ȡ��
	INTERACTION_RESULT_TIMEOUT,						// �����Ѿ���ʱ
	INTERACTION_RESULT_INVALID_INTERACTION			// ��Ч�Ľ����Ự
}EnInteractionResult;
// UI�ṹ���Ͷ���

// ȷ�Ͻ��������
typedef enum EnComfirmTipType
{
	CONFIRM_TIP_TYPE_UNKNOWN	= 0,	// �����ܵ�ֵ
	CONFIRM_TIP_TYPE_2G_SIGN,			// ����ǩ��
	CONFIRM_TIP_TYPE_INITIALIZE_KEY,	// ��ʼ��
	CONFIRM_TIP_TYPE_VEFIFY_PIN,		// ��֤PIN
	CONFIRM_TIP_TYPE_CHANGE_PIN,		// �޸�PIN
	CONFIRM_TIP_TYPE_ERASE_CERT,		// ����֤��
	CONFIRM_TIP_TYPE_UPDATE_PROTECT_KEY, // ���±�����Կ
	CONFIRM_TIP_TYPE_COMMON, // ��ͨȷ�Ͽ�
	CONFIRM_TIP_TYPE_CHANGE_PIN_WARNING, // ʣ���ض����Դ���ʱ�޸�PIN�����⾯����Ϣ
	CONFIRM_TIP_TYPE_VERIFY_PIN_ON_KEY,	// ��Key����֤����
	CONFIRM_TIP_TYPE_CHANGE_PIN_ON_KEY,	// ��Key���޸�����
	COMFIRM_TIP_TYPE_UNBLOCK_PIN,
	CONFIRM_TIP_TYPE_GEN_KEY,		// ������Կ��
	CONFIRM_TIP_TYPE_CHANGE_SECURITY_SETTING, // �޸İ�ȫ����
}EnComfirmTipType;

// ��ȡ��֤PIN��Ϣ�����ݽṹ
typedef struct tagBlkPIN
{
	// u4MinPinLen��u4MaxPinLenΪ��������
	u4 u4MinPinLen; // PIN����С����
	u4 u4MaxPinLen; // PIN����󳤶�
	// 32���ַ���ΪPIN���Ŀǰ�����´�����
	// Ϊ�˰�ȫ�������ŵ������ժҪֵ
	u1 pu1PIN[33]; 
	
}BlkPIN;

// �޸ı�ǩ
// ��ȡ��֤PIN��Ϣ�����ݽṹ
typedef struct tagBlkModLabel
{
	// u4MinPinLen��u4MaxPinLenΪ��������
	u4 u4MinPinLen; // PIN����С����
	u4 u4MaxPinLen; // PIN����󳤶�
	u4 u4MinLabelLen; // ������С����
	u4 u4MaxLabelLen; // ������󳤶�
	// 32���ַ���ΪPIN���Ŀǰ�����´�����
	// Ϊ�˰�ȫ�������ŵ������ժҪֵ
	char szLabel[65];
	u1 pu1PIN[33]; 
	
}BlkModLabel;

// ��ȡ�޸�PIN��Ϣ�����ݽṹ
typedef struct tagBlkModPIN
{
	u4 u4PinType; //����Ա�����û�
	// u4MinPinLen��u4MaxPinLenΪ��������
	u4 u4MinPinLen; // PIN����С����
	u4 u4MaxPinLen; // PIN����󳤶�
	// Ϊ�˰�ȫ�������ŵ������ժҪֵ
	u1									pu1OrgPIN[33];
	u1									pu1NewPIN[33];
}BlkModPIN;

// ��ȡ�޸�PIN��Ϣ�����ݽṹ
typedef struct tagBlkUnblockPIN
{
	// u4MinPinLen��u4MaxPinLenΪ��������
	u4 u4MinPinLen; // PIN����С����
	u4 u4MaxPinLen; // PIN����󳤶�
	// Ϊ�˰�ȫ�������ŵ������ժҪֵ
	u1									pu1SoPIN[33];
	u1									pu1NewUserPIN[33];
}BlkUnblockPIN;
// ȷ�Ͽ�

// ��ʾ��Ϣ
typedef enum CommonMsgReturnCode
{
	CMRC_NONE = 0,
	CMRC_YES,
	CMRC_NO
}CommonMsgReturnCode;

typedef struct tagBlkCommonMsg
{
	u4									u4MsgId;		 // �� EsError.h
	u4									u4MsgParam; // ��Ϣ����
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


// ����ǩ��ȷ����ʾ�����
typedef struct tagBlk2GSignConfirmParam
{
	ESBOOL								bShowDetail; // �Ƿ���ʾ������ϸ
	// ������Ϣ
	char								szWarning[1024];

	// ����������ʾ��ʽ
	// �Ƿ����
	ESBOOL								bCenter;
	// �Ƿ�ð�Ŷ���
	ESBOOL								bColonAligned;
	// ��ʱʱ�䣬�����ʱ��㣬ȷ�ϲ�����ʱ��ȷ�Ͽ��˳���ȡ���¼�������
	// ���u4TimeOutTickCntΪ0����0xFFFFFFFF����ʾ��ʹ�õ���ʱ
	
	// ��������
	// szSignDetail����һ���ĸ�ʽ����<B></B>���ε����ݱ�ʾҪ��д��ʾ��ʾ��������������:������˾\n<B>�տ��ʺ�:95588202000099999999</B>\n<B>�ܽ��:100000.00RMB</B>
	char								szSignDataDetail[2048];
}Blk2GSignConfirmParam;

typedef struct tagBlkUpdateProtectKeyTipParam
{
	u4									u4RemainedRetryTimes;
}BlkUpdateProtectKeyTipParam;

typedef struct tagBlkConfirmTip
{
	EnComfirmTipType				enCTT;
	ESBOOL								bUserCanCloseUI; // �û��Ƿ��ܹ��ر�UI
	u4											u4TimeOutTickCnt; 
	union Data
	{
		BlkChangePinTipParam			blkChgPinParam;
		BlkVerifyPinTipParam			blkVerPinParam;
		Blk2GSignConfirmParam			blk2GSignParam;
		BlkUpdateProtectKeyTipParam		blkUpdataPrtKeyParam;
		BlkUnblockPinTipParam			blkUnblockPinTipParam;
	}unDataIn;
    u4                                  u4KeyType;  // KEY���ͣ���������ͬһ�ͻ��Ķ���KEY��ȷ�Ͽ򵯲�ͬͼƬ��
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
	EnUIType							enUiType;		// �û�ָ��
	u4									u4InteractionID; // �û�ָ����һ��Ϊ�ͻ����ύUI������̵߳�ID

	// �����ֶβ����û�ָ������Ϊ�ڲ�ʹ��
	// �Ự��Կ����,16���ֽڣ����Ϊһ�������仯�������
	u1									pu13Des168SessionKeySeed[16];
	// ��֤���������ֶβ�������TLV�ĸ�ʽ������֯�������ֶ���󳤶�Ϊ256�ֽ�
	// ���ʽΪ T����������ͣ�|L����������ȣ�|V���������|
	// T�������������ͣ�|L���������ݳ��ȣ�|V���������ݣ�
	// �����������һ���㷨���ɽ�����Կ���ɶԽ��������������ݽ��н���
	u1									pu1AuthParam[256]; 
	ESBOOL								bDataEncrypted; //���ݶ��Ƿ��Ѿ�����
	u8							u8HWndParant; // �����ھ��
	// ��ʶ�������Ƿ��Ѿ�����������������Ѿ���������ô���������ٶԸ����ڽ�������
	ESBOOL								bParentBlocked; 
	ESBOOL								bShowOnVirtualDesktop; // ������������ʾ
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
// UIParam ����Ϊ4K
typedef struct tagBlkUIParam
{
	EnInteractionResult					enRes;
	BlkUIParamHeader					blkHeader;
	UnUIData							unUIData;
	// Data��һ��Ҫ���������ֽڣ���Ȼ�����ֽڲ�����ʵ�����壬
	// ���ڶ�Data����ܽ��ܵĹ����У������ֽ�������Ȼ�Ĳ�������
	u1								pbReserved[MAX_UI_PARAM_LEN-sizeof(EnInteractionResult)-sizeof(BlkUIParamHeader)-sizeof(UnUIData)-sizeof(u4)];
	u4								u4CheckSum;
}BlkUIParam;


#pragma pack(pop)

#endif // !defined(EA_864B3AB2_5E94_48c4_A390_0CBDEA639E69__INCLUDED_)
