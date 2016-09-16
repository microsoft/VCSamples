// DispCtl.h : Declaration of the CDispCtl
//
// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.1

#ifndef __DISPCTL_H_
#define __DISPCTL_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#ifdef	_DEBUG
#import "..\DispServer\Debug\DispServer.exe"  no_namespace, named_guids
#else
#import "..\DispServer\release\DispServer.exe"  no_namespace, named_guids
#endif

/////////////////////////////////////////////////////////////////////////////
// CDispCtl
class ATL_NO_VTABLE CDispCtl : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IDispCtl, &IID_IDispCtl, &LIBID_DISPCLIENTLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public CComControl<CDispCtl>,
	public IPersistStreamInitImpl<CDispCtl>,
	public IOleControlImpl<CDispCtl>,
	public IOleObjectImpl<CDispCtl>,
	public IOleInPlaceActiveObjectImpl<CDispCtl>,
	public IViewObjectExImpl<CDispCtl>,
	public IOleInPlaceObjectWindowlessImpl<CDispCtl>,
	public IPersistStorageImpl<CDispCtl>,
	public ISpecifyPropertyPagesImpl<CDispCtl>,
	public IQuickActivateImpl<CDispCtl>,
	public IDataObjectImpl<CDispCtl>,
	public IProvideClassInfo2Impl<&CLSID_DispCtl, NULL, &LIBID_DISPCLIENTLib>,
	public CComCoClass<CDispCtl, &CLSID_DispCtl>,
	public IDispEventImpl<1, CDispCtl, &DIID__IDispServEvents>
{
public:
	CDispCtl()
	{
		m_bConnected = FALSE;
		m_OutText.vt = VT_BSTR;
		m_OutText.bstrVal = SysAllocString(L"Disconnected");
	}
	~CDispCtl()
	{
		Disconnect();
	}
DECLARE_REGISTRY_RESOURCEID(IDR_DISPCTL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDispCtl)
	COM_INTERFACE_ENTRY(IDispCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()

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


//Map used to sink events.
BEGIN_SINK_MAP(CDispCtl)
	SINK_ENTRY_EX(1, DIID__IDispServEvents, 1, &CDispCtl::OnTransmit)
END_SINK_MAP()	
	
	
	
	
// IDispCtl
public:
	STDMETHOD(Send)(VARIANT data);
	STDMETHOD(Disconnect)();
	STDMETHOD(Connect)();
	STDMETHOD(OnTransmit)(VARIANT data);

	bool m_bConnected;
	IDispServ* m_pIServ;
	DWORD m_dwCookie;
	VARIANT m_OutText;

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
};

OBJECT_ENTRY_AUTO(__uuidof(DispCtl), CDispCtl)

#endif //__DISPCTL_H_
