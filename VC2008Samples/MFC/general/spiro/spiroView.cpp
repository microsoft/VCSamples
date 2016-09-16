// spiroView.cpp : implementation of the CSpiroView class
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
#include "spiro.h"
#include "piece.h"
#include "mainfrm.h"

#pragma warning( disable : 4189 )

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSpiroView

IMPLEMENT_DYNCREATE(CSpiroView, CScrollView)

BEGIN_MESSAGE_MAP(CSpiroView, CScrollView)
	//{{AFX_MSG_MAP(CSpiroView)
	ON_COMMAND(ID_PENWIDTH, OnPenWidth)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_UPDATE_COMMAND_UI(ID_ENORMOUSWHEEL, OnUpdateAnyWheel)
	ON_COMMAND(ID_HUGERING, OnDropRing)
	ON_COMMAND(ID_ENORMOUSWHEEL, OnDropWheel)
	ON_UPDATE_COMMAND_UI(ID_REMOVERING, OnUpdateRemoveRing)
	ON_UPDATE_COMMAND_UI(ID_REMOVEWHEEL, OnUpdateRemoveWheel)
	ON_COMMAND(ID_REMOVERING, OnRemoveRing)
	ON_COMMAND(ID_REMOVEWHEEL, OnRemoveWheel)
	ON_UPDATE_COMMAND_UI(ID_ZOOMIN, OnUpdateZoomIn)
	ON_COMMAND(ID_ZOOMIN, OnZoomIn)
	ON_COMMAND(ID_ZOOMOUT, OnZoomOut)
	ON_UPDATE_COMMAND_UI(ID_ZOOMOUT, OnUpdateZoomOut)
	ON_WM_LBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_DRAWPATTERN, OnUpdateDrawPattern)
	ON_COMMAND(ID_DRAWPATTERN, OnDrawPattern)
	ON_COMMAND(ID_END_DRAWING, OnEndDrawing)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_BLACK, OnBlack)
	ON_COMMAND(ID_BLUE, OnBlue)
	ON_COMMAND(ID_GREEN, OnGreen)
	ON_COMMAND(ID_PURPLE, OnPurple)
	ON_COMMAND(ID_RED, OnRed)
	ON_COMMAND(ID_YELLOW, OnYellow)
	ON_UPDATE_COMMAND_UI(ID_BLUE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(ID_PAUSEDRAWING, OnUpdatePauseDrawing)
	ON_COMMAND(ID_PAUSEDRAWING, OnPauseDrawing)
	ON_UPDATE_COMMAND_UI(IDC_SLOW, OnUpdateSlow)
	ON_COMMAND(IDC_SLOW, OnSlow)
	ON_UPDATE_COMMAND_UI(ID_FAST, OnUpdateFast)
	ON_COMMAND(ID_FAST, OnFast)
	ON_COMMAND(ID_TIMERTICK, OnCallTimerTick)
	ON_UPDATE_COMMAND_UI(ID_TIMERTICK, OnUpdateTimerTick)
	ON_COMMAND(ID_TRACEWIDTH, OnTraceWidth)
	ON_COMMAND(ID_VERYLARGERING, OnDropRing)
	ON_COMMAND(ID_MEDIUMRING, OnDropRing)
	ON_COMMAND(ID_SMALLRING, OnDropRing)
	ON_COMMAND(ID_HUGEWHEEL, OnDropWheel)
	ON_COMMAND(ID_VERYLARGEWHEEL, OnDropWheel)
	ON_COMMAND(ID_LARGEWHEEL, OnDropWheel)
	ON_COMMAND(ID_MEDIUMWHEEL, OnDropWheel)
	ON_COMMAND(ID_SMALLWHEEL, OnDropWheel)
	ON_COMMAND(ID_TINYWHEEL, OnDropWheel)
	ON_UPDATE_COMMAND_UI(ID_HUGEWHEEL, OnUpdateAnyWheel)
	ON_UPDATE_COMMAND_UI(ID_VERYLARGEWHEEL, OnUpdateAnyWheel)
	ON_UPDATE_COMMAND_UI(ID_LARGEWHEEL, OnUpdateAnyWheel)
	ON_UPDATE_COMMAND_UI(ID_MEDIUMWHEEL, OnUpdateAnyWheel)
	ON_UPDATE_COMMAND_UI(ID_SMALLWHEEL, OnUpdateAnyWheel)
	ON_UPDATE_COMMAND_UI(ID_TINYWHEEL, OnUpdateAnyWheel)
	ON_UPDATE_COMMAND_UI(ID_TRACEWIDTH, OnUpdateTraceWidth)
	//}}AFX_MSG_MAP
	// Standard printing commands

	ON_UPDATE_COMMAND_UI(ID_RED, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(ID_PURPLE, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(ID_YELLOW, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(ID_GREEN, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(ID_BLACK, OnUpdateColor)
	ON_UPDATE_COMMAND_UI(ID_HUGERING, OnUpdateAnyRing)
	ON_UPDATE_COMMAND_UI(ID_VERYLARGERING, OnUpdateAnyRing)
	ON_UPDATE_COMMAND_UI(ID_MEDIUMRING, OnUpdateAnyRing)
	ON_UPDATE_COMMAND_UI(ID_SMALLRING, OnUpdateAnyRing)

	ON_COMMAND(ID_FILE_PRINT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CScrollView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSpiroView construction/destruction
CSpiroView*	g_pView = NULL;

CSpiroView::CSpiroView() : m_ptWheelPosFirst(0, 0), m_ptHotSpotDragFigure(0, 0)
{
	m_nZoomNumer = 1;
	m_IDTimer = 0;
	m_nZoomDenom = 1;
	m_pAnchor = NULL;
	m_pWheel = NULL;
	m_bDrawingActive = false;
	m_bStartDrag = false;
	m_bDrawingDone = false;
	m_bDroppingAnchor = false;
	m_bDroppingWheel = false;
	m_bMovingPencil = false;
	m_nCurrentPenWidth = 1;  
	m_coCurrentPen = RGB(0, 0, 0);  //color of current pen
	m_nTracesPerTick = TRACES_PER_TICK_SLOW;
	m_dDataAnchorFirst = 0;
	m_dDataWheelFirst = 0;
	m_pDCMem = NULL;
	m_pBitmap = NULL;
	m_pBitmapDragFigure = NULL;
	m_pbitmapOld = NULL;
	m_pFigureDrag = NULL;
	m_pILDragFigure = NULL;
}

CSpiroView::~CSpiroView()
{
	delete m_pAnchor;
	delete m_pWheel;

	if (m_pDCMem != NULL)
	{
		ENSURE(m_pbitmapOld != NULL);
		m_pDCMem->SelectObject(m_pbitmapOld);
		delete m_pDCMem;
		delete m_pBitmap;
	}
	else
	{
		ASSERT(m_pbitmapOld == NULL);
		ASSERT(m_pBitmap == NULL);
	}
}

BOOL CSpiroView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CScrollView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CSpiroView drawing

void CSpiroView::OnDraw(CDC* pDC)
{
	ENSURE(pDC != NULL);
	
	CPaintDC*	pDCPaint;
	int			nWidthClip(0);  // Initialize to avoid compiler warnings.
	int			nHeightClip(0);  // Initialize to avoid compiler warnings.
	CRect		rectClip;
	CSpiroRect	rectLogClip;
	
	if (!pDC->IsPrinting())
	{
		ASSERT(pDC->IsKindOf(RUNTIME_CLASS(CPaintDC)));
		pDCPaint = (CPaintDC*)pDC;
		rectClip = pDCPaint->m_ps.rcPaint;
		rectLogClip = rectClip;
		pDC->DPtoLP(&rectLogClip);   // this will be the clip rectangle which includes the zoom factor in it
		nWidthClip = rectLogClip.Width();
		nHeightClip = rectLogClip.Height();
		// Prepare a memory DC to draw on
		if (nWidthClip <= 0 || nHeightClip >= 0)  // the clipping region is empty
			return;  // nothing to draw in this case
	}

	g_pView = this;
	CSpiroDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CDC* pDCUse = pDC;
	int nSavedDC(0);  // Initialized to avoid compiler warnings.

	CRgn*	prgnWheel = NULL;

	if (!pDC->IsPrinting())
	{
		if (m_pDCMem == NULL)
		{
			m_pDCMem = new CDC();
			ASSERT(m_pDCMem != NULL);
			VERIFY(m_pDCMem->CreateCompatibleDC(pDC));
			m_pDCMem->SetMapMode(MM_SPIRO);
		}

		int cxClip = rectClip.Width();
		int cyClip = rectClip.Height();
		ASSERT(cxClip > 0 && cyClip >0);

		if (m_pBitmap == NULL)
			m_pBitmap = new CBitmap();

		if (cxClip > m_sizeBitmap.cx || cyClip > m_sizeBitmap.cy)
		{
			if (m_pbitmapOld != NULL)
			{
				m_pDCMem->SelectObject(m_pbitmapOld);
				m_pBitmap->DeleteObject();
			}

			VERIFY(m_pBitmap->CreateCompatibleBitmap(pDC, cxClip, cyClip));
			m_pbitmapOld  = m_pDCMem->SelectObject(m_pBitmap);
			m_sizeBitmap.cx = cxClip;
			m_sizeBitmap.cy = cyClip;
		}

		CPoint ptViewportOrg = pDC->GetViewportOrg();
		ptViewportOrg.x -= rectClip.left;
		ptViewportOrg.y -= rectClip.top;
		m_pDCMem->SetViewportOrg(ptViewportOrg);
		m_pDCMem->SetWindowOrg(pDC->GetWindowOrg());

		CSpiroRect  rectDoc(rectLogClip);
		CSpiroRect	rectOut(rectDoc);  // strip to the right of the doc (vertical strip)

		int cx = pDoc->m_sizeExtent.cx * m_nZoomNumer / m_nZoomDenom;
		CBrush	br(GetSysColor(COLOR_3DLIGHT));

		if (rectDoc.right > cx)  // paint vertical strip
		{
			rectOut.left = cx;
			rectDoc.right = cx;
			m_pDCMem->FillRect(&rectOut, &br);
		}

		if (rectDoc.bottom < 0)
		{
			rectOut.SetRect(rectDoc.left, 0, cx, rectDoc.bottom);
			m_pDCMem->FillRect(&rectOut, &br);
			rectDoc.bottom = 0;
		}

		CBrush brush(GetSysColor(COLOR_WINDOW));
		m_pDCMem->FillRect(&rectDoc, &brush);

		pDCUse = m_pDCMem;
		nSavedDC = pDCUse->SaveDC();
		pDCUse->IntersectClipRect(0, pDoc->m_sizeExtent.cy * m_nZoomNumer / m_nZoomDenom, cx, 0);

		if (m_pWheel != NULL)
		{
			prgnWheel = new CRgn();
			m_pWheel->GetLogPieceRgn(prgnWheel, m_nZoomNumer, m_nZoomDenom);
		}
	}


	// draw the current figure
	pDoc->m_pFigureCurrent->Draw(pDCUse, m_nZoomNumer, m_nZoomDenom
												, prgnWheel, &rectLogClip);

	// draw all the other figures
	INT_PTR nLast = pDoc->m_arrPFigures.GetUpperBound();
	CFigure* pFig;
	for (int i = 0; i <= nLast; i++)
	{
		pFig = (CFigure*)pDoc->m_arrPFigures.GetAt(i);
		pFig->Draw(pDCUse, m_nZoomNumer, m_nZoomDenom, prgnWheel, &rectLogClip);
	}

	delete prgnWheel;

	if (!pDC->IsPrinting())
	{

		pDCUse->RestoreDC(nSavedDC);

		if (m_pAnchor != NULL) 
			m_pAnchor->Draw(m_pDCMem, m_nZoomNumer, m_nZoomDenom);

		if (m_pWheel != NULL)
			m_pWheel->Draw(m_pDCMem, m_nZoomNumer, m_nZoomDenom);

		// now transfer the information in the memory DC to the device DC
		VERIFY(pDC->BitBlt(rectLogClip.left, rectLogClip.top, nWidthClip, nHeightClip, 
													pDCUse, rectLogClip.left, rectLogClip.top, SRCCOPY));

	}
}

/////////////////////////////////////////////////////////////////////////////
// CSpiroView printing

BOOL CSpiroView::OnPreparePrinting(CPrintInfo* pInfo)
{
	BOOL bRet = DoPreparePrinting(pInfo);
	pInfo->m_nNumPreviewPages = 2;
	pInfo->SetMaxPage(2);   // will always print 2 pages
	return bRet;
}

void CSpiroView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CSpiroView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CSpiroView diagnostics

#ifdef _DEBUG
void CSpiroView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CSpiroView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CSpiroDoc* CSpiroView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSpiroDoc)));
	return (CSpiroDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSpiroView message handlers

void CSpiroView::OnInitialUpdate() 
{
	CScrollView::OnInitialUpdate();

	if (m_pAnchor != NULL)
	{
		delete m_pAnchor;
		m_pAnchor = NULL;
	}

	if (m_pWheel != NULL)
	{
		delete m_pWheel;
        m_pWheel = NULL;
	}

	m_bDrawingActive = false;
	m_bStartDrag = false;
	m_bDrawingDone = false;
	m_bDroppingAnchor = false;
	m_bDroppingWheel = false;
	m_bMovingPencil = false;
	m_dDataAnchorFirst = 0;
	m_dDataWheelFirst = 0;

	CSpiroDoc* pDoc = GetDocument();
	ENSURE(pDoc != NULL);
	SetScrollSizes(MM_SPIRO, pDoc->m_sizeExtent);
}

void CSpiroView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo) 
{
	CScrollView::OnPrepareDC(pDC, pInfo);
	
	CSpiroDoc* pDoc = GetDocument();
	ENSURE(pDoc != NULL);

	if (!pDC->IsPrinting())
		pDC->SetWindowOrg(0, pDoc->m_sizeExtent.cy * m_nZoomNumer / m_nZoomDenom);
}

void CSpiroView::OnUpdateAnyRing(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pAnchor == NULL && !m_bDroppingAnchor && !m_bDroppingWheel);	
}

void CSpiroView::OnUpdateAnyWheel(CCmdUI* pCmdUI) 
{
	// The wheel can act as a ring or as a wheel
	pCmdUI->Enable((m_pAnchor == NULL || m_pWheel == NULL) &&
					!m_bDroppingAnchor && !m_bDroppingWheel);
}

void CSpiroView::OnUpdateDraw(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pAnchor != NULL && m_pWheel != NULL);	
}

void CSpiroView::OnUpdatePause(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_bDrawingActive);	
}

