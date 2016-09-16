// ATLControls.h : Helper classes for common controls
//
//  These classes are only intended as a sample and
//  are NOT supported by Microsoft
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __ATLCONTROLS_H__
#define __ATLCONTROLS_H__

#ifndef __cplusplus
	#error ATL requires C++ compilation (use a .cpp suffix)
#endif

#ifndef __ATLWIN_H__
	#error atlcontrols.h requires atlwin.h to be included first
#endif

#include <commctrl.h>

namespace ATLControls
{


/////////////////////////////////////////////////////////////////////////////
// Forward declarations

template <class Base> class CStaticT;
template <class Base> class CButtonT;
template <class Base> class CListBoxT;
template <class Base> class CComboBoxT;
template <class Base> class CEditT;
template <class Base> class CScrollBarT;
class CImageList;
template <class Base> class CListViewCtrlT;
template <class Base> class CTreeViewCtrlT;
class CTreeItem;
template <class Base> class CTreeViewCtrlExT;
template <class Base> class CHeaderCtrlT;
template <class Base> class CToolBarCtrlT;
template <class Base> class CStatusBarCtrlT;
template <class Base> class CTabCtrlT;
class CToolInfo;
template <class Base> class CToolTipCtrlT;
template <class Base> class CTrackBarCtrlT;
template <class Base> class CUpDownCtrlT;
template <class Base> class CProgressBarCtrlT;
template <class Base> class CHotKeyCtrlT;
template <class Base> class CAnimateCtrlT;
template <class Base> class CRichEditCtrlT;
template <class Base> class CDragListBoxT;
template <class T> class CDragListNotifyImpl;
template <class Base> class CReBarCtrlT;
template <class Base> class CComboBoxExT;
template <class Base> class CDateTimePickerCtrlT;
template <class Base> class CMonthCalendarCtrlT;
#if (_WIN32_IE >= 0x0400)
template <class Base> class CFlatScrollBarT;
template <class Base> class CIPAddressCtrlT;
template <class Base> class CPagerCtrlT;
#endif //(_WIN32_IE >= 0x0400)
template <class T> class CCustomDraw;

// --- Standard Windows controls ---

/////////////////////////////////////////////////////////////////////////////
// CStatic - client side for a Windows STATIC control

template <class Base>
class CStaticT : public Base
{
public:
// Constructors
	CStaticT(HWND hWnd = NULL) : Base(hWnd) { }

	CStaticT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return _T("STATIC");
	}

	HICON SetIcon(HICON hIcon)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HICON)::SendMessage(m_hWnd, STM_SETICON, (WPARAM)hIcon, 0L);
	}
	HICON GetIcon() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HICON)::SendMessage(m_hWnd, STM_GETICON, 0, 0L);
	}

	HENHMETAFILE SetEnhMetaFile(HENHMETAFILE hMetaFile)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HENHMETAFILE)::SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_ENHMETAFILE, (LPARAM)hMetaFile);
	}
	HENHMETAFILE GetEnhMetaFile() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HENHMETAFILE)::SendMessage(m_hWnd, STM_GETIMAGE, IMAGE_ENHMETAFILE, 0L);
	}
	HBITMAP SetBitmap(HBITMAP hBitmap)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HBITMAP)::SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
	}
	HBITMAP GetBitmap() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HBITMAP)::SendMessage(m_hWnd, STM_GETIMAGE, IMAGE_BITMAP, 0L);
	}
	HCURSOR SetCursor(HCURSOR hCursor)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HCURSOR)::SendMessage(m_hWnd, STM_SETIMAGE, IMAGE_CURSOR, (LPARAM)hCursor);
	}
	HCURSOR GetCursor()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HCURSOR)::SendMessage(m_hWnd, STM_GETIMAGE, IMAGE_CURSOR, 0L);
	}
};

typedef CStaticT<CWindow>   CStatic;

/////////////////////////////////////////////////////////////////////////////
// CButton - client side for a Windows BUTTON control

template <class Base>
class CButtonT : public Base
{
public:
// Constructors
	CButtonT(HWND hWnd = NULL) : Base(hWnd) { }

	CButtonT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return _T("BUTTON");
	}

	UINT GetState() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, BM_GETSTATE, 0, 0L);
	}
	void SetState(BOOL bHighlight)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, BM_SETSTATE, bHighlight, 0L);
	}
	int GetCheck() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, BM_GETCHECK, 0, 0L);
	}
	void SetCheck(int nCheck)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, BM_SETCHECK, nCheck, 0L);
	}
	UINT GetButtonStyle() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::GetWindowLong(m_hWnd, GWL_STYLE) & 0xff;
	}
	void SetButtonStyle(UINT nStyle, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, BM_SETSTYLE, nStyle, (LPARAM)bRedraw);
	}

	HICON SetIcon(HICON hIcon)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HICON)::SendMessage(m_hWnd, BM_SETIMAGE, IMAGE_ICON, (LPARAM)hIcon);
	}
	HICON GetIcon() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HICON)::SendMessage(m_hWnd, BM_GETIMAGE, IMAGE_ICON, 0L);
	}
	HBITMAP SetBitmap(HBITMAP hBitmap)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HBITMAP)::SendMessage(m_hWnd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)hBitmap);
	}
	HBITMAP GetBitmap() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HBITMAP)::SendMessage(m_hWnd, BM_GETIMAGE, IMAGE_BITMAP, 0L);
	}
	HCURSOR SetCursor(HCURSOR hCursor)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HCURSOR)::SendMessage(m_hWnd, BM_SETIMAGE, IMAGE_CURSOR, (LPARAM)hCursor);
	}
	HCURSOR GetCursor()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HCURSOR)::SendMessage(m_hWnd, BM_GETIMAGE, IMAGE_CURSOR, 0L);
	}
};

typedef CButtonT<CWindow>   CButton;

/////////////////////////////////////////////////////////////////////////////
// CListBox - client side for a Windows LISTBOX control

template <class Base>
class CListBoxT : public Base
{
public:
// Constructors
	CListBoxT(HWND hWnd = NULL) : Base(hWnd) { }

	CListBoxT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return _T("LISTBOX");
	}

	// for entire listbox
	int GetCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETCOUNT, 0, 0L);
	}
	int GetHorizontalExtent() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETHORIZONTALEXTENT, 0, 0L);
	}
	void SetHorizontalExtent(int cxExtent)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, LB_SETHORIZONTALEXTENT, cxExtent, 0L);
	}
	int GetTopIndex() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETTOPINDEX, 0, 0L);
	}
	int SetTopIndex(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_SETTOPINDEX, nIndex, 0L);
	}
	LCID GetLocale() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (LCID)::SendMessage(m_hWnd, LB_GETLOCALE, 0, 0L);
	}
	LCID SetLocale(LCID nNewLocale)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (LCID)::SendMessage(m_hWnd, LB_SETLOCALE, (WPARAM)nNewLocale, 0L);
	}
	int InitStorage(int nItems, UINT nBytes)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_INITSTORAGE, (WPARAM)nItems, nBytes);
	}
	UINT ItemFromPoint(POINT pt, BOOL& bOutside) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		DWORD dw = (DWORD)::SendMessage(m_hWnd, LB_ITEMFROMPOINT, 0, MAKELPARAM(pt.x, pt.y));
		bOutside = !!HIWORD(dw);
		return LOWORD(dw);
	}

	// for single-selection listboxes
	int GetCurSel() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(!(GetStyle() & LBS_MULTIPLESEL));
		return (int)::SendMessage(m_hWnd, LB_GETCURSEL, 0, 0L);
	}
	int SetCurSel(int nSelect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(!(GetStyle() & LBS_MULTIPLESEL));
		return (int)::SendMessage(m_hWnd, LB_SETCURSEL, nSelect, 0L);
	}

	// for multiple-selection listboxes
	int GetSel(int nIndex) const           // also works for single-selection
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETSEL, nIndex, 0L);
	}
	int SetSel(int nIndex, BOOL bSelect = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
		return (int)::SendMessage(m_hWnd, LB_SETSEL, bSelect, nIndex);
	}
	int GetSelCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
		return (int)::SendMessage(m_hWnd, LB_GETSELCOUNT, 0, 0L);
	}
	int GetSelItems(int nMaxItems, LPINT rgIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
		return (int)::SendMessage(m_hWnd, LB_GETSELITEMS, nMaxItems, (LPARAM)rgIndex);
	}
	void SetAnchorIndex(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
		::SendMessage(m_hWnd, LB_SETANCHORINDEX, nIndex, 0L);
	}
	int GetAnchorIndex() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LBS_MULTIPLESEL);
		return (int)::SendMessage(m_hWnd, LB_GETANCHORINDEX, 0, 0L);
	}

	// for listbox items
	DWORD GetItemData(int nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, LB_GETITEMDATA, nIndex, 0L);
	}
	int SetItemData(int nIndex, DWORD dwItemData)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_SETITEMDATA, nIndex, (LPARAM)dwItemData);
	}
	void* GetItemDataPtr(int nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (LPVOID)::SendMessage(m_hWnd, LB_GETITEMDATA, nIndex, 0L);
	}
	int SetItemDataPtr(int nIndex, void* pData)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItemData(nIndex, (DWORD)(LPVOID)pData);
	}
	int GetItemRect(int nIndex, LPRECT lpRect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETITEMRECT, nIndex, (LPARAM)lpRect);
	}
	int GetText(int nIndex, LPTSTR lpszBuffer) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETTEXT, nIndex, (LPARAM)lpszBuffer);
	}
#ifndef _ATL_NO_COM
	BOOL GetTextBSTR(int nIndex, BSTR& bstrText) const
	{
		
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(bstrText == NULL);

		int nLen = GetTextLen(nIndex);
		if(nLen == LB_ERR)
			return FALSE;

		LPTSTR lpszText = (LPTSTR)_alloca((nLen + 1) * sizeof(TCHAR));

		if(GetText(nIndex, lpszText) == LB_ERR)
			return FALSE;

		bstrText = ::SysAllocString(CT2OLE(lpszText));
		return (bstrText != NULL) ? TRUE : FALSE;
	}
#endif //!_ATL_NO_COM
	int GetTextLen(int nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETTEXTLEN, nIndex, 0L);
	}

	// Settable only attributes
	void SetColumnWidth(int cxWidth)
	{
		ATLENSURE(::IsWindow(m_hWnd)); ::SendMessage(m_hWnd, LB_SETCOLUMNWIDTH, cxWidth, 0L);
	}
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LB_SETTABSTOPS, nTabStops, (LPARAM)rgTabStops);
	}
	BOOL SetTabStops()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LB_SETTABSTOPS, 0, 0L);
	}
	BOOL SetTabStops(const int& cxEachStop)    // takes an 'int'
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LB_SETTABSTOPS, 1, (LPARAM)(LPINT)&cxEachStop);
	}

	int SetItemHeight(int nIndex, UINT cyItemHeight)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_SETITEMHEIGHT, nIndex, MAKELONG(cyItemHeight, 0));
	}
	int GetItemHeight(int nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETITEMHEIGHT, nIndex, 0L);
	}
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_FINDSTRINGEXACT, nIndexStart, (LPARAM)lpszFind);
	}
	int GetCaretIndex() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_GETCARETINDEX, 0, 0);
	}
	int SetCaretIndex(int nIndex, BOOL bScroll = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_SETCARETINDEX, nIndex, MAKELONG(bScroll, 0));
	}

// Operations
	// manipulating listbox items
	int AddString(LPCTSTR lpszItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_ADDSTRING, 0, (LPARAM)lpszItem);
	}
	int DeleteString(UINT nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_DELETESTRING, nIndex, 0L);
	}
	int InsertString(int nIndex, LPCTSTR lpszItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_INSERTSTRING, nIndex, (LPARAM)lpszItem);
	}
	void ResetContent()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, LB_RESETCONTENT, 0, 0L);
	}
	int Dir(UINT attr, LPCTSTR lpszWildCard)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_DIR, attr, (LPARAM)lpszWildCard);
	}

	// selection helpers
	int FindString(int nStartAfter, LPCTSTR lpszItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_FINDSTRING, nStartAfter, (LPARAM)lpszItem);
	}
	int SelectString(int nStartAfter, LPCTSTR lpszItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LB_SELECTSTRING, nStartAfter, (LPARAM)lpszItem);
	}
	int SelItemRange(BOOL bSelect, int nFirstItem, int nLastItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return bSelect ? (int)::SendMessage(m_hWnd, LB_SELITEMRANGEEX, nFirstItem, nLastItem) : (int)::SendMessage(m_hWnd, LB_SELITEMRANGEEX, nLastItem, nFirstItem);
	}
};

typedef CListBoxT<CWindow>  CListBox;

/////////////////////////////////////////////////////////////////////////////
// CComboBox - client side for a Windows COMBOBOX control

template <class Base>
class CComboBoxT : public Base
{
public:
// Constructors
	CComboBoxT(HWND hWnd = NULL) : Base(hWnd) { }

	CComboBoxT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return _T("COMBOBOX");
	}

	// for entire combo box
	int GetCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_GETCOUNT, 0, 0L);
	}
	int GetCurSel() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_GETCURSEL, 0, 0L);
	}
	int SetCurSel(int nSelect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_SETCURSEL, nSelect, 0L);
	}
	LCID GetLocale() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (LCID)::SendMessage(m_hWnd, CB_GETLOCALE, 0, 0L);
	}
	LCID SetLocale(LCID nNewLocale)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (LCID)::SendMessage(m_hWnd, CB_SETLOCALE, (WPARAM)nNewLocale, 0L);
	}
	int GetTopIndex() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_GETTOPINDEX, 0, 0L);
	}
	int SetTopIndex(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_SETTOPINDEX, nIndex, 0L);
	}
	int InitStorage(int nItems, UINT nBytes)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_INITSTORAGE, (WPARAM)nItems, nBytes);
	}
	void SetHorizontalExtent(UINT nExtent)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, CB_SETHORIZONTALEXTENT, nExtent, 0L);
	}
	UINT GetHorizontalExtent() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, CB_GETHORIZONTALEXTENT, 0, 0L);
	}
	int SetDroppedWidth(UINT nWidth)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_SETDROPPEDWIDTH, nWidth, 0L);
	}
	int GetDroppedWidth() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_GETDROPPEDWIDTH, 0, 0L);
	}

	// for edit control
	DWORD GetEditSel() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, CB_GETEDITSEL, 0, 0L);
	}
	BOOL LimitText(int nMaxChars)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, CB_LIMITTEXT, nMaxChars, 0L);
	}
	BOOL SetEditSel(int nStartChar, int nEndChar)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, CB_SETEDITSEL, 0, MAKELONG(nStartChar, nEndChar));
	}

	// for combobox item
	DWORD GetItemData(int nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, CB_GETITEMDATA, nIndex, 0L);
	}
	int SetItemData(int nIndex, DWORD dwItemData)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_SETITEMDATA, nIndex, (LPARAM)dwItemData);
	}
	void* GetItemDataPtr(int nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (LPVOID)GetItemData(nIndex);
	}
	int SetItemDataPtr(int nIndex, void* pData)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItemData(nIndex, (DWORD)(LPVOID)pData);
	}
	int GetLBText(int nIndex, LPTSTR lpszText) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_GETLBTEXT, nIndex, (LPARAM)lpszText);
	}
#ifndef _ATL_NO_COM
	BOOL GetLBTextBSTR(int nIndex, BSTR& bstrText) const
	{
		
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(bstrText == NULL);

		int nLen = GetLBTextLen(nIndex);
		if(nLen == CB_ERR)
			return FALSE;

		LPTSTR lpszText = (LPTSTR)_alloca((nLen + 1) * sizeof(TCHAR));

		if(GetLBText(nIndex, lpszText) == CB_ERR)
			return FALSE;

		bstrText = ::SysAllocString(CT2OLE(lpszText));
		return (bstrText != NULL) ? TRUE : FALSE;
	}
#endif //!_ATL_NO_COM
	int GetLBTextLen(int nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_GETLBTEXTLEN, nIndex, 0L);
	}

	int SetItemHeight(int nIndex, UINT cyItemHeight)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_SETITEMHEIGHT, nIndex, MAKELONG(cyItemHeight, 0));
	}
	int GetItemHeight(int nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_GETITEMHEIGHT, nIndex, 0L);
	}
	int FindStringExact(int nIndexStart, LPCTSTR lpszFind) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_FINDSTRINGEXACT, nIndexStart, (LPARAM)lpszFind);
	}
	int SetExtendedUI(BOOL bExtended = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_SETEXTENDEDUI, bExtended, 0L);
	}
	BOOL GetExtendedUI() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, CB_GETEXTENDEDUI, 0, 0L);
	}
	void GetDroppedControlRect(LPRECT lprect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, CB_GETDROPPEDCONTROLRECT, 0, (DWORD)lprect);
	}
	BOOL GetDroppedState() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, CB_GETDROPPEDSTATE, 0, 0L);
	}

// Operations
	// for drop-down combo boxes
	void ShowDropDown(BOOL bShowIt = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, CB_SHOWDROPDOWN, bShowIt, 0L);
	}

	// manipulating listbox items
	int AddString(LPCTSTR lpszString)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_ADDSTRING, 0, (LPARAM)lpszString);
	}
	int DeleteString(UINT nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_DELETESTRING, nIndex, 0L);
	}
	int InsertString(int nIndex, LPCTSTR lpszString)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_INSERTSTRING, nIndex, (LPARAM)lpszString);
	}
	void ResetContent()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, CB_RESETCONTENT, 0, 0L);
	}
	int Dir(UINT attr, LPCTSTR lpszWildCard)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_DIR, attr, (LPARAM)lpszWildCard);
	}

	// selection helpers
	int FindString(int nStartAfter, LPCTSTR lpszString) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_FINDSTRING, nStartAfter, (LPARAM)lpszString);
	}
	int SelectString(int nStartAfter, LPCTSTR lpszString)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CB_SELECTSTRING, nStartAfter, (LPARAM)lpszString);
	}

	// Clipboard operations
	void Clear()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_CLEAR, 0, 0L);
	}
	void Copy()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_COPY, 0, 0L);
	}
	void Cut()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_CUT, 0, 0L);
	}
	void Paste()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_PASTE, 0, 0L);
	}
};

typedef CComboBoxT<CWindow> CComboBox;

/////////////////////////////////////////////////////////////////////////////
// CEdit - client side for a Windows EDIT control

