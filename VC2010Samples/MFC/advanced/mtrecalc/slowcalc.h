// slowcalc.h   Simulation of a calculation that takes a long time
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

BOOL SlowAdd(int nInt1, int nInt2, int& nResult, CRecalcThreadInfo* pInfo, int nSeconds,
	HWND hwndNotifyProgress);
