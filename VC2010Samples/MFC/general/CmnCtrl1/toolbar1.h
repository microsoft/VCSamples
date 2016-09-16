// Toolbar1.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CStandardBar window
#ifndef INC_TOOLBAR1_H
#define INC_TOOLBAR1_H

class CStandardBar : public CToolBarCtrl
{
private:
	int         m_nButtonCount;
	TBBUTTON    *m_pTBButtons;
	using CToolBarCtrl::Create;

// Construction
public:
	CStandardBar();

// Attributes
public:

// Operations
public:


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStandardBar)
	public:
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	virtual BOOL Create( DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID);
	//}}AFX_VIRTUAL


// Implementation
public:
	virtual ~CStandardBar();

protected:
	BOOL BeginAdjust(WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	BOOL BeginDrag(WPARAM wParam, LPARAM  lParam, LRESULT* pLResult);
	BOOL CustomizeHelp(WPARAM wParam, LPARAM  lParam, LRESULT* pLResult);
	BOOL EndAdjust(WPARAM wParam, LPARAM  lParam, LRESULT* pLResult);
	BOOL EndDrag(WPARAM wParam, LPARAM  lParam, LRESULT* pLResult);
	BOOL GetButtonInfo(WPARAM wParam, LPARAM  lParam, LRESULT* pLResult);
	BOOL QueryDelete(WPARAM wParam, LPARAM  lParam, LRESULT* pLResult);
	BOOL QueryInsert(WPARAM wParam, LPARAM  lParam, LRESULT* pLResult);
	BOOL Reset(WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	BOOL ToolBarChange(WPARAM wParam, LPARAM lParam,LRESULT* pLResult);
	CString NeedText(UINT nID, NMHDR * pNotifyStruct, LRESULT * lResult);

	// Generated message map functions
protected:
	//{{AFX_MSG(CStandardBar)
	afx_msg void OnNeedTextW( UINT nID, NMHDR * pNotifyStruct, LRESULT * lResult );
	afx_msg void OnNeedTextA( UINT nID, NMHDR * pNotifyStruct, LRESULT * lResult );
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#endif
