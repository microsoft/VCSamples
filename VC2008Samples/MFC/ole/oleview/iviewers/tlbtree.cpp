// tlbtree.cpp : implementation file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "iview.h"
#include "util.h"
#include "iviewers.h"
#include "iviewer.h"
#include "typelib.h"
#include "tlbtree.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#define MAX_NAMES   256

/////////////////////////////////////////////////////////////////////////////
// CTypeLibTreeView
IMPLEMENT_DYNCREATE(CTypeLibTreeView, CView)

CTypeLibTreeView::CTypeLibTreeView( )
{
	m_hTypeInfos = NULL ;
	m_ptlb = NULL ;
}

CTypeLibTreeView::~CTypeLibTreeView()
{
	if (m_ptlb)
		m_ptlb->Release() ;
}


BEGIN_MESSAGE_MAP(CTypeLibTreeView, CView)
	//{{AFX_MSG_MAP(CTypeLibTreeView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TVN_SELCHANGED, ID_TREEVIEW, OnTreeSelchanged)
	ON_NOTIFY(TVN_ITEMEXPANDING, ID_TREEVIEW, OnTreeItemExpanding)
	ON_NOTIFY(TVN_ITEMEXPANDED, ID_TREEVIEW, OnTreeItemExpanded)
	ON_NOTIFY(NM_RETURN, ID_TREEVIEW, OnTreeItemReturn)
	ON_NOTIFY(TVN_DELETEITEM, ID_TREEVIEW, OnTreeDeleteItem)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTypeLibTreeView drawing


/////////////////////////////////////////////////////////////////////////////
// CTypeLibTreeView diagnostics

#ifdef _DEBUG
void CTypeLibTreeView::AssertValid() const
{
	CView::AssertValid();
}

void CTypeLibTreeView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTypeLibTreeView message handlers

int CTypeLibTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	RECT rect ;
	rect.top = lpCreateStruct->y ;
	rect.left = lpCreateStruct->x ;
	rect.bottom = lpCreateStruct->cy ;
	rect.right = lpCreateStruct->cx ;

	if (!m_tree.Create( WS_CHILD | WS_VISIBLE |
								WS_BORDER |
								TVS_HASLINES |
								TVS_LINESATROOT |
								TVS_SHOWSELALWAYS |
								TVS_HASBUTTONS |
								TVS_DISABLEDRAGDROP,
								rect, this, ID_TREEVIEW ))
	{
		TRACE( _T("Tree control failed to create!") ) ;
		return -1 ;
	}

	m_images.Create( IDB_IMAGELIST, 16, 64, RGBLTGREEN ) ;
	m_tree.SetImageList( &m_images, TVSIL_NORMAL ) ;

	return 0;
}

void CTypeLibTreeView::OnDestroy()
{
	CView::OnDestroy();
	m_tree.DeleteAllItems() ;
}

void CTypeLibTreeView::OnDraw(CDC* pDC)
{
	// TODO: Add your specialized code here and/or call the base class

}

void CTypeLibTreeView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	m_tree.SetWindowPos( NULL, -1, -1, cx+2, cy+2, SWP_NOZORDER ) ;
}

void CTypeLibTreeView::OnInitialUpdate()
{
	TRACE(_T("OnInitialUpdate\n")) ;
	CTypeLibWnd* pFrame = (CTypeLibWnd*)GetParent()->GetParent() ;
	ASSERT(pFrame->IsKindOf(RUNTIME_CLASS(CTypeLibWnd)));

	ASSERT(pFrame->m_ptlb) ;
	m_ptlb = pFrame->m_ptlb ;
	ENSURE(m_ptlb);
	m_ptlb->AddRef() ;

	CView::OnInitialUpdate();
}

