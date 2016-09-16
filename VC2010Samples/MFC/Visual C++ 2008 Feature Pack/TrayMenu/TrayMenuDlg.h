// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CTrayMenuDlg dialog

#define CDialog CDialogEx

class CTrayMenuDlg : public CDialog
{
// Construction
public:
	CTrayMenuDlg(CWnd* pParent = NULL);	// standard constructor
	virtual ~CTrayMenuDlg();

// Dialog Data
	enum { IDD = IDD_TRAYMENU_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support

// Implementation
protected:
	HICON m_hIcon;

	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAppAbout();
	afx_msg void OnAppExit();
	afx_msg void OnAppOpen();
	afx_msg void OnItem1();
	afx_msg void OnItem2();
	afx_msg void OnItem3();
	afx_msg void OnItem4();
	afx_msg void OnUpdateItem4(CCmdUI* pCmdUI);
	afx_msg LRESULT OnTrayNotify(WPARAM wp, LPARAM lp);

	DECLARE_MESSAGE_MAP()

	NOTIFYICONDATA	m_nid;			// struct for Shell_NotifyIcon args

	void OnTrayContextMenu ();
};

