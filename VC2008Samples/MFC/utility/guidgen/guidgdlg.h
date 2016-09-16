// guidgdlg.h : header file
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
// CGuidGenDlg dialog

class CGuidGenDlg : public CDialog
{
// Construction
public:
	CGuidGenDlg(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
	//{{AFX_DATA(CGuidGenDlg)
	enum { IDD = IDD_GUIDGEN_DIALOG };
	int     m_nGuidType;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGuidGenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	GUID m_guid;    // generated GUID
	void GetFormattedGuid(CString& rString);

	// Generated message map functions
	//{{AFX_MSG(CGuidGenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	afx_msg void OnNewguid();
	//}}AFX_MSG
	afx_msg void OnChangedSel(UINT nID);
	DECLARE_MESSAGE_MAP()
};
