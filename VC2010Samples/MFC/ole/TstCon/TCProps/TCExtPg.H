// TCExtPage.H : Declaration of the CTCExtPage
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#ifndef __TCEXTPAGE_H_
#define __TCEXTPAGE_H_

#include "resource.h"       // main symbols

#pragma warning( disable : 4268 )
EXTERN_C const CLSID CLSID_TCExtPage;
#pragma warning( default : 4268 )

/////////////////////////////////////////////////////////////////////////////
// CTCExtPage
class ATL_NO_VTABLE CTCExtPage :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTCExtPage, &CLSID_TCExtPage>,
	public IPropertyPageImpl<CTCExtPage>,
	public CDialogImpl<CTCExtPage>
{
public:
	CTCExtPage()
	{
		m_dwTitleID = IDS_TITLETCExtPage;
		m_dwHelpFileID = IDS_HELPFILETCExtPage;
		m_dwDocStringID = IDS_DOCSTRINGTCExtPage;
	}

	enum {IDD = IDD_TCEXTPAGE};

DECLARE_REGISTRY_RESOURCEID(IDR_TCEXTPAGE)

BEGIN_COM_MAP(CTCExtPage)
	COM_INTERFACE_ENTRY_IMPL(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CTCExtPage)
   MESSAGE_HANDLER( WM_INITDIALOG, OnInitDialog )
	CHAIN_MSG_MAP(IPropertyPageImpl<CTCExtPage>)
END_MSG_MAP()

// IPropertyPage
public:
	STDMETHOD( Apply )();

protected:
   LRESULT OnInitDialog( UINT nMessage, WPARAM wParam, LPARAM lParam,
	  BOOL& bHandled );
};

OBJECT_ENTRY_AUTO(CLSID_TCExtPage, CTCExtPage)

#endif //__TCEXTPAGE_H_