// D3D.h : Declaration of the CDirect3D
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include <objsafe.h>
#include "resource.h"       // main symbols
#include "d3diface.h"

#include "D3DWnd.h"
#pragma warning(disable : 4100)

//////////////////////////////////////////////////////////////////////////////////////////////////
// CTimer
template <class Derived, class T, const IID* piid>
class CTimer
{
public:

	CTimer()
	{
		m_bTimerOn = FALSE;
	}

	HRESULT TimerOn(DWORD dwTimerInterval)
	{
		Derived* pDerived = ((Derived*)this);

		m_dwTimerInterval = dwTimerInterval;
		if (m_bTimerOn) // already on, just change interval
			return S_OK;

		m_bTimerOn = TRUE;
		m_dwTimerInterval = dwTimerInterval;
		m_pStream = NULL;

		HRESULT hRes;

		hRes = CoMarshalInterThreadInterfaceInStream(*piid, (T*)pDerived, &m_pStream);

		// Create thread and pass the thread proc the this ptr
		m_hThread = CreateThread(NULL, 0, &_Apartment, (void*)this, 0, &m_dwThreadID);

		return S_OK;
	}

	void TimerOff()
	{
		if (m_bTimerOn)
		{
			m_bTimerOn = FALSE;
			AtlWaitWithMessageLoop(m_hThread);
		}
	}


// Implementation
private:
	static DWORD WINAPI _Apartment(void* pv)
	{
		CTimer<Derived, T, piid>* pThis = (CTimer<Derived, T, piid>*) pv;
		pThis->Apartment();
		return 0;
	}

	DWORD Apartment()
	{
		CoInitialize(NULL);
		HRESULT hRes;

		m_spT.Release();

		if (m_pStream)
			hRes = CoGetInterfaceAndReleaseStream(m_pStream, *piid, (void**)&m_spT);

		while(m_bTimerOn)
		{
			Sleep(m_dwTimerInterval);
			if (!m_bTimerOn)
				break;

			m_spT->DisplayScene();
		}
		m_spT.Release();

		CoUninitialize();
		return 0;
	}

// Attributes
public:
	DWORD m_dwTimerInterval;

// Implementation
private:
	HANDLE m_hThread;
	DWORD m_dwThreadID;
	LPSTREAM m_pStream;
	CComPtr<T> m_spT;
	BOOL m_bTimerOn;
};


/////////////////////////////////////////////////////////////////////////////
// CDirect3D
[ coclass,
  uuid(CADC8E2D-3D83-485c-8449-3C1D278264CA),
  helpstring("Direct3DCtl Class"),
  progid("Direct3DCtl.Direct3DCtlAttrib.1"),
  vi_progid("Direct3DCtl.Direct3DCtlAttrib"),
  implements_category("CATID_Control"),
  registration_script("control.rgs"),
  support_error_info("IDirect3DCtl"),
  default("IDirect3DCtl")
]
class CDirect3D :
	public CComControl<CDirect3D>,
	public CTimer<CDirect3D, IDirect3DCtl, &__uuidof(IDirect3DCtl)>,
	public IDirect3DCtl,
	public IPersistStreamInitImpl<CDirect3D>,
	public IPersistStorageImpl<CDirect3D>,
	public IQuickActivateImpl<CDirect3D>,
	public IOleControlImpl<CDirect3D>,
	public IOleObjectImpl<CDirect3D>,
	public IOleInPlaceActiveObjectImpl<CDirect3D>,
	public IViewObjectExImpl<CDirect3D>,
	public IOleInPlaceObjectWindowlessImpl<CDirect3D>,
	public IDataObjectImpl<CDirect3D>,
	public IObjectSafetyImpl<CDirect3D, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
	CDirect3D()
	{
		m_hOurWnd   = NULL;
		m_p3DWindow = NULL;
		m_dwSafety  = 0;
	}
	~CDirect3D()
	{
		// Stop, if we haven't stopped already
		if (m_p3DWindow)
			Stop3D();
	}

DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_MSG_MAP(CDirect3D)
	MESSAGE_HANDLER(WM_ERASEBKGND, OnEraseBackground)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnLButtonDown)
END_MSG_MAP()

BEGIN_PROPERTY_MAP(CDirect3D)
END_PROPERTY_MAP()


	STDMETHOD(OnFrameWindowActivate)(BOOL fActivate)
	{
		ATLTRACE(_T("OnFrameWindowActivate\n"));
		if (fActivate && m_p3DWindow)
			m_p3DWindow->SetPalette();

		return S_OK;
	}
// IDirect3DCtl
public:

