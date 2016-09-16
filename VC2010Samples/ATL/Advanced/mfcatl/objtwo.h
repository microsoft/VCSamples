// ObjTwo.h : header file
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#pragma once
#include "Resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CObjectTwo: ATL implementation

class CObjectTwo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CObjectTwo, &CLSID_ObjectTwo>,
	public IDispatchImpl<IObjectTwo, &IID_IObjectTwo, &LIBID_MfcAtl, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:

DECLARE_NOT_AGGREGATABLE(CObjectTwo)
DECLARE_REGISTRY_RESOURCEID(IDR_OBJECTTWO)

BEGIN_COM_MAP(CObjectTwo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectTwo)
END_COM_MAP()

// IObjectTwo
public:
	STDMETHOD(get_SayHello)(BSTR* bstr);
};

OBJECT_ENTRY_AUTO(CLSID_ObjectTwo, CObjectTwo)