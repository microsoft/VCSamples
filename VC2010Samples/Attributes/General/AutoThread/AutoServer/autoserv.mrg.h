// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\general\autothread\autoserver\autoserv.mrg.h
// compiler-generated file created 09/15/17 at 22:35:15
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

// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
// AutoServ.h : Declaration of the CAutoServ

#pragma once
#include "resource.h"       // main symbols

[emitidl];

	[
		object,
		uuid("1E2BF8D5-BF3B-4E35-BB79-90949E6A7349"),
		dual,
		helpstring("IAutoServ Interface"),
		pointer_default(unique)
	]
	__interface IAutoServ : IDispatch
	{
		[id(1), helpstring("method Sleep")] HRESULT Sleep(long delay);
	};

	
/////////////////////////////////////////////////////////////////////////////
// CAutoServ
[
	coclass,
	uuid("3CD5B892-A27C-445D-AF50-8841D67F371E"),
	helpstring("AutoServ Class"),
	version("1.0"),
	progid("AutoServer.AutoServ.1"),
	default("IAutoServ"),
	vi_progid("AutoServer.AutoServ"),
	registration_script("AutoServer.rgs"),
	threading(apartment)
]
class ATL_NO_VTABLE CAutoServ : 
	public IAutoServ
,
    /*+++ Added Baseclass */ public IProvideClassInfoImpl<&__uuidof(CAutoServ)>
{
public:
	CAutoServ()
	{
	}

	
//Must use this macro so the auto thread class
//factory is used.
//To remove the CComAutoThreadModule properties comment out the next line
DECLARE_CLASSFACTORY_AUTO_THREAD()
DECLARE_PROTECT_FINAL_CONSTRUCT()


// IAutoServ
public:
	STDMETHOD(Sleep)(long delay);

	//+++ Start Injected Code For Attribute 'coclass'
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    virtual HRESULT STDMETHODCALLTYPE IAutoServ::Invoke(
                /* [in] */ DISPID dispIdMember,
                /* [in] */ REFIID riid,
                /* [in] */ LCID lcid,
                /* [in] */ WORD wFlags,
                /* [out][in] */ DISPPARAMS *pDispParams,
                /* [out] */ VARIANT *pVarResult,
                /* [out] */ EXCEPINFO *pExcepInfo,
                /* [out] */ UINT *puArgErr) 
    {
        (void) riid;
        (void) dispIdMember;
        (void) lcid;
        (void) wFlags;
        (void) pExcepInfo;
        (void) puArgErr;
        HRESULT hr = S_OK;
        if (pDispParams == 0) {
            return DISP_E_BADVARTYPE;
        }
        if (pDispParams->cArgs > 1) {
            return DISP_E_BADPARAMCOUNT;
        }
        if (pVarResult != 0) {
            ::VariantInit(pVarResult);
        }
        ATL::CComVariant rgVars[1];
        VARIANT* rgpVars[1];
        UINT index = 0;
        for (; index < pDispParams->cArgs; ++index) {
            rgpVars[index] = &pDispParams->rgvarg[index];
        }
        VARIANT v0;
        VARIANT* v;
        switch (dispIdMember) {
        case 1:
            {
                if (pDispParams->cArgs != 1) {
                    return DISP_E_BADPARAMCOUNT;
                }
                v = rgpVars[0];
                if (v->vt != VT_I4)
            {
                    rgVars[0] = *rgpVars[0];
                    v = &rgVars[0];
                    if (FAILED(__VariantChangeType(v, &v0, VT_I4))) {
                        if (puArgErr != 0) {
                            *puArgErr = 0;
                        }
                        return DISP_E_TYPEMISMATCH;
                    }
                }
                long i1 = V_I4(v);
                hr = ((::IAutoServ*) this)->Sleep(i1);
                break;
            }
        default:
            return DISP_E_MEMBERNOTFOUND;
        }
        if (FAILED(hr) && pExcepInfo != NULL)
        {
            AtlExcepInfoFromErrorInfo(hr, pExcepInfo);
        }
        return hr;
    }
    virtual HRESULT STDMETHODCALLTYPE IAutoServ::GetIDsOfNames(
                /* [in] */ REFIID riid,
                /* [size_is][in] */ LPOLESTR *rgszNames,
                /* [in] */ UINT cNames,
                /* [in] */ LCID lcid,
                /* [size_is][out] */ DISPID *rgDispId) 
    {
        (void) riid;
        (void) rgszNames;
        (void) cNames;
        (void) lcid;
        (void) rgDispId;
        static LPOLESTR names[] = { L"delay", L"Sleep" };
        static DISPID dids[] = { 0, 1 };
        for (unsigned int i = 0; i < cNames; ++i) {
            int fFoundIt = 0;
            for (unsigned int j = 0; j < sizeof(names)/sizeof(LPOLESTR); ++j) {
                if (_wcsicmp(rgszNames[i], names[j]) == 0) {
                    fFoundIt = 1;
                    rgDispId[i] = dids[j];
                    break;
                }
            }
            if (fFoundIt == 0) {
                return DISP_E_UNKNOWNNAME;
            }
        }
        return S_OK;
    }
    HRESULT TypeInfoHelper(REFIID iidDisp, LCID /*lcid*/, ITypeInfo** ppTypeInfo) 
    {
        if (ppTypeInfo == NULL) {
            return E_POINTER;
        }
        *ppTypeInfo = NULL;
        TCHAR szModule1[_MAX_PATH];
        int nLen = ::GetModuleFileName(_AtlBaseModule.GetModuleInstance(), szModule1, _MAX_PATH);
        if (nLen == 0 || nLen == _MAX_PATH) {
            return E_FAIL;
        }
        USES_CONVERSION_EX;
        LPOLESTR pszModule = T2OLE_EX(szModule1, _ATL_SAFE_ALLOCA_DEF_THRESHOLD);
#ifndef _UNICODE
        if (pszModule == NULL) {
            return E_OUTOFMEMORY;
        }
#endif
        CComPtr<ITypeLib> spTypeLib;
        HRESULT hr = LoadTypeLib(pszModule, &spTypeLib);
        if (SUCCEEDED(hr)) {
            CComPtr<ITypeInfo> spTypeInfo;
            hr = spTypeLib->GetTypeInfoOfGuid(iidDisp, &spTypeInfo);
            if (SUCCEEDED(hr)) {
                *ppTypeInfo = spTypeInfo.Detach();
            }
        }
        return hr;
    }
    virtual HRESULT STDMETHODCALLTYPE IAutoServ::GetTypeInfoCount(unsigned int*  pctinfo) 
    {
        if (pctinfo == NULL) {
            return E_POINTER;
        }
        CComPtr<ITypeInfo> spTypeInfo;
        *pctinfo = 
                       (SUCCEEDED(TypeInfoHelper(__uuidof(IAutoServ), 0, &spTypeInfo))) ? 1 : 0;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE IAutoServ::GetTypeInfo(unsigned int iTInfo, LCID lcid, ITypeInfo** ppTInfo) 
    {
        if (iTInfo != 0) {
            return DISP_E_BADINDEX;
        }
        return TypeInfoHelper(__uuidof(IAutoServ), lcid, ppTInfo);
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    static DWORD* GetOpCodes() 
    {
        static DWORD rgOps[] = 
            					{
            						0x70000000,
            0x10004000,
            0x30004000,
            0x50000000,
            0x30008000,
            0x80000003,
            0x50000000,
            0x60000000,
            0x30010000,
            0x50000000,
            0x80004002,
            0x60000000,
            0x60000000,
            0x60000000,
            0
            					};
        return rgOps;
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    static RGSDWORD* GetOpcodeDWORDVals() 
    {
        static RGSDWORD rgDWORDS[] = 
            					{
            						{0, 0}
            					};
        return rgDWORDS;
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    static RGSBinary* GetOpcodeBinaryVals() 
    {

        static RGSBinary rgBinary[] = 
            					{
            						{0, 0}
            					};
        return rgBinary;
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    static RGSStrings* GetOpcodeStringVals() 
    {
        static RGSStrings rgStrings[] = 
            					{
            						{_T(""),0 }, 
            {_T("AppID"),0 }, 
            {_T("{A6D89F10-35F4-11D2-9375-00C04FD9757C}"),0 }, 
            {_T("AutoServer"),0 }, 
            {_T("AutoServer.EXE"),0 }, 
            {NULL, 0}
            					};
        return rgStrings;
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) 
    {
        CRegistryVirtualMachine rvm;
        HRESULT hr;
        if (FAILED(hr = rvm.AddStandardReplacements()))
            return hr;
        rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());
        return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(), GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    static const TCHAR* GetObjectFriendlyName() 
    {
        return _T("CAutoServ Object");
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    static const TCHAR* GetProgID() 
    {
        return _T("AutoServer.AutoServ.1");
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    static const TCHAR* GetVersionIndependentProgID() 
    {
        return _T("AutoServer.AutoServ");
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"
    BEGIN_COM_MAP(CAutoServ)
        COM_INTERFACE_ENTRY(IAutoServ)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
    END_COM_MAP()

	//--- End Injected Code For Attribute 'coclass'
}

//+++ Start Injected Code For Attribute 'coclass'
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoserver\\AutoServ.h"

				OBJECT_ENTRY_AUTO(__uuidof(CAutoServ), CAutoServ)
			
//--- End Injected Code For Attribute 'coclass'
;
STDMETHODIMP CAutoServ::Sleep(long delay)
{
	//put this thread to sleep for a bit.
	::Sleep(delay);
	return S_OK;
}