template <class Base>
class CEditT : public Base
{
public:
// Constructors
	CEditT(HWND hWnd = NULL) : Base(hWnd) { }

	CEditT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return _T("EDIT");
	}

	BOOL CanUndo() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_CANUNDO, 0, 0L);
	}
	int GetLineCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_GETLINECOUNT, 0, 0L);
	}
	BOOL GetModify() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_GETMODIFY, 0, 0L);
	}
	void SetModify(BOOL bModified = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETMODIFY, bModified, 0L);
	}
	void GetRect(LPRECT lpRect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_GETRECT, 0, (LPARAM)lpRect);
	}
	DWORD GetSel() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, EM_GETSEL, 0, 0L);
	}
	void GetSel(int& nStartChar, int& nEndChar) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_GETSEL, (WPARAM)&nStartChar, (LPARAM)&nEndChar);
	}
	HLOCAL GetHandle() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HLOCAL)::SendMessage(m_hWnd, EM_GETHANDLE, 0, 0L);
	}
	void SetHandle(HLOCAL hBuffer)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETHANDLE, (WPARAM)hBuffer, 0L);
	}
	void SetMargins(UINT nLeft, UINT nRight)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETMARGINS, EC_LEFTMARGIN|EC_RIGHTMARGIN, MAKELONG(nLeft, nRight));
	}
	DWORD GetMargins() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD)::SendMessage(m_hWnd, EM_GETMARGINS, 0, 0L);
	}
	void SetLimitText(UINT nMax)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETLIMITTEXT, nMax, 0L);
	}
	UINT GetLimitText() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, EM_GETLIMITTEXT, 0, 0L);
	}
	POINT PosFromChar(UINT nChar) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		POINT point;
		::SendMessage(m_hWnd, EM_POSFROMCHAR, (WPARAM)&point, (LPARAM)nChar);
		return point;
	}
	int CharFromPos(POINT pt) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_CHARFROMPOS, 0, MAKELPARAM(pt.x, pt.y));
	}

	// NOTE: first word in lpszBuffer must contain the size of the buffer!
	int GetLine(int nIndex, LPTSTR lpszBuffer) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
	}
	int GetLine(int nIndex, LPTSTR lpszBuffer, int nMaxLength) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		*(LPWORD)lpszBuffer = (WORD)nMaxLength;
		return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
	}

// Operations
	void EmptyUndoBuffer()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_EMPTYUNDOBUFFER, 0, 0L);
	}
	BOOL FmtLines(BOOL bAddEOL)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_FMTLINES, bAddEOL, 0L);
	}
	void LimitText(int nChars = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_LIMITTEXT, nChars, 0L);
	}
	int LineFromChar(int nIndex = -1) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_LINEFROMCHAR, nIndex, 0L);
	}
	int LineIndex(int nLine = -1) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_LINEINDEX, nLine, 0L);
	}
	int LineLength(int nLine = -1) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_LINELENGTH, nLine, 0L);
	}
	void LineScroll(int nLines, int nChars = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_LINESCROLL, nChars, nLines);
	}
	void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_REPLACESEL, (WPARAM) bCanUndo, (LPARAM)lpszNewText);
	}
	void SetPasswordChar(TCHAR ch)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETPASSWORDCHAR, ch, 0L);
	}
	void SetRect(LPCRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETRECT, 0, (LPARAM)lpRect);
	}
	void SetRectNP(LPCRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETRECTNP, 0, (LPARAM)lpRect);
	}
	void SetSel(DWORD dwSelection, BOOL bNoScroll = FALSE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETSEL, LOWORD(dwSelection), HIWORD(dwSelection));
		if(!bNoScroll)
			::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0L);
	}
	void SetSel(int nStartChar, int nEndChar, BOOL bNoScroll = FALSE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETSEL, nStartChar, nEndChar);
		if(!bNoScroll)
			::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0L);
	}
	BOOL SetTabStops(int nTabStops, LPINT rgTabStops)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_SETTABSTOPS, nTabStops, (LPARAM)rgTabStops);
	}
	BOOL SetTabStops()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, EM_SETTABSTOPS, 0, 0L);
	}
	BOOL SetTabStops(const int& cxEachStop)    // takes an 'int'
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_SETTABSTOPS, 1, (LPARAM)(LPINT)&cxEachStop);
	}

	// Additional operations
	void ScrollCaret()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0L);
	}
	void InsertText(int nInsertAfterChar, LPCTSTR lpstrText, BOOL bNoScroll = FALSE, BOOL bCanUndo = FALSE)
	{
		SetSel(nInsertAfterChar, nInsertAfterChar, bNoScroll);
		ReplaceSel(lpstrText, bCanUndo);
	}
	void AppendText(LPCTSTR lpstrText, BOOL bNoScroll = FALSE, BOOL bCanUndo = FALSE)
	{
		InsertText(GetWindowTextLength(), lpstrText, bNoScroll, bCanUndo);
	}

	// Clipboard operations
	BOOL Undo()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_UNDO, 0, 0L);
	}
	void Clear()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_CLEAR, 0, 0L);
	}
	void Copy()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_COPY, 0, 0L);
	}
	void Cut()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_CUT, 0, 0L);
	}
	void Paste()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_PASTE, 0, 0L);
	}

	BOOL SetReadOnly(BOOL bReadOnly = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_SETREADONLY, bReadOnly, 0L);
	}
	int GetFirstVisibleLine() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_GETFIRSTVISIBLELINE, 0, 0L);
	}
	TCHAR GetPasswordChar() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (TCHAR)::SendMessage(m_hWnd, EM_GETPASSWORDCHAR, 0, 0L);
	}
};

typedef CEditT<CWindow>     CEdit;

/////////////////////////////////////////////////////////////////////////////
// CScrollBar - client side for a Windows SCROLLBAR control

template <class Base>
class CScrollBarT : public Base
{
public:
// Constructors
	CScrollBarT(HWND hWnd = NULL) : Base(hWnd) { }

	CScrollBarT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return _T("SCROLLBAR");
	}

	int GetScrollPos() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::GetScrollPos(m_hWnd, SB_CTL);
	}
	int SetScrollPos(int nPos, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SetScrollPos(m_hWnd, SB_CTL, nPos, bRedraw);
	}
	void GetScrollRange(LPINT lpMinPos, LPINT lpMaxPos) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::GetScrollRange(m_hWnd, SB_CTL, lpMinPos, lpMaxPos);
	}
	void SetScrollRange(int nMinPos, int nMaxPos, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SetScrollRange(m_hWnd, SB_CTL, nMinPos, nMaxPos, bRedraw);
	}
	void ShowScrollBar(BOOL bShow = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::ShowScrollBar(m_hWnd, SB_CTL, bShow);
	}

	BOOL EnableScrollBar(UINT nArrowFlags = ESB_ENABLE_BOTH)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::EnableScrollBar(m_hWnd, SB_CTL, nArrowFlags);
	}

	BOOL SetScrollInfo(LPSCROLLINFO lpScrollInfo, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SetScrollInfo(m_hWnd, SB_CTL, lpScrollInfo, bRedraw);
	}
	BOOL GetScrollInfo(LPSCROLLINFO lpScrollInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::GetScrollInfo(m_hWnd, SB_CTL, lpScrollInfo);
	}
	int GetScrollLimit()
	{
		int nMin, nMax;
		::GetScrollRange(m_hWnd, SB_CTL, &nMin, &nMax);
		SCROLLINFO info;
		info.cbSize = sizeof(SCROLLINFO);
		info.fMask = SIF_PAGE;
		if(::GetScrollInfo(m_hWnd, SB_CTL, &info))
			nMax -= ((info.nPage-1) > 0) ? (info.nPage-1) : 0;

		return nMax;
	}
};

typedef CScrollBarT<CWindow>    CScrollBar;


// --- Windows Common Controls ---

/////////////////////////////////////////////////////////////////////////////
// CImageList

class CImageList
{
public:
	HIMAGELIST m_hImageList;

// Constructors
	CImageList(HIMAGELIST hImageList = NULL) : m_hImageList(hImageList) { }

	CImageList& operator=(HIMAGELIST hImageList)
	{
		m_hImageList = hImageList;
		return *this;
	}

	operator HIMAGELIST() const { return m_hImageList; }

	BOOL Create(int cx, int cy, UINT nFlags, int nInitial, int nGrow)
	{
		ATLENSURE(m_hImageList == NULL);
		m_hImageList = ImageList_Create(cx, cy, nFlags, nInitial, nGrow);
		return (m_hImageList != NULL) ? TRUE : FALSE;
	}
	BOOL Create(UINT nBitmapID, int cx, int nGrow, COLORREF crMask)
	{
		ATLENSURE(m_hImageList == NULL);
		ATLENSURE(HIWORD(nBitmapID) == 0);
		m_hImageList = ImageList_LoadBitmap(_pModule->GetModuleInstance(), MAKEINTRESOURCE(nBitmapID), cx, nGrow, crMask);
		return (m_hImageList != NULL) ? TRUE : FALSE;
	}
	BOOL Create(LPCTSTR lpszBitmapID, int cx, int nGrow, COLORREF crMask)
	{
		ATLENSURE(m_hImageList == NULL);
		m_hImageList = ImageList_LoadBitmap(_pModule->GetModuleInstance(), lpszBitmapID, cx, nGrow, crMask);
		return (m_hImageList != NULL) ? TRUE : FALSE;
	}
	BOOL Merge(HIMAGELIST hImageList1, int nImage1, HIMAGELIST hImageList2, int nImage2, int dx, int dy)
	{
		ATLENSURE(m_hImageList == NULL);
		m_hImageList = ImageList_Merge(hImageList1, nImage1, hImageList2, nImage2, dx, dy);
		return (m_hImageList != NULL) ? TRUE : FALSE;
	}

// Attributes

	void Attach(HIMAGELIST hImageList)
	{
		ATLENSURE(m_hImageList == NULL);
		ATLENSURE(hImageList != NULL);
		m_hImageList = hImageList;
	}
	HIMAGELIST Detach()
	{
		HIMAGELIST hImageList = m_hImageList;
		m_hImageList = NULL;
		return hImageList;
	}

	int GetImageCount() const
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_GetImageCount(m_hImageList);
	}
	COLORREF SetBkColor(COLORREF cr)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_SetBkColor(m_hImageList, cr);
	}
	COLORREF GetBkColor() const
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_GetBkColor(m_hImageList);
	}
	BOOL GetImageInfo(int nImage, IMAGEINFO* pImageInfo) const
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_GetImageInfo(m_hImageList, nImage, pImageInfo);
	}

// Operations
	BOOL Destroy()
	{
		if (m_hImageList == NULL)
			return FALSE;
		BOOL bRet = ImageList_Destroy(Detach());
		if(bRet)
			m_hImageList = NULL;
		return bRet;
	}

	int Add(HBITMAP hBitmap, HBITMAP hBitmapMask)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_Add(m_hImageList, hBitmap, hBitmapMask);
	}
	int Add(HBITMAP hBitmap, COLORREF crMask)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_AddMasked(m_hImageList, hBitmap, crMask);
	}
	BOOL Remove(int nImage)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_Remove(m_hImageList, nImage);
	}
	BOOL Replace(int nImage, HBITMAP hBitmap, HBITMAP hBitmapMask)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_Replace(m_hImageList, nImage, hBitmap, hBitmapMask);
	}
	int AddIcon(HICON hIcon)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_AddIcon(m_hImageList, hIcon);
	}
	int ReplaceIcon(int nImage, HICON hIcon)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_ReplaceIcon(m_hImageList, nImage, hIcon);
	}
	HICON ExtractIcon(int nImage)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_ExtractIcon(NULL, m_hImageList, nImage);
	}
	BOOL Draw(HDC hDC, int nImage, POINT pt, UINT nStyle)
	{
		ATLENSURE(m_hImageList != NULL);
		ATLENSURE(hDC != NULL);
		return ImageList_Draw(m_hImageList, nImage, hDC, pt.x, pt.y, nStyle);
	}
	BOOL DrawEx(int nImage, HDC hDC, int x, int y, int dx, int dy, COLORREF rgbBk, COLORREF rgbFg, UINT fStyle)
	{
		ATLENSURE(m_hImageList != NULL);
		ATLENSURE(hDC != NULL);
		return ImageList_DrawEx(m_hImageList, nImage, hDC, x, y, dx, dy, rgbBk, rgbFg, fStyle);
	}
	BOOL SetOverlayImage(int nImage, int nOverlay)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_SetOverlayImage(m_hImageList, nImage, nOverlay);
	}

// Drag APIs
	BOOL BeginDrag(int nImage, POINT ptHotSpot)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_BeginDrag(m_hImageList, nImage, ptHotSpot.x, ptHotSpot.y);
	}
	static void PASCAL EndDrag()
	{
		ImageList_EndDrag();
	}
	static BOOL PASCAL DragMove(POINT pt)
	{
		return ImageList_DragMove(pt.x, pt.y);
	}
	BOOL SetDragCursorImage(int nDrag, POINT ptHotSpot)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_SetDragCursorImage(m_hImageList, nDrag, ptHotSpot.x, ptHotSpot.y);
	}
	static BOOL PASCAL DragShowNolock(BOOL bShow)
	{
		return ImageList_DragShowNolock(bShow);
	}
	static HIMAGELIST PASCAL GetDragImage(LPPOINT lpPoint, LPPOINT lpPointHotSpot)
	{
		return ImageList_GetDragImage(lpPoint, lpPointHotSpot);
	}
	static BOOL PASCAL DragEnter(HWND hWnd, POINT point)
	{
		return ImageList_DragEnter(hWnd, point.x, point.y);
	}
	static BOOL PASCAL DragLeave(HWND hWnd)
	{
		return ImageList_DragLeave(hWnd);
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	HIMAGELIST Duplicate(HIMAGELIST hImageList)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_Duplicate(m_hImageList);
	}
	BOOL SetImageCount(UINT uNewCount)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_SetImageCount(m_hImageList, uNewCount);
	}
	BOOL Copy(int nSrc, int nDst, UINT uFlags = ILCF_MOVE)
	{
		ATLENSURE(m_hImageList != NULL);
		return ImageList_Copy(m_hImageList, nDst, m_hImageList, nSrc, uFlags);
	}
	static BOOL DrawIndirect(IMAGELISTDRAWPARAMS* pimldp)
	{
		return ImageList_DrawIndirect(pimldp);
	}
#endif //(_WIN32_IE >= 0x0400)
};


/////////////////////////////////////////////////////////////////////////////
// CListViewCtrl

