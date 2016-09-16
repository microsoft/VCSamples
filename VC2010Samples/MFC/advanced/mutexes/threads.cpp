// threads.cpp : implementation file
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
// This sample application is derived from the Mutex application
// distributed with Jeffrey Richter's "Advanced Windows" programming book
// (Microsoft Press).  See the book for more information about Win32
// programming topics, including thread synchronization.

#include "stdafx.h"
#include "mutexes.h"
#include "mutexdlg.h"
#include "threads.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNCREATE(CExampleThread, CWinThread)

CExampleThread::CExampleThread()
{
	m_bDone = FALSE;
	m_pOwner = NULL;
	m_bAutoDelete = FALSE;
}

/////////////////////////////////////////////////////////////////////////////
// CCounterThread

IMPLEMENT_DYNCREATE(CCounterThread, CExampleThread)

CCounterThread::CCounterThread()
{
}

CCounterThread::~CCounterThread()
{
}

BOOL CCounterThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CCounterThread::Run()
{
	BOOL fSyncChecked;
	unsigned int nNumber;

	if (m_pOwner == NULL)
		return -1;

	CSingleLock sLock(&(m_pOwner->m_mutex));

	while (!m_bDone)
	{
		// Get the status of the Synchronize
		// check box and save it.

		fSyncChecked = m_pOwner->IsDlgButtonChecked(IDC_SYNCHRONIZE);

		// If the user wants us synchronized, do it!
		if (fSyncChecked)
			sLock.Lock();

		VERIFY( _stscanf_s((LPCTSTR) m_pOwner->m_strNumber, _T("%d"), &nNumber) == 1 );
		nNumber++;
		
		m_pOwner->m_strNumber.SetAt(0,L'\0');
		int nCurrentDigitPos=0;
		while (nNumber != 0)
		{
			m_pOwner->m_strNumber.ReleaseBufferSetLength(nCurrentDigitPos+1);
			m_pOwner->m_strNumber.SetAt(nCurrentDigitPos,(TCHAR) ('0' + nNumber%10));

			// A call to Sleep() here tells the system that we want
			// to relinquis the remainder of our time slice to
			// another thread.  this call is needed for
			// single-CPU systems so that the results of the
			// synchronization or lack thereof are obvious.
			// Normally, your programs would NOT call Sleep() here.

			Sleep(0);

			// get ready to get the next digit.
			nNumber /= 10;
			++nCurrentDigitPos;
		}

		// Characters were generated in reverse order,
		// reverse the string
		m_pOwner->m_strNumber.MakeReverse();

		if (fSyncChecked)
		{
		// If the user wants synchronization, do it.
			sLock.Unlock();
		}

		// If the user wants to display something
		// after each iteration, do it.

		if (m_pOwner->IsDlgButtonChecked(IDC_SHOWCNTRTHRD))
			m_pOwner->AddToListBox(_T("Cntr: Increment"));
	}

	m_pOwner->PostMessage(WM_CLOSE, 0, 0L);
	return 0;
}

BEGIN_MESSAGE_MAP(CCounterThread, CWinThread)
	//{{AFX_MSG_MAP(CCounterThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCounterThread message handlers
/////////////////////////////////////////////////////////////////////////////
// CDisplayThread

IMPLEMENT_DYNCREATE(CDisplayThread, CExampleThread)

CDisplayThread::CDisplayThread()
{
}

CDisplayThread::~CDisplayThread()
{
}

BOOL CDisplayThread::InitInstance()
{
	// TODO:  perform and per-thread initialization here
	return TRUE;
}

int CDisplayThread::Run()
{
	BOOL fSyncChecked;
	CString strBuffer;

	ASSERT(m_pOwner != NULL);
	if (m_pOwner == NULL)
		return -1;

	CSingleLock sLock(&(m_pOwner->m_mutex));

	while (!m_bDone)
	{
		// Determine whether the user wants the threads
		// to be synchronized.

		fSyncChecked = m_pOwner->IsDlgButtonChecked(IDC_SYNCHRONIZE);

		if (fSyncChecked)
			sLock.Lock();

		// Construct a string with the string form of the number.

		strBuffer = _T("Dspy: ");
		strBuffer += m_pOwner->m_strNumber;

		if (fSyncChecked)
			sLock.Unlock();

		// Add the string form of the number to the list box.
		m_pOwner->AddToListBox(strBuffer);
	}

	m_pOwner->PostMessage(WM_CLOSE, 0, 0L);
	return 0;
}

BEGIN_MESSAGE_MAP(CDisplayThread, CWinThread)
	//{{AFX_MSG_MAP(CDisplayThread)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisplayThread message handlers
