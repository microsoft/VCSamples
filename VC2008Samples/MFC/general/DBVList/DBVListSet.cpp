// DBVListSet.cpp : implementation of the CDBVListSet class
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
#include "DBVList.h"
#include "DBVListSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBVListSet implementation

IMPLEMENT_DYNAMIC(CDBVListSet, CDaoRecordset)

CDBVListSet::CDBVListSet(CDaoDatabase* pdb)
	: CDaoRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CDBVListSet)
	m_Email = _T("");
	m_Name = _T("");
	m_Phone = _T("");
	m_Location = _T("");
	m_Title = _T("");
	m_Department = _T("");
	m_Division = _T("");
	m_nFields = 7;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dbOpenDynaset;
}

CString CDBVListSet::GetDefaultDBName()
{
	return _T("employee.mdb");
}


CString CDBVListSet::GetDefaultSQL()
{
	return _T("[Employee8]");
}

void CDBVListSet::DoFieldExchange(CDaoFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CDBVListSet)
	pFX->SetFieldType(CDaoFieldExchange::outputColumn);
	DFX_Text(pFX, _T("[Email]"), m_Email);
	DFX_Text(pFX, _T("[Name]"), m_Name);
	DFX_Text(pFX, _T("[Phone]"), m_Phone);
	DFX_Text(pFX, _T("[Location]"), m_Location);
	DFX_Text(pFX, _T("[Title]"), m_Title);
	DFX_Text(pFX, _T("[Department]"), m_Department);
	DFX_Text(pFX, _T("[Division]"), m_Division);
	//}}AFX_FIELD_MAP
}

void CDBVListSet::SetFilter(CString strCurQuery)
{
	// convenience function to set the SQL filter for the query

	if (strCurQuery == m_strFilter)
		return;

	CWaitCursor wait;

	m_strFilter.Format(_T("[Division] = '%s'"), (LPCTSTR)strCurQuery);
	if (!IsOpen())
		Open();
	Requery();

	// update record counts
	while (!IsEOF())
		MoveNext();
}


void CDBVListSet::SetSort(LPCTSTR pszSortField)
{
	// convenience function to set the SQL sort for the query

	m_strSort = pszSortField;
	if (IsOpen())
	{
		CWaitCursor wait;
		Requery();
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDBVListSet diagnostics

#ifdef _DEBUG
void CDBVListSet::AssertValid() const
{
	CDaoRecordset::AssertValid();
}

void CDBVListSet::Dump(CDumpContext& dc) const
{
	CDaoRecordset::Dump(dc);
}
#endif //_DEBUG
