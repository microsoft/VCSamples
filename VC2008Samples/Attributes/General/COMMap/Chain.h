// Chain.h : Declaration of the CChain
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#include "mapres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COMMap
[emitidl];
#include "COMMapIface.h"
class CChainBase :
public IDispatchImpl<IChain, &__uuidof(IChain)>,
	public ISupportErrorInfo
{
public:
	CChainBase(){}
	~CChainBase(){}
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IChain
public:
	STDMETHOD(get_Name2)(BSTR* pbstrName);
};

[emitidl];
[
	coclass,
	uuid("4E5DD450-3EA0-473D-9AB5-55E7EB597348"),
	helpstring("Chain Class"),
	version("1.0"),
	progid("COMMap.Chain.1"),
	vi_progid("COMMap.Chain"),
	threading(both),
	registration_script("Chain.rgs"),
	default("IChain")
]
class CChain :
	public CChainBase
{
public:
//DECLARE_NOT_AGGREGATABLE(CChainBase)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

};
