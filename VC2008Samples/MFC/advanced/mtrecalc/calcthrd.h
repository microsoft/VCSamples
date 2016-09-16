// calcthrd.h : interface of the controlling function of the recalc worker thread
//              and of the CRecalcUIThread class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

struct CRecalcThreadInfo
{
	int m_nInt1;
	int m_nInt2;
	int m_nSum;
	HWND m_hwndNotifyRecalcDone;
	HANDLE m_hEventStartRecalc;
	HANDLE m_hEventRecalcDone;
	HANDLE m_hEventKillRecalcThread;
	HANDLE m_hEventRecalcThreadKilled;
	int m_nRecalcSpeedSeconds;
	HWND m_hwndNotifyProgress;
};

// Controlling function for the worker thread.
UINT RecalcThreadProc(LPVOID pParam /* CRecalcThreadInfo ptr */);
