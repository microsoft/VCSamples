// RListDoc.cpp : implementation of the CRowListDoc class
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
#include "RowList.h"

#include "RListDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRowListDoc

IMPLEMENT_DYNCREATE(CRowListDoc, CDocument)

BEGIN_MESSAGE_MAP(CRowListDoc, CDocument)
	//{{AFX_MSG_MAP(CRowListDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRowListDoc construction/destruction

CRowListDoc::CRowListDoc()
{
	// TODO: add one-time construction code here

}

CRowListDoc::~CRowListDoc()
{
}

BOOL CRowListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CRowListDoc serialization

void CRowListDoc::Serialize(CArchive& ar)
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
// CRowListDoc diagnostics

#ifdef _DEBUG
void CRowListDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRowListDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRowListDoc commands
