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
#include "MenuSubSet.h"

#include "MenuSubSetDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetDoc

IMPLEMENT_DYNCREATE(CMenuSubSetDoc, CDocument)

BEGIN_MESSAGE_MAP(CMenuSubSetDoc, CDocument)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetDoc construction/destruction

CMenuSubSetDoc::CMenuSubSetDoc()
{
	// TODO: add one-time construction code here

}

CMenuSubSetDoc::~CMenuSubSetDoc()
{
}

BOOL CMenuSubSetDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetDoc serialization

void CMenuSubSetDoc::Serialize(CArchive& ar)
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
// CMenuSubSetDoc diagnostics

#ifdef _DEBUG
void CMenuSubSetDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMenuSubSetDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMenuSubSetDoc commands
