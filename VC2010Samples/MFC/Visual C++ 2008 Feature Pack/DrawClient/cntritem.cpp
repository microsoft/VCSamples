// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"

#ifndef SHARED_HANDLERS
#include "DrawClient.h"
#endif

#include "drawdoc.h"
#include "drawobj.h"
#ifndef SHARED_HANDLERS
#include "drawvw.h"
#endif
#include "cntritem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDrawItem implementation

IMPLEMENT_SERIAL(CDrawItem, COleClientItem, 0)

CDrawItem::CDrawItem(CDrawDoc* pContainer, CDrawOleObj* pDrawObj)
: COleClientItem(pContainer)
{
	m_pDrawObj = pDrawObj;
}

CDrawItem::~CDrawItem()
{
	if (m_pDrawObj != NULL)
		m_pDrawObj->m_pClientItem = NULL;
}

void CDrawItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	switch (nCode)
	{
	case OLE_CHANGED_STATE:
	case OLE_CHANGED_ASPECT:
		m_pDrawObj->Invalidate();
		break;
	case OLE_CHANGED:
		UpdateExtent(); // extent may have changed
		m_pDrawObj->Invalidate();
		break;
	}
}

BOOL CDrawItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);
#ifndef SHARED_HANDLERS
	CDrawView* pView = GetActiveView();
	ASSERT_VALID(pView);
	CRect rect = rectPos;
	pView->ClientToDoc(rect);

	if (rect != m_pDrawObj->m_position)
	{
		// invalidate old rectangle
		m_pDrawObj->Invalidate();

		// update to new rectangle
		m_pDrawObj->m_position = rect;
		GetExtent(&m_pDrawObj->m_extent);

		// and invalidate new rectangle
		m_pDrawObj->Invalidate();

		// mark document as dirty
		GetDocument()->SetModifiedFlag();
	}
#endif
	return COleClientItem::OnChangeItemPosition(rectPos);
}

void CDrawItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// update to extent of item if m_position is not initialized
	if (m_pDrawObj->m_position.IsRectEmpty())
		UpdateExtent();

	// copy m_position, which is in document coordinates
#ifndef SHARED_HANDLERS
	CDrawView* pView = GetActiveView();
	ASSERT_VALID(pView);
	rPosition = m_pDrawObj->m_position;
	pView->DocToClient(rPosition);
#endif
}

void CDrawItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Call base class first to read in COleClientItem data.
	// Note: this sets up the m_pDocument pointer returned from
	//  CDrawItem::GetDocument, therefore it is a good idea
	//  to call the base class Serialize first.
	COleClientItem::Serialize(ar);

	// now store/retrieve data specific to CDrawItem
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

BOOL CDrawItem::UpdateExtent()
{
	CSize size;
	if (!GetExtent(&size) || size == m_pDrawObj->m_extent)
		return FALSE;       // blank

	// if new object(i.e. m_extent is empty) setup position
	if (m_pDrawObj->m_extent == CSize(0, 0))
	{
		m_pDrawObj->m_position.right = m_pDrawObj->m_position.left + MulDiv(size.cx, 10, 254);
		m_pDrawObj->m_position.bottom = m_pDrawObj->m_position.top - MulDiv(size.cy, 10, 254);
	}
	// else data changed so scale up rect as well
	else if (!IsInPlaceActive() && size != m_pDrawObj->m_extent)
	{
		m_pDrawObj->m_position.right = m_pDrawObj->m_position.left + MulDiv(m_pDrawObj->m_position.Width(), size.cx, m_pDrawObj->m_extent.cx);
		m_pDrawObj->m_position.bottom = m_pDrawObj->m_position.top + MulDiv(m_pDrawObj->m_position.Height(), size.cy, m_pDrawObj->m_extent.cy);
	}

	m_pDrawObj->m_extent = size;
	m_pDrawObj->Invalidate();   // redraw to the new size/position
	return TRUE;
}

void CDrawItem::OnActivate()
{
	// allow only one inplace active item per frame
#ifndef SHARED_HANDLERS
	CView* pView = GetActiveView();
	ASSERT_VALID(pView);
	COleClientItem* pItem = GetDocument()->GetInPlaceActiveItem(pView);
	if (pItem != NULL && pItem != this)
		pItem->Close();
#endif

	COleClientItem::OnActivate();
}

void CDrawItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

	// hide the object if it is not an outside-in object
	DWORD dwMisc = 0;
	m_lpObject->GetMiscStatus(GetDrawAspect(), &dwMisc);
	if (dwMisc & OLEMISC_INSIDEOUT)
		DoVerb(OLEIVERB_HIDE, NULL);
}

BOOL CDrawItem::OnShowControlBars(CFrameWnd* pFrameWnd, BOOL bShow)
{
#ifndef SHARED_HANDLERS
	CMDIFrameWndEx* pMainFrame = DYNAMIC_DOWNCAST(CMDIFrameWndEx, pFrameWnd);

	if (pMainFrame != NULL)
	{
		ASSERT_VALID(pMainFrame);
		BOOL bResult = pMainFrame->OnShowPanes(bShow);
		pMainFrame->RecalcLayout();
		return bResult;
	}
#endif
	return FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CDrawItem diagnostics

#ifdef _DEBUG
void CDrawItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CDrawItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif


