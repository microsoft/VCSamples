// mainfrm.cpp : implementation of the CMainFrame class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "bounce.h"
#include "hello.h"
#include "mdi.h"

#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_COMMAND(IDM_BOUNCE, OnBounce)
	ON_COMMAND(IDM_HELLO, OnHello)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}


/////////////////////////////////////////////////////////////////////////////
// CMainFrame commands

#pragma warning(push)
#pragma warning(disable : 6014) // see comment in function
void CMainFrame::OnBounce()
{
	CBounceWnd *pBounceWnd = new CBounceWnd;
	if (!pBounceWnd->Create(_T("Bounce"),
		WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, rectDefault, this))
		return;

	// the default PostNcDestroy handler will delete this object when destroyed
}


void CMainFrame::OnHello()
{
	CHelloWnd *pHelloWnd = new CHelloWnd;
	if (!pHelloWnd->Create(_T("Hello"),
		WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		rectDefault, this))
		return;

	// the default PostNcDestroy handler will delete this object when destroyed
}
#pragma warning(pop)
