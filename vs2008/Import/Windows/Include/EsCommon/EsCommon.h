#ifndef _ES_COMMON_H_
#define _ES_COMMON_H_

// #if defined(_WINDOWS)||defined(WIN32)
// 
// #ifdef _WP
// #define	_OS_WPHONE_
// #else
// #define	_OS_WINDOWS_
// #endif
// 
// #endif
#include "../EsTypeDef.h"


#if defined(_OS_WINDOWS_)
#	pragma message("macro _OS_WINDOWS_ defined")
#	include <windows.h>
#	include <process.h>
#	include <stdarg.h>
#	include <tchar.h>
#elif defined _OS_IOS_
#	pragma message("macro _OS_IOS_ defined")
#   include <stdlib.h>
#   include <stdio.h>
#   include <string.h>
#   include <errno.h>
#   include <time.h>
#   include <pthread.h>
#   include <stdlib.h>
#   include <unistd.h>
#   include <sys/times.h>
#   include <sys/shm.h>
#   include <sys/sem.h>
#   include <sys/ipc.h>
#   include <ctype.h>
#   include <stdarg.h>
#   include <wchar.h>

#   define AT_SIGNATURE		2
#   define AT_KEYEXCHANGE		1
#   define INFINITE	0xFFFFFFFF
#   define MAX_PATH     260

#elif defined _OS_LINUX_
#	include <stdlib.h>
#	include <string.h>
#	include <ctype.h>
#   define AT_SIGNATURE		2
#   define AT_KEYEXCHANGE		1
#   define INFINITE	0xFFFFFFFF
#   define MAX_PATH     260

#elif defined _OS_WPHONE_
#	pragma message("macro _OS_WPHONE_ defined")
#	include <windows.h>
#	include <synchapi.h>
#	include <tchar.h>
#	include <stdlib.h>
#	define	CALL_TYPE	__stdcall
#elif defined _OS_ANDROID_
#	pragma message("macro _OS_ANDROID_ defined")
#	include <stdlib.h>
#	include <string.h>
#   include <errno.h>
#   include <time.h>
#   include <pthread.h>
#   include <stdlib.h>
#   include <unistd.h>
#   include <sys/times.h>
#   include <stdarg.h>
#   include <linux/shm.h>
#   include <sys/ipc.h>
#   include <ctype.h>

#   define AT_SIGNATURE		2
#   define AT_KEYEXCHANGE		1
#   define  INFINITE	0xFFFFFFFF
#   define MAX_PATH     260

#elif defined _OS_MAC_OSX_
#	pragma message("macro _OS_MAC_OSX_ defined")

#   include <dlfcn.h>
#   include <unistd.h>
#   include <fcntl.h>
#   include <ctype.h>
#   include <sys/stat.h>
#   include <sys/types.h>
#   include <sys/fcntl.h>
#   include <sys/socket.h>
#   include <sys/times.h>
#   include <netinet/in.h>
#   include <netdb.h>
#   include <arpa/inet.h>
#   include <stdlib.h>
#   include <stdio.h>
#   include <string.h>
#   include <errno.h>
#   include <sys/ipc.h>
#   include <time.h>
#   include <assert.h>
#   include <pthread.h>
#   include <sys/ipc.h>
#   include <sys/shm.h>
#   include <sys/sem.h>
#   include <wchar.h>
#	include <ctype.h>

#   define AT_SIGNATURE		2
#   define AT_KEYEXCHANGE		1
#   define  INFINITE	0xFFFFFFFF
#   define MAX_PATH     260

#else
#	pragma message("NO OS type macro defined !!!!!!")
#endif


// #if defined (_OS_IOS_) | defined (_OS_ANDROID_)
// #	define  INFINITE	0
//     u4 GetTickCount(void);
//     u4 GetCurrentProcessId(void);
//     u4 GetCurrentThreadId(void);
//     u4 GetLastError();
//     void Sleep(u4 mSecond);
//     void DestroyMutex(void * hHandle);
// #endif

