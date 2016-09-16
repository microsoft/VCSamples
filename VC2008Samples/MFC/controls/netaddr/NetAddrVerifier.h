// NetAddrVerifier.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CNetAddrVerifierApp:
// See NetAddrVerifier.cpp for the implementation of this class
//

class CNetAddrVerifierApp : public CWinApp
{
public:
	CNetAddrVerifierApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
	afx_msg void OnVerifyIPv4();
};

extern CNetAddrVerifierApp theApp;