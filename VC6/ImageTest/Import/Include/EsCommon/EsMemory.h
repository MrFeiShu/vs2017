#ifndef _ES_MEMORY_H_
#define _ES_MEMORY_H_

#ifdef __cplusplus
extern "C" {
#endif

	// memory operation
	void CALL_TYPE EsGenUuid(char* pszUuid);
	void CALL_TYPE EsGetRand(void* pvRand, u4 u4RandLen);
	ESBOOL CALL_TYPE EsGetVidPidFromName(const char* pszDevName, u4* pu4VidPid);

	u4 CALL_TYPE EsMemAlloc(void** ppvMem, const void* pvData, u4 u4MemLen);
	void CALL_TYPE EsMemFree(void** ppvMem);
	u4 CALL_TYPE EsFileRead(const char* pszFileName, void** ppvFileData, u4* pu4FileDataLen);
	u4 CALL_TYPE EsFileWrite(const char* pszFileName, const void* pvFileData, u4 u4FileDataLen, ESBOOL bAppend);
	u4 CALL_TYPE EsFileReadPart(const char* pszFileName, u4 u4Offset, void* pvData, u4 u4DataLen);
	u4 CALL_TYPE EsFileWritePart(const char* pszFileName, u4 u4Offset, const void* pvData, u4 u4DataLen);

	u4 CALL_TYPE EsMemCmpValue(const void* pvData, u1 u1Value, u4 u4DataLen);
	void CALL_TYPE EsMemRev(void* pvData, u4 u4DataLen);
	void CALL_TYPE EsMemXor(const void* pvInput, void* pvOutput, u4 u4DataLen);
	void CALL_TYPE EsMemNeg(void* pvData, u4 u4DataLen);
	void CALL_TYPE EsMemSafeClear(void* pvData, u4 u4DataLen);

	u4 CALL_TYPE EsGetReturnData(const void *pvRealData, u4 u4RealDataLen, void *pvOutData, u4* pu4OutDataLen);
	u4 CALL_TYPE EsGetReturnString(const char* szOrgString, u4 u4OrgStringLen, char* szReturnString, u4* pu4ReturnStringLen);
	u4 CALL_TYPE EsGetReturnCount(const void* pvOrgElement, u4 u4OrgElementLen, void* pvReturnElement, u4* pu4ReturnElementCount, u4 u4ElementSize);

	void CALL_TYPE EsStringReplaceChar(const char* szOrgName, char* szDstName);
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
//	u4 CALL_TYPE EsPfxParse(const char* pszPfxFileName, const char* pszPassword, BlkAsymKey* pblkAsymKey, void* pvCert, u4* pu4CertLen);
	u4 CALL_TYPE EsGetCurrentPath(char* pszFilePath);

#ifdef __cplusplus
};
#endif

#endif
