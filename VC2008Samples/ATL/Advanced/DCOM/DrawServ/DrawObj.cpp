// DrawObj.cpp : Implementation of CDrawServApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

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