template <class Base>
class CListViewCtrlT : public Base
{
public:
// Constructors
	CListViewCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CListViewCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return WC_LISTVIEW;
	}

	COLORREF GetBkColor() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, LVM_GETBKCOLOR, 0, 0L);
	}
	BOOL SetBkColor(COLORREF cr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETBKCOLOR, 0, cr);
	}
	HIMAGELIST GetImageList(int nImageListType) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, LVM_GETIMAGELIST, nImageListType, 0L);
	}
	HIMAGELIST SetImageList(HIMAGELIST hImageList, int nImageList)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, LVM_SETIMAGELIST, nImageList, (LPARAM)hImageList);
	}
	int GetItemCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_GETITEMCOUNT, 0, 0L);
	}
	BOOL GetItem(LV_ITEM* pItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETITEM, 0, (LPARAM)pItem);
	}
	BOOL SetItem(const LV_ITEM* pItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETITEM, 0, (LPARAM)pItem);
	}
	BOOL SetItemState(int nItem, UINT nState, UINT nStateMask)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItem(nItem, 0, LVIF_STATE, NULL, 0, nState, nStateMask, 0);
	}
	BOOL SetItemText(int nItem, int nSubItem, LPCTSTR lpszText)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItem(nItem, nSubItem, LVIF_TEXT, lpszText, 0, 0, 0, 0);
	}
	BOOL SetItemData(int nItem, DWORD dwData)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItem(nItem, 0, LVIF_PARAM, NULL, 0, 0, 0, (LPARAM)dwData);
	}
	int InsertItem(const LV_ITEM* pItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_INSERTITEM, 0, (LPARAM)pItem);
	}
	int InsertItem(int nItem, LPCTSTR lpszItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return InsertItem(LVIF_TEXT, nItem, lpszItem, 0, 0, 0, 0);
	}
	int InsertItem(int nItem, LPCTSTR lpszItem, int nImage)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return InsertItem(LVIF_TEXT|LVIF_IMAGE, nItem, lpszItem, 0, 0, nImage, 0);
	}
	BOOL DeleteItem(int nItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_DELETEITEM, nItem, 0L);
	}
	BOOL DeleteAllItems()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_DELETEALLITEMS, 0, 0L);
	}
	UINT GetCallbackMask() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, LVM_GETCALLBACKMASK, 0, 0L);
	}
	BOOL SetCallbackMask(UINT nMask)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETCALLBACKMASK, nMask, 0L);
	}
	int GetNextItem(int nItem, int nFlags) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_GETNEXTITEM, nItem, MAKELPARAM(nFlags, 0));
	}
	int FindItem(LV_FINDINFO* pFindInfo, int nStart) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_FINDITEM, nStart, (LPARAM)pFindInfo);
	}
	int HitTest(LV_HITTESTINFO* pHitTestInfo) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_HITTEST, 0, (LPARAM)pHitTestInfo);
	}
	BOOL SetItemPosition(int nItem, POINT pt)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETITEMPOSITION32, nItem, (LPARAM)&pt);
	}
	BOOL GetItemPosition(int nItem, LPPOINT lpPoint) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETITEMPOSITION, nItem, (LPARAM)lpPoint);
	}
	int GetStringWidth(LPCTSTR lpsz) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_GETSTRINGWIDTH, 0, (LPARAM)lpsz);
	}
	BOOL EnsureVisible(int nItem, BOOL bPartialOK)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_ENSUREVISIBLE, nItem, MAKELPARAM(bPartialOK, 0));
	}
	BOOL Scroll(SIZE size)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SCROLL, size.cx, size.cy);
	}
	BOOL RedrawItems(int nFirst, int nLast)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_REDRAWITEMS, nFirst, nLast);
	}
	BOOL Arrange(UINT nCode)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_ARRANGE, nCode, 0L);
	}
	HWND EditLabel(int nItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, LVM_EDITLABEL, nItem, 0L);
	}
	HWND GetEditControl() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, LVM_GETEDITCONTROL, 0, 0L);
	}
	BOOL GetColumn(int nCol, LV_COLUMN* pColumn) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETCOLUMN, nCol, (LPARAM)pColumn);
	}
	BOOL SetColumn(int nCol, const LV_COLUMN* pColumn)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETCOLUMN, nCol, (LPARAM)pColumn);
	}
	int InsertColumn(int nCol, const LV_COLUMN* pColumn)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_INSERTCOLUMN, nCol, (LPARAM)pColumn);
	}
	BOOL DeleteColumn(int nCol)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_DELETECOLUMN, nCol, 0L);
	}
	int GetColumnWidth(int nCol) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_GETCOLUMNWIDTH, nCol, 0L);
	}
	BOOL SetColumnWidth(int nCol, int cx)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETCOLUMNWIDTH, nCol, MAKELPARAM(cx, 0));
	}
	BOOL GetViewRect(LPRECT lpRect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETVIEWRECT, 0, (LPARAM)lpRect);
	}
	COLORREF GetTextColor() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, LVM_GETTEXTCOLOR, 0, 0L);
	}
	BOOL SetTextColor(COLORREF cr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETTEXTCOLOR, 0, cr);
	}
	COLORREF GetTextBkColor() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, LVM_GETTEXTBKCOLOR, 0, 0L);
	}
	BOOL SetTextBkColor(COLORREF cr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETTEXTBKCOLOR, 0, cr);
	}
	int GetTopIndex() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_GETTOPINDEX, 0, 0L);
	}
	int GetCountPerPage() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_GETCOUNTPERPAGE, 0, 0L);
	}
	BOOL GetOrigin(LPPOINT lpPoint) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETORIGIN, 0, (LPARAM)lpPoint);
	}
	BOOL Update(int nItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_UPDATE, nItem, 0L);
	}
	BOOL SetItemState(int nItem, LV_ITEM* pItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETITEMSTATE, nItem, (LPARAM)pItem);
	}
	UINT GetItemState(int nItem, UINT nMask) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, LVM_GETITEMSTATE, nItem, nMask);
	}
	void SetItemCount(int nItems)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, LVM_SETITEMCOUNT, nItems, 0L);
	}
	BOOL SortItems(PFNLVCOMPARE pfnCompare, DWORD dwData)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SORTITEMS, dwData, (LPARAM)pfnCompare);
	}
	UINT GetSelectedCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, LVM_GETSELECTEDCOUNT, 0, 0L);
	}

	BOOL GetItemRect(int nItem, LPRECT lpRect, UINT nCode) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		lpRect->left = nCode;
		return (BOOL)::SendMessage(m_hWnd, LVM_GETITEMRECT, (WPARAM)nItem, (LPARAM)lpRect);
	}

	int InsertColumn(int nCol, LPCTSTR lpszColumnHeading, int nFormat, int nWidth, int nSubItem)
	{
		LV_COLUMN column;
		column.mask = LVCF_TEXT|LVCF_FMT;
		column.pszText = (LPTSTR)lpszColumnHeading;
		column.fmt = nFormat;
		if (nWidth != -1)
		{
			column.mask |= LVCF_WIDTH;
			column.cx = nWidth;
		}
		if (nSubItem != -1)
		{
			column.mask |= LVCF_SUBITEM;
			column.iSubItem = nSubItem;
		}
		return InsertColumn(nCol, &column);
	}

	int InsertItem(UINT nMask, int nItem, LPCTSTR lpszItem, UINT nState, UINT nStateMask, int nImage, LPARAM lParam)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		LV_ITEM item;
		item.mask = nMask;
		item.iItem = nItem;
		item.iSubItem = 0;
		item.pszText = (LPTSTR)lpszItem;
		item.state = nState;
		item.stateMask = nStateMask;
		item.iImage = nImage;
		item.lParam = lParam;
		return InsertItem(&item);
	}

	int HitTest(POINT pt, UINT* pFlags) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		LV_HITTESTINFO hti;
		hti.pt = pt;
		int nRes = (int)::SendMessage(m_hWnd, LVM_HITTEST, 0, (LPARAM)&hti);
		if (pFlags != NULL)
			*pFlags = hti.flags;
		return nRes;
	}

	BOOL SetItem(int nItem, int nSubItem, UINT nMask, LPCTSTR lpszItem,
		int nImage, UINT nState, UINT nStateMask, LPARAM lParam)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		LV_ITEM lvi;
		lvi.mask = nMask;
		lvi.iItem = nItem;
		lvi.iSubItem = nSubItem;
		lvi.stateMask = nStateMask;
		lvi.state = nState;
		lvi.pszText = (LPTSTR) lpszItem;
		lvi.iImage = nImage;
		lvi.lParam = lParam;
		return (BOOL)::SendMessage(m_hWnd, LVM_SETITEM, 0, (LPARAM)&lvi);
	}

#ifndef _ATL_NO_COM
	BOOL GetItemText(int nItem, int nSubItem, BSTR& bstrText) const
	{
		
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(bstrText == NULL);
		LV_ITEM lvi;
		memset(&lvi, 0, sizeof(LV_ITEM));
		lvi.iSubItem = nSubItem;

		LPTSTR lpstrText = NULL;
		int nLen = 128;
		int nRes;
		do
		{
			nLen *= 2;
			lvi.cchTextMax = nLen;
			if(lpstrText != NULL)
			{
				delete [] lpstrText;
				lpstrText = NULL;
			}
			ATLTRY(lpstrText = new TCHAR[nLen]);
			if(lpstrText == NULL)
				break;
			lpstrText[0] = NULL;
			lvi.pszText = lpstrText;
			nRes  = (int)::SendMessage(m_hWnd, LVM_GETITEMTEXT, (WPARAM)nItem,
				(LPARAM)&lvi);
		} while (nRes == nLen-1);

		bstrText = ::SysAllocString(CT2OLE(lpstrText));
		delete [] lpstrText;

		return (bstrText != NULL) ? TRUE : FALSE;
	}
#endif //!_ATL_NO_COM

	int GetItemText(int nItem, int nSubItem, LPTSTR lpszText, int nLen) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		LV_ITEM lvi;
		memset(&lvi, 0, sizeof(LV_ITEM));
		lvi.iSubItem = nSubItem;
		lvi.cchTextMax = nLen;
		lvi.pszText = lpszText;
		return (int)::SendMessage(m_hWnd, LVM_GETITEMTEXT, (WPARAM)nItem, (LPARAM)&lvi);
	}

	DWORD GetItemData(int nItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		LV_ITEM lvi;
		memset(&lvi, 0, sizeof(LV_ITEM));
		lvi.iItem = nItem;
		lvi.mask = LVIF_PARAM;
		::SendMessage(m_hWnd, LVM_GETITEM, 0, (LPARAM)&lvi);
		return (DWORD)lvi.lParam;
	}

	void RemoveImageList(int nImageList)
	{
		HIMAGELIST h = (HIMAGELIST)::SendMessage(m_hWnd, LVM_GETIMAGELIST, (WPARAM)nImageList, 0L);
		if (h != NULL)
			::SendMessage(m_hWnd, LVM_SETIMAGELIST, (WPARAM)nImageList, 0L);
	}

	HIMAGELIST CreateDragImage(int nItem, LPPOINT lpPoint)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, LVM_CREATEDRAGIMAGE, nItem, (LPARAM)lpPoint);
	}

	BOOL AddColumn(LPCTSTR strItem,int nItem,int nSubItem = -1,
			int nMask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM,
			int nFmt = LVCFMT_LEFT)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		LV_COLUMN lvc;
		lvc.mask = nMask;
		lvc.fmt = nFmt;
		lvc.pszText = (LPTSTR)strItem;
		lvc.cx = GetStringWidth(lvc.pszText) + 15;
		if(nMask & LVCF_SUBITEM)
		{
			if(nSubItem != -1)
				lvc.iSubItem = nSubItem;
			else
				lvc.iSubItem = nItem;
		}
		return InsertColumn(nItem, &lvc);
	}

	BOOL AddItem(int nItem,int nSubItem,LPCTSTR strItem,int nImageIndex = -1)
	{
		LV_ITEM lvItem;
		lvItem.mask = LVIF_TEXT;
		lvItem.iItem = nItem;
		lvItem.iSubItem = nSubItem;
		lvItem.pszText = (LPTSTR) strItem;
		if(nImageIndex != -1){
			lvItem.mask |= LVIF_IMAGE;
			lvItem.iImage = nImageIndex;
		}
		if(nSubItem == 0)
			return InsertItem(&lvItem);
		return SetItem(&lvItem);
	}

	// single-selection only
	int GetSelectedIndex() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LVS_SINGLESEL);

		return (int)::SendMessage(m_hWnd, LVM_GETNEXTITEM, -1, MAKELPARAM(LVNI_ALL | LVNI_SELECTED, 0));
	}

	BOOL GetSelectedItem(LV_ITEM* pItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LVS_SINGLESEL);
		ATLENSURE(pItem != NULL);

		pItem->iItem = (int)::SendMessage(m_hWnd, LVM_GETNEXTITEM, -1, MAKELPARAM(LVNI_ALL | LVNI_SELECTED, 0));
		if(pItem->iItem == -1)
			return FALSE;

		return (BOOL)::SendMessage(m_hWnd, LVM_GETITEM, 0, (LPARAM)pItem);
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	BOOL GetBkImage(LPLVBKIMAGE plvbki)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETBKIMAGE, 0, (LPARAM)plvbki);
	}
	BOOL SetBkImage(LPLVBKIMAGE plvbki)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETBKIMAGE, 0, (LPARAM)plvbki);
	}
	DWORD GetExtendedListViewStyle()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0L);
	}
	// dwExMask = 0 means all styles
	DWORD SetExtendedListViewStyle(DWORD dwExStyle, DWORD dwExMask = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD)::SendMessage(m_hWnd, LVM_SETEXTENDEDLISTVIEWSTYLE, dwExMask, dwExStyle);
	}
	HCURSOR GetHotCursor()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HCURSOR)::SendMessage(m_hWnd, LVM_GETHOTCURSOR, 0, 0L);
	}
	HCURSOR SetHotCursor(HCURSOR hHotCursor)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HCURSOR)::SendMessage(m_hWnd, LVM_SETHOTCURSOR, 0, (LPARAM)hHotCursor);
	}
	int GetHotItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, LVM_GETHOTITEM, 0, 0L);
	}
	int SetHotItem(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, LVM_SETHOTITEM, nIndex, 0L);
	}
	int GetSelectionMark()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, LVM_GETSELECTIONMARK, 0, 0L);
	}
	int SetSelectionMark(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, LVM_SETSELECTIONMARK, 0, nIndex);
	}
	BOOL GetWorkAreas(int nWorkAreas, LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETWORKAREAS, nWorkAreas, (LPARAM)lpRect);
	}
	BOOL SetWorkAreas(int nWorkAreas, LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETWORKAREAS, nWorkAreas, (LPARAM)lpRect);
	}
	BOOL GetColumnOrderArray(int nCount, int* lpnArray)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETCOLUMNORDERARRAY, nCount, (LPARAM)lpnArray);
	}
	BOOL SetColumnOrderArray(int nCount, int* lpnArray)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_SETCOLUMNORDERARRAY, nCount, (LPARAM)lpnArray);
	}
	DWORD GetHoverTime()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetExtendedListViewStyle() & (LVS_EX_TRACKSELECT | LVS_EX_ONECLICKACTIVATE | LVS_EX_TWOCLICKACTIVATE));
		return ::SendMessage(m_hWnd, LVM_GETHOVERTIME, 0, 0L);
	}
	DWORD SetHoverTime(DWORD dwHoverTime)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetExtendedListViewStyle() & (LVS_EX_TRACKSELECT | LVS_EX_ONECLICKACTIVATE | LVS_EX_TWOCLICKACTIVATE));
		return ::SendMessage(m_hWnd, LVM_SETHOVERTIME, 0, dwHoverTime);
	}
	HWND GetHeader()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, LVM_GETHEADER, 0, 0L);
	}
	BOOL GetSubItemRect(int nItem, int nSubItem, int nFlag, LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LVS_REPORT);
		ATLENSURE(lpRect != NULL);
		lpRect->top = nSubItem;
		lpRect->left = nFlag;
		return (BOOL)::SendMessage(m_hWnd, LVM_GETSUBITEMRECT, nItem, (LPARAM)lpRect);
	}
	BOOL GetCheckState(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetExtendedListViewStyle() & LVS_EX_CHECKBOXES);
		UINT uRet = GetItemState(nIndex, LVIS_STATEIMAGEMASK);
//REVIEW
		return (uRet >> 12) - 1;
	}
	BOOL SetCheckState(int nItem, BOOL bCheck)
	{
		int nCheck = bCheck ? 2 : 1;    // one based index
		return SetItemState(nItem, INDEXTOSTATEIMAGEMASK(nCheck), LVIS_STATEIMAGEMASK);
	}
	DWORD ApproximateViewRect(int cx = -1, int cy = -1, int nCount = -1)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, LVM_APPROXIMATEVIEWRECT, nCount, MAKELPARAM(cx, cy));
	}
	BOOL GetNumberOfWorkAreas(int* pnWorkAreas)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, LVM_GETNUMBEROFWORKAREAS, 0, (LPARAM)pnWorkAreas);
	}
	DWORD SetIconSpacing(int cx, int cy)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(GetStyle() & LVS_ICON);
		return ::SendMessage(m_hWnd, LVM_SETICONSPACING, 0, MAKELPARAM(cx, cy));
	}
	void SetItemCountEx(int nItems, DWORD dwFlags)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE((GetStyle() & LVS_OWNERDATA) && (GetStyle() & (LVS_REPORT | LVS_LIST)));
		::SendMessage(m_hWnd, LVM_SETITEMCOUNT, nItems, dwFlags);
	}
	int SubItemHitTest(LPLVHITTESTINFO lpInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, LVM_SUBITEMHITTEST, 0, (LPARAM)lpInfo);
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CListViewCtrlT<CWindow>     CListViewCtrl;

/////////////////////////////////////////////////////////////////////////////
// CTreeViewCtrl

template <class Base>
class CTreeViewCtrlT : public Base
{
public:
// Constructors
	CTreeViewCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CTreeViewCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Operations
	static LPCTSTR GetWndClassName()
	{
		return WC_TREEVIEW;
	}

	HTREEITEM InsertItem(LPTV_INSERTSTRUCT lpInsertStruct)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_INSERTITEM, 0, (LPARAM)lpInsertStruct);
	}
	HTREEITEM InsertItem(LPCTSTR lpszItem, int nImage,
		int nSelectedImage, HTREEITEM hParent, HTREEITEM hInsertAfter)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, lpszItem, nImage, nSelectedImage, 0, 0, 0, hParent, hInsertAfter);
	}
	HTREEITEM InsertItem(LPCTSTR lpszItem, HTREEITEM hParent, HTREEITEM hInsertAfter)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return InsertItem(TVIF_TEXT, lpszItem, 0, 0, 0, 0, 0, hParent, hInsertAfter);
	}
	BOOL DeleteItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_DELETEITEM, 0, (LPARAM)hItem);
	}
	BOOL DeleteAllItems()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_DELETEITEM, 0, (LPARAM)TVI_ROOT);
	}
	BOOL Expand(HTREEITEM hItem, UINT nCode)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_EXPAND, nCode, (LPARAM)hItem);
	}
	UINT GetCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, TVM_GETCOUNT, 0, 0L);
	}
	UINT GetIndent() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, TVM_GETINDENT, 0, 0L);
	}
	void SetIndent(UINT nIndent)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TVM_SETINDENT, nIndent, 0L);
	}
	HIMAGELIST GetImageList(UINT nImageList) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)(::SendMessage(m_hWnd, TVM_GETIMAGELIST, (UINT)nImageList, 0L));
	}
	HIMAGELIST SetImageList(HIMAGELIST hImageList, int nImageListType)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)(::SendMessage(m_hWnd, TVM_SETIMAGELIST, (UINT)nImageListType, (LPARAM)hImageList));
	}
	HTREEITEM GetNextItem(HTREEITEM hItem, UINT nCode)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, nCode, (LPARAM)hItem);
	}
	HTREEITEM GetChildItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_CHILD, (LPARAM)hItem);
	}
	HTREEITEM GetNextSiblingItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_NEXT, (LPARAM)hItem);
	}
	HTREEITEM GetPrevSiblingItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_PREVIOUS, (LPARAM)hItem);
	}
	HTREEITEM GetParentItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_PARENT, (LPARAM)hItem);
	}
	HTREEITEM GetFirstVisibleItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_FIRSTVISIBLE, 0L);
	}
	HTREEITEM GetNextVisibleItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_NEXTVISIBLE, (LPARAM)hItem);
	}
	HTREEITEM GetPrevVisibleItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_PREVIOUSVISIBLE, (LPARAM)hItem);
	}
	HTREEITEM GetSelectedItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_CARET, 0L);
	}
	HTREEITEM GetDropHilightItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_DROPHILITE, 0L);
	}
	HTREEITEM GetRootItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0L);
	}
	BOOL Select(HTREEITEM hItem, UINT nCode)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_SELECTITEM, nCode, (LPARAM)hItem);
	}
	BOOL SelectItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_SELECTITEM, TVGN_CARET, (LPARAM)hItem);
	}
	BOOL SelectDropTarget(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_SELECTITEM, TVGN_DROPHILITE, (LPARAM)hItem);
	}
	BOOL SelectSetFirstVisible(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_SELECTITEM, TVGN_FIRSTVISIBLE, (LPARAM)hItem);
	}
	BOOL GetItem(TV_ITEM* pItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)pItem);
	}
	BOOL SetItem(TV_ITEM* pItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_SETITEM, 0, (LPARAM)pItem);
	}
	BOOL SetItemText(HTREEITEM hItem, LPCTSTR lpszItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItem(hItem, TVIF_TEXT, lpszItem, 0, 0, 0, 0, NULL);
	}
	BOOL SetItemImage(HTREEITEM hItem, int nImage, int nSelectedImage)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItem(hItem, TVIF_IMAGE|TVIF_SELECTEDIMAGE, NULL, nImage, nSelectedImage, 0, 0, NULL);
	}
	BOOL SetItemState(HTREEITEM hItem, UINT nState, UINT nStateMask)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItem(hItem, TVIF_STATE, NULL, 0, 0, nState, nStateMask, NULL);
	}
	BOOL SetItemData(HTREEITEM hItem, DWORD dwData)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return SetItem(hItem, TVIF_PARAM, NULL, 0, 0, 0, 0, (LPARAM)dwData);
	}
	HWND EditLabel(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TVM_EDITLABEL, 0, (LPARAM)hItem);
	}
	HTREEITEM HitTest(TV_HITTESTINFO* pHitTestInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_HITTEST, 0, (LPARAM)pHitTestInfo);
	}
	HWND GetEditControl() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TVM_GETEDITCONTROL, 0, 0L);
	}
	UINT GetVisibleCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, TVM_GETVISIBLECOUNT, 0, 0L);
	}
	BOOL SortChildren(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_SORTCHILDREN, 0, (LPARAM)hItem);
	}
	BOOL EnsureVisible(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_ENSUREVISIBLE, 0, (LPARAM)hItem);
	}
	BOOL SortChildrenCB(LPTV_SORTCB pSort)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_SORTCHILDRENCB, 0, (LPARAM)pSort);
	}

	BOOL GetItemRect(HTREEITEM hItem, LPRECT lpRect, BOOL bTextOnly) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		*(HTREEITEM*)lpRect = hItem;
		return (BOOL)::SendMessage(m_hWnd, TVM_GETITEMRECT, (WPARAM)bTextOnly, (LPARAM)lpRect);
	}

