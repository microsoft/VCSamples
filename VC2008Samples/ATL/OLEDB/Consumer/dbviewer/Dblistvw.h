// DBListVw.h : header file
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

#ifndef __DBLISTVW_H__
#define __DBLISTVW_H__


/////////////////////////////////////////////////////////////////////////////
// Binding Structures

struct MYBIND
{
	MYBIND()
	{
		memset(this, 0, sizeof(*this));
	}

	TCHAR   szValue[40];
	DWORD   dwStatus;
};

/////////////////////////////////////////////////////////////////////////////
// Forward Declarations

class CEditDlg;

/////////////////////////////////////////////////////////////////////////////
// CDBListView view

class CDBListView : public CListView
{
protected:
	CDBListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CDBListView)

// Attributes
public:
	BOOL        IsEditable() { return m_bEditable; };
	CDBViewDoc* GetDocument();
	CSession*   m_pSession;

protected:
	BOOL    m_bVertical;
	int     m_nColumns;
	BOOL    m_bEditable;
	CString m_strTable;
	ULONG   m_ulFields;
	CCommand<CManualAccessor, CRowset, CMultipleResults>* m_pMultipleCommand;

// Operations
public:
	void ShowProcedures(LPCTSTR lpszProcedureName = NULL);
	void ShowTableSchema(LPCTSTR lpszTableName);
	void ShowTableData(LPCTSTR lpszTableName);
	void CallProcedure(LPCTSTR lpszProcName);
	void InsertRecord(LPCTSTR lpszTableName);
	void ShowDatabase();
	void EraseList();
	int  DisplayData(CRowset<CManualAccessor>* pRS, struct MYBIND* pBind);

protected:
	BOOL    UpdateDatabase(int nRow, CEditDlg* pEditDlg);
	void    DisplayColumnHeadings(UINT nStringID);
	void    AddItem(int nItem, int nSubItem, LPCTSTR lpszItem);
	void    AdjustColumnWidths();
	HRESULT SelectRecord(int nRow, CCommand<CManualAccessor>* pRS,
				TCHAR (**lpszColumns)[40], ULONG* pulColumns);
	void    DeleteRecord();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBListView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL
	void OnKeyDown(NMHDR *pNotifyStruct, LRESULT *result);

// Implementation
protected:
	virtual ~CDBListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	DBROWCOUNT m_lRows;
	CString m_strQuery;
	//{{AFX_MSG(CDBListView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnUpdateNextResult(CCmdUI* pCmdUI);
	afx_msg void OnNextResult();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DBViewVw.cpp
inline CDBViewDoc* CDBListView::GetDocument()
   { return (CDBViewDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

#endif // __DBLISTVW_H__

/////////////////////////////////////////////////////////////////////////////
