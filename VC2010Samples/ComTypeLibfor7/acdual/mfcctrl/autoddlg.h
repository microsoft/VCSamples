// autoddlg.h : header file
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
// CAutoDrivDlg dialog

class CAutoDrivDlg : public CDialog
{
// Construction
public:
	CAutoDrivDlg(CWnd* pParent = NULL ); // standard constructor

// Dialog Data
	//{{AFX_DATA(CAutoDrivDlg)
	enum { IDD = IDD_AUTODRIV_DIALOG };
	CString m_szText;
	short   m_x;
	short   m_y;
	BOOL    m_bUseDispatch;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoDrivDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	IAClickPtr m_pAutoClikObject;
	IDualAClickPtr m_pDualAutoClikObject;

	// Generated message map functions
	//{{AFX_MSG(CAutoDrivDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnClose();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnAnimateXY();
	afx_msg void OnAnimatePos();
	afx_msg void OnSetAll();
	afx_msg void OnSetPosition();
	afx_msg void OnSetText();
	afx_msg void OnSetX();
	afx_msg void OnSetY();
	afx_msg void OnRefresh();
	afx_msg void OnGetAll();
	afx_msg void OnGetPosition();
	afx_msg void OnUseDispatch();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
