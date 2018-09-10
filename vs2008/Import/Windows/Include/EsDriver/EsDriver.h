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
	char				m_pszPortBindFilePath[0x40];	// 端口绑定配置文件路径：非空则根据此文件中的信息来分配端口号，为空则采用Driver层内部的分配方式
	u4					m_u4DevTypeSupportFlag;			// DEV_TYPE_XXX
	BlkVidPid			m_blkVidPidInclude;             // 包含项（支持通配符FFFF）
	BlkVidPid			m_blkVidPidExclude;             // 排除项（支持通配符FFFF）
	BlkReaderFeature	m_blkReaderFeature;
}BlkDriverConfig;

#define DRV_LIST_ONLY_EXIST     0x01
#define DRV_LIST_ALL_SUPPORT    0x00

// 0xE06190XX 表示指令的执行需要用户按键确认或需要等待Key进行操作，XX表示提示的类型
#define DRV_NEED_PRESS_KEY			0xE0619000

#define	PROMPT_VERIFY_PIN_ERROR		(DRV_NEED_PRESS_KEY + 0x90)
#define	PROMPT_CHANGE_PIN_ERROR		(DRV_NEED_PRESS_KEY + 0xA0)
#define	PROMPT_VERIFY_PIN_ERROR_1	(DRV_NEED_PRESS_KEY + 0x91)	// PIN认证，还有1次重试机会
#define	PROMPT_CHANGE_PIN_ERROR_1	(DRV_NEED_PRESS_KEY + 0xA1)	// PIN修改，还有1次重试机会
#define	PROMPT_VERIFY_PIN_ERROR_2	(DRV_NEED_PRESS_KEY + 0x92)	// PIN认证，还有2次重试机会
#define	PROMPT_CHANGE_PIN_ERROR_2	(DRV_NEED_PRESS_KEY + 0xA2)	// PIN修改，还有2次重试机会
#define PROMPT_ERASE_TOKEN			(DRV_NEED_PRESS_KEY + 0x81)
#define PROMPT_CHANGE_PIN			(DRV_NEED_PRESS_KEY + 0x82)
#define PROMPT_DELETE_CERT			(DRV_NEED_PRESS_KEY + 0x83)
#define PROMPT_INIT_TOKEN			(DRV_NEED_PRESS_KEY + 0x85)
#define PROMPT_KEY_SCROLL_UP        (DRV_NEED_PRESS_KEY + 0x88) // 部分cos上翻按键（已知：广发、贵阳银行二代KEY），可能需要UI重新计时
#define PROMPT_KEY_SCROLL_DOWN      (DRV_NEED_PRESS_KEY + 0x89) // 部分cos下翻按键
#define PROMPT_2G_SIGN				(DRV_NEED_PRESS_KEY + 0x8A)
#define PROMPT_GEN_KEY				(DRV_NEED_PRESS_KEY + 0x8B)

// added by zqb : 重庆银行 1.5G签名 SHA1批量转账，需要按键确认，不在Key上显示具体账号信息 (重庆银行更新了1.5G签名报文hash算法为SHA1)
#define PROMPT_1_5_G_SIGN			(DRV_NEED_PRESS_KEY + 0x8C) // 1.5代签名提示返回

#define PROMPT_UNBLOCK_PIN			(DRV_NEED_PRESS_KEY + 0x8D) // 改为8D，防止与1.5代签名的确认冲突
#define PROMPT_CHANGE_SOFT_SETTING (DRV_NEED_PRESS_KEY + 0x8E) // 注意，在农行Key中，与标准版的DRV_KEY_NEED_FONT_DATA的定义冲突了
#define DRV_KEY_NEED_FONT_DATA      (DRV_NEED_PRESS_KEY + 0x8E) // cos需要字符点阵数据


#define PROMPT_VERIFY_PIN_ON_KEY	(DRV_NEED_PRESS_KEY + 0xB1)
#define PROMPT_CHANGE_PIN_ON_KEY	(DRV_NEED_PRESS_KEY + 0xB2)
#define PROMPT_VALID_KEY_DOWN		(DRV_NEED_PRESS_KEY + 0xB3)	// added by zhouxiao: 交行设备上在签名、输入密码等操作时按下有效按键