void CSpiroView::OnPenWidth() 
{
	CSpiroDoc* pDoc = GetDocument();
	ENSURE(pDoc != NULL);

	pDoc->m_bThickPen = !pDoc->m_bThickPen; // toggle the width of the pen
}

void CSpiroView::OnUpdatePenWidth(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!m_bDrawingActive);	
}

BOOL CSpiroView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
{
	if (m_bDroppingAnchor)
	{
		::SetCursor(GetApp()->m_cursorRing);
		return TRUE;
	}

	if (m_bDroppingWheel)
	{
		::SetCursor(GetApp()->m_cursorWheel);
		return TRUE;
	}

	return CScrollView::OnSetCursor(pWnd, nHitTest, message);
}

void CSpiroView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	if (m_bDrawingActive)
		return;

	if (m_bDroppingAnchor || m_bDroppingWheel)
	{
		ASSERT(!m_bDrawingDone);
		CWheel* pWheelDrop = NULL;
		CRing*	pRingDrop = NULL;
		CSpiroDoc* pDoc = GetDocument();
		ENSURE(pDoc != NULL);

		//convert the client coordinates to logical coordinates
		CDC* pDC = GetDC();
		ENSURE(pDC != NULL);
		OnPrepareDC(pDC);

		// Convert client coordinates to Logical coordinates
		CPoint pointScaled(point);
		pDC->DPtoLP(&pointScaled);
		point.x = pointScaled.x * m_nZoomDenom / m_nZoomNumer;  // undo scaling effects
		point.y = pointScaled.y * m_nZoomDenom / m_nZoomNumer;

		CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
		ENSURE(pFrame != NULL && pFrame->IsKindOf(RUNTIME_CLASS(CMainFrame)));

		if (m_bDroppingAnchor)
		{
			ASSERT(m_iPieceDropped >= 0 && m_iPieceDropped < TOTALRINGS);
			pRingDrop = new CRing(CRing::m_rgnRads[m_iPieceDropped] - RINGWIDTH,
				CRing::m_rgnRads[m_iPieceDropped],
				CRing::m_rgco[m_iPieceDropped], RGB(0, 0, 0));

			ENSURE(pRingDrop != NULL);  
			m_bDroppingAnchor = false;
			ENSURE(m_pAnchor == NULL);
			m_pAnchor = pRingDrop;
			m_pAnchor->SetPosition(point);
			m_dDataAnchorFirst = m_pAnchor->GetFigData();
		}
		else if (m_bDroppingWheel)
		{
			CBasePiece** ppPiece = (m_pAnchor == NULL? &m_pAnchor : &m_pWheel);
			ASSERT(m_iPieceDropped >= 0 && m_iPieceDropped < TOTALWHEELS);
			pWheelDrop = new CWheel(CWheel::m_rgnRads[m_iPieceDropped],
								CWheel::m_rgco[m_iPieceDropped],
								CWheel::m_rgcoPattern[m_iPieceDropped]);
								

			ENSURE(pWheelDrop != NULL);
			ENSURE(*ppPiece == NULL);
			*ppPiece = pWheelDrop;
			m_bDroppingWheel = false;
			(*ppPiece)->SetPosition(point);

			if (m_pWheel != NULL)
			{
				m_pWheel->SetWheelMode();

				// set the default pen location. pDC and zoom ration are dummies
				m_pWheel->SetPenLocation(this, pDC, CPoint(0, 0), 1, 1);

				ENSURE(m_pAnchor != NULL);

				CPoint ptContact;
				double dAngle;
				// Get contact position from the anchor and set wheel position
				// Decides if wheel is internal in case of being a ring
				m_pAnchor->GetContactPosition(pointScaled, m_nZoomNumer, 
										m_nZoomDenom, ptContact, dAngle);
			
				if (m_pWheel->GetPerimeter() >= m_pAnchor->GetPerimeter())
				{
					pointScaled.x = 0;
					pointScaled.y = 0;   // force the wheel out of the ring

					// get contact position again to make sure it's right
					m_pAnchor->GetContactPosition(pointScaled, m_nZoomNumer, 
											m_nZoomDenom, ptContact, dAngle);
				}

 				m_pWheel->SetPosition(ptContact, dAngle);
				m_dDataWheelFirst = m_pWheel->GetFigData();
				m_ptWheelPosFirst = m_pWheel->m_ptPos;
				PressButton(0);  // get the color settings for the new wheel
				CreateFigure();
			}

			m_iPieceDropped += TOTALRINGS + 1;
#ifdef _DEBUG
			int nID = pFrame->m_wndToolBarSpiro.GetItemID(m_iPieceDropped);
			ASSERT(nID >= ID_ENORMOUSWHEEL && nID <= ID_TINYWHEEL);
#endif
		}

		// uncheck the button used to select the piece in the toolbar
		UINT nButtonID = pFrame->m_wndToolBarSpiro.GetItemID(m_iPieceDropped);
		pFrame->m_wndToolBarSpiro.GetToolBarCtrl().CheckButton(nButtonID, FALSE);

		// invalidate the region holding the ring
		CRgn	rgn;  // region occupied by the piece
		(m_pWheel != NULL? m_pWheel : m_pAnchor)->GetDevPieceRgn(pDC,
									&rgn, m_nZoomNumer, m_nZoomDenom, false);

		InvalidateRgn(&rgn, FALSE);
		m_iPieceDropped = -1; // reset to keep control on values.
		ReleaseDC(pDC);
		return;
	}

	// check if the user wants to drag the pen position

	CDC* pDC = GetDC();
	ENSURE(pDC != NULL);
	OnPrepareDC(pDC);
	CPoint pointScaled(point);
	pDC->DPtoLP(&pointScaled);   // gets the logical coord point value with scale into account

	if (m_pWheel != NULL)
	{
		if (m_pWheel->HitTest(pDC, point, m_nZoomNumer, m_nZoomDenom) == HIT_PEN_LOCATION)  // start drag operation
		{
			MSG		msg;

			// if there is a WM_LBUTTONUP in the queue do not drag pencil location
			if (!::PeekMessage(&msg, m_hWnd, WM_LBUTTONUP, WM_LBUTTONUP, PM_NOREMOVE))
			{
				ClientToScreen(&point); // convert to screen coordinates
				CRect rectWindow;
				GetWindowRect(&rectWindow);
				point.x -= rectWindow.left;
				point.y -= rectWindow.top;  // point relative to windows corner

				CImageList& il = GetApp()->m_imageList;
				::ShowCursor(FALSE);
				il.BeginDrag(0, CPoint(0, 47));
				il.DragEnter(this, point);
				m_bMovingPencil = true;
				SetCapture();
			}
		}
	}

	for (;;) 
	{
		CRgn	rgn;
		MSG		msg;

		if (::PeekMessage(&msg, m_hWnd, WM_LBUTTONUP, WM_LBUTTONUP, PM_NOREMOVE))  // no drag is being requested
			break;

		if (m_pWheel != NULL)
		{
			m_pWheel->GetLogPieceRgn(&rgn, m_nZoomNumer, m_nZoomDenom);
			if (rgn.PtInRegion(pointScaled))  // clicked on wheel.  Don't do anything
				break;

			rgn.DeleteObject();
		}

		if (m_pAnchor != NULL)
		{
			m_pAnchor->GetLogPieceRgn(&rgn, m_nZoomNumer, m_nZoomDenom);
			if (rgn.PtInRegion(pointScaled))   // clicked on the anchor
				break;

			rgn.DeleteObject();
		}

		// find now if the user clicked on a Figure.  The current Figure cannot be dragged.  This is by design
		CSpiroDoc*	pDoc = GetDocument();
		INT_PTR		iPic;
		CFigure*	pFigure;
		CSpiroRect	rect;

		for (iPic = pDoc->m_arrPFigures.GetUpperBound(); iPic >= 0; iPic--)
		{
			pFigure = (CFigure*)pDoc->m_arrPFigures.GetAt(iPic);
			ENSURE(pFigure != NULL);
			pFigure->GetBoundingRect(&rect);
			rect.Scale(m_nZoomNumer, m_nZoomDenom);
			if (pointScaled.x < rect.left || pointScaled.x >= rect.right ||
					pointScaled.y > rect.top || pointScaled.y <= rect.bottom)
			{
				continue;
			}

			bool bCopy = (nFlags & MK_CONTROL) == MK_CONTROL;
			m_pFigureDrag = (bCopy? new CFigure(pFigure) : pFigure);

			if (!bCopy)
				pDoc->m_arrPFigures.RemoveAt(iPic);

			ENSURE(m_pILDragFigure == NULL);

			// First draw the Figure into a memery DC using an allocated bitmap
			CDC	dcMem;
			ENSURE(pDC != NULL);

			VERIFY(dcMem.CreateCompatibleDC(pDC));
			dcMem.SetMapMode(MM_SPIRO);
			dcMem.SetViewportOrg(0, 0);
			dcMem.SetWindowOrg(rect.left, rect.top);

			CSpiroRect	rectBitmap(rect);
			dcMem.LPtoDP(&rectBitmap);
			ASSERT(rectBitmap.left == 0 && rectBitmap.top == 0);

			int			nWidth = rectBitmap.right;
			int			nHeight = rectBitmap.bottom;

			CBitmap*	pbmOld = NULL;
			
			ASSERT(m_pBitmapDragFigure == NULL);
			m_pBitmapDragFigure = new CBitmap();
			m_pBitmapDragFigure->CreateCompatibleBitmap(pDC, nWidth, nHeight);
			pbmOld = dcMem.SelectObject(m_pBitmapDragFigure);

		//	dcMem.PatBlt(rect.left, rect.top, rect.Width(), rect.Height(), WHITENESS);
			CBrush	brush;
			brush.CreateStockObject(WHITE_BRUSH);
			dcMem.FillRect(&rect, &brush);
			m_pFigureDrag->Draw(&dcMem, m_nZoomNumer, m_nZoomDenom, NULL, &rect);
			dcMem.SelectObject(pbmOld);
			// Then create an imagelist and add the bitmap to it
			ASSERT(m_pILDragFigure == NULL);
			m_pILDragFigure = new CImageList();				
			VERIFY(m_pILDragFigure->Create(nWidth, nHeight, ILC_COLOR | ILC_MASK, 1, 1));
			VERIFY(m_pILDragFigure->Add(m_pBitmapDragFigure, RGB(255, 255, 255)) == 0);

			m_bStartDrag = true;  // Enter the drag on first mouse move

			//calculate the hot spot for the figure
			m_ptHotSpotDragFigure.x = pointScaled.x - rect.left;
			m_ptHotSpotDragFigure.y = pointScaled.y - rect.bottom;
			pDC->SetWindowOrg(0, rect.top - rect.bottom);
			pDC->SetViewportOrg(0, 0);
			pDC->LPtoDP(&m_ptHotSpotDragFigure);
			m_pILDragFigure->BeginDrag(0, m_ptHotSpotDragFigure);
			SetCapture();
			break;
		}

		break;
	}

	ReleaseDC(pDC);
	CScrollView::OnLButtonDown(nFlags, point);
}

