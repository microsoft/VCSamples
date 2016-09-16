// TraceTool.h : main header file for the PROJECT_NAME application
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

#include "resource.h"		// main symbols


// CTraceToolApp:
// See TraceTool.cpp for the implementation of this class
//
class CTraceToolApp : public CWinApp
{
public:
	CTraceToolApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation
	ATL::CEvent m_hSingleInstanceEvent;

	DECLARE_MESSAGE_MAP()
};

extern CTraceToolApp theApp;
