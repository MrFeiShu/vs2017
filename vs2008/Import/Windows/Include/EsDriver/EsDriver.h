#ifndef _ES_DRIVER_H_
#define _ES_DRIVER_H_

#define MAX_VIDPID_NUM				32
#define MAX_READER_NUM				32
#define MAX_READER_NAME_LEN			64

#define DEV_TYPE_HID					0x0001
#define DEV_TYPE_PCSC					0x0002
#define DEV_TYPE_SCSI					0x0004
#define DEV_TYPE_AUDIO					0x0008
#define DEV_TYPE_BLUE_TOOTH				0x0010
#define DEV_TYPE_IDOCK_PROTOCAL			0x0020
#define DEV_TYPE_APDU                   0x0040

typedef struct BlkVidPidTag
{
	u4		m_u4Count;
	u4		m_pu4VidPid[MAX_VIDPID_NUM];
}BlkVidPid;

typedef struct BlkReaderFeatureTag
{
	u4		m_u4Count;
	char	m_szName[MAX_READER_NUM][MAX_READER_NAME_LEN];
}BlkReaderFeature;

typedef struct BlkDriverConfigTag
{
	u4					m_u4CustomerId;
	char				m_pszPortBindFilePath[0x40];	// �˿ڰ������ļ�·�����ǿ�����ݴ��ļ��е���Ϣ������˿ںţ�Ϊ�������Driver���ڲ��ķ��䷽ʽ
	u4					m_u4DevTypeSupportFlag;			// DEV_TYPE_XXX
	BlkVidPid			m_blkVidPidInclude;             // �����֧��ͨ���FFFF��
	BlkVidPid			m_blkVidPidExclude;             // �ų��֧��ͨ���FFFF��
	BlkReaderFeature	m_blkReaderFeature;
}BlkDriverConfig;

#define DRV_LIST_ONLY_EXIST     0x01
#define DRV_LIST_ALL_SUPPORT    0x00

// 0xE06190XX ��ʾָ���ִ����Ҫ�û�����ȷ�ϻ���Ҫ�ȴ�Key���в�����XX��ʾ��ʾ������
#define DRV_NEED_PRESS_KEY			0xE0619000

#define	PROMPT_VERIFY_PIN_ERROR		(DRV_NEED_PRESS_KEY + 0x90)
#define	PROMPT_CHANGE_PIN_ERROR		(DRV_NEED_PRESS_KEY + 0xA0)
#define	PROMPT_VERIFY_PIN_ERROR_1	(DRV_NEED_PRESS_KEY + 0x91)	// PIN��֤������1�����Ի���
#define	PROMPT_CHANGE_PIN_ERROR_1	(DRV_NEED_PRESS_KEY + 0xA1)	// PIN�޸ģ�����1�����Ի���
#define	PROMPT_VERIFY_PIN_ERROR_2	(DRV_NEED_PRESS_KEY + 0x92)	// PIN��֤������2�����Ի���
#define	PROMPT_CHANGE_PIN_ERROR_2	(DRV_NEED_PRESS_KEY + 0xA2)	// PIN�޸ģ�����2�����Ի���
#define PROMPT_ERASE_TOKEN			(DRV_NEED_PRESS_KEY + 0x81)
#define PROMPT_CHANGE_PIN			(DRV_NEED_PRESS_KEY + 0x82)
#define PROMPT_DELETE_CERT			(DRV_NEED_PRESS_KEY + 0x83)
#define PROMPT_INIT_TOKEN			(DRV_NEED_PRESS_KEY + 0x85)
#define PROMPT_KEY_SCROLL_UP        (DRV_NEED_PRESS_KEY + 0x88) // ����cos�Ϸ���������֪���㷢���������ж���KEY����������ҪUI���¼�ʱ
#define PROMPT_KEY_SCROLL_DOWN      (DRV_NEED_PRESS_KEY + 0x89) // ����cos�·�����
#define PROMPT_2G_SIGN				(DRV_NEED_PRESS_KEY + 0x8A)
#define PROMPT_GEN_KEY				(DRV_NEED_PRESS_KEY + 0x8B)

