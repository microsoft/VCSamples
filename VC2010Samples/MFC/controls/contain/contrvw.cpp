// ContrVw.cpp : implementation of the CContainerView class
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
// CContainerView

IMPLEMENT_DYNCREATE(CContainerView, CView)

BEGIN_MESSAGE_MAP(CContainerView, CView)
	//{{AFX_MSG_MAP(CContainerView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	ON_WM_SETFOCUS()
	ON_WM_SIZE()
	ON_COMMAND(ID_OLE_INSERT_NEW, OnInsertObject)
	ON_COMMAND(ID_CANCEL_EDIT_CNTR, OnCancelEditCntr)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONDBLCLK()
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_EDIT_CLEAR, OnEditClear)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CLEAR, OnUpdateEditClear)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CContainerView construction/destruction

CContainerView::CContainerView()
{
	m_pSelection = NULL;
	// TODO: add construction code here

}

CContainerView::~CContainerView()
{
}

BOOL CContainerView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CContainerView drawing

void CContainerView::OnDraw(CDC* pDC)
{
	CContainerDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	// draw the OLE items from the list
	POSITION pos = pDoc->GetStartPosition();
	while (pos != NULL)
	{
		// draw the item
		CContainerItem* pItem = (CContainerItem*)pDoc->GetNextItem(pos);
		pItem->Draw(pDC, pItem->m_rect);

		// draw the tracker over the item
		CRectTracker tracker;
		SetupTracker(pItem, &tracker);
		tracker.Draw(pDC);
	}
}

void CContainerView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	// TODO: remove this code when final selection model code is written
	m_pSelection = NULL;    // initialize selection

}

/////////////////////////////////////////////////////////////////////////////
// CContainerView printing

BOOL CContainerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CContainerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CContainerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// OLE Client support and commands

BOOL CContainerView::IsSelected(const CObject* pDocItem) const
{
	// The implementation below is adequate if your selection consists of
	//  only CContainerItem objects.  To handle different selection
	//  mechanisms, the implementation here should be replaced.

	// TODO: implement this function that tests for a selected OLE client item

	return pDocItem == m_pSelection;
}

void CContainerView::OnInsertObject()
{
	// Invoke the standard Insert Object dialog box to obtain information
	//  for new CContainerItem object.
	COleInsertDialog dlg;
	if (dlg.DoModal() != IDOK)
		return;

	BeginWaitCursor();

	CContainerItem* pItem = NULL;
	TRY
	{
		// Create new item connected to this document.
		CContainerDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CContainerItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from the dialog data.
		if (!dlg.CreateItem(pItem))
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);
		pItem->UpdateLink();
		pItem->UpdateFromServerExtent();

		// If item created from class list (not from file) then launch
		//  the server to edit the item.
		if (dlg.GetSelectionType() == COleInsertDialog::createNewItem)
			pItem->DoVerb(OLEIVERB_SHOW, this);

		ASSERT_VALID(pItem);

		SetSelection(pItem);
		pItem->InvalidateItem();
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH

	EndWaitCursor();
}

// The following command handler provides the standard keyboard
//  user interface to cancel an in-place editing session.  Here,
//  the container (not the server) causes the deactivation.
void CContainerView::OnCancelEditCntr()
{
	// Close any in-place active item on this view.
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
	{
		pActiveItem->Close();
	}
	ASSERT(GetDocument()->GetInPlaceActiveItem(this) == NULL);
}

// Special handling of OnSetFocus and OnSize are required for a container
//  when an object is being edited in-place.
void CContainerView::OnSetFocus(CWnd* pOldWnd)
{
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL &&
		pActiveItem->GetItemState() == COleClientItem::activeUIState)
	{
		// need to set focus to this item if it is in the same view
		CWnd* pWnd = pActiveItem->GetInPlaceWindow();
		if (pWnd != NULL)
		{
			pWnd->SetFocus();   // don't call the base class
			return;
		}
	}

	CView::OnSetFocus(pOldWnd);
}

void CContainerView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
	if (pActiveItem != NULL)
		pActiveItem->SetItemRects();
}
CContainerItem* CContainerView::HitTestItems(CPoint point)
{
	CContainerDoc* pDoc = GetDocument();
	CContainerItem* pItemHit = NULL;
	POSITION pos = pDoc->GetStartPosition();
	while (pos != NULL)
	{
		CContainerItem* pItem = (CContainerItem*)pDoc->GetNextItem(pos);
		if (pItem->m_rect.PtInRect(point))
			pItemHit = pItem;
	}
	return pItemHit;    // return top item at point
}

