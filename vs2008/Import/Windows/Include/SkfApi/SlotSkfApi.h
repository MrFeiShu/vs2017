#ifndef _SLOTSKFAPI_H_
#define _SLOTSKFAPI_H_

#include <time.h>
#include <EsConfig/MidwareConfig.h>

#define SKF_HANDLE_TYPE_DEV		0x00000000
#define SKF_HANDLE_TYPE_APP		0x01000000
#define SKF_HANDLE_TYPE_CNT		0x02000000
#define SKF_HANDLE_TYPE_HASH	0x03000000
#define SKF_HANDLE_TYPE_KEY		0x04000000
#define SKF_HANDLE_TYPE_MAC		0x05000000
#define SKF_HANDLE_TYPE_AGREE   0x06000000

#define SKF_MAX_EVENT_COUNT     128

typedef struct BlkSkfDevTag         // 请将本结构句柄放在第一个成员
{
	DEVHANDLE		m_hDev;			// 返回给调用者的设备句柄，低三个字节是生成的随机数，最高字节为00
	u4				m_u4SlotId;		// 设备对应的SlotId
}BlkSkfDev;

typedef struct BlkSkfAppTag
{
	HAPPLICATION	m_hApp;			// 返回给调用者的应用句柄，低三个字节是生成的随机数，最高字节为01
	DEVHANDLE		m_hDev;			// 对应的设备句柄
	u4				m_u4SlotId;		// 设备对应的SlotId
    char            m_szAppName[0x20];  // 应用名称
}BlkSkfApp;

typedef struct BlkSkfCntTag
{
	HCONTAINER		m_hCnt;			// 返回给调用者的容器句柄，低三个字节是生成的随机数，最高字节为02
	DEVHANDLE		m_hDev;			// 对应的设备句柄
	HAPPLICATION	m_hApp;			// 返回给调用者的应用句柄，低三个字节是生成的随机数，最高字节为01
	u4				m_u4SlotId;		// 设备对应的SlotId
	u4				m_u4CntId;
}BlkSkfCnt;

typedef struct BlkSkfHashTag
{
	HANDLE			m_hHash;		// 返回给调用者的哈希句柄，低三个字节是生成的随机数，最高字节为03
	DEVHANDLE		m_hDev;			// 对应的设备句柄
	HAPPLICATION	m_hApp;			// 返回给调用者的应用句柄，低三个字节是生成的随机数，最高字节为01
	HCONTAINER		m_hCnt;			// 返回给调用者的容器句柄，低三个字节是生成的随机数，最高字节为02
	u4				m_u4HashHandle;	// SLOTAPI的哈希句柄
	u4				m_u4SlotId;		// 设备对应的SlotId
	u4				m_u4AlgId;		// 哈希算法标识
	ESBOOL			m_bZaValid;
	u1				m_pu1Za[0x20];
}BlkSkfHash;

typedef struct BlkSkfKeyTag
{
	HANDLE			m_hKey;			// 返回给调用者的密钥句柄，低三个字节是生成的随机数，最高字节为04
	DEVHANDLE		m_hDev;			// 对应的设备句柄
	HAPPLICATION	m_hApp;			// 返回给调用者的应用句柄，低三个字节是生成的随机数，最高字节为01
	HCONTAINER		m_hCnt;			// 返回给调用者的容器句柄，低三个字节是生成的随机数，最高字节为02
	u4				m_u4SlotId;
	u4				m_u4AlgId;
	u4				m_u4AlgMode;
    u4              m_u4PadMode;
    u4              m_u4KeyLen;     // add by liyinghui, 2014-05-26
	u1				m_pu1Key[0x20];
    u1              m_pu1RemainData[0x20];  // 使用软算法时有效
    u4              m_u4RemainLen;
    ESBOOL          m_bSetSymmSoft; // setsymmtrykey是否使用软算法
}BlkSkfKey;

