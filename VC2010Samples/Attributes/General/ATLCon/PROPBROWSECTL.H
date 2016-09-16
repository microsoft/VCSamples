// PropBrowseCtl.h : Property browser ActiveX Control
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __PROPBROWSECTL_H_
#define __PROPBROWSECTL_H_

#include "resource.h"       // main symbols
#include "ATLControls.h"    // Common control helpers

[
	object,
	uuid(5AC61281-483A-4E01-B53D-CB3A3B4B0F60),
	dual,
	helpstring("IATLConPropertyBrowser Interface"),
	pointer_default(unique)
]
__interface IATLConPropertyBrowser : IDispatch
{
	[propput, helpstring("Set the interface to browse")]
	HRESULT Dispatch([in]IDispatch* pDispatch);
	[propget, helpstring("Get the interface being browsed")]
	HRESULT Dispatch([out,retval]IDispatch** ppDispatch);
	[propget, id(1), helpstring("Enable/Disable the property description")] HRESULT ShowDescription([out, retval] BOOL *pVal);
	[propput, id(1), helpstring("Is property description enabled")] HRESULT ShowDescription([in] BOOL newVal);
};

using namespace ATLControls;

class CProperty
{
public:
	DISPID m_dispid;
	VARTYPE m_vtNative;
	CComVariant m_value;
	CComPtr<IDispatch> m_spDisp;
	CComPtr<ITypeInfo> m_spInfo;
	CComBSTR m_bstrDesc;
	CProperty(IDispatch* pDisp, DISPID di, VARIANT val, BSTR bstrDesc, ITypeInfo* p = NULL)
	{
		m_dispid = di;
		m_value = val;
		m_bstrDesc = bstrDesc;
		m_vtNative = m_value.vt;
		m_spDisp = pDisp;
		m_spInfo = p;
	}
	bool IsCombo()
	{
		return ((m_spInfo != NULL) || (m_vtNative == VT_BOOL));
	}
	HRESULT GetStringValue(BSTR* pbstr)
	{
		if (m_spInfo == NULL)
		{
			switch(m_vtNative)
			{
			case VT_BOOL:
				{
					CComBSTR bstr = (m_value.boolVal == VARIANT_TRUE) ? L"True" : L"False";
					*pbstr = bstr.Detach();
				}
				break;
			default:
				CComVariant v = m_value;
				v.ChangeType(VT_BSTR);
				*pbstr = v.bstrVal;
				v.bstrVal = NULL;
				break;
			}
		}
		else
		{
			
			TYPEATTR *pta=NULL;
			m_spInfo->GetTypeAttr(&pta);
			if(pta && pta->typekind == TKIND_ENUM)
			{
				VARDESC* pvd=NULL;
				for (int i=0;i<pta->cVars;i++)
				{
					m_spInfo->GetVarDesc(i, &pvd);
					if (pvd->lpvarValue->lVal == m_value.lVal)
					{
						DISPID idMember = pvd->memid;
						CComBSTR bstrName;
						m_spInfo->GetDocumentation(idMember, &bstrName, NULL, NULL, NULL);
						
						CString tempStr;
						tempStr.Format(_T("%d - %s"), pvd->lpvarValue->lVal, bstrName);
						*pbstr = tempStr.AllocSysString();
					}
					m_spInfo->ReleaseVarDesc(pvd);
				}
			}
			if(pta)
				m_spInfo->ReleaseTypeAttr(pta);
		}
		return S_OK;
	}
	HRESULT SetValue(LPCTSTR pstr)
	{
		_ASSERTE(m_spInfo == NULL);
		switch(m_vtNative)
		{
		case VT_BOOL:
			m_value = (_stricmp(pstr, _T("True"))==0) ? true : false;
			break;
		default:
			m_value = pstr;
			m_value.ChangeType(m_vtNative);
			break;
		}
		CComDispatchDriver dd(m_spDisp);
		HRESULT hr = dd.PutProperty(m_dispid, &m_value);
		if (hr!=S_OK)
		{
			return hr;
		}
		return S_OK;
	}
	HRESULT SetValue(int nIndex)
	{
		if (m_spInfo == NULL)
		{
			switch(m_vtNative)
			{
			case VT_BOOL:
				m_value = (nIndex == 0) ? true : false;
				break;
			default:
				break;
			}
		}
		else
		{
			VARDESC* pvd=NULL;
			m_spInfo->GetVarDesc(nIndex, &pvd);
			m_value = pvd->lpvarValue->lVal;
			m_spInfo->ReleaseVarDesc(pvd);
		}
		CComDispatchDriver dd(m_spDisp);
		HRESULT hr = dd.PutProperty(m_dispid, &m_value);
		if (hr!=S_OK)
		{
			return hr;
		}
		return S_OK;
	}
	HRESULT AddEnumValues(HWND hwnd)
	{
		
		CComboBox cb = hwnd;
		cb.ResetContent();
		if (m_vtNative == VT_BOOL)
		{
			cb.AddString(_T("True"));
			cb.AddString(_T("False"));
			cb.SetCurSel( (m_value.boolVal==VARIANT_TRUE) ? 0 : 1);
		}
		if (m_spInfo != NULL)
		{
			TYPEATTR *pta=NULL;
			m_spInfo->GetTypeAttr(&pta);
			if(pta && pta->typekind == TKIND_ENUM)
			{
				VARDESC* pvd=NULL;
				for (int i=0;i<pta->cVars;i++)
				{
					m_spInfo->GetVarDesc(i, &pvd);
					DISPID idMember = pvd->memid;
					CComBSTR bstrName;
					m_spInfo->GetDocumentation(idMember, &bstrName, NULL, NULL, NULL);

					CString tempStr;
					tempStr.Format(_T("%d - %s"), pvd->lpvarValue->lVal, bstrName);
					cb.AddString(tempStr);
					if (pvd->lpvarValue->lVal == m_value.lVal)
						cb.SetCurSel(i);
					m_spInfo->ReleaseVarDesc(pvd);
				}
			}
			if(pta)
				m_spInfo->ReleaseTypeAttr(pta);
		}
		return S_OK;
	}
};

