// Agg.h : Declaration of the CAgg
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
#pragma once
#include "aggres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Aggreg
[emitidl];
#include "AggregIface.h"
[
	coclass,
	uuid("B27F2CE1-D1B9-42B3-9E4C-9E7CA7767043"),
	helpstring("Agg Class"),
	version("1.0"),
	progid("Aggreg.Agg.1"),
	vi_progid("Aggreg.Agg"),
	threading(both),
	support_error_info("IAgg"),
	default("IAgg")
]
class CAgg : public IAgg
{
public:
	CAgg(){}
//DECLARE_NOT_AGGREGATABLE(CAgg)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

// IAgg
public:
	STDMETHOD(get_Name)(BSTR* pbstrName)
	{
		*pbstrName = ::SysAllocString(L"IAgg");
		return S_OK;
	}
};
