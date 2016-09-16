// MDrive.h : main header file for the MDRIVE application
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __AFXWIN_H__
	#error include 'premdriv.h' before including this file for PCH
#endif

#include "mdrivres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMDriveApp:
// See MDrive.cpp for the implementation of this class
//

class CMDriveApp : public CWinApp
{
public:
	CMDriveApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDriveApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMDriveApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////