/////////////////////////////////////////////////////////////////////////////
// CPropertyBrowseControl
[ coclass,
  uuid(553C1A15-0BBE-4694-B3CB-6672434C3D2B),
  helpstring("ATLConPropertyBrowser Class"),
  default("IATLConPropertyBrowser")
]
class ATL_NO_VTABLE CPropertyBrowseControl :
	public IDispatchImpl<IATLConPropertyBrowser, &__uuidof(IATLConPropertyBrowser)>,
	public CComControl<CPropertyBrowseControl, CWindowImpl<CPropertyBrowseControl, CWindow, CWinTraitsOR<0, WS_EX_CLIENTEDGE> > >,
	public IOleControlImpl<CPropertyBrowseControl>,
	public IOleObjectImpl<CPropertyBrowseControl>,
	public IOleInPlaceActiveObjectImpl<CPropertyBrowseControl>,
	public IViewObjectExImpl<CPropertyBrowseControl>,
	public IOleInPlaceObjectWindowlessImpl<CPropertyBrowseControl>
{
public:
	CPropertyBrowseControl()
	{
		// Initialize control hosting support
		AtlAxWinInit();
		m_bWindowOnly = true;
		m_bShowDesc = true;
	}

DECLARE_WND_CLASS_EX(NULL, CS_DBLCLKS, COLOR_WINDOW)

BEGIN_MSG_MAP(CPropertyBrowseControl)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_SETFOCUS, OnSetFocus)
	MESSAGE_HANDLER(WM_KILLFOCUS, OnKillFocus)
	MESSAGE_HANDLER(WM_MOUSEACTIVATE, OnMouseActivate)
	MESSAGE_HANDLER(WM_NOTIFY, OnNotify)
	MESSAGE_HANDLER(WM_SIZE, OnSize)
	DEFAULT_REFLECTION_HANDLER()
	ALT_MSG_MAP(1)      //ListView
		MESSAGE_HANDLER(WM_DESTROY, OnListViewDestroy)
		COMMAND_HANDLER(103, CBN_KILLFOCUS, OnComboKillFocus)
		COMMAND_HANDLER(103, CBN_SELCHANGE, OnComboOK)
	ALT_MSG_MAP(2)      //Edit control
		MESSAGE_HANDLER(WM_CHAR, OnChar)
		MESSAGE_HANDLER(WM_KILLFOCUS, OnEditKillFocus)
	ALT_MSG_MAP(3)      //Combobox
	ALT_MSG_MAP(4)      //Static control
