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
#include <atlctl.h>
#include <olectl.h>
extern const GUID CLSID_CCircProps;

#define PRINTSIZE(theClass) \
{\
	TCHAR szBuf[255];\
	wsprintf(szBuf, _T("sizeof(") _T(#theClass) _T(") = %d\n"), sizeof(theClass));\
	OutputDebugString(szBuf);\
}

//**** Interface Section
[	dispinterface,
	uuid(544B15ED-AB2F-479E-8AC7-1344CD4FC30E),
	helpstring("Event interface for Circ Control")
]
__interface _CircEvents
{
	[id(1)] void Click();
	[id(2)] void KeyPress(short KeyAscii);
};


[	object,
	uuid(0806E754-1256-45DE-A026-EFF47B37304E),
	dual,
	helpstring("ICircCtl Interface"),
	pointer_default(unique)
]
__interface ICircCtl : IDispatch
{
	[propput, id(DISPID_CAPTION)]
	HRESULT Caption([in]BSTR pCaption);
	[propget, id(DISPID_CAPTION)]
	HRESULT Caption([out,retval]BSTR* ppCaption);
	[propput, id(DISPID_ENABLED)]
	HRESULT Enabled([in]VARIANT_BOOL vbool);
	[propget, id(DISPID_ENABLED)]
	HRESULT Enabled([out,retval]VARIANT_BOOL* pbool);
	[propput, id(DISPID_BACKCOLOR)]
	HRESULT BackColor([in]OLE_COLOR clr);
	[propget, id(DISPID_BACKCOLOR)]
	HRESULT BackColor([out,retval]OLE_COLOR* pclr);
	[propput, id(DISPID_FORECOLOR)]
	HRESULT ForeColor([in]OLE_COLOR clr);
	[propget, id(DISPID_FORECOLOR)]
	HRESULT ForeColor([out,retval]OLE_COLOR* pclr);
	[propput, id(DISPID_FONT)]
	HRESULT Font([in]IFontDisp* pFont);
	[propputref, id(DISPID_FONT)]
	HRESULT Font([in]IFontDisp* pFont);
	[propget, id(DISPID_FONT)]
	HRESULT Font([out,retval]IFontDisp** ppFont);
};

//**** Class definition
[ coclass,
  uuid(BDB53AB2-6073-48DF-9974-0C0D8047A54F),
  helpstring("CircCtl Attrib Control"),
  event_source(com),
  implements_category("CATID_Control"),
  implements_category("CATID_Insertable"),
  support_error_info("ICircCtl"),
  default("ICircCtl")
]
class ATL_NO_VTABLE CCircCtl :
	public CComControl<CCircCtl>,
	public CStockPropImpl<CCircCtl, ICircCtl, &__uuidof(ICircCtl), &CAtlModule::m_libid>,
	public IPersistStreamInitImpl<CCircCtl>,
	public IPersistStorageImpl<CCircCtl>,
	public IQuickActivateImpl<CCircCtl>,
	public IOleControlImpl<CCircCtl>,
	public IOleObjectImpl<CCircCtl>,
	public IOleInPlaceActiveObjectImpl<CCircCtl>,
	public IViewObjectExImpl<CCircCtl>,
	public IOleInPlaceObjectWindowlessImpl<CCircCtl>,
	public IDataObjectImpl<CCircCtl>,
	public ISpecifyPropertyPagesImpl<CCircCtl>,
	public IPersistPropertyBagImpl<CCircCtl>,
	public IPerPropertyBrowsingImpl<CCircCtl>,
	public IOleLinkImpl<CCircCtl>,
	public IRunnableObjectImpl<CCircCtl>
{
public:
	CCircCtl()
	{
		m_bEnabled = TRUE;
		m_bstrCaption = _T("Circ with Attributes");
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
//DECLARE_NOT_AGGREGATABLE(CCircCtl)
DECLARE_GET_CONTROLLING_UNKNOWN()

__event __interface _CircEvents;

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

// Implementation
public:
	HRESULT OnDraw(ATL_DRAWINFO& di);

	LRESULT OnChar(UINT, WPARAM wParam, LPARAM, BOOL&)
	{
		_CircEvents_KeyPress(static_cast<short>(wParam));
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
		_CircEvents_Click();
		MessageBeep(MB_OK);
//      FireDataChange();
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
