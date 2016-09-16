// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "OwnerDrawMenu.h"

#include "OwnerDrawMenuDoc.h"
#include "OwnerDrawMenuView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

static const CString strInfo = 
	_T("This sample illustrates how the popup menu items may be drawn on the fly.\r\n\r\n")
	_T("Click the \"Line Style\" toolbar button to see an owner-draw menu item\r\n")
	_T("which is implemented in the CLineStyleMenuItem class.\r\n")
	_T("The menu items are replaced by this object in CMainFrame::OnShowPopupMenu.");

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuView

IMPLEMENT_DYNCREATE(COwnerDrawMenuView, CView)

BEGIN_MESSAGE_MAP(COwnerDrawMenuView, CView)
	ON_COMMAND(ID_MORE_LINES, OnMoreLines)
	ON_WM_CONTEXTMENU()
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, OnFilePrintPreview)
	ON_COMMAND_RANGE(ID_LINE_STYLE_1, ID_LINE_STYLE_10, OnLineStyle)
	ON_UPDATE_COMMAND_UI_RANGE(ID_LINE_STYLE_1, ID_LINE_STYLE_10, OnUpdateLineStyle)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuView construction/destruction

COwnerDrawMenuView::COwnerDrawMenuView()
{
	m_uiLineStyleCmd = ID_LINE_STYLE_3;
}

COwnerDrawMenuView::~COwnerDrawMenuView()
{
}

BOOL COwnerDrawMenuView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuView drawing

void COwnerDrawMenuView::OnDraw(CDC* pDC)
{
//	COwnerDrawMenuDoc* pDoc = GetDocument();
//	ASSERT_VALID(pDoc);

	const int iOffset = 20;

	CFont* pFontOld = (CFont*) pDC->SelectStockObject (DEFAULT_GUI_FONT);
	ASSERT (pFontOld != NULL);

	CRect rectClient;
	GetClientRect (&rectClient);

	CRect rectText = rectClient;
	rectText.DeflateRect (iOffset, iOffset);
	pDC->DrawText (strInfo, rectText, DT_CALCRECT | DT_WORDBREAK);

	rectText.OffsetRect (	(rectClient.Width () - rectText.Width () - 2 * iOffset) / 2,
							(rectClient.Height () - rectText.Height () - 2 * iOffset) / 2);

	CRect rectFrame = rectText;
	rectFrame.InflateRect (iOffset, iOffset);

	pDC->FillSolidRect (rectFrame, ::GetSysColor (COLOR_INFOBK));
	
	rectFrame.DeflateRect (1, 1);
	pDC->Draw3dRect (rectFrame, ::GetSysColor (COLOR_3DSHADOW), 
					::GetSysColor (COLOR_3DLIGHT));

	rectFrame.DeflateRect (2, 2);
	pDC->Draw3dRect (rectFrame, ::GetSysColor (COLOR_3DSHADOW), 
					::GetSysColor (COLOR_3DLIGHT));

	pDC->SetTextColor (::GetSysColor (COLOR_INFOTEXT));
	pDC->SetBkMode (TRANSPARENT);

	pDC->DrawText (strInfo, rectText, DT_WORDBREAK);

	pDC->SelectObject (pFontOld);
}

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuView printing

void COwnerDrawMenuView::OnFilePrintPreview() 
{
	AFXPrintPreview (this);
}

BOOL COwnerDrawMenuView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COwnerDrawMenuView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COwnerDrawMenuView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuView diagnostics

#ifdef _DEBUG
void COwnerDrawMenuView::AssertValid() const
{
	CView::AssertValid();
}

void COwnerDrawMenuView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

COwnerDrawMenuDoc* COwnerDrawMenuView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COwnerDrawMenuDoc)));
	return (COwnerDrawMenuDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuView message handlers

void COwnerDrawMenuView::OnContextMenu(CWnd*, CPoint point)
{
	theApp.ShowPopupMenu (IDR_CONTEXT_MENU, point, this);
}

void COwnerDrawMenuView::OnLineStyle(UINT uiCmd)
{
	m_uiLineStyleCmd = uiCmd;

	CString str;
	str.Format (_T("Line style: %d"), uiCmd - ID_LINE_STYLE_1 + 1);

	MessageBox (str);
}

void COwnerDrawMenuView::OnUpdateLineStyle(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck (m_uiLineStyleCmd == pCmdUI->m_nID);
}

void COwnerDrawMenuView::OnMoreLines() 
{
	MessageBox (_T("More line styles...."));
}