END_MSG_MAP()

	LRESULT OnEditKillFocus(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		RECT rc = {0,0,0,0};
		m_edit.MoveWindow(&rc);
		bHandled = FALSE;
		return 1;
	}

	LRESULT OnComboKillFocus(int, int, HWND h, BOOL& bHandled)
	{
		RECT rc = {0,0,0,0};
		m_combobox.MoveWindow(&rc);
		bHandled = FALSE;
		return 1;
	}

	void OnComboDone()
	{
		RECT rc = {0,0,0,0};
		m_combobox.MoveWindow(&rc);
		CComBSTR bstrText;
		m_combobox.GetWindowText(bstrText.m_str);
		
		m_list.SetItemText(m_nItem, m_nSubItem, COLE2T(bstrText));
		m_list.SetFocus();
		CProperty* pProp = (CProperty*)m_list.GetItemData(m_nItem);
		pProp->SetValue(m_combobox.GetCurSel());
	}

	LRESULT OnComboOK(int, int, HWND h, BOOL& bHandled)
	{
		OnComboDone();
		return 1;
	}

	LRESULT OnSize(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		WORD cx = LOWORD(lParam);
		WORD cy = HIWORD(lParam);
		if (m_bShowDesc)
			cy -= m_nHeightDesc;
		m_list.MoveWindow(0, 0, cx, cy);
		m_wndDesc.MoveWindow(0, cy, cx, cy+m_nHeightDesc);
		return 999;
	}

	BOOL PreTranslateAccelerator(LPMSG pMsg, HRESULT& hRet)
	{
		if(pMsg->message == WM_KEYDOWN)
		{
			switch(pMsg->wParam)
			{
			case VK_LEFT:
			case VK_RIGHT:
			case VK_UP:
			case VK_DOWN:
			case VK_HOME:
			case VK_END:
			case VK_NEXT:
			case VK_PRIOR:
				hRet = S_FALSE;
				return TRUE;
			}
		}
		return FALSE;
	}

	LRESULT OnSetFocus(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		BOOL b;
		CComControlBase::OnSetFocus(0, 0, 0, b);
		DoVerbUIActivate(&m_rcPos,  NULL);
		if(!IsChild(::GetFocus()))
			m_list.SetFocus();
		return DefWindowProc();
	}

	LRESULT OnListViewDestroy(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		ClearListView();
		bHandled = FALSE;
		return 1;
	}

	void ClearListView()
	{
		int n = m_list.GetItemCount();
		for (int i=0;i<n;i++)
			delete (CProperty*)m_list.GetItemData(i);
		m_list.DeleteAllItems();
	}

	static VARTYPE GetUserDefinedType(ITypeInfo *pTI, HREFTYPE hrt)
	{
		CComPtr<ITypeInfo> spTypeInfo;
		VARTYPE vt = VT_USERDEFINED;
		HRESULT hr = E_FAIL;
		hr = pTI->GetRefTypeInfo(hrt, &spTypeInfo);
		if(FAILED(hr))
			return vt;
		TYPEATTR *pta=NULL;

		spTypeInfo->GetTypeAttr(&pta);
		if(pta && pta->typekind == TKIND_ALIAS)
		{
			if (pta->tdescAlias.vt == VT_USERDEFINED)
				GetUserDefinedType(spTypeInfo,pta->tdescAlias.hreftype);
			else
				vt = pta->tdescAlias.vt;
		}

		if(pta)
			spTypeInfo->ReleaseTypeAttr(pta);
		return vt;

	}
	static HRESULT GetEnumTypeInfo(ITypeInfo *pTI, HREFTYPE hrt, ITypeInfo** ppEnumInfo)
	{
		CComPtr<ITypeInfo> spTypeInfo;
		HRESULT hr = E_FAIL;
		hr = pTI->GetRefTypeInfo(hrt, &spTypeInfo);
		if(FAILED(hr))
			return hr;
		TYPEATTR *pta=NULL;

		spTypeInfo->GetTypeAttr(&pta);
		if(pta != NULL)
		{
			if (pta->typekind == TKIND_ALIAS)
			{
				if (pta->tdescAlias.vt == VT_USERDEFINED)
					return GetEnumTypeInfo(spTypeInfo,pta->tdescAlias.hreftype, ppEnumInfo);
			}
			else if (pta->typekind == TKIND_ENUM)
			{
				hr = spTypeInfo.CopyTo(ppEnumInfo);
				if(FAILED(hr))
					return hr;
			}
			spTypeInfo->ReleaseTypeAttr(pta);
		}
		return (*ppEnumInfo != NULL) ? S_OK : E_FAIL;
	}

	int m_nItem;
	int m_nSubItem;
	int m_nHeightDesc;
	bool m_bShowDesc;

	LRESULT OnNotify(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnChar(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	HRESULT AddDispatch(IDispatch* pDisp);

// IViewObjectEx
	DECLARE_VIEW_STATUS(VIEWSTATUS_SOLIDBKGND | VIEWSTATUS_OPAQUE)

// IPropertyBrowseControl
public:
	STDMETHOD(put_Dispatch)(IDispatch* pDisp);
	STDMETHOD(get_Dispatch)(IDispatch** ppDisp);
	STDMETHOD(get_ShowDescription)(/*[out, retval]*/ BOOL *pVal);
	STDMETHOD(put_ShowDescription)(/*[in]*/ BOOL newVal);

	CComPtr<IDispatch> m_spDispatch;

	CContainedWindowT<CListViewCtrl, CWinTraitsOR<LVS_REPORT | LVS_EX_GRIDLINES | LVS_NOSORTHEADER | LVS_SINGLESEL, 0/*WS_EX_CLIENTEDGE*/> > m_list;
	CContainedWindowT<CEdit, CWinTraitsOR<WS_BORDER | ES_AUTOHSCROLL> > m_edit;
	CContainedWindowT<CComboBox, CWinTraitsOR<CBS_DROPDOWNLIST> > m_combobox;
	CContainedWindowT<CStatic, CWinTraits<SS_LEFT, 0> > m_wndDesc;
	LRESULT OnCreate(UINT nMessage, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
};

#endif //__PROPBROWSECTL_H_
