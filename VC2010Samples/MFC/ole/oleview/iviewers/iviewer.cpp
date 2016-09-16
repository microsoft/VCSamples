// iviewer.h : implementation file
//
// Base iviewer class
//
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "iviewers.h"
#include "iviewer.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInterfaceViewer command target

/////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////
// CInterfaceViewer

IMPLEMENT_DYNAMIC(CInterfaceViewer, CCmdTarget)

CInterfaceViewer::CInterfaceViewer()
{
	AfxOleLockApp() ;
}

CInterfaceViewer::~CInterfaceViewer()
{
	AfxOleUnlockApp() ;
}

HRESULT CInterfaceViewer::OnView(HWND /*hwndParent*/, REFIID /*riid*/, LPUNKNOWN /*punk*/)
{
	AfxMessageBox(_T("Implement interface viewer UI here.") ) ;
	return NOERROR ;
}

BEGIN_MESSAGE_MAP(CInterfaceViewer, CCmdTarget)
	//{{AFX_MSG_MAP(CInterfaceViewer)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CInterfaceViewer message handlers

/////////////////////////////////////////////////////////////////////////////
// IInterfaceViewer implementation

BEGIN_INTERFACE_MAP(CInterfaceViewer, CCmdTarget)
	INTERFACE_PART(CInterfaceViewer, IID_IInterfaceViewer, InterfaceViewer)
END_INTERFACE_MAP()

STDMETHODIMP_(ULONG) CInterfaceViewer::XInterfaceViewer::AddRef()
{
	METHOD_PROLOGUE(CInterfaceViewer, InterfaceViewer)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CInterfaceViewer::XInterfaceViewer::Release()
{
	METHOD_PROLOGUE(CInterfaceViewer, InterfaceViewer)
	return pThis->ExternalRelease();
}

STDMETHODIMP CInterfaceViewer::XInterfaceViewer::QueryInterface(REFIID iid, void** ppvObj)
{
	METHOD_PROLOGUE(CInterfaceViewer, InterfaceViewer)
	return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj) ;
}

STDMETHODIMP CInterfaceViewer::XInterfaceViewer::View(HWND hwndParent, REFIID riid, LPUNKNOWN punk)
{
	METHOD_PROLOGUE(CInterfaceViewer, InterfaceViewer)
	return pThis->OnView( hwndParent, riid, punk ) ;
}
