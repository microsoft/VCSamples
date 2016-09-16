// Helper.h : Declaration of the CHelper

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

// CHelper

class ATL_NO_VTABLE CHelper : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CHelper, &CLSID_Helper>,
	public IDispatchImpl<IHelper, &IID_IHelper, &LIBID_ATLPages7Lib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CHelper()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_HELPER)


BEGIN_COM_MAP(CHelper)
	COM_INTERFACE_ENTRY(IHelper)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}

public:

	STDMETHOD(ShowSpecifiedPages)(BSTR bstrCaption, IUnknown* pUnk);
	STDMETHOD(ShowPage)(BSTR bstrCaption, BSTR bstrID, IUnknown* pUnk);
};

OBJECT_ENTRY_AUTO(__uuidof(Helper), CHelper)
