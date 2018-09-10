#ifndef _ES_ERROR_H_
#define _ES_ERROR_H_

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// 错误码结构定义如下:
//				 ---------------------------------------------------------------------------------------------------------
//	比特位:		|31 30 |29 28 | 27 26 25 24 | 23 22 21 20 | 19 18 17 16  | 15 14 13 12 | 11 09 08 07 06 05 04 03 02 01 00 |
//	比特值:		| 1  1 | 1  0 |  0  0  0  0 |  0  1  1  0 |  0  0  0 0/1 |             |                                  |
//				+------+---------------------------------------------------------------------------------------------------
//	十六进制:	|      E      |      0      |       6     |      0/1     |             |                                  |
//				-----------------------------------------------------------------------------------------------------------
//	说明:			错误标志		     公司标志                            模块编号             模块内部编码
//						E					060/061			0: 模块错误码
//															1: COS错误码
//																			 0: COMMON
//																			 1: DRIVER
//																			 2: COS
//																			 3: SLOT
//																			 4: CSP
//																			 5: PKCS
//																			 6: Manager Tool
//																			 7: Config
//																			 8: Ocx
//																			 9: XML
//                                                                           A: PROXY
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ERROR_NO_ERROR					0x00000000  // 成功
#define ERROR_SYSTEM					0xE0FFFFFF	// 软件系统错误，应该是执行了按常理不会执行的代码
#define ERROR_SLOT_EXCEPTION			0xE0603FFF

#define ERROR_COMMON_MAXRETRY			0xE0600000  // 什么意思?
#define ERROR_COMMON_MUTEX_WAIT_FAILED	0xE0600001  // 等待互斥体失败
#define ERROR_COMMON_OUT_OF_MEMORY		0xE0600002	// 主机内存不足

#define ERROR_COMMON_INVALID_DATA		0xE0600003  // 数据错误
#define ERROR_COMMON_DATA_LEN			0xE0600004  // 数据长度错误
#define ERROR_COMMON_BUFFER_TOO_SMALL	0xE0600005  // 缓冲区不足
#define ERROR_COMMON_VERIFY_FAILED		0xE0600006  // 验签失败

#define ERROR_COMMON_INVALID_PARAM		0xE0600007  // 无效参数
#define ERROR_COMMON_NOT_FOUND			0xE0600008  // 没找到
#define ERROR_COMMON_SHM_OFFSET			0xE0600009  // 共享内存偏移错误
#define ERROR_COMMON_SHM_LENGTH			0xE060000A  // 共享内存长度错误

#define ERROR_COMMON_WAIT_TIME_OUT		0xE060000B  // 等待超时
#define ERROR_COMMON_CONNECT_FAILED		0xE060000C  // 连接错误
#define ERROR_COMMON_NO_DATA_RECIEVED	0xE060000C  // 没有收到实际数据

#define ERROR_COMMON_LIST_TAIL			0xE060000D	// 已经到了链表的尾部
// #define ERROR_COMMON_LIST_DATA_UNFOUND	0xE060000E	// 在链表中没有找到数据
#define ERROR_COMMON_CONDITION			0xE060000F	// 条件状态不满足
#define ERROR_COMMON_NO_DEVICE			0xE0600010	// 没有设备

#define ERROR_COS_INVALID_PARAM			0xE0602000		// 无效参数
#define ERROR_COS_DATA_LEN				0xE0602001		// 数据长度错误
#define ERROR_COS_BUFFER_TOO_SMALL		0xE0602002		// 缓冲区不足

#define ERROR_DRV_NOT_INITIALIZED		0xE0601000		// Drv库未初始化
#define ERROR_DRV_NOT_CONNECTED			0xE0601001		// 设备未连接
#define ERROR_DRV_INVALID_SLOT_ID		0xE0601002		// 无效的SlotID
#define ERROR_DRV_NO_ENOUGH_MEMORY		0xE0601003		// 内存空间不足
#define ERROR_DRV_INVALID_PARAM			0xE0601004
#define ERROR_DRV_INVALID_VIDPID		0xE0601005
#define ERROR_DRV_INVALID_READER		0xE0601006
#define ERROR_DRV_PROTO_UNSORPORT		0xE0601007      // 驱动不支持此种协议
#define ERROR_DRV_COMMUNICATE_FAILED	0xE0601008		// 通信错误，比如突然拔除设备
#define ERROR_DRV_SCSI_ERROR			0xE0601009		// SCSI通信协议错误

