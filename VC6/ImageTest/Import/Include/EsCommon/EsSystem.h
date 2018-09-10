#ifndef _ES_SYSTEM_H_
#define _ES_SYSTEM_H_

#ifdef __cplusplus
extern "C" 
{
#endif

	#define LANG_ID_SIPMLE_CHINESE			2052
	#define LANG_ID_TRADITIONAL_CHINESE		1028
	#define LANG_ID_ENGLISH_US				1033
	#define ESPRODCUT_PARAM_LANG            0x01
	#define ESPRODCUT_PARAM_VIRTUAL_DESKTOP			0x02

	#pragma pack(push, 1)
	typedef struct BlkProductParamTag
	{
		int nLangId;
		u4 u4UseVirtualDesktop;
		unsigned char pucReserved[512-sizeof(int)-4];
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
	#define OS_WIN81	0x0603
	#define OS_WIN10	0x1000
	#define OS_UNKNOWN	0xFFFFFFFF
	u4 CALL_TYPE EsOsGetVersion(void);
	u4 CALL_TYPE EsOsGetFileVersion(const char* szFileName, char* szFileVersion, u4* pu4VersionLen);

	ESBOOL CALL_TYPE EsOsIs64Bit();
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

#ifdef __cplusplus
};
#endif

#endif