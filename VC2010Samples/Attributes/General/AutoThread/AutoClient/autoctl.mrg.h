// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\general\autothread\autoclient\autoctl.mrg.h
// compiler-generated file created 09/15/17 at 22:35:26
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



//+++ Start Injected Code
#injected_line 15 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"

#include <comdef.h>

//--- End Injected Code
// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
// AutoCtl.h : Declaration of the CAutoCtl

#pragma once

#include "resource.h"       // main symbols
#include <atlctl.h>
#import "..\autoserver\_Server.tlb" no_namespace

	[
		object,
		uuid("C26DF971-A799-4020-9A88-A4E902252657"),
		dual,
		helpstring("IAutoCtl Interface"),
		pointer_default(unique)
	]
	__interface IAutoCtl : IDispatch
	{
		[propget, id(1), helpstring("property Delay")] HRESULT Delay([out, retval] long *pVal);
		[propput, id(1), helpstring("property Delay")] HRESULT Delay([in] long newVal);
	};
/////////////////////////////////////////////////////////////////////////////
// CAutoCtl
[
	coclass,
	uuid("A7EDFF03-84C9-429a-89EE-2FDDBE4DAED1"),
	helpstring("AutoCtl Class"),
	version("1.0"),
	progid("AutoClient.AutoCtl.1"),
	vi_progid("AutoClient.AutoCtl"),
	default("IAutoCtl"),
	threading(apartment),
	registration_script("AutoCtl.rgs")
]
class ATL_NO_VTABLE CAutoCtl : 
	public IAutoCtl,
	public CComControl<CAutoCtl>,
	public IPersistStreamInitImpl<CAutoCtl>,
	public IOleControlImpl<CAutoCtl>,
	public IOleObjectImpl<CAutoCtl>,
	public IOleInPlaceActiveObjectImpl<CAutoCtl>,
	public IViewObjectExImpl<CAutoCtl>,
	public IOleInPlaceObjectWindowlessImpl<CAutoCtl>,
	public IPersistStorageImpl<CAutoCtl>,
	public ISpecifyPropertyPagesImpl<CAutoCtl>,
	public IQuickActivateImpl<CAutoCtl>,
	public IDataObjectImpl<CAutoCtl>,
	public IProvideClassInfoImpl<&(__uuidof(CAutoCtl))>
