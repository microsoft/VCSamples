// File: MacroDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_MACRODLG_H__C4B24B98_0D5D_11D1_8E2F_00C04FB68D60__INCLUDED_)
#define AFX_MACRODLG_H__C4B24B98_0D5D_11D1_8E2F_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// MacroDlg.H : header file
//

class CScript;
class CScriptManager;

/////////////////////////////////////////////////////////////////////////////
// CMacroDlg dialog

class CMacroDlg :
   public CDialog
{
// Construction
public:
	CMacroDlg( CWnd* pParent = NULL );   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMacroDlg)
	enum { IDD = IDD_MACRO };
	CButton m_butRun;
	CListBox    m_lbMacros;
	CString m_strMacroName;
	//}}AFX_DATA

   CScriptManager* m_pScriptManager;
   CScript* m_pScript;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMacroDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   void UpdateMacroList();

	// Generated message map functions
	//{{AFX_MSG(CMacroDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnOpenFile();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MACRODLG_H__C4B24B98_0D5D_11D1_8E2F_00C04FB68D60__INCLUDED_)
