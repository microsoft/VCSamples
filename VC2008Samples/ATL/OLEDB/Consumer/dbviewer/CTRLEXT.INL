// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CTreeCursor CTLEXT_INLINE functions

#define CTLEXT_INLINE inline

CTLEXT_INLINE CTreeCursor::CTreeCursor() : m_hTreeItem(NULL),   m_pTree(NULL)
	{ }
CTLEXT_INLINE CTreeCursor::CTreeCursor(HTREEITEM hTreeItem,CTreeCtrlEx* pTree) :    m_hTreeItem(hTreeItem), m_pTree(pTree)
	{ }
CTLEXT_INLINE CTreeCursor::CTreeCursor(const CTreeCursor& posSrc)
	{ *this = posSrc; }
CTLEXT_INLINE CTreeCursor::~CTreeCursor()
	{ }
CTLEXT_INLINE CTreeCursor::operator HTREEITEM()
	{ return m_hTreeItem; }
CTLEXT_INLINE CTreeCursor CTreeCursor::InsertAfter(LPCTSTR strItem,HTREEITEM hAfter,int nImageIndex)
	{ return _Insert(strItem,nImageIndex,hAfter); }
CTLEXT_INLINE CTreeCursor CTreeCursor::AddHead(LPCTSTR strItem,int nImageIndex)
	{ return _Insert(strItem,nImageIndex,TVI_FIRST); }
CTLEXT_INLINE CTreeCursor CTreeCursor::AddTail(LPCTSTR strItem,int nImageIndex)
	{ return _Insert(strItem,nImageIndex,TVI_LAST); }
