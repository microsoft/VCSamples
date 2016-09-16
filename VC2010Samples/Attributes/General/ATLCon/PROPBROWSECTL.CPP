// PropBrowseCtl.cpp : Implementation of a property browser control
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "PropBrowseCtl.h"

/////////////////////////////////////////////////////////////////////////////
// CPropertyBrowseControl
#include <exdisp.h>

LRESULT CPropertyBrowseControl::OnCreate(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	DefWindowProc();
	RECT rc;
	GetClientRect(&rc);
	m_list.Create(this, 1, m_hWnd, &rc, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 101);
	m_list.SetExtendedListViewStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT);
	HFONT hFont = m_list.GetFont();
	m_list.AddColumn(_T("Name"), 0);
	m_list.AddColumn(_T("Value"), 1);

	TEXTMETRIC tm;
	HDC hdc = ::GetDC(NULL);
	HFONT hOldFont = (HFONT)::SelectObject(hdc, hFont);
	::GetTextMetrics(hdc, &tm);
	::SelectObject(hdc, hOldFont);
	::ReleaseDC(NULL, hdc);
	m_nHeightDesc = (tm.tmHeight+tm.tmExternalLeading)*3; //room for three lines of text

	rc.bottom -= m_nHeightDesc;
	m_list.MoveWindow(&rc);

	RECT rc2 = {0,0,0,0};
	m_edit.Create(this, 2, m_list, &rc2);
	m_edit.SetFont(hFont);
	// combobox has ID of 103
	m_combobox.Create(this, 3, m_list, &rc2, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 103);
	m_combobox.SetFont(hFont);

	rc.top = rc.bottom;
	rc.bottom += m_nHeightDesc;
	m_wndDesc.Create(this, 4, m_hWnd, &rc2, NULL, WS_CHILD | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS, 0, 104);
	m_wndDesc.SetFont(hFont);
	return 0;
}

LRESULT CPropertyBrowseControl::OnNotify(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	
	NMLISTVIEW* pnmlv = (NMLISTVIEW*) lParam;
	if (pnmlv->hdr.code == LVN_ITEMCHANGED)
	{
		if (pnmlv->uNewState & LVIS_FOCUSED)
		{
			LPARAM lItem = m_list.GetItemData(pnmlv->iItem);
			CProperty* pProp = (CProperty*)lItem;
			LPCTSTR lpszDesc = (pProp == NULL) ? _T("") : COLE2T(pProp->m_bstrDesc);
			m_wndDesc.SetWindowText(lpszDesc);
		}
	}

	if (pnmlv->hdr.code == NM_RETURN)
	{
		pnmlv->hdr.code = NM_DBLCLK;
		pnmlv->iItem = m_list.GetSelectedIndex();
		pnmlv->iSubItem = 1;
	}
	if ((pnmlv->hdr.code == NM_DBLCLK) || (pnmlv->hdr.code == NM_CLICK))
	{
		if (pnmlv->iSubItem == 1)
		{
			RECT rc;
			m_nItem = pnmlv->iItem;
			m_nSubItem = pnmlv->iSubItem;
			CComBSTR bstrText;
			m_list.GetItemText(m_nItem, m_nSubItem, bstrText.m_str);
			m_list.GetSubItemRect(m_nItem, m_nSubItem, 0, &rc);
			LPCTSTR lpszText = COLE2T(bstrText);
			LPARAM lItem = m_list.GetItemData(pnmlv->iItem);
			CProperty* pProp = (CProperty*)lItem;
			if (pProp != NULL)
			{
				if (!pProp->IsCombo()) // use edit control if not an enum
				{
					m_edit.SetWindowText(lpszText ? lpszText : _T(""));
					rc.top -= 2;
					rc.bottom -= 2;
					m_edit.MoveWindow(&rc);
					m_edit.SetFocus();
				}
				else
				{
					pProp->AddEnumValues(m_combobox);
	//              m_combobox.SetWindowText(lpszText ? lpszText : _T(""));
					int nHeight = m_combobox.GetItemHeight(-1);
					int nOffset = (nHeight-(rc.bottom-rc.top))/2 + 2;
					rc.bottom -= nOffset;
					rc.top -= nOffset;
					rc.bottom += 100;
					m_combobox.MoveWindow(&rc);
					m_combobox.SetFocus();
				}
			}
		}
		else
		{
			RECT rc = {0,0,0,0};
			m_combobox.MoveWindow(&rc);
			m_edit.MoveWindow(&rc);
		}
	}
	return 0;
}

LRESULT CPropertyBrowseControl::OnChar(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	TCHAR ch = (TCHAR) wParam;
	if (ch == VK_RETURN)
	{
		
		RECT rc = {0,0,0,0};
		m_edit.MoveWindow(&rc);
		CComBSTR bstrText;
		m_edit.GetWindowText(bstrText.m_str);
		m_list.SetItemText(m_nItem, m_nSubItem, COLE2T(bstrText));
		m_list.SetFocus();
		LPARAM lItem = m_list.GetItemData(m_nItem);
		CProperty* pProp = (CProperty*)lItem;
		pProp->SetValue(COLE2T(bstrText));
		return 0;
	}
	return m_edit.DefWindowProc();
}

