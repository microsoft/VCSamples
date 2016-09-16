// Scheduler.h : main header file for the PROJECT_NAME application
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#ifndef __SCHEDULER_H_
#define __SCHEDULER_H

#define BROWN ((long)0x993366)
#define BLACK ((long)0x000000)
#define AQUA ((long)0x99ffff)
#define YELLOW ((long)0xfffacd)
#define BLUE ((long)0x0000cc)
#define RED ((long)0xff0066)

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "MyScheduler.h"
#include "resource.h"		// main symbols

template <> 
void __stdcall SerializeElements <CMyScheduler> ( CArchive& ar, CMyScheduler* pSchedule, INT_PTR nCount );

/////////////////////////////////////////////////////////////////////////////
// CSchedulerApp:
// See Scheduler.cpp for the implementation of this class
//

class CSchedulerApp : public CWinApp
{
public:
	CSchedulerApp();

// Overrides
	public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

#endif
