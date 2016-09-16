// VariantUseDlg.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_VARIANTUSEDLG_H__0E9FDA47_3143_11D2_9373_00C04FD9757C__INCLUDED_)
#define AFX_VARIANTUSEDLG_H__0E9FDA47_3143_11D2_9373_00C04FD9757C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVarUseDlg dialog

class CVarUseDlg : public CDialog
{
// Construction
public:
	void FunctionCallWithVariant(VARIANT myVariant);
	CVarUseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVarUseDlg)
	enum { IDD = IDD_VARIANTUSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVarUseDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVarUseDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCurrency();
	afx_msg void OnStrings();
	afx_msg void OnBasic();
	afx_msg void OnSafeArray();
	afx_msg void OnOleArray();
	afx_msg void OnMultiDimensionArray();
	afx_msg void OnDate();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VARIANTUSEDLG_H__0E9FDA47_3143_11D2_9373_00C04FD9757C__INCLUDED_)
