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

[ emitidl ];
[
	object,
	uuid(D61AF69C-AAF7-4FBB-823A-F55CCB2857A2),
	dual,
	helpstring("IFireTabCtrl Interface"),
	pointer_default(unique)
]
__interface IFireTabCtrl : IDispatch
{
	[propget, id(1), helpstring("property Decay")] HRESULT Decay([out, retval] long *pVal);
	[propput, id(1), helpstring("property Decay")] HRESULT Decay([in] long newVal);
	[propget, id(2), helpstring("property Flammability")] HRESULT Flammability([out, retval] long *pVal);
	[propput, id(2), helpstring("property Flammability")] HRESULT Flammability([in] long newVal);
	[propget, id(3), helpstring("property MaxHeat")] HRESULT MaxHeat([out, retval] long *pVal);
	[propput, id(3), helpstring("property MaxHeat")] HRESULT MaxHeat([in] long newVal);
	[propget, id(4), helpstring("property SpreadRate")] HRESULT SpreadRate([out, retval] long *pVal);
	[propput, id(4), helpstring("property SpreadRate")] HRESULT SpreadRate([in] long newVal);
	[propget, id(5), helpstring("property Size")] HRESULT Size([out, retval] long *pVal);
	[propput, id(5), helpstring("property Size")] HRESULT Size([in] long newVal);
	[propget, id(6), helpstring("property Smoothness")] HRESULT Smoothness([out, retval] long *pVal);
	[propput, id(6), helpstring("property Smoothness")] HRESULT Smoothness([in] long newVal);
	[propget, id(7), helpstring("property Distribution")] HRESULT Distribution([out, retval] long *pVal);
	[propput, id(7), helpstring("property Distribution")] HRESULT Distribution([in] long newVal);
	[propget, id(8), helpstring("property Chaos")] HRESULT Chaos([out, retval] long *pVal);
	[propput, id(8), helpstring("property Chaos")] HRESULT Chaos([in] long newVal);
	[propget, id(9), helpstring("property StartTab")] HRESULT StartTab([out, retval] long *pVal);
	[propput, id(9), helpstring("property StartTab")] HRESULT StartTab([in] long newVal);
	[id(-552), helpstring("method AboutBox")] HRESULT AboutBox();
};

class CPropDlg;

/////////////////////////////////////////////////////////////////////////////
// CFireTabCtrl
[
	coclass,
	threading(single),
	uuid("64D01C7F-810D-446E-A07E-16C764235644"),
	progid("AtlFireCtl.AtlFireCtlAttrib.1"),
	vi_progid("AtlFireCtl.AtlFireCtlAttrib"),
	default("IFireTabCtrl"),
	version("1.0"),
	support_error_info("IFireTabCtrl"),
	registration_script("FireTabCtrl.rgs")
]
class ATL_NO_VTABLE CFireTabCtrl :
	public IFireTabCtrl,
	public CComControl<CFireTabCtrl>,
	public IProvideClassInfoImpl<&__uuidof(CFireTabCtrl)>,
	public IPersistStreamInitImpl<CFireTabCtrl>,
	public IPersistStorageImpl<CFireTabCtrl>,
	public IPersistPropertyBagImpl<CFireTabCtrl>,
	public IQuickActivateImpl<CFireTabCtrl>,
	public IObjectSafetyImpl<CFireTabCtrl, INTERFACESAFE_FOR_UNTRUSTED_CALLER>,
	public IOleControlImpl<CFireTabCtrl>,
	public IOleObjectImpl<CFireTabCtrl>,
	public IOleInPlaceActiveObjectImpl<CFireTabCtrl>,
	public IViewObjectExImpl<CFireTabCtrl>,
	public IOleInPlaceObjectWindowlessImpl<CFireTabCtrl>,
	public IDataObjectImpl<CFireTabCtrl>,
	public ISpecifyPropertyPagesImpl<CFireTabCtrl>,
	public IConnectionPointContainerImpl<CFireTabCtrl>,
	public IPropertyNotifySinkCP<CFireTabCtrl>
{
public:

BEGIN_PROPERTY_MAP(CFireTabCtrl)
	// Example entries
	PROP_ENTRY_TYPE("FireDecay", 1, __uuidof(CFireTabCtrl), VT_I4)
	PROP_ENTRY_TYPE("FireFlammability", 2, __uuidof(CFireTabCtrl), VT_I4)
	PROP_ENTRY_TYPE("FireMaxHeat", 3, __uuidof(CFireTabCtrl), VT_I4)
	PROP_ENTRY_TYPE("FireSpreadRate", 4, __uuidof(CFireTabCtrl), VT_I4)
	PROP_ENTRY_TYPE("FireSize", 5, __uuidof(CFireTabCtrl), VT_I4)
	PROP_ENTRY_TYPE("RenderSmoothness", 6, __uuidof(CFireTabCtrl), VT_I4)
	PROP_ENTRY_TYPE("RenderDistribution", 7, __uuidof(CFireTabCtrl), VT_I4)
	PROP_ENTRY_TYPE("RenderChaos", 8, __uuidof(CFireTabCtrl), VT_I4)
	PROP_ENTRY_TYPE("StartTab", 9, __uuidof(CFireTabCtrl), VT_I4)
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
#endif //__FIRETABCTRL_H_
