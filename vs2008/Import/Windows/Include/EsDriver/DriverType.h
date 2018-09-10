#ifndef _DRIVER_TYPE_H_
#define _DRIVER_TYPE_H_

//----------------------------------------------------------------------------
// device list callback
typedef u4 (CALL_TYPE *FunListCallback)(const char *szDevName, u4 u4DevType);
//----------------------------------------------------------------------------
// interface

// ģ���ʼ��
typedef u4 (CALL_TYPE *FunProtocolInit)(void);

// ģ�鷴��ʼ��
typedef u4 (CALL_TYPE *FunProtocolFinal)(void);

// ö���豸����ÿһ���ҵ����豸����funCallback
typedef u4 (CALL_TYPE *FunProtocolListDev)(FunListCallback funCallback);

// ���ӻ���豸���
typedef u4 (CALL_TYPE *FunProtocolConnectDev)(char * pszDevName, ESHANDLE *phDev);

// ��ס���豸������ΪNULL
typedef u4 (CALL_TYPE *FunProtocolLockDev)(ESHANDLE hDev);
// �ͷŴ��豸������ΪNULL
typedef u4 (CALL_TYPE *FunProtocolUnLockDev)(ESHANDLE hDev);

// �����豸���ƻ�ȡVID��PID
typedef u4 (CALL_TYPE *FunProtocolGetVidPidViaName)(const char * pszDevName, u4 *pu4VidPid);

// �ͷ��豸���
typedef u4 (CALL_TYPE *FunProtocolDisconnectDev)(ESHANDLE hDev);

// ����ָ��
#if defined (_OS_WINDOWS_) | defined (_OS_MAC_OSX_)
typedef u4 (CALL_TYPE *FunProtocolSendApdu)(ESHANDLE hDev, u4 u4Enc, const u1 *pu1Send, u4 u4SendLen, u1 *pu1Recv, u4 *pu4RecvLen);
#endif

#if defined (_OS_IOS_) | defined (_OS_ANDROID_) 
typedef u4 (CALL_TYPE *FunProtocolSendApdu)(ESHANDLE hDev, const u1 *pu1Send, u4 u4SendLen, u1 *pu1Recv, u4 *pu4RecvLen);
#endif

// ��λ�豸
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