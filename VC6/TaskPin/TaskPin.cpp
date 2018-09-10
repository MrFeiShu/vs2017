// TaskbarShortcut.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include <shlobj.h>

/************************************************************************/
/* 
/* ������Դ��https://github.com/prestocore/browser/blob/8c5977d18f4ed8aea10547829127d52bc612a725/platforms/windows/WindowsShortcut.cpp
/* �������ܣ������������������������
/* ����������
/* lpPath��Ҫ����������ļ���·��
/* lpFileName��Ҫ����������ļ����ļ���
/* bIsPin��TRUE Ϊ�����ļ�����������FALSE Ϊ��������������Ĭ��Ϊ FALSE
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
	
    // �� Win7 Ĭ�ϵ� Media Player ��ݷ�ʽ��������ȡ���̶�
    TaskbarPin(
        _T("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs"),
        _T("Windows Media Player.lnk")
		);
	
    // �� Win7 Ĭ�ϵ� IE ��ݷ�ʽ��������ȡ���̶�
    TaskbarPin(
        _T("C:\\Users\\Administrator\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs"),
        _T("Internet Explorer.lnk")
		);
	
    CoUninitialize();
    return 0;
}