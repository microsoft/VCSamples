// AutoAgg.cpp : Implementation of CAggregApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "preagg.h"
#include "Aggreg.h"
#include "AutoAgg.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CAutoAgg::InterfaceSupportsErrorInfo(REFIID riid)
{
	if (riid == IID_IAutoAgg)
		return S_OK;
	return S_FALSE;
}

STDMETHODIMP CAutoAgg::get_Name(BSTR* pbstrName)
{
	*pbstrName = ::SysAllocString(L"IAutoAgg");
	return S_OK;
}
