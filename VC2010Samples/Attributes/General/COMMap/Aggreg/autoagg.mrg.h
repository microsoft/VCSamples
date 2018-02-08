// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\general\commap\aggreg\autoagg.mrg.h
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

// AutoAgg.h : Declaration of the CAutoAgg
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#include "aggres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Aggreg
[emitidl];
#include "AggregIface.h"
[
	coclass,
	uuid("501153E5-FAD9-4E5C-9C3D-8CC815D4F60E"),
	helpstring("AutoAgg Class"),
	version("1.0"),
	progid("Aggreg.AutoAgg.1"),
	vi_progid("Aggreg.AutoAgg"),
	threading(both),
	support_error_info("IAutoAgg"),
	default("IAutoAgg")
]
class CAutoAgg  : public IAutoAgg
,
    /*+++ Added Baseclass */ public ISupportErrorInfo
{
public:
	CAutoAgg(){}
//DECLARE_NOT_AGGREGATABLE(CAutoAgg)
// Remove the comment from the line above if you don't want your object to
// support aggregation.  The default is to support it

// IAutoAgg
public:
	STDMETHOD(get_Name)(BSTR* pbstrName)
	{
		*pbstrName = ::SysAllocString(L"IAutoAgg");
		return S_OK;
	}

	//+++ Start Injected Code For Attribute 'support_error_info'
#injected_line 20 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    virtual HRESULT STDMETHODCALLTYPE IAutoAgg::Invoke(
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
        case 0:
            {
                if (pDispParams->cArgs != 0) {
                    return DISP_E_BADPARAMCOUNT;
                }
                BSTR i1;
                hr = ((::IAutoAgg*) this)->get_Name(&i1);
                if (pVarResult != 0) {
                    V_VT(pVarResult) = VT_BSTR;
                    V_BSTR(pVarResult) = (BSTR) i1;
                }
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
    virtual HRESULT STDMETHODCALLTYPE IAutoAgg::GetIDsOfNames(
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
        static LPOLESTR names[] = { L"Name", L"pbstrName", L"get_Name" };
        static DISPID dids[] = { 0, 0, 0 };
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
    virtual HRESULT STDMETHODCALLTYPE IAutoAgg::GetTypeInfoCount(unsigned int*  pctinfo) 
    {
        if (pctinfo == NULL) {
            return E_POINTER;
        }
        CComPtr<ITypeInfo> spTypeInfo;
        *pctinfo = 
                       (SUCCEEDED(TypeInfoHelper(__uuidof(IAutoAgg), 0, &spTypeInfo))) ? 1 : 0;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE IAutoAgg::GetTypeInfo(unsigned int iTInfo, LCID lcid, ITypeInfo** ppTInfo) 
    {
        if (iTInfo != 0) {
            return DISP_E_BADINDEX;
        }
        return TypeInfoHelper(__uuidof(IAutoAgg), lcid, ppTInfo);
    }
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
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
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    static RGSDWORD* GetOpcodeDWORDVals() 
    {
        static RGSDWORD rgDWORDS[] = 
            					{
            						{0, 0}
            					};
        return rgDWORDS;
    }
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    static RGSBinary* GetOpcodeBinaryVals() 
    {

        static RGSBinary rgBinary[] = 
            					{
            						{0, 0}
            					};
        return rgBinary;
    }
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    static RGSStrings* GetOpcodeStringVals() 
    {
        static RGSStrings rgStrings[] = 
            					{
            						{_T(""),0 }, 
            {_T("Aggreg.AutoAgg.1"),0 }, 
            {_T("%FriendlyName%"),1 }, 
            {_T("CLSID"),0 }, 
            {_T("{501153E5-FAD9-4E5C-9C3D-8CC815D4F60E}"),0 }, 
            {_T("Aggreg.AutoAgg"),0 }, 
            {_T("CurVer"),0 }, 
            {_T("ProgID"),0 }, 
            {_T("VersionIndependentProgID"),0 }, 
            {_T("Programmable"),0 }, 
            {_T("%MODULETYPE%"),1 }, 
            {_T("%MODULE%"),1 }, 
            {_T("ThreadingModel"),0 }, 
            {_T("both"),0 }, 
            {_T("AppID"),0 }, 
            {_T("%APPID%"),1 }, 
            {_T("TypeLib"),0 }, 
            {_T("%MODULEGUID%"),1 }, 
            {NULL, 0}
            					};
        return rgStrings;
    }
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) 
    {
        CRegistryVirtualMachine rvm;
        HRESULT hr;
        if (FAILED(hr = rvm.AddStandardReplacements()))
            return hr;
        rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());
        return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(), GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);
    }
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    static const TCHAR* GetObjectFriendlyName() 
    {
        return _T("CAutoAgg Object");
    }
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    static const TCHAR* GetProgID() 
    {
        return _T("Aggreg.AutoAgg.1");
    }
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    static const TCHAR* GetVersionIndependentProgID() 
    {
        return _T("Aggreg.AutoAgg");
    }
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"
    BEGIN_COM_MAP(CAutoAgg)
        COM_INTERFACE_ENTRY(IAutoAgg)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
        COM_INTERFACE_ENTRY(ISupportErrorInfo)
    END_COM_MAP()
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"

    STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid) 
        					
    {
        static const IID* rgErrorGuids[] = 
            						{
            							&__uuidof(IAutoAgg)
            						};
        for (int i=0; i < sizeof(rgErrorGuids) / sizeof(rgErrorGuids[0]); i++)
						{
            if (InlineIsEqualGUID(*rgErrorGuids[i],riid))
                return S_OK;
        }
        return S_FALSE;
    } 

	//--- End Injected Code For Attribute 'support_error_info'
}

//+++ Start Injected Code For Attribute 'support_error_info'
#injected_line 27 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\commap\\aggreg\\autoagg.h"

				OBJECT_ENTRY_AUTO(__uuidof(CAutoAgg), CAutoAgg)
			
//--- End Injected Code For Attribute 'support_error_info'
;
