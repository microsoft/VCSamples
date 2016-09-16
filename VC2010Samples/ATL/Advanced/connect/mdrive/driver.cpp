// Driver.cpp : Implementation of CDriveApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "premdriv.h"
#include "..\connect.h"
#include "Driver.h"

extern HDC hDrawDC;
extern unsigned int nHeight;
extern unsigned int nThreads;

/////////////////////////////////////////////////////////////////////////////
//

STDMETHODIMP CDriver::Fire(long l)
{
	m_cs.Lock();
	foo pos;
	if (!m_mapPos.Lookup(l, pos))
	{
		m_mapPos[l] = foo();
	}
	COLORREF cr = RGB(255,255,255);
	switch (l)
	{
	case 0:
		cr = RGB(255,0,0);
		break;
	case 1:
		cr = RGB(0,255,0);
		break;
	case 2:
		cr = RGB(0,0,255);
		break;
	case 3:
		cr = RGB(255,255,0);
		break;
	case 4:
		cr = RGB(255,0,255);
		break;
	case 5:
		cr = RGB(0,255,255);
		break;
	case 6:
		cr = RGB(64,64,64);
		break;
	case 7:
		cr = RGB(128,128,128);
		break;
	case 8:
		cr = RGB(192,192,192);
		break;
	case 9:
		cr = RGB(0,0,0);
		break;
	}
	int nH = nHeight/nThreads;
	if (pos.nDir == 1)
		SetPixel(hDrawDC, m_nID, nH*l+pos.nPos, cr);
	else
		SetPixel(hDrawDC, m_nID, nH*l+pos.nPos, RGB(0,0,0));
	pos.nPos += pos.nDir;
	if (pos.nPos >= nH)
	{
		pos.nDir = -1;
		pos.nPos = nH-1;
	}
	if (pos.nPos <= -1)
	{
		pos.nDir = 1;
		pos.nPos = 0;
	}
	m_mapPos[l] = pos;
	m_cs.Unlock();
	GdiFlush();
	return S_OK;
}
