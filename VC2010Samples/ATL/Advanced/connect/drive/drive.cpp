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

#include "predrive.h"
#include "initguid.h"
#include "..\connect.h"

#define IID_DEFINED
#include "..\connect_i.c"

CComModule _Module;


/////////////////////////////////////////////////////////////////////////////
// CDriver

class CDriver :
	public IDispatchImpl<IRandomEvent, &IID_IRandomEvent, &LIBID_CONNECTLib>,
	public CComObjectRoot
{
public:
	CDriver() {}
BEGIN_COM_MAP(CDriver)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IRandomEvent)
END_COM_MAP()

// IRandomEvent
	STDMETHOD(Fire)(long l)
	{
		_tprintf(_T("%d\n"), l);
		return S_OK;
	}
};

/////////////////////////////////////////////////////////////////////////////
//

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/,
	LPTSTR /*lpCmdLine*/, int /*nShowCmd*/)
{
	HRESULT hRes = CoInitialize(NULL);
//  If you are running on NT 4.0 or higher you can use the following call
//  instead to make the EXE free threaded.
//  This means that calls come in on a random RPC thread
//  HRESULT hRes = CoInitializeEx(NULL, COINIT_MULTITHREADED);
	ATLASSERT(SUCCEEDED(hRes));
	_Module.Init(NULL, hInstance);

	CComObject<CDriver>* pDriver;
	IRandom* pM;
	CoCreateInstance(CLSID_CoRandom, NULL, CLSCTX_ALL, IID_IRandom, (void**)&pM);
	ATLASSERT(pM != NULL);

	long nID;
	pM->Start(&nID);
	DWORD dwTick = GetTickCount();
	while (GetTickCount()-dwTick < 3000)
	{
		CComObject<CDriver>::CreateInstance(&pDriver);
		DWORD dwAdvise = 0;
		puts("Connect");
		hRes = AtlAdvise(pM, pDriver->GetUnknown(), IID_IRandomEvent, &dwAdvise);
		Sleep(1);
		AtlUnadvise(pM, IID_IRandomEvent, dwAdvise);
		puts("Disconnect");
		Sleep(1);
	}
	pM->Stop(nID);

	pM->Release();

	CoUninitialize();
	return 0;
}
