// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// GestureDemoView.cpp : implementation of the CGestureDemoView class
//

#include "stdafx.h"
#include <math.h>
#include "GestureDemo.h"
#include "MainFrm.h"

#include "GestureDemoDoc.h"
#include "GestureDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define PI 3.1415926535897932384626433832795

// CGestureDemoView

IMPLEMENT_DYNCREATE(CGestureDemoView, CView)

BEGIN_MESSAGE_MAP(CGestureDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CGestureDemoView::OnFilePrintPreview)
	ON_WM_ERASEBKGND()
	ON_COMMAND(IDC_RESET, &CGestureDemoView::OnResetConfig)
END_MESSAGE_MAP()

// CGestureDemoView construction/destruction

CGestureDemoView::CGestureDemoView()
{
	m_dblZoomRatio = 1.;
	m_ptCenter = m_ptOffset = CPoint(0, 0);
	m_dblAngle = m_dblAngleStart = 0.;
	m_bInZoom = FALSE;
	m_bInPan = FALSE;
	m_bInRotate = FALSE;

	Gdiplus::GdiplusStartupInput input;
	Gdiplus::GdiplusStartupOutput output;
	Gdiplus::Status status = Gdiplus::GdiplusStartup(&m_ulGDIPlusToken, &input, &output);
	if (status != Gdiplus::Ok)
	{
		m_ulGDIPlusToken = 0;
	}
}

CGestureDemoView::~CGestureDemoView()
{
	if (m_ulGDIPlusToken != 0)
	{
		Gdiplus::GdiplusShutdown(m_ulGDIPlusToken);
		m_ulGDIPlusToken = 0;
	}
}

BOOL CGestureDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CGestureDemoView printing


void CGestureDemoView::OnFilePrintPreview()
{

	AFXPrintPreview(this);

}

BOOL CGestureDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CGestureDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CGestureDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CGestureDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CGestureDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
}


// CGestureDemoView diagnostics

#ifdef _DEBUG
void CGestureDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CGestureDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CGestureDemoDoc* CGestureDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CGestureDemoDoc)));
	return (CGestureDemoDoc*)m_pDocument;
}
#endif //_DEBUG


// CGestureDemoView message handlers

void CGestureDemoView::OnInitialUpdate()
{
	CView::OnInitialUpdate();
	OnResetConfig();
}

/////////////////////////////////////////////////////////////////////////////
// CGestureDemoView drawing

void CGestureDemoView::OnDraw(CDC* pDC)
{
	CGestureDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CMemDC dcMem(*pDC, this);
	CDC& dc = dcMem.GetDC();

	CRect rectClient;
	GetClientRect(&rectClient);

	if (pDoc->m_Image.IsNull())
	{
		dc.FillRect(rectClient, &afxGlobalData.brWindow);

		CString str = _T("Please open any image file to start the demo");
		dc.TextOut(10, 10, str);
		return;
	}

	Gdiplus::Graphics graphics(dc.GetSafeHdc());
	Gdiplus::SolidBrush br(Gdiplus::Color(255, 255, 255));

	graphics.FillRectangle(&br, rectClient.left, rectClient.top, rectClient.Width(), rectClient.Height());

	Gdiplus::Matrix transformMatrix;

	transformMatrix.RotateAt(Gdiplus::REAL(m_dblAngle * 180 / PI), Gdiplus::PointF (Gdiplus::REAL(m_ptCenter.x), Gdiplus::REAL(m_ptCenter.y)));
	transformMatrix.Translate(Gdiplus::REAL(m_ptOffset.x), Gdiplus::REAL(m_ptOffset.y));
	transformMatrix.Scale(Gdiplus::REAL(m_dblZoomRatio), Gdiplus::REAL(m_dblZoomRatio));

	graphics.SetTransform(&transformMatrix);

	Gdiplus::Bitmap bm((HBITMAP)pDoc->m_Image, NULL);
	graphics.SetInterpolationMode(Gdiplus::InterpolationModeHighQuality);

	CRect rectDest(0, 0, pDoc->m_Image.GetWidth(), pDoc->m_Image.GetHeight());
	graphics.DrawImage(&bm, rectDest.left, rectDest.top, rectDest.right - rectDest.left, rectDest.bottom - rectDest.top);
}

