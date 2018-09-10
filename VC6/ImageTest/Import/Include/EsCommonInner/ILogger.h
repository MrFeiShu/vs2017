///////////////////////////////////////////////////////////
//  ILogger.h
//  Implementation of the Class ILogger
//  Created on:      17-一月-2013 17:05:47
///////////////////////////////////////////////////////////

#if !defined(EA_54A0108C_CC29_4755_9111_EB58298A94C7__INCLUDED_)
#define EA_54A0108C_CC29_4755_9111_EB58298A94C7__INCLUDED_
//#include "EsTypeDef.h"
#include <EsCommon/EsCommon.h>
#pragma warning(disable:4786) // VC6中使用stl，编译时有许多4786警告
#pragma pack(push, 1)

typedef enum LOG_TYPE
{
	LogUnknown = 0,
	LogInformation,
	LogWarning,
	LogError
}LOG_TYPE;

typedef struct tagBlkLogItem 
{
	LOG_TYPE	enLogType; 
	char		szFile[0x80];
	u8			u8Time;
	u4			u4PID;
	u4			u4TID;
	u4			u4Line;
	char		szLog[0x0800 * 2 + 0x08];

	u8			u8PerformanceCounter; // 高精度计数器，LogViewer以此来排序
	u1			pu1Reserved[0x1400 - sizeof(LOG_TYPE) - 0x80 - sizeof(u8)*2 - sizeof(u4)*3 - 0x0800 * 2 - 0x08];
	
	// 拷贝构造函数
	tagBlkLogItem (const tagBlkLogItem& other)
	{
		memcpy(this, &other, sizeof(tagBlkLogItem));
	}
	tagBlkLogItem ()
	{
		memset(&enLogType, 0, sizeof(tagBlkLogItem));
	}
}BlkLogItem;

#pragma pack(pop)

typedef enum EnLogDestination
{
	LOG_TO_VIEWER =1,
	LOG_TO_FILE = 2,
	LOG_TO_FILE_FORMATTED = 3
}EnLogDestination;

typedef struct tagBlkLogParam
{
	EnLogDestination enLogDest;
}BlkLogParam;

class ILogger
{

public:
	virtual void Initialize(const BlkLogParam& blkLogParam) = 0;
	virtual void Log(LOG_TYPE enLogType, const char* szFile, u4 u4Line, const char* lpszFormat, ...) = 0;

};


#endif // !defined(EA_54A0108C_CC29_4755_9111_EB58298A94C7__INCLUDED_)
