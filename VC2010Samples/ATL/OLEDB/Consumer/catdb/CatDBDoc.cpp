// CatDBDoc.cpp : implementation of the CCatDBDoc class
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
#include "CatDB.h"

#include "tablepag.h"
#include "colpage.h"
#include "CatDBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCatDBDoc

IMPLEMENT_DYNCREATE(CCatDBDoc, CDocument)

BEGIN_MESSAGE_MAP(CCatDBDoc, CDocument)
	//{{AFX_MSG_MAP(CCatDBDoc)
	ON_COMMAND(ID_VIEW_SETTINGS, OnViewSettings)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCatDBDoc construction/destruction

CCatDBDoc::CCatDBDoc()
{
	m_pTableset = NULL;
	m_pColumnset = NULL;
	m_strTableName = _T("");
}

CCatDBDoc::~CCatDBDoc()
{
}

BOOL CCatDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// initialize current view level
	m_nLevel = levelNone;

	// initialize table settings
	m_bSystemTables = GetProfileValue(_T("TableSettings"),_T("SystemTables"));
	m_bViews        = GetProfileValue(_T("TableSettings"),_T("Views"));
	m_bSynonyms     = GetProfileValue(_T("TableSettings"),_T("SystemTables"));

	// initialize column info settings
	m_bLength       = GetProfileValue(_T("ColumnInfoSettings"),_T("Length"));
	m_bPrecision    = GetProfileValue(_T("ColumnInfoSettings"),_T("Precision"));
	m_bNullability  = GetProfileValue(_T("ColumnInfoSettings"),_T("Nullability"));

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CCatDBDoc serialization

void CCatDBDoc::Serialize(CArchive& ar)
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
// CCatDBDoc diagnostics

#ifdef _DEBUG
void CCatDBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CCatDBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CCatDBDoc commands

void CCatDBDoc::SetLevel(Level nLevel)
{
	m_nLevel = nLevel;
	UpdateAllViews(NULL);
}

CString CCatDBDoc::GetDSN()
{
	// Check to see if the database is open
	if (!m_pTableset)
		return _T("[No Data Source Selected]");

	// pull DSN from database connect string
	return m_strConnect;
}

void CCatDBDoc::FetchColumnInfo(LPCSTR lpszName)
{
	if (m_pColumnset)
	{
		delete m_pColumnset;
		m_pColumnset = NULL;
	}

	m_pColumnset = new CColumns;
	HRESULT hr = m_pColumnset->Open(m_session, NULL, NULL, lpszName);
	if (FAILED(hr))
	{
		AfxMessageBox(_T("Couldn't open column rowset"));
		delete m_pColumnset;
		m_pColumnset = NULL;
	}
}

BOOL CCatDBDoc::FetchTableInfo()
{
	if (m_pTableset != NULL)
	{
		delete m_pTableset;
		m_pTableset = NULL;
	}
	m_pTableset = new CTables;

	// Must use char array for ODBC interface
	// (can simply hard code max size)
	char lpszType[64];

	strcpy_s(lpszType, 64, "TABLE");
	if (m_bViews)
		strcat_s(lpszType, 64, ",VIEW");
	if (m_bSystemTables)
		strcat_s(lpszType, 64, ",SYSTEM TABLE");
	if (m_bSynonyms)
		strcat_s(lpszType, 64, ",ALIAS,SYNONYM");

	if (m_pTableset->Open(m_session, NULL, NULL, NULL, lpszType) != S_OK)
	{
		delete m_pTableset;
		m_pTableset = NULL;
		return FALSE;
	}

	return TRUE;
}

BOOL CCatDBDoc::OnOpenDocument()
{
	// close and delete any open recordsets
	if (m_pTableset)
	{
		delete m_pTableset;
		m_pTableset = NULL;
	}

	if (m_pColumnset)
	{
		delete m_pColumnset;
		m_pColumnset = NULL;
	}

	if (m_source.m_spInit != NULL)
		m_source.m_spInit.Release();

	if (m_session.m_spOpenRowset != NULL)
		m_session.m_spOpenRowset.Release();

	// close the database
	if (!m_strConnect.IsEmpty())
		m_strConnect = "";

	// open the database
	if (m_source.Open(AfxGetMainWnd()->GetSafeHwnd()) != S_OK)
	{
		AfxMessageBox(_T("Couldn't connect to data source"));
		m_strConnect = _T("");
		return FALSE;
	}
	else
	{
		if (m_session.Open(m_source) != S_OK)
		{
			AfxMessageBox(_T("Couldn't create session on provider"));
			return FALSE;
		}
		CComVariant var;
		HRESULT hr;
		hr = m_source.GetProperty(DBPROPSET_DATASOURCEINFO, DBPROP_DATASOURCENAME, &var);
		if (FAILED(hr) || (var.vt == VT_EMPTY))
			m_strConnect = _T("No Data Source Name Specified");
		else
			m_strConnect = COLE2T(var.bstrVal);
	}

	if (FetchTableInfo())
		return TRUE;
	else
		return FALSE;
}

