// MyListCtrl.cpp : implementation file
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
#include "listhdr.h"
#include "mlistctl.h"
//#include "listcpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyListCtrl

CMyListCtrl::CMyListCtrl()
{
	m_bDragging = FALSE;
	m_pimageListDrag = NULL;
	m_oldDNDStyle = NULL;
}

CMyListCtrl::~CMyListCtrl()
{
}


BEGIN_MESSAGE_MAP(CMyListCtrl, CListCtrl)
	//{{AFX_MSG_MAP(CMyListCtrl)
	ON_NOTIFY_REFLECT(LVN_BEGINDRAG, OnBeginDrag)
	ON_NOTIFY_REFLECT(LVN_BEGINRDRAG, OnBeginDrag)
	ON_NOTIFY_REFLECT(LVN_ENDLABELEDIT, OnEndLabelEdit)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyListCtrl message handlers
void CMyListCtrl::OnBeginDrag(LPNMHDR pnmhdr, LRESULT* /*pResult*/)
{
	CPoint          ptItem, ptAction, ptImage;
	NM_LISTVIEW     *pnmListView = (NM_LISTVIEW *)pnmhdr;

	m_oldDNDStyle = GetExtendedStyle();
	if (m_oldDNDStyle != 0) SetExtendedStyle(0);	// styles model original icon DND behavior
	
	ASSERT(!m_bDragging);
	m_bDragging = TRUE;
	m_iItemDrag = pnmListView->iItem;
	ptAction = pnmListView->ptAction;
	GetItemPosition(m_iItemDrag, &ptItem);  // ptItem is relative to (0,0) and not the view origin
	GetOrigin(&m_ptOrigin);

	ASSERT(m_pimageListDrag == NULL);
	m_pimageListDrag = CreateDragImage(m_iItemDrag, &ptImage);
	m_sizeDelta = ptAction - ptImage;   // difference between cursor pos and image pos
	m_ptHotSpot = ptAction - ptItem + m_ptOrigin;  // calculate hotspot for the cursor
	m_pimageListDrag->DragShowNolock(TRUE);  // lock updates and show drag image
	m_pimageListDrag->SetDragCursorImage(0, CPoint(0, 0));// define the hot spot for the new cursor image
	m_pimageListDrag->BeginDrag(0, CPoint(0, 0));

	ptAction -= m_sizeDelta;
	m_pimageListDrag->DragEnter(this, ptAction);
	m_pimageListDrag->DragMove(ptAction);  // move image to overlap original icon
	m_iItemDrop = -1;// no drop target
	SetCapture();
}

void CMyListCtrl::OnMouseMove(UINT nFlags, CPoint point)
{
	long        lStyle;
	int         iItem;
	LV_ITEM     lvitem;

	lStyle = GetWindowLong(m_hWnd, GWL_STYLE);
	lStyle &= LVS_TYPEMASK;  // drag will do different things in list and report mode

	if (m_bDragging)
	{
		ASSERT(m_pimageListDrag != NULL);
		m_pimageListDrag->DragMove(point - m_sizeDelta);  // move the image 
		if ((iItem = HitTest(point)) != -1)
		{
			lvitem.mask = LVIF_STATE;
			lvitem.stateMask = LVIS_DROPHILITED;  // highlight the drop target
			if (m_iItemDrop != -1)  // remove the drophighlighted from previous item
			{
				m_pimageListDrag->DragLeave(this);
				lvitem.iItem = m_iItemDrop;
				lvitem.iSubItem = 0;
				lvitem.state = 0;	// sets drophighlighted to FALSE  

				SetItem(&lvitem);
			}
			
			m_iItemDrop = iItem;
			m_pimageListDrag->DragLeave(this); // unlock the window and hide drag image

			if (lStyle == LVS_REPORT || lStyle == LVS_LIST)
			{
				lvitem.iItem = iItem;
				lvitem.iSubItem = 0;
				lvitem.state = LVIS_DROPHILITED;	// sets the drophighlighted

				SetItem(&lvitem);
				UpdateWindow();
			}
			point -= m_sizeDelta;
			m_pimageListDrag->DragEnter(this, point);  // lock updates and show drag image
		}
	}
	CListCtrl::OnMouseMove(nFlags, point);
}


void CMyListCtrl::OnButtonUp(CPoint point)
{
	if (m_bDragging)  // end of the drag operation
	{
		long        lStyle;
		CString     cstr;

		lStyle = GetWindowLong(m_hWnd, GWL_STYLE) & LVS_TYPEMASK;
		if (m_oldDNDStyle != 0) SetExtendedStyle(m_oldDNDStyle);

		m_bDragging = FALSE;
		ASSERT(m_pimageListDrag != NULL);
		m_pimageListDrag->DragLeave(this);

		SetItemState(m_iItemDrop, 0, LVIS_DROPHILITED);	// remove the drophighlighted from last highlighted target

		m_pimageListDrag->EndDrag();
		delete m_pimageListDrag;
		m_pimageListDrag = NULL;

		// The drop target's sub-item text is replaced by the dragged item's
		// main text
		if (lStyle == LVS_REPORT && m_iItemDrop != m_iItemDrag)
		{
			cstr = GetItemText(m_iItemDrag, 0);
			SetItemText(m_iItemDrop, 1, cstr);
		}

		//the character string "**" is added to the end of the drop target's main text
		if (lStyle == LVS_LIST && m_iItemDrop != m_iItemDrag)
		{
			cstr = GetItemText(m_iItemDrop, 0);
			cstr += _T("**");
			SetItemText(m_iItemDrop, 0, cstr);
		}

		  // move the icon
		if (lStyle == LVS_ICON || lStyle == LVS_SMALLICON)
		{
			point -= m_ptHotSpot;  // the icon should be drawn exactly where the image is
			point += m_ptOrigin;
			SetItemPosition(m_iItemDrag, point);  // just move the dragged item
		}

		::ReleaseCapture();
	}
}

void CMyListCtrl::OnLButtonUp(UINT nFlags, CPoint point)
{
	OnButtonUp(point);
	CListCtrl::OnLButtonUp(nFlags, point);
}

void CMyListCtrl::OnRButtonUp(UINT nFlags, CPoint point)
{
	OnButtonUp(point);
	CListCtrl::OnRButtonUp(nFlags, point);
}

void CMyListCtrl::OnEndLabelEdit(LPNMHDR pnmhdr, LRESULT* /*pLResult*/)
{
	LV_DISPINFO  *plvDispInfo = (LV_DISPINFO *)pnmhdr;
	LV_ITEM      *plvItem = &plvDispInfo->item;

	if (plvItem->pszText != NULL)
		SetItemText(plvItem->iItem, plvItem->iSubItem, plvItem->pszText);
}
