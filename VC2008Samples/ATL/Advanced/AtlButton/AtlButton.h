// AtlButton.h : Declaration of the CAtlButton
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
#include "cpatlbutn.h"
#include <atlctl.h>

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

			m_spT->_OnTimer();
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
// CAtlButton
class CAtlButton :
	public CComObjectRoot,
	public CTimer<CAtlButton, IAtlButton, &IID_IAtlButton>,
	public CComCoClass<CAtlButton,&CLSID_CAtlButton>,
	public CComControl<CAtlButton>,
	public CStockPropImpl<CAtlButton, IAtlButton, &IID_IAtlButton, &LIBID_ATLBUTNLib>,
	public ISpecifyPropertyPagesImpl<CAtlButton>,
	public IPersistStreamInitImpl<CAtlButton>,
	public IOleControlImpl<CAtlButton>,
	public IOleObjectImpl<CAtlButton>,
	public IOleInPlaceActiveObjectImpl<CAtlButton>,
	public IViewObjectExImpl<CAtlButton>,
	public IOleInPlaceObjectWindowlessImpl<CAtlButton>,
	public IProvideClassInfo2Impl<&CLSID_CAtlButton, &DIID__ATLButton, &LIBID_ATLBUTNLib>,
	public IPersistPropertyBagImpl<CAtlButton>,
	public IConnectionPointContainerImpl<CAtlButton>,
	public CProxy_ATLButton<CAtlButton>,
	public IObjectSafetyImpl<CAtlButton, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
	CAtlButton()
	{
		m_nEntry = 0;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ATLBUTTON)


