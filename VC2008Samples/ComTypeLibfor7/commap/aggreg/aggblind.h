// AggBlind.h : Declaration of the CAggBlind
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

class CAggBlind : 
    public CComDualImpl<IAggBlind, &__uuidof(IAggBlind), &LIBID_AGGREGLib>, 
    public ISupportErrorInfo,
    public CComObjectRoot,
    public CComCoClass<CAggBlind,&__uuidof(CoAggBlind)>
{
public:
    CAggBlind(){}
BEGIN_COM_MAP(CAggBlind)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IAggBlind)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(CAggBlind) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation.  The default is to support it

DECLARE_REGISTRY_RESOURCEID(IDR_AggBlind)
// ISupportsErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IAggBlind
public:
    STDMETHOD(get_Name)(BSTR* pbstrName);
};
