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
#include <atlctl.h>

[emitidl];


/////////////////////////////////////////////////////////////////////////////
// SubEdit
[
		object,
		uuid(380E9187-5C4C-4C9D-9EC8-C70181F13DFF),
		dual,
		helpstring("IAtlEdit Interface"),
		pointer_default(unique)
]
__interface IAtlEdit : IDispatch
{
};

/////////////////////////////////////////////////////////////////////////////
// Csimplecontrol
[
	coclass,
	default("IAtlEdit"),
	threading(apartment),
	progid("SubEdit.AtlEdit.1"),
	vi_progid("SubEdit.AtlEdit"),
	version(1.0),
	uuid(AF1F3D15-D053-4072-8943-4E3997D48C5D),
	helpstring("AtlEdit Class"),
	com_interface_entry="COM_INTERFACE_ENTRY_IMPL(ISpecifyPropertyPages)",
	registration_script(script="AtlEdit.rgs"),
	implements_category("CATID_Insertable")
]
class ATL_NO_VTABLE CAtlEdit : 
	public IAtlEdit,
	public CComControl<CAtlEdit>,
	public IProvideClassInfoImpl<&__uuidof(CAtlEdit), &CAtlModule::m_libid>,
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
		OLECHAR* sz = L"one";
		m_bWindowOnly = TRUE;
	}

BEGIN_PROPERTY_MAP(CAtlEdit)
	PROP_PAGE(CLSID_StockColorPage)
END_PROPERTY_MAP()

#if 0
BEGIN_COM_MAP(CAtlEdit)
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
	COM_INTERFACE_ENTRY_IMPL(IDataObject)
	COM_INTERFACE_ENTRY(IProvideClassInfo)
	COM_INTERFACE_ENTRY(IProvideClassInfo2)
END_COM_MAP()
#endif

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
	LRESULT OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
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
	LRESULT OnChar(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if (isalnum(wParam) || wParam == VK_SPACE || wParam == VK_RETURN || wParam == VK_TAB)
			m_EditCtrl.DefWindowProc(WM_CHAR, wParam, lParam);
		return 0;
	}
	LRESULT OnCtlColorEdit(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		::SetTextColor((HDC)wParam, RGB(255,255,0));
		::SetBkColor((HDC)wParam,RGB(0,0,0));
		return (LRESULT)::GetStockObject(BLACK_BRUSH);
	}
};