#ifndef _ATL_NO_COM
	BOOL GetItemText(HTREEITEM hItem, BSTR& bstrText) const
	{
		
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(bstrText == NULL);
		TV_ITEM item;
		item.hItem = hItem;
		item.mask = TVIF_TEXT;
		LPTSTR lpstrText = NULL;
		int nLen = 128;
		do
		{
			nLen *= 2;
			LPTSTR lpstrTemp;
			lpstrTemp = (LPTSTR)realloc(lpstrText, nLen * sizeof(TCHAR));
			if(lpstrTemp == NULL)
			{
				free(lpstrText);
				return FALSE;
			}
			lpstrText = lpstrTemp;
			item.pszText = lpstrText;
			item.cchTextMax = nLen;
			::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item);
		}
		while (lstrlen(item.pszText) == (nLen-1));

		bstrText = ::SysAllocString(CT2OLE(lpstrText));
		free(lpstrText);

		return (bstrText != NULL) ? TRUE : FALSE;
	}
#endif //!_ATL_NO_COM

	BOOL GetItemImage(HTREEITEM hItem, int& nImage, int& nSelectedImage) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_ITEM item;
		item.hItem = hItem;
		item.mask = TVIF_IMAGE|TVIF_SELECTEDIMAGE;
		BOOL bRes = (BOOL)::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item);
		if (bRes)
		{
			nImage = item.iImage;
			nSelectedImage = item.iSelectedImage;
		}
		return bRes;
	}

	UINT GetItemState(HTREEITEM hItem, UINT nStateMask) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_ITEM item;
		item.hItem = hItem;
		item.mask = TVIF_STATE;
		item.stateMask = nStateMask;
		item.state = 0;
		::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item);
		return item.state;
	}

	DWORD GetItemData(HTREEITEM hItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_ITEM item;
		item.hItem = hItem;
		item.mask = TVIF_PARAM;
		::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item);
		return (DWORD)item.lParam;
	}

	BOOL ItemHasChildren(HTREEITEM hItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_ITEM item;
		item.hItem = hItem;
		item.mask = TVIF_CHILDREN;
		::SendMessage(m_hWnd, TVM_GETITEM, 0, (LPARAM)&item);
		return item.cChildren;
	}

	BOOL SetItem(HTREEITEM hItem, UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_ITEM item;
		item.hItem = hItem;
		item.mask = nMask;
		item.pszText = (LPTSTR) lpszItem;
		item.iImage = nImage;
		item.iSelectedImage = nSelectedImage;
		item.state = nState;
		item.stateMask = nStateMask;
		item.lParam = lParam;
		return (BOOL)::SendMessage(m_hWnd, TVM_SETITEM, 0, (LPARAM)&item);
	}

	HTREEITEM InsertItem(UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam,
		HTREEITEM hParent, HTREEITEM hInsertAfter)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_INSERTSTRUCT tvis;
		tvis.hParent = hParent;
		tvis.hInsertAfter = hInsertAfter;
		tvis.item.mask = nMask;
		tvis.item.pszText = (LPTSTR) lpszItem;
		tvis.item.iImage = nImage;
		tvis.item.iSelectedImage = nSelectedImage;
		tvis.item.state = nState;
		tvis.item.stateMask = nStateMask;
		tvis.item.lParam = lParam;
		return (HTREEITEM)::SendMessage(m_hWnd, TVM_INSERTITEM, 0, (LPARAM)&tvis);
	}

	HTREEITEM HitTest(POINT pt, UINT* pFlags)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_HITTESTINFO hti;
		hti.pt = pt;
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_HITTEST, 0, (LPARAM)&hti);
		if (pFlags != NULL)
			*pFlags = hti.flags;
		return hTreeItem;
	}

	void RemoveImageList(int nImageList)
	{
		HIMAGELIST h = (HIMAGELIST)::SendMessage(m_hWnd, TVM_GETIMAGELIST, (WPARAM)nImageList, 0L);
		::SendMessage(m_hWnd, TVM_SETIMAGELIST, (WPARAM)nImageList, 0L);
	}

	HIMAGELIST CreateDragImage(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TVM_CREATEDRAGIMAGE, 0, (LPARAM)hItem);
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	HWND GetToolTips()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TVM_GETTOOLTIPS, 0, 0L);
	}
	HWND SetToolTips(HWND hWndTT)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TVM_SETTOOLTIPS, (WPARAM)hWndTT, 0L);
	}
	BOOL Expand(HTREEITEM hItem, int nType)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TVM_EXPAND, nType, (LPARAM)hItem);
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CTreeViewCtrlT<CWindow>     CTreeViewCtrl;

/////////////////////////////////////////////////////////////////////////////
// CTreeViewCtrlEx

typedef CTreeViewCtrlExT<CWindow> CTreeViewCtrlEx;  // forward declaration

class CTreeItem
{
public:
	HTREEITEM m_hTreeItem;
	CTreeViewCtrlEx* m_pTreeView;

// Construction
	CTreeItem(HTREEITEM hTreeItem = NULL, CTreeViewCtrlEx* pTreeView = NULL) : m_hTreeItem(hTreeItem), m_pTreeView(pTreeView)
	{ }

	CTreeItem(const CTreeItem& posSrc)
	{
		*this = posSrc;
	}

	operator HTREEITEM() { return m_hTreeItem; }

	const CTreeItem& operator =(const CTreeItem& itemSrc)
	{
		m_hTreeItem = itemSrc.m_hTreeItem;
		m_pTreeView = itemSrc.m_pTreeView;
		return *this;
	}

// Attributes
	CTreeViewCtrlEx* GetTreeView() const { return m_pTreeView; }

	BOOL operator !() const { return m_hTreeItem == NULL; }
	BOOL IsNull() const { return m_hTreeItem == NULL; }

	BOOL GetRect(LPRECT lpRect, BOOL bTextOnly);
#ifndef _ATL_NO_COM
	BOOL GetText(BSTR& bstrText);
#endif //!_ATL_NO_COM
	BOOL GetImage(int& nImage, int& nSelectedImage);
	UINT GetState(UINT nStateMask);
	DWORD GetData();
	BOOL SetItem(UINT nMask, LPCTSTR lpszItem, int nImage, int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam);
	BOOL SetText(LPCTSTR lpszItem);
	BOOL SetImage(int nImage, int nSelectedImage);
	BOOL SetState(UINT nState, UINT nStateMask);
	BOOL SetData(DWORD dwData);

// Operations
	CTreeItem InsertAfter(LPCTSTR lpstrItem, HTREEITEM hItemAfter, int nImageIndex)
	{
		return _Insert(lpstrItem, nImageIndex, hItemAfter);
	}
	CTreeItem AddHead(LPCTSTR lpstrItem, int nImageIndex)
	{
		return _Insert(lpstrItem, nImageIndex, TVI_FIRST);
	}
	CTreeItem AddTail(LPCTSTR lpstrItem, int nImageIndex)
	{
		return _Insert(lpstrItem, nImageIndex, TVI_LAST);
	}

	CTreeItem GetChild();
	CTreeItem GetNext(UINT nCode);
	CTreeItem GetNextSibling();
	CTreeItem GetPrevSibling();
	CTreeItem GetParent();
	CTreeItem GetFirstVisible();
	CTreeItem GetNextVisible();
	CTreeItem GetPrevVisible();
	CTreeItem GetSelected();
	CTreeItem GetDropHilight();
	CTreeItem GetRoot();
	BOOL HasChildren();
	BOOL Delete();
	BOOL Expand(UINT nCode = TVE_EXPAND);
	BOOL Select(UINT nCode);
	BOOL Select();
	BOOL SelectDropTarget();
	BOOL SelectSetFirstVisible();
	HWND EditLabel();
	HIMAGELIST CreateDragImage();
	BOOL SortChildren();
	BOOL EnsureVisible();

	CTreeItem _Insert(LPCTSTR lpstrItem, int nImageIndex, HTREEITEM hItemAfter);
	int GetImageIndex();
};


template <class Base>
class CTreeViewCtrlExT : public CTreeViewCtrlT< Base >
{
public:
// Constructors
	CTreeViewCtrlExT(HWND hWnd = NULL) : CTreeViewCtrlT< Base >(hWnd) { }

	CTreeViewCtrlExT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

// Operations (overides that return CTreeItem)
	CTreeItem InsertItem(LPTV_INSERTSTRUCT lpInsertStruct)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_INSERTITEM, 0, (LPARAM)lpInsertStruct);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem InsertItem(LPCTSTR lpszItem, int nImage,
		int nSelectedImage, HTREEITEM hParent, HTREEITEM hInsertAfter)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return InsertItem(TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE, lpszItem, nImage, nSelectedImage, 0, 0, 0, hParent, hInsertAfter);
	}
	CTreeItem InsertItem(LPCTSTR lpszItem, HTREEITEM hParent, HTREEITEM hInsertAfter)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return InsertItem(TVIF_TEXT, lpszItem, 0, 0, 0, 0, 0, hParent, hInsertAfter);
	}
	CTreeItem GetNextItem(HTREEITEM hItem, UINT nCode)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, nCode, (LPARAM)hItem);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetChildItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_CHILD, (LPARAM)hItem);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetNextSiblingItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_NEXT, (LPARAM)hItem);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetPrevSiblingItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_PREVIOUS, (LPARAM)hItem);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetParentItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_PARENT, (LPARAM)hItem);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetFirstVisibleItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_FIRSTVISIBLE, 0L);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetNextVisibleItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_NEXTVISIBLE, (LPARAM)hItem);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetPrevVisibleItem(HTREEITEM hItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_PREVIOUSVISIBLE, (LPARAM)hItem);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetSelectedItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_CARET, 0L);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetDropHilightItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_DROPHILITE, 0L);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem GetRootItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_GETNEXTITEM, TVGN_ROOT, 0L);
		return CTreeItem(hTreeItem, this);
	}
	CTreeItem HitTest(TV_HITTESTINFO* pHitTestInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_HITTEST, 0, (LPARAM)pHitTestInfo);
		return CTreeItem(hTreeItem, this);
	}

	CTreeItem InsertItem(UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam,
		HTREEITEM hParent, HTREEITEM hInsertAfter)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_INSERTSTRUCT tvis;
		tvis.hParent = hParent;
		tvis.hInsertAfter = hInsertAfter;
		tvis.item.mask = nMask;
		tvis.item.pszText = (LPTSTR) lpszItem;
		tvis.item.iImage = nImage;
		tvis.item.iSelectedImage = nSelectedImage;
		tvis.item.state = nState;
		tvis.item.stateMask = nStateMask;
		tvis.item.lParam = lParam;
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_INSERTITEM, 0, (LPARAM)&tvis);
		return CTreeItem(hTreeItem, this);
	}

	CTreeItem HitTest(POINT pt, UINT* pFlags)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TV_HITTESTINFO hti;
		hti.pt = pt;
		HTREEITEM hTreeItem = (HTREEITEM)::SendMessage(m_hWnd, TVM_HITTEST, 0, (LPARAM)&hti);
		if (pFlags != NULL)
			*pFlags = hti.flags;
		return CTreeItem(hTreeItem, this);
	}
};


// CTreeItem inline methods
inline BOOL CTreeItem::GetRect(LPRECT lpRect, BOOL bTextOnly)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetItemRect(m_hTreeItem,lpRect,bTextOnly);
}
inline CTreeItem CTreeItem::GetNext(UINT nCode)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetNextItem(m_hTreeItem,nCode);
}
inline CTreeItem CTreeItem::GetChild()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetChildItem(m_hTreeItem);
}
inline CTreeItem CTreeItem::GetNextSibling()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetNextSiblingItem(m_hTreeItem);
}
inline CTreeItem CTreeItem::GetPrevSibling()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetPrevSiblingItem(m_hTreeItem);
}
inline CTreeItem CTreeItem::GetParent()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetParentItem(m_hTreeItem);
}
inline CTreeItem CTreeItem::GetFirstVisible()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetFirstVisibleItem();
}
inline CTreeItem CTreeItem::GetNextVisible()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetNextVisibleItem(m_hTreeItem);
}
inline CTreeItem CTreeItem::GetPrevVisible()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetPrevVisibleItem(m_hTreeItem);
}
inline CTreeItem CTreeItem::GetSelected()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetSelectedItem();
}
inline CTreeItem CTreeItem::GetDropHilight()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetDropHilightItem();
}
inline CTreeItem CTreeItem::GetRoot()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetRootItem();
}
#ifndef _ATL_NO_COM
inline BOOL CTreeItem::GetText(BSTR& bstrText)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetItemText(m_hTreeItem, bstrText);
}
#endif //!_ATL_NO_COM
inline BOOL CTreeItem::GetImage(int& nImage, int& nSelectedImage)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetItemImage(m_hTreeItem,nImage,nSelectedImage);
}
inline UINT CTreeItem::GetState(UINT nStateMask)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetItemState(m_hTreeItem,nStateMask);
}
inline DWORD CTreeItem::GetData()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->GetItemData(m_hTreeItem);
}
inline BOOL CTreeItem::SetItem(UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SetItem(m_hTreeItem, nMask, lpszItem, nImage, nSelectedImage, nState, nStateMask, lParam);
}
inline BOOL CTreeItem::SetText(LPCTSTR lpszItem)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SetItemText(m_hTreeItem,lpszItem);
}
inline BOOL CTreeItem::SetImage(int nImage, int nSelectedImage)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SetItemImage(m_hTreeItem,nImage,nSelectedImage);
}
inline BOOL CTreeItem::SetState(UINT nState, UINT nStateMask)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SetItemState(m_hTreeItem,nState,nStateMask);
}
inline BOOL CTreeItem::SetData(DWORD dwData)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SetItemData(m_hTreeItem,dwData);
}
inline BOOL CTreeItem::HasChildren()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->ItemHasChildren(m_hTreeItem);
}
inline BOOL CTreeItem::Delete()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->DeleteItem(m_hTreeItem);
}
inline BOOL CTreeItem::Expand(UINT nCode)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->Expand(m_hTreeItem,nCode);
}
inline BOOL CTreeItem::Select(UINT nCode)
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->Select(m_hTreeItem,nCode);
}
inline BOOL CTreeItem::Select()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SelectItem(m_hTreeItem);
}
inline BOOL CTreeItem::SelectDropTarget()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SelectDropTarget(m_hTreeItem);
}
inline BOOL CTreeItem::SelectSetFirstVisible()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SelectSetFirstVisible(m_hTreeItem);
}
inline HWND CTreeItem::EditLabel()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->EditLabel(m_hTreeItem);
}
inline HIMAGELIST CTreeItem::CreateDragImage()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->CreateDragImage(m_hTreeItem);
}
inline BOOL CTreeItem::SortChildren()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->SortChildren(m_hTreeItem);
}
inline BOOL CTreeItem::EnsureVisible()
{
	ATLENSURE(m_pTreeView != NULL);
	return m_pTreeView->EnsureVisible(m_hTreeItem);
}

inline CTreeItem CTreeItem::_Insert(LPCTSTR lpstrItem, int nImageIndex, HTREEITEM hItemAfter)
{
	ATLENSURE(m_pTreeView != NULL);
	TV_INSERTSTRUCT ins;
	ins.hParent = m_hTreeItem;
	ins.hInsertAfter = hItemAfter;
	ins.item.mask = TVIF_TEXT;
	ins.item.pszText = (LPTSTR)lpstrItem;
	if(nImageIndex != -1)
	{
		ins.item.mask |= TVIF_IMAGE | TVIF_SELECTEDIMAGE;
		ins.item.iImage = nImageIndex;
		ins.item.iSelectedImage = nImageIndex;
	}
	return CTreeItem(m_pTreeView->InsertItem(&ins), m_pTreeView);
}

inline int CTreeItem::GetImageIndex()
{
	ATLENSURE(m_pTreeView != NULL);
	TV_ITEM item;
	item.mask = TVIF_HANDLE | TVIF_IMAGE;
	item.hItem = m_hTreeItem;
	m_pTreeView->GetItem(&item);
	return item.iImage;
}


/////////////////////////////////////////////////////////////////////////////
// CHeaderCtrl

template <class Base>
class CHeaderCtrlT : public Base
{
public:
// Constructors
	CHeaderCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CHeaderCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return WC_HEADER;
	}

	int GetItemCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, HDM_GETITEMCOUNT, 0, 0L);
	}
	BOOL GetItem(int nIndex, HD_ITEM* pHeaderItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, HDM_GETITEM, nIndex, (LPARAM)pHeaderItem);
	}
	BOOL SetItem(int nIndex, HD_ITEM* pHeaderItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, HDM_SETITEM, nIndex, (LPARAM)pHeaderItem);
	}

// Operations
	int InsertItem(int nIndex, HD_ITEM* phdi)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, HDM_INSERTITEM, nIndex, (LPARAM)phdi);
	}
	BOOL DeleteItem(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, HDM_DELETEITEM, nIndex, 0L);
	}
	BOOL Layout(HD_LAYOUT* pHeaderLayout)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, HDM_LAYOUT, 0, (LPARAM)pHeaderLayout);
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	HIMAGELIST GetImageList()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, HDM_GETIMAGELIST, 0, 0L);
	}
	HIMAGELIST SetImageList(HIMAGELIST hImageList)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, HDM_SETIMAGELIST, 0, (LPARAM)hImageList);
	}
	BOOL GetOrderArray(int nSize, int* lpnArray)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, HDM_GETORDERARRAY, nSize, (LPARAM)lpnArray);
	}
	BOOL SetOrderArray(int nSize, int* lpnArray)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, HDM_SETORDERARRAY, nSize, (LPARAM)lpnArray);
	}
	int OrderToIndex(int nOrder)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, HDM_ORDERTOINDEX, nOrder, 0L);
	}
	HIMAGELIST CreateDragImage(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, HDM_CREATEDRAGIMAGE, nIndex, 0L);
	}
	BOOL GetItemRect(int nIndex, LPRECT lpItemRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, HDM_GETITEMRECT, nIndex, (LPARAM)lpItemRect);
	}
	int SetHotDivider(BOOL bPos, DWORD dwInputValue)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, HDM_SETHOTDIVIDER, bPos, dwInputValue);
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CHeaderCtrlT<CWindow>       CHeaderCtrl;

/////////////////////////////////////////////////////////////////////////////
// CToolBarCtrl

template <class Base>
class CToolBarCtrlT : public Base
{
public:
// Construction
	CToolBarCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CToolBarCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return TOOLBARCLASSNAME;
	}

	BOOL IsButtonEnabled(int nID) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_ISBUTTONENABLED, nID, 0L);
	}
	BOOL IsButtonChecked(int nID) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_ISBUTTONCHECKED, nID, 0L);
	}
	BOOL IsButtonPressed(int nID) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_ISBUTTONPRESSED, nID, 0L);
	}
	BOOL IsButtonHidden(int nID) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return(BOOL) ::SendMessage(m_hWnd, TB_ISBUTTONHIDDEN, nID, 0L);
	}
	BOOL IsButtonIndeterminate(int nID) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_ISBUTTONINDETERMINATE, nID, 0L);
	}
	BOOL SetState(int nID, UINT nState)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETSTATE, nID, MAKELPARAM(nState, 0));
	}
	int GetState(int nID) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_GETSTATE, nID, 0L);
	}
	BOOL GetButton(int nIndex, LPTBBUTTON lpButton) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_GETBUTTON, nIndex, (LPARAM)lpButton);
	}
	int GetButtonCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_BUTTONCOUNT, 0, 0L);
	}
	BOOL GetItemRect(int nIndex, LPRECT lpRect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_GETITEMRECT, nIndex, (LPARAM)lpRect);
	}
	void SetButtonStructSize(int nSize)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TB_BUTTONSTRUCTSIZE, nSize, 0L);
	}
	BOOL SetButtonSize(SIZE size)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETBUTTONSIZE, 0, MAKELPARAM(size.cx, size.cy));
	}
	BOOL SetBitmapSize(SIZE size)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETBITMAPSIZE, 0, MAKELPARAM(size.cx, size.cy));
	}
	HWND GetToolTips() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TB_GETTOOLTIPS, 0, 0L);
	}
	void SetToolTips(HWND hWndToolTip)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TB_SETTOOLTIPS, (WPARAM)hWndToolTip, 0L);
	}
	void SetNotifyWnd(HWND hWnd)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TB_SETPARENT, (WPARAM)hWnd, 0L);
	}
	void SetRows(int nRows, BOOL bLarger, LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TB_SETROWS, MAKELPARAM(nRows, bLarger), (LPARAM)lpRect);
	}
	int GetRows() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_GETROWS, 0, 0L);
	}
	BOOL SetCmdID(int nIndex, UINT nID)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETCMDID, nIndex, nID);
	}
	UINT GetBitmapFlags() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, TB_GETBITMAPFLAGS, 0, 0L);
	}

// Operations
	BOOL EnableButton(int nID, BOOL bEnable = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_ENABLEBUTTON, nID, MAKELPARAM(bEnable, 0));
	}
	BOOL CheckButton(int nID, BOOL bCheck = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_CHECKBUTTON, nID, MAKELPARAM(bCheck, 0));
	}
	BOOL PressButton(int nID, BOOL bPress = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_PRESSBUTTON, nID, MAKELPARAM(bPress, 0));
	}
	BOOL HideButton(int nID, BOOL bHide = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_HIDEBUTTON, nID, MAKELPARAM(bHide, 0));
	}
	BOOL Indeterminate(int nID, BOOL bIndeterminate = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_INDETERMINATE, nID, MAKELPARAM(bIndeterminate, 0));
	}
	int AddBitmap(int nNumButtons, UINT nBitmapID)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TBADDBITMAP tbab;
		tbab.hInst = _Module.GetResourceInstance();
		ATLENSURE(tbab.hInst != NULL);
		tbab.nID = nBitmapID;
		return (int)::SendMessage(m_hWnd, TB_ADDBITMAP, (WPARAM)nNumButtons, (LPARAM)&tbab);
	}
	int AddBitmap(int nNumButtons, HBITMAP hBitmap)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TBADDBITMAP tbab;
		tbab.hInst = NULL;
		tbab.nID = (UINT)hBitmap;
		return (int)::SendMessage(m_hWnd, TB_ADDBITMAP, (WPARAM)nNumButtons, (LPARAM)&tbab);
	}
	BOOL AddButtons(int nNumButtons, LPTBBUTTON lpButtons)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_ADDBUTTONS, nNumButtons, (LPARAM)lpButtons);
	}
	BOOL InsertButton(int nIndex, LPTBBUTTON lpButton)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_INSERTBUTTON, nIndex, (LPARAM)lpButton);
	}
	BOOL DeleteButton(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_DELETEBUTTON, nIndex, 0L);
	}
	UINT CommandToIndex(UINT nID) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, TB_COMMANDTOINDEX, nID, 0L);
	}
	void SaveState(HKEY hKeyRoot, LPCTSTR lpszSubKey, LPCTSTR lpszValueName)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TBSAVEPARAMS tbs;
		tbs.hkr = hKeyRoot;
		tbs.pszSubKey = lpszSubKey;
		tbs.pszValueName = lpszValueName;
		::SendMessage(m_hWnd, TB_SAVERESTORE, (WPARAM)TRUE, (LPARAM)&tbs);
	}
	void RestoreState(HKEY hKeyRoot, LPCTSTR lpszSubKey, LPCTSTR lpszValueName)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		TBSAVEPARAMS tbs;
		tbs.hkr = hKeyRoot;
		tbs.pszSubKey = lpszSubKey;
		tbs.pszValueName = lpszValueName;
		::SendMessage(m_hWnd, TB_SAVERESTORE, (WPARAM)FALSE, (LPARAM)&tbs);
	}
	void Customize()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TB_CUSTOMIZE, 0, 0L);
	}
	int AddString(UINT nStringID)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_ADDSTRING, (WPARAM)_Module.GetResourceInstance(), (LPARAM)nStringID);
	}
	int AddStrings(LPCTSTR lpszStrings)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_ADDSTRING, 0, (LPARAM)lpszStrings);
	}
	void AutoSize()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TB_AUTOSIZE, 0, 0L);
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	BOOL GetAnchorHighlight()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_GETANCHORHIGHLIGHT, 0, 0L);
	}
	BOOL SetAnchorHighlight(BOOL bEnable = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETANCHORHIGHLIGHT, bEnable, 0L);
	}
	BOOL GetButtonInfo(int nID, LPTBBUTTONINFO lptbbi)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_GETBUTTONINFO, 0, (LPARAM)lptbbi);
	}
	BOOL SetButtonInfo(int nID, LPTBBUTTONINFO lptbbi)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETBUTTONINFO, 0, (LPARAM)lptbbi);
	}
	HIMAGELIST GetImageList()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TB_GETIMAGELIST, 0, 0L);
	}
	HIMAGELIST SetImageList(HIMAGELIST hImageList)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TB_SETIMAGELIST, 0, (LPARAM)hImageList);
	}
	HIMAGELIST GetDisabledImageList()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TB_GETDISABLEDIMAGELIST, 0, 0L);
	}
	HIMAGELIST SetDisabledImageList(HIMAGELIST hImageList)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TB_SETDISABLEDIMAGELIST, 0, (LPARAM)hImageList);
	}
	HIMAGELIST GetHotImageList()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TB_GETHOTIMAGELIST, 0, 0L);
	}
	HIMAGELIST SetHotImageList(HIMAGELIST hImageList)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TB_SETHOTIMAGELIST, 0, (LPARAM)hImageList);
	}
	int GetHotItem()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_GETHOTITEM, 0, 0L);
	}
	int SetHotItem(int nItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_SETHOTITEM, nItem, 0L);
	}
	DWORD GetStyle()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, TB_GETSTYLE, 0, 0L);
	}
//REVIEW - return value?
	void SetStyle(DWORD dwStyle)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TB_SETSTYLE, 0, dwStyle);
	}
	DWORD GetBitmapFlags()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, TB_GETBITMAPFLAGS, 0, 0L);
	}
	DWORD GetButtonSize()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, TB_GETBUTTONSIZE, 0, 0L);
	}
	HRESULT GetObject(REFIID iid, LPVOID* ppvObject)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HRESULT)::SendMessage(m_hWnd, TB_GETOBJECT, (WPARAM)&iid, (LPARAM)ppvObject);
	}
	BOOL GetRect(int nID, LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_GETRECT, nID, (LPARAM)lpRect);
	}
	int GetTextRows()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_GETTEXTROWS, 0, 0L);
	}
	BOOL HighlightButton(int nButtonID, BOOL bHighlight)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_HIGHLIGHTBUTTON, nButtonID, MAKELPARAM(bHighlight, 0));
	}
	BOOL IsButtonHighlighted(int nButtonID)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_ISBUTTONHIGHLIGHTED, nButtonID, 0L);
	}
	int LoadImages(int nBitmapID)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_LOADIMAGES, nBitmapID, (LPARAM)_Module.GetResourceInstance());
	}
	int LoadStdImages(int nBitmapID)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TB_LOADIMAGES, nBitmapID, (LPARAM)HINST_COMMCTRL);
	}
	BOOL ReplaceBitmap(LPTBREPLACEBITMAP ptbrb)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_REPLACEBITMAP, 0, (LPARAM)ptbrb);
	}
	BOOL SetButtonWidth(int cxMin, int cxMax)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETBUTTONWIDTH, 0, MAKELPARAM(cxMin, cxMax));
	}
	DWORD SetDrawTextFlags(DWORD dwMask, DWORD dwFlags)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, TB_SETDRAWTEXTFLAGS, dwMask, dwFlags);
	}
	BOOL SetIndent(int nIndent)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETINDENT, nIndent, 0L);
	}
	BOOL SetMaxTextRows(int nMaxTextRows)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TB_SETMAXTEXTROWS, nMaxTextRows, 0L);
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CToolBarCtrlT<CWindow>      CToolBarCtrl;

/////////////////////////////////////////////////////////////////////////////
// CStatusBarCtrl

template <class Base>
class CStatusBarCtrlT : public Base
{
public:
// Constructors
	CStatusBarCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CStatusBarCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return STATUSCLASSNAME;
	}

	BOOL SetText(int nPane, LPCTSTR lpszText, int nType = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(nPane < 256);
		return (BOOL)::SendMessage(m_hWnd, SB_SETTEXT, (nPane | nType), (LPARAM)lpszText);
	}
	int GetText(int nPane, LPSTR lpszText, int* pType = NULL) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(nPane < 256);
		DWORD dw = ::SendMessage(m_hWnd, SB_GETTEXT, (WPARAM)nPane, (LPARAM)lpszText);
		if(pType != NULL)
			*pType = HIWORD(dw);
		return LOWORD(dw);
	}
#ifndef _ATL_NO_COM
	BOOL GetTextBSTR(int nPane, BSTR& bstrText, int* pType = NULL) const
	{
		
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(nPane < 256);
		ATLENSURE(bstrText == NULL);
		int nLength = LOWORD(::SendMessage(m_hWnd, SB_GETTEXTLENGTH, (WPARAM)nPane, 0L));
		if(nLength == 0)
			return FALSE;

		LPSTR lpszText = (LPSTR)_alloca((nLength + 1) * sizeof(char));
		if(!GetText(nPane, lpszText, pType))
			return FALSE;

		bstrText = ::SysAllocString(CA2W(lpszText));
		return (bstrText != NULL) ? TRUE : FALSE;
	}
#endif //!_ATL_NO_COM
	int GetTextLength(int nPane, int* pType = NULL) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(nPane < 256);
		DWORD dw = ::SendMessage(m_hWnd, SB_GETTEXTLENGTH, (WPARAM)nPane, 0L);
		if (pType != NULL)
			*pType = HIWORD(dw);
		return LOWORD(dw);
	}
	BOOL SetParts(int nParts, int* pWidths)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, SB_SETPARTS, nParts, (LPARAM)pWidths);
	}
	int GetParts(int nParts, int* pParts) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, SB_GETPARTS, nParts, (LPARAM)pParts);
	}
	BOOL GetBorders(int* pBorders) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, SB_GETBORDERS, 0, (LPARAM)pBorders);
	}
	BOOL GetBorders(int& nHorz, int& nVert, int& nSpacing) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		int borders[3];
		BOOL bResult = (BOOL)::SendMessage(m_hWnd, SB_GETBORDERS, 0, (LPARAM)&borders);
		if (bResult)
		{
			nHorz = borders[0];
			nVert = borders[1];
			nSpacing = borders[2];
		}
		return bResult;
	}
	void SetMinHeight(int nMin)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, SB_SETMINHEIGHT, nMin, 0L);
	}
	BOOL SetSimple(BOOL bSimple = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, SB_SIMPLE, bSimple, 0L);
	}
	BOOL GetRect(int nPane, LPRECT lpRect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, SB_GETRECT, nPane, (LPARAM)lpRect);
	}

	// new common control support
	BOOL IsSimple() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, SB_ISSIMPLE, 0, 0L);
	}
};

typedef CStatusBarCtrlT<CWindow>    CStatusBarCtrl;

/////////////////////////////////////////////////////////////////////////////
// CTabCtrl

template <class Base>
class CTabCtrlT : public Base
{
public:
// Constructors
	CTabCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CTabCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return WC_TABCONTROL;
	}

	HIMAGELIST GetImageList() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TCM_GETIMAGELIST, 0, 0L);
	}
	HIMAGELIST SetImageList(HIMAGELIST hImageList)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, TCM_SETIMAGELIST, 0, (LPARAM)hImageList);
	}
	int GetItemCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TCM_GETITEMCOUNT, 0, 0L);
	}
	BOOL GetItem(int nItem, TC_ITEM* pTabCtrlItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TCM_GETITEM, nItem, (LPARAM)pTabCtrlItem);
	}
	BOOL SetItem(int nItem, TC_ITEM* pTabCtrlItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TCM_SETITEM, nItem, (LPARAM)pTabCtrlItem);
	}
	BOOL GetItemRect(int nItem, LPRECT lpRect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TCM_GETITEMRECT, nItem, (LPARAM)lpRect);
	}
	int GetCurSel() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TCM_GETCURSEL, 0, 0L);
	}
	int SetCurSel(int nItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TCM_SETCURSEL, nItem, 0L);
	}
	SIZE SetItemSize(SIZE size)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		DWORD dwSize = ::SendMessage(m_hWnd, TCM_SETITEMSIZE, 0, MAKELPARAM(size.cx, size.cy));
		SIZE sizeRet;
		sizeRet.cx = LOWORD(dwSize);
		sizeRet.cy = HIWORD(dwSize);
		return sizeRet;
	}
	void SetPadding(SIZE size)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TCM_SETPADDING, 0, MAKELPARAM(size.cx, size.cy));
	}
	int GetRowCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TCM_GETROWCOUNT, 0, 0L);
	}
	HWND GetTooltips() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TCM_GETTOOLTIPS, 0, 0L);
	}
	void SetTooltips(HWND hWndToolTip)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TCM_SETTOOLTIPS, (WPARAM)hWndToolTip, 0L);
	}
	int GetCurFocus() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TCM_GETCURFOCUS, 0, 0L);
	}

// Operations
	BOOL InsertItem(int nItem, TC_ITEM* pTabCtrlItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TCM_INSERTITEM, nItem, (LPARAM)pTabCtrlItem);
	}
	BOOL DeleteItem(int nItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TCM_DELETEITEM, nItem, 0L);
	}
	BOOL DeleteAllItems()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TCM_DELETEALLITEMS, 0, 0L);
	}
	void AdjustRect(BOOL bLarger, LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TCM_ADJUSTRECT, bLarger, (LPARAM)lpRect);
	}
	void RemoveImage(int nImage)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TCM_REMOVEIMAGE, nImage, 0L);
	}
	int HitTest(TC_HITTESTINFO* pHitTestInfo) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TCM_HITTEST, 0, (LPARAM)pHitTestInfo);
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	DWORD GetExtendedStyle()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD)::SendMessage(m_hWnd, TCM_GETEXTENDEDSTYLE, 0, 0L);
	}
	DWORD SetExtendedStyle(DWORD dwExMask, DWORD dwExStyle)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD)::SendMessage(m_hWnd, TCM_SETEXTENDEDSTYLE, dwExMask, dwExStyle);
	}
	int SetMinTabWidth(int nWidth = -1)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TCM_SETMINTABWIDTH, 0, nWidth);
	}
	void DeselectAll(BOOL bExcludeFocus = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TCM_DESELECTALL, bExcludeFocus, 0L);
	}
	BOOL HighlightItem(int nIndex, BOOL bHighlight = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TCM_HIGHLIGHTITEM, nIndex, MAKELPARAM(bHighlight, 0));
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CTabCtrlT<CWindow>  CTabCtrl;

/////////////////////////////////////////////////////////////////////////////
// CToolTipCtrl

class CToolInfo : public TOOLINFO
{
public:
/**/    TCHAR m_szText[256];

/**/    operator LPTOOLINFO() { return this; }
/**/    operator LPARAM() { return (LPARAM)this; }

	void Fill(HWND hWnd, UINT nIDTool)
	{
		memset(this, 0, sizeof(TOOLINFO));
		cbSize = sizeof(TOOLINFO);
		if(nIDTool == 0)
		{
			hwnd = ::GetParent(hWnd);
			uFlags = TTF_IDISHWND;
			uId = (UINT_PTR)hWnd;
		}
		else
		{
			hwnd = hWnd;
			uFlags = 0;
			uId = nIDTool;
		}
	}
};

