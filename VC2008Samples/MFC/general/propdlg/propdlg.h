// propdlg.h : main header file for the PROPDLG application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#define WM_USER_CHANGE_OBJECT_PROPERTIES (WM_USER + 1)

/////////////////////////////////////////////////////////////////////////////
// CPropDlgApp:
// See propdlg.cpp for the implementation of this class
//

class CPropDlgApp : public CWinApp
{
public:
	CPropDlgApp();

// Overrides
	// ClassWizard generate virtual function overrides
	//{{AFX_VIRTUAL(CPropDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPropDlgApp)
	afx_msg void OnAppAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
