// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// TouchDemoView.cpp : implementation of the CTouchDemoView class
//

#include "stdafx.h"
#include "TouchDemo.h"

#include "TouchDemoDoc.h"
#include "TouchDemoView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTouchDemoView

IMPLEMENT_DYNCREATE(CTouchDemoView, CView)

BEGIN_MESSAGE_MAP(CTouchDemoView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTouchDemoView::OnFilePrintPreview)
	ON_WM_ERASEBKGND()
	ON_WM_CREATE()
END_MESSAGE_MAP()

// CTouchDemoView construction/destruction

inline int Rand (int nMax)
{
	int nRes = rand () % nMax;
	return min (nRes, nMax - 1);
}

CTouchDemoView::CTouchDemoView()
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		m_arObjects.Add (new CTouchObject(RGB (Rand(255), Rand(255), Rand(255)), CPoint (Rand(500), Rand(300))));
	}
}

CTouchDemoView::~CTouchDemoView()
{
	for (int i = 0; i < m_arObjects.GetSize(); i++)
	{
		delete m_arObjects[i];
	}
}

BOOL CTouchDemoView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTouchDemoView drawing

void CTouchDemoView::OnDraw(CDC* pDC)
{
	CTouchDemoDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CRect rect;
	GetClientRect (rect);

	pDC->FillSolidRect (rect, RGB (255, 255, 255));

	for (int i = 0; i < m_arObjects.GetSize(); i++)
	{
		m_arObjects[i]->OnDraw(pDC);
	}
}

// CTouchDemoView printing

void CTouchDemoView::OnFilePrintPreview()
{
	AFXPrintPreview(this);
}

BOOL CTouchDemoView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTouchDemoView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTouchDemoView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CTouchDemoView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTouchDemoView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
}

// CTouchDemoView diagnostics

#ifdef _DEBUG
void CTouchDemoView::AssertValid() const
{
	CView::AssertValid();
}

void CTouchDemoView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTouchDemoDoc* CTouchDemoView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTouchDemoDoc)));
	return (CTouchDemoDoc*)m_pDocument;
}
#endif //_DEBUG

// CTouchDemoView message handlers

BOOL CTouchDemoView::OnEraseBkgnd(CDC* /*pDC*/)
{
	return TRUE;
}

int CTouchDemoView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!RegisterTouchWindow())
	{
		ASSERT(FALSE);
	}

	return 0;
}

BOOL CTouchDemoView::OnTouchInput(CPoint pt, int nInputNumber, int nInputsCount, PTOUCHINPUT pInput)
{
	if ((pInput->dwFlags & TOUCHEVENTF_DOWN) == TOUCHEVENTF_DOWN)
	{
		for (INT_PTR i = m_arObjects.GetSize() - 1; i >= 0; i--)
		{
			if (m_arObjects[i]->HitTest(pt) && m_arObjects[i]->m_nTouchNumber == -1)
			{
				m_arObjects[i]->m_nTouchNumber = pInput->dwID;
				return TRUE;
			}
		}

		return FALSE;
	}

	BOOL bUpdate = FALSE;

	for (int i = 0; i < m_arObjects.GetSize(); i++)
	{
		if (m_arObjects[i]->m_nTouchNumber == pInput->dwID)
		{
			InvalidateRect(m_arObjects[i]->GetRect());
			m_arObjects[i]->Move(pt);
			InvalidateRect(m_arObjects[i]->GetRect());

			bUpdate = TRUE;

			if ((pInput->dwFlags & TOUCHEVENTF_UP) == TOUCHEVENTF_UP)
			{
				m_arObjects[i]->m_nTouchNumber = -1;
			}
		}
	}

	if (bUpdate)
	{
		UpdateWindow ();
	}

	return TRUE;
}

ULONG CTouchDemoView::GetGestureStatus(CPoint ptTouch)
{
	for (int i = 0; i < m_arObjects.GetSize(); i++)
	{
		if (m_arObjects[i]->HitTest(ptTouch))
		{
			return CView::GetGestureStatus(ptTouch);
		}
	}

	// Diasable UI feedbacks (waves, circles e.t.c)
	return TABLET_DISABLE_PENTAPFEEDBACK | TABLET_DISABLE_PENBARRELFEEDBACK | TABLET_DISABLE_FLICKS;
}