void CContainerView::SetSelection(CContainerItem* pItem)
{
	// close in-place active item
	if (pItem == NULL || m_pSelection != pItem)
	{
		COleClientItem* pActiveItem = GetDocument()->GetInPlaceActiveItem(this);
		if (pActiveItem != NULL && pActiveItem != pItem)
			pActiveItem->Close();
	}
	// update view to new selection
	if (m_pSelection != pItem)
	{
		if (m_pSelection != NULL)
			OnUpdate(NULL, HINT_UPDATE_ITEM, m_pSelection);

		m_pSelection = pItem;
		if (m_pSelection != NULL)
			OnUpdate(NULL, HINT_UPDATE_ITEM, m_pSelection);
	}
}

void CContainerView::SetupTracker(CContainerItem* pItem, CRectTracker* pTracker)
{
	pTracker->m_rect = pItem->m_rect;

	if (pItem == m_pSelection)
		pTracker->m_nStyle |= CRectTracker::resizeInside;

	if (pItem->GetType() == OT_LINK)
		pTracker->m_nStyle |= CRectTracker::dottedLine;
	else
		pTracker->m_nStyle |= CRectTracker::solidLine;

	if (pItem->GetItemState() == COleClientItem::openState ||
		pItem->GetItemState() == COleClientItem::activeUIState)
	{
		pTracker->m_nStyle |= CRectTracker::hatchInside;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CContainerView diagnostics

#ifdef _DEBUG
void CContainerView::AssertValid() const
{
	CView::AssertValid();
}

void CContainerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CContainerDoc* CContainerView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CContainerDoc)));
	return (CContainerDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CContainerView message handlers
void CContainerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CContainerItem* pItemHit = HitTestItems(point);
	SetSelection(pItemHit);

	if (pItemHit != NULL)
	{
		CRectTracker tracker;
		SetupTracker(pItemHit, &tracker);

		UpdateWindow();
		if (tracker.Track(this, point))
		{
			pItemHit->InvalidateItem();
			pItemHit->m_rect = tracker.m_rect;
			pItemHit->InvalidateItem();
			GetDocument()->SetModifiedFlag();
		}
	}

	CView::OnLButtonDown(nFlags, point);
}

void CContainerView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	OnLButtonDown(nFlags, point);

	if (m_pSelection != NULL)
	{
		m_pSelection->DoVerb(GetKeyState(VK_CONTROL) < 0 ?
			OLEIVERB_OPEN : OLEIVERB_PRIMARY, this);
	}

	CView::OnLButtonDblClk(nFlags, point);
}

BOOL CContainerView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (pWnd == this && m_pSelection != NULL)
	{
		// give the tracker for the selection a chance
		CRectTracker tracker;
		SetupTracker(m_pSelection, &tracker);
		if (tracker.SetCursor(this, nHitTest))
			return TRUE;
	}

	return CView::OnSetCursor(pWnd, nHitTest, message);
}

void CContainerView::OnEditClear()
{
	if (m_pSelection != NULL)
	{
		m_pSelection->Delete();
		m_pSelection = NULL;
		GetDocument()->UpdateAllViews(NULL);
	}
}

void CContainerView::OnUpdateEditClear(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pSelection != NULL);

}
void CContainerView::OnEditCopy()
{
	if (m_pSelection != NULL)
		m_pSelection->CopyToClipboard();
}

void CContainerView::OnUpdateEditCopy(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_pSelection != NULL);
}

void CContainerView::OnEditPaste()
{
	CContainerItem* pItem = NULL;

	TRY
	{
		// Create new item connected to this document.
		CContainerDoc* pDoc = GetDocument();
		ASSERT_VALID(pDoc);
		pItem = new CContainerItem(pDoc);
		ASSERT_VALID(pItem);

		// Initialize the item from clipboard data
		if (!pItem->CreateFromClipboard())
			AfxThrowMemoryException();  // any exception will do
		ASSERT_VALID(pItem);

		// update the size before displaying
		pItem->UpdateFromServerExtent();

		// set selection to newly pasted item
		SetSelection(pItem);
		pItem->InvalidateItem();
	}
	CATCH(CException, e)
	{
		if (pItem != NULL)
		{
			ASSERT_VALID(pItem);
			pItem->Delete();
		}
		AfxMessageBox(IDP_FAILED_TO_CREATE);
	}
	END_CATCH
}
void CContainerView::OnUpdate(CView* /* pSender */, LPARAM lHint, CObject* pHint)
{
	switch (lHint)
	{
	case HINT_UPDATE_WINDOW:    // invalidate entire window
		Invalidate();
		break;
	case HINT_UPDATE_ITEM:      // invalidate single item
		{
			CRectTracker tracker;
			SetupTracker((CContainerItem*)pHint, &tracker);
			CRect rect;
			tracker.GetTrueRect(rect);
			InvalidateRect(rect);
		}
		break;
	}
}
