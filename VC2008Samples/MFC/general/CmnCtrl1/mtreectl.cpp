// MyTreeCtrl.cpp : implementation file
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
#include "CmnCtrl1.h"
#include "mtreectl.h"
#include "treecpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl

CMyTreeCtrl::CMyTreeCtrl()
{
	m_bDragging = FALSE;
	m_pimagelist = NULL;
}

CMyTreeCtrl::~CMyTreeCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyTreeCtrl, CTreeCtrl)
	//{{AFX_MSG_MAP(CMyTreeCtrl)
	ON_NOTIFY_REFLECT(TVN_ENDLABELEDIT, OnEndLabelEdit)
	ON_NOTIFY_REFLECT(TVN_BEGINDRAG, OnBeginDrag)
	ON_NOTIFY_REFLECT(TVN_BEGINRDRAG, OnBeginDrag)
	ON_WM_MOUSEMOVE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl message handlers
void CMyTreeCtrl::OnDestroy()
{
	CImageList  *pimagelist;

	pimagelist = GetImageList(TVSIL_NORMAL);
	pimagelist->DeleteImageList();
	delete pimagelist;
}

void CMyTreeCtrl::SetNewStyle(long lStyleMask, BOOL bSetBits)
{
	long        lStyleOld;

	lStyleOld = GetWindowLong(m_hWnd, GWL_STYLE);
	lStyleOld &= ~lStyleMask;
	if (bSetBits)
		lStyleOld |= lStyleMask;

	SetWindowLong(m_hWnd, GWL_STYLE, lStyleOld);
	SetWindowPos(NULL, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER);
}

void CMyTreeCtrl::OnEndLabelEdit(LPNMHDR pnmhdr, LRESULT *pLResult)
{
	TV_DISPINFO     *ptvinfo;

	((CTreeCtrlPage *)GetParent())->ShowNotification(pnmhdr, pLResult);
	ptvinfo = (TV_DISPINFO *)pnmhdr;
	if (ptvinfo->item.pszText != NULL)
	{
		ptvinfo->item.mask = TVIF_TEXT;
		SetItem(&ptvinfo->item);
	}
	*pLResult = TRUE;
}

void CMyTreeCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	HTREEITEM           hitem;
	UINT                flags;

	if (m_bDragging)
	{
		ASSERT(m_pimagelist != NULL);
		m_pimagelist->DragMove(point);
		if ((hitem = HitTest(point, &flags)) != NULL)
		{
			m_pimagelist->DragLeave(this);
			SelectDropTarget(hitem);
			m_hitemDrop = hitem;
			m_pimagelist->DragEnter(this, point);
		}
	}

	CTreeCtrl::OnMouseMove(nFlags, point);
}

BOOL CMyTreeCtrl::IsChildNodeOf(HTREEITEM hitemChild, HTREEITEM hitemSuspectedParent)
{
	do
	{
		if (hitemChild == hitemSuspectedParent)
			break;
	}
	while ((hitemChild = GetParentItem(hitemChild)) != NULL);

	return (hitemChild != NULL);
}


BOOL CMyTreeCtrl::TransferItem(HTREEITEM hitemDrag, HTREEITEM hitemDrop)
{
	TV_INSERTSTRUCT     tvstruct;
	TCHAR               sztBuffer[50];
	HTREEITEM           hNewItem, hFirstChild;

		// avoid an infinite recursion situation
	tvstruct.item.hItem = hitemDrag;
	tvstruct.item.cchTextMax = 49;
	tvstruct.item.pszText = sztBuffer;
	tvstruct.item.mask = TVIF_CHILDREN | TVIF_HANDLE | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT;
	GetItem(&tvstruct.item);  // get information of the dragged element
	tvstruct.hParent = hitemDrop;
	tvstruct.hInsertAfter = TVI_SORT;
	tvstruct.item.mask = TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_TEXT;
	hNewItem = InsertItem(&tvstruct);

	while ((hFirstChild = GetChildItem(hitemDrag)) != NULL)
	{
		TransferItem(hFirstChild, hNewItem);  // recursively transfer all the items
		DeleteItem(hFirstChild);        // delete the first child and all its children
	}
	return TRUE;
}

void CMyTreeCtrl::OnButtonUp()
{
	if (m_bDragging)
	{
		ASSERT(m_pimagelist != NULL);
		m_pimagelist->DragLeave(this);
		m_pimagelist->EndDrag();
		delete m_pimagelist;
		m_pimagelist = NULL;

		if (m_hitemDrag != m_hitemDrop && !IsChildNodeOf(m_hitemDrop, m_hitemDrag) &&
															GetParentItem(m_hitemDrag) != m_hitemDrop)
		{
			TransferItem(m_hitemDrag, m_hitemDrop);
			DeleteItem(m_hitemDrag);
		}
		else
			MessageBeep(0);

		ReleaseCapture();
		m_bDragging = FALSE;
		SelectDropTarget(NULL);
	}
}

void CMyTreeCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	OnButtonUp();
	CTreeCtrl::OnLButtonUp(nFlags, point);
}

void CMyTreeCtrl::OnRButtonUp(UINT nFlags, CPoint point)
{
	OnButtonUp();
	CTreeCtrl::OnRButtonUp(nFlags, point);
}

void CMyTreeCtrl::OnBeginDrag(LPNMHDR pnmhdr, LRESULT *pLResult)
{
	CPoint      ptAction;
	UINT        nFlags;

	GetCursorPos(&ptAction);
	ScreenToClient(&ptAction);
	((CTreeCtrlPage *)GetParent())->ShowNotification(pnmhdr, pLResult);
	ASSERT(!m_bDragging);
	m_bDragging = TRUE;
	m_hitemDrag = HitTest(ptAction, &nFlags);
	m_hitemDrop = NULL;

	ASSERT(m_pimagelist == NULL);
	m_pimagelist = CreateDragImage(m_hitemDrag);  // get the image list for dragging
	m_pimagelist->DragShowNolock(TRUE);
	m_pimagelist->SetDragCursorImage(0, CPoint(0, 0));
	m_pimagelist->BeginDrag(0, CPoint(0,0));
	m_pimagelist->DragMove(ptAction);
	m_pimagelist->DragEnter(this, ptAction);
	SetCapture();
}
