
// MFCDirect2DApp.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols

// CMFCDirect2DAppApp:
// See MFCDirect2DApp.cpp for the implementation of this class
//

class CMFCDirect2DAppApp : public CWinApp
{
public:
	CMFCDirect2DAppApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCDirect2DAppApp theApp;
