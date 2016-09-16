// CircCtl.h : Declaration of the CCircCtl
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "resource.h"       // main symbols
#include "CPEvent.h"        // connection point for events

class ATL_NO_VTABLE CCircCtl :
	public CComObjectRoot,
	public CComCoClass<CCircCtl,&CLSID_CCircCtl>,
	public CComControl<CCircCtl>,
	public CStockPropImpl<CCircCtl, ICircCtl, &IID_ICircCtl, &LIBID_CIRCLib>,
	public IPersistStreamInitImpl<CCircCtl>,
	public IPersistStorageImpl<CCircCtl>,
	public IQuickActivateImpl<CCircCtl>,
	public IProvideClassInfo2Impl<&CLSID_CCircCtl, &DIID__CircEvents, &LIBID_CIRCLib>,
	public IOleControlImpl<CCircCtl>,
	public IOleObjectImpl<CCircCtl>,
	public IOleInPlaceActiveObjectImpl<CCircCtl>,
	public IViewObjectExImpl<CCircCtl>,
	public IOleInPlaceObjectWindowlessImpl<CCircCtl>,
	public IConnectionPointContainerImpl<CCircCtl>,
	public CProxy_CircEvents<CCircCtl>,
	public IDataObjectImpl<CCircCtl>,
	public ISpecifyPropertyPagesImpl<CCircCtl>,
	public IPropertyNotifySinkCP<CCircCtl, CComDynamicUnkArray >,
	public IPersistPropertyBagImpl<CCircCtl>,
	public IPerPropertyBrowsingImpl<CCircCtl>,
	public IOleLinkImpl<CCircCtl>,
	public IRunnableObjectImpl<CCircCtl>
{
public:
	CCircCtl()
	{
		m_bEnabled = TRUE;
		m_bstrCaption = _T("ATL Rules");
		m_bRequiresSave = TRUE;
		m_hPalette = NULL;
		m_hWnd = NULL;
		m_clrForeColor = RGB(255, 0, 0);
		m_clrBackColor = RGB(0, 0, 255);
	}
	~CCircCtl()
	{
		ATLTRACE(_T("I'm out of here\n"));
	}

	static LPCTSTR GetWindowClassName() {return _T("CCircCtl");}

DECLARE_REGISTRY_RESOURCEID(IDR_CircCtl)
DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(CCircCtl)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ICircCtl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_IID(IID_IViewObject, IViewObjectEx)
	COM_INTERFACE_ENTRY_IID(IID_IViewObject2, IViewObjectEx)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY_IID(IID_IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IID(IID_IOleInPlaceObject, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IPersistPropertyBag)
	COM_INTERFACE_ENTRY(IPerPropertyBrowsing)
	COM_INTERFACE_ENTRY(IOleLink)
	COM_INTERFACE_ENTRY(IRunnableObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IID(IID_IPersist, IPersistPropertyBag)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(CCircCtl)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID__CircEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CCircCtl)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
	MESSAGE_HANDLER(WM_CHAR, OnChar)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
END_MSG_MAP()

BEGIN_PROPERTY_MAP(CCircCtl)
	PROP_ENTRY_TYPE("Caption", DISPID_CAPTION, CLSID_CCircProps, VT_BSTR)
	PROP_ENTRY_TYPE("Enabled", DISPID_ENABLED, CLSID_CCircProps, VT_BOOL)
	PROP_ENTRY_TYPE("ForeColor", DISPID_FORECOLOR, CLSID_StockColorPage, VT_DISPATCH)
	PROP_ENTRY_TYPE("BackColor", DISPID_BACKCOLOR, CLSID_StockColorPage, VT_DISPATCH)
	PROP_ENTRY_TYPE("Font", DISPID_FONT, CLSID_StockFontPage, VT_DISPATCH)
END_PROPERTY_MAP()

public:
	HRESULT OnDraw(ATL_DRAWINFO& di);

	LRESULT OnChar(UINT, WPARAM wParam, LPARAM, BOOL&)
	{
		Fire_KeyPress(static_cast<short>(wParam));
		return 0;
	}
	STDMETHOD(DoVerb)(LONG iVerb,LPMSG lpmsg, IOleClientSite *pActiveSite,
				   LONG lindex, HWND hwndParent, LPCRECT lprcPosRect)
	{
		if (iVerb == 1)
			return IOleObjectImpl<CCircCtl>::DoVerb(OLEIVERB_PROPERTIES, lpmsg, pActiveSite,
												lindex, hwndParent, lprcPosRect);
		if (iVerb == 2)
			return IOleObjectImpl<CCircCtl>::DoVerb(OLEIVERB_SHOW, lpmsg, pActiveSite,
												lindex, hwndParent, lprcPosRect);

		return IOleObjectImpl<CCircCtl>::DoVerb(iVerb, lpmsg, pActiveSite,
												lindex, hwndParent, lprcPosRect);

	}
	STDMETHOD(QueryHitPoint)(DWORD dwAspect, LPCRECT pRectBounds, POINT ptlLoc, LONG /* lCloseHint */, DWORD *pHitResult)
	{
		*pHitResult = HITRESULT_OUTSIDE;
		if (dwAspect == DVASPECT_CONTENT)
		{
			if (PtInRect(pRectBounds, ptlLoc))
			{
				HRGN hRgn = ::CreateEllipticRgn(pRectBounds->left, pRectBounds->top, pRectBounds->right + 1, pRectBounds->bottom + 1);
				if (PtInRegion(hRgn, ptlLoc.x, ptlLoc.y))
					*pHitResult = HITRESULT_HIT;
				DeleteObject(hRgn);
			}
		}
		return S_OK;
	}
	LRESULT OnLButtonDown(UINT, WPARAM, LPARAM, BOOL&)
	{
		Fire_Click();
		MessageBeep(MB_OK);
		return 0;
	}
	LRESULT OnCreate(UINT, WPARAM, LPARAM, BOOL&)
	{
		// Won't be in here unless window based and active
		RECT rc;
		::GetClientRect(m_hWnd, &rc);
		HRGN hRgn = ::CreateEllipticRgn(rc.left, rc.top, rc.right + 1, rc.bottom + 1);
		::SetWindowRgn(m_hWnd, hRgn, FALSE);
		return 0;
	}
	STDMETHOD(QuickActivate)(QACONTAINER *pqacontainer, QACONTROL *pqacontrol)
	{
		m_hPalette = pqacontainer->hpal;
		return IQuickActivateImpl<CCircCtl>::QuickActivate(pqacontainer, pqacontrol);
	}

public:
	VARIANT_BOOL m_bEnabled;
	HPALETTE m_hPalette;
	CComBSTR m_bstrCaption;
	OLE_COLOR m_clrBackColor;
	OLE_COLOR m_clrForeColor;
	CComPtr<IFontDisp> m_pFont;
};
