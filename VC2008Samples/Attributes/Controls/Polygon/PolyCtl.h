// PolyCtl.h : Declaration of the CPolyCtl
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#ifndef __POLYCTL_H_
#define __POLYCTL_H_

#include <math.h>
#include "resource.h"       // main symbols
#include <atlctl.h>
#include "PolyProp.h"

#include "PolygonIface.h"
/////////////////////////////////////////////////////////////////////////////
// CPolyCtl
[
	coclass,
	uuid("44487B6B-DDC8-4A13-9B20-A8A892629026"),
	helpstring("PolyCtl Class"),
	version("1.0"),
	progid("Polygon.PolyCtlAttrib.1"),
	vi_progid("Polygon.PolyCtlAttrib"),
	threading(apartment),
	implements_category("CATID_Insertable"),
    implements_category("CATID_Control"),
	registration_script("control.rgs"),
	event_source(com),
	default(IPolyCtl),
	support_error_info(IPolyCtl)
]
class ATL_NO_VTABLE CPolyCtl :
	public CStockPropImpl<CPolyCtl, IPolyCtl, &__uuidof(IPolyCtl), &CAtlModule::m_libid>,
	public CComControl<CPolyCtl>,
	public IPersistStreamInitImpl<CPolyCtl>,
	public IOleControlImpl<CPolyCtl>,
	public IOleObjectImpl<CPolyCtl>,
	public IOleInPlaceActiveObjectImpl<CPolyCtl>,
	public IViewObjectExImpl<CPolyCtl>,
	public IOleInPlaceObjectWindowlessImpl<CPolyCtl>,
	public IPersistStorageImpl<CPolyCtl>,
	public ISpecifyPropertyPagesImpl<CPolyCtl>,
	public IQuickActivateImpl<CPolyCtl>,
	public IDataObjectImpl<CPolyCtl>,
	public IObjectSafetyImpl<CPolyCtl, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
	CPolyCtl()
	{
		m_nSides = 3;
		m_clrFillColor = RGB(0, 0xFF, 0);
	}


	
__event __interface _IPolyCtlEvents;

BEGIN_PROP_MAP(CPolyCtl)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY_TYPE("FillColor", DISPID_FILLCOLOR, CLSID_StockColorPage, VT_DISPATCH)
	PROP_ENTRY_TYPE("Sides", 1, __uuidof(CPolyProp), VT_I2)
END_PROP_MAP()

BEGIN_MSG_MAP(CPolyCtl)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	CHAIN_MSG_MAP(CComControl<CPolyCtl>)
	DEFAULT_REFLECTION_HANDLER()
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);


// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IPolyCtl
public:
	STDMETHOD(get_Sides)(/*[out, retval]*/ short *pVal);
	STDMETHOD(put_Sides)(/*[in]*/ short newVal);
	void    CalcPoints(const RECT& rc);

HRESULT OnDraw(ATL_DRAWINFO& di)
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

	LRESULT CPolyCtl::OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
		{
		HRGN hRgn;
		WORD xPos = LOWORD(lParam);  // horizontal position of cursor
		WORD yPos = HIWORD(lParam);  // vertical position of cursor
		CalcPoints(m_rcPos);   // Create a region from our list of points
		hRgn = CreatePolygonRgn(&m_arrPoint[0], m_nSides, WINDING);

		// If the clicked point is in our polygon then fire the ClickIn
		//  event otherwise we fire the ClickOut event
		if (PtInRegion(hRgn, xPos, yPos))
			_IPolyCtlEvents_ClickIn(xPos, yPos);
		else
			_IPolyCtlEvents_ClickOut(xPos, yPos);   // Delete the region that we created
		DeleteObject(hRgn);
		return 0;
		}
	};

#endif //__POLYCTL_H_
