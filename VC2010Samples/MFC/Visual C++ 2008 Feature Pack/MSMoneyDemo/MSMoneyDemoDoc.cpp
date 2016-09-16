// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// MSMoneyDemoDoc.cpp : implementation of the CMSMoneyDemoDoc class
//

#include "stdafx.h"
#include "MSMoneyDemo.h"

#include "MSMoneyDemoDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoDoc

IMPLEMENT_DYNCREATE(CMSMoneyDemoDoc, CDocument)

BEGIN_MESSAGE_MAP(CMSMoneyDemoDoc, CDocument)
	ON_COMMAND(ID_GO_BACK, OnGoBack)
	ON_UPDATE_COMMAND_UI(ID_GO_BACK, OnUpdateGoBack)
	ON_COMMAND(ID_GO_FORWARD, OnGoForward)
	ON_UPDATE_COMMAND_UI(ID_GO_FORWARD, OnUpdateGoForward)
	ON_COMMAND(ID_GO_ADDRESS, OnGoAddress)
	ON_UPDATE_COMMAND_UI(ID_GO_ADDRESS, OnUpdateGoAddress)
	ON_COMMAND(ID_VIEW_STOP, OnViewStop)
	ON_UPDATE_COMMAND_UI(ID_VIEW_STOP, OnUpdateViewStop)
	ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
	ON_UPDATE_COMMAND_UI(ID_VIEW_REFRESH, OnUpdateViewRefresh)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoDoc construction/destruction

CMSMoneyDemoDoc::CMSMoneyDemoDoc()
{
}

CMSMoneyDemoDoc::~CMSMoneyDemoDoc()
{
}

BOOL CMSMoneyDemoDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoDoc serialization

void CMSMoneyDemoDoc::Serialize(CArchive& ar)
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
// CMSMoneyDemoDoc diagnostics

#ifdef _DEBUG
void CMSMoneyDemoDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMSMoneyDemoDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMSMoneyDemoDoc commands

void CMSMoneyDemoDoc::OnGoBack() 
{
}

void CMSMoneyDemoDoc::OnUpdateGoBack(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (IsBackAvailable ());
}

void CMSMoneyDemoDoc::OnGoForward() 
{
}

void CMSMoneyDemoDoc::OnUpdateGoForward(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (IsFrwdAvailable ());
}

void CMSMoneyDemoDoc::OnGoAddress() 
{
}

void CMSMoneyDemoDoc::OnUpdateGoAddress(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
}

void CMSMoneyDemoDoc::OnViewStop() 
{
}

void CMSMoneyDemoDoc::OnUpdateViewStop(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
}

void CMSMoneyDemoDoc::OnViewRefresh() 
{
}

void CMSMoneyDemoDoc::OnUpdateViewRefresh(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable (TRUE);
}