template <class Base>
class CToolTipCtrlT : public Base
{
public:
// Constructors
	CToolTipCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CToolTipCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return TOOLTIPS_CLASS;
	}

	void GetText(LPTOOLINFO lpToolInfo) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_GETTEXT, 0, (LPARAM)&lpToolInfo);
	}
	void GetText(LPTSTR lpstrText, HWND hWnd, UINT nIDTool = 0) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(hWnd != NULL);

//      TOOLINFO ti;
//      FillInToolInfo(ti, hWnd, nIDTool);
		CToolInfo ti;
		ti.Fill(hWnd, nIDTool);
		ti.lpszText = lpstrText;    // should be 256 characters long
		::SendMessage(m_hWnd, TTM_GETTEXT, 0, ti);
	}
	BOOL GetToolInfo(LPTOOLINFO lpToolInfo) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TTM_GETTOOLINFO, 0, (LPARAM)lpToolInfo);
	}
	BOOL GetToolInfo(HWND hWnd, UINT nIDTool, UINT* puFlags, LPRECT lpRect, LPTSTR lpstrText) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(hWnd != NULL);

		TOOLINFO ti;
		FillInToolInfo(ti, hWnd, nIDTool);
		ti.lpszText = lpstrText;
		BOOL bRet = (BOOL)::SendMessage(m_hWnd, TTM_GETTOOLINFO, 0, (LPARAM)&ti);
		if(bRet)
		{
			*puFlags = ti.uFlags;
			memcpy(lpRect, &(ti.rect), sizeof(RECT));
		}
		return bRet;
	}
	void SetToolInfo(LPTOOLINFO lpToolInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_SETTOOLINFO, 0, (LPARAM)lpToolInfo);
	}
	void SetToolRect(LPTOOLINFO lpToolInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_NEWTOOLRECT, 0, (LPARAM)lpToolInfo);
	}
	void SetToolRect(HWND hWnd, UINT nIDTool, LPCRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(hWnd != NULL);
		ATLENSURE(nIDTool != 0);

		TOOLINFO ti;
		FillInToolInfo(ti, hWnd, nIDTool);
		memcpy(&ti.rect, lpRect, sizeof(RECT));
		::SendMessage(m_hWnd, TTM_NEWTOOLRECT, 0, (LPARAM)&ti);
	}
	int GetToolCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TTM_GETTOOLCOUNT, 0, 0L);
	}

// Operations
	void Activate(BOOL bActivate)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_ACTIVATE, bActivate, 0L);
	}
	BOOL AddTool(LPTOOLINFO lpToolInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TTM_ADDTOOL, 0, (LPARAM)lpToolInfo);
	}
	BOOL AddTool(HWND hWnd, LPCTSTR lpszText = LPSTR_TEXTCALLBACK, LPCRECT lpRectTool = NULL, UINT nIDTool = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(hWnd != NULL);
		ATLENSURE(lpszText != NULL);
		// the toolrect and toolid must both be zero or both valid
		ATLENSURE((lpRectTool != NULL && nIDTool != 0) || (lpRectTool == NULL && nIDTool == 0));

		TOOLINFO ti;
		FillInToolInfo(ti, hWnd, nIDTool);
		if(lpRectTool != NULL)
			memcpy(&ti.rect, lpRectTool, sizeof(RECT));
		ti.hinst = _Module.GetResourceInstance();   // needed only if lpszText is from MAKEINTRESOURCE
		ti.lpszText = (LPTSTR)lpszText;
		return (BOOL)::SendMessage(m_hWnd, TTM_ADDTOOL, 0, (LPARAM)&ti);
	}
	BOOL AddTool(HWND hWnd, UINT nIDText, LPCRECT lpRectTool = NULL, UINT nIDTool = 0)
	{
		ATLENSURE(nIDText != 0);
		return AddTool(hWnd, MAKEINTRESOURCE(nIDText), lpRectTool, nIDTool);
	}
	void DelTool(LPTOOLINFO lpToolInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_DELTOOL, 0, (LPARAM)lpToolInfo);
	}
	void DelTool(HWND hWnd, UINT nIDTool = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(hWnd != NULL);

		TOOLINFO ti;
		FillInToolInfo(ti, hWnd, nIDTool);
		::SendMessage(m_hWnd, TTM_DELTOOL, 0, (LPARAM)&ti);
	}
	BOOL HitTest(LPTTHITTESTINFO lpHitTestInfo) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TTM_HITTEST, 0, (LPARAM)lpHitTestInfo);
	}
	BOOL HitTest(HWND hWnd, POINT pt, LPTOOLINFO lpToolInfo) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(hWnd != NULL);
		ATLENSURE(lpToolInfo != NULL);

		TTHITTESTINFO hti;
		memset(&hti, 0, sizeof(hti));
		hti.ti.cbSize = sizeof(TOOLINFO);
		hti.hwnd = hWnd;
		hti.pt.x = pt.x;
		hti.pt.y = pt.y;
		if((BOOL)::SendMessage(m_hWnd, TTM_HITTEST, 0, (LPARAM)&hti))
		{
			memcpy(lpToolInfo, &hti.ti, sizeof(TOOLINFO));
			return TRUE;
		}
		return FALSE;
	}
	void RelayEvent(LPMSG lpMsg)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_RELAYEVENT, 0, (LPARAM)lpMsg);
	}
	void SetDelayTime(UINT nDelay)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_SETDELAYTIME, 0, nDelay);
	}
	void UpdateTipText(LPTOOLINFO lpToolInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_UPDATETIPTEXT, 0, (LPARAM)lpToolInfo);
	}
	void UpdateTipText(LPCTSTR lpszText, HWND hWnd, UINT nIDTool = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(hWnd != NULL);

		TOOLINFO ti;
		FillInToolInfo(ti, hWnd, nIDTool);
		ti.hinst = _Module.GetResourceInstance();
		ti.lpszText = (LPTSTR)lpszText;
		::SendMessage(m_hWnd, TTM_UPDATETIPTEXT, 0, (LPARAM)&ti);
	}
	void UpdateTipText(UINT nIDText, HWND hWnd, UINT nIDTool = 0)
	{
		ATLENSURE(nIDText != 0);
		UpdateTipText(MAKEINTRESOURCE(nIDText), hWnd, nIDTool);
	}

// Implementation
/**/    static void FillInToolInfo(TOOLINFO& ti, HWND hWnd, UINT nIDTool)
	{
		memset(&ti, 0, sizeof(ti));
		ti.cbSize = sizeof(ti);
		if (nIDTool == 0)
		{
			ti.hwnd = ::GetParent(hWnd);
			ti.uFlags = TTF_IDISHWND;
			ti.uId = (UINT)hWnd;
		}
		else
		{
			ti.hwnd = hWnd;
			ti.uFlags = 0;
			ti.uId = nIDTool;
		}
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	int GetDelayTime(DWORD dwType)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TTM_GETDELAYTIME, dwType, 0L);
	}
	void SetDelayTime(DWORD dwType, int nTime)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_SETDELAYTIME, dwType, MAKELPARAM(nTime, 0));
	}
	void GetMargin(LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_GETMARGIN, 0, (LPARAM)lpRect);
	}
	void SetMargin(LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_SETMARGIN, 0, (LPARAM)lpRect);
	}
	int GetMaxTipWidth()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TTM_GETMAXTIPWIDTH, 0, 0L);
	}
	int SetMaxTipWidth(int nWidth)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TTM_SETMAXTIPWIDTH, 0, nWidth);
	}
	COLORREF GetTipBkColor()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, TTM_GETTIPBKCOLOR, 0, 0L);
	}
	void SetTipBkColor(COLORREF clr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_SETTIPBKCOLOR, (WPARAM)clr, 0L);
	}
	COLORREF GetTipTextColor()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, TTM_GETTIPTEXTCOLOR, 0, 0L);
	}
	void SetTipTextColor(COLORREF clr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_SETTIPTEXTCOLOR, (WPARAM)clr, 0L);
	}
	BOOL GetCurrentTool(LPTOOLINFO lpToolInfo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TTM_GETCURRENTTOOL, 0, (LPARAM)lpToolInfo);
	}
	void Pop()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_POP, 0, 0L);
	}
	void TrackActivate(LPTOOLINFO lpToolInfo, BOOL bActivate)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_TRACKACTIVATE, bActivate, (LPARAM)lpToolInfo);
	}
	void TrackPosition(int xPos, int yPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TTM_TRACKPOSITION, 0, MAKELPARAM(xPos, yPos));
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CToolTipCtrlT<CWindow>      CToolTipCtrl;

/////////////////////////////////////////////////////////////////////////////
// CTrackBarCtrl

template <class Base>
class CTrackBarCtrlT : public Base
{
public:
// Constructors
	CTrackBarCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CTrackBarCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return TRACKBAR_CLASS;
	}

	int GetLineSize() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_GETLINESIZE, 0, 0L);
	}
	int SetLineSize(int nSize)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_SETLINESIZE, 0, nSize);
	}
	int GetPageSize() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_GETPAGESIZE, 0, 0L);
	}
	int SetPageSize(int nSize)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_SETPAGESIZE, 0, nSize);
	}
	int GetRangeMax() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_GETRANGEMAX, 0, 0L);
	}
	int GetRangeMin() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_GETRANGEMIN, 0, 0L);
	}
	void GetRange(int& nMin, int& nMax) const
	{
		nMin = GetRangeMin();
		nMax = GetRangeMax();
	}
	void SetRangeMin(int nMin, BOOL bRedraw = FALSE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_SETRANGEMIN, bRedraw, nMin);
	}
	void SetRangeMax(int nMax, BOOL bRedraw = FALSE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_SETRANGEMAX, bRedraw, nMax);
	}
	void SetRange(int nMin, int nMax, BOOL bRedraw = FALSE)
	{
		SetRangeMin(nMin, bRedraw);
		SetRangeMax(nMax, bRedraw);
	}
	int GetSelStart() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, TBM_GETSELSTART, 0, 0L);
	}
	int GetSelEnd() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, TBM_GETSELEND, 0, 0L);
	}
	void GetSelection(int& nMin, int& nMax) const
	{
		nMin = GetSelStart();
		nMax = GetSelEnd();
	}
	void SetSelStart(int nMin)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_SETSELSTART, 0, (LPARAM)nMin);
	}
	void SetSelEnd(int nMax)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_SETSELEND, 0, (LPARAM)nMax);
	}
	void SetSelection(int nMin, int nMax)
	{
		SetSelStart(nMin);
		SetSelEnd(nMin);
	}
	void GetChannelRect(LPRECT lprc) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_GETCHANNELRECT, 0, (LPARAM)lprc);
	}
	void GetThumbRect(LPRECT lprc) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_GETTHUMBRECT, 0, (LPARAM)lprc);
	}
	int GetPos() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_GETPOS, 0, 0L);
	}
	void SetPos(int nPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_SETPOS, TRUE, nPos);
	}
	UINT GetNumTics() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, TBM_GETNUMTICS, 0, 0L);
	}
	DWORD* GetTicArray() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD*)::SendMessage(m_hWnd, TBM_GETPTICS, 0, 0L);
	}
	int GetTic(int nTic) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_GETTIC, nTic, 0L);
	}
	int GetTicPos(int nTic) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_GETTICPOS, nTic, 0L);
	}
	BOOL SetTic(int nTic)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, TBM_SETTIC, 0, nTic);
	}
	void SetTicFreq(int nFreq)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_SETTICFREQ, nFreq, 0L);
	}

// Operations
	void ClearSel(BOOL bRedraw = FALSE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_CLEARSEL, bRedraw, 0L);
	}
	void VerifyPos()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_SETPOS, FALSE, 0L);
	}
	void ClearTics(BOOL bRedraw = FALSE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_CLEARTICS, bRedraw, 0L);
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	HWND GetBuddy(BOOL bLeft = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TBM_GETBUDDY, bLeft, 0L);
	}
	HWND SetBuddy(HWND hWndBuddy, BOOL bLeft = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TBM_SETBUDDY, bLeft, (LPARAM)hWndBuddy);
	}
	HWND GetToolTips()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, TBM_GETTOOLTIPS, 0, 0L);
	}
	void SetToolTips(HWND hWndTT)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, TBM_SETTOOLTIPS, (WPARAM)hWndTT, 0L);
	}
	int SetTipSide(int nSide)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, TBM_SETTIPSIDE, nSide, 0L);
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CTrackBarCtrlT<CWindow>     CTrackBarCtrl;

/////////////////////////////////////////////////////////////////////////////
// CUpDownCtrl

template <class Base>
class CUpDownCtrlT : public Base
{
public:
// Constructors
	CUpDownCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CUpDownCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return UPDOWN_CLASS;
	}

	BOOL SetAccel(int nAccel, UDACCEL* pAccel)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)LOWORD(::SendMessage(m_hWnd, UDM_SETACCEL, nAccel, (LPARAM)pAccel));
	}
	UINT GetAccel(int nAccel, UDACCEL* pAccel) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)LOWORD(::SendMessage(m_hWnd, UDM_GETACCEL, nAccel, (LPARAM)pAccel));
	}
	int SetBase(int nBase)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, UDM_SETBASE, nBase, 0L);
	}
	UINT GetBase() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)LOWORD(::SendMessage(m_hWnd, UDM_GETBASE, 0, 0L));
	}
	HWND SetBuddy(HWND hWndBuddy)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, UDM_SETBUDDY, (WPARAM)hWndBuddy, 0L);
	}
	HWND GetBuddy() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, UDM_GETBUDDY, 0, 0L);
	}
	int SetPos(int nPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)(short)LOWORD(::SendMessage(m_hWnd, UDM_SETPOS, 0, MAKELPARAM(nPos, 0)));
	}
	int GetPos() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, UDM_GETPOS, 0, 0L);
	}
	void SetRange(int nLower, int nUpper)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, UDM_SETRANGE, 0, MAKELPARAM(nUpper, nLower));
	}
	DWORD GetRange() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD)::SendMessage(m_hWnd, UDM_GETRANGE, 0, 0L);
	}
	void GetRange(int& nLower, int& nUpper) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		DWORD dwRet = ::SendMessage(m_hWnd, UDM_GETRANGE, 0, 0L);
		nLower = (int)(short)HIWORD(dwRet);
		nUpper = (int)(short)LOWORD(dwRet);
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	void SetRange32(int nLower, int nUpper)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, UDM_SETRANGE32, nLower, nUpper);
	}
	void GetRange32(int& nLower, int& nUpper) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, UDM_GETRANGE32, (WPARAM)&nLower, (LPARAM)&nUpper);
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CUpDownCtrlT<CWindow>       CUpDownCtrl;

/////////////////////////////////////////////////////////////////////////////
// CProgressBarCtrl

template <class Base>
class CProgressBarCtrlT : public Base
{
public:
// Constructors
	CProgressBarCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CProgressBarCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return PROGRESS_CLASS;
	}

	DWORD SetRange(int nLower, int nUpper)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD)::SendMessage(m_hWnd, PBM_SETRANGE, 0, MAKELPARAM(nLower, nUpper));
	}
	int SetPos(int nPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)LOWORD(::SendMessage(m_hWnd, PBM_SETPOS, nPos, 0L));
	}
	int OffsetPos(int nPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)LOWORD(::SendMessage(m_hWnd, PBM_DELTAPOS, nPos, 0L));
	}
	int SetStep(int nStep)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)LOWORD(::SendMessage(m_hWnd, PBM_SETSTEP, nStep, 0L));
	}

// Operations
	int StepIt()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int) LOWORD(::SendMessage(m_hWnd, PBM_STEPIT, 0, 0L));
	}

	// new common control support
#if (_WIN32_IE >= 0x0400)
	UINT GetPos()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, PBM_GETPOS, 0, 0L);
	}
	void GetRange(PPBRANGE pPBRange)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(pPBRange != NULL);
		::SendMessage(m_hWnd, PBM_GETRANGE, TRUE, (LPARAM)pPBRange);
	}
	int GetRangeLimit(BOOL bLimit)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, PBM_GETRANGE, bLimit, (LPARAM)NULL);
	}
	DWORD SetRange32(int nMin, int nMax)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD)::SendMessage(m_hWnd, PBM_SETRANGE32, nMin, nMax);
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CProgressBarCtrlT<CWindow>  CProgressBarCtrl;

/////////////////////////////////////////////////////////////////////////////
// CHotKeyCtrl

template <class Base>
class CHotKeyCtrlT : public Base
{
public:
// Constructors
	CHotKeyCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CHotKeyCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return HOTKEY_CLASS;
	}

	void SetHotKey(WORD wVirtualKeyCode, WORD wModifiers)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, HKM_SETHOTKEY, MAKEWORD(wVirtualKeyCode, wModifiers), 0L);
	}
	DWORD GetHotKey() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, HKM_GETHOTKEY, 0, 0L);
	}
	void GetHotKey(WORD &wVirtualKeyCode, WORD &wModifiers) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		DWORD dw = ::SendMessage(m_hWnd, HKM_GETHOTKEY, 0, 0L);
		wVirtualKeyCode = LOBYTE(LOWORD(dw));
		wModifiers = HIBYTE(LOWORD(dw));
	}

// Operations
	void SetRules(WORD wInvalidComb, WORD wModifiers)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, HKM_SETRULES, wInvalidComb, MAKELPARAM(wModifiers, 0));
	}
};

typedef CHotKeyCtrlT<CWindow>       CHotKeyCtrl;

/////////////////////////////////////////////////////////////////////////////
// CAnimateCtrl

template <class Base>
class CAnimateCtrlT : public Base
{
public:
// Constructors
	CAnimateCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CAnimateCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Operations
	static LPCTSTR GetWndClassName()
	{
		return ANIMATE_CLASS;
	}

	BOOL Open(LPCTSTR lpszFileName)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, ACM_OPEN, 0, (LPARAM)lpszFileName);
	}
	BOOL Open(UINT nID)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, ACM_OPEN, 0, (LPARAM)MAKEINTRESOURCE(nID));
	}
	BOOL Play(UINT nFrom, UINT nTo, UINT nRep)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, ACM_PLAY, nRep, MAKELPARAM(nFrom, nTo));
	}
	BOOL Stop()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, ACM_STOP, 0, 0L);
	}
	BOOL Close()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, ACM_OPEN, 0, 0L);
	}
	BOOL Seek(UINT nTo)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, ACM_PLAY, 0, MAKELPARAM(nTo, nTo));
	}
};

typedef CAnimateCtrlT<CWindow>      CAnimateCtrl;

/////////////////////////////////////////////////////////////////////////////
// CRichEditCtrl

