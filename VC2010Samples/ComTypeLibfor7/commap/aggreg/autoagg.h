// AutoAgg.h : Declaration of the CAutoAgg
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.


#include "aggres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Aggreg

class CAutoAgg : 
    public CComDualImpl<IAutoAgg, &__uuidof(IAutoAgg), &LIBID_AGGREGLib>, 
    public ISupportErrorInfo,
    public CComObjectRoot,
    public CComCoClass<CAutoAgg,&__uuidof(CoAutoAgg)>
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
