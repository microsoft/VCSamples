// FireTabCtrl.h : Declaration of the CFireTabCtrl
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.


#ifndef __FIRETABCTRL_H_
#define __FIRETABCTRL_H_

#include "resource.h"       // main symbols
#include <commctrl.h>
#include "FireWnd.h"

class CPropDlg;

/////////////////////////////////////////////////////////////////////////////
// CFireTabCtrl
class ATL_NO_VTABLE CFireTabCtrl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFireTabCtrl, &CLSID_FireTabCtrl>,
	public CComControl<CFireTabCtrl>,	
	public IProvideClassInfoImpl<&CLSID_FireTabCtrl, &LIBID_ATLFIRELib>,	
	public IPersistPropertyBagImpl<CFireTabCtrl>,
	public IQuickActivateImpl<CFireTabCtrl>,
	public IOleControlImpl<CFireTabCtrl>,
	public IOleObjectImpl<CFireTabCtrl>,
	public IOleInPlaceActiveObjectImpl<CFireTabCtrl>,
	public IViewObjectExImpl<CFireTabCtrl>,
	public IOleInPlaceObjectWindowlessImpl<CFireTabCtrl>,
	public IDataObjectImpl<CFireTabCtrl>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CFireTabCtrl>,
	public IPropertyNotifySinkCP<CFireTabCtrl>,
	public IFireTabCtrl
{
public:


DECLARE_REGISTRY_RESOURCEID(IDR_FIRETABCTRL)

BEGIN_COM_MAP(CFireTabCtrl)
	COM_INTERFACE_ENTRY(IFireTabCtrl)	
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY2(IViewObject2, IViewObjectEx)
	COM_INTERFACE_ENTRY2(IViewObject, IViewObjectEx)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY2(IOleInPlaceObject, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY2(IPersist, IPersistPropertyBag)
	COM_INTERFACE_ENTRY(IPersistPropertyBag)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_PROPERTY_MAP(CFireTabCtrl)
	// Example entries
	PROP_ENTRY_TYPE("FireDecay", 1, CLSID_FireTabCtrl, VT_I4)
	PROP_ENTRY_TYPE("FireFlammability", 2, CLSID_FireTabCtrl, VT_I4)
	PROP_ENTRY_TYPE("FireMaxHeat", 3, CLSID_FireTabCtrl, VT_I4)
	PROP_ENTRY_TYPE("FireSpreadRate", 4, CLSID_FireTabCtrl, VT_I4)
	PROP_ENTRY_TYPE("FireSize", 5, CLSID_FireTabCtrl, VT_I4)
	PROP_ENTRY_TYPE("RenderSmoothness", 6, CLSID_FireTabCtrl, VT_I4)
	PROP_ENTRY_TYPE("RenderDistribution", 7, CLSID_FireTabCtrl, VT_I4)
	PROP_ENTRY_TYPE("RenderChaos", 8, CLSID_FireTabCtrl, VT_I4)
	PROP_ENTRY_TYPE("StartTab", 9, CLSID_FireTabCtrl, VT_I4)
END_PROPERTY_MAP()

BEGIN_CONNECTION_POINT_MAP(CFireTabCtrl)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CFireTabCtrl)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_KILLFOCUS, OnKillFocus)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_ACTIVATE, OnActivate)
	MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackground)
	MESSAGE_HANDLER(WM_SIZE, OnSize)
	NOTIFY_CODE_HANDLER(TCN_SELCHANGE, OnSelChanged)
ALT_MSG_MAP(1)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
END_MSG_MAP()

	CFireTabCtrl();
	~CFireTabCtrl();
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSelChanged(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);
	LRESULT OnActivate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnEraseBackground(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	HRESULT IOleInPlaceObject_UIDeactivate();
	STDMETHOD(IOleInPlaceObject_SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip);
	// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
	// IViewObjectEx
	STDMETHOD(GetViewStatus)(DWORD* pdwStatus);

// IFireTabCtrl
public:
	STDMETHOD(AboutBox)();
	STDMETHOD(get_StartTab)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_StartTab)(/*[in]*/ long newVal);
	STDMETHOD(get_Chaos)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Chaos)(/*[in]*/ long newVal);
	STDMETHOD(get_Distribution)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Distribution)(/*[in]*/ long newVal);
	STDMETHOD(get_Smoothness)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Smoothness)(/*[in]*/ long newVal);
	STDMETHOD(get_Size)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Size)(/*[in]*/ long newVal);
	STDMETHOD(get_SpreadRate)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_SpreadRate)(/*[in]*/ long newVal);
	STDMETHOD(get_MaxHeat)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_MaxHeat)(/*[in]*/ long newVal);
	STDMETHOD(get_Flammability)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Flammability)(/*[in]*/ long newVal);
	STDMETHOD(get_Decay)(/*[out, retval]*/ long *pVal);
	STDMETHOD(put_Decay)(/*[in]*/ long newVal);
	HRESULT OnDraw(ATL_DRAWINFO& di);

// Attributes
	CContainedWindow m_ctlSysTabControl32;
	CFireWnd m_Display;
};


/////////////////////////////////////////////////////////////////////////////
// CPropDlg
class CAboutBox :
	public CDialogImpl<CAboutBox>
{
public:

	CAboutBox(){}

	enum { IDD = IDD_ABOUTBOX };

BEGIN_MSG_MAP(CAboutBox)
	COMMAND_ID_HANDLER(IDOK, OnOK)
END_MSG_MAP()
LRESULT OnOK(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);

};

OBJECT_ENTRY_AUTO(__uuidof(FireTabCtrl), CFireTabCtrl)

#endif //__FIRETABCTRL_H_
