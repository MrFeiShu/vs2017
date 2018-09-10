#ifndef _ES_ERROR_H_
#define _ES_ERROR_H_

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������ṹ��������:
//				 ---------------------------------------------------------------------------------------------------------
//	����λ:		|31 30 |29 28 | 27 26 25 24 | 23 22 21 20 | 19 18 17 16  | 15 14 13 12 | 11 09 08 07 06 05 04 03 02 01 00 |
//	����ֵ:		| 1  1 | 1  0 |  0  0  0  0 |  0  1  1  0 |  0  0  0 0/1 |             |                                  |
//				+------+---------------------------------------------------------------------------------------------------
//	ʮ������:	|      E      |      0      |       6     |      0/1     |             |                                  |
//				-----------------------------------------------------------------------------------------------------------
//	˵��:			�����־		     ��˾��־                            ģ����             ģ���ڲ�����
//						E					060/061			0: ģ�������
//															1: COS������
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

#define ERROR_NO_ERROR					0x00000000  // �ɹ�
#define ERROR_SYSTEM					0xE0FFFFFF	// ���ϵͳ����Ӧ����ִ���˰�������ִ�еĴ���
#define ERROR_SLOT_EXCEPTION			0xE0603FFF

#define ERROR_COMMON_MAXRETRY			0xE0600000  // ʲô��˼?
#define ERROR_COMMON_MUTEX_WAIT_FAILED	0xE0600001  // �ȴ�������ʧ��
#define ERROR_COMMON_OUT_OF_MEMORY		0xE0600002	// �����ڴ治��

#define ERROR_COMMON_INVALID_DATA		0xE0600003  // ���ݴ���
#define ERROR_COMMON_DATA_LEN			0xE0600004  // ���ݳ��ȴ���
#define ERROR_COMMON_BUFFER_TOO_SMALL	0xE0600005  // ����������
#define ERROR_COMMON_VERIFY_FAILED		0xE0600006  // ��ǩʧ��

#define ERROR_COMMON_INVALID_PARAM		0xE0600007  // ��Ч����
#define ERROR_COMMON_NOT_FOUND			0xE0600008  // û�ҵ�
#define ERROR_COMMON_SHM_OFFSET			0xE0600009  // �����ڴ�ƫ�ƴ���
#define ERROR_COMMON_SHM_LENGTH			0xE060000A  // �����ڴ泤�ȴ���

#define ERROR_COMMON_WAIT_TIME_OUT		0xE060000B  // �ȴ���ʱ
#define ERROR_COMMON_CONNECT_FAILED		0xE060000C  // ���Ӵ���
#define ERROR_COMMON_NO_DATA_RECIEVED	0xE060000C  // û���յ�ʵ������

#define ERROR_COMMON_LIST_TAIL			0xE060000D	// �Ѿ����������β��
// #define ERROR_COMMON_LIST_DATA_UNFOUND	0xE060000E	// ��������û���ҵ�����
#define ERROR_COMMON_CONDITION			0xE060000F	// ����״̬������
#define ERROR_COMMON_NO_DEVICE			0xE0600010	// û���豸

#define ERROR_COS_INVALID_PARAM			0xE0602000		// ��Ч����
#define ERROR_COS_DATA_LEN				0xE0602001		// ���ݳ��ȴ���
#define ERROR_COS_BUFFER_TOO_SMALL		0xE0602002		// ����������

#define ERROR_DRV_NOT_INITIALIZED		0xE0601000		// Drv��δ��ʼ��
#define ERROR_DRV_NOT_CONNECTED			0xE0601001		// �豸δ����
#define ERROR_DRV_INVALID_SLOT_ID		0xE0601002		// ��Ч��SlotID
#define ERROR_DRV_NO_ENOUGH_MEMORY		0xE0601003		// �ڴ�ռ䲻��
#define ERROR_DRV_INVALID_PARAM			0xE0601004
#define ERROR_DRV_INVALID_VIDPID		0xE0601005
#define ERROR_DRV_INVALID_READER		0xE0601006
#define ERROR_DRV_PROTO_UNSORPORT		0xE0601007      // ������֧�ִ���Э��
#define ERROR_DRV_COMMUNICATE_FAILED	0xE0601008		// ͨ�Ŵ��󣬱���ͻȻ�γ��豸
#define ERROR_DRV_SCSI_ERROR			0xE0601009		// SCSIͨ��Э�����

