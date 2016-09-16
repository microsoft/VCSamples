// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
// AutoServ.h : Declaration of the CAutoServ

#pragma once
#include "resource.h"       // main symbols

[emitidl];

	[
		object,
		uuid("1E2BF8D5-BF3B-4E35-BB79-90949E6A7349"),
		dual,
		helpstring("IAutoServ Interface"),
		pointer_default(unique)
	]
	__interface IAutoServ : IDispatch
	{
		[id(1), helpstring("method Sleep")] HRESULT Sleep(long delay);
	};

	
/////////////////////////////////////////////////////////////////////////////
// CAutoServ
[
	coclass,
	uuid("3CD5B892-A27C-445D-AF50-8841D67F371E"),
	helpstring("AutoServ Class"),
	version("1.0"),
	progid("AutoServer.AutoServ.1"),
	default("IAutoServ"),
	vi_progid("AutoServer.AutoServ"),
	registration_script("AutoServer.rgs"),
	threading(apartment)
]
class ATL_NO_VTABLE CAutoServ : 
	public IAutoServ
{
public:
	CAutoServ()
	{
	}

	
//Must use this macro so the auto thread class
//factory is used.
//To remove the CComAutoThreadModule properties comment out the next line
DECLARE_CLASSFACTORY_AUTO_THREAD()
DECLARE_PROTECT_FINAL_CONSTRUCT()


// IAutoServ
public:
	STDMETHOD(Sleep)(long delay);
};
STDMETHODIMP CAutoServ::Sleep(long delay)
{
	//put this thread to sleep for a bit.
	::Sleep(delay);
	return S_OK;
}


