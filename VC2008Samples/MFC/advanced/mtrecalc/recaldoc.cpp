// recaldoc.cpp : implementation of the CRecalcDoc class
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
#include "mtrecalc.h"
#include "calcthrd.h"
#include "recaldoc.h"
#include "slowcalc.h"
#include "speeddlg.h"
#include "recalcvw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecalcDoc

IMPLEMENT_DYNCREATE(CRecalcDoc, CDocument)

BEGIN_MESSAGE_MAP(CRecalcDoc, CDocument)
	ON_COMMAND_RANGE(ID_SINGLE_THREAD, ID_UI_THREAD, OnDemoThread)
	ON_UPDATE_COMMAND_UI_RANGE(ID_SINGLE_THREAD, ID_UI_THREAD, OnUpdateDemoThread)
	//{{AFX_MSG_MAP(CRecalcDoc)
	ON_COMMAND(ID_RECALC_SPEED, OnRecalcSpeed)
	ON_COMMAND(ID_KILL_WORKER_THREAD, OnKillWorkerThread)
	ON_UPDATE_COMMAND_UI(ID_KILL_WORKER_THREAD, OnUpdateKillWorkerThread)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecalcDoc construction/destruction

CRecalcDoc::CRecalcDoc()
{
	m_nInt1 = m_nInt2 = m_nSum = 0;
	m_bRecalcNeeded = m_bRecalcInProgress = FALSE;
	m_nRecalcSpeedSeconds = 5;

	m_nCurrentDemoCommand = ID_SINGLE_THREAD;

	m_hEventStartRecalc = CreateEvent(NULL, FALSE, FALSE, NULL); // auto reset, initially reset
	m_hEventRecalcDone = CreateEvent(NULL, TRUE, TRUE, NULL); // manual reset, initially set
	m_hEventKillRecalcThread = CreateEvent(NULL, FALSE, FALSE, NULL); // auto reset, initially reset
	m_hEventRecalcThreadKilled = CreateEvent(NULL, FALSE, FALSE, NULL); // auto reset, initially reset

	m_recalcThreadInfo.m_hEventStartRecalc = m_hEventStartRecalc;
	m_recalcThreadInfo.m_hEventRecalcDone = m_hEventRecalcDone;
	m_recalcThreadInfo.m_hEventKillRecalcThread = m_hEventKillRecalcThread;
	m_recalcThreadInfo.m_hEventRecalcThreadKilled = m_hEventRecalcThreadKilled;

	m_pRecalcWorkerThread = NULL;
}

CRecalcDoc::~CRecalcDoc()
{
	// In this application, the document owns the worker thread.
	// The document's destructor is responsible for killing the active worker
	// thread.

	// It's a good idea to wait for the worker thread to notify via a
	// "thread killed" event that it has killed itself. Otherwise, in the case
	// where the app is terminating, is possible (even if unlikely) that it
	// will detect a memory leak of the CWinThread object before the
	// CWinThread object has had a chance to auto-delete itself.

	DWORD dwExitCode;
	if (m_pRecalcWorkerThread != NULL &&
		GetExitCodeThread(m_pRecalcWorkerThread->m_hThread, &dwExitCode) &&
		dwExitCode == STILL_ACTIVE)
	{
		// Kill the worker thread by setting the "kill thread" event.
		// See comment in OnKillWorkerThread for explanation of the sequence
		// of the "kill thread" and "start recalc" events.
		SetEvent(m_hEventKillRecalcThread);
		SetEvent(m_hEventStartRecalc);
		WaitForSingleObject(m_hEventRecalcThreadKilled, INFINITE);
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRecalcDoc overrides


BOOL CRecalcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	return TRUE;
}

BOOL CRecalcDoc::OnSaveDocument(LPCTSTR lpszPathName)
{
	if (m_bRecalcInProgress)
	{
		if (AfxMessageBox(IDS_CONTINUE_RECALC_BEFORE_SAVE, MB_YESNO) == IDYES)
		{
			BeginWaitCursor();
			WaitForSingleObject(m_hEventRecalcDone, INFINITE);
			RecalcDone();
			EndWaitCursor();
		}
		else
		{
			AfxMessageBox(IDS_FILE_NOT_SAVED);
			return FALSE;
		}
	}
	else if (m_bRecalcNeeded) // recalc needed but not in progress
	{
		if (AfxMessageBox(IDS_NEED_RECALC_BEFORE_SAVE, MB_YESNO) == IDYES)
		{
			BeginWaitCursor();

			// Update the document from data in the view and start recalculation.
			POSITION pos = GetFirstViewPosition();
			ASSERT(pos != NULL);
			CView* pView = GetNextView(pos);
			pView->SendMessage(WM_USER_RECALC_NOW, 0, 0);

			WaitForSingleObject(m_hEventRecalcDone, INFINITE);
			RecalcDone();
			EndWaitCursor();
		}
		else
		{
			AfxMessageBox(IDS_FILE_NOT_SAVED);
			return FALSE;
		}
	}
	return CDocument::OnSaveDocument(lpszPathName);
}


/////////////////////////////////////////////////////////////////////////////
// CRecalcDoc serialization

void CRecalcDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		ar << (WORD)m_nInt1;
		ar << (WORD)m_nInt2;
		ar << (WORD)m_nSum;
	}
	else
	{
		WORD w;
		ar >> w;
		m_nInt1 = w;
		ar >> w;
		m_nInt2 = w;
		ar >> w;
		m_nSum = w;
	}
}

