// DlgCbar.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/*****************************************************************************
  Purpose:
	Interface for CTheApp.  This class encapsulates the initialization,
	running, and termination of the DLGCBAR application.  There must be
	exactly one object of class CTheApp in the application.  The object
	must be declared at the global level.

  Functions:
	CTheApp::CTheApp()          -- constructor
	CTheApp::~CTheApp()         -- destructor
	CTheApp::FirstInstance()    -- locate first instance of app
	CTheApp::InitInstance()     -- initialize app-instance
	CTheApp::OnHelpAbout()      -- display About box

  Development Team:
	Mary Kirtland
  Ported to 32-bit by:
	Mike Hedley
  Created by Microsoft Product Support Services, Premier ISV Support
  Copyright (c) Microsoft Corporation.  All rights reserved.
\****************************************************************************/

#ifndef __DLGCBAR_H__
#define __DLGCBAR_H__

class CTheApp : public CWinApp
{
public:
	CTheApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTheApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTheApp();

protected:
	BOOL FirstInstance();

	// Generated message map functions
	//{{AFX_MSG(CTheApp)
	afx_msg void OnHelpAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#endif //__DLGCBAR_H__