#ifdef __cplusplus
extern "C" 
{
#endif

	//-------------------------------------------------------------------
	u4 CALL_TYPE EsCommonLibInit(void);
	u4 CALL_TYPE EsCommonLibRelease(void);

	//----------------------------------------------------------------------------------
	// EsCommonString	(Safe string API)
	// 为字符串定义一种调用约定。CALL_TYPE（__stdcall）是不适合变参的API定义的，字符串API参数存在变参的情况，所以必须另外定义。
#	define STR_CALL_TYPE __cdecl

	ESBOOL STR_CALL_TYPE EsStrCopy(char* pszDest, size_t cchDest, const char* pszSrc);
	ESBOOL STR_CALL_TYPE EsWcsCopy(wchar_t* pszDest, size_t cchDest, const wchar_t* pszSrc);
	
	ESBOOL STR_CALL_TYPE EsStrCat(char* pszDest, size_t cchDest, const char* pszSrc);
	ESBOOL STR_CALL_TYPE EsWcsCat(wchar_t* pszDest, size_t cchDest, const wchar_t* pszSrc);
	
	ESBOOL STR_CALL_TYPE EsStrPrintf(char * pszDest, size_t cchDest, const char * pszFormat, ...);
	ESBOOL STR_CALL_TYPE EsWcsPrintf(wchar_t * pszDest, size_t cchDest, const wchar_t * pszFormat, ...);
	
	ESBOOL STR_CALL_TYPE EsStrVPrintf(char * pszDest, size_t cchDest, const char * pszFormat, va_list argList);
	ESBOOL STR_CALL_TYPE EsWcsVPrintf(wchar_t * pszDest, size_t cchDest, const wchar_t * pszFormat, va_list argList);

	s4 STR_CALL_TYPE EsStrICmp(const char* str1, const char* str2);
	s4 STR_CALL_TYPE EsWcsICmp(const wchar_t* str1, const wchar_t* str2);
	char * STR_CALL_TYPE EsStrLower(char *str, size_t len);
	
#ifdef UNICODE
#	define EsTcsCopy EsWcsCopy
#	define EsTcsCat EsWcsCat
#	define EsTcsPrintf EsWcsPrintf
#	define EsTcsVPrintf EsWcsVPrintf
#else
#	define EsTcsCopy EsStrCopy
#	define EsTcsCat EsStrCat
#	define EsTcsPrintf EsStrPrintf
#	define EsTcsVPrintf EsStrVPrintf
#endif

	//-------------------------------------------------------------------------------------------------
	// EsCommonMutex
	u4 CALL_TYPE EsMutexCreate(const char* szMutexName, ESHANDLE* phMutex); // szMutexName can be NULL
	u4 CALL_TYPE EsMutexOpen(const char* szMutexName, ESHANDLE* phMutex);
	u4 CALL_TYPE EsMutexWait(ESHANDLE hMutex, u4 u4TimeOut);
	u4 CALL_TYPE EsMutexRelease(ESHANDLE hMutex);
	u4 CALL_TYPE EsMutexDestroy(ESHANDLE hMutex);

	//-------------------------------------------------------------------------------------------------
	// EsCommonCriticalSection
	void CALL_TYPE EsCriticalSectionCreate();
	void CALL_TYPE EsCriticalSectionDestory();
	void CALL_TYPE EsCriticalSectionEnter();
	void CALL_TYPE EsCriticalSectionLeave();

	//-------------------------------------------------------------------------------------------------
	// EsCommonEvent
	u4 CALL_TYPE EsEventCreate(const char* szEventName, ESHANDLE* phEvent);
	u4 CALL_TYPE EsEventOpen(const char* szEventName, ESHANDLE* phEvent);
	u4 CALL_TYPE EsEventClose(ESHANDLE hEvent);
	u4 CALL_TYPE EsEventSet(ESHANDLE hEvent);
	u4 CALL_TYPE EsEventReset(ESHANDLE hEvent);
	
#define ES_WAIT_OBJ_0 0
	u4 CALL_TYPE EsEventWait(ESHANDLE hEvent, u4 u4Timeout);
	//-------------------------------------------------------------------------------------------------
    typedef enum EnThreadState
    {
        ESTHREAD_STATE_RUNNING          = 1,
        ESTHREAD_STATE_TO_BE_EXITED     = 2,
        ESTHREAD_STATE_EXITED           = 3
    }EnThreadState;

	// EsCommonThread
	typedef u4 (CALL_TYPE *FunThreadCallBack)(void*);
	// 启动一个线程
	u4 CALL_TYPE EsThreadBegin(FunThreadCallBack funCallBack, void* pvParam, ESHANDLE* phThread);
	// 线程函数判断是否有线程要求自己退出
	ESBOOL CALL_TYPE EsThreadShouldExit(ESHANDLE hThread);
	// 外部要求线程结束并等待线程退出
	u4 CALL_TYPE EsThreadEnd(ESHANDLE hThread);
	// 关闭线程句柄（仅释放句柄，不等待线程退出）
	u4 CALL_TYPE EsThreadCloseHandle(ESHANDLE hThread);
    u4 CALL_TYPE EsThreadGetState(ESHANDLE hThread);
    u4 CALL_TYPE EsThreadSetState(ESHANDLE hThread, u4 u4State);

	//-------------------------------------------------------------------------------------------------
	// EsCommonShareMemory
	u4 CALL_TYPE EsShareMemOpen(const char* szMapName, u4 u4Size, ESHANDLE* phMap);
	u4 CALL_TYPE EsShareMemClose(ESHANDLE hMap);
	u4 CALL_TYPE EsShareMemGetData(ESHANDLE hMap, void** ppvMap);
	u4 CALL_TYPE EsShareMemLock(ESHANDLE hMap);
	u4 CALL_TYPE EsShareMemUnlock(ESHANDLE hMap);

	u4 CALL_TYPE EsShareMemGetSize(ESHANDLE hMap, u4* pu4Size);
	u4 CALL_TYPE EsShareMemGetAttachCount(ESHANDLE hMap, u4*pu4Count);
	u4 CALL_TYPE EsShareMemRead(ESHANDLE hMap, u4 u4Offset, void* pvData, u4 u4DataLen); // only for windows now
	u4 CALL_TYPE EsShareMemWrite(ESHANDLE hMap, u4 u4Offset, const void* pvData, u4 u4DataLen); // only for windows now

	//-------------------------------------------------------------------
	// EsCommonSystem
#define LANG_ID_SIPMLE_CHINESE			2052
#define LANG_ID_TRADITIONAL_CHINESE		1028
#define LANG_ID_ENGLISH_US				1033
#define ESPRODCUT_PARAM_LANG            0x01

#pragma pack(push, 1)
    typedef struct BlkProductParamTag
    {
        int nLangId;
        unsigned char pucReserved[512-4];
    }BlkProductParam;
#pragma pack(pop)

	u4 CALL_TYPE EsOsGetLanguage(u4* pu4LangId);
    u4 CALL_TYPE EsOsSetProductParam(const char* pszProductName, u4 u4Param, const void* pvParamData, u4 u4ParamDataLen);
    u4 CALL_TYPE EsOsGetProductParam(const char* pszProductName, u4 u4Param, void* pvParamData, u4* pu4ParamDataLen);


#define OS_WIN95	0x0095
#define OS_WIN98	0x0098
#define OS_WINNT	0x0104
#define OS_WIN2K	0x0120
#define OS_WINXP	0x0121
#define OS_WIN2K3	0x0123
#define OS_WIN2K8	0x0128
#define OS_VISTA	0x0225
#define OS_WIN7		0x0407
#define OS_WIN8		0x0408
#define OS_UNKNOWN	0xFFFFFFFF
	u4 CALL_TYPE EsOsGetVersion(void);
	u4 CALL_TYPE EsOsGetFileVersion(const char* szFileName, char* szFileVersion, u4* pu4VersionLen);

	ESBOOL CALL_TYPE EsIs64BitOs();
	void CALL_TYPE EsOsDisOrRevRedirection(ESBOOL bDisable);
#	define LANGE_ZH_CN				0x00
#	define LANGE_ENGLISH			0x01
#	define LANGE_ZH_TW				0x02
#	define LANGE_FRANCE				0x03
#	define LANGE_RUSSIAN			0x04
#	define LANGE_JAPAN				0x05
#	define LANGE_INDONESIA			0x06
#	define LANGE_GERMAN				0x07
#	define LANGE_ARAB				0x08
#	define LANGE_KOREA				0x09
#	define LANGE_KAZAK				0x0A
#	define LANGE_THAI				0x0B

#	define WINDOWS_95				0x01
#	define WINDOWS_98				0x02
#	define WINDOWS_2000				0x03
#	define WINDOWS_XP_32			0x04
#	define WINDOWS_XP_64			0x05
#	define WINDOWS_VISTA_32			0x06
#	define WINDOWS_VISTA_64			0x07
#	define WINDOWS_7_32				0x08
#	define WINDOWS_7_64				0x09
	u1 CALL_TYPE EsOsGetLanguageVersion(void);

	u4 CALL_TYPE EsOsSleep(u4 u4MiliSeconds);
	//-------------------------------------------------------------------------------------------------
	// EsCommonAlg

	// HASH Alg
	#define	ES_HASH_ALG_MD5		 0x80000001
	#define	ES_HASH_ALG_SHA1	 0x80000002
	#define	ES_HASH_ALG_SHA256	 0x80000003
	#define	ES_HASH_ALG_SHA384   0x80000004
	#define	ES_HASH_ALG_SHA512   0x80000005
	#define	ES_HASH_ALG_SM3		 0x80000006
	#define	ES_HASH_ALG_MD5SHA1	 0x80000007
	#define ES_HASH_ALG_SET		 0x800000FF		// 只能通过设置接口设置哈希值
	
	// pvIv can be NULL
	u4 CALL_TYPE EsHashInit(ESHANDLE* phHash, const void* pvIv, u4 u4HashAlgId);
	u4 CALL_TYPE EsHashUpdate(ESHANDLE hHash, const void *pvInput, u4 u4InputLen);
	u4 CALL_TYPE EsHashFinal(ESHANDLE hHash, void* pvHashValue);
	u4 CALL_TYPE EsHashRelease(ESHANDLE hHash);
	u4 CALL_TYPE EsHashGetSize(ESHANDLE hHash, u4* pu4BlockSize, u4* pu4IvSize, u4* pu4ValueSize);
	u4 CALL_TYPE EsHashGetValue(ESHANDLE hHash, void* pvHashValue, u4* pu4DataLen); // pu4DataLen can be NULL
	u4 CALL_TYPE EsHashSetValue(ESHANDLE hHash, const void* pvHashValue, u4 u4DataLen);
	
	u1	 CALL_TYPE EsHashGetOid(u4 u4AlgId, u1* pu1Oid);
	u1	 CALL_TYPE EsHashData(u4 u4HashAlgId, const void* pvMsg, u4 u4MsgLen, void* pvHashValue);
	
	// Symm Alg
	#define	ES_SYMM_ALG_DES		    0x0001
	#define ES_SYMM_ALG_3DES112	    0x0002
	#define ES_SYMM_ALG_3DES168		0x0004
	#define ES_SYMM_ALG_AES128		0x0008
	#define ES_SYMM_ALG_AES192		0x0010
	#define ES_SYMM_ALG_AES256		0x0020
	#define ES_SYMM_ALG_SSF33		0x0100
	#define ES_SYMM_ALG_SM1			0x0200
	#define ES_SYMM_ALG_SM4		    0x0400

	//---------------------------------------------------------------------------------
	// no padding

	// 分组算法
	u4 CALL_TYPE EsSymmGetInfo(u4 u4AlgId, u4* pu4BlockLen, u4* pu4KeyLen);
	u4 CALL_TYPE EsSymmEncEcb(u4 u4AlgId, const void* pvKey, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	u4 CALL_TYPE EsSymmDecEcb(u4 u4AlgId, const void* pvKey, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	u4 CALL_TYPE EsSymmEncCbc(u4 u4AlgId, const void* pvKey, const void* pvIv, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	u4 CALL_TYPE EsSymmDecCbc(u4 u4AlgId, const void* pvKey, const void* pvIv, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	u4 CALL_TYPE EsSymmMac(u4 u4AlgId, const void* pvKey, const void* pvIv, const void* pvInput, u4 u4InputLen, void* pvOutput, u4* pu4OutputLen);
	
	// 流算法
	typedef struct _rc4_state
	{
		int x, y, m[256];
	}rc4_state;

	void EsRc4Setup(rc4_state *s, unsigned char *key, int length);

	void EsRc4Crypt(rc4_state *s, unsigned char *data, int length);

	//---------------------------------------------------------------------------------
	// 本套接口主要按照PKCS11的接口形式提供，CSP可以在此接口上封装实现。
	// SymCipher for PKCS11
	
	#define ES_PADDING_PKCS5	1
	#define ES_PADDING_NONE		0
	#define ES_MODE_CBC			1
	#define ES_MODE_ECB			0

	u4 CALL_TYPE EsSymCipherInit(u4 u4SlotId, u4 u4AlgId, u4 u4BlockSize,
				const u1* pu1Key, u4 u4KeyLen, const u1 *pu1IV, u4 u4IVLen,
				u4	u4Mode, u4 u4Padding, ESHANDLE* phEsCipher);
	u4 CALL_TYPE EsSymCipherRelease(ESHANDLE hEsCipher);
	u4 CALL_TYPE EsSymCipherEncrypt(ESHANDLE hEsCipher, u1* pu1Out, u4*	pu4OutLen, const u1* pu1In, u4 u4InLen);
	u4 CALL_TYPE EsSymCipherEncryptUpdate(ESHANDLE hEsCipher, u1* pu1Out, u4* pu4OutLen, const u1* pu1In, u4 u4InLen);
	u4 CALL_TYPE EsSymCipherEncryptFinal(ESHANDLE hEsCipher, u1* pu1Out, u4* pu4OutLen);
	u4 CALL_TYPE EsSymCipherDecrypt(ESHANDLE hEsCipher, u1* pu1Out, u4* pu4OutLen, const u1* pu1In, u4 u4InLen);
	u4 CALL_TYPE EsSymCipherDecryptUpdate(ESHANDLE hEsCipher, u1* pu1Out, u4* pu4OutLen, const u1* pu1In, u4 u4InLen);
	u4 CALL_TYPE EsSymCipherDecryptFinal(ESHANDLE hEsCipher, u1* pu1Out, u4* pu4OutLen);
	// 这两个接口主要是CSP调用，为了在上层调用为取长度和上层缓冲区长度不足时不进行实质性的运算，特提供以下两个接口
	// EsSymCipherEncryptGetOutLen,EsSymCipherDecryptGetOutLen are for CSP convenience
	u4 CALL_TYPE EsSymCipherEncryptGetOutLen(ESHANDLE hEsCipher, u4* pu4OutLen, u4 u4InLen, u4 u4FinalFlag);
	u4 CALL_TYPE EsSymCipherDecryptGetOutLen(ESHANDLE hEsCipher, u4* pu4OutLen, u4 u4InLen, u4 u4FinalFlag);
	//---------------------------------------------------------------------------------

#define	ES_ASYM_ALG_RSA		 0x01
#define	ES_ASYM_ALG_SM2		 0x02
#ifndef _BLKASYMKEY_
#define _BLKASYMKEY_
    typedef struct BlkRsaKeyTag
    {
        u4				m_u4ELen;
        u1				m_pu1E[256];
        u1				m_pu1N[256];
        u1				m_pu1D[256];
        u1				m_pu1P[128];
        u1				m_pu1Q[128];
        u1				m_pu1Dp[128];
        u1				m_pu1Dq[128];
        u1				m_pu1Qinv[128];
    }BlkRsaKey;
    typedef struct BlkSm2KeyTag
    {
        u1				m_pu1PubKeyX[32];
        u1				m_pu1PubKeyY[32];
        u1				m_pu1PriKeyD[32];
    }BlkSm2Key;
    typedef union UnionAsymKeyTag
    {
        BlkRsaKey		m_blkRsaKey;
        BlkSm2Key		m_blkSm2Key;
    }UnionAsymKey;
    typedef struct BlkAsymKeyTag
    {
        u4				m_u4AlgId;
        u4				m_u4ModLen;
        UnionAsymKey	m_unionAsymKey;
    }BlkAsymKey;
#endif

	// Asym alg -- RSA
	// for big number, MSB first
	// pvPubKeyE 4 bytes
	u4 CALL_TYPE EsRsaGen(int iModBitLen, void*	pvPubKeyN, void* pvPubKeyE, void* pvPriKeyD,void* pvPriKeyP, void* pvPriKeyQ, void* pvPriKeyDP, void* pvPriKeyDQ, void*	pvPriKeyQInv);
	u4 CALL_TYPE EsRsaEnc(u2 u2ModLen, const void* pvPubKeyN, const void* pvPubKeyE, u4 u4ELen, const void* pvInput, void* pvOutput);
    u4 CALL_TYPE EsRsaSign(const BlkAsymKey* pblkAsymKey, u4 u4HashAlgId, const void* pvHashValue, void* pvSignature, u4* pu4SignatureLen);
    u4 CALL_TYPE EsRsaVerify(u2 u2ModLen, const void* pvPubKeyN, const void* pvPubKeyE, u4 u4ELen,const void* pvHashValue, u4 u4HashValueLen, const void* pvSignature, u4 u4SignatureLen);
	u4 CALL_TYPE EsRsaDecD(u2 u2ModLen, const void* pvPriKeyN, const void* pvPriKeyD, const void* pvInput, void* pvOutput);
	u4 CALL_TYPE EsRsaDec(u2 u2ModLen, const void* pvPriKeyP, const void* pvPriKeyQ, const void* pvPriKeyDP, const void* pvPriKeyDQ, const void* pvPriKeyQinv, const void* pvInput, void* pvOutput);

	// Asym alg -- SM2
	// for big number, MSB first
	u4 CALL_TYPE EsSm2GenKey(u1* pu1PriKeyD, u1* pu1PubKeyQx, u1* pu1PubKeyQy);
	u4 CALL_TYPE EsSm2Sign(const u1* pu1PriKeyD, const u1* pu1HashValue, u1* pu1SignatureR, u1* pu1SignatureS);
	u4 CALL_TYPE EsSm2Verify(const u1* pu1PubKeyQx, const u1* pu1PubKeyQy, const u1* pu1HashValue, const u1* pu1SignatureR, const u1* pu1SignatureS);
	u4 CALL_TYPE EsSm2GetZa(const char* pszID, const u1* pu1PubKeyQx, const u1* pu1PubKeyQy, u1 * pu1Za);
	u4 CALL_TYPE EsSm2Enc(const u1 * pu1PubKeyQx, const u1 * pu1PubKeyQy, const u1 * pu1Plain, u4 u4PlainLen, u1 * pu1Cipher, u4 * pu4CipherLen);
	u4 CALL_TYPE EsSm2Dec(const u1* pu1PriKeyD, const u1* pu1Cipher, u4 u4CipherLen, u1* pu1Plain, u4* pu4PlainLen);

    u1 CALL_TYPE EsSm3Hash(ESBOOL bCalcZa, const BlkAsymKey* pblkAsymKey, const void* pvMsg, u4 u4MsgLen, u1* pu1HashValue);
    u4 CALL_TYPE EsAsymGenKeyPair(BlkAsymKey* pblkAsymKey);
    u4 CALL_TYPE EsAsymSign(const BlkAsymKey* pblkAsymKey, const void* pvSignData, void* pvSignature, u4* pu4SignatureLen);
    u4 CALL_TYPE EsAsymEnc(const BlkAsymKey* pblkAsymKey, const void* pvPlainText, u4 u4PlainTextLen, void* pvCipherText, u4* pu4CipherTextLen);
	u4 CALL_TYPE EsAsymDec(const BlkAsymKey* pblkAsymKey, const void* pvCipherText, u4 u4CipherTextLen, void* pvPlainText, u4* pu4PlainTextLen);
	u4 CALL_TYPE EsAsymVerifySignature(const BlkAsymKey* pblkAsymKey, u4 u4HashAlgId, const void* pvHashValue, const void* pvSignature, u4 u4SignatureLen);
    u4 CALL_TYPE EsAsymVerifySignatureMsg(const BlkAsymKey* pblkAsymKey, ESBOOL bCalcZa, u4 u4HashAlgId, const void* pvMsg, u4 u4MsgLen, const void* pvSignature, u4 u4SignatureLen);
    u4 CALL_TYPE EsAsymSignMsg(const BlkAsymKey* pblkAsymKey, u4 u4HashAlgId, const void* pvMsg, u4 u4MsgLen, void* pvSignature, u4* pu4SignatureLen);


	typedef struct BlkSm2CtxTag
	{
		u4 m_u4State;					// 0x00 未计算过C1, 0x01 已经计算过C1
		u1 m_pu1RFU[0x40+0x04+0x68];    // 函数内部使用的结构，调用者不用关心
	}BlkSm2Ctx;
	// u4FinalFlag = 0x00 数据长度必须是0x40的整数倍
	// u4FinalFlag = 0x01 数据长度任意
	u4 CALL_TYPE EsSm2EncEx(const u1 * pu1PubKeyQx, const u1 * pu1PubKeyQy, u4 u4FinalFlag, BlkSm2Ctx* pblkSm2Ctx, const u1 * pu1Plain, u4 u4PlainLen, u1 * pu1Cipher, u4 * pu4CipherLen);


	// 先要设置好结构中的AlgId和ModLen
	u4 CALL_TYPE EsAsymGenKeyPair(BlkAsymKey* pblkAsymKey);

#	define	PADDING_TYPE_ZERO		0x00	// padding 00
#	define	PADDING_TYPE_PKCS_1		0x01	// padding fmt: 00 01 FF...FF 00 Data
#	define	PADDING_TYPE_PKCS_2		0x02	// padding fmt: 00 02 PS 00 Data
#	define	PADDING_TYPE_PKCS_5		0x05	// padding fmt: XX[XX]
#	define	PADDING_TYPE_PKCS_9		0x09	// padding fmt: 00 09 FF...FF 00 Data
#	define	PADDING_TYPE_7816		0x80	// padding fmt: Data 80 00..00，如果Data是满分组，就不补足
	u4 CALL_TYPE EsPadding(const void* pvOrgData, u4 u4OrgDataLen, u4 u4PaddingType, u4 u4ModOrBlockLen, void* pvOutData, u4* pu4OutDataLen);
	u4 CALL_TYPE EsPaddingRemove(const void* pvOrgData, u4 u4OrgDataLen, u4 u4PaddingType, u4 u4ModOrBlockLen, void* pvOutData, u4 *pu4OutDataLen);
		


	//-------------------------------------------------------------------------------------------------
	// EsCommonList

	typedef void*	(CALL_TYPE *FunNewData)(const void* pvData);
	typedef int		(CALL_TYPE *FunFreeData)(void* pvNodeData);
	typedef int		(CALL_TYPE *FunCompareData)(const void* pvNodeData, const void* pvData);
	typedef u4		(CALL_TYPE *FunTravelData)(const void* pvNodeData, const void* pvParam);
	
	// 三个指针函数可以为空，内部使用默认函数
	u4 CALL_TYPE EsListInit(ESHANDLE* phList, FunNewData funNewData, FunFreeData funFreeData, FunCompareData funCompareData);
	// 默认删除函数为空，也就是不对节点数据做任何处理
	u4 CALL_TYPE EsListRelease(ESHANDLE hList);
	// 设置新增加节点时的回调函数，在EsListAdd函数中被调用
	u4 CALL_TYPE EsListSetFunNew(ESHANDLE hList, FunNewData funNewData);
	// 设置新删除节点时的回调函数，在EsListRelease、EsListDelete函数中被调用
	u4 CALL_TYPE EsListSetFunFree(ESHANDLE hList, FunFreeData funFreeData);
	// 设置新比较节点时的回调函数，在EsListFind、EsListDelete函数中被调用
	u4 CALL_TYPE EsListSetFunCompare(ESHANDLE hList, FunCompareData funCompareData);
	// 默认建立函数是不做任何处理，只将pvNodeData保存在链表中
	u4 CALL_TYPE EsListAdd(ESHANDLE hList, const void* pvNodeData);
	// 默认建立函数是不做任何处理，只将pvNodeData保存在链表的尾部
	u4 CALL_TYPE EsListAddTail(ESHANDLE hList, const void* pvNodeData);
	// 查找相同数据的节点，如果没有比较回调函数，只是简单地比较节点地址
	u4 CALL_TYPE EsListFind(ESHANDLE hList, const void* pvFindData, void** ppvNodeData);
	// 删除数据，如果没有比较回调函数，只是简单地比较节点地址
	u4 CALL_TYPE EsListDelete(ESHANDLE hList, const void* pvFindData);
	// 删除数据，如果回调函数为NULL，采用已经设置好的比较回调函数
	u4 CALL_TYPE EsListDeleteAll(ESHANDLE hList, const void* pvFindData, FunCompareData funCompareData);
	// 生成一个ID值（最高字节保持为00，只生成三个字节的数据），使得这个ID值在整个链表中是唯一的
	u4 CALL_TYPE EsListGenNewId(ESHANDLE hList, u4* pu4Id);
	// 遍历整个链表，遍历过程中调用传入的回调函数，如果回调函数返回失败，则不继续遍历
	u4 CALL_TYPE EsListTravel(ESHANDLE hList, FunTravelData funTravelData, const void* pvParam);
	// 更新一个节点的内容，内部调用删除、新建的回调函数，注意：此函数会改变节点数据的指针
	u4 CALL_TYPE EsListUpdate(ESHANDLE hList, const void* pvUpdateData);
	// 合并两个链表，最终结果存储在hListDst中
	u4 CALL_TYPE EsListMerge(ESHANDLE hListSrc, ESHANDLE hListDst);
	// 查找链表中下一个节点保存的数据，pvDataPrev为NULL表示查找链表头
	u4 CALL_TYPE EsListGetNext(ESHANDLE hList, const void* pvDataPrev, void** ppvDataNext);

	//-------------------------------------------------------------------------------------------------
	// EsCommonDArray

	u4 CALL_TYPE DArrayInit(ESHANDLE* phHandle);
	u4 CALL_TYPE DArrayAppend(ESHANDLE hHandle, const void* pvData, u4 u4DataSize);
	void* CALL_TYPE DArrayGetData(ESHANDLE hHandle);
	u4 CALL_TYPE DArrayGetSize(ESHANDLE hHandle);
	u4 CALL_TYPE DArrayRelease(ESHANDLE hHandle);
#define EsArrayInit		DArrayInit
#define EsArrayAppend	DArrayAppend
#define EsArrayGetData	DArrayGetData
#define EsArrayGetSize	DArrayGetSize
#define EsArrayRelease	DArrayRelease
	//-------------------------------------------------------------------------------------------------
	// EsCommonEncode
	// encode & decode

	// Base64
	// 返回编码后的长度
	u4 CALL_TYPE EsBase64Encode(const u1* pu1Src, u4 u4SrcLen, char * pszBase64code, u4 u4Base64BufLen);
	// 返回解码后的长度
	u4 CALL_TYPE EsBase64Decode(const char * pszBase64code, u4 u4Base64CodeLen, u1 * pu1Buf);

	// Der 
	// 返回编码后的长度（含TLV）
	// 编码OID时忽略参数u4ValueLen
	u4 CALL_TYPE EsDerEncode(u4 u4Tag, const void* pvValue, u4 u4ValueLen, u1* pu1Der);
	// 返回元素的大小（含TLV）
	u4 CALL_TYPE EsDerGetElementLen(u1* pu1Der, u4* pu4LenLen);
	u4 CALL_TYPE EsDerGetTagAndLen(const u1* pu1DerData, u4 u4DerDataLen, u2* pu2Tag, u4* pu4ValueLen, u4* pu4TagLenSize);
    u4 CALL_TYPE EsDerSkipTlv(u1** ppu1Data, u4* pu4DataLen, u2 u2ExpectTag);
    void CALL_TYPE EsDerEncodePubKey(const BlkAsymKey *pblkAsymPubKey, u1* pu1PubKeyEncoded, u4 * pu4PubKeyEncodedLen);
    u4 CALL_TYPE EsDerDecodePubKey(const u1* pu1PubKeyEncoded, u4 u4PubKeyEncodedLen, BlkAsymKey * pblkAsymKey);
    void CALL_TYPE EsDerEncodePriKey(const BlkAsymKey* pblkAsymKey, u1* pu1DerPriKey, u4* pu4DerPriKeyLen);
    u4 CALL_TYPE EsDerDecodePriKey(const u1* pu1DerPriKey, u4 u4DerPriKeyLen, BlkAsymKey* pblkAsymKey);
    u4 CALL_TYPE EsDerEncodeSm2Signature(const u1* pu1Sm2Signature, u4 u4SignatureLen, u1* pu1DerSignature, u4* pu4DerSignatureLen);
    u4 CALL_TYPE EsDerDecodeSm2Signature(const u1* pu1DerSignature, u4 u4DerSignatureLen, u1* pu1Signature, u4* pu4SignatureLen);

	// Cert
	typedef enum EN_CERT_PARAM
	{
		CERT_PARAM_VALID_TIME_BEGIN = 0,	// YYMMDDHHMMSS
		CERT_PARAM_VALID_TIME_END = 1,		// YYMMDDHHMMSS
		CERT_PARAM_SIGN_ALG = 2,			// [4] ES_ASYM_ALG_XXX
	}EN_CERT_PARAM;

	// pu4ValueLen IN OUT
	u4 CALL_TYPE EsCertGetParam(const u1* pu1Cert, EN_CERT_PARAM enCertParam, u1* pu1Value, u4* pu4ValueLen);


	//-------------------------------------------------------------------------------------------------
	// EsCommonMisc

	// memory operation
	void CALL_TYPE EsGenUuid(char* pszUuid);
	void CALL_TYPE EsGetRand(void* pvRand, u4 u4RandLen);
	ESBOOL CALL_TYPE EsGetVidPidFromName(const char* pszDevName, u4* pu4VidPid);

    u4 CALL_TYPE EsMemAlloc(void** ppvMem, const void* pvData, u4 u4MemLen);
    void CALL_TYPE EsMemFree(void** ppvMem);
    u4 CALL_TYPE EsFileRead(const char* pszFileName, ESBOOL bTxtFile, void** ppvFileData, u4* pu4FileDataLen);
    u4 CALL_TYPE EsFileWrite(const char* pszFileName, ESBOOL bTxtFile, const void* pvFileData, u4 u4FileDataLen, ESBOOL bAppend);

	u4 CALL_TYPE EsMemCmpValue(const void* pvData, u1 u1Value, u4 u4DataLen);
	void CALL_TYPE EsMemRev(void* pvData, u4 u4DataLen);
	void CALL_TYPE EsMemXor(const void* pvInput, void* pvOutput, u4 u4DataLen);
	void CALL_TYPE EsMemNeg(void* pvData, u4 u4DataLen);
    void CALL_TYPE EsMemSafeClear(void* pvData, u4 u4DataLen);

	u4 CALL_TYPE EsGetReturnData(const void *pvRealData, u4 u4RealDataLen, void *pvOutData, u4* pu4OutDataLen);
	u4 CALL_TYPE EsGetReturnString(const char* szOrgString, u4 u4OrgStringLen, char* szReturnString, u4* pu4ReturnStringLen);
	u4 CALL_TYPE EsGetReturnCount(const void* pvOrgElement, u4 u4OrgElementLen, void* pvReturnElement, u4* pu4ReturnElementCount, u4 u4ElementSize);

	void CALL_TYPE EsConvertName(const char* szOrgName, char* szDstName);
	u4 CALL_TYPE EsAsc2Hex(const char* szAsc, void* pvHex);
	u4 CALL_TYPE EsHex2Asc(const void* pvHex, u4 u4HexLen, char* szAsc);
	u4 CALL_TYPE EsHex2AscNoZeroLeading(const void* pvHex, u4 u4HexLen, char* szAsc);
	typedef struct BlkIdNameInfoTag
	{
		u4			m_u4Id;
		char		m_szName[0x20];
	}BlkIdNameInfo;
	char* CALL_TYPE EsFindNameViaId(u4 u4Id, const BlkIdNameInfo* pblkIdNameInfo);
	u4 CALL_TYPE EsFindIdViaName(const char* szName, const BlkIdNameInfo* pblkIdNameInfo);

	u4 CALL_TYPE EsChar2WChar(const char* pszString, wchar_t* pszwString, u4* pu4WStringLen);
	u4 CALL_TYPE EsWChar2Char(const wchar_t* pszwString, char* pszString, u4* pu4StringLen);
	u4 CALL_TYPE EsPfxParse(const char* pszPfxFileName, const char* pszPassword, BlkAsymKey* pblkAsymKey, void* pvCert, u4* pu4CertLen);
	u4 CALL_TYPE EsGetCurrentPath(char* pszFilePath);

#if 0
#		define OutputDebugStr_Str(szTitle)								_OutputDebugStr_Str(szTitle)
#		define OutputDebugStr_DWORD(szTitle, dwData)					_OutputDebugStr_DWORD(szTitle, dwData)
#		define OutputDebugStr_BOOL(szTitle, bValue)						_OutputDebugStr_BOOL(szTitle, bValue)
#		define OutputDebugStr_ByteArray(szTitle, pbData, dwDataLen)		_OutputDebugStr_ByteArray(szTitle, pbData, dwDataLen)
//#		define OutputDebugStr_Fmt(szFmt, ...)							_OutputDebugStr_Fmt(szFmt, __VA_ARGS__)
#else
#		define OutputDebugStr_Str(szTitle)
#		define OutputDebugStr_DWORD(szTitle, dwData)
#		define OutputDebugStr_BOOL(szTitle, bValue)
#		define OutputDebugStr_ByteArray(szTitle, pbData, dwDataLen)
//#		define OutputDebugStr_Fmt(szFmt, ...)
#endif
		void _OutputDebugStr_Str(char* szTitle);	
		void _OutputDebugStr_DWORD(char* szTitle, u4 dwData);
		void _OutputDebugStr_BOOL(char* szTitle, int bValue);
		void _OutputDebugStr_ByteArray(char* szTitle, u1* pbData, u4 dwDataLen);
		void _OutputDebugStr_Fmt(char* szFmt, ...);
#ifdef __cplusplus
}
#endif

#include "EsCommonLog.h"
#define IF_ERROR_GOTO_END()			do{if( 0 != u4Result ) {ES_LOG((LOG_TYPE_INFORMATION, FILE_AND_LINE, "u4Result = %08X", u4Result));goto END;}}while(0)

#define BYTE2U4(pu1Data)			(((u4)((pu1Data)[0])<<24) + ((u4)((pu1Data)[1])<<16) + ((u2)((pu1Data)[2])<<8) + (u1)((pu1Data)[3]))
#define BYTE2WORD(pu1Data)			((u2)(((u2)((pu1Data)[0])<<8) + (u1)((pu1Data)[1])))
#define U42BYTE(pu1Data,u4Data)	((u1*)(pu1Data))[0] = (u1)((u4Data)>>24);((u1*)(pu1Data))[1] = (u1)((u4Data)>>16);((u1*)pu1Data)[2] = (u1)((u4Data)>>8);((u1*)pu1Data)[3] = (u1)((u4Data))
#define WORD2BYTE(pu1Data,u2Data)	((u1*)(pu1Data))[0] = (u1)((u2Data)>>8);((u1*)(pu1Data))[1] = (u1)((u2Data))


#define VAR_OFFSET(structname,var)	((u4)(&((structname *)NULL)->var))

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif




#endif // _ES_COMMON_H_
