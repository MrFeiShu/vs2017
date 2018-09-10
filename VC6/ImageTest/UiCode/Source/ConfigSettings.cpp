#include "StdAfx.h"
#include <MYbankSettings.h>
#include <shlwapi.h>
#include <EsCommon/EsCommon.h>

static BOOL MYbankGetCfgPath(LPTSTR pszPath, DWORD cchPathLen)
{
    TCHAR   szPath[MAX_PATH];
    int     nRet = 0;
	
    SHGetSpecialFolderPath(NULL, szPath, CSIDL_COMMON_DOCUMENTS, 0);
    EsTcsCat(szPath, MAX_PATH, TEXT("\\MYbank_ExcelSecu"));
	
    if ( !PathFileExists(szPath) )
    {
        nRet = SHCreateDirectoryEx(NULL, szPath, NULL);
        if ( 0 != nRet ) return FALSE;
    }
	
    EsTcsCat(szPath, sizeof(szPath), TEXT("\\MYbankSettings.cfg"));
    if ( !PathFileExists(szPath) )
    {
        HANDLE hFile = CreateFile(szPath, 
            GENERIC_WRITE|GENERIC_READ, 
            0, 
            NULL, 
            CREATE_ALWAYS, 
            FILE_ATTRIBUTE_NORMAL, 
            NULL);
		CloseHandle(hFile);
    }
	
    return EsTcsCopy(pszPath, cchPathLen, szPath) ? TRUE : FALSE;
}

BOOL MYbankGetDwordOptions(LPCTSTR pszOptName, DWORD dwDefVal, DWORD* pdwOptVal)
{
    TCHAR   szCfgPath[MAX_PATH];
    BOOL    bRet = TRUE;
	
    bRet = MYbankGetCfgPath(szCfgPath, MAX_PATH);
    if ( !bRet ) return bRet;
	
    *pdwOptVal = GetPrivateProfileInt(TEXT("Option"), pszOptName, dwDefVal, szCfgPath);
	
    return bRet;
}

BOOL MYbankSetDwordOptions(LPCTSTR pszOptName, DWORD dwOptVal)
{
    TCHAR   szCfgPath[MAX_PATH];
    TCHAR   szValue[20];
    BOOL    bRet = TRUE;
    
    bRet = MYbankGetCfgPath(szCfgPath, MAX_PATH);
    if ( !bRet ) return bRet;
    
    EsTcsPrintf(szValue, _countof(szValue), TEXT("%d"), dwOptVal);
    bRet = WritePrivateProfileString(TEXT("Option"), pszOptName, szValue, szCfgPath);
    
    return bRet;
}

