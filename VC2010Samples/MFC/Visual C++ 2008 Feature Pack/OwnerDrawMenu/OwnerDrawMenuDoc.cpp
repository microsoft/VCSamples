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
#include "OwnerDrawMenu.h"

#include "OwnerDrawMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuDoc

IMPLEMENT_DYNCREATE(COwnerDrawMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(COwnerDrawMenuDoc, CDocument)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuDoc construction/destruction

COwnerDrawMenuDoc::COwnerDrawMenuDoc()
{
	// TODO: add one-time construction code here

}

COwnerDrawMenuDoc::~COwnerDrawMenuDoc()
{
}

BOOL COwnerDrawMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuDoc serialization

void COwnerDrawMenuDoc::Serialize(CArchive& ar)
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
// COwnerDrawMenuDoc diagnostics

#ifdef _DEBUG
void COwnerDrawMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COwnerDrawMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COwnerDrawMenuDoc commands