void CSpiroView::OnMouseMove(UINT nFlags, CPoint point) 
{
	if (m_bMovingPencil || m_pFigureDrag != NULL)  // the user is dragging the pencil location
	{
		CPoint ptWindow(point);
		ClientToScreen(&ptWindow);
		CRect	rectWindow;
		GetWindowRect(&rectWindow);
		ptWindow.Offset(-rectWindow.left, -rectWindow.top);

		CImageList* pImList = m_bMovingPencil? &GetApp()->m_imageList : m_pILDragFigure;

		ENSURE(pImList != NULL);
		if (m_bStartDrag)
		{
			ENSURE(m_pFigureDrag != NULL);
			m_bStartDrag = false;
			CSpiroRect rect;
			m_pFigureDrag->GetBoundingRect(&rect);
			rect.Scale(m_nZoomNumer, m_nZoomDenom);
			CDC* pDC = GetDC();
			ENSURE(pDC != NULL);
			OnPrepareDC(pDC);
			pDC->LPtoDP(&rect);
			ReleaseDC(pDC);
			rect.InflateRect(4, 4);
			InvalidateRect(&rect);
			pImList->DragLeave(this);
			UpdateWindow();
			pImList->DragEnter(this, ptWindow);
		}
		else
			pImList->DragMove(ptWindow);

		return;
	}

	CScrollView::OnMouseMove(nFlags, point);
}

