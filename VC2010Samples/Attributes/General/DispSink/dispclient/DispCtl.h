	// DispCtl.h : Declaration of the CDispCtl
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once
#include "resource.h"       // main symbols

#include <atlctl.h>

// Importing a COM component by program ID or typelib ID requires that the component 
// be registered before compile time. This feature won't work under a 32bit to 64bit 
// cross compiland.
#ifdef _WIN64
#import "..\dispserver\_DispServer.tlb" embedded_idl, no_namespace
#else
#import "progid:DispServer.DispServ.1" embedded_idl, no_namespace
#endif


// IDispCtl
[
	object,
	uuid(0F4098BD-0318-4F89-A505-A954211198CE),
	dual,
	helpstring("IDispCtl Interface"),
	pointer_default(unique)
]
__interface IDispCtl : public IDispatch
{
	[id(1), helpstring("method Connect")] HRESULT Connect();
	[id(2), helpstring("method Disconnect")] HRESULT Disconnect();
	[id(3), helpstring("method Send")] HRESULT Send(VARIANT data);
};


// CDispCtl
[
	coclass,
	threading(single),
	vi_progid("DispClient.DispCtl"),
	progid("DispClient.DispCtl.1"),
	version(1.0),
	default("IDispCtl"),
	uuid("A40B4D20-27B8-4387-A494-5D7F0D0A81C3"),
	helpstring("DispCtl Class"),
	registration_script("control.rgs"),
	event_receiver(com)
]
class ATL_NO_VTABLE CDispCtl : 
	public IDispCtl,
	public IPersistStreamInitImpl<CDispCtl>,
	public IOleControlImpl<CDispCtl>,
	public IOleObjectImpl<CDispCtl>,
	public IOleInPlaceActiveObjectImpl<CDispCtl>,
	public IViewObjectExImpl<CDispCtl>,
	public IOleInPlaceObjectWindowlessImpl<CDispCtl>,
	public IDataObjectImpl<CDispCtl>,
	public IProvideClassInfoImpl<&__uuidof(CDispCtl)>,
	public CComControl<CDispCtl>
{
public:

	CDispCtl()
	{
		m_bConnected = false;
		m_OutText = L"Not Connected";
	}
	~CDispCtl()
	{
		Disconnect();
	}

DECLARE_OLEMISC_STATUS(OLEMISC_RECOMPOSEONRESIZE | 
	OLEMISC_CANTLINKINSIDE | 
	OLEMISC_INSIDEOUT | 
	OLEMISC_ACTIVATEWHENVISIBLE | 
	OLEMISC_SETCLIENTSITEFIRST
)


BEGIN_PROP_MAP(CDispCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
END_PROP_MAP()


BEGIN_MSG_MAP(CDispCtl)
	CHAIN_MSG_MAP(CComControl<CDispCtl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IDispCtl
public:
	HRESULT Connect()
	{
		HRESULT hr;
		hr = m_spIServ.CoCreateInstance(__uuidof(CDispServ));
		if (SUCCEEDED(hr))
		{
			hr = __hook(&_IDispServEvents::Transfer, m_spIServ, &CDispCtl::OnTransmit);
		}
		if (hr == S_OK) {
			m_bConnected = true;
			m_OutText = L"Connected";
		}
		FireViewChange();
		return(hr);
	}

	HRESULT Disconnect()
	{
		if (m_bConnected)
		{
			HRESULT hr = __unhook(&_IDispServEvents::Transfer, m_spIServ, &CDispCtl::OnTransmit);
			if (SUCCEEDED(hr)) {
				m_spIServ.Release();
				m_bConnected = false;
				m_OutText = L"Not Connected";
			}
			FireViewChange();
			return(hr);
		}
		return(S_OK);
	}

	HRESULT OnTransmit(VARIANT data)
	{
		if (data.vt == VT_BSTR)
			m_OutText = data;
		FireViewChange();
		return(S_OK);
	}

	HRESULT Send(VARIANT data)
	{
		if (m_bConnected)
			m_spIServ->Send(data);
		return(S_OK);
	}

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		LPCTSTR text = COLE2CT(m_OutText.bstrVal);
		RECT& rc = *(RECT*)di.prcBounds;
		Rectangle(di.hdcDraw, rc.left, rc.top, rc.right, rc.bottom);
		SetTextAlign(di.hdcDraw, TA_CENTER|TA_BASELINE);
		TextOut(di.hdcDraw, 
			(rc.left + rc.right) / 2, 
			(rc.top + rc.bottom) / 2, 
			text, 
			lstrlen(text));

		return S_OK;

	}


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}
	
	void FinalRelease() 
	{
	}
private:
	// Data
	bool m_bConnected;
	CComPtr<IDispServ> m_spIServ;
	CComVariant m_OutText;
};

