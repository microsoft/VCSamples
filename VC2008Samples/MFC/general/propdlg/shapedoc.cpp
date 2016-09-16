// shapedoc.cpp : implementation of the CShapesDoc class
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
#include "shapedoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShapesDoc

IMPLEMENT_DYNCREATE(CShapesDoc, CDocument)

BEGIN_MESSAGE_MAP(CShapesDoc, CDocument)
	//{{AFX_MSG_MAP(CShapesDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShapesDoc construction/destruction

CShapesDoc::CShapesDoc()
{
}

CShapesDoc::~CShapesDoc()
{
	POSITION pos = m_shapeList.GetHeadPosition();
	while (pos != NULL)
	{
		delete m_shapeList.GetNext(pos);
	}
}

BOOL CShapesDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	CRect rect(20,20,120,120);

	CShape* pShapeNew = new CShape(
		black,
		rectangle,
		rect);
	AddShape(pShapeNew);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CShapesDoc operations

void CShapesDoc::AddShape(CShape* pShapeNew)
{
	m_shapeList.AddHead(pShapeNew);
	UpdateAllViews(NULL);
	SetModifiedFlag();
}

CShape* CShapesDoc::HitTest(CPoint pt)
{
	CShape* pShapeHit;
	POSITION pos = m_shapeList.GetHeadPosition();
	while (pos != NULL)
	{
		pShapeHit = m_shapeList.GetNext(pos);
		if (pShapeHit->m_rect.PtInRect(pt))
			return pShapeHit;
	}
	return NULL;
}

/////////////////////////////////////////////////////////////////////////////
// CShapesDoc serialization

void CShapesDoc::Serialize(CArchive& ar)
{
	m_shapeList.Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CShapesDoc diagnostics

#ifdef _DEBUG
void CShapesDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShapesDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShapesDoc commands