// receives a pointer to the array of ID's and the count of elements in the array
void CSpiroView::OnDropPiece(int* rgID, int nCount)
{
#ifdef _DEBUG
	int nChosen = -1;
#endif

	CMainFrame*		pFrame = (CMainFrame*)AfxGetMainWnd();
	ENSURE(pFrame != NULL && pFrame->IsKindOf(RUNTIME_CLASS(CMainFrame)));

	int i;
	for (i = 0; i < nCount; i ++)
	{
		if (pFrame->m_wndToolBarSpiro.GetToolBarCtrl().IsButtonChecked(rgID[i]))
#ifdef _DEBUG
		{
			ASSERT(nChosen == -1);
			nChosen = i;
		}
#else  // !_DEBUG
			break;
#endif	// !_DEBUG
	}

#ifdef _DEBUG
	VERIFY((i = nChosen) != -1);
#endif

	m_iPieceDropped = i;
}

void CSpiroView::OnDropRing() 
{
	static const int rgID[] = {ID_HUGERING, ID_VERYLARGERING,
								ID_MEDIUMRING, ID_SMALLRING};

	OnDropPiece((int*)rgID, elementsof(rgID));
	m_bDroppingAnchor = true;
}

void CSpiroView::OnDropWheel() 
{
	static const int rgID[] = {ID_ENORMOUSWHEEL, ID_HUGEWHEEL, ID_VERYLARGEWHEEL, 
								ID_LARGEWHEEL, ID_MEDIUMWHEEL,
								ID_SMALLWHEEL, ID_TINYWHEEL};

	OnDropPiece((int*)rgID, elementsof(rgID));
	m_bDroppingWheel = true;
}

