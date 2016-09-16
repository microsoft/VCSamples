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
#include <atlwin.h>
#include <atlctl.h>
#include "circprres.h"
#include "_circ.h"

#define IID_DEFINED
#include "_circ_i.c"


template <class T>
class CCircPropertyPageDlg :
	public IPropertyPageImpl<T>,
	public CDialogImpl<T>
	{
public:
	typedef CCircPropertyPageDlg className;

	CCircPropertyPageDlg()
	{
		_tcscpy_s(m_szTitle, _MAX_PATH, _T("OldMotherHubbard"));
	}

	enum {IDD = IDD_CIRCPROPS};

	BEGIN_MSG_MAP(CCircPropertyPageDlg< T >)
		COMMAND_ID_HANDLER(IDC_SETTEXT, OnSetText)
		MESSAGE_HANDLER(WM_CTLCOLOREDIT, OnCtlColorEdit)
		CHAIN_MSG_MAP(IPropertyPageImpl<T>)
	END_MSG_MAP()

	TCHAR m_szTitle[_MAX_PATH];

	LRESULT OnSetText(WORD wNotify, WORD wID, HWND hWnd, BOOL& bHandled)
	{
		SendDlgItemMessage(IDC_EDIT1, EM_GETLINE, 0, (LPARAM)m_szTitle);
		SetDirty(TRUE);
		return 0;
	}
	LRESULT OnCtlColorEdit(UINT, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		::SetTextColor((HDC)wParam, RGB(255,255,0));
		::SetBkMode((HDC)wParam, TRANSPARENT);
		return (LRESULT)::GetStockObject(BLACK_BRUSH);
	}
	LRESULT OnPagePropMsg(UINT, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		ATLTRACE(_T("Recieved  Page Prop Message\n"));
		return 0;
	}
};

/////////////////////////////////////////////////////////////////////////////
// circ
[ coclass,
  uuid("070AAE89-7C69-405f-8434-E10CCEDB30FA"),
  default("ICircCtl")
]
class CCircProps :
	public CCircPropertyPageDlg<CCircProps>
{

public:
	CCircProps()
	{
		m_dwTitleID = IDS_TITLE;
		m_dwHelpFileID = IDS_HELPFILE;
		m_dwDocStringID = IDS_DOCSTRING;
	}
	STDMETHOD(Apply)(void)
	{
		ICircCtl* pCirc;

		ATLTRACE(_T("CCircProps::Apply\n"));
		for (UINT i = 0; i < m_nObjects; i++)
		{
			m_ppUnk[i]->QueryInterface(IID_ICircCtl, (void**)&pCirc);
			pCirc->put_Caption(CComBSTR(m_szTitle));
			pCirc->Release();
		}
		m_bDirty = FALSE;
		return S_OK;
	}
	STDMETHOD(GetPageInfo)(PROPPAGEINFO *pPageInfo)
	{
		ATLTRACE(_T("CCircProps::GetPageInfo\n"));
		LONG cDlgBaseUnits = GetDialogBaseUnits();

		m_size.cx = (LOWORD(cDlgBaseUnits) * 188) / 4;
		m_size.cy = (HIWORD(cDlgBaseUnits) * 97) / 8;

		return CCircPropertyPageDlg<CCircProps>::GetPageInfo(pPageInfo);
	}

	STDMETHOD(SetObjects)(ULONG nObjects, IUnknown **ppUnk)
	{
		HRESULT hr = IPropertyPageImpl<CCircProps>::SetObjects(nObjects, ppUnk);
		if (SUCCEEDED(hr))
		{
			CComPtr<ICircCtl> pCirc;
			m_ppUnk[0]->QueryInterface(IID_ICircCtl, (void**)&pCirc);
			if (pCirc != NULL)
			{
				BSTR bstrTitle;
				pCirc->get_Caption(&bstrTitle);
				_tcscpy_s(m_szTitle, _MAX_PATH, COLE2T(bstrTitle));
			}
		}
		return hr;
	}

DECLARE_GET_CONTROLLING_UNKNOWN()
};
