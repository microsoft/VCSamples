// File: LogDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_LOGGINGDLG_H__FB7E06FB_DD1D_11D0_8E12_00C04FB68D60__INCLUDED_)
#define AFX_LOGGINGDLG_H__FB7E06FB_DD1D_11D0_8E12_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// LoggingDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CLoggingDlg dialog

class CLoggingDlg : public CDialog
{
// Construction
public:
	CLoggingDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CLoggingDlg)
	enum { IDD = IDD_LOGGING };
	CButton m_butFileNameBrowse;
	CEdit   m_eboxFileName;
	CString m_strFileName;
	int     m_iLogType;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLoggingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CLoggingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnLogToDebug();
	afx_msg void OnLogToFile();
	afx_msg void OnFileNameBrowse();
	afx_msg void OnLogToNull();
	afx_msg void OnLogToOutput();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LOGGINGDLG_H__FB7E06FB_DD1D_11D0_8E12_00C04FB68D60__INCLUDED_)
