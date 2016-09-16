// recalcvw.cpp : implementation of the CRecalcView class
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
#include "mtrecalc.h"
#include "calcthrd.h"
#include "recaldoc.h"
#include "recalcvw.h"
#include "resource.h"
#include "slowcalc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecalcView

IMPLEMENT_DYNCREATE(CRecalcView, CFormView)

BEGIN_MESSAGE_MAP(CRecalcView, CFormView)
	ON_MESSAGE(WM_USER_RECALC_DONE, OnRecalcDone)
	ON_MESSAGE(WM_USER_RECALC_NOW, OnRecalcNowMsg)
	//{{AFX_MSG_MAP(CRecalcView)
	ON_EN_KILLFOCUS(IDC_INT1, OnKillFocus)
	ON_EN_KILLFOCUS(IDC_INT2, OnKillFocus)
	ON_COMMAND(ID_RECALCULATE_NOW, OnRecalculateNow)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecalcView construction/destruction

CRecalcView::CRecalcView()
	: CFormView(CRecalcView::IDD)
{
	//{{AFX_DATA_INIT(CRecalcView)
	m_nInt1 = 0;
	m_nInt2 = 0;
	//}}AFX_DATA_INIT

	m_bFirstKillFocus = FALSE;
}

CRecalcView::~CRecalcView()
{
}

void CRecalcView::OnUpdate(
	CView* /*pSender*/, LPARAM lHint, CObject* /*pHint*/)
{
	CRecalcDoc* pDoc = GetDocument();
	if (lHint != UPDATE_HINT_SUM)
	{
		m_nInt1 = pDoc->m_nInt1;
		m_nInt2 = pDoc->m_nInt2;
		UpdateData(FALSE);
	}

	CString strSum;
	if (pDoc->m_bRecalcNeeded)
	{
		if (pDoc->m_bRecalcInProgress)
			strSum.LoadString(IDS_RECALCULATING);
		else
			strSum = _T("?");
	}
	else
	{
		strSum.Format(_T("%i"), pDoc->m_nSum);
	}
	m_ctlSum.SetWindowText(strSum);
	m_ctlSum.UpdateWindow();
}

void CRecalcView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRecalcView)
	DDX_Control(pDX, IDC_SUM, m_ctlSum);
	DDX_Text(pDX, IDC_INT1, m_nInt1);
	DDX_Text(pDX, IDC_INT2, m_nInt2);
	//}}AFX_DATA_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CRecalcView printing

BOOL CRecalcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRecalcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CRecalcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
}

void CRecalcView::OnPrint(CDC*, CPrintInfo*)
{
}

/////////////////////////////////////////////////////////////////////////////
// CRecalcView diagnostics

#ifdef _DEBUG
void CRecalcView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRecalcView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CRecalcDoc* CRecalcView::GetDocument() // non-debug version is inline
{
	return STATIC_DOWNCAST(CRecalcDoc, m_pDocument);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRecalcView message handlers

void CRecalcView::OnRecalculateNow()
{
	if (!UpdateData())
		return;

	GetDocument()->UpdateInt1AndInt2(m_nInt1, m_nInt2, TRUE);
}

LRESULT CRecalcView::OnRecalcNowMsg(WPARAM, LPARAM)
{
	// The WM_USER_RECALC_NOW message is posted by the view to itself whenever
	// the focus changes from one field to another.  The view cannot call
	// UpdateData() from the WM_KILLFOCUS handler because UpdateData() will
	// incorrectly try to call SetFocus() during the WM_KILLFOCUS if the
	// field exchange (DDX) or validation (DDV) fails.

	// The WM_USER_RECALC_NOW message is also posted by the document in other
	// circumstances (such as when the user is trying to save the document
	// before it has been recalculated).    In this case, the kill focus
	// problem is not an issue.

	BOOL bUpdateDataSuccess = UpdateData();
	m_bFirstKillFocus = FALSE;
	if (!bUpdateDataSuccess)
		return 0;

	GetDocument()->UpdateInt1AndInt2(m_nInt1, m_nInt2, FALSE);
	return 0;
}

void CRecalcView::OnKillFocus()
{
	// See comment for OnRecalcNowMsg.

	// Only post the WM_USER_RECALC_NOW message if the view is not already
	// in the process of handling the first kill focus.  If UpdateData() fails
	// in the OnRecalcNowMsg handler, then the framework will call SetFocus()
	// to set the focus back on the control with the invalid value.  The SetFocus()
	// call will cause another WM_KILLFOCUS message to be sent.  If this OnKillFocus()
	// handler were to post yet another WM_USER_RECALC_NOW message, the program would
	// go into an infinite loop of attempting focus changes.

	if (!m_bFirstKillFocus)
	{
		PostMessage(WM_USER_RECALC_NOW, 0, 0);
		m_bFirstKillFocus = TRUE;
	}
}


LRESULT CRecalcView::OnRecalcDone(WPARAM, LPARAM)
{
	GetDocument()->RecalcDone();
	return 0;
}
