// calcthrd.cpp : implementation of the worker thread
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
#include "calcthrd.h"
#include "recaldoc.h"
#include "slowcalc.h"
#include "mtrecalc.h"

UINT RecalcThreadProc(LPVOID pParam)
{
	CRecalcThreadInfo* pRecalcInfo = (CRecalcThreadInfo*)pParam;

	// This recalc thread runs in an infinite loop, waiting to recalculate the
	// result whenever the main application thread sets the "start recalc" event.
	// The recalc thread exits the loop only when the main application sets the
	// "kill recalc" event.

	BOOL bRecalcCompleted = FALSE;
	while (TRUE)
	{
		bRecalcCompleted = FALSE;

		// Wait until the main application thread asks this thread to do
		//      another calculation.
		if (WaitForSingleObject(pRecalcInfo->m_hEventStartRecalc, INFINITE)
			!= WAIT_OBJECT_0)
			break;

		// Exit the thread if the main application sets the "kill recalc"
		// event. The main application will set the "start recalc" event
		// before setting the "kill recalc" event.

		if (WaitForSingleObject(pRecalcInfo->m_hEventKillRecalcThread, 0)
			== WAIT_OBJECT_0)
			break; // Terminate this thread by existing the proc.

		// Reset event to indicate "not done", that is, recalculation is in progress.
		ResetEvent(pRecalcInfo->m_hEventRecalcDone);

		bRecalcCompleted = SlowAdd(pRecalcInfo->m_nInt1,
			pRecalcInfo->m_nInt2,
			pRecalcInfo->m_nSum,
			pRecalcInfo,
			pRecalcInfo->m_nRecalcSpeedSeconds,
			pRecalcInfo->m_hwndNotifyProgress);

		// Set event to indicate that recalculation is done (i.e., no longer in progres),
		// even if perhaps interrupted by "kill recalc" event detected in the SlowAdd function.
		SetEvent(pRecalcInfo->m_hEventRecalcDone);

		if (!bRecalcCompleted)  // If interrupted by kill then...
			break; // terminate this thread by exiting the proc.

		::PostMessage(pRecalcInfo->m_hwndNotifyRecalcDone,
			WM_USER_RECALC_DONE, 0, 0);
	}

	if (!bRecalcCompleted)
		SetEvent(pRecalcInfo->m_hEventRecalcThreadKilled);

	return 0;
}
