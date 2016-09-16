// DrawObj.cpp : Implementation of CDrawServApp and DLL registration.
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#include "predraw.h"
#include "DrawServ.h"
#include "DrawObj.h"

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CDrawObj::InterfaceSupportsErrorInfo(REFIID riid)
{
    if (riid == IID_IDrawServ)
        return S_OK;
    return S_FALSE;
}
