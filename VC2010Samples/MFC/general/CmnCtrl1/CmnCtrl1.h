// CmnCtrl1.h : main header file for the CMNCTRL1 application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#if !defined(AFX_CMNCTRL1_H__A14ECE83_E24D_11D0_8286_00C04FD73634__INCLUDED_)
#define AFX_CMNCTRL1_H__A14ECE83_E24D_11D0_8286_00C04FD73634__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

#define TTT_BUF_SIZE	80	/* szText is a buffer of size 80 (from commctrl.h) */

/////////////////////////////////////////////////////////////////////////////
// CCmnCtrl1App:
// See CmnCtrl1.cpp for the implementation of this class
//
#define CELEMS(rgFoo) (sizeof(rgFoo) / sizeof(rgFoo[0]))

class CCmnCtrl1App : public CWinApp
{
public:
	CCmnCtrl1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCmnCtrl1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCmnCtrl1App)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMNCTRL1_H__A14ECE83_E24D_11D0_8286_00C04FD73634__INCLUDED_)
