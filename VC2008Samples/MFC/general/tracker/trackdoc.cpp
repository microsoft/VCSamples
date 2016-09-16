// trackdoc.cpp : implementation of the CTrackerDoc class
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

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc

IMPLEMENT_DYNCREATE(CTrackerDoc, CDocument)

BEGIN_MESSAGE_MAP(CTrackerDoc, CDocument)
	//{{AFX_MSG_MAP(CTrackerDoc)
	ON_COMMAND(ID_EDIT_DOTTEDLINE, OnEditDottedline)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DOTTEDLINE, OnUpdateEditDottedline)
	ON_COMMAND(ID_EDIT_HATCHEDBORDER, OnEditHatchedborder)
	ON_UPDATE_COMMAND_UI(ID_EDIT_HATCHEDBORDER, OnUpdateEditHatchedborder)
	ON_UPDATE_COMMAND_UI(ID_EDIT_HATCHEDINSIDE, OnUpdateEditHatchedinside)
	ON_COMMAND(ID_EDIT_HATCHEDINSIDE, OnEditHatchedinside)
	ON_COMMAND(ID_EDIT_RESIZEINSIDE, OnEditResizeinside)
	ON_UPDATE_COMMAND_UI(ID_EDIT_RESIZEINSIDE, OnUpdateEditResizeinside)
	ON_COMMAND(ID_EDIT_RESIZEOUTSIDE, OnEditResizeoutside)
	ON_UPDATE_COMMAND_UI(ID_EDIT_RESIZEOUTSIDE, OnUpdateEditResizeoutside)
	ON_COMMAND(ID_EDIT_SOLIDLINE, OnEditSolidline)
	ON_UPDATE_COMMAND_UI(ID_EDIT_SOLIDLINE, OnUpdateEditSolidline)
	ON_COMMAND(ID_EDIT_ALLOWINVERT, OnEditAllowInvert)
	ON_UPDATE_COMMAND_UI(ID_EDIT_ALLOWINVERT, OnUpdateEditAllowInvert)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc construction/destruction

CTrackerDoc::CTrackerDoc()
{
	m_tracker.m_rect.left = 10;
	m_tracker.m_rect.top = 10;
	m_tracker.m_rect.right = 101;
	m_tracker.m_rect.bottom = 101;
	m_bAllowInvert = FALSE;
}

CTrackerDoc::~CTrackerDoc()
{
}

BOOL CTrackerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc serialization

void CTrackerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		DWORD dw = m_tracker.m_nStyle;
		WORD w = (WORD)m_bAllowInvert;
		ar << m_tracker.m_rect << dw << w;
	}
	else
	{
		DWORD dw;
		WORD w;
		ar >> m_tracker.m_rect >> dw >> w;
		m_tracker.m_nStyle = (UINT)dw;
		m_bAllowInvert = w;
	}
}


/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc diagnostics

#ifdef _DEBUG
void CTrackerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTrackerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTrackerDoc commands

void CTrackerDoc::OnEditSolidline()
{
	CRect rectTrue;
	m_tracker.GetTrueRect(&rectTrue);
	m_tracker.m_nStyle &= ~CRectTracker::dottedLine;
	m_tracker.m_nStyle ^= CRectTracker::solidLine;
	SetModifiedFlag();
	UpdateAllViews(NULL, (LPARAM)(LPCRECT)rectTrue);
	UpdateAllViews(NULL);
}

void CTrackerDoc::OnUpdateEditSolidline(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!!(m_tracker.m_nStyle & CRectTracker::solidLine));
}

void CTrackerDoc::OnEditDottedline()
{
	CRect rectTrue;
	m_tracker.GetTrueRect(&rectTrue);
	m_tracker.m_nStyle &= ~CRectTracker::solidLine;
	m_tracker.m_nStyle ^= CRectTracker::dottedLine;
	SetModifiedFlag();
	UpdateAllViews(NULL, (LPARAM)(LPCRECT)rectTrue);
	UpdateAllViews(NULL);
}

void CTrackerDoc::OnUpdateEditDottedline(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!!(m_tracker.m_nStyle & CRectTracker::dottedLine));
}

void CTrackerDoc::OnEditHatchedborder()
{
	CRect rectTrue;
	m_tracker.GetTrueRect(&rectTrue);
	m_tracker.m_nStyle ^= CRectTracker::hatchedBorder;
	SetModifiedFlag();
	UpdateAllViews(NULL, (LPARAM)(LPCRECT)rectTrue);
	UpdateAllViews(NULL);
}

void CTrackerDoc::OnUpdateEditHatchedborder(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!!(m_tracker.m_nStyle & CRectTracker::hatchedBorder));
}

void CTrackerDoc::OnEditHatchedinside()
{
	CRect rectTrue;
	m_tracker.GetTrueRect(&rectTrue);
	m_tracker.m_nStyle ^= CRectTracker::hatchInside;
	SetModifiedFlag();
	UpdateAllViews(NULL, (LPARAM)(LPCRECT)rectTrue);
	UpdateAllViews(NULL);
}

void CTrackerDoc::OnUpdateEditHatchedinside(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!!(m_tracker.m_nStyle & CRectTracker::hatchInside));
}

void CTrackerDoc::OnEditResizeinside()
{
	CRect rectTrue;
	m_tracker.GetTrueRect(&rectTrue);
	m_tracker.m_nStyle &= ~CRectTracker::resizeOutside;
	m_tracker.m_nStyle ^= CRectTracker::resizeInside;
	SetModifiedFlag();
	UpdateAllViews(NULL, (LPARAM)(LPCRECT)rectTrue);
	UpdateAllViews(NULL);
}

void CTrackerDoc::OnUpdateEditResizeinside(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!!(m_tracker.m_nStyle & CRectTracker::resizeInside));
}

void CTrackerDoc::OnEditResizeoutside()
{
	CRect rectTrue;
	m_tracker.GetTrueRect(&rectTrue);
	m_tracker.m_nStyle &= ~CRectTracker::resizeInside;
	m_tracker.m_nStyle ^= CRectTracker::resizeOutside;
	SetModifiedFlag();
	UpdateAllViews(NULL, (LPARAM)(LPCRECT)rectTrue);
	UpdateAllViews(NULL);
}

void CTrackerDoc::OnUpdateEditResizeoutside(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(!!(m_tracker.m_nStyle & CRectTracker::resizeOutside));
}

void CTrackerDoc::OnEditAllowInvert()
{
	m_bAllowInvert = !m_bAllowInvert;
	SetModifiedFlag();
}

void CTrackerDoc::OnUpdateEditAllowInvert(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bAllowInvert);
}
