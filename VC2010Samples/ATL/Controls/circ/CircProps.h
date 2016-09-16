// CircProps.h : Declaration of the CCircProps
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
#include <atlctl.h>
#include "circprres.h"
#include "circ.h"

#define IID_DEFINED
#include "circ_i.c"

/////////////////////////////////////////////////////////////////////////////
// circ
class CCircProps :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCircProps,&CLSID_CCircProps>,
	public IPropertyPageImpl<CCircProps>,
	public CDialogImpl<CCircProps>
{
public:
	CCircProps()
	{
		m_dwTitleID = IDS_TITLE;
		m_dwHelpFileID = IDS_HELPFILE;
		m_dwDocStringID = IDS_DOCSTRING;
	}

	enum {IDD = IDD_CIRCPROPS};

DECLARE_REGISTRY_RESOURCEID(IDR_CircProps)

BEGIN_COM_MAP(CCircProps)
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()	

BEGIN_MSG_MAP(CCircProps)
	CHAIN_MSG_MAP(IPropertyPageImpl<CCircProps>)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	COMMAND_HANDLER(IDC_EDIT1, EN_CHANGE, OnCaptionChange)
END_MSG_MAP()

	STDMETHOD(Apply)(void)
	{
		ATLTRACE(_T("CCircProps::Apply\n"));

		CComBSTR bstrCaption;	
		GetDlgItemText(IDC_EDIT1, bstrCaption.m_str);
		for (UINT i = 0; i < m_nObjects; i++)
		{
			CComPtr<ICircCtl> pCirc;
			m_ppUnk[i]->QueryInterface(IID_ICircCtl, (void**)&pCirc);
			pCirc->put_Caption(bstrCaption);
		}
		SetDirty(FALSE);
		return S_OK;
	}

	LRESULT OnInitDialog(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		if (m_nObjects)
		{
			CComPtr<ICircCtl> pCirc;
			m_ppUnk[0]->QueryInterface(IID_ICircCtl, (void**)&pCirc);
			if (pCirc != NULL)
			{
				CComBSTR bstrCaption;
				pCirc->get_Caption(&bstrCaption);
				SetDlgItemText(IDC_EDIT1, COLE2T(bstrCaption));
				SetDirty(FALSE);
			}
		}
		return TRUE;
	}

	LRESULT OnCaptionChange(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		SetDirty(TRUE);
		return 0;
	}
};
