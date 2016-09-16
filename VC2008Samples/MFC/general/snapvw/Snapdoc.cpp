// SnapDoc.cpp : implementation of the CSnapDoc class
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

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSnapDoc

IMPLEMENT_DYNCREATE(CSnapDoc, CDocument)

BEGIN_MESSAGE_MAP(CSnapDoc, CDocument)
	//{{AFX_MSG_MAP(CSnapDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSnapDoc construction/destruction

CSnapDoc::CSnapDoc()
{
	// TODO: add one-time construction code here

}

CSnapDoc::~CSnapDoc()
{
}

BOOL CSnapDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CSnapDoc serialization


/////////////////////////////////////////////////////////////////////////////
// CSnapDoc diagnostics

#ifdef _DEBUG
void CSnapDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSnapDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSnapDoc commands
