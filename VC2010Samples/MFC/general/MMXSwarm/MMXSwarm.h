// MMXSwarm.h : main header file for the MMXSwarm application
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMMXSwarmApp:

// See MMXSwarm.cpp for the implementation of this class
//
class CChildView;

class CMMXSwarmApp : public CWinApp
{
public:
	CMMXSwarmApp();

// Overrides
public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);

// Implementation
public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

private:
	CChildView *m_pView; // For forwarding OnIdle()
};