BEGIN_COM_MAP(CAtlButton)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IAtlButton)
	COM_INTERFACE_ENTRY(IViewObject)
	COM_INTERFACE_ENTRY(IViewObject2)
	COM_INTERFACE_ENTRY(IViewObjectEx)
	COM_INTERFACE_ENTRY(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY2(IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceObject)
	COM_INTERFACE_ENTRY(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY(IOleControl)
	COM_INTERFACE_ENTRY(IOleObject)
	COM_INTERFACE_ENTRY(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist, IPersistStreamInit)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
	COM_INTERFACE_ENTRY_IMPL(IPersistPropertyBag)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IObjectSafety)
END_COM_MAP()

BEGIN_PROP_MAP(CAtlButton)
	PROP_DATA_ENTRY("_cx", m_sizeExtent.cx, VT_UI4)
	PROP_DATA_ENTRY("_cy", m_sizeExtent.cy, VT_UI4)
	PROP_ENTRY_TYPE_EX("Static_Image", 3, CLSID_MSStockPicture, IID_IAtlButton, VT_DISPATCH)
	PROP_ENTRY_TYPE("Hover_Image", 4, CLSID_MSStockPicture, VT_DISPATCH)
	PROP_ENTRY_TYPE("Push_Image", 5, CLSID_MSStockPicture, VT_DISPATCH)
END_PROP_MAP()

BEGIN_CONNECTION_POINT_MAP(CAtlButton)
	CONNECTION_POINT_ENTRY(DIID__ATLButton)
END_CONNECTION_POINT_MAP()

BEGIN_MSG_MAP(CAtlButton)
	MESSAGE_HANDLER(WM_ERASEBKGND, OnErase)
	MESSAGE_HANDLER(WM_MOUSEMOVE, OnMouseMove)
	MESSAGE_HANDLER(WM_LBUTTONDOWN, OnButtonDown)
	MESSAGE_HANDLER(WM_LBUTTONUP, OnButtonUp)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
END_MSG_MAP()

	LRESULT OnErase(UINT, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		return 0;
	}
	LRESULT OnButtonDown(UINT, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		m_nEntry = 2;
		FireViewChange();
		OnClick();
		return 0;
	}
	LRESULT OnButtonUp(UINT, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		m_nEntry = 1;
		FireViewChange();
		OnClick();
		return 0;
	}
	LRESULT OnMouseMove(UINT, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		if (m_nEntry == 0)
		{
			m_nEntry = 1;
			FireViewChange();
		}
		return 0;
	}

// IAtlButton
public:
	CComPtr<IPictureDisp> m_spPictures[3];
	int m_nEntry;

	HRESULT PutImage(IPictureDisp* pPicture, int nEntry)
	{
		if (FireOnRequestEdit(DISPID_PICTURE) == S_FALSE)
			return S_FALSE;
		m_spPictures[nEntry] = 0;
		if (pPicture)
		{
			CComQIPtr<IPersistStream, &IID_IPersistStream> p(pPicture);
			if (p)
			{
				ULARGE_INTEGER l;
				p->GetSizeMax(&l);
				HGLOBAL hGlob = GlobalAlloc(GHND, l.LowPart);
				if (hGlob)
				{
					CComPtr<IStream> spStream;
					CreateStreamOnHGlobal(hGlob, TRUE, &spStream);
					if (spStream)
					{
						if (SUCCEEDED(p->Save(spStream, FALSE)))
						{
							LARGE_INTEGER l1;
							l1.QuadPart = 0;
							spStream->Seek(l1, STREAM_SEEK_SET, NULL);
							OleLoadPicture(spStream, l1.LowPart, FALSE, IID_IPictureDisp, (void**)&m_spPictures[nEntry]);
						}
						spStream.Release();
					}
					GlobalFree(hGlob);
				}
			}
		}
		m_bRequiresSave = TRUE;
		FireOnChanged(nEntry + 3);
		FireViewChange();
		SendOnDataChange(NULL);

		return S_OK;

	}
	HRESULT PutRefImage(IPictureDisp* pPicture, int nEntry)
	{
		if (FireOnRequestEdit(DISPID_PICTURE) == S_FALSE)
			return S_FALSE;
		m_spPictures[nEntry] = pPicture;
		m_bRequiresSave = TRUE;
		FireOnChanged(DISPID_PICTURE);
		FireViewChange();
		SendOnDataChange(NULL);
		return S_OK;
	}

	HRESULT GetImage(IPictureDisp **ppPicture, int nEntry)
	{
		if (ppPicture != NULL)
		{
			*ppPicture = m_spPictures[nEntry];
			if (*ppPicture)
				(*ppPicture)->AddRef();
			return S_OK;
		}
		return E_POINTER;
	}

	STDMETHOD(putref_PictureStatic)(IPictureDisp *pPicture)
	{
		return PutRefImage(pPicture, 0);
	}
    
    STDMETHOD(put_PictureStatic)( IPictureDisp *pPicture)
	{
		return PutImage(pPicture, 0);
	}
    
    STDMETHOD(get_PictureStatic)(IPictureDisp **ppPicture)
	{
		return GetImage(ppPicture, 0);
	}
    
	STDMETHOD(putref_PictureHover)(IPictureDisp *pPicture)
	{
		return PutRefImage(pPicture, 1);
	}
    
    STDMETHOD(put_PictureHover)( IPictureDisp *pPicture)
	{
		return PutImage(pPicture, 1);
	}
    
    STDMETHOD(get_PictureHover)(IPictureDisp **ppPicture)
	{
		return GetImage(ppPicture, 1);
	}
	STDMETHOD(putref_PicturePush)(IPictureDisp *pPicture)
	{
		return PutRefImage(pPicture, 2);
	}
    
    STDMETHOD(put_PicturePush)( IPictureDisp *pPicture)
	{
		return PutImage(pPicture, 2);
	}
    
    STDMETHOD(get_PicturePush)(IPictureDisp **ppPicture)
	{
		return GetImage(ppPicture, 2);
	}

	STDMETHOD(_OnTimer)()
	{
		POINT pos;
		GetCursorPos(&pos);
		if (m_bInPlaceActive)
		{
			HWND hwnd;
			m_spInPlaceSite->GetWindow(&hwnd);
			::ScreenToClient(hwnd, &pos);

			if (!PtInRect(&m_rcPos, pos))
			{
				if (m_nEntry > 0)
				{
					m_nEntry = 0;
					FireViewChange();
				}
			}
		}

		return S_OK;
	}
	HRESULT InPlaceActivate(LONG iVerb, const RECT* prcPosRect = NULL)
	{
		HRESULT hr;

		hr = CComControl<CAtlButton>::InPlaceActivate(iVerb, prcPosRect);
		TimerOn(250);
		return hr;
	}
	STDMETHOD(InPlaceDeactivate)(void)
	{
		TimerOff();
		return IOleInPlaceObjectWindowlessImpl<CAtlButton>::InPlaceDeactivate();
	}

	HRESULT OnDraw(ATL_DRAWINFO& di)
	{
		RECT& rc = *(RECT*)di.prcBounds;

		if (m_spPictures[m_nEntry])
		{
			CComPtr<IPicture> spPicture;
			HRESULT hr = m_spPictures[m_nEntry].QueryInterface(&spPicture);
			if (FAILED(hr))
				return hr;

			OLE_XSIZE_HIMETRIC hmWidth;
			OLE_YSIZE_HIMETRIC hmHeight;

			spPicture->get_Width(&hmWidth);
			spPicture->get_Height(&hmHeight);

			spPicture->Render(di.hdcDraw, 
				rc.left, rc.top, (rc.right - rc.left), (rc.bottom - rc.top), 
				0, hmHeight - 1, hmWidth, -hmHeight,
				&rc);
		}
		return S_OK;
	}

	STDMETHOD(QueryHitPoint)(DWORD dwAspect, LPCRECT pRectBounds, POINT ptlLoc, LONG /* lCloseHint */, DWORD *pHitResult)
	{
		if (dwAspect == DVASPECT_CONTENT)
		{
			*pHitResult = PtInRect(pRectBounds, ptlLoc) ? HITRESULT_HIT : HITRESULT_OUTSIDE;
			if (m_nEntry == 0)
			{
				m_nEntry = 1;
				FireViewChange();
			}
			return S_OK;
		}
		ATLTRACE(_T("Wrong DVASPECT\n"));
		return E_FAIL;
	}
};