void CSpiroView::OnUpdateRemoveRing(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pAnchor != NULL && !m_bDroppingAnchor && !m_bDroppingWheel && !m_bDrawingActive);	
}

void CSpiroView::OnUpdateRemoveWheel(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pWheel != NULL && !m_bDroppingAnchor && !m_bDroppingWheel && !m_bDrawingActive);	
}

void CSpiroView::OnRemovePiece(CBasePiece** ppPiece) 
{
	ENSURE(ppPiece != NULL && *ppPiece != NULL);
	CRgn	rgnPiece;

	CDC*	pDC = GetDC();
	ENSURE(pDC != NULL);
	OnPrepareDC(pDC);

	(*ppPiece)->GetDevPieceRgn(pDC, &rgnPiece, m_nZoomNumer, m_nZoomDenom, true);

	InvalidateRgn(&rgnPiece);
	delete *ppPiece;
	*ppPiece = NULL;
	ReleaseDC(pDC);
	GetDocument()->TransferCurrentFigure();  // make the current figure permanent
	m_bDrawingDone = false;
}

void CSpiroView::OnRemoveRing()
{
	ENSURE(m_pAnchor != NULL);
	OnRemovePiece(&m_pAnchor);
	if (m_pWheel != NULL)
		OnRemovePiece(&m_pWheel);
}

void CSpiroView::OnRemoveWheel() 
{
	OnRemovePiece(&m_pWheel);
}

void CSpiroView::OnUpdateZoomIn(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_nZoomNumer != 1 || m_nZoomDenom != 1);
}

void CSpiroView::OnZoomIn()
{
	ZoomChange(1);  
}

void CSpiroView::ZoomChange(int nChange)
{
	m_nZoomNumer = (m_nZoomNumer * 4 / m_nZoomDenom) + nChange;
	m_nZoomDenom = 4;
	if (m_nZoomDenom % m_nZoomNumer == 0)
	{
		m_nZoomDenom /= m_nZoomNumer;
		m_nZoomNumer = 1;
	}

	// change the extent of the document to match the new zoom
	CSpiroDoc* pDoc = GetDocument();
	ENSURE(pDoc != NULL);
	SetScrollSizes(MM_SPIRO, CSize(pDoc->m_sizeExtent.cx * m_nZoomNumer / m_nZoomDenom,
						pDoc->m_sizeExtent.cy * m_nZoomNumer / m_nZoomDenom));

	Invalidate();  // invalidate the window so it's drawn again
}

void CSpiroView::OnZoomOut()
{
	ZoomChange(-1);
}

void CSpiroView::OnUpdateZoomOut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_nZoomNumer != 1 || m_nZoomDenom != 4);	
}

void CSpiroView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	if (m_bMovingPencil)
	{
		CImageList& il = GetApp()->m_imageList;
		il.DragLeave(this);
		il.EndDrag();
		::ShowCursor(TRUE);

		ENSURE(m_pWheel != NULL);
		CDC* pDC = GetDC();
		ENSURE(pDC != NULL);
		OnPrepareDC(pDC);

		// undo the effect of the zoom factor on the point value
		pDC->DPtoLP(&point);
		point.x = point.x * m_nZoomDenom / m_nZoomNumer;
		point.y = point.y * m_nZoomDenom / m_nZoomNumer;
		if (m_pWheel->SetPenLocation(this, pDC, point, m_nZoomNumer, m_nZoomDenom))
		{
			GetDocument()->TransferCurrentFigure();
			CreateFigure();  // create figure for the new pen location
		}

		ReleaseDC(pDC);
		ReleaseCapture();
		m_bMovingPencil = false;
	}
	else if (m_pFigureDrag != NULL)
	{
		ENSURE(m_pILDragFigure != NULL);

		CPoint ptWindow(point);
		CDC* pDC = GetDC();
		ENSURE(pDC != NULL);

		// get new position for the figure being drawn and insert it into figure arrays
		
		CPoint	ptCorner(point.x - m_ptHotSpotDragFigure.x, point.y - m_ptHotSpotDragFigure.y);
		OnPrepareDC(pDC);
		pDC->DPtoLP(&ptCorner);   // convert corner of figure to logical coords

		ptCorner.x = ptCorner.x * m_nZoomDenom / m_nZoomNumer;  // undo effect of zooming
		ptCorner.y = ptCorner.y * m_nZoomDenom / m_nZoomNumer;


		if (m_pFigureDrag->MoveFigure(ptCorner, GetDocument()))   // move figure to new place
		{
			CSpiroRect	rect;
			m_pFigureDrag->GetBoundingRect(&rect);
			rect.Scale(m_nZoomNumer, m_nZoomDenom);
			pDC->LPtoDP(&rect);
			InvalidateRect(&rect);
			ReleaseDC(pDC);
		}

 		m_pILDragFigure->DragLeave(this);
		m_pILDragFigure->EndDrag();
 		UpdateWindow();
		delete m_pILDragFigure;  
		delete m_pBitmapDragFigure;   
		m_pBitmapDragFigure = NULL;
		m_pILDragFigure = NULL;

		ReleaseCapture();
		m_pFigureDrag = NULL;
	}

	CScrollView::OnLButtonUp(nFlags, point);
}

int CompareLong(const void* pn1, const void* pn2)   // used for qsorting an array
{
	return *(long*)pn1 - *(long*)pn2;
}