/////////////////////////////////////////////////////////////////////////////
// CRecalcDoc diagnostics

#ifdef _DEBUG
void CRecalcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CRecalcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


/////////////////////////////////////////////////////////////////////////////
// CRecalcDoc operations and implementation

void CRecalcDoc::UpdateInt1AndInt2(int n1, int n2, BOOL bForceRecalc)
{
	if (!bForceRecalc && m_nInt1 == n1 && m_nInt2 == n2)
		return;  // recalculation not needed

	SetModifiedFlag();
	m_nInt1 = n1;
	m_nInt2 = n2;

	m_bRecalcNeeded = m_bRecalcInProgress = TRUE;
	// Synchronize the int1 and int2 fields in the other views,
	// and show "recalculating..." in the sum field.
	UpdateAllViews(NULL);

	switch (m_nCurrentDemoCommand)
	{
		case ID_SINGLE_THREAD:
			RecalcInSingleThread();
			break;

		case ID_WORKER_THREAD:
			RecalcInSecondThread();
			break;
		default:
			ASSERT(FALSE);
	}
}


void CRecalcDoc::RecalcInSingleThread()
{
	SlowAdd(m_nInt1, m_nInt2, m_nSum, NULL, m_nRecalcSpeedSeconds, AfxGetMainWnd()->m_hWnd);

	m_bRecalcNeeded = m_bRecalcInProgress = FALSE;

	// Update the "sum" field.
	UpdateAllViews(NULL, UPDATE_HINT_SUM);

}

void CRecalcDoc::RecalcInSecondThread()
{
	if (m_pRecalcWorkerThread == NULL)
	{
		// Begin the worker thread.  It is ok to fill in the CThreadInfo
		// structure after the thread has started, because the thread
		// waits for the "start recalc" event before referring to the structure.
		m_pRecalcWorkerThread =
			AfxBeginThread(RecalcThreadProc, &m_recalcThreadInfo);
	}

	m_recalcThreadInfo.m_nInt1 = m_nInt1;
	m_recalcThreadInfo.m_nInt2 = m_nInt2;
	POSITION pos = GetFirstViewPosition();
	ASSERT(pos != NULL);
	CView* pView = GetNextView(pos);
	ENSURE(pView != NULL);
	m_recalcThreadInfo.m_hwndNotifyRecalcDone = pView->m_hWnd;
	m_recalcThreadInfo.m_hwndNotifyProgress = AfxGetMainWnd()->m_hWnd;
	m_recalcThreadInfo.m_nRecalcSpeedSeconds = m_nRecalcSpeedSeconds;

	// The events are initially set or reset in the CreateEvent call;
	// but they may be left in an improperly initialized state if
	// a worker thread has been previously started and then prematurely
	// killed.  Set/reset the events to the proper initial state.
	// Set the "start recalc" event last, since it is the event the
	// triggers the starting of the worker thread recalculation.
	SetEvent(m_hEventRecalcDone);
	ResetEvent(m_hEventKillRecalcThread);
	ResetEvent(m_hEventRecalcThreadKilled);
	SetEvent(m_hEventStartRecalc);
	// RecalcDone() will be called by the view when the thread sends a
	// WM_USER_RECALC_DONE message.
}

void CRecalcDoc::RecalcDone()
{   // Called by the view when the worker thread sends a WM_USER_RECALC_DONE message.

	m_nSum = m_recalcThreadInfo.m_nSum;
	m_bRecalcNeeded = m_bRecalcInProgress = FALSE;
	UpdateAllViews(NULL, UPDATE_HINT_SUM);
}


/////////////////////////////////////////////////////////////////////////////
// CRecalcDoc commands

void CRecalcDoc::OnDemoThread(UINT nCmdID)
{
	m_nCurrentDemoCommand = nCmdID;
}

void CRecalcDoc::OnUpdateDemoThread(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(pCmdUI->m_nID == m_nCurrentDemoCommand);
}

void CRecalcDoc::OnRecalcSpeed()
{
	CSpeedDlg dlg;
	dlg.m_nRecalcSpeedSeconds = m_nRecalcSpeedSeconds;
	if (dlg.DoModal() == IDOK)
		m_nRecalcSpeedSeconds = dlg.m_nRecalcSpeedSeconds;
}

void CRecalcDoc::OnKillWorkerThread()
{
	// The worker thread periodically checks for the "kill recalc" event
	// during its execution of a recalculation.  When the worker thread
	// is not currently recalculating, it is waiting for a "start recalc"
	// event.  Therefore, in order to kill the thread that might be waiting
	// for the "start recalc" event, it is necessary to first set the
	// "start recalc" event.
	SetEvent(m_hEventKillRecalcThread);
	SetEvent(m_hEventStartRecalc);

	WaitForSingleObject(m_hEventRecalcThreadKilled, INFINITE);

	m_pRecalcWorkerThread = NULL;
	m_bRecalcInProgress = FALSE; // but m_bRecalcNeeded is still TRUE
	UpdateAllViews(NULL, UPDATE_HINT_SUM);
}

void CRecalcDoc::OnUpdateKillWorkerThread(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_nCurrentDemoCommand == ID_WORKER_THREAD
			&& m_pRecalcWorkerThread != NULL);
}
