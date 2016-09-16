// Chain.cpp : Implementation of CCOMMapApp and DLL registration.
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#include "premap.h"
#include "Chain.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CChainBase::InterfaceSupportsErrorInfo(REFIID riid)
{
    if (riid == __uuidof(IChain))
        return S_OK;
    return S_FALSE;
}

STDMETHODIMP CChainBase::get_Name2(BSTR* pbstrName)
{
    *pbstrName = ::SysAllocString(L"IChain");
    return S_OK;
}
