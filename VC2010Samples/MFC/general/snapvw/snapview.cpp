// SnapView.cpp : implementation of the CSnapView class
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
#include "SnapVw.h"

#include "SnapDoc.h"
#include "SnapView.h"
#include "BkfstPg.h"
#include "LunchPg.h"
#include "DinnerPg.h"
#include "SnapPs.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnapView

IMPLEMENT_DYNCREATE(CSnapView, CFormView)

BEGIN_MESSAGE_MAP(CSnapView, CFormView)
	//{{AFX_MSG_MAP(CSnapView)
	ON_WM_SIZE()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnapView construction/destruction

CSnapView::CSnapView() : CFormView((LPCTSTR)NULL)
{
	//{{AFX_DATA_INIT(CSnapView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here

	m_bSizedBefore = FALSE;
	m_pPropSheet = NULL;
	m_pPageBkfst = NULL;
	m_pPageLunch = NULL;
	m_pPageDinner = NULL;

	m_hWndFocus = NULL;
}

CSnapView::~CSnapView()
{
	// explicitly delete sheet and pages
	delete m_pPropSheet;
	delete m_pPageBkfst;
	delete m_pPageLunch;
	delete m_pPageDinner;
}

void CSnapView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSnapView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CSnapView printing


/////////////////////////////////////////////////////////////////////////////
// CSnapView diagnostics

#ifdef _DEBUG
void CSnapView::AssertValid() const
{
	CFormView::AssertValid();
}

void CSnapView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CSnapDoc* CSnapView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CSnapDoc)));
	return (CSnapDoc*) m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnapView message handlers

void CSnapView::OnSize(UINT nType, int cx, int cy)
{
	if (nType != SIZE_MINIMIZED && cx != 0 && cy != 0 && m_pPropSheet != NULL)
	{
		if (m_bSizedBefore == FALSE)
		{
			m_bSizedBefore = TRUE;

			// get the size of the property sheet
			CRect rectSized;
			m_pPropSheet->GetWindowRect(rectSized);

			// calculate the size of the frame
			CFrameWnd* pFrame = GetParentFrame();
			if (pFrame != NULL)
			{
				pFrame->CalcWindowRect(rectSized);
				CWnd* pParent = pFrame->GetParent();

				if (pParent != NULL)
					pParent->ScreenToClient(rectSized);

				// resize and reposition the frame
				pFrame->MoveWindow(rectSized);
			}
		}
	}
}

BOOL CSnapView::Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName,
	DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext)
{
	ENSURE(pParentWnd != NULL);
	ASSERT_KINDOF(CFrameWnd, pParentWnd);

	if (!CWnd::Create(lpszClassName, lpszWindowName, dwStyle | WS_CLIPCHILDREN,
		rect, pParentWnd, nID, pContext))
	{
		return FALSE;
	}

	// add your pages here!

	m_pPageBkfst = new CBkfstPage;
	m_pPageLunch = new CLunchPage;
	m_pPageDinner = new CDinnerPage;

	// create the window object

	m_pPropSheet = new CSnapPropertySheet;
	m_pPropSheet->AddPage(m_pPageBkfst);
	m_pPropSheet->AddPage(m_pPageLunch);
	m_pPropSheet->AddPage(m_pPageDinner);

	// create a modeless property page
	if (!m_pPropSheet->Create(this,
			DS_CONTEXTHELP | DS_SETFONT | WS_CHILD | WS_VISIBLE))
	{
		DestroyWindow();
		return FALSE;
	}

	m_pPropSheet->SetWindowPos(NULL, 0, 0, 0, 0,
			SWP_NOACTIVATE | SWP_NOZORDER | SWP_NOSIZE);

	// we use the style from the template - but make sure that
	// the WS_BORDER bit is correct.
	// the WS_BORDER bit will be whatever is in dwRequestedStyle

	m_pPropSheet->ModifyStyle(WS_BORDER|WS_CAPTION,
		dwStyle & (WS_BORDER|WS_CAPTION));

	// Force the size requested.
	// Fake a call to OnSize()--it would have been called automatically
	// if this were using the base class implementation of Create().

	CFrameWnd* pParentFrame = GetParentFrame();
	CRect rectSize;
	m_pPropSheet->GetWindowRect(rectSize);
	pParentFrame->CalcWindowRect(rectSize);
	OnSize(SIZE_RESTORED, rectSize.Width(), rectSize.Height());

	return TRUE;
}

BOOL CSnapView::OnEraseBkgnd(CDC* pDC)
{
	CBrush* pOldBrush;

	CBrush backBrush;
	backBrush.CreateSolidBrush(::GetSysColor(COLOR_3DLIGHT));
	backBrush.UnrealizeObject();

	CRect rectClient;
	GetClientRect(rectClient);

	pOldBrush = pDC->SelectObject(&backBrush);
	pDC->Rectangle(rectClient);

	pDC->SelectObject(pOldBrush);
	return TRUE;
}

void CSnapView::OnDraw(CDC* /*pDC*/)
{
	// we don't draw because the child window will do it all
}

void CSnapView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	SetScaleToFitSize(CSize(1, 1));
}
