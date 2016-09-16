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
// IATLAsync
[
	object,
	uuid(12BFAE1F-0BF9-4170-BE6E-31723B61C033),
	dual,
	helpstring("IATLAsyncAttrib Interface"),
	pointer_default(unique)
]
__interface IATLAsyncAttrib : IDispatch
{
	[propput, id(0)] HRESULT URL([in]BSTR strURL);
	[propget, id(0)] HRESULT URL([out,retval]BSTR* pstrURL);

};

/////////////////////////////////////////////////////////////////////////////
// CATLAsync
[
	coclass,
	threading(apartment),
	version("1.0"),
	uuid("F447C21A-5F8C-4E88-B2D9-B76027CACFA5"),
	progid("ATLAsync.ATLAsync.1"),
	vi_progid("ATLAsync.ATLAsync"),
	default("IATLAsyncAttrib"),
	registration_script("ATLAsync.rgs")
]
class ATL_NO_VTABLE CATLAsyncAttrib :
	public IATLAsyncAttrib,
	public CComControl<CATLAsyncAttrib>,
	public IProvideClassInfoImpl<&__uuidof(CATLAsyncAttrib), &_AtlModule.m_libid>,
	public IPersistStreamInitImpl<CATLAsyncAttrib>,
	public IPersistStorageImpl<CATLAsyncAttrib>,
	public IQuickActivateImpl<CATLAsyncAttrib>,
	public IOleControlImpl<CATLAsyncAttrib>,
	public IOleObjectImpl<CATLAsyncAttrib>,
	public IOleInPlaceActiveObjectImpl<CATLAsyncAttrib>,
	public IViewObjectExImpl<CATLAsyncAttrib>,
	public IOleInPlaceObjectWindowlessImpl<CATLAsyncAttrib>,
	public IDataObjectImpl<CATLAsyncAttrib>,
	public IPersistPropertyBagImpl<CATLAsyncAttrib>,
	public IPerPropertyBrowsingImpl<CATLAsyncAttrib>,
	public IObjectSafetyImpl<CATLAsyncAttrib, INTERFACESAFE_FOR_UNTRUSTED_CALLER>
{
public:
	CContainedWindow m_EditCtrl;

	CATLAsyncAttrib() : m_EditCtrl(_T("EDIT"), this, 1)
	{
		m_bWindowOnly = TRUE;
	}

BEGIN_PROPERTY_MAP(CATLAsyncAttrib)
	PROP_ENTRY_TYPE("URL", 0, CLSID_NULL, VT_BSTR)
END_PROPERTY_MAP()


BEGIN_MSG_MAP(CATLAsyncAttrib)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
ALT_MSG_MAP(1)
	MESSAGE_HANDLER(WM_LBUTTONDBLCLK, OnDoubleClick)
END_MSG_MAP()

// IATLAsync
public:

	HRESULT OnDraw(ATL_DRAWINFO&)
	{
		return 0;
	}
	LRESULT OnDoubleClick(UINT, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		put_URL(CComBSTR(_T("http://www.microsoft.com")));

		return 0;
	}
	LRESULT OnCreate(UINT, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		RECT rc;
		GetWindowRect(&rc);
		rc.right -= rc.left;
		rc.bottom -= rc.top;
		rc.top = rc.left = 0;
		USES_CONVERSION;
		m_EditCtrl.Create(m_hWnd, rc, OLE2CT((BSTR)m_bstrText), WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL);
		::SendMessage(m_EditCtrl.m_hWnd, WM_SETTEXT, 0,  (LPARAM)_T("Double click on this window or set the URL property to initiate download."));
		return 0;
	}
	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		IOleInPlaceObjectWindowlessImpl<CATLAsyncAttrib>::SetObjectRects(prcPos, prcClip);
		int cx, cy;
		cx = prcPos->right - prcPos->left;
		cy = prcPos->bottom - prcPos->top;
		::SetWindowPos(m_EditCtrl.m_hWnd, NULL, 0,
					 0, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);
		return S_OK;
	}

	CComBSTR m_bstrText;    //holds data received from the URL

	//OnData will be used as a callback functin by the CBindStatusCallback object.
	//OnData will be called periodically with data from the asynchronous transfer
	void OnData(CBindStatusCallback<CATLAsyncAttrib>* pbsc, BYTE* pBytes, DWORD dwSize)
	{
		ATLTRACE(_T("OnData called\n"));
		m_bstrText.Append((LPCSTR)pBytes);
		if (::IsWindow(m_EditCtrl.m_hWnd))
		{
			USES_CONVERSION;
			::SendMessage(m_EditCtrl.m_hWnd, WM_SETTEXT, 0,  (LPARAM)OLE2CT((BSTR)m_bstrText));
		}
	}

	//put_URL is the put method for the URL property.
	//Calling this function starts the URL transfer.
	STDMETHOD(put_URL)(BSTR strURL)
	{
		USES_CONVERSION;
		ATLTRACE(_T("IATLAsync::put_URL\n"));
		m_bstrURL = strURL;
		if (::IsWindow(m_EditCtrl.m_hWnd))
		{
			USES_CONVERSION;
			::SendMessage(m_EditCtrl.m_hWnd, WM_SETTEXT, 0,  (LPARAM)_T(""));
			CBindStatusCallback<CATLAsyncAttrib>::Download(this, &CATLAsyncAttrib::OnData, m_bstrURL, m_spClientSite, FALSE);
		}
		return S_OK;
	}
	STDMETHOD(get_URL)(BSTR* pstrURL)
	{
		ATLTRACE(_T("IATLAsync::get_URL\n"));
		*pstrURL = m_bstrURL.Copy();
		return S_OK;
	}
	CComBSTR m_bstrURL; //string representing a URL
};
