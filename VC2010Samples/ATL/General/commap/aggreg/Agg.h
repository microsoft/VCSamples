// Agg.h : Declaration of the CAgg
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

class CAgg :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAgg, &CLSID_CAgg>,
	public IDispatchImpl<IAgg, &IID_IAgg, &LIBID_AGGREGLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public ISupportErrorInfo	
{
public:
	CAgg(){}
BEGIN_COM_MAP(CAgg)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IAgg)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CAgg)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

DECLARE_REGISTRY_RESOURCEID(IDR_Agg)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IAgg
public:
	STDMETHOD(get_Name)(BSTR* pbstrName);
};

OBJECT_ENTRY_AUTO(__uuidof(CAgg), CAgg)