long CSpiroView::GetWheelDistanceForFigure() const
{
	ENSURE(m_pWheel != NULL && m_pAnchor != NULL);
	double	dPerimWheel = m_pWheel->GetPerimeter();
	double	dPerimAnchor = m_pAnchor->GetPerimeter();

	bool	bInverted(false);	// Anchor and wheel swapped to have anchor > wheel.

	if (dPerimAnchor < dPerimWheel)
	{
		bInverted = true;
		double d = dPerimAnchor;
		dPerimAnchor = dPerimWheel;
		dPerimWheel = d;
	}

	double	dRemain = 0;
	long	rgCycleOrder[200]; 
	double	rgdCycleLimits[2][200];  // first and last mark in every cycle
	double	dCurrentPos = 0.0;
	int		nTurnsThisCycle;
	int		nTotalTurns = 0;
	int		i;
	long	nTolerance = m_pAnchor->GetCycleError();  // returns distance tolerance for one figure
	int		iCycle;

	for (iCycle = 0;iCycle < 200;iCycle++)
	{
		nTurnsThisCycle = (long)((dPerimAnchor + dRemain) / dPerimWheel);
		rgdCycleLimits[0][iCycle] = dCurrentPos + dPerimWheel;
		while (rgdCycleLimits[0][iCycle] - dPerimAnchor >= 0.0)
			rgdCycleLimits[0][iCycle] -= dPerimAnchor;

		rgdCycleLimits[1][iCycle] = dCurrentPos + nTurnsThisCycle * dPerimWheel;
		while (rgdCycleLimits[1][iCycle] - dPerimAnchor >= 0.0)
			rgdCycleLimits[1][iCycle] -= dPerimAnchor;

		ASSERT(rgdCycleLimits[1][iCycle] >= 0.0 && rgdCycleLimits[1][iCycle] < dPerimAnchor);

		rgCycleOrder[iCycle] = iCycle;  // rgCycleOrder says the order of the columns

		// sort the cycle order to find which columns go first
		for (i = 0; i < iCycle; i++)
		{
			// is new cycle being inserted at position i?
			if (rgdCycleLimits[0][rgCycleOrder[i]] > rgdCycleLimits[0][iCycle])
			{
				//yes.  Insert iCycle in this position in rgCycleOrder
				memmove_s((int*)rgCycleOrder + i + 1, (iCycle - i) * sizeof(int), (int*)rgCycleOrder + i, (iCycle - i) * sizeof(int));
				rgCycleOrder[i] = iCycle;
				break;
			}
		}

		double	dLastGap(0);  // Initialize to avoid compiler warnings.
		double	dThisGap;
		double	dLastPos;
		double	dThisPos;

		// check if the values are so close to the origin that the cycle is complete
		bool bFirstTurnCloses = rgdCycleLimits[0][iCycle] < (double)nTolerance;
		if (bFirstTurnCloses ||   // close to origin? check gaps
				dPerimAnchor - rgdCycleLimits[1][iCycle] < (double)nTolerance ||
				rgdCycleLimits[1][iCycle] < 0.000000001)
		{
			dLastPos = rgdCycleLimits[0][rgCycleOrder[0]];
			for (i = 1; i < iCycle; i++)
			{
				dThisGap = (dThisPos = rgdCycleLimits[0][rgCycleOrder[i]]) - dLastPos;
				if (i > 1 && abs((long)(dThisGap - dLastGap)) > nTolerance / 4)   // there are gaps to be filled in
					break;

				dLastGap = dThisGap;
				dLastPos = dThisPos;
			}

			if (i == iCycle)
			{
				nTotalTurns += bFirstTurnCloses? 1 : nTurnsThisCycle;
				break;
			}
		}

		nTotalTurns += nTurnsThisCycle;
		dCurrentPos = rgdCycleLimits[1][iCycle];
		dRemain = dPerimAnchor - dCurrentPos;
	}

	if (bInverted)   // adjust the number of turns 
	{
		double d = (double)nTotalTurns * dPerimWheel / dPerimAnchor;
		nTotalTurns = (long)d;
		if (d - (double)nTotalTurns > 0.9)
			nTotalTurns++;

		dPerimWheel = dPerimAnchor;
	}

	ASSERT(nTotalTurns < 200 && nTotalTurns > 0);
	return (long)(nTotalTurns * dPerimWheel);
}

// This routine creates the figure when the wheel is dropped or the pen is moved.
// It is very critical that these calculations are done as fast as possible.
void CSpiroView::CreateFigure()
{
	long		nTotalDistance;
	CSpiroDoc*	pDoc = GetDocument();
	ENSURE(pDoc != NULL);
	CFigure*	pFigure = pDoc->m_pFigureCurrent;

	ENSURE(pFigure != NULL);
	ENSURE(m_pWheel != NULL && m_pAnchor != NULL);

	m_ptWheelPosFirst = m_pWheel->m_ptPos;
	m_dDataWheelFirst = m_pWheel->GetFigData();
	double dAnchorDataStart = m_pAnchor->GetFigData();

	nTotalDistance = GetWheelDistanceForFigure();  // get the total wheel travel distance
	m_pWheel->SetAngleDelta(STEP_DISTANCE, m_pAnchor->ReverseWheelDirection());
	m_pAnchor->SetAngleDelta(STEP_DISTANCE, false/*dummy value*/);

	CPoint ptPen;
	m_pWheel->GetPenLocation(&ptPen);

	CPoint	ptContact;
	double	dAngle;
	double	dAngleExtra;

	pFigure->AddCommand(SET_PEN_WIDTH, m_nCurrentPenWidth);
	m_pWheel->m_icoCurrent = -1;
	ASSERT(m_pWheel->m_nColorCount > 0);
	m_coCurrentPen = m_pWheel->m_rgCo[0];
	pFigure->AddCommand(MOVE_TO, ptPen, m_pWheel->m_ptPos, m_pWheel->GetFigData(), m_pAnchor->GetFigData());

	long	nTraces = nTotalDistance / STEP_DISTANCE;

	ASSERT(m_pWheel->m_icoCurrent >= -1 && m_pWheel->m_icoCurrent <= m_pWheel->m_nColorCount);
	ASSERT(m_pWheel->m_nColorCount > 0);
	pFigure->m_nTracesPerColor = nTraces / m_pWheel->m_nColorCount;
	pFigure->m_nTracesThisColor = 0;  // force color change upon starting

	for (long i = 0; i < nTraces; i++)  // travel until very close to the end
	{
		m_pAnchor->AdvanceTrace(ptContact, dAngle, dAngleExtra); // returns point of contact
		m_pWheel->AdvanceTrace(ptContact, dAngle, dAngleExtra);
		m_pWheel->GetPenLocation(&ptPen);  
		pFigure->AddCommand((i == 0? MOVE_TO : LINE_TO), ptPen, 
							m_pWheel->m_ptPos, m_pWheel->GetFigData(),
							m_pAnchor->GetFigData());
	}

	m_pWheel->m_ptPos = m_ptWheelPosFirst;
	m_pWheel->SetFigData(m_dDataWheelFirst);
	m_pAnchor->SetFigData(dAnchorDataStart);
}

