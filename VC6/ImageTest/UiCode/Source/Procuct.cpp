#include "StdAfx.h"
#include "Product.h"
//#include "UIConfig.h"

bool GetCurrentModuleHandle(HMODULE& hMod)
{
	MEMORY_BASIC_INFORMATION info = {0};  
	int nTrick = 0;
	if ( 0 == ::VirtualQuery((void*)&GetCurrentModuleHandle, &info, sizeof(info)) )
	{
		return false;
	}
	
	hMod = (HMODULE)info.AllocationBase;  
	
	return true;
}

int GetProductInstallDir(LPCTSTR lpszProductCode, LPTSTR lpszProductDir, int nBufLen)
{
	TCHAR   szRegKeyPath[MAX_PATH];
	HKEY    hKey = NULL;
	DWORD   dwBufSize;
	LONG	lRet;
	TCHAR* lpszPos;
	
	_tcscpy(szRegKeyPath, TEXT("SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\"));
	_tcscat(szRegKeyPath, lpszProductCode);
	lRet = RegOpenKeyEx(HKEY_LOCAL_MACHINE, szRegKeyPath, 0, KEY_READ, &hKey);
	if ( 0 != lRet ) goto END;
	dwBufSize = nBufLen * sizeof(TCHAR);
	lRet = RegQueryValueEx(hKey, TEXT("UninstallString"), NULL, NULL, (LPBYTE)lpszProductDir, &dwBufSize);
	if ( 0 != lRet ) goto END;
	
	lpszPos = _tcsrchr(lpszProductDir, TEXT('\\'));
	if ( lpszPos )
	{
		*(lpszPos+1) = TEXT('\0');
	}
	else
	{
		lRet = -1;
		lpszProductDir[0] = TEXT('\0');
	}
	
END:
	if (NULL != hKey) RegCloseKey(hKey);
	return lRet;
}

int GetCurrentProductInstallDir( LPTSTR lpszProductDir, int nBufLen)
{
#if defined(_STAND_ALONE_)
    return GetProductInstallDir(PRODUCT_CODE, lpszProductDir, nBufLen);
#else
    HMODULE     hMod;
    TCHAR*      lpszPos;
    GetCurrentModuleHandle(hMod);
    GetModuleFileName(hMod, lpszProductDir, MAX_PATH);
    lpszPos = _tcsrchr(lpszProductDir, L'\\');
    if ( NULL == lpszPos ) return 1;

    *(lpszPos+1) = TEXT('\0');

    return 0;
#endif
}
