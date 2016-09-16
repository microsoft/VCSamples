// AutoAgg.h : Declaration of the CAutoAgg
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
	uuid("501153E5-FAD9-4E5C-9C3D-8CC815D4F60E"),
	helpstring("AutoAgg Class"),
	version("1.0"),
	progid("Aggreg.AutoAgg.1"),
	vi_progid("Aggreg.AutoAgg"),
	threading(both),
	support_error_info("IAutoAgg"),
	default("IAutoAgg")
]
class CAutoAgg  : public IAutoAgg
{
public:
	CAutoAgg(){}
//DECLARE_NOT_AGGREGATABLE(CAutoAgg)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

// IAutoAgg
public:
	STDMETHOD(get_Name)(BSTR* pbstrName)
	{
		*pbstrName = ::SysAllocString(L"IAutoAgg");
		return S_OK;
	}
};
