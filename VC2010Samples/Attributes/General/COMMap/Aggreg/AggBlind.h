// AggBlind.h : Declaration of the CAggBlind
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
	uuid("A86DF044-ED8E-40AD-B00A-EAE3D6DE49AA"),
	helpstring("AggBlind Class"),
	version("1.0"),
	progid("Aggreg.AggBlind.1"),
	vi_progid("Aggreg.Blind"),
	threading(both),
	support_error_info("IAggBlind"),
	default("IAggBlind")
]
class CAggBlind  : public IAggBlind
{
public:
	CAggBlind(){}
//DECLARE_NOT_AGGREGATABLE(CAggBlind)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

	// IAggBlind
public:
	STDMETHOD(get_Name)(BSTR* pbstrName)
	{
		*pbstrName = ::SysAllocString(L"IAggBlind");
		return S_OK;
	}
};
