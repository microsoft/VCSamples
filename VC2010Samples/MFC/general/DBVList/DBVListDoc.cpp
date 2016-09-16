// DBVListDoc.cpp : implementation of the CDBVListDoc class
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
#include "DBVList.h"

#include "DBVListSet.h"
#include "DBVListDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBVListDoc

IMPLEMENT_DYNCREATE(CDBVListDoc, CDocument)

BEGIN_MESSAGE_MAP(CDBVListDoc, CDocument)
	//{{AFX_MSG_MAP(CDBVListDoc)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBVListDoc construction/destruction

CDBVListDoc::CDBVListDoc()
{
}

CDBVListDoc::~CDBVListDoc()
{
}

BOOL CDBVListDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDBVListDoc diagnostics

#ifdef _DEBUG
void CDBVListDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDBVListDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBVListDoc commands
