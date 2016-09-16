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
#include "DynamicMenu.h"

#include "DynamicMenuDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDynamicMenuDoc

IMPLEMENT_DYNCREATE(CDynamicMenuDoc, CDocument)

BEGIN_MESSAGE_MAP(CDynamicMenuDoc, CDocument)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDynamicMenuDoc construction/destruction

CDynamicMenuDoc::CDynamicMenuDoc()
{
	// TODO: add one-time construction code here

}

CDynamicMenuDoc::~CDynamicMenuDoc()
{
}

BOOL CDynamicMenuDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDynamicMenuDoc serialization

void CDynamicMenuDoc::Serialize(CArchive& ar)
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
// CDynamicMenuDoc diagnostics

#ifdef _DEBUG
void CDynamicMenuDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDynamicMenuDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDynamicMenuDoc commands
