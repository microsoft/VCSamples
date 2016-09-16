// PolyProp.h : Declaration of the CPolyProp
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#ifndef __POLYPROP_H_
#define __POLYPROP_H_

#include "resource.h"       // main symbols

EXTERN_C const CLSID CLSID_PolyProp;
#include "PolygonIface.h"
/////////////////////////////////////////////////////////////////////////////
// CPolyProp
[
	coclass,
	uuid("E4AB4412-3A8B-4302-B395-EF041BBCCEA1"),
	helpstring("PolyProp Class"),
	version("1.0"),
	progid("Polygon.PolyPropAttrib.1"),
	vi_progid("Polygon.PolyPropAttrib"),
	default("IPolyCtl"),
	threading(apartment),
	implements_category("CATID_Programmable")
]
class ATL_NO_VTABLE CPolyProp :
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
	ATLTRACE(_T("CPolyProp::Apply\n"));

	for (UINT i = 0; i < m_nObjects; i++)
	{
		CComQIPtr<IPolyCtl, &__uuidof(IPolyCtl)> pPoly(m_ppUnk[i]);
		short nSides = (short)GetDlgItemInt(IDC_SIDES);
		if FAILED(pPoly->put_Sides(nSides))
		{
			CComPtr<IErrorInfo> pError;
			CComBSTR         strError;
			if(GetErrorInfo(0, &pError) != S_OK) 
				return E_FAIL;
			
			pError->GetDescription(&strError);
			MessageBox(COLE2T(strError), _T("Error"), MB_ICONEXCLAMATION);
			return E_FAIL;
			}
	}
	m_bDirty = FALSE;
	return S_OK;
}
	LRESULT OnChangeSides(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled)
	{
		SetDirty(TRUE);
		return 0;
	}
};

#endif //__POLYPROP_H_
