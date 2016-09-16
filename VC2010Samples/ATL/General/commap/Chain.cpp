// Chain.cpp : Implementation of CCOMMapApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "premap.h"
#include "COMMap.h"
#include "Chain.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CChainBase::InterfaceSupportsErrorInfo(REFIID riid)
{
	if (riid == IID_IChain)
		return S_OK;
	return S_FALSE;
}

STDMETHODIMP CChainBase::get_Name2(BSTR* pbstrName)
{
	*pbstrName = ::SysAllocString(L"IChain");
	return S_OK;
}