CTLEXT_INLINE BOOL CTreeCursor::GetRect(LPRECT lpRect, BOOL bTextOnly)
	{ return m_pTree->GetItemRect(m_hTreeItem,lpRect,bTextOnly); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetNext(UINT nCode)
	{ return m_pTree->GetNextItem(m_hTreeItem,nCode); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetChild()
	{ return m_pTree->GetChildItem(m_hTreeItem); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetNextSibling()
	{ return m_pTree->GetNextSiblingItem(m_hTreeItem); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetPrevSibling()
	{ return m_pTree->GetPrevSiblingItem(m_hTreeItem); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetParent()
	{ return m_pTree->GetParentItem(m_hTreeItem); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetFirstVisible()
	{ return m_pTree->GetFirstVisibleItem(); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetNextVisible()
	{ return m_pTree->GetNextVisibleItem(m_hTreeItem); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetPrevVisible()
	{ return m_pTree->GetPrevVisibleItem(m_hTreeItem); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetSelected()
	{ return m_pTree->GetSelectedItem(); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetDropHilight()
	{ return m_pTree->GetDropHilightItem(); }
CTLEXT_INLINE CTreeCursor CTreeCursor::GetRoot()
	{ return m_pTree->GetRootItem(); }
CTLEXT_INLINE CString CTreeCursor::GetText()
	{ return m_pTree->GetItemText(m_hTreeItem); }
CTLEXT_INLINE BOOL CTreeCursor::GetImage(int& nImage, int& nSelectedImage)
	{ return m_pTree->GetItemImage(m_hTreeItem,nImage,nSelectedImage); }
CTLEXT_INLINE UINT CTreeCursor::GetState(UINT nStateMask)
	{ return m_pTree->GetItemState(m_hTreeItem,nStateMask); }
CTLEXT_INLINE DWORD_PTR CTreeCursor::GetData()
	{ return m_pTree->GetItemData(m_hTreeItem); }
//CTLEXT_INLINE BOOL SetItem(UINT nMask, LPCTSTR lpszItem, int nImage,
//  int nSelectedImage, UINT nState,nStateMask,lParam);
CTLEXT_INLINE BOOL CTreeCursor::SetText(LPCTSTR lpszItem)
	{ return m_pTree->SetItemText(m_hTreeItem,lpszItem); }
CTLEXT_INLINE BOOL CTreeCursor::SetImage(int nImage, int nSelectedImage)
	{ return m_pTree->SetItemImage(m_hTreeItem,nImage,nSelectedImage); }
CTLEXT_INLINE BOOL CTreeCursor::SetState(UINT nState, UINT nStateMask)
	{ return m_pTree->SetItemState(m_hTreeItem,nState,nStateMask); }
CTLEXT_INLINE BOOL CTreeCursor::SetData(DWORD dwData)
	{ return m_pTree->SetItemData(m_hTreeItem,dwData); }
CTLEXT_INLINE BOOL CTreeCursor::HasChildren()
	{ return m_pTree->ItemHasChildren(m_hTreeItem); }
// Operations
CTLEXT_INLINE BOOL CTreeCursor::Delete()
	{ return m_pTree->DeleteItem(m_hTreeItem); }
CTLEXT_INLINE BOOL CTreeCursor::Expand(UINT nCode)
	{ return m_pTree->Expand(m_hTreeItem,nCode); }
CTLEXT_INLINE CTreeCursor CTreeCursor::Select(UINT nCode)
	{ return m_pTree->Select(m_hTreeItem,nCode); }
CTLEXT_INLINE CTreeCursor CTreeCursor::Select()
	{ return m_pTree->SelectItem(m_hTreeItem); }
CTLEXT_INLINE CTreeCursor CTreeCursor::SelectDropTarget()
	{ return m_pTree->SelectDropTarget(m_hTreeItem); }
CTLEXT_INLINE CTreeCursor CTreeCursor::SelectSetFirstVisible()
	{ return m_pTree->SelectSetFirstVisible(m_hTreeItem); }
CTLEXT_INLINE CEdit* CTreeCursor::EditLabel()
	{ return m_pTree->EditLabel(m_hTreeItem); }
CTLEXT_INLINE CImageList* CTreeCursor::CreateDragImage()
	{ return m_pTree->CreateDragImage(m_hTreeItem); }
CTLEXT_INLINE BOOL CTreeCursor::SortChildren()
	{ return m_pTree->SortChildren(m_hTreeItem); }
CTLEXT_INLINE BOOL CTreeCursor::EnsureVisible()
	{ return m_pTree->EnsureVisible(m_hTreeItem); }

/////////////////////////////////////////////////////////////////////////////
// CTreeCtrlEx CTLEXT_INLINE functions

CTLEXT_INLINE CTreeCtrlEx::CTreeCtrlEx() : CTreeCtrl()
	{ }
CTLEXT_INLINE CTreeCtrlEx::~CTreeCtrlEx()
	{ }
CTLEXT_INLINE CImageList* CTreeCtrlEx::SetImageList(CImageList* pImageList, int nImageListType)
	{ return CTreeCtrl::SetImageList(pImageList,nImageListType); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetNextItem(HTREEITEM hItem, UINT nCode)
	{ return CTreeCursor(CTreeCtrl::GetNextItem(hItem,nCode),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetChildItem(HTREEITEM hItem)
	{ return CTreeCursor(CTreeCtrl::GetChildItem(hItem),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetNextSiblingItem(HTREEITEM hItem)
	{ return CTreeCursor(CTreeCtrl::GetNextSiblingItem(hItem),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetPrevSiblingItem(HTREEITEM hItem)
	{ return CTreeCursor(CTreeCtrl::GetPrevSiblingItem(hItem),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetParentItem(HTREEITEM hItem)
	{ return CTreeCursor(CTreeCtrl::GetParentItem(hItem),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetFirstVisibleItem()
	{ return CTreeCursor(CTreeCtrl::GetFirstVisibleItem(),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetNextVisibleItem(HTREEITEM hItem)
	{ return CTreeCursor(CTreeCtrl::GetNextVisibleItem(hItem),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetPrevVisibleItem(HTREEITEM hItem)
	{ return CTreeCursor(CTreeCtrl::GetPrevVisibleItem(hItem),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetSelectedItem()
	{ return CTreeCursor(CTreeCtrl::GetSelectedItem(),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetDropHilightItem()
	{ return CTreeCursor(CTreeCtrl::GetDropHilightItem(),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::GetRootItem()
	{ return CTreeCursor(CTreeCtrl::GetRootItem(),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::InsertItem(LPTV_INSERTSTRUCT lpInsertStruct)
	{ return CTreeCursor(CTreeCtrl::InsertItem(lpInsertStruct),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::InsertItem(UINT nMask, LPCTSTR lpszItem, int nImage,
	int nSelectedImage, UINT nState, UINT nStateMask, LPARAM lParam,
	HTREEITEM hParent, HTREEITEM hInsertAfter)
	{ return CTreeCursor(CTreeCtrl::InsertItem(nMask, lpszItem, nImage,
		nSelectedImage, nState, nStateMask, lParam, hParent, hInsertAfter),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::InsertItem(LPCTSTR lpszItem, HTREEITEM hParent,HTREEITEM hInsertAfter)
	{ return CTreeCursor(CTreeCtrl::InsertItem(lpszItem, hParent, hInsertAfter),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::InsertItem(LPCTSTR lpszItem, int nImage, int nSelectedImage,
		HTREEITEM hParent, HTREEITEM hInsertAfter)
	{ return CTreeCursor(CTreeCtrl::InsertItem(lpszItem, nImage, nSelectedImage,
		hParent, hInsertAfter),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::Select(HTREEITEM hItem, UINT nCode)
	{ 
		if(CTreeCtrl::Select(hItem,nCode))
			return CTreeCursor(hItem,this);
		
		return CTreeCursor(NULL,this); 
	}

CTLEXT_INLINE CTreeCursor CTreeCtrlEx::SelectItem(HTREEITEM hItem)
	{ 
		if(CTreeCtrl::SelectItem(hItem))
			return CTreeCursor(hItem,this);
		
		return CTreeCursor(NULL,this); 
	}

CTLEXT_INLINE CTreeCursor CTreeCtrlEx::SelectDropTarget(HTREEITEM hItem)
	{ 		
		if(CTreeCtrl::SelectDropTarget(hItem))
			return CTreeCursor(hItem,this);
		
		return CTreeCursor(NULL,this); 
	}
		

CTLEXT_INLINE CTreeCursor CTreeCtrlEx::SelectSetFirstVisible(HTREEITEM hItem)
	{
		if(CTreeCtrl::SelectSetFirstVisible(hItem))
			return CTreeCursor(hItem,this);
		
		return CTreeCursor(NULL,this); 
	}

CTLEXT_INLINE CTreeCursor CTreeCtrlEx::HitTest(CPoint pt, UINT* pFlags)
	{ return CTreeCursor(CTreeCtrl::HitTest(pt,pFlags),this); }
CTLEXT_INLINE CTreeCursor CTreeCtrlEx::HitTest(TV_HITTESTINFO* pHitTestInfo)
	{ return CTreeCursor(CTreeCtrl::HitTest(pHitTestInfo),this); }

/////////////////////////////////////////////////////////////////////////////
// CListCtrlEx CTLEXT_INLINE functions

CTLEXT_INLINE CListCtrlEx::CListCtrlEx() : CListCtrl()
 { }
CTLEXT_INLINE CListCtrlEx::~CListCtrlEx()
 { }
CTLEXT_INLINE CImageList* CListCtrlEx::SetImageList(CImageList* pImageList, int nImageListType)
 { return CListCtrl::SetImageList(pImageList,nImageListType); }
