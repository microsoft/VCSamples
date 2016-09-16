// mtbounce.cpp : Implements the user interface thread for the
//                bounce window.
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
#include "mtbounce.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

// A single global event handle is used to synchronize the termination
// of the application and the termination of bounce threads.  This
// synchronization avoids false memory leak detection of CBounceThread
// objects that did not have time to be auto-destroyed before the
// application terminates.
//
// The reason that m_hEventBounceThreadKilled cannot be a per-object member
// variable of the CBounceThread object is because the event handle must
// be referred to by the delete operator.   By the time the delete operator
// is called, the member variable no longer can be referenced.  The reason
// that it is permissable to use a global event, instead of per thread events,
// is that each CBounceWnd window is destroyed in sequence, one after another.
// Therefore, each CBounceThread is destroyed in sequence, one after another.

HANDLE CBounceThread::m_hEventBounceThreadKilled;

/////////////////////////////////////////////////////////////////////////////
// CBounceThread

IMPLEMENT_DYNCREATE(CBounceThread, CWinThread)

CBounceThread::CBounceThread()
{
}

CBounceThread::CBounceThread(HWND hwndParent) : m_hwndParent(hwndParent)
{
}

CBounceThread::~CBounceThread()
{
}

void CBounceThread::operator delete(void* p)
{
	// The exiting main application thread waits for this event before completely
	// terminating in order to avoid a false memory leak detection.  See also
	// CBounceWnd::OnNcDestroy in bounce.cpp.

	SetEvent(m_hEventBounceThreadKilled);

	CWinThread::operator delete(p);
}

int CBounceThread::InitInstance()
{
	CWnd* pParent = CWnd::FromHandle(m_hwndParent);
	CRect rect;
	pParent->GetClientRect(&rect);

	BOOL bReturn = m_wndBounce.Create(_T("BounceMTChildWnd"),
		WS_CHILD | WS_VISIBLE, rect, pParent);

	// It is important to set CWinThread::m_pMainWnd to the user interface
	// window.  This is required so that when the m_pMainWnd is destroyed,
	// the CWinThread is also automatically destroyed.  For insight into
	// how the CWinThread is automatically destroyed when the m_pMainWnd
	// window is destroyed, see the implementation of CWnd::OnNcDestroy
	// in wincore.cpp of the MFC sources.

	if (bReturn)
		m_pMainWnd = &m_wndBounce;

	return bReturn;
}

int CBounceThread::ExitInstance()
{
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CBounceThread, CWinThread)
	//{{AFX_MSG_MAP(CBounceThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBounceThread message handlers
