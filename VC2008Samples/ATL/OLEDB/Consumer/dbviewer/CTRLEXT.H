// ctrlext.h : header file
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#ifndef __CTRLEXT_H__
#define __CTRLEXT_H__

/////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class CTreeCtrlEx;
class CListCtrlEx;
class CTreeCursor;


/////////////////////////////////////////////////////////////////////////////
// CTreeCursor

class CTreeCursor
{
	// Attributes
protected:
	HTREEITEM   m_hTreeItem;
	CTreeCtrlEx *m_pTree;

	// Implementation
protected:
	CTreeCursor CTreeCursor::_Insert(LPCTSTR strItem, int nImageIndex,
					HTREEITEM hAfter);

	// Operations
public:
	CTreeCursor();
	CTreeCursor(HTREEITEM hTreeItem, CTreeCtrlEx* pTree);
	CTreeCursor(const CTreeCursor& posSrc);
	~CTreeCursor();
	const CTreeCursor& operator =(const CTreeCursor& posSrc);
	operator HTREEITEM();

	CTreeCursor InsertAfter(LPCTSTR strItem, HTREEITEM hAfter,
					int nImageIndex = -1);
	CTreeCursor AddHead(LPCTSTR strItem, int nImageIndex = -1);
	CTreeCursor AddTail(LPCTSTR strItem, int nImageIndex = -1);

	int GetImageID();

	BOOL GetRect(LPRECT lpRect, BOOL bTextOnly);
	CTreeCursor GetNext(UINT nCode);
	CTreeCursor GetChild();
	CTreeCursor GetNextSibling();
	CTreeCursor GetPrevSibling();
	CTreeCursor GetParent();
	CTreeCursor GetFirstVisible();
	CTreeCursor GetNextVisible();
	CTreeCursor GetPrevVisible();
	CTreeCursor GetSelected();
	CTreeCursor GetDropHilight();
	CTreeCursor GetRoot();
	CString GetText();
	BOOL GetImage(int& nImage, int& nSelectedImage);
	UINT GetState(UINT nStateMask);
	DWORD_PTR GetData();
	BOOL Set(UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam);
	BOOL SetText(LPCTSTR lpszItem);
	BOOL SetImage(int nImage, int nSelectedImage);
	BOOL SetState(UINT nState, UINT nStateMask);
	BOOL SetData(DWORD dwData);
	BOOL HasChildren();
// Operations
	BOOL Delete();

	BOOL Expand(UINT nCode = TVE_EXPAND);
	CTreeCursor Select(UINT nCode);
	CTreeCursor Select();
	CTreeCursor SelectDropTarget();
	CTreeCursor SelectSetFirstVisible();
	CEdit* EditLabel();
	CImageList* CreateDragImage();
	BOOL SortChildren();
	BOOL EnsureVisible();
};


/////////////////////////////////////////////////////////////////////////////
// CListCtrlEx window

class CListCtrlEx : public CListCtrl
{
// Construction
public:
	CListCtrlEx();

// Attributes
public:

// Operations
public:
	CImageList* SetImageList(CImageList* pImageList,
					int nImageListType = TVSIL_NORMAL);
	BOOL AddColumn(
		LPCTSTR strItem, int nItem, int nSubItem = -1,
		int nMask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM,
		int nFmt = LVCFMT_LEFT);
	BOOL AddItem(int nItem, int nSubItem, LPCTSTR strItem, int nImageIndex = -1);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlEx)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListCtrlEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListCtrlEx)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlEx window

class CTreeCtrlEx : public CTreeCtrl
{
// Construction
public:
	CTreeCtrlEx();

// Attributes
public:

// Operations
public:
	CImageList* SetImageList(CImageList* pImageList, int nImageListType = TVSIL_NORMAL);

	CTreeCursor GetNextItem(HTREEITEM hItem, UINT nCode);
	CTreeCursor GetChildItem(HTREEITEM hItem);
	CTreeCursor GetNextSiblingItem(HTREEITEM hItem);
	CTreeCursor GetPrevSiblingItem(HTREEITEM hItem);
	CTreeCursor GetParentItem(HTREEITEM hItem);
	CTreeCursor GetFirstVisibleItem();
	CTreeCursor GetNextVisibleItem(HTREEITEM hItem);
	CTreeCursor GetPrevVisibleItem(HTREEITEM hItem);
	CTreeCursor GetSelectedItem();
	CTreeCursor GetDropHilightItem();
	CTreeCursor GetRootItem();
	CTreeCursor InsertItem(LPTV_INSERTSTRUCT lpInsertStruct);
	CTreeCursor InsertItem(UINT nMask, LPCTSTR lpszItem, int nImage,
		int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam,
		HTREEITEM hParent, HTREEITEM hInsertAfter);
	CTreeCursor InsertItem(LPCTSTR lpszItem, HTREEITEM hParent = TVI_ROOT,
		HTREEITEM hInsertAfter = TVI_LAST);
	CTreeCursor InsertItem(LPCTSTR lpszItem, int nImage, int nSelectedImage,
		HTREEITEM hParent = TVI_ROOT, HTREEITEM hInsertAfter = TVI_LAST);
	CTreeCursor Select(HTREEITEM hItem, UINT nCode);
	CTreeCursor SelectItem(HTREEITEM hItem);
	CTreeCursor SelectDropTarget(HTREEITEM hItem);
	CTreeCursor SelectSetFirstVisible(HTREEITEM hItem);
	CTreeCursor HitTest(CPoint pt, UINT* pFlags = NULL);
	CTreeCursor HitTest(TV_HITTESTINFO* pHitTestInfo);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeCtrlEx)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTreeCtrlEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CTreeCtrlEx)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#include "CtrlExt.inl"

/////////////////////////////////////////////////////////////////////////////

#endif // __CTRLEXT_H__

/////////////////////////////////////////////////////////////////////////////
