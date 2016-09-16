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
#include "mtbounce.h"

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

void CMainFrame::OnBounce()
{
#pragma warning(push)
#pragma warning(disable:6014)
	CBounceMDIChildWnd *pBounceMDIChildWnd = new CBounceMDIChildWnd;
#pragma warning(pop)
	if (!pBounceMDIChildWnd->Create( _T("Bounce"),
		WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW, rectDefault, this))
		return;
}

void CMainFrame::OnHello()
{
#pragma warning(push)
#pragma warning(disable:6014)
	CHelloWnd *pHelloWnd = new CHelloWnd;
#pragma warning(pop)

	if (!pHelloWnd->Create(_T("Hello"),
		WS_CHILD | WS_VISIBLE | WS_OVERLAPPEDWINDOW,
		rectDefault, this))
		return;

	// the default PostNcDestroy handler will delete this object when destroyed
}

static BOOL CALLBACK SendPrepareToClose(HWND hWnd, LPARAM)
{
	CWnd* pWnd = CWnd::FromHandlePermanent(hWnd);
	if (pWnd != NULL)
	{
		pWnd->SendMessage(WM_USER_PREPARE_TO_CLOSE);
		if (pWnd->GetWindow(GW_CHILD) != NULL)
			::EnumChildWindows(pWnd->m_hWnd, SendPrepareToClose, 0);
	}
	return TRUE;
}

BOOL CMainFrame::DestroyWindow()
{
	::EnumChildWindows(m_hWnd, SendPrepareToClose, 0);

	return CMDIFrameWnd::DestroyWindow();
}
