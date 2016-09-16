
// MFCDirect2DHelloWorld.h : main header file for the MFCDirect2DHelloWorld application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCDirect2DHelloWorldApp:
// See MFCDirect2DHelloWorld.cpp for the implementation of this class
//

class CMFCDirect2DHelloWorldApp : public CWinApp
{
public:
	CMFCDirect2DHelloWorldApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCDirect2DHelloWorldApp theApp;
