// Chain.h : Declaration of the CChain
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.


#include "mapres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COMMap

class CChainBase : 
    public CComDualImpl<IChain, &__uuidof(IChain), &LIBID_COMMAPLib>, 
    public ISupportErrorInfo,
    public CComObjectRoot
{
public:
    CChainBase(){}
    ~CChainBase(){}
BEGIN_COM_MAP(CChainBase)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY(IChain)
    COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
// ISupportsErrorInfo
    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IChain
public:
    STDMETHOD(get_Name2)(BSTR* pbstrName);
};

class CChain : 
    public CChainBase,
    public CComCoClass<CChain,&__uuidof(CoChain)>
{
public:
//DECLARE_NOT_AGGREGATABLE(CChainBase) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation.  The default is to support it

DECLARE_REGISTRY_RESOURCEID(IDR_Chain)
};
