// DrawCliLiveIconsHandler.h : Declaration of the CDrawCliLiveIconsHandler

#pragma once
#include "resource.h"       // main symbols

#include <atlhandler.h>
#include <atlhandlerimpl.h>
#include "..\drawdoc.h"

#include "DrawClientHandlers_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDrawCliLiveIconsHandler

class ATL_NO_VTABLE CDrawCliLiveIconsHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDrawCliLiveIconsHandler, &CLSID_DrawCliLiveIconsHandler>,
	public CThumbnailProviderImpl
{
public:
	CDrawCliLiveIconsHandler()
	{		
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DRAWCLILIVEICONSHANDLER)

DECLARE_NOT_AGGREGATABLE(CDrawCliLiveIconsHandler)

BEGIN_COM_MAP(CDrawCliLiveIconsHandler)
	COM_INTERFACE_ENTRY(IInitializeWithStream)
	COM_INTERFACE_ENTRY(IThumbnailProvider)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		CThumbnailProviderImpl::FinalRelease ();
	}

public:

protected:
	virtual HRESULT GetBitmap(UINT cx, HBITMAP *phbmp, WTS_ALPHATYPE *pdwAlpha)
	{
		CDrawDoc* pDocument = DYNAMIC_DOWNCAST (CDrawDoc, (CObject*) m_pDocument->GetContainer ());

		HDC hdc = ::GetDC(NULL);
		CDC* pDC = CDC::FromHandle(hdc);
		CDC dc;
		CDC* pDrawDC = pDC;
		CBitmap* pOldBitmap = NULL;
		CBitmap bitmap;

		pDocument->FixUpObjectPositions();
		CRect rectDocBounds = pDocument->m_rectDocumentBounds;

		if (dc.CreateCompatibleDC(pDC))
		{
			if (bitmap.CreateCompatibleBitmap(pDC, rectDocBounds.Width(), rectDocBounds.Height()))
			{
				pDrawDC = &dc;
				pOldBitmap = dc.SelectObject(&bitmap);
			}
		}
		else
		{
			::ReleaseDC(NULL, hdc);
			return E_FAIL;
		}

		dc.SelectObject(&bitmap);
		pDocument->Draw(pDrawDC);

		if (pDrawDC != pDC)
		{
			dc.SelectObject(pOldBitmap);
		}

		::ReleaseDC (NULL, hdc);
		*phbmp = (HBITMAP)bitmap.Detach ();

		return S_OK;
	}
	DECLARE_DOCUMENT(CDrawDoc)
};

OBJECT_ENTRY_AUTO(__uuidof(DrawCliLiveIconsHandler), CDrawCliLiveIconsHandler)
