// FireWnd.h : Declaration of the CFireWnd
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __FIREWND_H_
#define __FIREWND_H_

#include "resource.h"       // main symbols
#include "size.h"
#include "propdlg.h"

/////////////////////////////////////////////////////////////////////////////
// CFireWnd

class CFireWnd :
	public CDialogImpl<CFireWnd>
{

public:

	CFireWnd();
	~CFireWnd();

	enum { IDD = IDD_FIREWND };

BEGIN_MSG_MAP(CFireWnd)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
	MESSAGE_HANDLER(WM_PAINT, OnPaint)
	MESSAGE_HANDLER(WM_RBUTTONDOWN, OnRButtonDown)
	MESSAGE_HANDLER(WM_DESTROY, OnDestroy)
	MESSAGE_HANDLER(WM_PALETTECHANGED, OnPaletteChanged)
	MESSAGE_HANDLER(WM_QUERYNEWPALETTE, OnQueryNewPalette)
	MESSAGE_HANDLER(WM_TIMER, OnTimer)
	MESSAGE_HANDLER(WM_SIZE, OnSize)
	COMMAND_ID_HANDLER(IDM_PROPERTIES, OnProperties)
END_MSG_MAP()

public:
	// Message handlers
	LRESULT OnDestroy(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnPaint(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnSize(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnPaletteChanged(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnQueryNewPalette(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnTimer(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
	LRESULT OnProperties(WORD wNotifyCode, WORD wID, HWND hWndCtlr, BOOL& bHandled);
	LRESULT OnRButtonDown(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

	// Fire Attributes

	long m_nDecay;
	long m_nFlammability;
	long m_nMaxHeat;
	long m_nSpreadRate;
	long m_nSize;
	long m_nSmoothness;
	long m_nDistribution;
	long m_nChaos;
	long m_curColor;
	long m_MaxBurn;
	UINT m_uTimerID;

	CSize rcSize;   // the size of the rect cached from SetObjectRects
	CSize bmSize;   // bitmap size cx = width, cy = height
protected:

	HMENU m_hRightMenu;
	HMENU m_hPropMenu;
	BYTE* m_Fire;
	int m_nFireSize;

	// Seed used by faster Rand().
	static unsigned long m_RandSeed;

	// Device Context Attributes
	HDC m_hMemDC;
	HDC m_hWinDC;

	// Palette Attributes
	RGBQUAD m_rgbPalette[256];
	HPALETTE m_hPalette;
	HPALETTE m_pOldPalette;

	// Bitmap Attributes
	HBITMAP m_hBitmap;
	HBITMAP m_pOldBitmap;

	BYTE* m_pBits;

// Operations
public:
	enum { red = 1, blue=2, green = 3 };
	void InitFire();
	HPALETTE* GetPalette();
	void RenderFlame();
	void PaintFlame(HDC hDC = NULL);
	void CreatePopup();
	void CreatePalette(int nColor);

protected:
	void CreateBitmap();
	void BurnPoint(BYTE* pRow, BYTE* pNextRow);

	// This function replaces the crt lib rand() function.
	// The CRT lib function is very slow.  Since rand() is
	// one of the most frequently called functions it was
	// necessary to optimize it.  This function may be
	// inlined and is computationally simple.
	unsigned long Rand();

};


inline unsigned long CFireWnd::Rand()
{
	// Using the current seed, generate a new random value
	// and seed and return it.  The random value is shifted
	// to reduce some of the noise and produce a more
	// realistic flame.
	return (m_RandSeed = 1664525L * m_RandSeed + 1013904223L) >> 5;
}

inline void CFireWnd::BurnPoint(BYTE* pRow, BYTE* pNextRow)
{
	BYTE* pTarget;

	int off = Rand() % (m_nDistribution + 1);

	int val = m_nDecay + 1;
	val = Rand() % val;
	val = *pNextRow - val;

	if (Rand() & 1)
		pTarget = pRow + off;
	else
		pTarget = pRow - off;

	if (val > 16)
		*pTarget = (BYTE)val;
	else
		*pTarget = 16;
}

#endif //__FIREWND_H_
