// slowcalc.cpp : implementation of the recalc engine, which is reused by
//                both demonstrations of recalculating: single thread,
//                and worker thread.
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


BOOL SlowAdd(int nInt1, int nInt2, int& nResult, CRecalcThreadInfo* pInfo, int nSeconds,
	HWND hwndNotifyProgress)
{
	CWnd* pWndNotifyProgress = CWnd::FromHandle(hwndNotifyProgress);

	BOOL bRestartCalculation = TRUE;
	while (bRestartCalculation)
	{
		bRestartCalculation = FALSE;
		// Do the calculation 5% at a time, allowing for interruption to
		// restart calculation.
		for (int nCount = 1; nCount < 20; nCount++)
		{
			if (pInfo != NULL
				&& WaitForSingleObject(pInfo->m_hEventKillRecalcThread, 0)  == WAIT_OBJECT_0)
			{
				if (hwndNotifyProgress != NULL)
				{
					// Reset progress indication to 0 (recalculation not begun)
					pWndNotifyProgress->PostMessage(WM_USER_RECALC_IN_PROGRESS);
				}
				return FALSE; // Terminate this recalculation
			}

			if (pInfo != NULL
				&&WaitForSingleObject(pInfo->m_hEventStartRecalc, 0) == WAIT_OBJECT_0)
			{
				// Get new source data for the calculation.
				nInt1 = pInfo->m_nInt1;
				nInt2 = pInfo->m_nInt2;
				bRestartCalculation = TRUE;
				continue;
			}

			// Notify window about each 5% of progress
			if (hwndNotifyProgress != NULL)
			{
				// If calculating in a single thread, send rather than post the
				// "in progress" message, so that the progress is reflected
				// immediately in the status bar.  Otherwise, the posted "in
				// progress" messages won't be handled until after the recalculation
				// has totally completed.
				//
				// If calculating in a separate thread, however, then post rather
				// than send the "in progress" message.  Otherwise, in the case where
				// the main thread tries to kill the worker thread, there may be
				// a deadlock where the main thread is doing a WaitForSingleObject
				// on the "kill done" event while the worker thread is waiting for
				// the main thread to handle the sent message.
				if (pInfo == NULL)
				{
					pWndNotifyProgress->SendMessage(WM_USER_RECALC_IN_PROGRESS, nCount*5);
				}
				else
				{
					pWndNotifyProgress->PostMessage(WM_USER_RECALC_IN_PROGRESS, nCount*5);
				}
			}
			// Sleep 1/20th of total recalc time, which is 50 milliseconds
			// per each of total number of seconds (nSeconds) of recalc time.
			Sleep(nSeconds * 50);

		}

		if (hwndNotifyProgress != NULL)
		{
			// See comment above regarding post versus send message.
			if (pInfo == NULL)
				pWndNotifyProgress->SendMessage(WM_USER_RECALC_IN_PROGRESS, 100);
			else
				pWndNotifyProgress->PostMessage(WM_USER_RECALC_IN_PROGRESS, 100);

		}
	}

	nResult = nInt1 + nInt2;
	return TRUE;
}
