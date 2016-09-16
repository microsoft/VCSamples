// AutoAgg.cpp : Implementation of CAggregApp and DLL registration.
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#include "preagg.h"
#include "AutoAgg.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CAutoAgg::InterfaceSupportsErrorInfo(REFIID riid)
{
    if (riid == __uuidof(IAutoAgg))
        return S_OK;
    return S_FALSE;
}

STDMETHODIMP CAutoAgg::get_Name(BSTR* pbstrName)
{
    *pbstrName = ::SysAllocString(L"IAutoAgg");
    return S_OK;
}