#define ERROR_DRV_CONNECT_FAIL			0xE060100A		// 连接错误
#define ERROR_DRV_SEND_FAIL				0xE060100B		// 发送错误
#define ERROR_DRV_RECV_FAIL				0xE060100C		// 接收错误
#define ERROR_DRV_RECV_TIMEOUT			0xE060100D		// 接收超时
#define ERROR_DRV_RECV_CRC				0xE060100E		// 接收校验错误

#define ERROR_SLOT_INVALID_ID			0xE0603000		// 不合法的SlotId
#define ERROR_SLOT_UNSUPPORTED_STRUCT	0xE0603001		// 不支持的中间件结构
#define ERROR_SLOT_SHM					0xE0603002		// 共享内存错误
#define ERROR_SLOT_SAME_SN				0xE0603003		// 存在相同的SN
#define ERROR_SLOT_INVALID_PARAM		0xE0603004		// 无效参数
#define ERROR_SLOT_INVALID_HANDLE		0xE0603005		// 无效句柄
#define ERROR_SLOT_REFDATA_UNFOUND		0xE0603006      // 这个什么意思？
#define ERROR_SLOT_CANCEL				0xE0603007      // 操作被用户取消，包括按KEY上的取消键、关闭UI取消（KEY要支持软取消）
#define ERROR_SLOT_TIMEOUT				0xE0603008      // 操作因超时而被取消
#define ERROR_SLOT_FMT					0xE0603009      // 一条指令格式化出错
#define ERROR_SLOT_UI					0xE060300A      // UI出错
#define ERROR_SLOT_HASH_END				0xE060300B      // HASH已经终止
#define ERROR_SLOT_BUFFER_TOO_SMALL		0xE060300C		// 缓冲区不足
#define ERROR_SLOT_CACHEPIN_NOT_EXISTED 0xE060300D		// 没有PIN缓存
#define ERROR_SLOT_XML_DATA_FMT			0xE060300E		// 二代签名数据格式错误
#define ERROR_SLOT_KEY_LOCKED			0xE060300F		// Key被锁死
#define ERROR_SLOT_UI_PROMPT_CANCLOSE   0xE0603010      // 这不是一个错误码，只是用于弹出异步公共消息框
#define ERROR_SLOT_REMOTE_DESKTOP_FORBIDDEN 0xE0603011 // 远程桌面不支持
#define ERROR_SLOT_MODULE_SIGN_ERROR	0xE0603012      // 模块签名校验失败
#define ERROR_SLOT_NEED_TO_CHANGE_PIN   ERROR_MAN_TOOL_USER_PIN_NEED_TO_BE_CHANGED  // 需要修改原始PIN，这里是为了保持错误码一致
#define ERROR_SLOT_CILENT               0xE0603013


// 0xE06031XX: 表示是大文件结构模块的错误码
#define ERROR_SLOT_NOT_INITIALIZED		0xE0603100		// 设备没有初始化
#define ERROR_SLOT_NO_CURRENT_FILE		0xE0603101		// 没有当前文件
#define ERROR_SLOT_FILE_ACCESS			0xE0603102		// 文件访问越界
#define ERROR_SLOT_FAT					0xE0603103		// FAT错误
#define ERROR_SLOT_CONATINER_NOT_EXISTED 0xE0603104		// 没有容器
#define ERROR_SLOT_INVALID_CONTAINER	0xE0603105		// 容器索引错误
#define ERROR_SLOT_CERT_ACCESS			0xE0603106		// 证书访问错误
#define ERROR_SLOT_ITEM_NOT_FOUND		0xE0603107		// 没有找到
#define ERROR_SLOT_STORAGE_FULL			0xE0603108		// 公私钥对、证书、容器等用满
#define ERROR_SLOT_ITEM_EXISTED			0xE0603109		// 文件或证书已经存在
#define ERROR_SLOT_ITEM_NOT_EXISTED		0xE060310A		// 文件、证书或公私钥不存在
#define ERROR_SLOT_OUT_OF_MEMORY		0xE060310B		// Token空间不够
#define ERROR_SLOT_FILE_EXISTS			0xE060310C		// file exists
#define ERROR_SLOT_CNT_TYPE_FIXED		0xE060310D		// 容器类型已经确定
#define ERROR_SLOT_CNT_TYPE_LIMIT		0xE060310E		// 生成密钥对因容器类型限制而失败