#include <richedit.h>
#include <richole.h>

#ifdef _UNICODE
#if (_RICHEDIT_VER == 0x0100)
#undef RICHEDIT_CLASS
#define RICHEDIT_CLASS  L"RICHEDIT"
#endif //(_RICHEDIT_VER == 0x0100)
#endif //_UNICODE

template <class Base>
class CRichEditCtrlT : public Base
{
public:
// Constructors
	CRichEditCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CRichEditCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return RICHEDIT_CLASS;
	}

	BOOL CanUndo() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_CANUNDO, 0, 0L);
	}
	int GetLineCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_GETLINECOUNT, 0, 0L);
	}
	BOOL GetModify() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_GETMODIFY, 0, 0L);
	}
	void SetModify(BOOL bModified = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETMODIFY, bModified, 0L);
	}
	void GetRect(LPRECT lpRect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_GETRECT, 0, (LPARAM)lpRect);
	}
	POINT GetCharPos(long lChar) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		POINT pt;
		::SendMessage(m_hWnd, EM_POSFROMCHAR, (WPARAM)&pt, (LPARAM)lChar);
		return pt;
	}
	UINT SetOptions(WORD wOp, DWORD dwFlags)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, EM_SETOPTIONS, (WPARAM)wOp, (LPARAM)dwFlags);
	}

	// NOTE: first word in lpszBuffer must contain the size of the buffer!
	int GetLine(int nIndex, LPTSTR lpszBuffer) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
	}
	int GetLine(int nIndex, LPTSTR lpszBuffer, int nMaxLength) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		*(LPINT)lpszBuffer = nMaxLength;
		return (int)::SendMessage(m_hWnd, EM_GETLINE, nIndex, (LPARAM)lpszBuffer);
	}

	BOOL CanPaste(UINT nFormat = 0) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_CANPASTE, nFormat, 0L);
	}
	void GetSel(long& nStartChar, long& nEndChar) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		CHARRANGE cr;
		::SendMessage(m_hWnd, EM_EXGETSEL, 0, (LPARAM)&cr);
		nStartChar = cr.cpMin;
		nEndChar = cr.cpMax;
	}
	void GetSel(CHARRANGE &cr) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_EXGETSEL, 0, (LPARAM)&cr);
	}
	void LimitText(long nChars = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_EXLIMITTEXT, 0, nChars);
	}
	long LineFromChar(long nIndex) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, EM_EXLINEFROMCHAR, 0, nIndex);
	}
	int SetSel(long nStartChar, long nEndChar)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		CHARRANGE cr;
		cr.cpMin = nStartChar;
		cr.cpMax = nEndChar;
		return (int)::SendMessage(m_hWnd, EM_EXSETSEL, 0, (LPARAM)&cr);
	}
	int SetSel(CHARRANGE &cr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_EXSETSEL, 0, (LPARAM)&cr);
	}
	DWORD GetDefaultCharFormat(CHARFORMAT &cf) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		cf.cbSize = sizeof(CHARFORMAT);
		return (DWORD)::SendMessage(m_hWnd, EM_GETCHARFORMAT, 0, (LPARAM)&cf);
	}
	DWORD GetSelectionCharFormat(CHARFORMAT &cf) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		cf.cbSize = sizeof(CHARFORMAT);
		return (DWORD)::SendMessage(m_hWnd, EM_GETCHARFORMAT, 1, (LPARAM)&cf);
	}
	long GetEventMask() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, EM_GETEVENTMASK, 0, 0L);
	}
	long GetLimitText() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, EM_GETLIMITTEXT, 0, 0L);
	}
	DWORD GetParaFormat(PARAFORMAT &pf) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		pf.cbSize = sizeof(PARAFORMAT);
		return (DWORD)::SendMessage(m_hWnd, EM_GETPARAFORMAT, 0, (LPARAM)&pf);
	}
	// richedit EM_GETSELTEXT is ANSI
	long GetSelText(LPSTR lpBuf) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, EM_GETSELTEXT, 0, (LPARAM)lpBuf);
	}
#ifndef _ATL_NO_COM
	BOOL GetSelTextBSTR(BSTR& bstrText) const
	{
		
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(bstrText == NULL);

		CHARRANGE cr;
		cr.cpMin = cr.cpMax = 0;
		::SendMessage(m_hWnd, EM_EXGETSEL, 0, (LPARAM)&cr);
		LPSTR lpstrText = (char*)_alloca((cr.cpMax - cr.cpMin + 1) * 2);
		lpstrText[0] = 0;
		if(::SendMessage(m_hWnd, EM_GETSELTEXT, 0, (LPARAM)lpstrText) == 0)
			return FALSE;

		bstrText = ::SysAllocString(CA2W(lpstrText));
		return (bstrText != NULL) ? TRUE : FALSE;
	}
#endif //!_ATL_NO_COM
	WORD GetSelectionType() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (WORD)::SendMessage(m_hWnd, EM_SELECTIONTYPE, 0, 0L);
	}
	COLORREF SetBackgroundColor(BOOL bSysColor, COLORREF cr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, EM_SETBKGNDCOLOR, bSysColor, cr);
	}
	BOOL SetDefaultCharFormat(CHARFORMAT &cf)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		cf.cbSize = sizeof(CHARFORMAT);
		return (BOOL)::SendMessage(m_hWnd, EM_SETCHARFORMAT, 0, (LPARAM)&cf);
	}
	BOOL SetSelectionCharFormat(CHARFORMAT &cf)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		cf.cbSize = sizeof(CHARFORMAT);
		return (BOOL)::SendMessage(m_hWnd, EM_SETCHARFORMAT, SCF_SELECTION, (LPARAM)&cf);
	}
	BOOL SetWordCharFormat(CHARFORMAT &cf)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		cf.cbSize = sizeof(CHARFORMAT);
		return (BOOL)::SendMessage(m_hWnd, EM_SETCHARFORMAT, SCF_SELECTION|SCF_WORD, (LPARAM)&cf);
	}
	DWORD SetEventMask(DWORD dwEventMask)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (DWORD)::SendMessage(m_hWnd, EM_SETEVENTMASK, 0, dwEventMask);
	}
	BOOL SetParaFormat(PARAFORMAT &pf)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		pf.cbSize = sizeof(PARAFORMAT);
		return (BOOL)::SendMessage(m_hWnd, EM_SETPARAFORMAT, 0, (LPARAM)&pf);
	}
	BOOL SetTargetDevice(HDC hDC, long lLineWidth)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_SETTARGETDEVICE, (WPARAM)hDC, lLineWidth);
	}
	long GetTextLength() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, WM_GETTEXTLENGTH, 0, 0L);
	}
	BOOL SetReadOnly(BOOL bReadOnly = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_SETREADONLY, bReadOnly, 0L);
	}
	int GetFirstVisibleLine() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_GETFIRSTVISIBLELINE, 0, 0L);
	}

// Operations
	void EmptyUndoBuffer()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_EMPTYUNDOBUFFER, 0, 0L);
	}

	int LineIndex(int nLine = -1) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_LINEINDEX, nLine, 0L);
	}
	int LineLength(int nLine = -1) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, EM_LINELENGTH, nLine, 0L);
	}
	BOOL LineScroll(int nLines, int nChars = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_LINESCROLL, nChars, nLines);
	}
	void ReplaceSel(LPCTSTR lpszNewText, BOOL bCanUndo = FALSE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_REPLACESEL, (WPARAM) bCanUndo, (LPARAM)lpszNewText);
	}
	void SetRect(LPCRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SETRECT, 0, (LPARAM)lpRect);
	}

	BOOL DisplayBand(LPRECT pDisplayRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_DISPLAYBAND, 0, (LPARAM)pDisplayRect);
	}
	long FindText(DWORD dwFlags, FINDTEXTEX* pFindText) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, EM_FINDTEXTEX, dwFlags, (LPARAM)pFindText);
	}
	long FormatRange(FORMATRANGE* pfr, BOOL bDisplay = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, EM_FORMATRANGE, (WPARAM)bDisplay, (LPARAM)pfr);
	}
	void HideSelection(BOOL bHide, BOOL bPerm)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_HIDESELECTION, bHide, bPerm);
	}
	void PasteSpecial(UINT nClipFormat, DWORD dvAspect = 0, HMETAFILE hMF = 0)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		REPASTESPECIAL reps;
		reps.dwAspect = dvAspect;
		reps.dwParam = (DWORD)hMF;
		::SendMessage(m_hWnd, EM_PASTESPECIAL, nClipFormat, (LPARAM)&reps);
	}
	void RequestResize()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_REQUESTRESIZE, 0, 0L);
	}
	long StreamIn(int nFormat, EDITSTREAM& es)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, EM_STREAMIN, nFormat, (LPARAM)&es);
	}
	long StreamOut(int nFormat, EDITSTREAM& es)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (long)::SendMessage(m_hWnd, EM_STREAMOUT, nFormat, (LPARAM)&es);
	}

	// Additional operations
	void ScrollCaret()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, EM_SCROLLCARET, 0, 0L);
	}
	int InsertText(long nInsertAfterChar, LPCTSTR lpstrText, BOOL bCanUndo = FALSE)
	{
		int nRet = SetSel(nInsertAfterChar, nInsertAfterChar);
		ReplaceSel(lpstrText, bCanUndo);
		return nRet;
	}
	int AppendText(LPCTSTR lpstrText, BOOL bCanUndo = FALSE)
	{
		return InsertText(GetWindowTextLength(), lpstrText, bCanUndo);
	}

	// Clipboard operations
	BOOL Undo()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_UNDO, 0, 0L);
	}
	void Clear()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_CLEAR, 0, 0L);
	}
	void Copy()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_COPY, 0, 0L);
	}
	void Cut()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_CUT, 0, 0L);
	}
	void Paste()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, WM_PASTE, 0, 0L);
	}

// OLE support
	IRichEditOle* GetIRichEditOle() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		IRichEditOle *pRichItem = NULL;
		::SendMessage(m_hWnd, EM_GETOLEINTERFACE, 0, (LPARAM)&pRichItem);
		return pRichItem;
	}
	BOOL SetOLECallback(IRichEditOleCallback* pCallback)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, EM_SETOLECALLBACK, 0, (LPARAM)pCallback);
	}
};

typedef CRichEditCtrlT<CWindow>     CRichEditCtrl;

/////////////////////////////////////////////////////////////////////////////
// CDragListBox

template <class Base>
class CDragListBoxT : public CListBoxT< Base >
{
public:
// Constructors
	CDragListBoxT(HWND hWnd = NULL) : CListBoxT< Base >(hWnd) { }

	CDragListBoxT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Operations
	BOOL MakeDragList()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(!(GetStyle() & LBS_MULTIPLESEL));
		BOOL bRet = ::MakeDragList(m_hWnd);
		UINT& uMsg = GetDragListMessage();
		if(uMsg == 0)
		{
/*?*/           ::EnterCriticalSection(&_Module.m_csWindowCreate);
			if(uMsg == 0)
				uMsg = ::RegisterWindowMessage(DRAGLISTMSGSTRING);
/*?*/           ::LeaveCriticalSection(&_Module.m_csWindowCreate);
		}
		ATLENSURE(uMsg != 0);
		return bRet;
	}

	int LBItemFromPt(POINT pt, BOOL bAutoScroll = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::LBItemFromPt(m_hWnd, pt, bAutoScroll);
	}

	void DrawInsert(int nItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::DrawInsert(GetParent(), m_hWnd, nItem);
	}

	static UINT& GetDragListMessage()
	{
		static UINT m_uDragListMessage = 0;
		return m_uDragListMessage;
	}
};

typedef CDragListBoxT<CWindow>      CDragListBox;

template <class T>
class CDragListNotifyImpl
{
public:
	BEGIN_MSG_MAP(CDragListNotifyImpl< T >)
		MESSAGE_HANDLER(CDragList::GetDragListMessage(), OnDragListNotify)
	END_MSG_MAP()

	LRESULT OnDragListNotify(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		if(uMsg == 0)   // message not registered
		{
			bHandled = FALSE;
			return 1;
		}
		T* pT = static_cast<T*>(this);
		LPDRAGLISTINFO lpDragListInfo = (LPDRAGLISTINFO)lParam;
		LRESULT lRet = 0;
		switch(lpDragListInfo->uNotification)
		{
		case DL_BEGINDRAG:
			lRet = (LPARAM)pT->OnBeginDrag((int)wParam, lpDragListInfo->hWnd, lpDragListInfo->ptCursor);
			break;
		case DL_CANCELDRAG:
			pT->OnCancelDrag((int)wParam, lpDragListInfo->hWnd, lpDragListInfo->ptCursor);
			break;
		case DL_DRAGGING:
			lRet = (LPARAM)pT->OnDragging((int)wParam, lpDragListInfo->hWnd, lpDragListInfo->ptCursor);
			break;
		case DL_DROPPED:
			pT->OnDropped((int)wParam, lpDragListInfo->hWnd, lpDragListInfo->ptCursor);
			break;
		default:
			ATLTRACE2(atlTraceWindowing, 0, _T("Unknown DragListBox notification\n"));
			bHandled = FALSE;   // don't handle it
			break;
		}
		return lRet;
	}

	BOOL OnBeginDrag(int nCtlID, HWND hWndDragList, POINT ptCursor)
	{
		return TRUE;    // allow dragging
	}
	void OnCancelDrag(int nCtlID, HWND hWndDragList, POINT ptCursor)
	{
		// nothing to do
	}
	int OnDragging(int nCtlID, HWND hWndDragList, POINT ptCursor)
	{
		return 0;   // don't change cursor
	}
	void OnDropped(int nCtlID, HWND hWndDragList, POINT ptCursor)
	{
		// nothing to do
	}
};


// --- New Windows Common Controls ---

/////////////////////////////////////////////////////////////////////////////
// CReBarCtrl

template <class Base>
class CReBarCtrlT : public Base
{
public:
// Constructors
	CReBarCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CReBarCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return REBARCLASSNAME;
	}

#if (_WIN32_IE >= 0x0400)
	COLORREF GetTextColor() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, RB_GETTEXTCOLOR, 0, 0L);
	}
	COLORREF SetTextColor(COLORREF clr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, RB_SETTEXTCOLOR, 0, (LPARAM)clr);
	}
	COLORREF GetBkColor() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, RB_GETBKCOLOR, 0, 0L);
	}
	COLORREF SetBkColor(COLORREF clr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, RB_SETBKCOLOR, 0, (LPARAM)clr);
	}
#endif //(_WIN32_IE >= 0x0400)
	UINT GetBandCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, RB_GETBANDCOUNT, 0, 0L);
	}
	BOOL GetBandInfo(int nBand, LPREBARBANDINFO lprbbi) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_GETBANDINFO, nBand, (LPARAM)lprbbi);
	}
	BOOL SetBandInfo(int nBand, LPREBARBANDINFO lprbbi)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_SETBANDINFO, nBand, (LPARAM)lprbbi);
	}
	BOOL GetBarInfo(LPREBARINFO lprbi) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_GETBARINFO, 0, (LPARAM)lprbi);
	}
	BOOL SetBarInfo(LPREBARINFO lprbi)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_SETBARINFO, 0, (LPARAM)lprbi);
	}
#if (_WIN32_IE >= 0x0400)
	UINT GetBarHeight() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, RB_GETBARHEIGHT, 0, 0L);
	}
	BOOL GetRect(int nBand, LPRECT lpRect) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_GETRECT, nBand, (LPARAM)lpRect);
	}
#endif //(_WIN32_IE >= 0x0400)
	UINT GetRowCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, RB_GETROWCOUNT, 0, 0L);
	}
	UINT GetRowHeight(int nBand) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (UINT)::SendMessage(m_hWnd, RB_GETROWHEIGHT, nBand, 0L);
	}
#if (_WIN32_IE >= 0x0400)
	HWND GetToolTips() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, RB_GETTOOLTIPS, 0, 0L);
	}
	void SetToolTips(HWND hwndToolTip)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_SETTOOLTIPS, (WPARAM)hwndToolTip, 0L);
	}
#endif //(_WIN32_IE >= 0x0400)

// Operations
#if (_WIN32_IE >= 0x0400)
	void BeginDrag(int nBand, DWORD dwPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_BEGINDRAG, nBand, dwPos);
	}
	void BeginDrag(int nBand, int xPos, int yPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_BEGINDRAG, nBand, MAKELPARAM(xPos, yPos));
	}
	void EndDrag()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_ENDDRAG, 0, 0L);
	}
	void DragMove(DWORD dwPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_DRAGMOVE, 0, dwPos);
	}
	void DragMove(int xPos, int yPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_DRAGMOVE, 0, MAKELPARAM(xPos, yPos));
	}
	void GetDropTarget(IDropTarget** ppDropTarget) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_GETDROPTARGET, 0, (LPARAM)ppDropTarget);
	}
#endif //(_WIN32_IE >= 0x0400)
	BOOL InsertBand(int nBand, LPREBARBANDINFO lprbbi)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		lprbbi->cbSize = sizeof(REBARBANDINFO);
		return (BOOL)::SendMessage(m_hWnd, RB_INSERTBAND, nBand, (LPARAM)lprbbi);
	}
	BOOL DeleteBand(int nBand)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_DELETEBAND, nBand, 0L);
	}
#if (_WIN32_IE >= 0x0400)
	void MaximizeBand(int nBand)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_MAXIMIZEBAND, nBand, 0L);
	}
	void MinimizeBand(int nBand)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, RB_MINIMIZEBAND, nBand, 0L);
	}
	BOOL SizeToRect(LPRECT lpRect)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, RB_SIZETORECT, 0, (LPARAM)lpRect);
	}
#endif //(_WIN32_IE >= 0x0400)
	HWND SetNotifyWnd(HWND hWnd)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, RB_SETPARENT, (WPARAM)hWnd, 0L);
	}
#if (_WIN32_IE >= 0x0400)
	int IdToIndex(UINT uBandID) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, RB_IDTOINDEX, uBandID, 0L);
	}
	int HitTest(LPRBHITTESTINFO lprbht) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, RB_HITTEST, 0, (LPARAM)lprbht);
	}
#endif //(_WIN32_IE >= 0x0400)
};

typedef CReBarCtrlT<CWindow>        CReBarCtrl;

/////////////////////////////////////////////////////////////////////////////
// CComboBoxEx

template <class Base>
class CComboBoxExT : public CComboBoxT< Base >
{
public:
// Constructors
	CComboBoxExT(HWND hWnd = NULL) : CComboBoxT< Base >(hWnd) { }

