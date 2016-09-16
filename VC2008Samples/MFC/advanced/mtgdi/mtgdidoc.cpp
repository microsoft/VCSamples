// mtgdidoc.cpp : implementation of the CThreadDoc class
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
#include "mtgdi.h"

#include "mtgdidoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CThreadDoc

IMPLEMENT_DYNCREATE(CThreadDoc, CDocument)

BEGIN_MESSAGE_MAP(CThreadDoc, CDocument)
	//{{AFX_MSG_MAP(CThreadDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CThreadDoc construction/destruction

CThreadDoc::CThreadDoc()
{
	// TODO: add one-time construction code here

}

CThreadDoc::~CThreadDoc()
{
}

BOOL CThreadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CThreadDoc serialization

void CThreadDoc::Serialize(CArchive& ar)
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
// CThreadDoc diagnostics

#ifdef _DEBUG
void CThreadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CThreadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CThreadDoc commands