void CSpiroView::OnUpdateDrawPattern(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!m_bDrawingDone && m_pAnchor != NULL && m_pWheel != NULL);
}

void CALLBACK  CSpiroView::TimerCallBack(HWND , UINT , UINT_PTR , DWORD )
{
	ENSURE(g_pView != NULL && g_pView->IsKindOf(RUNTIME_CLASS(CSpiroView)));
	if (!g_pView->m_bDrawingActive)  //waiting for the timer to be killed
		return;

	CSpiroDoc* pDoc = g_pView->GetDocument();
	CFigure* pFigure = pDoc->m_pFigureCurrent;
	ENSURE(pFigure != NULL);

	int nLast =   min(pFigure->m_nTotalDrawn + g_pView->m_nTracesPerTick,
					pFigure->m_arrCommands.GetUpperBound());

	if (nLast == -1)
		return;

	int nFirst = pFigure->m_nTotalDrawn + 1;
	CFigCommand figCommand;

	// Will now invalidate the rectangle that needs to be drawn

	CSpiroRect	rect(1200, 0, 0, 1800);

	// go to the last known point in the pattern and move the pen to that position
	int i;
	for (i = 1; nFirst - i >= 0; i++)
	{
		figCommand = pFigure->m_arrCommands.GetAt(nFirst - i);
		if (figCommand.m_type == MOVE_TO || figCommand.m_type == LINE_TO)
		{
			rect.left = rect.right = figCommand.m_point.x;
			rect.top = rect.bottom = figCommand.m_point.y;
			break;
		}
	}

	for (; nFirst <= nLast; nFirst++)
	{
		figCommand = pDoc->m_pFigureCurrent->m_arrCommands.GetAt(nFirst);
		if (figCommand.m_type == SET_PEN_WIDTH || figCommand.m_type == CHANGE_COLOR)
			continue;  // this does not change the area to be invalidated.

		// do we need to change color according to the selection?
		if (pFigure->m_nTracesThisColor-- == 0 && 
				g_pView->m_pWheel->m_icoCurrent != g_pView->m_pWheel->m_nColorCount - 1)
		{
			figCommand.m_type = CHANGE_COLOR;
			ASSERT(g_pView->m_pWheel->m_icoCurrent >= -1);
			figCommand.m_co = g_pView->m_pWheel->m_rgCo[++g_pView->m_pWheel->m_icoCurrent];
			pFigure->m_arrCommands.InsertAt(nFirst, figCommand);
			nLast++;
			pFigure->m_nTracesThisColor = pFigure->m_nTracesPerColor;
			continue;
		}

		if (pFigure->m_nTracesThisColor == -1)
			pFigure->m_nTracesThisColor = pFigure->m_nTracesPerColor;

		ASSERT(figCommand.m_type == MOVE_TO || figCommand.m_type == LINE_TO);
		if (figCommand.m_point.x < rect.left)
			rect.left = figCommand.m_point.x;
		if (figCommand.m_point.x + 2 > rect.right)
			rect.right = figCommand.m_point.x + 2;
		if (figCommand.m_point.y > rect.top)
			rect.top = figCommand.m_point.y;
		if (figCommand.m_point.y - 2 < rect.bottom)
			rect.bottom = figCommand.m_point.y - 2;
	}

	pFigure->m_nTotalDrawn = nLast;
	ASSERT(nFirst == nLast + 1);  // make sure the while executed
	// now set the new position for the wheel
	ENSURE(g_pView->m_pWheel != NULL);
	g_pView->m_pWheel->MovePiece(g_pView, figCommand.m_ptWheelPos, figCommand.m_dWheelData,
						g_pView->m_nZoomNumer, g_pView->m_nZoomDenom);

	rect.Scale(g_pView->m_nZoomNumer, g_pView->m_nZoomDenom);
	CDC* pDC = g_pView->GetDC();
	g_pView->OnPrepareDC(pDC);
	pDC->LPtoDP(&rect);
	if (rect.left < rect.right && rect.top < rect.bottom)
		g_pView->InvalidateRect(&rect);  // Redraw area covering new lines

	g_pView->ReleaseDC(pDC);

	if (nLast == pDoc->m_pFigureCurrent->m_arrCommands.GetUpperBound() &&
						g_pView->m_IDTimer != 0)
	{
		g_pView->PostMessage(WM_COMMAND, ID_END_DRAWING );  // kill the timer
		g_pView->m_bDrawingActive = false;
	}

	pDoc->SetModifiedFlag();
}

void CSpiroView::OnDrawPattern() 
{
	ASSERT(!m_bDrawingActive);
	g_pView = this;
	m_IDTimer = SetTimer(1, 100, TimerCallBack);
	ASSERT(m_IDTimer != 0);
	m_bDrawingActive = true;

	// enable the pause button
	ENSURE(m_pWheel != NULL);
	CMainFrame* pFrame = (CMainFrame *)AfxGetMainWnd();
	ENSURE(pFrame != NULL && pFrame->IsKindOf(RUNTIME_CLASS(CMainFrame)));
	CToolBarCtrl& tb = pFrame->m_wndToolBar.GetToolBarCtrl();
	tb.SetState(ID_PAUSEDRAWING, TBSTATE_ENABLED);
	tb.SetState(ID_DRAWPATTERN, 0);
	CToolBarCtrl& tbctrl = pFrame->m_wndToolBarSpiro.GetToolBarCtrl();
	tbctrl.SetState(ID_REMOVERING, 0);
	tbctrl.SetState(ID_REMOVEWHEEL, 0);
}

void CSpiroView::OnEndDrawing()
{
	ASSERT(m_IDTimer != 0);
	ASSERT(!m_bDrawingActive);
	VERIFY(KillTimer(m_IDTimer));
	m_IDTimer = 0;
	ENSURE(m_pAnchor != NULL);
	m_pAnchor->SetFigData(m_dDataAnchorFirst);
	ENSURE(m_pWheel != NULL);
	m_pWheel->MovePiece(this, m_ptWheelPosFirst, m_dDataWheelFirst, m_nZoomNumer, m_nZoomDenom);
	m_pWheel->m_icoCurrent = -1;  // set the current color to nothing.
}


BOOL CSpiroView::OnEraseBkgnd(CDC*) 
{
	return TRUE;
}

void CSpiroView::OnBlack() 
{
	PressButton(ID_BLACK);
}

