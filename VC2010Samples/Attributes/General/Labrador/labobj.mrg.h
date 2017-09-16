// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\general\labrador\labobj.mrg.h
// compiler-generated file created 09/15/17 at 22:19:24
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

// LabObj.h : Declaration of the CLabrador
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
#ifndef _LABOBJ_H_
#define _LABOBJ_H_

#include "labres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Beeper

//[emitidl];

#define MAX_MY_BSTR_LEN 32
typedef [string] WCHAR MY_BSTR[MAX_MY_BSTR_LEN];
/////////////////////////////////////////////////////////////////////////////
// Iserviceobj
[
		object,
		uuid(8CC00B42-2860-4D28-88D9-DD3A6F92896E),
		helpstring("IMammal Interface")
]
__interface IMammal 
{
	[helpstring("method GetSpeciesName")]HRESULT GetSpeciesName([out, string] MY_BSTR p);
	[helpstring("method IsAlive")]HRESULT IsAlive([out] BOOL* pBool);
};

[
		object,
		uuid(B9688DC3-9B57-4C37-A7D7-078BECD52FA6),
		helpstring("IDog Interface")
]
__interface IDog 
{
	[helpstring("method GetPetName")]HRESULT GetPetName([out, string] MY_BSTR p);
	[helpstring("method SetPetName")]HRESULT SetPetName([in, string] MY_BSTR p);
	[helpstring("method IsBarking")]HRESULT IsBarking([out] BOOL* pBool);
};


/////////////////////////////////////////////////////////////////////////////
// CLabrador
[
	coclass,
	threading(apartment),
	progid("LABRADOR.Labrador.1"),
	vi_progid("LABRADOR.Labrador"),
	aggregatable(never),
	version(1.0),
	uuid("CE8E837C-7A09-4C98-82D3-844D9BBF4AAD"),
	default("IMammal")
	
]
class CLabrador :
	public IMammal,
	public IDog
,
    /*+++ Added Baseclass */ public IProvideClassInfoImpl<&__uuidof(CLabrador)>
{
public:
	CLabrador();

// IDog
	STDMETHOD(GetPetName)(MY_BSTR pStr);
	STDMETHOD(SetPetName)(MY_BSTR pStr);
	STDMETHOD(IsBarking)(BOOL* pBool);

// IMammal
	STDMETHOD(GetSpeciesName)(MY_BSTR pStr);
	STDMETHOD(IsAlive)(BOOL* pBool);

private:
	WCHAR   m_szPetName[32];
	WCHAR   m_szSpeciesName[32];
	BOOL    m_bIsBarking;
	BOOL    m_bIsAlive;

	//+++ Start Injected Code For Attribute 'coclass'
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    static DWORD* GetOpCodes() 
    {
        static DWORD rgOps[] = 
            					{
            						0x70000000,
            0x30004000,
            0x80000002,
            0x50000000,
            0x3000c000,
            0x80000004,
            0x50000000,
            0x60000000,
            0x60000000,
            0x30014000,
            0x80000002,
            0x50000000,
            0x3000c000,
            0x80000004,
            0x50000000,
            0x60000000,
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
            0x3001c000,
            0x80000001,
            0x50000000,
            0x60000000,
            0x30020000,
            0x80000005,
            0x50000000,
            0x60000000,
            0x20024000,
            0x30024000,
            0x50000000,
            0x60000000,
            0x30028000,
            0x8000000b,
            0x50000000,
            0x8003000d,
            0x60000000,
            0x8003800f,
            0x30040000,
            0x80000011,
            0x50000000,
            0x60000000,
            0x60000000,
            0x60000000,
            0x60000000,
            0
            					};
        return rgOps;
    }
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    static RGSDWORD* GetOpcodeDWORDVals() 
    {
        static RGSDWORD rgDWORDS[] = 
            					{
            						{0, 0}
            					};
        return rgDWORDS;
    }
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    static RGSBinary* GetOpcodeBinaryVals() 
    {

        static RGSBinary rgBinary[] = 
            					{
            						{0, 0}
            					};
        return rgBinary;
    }
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    static RGSStrings* GetOpcodeStringVals() 
    {
        static RGSStrings rgStrings[] = 
            					{
            						{_T(""),0 }, 
            {_T("LABRADOR.Labrador.1"),0 }, 
            {_T("%FriendlyName%"),1 }, 
            {_T("CLSID"),0 }, 
            {_T("{CE8E837C-7A09-4C98-82D3-844D9BBF4AAD}"),0 }, 
            {_T("LABRADOR.Labrador"),0 }, 
            {_T("CurVer"),0 }, 
            {_T("ProgID"),0 }, 
            {_T("VersionIndependentProgID"),0 }, 
            {_T("Programmable"),0 }, 
            {_T("%MODULETYPE%"),1 }, 
            {_T("%MODULE%"),1 }, 
            {_T("ThreadingModel"),0 }, 
            {_T("apartment"),0 }, 
            {_T("AppID"),0 }, 
            {_T("%APPID%"),1 }, 
            {_T("TypeLib"),0 }, 
            {_T("%MODULEGUID%"),1 }, 
            {NULL, 0}
            					};
        return rgStrings;
    }
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) 
    {
        CRegistryVirtualMachine rvm;
        HRESULT hr;
        if (FAILED(hr = rvm.AddStandardReplacements()))
            return hr;
        rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());
        return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(), GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);
    }
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    static const TCHAR* GetObjectFriendlyName() 
    {
        return _T("CLabrador Object");
    }
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"

    DECLARE_NOT_AGGREGATABLE(CLabrador);

#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    static const TCHAR* GetProgID() 
    {
        return _T("LABRADOR.Labrador.1");
    }
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    static const TCHAR* GetVersionIndependentProgID() 
    {
        return _T("LABRADOR.Labrador");
    }
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"
    BEGIN_COM_MAP(CLabrador)
        COM_INTERFACE_ENTRY(IMammal)
        COM_INTERFACE_ENTRY(IDog)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
    END_COM_MAP()

	//--- End Injected Code For Attribute 'coclass'
}

//+++ Start Injected Code For Attribute 'coclass'
#injected_line 52 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\labrador\\LabObj.h"

				OBJECT_ENTRY_AUTO(__uuidof(CLabrador), CLabrador)
			
//--- End Injected Code For Attribute 'coclass'
;

#endif
