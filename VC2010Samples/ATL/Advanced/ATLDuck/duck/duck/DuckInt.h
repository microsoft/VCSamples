// DuckInt.h : Declaration of the CDuckInt
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __DUCKINT_H_
#define __DUCKINT_H_

#include "duck.h"
#include "resource.h"       // main symbols
/////////////////////////////////////////////////////////////////////////////
// CDuckInt
class ATL_NO_VTABLE CDuckInt :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<CDuckInt, &CLSID_DuckInt>,
	public IDuckInt
{
public:
	CDuckInt()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DUCKINT)
DECLARE_NOT_AGGREGATABLE(CDuckInt)

BEGIN_COM_MAP(CDuckInt)
	COM_INTERFACE_ENTRY(IDuckInt)
END_COM_MAP()

// IDuckInt
public:
	STDMETHOD(Walk)(BSTR szWhosCalling);
	STDMETHOD(Paddle)(BSTR szWhosCalling);
	STDMETHOD(Flap)(BSTR szWhosCalling);
	STDMETHOD(Quack)(BSTR szWhosCalling);
protected:
};
OBJECT_ENTRY_AUTO(CLSID_DuckInt, CDuckInt)

#endif //__DUCKINT_H_
