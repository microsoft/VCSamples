// DBDoc.cpp : implementation of the CDBViewDoc class
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#include "stdafx.h"
#include "DBViewer.h"

#include "DBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBViewDoc

IMPLEMENT_DYNCREATE(CDBViewDoc, CDocument)

BEGIN_MESSAGE_MAP(CDBViewDoc, CDocument)
	//{{AFX_MSG_MAP(CDBViewDoc)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBViewDoc construction/destruction

CDBViewDoc::CDBViewDoc()
{
	m_pListView = NULL;
	m_pTreeView = NULL;
}

CDBViewDoc::~CDBViewDoc()
{
	m_pListView = NULL;
	m_pTreeView = NULL;
}

BOOL CDBViewDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDBViewDoc serialization

void CDBViewDoc::Serialize(CArchive& ar)
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
// CDBViewDoc diagnostics

#ifdef _DEBUG
void CDBViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDBViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBViewDoc commands

void CDBViewDoc::RefreshViews()
{
	if (m_pListView)
		m_pListView->EraseList();

	if (m_pTreeView)
		m_pTreeView->PopulateTree();
}

BOOL CDBViewDoc::OnOpenDocument(LPCTSTR )
{
	// Release any existing connections before proceeding.  This prevents
	// assertions while calling CDataSource::Open and CSession::Open
	if (m_Connect.m_spInit != NULL)
		m_Connect.m_spInit.Release();

	if (m_Session.m_spOpenRowset != NULL)
		m_Session.m_spOpenRowset.Release();

	m_strConnect = _T("");

	// Open the connection and session.  The connect uses the data
	// links dialog.  This will have the effect of opening the 
	// provider with service components if applicable.
	if (m_Connect.Open(AfxGetMainWnd()->GetSafeHwnd()) != S_OK)
	{
		AfxMessageBox(_T("Unable to connect to data source"));
		return FALSE;
	}

	USES_CONVERSION;

	if (m_Session.Open(m_Connect) != S_OK)
	{
		AfxMessageBox(_T("Couldn't create session on data source"));
		return FALSE;
	}

	m_pTreeView->m_pSession = &m_Session;
	m_pListView->m_pSession = &m_Session;

	// Get available information about the provider that the views
	// will use
	ExtractProviderInfo();

	// Refresh any new views
	RefreshViews();
	return TRUE;

}

CString CDBViewDoc::GetDSN()
{
	// pull DSN from database connect string
	return m_strConnect;
}

CString CDBViewDoc::GetConnect()
{
	return m_strConnect;
}

void CDBViewDoc::OnFileOpen()
{
	OnOpenDocument(NULL);
}

CDataSource* CDBViewDoc::GetDataSource()
{
	return &m_Connect;
}

void CDBViewDoc::ExtractProviderInfo()
{

	// Extract the data source name for display purposes
	CComVariant var;
	if SUCCEEDED(m_Connect.GetProperty(DBPROPSET_DATASOURCEINFO, DBPROP_DATASOURCENAME, &var))
	{
		m_strConnect = COLE2T(var.bstrVal);
	}
	else
	{
	  if(m_strConnect.LoadString(IDS_NONAME_SPECIFIED) == FALSE)
	  {
	    AfxThrowResourceException();
	  }
	}

	// Determine if there are any literal characters that specify
	// table and column names.
	CComQIPtr<IDBInfo> spInfo(m_Connect.m_spInit);

	if (spInfo != NULL)
	{
		DBLITERAL dbLit = DBLITERAL_QUOTE;
		ULONG ulLiteralInfo = 0;
		DBLITERALINFO* pLiteralInfo = NULL;
		OLECHAR* pChar = NULL;

		HRESULT hr = spInfo->GetLiteralInfo(1, &dbLit, &ulLiteralInfo,
						&pLiteralInfo, &pChar);

		if (SUCCEEDED(hr))
		{
			m_strQuoteStart = pLiteralInfo[0].pwszLiteralValue;
			m_strQuoteEnd = m_strQuoteStart;
		}

		if (pLiteralInfo != NULL)
			CoTaskMemFree(pLiteralInfo);

		if (pChar != NULL)
			CoTaskMemFree(pChar);
	}
}