typedef struct BlkSkfMacTag
{
    HANDLE          m_hMac;         // 返回给调用者的Mac句柄，低三个字节是生成的随机数，最高字节为05
    HANDLE			m_hKey;			// 返回给调用者的密钥句柄，低三个字节是生成的随机数，最高字节为04
    DEVHANDLE		m_hDev;			// 对应的设备句柄
    HAPPLICATION	m_hApp;			// 返回给调用者的应用句柄，低三个字节是生成的随机数，最高字节为01
    HCONTAINER		m_hCnt;			// 返回给调用者的容器句柄，低三个字节是生成的随机数，最高字节为02
    u4				m_u4SlotId;
    u4              m_u4RemainLen;
    u1              m_pu1Remain[0x20];
}BlkSkfMac;

typedef struct BlkSkfEccAgreeTag
{
    HANDLE         m_hAgr;          // 本结构句柄必须放在最前面
    DEVHANDLE      m_hDev;
    HAPPLICATION   m_hApp;
    HCONTAINER     m_hCnt;
    u4             m_u4SlotId;
    u4             m_u4AlgId;
    u4             m_u4AlgMode;
}BlkSkfEccAgree;

typedef struct BlkSkfGlobalTag
{
	ESHANDLE		m_hMutex;		// 同步句柄
	ESHANDLE		m_hListDev;		// 设备句柄链表，对应BlkSkfDev结构
	ESHANDLE		m_hListApp;		// 应用句柄链表，对应BlkSkfApp结构
	ESHANDLE		m_hListCnt;
	ESHANDLE		m_hListHash;
	ESHANDLE		m_hListKey;
    ESHANDLE        m_hListMac;
    ESHANDLE        m_hListAgree;   // ECC密钥协商句柄
}BlkSkfGlobal;

typedef struct BlkEventNodeTag
{
    u4		m_u4SlotId;
    u4		m_u4EventType;  // 拔插事件，0 - 没有事件; 1 - 插入; 2 - 拔出
    clock_t m_tTime;
}BlkEventNode;

typedef struct BlkSkfEventInfoTag
{
    volatile u4             m_u4EventWaitingCount;      //  允许多个等待线程
    volatile u4             m_u4EventCancelingCount;
    volatile BlkEventNode	m_blkEvent[SKF_MAX_EVENT_COUNT];
    volatile u4             m_u4EarliestEventIndex;
    volatile u4             m_u4LatestEventIndex;
    ESHANDLE                m_hEventMutex;
}BlkSkfEventInfo;

#define SKF_APP_FLAG_DELETE	0x01

#pragma pack(push, 1)
typedef struct BlkSkfAppInfoTag
{
    u1      u1AdminPinTryMax;   
    u1      u1IsAdminPinOrg;      
	u1		u1Flag;
    u1      pu1Reserved[32 - 3];
}BlkSkfAppInfo;
#pragma pack(pop)


