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

#include "mapres.h"       // main symbols
#include "Chain.h"
#include "aggreg\agg.h"
#include "COMMapIface.h"

/////////////////////////////////////////////////////////////////////////////
// COMMap
class COuter;
class CTearOff1:
public IDispatchImpl<ITearOff1, &__uuidof(ITearOff1)>,
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
public IDispatchImpl<ITearOff2, &__uuidof(ITearOff2)>,
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

[emitidl];
#include "COMMapIface.h"
[
	coclass,
	uuid("CAE80FFC-E058-430B-AEC2-64C7585B5EBE"),
	helpstring("Outer Class"),
	version("1.0"),
	progid("COMMap.Outer.1"),
	vi_progid("COMMap.Outer"),
	threading(both),
	registration_script("Outer.rgs"),
	default(IOuter),
	implements_category("CATID_Control"),
	com_interface_entry("COM_INTERFACE_ENTRY2(IDispatch,IOuter)"),
	com_interface_entry("COM_INTERFACE_ENTRY_TEAR_OFF(__uuidof(ITearOff1), CTearOff1)"),
	com_interface_entry("COM_INTERFACE_ENTRY_CACHED_TEAR_OFF(__uuidof(ITearOff2), CTearOff2, m_pUnkTearOff2.p)"),
	com_interface_entry("COM_INTERFACE_ENTRY_AGGREGATE(__uuidof(IAgg), m_pUnkAgg.p)"),
	com_interface_entry("COM_INTERFACE_ENTRY_AGGREGATE_BLIND(m_pUnkAggBlind.p)"),
	com_interface_entry("COM_INTERFACE_ENTRY_AUTOAGGREGATE(__uuidof(IAutoAgg), m_pUnkAutoAgg.p, __uuidof(CAutoAgg))"),
	com_interface_entry("COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(m_pUnkAutoAggB.p, __uuidof(CAutoAggB))"),
	com_interface_entry("COM_INTERFACE_ENTRY(ISupportErrorInfo)")
]
class COuter :
	public CChainBase,
	public IOuter
{
public:
	COuter(){}
	~COuter(){}
	HRESULT FinalConstruct();
	void FinalRelease();

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

#endif // _OUTER_H