,
    /*+++ Added Baseclass */ public CComObjectRootEx<CComSingleThreadModel>
{
public:
	CAutoCtl()
	{
		m_Text = _T("Waiting");
		m_Delay = 1000;
		//Create server object during creation.
		CComPtr<IUnknown> pUnk = NULL;
		HRESULT hr = pUnk.CoCreateInstance(__uuidof(CAutoServ));
		ATLASSERT(hr == S_OK);
		hr = pUnk->QueryInterface(__uuidof(IAutoServ), (void**)&m_Server);
		ATLASSERT(hr == S_OK);
	}
	~CAutoCtl()
	{
		//Release server Object when finished.
		IUnknown* ServUnknown = (IUnknown*)m_Server;
		ServUnknown->Release();
	}
	
DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_PROP_MAP(CAutoCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()

BEGIN_MSG_MAP(CAutoCtl)
	CHAIN_MSG_MAP(CComControl<CAutoCtl>)
	DEFAULT_REFLECTION_HANDLER()
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IAutoCtl
public:
	STDMETHOD(get_Delay)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Delay)(/*[in]*/ long newVal);
	long m_Delay;
	IAutoServ* m_Server;
	LPCTSTR m_Text;
	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;
		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);

		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		TextOut(di.hdcDraw, 
			(rc.left + rc.right) / 2, 
			(rc.top + rc.bottom) / 2, 
			m_Text, 
			lstrlen(m_Text));

		return S_OK;
	}
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		//Change Output String.
		m_Text = _T("Waiting.");
		FireViewChange();
		//Call Server Function.
		m_Server->Sleep(m_Delay);
		//When Server Returns, Change Output String back.
		m_Text = _T("Ready.");
		FireViewChange();
		return 0;
	}

	//+++ Start Injected Code For Attribute 'coclass'
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    virtual HRESULT STDMETHODCALLTYPE IAutoCtl::Invoke(
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
                if (wFlags & 2) {
                    if (pDispParams->cArgs != 0) {
                        return DISP_E_BADPARAMCOUNT;
                    }
                    long i1;
                    hr = ((::IAutoCtl*) this)->get_Delay(&i1);
                    if (pVarResult != 0) {
                        V_VT(pVarResult) = VT_I4;
                        V_I4(pVarResult) = i1;
                    }
                    break;
                }
                else 
        if (wFlags & 4) {
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
                    hr = ((::IAutoCtl*) this)->put_Delay(i1);
                    break;
                }
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
    virtual HRESULT STDMETHODCALLTYPE IAutoCtl::GetIDsOfNames(
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
        static LPOLESTR names[] = { L"Delay", L"pVal", L"get_Delay", L"put_Delay" };
        static DISPID dids[] = { 1, 0, 1, 1 };
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
    virtual HRESULT STDMETHODCALLTYPE IAutoCtl::GetTypeInfoCount(unsigned int*  pctinfo) 
    {
        if (pctinfo == NULL) {
            return E_POINTER;
        }
        CComPtr<ITypeInfo> spTypeInfo;
        *pctinfo = 
                       (SUCCEEDED(TypeInfoHelper(__uuidof(IAutoCtl), 0, &spTypeInfo))) ? 1 : 0;
        return S_OK;
    }
    virtual HRESULT STDMETHODCALLTYPE IAutoCtl::GetTypeInfo(unsigned int iTInfo, LCID lcid, ITypeInfo** ppTInfo) 
    {
        if (iTInfo != 0) {
            return DISP_E_BADINDEX;
        }
        return TypeInfoHelper(__uuidof(IAutoCtl), lcid, ppTInfo);
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
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
            0x3001c000,
            0x80000001,
            0x50000000,
            0x60000000,
            0x30020000,
            0x80000005,
            0x50000000,
            0x60000000,
            0x30024000,
            0x50000000,
            0x60000000,
            0x30028000,
            0x8000000b,
            0x50000000,
            0x8003000d,
            0x60000000,
            0x30024000,
            0x50000000,
            0x60000000,
            0x30038000,
            0x8000000f,
            0x50000000,
            0x60000000,
            0x30040000,
            0x80000011,
            0x50000000,
            0x30048000,
            0x80000013,
            0x50000000,
            0x60000000,
            0x60000000,
            0x30050000,
            0x80000015,
            0x50000000,
            0x60000000,
            0x30058000,
            0x80000017,
            0x50000000,
            0x60000000,
            0x80060019,
            0x60000000,
            0x60000000,
            0x60000000,
            0
            					};
        return rgOps;
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    static RGSDWORD* GetOpcodeDWORDVals() 
    {
        static RGSDWORD rgDWORDS[] = 
            					{
            						{0, 0}
            					};
        return rgDWORDS;
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    static RGSBinary* GetOpcodeBinaryVals() 
    {

        static RGSBinary rgBinary[] = 
            					{
            						{0, 0}
            					};
        return rgBinary;
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    static RGSStrings* GetOpcodeStringVals() 
    {
        static RGSStrings rgStrings[] = 
            					{
            						{_T(""),0 }, 
            {_T("AutoClient.AutoCtl.1"),0 }, 
            {_T("AutoCtl Class"),0 }, 
            {_T("CLSID"),0 }, 
            {_T("{A7EDFF03-84C9-429a-89EE-2FDDBE4DAED1}"),0 }, 
            {_T("AutoClient.AutoCtl"),0 }, 
            {_T("CurVer"),0 }, 
            {_T("ProgID"),0 }, 
            {_T("VersionIndependentProgID"),0 }, 
            {_T("Programmable"),0 }, 
            {_T("%MODULETYPE%"),1 }, 
            {_T("%MODULE%"),1 }, 
            {_T("ThreadingModel"),0 }, 
            {_T("apartment"),0 }, 
            {_T("ToolboxBitmap32"),0 }, 
            {_T("%MODULE%, 101"),1 }, 
            {_T("MiscStatus"),0 }, 
            {_T("0"),0 }, 
            {_T("1"),0 }, 
            {_T("131473"),0 }, 
            {_T("TypeLib"),0 }, 
            {_T("%MODULEGUID%"),1 }, 
            {_T("Version"),0 }, 
            {_T("1.0"),0 }, 
            {_T("LocalizedString"),0 }, 
            {_T("@%MODULE%,-100"),1 }, 
            {NULL, 0}
            					};
        return rgStrings;
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    static HRESULT WINAPI UpdateRegistry(BOOL bRegister) 
    {
        CRegistryVirtualMachine rvm;
        HRESULT hr;
        if (FAILED(hr = rvm.AddStandardReplacements()))
            return hr;
        rvm.AddReplacement(_T("FriendlyName"), GetObjectFriendlyName());
        return rvm.VMUpdateRegistry(GetOpCodes(), GetOpcodeStringVals(), GetOpcodeDWORDVals(), GetOpcodeBinaryVals(), bRegister);
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    static const TCHAR* GetObjectFriendlyName() 
    {
        return _T("CAutoCtl Object");
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    static const TCHAR* GetProgID() 
    {
        return _T("AutoClient.AutoCtl.1");
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    static const TCHAR* GetVersionIndependentProgID() 
    {
        return _T("AutoClient.AutoCtl");
    }
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"
    BEGIN_COM_MAP(CAutoCtl)
        COM_INTERFACE_ENTRY(IAutoCtl)
        COM_INTERFACE_ENTRY(IDispatch)
        COM_INTERFACE_ENTRY(IPersistStreamInit)
        COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
        COM_INTERFACE_ENTRY(IOleControl)
        COM_INTERFACE_ENTRY(IOleObject)
        COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
        COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceActiveObject)
        COM_INTERFACE_ENTRY(IViewObjectEx)
        COM_INTERFACE_ENTRY(IViewObject2)
        COM_INTERFACE_ENTRY(IViewObject)
        COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
        COM_INTERFACE_ENTRY(IOleInPlaceObject)
        COM_INTERFACE_ENTRY(IPersistStorage)
        COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
        COM_INTERFACE_ENTRY(IQuickActivate)
        COM_INTERFACE_ENTRY(IDataObject)
        COM_INTERFACE_ENTRY(IProvideClassInfo)
    END_COM_MAP()

	//--- End Injected Code For Attribute 'coclass'
}

//+++ Start Injected Code For Attribute 'coclass'
#injected_line 32 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\general\\autothread\\autoclient\\AutoCtl.h"

				OBJECT_ENTRY_AUTO(__uuidof(CAutoCtl), CAutoCtl)
			
//--- End Injected Code For Attribute 'coclass'
;

