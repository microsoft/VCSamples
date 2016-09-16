// trackvw.cpp : implementation of the CTrackerView class
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
#include "trackapp.h"

#include "trackdoc.h"
#include "trackvw.h"
#include "dialogs.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrackerView

IMPLEMENT_DYNCREATE(CTrackerView, CView)

BEGIN_MESSAGE_MAP(CTrackerView, CView)
	//{{AFX_MSG_MAP(CTrackerView)
	ON_WM_LBUTTONDOWN()
	ON_WM_SETCURSOR()
	ON_COMMAND(ID_VIEW_SETHANDLESIZE, OnViewSethandlesize)
	ON_COMMAND(ID_VIEW_SETMINIMUMSIZE, OnViewSetminimumsize)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrackerView construction/destruction

CTrackerView::CTrackerView()
{
	// TODO: add construction code here
}

CTrackerView::~CTrackerView()
{
}

/////////////////////////////////////////////////////////////////////////////
// CTrackerView drawing

static void SetNormalRect(CRect& rect, int left, int top, int width, int height)
{
	// set it
	rect.left = left;
	rect.top = top;
	rect.right = left + width;
	rect.bottom = top + height;

	// normalize it
	int nTemp;
	if (rect.left > rect.right)
	{
		nTemp = rect.left;
		rect.left = rect.right;
		rect.right = nTemp;
	}
	if (rect.top > rect.bottom)
	{
		nTemp = rect.top;
		rect.top = rect.bottom;
		rect.bottom = nTemp;
	}
}

void CTrackerView::OnDraw(CDC* pDC)
{
	CTrackerDoc* pDoc = GetDocument();

	CBrush* pOldBrush = NULL;
	TRY
	{
		// draw inside in various colors
		CBrush brush1, brush2;
		CRect rect;
		int nWidth = pDoc->m_tracker.m_rect.Width();
		int nHeight = pDoc->m_tracker.m_rect.Height();
		int nSgnX = nWidth != 0 ? nWidth / abs(nWidth) : 1;
		int nSgnY = nHeight != 0 ? nHeight / abs(nHeight) : 1;
		pDC->SetTextAlign(TA_CENTER);
		pDC->SetBkMode(TRANSPARENT);
		int nCenterX, nCenterY;

		TEXTMETRIC tm;
		pDC->GetTextMetrics(&tm);

		brush1.CreateSolidBrush(RGB(255, 0, 0));
		pOldBrush = pDC->SelectObject(&brush1);
		SetNormalRect(rect, pDoc->m_tracker.m_rect.left,
			pDoc->m_tracker.m_rect.top, nWidth/2, nHeight/2);
		pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
		nCenterX = rect.left + rect.Width()/2;
		nCenterY = rect.top + rect.Height()/2 - tm.tmHeight/2;
		pDC->ExtTextOut(nCenterX, nCenterY, ETO_CLIPPED, rect, _T("1"), 1, NULL);

		brush2.CreateSolidBrush(RGB(0, 255, 0));
		pDC->SelectObject(&brush2);
		brush1.DeleteObject();
		SetNormalRect(rect, pDoc->m_tracker.m_rect.left+nWidth/2,
			pDoc->m_tracker.m_rect.top, (nWidth+nSgnX)/2, nHeight/2);
		pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
		nCenterX = rect.left + rect.Width()/2;
		nCenterY = rect.top + rect.Height()/2 - tm.tmHeight/2;
		pDC->ExtTextOut(nCenterX, nCenterY, ETO_CLIPPED, rect, _T("2"), 1, NULL);

		brush1.CreateSolidBrush(RGB(0, 0, 255));
		pDC->SelectObject(&brush1);
		brush2.DeleteObject();
		SetNormalRect(rect, pDoc->m_tracker.m_rect.left,
			pDoc->m_tracker.m_rect.top+nHeight/2, nWidth/2, (nHeight+nSgnY)/2);
		pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
		nCenterX = rect.left + rect.Width()/2;
		nCenterY = rect.top + rect.Height()/2 - tm.tmHeight/2;
		pDC->ExtTextOut(nCenterX, nCenterY, ETO_CLIPPED, rect, _T("3"), 1, NULL);

		brush2.CreateSolidBrush(RGB(192, 192, 192));
		pDC->SelectObject(&brush2);
		brush1.DeleteObject();
		SetNormalRect(rect, pDoc->m_tracker.m_rect.left+nWidth/2,
			pDoc->m_tracker.m_rect.top+nHeight/2,
			(nWidth+nSgnX)/2, (nHeight+nSgnY)/2);
		pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), PATCOPY);
		nCenterX = rect.left + rect.Width()/2;
		nCenterY = rect.top + rect.Height()/2 - tm.tmHeight/2;
		pDC->ExtTextOut(nCenterX, nCenterY, ETO_CLIPPED, rect, _T("4"), 1, NULL);

		// cleanup DC
		if (pOldBrush != NULL)
			pDC->SelectObject(pOldBrush);
		brush2.DeleteObject();

		// draw tracker on outside
		pDoc->m_tracker.Draw(pDC);
	}
	CATCH_ALL(e)
	{
		if (pOldBrush != NULL)
			pDC->SelectObject(pOldBrush);
	}
	END_CATCH_ALL
}

