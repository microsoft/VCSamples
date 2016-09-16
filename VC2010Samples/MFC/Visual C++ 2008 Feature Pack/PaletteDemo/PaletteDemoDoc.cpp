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
#include "PaletteDemo.h"

#include "PaletteDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoDoc

IMPLEMENT_DYNCREATE(CPaletteDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CPaletteDemoDoc, CDocument)
	ON_COMMAND_RANGE(ID_PAL_CURSOR, ID_PAL_AVI, OnPaletteTool)
	ON_UPDATE_COMMAND_UI_RANGE(ID_PAL_CURSOR, ID_PAL_AVI, OnUpdatePaletteTool)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoDoc construction/destruction

CPaletteDemoDoc::CPaletteDemoDoc()
{
	m_uiCurrTool = ID_PAL_CURSOR;
}

CPaletteDemoDoc::~CPaletteDemoDoc()
{
}

BOOL CPaletteDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoDoc serialization

void CPaletteDemoDoc::Serialize(CArchive& ar)
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
// CPaletteDemoDoc diagnostics

#ifdef _DEBUG
void CPaletteDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPaletteDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPaletteDemoDoc commands

void CPaletteDemoDoc::OnPaletteTool(UINT uiCmd)
{
	m_uiCurrTool = uiCmd;
}

void CPaletteDemoDoc::OnUpdatePaletteTool(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck (m_uiCurrTool == pCmdUI->m_nID);
}
