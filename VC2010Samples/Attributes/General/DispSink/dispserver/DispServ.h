// DispServ.h : Declaration of the CDispServ
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once
#include "resource.h"       // main symbols


// IDispServ
[
	object,
	uuid("B7D047AB-E688-4C9B-A956-31D6CEE5DB51"),
	dual,	helpstring("IDispServ Interface"),
	pointer_default(unique)
]
__interface IDispServ : IDispatch
{
	[id(1), helpstring("method Send")] HRESULT Send(VARIANT data);
};


// _IDispServEvents
[
	dispinterface,
	uuid("06B96B46-4F91-4087-A81F-7F20904E9A45"),
	helpstring("_IDispServEvents Interface")
]
__interface _IDispServEvents
{
	[id(1), helpstring("method Transfer")] HRESULT Transfer(VARIANT data);
};


// CDispServ

[
	coclass,
	threading(apartment),
	event_source(com),
	vi_progid("DispServer.DispServ"),
	progid("DispServer.DispServ.1"),
	version(1.0),
	default("IDispServ"),
	uuid("BD9B1276-EBE9-4E9C-B3F9-07298D8BBF4D"),
	helpstring("DispServ Class")
]
class ATL_NO_VTABLE CDispServ : 
	public IDispServ
{
public:
	CDispServ()
	{
	}

	__event __interface _IDispServEvents;

	DECLARE_PROTECT_FINAL_CONSTRUCT()
	DECLARE_CLASSFACTORY_SINGLETON(CDispServ);

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:
	STDMETHOD(Send)(VARIANT data)
	{
		_IDispServEvents_Transfer(data);
		return(S_OK);
	}
};

