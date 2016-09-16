// CDInfo1.h : Declaration of the CCDInfo
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

//#include <commctrl.h>
#include <atlctl.h>
#include "resource.h"       // main symbols
#include "CCDInfo.h"
#include "CPCDInfo.h"

#define PI 3.14159265358979
#define BORDER 5

/////////////////////////////////////////////////////////////////////////////
// CCDInfo
class CCDInfo :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCDInfo, &CLSID_CCDInfo>,
	public CComControl<CCDInfo>,
	public IDispatchImpl<ICDInfo, &IID_ICDInfo, &LIBID_CDInfoLib>,
	public IProvideClassInfo2Impl<&CLSID_CCDInfo, &DIID_CDEvents, &LIBID_CDInfoLib>,
	public IPersistStreamInitImpl<CCDInfo>,
	public IPersistStorageImpl<CCDInfo>,
	public IQuickActivateImpl<CCDInfo>,
	public IOleControlImpl<CCDInfo>,
	public IOleObjectImpl<CCDInfo>,
	public IOleInPlaceActiveObjectImpl<CCDInfo>,
	public IViewObjectExImpl<CCDInfo>,
	public IOleInPlaceObjectWindowlessImpl<CCDInfo>,
	public IDataObjectImpl<CCDInfo>,
	public IPropertyNotifySinkCP<CCDInfo>,
	public IRunnableObjectImpl<CCDInfo>,
	public IPerPropertyBrowsingImpl<CCDInfo>,
	public IConnectionPointContainerImpl<CCDInfo>,
	public CProxyCDEvents<CCDInfo>,
	public IOleLinkImpl<CCDInfo>
{
public:
	CCDInfo()
	{
		ZeroMemory(&m_rcEllipse, sizeof(RECT));
		m_hPalette = NULL;
		m_wndToolTip.m_hWnd = NULL;
	}
	CWindow m_wndToolTip;

DECLARE_REGISTRY_RESOURCEID(IDR_CDInfo)

BEGIN_COM_MAP(CCDInfo)
	COM_INTERFACE_ENTRY(ICDInfo)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_IMPL(IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject2, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleInPlaceObject, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY_IMPL(IOleControl)
	COM_INTERFACE_ENTRY_IMPL(IOleObject)
	COM_INTERFACE_ENTRY_IMPL(IQuickActivate)
	COM_INTERFACE_ENTRY_IMPL(IPersistStorage)
	COM_INTERFACE_ENTRY_IMPL(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY_IMPL(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IRunnableObject)
	COM_INTERFACE_ENTRY_IMPL(IPerPropertyBrowsing)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY_IMPL(IOleLink)
END_COM_MAP()

BEGIN_PROPERTY_MAP(CCDInfo)
END_PROPERTY_MAP()

BEGIN_CONNECTION_POINT_MAP(CCDInfo)
	CONNECTION_POINT_ENTRY(IID_IPropertyNotifySink)
	CONNECTION_POINT_ENTRY(DIID_CDEvents)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CCDInfo)
	MESSAGE_HANDLER(WM_PAINT         , OnPaint)
	MESSAGE_HANDLER(WM_ERASEBKGND , OnEraseBkgnd)
	MESSAGE_HANDLER(WM_MOUSEMOVE     , OnMouseMove)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
	MESSAGE_HANDLER(WM_LBUTTONUP  , RelayEvent)
	MESSAGE_HANDLER(WM_RBUTTONDOWN, RelayEvent)
	MESSAGE_HANDLER(WM_RBUTTONUP  , RelayEvent)
	MESSAGE_HANDLER(WM_MBUTTONDOWN, RelayEvent)
	MESSAGE_HANDLER(WM_MBUTTONUP  , RelayEvent)
END_MSG_MAP()

	LRESULT OnEraseBkgnd(UINT /* uMsg */, WPARAM /* wParam */, LPARAM /* lParam */, BOOL& /* bHandled */)
	{
		// We don't paint the background here as it is done in the OnDraw function.
		// This is to stop flickering when a tooltip is displayed.
		return 1;
	}
	HRESULT OnDraw(ATL_DRAWINFO& di);
	LRESULT OnLButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnMouseMove(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	LRESULT RelayEvent(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& /* bHandled */)
	{
		if (m_wndToolTip.m_hWnd)
		{
			MSG msg;
			msg.lParam  = lParam;
			msg.wParam  = wParam;
			msg.message = uMsg;
			msg.hwnd    = m_hTheWnd;
			::SendMessage(m_wndToolTip.m_hWnd, TTM_RELAYEVENT, 0, (LPARAM)&msg);
		}
		return 0;
	}

	HRESULT InPlaceActivate(LONG iVerb, const RECT* prcPosRect=NULL)
	{
		HRESULT hr;

		hr = CComControlBase::InPlaceActivate(iVerb, prcPosRect);
		if (m_wndToolTip.m_hWnd == NULL)
		{
			GetTheWindow();
			CreateTooltipWindow();
		}
		return hr;
	}

	STDMETHOD(InPlaceDeactivate)(void)
	{
		if (m_wndToolTip.m_hWnd)
			m_wndToolTip.DestroyWindow();

		return IOleInPlaceObjectWindowlessImpl<CCDInfo>::InPlaceDeactivate();
	}

	STDMETHOD(QuickActivate)(QACONTAINER *pqacontainer, QACONTROL *pqacontrol)
	{
		m_hPalette = pqacontainer->hpal;
		return IQuickActivateImpl<CCDInfo>::QuickActivate(pqacontainer, pqacontrol);
	}

// ICDInfo
	STDMETHOD(get_Tracks)(short* pTracks)
	{
		*pTracks = m_cd.GetNumberOfTracks();
		return S_OK;
	}
	STDMETHOD(put_Tracks)(short nTracks)
	{
		m_dblCurrentAngle = 3 * PI / 2; // Reset the drawing angle
		m_cd.SetNumberOfTracks(nTracks);
		return S_OK;
	}
	STDMETHOD(get_Length)(short nTrack, short* pLength)
	{
		*pLength = m_cd.GetTrackLength(nTrack);
		return S_OK;
	}
	STDMETHOD(put_Length)(short nTrack, short nLength)
	{
		m_cd.SetTrackLength(nTrack, nLength);
		return S_OK;
	}
	STDMETHOD(get_TotalLength)(short* pLength)
	{
		*pLength = m_cd.GetTotalLength();
		return S_OK;
	}
	STDMETHOD(Read)(short* pTracks)
	{
		m_dblCurrentAngle = 3 * PI / 2; // Reset the drawing angle
		*pTracks = m_cd.Read();
		Redraw();
		return S_OK;
	}
	STDMETHOD(Redraw)()
	{
		if (m_bWndLess)
			m_spInPlaceSite->InvalidateRect(NULL, TRUE);
		else if (m_hWnd)
			InvalidateRect(NULL, TRUE);
		return S_OK;
	}
	STDMETHOD(Play)(short nTrack)
	{
		DrawToTrack(nTrack);
		m_cd.Play(nTrack);
		return S_OK;
	}

	// We override the next couple of methods to trap when our size changes
	// so we can set our m_rcEllipse accordingly
	STDMETHOD(SetExtent)(DWORD  dwDrawAspect, SIZEL *psizel)
	{
		HRESULT hr = IOleObjectImpl<CCDInfo>::SetExtent(dwDrawAspect, psizel);
		m_rcEllipse = m_rcPos;
		ReduceRect(&m_rcEllipse);
		if (!m_bWndLess)
			OffsetRect(&m_rcEllipse, -m_rcEllipse.left+BORDER, -m_rcEllipse.top+BORDER);
		return hr;
	}
	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		HRESULT hr = IOleInPlaceObjectWindowlessImpl<CCDInfo>::SetObjectRects(prcPos, prcClip);
		m_rcEllipse = m_rcPos;
		ReduceRect(&m_rcEllipse);
		if (!m_bWndLess)
			OffsetRect(&m_rcEllipse, -m_rcEllipse.left+BORDER, -m_rcEllipse.top+BORDER);
		return hr;
	}
	void ReduceRect(RECT* pRect)
	{
		InflateRect(pRect, BORDER * ((pRect->left < pRect->right) ? -1 : 1),
			BORDER * ((pRect->top < pRect->bottom) ? -1 : 1));
	}

	HWND        m_hTheWnd;
private:
	void        CreateTooltipWindow();
	void        GetTheWindow();
	void        DrawOffScreen(HDC hdc, RECT rc);
	void        DrawCD(HDC hdc, RECT rc);
	POINT       CalcPoint(POINT ptCenter, double dwRadius, double fAngle);
	double      CalcAngle(POINT ptCenter, POINT point);
	short       GetTrackFromPoint(const POINT& pt);
	BOOL        InEllipse(RECT& rect, POINT point);
	double      GetTrackAngle(short nWantedTrack);
	void        DrawToTrack(short nTrack);

	short       m_nCurrentTrack;
	short       m_nMouseTrack;
	CDInfo      m_cd;
	RECT        m_rcEllipse;
	HPALETTE    m_hPalette;
	double      m_dblCurrentAngle;

	static COLORREF     m_colSegment[];
};
