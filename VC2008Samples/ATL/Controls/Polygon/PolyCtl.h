// PolyCtl.h : Declaration of the CPolyCtl

// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __POLYCTL_H_
#define __POLYCTL_H_

#include <math.h>
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "PolygonCP.h"


/////////////////////////////////////////////////////////////////////////////
// CPolyCtl
class ATL_NO_VTABLE CPolyCtl :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CStockPropImpl<CPolyCtl, IPolyCtl, &IID_IPolyCtl, &LIBID_POLYGONLib>,
	public CComControl<CPolyCtl>,
	public IPersistStreamInitImpl<CPolyCtl>,
	public IOleControlImpl<CPolyCtl>,
	public IOleObjectImpl<CPolyCtl>,
	public IOleInPlaceActiveObjectImpl<CPolyCtl>,
	public IViewObjectExImpl<CPolyCtl>,
	public IOleInPlaceObjectWindowlessImpl<CPolyCtl>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CPolyCtl>,
	public IPersistStorageImpl<CPolyCtl>,
	public ISpecifyPropertyPagesImpl<CPolyCtl>,
	public IQuickActivateImpl<CPolyCtl>,
	public IDataObjectImpl<CPolyCtl>,
	public IProvideClassInfo2Impl<&CLSID_PolyCtl, &DIID__IPolyCtlEvents, &LIBID_POLYGONLib>,
	public IPropertyNotifySinkCP<CPolyCtl>,
	public CComCoClass<CPolyCtl, &CLSID_PolyCtl>,
	public CProxy_IPolyCtlEvents< CPolyCtl >,
	public IObjectSafetyImpl<CPolyCtl, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
	CPolyCtl()
	{
		m_nSides = 3;
		m_clrFillColor = RGB(0, 0xFF, 0);
	}

DECLARE_REGISTRY_RESOURCEID(IDR_POLYCTL)

BEGIN_COM_MAP(CPolyCtl)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IPolyCtl)
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
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY(IQuickActivate)
	COM_INTERFACE_ENTRY(IPersistStorage)
	COM_INTERFACE_ENTRY(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()

BEGIN_PROP_MAP(CPolyCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY_TYPE("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage, VT_DISPATCH)
	PROP_ENTRY_TYPE("Sides", 1, CLSID_PolyProp, VT_I2)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CPolyCtl)
	CONNECTION_POINT_ENTRY(DIID__IPolyCtlEvents)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CPolyCtl)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	CHAIN_MSG_MAP(CComControl<CPolyCtl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);



// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		static const IID* arr[] =
		{
			&IID_IPolyCtl,
		};
		for (int i=0; i<sizeof(arr)/sizeof(arr[0]); i++)
		{
			if (InlineIsEqualGUID(*arr[i], riid))
				return S_OK;
		}
		return S_FALSE;
	}

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IPolyCtl
public:
	STDMETHOD(get_Sides)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Sides)(/*[in]*/ short newVal);
	void    CalcPoints(const RECT& rc);

HRESULT CPolyCtl::OnDraw(ATL_DRAWINFO& di)
{
   RECT& rc = *(RECT*)di.prcBounds;
   HDC hdc  = di.hdcDraw;

   COLORREF    colFore;
   HBRUSH      hOldBrush, hBrush;
   HPEN        hOldPen, hPen;

   // Translate m_colFore into a COLORREF type
   OleTranslateColor(m_clrFillColor, NULL, &colFore);

   // Create and select the colors to draw the circle
   hPen = (HPEN)GetStockObject(BLACK_PEN);
   hOldPen = (HPEN)SelectObject(hdc, hPen);
   hBrush = (HBRUSH)GetStockObject(WHITE_BRUSH);
   hOldBrush = (HBRUSH)SelectObject(hdc, hBrush);

   Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);

   // Create and select the brush that will be used to fill the polygon
   hBrush    = CreateSolidBrush(colFore);
   SelectObject(hdc, hBrush);

   CalcPoints(rc);
   Polygon(hdc, &m_arrPoint[0], m_nSides);

   // Select back the old pen and brush and delete the brush we created
   SelectObject(hdc, hOldPen);
   SelectObject(hdc, hOldBrush);
   DeleteObject(hBrush);

   return S_OK;
}


	OLE_COLOR m_clrFillColor;
	short m_nSides;
	POINT m_arrPoint[100];

	LRESULT CPolyCtl::OnLButtonDown(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM lParam, BOOL& /*bHandled*/)
		{
		HRGN hRgn;
		WORD xPos = LOWORD(lParam);  // horizontal position of cursor
		WORD yPos = HIWORD(lParam);  // vertical position of cursor
		CalcPoints(m_rcPos);   // Create a region from our list of points
		hRgn = CreatePolygonRgn(&m_arrPoint[0], m_nSides, WINDING);

		// If the clicked point is in our polygon then fire the ClickIn
		//  event otherwise we fire the ClickOut event
		if (PtInRegion(hRgn, xPos, yPos))
			Fire_ClickIn(xPos, yPos);
		else
			Fire_ClickOut(xPos, yPos);   // Delete the region that we created
		DeleteObject(hRgn);
		return 0;
		}
	};

#endif //__POLYCTL_H_
