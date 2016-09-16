// AggBlind.cpp : Implementation of CAggregApp and DLL registration.
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
#include "AggBlind.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CAggBlind::InterfaceSupportsErrorInfo(REFIID riid)
{
	if (riid == IID_IAggBlind)
		return S_OK;
	return S_FALSE;
}

STDMETHODIMP CAggBlind::get_Name(BSTR* pbstrName)
{
	*pbstrName = ::SysAllocString(L"IAggBlind");
	return S_OK;
}
