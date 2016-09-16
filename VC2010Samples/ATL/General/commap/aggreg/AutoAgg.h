// AutoAgg.h : Declaration of the CAutoAgg
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Aggreg

class CAutoAgg :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAutoAgg, &CLSID_CAutoAgg>,
	public IDispatchImpl<IAutoAgg, &IID_IAutoAgg, &LIBID_AGGREGLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ISupportErrorInfo
{
public:
	CAutoAgg(){}
BEGIN_COM_MAP(CAutoAgg)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IAutoAgg)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CAutoAgg)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

DECLARE_REGISTRY_RESOURCEID(IDR_AutoAgg)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IAutoAgg
public:
	STDMETHOD(get_Name)(BSTR* pbstrName);
};

OBJECT_ENTRY_AUTO(__uuidof(CAutoAgg), CAutoAgg)