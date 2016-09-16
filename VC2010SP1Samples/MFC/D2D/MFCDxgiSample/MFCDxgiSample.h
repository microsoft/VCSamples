
// MFCDxgiSample.h : main header file for the MFCDxgiSample application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CMFCDxgiSampleApp:
// See MFCDxgiSample.cpp for the implementation of this class
//

class CMFCDxgiSampleApp : public CWinApp
{
public:
	CMFCDxgiSampleApp();


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCDxgiSampleApp theApp;
