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
#include "PaletteDemo.h"
#include "ToolsPalette.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const int nInfoHeight = 50;	// Information area height
const int nHorzMargin = 5;
const int nVertMargin = 5;

/////////////////////////////////////////////////////////////////////////////
// CToolsPalette

CToolsPalette::CToolsPalette()
{
	m_nColumns = 2;
}

CToolsPalette::~CToolsPalette()
{
}


BEGIN_MESSAGE_MAP(CToolsPalette, CMFCToolBar)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CToolsPalette message handlers

CSize CToolsPalette::CalcSize (BOOL /*bVertDock*/)
{
	// Calculate palette bar size. First, calculate bar width
	// according to the number of columns:
	int cx = GetColumnWidth () * m_nColumns;

	// Now, wrap bar by width and calculate its height:
	int cy = WrapToolBar (cx) * GetRowHeight ();

	// Add vertical and horizontal margins:
	return CSize (cx + nHorzMargin * 2, cy + nInfoHeight + nVertMargin * 2);
}
//**********************************************************************************
void CToolsPalette::AdjustLocations ()
{
	CRect rectClient;
	GetClientRect (rectClient);

	int x = rectClient.left + nHorzMargin;
	int y = rectClient.top + nVertMargin;

	// Set buttons locations:
	for (POSITION pos = m_Buttons.GetHeadPosition (); pos != NULL;)
	{
		CMFCToolBarButton* pButton = (CMFCToolBarButton*) m_Buttons.GetNext (pos);
		ASSERT_VALID (pButton);

		pButton->SetRect (CRect (CPoint (x, y), CSize (GetColumnWidth (), GetRowHeight ())));

		if (pButton->m_bWrap && pos != NULL)
		{
			// Start next row:
			y += GetRowHeight ();
			x = rectClient.left + nHorzMargin;
		}
		else
		{
			// Move to the next column:
			x += GetColumnWidth ();
		}
	}

	// Set info. area rectangle (at the bottom of bar):
	if (y + GetRowHeight () < rectClient.bottom)
	{
		m_rectInfo = rectClient;
		m_rectInfo.top = y + GetRowHeight ();
		m_rectInfo.DeflateRect (nHorzMargin, nVertMargin);
	}
	else
	{
		m_rectInfo.SetRectEmpty ();
	}
}
//**********************************************************************************
void CToolsPalette::SetColumns (int nColumns)
{
	m_nColumns = nColumns;

	if (GetSafeHwnd () != NULL && GetParentFrame () != NULL)
	{
		GetParentFrame ()->RecalcLayout ();
	}
}
//**********************************************************************************
void CToolsPalette::DoPaint(CDC* pDC)
{
	CMFCToolBar::DoPaint (pDC);

	//-----------------------
	// Draw information area:
	//-----------------------
	if (m_rectInfo.Height () > 10)
	{
		pDC->Draw3dRect (m_rectInfo,	afxGlobalData.clrBarShadow, 
										afxGlobalData.clrBarHilite);

		CFont* pOldFont = (CFont*) pDC->SelectStockObject (DEFAULT_GUI_FONT);
		pDC->SetBkMode (TRANSPARENT);

		pDC->DrawText (CString (_T("Info")), m_rectInfo, DT_VCENTER | DT_CENTER | DT_SINGLELINE);

		pDC->SelectObject (pOldFont);
	}
}
