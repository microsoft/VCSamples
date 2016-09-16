// ATLDrawDoc.cpp : implementation of the CATLDrawDoc class
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
//

#include "preatldr.h"
#include "ATLDraw.h"

#include "ATLDDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CATLDrawDoc

IMPLEMENT_DYNCREATE(CATLDrawDoc, CDocument)

BEGIN_MESSAGE_MAP(CATLDrawDoc, CDocument)
	//{{AFX_MSG_MAP(CATLDrawDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CATLDrawDoc construction/destruction

CATLDrawDoc::CATLDrawDoc()
{
	// TODO: add one-time construction code here

}

CATLDrawDoc::~CATLDrawDoc()
{
}

BOOL CATLDrawDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CATLDrawDoc serialization

void CATLDrawDoc::Serialize(CArchive& ar)
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
// CATLDrawDoc diagnostics

#ifdef _DEBUG
void CATLDrawDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CATLDrawDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CATLDrawDoc commands
