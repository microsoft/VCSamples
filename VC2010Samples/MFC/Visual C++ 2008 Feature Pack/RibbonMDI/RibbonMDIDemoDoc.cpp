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
#include "RibbonMDIDemo.h"

#include "RibbonMDIDemoDoc.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoDoc

IMPLEMENT_DYNCREATE(CRibbonMDIDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CRibbonMDIDemoDoc, CDocument)
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoDoc construction/destruction

CRibbonMDIDemoDoc::CRibbonMDIDemoDoc()
{
	// TODO: add one-time construction code here

}

CRibbonMDIDemoDoc::~CRibbonMDIDemoDoc()
{
}

BOOL CRibbonMDIDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoDoc serialization

void CRibbonMDIDemoDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoDoc diagnostics

#ifdef _DEBUG
void CRibbonMDIDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRibbonMDIDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRibbonMDIDemoDoc commands

void CRibbonMDIDemoDoc::OnFileClose() 
{
	CMainFrame* pMainFrame = (CMainFrame*) AfxGetMainWnd ();

	if (pMainFrame != NULL && pMainFrame->IsPrintPreviewMode ())
	{
		return;
	}

	CDocument::OnFileClose();
}
