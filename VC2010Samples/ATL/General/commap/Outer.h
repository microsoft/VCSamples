// Outer.h : Declaration of the COuter
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
//
#ifndef _OUTER_H
#define _OUTER_H

#include "resource.h"       // main symbols
#include "chain.h"
#include "aggreg\aggreg.h"

/////////////////////////////////////////////////////////////////////////////
// COMMap

class COuter;

class CTearOff1:
	public IDispatchImpl<ITearOff1, &IID_ITearOff1, &LIBID_COMMAPLib>,
	public CComTearOffObjectBase<COuter>
{
public:
	CTearOff1(){}
	~CTearOff1(){}

	BEGIN_COM_MAP(CTearOff1)
		COM_INTERFACE_ENTRY(ITearOff1)
	END_COM_MAP()

	HRESULT STDMETHODCALLTYPE get_Name(BSTR* pbstrName)
	{
		*pbstrName = ::SysAllocString(L"ITearOff1");
		return S_OK;
	}
};

class CTearOff2:
	public IDispatchImpl<ITearOff2, &IID_ITearOff2, &LIBID_COMMAPLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public CComTearOffObjectBase<COuter>
{
public:
	CTearOff2(){}
	~CTearOff2(){}

	BEGIN_COM_MAP(CTearOff2)
		COM_INTERFACE_ENTRY(ITearOff2)
	END_COM_MAP()

	HRESULT STDMETHODCALLTYPE get_Name(BSTR* pbstrName)
	{
		*pbstrName = ::SysAllocString(L"ITearOff2");
		return S_OK;
	}
};

class COuter :
	public CChainBase,
	public IDispatchImpl<IOuter, &IID_IOuter, &LIBID_COMMAPLib>,
	public CComCoClass<COuter,&CLSID_COuter>
{
public:
	COuter(){}
	~COuter(){}
	HRESULT FinalConstruct();
	void FinalRelease();
BEGIN_COM_MAP(COuter)
	COM_INTERFACE_ENTRY2(IDispatch, IOuter)
	COM_INTERFACE_ENTRY(IOuter)
	COM_INTERFACE_ENTRY_TEAR_OFF(IID_ITearOff1, CTearOff1)
	COM_INTERFACE_ENTRY_CACHED_TEAR_OFF(IID_ITearOff2, CTearOff2, m_pUnkTearOff2.p)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IAgg, m_pUnkAgg.p)
	COM_INTERFACE_ENTRY_AGGREGATE_BLIND(m_pUnkAggBlind.p)
	COM_INTERFACE_ENTRY_AUTOAGGREGATE(IID_IAutoAgg, m_pUnkAutoAgg.p, CLSID_CAutoAgg)
	COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(m_pUnkAutoAggB.p, CLSID_CAutoAggB)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY_CHAIN(CChainBase)
END_COM_MAP()
//DECLARE_NOT_AGGREGATABLE(COuter)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

DECLARE_REGISTRY_RESOURCEID(IDR_Outer)
DECLARE_GET_CONTROLLING_UNKNOWN()
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

	CComPtr<IUnknown> m_pUnkTearOff2;
	CComPtr<IUnknown> m_pUnkAgg;
	CComPtr<IUnknown> m_pUnkAggBlind;
	CComPtr<IUnknown> m_pUnkAutoAgg;
	CComPtr<IUnknown> m_pUnkAutoAggB;
	CComObjectThreadModel::AutoCriticalSection m_sec;

// IOuter
public:
	STDMETHOD(GetName)(short n, BSTR* pbstrName);
};

OBJECT_ENTRY_AUTO(__uuidof(COuter), COuter)

#endif // _OUTER_H
