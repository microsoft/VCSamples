// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\general\autothread\autoserver\autoserver.mrg.cpp
// compiler-generated file created 09/15/17 at 22:35:15
//
// This C++ source file is intended to be a representation of the
// source code injected by the compiler.  It may not compile or
// run exactly as the original source file.
//


//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute providers

#pragma message("\n\nNOTE: This merged source file should be visually inspected for correctness.\n\n")
//--- End Injected Code

// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
// AutoServer.cpp : Implementation of WinMain


// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f AutoServerps.mk in the project directory.

#include "stdafx.h"
#include "resource.h"
#include <initguid.h>

#include "AutoServ.h"


const DWORD dwTimeOut = 5000; // time for EXE to be idle before shutting down
const DWORD dwPause = 1000; // time to wait for threads to finish up

[emitidl];
[module(exe, name="AutoServerLib", uuid="{A6D89F0F-35F4-11D2-9375-00C04FD9757C}", helpstring="AutoServer 1.0 Type Library")];

//+++ Start Injected Code For Attribute 'module'
#injected_line 27 "AutoServer.cpp"
extern "C" const __declspec(selectany) GUID __LIBID_ = {0xa6d89f0f,0x35f4,0x11d2,{0x93,0x75,0x00,0xc0,0x4f,0xd9,0x75,0x7c}};
struct __declspec(uuid("a6d89f0f-35f4-11d2-9375-00c04fd9757c")) AutoServerLib;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 27 "AutoServer.cpp"

class CAutoServerLibModule;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 27 "AutoServer.cpp"

extern CAutoServerLibModule _AtlModule;

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 27 "AutoServer.cpp"

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nShowCmd);

//--- End Injected Code For Attribute 'module'


//+++ Start Injected Code For Attribute 'module'
#injected_line 27 "AutoServer.cpp"

class CAutoServerLibModule : public CAtlExeModuleT<CAutoServerLibModule>
    								
{
public:
    DECLARE_LIBID(__uuidof(AutoServerLib))
        								
};

#injected_line 27 "AutoServer.cpp"

CAutoServerLibModule _AtlModule;

#injected_line 27 "AutoServer.cpp"

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPTSTR lpCmdLine, int nShowCmd)
    					
{
    return _AtlModule.WinMain(nShowCmd);
}

//--- End Injected Code For Attribute 'module'

CAtlAutoThreadModule _AtlAutoThreadModule;
class CAppExeModule : public CAtlAutoThreadModule
{
public:
	LONG Unlock();
	DWORD dwThreadID;
	HANDLE hEventShutdown;
	void MonitorShutdown();
	bool StartMonitor();
	bool bActivity;
};

// Passed to CreateThread to monitor the shutdown event
static DWORD WINAPI MonitorProc(void* pv)
{
    CAppExeModule* p = (CAppExeModule*)pv;
    p->MonitorShutdown();
    return 0;
}

LONG CAppExeModule::Unlock()
{
    LONG l = _pAtlModule->Unlock();
    if (l == 0)
    {
        bActivity = true;
        SetEvent(hEventShutdown); // tell monitor that we transitioned to zero
    }
    return l;
}
//Monitors the shutdown event
void CAppExeModule::MonitorShutdown()
{
    while (1)
    {
        WaitForSingleObject(hEventShutdown, INFINITE);
        DWORD dwWait=0;
        do
        {
            bActivity = false;
            dwWait = WaitForSingleObject(hEventShutdown, dwTimeOut);
        } while (dwWait == WAIT_OBJECT_0);
        // timed out
			
        if (!bActivity && _pAtlModule->m_nLockCnt == 0) // if no activity let's really bail
        {
#if defined(_ATL_FREE_THREADED)
            CoSuspendClassObjects();
            if (!bActivity && _pAtlModule->m_nLockCnt == 0)
#endif
                break;
        }
    }
    CloseHandle(hEventShutdown);
    PostThreadMessage(dwThreadID, WM_QUIT, 0, 0);
}

bool CAppExeModule::StartMonitor()
{
    hEventShutdown = CreateEvent(NULL, false, false, NULL);
    if (hEventShutdown == NULL)
        return false;
    DWORD dwThreadID;
    HANDLE h = CreateThread(NULL, 0, MonitorProc, this, 0, &dwThreadID);
    return (h != NULL);
}

LPCTSTR FindOneOf(LPCTSTR p1, LPCTSTR p2)
{
    while (p1 != NULL && *p1 != NULL)
    {
        LPCTSTR p = p2;
        while (p != NULL && *p != NULL)
        {
            if (*p1 == *p)
                return CharNext(p1);
            p = CharNext(p);
        }
        p1 = CharNext(p1);
    }
    return NULL;
}