#define ERROR_DRV_CONNECT_FAIL			0xE060100A		// ���Ӵ���
#define ERROR_DRV_SEND_FAIL				0xE060100B		// ���ʹ���
#define ERROR_DRV_RECV_FAIL				0xE060100C		// ���մ���
#define ERROR_DRV_RECV_TIMEOUT			0xE060100D		// ���ճ�ʱ
#define ERROR_DRV_RECV_CRC				0xE060100E		// ����У�����

#define ERROR_SLOT_INVALID_ID			0xE0603000		// ���Ϸ���SlotId
#define ERROR_SLOT_UNSUPPORTED_STRUCT	0xE0603001		// ��֧�ֵ��м���ṹ
#define ERROR_SLOT_SHM					0xE0603002		// �����ڴ����
#define ERROR_SLOT_SAME_SN				0xE0603003		// ������ͬ��SN
#define ERROR_SLOT_INVALID_PARAM		0xE0603004		// ��Ч����
#define ERROR_SLOT_INVALID_HANDLE		0xE0603005		// ��Ч���
#define ERROR_SLOT_REFDATA_UNFOUND		0xE0603006      // ���ʲô��˼��
#define ERROR_SLOT_CANCEL				0xE0603007      // �������û�ȡ����������KEY�ϵ�ȡ�������ر�UIȡ����KEYҪ֧����ȡ����
#define ERROR_SLOT_TIMEOUT				0xE0603008      // ������ʱ����ȡ��
#define ERROR_SLOT_FMT					0xE0603009      // һ��ָ���ʽ������
#define ERROR_SLOT_UI					0xE060300A      // UI����
#define ERROR_SLOT_HASH_END				0xE060300B      // HASH�Ѿ���ֹ
#define ERROR_SLOT_BUFFER_TOO_SMALL		0xE060300C		// ����������
#define ERROR_SLOT_CACHEPIN_NOT_EXISTED 0xE060300D		// û��PIN����
#define ERROR_SLOT_XML_DATA_FMT			0xE060300E		// ����ǩ�����ݸ�ʽ����
#define ERROR_SLOT_KEY_LOCKED			0xE060300F		// Key������
#define ERROR_SLOT_UI_PROMPT_CANCLOSE   0xE0603010      // �ⲻ��һ�������룬ֻ�����ڵ����첽������Ϣ��
#define ERROR_SLOT_REMOTE_DESKTOP_FORBIDDEN 0xE0603011 // Զ�����治֧��
#define ERROR_SLOT_MODULE_SIGN_ERROR	0xE0603012      // ģ��ǩ��У��ʧ��
#define ERROR_SLOT_NEED_TO_CHANGE_PIN   ERROR_MAN_TOOL_USER_PIN_NEED_TO_BE_CHANGED  // ��Ҫ�޸�ԭʼPIN��������Ϊ�˱��ִ�����һ��
#define ERROR_SLOT_CILENT               0xE0603013


// 0xE06031XX: ��ʾ�Ǵ��ļ��ṹģ��Ĵ�����
#define ERROR_SLOT_NOT_INITIALIZED		0xE0603100		// �豸û�г�ʼ��
#define ERROR_SLOT_NO_CURRENT_FILE		0xE0603101		// û�е�ǰ�ļ�
#define ERROR_SLOT_FILE_ACCESS			0xE0603102		// �ļ�����Խ��
#define ERROR_SLOT_FAT					0xE0603103		// FAT����
#define ERROR_SLOT_CONATINER_NOT_EXISTED 0xE0603104		// û������
#define ERROR_SLOT_INVALID_CONTAINER	0xE0603105		// ������������
#define ERROR_SLOT_CERT_ACCESS			0xE0603106		// ֤����ʴ���
#define ERROR_SLOT_ITEM_NOT_FOUND		0xE0603107		// û���ҵ�
#define ERROR_SLOT_STORAGE_FULL			0xE0603108		// ��˽Կ�ԡ�֤�顢����������
#define ERROR_SLOT_ITEM_EXISTED			0xE0603109		// �ļ���֤���Ѿ�����
#define ERROR_SLOT_ITEM_NOT_EXISTED		0xE060310A		// �ļ���֤���˽Կ������
#define ERROR_SLOT_OUT_OF_MEMORY		0xE060310B		// Token�ռ䲻��
#define ERROR_SLOT_FILE_EXISTS			0xE060310C		// file exists
#define ERROR_SLOT_CNT_TYPE_FIXED		0xE060310D		// ���������Ѿ�ȷ��
#define ERROR_SLOT_CNT_TYPE_LIMIT		0xE060310E		// ������Կ���������������ƶ�ʧ��

