#ifndef _ES_COMMON_H_
#define _ES_COMMON_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../EsTypeDef.h"
#include "../EsError.h"

#if defined(_OS_WINDOWS_)
#	include <windows.h>
#	include <process.h>
#	include <stdarg.h>
#	include <tchar.h>

#elif defined (_OS_IOS_)
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
#   include <sys/stat.h>
#   include <netinet/in.h>
#   include <netdb.h>
#   include <arpa/inet.h>
#   include <sys/types.h>
#   include <sys/fcntl.h>
#   include <sys/socket.h>
#   include <sys/times.h>

#elif defined _OS_LINUX_
#	include <ctype.h>
#elif defined _OS_WPHONE_
#	include <windows.h>
#	include <synchapi.h>
#	include <tchar.h>
#elif defined _OS_ANDROID_
#   include <errno.h>
#   include <time.h>
#   include <pthread.h>
#   include <unistd.h>
#   include <sys/times.h>
#   include <stdarg.h>
#   include <linux/shm.h>
#   include <sys/ipc.h>
#   include <ctype.h>
#	include <sys/socket.h>
#	include <arpa/inet.h>
#	include <sys/types.h>
#elif defined _OS_MAC_OSX_
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
#else
#	pragma message("NO OS type macro defined !!!!!!")
#endif

#ifdef _OS_WINDOWS_
	#pragma comment(lib, "crypt32.lib")
#endif

#define IF_ERROR_GOTO_END()			do{if( 0 != u4Result ) {ES_LOG((LOG_TYPE_INFORMATION, FILE_AND_LINE, "u4Result = %08X", u4Result));goto END;}}while(0)

#define BYTE2U4(pu1Data)			(((u4)((pu1Data)[0])<<24) + ((u4)((pu1Data)[1])<<16) + ((u2)((pu1Data)[2])<<8) + (u1)((pu1Data)[3]))
#define BYTE2WORD(pu1Data)			((u2)(((u2)((pu1Data)[0])<<8) + (u1)((pu1Data)[1])))
#define U42BYTE(pu1Data,u4Data)	((u1*)(pu1Data))[0] = (u1)((u4Data)>>24);((u1*)(pu1Data))[1] = (u1)((u4Data)>>16);((u1*)pu1Data)[2] = (u1)((u4Data)>>8);((u1*)pu1Data)[3] = (u1)((u4Data))
#define WORD2BYTE(pu1Data,u2Data)	((u1*)(pu1Data))[0] = (u1)((u2Data)>>8);((u1*)(pu1Data))[1] = (u1)((u2Data))


#define VAR_OFFSET(structname,var)	((long)(&((structname *)NULL)->var))

#ifndef _countof
#define _countof(array) (sizeof(array)/sizeof(array[0]))
#endif

#ifndef MAX_PATH
#   define MAX_PATH					260
#endif

// Safe string apis
#include "EsString.h"

// Mutex apis
#include "EsMutex.h"

// Event apis
#include "EsEvent.h"

// Thread apis
#include "EsThread.h"

// ShareMemory apis
#include "EsShareMem.h"

// System apis
#include "EsSystem.h"

// Algorithm apis
#include "EsAlgorithm.h"

// List apis
#include "EsList.h"

// Array apis
#include "EsArray.h"

// EncodeDecode apis
#include "EsEncodeDecode.h"

// MemoryOperation apis
#include "EsMemory.h"

// P10 apis
#include "EsP10.h"

// P7 apis
#include "EsP7.h"

// Xml apis
#include "EsXml.h"

// Tlv apis
#include "EsTlv.h"

// Log apis
#include "EsLog.h"

#include "EsCommServer.h"

#include "EsCommClient.h"

#ifdef __cplusplus
extern "C" 
{
#endif
	u4 CALL_TYPE EsCommonLibInit(void);
	u4 CALL_TYPE EsCommonLibRelease(void);

#ifdef __cplusplus
}
#endif

#endif // _ES_COMMON_H_