// Implementation
public:
	// The drawing is done through CDirect3DWindow, so we need
	// to do nothing here.
	LRESULT OnEraseBackground(UINT, WPARAM, LPARAM, BOOL& bHandled)
	{
		return 0;
	}

	LRESULT OnLButtonDown(UINT, WPARAM, LPARAM, BOOL& bHandled)
	{
		m_p3DWindow->SetPalette();
		return 0;
	}

	HRESULT OnDraw(ATL_DRAWINFO&)
	{
		// We're not doing any drawing using GDI, so there is nothing to do here.
		// We still need to have this function so we don't bring in the default ATL
		// drawing code.
		return TRUE;
	}

	HRESULT InPlaceActivate(LONG iVerb, const RECT* prcPosRect = NULL)
	{
		HRESULT hr;

		hr = CComControlBase::InPlaceActivate(iVerb, prcPosRect);
		if (!m_p3DWindow)   // Start if we haven't started yet
			Start3D();
		return hr;
	}

	STDMETHOD(InPlaceDeactivate)(void)
	{
		if (m_p3DWindow)
			Stop3D();
		return IOleInPlaceObjectWindowlessImpl<CDirect3D>::InPlaceDeactivate();
	}

	STDMETHOD(Start3D)()
	{
		// Find out what window we need to use
		GetOurWindow();

		// If we haven't got a window yet, then there's nothing we can do
		if (m_hOurWnd == NULL)
			return E_FAIL;

		m_p3DWindow = new CDirect3DWindow;
		if (!m_p3DWindow)
		{
			return E_OUTOFMEMORY;
		}

		RECT rcInitialPos = m_rcPos;
		RectToDesktop(&rcInitialPos);

		HRESULT hr = m_p3DWindow->OnCreate(m_hOurWnd, rcInitialPos);

		// The OnSize method creates the initial scene
		if (SUCCEEDED(hr))
			m_p3DWindow->OnSize(m_hOurWnd, m_rcPos.right-m_rcPos.left,
				m_rcPos.bottom-m_rcPos.top);

		TimerOn(5);

		return hr;
	}

	STDMETHOD(Stop3D)()
	{
		TimerOff();
		delete m_p3DWindow;
		m_p3DWindow = NULL;
		return S_OK;
	}

	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		if (prcPos == NULL)
		{
			// I've seen VB5 send this
			ATLTRACE(_T("WARNING: SetObjects called with NULL prcPos\n"));
			return S_OK;
		}
		HRESULT hr = IOleInPlaceObjectWindowlessImpl<CDirect3D>::SetObjectRects(prcPos, prcClip);
		return hr;
	}
	STDMETHOD(DisplayScene)()
	{
		if (m_p3DWindow)
		{
//          m_p3DWindow->SetPalette();
			m_p3DWindow->TickScene();
			Draw3DWindow();
		}
		return S_OK;
	}
private:
	void Draw3DWindow()
	{
		static RECT rcOldPos;
		if (m_p3DWindow)
		{
			RECT rcPos = m_rcPos;
			RectToDesktop(&rcPos);

			// Has the size changed
			if ((rcPos.right-rcPos.left != rcOldPos.right-rcOldPos.left) ||
				(rcPos.bottom-rcPos.top != rcOldPos.bottom-rcOldPos.top))
			{
				ATLTRACE(_T("Draw(%d,%d,%d,%d)\n"),rcPos.left,rcPos.top,rcPos.right,rcPos.bottom);
				m_p3DWindow->OnSize(m_hOurWnd, m_rcPos.right-m_rcPos.left,
					m_rcPos.bottom-m_rcPos.top);
				ATLTRACE(_T("EndDraw\n"));
			}

			// Has it moved
			if (rcPos.left!=rcOldPos.left || rcPos.top!=rcOldPos.top)
				m_p3DWindow->OnMove(m_hOurWnd, rcPos.left, rcPos.top);

			rcOldPos = rcPos;

			m_p3DWindow->DoFrame();
		}
	}

	// Get the window we need to use. This will either be the window that has already
	// been created if we are window. If we are windowless the HWND of the client
	// will be retrieved from the HDC.
	void GetOurWindow()
	{
		// If we're windowless we still need an HWND for Direct3d
		if (m_bWndLess)
		{
			HDC hDC;

			// Get the HDC from the client
			m_spInPlaceSite->GetDC(NULL, OLEDC_NODRAW, &hDC);
			m_hOurWnd = WindowFromDC(hDC);
		#if 1
			// Code to make VB5 paint properly now it has clipped it's own hDC
			RECT rect;
			::GetClientRect(m_hOurWnd,&rect);
			HRGN hRegion = CreateRectRgn(rect.left,rect.top,rect.right,rect.bottom);
			SelectClipRgn(hDC,hRegion);
		#endif
			m_spInPlaceSite->ReleaseDC(hDC);
		}
		else
			m_hOurWnd = m_hWnd;
	}

	// Convert RECT so that it is relative to the desktop.
	void RectToDesktop(RECT* pRect)
	{
		POINT pt;
		pt.x = 0;
		pt.y = 0;
		::ClientToScreen(m_hOurWnd, &pt);
		if (m_bWndLess)
			::OffsetRect(pRect, pt.x, pt.y);
		else
			// If we're not windowless, cater for the fact that pRect will not necessarily be at (0,0)
			::OffsetRect(pRect, pt.x-pRect->left, pt.y-pRect->top);
	}

	HWND                m_hOurWnd;
	CDirect3DWindow*    m_p3DWindow;    // Pointer to Direct3D window if we have one
	DWORD               m_dwSafety;     // Current safety settings
};
