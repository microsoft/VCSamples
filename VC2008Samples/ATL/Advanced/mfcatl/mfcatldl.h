// MfcAtlDl.h : header file
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

/////////////////////////////////////////////////////////////////////////////
// CMfcAtlDlg dialog

class CMfcAtlDlg : public CDialog
{
// Construction
public:
	CMfcAtlDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMfcAtlDlg)
	enum { IDD = IDD_MFCATL_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcAtlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	virtual void PostNcDestroy();

	// Generated message map functions
	//{{AFX_MSG(CMfcAtlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg void OnPressClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