// added by zqb : �������� 1.5Gǩ�� SHA1����ת�ˣ���Ҫ����ȷ�ϣ�����Key����ʾ�����˺���Ϣ (�������и�����1.5Gǩ������hash�㷨ΪSHA1)
#define PROMPT_1_5_G_SIGN			(DRV_NEED_PRESS_KEY + 0x8C) // 1.5��ǩ����ʾ����

#define PROMPT_UNBLOCK_PIN			(DRV_NEED_PRESS_KEY + 0x8D) // ��Ϊ8D����ֹ��1.5��ǩ����ȷ�ϳ�ͻ
#define PROMPT_CHANGE_SOFT_SETTING (DRV_NEED_PRESS_KEY + 0x8E) // ע�⣬��ũ��Key�У����׼���DRV_KEY_NEED_FONT_DATA�Ķ����ͻ��
#define DRV_KEY_NEED_FONT_DATA      (DRV_NEED_PRESS_KEY + 0x8E) // cos��Ҫ�ַ���������


#define PROMPT_VERIFY_PIN_ON_KEY	(DRV_NEED_PRESS_KEY + 0xB1)
#define PROMPT_CHANGE_PIN_ON_KEY	(DRV_NEED_PRESS_KEY + 0xB2)
#define PROMPT_VALID_KEY_DOWN		(DRV_NEED_PRESS_KEY + 0xB3)	// added by zhouxiao: �����豸����ǩ������������Ȳ���ʱ������Ч����

#define DRV_WAIT_TIMEOUT			(DRV_NEED_PRESS_KEY + 0xF0)
#define DRV_KEY_OK					(0x00000000)
#define DRV_KEY_INTERRUPT			(0xE0610000 + 0x6FFA) // ��Ҫ�����Ĳ��������ָ���ȡ��
#define DRV_KEY_TIMEOUT				(0xE0610000 + 0x6FF9) // ��Ҫ�����Ĳ�����ʱ��ȡ��
#define DRV_KEY_CANCEL				(0xE0610000 + 0x6FF8) // ��Ҫ�����Ĳ�����ȡ������ȡ��

