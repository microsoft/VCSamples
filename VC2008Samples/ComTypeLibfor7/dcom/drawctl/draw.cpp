// Draw.cpp : Implementation of CDrawCtl
#include "stdafx.h"
#include "Draw.h"

/////////////////////////////////////////////////////////////////////////////
// CDrawCtl

STDMETHODIMP CDrawCtl::InterfaceSupportsErrorInfo(REFIID riid)
{
    static const IID* arr[] = 
    {
        &__uuidof(IDrawCtl),
    };
    for (int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
    {
        if (InlineIsEqualGUID(*arr[i],riid))
            return S_OK;
    }
    return S_FALSE;
}
