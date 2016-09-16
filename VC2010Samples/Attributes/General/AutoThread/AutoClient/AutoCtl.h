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
};

