// AutoCtl.h : Declaration of the CAutoCtl
//
// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#ifndef __AUTOCTL_H_
#define __AUTOCTL_H_

#include "resource.h"       // main symbols
#include <atlctl.h>
#ifdef	_DEBUG
#import "..\AutoServer\Debug\AutoServer.exe" no_namespace, named_guids
#else
#import "..\AutoServer\release\AutoServer.exe" no_namespace, named_guids
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutoCtl
class ATL_NO_VTABLE CAutoCtl : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public IDispatchImpl<IAutoCtl, &IID_IAutoCtl, &LIBID_AUTOCLIENTLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
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
	public IProvideClassInfoImpl<&CLSID_AutoCtl, &LIBID_AUTOCLIENTLib>,
	public CComCoClass<CAutoCtl, &CLSID_AutoCtl>
{
public:
	CAutoCtl()
	{
		m_Text = _T("Ready");
		m_Delay = 1000;
		//Create server object during creation.
		HRESULT hr;
		hr = CoCreateInstance(CLSID_AutoServ, NULL, CLSCTX_ALL, IID_IAutoServ, (void**)&m_Server);
		ATLASSERT(hr == S_OK);
	}
	~CAutoCtl()
	{
		//Release server Object when finished.
		IUnknown* ServUnknown = (IUnknown*)m_Server;
		ServUnknown->Release();
	}
DECLARE_REGISTRY_RESOURCEID(IDR_AUTOCTL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CAutoCtl)
	COM_INTERFACE_ENTRY(IAutoCtl)
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
END_COM_MAP()

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
	LRESULT OnLButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
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

OBJECT_ENTRY_AUTO(__uuidof(AutoCtl), CAutoCtl)

#endif //__AUTOCTL_H_
