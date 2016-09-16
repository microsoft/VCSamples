// superpad.h : main header file for the SuperPad application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "resource.h"
#include "pageset.h"
#include "aboutbox.h"

/////////////////////////////////////////////////////////////////////////////
// CTheApp

class CTheApp : public CWinApp
{
// Constructors
public:
	CTheApp();
	~CTheApp();

// Implementation
private:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	virtual BOOL OnIdle(LONG lCount);
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	DWORD m_dwSplashTime;
	CSplashWnd m_splash;

	COleTemplateServer m_server;

	//{{AFX_MSG(CTheApp)
	afx_msg void OnAppAbout();
	afx_msg void OnPageSetup();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

extern CPageSetupDlg NEAR dlgPageSetup;
extern CTheApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
