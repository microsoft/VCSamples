// ArrayManager.h : Declaration of the CArrayManager

// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#pragma once
#include "resource.h"       // main symbols

// CArrayManager

class ATL_NO_VTABLE CArrayManager : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CArrayManager, &CLSID_ArrayManager>,
	public IDispatchImpl<IArrayManager, &IID_IArrayManager, &LIBID_AtlSafeArrayLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IObjectSafetyImpl<CArrayManager, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
	CArrayManager()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ARRAYMANAGER)


BEGIN_COM_MAP(CArrayManager)
	COM_INTERFACE_ENTRY(IArrayManager)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

private:
	// array
	CComSafeArray<VARIANT> m_sa;

public:

	STDMETHOD(GetArray)(VARIANT* pvar);
	STDMETHOD(Add)(BSTR bstr);
	STDMETHOD(Remove)(ULONG nIndex);
	STDMETHOD(Change)(ULONG nIndex, BSTR bstr);
};

OBJECT_ENTRY_AUTO(__uuidof(ArrayManager), CArrayManager)
