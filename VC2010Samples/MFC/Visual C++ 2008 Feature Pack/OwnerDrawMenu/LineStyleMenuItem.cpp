// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "LineStyleMenuItem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CLineStyleMenuItem, CMFCToolBarMenuButton)

const int nHorzMargin = 5;

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CLineStyleMenuItem::CLineStyleMenuItem(int nWidth, UINT uiCmdID, LPCTSTR lpszText,
									   BOOL bIsChecked) :
	CMFCToolBarMenuButton (uiCmdID, NULL /* HMENU */, -1 /*iImage*/, lpszText)
{
	m_nWidth = nWidth;

	if (bIsChecked)
	{
		m_nStyle |= TBBS_CHECKED;
	}
}
//*****************************************************************************************
CLineStyleMenuItem::~CLineStyleMenuItem()
{
}
//*****************************************************************************************
void CLineStyleMenuItem::OnDraw (CDC* pDC, const CRect& rect, CMFCToolBarImages* /*pImages*/,
			BOOL /*bHorz*/, BOOL /*bCustomizeMode*/, BOOL bHighlight,
			BOOL /*bDrawBorder*/, BOOL /*bGrayDisabledButtons*/)
{
	ASSERT_VALID (pDC);

	CRect rectItem = rect;
	rectItem.DeflateRect (1, 1);

	//--------------------
	// Fill item interior:
	//--------------------
	FillInterior (pDC, rectItem, bHighlight);

	//-----------------
	// Draw text label:
	//-----------------
	CRect rectText = rectItem;
	rectText.DeflateRect (nHorzMargin, 0);
	rectText.right = rectText.left + afxGlobalData.GetTextWidth () * 4;

	pDC->DrawText (m_strText, rectText, DT_SINGLELINE | DT_VCENTER);

	//-----------
	// Draw line:
	//-----------
	CRect rectLine = rectItem;
	rectLine.left = rectText.right;
	rectLine.DeflateRect (nHorzMargin, 0);

	rectLine.top = (rect.top + rect.bottom - m_nWidth) / 2;
	rectLine.bottom = rectLine.top + m_nWidth;

	pDC->FillSolidRect (rectLine, GetSysColor (COLOR_WINDOWTEXT));

	//-------------
	// Draw border:
	//-------------
	if (m_nStyle & TBBS_CHECKED)
	{
		pDC->Draw3dRect (rectItem, GetSysColor (COLOR_3DSHADOW), GetSysColor (COLOR_3DHILIGHT));
	}
	else if (bHighlight)
	{
		pDC->Draw3dRect (rectItem, GetSysColor (COLOR_3DHILIGHT), GetSysColor (COLOR_3DSHADOW));
	}
}
//**************************************************************************************
void CLineStyleMenuItem::CopyFrom (const CMFCToolBarButton& s)
{
	CMFCToolBarButton::CopyFrom (s);

	const CLineStyleMenuItem& src = (const CLineStyleMenuItem&) s;
	m_nWidth = src.m_nWidth;
}
//**************************************************************************************
SIZE CLineStyleMenuItem::OnCalculateSize (CDC* pDC, const CSize& /*sizeDefault*/, BOOL /*bHorz*/)
{
	TEXTMETRIC tm;
	pDC->GetTextMetrics (&tm);

	return CSize (
		afxGlobalData.GetTextWidth () * 4 + 50,	// Text + line
		max (m_nWidth, tm.tmHeight) + 4);
}
