// DBVListSet.h : interface of the CDBVListSet class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#if !defined(AFX_DBVLISTSET_H__13CCB74D_ED59_11D0_8286_00C04FD73634__INCLUDED_)
#define AFX_DBVLISTSET_H__13CCB74D_ED59_11D0_8286_00C04FD73634__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CDBVListSet : public CDaoRecordset
{
public:
	CDBVListSet(CDaoDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CDBVListSet)
	void SetFilter(CString strCurQuery);
	void SetSort(LPCTSTR pszSortField);
// Field/Param Data
	//{{AFX_FIELD(CDBVListSet, CDaoRecordset)
	CString m_Email;
	CString m_Name;
	CString m_Phone;
	CString m_Location;
	CString m_Title;
	CString m_Department;
	CString m_Division;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBVListSet)
	public:
	virtual CString GetDefaultDBName();     // default Database Name
	virtual CString GetDefaultSQL();    // default SQL for Recordset
	virtual void DoFieldExchange(CDaoFieldExchange* pFX);   // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBVLISTSET_H__13CCB74D_ED59_11D0_8286_00C04FD73634__INCLUDED_)
