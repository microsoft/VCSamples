// maindoc.cpp : implementation of the CMainDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "viewex.h"

#include "enterdlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainDoc

IMPLEMENT_SERIAL(CMainDoc, CDocument, 0 /* schema number*/ )

BEGIN_MESSAGE_MAP(CMainDoc, CDocument)
	//{{AFX_MSG_MAP(CMainDoc)
	ON_COMMAND(IDM_CHANGEDATA, OnChangeData)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainDoc construction/destruction

CMainDoc::CMainDoc()
{
}

CMainDoc::~CMainDoc()
{
}

BOOL CMainDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	m_strData = "Sample Data String";
	m_colorData = RGB(0, 0, 0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainDoc serialization

void CMainDoc::Serialize(CArchive&)
{
	ASSERT(FALSE);      // this example program does not store data
}

/////////////////////////////////////////////////////////////////////////////
// CMainDoc commands

void CMainDoc::OnChangeData()
{
	CEnterDlg dlg;
	dlg.m_strInput = m_strData;
	if (dlg.DoModal() != IDOK)
		return;
	m_strData = dlg.m_strInput;
	// if this document stored data then we would call SetModifiedFlag here
	UpdateAllViews(NULL);   // general update
}

/////////////////////////////////////////////////////////////////////////////
