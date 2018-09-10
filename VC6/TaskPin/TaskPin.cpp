// TaskbarShortcut.cpp : 定义控制台应用程序的入口点。
//

#include <shlobj.h>

/************************************************************************/
/* 
/* 代码来源：https://github.com/prestocore/browser/blob/8c5977d18f4ed8aea10547829127d52bc612a725/platforms/windows/WindowsShortcut.cpp
/* 函数功能：将程序锁定或从任务栏解锁
/* 函数参数：
/* lpPath：要锁定或解锁文件的路径
/* lpFileName：要锁定或解锁文件的文件名
/* bIsPin：TRUE 为锁定文件到任务栏，FALSE 为从任务栏解锁，默认为 FALSE
/* 
/************************************************************************/

BOOL TaskbarPin(LPTSTR lpPath, LPTSTR lpFileName, BOOL bIsPin = FALSE)
{
    BOOL bRet = FALSE;
    HMENU hmenu = NULL;
    LPSHELLFOLDER pdf = NULL;
    LPSHELLFOLDER psf = NULL;
    LPITEMIDLIST pidl = NULL;
    LPITEMIDLIST pitm = NULL;
    LPCONTEXTMENU pcm = NULL;
	
    if (SUCCEEDED(SHGetDesktopFolder(&pdf))
        && SUCCEEDED(pdf->ParseDisplayName(NULL, NULL, lpPath, NULL, &pidl,  NULL))
        && SUCCEEDED(pdf->BindToObject(pidl, NULL, IID_IShellFolder, (void **)&psf))
        && SUCCEEDED(psf->ParseDisplayName(NULL, NULL, lpFileName, NULL, &pitm,  NULL))
        && SUCCEEDED(psf->GetUIObjectOf(NULL, 1, (LPCITEMIDLIST *)&pitm, IID_IContextMenu, NULL, (void **)&pcm))
        && (hmenu = CreatePopupMenu()) != NULL
        && SUCCEEDED(pcm->QueryContextMenu(hmenu, 0, 1, INT_MAX, CMF_NORMAL)))
    {
        CMINVOKECOMMANDINFO ici = { sizeof(CMINVOKECOMMANDINFO), 0 };
        ici.hwnd = NULL;
        ici.lpVerb = bIsPin ? "taskbarpin" : "taskbarunpin";
        pcm->InvokeCommand(&ici);
        bRet = TRUE;
    }
	
    if (hmenu)
        DestroyMenu(hmenu);
    if (pcm)
        pcm->Release();
    if (pitm)
        CoTaskMemFree(pitm);
    if (psf)
        psf->Release();
    if (pidl)
        CoTaskMemFree(pidl);
    if (pdf)
        pdf->Release();
	
    return bRet;
}

int _tmain(int argc, _TCHAR* argv[])
{
    CoInitialize(nullptr);
	
    // 将 Win7 默认的 Media Player 快捷方式从任务栏取消固定
    TaskbarPin(
        _T("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs"),
        _T("Windows Media Player.lnk")
		);
	
    // 将 Win7 默认的 IE 快捷方式从任务栏取消固定
    TaskbarPin(
        _T("C:\\Users\\Administrator\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs"),
        _T("Internet Explorer.lnk")
		);
	
    CoUninitialize();
    return 0;
}