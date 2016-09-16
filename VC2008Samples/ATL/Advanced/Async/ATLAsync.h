// ATLAsync.h : Declaration of the CATLAsync
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


/////////////////////////////////////////////////////////////////////////////
// CATLAsync
class CATLAsync :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CATLAsync, &CLSID_CATLAsync>,
	public IDispatchImpl<IATLAsync, &IID_IATLAsync, &LIBID_ASYNCLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public CComControl<CATLAsync>,
	public IProvideClassInfoImpl<&CLSID_CATLAsync, &LIBID_ASYNCLib>,
	public IPersistStreamInitImpl<CATLAsync>,
	public IPersistStorageImpl<CATLAsync>,
	public IQuickActivateImpl<CATLAsync>,
	public IOleControlImpl<CATLAsync>,
	public IOleObjectImpl<CATLAsync>,
	public IOleInPlaceActiveObjectImpl<CATLAsync>,
	public IViewObjectExImpl<CATLAsync>,
	public IOleInPlaceObjectWindowlessImpl<CATLAsync>,
	public IDataObjectImpl<CATLAsync>,
	public IPersistPropertyBagImpl<CATLAsync>,
	public IPerPropertyBrowsingImpl<CATLAsync>,
	public IObjectSafetyImpl<CATLAsync, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
	CContainedWindow m_EditCtrl;

	CATLAsync() : m_EditCtrl(_T("EDIT"), this, 1)
	{
		m_bWindowOnly = TRUE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ATLAsync)


BEGIN_COM_MAP(CATLAsync)
	COM_INTERFACE_ENTRY(IATLAsync)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IObjectSafety)
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
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IPersist, IPersistPropertyBag)
	COM_INTERFACE_ENTRY_IMPL(IPersistPropertyBag)
	COM_INTERFACE_ENTRY_IMPL(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
END_COM_MAP()

BEGIN_PROPERTY_MAP(CATLAsync)
	PROP_ENTRY_TYPE("URL", 0, CLSID_NULL, VT_BSTR)
END_PROPERTY_MAP()


BEGIN_MSG_MAP(CATLAsync)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
ALT_MSG_MAP(1)
	MESSAGE_HANDLER(WM_LBUTTONDBLCLK, OnDoubleClick)
END_MSG_MAP()

// IATLAsync
public:

	HRESULT OnDraw(ATL_DRAWINFO&)
	{
		return S_OK;
	}
	LRESULT OnDoubleClick(UINT, WPARAM , LPARAM , BOOL& )
	{
		put_URL(CComBSTR(_T("http://www.microsoft.com")));

		return 0;
	}
	LRESULT OnCreate(UINT, WPARAM , LPARAM , BOOL& )
	{
		RECT rc;
		GetWindowRect(&rc);
		rc.right -= rc.left;
		rc.bottom -= rc.top;
		rc.top = rc.left = 0;

		m_EditCtrl.Create(m_hWnd, rc, NULL, WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL);
		::SendMessage(m_EditCtrl.m_hWnd, WM_SETTEXT, 0,  (LPARAM)_T("Double click on this window or set the URL property to initiate download."));
		return 0;
	}
	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		IOleInPlaceObjectWindowlessImpl<CATLAsync>::SetObjectRects(prcPos, prcClip);
		int cx, cy;
		cx = prcPos->right - prcPos->left;
		cy = prcPos->bottom - prcPos->top;
		::SetWindowPos(m_EditCtrl.m_hWnd, NULL, 0,
					 0, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);
		return S_OK;
	}

	CComBSTR m_bstrText;    //holds data received from the URL

	//OnData will be used as a callback function by the CBindStatusCallback object.
	//OnData will be called periodically with data from the asynchronous transfer
	void OnData(CBindStatusCallback<CATLAsync>* , BYTE* pBytes, DWORD cBytes)
	{
		ATLTRACE(_T("OnData called\n"));

		cBytes;			// Avoid unused parameter warning.
		
		// CBindStatuscCallback really returns cBytes + 1 bytes in 
		// pBytes, the last byte is ensured to be zero, so the append 
		// works without extra checking - if you are using binary
		// data, you should rely only on cBytes of data passed in.

		m_bstrText.Append((LPCSTR)pBytes);
		if (::IsWindow(m_EditCtrl.m_hWnd))
		{
			USES_CONVERSION;
			_ATLTRY {
				::SendMessage(m_EditCtrl.m_hWnd, WM_SETTEXT, 0,  (LPARAM)(LPCSTR)COLE2CT((BSTR)m_bstrText));
			}
			_ATLCATCH( e ) {
				e; // unused
				// COLE2CT threw an exception!
				::SendMessage(m_EditCtrl.m_hWnd, WM_SETTEXT, 0, (LPARAM)_T("Could not allocate enough memory!!!"));
			}
		}
	}

	//put_URL is the put method for the URL property.
	//Calling this function starts the URL transfer.
	STDMETHOD(put_URL)(BSTR strURL)
	{
		HRESULT hResult = E_UNEXPECTED;

		ATLTRACE(_T("IATLAsync::put_URL\n"));
		m_bstrURL = strURL;

		if (::IsWindow(m_EditCtrl.m_hWnd))
		{
			::SendMessage(m_EditCtrl.m_hWnd, WM_SETTEXT, 0,  (LPARAM)_T(""));
			hResult = CBindStatusCallback<CATLAsync>::Download(this, &CATLAsync::OnData, m_bstrURL, m_spClientSite, FALSE);
		}

		return hResult;
	}

	STDMETHOD(get_URL)(BSTR* pstrURL)
	{
		ATLTRACE(_T("IATLAsync::get_URL\n"));
		if ( ( *pstrURL = m_bstrURL.Copy() ) == NULL && m_bstrURL != NULL )
			return E_OUTOFMEMORY;
		else 
			return S_OK;
	}

	CComBSTR m_bstrURL; //string representing a URL
};

OBJECT_ENTRY_AUTO(__uuidof(CATLAsync), CATLAsync)
