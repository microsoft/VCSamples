// shapesvw.cpp : implementation of the CShapesView class
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
#include "propdlg.h"

#include "shapeobj.h"
#include "colorpge.h"
#include "stylepge.h"
#include "preview.h"
#include "propsht.h"
#include "propsht2.h"
#include "shapedoc.h"
#include "shapesvw.h"

#include "minifrm.h"
#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShapesView

IMPLEMENT_DYNCREATE(CShapesView, CView)

BEGIN_MESSAGE_MAP(CShapesView, CView)
	ON_MESSAGE(WM_USER_CHANGE_OBJECT_PROPERTIES, OnChangeObjectProps)
	//{{AFX_MSG_MAP(CShapesView)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_SIMPLE_PROPERTY_SHEET, OnSimplePropertySheet)
	ON_UPDATE_COMMAND_UI(ID_SIMPLE_PROPERTY_SHEET, OnUpdateSimplePropertySheet)
	ON_COMMAND(ID_PROPERTY_SHEET_WITH_PREVIEW, OnPropertySheetWithPreview)
	ON_WM_KEYDOWN()
	ON_UPDATE_COMMAND_UI(ID_PROPERTY_SHEET_WITH_PREVIEW, OnUpdatePropertySheetWithPreview)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapesView construction/destruction

CShapesView::CShapesView()
{
	m_pShapeSelected = NULL;
	m_pModalShapePropSheet = NULL;
}

CShapesView::~CShapesView()
{
}


/////////////////////////////////////////////////////////////////////////////
// Operations

CModelessShapePropSheet* CShapesView::GetModelessShapePropSheet()
{
	CMainFrame* pMainFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	if (pMainFrame->m_pShapePropFrame == NULL)
		return NULL;
	return pMainFrame->m_pShapePropFrame->m_pModelessShapePropSheet;
}

/////////////////////////////////////////////////////////////////////////////
// CShapesView drawing

void CShapesView::OnDraw(CDC* pDC)
{
	CShapesDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);

	CRect rectDirty, rectIntersect;
	pDC->GetClipBox(&rectDirty);
	if (rectDirty.IsRectNull())
		GetClientRect(&rectDirty);

	CShape* pShape;
	POSITION pos = pDoc->m_shapeList.GetTailPosition();
	// Draw all of the shapes, except the currently selected shape, from
	// back to front.
	while (pos != NULL)
	{
		pShape = pDoc->m_shapeList.GetPrev(pos);
		if (rectIntersect.IntersectRect(&pShape->m_rect, &rectDirty) != 0
			&& pShape != m_pShapeSelected)
			pShape->Draw(pDC, FALSE);
	}
	// Draw the selected shape on top
	if (m_pShapeSelected != NULL)
		m_pShapeSelected->Draw(pDC, TRUE);
}

/////////////////////////////////////////////////////////////////////////////
// CShapesView printing

BOOL CShapesView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShapesView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CShapesView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

/////////////////////////////////////////////////////////////////////////////
// CShapesView diagnostics

#ifdef _DEBUG
void CShapesView::AssertValid() const
{
	CView::AssertValid();
}

