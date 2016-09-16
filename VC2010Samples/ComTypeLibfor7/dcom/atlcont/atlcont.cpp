// AtlCont.cpp : Implementation of WinMain

// You will need the NT SUR Beta 2 SDK or VC 4.2 or higher in order to build 
// this project.  This is because you will need MIDL 3.00.15 or higher and new
// headers and libs.  If you have VC 4.2 installed, then everything should
// already be configured correctly.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f AtlContps.mak in the project directory.

#include "stdafx.h"
#include "resource.h"
#include "initguid.h"
#include "AtlCont.h"

#define IID_DEFINED
#include "AtlCont_i.c"
#include "AtlCont1.h"


LONG CExeModule::Unlock()
{
    LONG l = CComModule::Unlock();
    if (l == 0)
        PostThreadMessage(dwThreadID, WM_QUIT, 0, 0);
    return l;
}

CExeModule _Module;

BEGIN_OBJECT_MAP(ObjectMap)
    OBJECT_ENTRY(CLSID_CAtlCont, CAtlCont)
END_OBJECT_MAP()


LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2)
{
    while (*p1 != NULL)
    {
        LPCTSTR p = p2;
        while (*p != NULL)
        {
            if (*p1 == *p++)
                return p1+1;
        }
        p1++;
    }
    return NULL;
}

/////////////////////////////////////////////////////////////////////////////
//
extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, 
    HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int /*nShowCmd*/)
{
    lpCmdLine = GetCommandLine();
    HRESULT hRes = CoInitialize(NULL);
    _ASSERTE(SUCCEEDED(hRes));
    hRes = CoInitializeSecurity(NULL, -1, NULL, NULL,
            RPC_C_AUTHN_LEVEL_NONE, RPC_C_IMP_LEVEL_IDENTIFY, NULL, EOAC_NONE, NULL);
    _ASSERTE(SUCCEEDED(hRes));

    _Module.Init(ObjectMap, hInstance);
    _Module.dwThreadID = GetCurrentThreadId();
    TCHAR szTokens[] = _T("-/");

    int nRet = 0;
    BOOL bRun = TRUE;
    LPCTSTR lpszToken = FindOneOf(lpCmdLine, szTokens);
    while (lpszToken != NULL)
    {
        if (_tcsicmp(lpszToken, _T("UnregServer"))==0)
        {
            _Module.UpdateRegistryFromResource(IDR_AtlCont, FALSE);
            nRet = _Module.UnregisterServer();
            bRun = FALSE;
            break;
        }
        if (_tcsicmp(lpszToken, _T("RegServer"))==0)
        {
            _Module.UpdateRegistryFromResource(IDR_AtlCont, TRUE);
            nRet = _Module.RegisterServer(TRUE);
            bRun = FALSE;
            break;
        }
        lpszToken = FindOneOf(lpszToken, szTokens);
    }

    if (bRun)
    {
        hRes = _Module.RegisterClassObjects(CLSCTX_LOCAL_SERVER, 
            REGCLS_MULTIPLEUSE);
        _ASSERTE(SUCCEEDED(hRes));

        CComPtr<IAtlCont> pApp;
        CoCreateInstance(CLSID_CAtlCont, NULL, CLSCTX_INPROC_SERVER, IID_IAtlCont, (void**)&pApp);
        if (pApp)
            pApp->Run();

        MSG msg;
        while (GetMessage(&msg, 0, 0, 0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        _Module.RevokeClassObjects();
    }
    CoUninitialize();
    return nRet;
}