void CTypeLibTreeView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	if (lHint != NULL || (lHint & UPDF_NOTREEVIEW))
		return ;

	TRACE(_T("OnUpdate\n")) ;
	m_tree.SetRedraw( FALSE ) ;
	BeginWaitCursor() ;

	m_tree.DeleteAllItems() ;
	m_hTypeInfos = NULL ;

	TV_INSERTSTRUCT tvis ;
	tvis.hParent = TVI_ROOT ;
	tvis.hInsertAfter = TVI_FIRST ;
	tvis.item.mask = TVIF_TEXT | TVIF_CHILDREN | TVIF_PARAM | TVIF_IMAGE | TVIF_SELECTEDIMAGE ;
	tvis.item.iImage = CTreeItem::typeTypeLib ;
	tvis.item.iSelectedImage = tvis.item.iImage + 1 ;

	HRESULT hr = S_OK ;
	CString strError ;
	TRY
	{
		CTypeLibWnd* pFrame = (CTypeLibWnd*)GetParent()->GetParent() ;
		if (pFrame == NULL)
		{
			strError = _T("Internal Application error.");
			AfxThrowMemoryException() ;
		}

		if (pFrame->m_fGroupByKind)
		{
			tvis.item.cChildren = 1 ;
		}
		else
		{
			tvis.item.cChildren = m_ptlb->GetTypeInfoCount() ;
		}

		BSTR    bstrName = NULL ;
		BSTR    bstrDoc = NULL ;
		BSTR    bstrHelp = NULL ;
		DWORD   dwHelpID ;
		hr = m_ptlb->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp ) ;
		if (FAILED(hr))
		{
			strError = _T("ITypeLib::GetDocumentation failed.") ;
			AfxThrowMemoryException() ;
		}

		#pragma warning (suppress: 6014)
		CTreeItem* pItem = new CTreeItem(&m_tree) ;
		if (pFrame->m_fGroupByKind)
			pItem->m_Type = CTreeItem::typeTypeLib2 ;
		else
			pItem->m_Type = CTreeItem::typeTypeLib ;
		pItem->SetTypeLib( m_ptlb ) ;
		m_ptlb->AddRef() ;
		tvis.item.lParam = (LPARAM)pItem ;

		COLE2CT lpszName(bstrName);
		if (::SysStringLen(bstrDoc) != 0)
		{
			COLE2CT lpszDoc(bstrDoc);
			CString str;
			str.Format( _T("%s (%s)"), lpszName, lpszDoc);
			tvis.item.pszText = str.GetBuffer(0);
			m_hTypeInfos = m_tree.InsertItem( &tvis ) ;
			str.ReleaseBuffer(-1) ;
		}
		else
		{
			tvis.item.pszText = (LPTSTR)lpszName;
			m_hTypeInfos = m_tree.InsertItem( &tvis ) ;
		}

		::SysFreeString( bstrName ) ;
		::SysFreeString( bstrDoc ) ;
		::SysFreeString( bstrHelp ) ;
	}
	CATCH(CException, pException)
	{
	}
	END_CATCH

	if (m_hTypeInfos)
	{
		m_tree.Expand( m_hTypeInfos, TVE_EXPAND ) ;
		//m_tree.SelectItem( m_hTypeInfos ) ;
	}

	m_tree.SetRedraw( TRUE ) ;
	EndWaitCursor() ;
}

void CTypeLibTreeView::DeleteTreeItems( HTREEITEM htree )
{
	HTREEITEM       hItem, hItemNext ;
	ASSERT(htree) ;

	hItem = m_tree.GetChildItem( htree ) ;
	while( hItem )
	{
		hItemNext = m_tree.GetNextSiblingItem( hItem ) ;
		m_tree.DeleteItem( hItem ) ;
		hItem = hItemNext ;
	}
}

void CTypeLibTreeView::OnTreeSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_TREEVIEW* pnmtv = (NM_TREEVIEW*)pNMHDR;
	*pResult = 0;

	CTypeLibWnd* pFrame = (CTypeLibWnd*)GetParent()->GetParent() ;
	ASSERT(pFrame->IsKindOf(RUNTIME_CLASS(CTypeLibWnd)));

	CTreeItem*  pItem = (CTreeItem*)pnmtv->itemNew.lParam ;
	if (pItem == NULL)
		return ;
	ASSERT(pItem->IsKindOf(RUNTIME_CLASS(CTreeItem)));

	pFrame->m_pSelectedItem = pItem ;

	pFrame->UpdateAllViews( this, UPDF_NOTREEVIEW, pItem ) ;
}

void CTypeLibTreeView::OnTreeItemExpanding(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = 0 ;
	NM_TREEVIEW* pnmtv = (NM_TREEVIEW*)pNMHDR;

	if ((pnmtv->action != TVE_EXPAND && pnmtv->itemNew.lParam) ||
		(pnmtv->itemNew.state & TVIS_EXPANDEDONCE))
		return ;

	CTreeItem*  pItem = (CTreeItem*)pnmtv->itemNew.lParam ;
	if (pItem == NULL)
		return ;
	ASSERT(pItem->IsKindOf(RUNTIME_CLASS(CTreeItem)));

	BeginWaitCursor() ;
	m_tree.SetRedraw( FALSE ) ;

	*pResult = !pItem->Expand(  pnmtv->itemNew.hItem ) ;

	// No children
	if (*pResult == TRUE)
	{
		TV_ITEM item ;
		item.cChildren = 0 ;
		item.mask = TVIF_CHILDREN ;
		item.hItem = pnmtv->itemNew.hItem ;
		m_tree.SetItem( &item ) ;
	}

	m_tree.SetRedraw( TRUE ) ;
	EndWaitCursor() ;
}


void CTypeLibTreeView::OnTreeItemExpanded(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = (LRESULT)FALSE ;
}

void CTypeLibTreeView::OnTreeItemReturn(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = (LRESULT)TRUE ;
	HTREEITEM hTreeItemSel = m_tree.GetSelectedItem() ;

	if (hTreeItemSel)
		m_tree.Expand( hTreeItemSel, TVE_TOGGLE ) ;
}

inline void CTypeLibTreeView::OnTreeDeleteItem(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = (LRESULT)TRUE ;
	NM_TREEVIEW* pnmtv = (NM_TREEVIEW*)pNMHDR;

	if (pnmtv->itemOld.lParam)
	{
		CTreeItem* pItem = (CTreeItem*)pnmtv->itemOld.lParam ;
		ASSERT(pItem->IsKindOf(RUNTIME_CLASS(CTreeItem)));
		delete pItem ;
		//pnmtv->itemOld.lParam = NULL ;
	}

}
