// npdoc.cpp : implementation of the CNotepadDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//

#include "stdafx.h"
#include "np.h"

#include "npdoc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotepadDoc

IMPLEMENT_DYNCREATE(CNotepadDoc, CDocument)

BEGIN_MESSAGE_MAP(CNotepadDoc, CDocument)
	//{{AFX_MSG_MAP(CNotepadDoc)
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CNotepadDoc construction/destruction

CNotepadDoc::CNotepadDoc()
{
}

CNotepadDoc::~CNotepadDoc()
{
}

BOOL CNotepadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	((CEditView*)m_viewList.GetHead())->SetWindowText(NULL);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CNotepadDoc serialization

void CNotepadDoc::Serialize(CArchive& ar)
{
	((CEditView*)m_viewList.GetHead())->SerializeRaw(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CNotepadDoc diagnostics

#ifdef _DEBUG
void CNotepadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CNotepadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNotepadDoc commands
