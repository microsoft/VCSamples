// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\general\commap\chain.mrg.h
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

// Chain.h : Declaration of the CChain
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#include "mapres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COMMap
[emitidl];
#include "COMMapIface.h"
class CChainBase :
public IDispatchImpl<IChain, &__uuidof(IChain)>,
	public ISupportErrorInfo
{
public:
	CChainBase(){}
	~CChainBase(){}
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IChain
public:
	STDMETHOD(get_Name2)(BSTR* pbstrName);
};

[emitidl];
[
	coclass,
	uuid("4E5DD450-3EA0-473D-9AB5-55E7EB597348"),
	helpstring("Chain Class"),
	version("1.0"),
	progid("COMMap.Chain.1"),
	vi_progid("COMMap.Chain"),
	threading(both),
	registration_script("Chain.rgs"),
	default("IChain")
]
class CChain :
	public CChainBase
,
    /*+++ Added Baseclass */ public IProvideClassInfoImpl<&__uuidof(CChain)>
{
public:
//DECLARE_NOT_AGGREGATABLE(CChainBase)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it


	//+++ Start Injected Code For Attribute 'coclass'
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
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
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
    static RGSDWORD* GetOpcodeDWORDVals() 
    {
        static RGSDWORD rgDWORDS[] = 
            					{
            						{0, 0}
            					};
        return rgDWORDS;
    }
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
    static RGSBinary* GetOpcodeBinaryVals() 
    {

        static RGSBinary rgBinary[] = 
            					{
            						{0, 0}
            					};
        return rgBinary;
    }
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
    static RGSStrings* GetOpcodeStringVals() 
    {
        static RGSStrings rgStrings[] = 
            					{
            						{_T(""),0 }, 
            {_T("COMMap.Chain.1"),0 }, 
            {_T("Chain Class"),0 }, 
            {_T("CLSID"),0 }, 
            {_T("{4E5DD450-3EA0-473D-9AB5-55E7EB597348}"),0 }, 
            {_T("COMMap.Chain"),0 }, 
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
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) 
    {
        CRegistryVirtualMachine rvm;
        HRESULT hr;
        if (FAILED(hr = rvm.AddStandardReplacements()))
            return hr;
        rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());
        return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(), GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);
    }
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
    static const TCHAR* GetObjectFriendlyName() 
    {
        return _T("CChain Object");
    }
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
    static const TCHAR* GetProgID() 
    {
        return _T("COMMap.Chain.1");
    }
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
    static const TCHAR* GetVersionIndependentProgID() 
    {
        return _T("COMMap.Chain");
    }
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"
    BEGIN_COM_MAP(CChain)
        COM_INTERFACE_ENTRY(IChain)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
    END_COM_MAP()

	//--- End Injected Code For Attribute 'coclass'
}

//+++ Start Injected Code For Attribute 'coclass'
#injected_line 36 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\Chain.h"

				OBJECT_ENTRY_AUTO(__uuidof(CChain), CChain)
			
//--- End Injected Code For Attribute 'coclass'
;