void CSpiroView::PressButton(UINT id)
{
	UINT rgID[] = {ID_BLUE, ID_RED, ID_GREEN, ID_YELLOW, ID_PURPLE};
	COLORREF rgCo[] = {RGB(0, 0, 255), RGB(255, 0, 0), 
						RGB(128, 128, 0), RGB(128, 64, 64), RGB(255, 0, 255)};

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	ENSURE(pFrame != NULL && pFrame->IsKindOf(RUNTIME_CLASS(CMainFrame)));
	CToolBarCtrl& tbctrl = pFrame->m_wndToolBar.GetToolBarCtrl();

	bool bCheck = tbctrl.IsButtonChecked(id) != 0;
	tbctrl.CheckButton(id, bCheck);

	int i;

	ENSURE(m_pWheel != NULL);     // otherwise the buttons should be disabled.
	m_pWheel->m_nColorCount = 0;

	// if pressed the black button, uncheck all the other colors
	if (bCheck && id == ID_BLACK)
	{
		for (i = 0; i < elementsof(rgID); i++)
			tbctrl.CheckButton(rgID[i], FALSE);

		m_coCurrentPen = RGB(0, 0, 0);
		m_pWheel->m_nColorCount = 1;
		m_pWheel->m_rgCo[0] = RGB(0, 0, 0);
	}
	else
	{
		// if all the buttons are unchecked, check the black
		// if any button is checked, uncheck the black
		for (i = 0; i < elementsof(rgID); i++)
		{
			if (tbctrl.IsButtonChecked(rgID[i]))
			{
				m_pWheel->m_rgCo[m_pWheel->m_nColorCount++] = rgCo[i];
				tbctrl.CheckButton(ID_BLACK, FALSE);  // inefficient, but not terribly awful
			}
		}

		if (m_pWheel->m_nColorCount == 0)
		{
			tbctrl.CheckButton(ID_BLACK, TRUE);
			m_pWheel->m_nColorCount = 1;
			m_pWheel->m_rgCo[0] = RGB(0, 0, 0);
		}
	}

	// set the color information for the current figure
	CFigure* pFigure = GetDocument()->m_pFigureCurrent;
	ENSURE(pFigure != NULL);
	long nTracesLeft = pFigure->m_nTotalTraces - pFigure->m_nTotalDrawn;
	ASSERT(m_pWheel->m_nColorCount != 0);
	pFigure->m_nTracesPerColor = nTracesLeft / m_pWheel->m_nColorCount;
	pFigure->m_nTracesThisColor = 0;  // force a color change upon starting
	m_pWheel->m_icoCurrent = -1;  // restart current color count

	// update pen color on the display
	CSpiroRect rectPen;
	m_pWheel->GetPenRect(&rectPen);
	rectPen.Scale(m_nZoomNumer, m_nZoomDenom);
	CDC* pDC = GetDC();
	OnPrepareDC(pDC);
	pDC->LPtoDP(&rectPen);
	InvalidateRect(&rectPen);
	ReleaseDC(pDC);
}

void CSpiroView::OnBlue() 
{
	PressButton(ID_BLUE);	
}

void CSpiroView::OnGreen() 
{
	PressButton(ID_GREEN);	
}

void CSpiroView::OnPurple() 
{
	PressButton(ID_PURPLE);	
}

void CSpiroView::OnRed() 
{
	PressButton(ID_RED);	
}

void CSpiroView::OnYellow() 
{
	PressButton(ID_YELLOW);	
}

void CSpiroView::OnUpdateColor(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_pWheel != NULL && !m_bDrawingActive);
}

void CSpiroView::OnUpdatePauseDrawing(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_bDrawingActive);	
}

void CSpiroView::OnPauseDrawing() 
{
	KillTimer(m_IDTimer);
	m_bDrawingActive = false;	
}

void CSpiroView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	CSpiroDoc*	pDoc = GetDocument();
	ENSURE(pDC != NULL);

	CRect rect(pInfo->m_rectDraw);
	rect.NormalizeRect();
	long  cyDiff = max(0, GetDocument()->m_sizeExtent.cy / 2 - rect.Height());

	if (pInfo->m_nCurPage == 1)
		pDC->SetWindowOrg(0, pDoc->m_sizeExtent.cy - cyDiff);  // clip off the top if necessary
	else
		pDC->SetWindowOrg(0, pDoc->m_sizeExtent.cy / 2);  // never clip on the second page

	CScrollView::OnPrint(pDC, pInfo);
}

void CSpiroView::OnUpdateSlow(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_nTracesPerTick != TRACES_PER_TICK_SLOW);	
}

void CSpiroView::OnSlow() 
{
	m_nTracesPerTick = TRACES_PER_TICK_SLOW;	
}

void CSpiroView::OnUpdateFast(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(m_nTracesPerTick != TRACES_PER_TICK_FAST);	
}

void CSpiroView::OnFast() 
{
	m_nTracesPerTick = TRACES_PER_TICK_FAST;	
}

void CSpiroView::OnCallTimerTick() 
{
	bool bDrawingActiveMode = m_bDrawingActive;
	m_bDrawingActive = true;
	TimerCallBack(m_hWnd, WM_TIMER, 0, 0);	
	m_bDrawingActive = bDrawingActiveMode;
}

void CSpiroView::OnUpdateTimerTick(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(!m_bDrawingActive && !m_bDrawingDone && m_pWheel != NULL && m_pAnchor != NULL);
}


void CSpiroView::OnTraceWidth() 
{
	CMainFrame*		pFrame = (CMainFrame*)AfxGetMainWnd();
	ENSURE(pFrame != NULL && pFrame->IsKindOf(RUNTIME_CLASS(CMainFrame)));
	CToolBarCtrl& tbctrl = pFrame->m_wndToolBar.GetToolBarCtrl();
	m_nCurrentPenWidth = tbctrl.IsButtonChecked(ID_TRACEWIDTH)? 2 : 1;
	CFigure* pFig = GetDocument()->m_pFigureCurrent;
	if (pFig != NULL)  // change the command that sets the pen width
	{
		INT_PTR iLim = pFig->m_arrCommands.GetSize();					  
		int i;
		CFigCommand figCommand;
		for (i = 0; i < iLim; i++)
		{
			figCommand = pFig->m_arrCommands.GetAt(i);
			if (figCommand.m_type != SET_PEN_WIDTH)
				continue;

			figCommand.m_nPenWidth = m_nCurrentPenWidth;
			pFig->m_arrCommands.SetAt(i, figCommand);
			break;
		}

		ASSERT(iLim == 0 || i < iLim);
	}
}

void CSpiroView::OnUpdateTraceWidth(CCmdUI* pCmdUI) 
{
	CSpiroDoc* pDoc = GetDocument();
	ENSURE(pDoc != NULL && pDoc->IsKindOf(RUNTIME_CLASS(CSpiroDoc)));
	pCmdUI->Enable(pDoc->m_pFigureCurrent != NULL && pDoc->m_pFigureCurrent->m_nTotalDrawn == 0);
}
