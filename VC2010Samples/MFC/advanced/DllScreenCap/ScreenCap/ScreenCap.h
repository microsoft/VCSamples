// ScreenCap.h : main header file for the ScreenCap application
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols


// CScreenCapApp:
// See ScreenCap.cpp for the implementation of this class
//

class CScreenCapApp : public CWinApp
{
public:
	CScreenCapApp();


// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	BOOL PreTranslateMessage(MSG* pMsg);
	BOOL OnIdle(LONG lCount);
};

extern CScreenCapApp theApp;