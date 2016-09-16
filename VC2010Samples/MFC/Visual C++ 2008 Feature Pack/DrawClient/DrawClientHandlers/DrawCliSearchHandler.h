// DrawCliSearchHandler.h : Declaration of the CDrawCliSearchHandler

#pragma once
#include "resource.h"       // main symbols

#include <atlhandler.h>
#include <atlhandlerimpl.h>
#include "..\drawdoc.h"

#include "DrawClientHandlers_i.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDrawCliSearchHandler

class ATL_NO_VTABLE CDrawCliSearchHandler :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDrawCliSearchHandler, &CLSID_DrawCliSearchHandler>,
	public CSearchFilterImpl
{
public:
	CDrawCliSearchHandler()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DRAWCLISEARCHHANDLER)

DECLARE_NOT_AGGREGATABLE(CDrawCliSearchHandler)

BEGIN_COM_MAP(CDrawCliSearchHandler)
	COM_INTERFACE_ENTRY(IPersistStream)
	COM_INTERFACE_ENTRY(IPersistFile)
	COM_INTERFACE_ENTRY(IFilter)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
		CSearchFilterImpl::FinalRelease ();
	}

public:
	// IPersistStream implementation
	IFACEMETHODIMP GetClassID(CLSID* pClassID)
	{
		*pClassID = CLSID_DrawCliSearchHandler;
		return S_OK;
	};

	DECLARE_DOCUMENT(CDrawDoc)
};

OBJECT_ENTRY_AUTO(__uuidof(DrawCliSearchHandler), CDrawCliSearchHandler)
