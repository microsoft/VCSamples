// Drive.cpp : Implementation of WinMain
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// You will need the NT SUR Beta 2 SDK or VC 4.2 in order to build this
// project.  This is because you will need MIDL 3.00.15 or higher and new
// headers and libs.  If you have VC 4.2 installed, then everything should
// already be configured correctly.

#include "predrive.h"
#import "..\_connect.tlb" no_namespace embedded_idl
[module(name="ComEvents")];

struct DECLSPEC_UUID("4F97A33D-CD6E-42d0-9D0D-D7994218A539")
CRondom;

/////////////////////////////////////////////////////////////////////////////
// CDriver
[ event_receiver(com)]
class CDriver{
public:
// IRandomEvent
	HRESULT Fire(long l)
	{
		_tprintf(_T("%d\n"), l);
		return S_OK;
	}
	void Hook(IRandom* pSrc)
	{
		HRESULT hr = __hook(&IRandomEvent::Fire, pSrc, &CDriver::Fire);
		if(FAILED(hr)){
			printf("Failed to hook up event!\n");
		}
	}
    void UnHook(IRandom* pSrc) {
        __unhook(pSrc);
    }
};

int main()
{
	CoInitialize(NULL);
	{
		IRandom* pS = 0;
		HRESULT hr = CoCreateInstance(__uuidof(CRandom), NULL, CLSCTX_ALL, __uuidof(IRandom), (void **)&pS);
		ATLASSERT(!FAILED(hr));

		CDriver sink;
		sink.Hook(pS);
		for(int i = 0; i < 200; i++){
			long id = 0;
			hr = pS->Start(&id);
			if(FAILED(hr)) break;
			Sleep(1000);
		}
		sink.UnHook(pS);
		pS->StopAll();
	}
	CoUninitialize();
	return 0;
}