void CShapesView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CShapesDoc* CShapesView::GetDocument() // non-debug version is inline
{
	ASSERT_KINDOF(CShapesDoc, m_pDocument);
	return (CShapesDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShapesView message handlers

void CShapesView::OnLButtonDown(UINT /*nFlags*/, CPoint point)
{
	CShapesDoc* pDoc = GetDocument();
	CModelessShapePropSheet* pModelessShapePropSheet
		= GetModelessShapePropSheet();

	CClientDC dc(this);

	CShape* pShapeHit;
	pShapeHit = pDoc->HitTest(point);
	if (pShapeHit != NULL)
	{   // Select the object that was clicked.

		CRect rectInvalid;
		// Invalidate the previously selected object, so it will
		// be redrawn as unselected.
		if (m_pShapeSelected != NULL)
			InvalidateRect(&m_pShapeSelected->m_rect);
		m_pShapeSelected = pShapeHit;

		// Invalidate the newly selected object, so it will be
		// redrawn as selected.
		InvalidateRect(&m_pShapeSelected->m_rect);

		// If the modeless property is visible, update its
		// settings to reflect the newly selected shape.
		if (pModelessShapePropSheet != NULL
			&& pModelessShapePropSheet->IsWindowVisible())
		{
		   pModelessShapePropSheet->
			   SetSheetPropsFromShape(m_pShapeSelected);
		}
	}
	else
	{   // Add a new shape

		CRect rect(point.x-50, point.y-50, point.x + 50, point.y + 50);
		CShape* pShapeNew = new CShape(
			black,
			rectangle,
			rect);
		pDoc->AddShape(pShapeNew);
		m_pShapeSelected = pShapeNew;
		// If the modeless property sheet exists, then apply its current
		// settings to the new shape.
		if (pModelessShapePropSheet != NULL)
		{
		   pModelessShapePropSheet->
			   SetShapePropsFromSheet(m_pShapeSelected);
		}
	}
}

void CShapesView::OnLButtonDblClk(UINT /*nFlags*/, CPoint /*point*/)
{
	// Double-click anywhere brings up modeless property sheet.
	CMainFrame* pMainFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
	pMainFrame->OnMiniFramePropertySheet();
}


void CShapesView::OnSimplePropertySheet()
{
	if (m_pShapeSelected == NULL)
		return;

	CPropertySheet dlgPropertySheet(AFX_IDS_APP_TITLE);
	CStylePage stylePage;
	CColorPage colorPage;

	stylePage.m_nShapeStyle = m_pShapeSelected->m_shapestyle;
	colorPage.m_nColor = m_pShapeSelected->m_shapecolor;

	dlgPropertySheet.AddPage(&stylePage);
	dlgPropertySheet.AddPage(&colorPage);

	if (dlgPropertySheet.DoModal() == IDOK)
	{
		m_pShapeSelected->m_shapecolor = colorPage.m_nColor;
		m_pShapeSelected->m_shapestyle
			= (SHAPE_STYLE)stylePage.m_nShapeStyle;
		GetDocument()->SetModifiedFlag();
		GetDocument()->UpdateAllViews(NULL);
	}
}

void CShapesView::OnUpdateSimplePropertySheet(CCmdUI* pCmdUI)
{
	// Borrow logic from Property Sheet with Preview command.
	OnUpdatePropertySheetWithPreview(pCmdUI);
}

void CShapesView::OnPropertySheetWithPreview()
{
	if (m_pShapeSelected == NULL)
		return;

	// Save pointer to the modal property sheet so that when the
	// user choose Apply Now and the CModalShapePropSheet sends
	// the WM_USER_CHANGE_OBJECT_PROPERTIES message to the view,
	// the view can easily refer back to the property sheet
	// to get the current settings and apply them to the currently
	// selected object.
	m_pModalShapePropSheet = new CModalShapePropSheet;

	// Cannot use CModalShapePropSheet::SetSheetPropsFromShape here
	// because it was designed to be called from the handler of
	// the user-defined WM_USER_CHANGE_OBJECT_PROPS message when
	// the user chooses Apply Now.  The window for the modal
	// property sheet here has not been created yet.  Calling
	// SetSheetPropsFromShape would result in a failure in trying
	// to update the window.
	m_pModalShapePropSheet->m_stylePage.m_nShapeStyle
		= m_pShapeSelected->m_shapestyle;
	m_pModalShapePropSheet->m_colorPage.m_nColor = m_pShapeSelected->m_shapecolor;

	if (m_pModalShapePropSheet->DoModal() == IDOK)
	{
		m_pModalShapePropSheet->SetShapePropsFromSheet(m_pShapeSelected);
		GetDocument()->SetModifiedFlag();
		GetDocument()->UpdateAllViews(NULL);
	}
	delete m_pModalShapePropSheet;
	m_pModalShapePropSheet = NULL;
}

void CShapesView::OnUpdatePropertySheetWithPreview(CCmdUI* pCmdUI)
{
	BOOL bEnable = TRUE;
	if (m_pShapeSelected == NULL)
	{
		bEnable = FALSE;
	}
	else
	{
		CModelessShapePropSheet* pModelessShapePropSheet
			= GetModelessShapePropSheet();
		if (pModelessShapePropSheet != NULL
			&& pModelessShapePropSheet->IsWindowVisible())
		{
			// Don't display modal property sheet if the modeless
			// property sheet is already displayed.
			bEnable = FALSE;
		}
	}
	pCmdUI->Enable(bEnable);
}

LRESULT CShapesView::OnChangeObjectProps(WPARAM, LPARAM)
{
	// The user-defined WM_USER_CHANGE_OBJECT_PROPS message is sent
	// by the modal CModalShapePropSheet when the user chooses Apply Now,
	// or by the modeless CModelessShapePropSheet when the user
	// changes any setting in a property page.

	if (m_pShapeSelected == NULL)
		return 0;

	CModelessShapePropSheet* pModelessShapePropSheet
		= GetModelessShapePropSheet();
	if (pModelessShapePropSheet != NULL)
		pModelessShapePropSheet->SetShapePropsFromSheet(m_pShapeSelected);

	if (m_pModalShapePropSheet != NULL)
		m_pModalShapePropSheet->SetShapePropsFromSheet(m_pShapeSelected);

	GetDocument()->SetModifiedFlag();
	GetDocument()->UpdateAllViews(NULL);
	return 0;
}

void CShapesView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_ESCAPE)
	{
		CMainFrame* pMainFrame = STATIC_DOWNCAST(CMainFrame, AfxGetMainWnd());
		pMainFrame->HideModelessPropSheet();
		return;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
