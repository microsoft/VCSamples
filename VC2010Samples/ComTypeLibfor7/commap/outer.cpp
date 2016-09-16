// Outer.cpp : Implementation of CCOMMapApp and DLL registration.
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
#include "Outer.h"


/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP COuter::InterfaceSupportsErrorInfo(REFIID riid)
{
    if (CChainBase::InterfaceSupportsErrorInfo(riid) == S_OK)
        return S_OK;
    if (riid == __uuidof(IOuter))
        return S_OK;
    return S_FALSE;
}

HRESULT COuter::FinalConstruct()
{
    IUnknown* pUnkOuter = GetControllingUnknown();

    HRESULT hRes = CoCreateInstance(__uuidof(CoAgg), pUnkOuter, CLSCTX_INPROC_SERVER, __uuidof(IUnknown), (void**)&m_pUnkAgg);
    if (hRes != S_OK)
        return hRes;

    hRes = CoCreateInstance(__uuidof(CoAggBlind), pUnkOuter, CLSCTX_INPROC_SERVER, __uuidof(IUnknown), (void**)&m_pUnkAggBlind);
    if (hRes != S_OK)
        return hRes;

    return S_OK;
}

void COuter::FinalRelease()
{ 
    m_pUnkTearOff2.Release();
    m_pUnkAgg.Release();
    m_pUnkAggBlind.Release();
    m_pUnkAutoAgg.Release();
    m_pUnkAutoAggB.Release();
}

STDMETHODIMP COuter::GetName(short n, BSTR* pbstrName)
{
    try {
    switch(n)
    {
    case 0:
            *pbstrName = ::SysAllocString(L"IOuter"); return S_OK;
    case 1:
        {
            ITearOff1Ptr pITearOff1 = GetControllingUnknown();
            return pITearOff1->get_Name(pbstrName);
            break;
        }
    case 2:
        {
            ITearOff2Ptr pITearOff2 = GetControllingUnknown();
            return pITearOff2->get_Name(pbstrName);
            break;
        }
    case 3:
        {
            IChainPtr pIChain = GetControllingUnknown();
            return pIChain->get_Name2(pbstrName);
            break;
        }
    case 4:
        {
            IAggPtr pIAgg = GetControllingUnknown();
            return pIAgg->get_Name(pbstrName);
            break;
        }
    case 5:
        {
            IAutoAggPtr pIAutoAgg = GetControllingUnknown();
            return pIAutoAgg->get_Name(pbstrName);
            break;
        }
    case 6:
        {
            IAggBlindPtr pIAggBlind = GetControllingUnknown();
            return pIAggBlind->get_Name(pbstrName);
            break;
        }
    case 7:
        {
            IAutoAggBPtr pIAutoAggB = GetControllingUnknown();
            return pIAutoAggB->get_Name(pbstrName);
            break;
        }
    }
    return Error(_T("Interface type out of range"));
    } catch(...) {
    return Error(_T("No interface"));
    }
}