#if defined(__cplusplus)
extern "C"
{
#endif

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	�������ʼ��������Ѿ���ʼ����ֱ�ӷ��أ�����ִ�г�ʼ������
	// ����˵��:
	//	pblkDrvCfg:		���������Driver������Ϣ�������ͻ���ʶ��VID��PID֧���б�
	// ����ֵ:
	//	0x00:				��ȷ
	//	����:				������
	// ��ע:
	//	��1���ͻ���ʶ�����У���ͬ�Ŀͻ��в�ͬ��ͬ���źţ���ͬ�Ŀͻ��в�ͬ�ļ���δ���
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvInit(const BlkDriverConfig* pblkDrvCfg);

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	�ͷ����������Դ
	// ����˵��:
	//	��
	// ����ֵ:
	//	0x00:				��ȷ
	//	����:				������
	// ��ע:
	//	��1�����ͷŹ����У��ȵ����ϲ����õĻص�����
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvFinal(void);

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	ö�ٵ�ǰ��֧�ֵ������豸�˿ں�
	// ����˵��:
	//	u4ListType:			���������DRV_LIST_ONLY_EXIST���о����豸�Ķ˿ڣ�DRV_LIST_ALL_SUPPORT���о����ж˿�
	//	pu4SlotList:		����������˿��б��˿ںŴ�1��ʼ����
	//	pu4SlotListLen:		������������ڵĶ˿���Ŀ
	// ����ֵ:
	//	0x00:				��ȷ
	//	����:				������
	// ��ע:
	//	��1���˿��б����֧��32�������pu4SlotList��Ҫ����32���˿ںŵĴ洢�ռ�
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvList(u4 u4ListType, u4* pu4SlotList, u4* pu4SlotCount);

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	�豸����
	// ����˵��:
	//	u4SlotId:			����������˿ں�
	// ����ֵ:
	//	0x00:				��ȷ
	//	����:				������
	// ��ע:
	//	
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvLock(u4 u4SlotId, u4 u4Timeout);

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	����豸����
	// ����˵��:
	//	u4SlotId:			����������˿ں�
	// ����ֵ:
	//	0x00:				��ȷ
	//	����:				������
	// ��ע:
	//	
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvUnlock(u4 u4SlotId);

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	�豸��λ
	// ����˵��:
	//	u4SlotId:			����������˿ں�
	//	pvAtr:				����������豸�ĸ�λ��Ϣ������ΪNULL
	//	pu4AtrLen:			����������豸�ĸ�λ��Ϣ���ȣ�����ΪNULL
	// ����ֵ:
	//	0x00:				��ȷ
	//	����:				������
	// ��ע:
	//	��1���豸�ĸ�λ��Ϣ������64���ֽڣ����pvAtr������Ҫ����64���ֽڵĿռ�
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvReset(u4 u4SlotId, void* pvAtr, u4* pu4AtrLen);

	// u4EncType = 0x00 ����
	// u4EncType = 0x01 HIDЭ�����
	// u4EncType = 0x02 APDU����(V2)
	// u4EncType = 0x03 APDU����(V3)
	u4 CALL_TYPE DrvSendApdu(u4 u4SlotId, u4 u4EncType, const void* pvSend, u4 u4SendLen, void* pvRecv, u4* pu4RecvLen);

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	
	// ����˵��:
	//
	// ����ֵ:
	//	0x00:			��ȷ
	//	����:			������
	// ��ע:
	//	�������ܹ�Ϊ�ϲ�Ӧ�ñ����豸��ص�ȫ����Ϣ������ͨ��TAG_MEMORY_XXX�ı��������
	//	�ڲ��Զ�ΪTAG_MEMORY_XXX�ı������ָ����С���ڴ棨u4DataSize������ʱ���pvDataΪNULL������������ڴ�ȫ������Ϊȫ00�������Ϊ�գ��򿽱���������ڴ���
	//	����Ѿ�������TAG_MEMORY_XXX���ڴ棬��ô�ͱȽϴ˴εĴ�С������˴α���ǰ����Ĵ����������룬������ǣ���ʹ��ԭ�����ڴ�
	//	TAG = 0x01XX��	��ʾ�����ϲ�Ӧ�õ���Ҫ������豸�����Ϣ���ڴ�
	//	TAG = 0x02XX:	��ʾ�����豸���ʱ�Ļص���������ʱu4SlotIdû������
	//////////////////////////////////////////////////////////////////////////
	#define DRV_TAG_PATHNAME			0x0003		// �����豸�ļ�·��
	#define DRV_TAG_DEV_STATE			0x0004		// �˿����Ƿ����豸
	#define DRV_TAG_DEV_VIDPID			0x0005		// �˿����豸��VIDPID
	#define DRV_TAG_CMD_SPLIT			0x0006		// �˿����豸��Ҫ��ָ��

	#define	DRV_TAG_MEMORY				0x0100		// �洢����־��ʼֵ
		#define	DRV_TAG_MEMORY_COS			(DRV_TAG_MEMORY + 0x0000)		// �洢����־1: COS��Ľṹ����
		#define	DRV_TAG_MEMORY_FATFILE		(DRV_TAG_MEMORY + 0x0001)		// �洢����־2: ���ļ��ṹ
		#define	DRV_TAG_MEMORY_SLOT			(DRV_TAG_MEMORY + 0x0002)		// �洢����־3: SLot
		#define	DRV_TAG_MEMORY_MERGED_CFG	(DRV_TAG_MEMORY + 0x0003)		// �洢����־4: �м����KEY�����úϲ��������
		#define	DRV_TAG_MEMORY_WARNNING_MSG	(DRV_TAG_MEMORY + 0x0004)		// �洢����־5: ������Ϣ--Ŀǰ������ʹ��

	#define DRV_TAG_CALLBACK			0x0200      // �ص�����
	#define DRV_TAG_PTLOBJ				0x0300		// �����������ݶ�����������Ϊ BlkPtlObj

	typedef u4 (CALL_TYPE *FunPtlSend)(ESHANDLE hDev, const u1 *pu1Send, u4 u4SendLen, u1 *pu1Recv, u4 *pu4RecvLen);
	typedef u4 (CALL_TYPE *FunPtlReset)(ESHANDLE hDev, u1 *pu1Atr, u4 *pu4AtrLen);
	typedef struct BlkPtlObjTag
	{
		u4				m_u4ObjectType;
		FunPtlSend		m_funPtlSend;
		FunPtlReset		m_funPtlReset;
		void*			m_pu4Rfu[0x10];
	}BlkPtlObj;

	u4 CALL_TYPE DrvSet(u4 u4SlotId, u4 u4Tag, const void* pvData, u4 u4DataSize);

	// �����豸�����Ϣ�ص����������豸������߰γ���ʱ����������Զ����ô˺���
	// �ڻص������У��ص�����ֻ����������ģ������ڴ棨����������DrvSet�������õ��ڴ棩�;��������ģ�������ģ����ڴ治��Ҫ����
	#define	DRV_DEV_CHANGE_INSERT		0x01
	#define	DRV_DEV_CHANGE_REMOVE		0x02
	#define	DRV_DEV_CHANGE_SLEEP_RESUME	0x03
	#define	DRV_DEV_DISCONNECTED		0x0A
	typedef u4 (CALL_TYPE *FunDevChange)(u4 u4SlotId, u4 u4DevChangeType);

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	
	// ����˵��:
	//
	// ����ֵ:
	//	0x00:			��ȷ
	//	����:			������
	// ��ע:
	//
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvGet(u4 u4SlotId, u4 u4Tag, void* pvData, u4* pu4DataSize);

	//////////////////////////////////////////////////////////////////////////
	// ��������:
	//	�������֪�����㣬���豸������߰γ�
	// ����˵��:
	//
	// ����ֵ:
	//	0x00:			��ȷ
	//	����:			������
	// ��ע:
	//	�ƶ�ƽ̨�õ���PCƽ̨�������õ�
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvSetEvent(u4 u4DevChangeType, const char* pszDevName, u4 u4DevType);

    //////////////////////////////////////////////////////////////////////////
    // ��������:
    //	ͨ���������ṩ���豸��Ϣ�������豸��ʹ�÷��ڽ�����
    // ����˵��:
    //
    // ����ֵ:
    //	0x00:			��ȷ
    //	����:			������
    // ��ע:
    //	
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE DrvConnectDevice(u4 u4DevType, const char* pszDevName, u4* pu4SlotId);

    //////////////////////////////////////////////////////////////////////////
    // ��������:
    //	�Ƴ��豸
    // ����˵��:
    //
    // ����ֵ:
    //	0x00:			��ȷ
    //	����:			������
    // ��ע:
    //	
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE DrvDisconnectDevice(u4 u4SlotId);

    //////////////////////////////////////////////////////////////////////////
    // ��������:
    //	�豸�¼�֪ͨ
    // ����˵��:
    //
    // ����ֵ:
    //	0x00:			��ȷ
    //	����:			������
    // ��ע:
    //	
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE DrvNotifyEvent(u4 u4SlotId, u4 u4EventType, void* pvParam, u4 u4Size);

    //////////////////////////////////////////////////////////////////////////
    // ��������:
    //	�豸�о�
    // ����˵��:
    //
    // ����ֵ:
    //	0x00:			��ȷ
    //	����:			������
    // ��ע:
    //	�豸����֮����'\0'�ָ��������������'\0'��ʾ�б����
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE DrvEnumDevice(u4 u4DevType, char* pszDevList, u4* pu4ListSize);


#if defined(__cplusplus)
};
#endif

#endif // _ES_DRIVER_H_