BOOL CGestureDemoView::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}

BOOL CGestureDemoView::OnGestureZoom(CPoint ptCenter, long lDelta)
{
	CGestureDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->m_Image.IsNull() || m_bInPan || m_bInRotate)
	{
		return FALSE;
	}

	ASSERT(m_pCurrentGestureInfo != NULL);
	ASSERT(ptCenter != CPoint(-1, -1));

	if ((m_pCurrentGestureInfo->dwFlags & GF_BEGIN) == GF_BEGIN)
	{
		m_bInZoom = TRUE;
	}
	else if ((m_pCurrentGestureInfo->dwFlags & GF_END) == GF_END)
	{
		m_bInZoom = FALSE;
	}
	else if (abs((int)lDelta) > 5)
	{
		const double dblZoomRatioOld = m_dblZoomRatio;

		m_dblZoomRatio += .001 * lDelta;
		m_dblZoomRatio = min(m_dblZoomRatio, 100.);
		m_dblZoomRatio = max(m_dblZoomRatio, .1);

		const double dblDelta = m_dblZoomRatio - dblZoomRatioOld;

		m_ptOffset.x += (int)(.5 + dblDelta * (m_ptOffset.x - ptCenter.x));
		m_ptOffset.y += (int)(.5 + dblDelta * (m_ptOffset.y - ptCenter.y));

		RedrawWindow();
	}

	return TRUE;
}

BOOL CGestureDemoView::OnGesturePan(CPoint ptFrom, CPoint ptTo)
{
	CGestureDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->m_Image.IsNull() || m_bInZoom || m_bInRotate)
	{
		return FALSE;
	}

	ASSERT(m_pCurrentGestureInfo != NULL);

	const int dx = ptTo.x - ptFrom.x;
	const int dy = ptTo.y - ptFrom.y;

	if ((m_pCurrentGestureInfo->dwFlags & GF_BEGIN) == GF_BEGIN)
	{
		m_bInPan = TRUE;
	}
	else if ((m_pCurrentGestureInfo->dwFlags & GF_END) == GF_END)
	{
		m_bInPan = FALSE;
	}
	else if (dx != 0 || dy != 0)
	{
		m_ptOffset.x += dx;
		m_ptOffset.y += dy;

		RedrawWindow();
	}

	return TRUE;
}

BOOL CGestureDemoView::OnGestureRotate(CPoint ptCenter, double dblAngle)
{
	CGestureDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->m_Image.IsNull() || m_bInZoom || m_bInPan)
	{
		return FALSE;
	}

	ASSERT(m_pCurrentGestureInfo != NULL);

	if ((m_pCurrentGestureInfo->dwFlags & GF_BEGIN) == GF_BEGIN)
	{
		m_ptCenter = ptCenter;
		m_dblAngleStart = m_dblAngle;
		m_bInRotate = TRUE;
	}
	else if ((m_pCurrentGestureInfo->dwFlags & GF_END) == GF_END)
	{
		m_bInRotate = FALSE;
	}
	else if (dblAngle != 0.)
	{
		m_dblAngle = m_dblAngleStart - dblAngle;
		RedrawWindow();
	}

	return TRUE;
}

BOOL CGestureDemoView::OnGestureTwoFingerTap(CPoint ptCenter)
{
	CGestureDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->m_Image.IsNull() || m_bInZoom || m_bInPan || m_bInRotate)
	{
		return FALSE;
	}

	m_dblZoomRatio = 1.;
	m_ptOffset = CPoint(0, 0);
	m_dblAngle = 0.;
	m_dblAngleStart = 0;

	RedrawWindow();
	return TRUE;
}

BOOL CGestureDemoView::OnGesturePressAndTap(CPoint ptFirstFinger, long lDelta)
{
	CGestureDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	if (pDoc->m_Image.IsNull() || m_bInZoom || m_bInPan || m_bInRotate)
	{
		return FALSE;
	}

	ClientToScreen(&ptFirstFinger);
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, ptFirstFinger.x, ptFirstFinger.y, this, TRUE);
	return TRUE;
}

void CGestureDemoView::OnResetConfig()
{
	CMainFrame* pMainFrame = DYNAMIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	if (pMainFrame != NULL)
	{
		pMainFrame->OnResetGestureConfig(this);
	}
}