#if defined(__cplusplus)
extern "C"
{
#endif
	extern BlkSkfGlobal	    g_blkSkfGlobal;
    extern BlkSkfEventInfo  g_blkSkfEventInfo;

	u4 CALL_TYPE SkfGlobalInit(void);
	void CALL_TYPE SkfGlobalRelease(void);
    u4 CALL_TYPE SkfSlotCallback(u4 u4SlotId, u4 u4EventType);
    u4 CALL_TYPE SkfLock(ESBOOL* pbLocked);
    u4 CALL_TYPE SkfUnlock(ESBOOL* pbLocked);


	u4 CALL_TYPE SkfGetDevInfo(DEVHANDLE hDev, BlkSkfDev** ppblkSkfDev, ESBOOL* pbLocked);
	u4 CALL_TYPE SkfGetAppInfo(HAPPLICATION hApplication, BlkSkfApp** ppblkSkfApp, ESBOOL* pbLocked);
	u4 CALL_TYPE SkfGetCntInfo(HCONTAINER hContainer, BlkSkfCnt** ppblkSkfCnt, ESBOOL* pbLocked);
	u4 CALL_TYPE SkfGetHashInfo(HANDLE hHash, BlkSkfHash** ppblkSkfHash, ESBOOL* pbLocked);
	u4 CALL_TYPE SkfGetKeyInfo(HANDLE hKey, BlkSkfKey** ppblkSkfKey, ESBOOL* pbLocked);
    u4 CALL_TYPE SkfGetMacInfo(HANDLE hMac, BlkSkfMac** ppblkSkfMac, ESBOOL* pbLocked);
    u4 CALL_TYPE SkfGetAgreeInfo(HANDLE hAgree, BlkSkfEccAgree** ppblkSkfAgree, ESBOOL* pbLocked);
	u4 CALL_TYPE SkfEnd(u4 u4Result, ESBOOL* pbLocked);

	u4 CALL_TYPE SkfCloseDevHandle(DEVHANDLE hDev);
	u4 CALL_TYPE SkfCloseAppHandle(HAPPLICATION hApplication);
	u4 CALL_TYPE SkfCloseCntHandle(HCONTAINER hContainer);
    u4 CALL_TYPE SkfCloseKeyHandle(HANDLE hKey);
    u4 CALL_TYPE SkfCloseMacHandle(HANDLE hMac);
    u4 CALL_TYPE SkfCloseAgreeHandle(HANDLE hAgree);
	u4 CALL_TYPE SkfCloseHandle(HANDLE hHandle);

	u4 CALL_TYPE SkfNewDevHandle(BlkSkfDev* pblkSkfDev);
	u4 CALL_TYPE SkfNewAppHandle(BlkSkfApp* pblkSkfApp);
	u4 CALL_TYPE SkfNewCntHandle(BlkSkfCnt* pblkSkfCnt);
	u4 CALL_TYPE SkfNewHashHandle(BlkSkfHash* pblkSkfHash);
	u4 CALL_TYPE SkfNewKeyHandle(BlkSkfKey* pblkSkfKey);
    u4 CALL_TYPE SkfNewMacHandle(BlkSkfMac* pblkSkfMac);
    u4 CALL_TYPE SkfNewAgreeHandle(BlkSkfEccAgree* pblkSkfAgr);

	u4 CALL_TYPE SkfDeleteCnt(u4 u4CntId);
    u4 CALL_TYPE SkfFindAppViaName(LPSTR szAppName, ESHANDLE* phApp);
    u4 CALL_TYPE SkfFindCntViaId(u4 u4CntId, ESHANDLE* phCnt);

    u4 CALL_TYPE SkfEventLock();
    u4 CALL_TYPE SkfEventUnlock();

    u4 CALL_TYPE SkfAlg2SlotAlg(u4 u4SkfAlgId, u4* pu4SlotAlgId, u4* pu4SlotAlgMode);
    u4 CALL_TYPE SkfAlg2EsAlg(u4 u4SkfAlgId, u4* pu4EsAlgId, u4* pu4EsAlgMode);
    u4 CALL_TYPE SlotAlg2EsAlg(u4 u4SlotAlg, u4* pu4EsAlg);
    u4 CALL_TYPE SkfAsymmKey2SlotAsymmKey(void* pSkfAsymmKey, u4 u4KeyType, ESBOOL bIsPriv, BlkAsymKey* pblkSlotAsymmKey);
    u4 CALL_TYPE SlotAsymmKey2SkfAsymmKey(BlkAsymKey* pblkSlotAsymmKey, u4 u4KeyType, ESBOOL bIsPriv, void* pSkfAsymmKey);
    u4 CALL_TYPE SkfEccCipher2SlotSm2Cipher(const ECCCIPHERBLOB* pblkEccCipher, u1* pu1SlotSm2Cipher, u4* pu4SlotCipherLen);
    u4 CALL_TYPE SlotSm2Cipher2SkfEccCipher(u1* pu1SlotSm2Cipher, u4 u4SlotCipherLen, PECCCIPHERBLOB pblkEccCipher);


#if defined(__cplusplus)
};
#endif

#endif