HRESULT CPropertyBrowseControl::AddDispatch(IDispatch* pDisp)
{
	
	CComPtr<ITypeInfo> spTypeInfo;
	if (pDisp == NULL)
		return S_OK;
	pDisp->GetTypeInfo(0, LOCALE_SYSTEM_DEFAULT, &spTypeInfo);

	if (spTypeInfo == NULL)
		return E_FAIL;

	TYPEATTR* pta;
	spTypeInfo->GetTypeAttr(&pta);

	if (pta->typekind == TKIND_INTERFACE)
	{
		// Get the dual
		CComPtr<ITypeInfo> spInfoTemp;
		HREFTYPE hRef;
		HRESULT hr = (int)spTypeInfo->GetRefTypeOfImplType(-1, &hRef);
		if (FAILED(hr))
			return E_FAIL;

		hr = spTypeInfo->GetRefTypeInfo(hRef, &spInfoTemp);
		if (FAILED(hr))
			return E_FAIL;

		spTypeInfo->ReleaseTypeAttr(pta);
		spTypeInfo = spInfoTemp;
		spTypeInfo->GetTypeAttr(&pta);
	}


	int item = m_list.GetItemCount();
	for (int i=0; i<pta->cFuncs; i++)
	{
		FUNCDESC* pfd;
		spTypeInfo->GetFuncDesc(i, &pfd);
		if (pfd->invkind & DISPATCH_PROPERTYGET
			&& (pfd->wFuncFlags & (FUNCFLAG_FRESTRICTED | FUNCFLAG_FHIDDEN)) == 0)
		{
			switch (pfd->elemdescFunc.tdesc.vt)
			{
			case VT_USERDEFINED:
			case VT_EMPTY:
			case VT_NULL:
			case VT_I2:
			case VT_I4:
			case VT_R4:
			case VT_R8:
			case VT_CY:
			case VT_DATE:
			case VT_BSTR:
			case VT_ERROR:
			case VT_BOOL:
			case VT_VARIANT:
			case VT_DECIMAL:
			case VT_I1:
			case VT_UI1:
			case VT_UI2:
			case VT_UI4:
			case VT_INT:
			case VT_UINT:
				{
					CComPtr<ITypeInfo> spUserTypeInfo;
					if (pfd->elemdescFunc.tdesc.vt == VT_USERDEFINED)
					{
						HREFTYPE hrt = pfd->elemdescFunc.tdesc.hreftype;
						VARTYPE vt = VT_USERDEFINED;
						HRESULT hr = E_FAIL;
						hr = GetEnumTypeInfo(spTypeInfo, hrt, &spUserTypeInfo);
						if(FAILED(hr))
							vt = GetUserDefinedType(spTypeInfo, hrt);
					}
					CComVariant varVal;
					CComBSTR bstrVal;
					CComBSTR bstrName;
					CComBSTR bstrDocString;
					spTypeInfo->GetDocumentation(pfd->memid, &bstrName, &bstrDocString, NULL, NULL);
					CComDispatchDriver dd(pDisp);
#pragma warning (suppress: 6031)
					dd.GetProperty(pfd->memid, &varVal);
					CProperty* pProp = new CProperty(pDisp, pfd->memid, varVal, bstrDocString, spUserTypeInfo);
					pProp->GetStringValue(&bstrVal);
					m_list.AddItem(item, 0, COLE2T(bstrName));
					m_list.AddItem(item, 1, COLE2T(bstrVal));
					LPARAM lItem = (LPARAM)pProp;
					m_list.SetItemData(item, (DWORD)lItem);
					item++;
				}
			}
		}
		spTypeInfo->ReleaseFuncDesc(pfd);
	}
	spTypeInfo->ReleaseTypeAttr(pta);
	return S_OK;
}

STDMETHODIMP CPropertyBrowseControl::put_Dispatch(IDispatch* pDisp)
{
	
	ClearListView();

	m_spDispatch = pDisp;
	if (pDisp != NULL)
	{
		m_list.SetRedraw(FALSE);
		AddDispatch(pDisp);
		m_list.SetRedraw(TRUE);
		m_list.SetColumnWidth(0, LVSCW_AUTOSIZE_USEHEADER);
		m_list.SetColumnWidth(1, LVSCW_AUTOSIZE_USEHEADER);
	}
	return S_OK;
}

STDMETHODIMP CPropertyBrowseControl::get_Dispatch(IDispatch** ppDisp)
{
	return m_spDispatch.CopyTo(ppDisp);
}

STDMETHODIMP CPropertyBrowseControl::get_ShowDescription(BOOL *pVal)
{
	*pVal = m_bShowDesc ? VARIANT_TRUE : VARIANT_FALSE;
	return S_OK;
}

STDMETHODIMP CPropertyBrowseControl::put_ShowDescription(BOOL newVal)
{
	m_bShowDesc = (newVal == VARIANT_TRUE);
	RECT rc;
	GetWindowRect(&rc);
	if (m_bShowDesc)
		rc.bottom -= m_nHeightDesc;
	m_list.MoveWindow(&rc);
	return S_OK;
}
