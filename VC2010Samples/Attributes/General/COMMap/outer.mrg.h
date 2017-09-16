// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\general\commap\outer.mrg.h
// compiler-generated file created 09/15/17 at 22:30:34
//
// This C++ source file is intended to be a representation of the
// source code injected by the compiler.  It may not compile or
// run exactly as the original source file.
//


//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute providers

#pragma message("\n\nNOTE: This merged source file should be visually inspected for correctness.\n\n")
//--- End Injected Code

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
#if 0
//+++ Base class was replaced:
	
	public IOuter

#endif
	/*+++ Added Baseclass */ public IDispatchImpl<IOuter, &__uuidof(IOuter)>,
    /*+++ Added Baseclass */ public IProvideClassInfoImpl<&__uuidof(COuter)>
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

	//+++ Start Injected Code For Attribute 'coclass'
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    static DWORD* GetOpCodes() 
    {
        static DWORD rgOps[] = 
            					{
            						0x70000000,
            0x20004000,
            0x30004000,
            0x80000002,
            0x50000000,
            0x3000c000,
            0x80000004,
            0x50000000,
            0x60000000,
            0x60000000,
            0x20014000,
            0x30014000,
            0x80000002,
            0x50000000,
            0x30018000,
            0x80000001,
            0x50000000,
            0x60000000,
            0x60000000,
            0x1000c000,
            0x3000c000,
            0x50000000,
            0x20010000,
            0x30010000,
            0x80000002,
            0x50000000,
            0x8001c008,
            0x30024000,
            0x80000001,
            0x50000000,
            0x60000000,
            0x30028000,
            0x80000005,
            0x50000000,
            0x60000000,
            0x3002c000,
            0x8000000c,
            0x50000000,
            0x8003400e,
            0x60000000,
            0x60000000,
            0x60000000,
            0x60000000,
            0
            					};
        return rgOps;
    }
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    static RGSDWORD* GetOpcodeDWORDVals() 
    {
        static RGSDWORD rgDWORDS[] = 
            					{
            						{0, 0}
            					};
        return rgDWORDS;
    }
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    static RGSBinary* GetOpcodeBinaryVals() 
    {

        static RGSBinary rgBinary[] = 
            					{
            						{0, 0}
            					};
        return rgBinary;
    }
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    static RGSStrings* GetOpcodeStringVals() 
    {
        static RGSStrings rgStrings[] = 
            					{
            						{_T(""),0 }, 
            {_T("COMMap.Outer.1"),0 }, 
            {_T("Outer Class"),0 }, 
            {_T("CLSID"),0 }, 
            {_T("{CAE80FFC-E058-430B-AEC2-64C7585B5EBE}"),0 }, 
            {_T("COMMap.Outer"),0 }, 
            {_T("CurVer"),0 }, 
            {_T("AppID"),0 }, 
            {_T("{4F9A68DE-DD9D-11CF-9462-00AA00BBAD7F}"),0 }, 
            {_T("ProgID"),0 }, 
            {_T("VersionIndependentProgID"),0 }, 
            {_T("%MODULETYPE%"),1 }, 
            {_T("%MODULE%"),1 }, 
            {_T("ThreadingModel"),0 }, 
            {_T("both"),0 }, 
            {NULL, 0}
            					};
        return rgStrings;
    }
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) 
    {
        CRegistryVirtualMachine rvm;
        HRESULT hr;
        if (FAILED(hr = rvm.AddStandardReplacements()))
            return hr;
        rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());
        return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(), GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);
    }
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    static const TCHAR* GetObjectFriendlyName() 
    {
        return _T("COuter Object");
    }
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    static const TCHAR* GetProgID() 
    {
        return _T("COMMap.Outer.1");
    }
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    static const TCHAR* GetVersionIndependentProgID() 
    {
        return _T("COMMap.Outer");
    }
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"
    BEGIN_COM_MAP(COuter)
        COM_INTERFACE_ENTRY2(IDispatch,IOuter)
        COM_INTERFACE_ENTRY_TEAR_OFF(__uuidof(ITearOff1), CTearOff1)
        COM_INTERFACE_ENTRY_CACHED_TEAR_OFF(__uuidof(ITearOff2), CTearOff2, m_pUnkTearOff2.p)
        COM_INTERFACE_ENTRY_AGGREGATE(__uuidof(IAgg), m_pUnkAgg.p)
        COM_INTERFACE_ENTRY_AGGREGATE_BLIND(m_pUnkAggBlind.p)
        COM_INTERFACE_ENTRY_AUTOAGGREGATE(__uuidof(IAutoAgg), m_pUnkAutoAgg.p, __uuidof(CAutoAgg))
        COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(m_pUnkAutoAggB.p, __uuidof(CAutoAggB))
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
        COM_INTERFACE_ENTRY(IChain)
        COM_INTERFACE_ENTRY2(IDispatch, IChain)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
        COM_INTERFACE_ENTRY(IOuter)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
    END_COM_MAP()
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"

    BEGIN_CATEGORY_MAP(COuter)
        IMPLEMENTED_CATEGORY(CATID_Control)
    END_CATEGORY_MAP()

	//--- End Injected Code For Attribute 'coclass'
}

//+++ Start Injected Code For Attribute 'coclass'
#injected_line 64 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Outer.h"

				OBJECT_ENTRY_AUTO(__uuidof(COuter), COuter)
			
//--- End Injected Code For Attribute 'coclass'
;

#endif // _OUTER_H
