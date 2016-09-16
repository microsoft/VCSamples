// dlgtempDlg.h : header file
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
// CDlgtempDlg dialog

#ifndef INC_SETUPDLG_H
#define INC_SETUPDLG_H

#include "itemtemp.h"
class CDlgtempDlg : public CDialog
{
// Construction
public:
	CDlgtempDlg(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgtempDlg)
	enum { IDD = IDD_DLGTEMP_DIALOG };
	CString m_strCaption;
	UINT    m_x;
	UINT    m_y;
	UINT    m_nWidth;
	UINT    m_nHeight;
	int     m_nItem;
	CString m_strSelectedItem;
	//}}AFX_DATA

	int     m_nActiveItem;

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgtempDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

	CMyDialogTemplate   m_dlgTemplate;
// Implementation
protected:
	HICON m_hIcon;

	void InfoToDialogHelper(int nItem, LPCTSTR lpszSelectedItem);

	// Generated message map functions
	//{{AFX_MSG(CDlgtempDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg void OnDemoIt();
	afx_msg void OnButtonInformation();
	afx_msg void OnStaticTextInformation();
	afx_msg void OnEditControlInformation();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif
