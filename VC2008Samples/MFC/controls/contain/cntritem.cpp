// CntrItem.cpp : implementation of the CContainerItem class
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "Contain.h"

#include "ContrDoc.h"
#include "CntrItem.h"
#include "ContrVw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CContainerItem implementation

IMPLEMENT_SERIAL(CContainerItem, COleClientItem, 0)

CContainerItem::CContainerItem(CContainerDoc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: add one-time construction code here
	m_rect.SetRect(10, 10, 50, 50);
}

CContainerItem::~CContainerItem()
{
	// TODO: add cleanup code here
	
}

void CContainerItem::InvalidateItem()
{
	GetDocument()->UpdateAllViews(NULL, HINT_UPDATE_ITEM, this);
}

void CContainerItem::UpdateFromServerExtent()
{
	CSize size;
	if (GetCachedExtent(&size))
	{
		// OLE returns the extent in HIMETRIC units -- we need pixels
		CClientDC dc(NULL);
		dc.HIMETRICtoDP(&size);

		// Only invalidate if it has actually changed, and also
		// only if it is not in-place active.  When in-place active, the
		// container item size should sync with the "window size" of the
		// object.  Only when not in-place active should the container 
		// item size should sync with the natural size of the object.

		if ((size != m_rect.Size()) && !IsInPlaceActive())
		{
			// invalidate old, update, invalidate new
			InvalidateItem();
			m_rect.bottom = m_rect.top + size.cy;
			m_rect.right = m_rect.left + size.cx;
			InvalidateItem();

			// mark document as modified
			GetDocument()->SetModifiedFlag();
		}
	}
}

void CContainerItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	// When an item is being edited (either in-place or fully open)
	//  it sends OnChange notifications for changes in the state of the
	//  item or visual appearance of its content.
	switch (nCode)
	{
	case OLE_CHANGED:
		InvalidateItem();
		UpdateFromServerExtent();
		break;
	case OLE_CHANGED_STATE:
	case OLE_CHANGED_ASPECT:
		InvalidateItem();
		break;
	}

}

BOOL CContainerItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// During in-place activation CContainerItem::OnChangeItemPosition
	//  is called by the server to change the position of the in-place
	//  window.  Usually, this is a result of the data in the server
	//  document changing such that the extent has changed or as a result
	//  of in-place resizing.
	//
	// The default here is to call the base class, which will call
	//  COleClientItem::SetItemRects to move the item
	//  to the new position.

	if (!COleClientItem::OnChangeItemPosition(rectPos))
		return FALSE;
	InvalidateItem();
	m_rect = rectPos;
	InvalidateItem();

	// mark document as dirty
	GetDocument()->SetModifiedFlag();

	return TRUE;
}

void CContainerItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);
	// return rect relative to client area of view
	rPosition = m_rect;
}

void CContainerItem::OnActivate()
{
	// allow only one inplace active item per frame
	CView* pView = GetActiveView();
	ASSERT_VALID(pView);
	COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
	if (pItem != NULL && pItem != this)
		pItem->Close();

	COleClientItem::OnActivate();
}

void CContainerItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

	// hide the object if it is not an outside-in object
	DWORD dwMisc = 0;
	m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
	if (dwMisc & OLEMISC_INSIDEOUT)
		DoVerb(OLEIVERB_HIDE, NULL);
}

void CContainerItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Call base class first to read in COleClientItem data.
	// Since this sets up the m_pDocument pointer returned from
	//  CContainerItem::GetDocument, it is a good idea to call
	//  the base class Serialize first.
	COleClientItem::Serialize(ar);

	// now store/retrieve data specific to CContainerItem
	if (ar.IsStoring())
	{
		// TODO: add storing code here
		ar << m_rect;
	}
	else
	{
		// TODO: add loading code here
		ar >> m_rect;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CContainerItem diagnostics

#ifdef _DEBUG
void CContainerItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CContainerItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
