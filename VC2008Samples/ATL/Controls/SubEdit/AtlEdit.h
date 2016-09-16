// AtlEdit.h : Declaration of the CAtlEdit
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

#pragma warning ( disable : 4244 )

/////////////////////////////////////////////////////////////////////////////
// CAtlEdit
class CAtlEdit :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAtlEdit, &CLSID_CAtlEdit>,
	public IDispatchImpl<IAtlEdit, &IID_IAtlEdit, &LIBID_SUBEDITLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public CComControl<CAtlEdit>,
	public IProvideClassInfoImpl<&CLSID_CAtlEdit, &LIBID_SUBEDITLib>,
	public IPersistStreamInitImpl<CAtlEdit>,
	public IPersistStorageImpl<CAtlEdit>,
	public IQuickActivateImpl<CAtlEdit>,
	public IOleControlImpl<CAtlEdit>,
	public IOleObjectImpl<CAtlEdit>,
	public IOleInPlaceActiveObjectImpl<CAtlEdit>,
	public IViewObjectExImpl<CAtlEdit>,
	public IOleInPlaceObjectWindowlessImpl<CAtlEdit>,
	public IDataObjectImpl<CAtlEdit>,
	public ISpecifyPropertyPagesImpl<CAtlEdit>
{
public:
	CContainedWindow m_EditCtrl;

	CAtlEdit() : m_EditCtrl(_T("EDIT"), this, 1)
	{
		m_bWindowOnly = TRUE;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_AtlEdit)


BEGIN_COM_MAP(CAtlEdit)
	COM_INTERFACE_ENTRY(IAtlEdit)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY_IMPL(IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject2, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IViewObject, IViewObjectEx)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleInPlaceObject, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL_IID(IID_IOleWindow, IOleInPlaceObjectWindowless)
	COM_INTERFACE_ENTRY_IMPL(IOleInPlaceActiveObject)
	COM_INTERFACE_ENTRY_IMPL(IOleControl)
	COM_INTERFACE_ENTRY_IMPL(IOleObject)
	COM_INTERFACE_ENTRY_IMPL(IQuickActivate)
	COM_INTERFACE_ENTRY_IMPL(IPersistStorage)
	COM_INTERFACE_ENTRY_IMPL(IPersistStreamInit)
	COM_INTERFACE_ENTRY2(IPersist,IPersistStreamInit)
	COM_INTERFACE_ENTRY_IMPL(ISpecifyPropertyPages)
	COM_INTERFACE_ENTRY_IMPL(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
END_COM_MAP()

BEGIN_PROPERTY_MAP(CAtlEdit)
	PROP_PAGE(CLSID_StockColorPage)
END_PROPERTY_MAP()


BEGIN_MSG_MAP(CAtlEdit)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
	MESSAGE_HANDLER(WM_CREATE, OnCreate)
	MESSAGE_HANDLER(WM_CTLCOLOREDIT, OnCtlColorEdit)
ALT_MSG_MAP(1)
	MESSAGE_HANDLER(WM_CHAR, OnChar)
END_MSG_MAP()

// IAtlEdit
public:
	HRESULT OnDraw(ATL_DRAWINFO&)
	{
		return S_OK;
	}
	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		RECT rc;
		GetWindowRect(&rc);
		rc.right -= rc.left;
		rc.bottom -= rc.top;
		rc.top = rc.left = 0;
		m_EditCtrl.Create(m_hWnd, rc, _T("hello"), WS_CHILD | WS_VISIBLE | ES_MULTILINE | ES_AUTOVSCROLL);
		return 0;
	}
	STDMETHOD(SetObjectRects)(LPCRECT prcPos,LPCRECT prcClip)
	{
		IOleInPlaceObjectWindowlessImpl<CAtlEdit>::SetObjectRects(prcPos, prcClip);
		int cx, cy;
		cx = prcPos->right - prcPos->left;
		cy = prcPos->bottom - prcPos->top;
		::SetWindowPos(m_EditCtrl.m_hWnd, NULL, 0,
					 0, cx, cy, SWP_NOZORDER | SWP_NOACTIVATE);
		return S_OK;
	}
	LRESULT OnChar(UINT /*uMsg*/, WPARAM wParam, LPARAM lParam, BOOL& /*bHandled*/)
	{
		if (isalnum(wParam) || wParam == VK_SPACE || wParam == VK_RETURN || wParam == VK_TAB)
			m_EditCtrl.DefWindowProc(WM_CHAR, wParam, lParam);
		return 0;
	}
	LRESULT OnCtlColorEdit(UINT /*uMsg*/, WPARAM wParam, LPARAM /*lParam*/, BOOL& /*bHandled*/)
	{
		::SetTextColor((HDC)wParam, RGB(255,255,0));
		::SetBkColor((HDC)wParam,RGB(0,0,0));
		return (LRESULT)::GetStockObject(BLACK_BRUSH);
	}
};

OBJECT_ENTRY_AUTO(__uuidof(CAtlEdit), CAtlEdit)