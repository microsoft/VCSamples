// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "RollupPane.h"

#include "RollupPaneDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRollupPaneDoc

IMPLEMENT_DYNCREATE(CRollupPaneDoc, CDocument)

BEGIN_MESSAGE_MAP(CRollupPaneDoc, CDocument)
END_MESSAGE_MAP()


// CRollupPaneDoc construction/destruction

CRollupPaneDoc::CRollupPaneDoc()
{
	// TODO: add one-time construction code here

}

CRollupPaneDoc::~CRollupPaneDoc()
{
}

BOOL CRollupPaneDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CRollupPaneDoc serialization

void CRollupPaneDoc::Serialize(CArchive& ar)
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


// CRollupPaneDoc diagnostics

#ifdef _DEBUG
void CRollupPaneDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRollupPaneDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CRollupPaneDoc commands