#define ERROR_CSP_SYSTEM_ERROR			0xE0604000		// CSP模块系统错误

#define ERROR_MAN_TOOL_OPEN_HELP_DOC_FAILURE 		0xE0606000 // 无法打开帮助文件
#define ERROR_MAN_TOOL_USER_PIN_NEED_TO_BE_CHANGED 	0x60606001 // 原始PIN码需要被修改
#define ERROR_MAN_TOOL_FORMAT_WARNING	 			0x60606002 // 格式化警告
#define ERROR_DEV_NEED_TO_BE_ACTIVATED				0x60606003 // 设备需要激活
#define ERROR_ID_OK									0x60600001
#define ERROR_ID_YES								0x60600002
#define ERROR_ID_NO									0x60600003
#define ERROR_ID_CANCEL								0x60600004

#define ERROR_CFG_READ_CFG_FAILURE		0xE0607000
#define ERROR_CFG_PARSE_CFG_FAILURE		0xE0607001
#define ERROR_CFG_PARAM					0xE0607002
#define ERROR_CFG_NOT_FOUND				0xE0607003
#define ERROR_CFG_BUFFER_TOO_SMALL		0xE0607004
#define ERROR_CFG_STRUCT				0xE0607005
#define ERROR_CFG_STACK_TOO_DEEP		0xE0607006 // 节点栈 过深
#define ERROR_CFG_STACK_NOT_MATCH		0xE0607007 // 节点栈 开始和结束不配对
#define ERROR_CFG_BRACKET_NOT_MATCH		0xE0607007 // 缺少括号

#define ERROR_KEY_VERIFY_PIN_FAILURE		0xE06163C0 // PIN验证失败的错误码格式应为0xE06163CX，其中X占四位，表示PIN剩余可重试次数
#define ERROR_KEY_SAFE_COND_NOT_SATISFIED   0xE0616982 // 安全状态不满足，如未校验PIN码
#define ERROR_KEY_KEY_LOCKED				0xE0616983 // KEY被锁死
#define ERROR_KEY_GET_RESPONSE_TIMEOUT		0xE0616FEF // 取响应超时
#define ERROR_KEY_DISCONNECTED				0xE0616FF2 // 设备断开连接
#define ERROR_KEY_CONSULT_SECURITY_KEY_FAILURE 0xE061FFFF // 密钥协商失败
#define ERROR_KEY_INCORRECT_KEY_PRESSED     0xE0616FFE  // 按键错误，在弹出确认对话前一直按着确认键会返回这个错误

#define ERROR_OCX_NO_KEY				0xE0608001		// 未插入设备
#define ERROR_OCX_MORE_KEY				0xE0608002		// 插入多于一个设备
#define ERROR_OCX_INVALID_PARAM			0xE0608003		// 参数错误
#define ERROR_OCX_NOT_INITIALIZED		0xE0608004		// 设备未初始化
#define ERROR_OCX_VERSION				0xE0608005		// 读取控件版本失败
#define ERROR_OCX_MALLOC_FAILED			0xE0608006		// 分配空间失败
#define ERROR_OCX_LOADLIB_FAILED		0xE0608007		// 加载动态库失败
#define ERRPR_OCX_GETVERSION_FAILED		0xE0608008		// 获取版本失败
#define ERRPR_OCX_DECODEBASE64_FAILED	0xE0608009		// 解析BASE64失败
#define ERRPR_OCX_INTERRUPT				0xE060800A		// 操作中途失败
#define ERROR_OCX_NOT_SUPPORT			0xE060800B		// 控件不支持

#define ERROR_XML_READ_FAILURE			0xE0609000
#define ERROR_XML_PARSE_FAILURE			0xE0609001

#define ERROR_PROXY_COMMUNICATE_FAILED  0xE060A000      // 与代理通信失败

#endif // _ES_ERROR_H_