	CComboBoxExT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return WC_COMBOBOXEX;
	}

#if (_WIN32_IE >= 0x0400)
	DWORD GetExtendedStyle() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, CBEM_GETEXTENDEDSTYLE, 0, 0L);
	}
	DWORD SetExtendedStyle(DWORD dwExMask, DWORD dwExStyle)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, CBEM_SETEXTENDEDSTYLE, dwExMask, dwExStyle);
	}
#endif //(_WIN32_IE >= 0x0400)
	HIMAGELIST GetImageList() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, CBEM_GETIMAGELIST, 0, 0L);
	}
	HIMAGELIST SetImageList(HIMAGELIST hImageList)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HIMAGELIST)::SendMessage(m_hWnd, CBEM_SETIMAGELIST, 0, (LPARAM)hImageList);
	}

// Operations
	int InsertItem(const COMBOBOXEXITEM FAR* lpcCBItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CBEM_INSERTITEM, 0, (LPARAM)lpcCBItem);
	}
	int DeleteItem(int nIndex)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, CBEM_DELETEITEM, nIndex, 0L);
	}
	BOOL GetItem(PCOMBOBOXEXITEM pCBItem) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, CBEM_GETITEM, 0, (LPARAM)pCBItem);
	}
	BOOL SetItem(const COMBOBOXEXITEM FAR* lpcCBItem)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, CBEM_SETITEM, 0, (LPARAM)lpcCBItem);
	}
	HWND GetComboCtrl() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, CBEM_GETCOMBOCONTROL, 0, 0L);
	}
	HWND GetEditCtrl() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, CBEM_GETEDITCONTROL, 0, 0L);
	}
	BOOL HasEditChanged() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, CBEM_HASEDITCHANGED, 0, 0L);
	}
};

typedef CComboBoxExT<CWindow>       CComboBoxEx;

/////////////////////////////////////////////////////////////////////////////
// CDateTimePickerCtrl

template <class Base>
class CDateTimePickerCtrlT : public Base
{
public:
// Constructors
	CDateTimePickerCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CDateTimePickerCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Operations
	static LPCTSTR GetWndClassName()
	{
		return DATETIMEPICK_CLASS;
	}

	BOOL SetFormat(LPTSTR lpszFormat)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, DTM_SETFORMAT, 0, (LPARAM)lpszFormat);
	}
	COLORREF GetMonthCalColor(int nColorType) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, DTM_GETMCCOLOR, nColorType, 0L);
	}
	COLORREF SetMonthCalColor(int nColorType, COLORREF clr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, DTM_SETMCCOLOR, nColorType, clr);
	}
#if (_WIN32_IE >= 0x0400)
	HFONT GetMonthCalFont() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HFONT)::SendMessage(m_hWnd, DTM_GETMCFONT, 0, 0L);
	}
	void SetMonthCalFont(HFONT hFont, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, DTM_SETMCFONT, (WPARAM)hFont, MAKELPARAM(bRedraw, 0));
	}
#endif //(_WIN32_IE >= 0x0400)
	DWORD GetRange(LPSYSTEMTIME lpSysTimeArray) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, DTM_GETRANGE, 0, (LPARAM)lpSysTimeArray);
	}
	BOOL SetRange(DWORD dwFlags, LPSYSTEMTIME lpSysTimeArray)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, DTM_SETRANGE, dwFlags, (LPARAM)lpSysTimeArray);
	}
	DWORD GetSystemTime(LPSYSTEMTIME lpSysTime) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, DTM_GETSYSTEMTIME, 0, (LPARAM)lpSysTime);
	}
	BOOL SetSystemTime(DWORD dwFlags, LPSYSTEMTIME lpSysTime)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, DTM_SETSYSTEMTIME, dwFlags, (LPARAM)lpSysTime);
	}
	HWND GetMonthCal() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (HWND)::SendMessage(m_hWnd, DTM_GETMONTHCAL, 0, 0L);
	}
};

typedef CDateTimePickerCtrlT<CWindow>       CDateTimePickerCtrl;

/////////////////////////////////////////////////////////////////////////////
// CMonthCalendarCtrl

template <class Base>
class CMonthCalendarCtrlT : public Base
{
public:
// Constructors
	CMonthCalendarCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CMonthCalendarCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return MONTHCAL_CLASS;
	}

	COLORREF GetColor(int nColorType) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, MCM_GETCOLOR, nColorType, 0L);
	}
	COLORREF SetColor(int nColorType, COLORREF clr)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, MCM_SETCOLOR, nColorType, clr);
	}
	BOOL GetCurSel(LPSYSTEMTIME lpSysTime) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_GETCURSEL, 0, (LPARAM)lpSysTime);
	}
	BOOL SetCurSel(LPSYSTEMTIME lpSysTime)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_SETCURSEL, 0, (LPARAM)lpSysTime);
	}
	int GetFirstDayOfWeek(BOOL* pbLocaleVal = NULL) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		DWORD dwRet = ::SendMessage(m_hWnd, MCM_GETFIRSTDAYOFWEEK, 0, 0L);
		if(pbLocaleVal != NULL)
			*pbLocaleVal = HIWORD(dwRet);
		return (int)LOWORD(dwRet);
	}
	int SetFirstDayOfWeek(int nDay, BOOL* pbLocaleVal = NULL)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		DWORD dwRet = ::SendMessage(m_hWnd, MCM_SETFIRSTDAYOFWEEK, 0, nDay);
		if(pbLocaleVal != NULL)
			*pbLocaleVal = HIWORD(dwRet);
		return (int)LOWORD(dwRet);
	}
	int GetMaxSelCount() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, MCM_GETMAXSELCOUNT, 0, 0L);
	}
	BOOL SetMaxSelCount(int nMax)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_SETMAXSELCOUNT, nMax, 0L);
	}
	int GetMonthDelta() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, MCM_GETMONTHDELTA, 0, 0L);
	}
	int SetMonthDelta(int nDelta)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, MCM_SETMONTHDELTA, nDelta, 0L);
	}
	DWORD GetRange(LPSYSTEMTIME lprgSysTimeArray) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, MCM_GETRANGE, 0, (LPARAM)lprgSysTimeArray);
	}
	BOOL SetRange(DWORD dwFlags, LPSYSTEMTIME lprgSysTimeArray)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_SETRANGE, dwFlags, (LPARAM)lprgSysTimeArray);
	}
	BOOL GetSelRange(LPSYSTEMTIME lprgSysTimeArray) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_GETSELRANGE, 0, (LPARAM)lprgSysTimeArray);
	}
	BOOL SetSelRange(LPSYSTEMTIME lprgSysTimeArray)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_SETSELRANGE, 0, (LPARAM)lprgSysTimeArray);
	}
	BOOL GetToday(LPSYSTEMTIME lpSysTime) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_GETTODAY, 0, (LPARAM)lpSysTime);
	}
	void SetToday(LPSYSTEMTIME lpSysTime)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, MCM_SETTODAY, 0, (LPARAM)lpSysTime);
	}
	BOOL GetMinReqRect(LPRECT lpRectInfo) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_GETMINREQRECT, 0, (LPARAM)lpRectInfo);
	}

// Operations
	int GetMonthRange(DWORD dwFlags, LPSYSTEMTIME lprgSysTimeArray) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, MCM_GETMONTHRANGE, dwFlags, (LPARAM)lprgSysTimeArray);
	}
	BOOL SetDayState(int nMonths, LPMONTHDAYSTATE lpDayStateArray)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, MCM_SETDAYSTATE, nMonths, (LPARAM)lpDayStateArray);
	}
	DWORD HitTest(PMCHITTESTINFO pMCHitTest) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::SendMessage(m_hWnd, MCM_HITTEST, 0, (LPARAM)pMCHitTest);
	}
};

typedef CMonthCalendarCtrlT<CWindow>        CMonthCalendarCtrl;

/////////////////////////////////////////////////////////////////////////////
// CFlatScrollBar

#if (_WIN32_IE >= 0x0400)

template <class Base>
class CFlatScrollBarT : public Base
{
public:
// Constructors
	CFlatScrollBarT(HWND hWnd = NULL) : Base(hWnd) { }

	CFlatScrollBarT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

// Initialization
	BOOL FlatSB_Initialize()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::InitializeFlatSB(m_hWnd);
	}
	HRESULT FlatSB_Uninitialize()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::UninitializeFlatSB(m_hWnd);
	}

// Attributes
	BOOL FlatSB_GetScrollProp(UINT uIndex, LPINT lpnValue) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_GetScrollProp(m_hWnd, uIndex, lpnValue);
	}
	BOOL FlatSB_SetScrollProp(UINT uIndex, int nValue, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_SetScrollProp(m_hWnd, uIndex, nValue, bRedraw);
	}

	int FlatSB_GetScrollPos(int nBar) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_GetScrollPos(m_hWnd, nBar);
	}

	int FlatSB_SetScrollPos(int nBar, int nPos, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_SetScrollPos(m_hWnd, nBar, nPos, bRedraw);
	}

	BOOL FlatSB_GetScrollRange(int nBar, LPINT lpMinPos, LPINT lpMaxPos) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_GetScrollRange(m_hWnd, nBar, lpMinPos, lpMaxPos);
	}

	BOOL FlatSB_SetScrollRange(int nBar, int nMinPos, int nMaxPos, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_SetScrollRange(m_hWnd, nBar, nMinPos, nMaxPos, bRedraw);
	}

	BOOL FlatSB_GetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_GetScrollInfo(m_hWnd, nBar, lpScrollInfo);
	}

	int FlatSB_SetScrollInfo(int nBar, LPSCROLLINFO lpScrollInfo, BOOL bRedraw = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_SetScrollInfo(m_hWnd, nBar, lpScrollInfo, bRedraw);
	}

// Operations
	BOOL FlatSB_ShowScrollBar(UINT nBar, BOOL bShow = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_ShowScrollBar(m_hWnd, nBar, bShow);
	}

	BOOL FlatSB_EnableScrollBar(UINT uSBFlags, UINT uArrowFlags = ESB_ENABLE_BOTH)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return ::FlatSB_EnableScrollBar(m_hWnd, uSBFlags, uArrowFlags);
	}
};

typedef CFlatScrollBarT<CWindow>    CFlatScrollBar;

#endif //(_WIN32_IE >= 0x0400)

/////////////////////////////////////////////////////////////////////////////
// CIPAddressCtrl

#if (_WIN32_IE >= 0x0400)

template <class Base>
class CIPAddressCtrlT : public Base
{
public:
// Constructors
	CIPAddressCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CIPAddressCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Atteributes
	static LPCTSTR GetWndClassName()
	{
		return WC_IPADDRESS;
	}

	BOOL IsBlank() const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (BOOL)::SendMessage(m_hWnd, IPM_ISBLANK, 0, 0L);
	}
	int GetAddress(LPDWORD lpdwAddress) const
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, IPM_GETADDRESS, 0, (LPARAM)lpdwAddress);
	}
	void SetAddress(DWORD dwAddress)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, IPM_SETADDRESS, 0, dwAddress);
	}
	void ClearAddress()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, IPM_CLEARADDRESS, 0, 0L);
	}
	void SetRange(int nField, WORD wRange)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, IPM_SETRANGE, nField, wRange);
	}
	void SetRange(int nField, BYTE nMin, BYTE nMax)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, IPM_SETRANGE, nField, MAKEIPRANGE(nMin, nMax));
	}
	void SetFocus(int nField)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, IPM_SETFOCUS, nField, 0L);
	}
};

typedef CIPAddressCtrlT<CWindow>        CIPAddressCtrl;

#endif //(_WIN32_IE >= 0x0400)

/////////////////////////////////////////////////////////////////////////////
// CPagerCtrl

#if (_WIN32_IE >= 0x0400)

template <class Base>
class CPagerCtrlT : public Base
{
public:
// Constructors
	CPagerCtrlT(HWND hWnd = NULL) : Base(hWnd) { }

	CPagerCtrlT< Base >& operator=(HWND hWnd)
	{
		m_hWnd = hWnd;
		return *this;
	}

	HWND Create(HWND hWndParent, RECT& rcPos, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			UINT nID = 0, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, rcPos, szWindowName, dwStyle, dwExStyle, nID, lpCreateParam);
	}
	HWND Create(HWND hWndParent, LPRECT lpRect = NULL, LPCTSTR szWindowName = NULL,
			DWORD dwStyle = 0, DWORD dwExStyle = 0,
			HMENU hMenu = NULL, LPVOID lpCreateParam = NULL)
	{
		return CWindow::Create(GetWndClassName(), hWndParent, lpRect, szWindowName, dwStyle, dwExStyle, hMenu, lpCreateParam);
	}

// Attributes
	static LPCTSTR GetWndClassName()
	{
		return WC_PAGESCROLLER;
	}

	int GetButtonSize()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, PGM_GETBUTTONSIZE, 0, 0L);
	}
	int SetButtonSize(int nButtonSize)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, PGM_SETBUTTONSIZE, 0, nButtonSize);
	}
	DWORD GetButtonState(int nButton)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(nButton == PGB_TOPORLEFT || nButton == PGB_BOTTOMORRIGHT);
		return (DWORD)::SendMessage(m_hWnd, PGM_GETBUTTONSTATE, 0, nButton);
	}
	COLORREF GetBkColor()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, PGM_GETBKCOLOR, 0, 0L);
	}
	COLORREF SetBkColor(COLORREF clrBk)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (COLORREF)::SendMessage(m_hWnd, PGM_SETBKCOLOR, 0, (LPARAM)clrBk);
	}
	int GetBorder()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, PGM_GETBORDER, 0, 0L);
	}
	int SetBorder(int nBorderSize)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, PGM_SETBORDER, 0, nBorderSize);
	}
	int GetPos()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, PGM_GETPOS, 0, 0L);
	}
	int SetPos(int nPos)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		return (int)::SendMessage(m_hWnd, PGM_SETPOS, 0, nPos);
	}

// Operations
	void SetChild(HWND hWndChild)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, PGM_SETCHILD, 0, (LPARAM)hWndChild);
	}
	void ForwardMouse(BOOL bForward = TRUE)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, PGM_FORWARDMOUSE, bForward, 0L);
	}
	void RecalcSize()
	{
		ATLENSURE(::IsWindow(m_hWnd));
		::SendMessage(m_hWnd, PGM_RECALCSIZE, 0, 0L);
	}
	void GetDropTarget(IDropTarget** ppDropTarget)
	{
		ATLENSURE(::IsWindow(m_hWnd));
		ATLENSURE(ppDropTarget != NULL);
		::SendMessage(m_hWnd, PGM_GETDROPTARGET, 0, (LPARAM)ppDropTarget);
	}
};

typedef CPagerCtrlT<CWindow>        CPagerCtrl;

#endif //(_WIN32_IE >= 0x0400)

/////////////////////////////////////////////////////////////////////////////
// CCustomDraw - MI class for custom-draw support

template <class T>
class CCustomDraw
{
public:
	BEGIN_MSG_MAP(CCustomDraw< T >)
		NOTIFY_CODE_HANDLER(NM_CUSTOMDRAW, OnCustomDraw)
	ALT_MSG_MAP(1)
		if(uMsg == OCM_NOTIFY && NM_CUSTOMDRAW == ((LPNMHDR)lParam)->code)
		{
			bHandled = TRUE;
			lResult = OnCustomDraw((int)wParam, (LPNMHDR)lParam, bHandled);
			if(bHandled)
				return TRUE;
		}
	END_MSG_MAP()

// message handler
	LRESULT OnCustomDraw(int idCtrl, LPNMHDR pnmh, BOOL& bHandled)
	{
		T* pT = static_cast<T*>(this);
		LPNMCUSTOMDRAW lpNMCustomDraw = (LPNMCUSTOMDRAW)pnmh;
		DWORD dwRet = 0;
		switch(lpNMCustomDraw->dwDrawStage)
		{
		case CDDS_PREPAINT:
			dwRet = pT->OnPrePaint(idCtrl, lpNMCustomDraw);
			break;
		case CDDS_POSTPAINT:
			dwRet = pT->OnPostPaint(idCtrl, lpNMCustomDraw);
			break;
		case CDDS_PREERASE:
			dwRet = pT->OnPreErase(idCtrl, lpNMCustomDraw);
			break;
		case CDDS_POSTERASE:
			dwRet = pT->OnPostErase(idCtrl, lpNMCustomDraw);
			break;
		case CDDS_ITEMPREPAINT:
			dwRet = pT->OnItemPrePaint(idCtrl, lpNMCustomDraw);
			break;
		case CDDS_ITEMPOSTPAINT:
			dwRet = pT->OnItemPostPaint(idCtrl, lpNMCustomDraw);
			break;
		case CDDS_ITEMPREERASE:
			dwRet = pT->OnItemPreErase(idCtrl, lpNMCustomDraw);
			break;
		case CDDS_ITEMPOSTERASE:
			dwRet = pT->OnItemPostErase(idCtrl, lpNMCustomDraw);
			break;
		default:
			bHandled = FALSE;
			break;
		}
		return dwRet;
	}

// overrideables
	DWORD OnPrePaint(int idCtrl, LPNMCUSTOMDRAW lpNMCustomDraw)
	{
		return CDRF_DODEFAULT;
	}
	DWORD OnPostPaint(int idCtrl, LPNMCUSTOMDRAW lpNMCustomDraw)
	{
		return CDRF_DODEFAULT;
	}
	DWORD OnPreErase(int idCtrl, LPNMCUSTOMDRAW lpNMCustomDraw)
	{
		return CDRF_DODEFAULT;
	}
	DWORD OnPostErase(int idCtrl, LPNMCUSTOMDRAW lpNMCustomDraw)
	{
		return CDRF_DODEFAULT;
	}
	DWORD OnItemPrePaint(int idCtrl, LPNMCUSTOMDRAW lpNMCustomDraw)
	{
		return CDRF_DODEFAULT;
	}
	DWORD OnItemPostPaint(int idCtrl, LPNMCUSTOMDRAW lpNMCustomDraw)
	{
		return CDRF_DODEFAULT;
	}
	DWORD OnItemPreErase(int idCtrl, LPNMCUSTOMDRAW lpNMCustomDraw)
	{
		return CDRF_DODEFAULT;
	}
	DWORD OnItemPostErase(int idCtrl, LPNMCUSTOMDRAW lpNMCustomDraw)
	{
		return CDRF_DODEFAULT;
	}
};

}; //namespace ATL

#endif // __ATLCONTROLS_H__
