// CmnCtrl3.h : main header file for the CmnCtrl3 application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CCmnCtrl3App:
// See CmnCtrl3.cpp for the implementation of this class
//

class CCmnCtrl3App : public CWinApp
{
public:
	CCmnCtrl3App();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CCmnCtrl3App theApp;
