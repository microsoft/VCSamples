// CircCtl.cpp : Implementation of CcircApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "circ.h"
#include "CircCtl.h"

/////////////////////////////////////////////////////////////////////////////
//

HRESULT CCircCtl::OnDraw(ATL_DRAWINFO& di)
{
	USES_CONVERSION;
	if (di.dwDrawAspect != DVASPECT_CONTENT)
		return E_FAIL;

	HDC hdc = di.hdcDraw;
	HDC hic = di.hicTargetDev;
	if (hic == NULL)
		hic = AtlCreateTargetDC(hdc, di.ptd);
	RECT& rc = *(RECT*)di.prcBounds;

	HPEN hFore;
	HBRUSH hBack;
	COLORREF colBack,colFore;
	OleTranslateColor(m_clrForeColor, m_hPalette, &colFore);
	OleTranslateColor(m_clrBackColor, m_hPalette, &colBack);
	hFore = CreatePen(PS_SOLID, 2, RGB(0,0,0));
	hBack = CreateSolidBrush(colBack);
	HGDIOBJ hOldBrush = SelectObject(hdc, hBack);
	HGDIOBJ hOldPen = SelectObject(hdc, hFore);
	Ellipse(hdc, rc.left, rc.top, rc.right, rc.bottom);
	SetTextColor(hdc, colFore);
	SetBkMode(hdc, TRANSPARENT);
	TEXTMETRIC tm;
	GetTextMetrics(hic, &tm);
	LPTSTR szCaption = CW2T(m_bstrCaption,0);
	int cbCaption = lstrlen(szCaption);
	int cHeight = (rc.top > rc.bottom) ? -tm.tmHeight/2 : tm.tmHeight/2;
	HFONT hOldFont = NULL;
	if (m_pFont)
	{
		CComPtr<IFont> pFont;
		m_pFont->QueryInterface(IID_IFont, (void**)&pFont);
		HFONT hfont;
		pFont->get_hFont(&hfont);
		hOldFont = (HFONT) SelectObject(hdc, hfont);
	}
	ExtTextOut(hdc ,
			  rc.left + (rc.right - rc.left)/2 - (tm.tmAveCharWidth*cbCaption)/2,
			  rc.top + (rc.bottom - rc.top)/2 - cHeight, 0, &rc,
			   szCaption, cbCaption, 0);
	SelectObject(hdc, hOldPen);
	SelectObject(hdc, hOldBrush);
	SelectObject(hdc, hBack);
	if (hOldFont)
		SelectObject(hdc, hOldFont);
	if (hic != hdc)
		DeleteDC(hic);
	DeleteObject(hFore);
	DeleteObject(hBack);
	return 0;
}
