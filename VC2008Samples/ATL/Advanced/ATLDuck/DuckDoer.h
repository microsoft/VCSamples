// DuckDoer.h : Declaration of the CDuckDoer
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __DUCKDOER_H_
#define __DUCKDOER_H_

#include "resource.h"       // main symbols
#include "cpduck.h"
#include "duckdoerdlg.h"
#include "atlduck.h"

/////////////////////////////////////////////////////////////////////////////
// CDuckDoer
class ATL_NO_VTABLE CDuckDoer :
	public CComObjectRootEx<CComObjectThreadModel>,
	public CComCoClass<CDuckDoer, &CLSID_DuckDoer>,
	public CProxyIDuckInt<CDuckDoer>,
	public IConnectionPointContainerImpl<CDuckDoer>,
	public IDuckDoer
{
public:
	CDuckDoer()
	{
		// The dialog has to exist always before a duck doer object is created
		// because the dialog is created in tWinMain, which happens before
		// IClassFactory::CreateInstance.
		ATLENSURE(m_pDlg != NULL);
		m_pDlg->SetOwner(this);
		m_bLocked = FALSE;
	}

	~CDuckDoer()
	{
		if (m_pDlg != NULL)
		{
			m_pDlg->DestroyWindow();
		}
	}

	

DECLARE_REGISTRY_RESOURCEID(IDR_DUCKDOER)
DECLARE_NOT_AGGREGATABLE(CDuckDoer)
DECLARE_CLASSFACTORY_SINGLETON(CDuckDoer)


public:
	STDMETHOD(Advise)(IUnknown* pUnk, DWORD* pdwCookie);
	STDMETHOD(Unadvise)(DWORD dwCookie);


BEGIN_COM_MAP(CDuckDoer)
	COM_INTERFACE_ENTRY(IDuckDoer)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

	static CDuckDoerDlg* m_pDlg;
	BOOL m_bLocked;

BEGIN_CONNECTION_POINT_MAP(CDuckDoer)
	CONNECTION_POINT_ENTRY(IID_IDuckInt)
END_CONNECTION_POINT_MAP()

	// IDuckDoer
};
OBJECT_ENTRY_AUTO(CLSID_DuckDoer, CDuckDoer)


#endif //__DUCKDOER_H_
