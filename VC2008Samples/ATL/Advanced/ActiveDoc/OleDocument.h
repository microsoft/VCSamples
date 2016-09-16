// OleDocument.h : IOleDocument implementation
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include <docobj.h>

//////////////////////////////////////////////////////////////////////////////
// IOleDocumentImpl
template <class T>
class ATL_NO_VTABLE IOleDocumentImpl : public IOleDocument
{
public:
	STDMETHOD(CreateView)(IOleInPlaceSite *pIPSite, IStream *pstm,
		DWORD /* dwReserved */, IOleDocumentView **ppView)
	{
		ATLTRACE(_T("IOleDocument::CreateView\n"));
		T* pT = static_cast<T*>(this);

		if (ppView == NULL)
			return E_POINTER;

		// If we've already created a view then we can't create another as we
		// currently only support the ability to create one view
		if (pT->m_spInPlaceSite != NULL)
			return E_FAIL;

		IOleDocumentView* pView;
		pT->GetUnknown()->QueryInterface(IID_IOleDocumentView, (void**)&pView);
		// If we support IOleDocument we should support IOleDocumentView
		ATLENSURE(pView != NULL);

		// If they've given us a site then use it
		if (pIPSite != NULL)
			pView->SetInPlaceSite(pIPSite);

		// If they have given us an IStream pointer then use it to
		// initialize the view
		if (pstm != NULL)
		{
			pView->ApplyViewState(pstm);
		}

		// Return the view
		*ppView = pView;

		return S_OK;
	}

	STDMETHOD(GetDocMiscStatus)(DWORD *pdwStatus)
	{
		ATLTRACE(_T("IOleDocument::GetDocMiscStatus\n"));
		*pdwStatus = DOCMISC_NOFILESUPPORT;
		return S_OK;
	}

	STDMETHOD(EnumViews)(IEnumOleDocumentViews** /*ppEnum*/,
		IOleDocumentView **ppView)
	{
		ATLTRACE(_T("IOleDocument::EnumViews\n"));
		T* pT = static_cast<T*>(this);

		if (ppView == NULL)
			return E_POINTER;

		// We only support one view
		pT->_InternalQueryInterface(IID_IOleDocumentView, (void**)ppView);
		return S_OK;
	}
};

//////////////////////////////////////////////////////////////////////////////
// IOleDocumentViewImpl

template <class T>
class ATL_NO_VTABLE IOleDocumentViewImpl : public IOleDocumentView
{
public:
	STDMETHOD(SetInPlaceSite)(IOleInPlaceSite *pIPSite)
	{
		ATLTRACE(_T("IOleDocumentView::SetInPlaceSite\n"));
		T* pT = static_cast<T*>(this);
		HRESULT hr;

		if (pT->m_spInPlaceSite)
		{
			// If we already have a site get rid of it
			UIActivate(FALSE);
			hr = pT->InPlaceDeactivate();
			if (FAILED(hr))
				return hr;
			ATLASSERT(!pT->m_bInPlaceActive);
		}
		if (pIPSite != NULL)
			pT->m_spInPlaceSite = (IOleInPlaceSiteWindowless*)pIPSite;

		return S_OK;
	}

   STDMETHOD(GetInPlaceSite)(IOleInPlaceSite **ppIPSite)
	{
		ATLTRACE(_T("IOleDocumentView::GetInPlaceSite\n"));
		T* pT = static_cast<T*>(this);

		ATLASSERT(ppIPSite);
		if (ppIPSite == NULL)
			return E_FAIL;

		*ppIPSite = pT->m_spInPlaceSite;
		pT->m_spInPlaceSite.p->AddRef();
		return S_OK;
	}

	STDMETHOD(GetDocument)(IUnknown **ppunk)
	{
		ATLTRACE(_T("IOleDocumentView::GetDocument\n"));
		T* pT = static_cast<T*>(this);

		ATLASSERT(ppunk);
		if (ppunk == NULL)
			return E_FAIL;

		*ppunk = pT->GetUnknown();
		(*ppunk)->AddRef();
		return S_OK;
	}

	STDMETHOD(SetRect)(LPRECT prcView)
	{
		static bool bResizing;
		if (bResizing)
			return S_OK;
		bResizing = true;
		
		ATLTRACE("IOleDocumentView::SetObjectRects(%d, %d,  %d, %d)\n", prcView->left, prcView->top, prcView->right, prcView->bottom);
		T* pT = static_cast<T*>(this);
		pT->SetObjectRects(prcView, prcView);

		bResizing = false;
		return S_OK;
	}

	STDMETHOD(GetRect)(LPRECT prcView)
	{
		ATLTRACE(_T("IOleDocumentView::GetRect\n"));
		T* pT = static_cast<T*>(this);

		ATLASSERT(prcView);
		if (prcView == NULL)
			return E_POINTER;

		*prcView = pT->m_rcPos;
		return S_OK;
	}

	STDMETHOD(SetRectComplex)(LPRECT /* prcView */, LPRECT /* prcHScroll */,
		LPRECT /* prcVScroll */, LPRECT /* prcSizeBox */)
	{
		ATLTRACENOTIMPL(_T("IOleDocumentView::SetRectComplex"));
	}