#define DRV_WAIT_TIMEOUT			(DRV_NEED_PRESS_KEY + 0xF0)
#define DRV_KEY_OK					(0x00000000)
#define DRV_KEY_INTERRUPT			(0xE0610000 + 0x6FFA) // 需要按键的操作因插入指令而取消
#define DRV_KEY_TIMEOUT				(0xE0610000 + 0x6FF9) // 需要按键的操作因超时而取消
#define DRV_KEY_CANCEL				(0xE0610000 + 0x6FF8) // 需要按键的操作因按取消键而取消

#if defined(__cplusplus)
extern "C"
{
#endif

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	驱动库初始化，如果已经初始化，直接返回，不再执行初始化操作
	// 参数说明:
	//	pblkDrvCfg:		输入参数，Driver配置信息，包括客户标识、VID、PID支持列表
	// 返回值:
	//	0x00:				正确
	//	其他:				错误码
	// 备注:
	//	（1）客户标识功能有：不同的客户有不同的同步信号，不同的客户有不同的监测插拔窗口
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvInit(const BlkDriverConfig* pblkDrvCfg);

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	释放驱动库的资源
	// 参数说明:
	//	无
	// 返回值:
	//	0x00:				正确
	//	其他:				错误码
	// 备注:
	//	（1）在释放过程中，先调用上层设置的回调函数
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvFinal(void);

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	枚举当前所支持的所有设备端口号
	// 参数说明:
	//	u4ListType:			输入参数，DRV_LIST_ONLY_EXIST：列举有设备的端口，DRV_LIST_ALL_SUPPORT：列举所有端口
	//	pu4SlotList:		输出参数，端口列表，端口号从1开始计数
	//	pu4SlotListLen:		输出参数，存在的端口数目
	// 返回值:
	//	0x00:				正确
	//	其他:				错误码
	// 备注:
	//	（1）端口列表最多支持32个，因此pu4SlotList需要分配32个端口号的存储空间
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvList(u4 u4ListType, u4* pu4SlotList, u4* pu4SlotCount);

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	设备锁定
	// 参数说明:
	//	u4SlotId:			输入参数，端口号
	// 返回值:
	//	0x00:				正确
	//	其他:				错误码
	// 备注:
	//	
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvLock(u4 u4SlotId, u4 u4Timeout);

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	解除设备锁定
	// 参数说明:
	//	u4SlotId:			输入参数，端口号
	// 返回值:
	//	0x00:				正确
	//	其他:				错误码
	// 备注:
	//	
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvUnlock(u4 u4SlotId);

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	设备复位
	// 参数说明:
	//	u4SlotId:			输入参数，端口号
	//	pvAtr:				输出参数，设备的复位信息，可以为NULL
	//	pu4AtrLen:			输出参数，设备的复位信息长度，可以为NULL
	// 返回值:
	//	0x00:				正确
	//	其他:				错误码
	// 备注:
	//	（1）设备的复位信息不超过64个字节，因此pvAtr至少需要分配64个字节的空间
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvReset(u4 u4SlotId, void* pvAtr, u4* pu4AtrLen);

	// u4EncType = 0x00 明文
	// u4EncType = 0x01 HID协议加密
	// u4EncType = 0x02 APDU加密(V2)
	// u4EncType = 0x03 APDU加密(V3)
	u4 CALL_TYPE DrvSendApdu(u4 u4SlotId, u4 u4EncType, const void* pvSend, u4 u4SendLen, void* pvRecv, u4* pu4RecvLen);

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	
	// 参数说明:
	//
	// 返回值:
	//	0x00:			正确
	//	其他:			错误码
	// 备注:
	//	驱动层能够为上层应用保存设备相关的全局信息，可以通过TAG_MEMORY_XXX的标记来申请
	//	内部自动为TAG_MEMORY_XXX的标记申请指定大小的内存（u4DataSize），此时如果pvData为NULL，则将所申请的内存全部设置为全00，如果不为空，则拷贝到申请的内存中
	//	如果已经申请了TAG_MEMORY_XXX的内存，那么就比较此次的大小，如果此次比以前申请的大，则重新申请，如果不是，则使用原来的内存
	//	TAG = 0x01XX：	表示设置上层应用的需要管理的设备相关信息的内存
	//	TAG = 0x02XX:	表示设置设备插拔时的回调函数，此时u4SlotId没有意义
	//////////////////////////////////////////////////////////////////////////
	#define DRV_TAG_PATHNAME			0x0003		// 驱动设备文件路径
	#define DRV_TAG_DEV_STATE			0x0004		// 端口内是否有设备
	#define DRV_TAG_DEV_VIDPID			0x0005		// 端口内设备的VIDPID
	#define DRV_TAG_CMD_SPLIT			0x0006		// 端口内设备需要拆指令

	#define	DRV_TAG_MEMORY				0x0100		// 存储器标志起始值
		#define	DRV_TAG_MEMORY_COS			(DRV_TAG_MEMORY + 0x0000)		// 存储器标志1: COS层的结构变量
		#define	DRV_TAG_MEMORY_FATFILE		(DRV_TAG_MEMORY + 0x0001)		// 存储器标志2: 大文件结构
		#define	DRV_TAG_MEMORY_SLOT			(DRV_TAG_MEMORY + 0x0002)		// 存储器标志3: SLot
		#define	DRV_TAG_MEMORY_MERGED_CFG	(DRV_TAG_MEMORY + 0x0003)		// 存储器标志4: 中间件和KEY内配置合并后的配置
		#define	DRV_TAG_MEMORY_WARNNING_MSG	(DRV_TAG_MEMORY + 0x0004)		// 存储器标志5: 警告信息--目前仅工行使用

	#define DRV_TAG_CALLBACK			0x0200      // 回调函数
	#define DRV_TAG_PTLOBJ				0x0300		// 设置驱动数据对象，输入数据为 BlkPtlObj

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

	// 定义设备插拔消息回调函数，在设备插入或者拔出的时候，驱动层会自动调用此函数
	// 在回调函数中，回调函数只处理与自身模块相关内存（不包括调用DrvSet函数设置的内存）和句柄，其他模块和驱动模块的内存不需要处理
	#define	DRV_DEV_CHANGE_INSERT		0x01
	#define	DRV_DEV_CHANGE_REMOVE		0x02
	#define	DRV_DEV_CHANGE_SLEEP_RESUME	0x03
	#define	DRV_DEV_DISCONNECTED		0x0A
	typedef u4 (CALL_TYPE *FunDevChange)(u4 u4SlotId, u4 u4DevChangeType);

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	
	// 参数说明:
	//
	// 返回值:
	//	0x00:			正确
	//	其他:			错误码
	// 备注:
	//
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvGet(u4 u4SlotId, u4 u4Tag, void* pvData, u4* pu4DataSize);

	//////////////////////////////////////////////////////////////////////////
	// 函数功能:
	//	调用这告知驱动层，有设备插入或者拔出
	// 参数说明:
	//
	// 返回值:
	//	0x00:			正确
	//	其他:			错误码
	// 备注:
	//	移动平台用到，PC平台将来会用到
	//////////////////////////////////////////////////////////////////////////
	u4 CALL_TYPE DrvSetEvent(u4 u4DevChangeType, const char* pszDevName, u4 u4DevType);

    //////////////////////////////////////////////////////////////////////////
    // 函数功能:
    //	通过调用者提供的设备信息，连接设备，使用非内建驱动
    // 参数说明:
    //
    // 返回值:
    //	0x00:			正确
    //	其他:			错误码
    // 备注:
    //	
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE DrvConnectDevice(u4 u4DevType, const char* pszDevName, u4* pu4SlotId);

    //////////////////////////////////////////////////////////////////////////
    // 函数功能:
    //	移除设备
    // 参数说明:
    //
    // 返回值:
    //	0x00:			正确
    //	其他:			错误码
    // 备注:
    //	
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE DrvDisconnectDevice(u4 u4SlotId);

    //////////////////////////////////////////////////////////////////////////
    // 函数功能:
    //	设备事件通知
    // 参数说明:
    //
    // 返回值:
    //	0x00:			正确
    //	其他:			错误码
    // 备注:
    //	
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE DrvNotifyEvent(u4 u4SlotId, u4 u4EventType, void* pvParam, u4 u4Size);

    //////////////////////////////////////////////////////////////////////////
    // 函数功能:
    //	设备列举
    // 参数说明:
    //
    // 返回值:
    //	0x00:			正确
    //	其他:			错误码
    // 备注:
    //	设备名称之间以'\0'分隔，最后连续俩个'\0'表示列表结束
    //////////////////////////////////////////////////////////////////////////
    u4 CALL_TYPE DrvEnumDevice(u4 u4DevType, char* pszDevList, u4* pu4ListSize);


#if defined(__cplusplus)
};
#endif

#endif // _ES_DRIVER_H_
