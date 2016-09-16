// This is part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// mfcieDoc.cpp : implementation of the CMfcieDoc class
//

#include "stdafx.h"
#include "mfcie.h"

#include "mfcieDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMfcieDoc

IMPLEMENT_DYNCREATE(CMfcieDoc, CDocument)

BEGIN_MESSAGE_MAP(CMfcieDoc, CDocument)
	//{{AFX_MSG_MAP(CMfcieDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMfcieDoc construction/destruction

CMfcieDoc::CMfcieDoc()
{
}

CMfcieDoc::~CMfcieDoc()
{
}

BOOL CMfcieDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMfcieDoc serialization

void CMfcieDoc::Serialize(CArchive& ar)
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
// CMfcieDoc diagnostics

#ifdef _DEBUG
void CMfcieDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMfcieDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMfcieDoc commands