#define ERROR_CSP_SYSTEM_ERROR			0xE0604000		// CSPģ��ϵͳ����

#define ERROR_MAN_TOOL_OPEN_HELP_DOC_FAILURE 		0xE0606000 // �޷��򿪰����ļ�
#define ERROR_MAN_TOOL_USER_PIN_NEED_TO_BE_CHANGED 	0x60606001 // ԭʼPIN����Ҫ���޸�
#define ERROR_MAN_TOOL_FORMAT_WARNING	 			0x60606002 // ��ʽ������
#define ERROR_DEV_NEED_TO_BE_ACTIVATED				0x60606003 // �豸��Ҫ����
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
#define ERROR_CFG_STACK_TOO_DEEP		0xE0607006 // �ڵ�ջ ����
#define ERROR_CFG_STACK_NOT_MATCH		0xE0607007 // �ڵ�ջ ��ʼ�ͽ��������
#define ERROR_CFG_BRACKET_NOT_MATCH		0xE0607007 // ȱ������

#define ERROR_KEY_VERIFY_PIN_FAILURE		0xE06163C0 // PIN��֤ʧ�ܵĴ������ʽӦΪ0xE06163CX������Xռ��λ����ʾPINʣ������Դ���
#define ERROR_KEY_SAFE_COND_NOT_SATISFIED   0xE0616982 // ��ȫ״̬�����㣬��δУ��PIN��
#define ERROR_KEY_KEY_LOCKED				0xE0616983 // KEY������
#define ERROR_KEY_GET_RESPONSE_TIMEOUT		0xE0616FEF // ȡ��Ӧ��ʱ
#define ERROR_KEY_DISCONNECTED				0xE0616FF2 // �豸�Ͽ�����
#define ERROR_KEY_CONSULT_SECURITY_KEY_FAILURE 0xE061FFFF // ��ԿЭ��ʧ��
#define ERROR_KEY_INCORRECT_KEY_PRESSED     0xE0616FFE  // ���������ڵ���ȷ�϶Ի�ǰһֱ����ȷ�ϼ��᷵���������

#define ERROR_OCX_NO_KEY				0xE0608001		// δ�����豸
#define ERROR_OCX_MORE_KEY				0xE0608002		// �������һ���豸
#define ERROR_OCX_INVALID_PARAM			0xE0608003		// ��������
#define ERROR_OCX_NOT_INITIALIZED		0xE0608004		// �豸δ��ʼ��
#define ERROR_OCX_VERSION				0xE0608005		// ��ȡ�ؼ��汾ʧ��
#define ERROR_OCX_MALLOC_FAILED			0xE0608006		// ����ռ�ʧ��
#define ERROR_OCX_LOADLIB_FAILED		0xE0608007		// ���ض�̬��ʧ��
#define ERRPR_OCX_GETVERSION_FAILED		0xE0608008		// ��ȡ�汾ʧ��
#define ERRPR_OCX_DECODEBASE64_FAILED	0xE0608009		// ����BASE64ʧ��
#define ERRPR_OCX_INTERRUPT				0xE060800A		// ������;ʧ��
#define ERROR_OCX_NOT_SUPPORT			0xE060800B		// �ؼ���֧��

#define ERROR_XML_READ_FAILURE			0xE0609000
#define ERROR_XML_PARSE_FAILURE			0xE0609001

#define ERROR_PROXY_COMMUNICATE_FAILED  0xE060A000      // �����ͨ��ʧ��

#endif // _ES_ERROR_H_