	STDMETHOD(Show)(BOOL fShow)
	{
		ATLTRACE(_T("IOleDocumentView::Show\n"));
		T* pT = static_cast<T*>(this);
		HRESULT hr = S_OK;

		if (fShow)
		{
			if (!pT->m_bUIActive)
				hr = pT->ActiveXDocActivate(OLEIVERB_INPLACEACTIVATE);
		}
		else
		{
			hr = pT->UIActivate(FALSE);
			::ShowWindow(pT->m_hWnd, SW_HIDE);
		}
		return hr;
	}

	STDMETHOD(UIActivate)(BOOL fUIActivate)
	{
		ATLTRACE(_T("IOleDocumentView::UIActivate\n"));
		T* pT = static_cast<T*>(this);
		HRESULT hr = S_OK;

		if (fUIActivate)
		{
			// We must know the client site first
			if (pT->m_spInPlaceSite == NULL)
				return E_UNEXPECTED;
			if (!pT->m_bUIActive)
				hr = pT->ActiveXDocActivate(OLEIVERB_UIACTIVATE);
		}
		else
		{
			pT->InPlaceMenuDestroy();
			pT->DestroyToolbar();
			hr = pT->UIDeactivate();
		}

		return hr;
	}

	STDMETHOD(Open)()
	{
		ATLTRACENOTIMPL(_T("IOleDocumentView::Open"));
	}

	STDMETHOD(CloseView)(DWORD /* dwReserved */)
	{
		ATLTRACE(_T("IOleDocumentView::CloseView\n"));
		T* pT = static_cast<T*>(this);
		pT->Show(FALSE);
		pT->SetInPlaceSite(NULL);
		return S_OK;
	}

	STDMETHOD(SaveViewState)(LPSTREAM /* pstm */)
	{
		ATLTRACENOTIMPL(_T("IOleDocumentView::SaveViewState"));
	}

	STDMETHOD(ApplyViewState)(LPSTREAM /* pstm */)
	{
		ATLTRACENOTIMPL(_T("IOleDocumentView::ApplyViewState"));
	}

	STDMETHOD(Clone)(IOleInPlaceSite* /* pIPSiteNew */,
		IOleDocumentView** /* ppViewNew */)
	{
		ATLTRACENOTIMPL(_T("IOleDocumentView::Clone"));
	}

	HRESULT ActiveXDocActivate(LONG iVerb)
	{
		HRESULT hr;
		T* pT = static_cast<T*>(this);

		pT->m_bNegotiatedWnd = TRUE;

		if (!pT->m_bInPlaceActive)
		{
			hr = pT->m_spInPlaceSite->CanInPlaceActivate();
			if (FAILED(hr))
				return hr;
			pT->m_spInPlaceSite->OnInPlaceActivate();
		}
		pT->m_bInPlaceActive = TRUE;

		// get location in the parent window,
		// as well as some information about the parent
		RECT rcPos, rcClip;
		CComPtr<IOleInPlaceUIWindow> spInPlaceUIWindow;
		pT->m_frameInfo.cb = sizeof(OLEINPLACEFRAMEINFO);

		HWND hwndParent;
		if (pT->m_spInPlaceSite->GetWindow(&hwndParent) == S_OK)
		{
			pT->m_spInPlaceFrame.Release();
			pT->m_spInPlaceSite->GetWindowContext(&pT->m_spInPlaceFrame,
				&spInPlaceUIWindow, &rcPos, &rcClip, &pT->m_frameInfo);

			if (!pT->m_bWndLess)
			{
				if (pT->m_hWnd)
				{
					::ShowWindow(pT->m_hWnd, SW_SHOW);
					pT->SetFocus();
				}
				else
					pT->m_hWnd = pT->Create(hwndParent, rcPos);
			}
			pT->SetObjectRects(&rcPos, &rcClip);
		}

		CComPtr<IOleInPlaceActiveObject> spActiveObject;
		QueryInterface(IID_IOleInPlaceActiveObject, (void**)&spActiveObject);

		// Gone active by now, take care of UIACTIVATE
		if (pT->DoesVerbUIActivate(iVerb))
		{
			if (!pT->m_bUIActive)
			{
				pT->m_bUIActive = TRUE;
				hr = pT->m_spInPlaceSite->OnUIActivate();
				if (FAILED(hr))
					return hr;

				// set ourselves up in the host
				if (spActiveObject != NULL)
				{
					if (pT->m_spInPlaceFrame != NULL)
						pT->m_spInPlaceFrame->SetActiveObject(spActiveObject, NULL);
					if (spInPlaceUIWindow != NULL)
						spInPlaceUIWindow->SetActiveObject(spActiveObject, NULL);
				}
			}
		}

		// Merge the menus
		pT->InPlaceMenuCreate();
		pT->SetupToolbar(spInPlaceUIWindow);
		pT->m_spClientSite->ShowObject();
		return S_OK;
	}
};
