// AutoAggB.h : Declaration of the CAutoAggB
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "aggres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Aggreg
[emitidl];
#include "AggregIface.h"
[
	coclass,
	uuid("4CA740C4-92B7-4F39-8309-C6DA39D7A255"),
	helpstring("AutoAggB Class"),
	version("1.0"),
	progid("Aggreg.AutoAggB.1"),
	vi_progid("Aggreg.AutoAggB"),
	threading(both),
	support_error_info("IAutoAggB"),
	default("IAutoAggB")
]
class CAutoAggB : public IAutoAggB
{
public:
	CAutoAggB(){}

// IAutoAggB
public:
	STDMETHOD(get_Name)(BSTR* pbstrName)
	{
		*pbstrName = ::SysAllocString(L"IAutoAggB");
		return S_OK;
	}

};