/////////////////////////////////////////////////////////////////////////////
// CTrackerView printing

BOOL CTrackerView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTrackerView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTrackerView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}




/////////////////////////////////////////////////////////////////////////////
// CTrackerView diagnostics

#ifdef _DEBUG
void CTrackerView::AssertValid() const
{
	CView::AssertValid();
}

void CTrackerView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTrackerDoc* CTrackerView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CTrackerDoc, m_pDocument);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrackerView update

void CTrackerView::OnUpdate(CView* /*pSender*/, LPARAM lHint, CObject* /*pHint*/)
{
	if (lHint == 0)
	{
		CRect rectTrue;
		CTrackerDoc* pDoc = GetDocument();
		pDoc->m_tracker.GetTrueRect(&rectTrue);
		InvalidateRect(rectTrue);
	}
	else
	{
		InvalidateRect((CRect*)lHint);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTrackerView message handlers

void CTrackerView::OnLButtonDown(UINT nFlags, CPoint point)
{
	CTrackerDoc* pDoc = GetDocument();
	CRect rectSave;
	pDoc->m_tracker.GetTrueRect(rectSave);
	if (pDoc->m_tracker.HitTest(point) < 0)
	{
		// just to demonstrate CRectTracker::TrackRubberBand
		CRectTracker tracker;
		if (tracker.TrackRubberBand(this, point, pDoc->m_bAllowInvert))
		{
			MessageBeep(0); // beep indicates TRUE

			// see if rubber band intersects with the doc's tracker
			CRect rectT;
			tracker.m_rect.NormalizeRect(); // so intersect rect works
			if (rectT.IntersectRect(tracker.m_rect, pDoc->m_tracker.m_rect))
			{
				// if so, put resize handles on it (ie. select it)
				if (pDoc->m_tracker.m_nStyle & CRectTracker::resizeInside)
				{
					// swap from resize inside to resize outside for effect
					pDoc->m_tracker.m_nStyle &= ~CRectTracker::resizeInside;
					pDoc->m_tracker.m_nStyle |= CRectTracker::resizeOutside;
				}
				else
				{
					// just use inside resize handles on first time
					pDoc->m_tracker.m_nStyle &= ~CRectTracker::resizeOutside;
					pDoc->m_tracker.m_nStyle |= CRectTracker::resizeInside;
				}
				pDoc->SetModifiedFlag();
				pDoc->UpdateAllViews(NULL, (LPARAM)(LPCRECT)rectSave);
				pDoc->UpdateAllViews(NULL);
			}
		}
	}
	else if (pDoc->m_tracker.Track(this, point, pDoc->m_bAllowInvert))
	{
		// normal tracking action, when tracker is "hit"
		pDoc->SetModifiedFlag();
		pDoc->UpdateAllViews(NULL, (LPARAM)(LPCRECT)rectSave);
		pDoc->UpdateAllViews(NULL);
	}
	CView::OnLButtonDown(nFlags, point);
}


BOOL CTrackerView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	// forward to tracker
	CTrackerDoc* pDoc = GetDocument();
	if (pWnd == this && pDoc->m_tracker.SetCursor(this, nHitTest))
		return TRUE;

	return CView::OnSetCursor(pWnd, nHitTest, message);
}


void CTrackerView::OnViewSethandlesize()
{
	CTrackerDoc* pDoc = GetDocument();
	CHandleSize dlg;
	dlg.m_nHandleSize = pDoc->m_tracker.m_nHandleSize;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->m_tracker.m_nHandleSize = dlg.m_nHandleSize;
		pDoc->UpdateAllViews(NULL);
	}
}

void CTrackerView::OnViewSetminimumsize()
{
	CTrackerDoc* pDoc = GetDocument();
	CMinSize dlg;
	dlg.m_nMinX = pDoc->m_tracker.m_sizeMin.cx;
	dlg.m_nMinY = pDoc->m_tracker.m_sizeMin.cy;
	if (dlg.DoModal() == IDOK)
	{
		pDoc->m_tracker.m_sizeMin.cx = dlg.m_nMinX;
		pDoc->m_tracker.m_sizeMin.cy = dlg.m_nMinY;
		pDoc->UpdateAllViews(NULL);
	}
}