void CCatDBDoc::OnViewSettings()
{
	CPropertySheet  sheet(_T("Settings"));
	CTablePage      pageTable;
	CColumnPage     pageColumn;

	// initialize and add table settings page
	sheet.AddPage(&pageTable);
	pageTable.m_bSystemTables = m_bSystemTables;
	pageTable.m_bViews = m_bViews;
	pageTable.m_bSynonyms = m_bSynonyms;

	// initialize and add column info settings page
	sheet.AddPage(&pageColumn);
	pageColumn.m_bLength = m_bLength;
	pageColumn.m_bPrecision = m_bPrecision;
	pageColumn.m_bNullability = m_bNullability;

	// execte property sheet and update settings
	if (sheet.DoModal() == IDOK)
	{
		BOOL    bTableModified = FALSE;
		BOOL    bColumnModified = FALSE;

		if (m_bSystemTables != pageTable.m_bSystemTables)
		{
			m_bSystemTables = pageTable.m_bSystemTables;
			AfxGetApp()->WriteProfileInt(_T("TableSettings"),
				_T("SystemTables"),m_bSystemTables);
			bTableModified = TRUE;
		}

		if (m_bViews != pageTable.m_bViews)
		{
			m_bViews = pageTable.m_bViews;
			AfxGetApp()->WriteProfileInt(_T("TableSettings"),
				_T("Views"),m_bViews);
			bTableModified = TRUE;
		}

		if (m_bSynonyms != pageTable.m_bSynonyms)
		{
			m_bSynonyms = pageTable.m_bSynonyms;
			AfxGetApp()->WriteProfileInt(_T("TableSettings"),
				_T("Synonyms"),m_bSynonyms);
			bTableModified = TRUE;
		}

		if (m_bLength != pageColumn.m_bLength)
		{
			m_bLength = pageColumn.m_bLength;
			AfxGetApp()->WriteProfileInt(_T("ColumnInfoSettings"),
				_T("Length"),m_bLength);
			bColumnModified = TRUE;
		}

		if (m_bPrecision != pageColumn.m_bPrecision)
		{
			m_bPrecision = pageColumn.m_bPrecision;
			AfxGetApp()->WriteProfileInt(_T("ColumnInfoSettings"),
				_T("Precision"),m_bPrecision);
			bColumnModified = TRUE;
		}

		if (m_bNullability != pageColumn.m_bNullability)
		{
			m_bNullability = pageColumn.m_bNullability;
			AfxGetApp()->WriteProfileInt(_T("ColumnInfoSettings"),
				_T("Nullability"),m_bNullability);
			bColumnModified = TRUE;
		}

		// check for table modification first
		if (bTableModified && (m_nLevel == CCatDBDoc::levelTable))
		{
			// close and delete any open recordsets
			if (m_pTableset)
			{
				delete m_pTableset;
				m_pTableset = 0;
			}

			if (m_pColumnset)
			{
				delete m_pColumnset;
				m_pColumnset = 0;
			}

			// refresh table data
			FetchTableInfo();
			UpdateAllViews(NULL);
		}

		// if table settings not modified, check column info
		else if (bColumnModified && (m_nLevel == CCatDBDoc::levelColumn))
		{
			FetchColumnInfo(m_strTableName);
			UpdateAllViews(NULL);
		}
	}
}

int CCatDBDoc::GetProfileValue(LPCTSTR lpszSection,LPCTSTR lpszItem)
{
	int nValue = AfxGetApp()->GetProfileInt(lpszSection,lpszItem,-1);
	if (nValue == -1)
	{
		nValue = 0;
		AfxGetApp()->WriteProfileInt(lpszSection,lpszItem,nValue);
	}
	return nValue;
}

void CCatDBDoc::OnCloseDocument()
{
	if (m_pTableset)
	{
		delete m_pTableset;
		m_pTableset = 0;
	}

	if (m_pColumnset)
	{
		delete m_pColumnset;
		m_pColumnset = 0;
	}

	CDocument::OnCloseDocument();
}
