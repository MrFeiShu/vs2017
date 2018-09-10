#ifndef _DRIVER_TYPE_H_
#define _DRIVER_TYPE_H_

//----------------------------------------------------------------------------
// device list callback
typedef u4 (CALL_TYPE *FunListCallback)(const char *szDevName, u4 u4DevType);
//----------------------------------------------------------------------------
// interface

// 模块初始化
typedef u4 (CALL_TYPE *FunProtocolInit)(void);

// 模块反初始化
typedef u4 (CALL_TYPE *FunProtocolFinal)(void);

// 枚举设备，对每一个找到的设备调用funCallback
typedef u4 (CALL_TYPE *FunProtocolListDev)(FunListCallback funCallback);

// 连接获得设备句柄
typedef u4 (CALL_TYPE *FunProtocolConnectDev)(char * pszDevName, ESHANDLE *phDev);

// 锁住此设备，可以为NULL
typedef u4 (CALL_TYPE *FunProtocolLockDev)(ESHANDLE hDev);
// 释放此设备，可以为NULL
typedef u4 (CALL_TYPE *FunProtocolUnLockDev)(ESHANDLE hDev);

// 根据设备名称获取VID、PID
typedef u4 (CALL_TYPE *FunProtocolGetVidPidViaName)(const char * pszDevName, u4 *pu4VidPid);

// 释放设备句柄
typedef u4 (CALL_TYPE *FunProtocolDisconnectDev)(ESHANDLE hDev);

// 发送指令
#if defined (_OS_WINDOWS_) | defined (_OS_MAC_OSX_)
typedef u4 (CALL_TYPE *FunProtocolSendApdu)(ESHANDLE hDev, u4 u4Enc, const u1 *pu1Send, u4 u4SendLen, u1 *pu1Recv, u4 *pu4RecvLen);
#endif

#if defined (_OS_IOS_) | defined (_OS_ANDROID_) 
typedef u4 (CALL_TYPE *FunProtocolSendApdu)(ESHANDLE hDev, const u1 *pu1Send, u4 u4SendLen, u1 *pu1Recv, u4 *pu4RecvLen);
#endif

// 复位设备
typedef u4 (CALL_TYPE *FunProtocolReset)(ESHANDLE hDev, u1 *pu1Atr, u4 *pu4AtrLen);

//-----------------------------------------------------------------------------
typedef struct BlkProtocolFuncTag
{
	FunProtocolInit				m_funInit;
	FunProtocolFinal			m_funFinal;
	FunProtocolListDev			m_funList;
	FunProtocolGetVidPidViaName m_funGetVidPidViaName;
	FunProtocolConnectDev		m_funConnect;
	FunProtocolLockDev			m_funLock;
	FunProtocolUnLockDev		m_funUnLock;
	FunProtocolDisconnectDev	m_funDisconnect;
	FunProtocolSendApdu			m_funSendApdu;
	FunProtocolReset			m_funReset;
}BlkProtocolFunc;

u4 CALL_TYPE GetProtocolFunc(u4 u4DevType, BlkProtocolFunc *pblkDevFunc);


#endif // _DRIVER_TYPE_H_