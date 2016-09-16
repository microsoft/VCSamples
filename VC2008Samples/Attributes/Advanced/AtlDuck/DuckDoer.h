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
#include "duckdoerdlg.h"


[ dispinterface,
  uuid(78A7BED6-B940-4B38-8261-4E6B4094F9ED),
  helpstring("IDuckInt Interface")
]
__interface IDuckInt : IDispatch
{
	[id(0),helpstring("method Quack")] HRESULT Quack(BSTR szWhosCalling);
	[id(1),helpstring("method Flap")] HRESULT Flap(BSTR szWhosCalling);
	[id(2),helpstring("method Paddle")] HRESULT Paddle(BSTR szWhosCalling);
	[id(3),helpstring("method Walk")] HRESULT Walk(BSTR szWhosCalling);
};


/////////////////////////////////////////////////////////////////////////////
// CDuckDoer
[ coclass,
  uuid(6D6B20D3-E68A-4691-9D7E-E6B34AD1F29E),
  helpstring("DuckDoer Attrib Class"),
  progid("AtlDuck.Atlduckattrib.1"),
  vi_progid("AtlDuck.Atlduckattrib"),
  default("IDispatch"),
  aggregatable(never),
  event_source(com)
]
class ATL_NO_VTABLE CDuckDoer
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

	HRESULT FinalConstruct()
	{
#ifdef _DEBUG
		_ASSERTE(AddRef() > 0);
#else
		AddRef();
#endif
		return S_OK;
	}


DECLARE_CLASSFACTORY_SINGLETON(CDuckDoer)


public:
	STDMETHOD(Advise)(IUnknown* pUnk, DWORD* pdwCookie);
	STDMETHOD(Unadvise)(DWORD dwCookie);


	static CDuckDoerDlg* m_pDlg;
	BOOL m_bLocked;

__event __interface IDuckInt;

	// IDuckDoer
};


#endif //__DUCKDOER_H_
