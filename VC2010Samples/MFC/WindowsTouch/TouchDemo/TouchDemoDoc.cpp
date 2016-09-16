// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// TouchDemoDoc.cpp : implementation of the CTouchDemoDoc class
//

#include "stdafx.h"
#include "TouchDemo.h"

#include "TouchDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTouchDemoDoc

IMPLEMENT_DYNCREATE(CTouchDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CTouchDemoDoc, CDocument)
END_MESSAGE_MAP()

// CTouchDemoDoc construction/destruction

CTouchDemoDoc::CTouchDemoDoc()
{
	// TODO: add one-time construction code here
}

CTouchDemoDoc::~CTouchDemoDoc()
{
}

BOOL CTouchDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

// CTouchDemoDoc serialization

void CTouchDemoDoc::Serialize(CArchive& ar)
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

// CTouchDemoDoc diagnostics

#ifdef _DEBUG
void CTouchDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTouchDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

// CTouchDemoDoc commands
