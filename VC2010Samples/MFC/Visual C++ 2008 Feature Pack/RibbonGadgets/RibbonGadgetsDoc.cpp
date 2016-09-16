// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "RibbonGadgets.h"

#include "RibbonGadgetsDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRibbonGadgetsDoc

IMPLEMENT_DYNCREATE(CRibbonGadgetsDoc, CDocument)

BEGIN_MESSAGE_MAP(CRibbonGadgetsDoc, CDocument)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRibbonGadgetsDoc construction/destruction

CRibbonGadgetsDoc::CRibbonGadgetsDoc()
	: m_bStartup (TRUE)
{
	// TODO: add one-time construction code here

}

CRibbonGadgetsDoc::~CRibbonGadgetsDoc()
{
}

BOOL CRibbonGadgetsDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonGadgetsDoc serialization

void CRibbonGadgetsDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
	}
	else
	{
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonGadgetsDoc diagnostics

#ifdef _DEBUG
void CRibbonGadgetsDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRibbonGadgetsDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRibbonGadgetsDoc commands
