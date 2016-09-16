// PolyProp.h : Declaration of the CPolyProp

// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __POLYPROP_H_
#define __POLYPROP_H_

#include "Polygon.h"        // definition of IPolyCtl
#include "resource.h"       // main symbols

EXTERN_C const CLSID CLSID_PolyProp;

/////////////////////////////////////////////////////////////////////////////
// CPolyProp
class ATL_NO_VTABLE CPolyProp :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CPolyProp, &CLSID_PolyProp>,
	public IPropertyPageImpl<CPolyProp>,
	public CDialogImpl<CPolyProp>
{
public:
	CPolyProp()
	{
		m_dwTitleID = IDS_TITLEPolyProp;
		m_dwHelpFileID = IDS_HELPFILEPolyProp;
		m_dwDocStringID = IDS_DOCSTRINGPolyProp;
	}

	enum {IDD = IDD_POLYPROP};

DECLARE_REGISTRY_RESOURCEID(IDR_POLYPROP)

BEGIN_COM_MAP(CPolyProp)
	COM_INTERFACE_ENTRY(IPropertyPage)
END_COM_MAP()

BEGIN_MSG_MAP(CPolyProp)
	COMMAND_HANDLER(IDC_SIDES, EN_CHANGE, OnChangeSides)
	CHAIN_MSG_MAP(IPropertyPageImpl<CPolyProp>)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

STDMETHOD(Apply)(void)
{
	USES_CONVERSION;
	ATLTRACE(_T("CPolyProp::Apply\n"));

	for (UINT i = 0; i < m_nObjects; i++)
	{
		CComQIPtr<IPolyCtl, &IID_IPolyCtl> pPoly(m_ppUnk[i]);
		short nSides = (short)GetDlgItemInt(IDC_SIDES);
		if FAILED(pPoly->put_Sides(nSides))
		{
			CComPtr<IErrorInfo> pError;
			CComBSTR         strError;
			if(GetErrorInfo(0, &pError) != S_OK)
			{
				return E_FAIL;
			}

			pError->GetDescription(&strError);
			MessageBox(COLE2T(strError), _T("Error"), MB_ICONEXCLAMATION);
			return E_FAIL;
			}
	}
	m_bDirty = FALSE;
	return S_OK;
}
	LRESULT OnChangeSides(WORD /*wNotifyCode*/, WORD /*wID*/, HWND /*hWndCtl*/, BOOL& /*bHandled*/)
	{
		SetDirty(TRUE);
		return 0;
	}
};

#endif //__POLYPROP_H_
