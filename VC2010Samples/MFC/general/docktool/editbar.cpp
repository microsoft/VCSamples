// editbar.cpp : implementation file
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
#include "docktool.h"
#include "editbar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#define COMBOBOX_INDEX 5
#define COMBOBOX_WIDTH 150
#define COMBOBOX_HEIGHT 150
#define COMBOBOX_BITMAP 4

static UINT BASED_CODE EditButtons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_EDIT_BM_TOGGLE,
	ID_EDIT_BM_NEXT,
	ID_EDIT_BM_PREV,
	ID_EDIT_BM_CLEARALL,
		ID_SEPARATOR,
	ID_EDIT_FIND,
		ID_SEPARATOR,
	ID_EDIT_FINDINFILES,
		ID_SEPARATOR,
	ID_EDIT_INDENT,
	ID_EDIT_UNINDENT,
		ID_SEPARATOR,
	ID_WINDOW_NEW,
	ID_WINDOW_SPLIT,
	ID_WINDOW_CASCADE,
	ID_WINDOW_TILE_HORZ,
	ID_WINDOW_TILE_VERT,
};

/////////////////////////////////////////////////////////////////////////////
// CEditBar

CEditBar::CEditBar()
{
	m_bColor = TRUE;
}

CEditBar::~CEditBar()
{
}

BOOL CEditBar::Init(CWnd* pParentWnd, BOOL bColor, BOOL bToolTips)
{
	m_bColor = bColor;
	m_bVertical = FALSE;

	// start out with no borders
	DWORD dwStyle = WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_SIZE_DYNAMIC;
	if (bToolTips)
		dwStyle |= (CBRS_TOOLTIPS | CBRS_FLYBY);
	if (!Create(pParentWnd, dwStyle, IDW_EDIT_BAR))
	{
		return FALSE;
	}

	if (!SetColor(m_bColor))
		return FALSE;

	if(!SetButtons(EditButtons, sizeof(EditButtons)/sizeof(UINT)))
		return FALSE;

	CRect rect(-COMBOBOX_WIDTH, -COMBOBOX_HEIGHT, 0, 0);
	// The ID of the ComboBox is important for two reasons.  One, so you
	// can receive notifications from the control.  And also for ToolTips.
	// During HitTesting if the ToolBar sees that the mouse is one a child
	// control, the toolbar will lookup the controls ID and search for a
	// string in the string table with the same ID to use for ToolTips
	// and StatusBar info.
	if (!m_SearchBox.Create(WS_CHILD | CBS_DROPDOWN |
		CBS_AUTOHSCROLL | WS_VSCROLL | CBS_HASSTRINGS, rect, this,
		IDC_EDITBAR_SEARCHBOX))
	{
		return FALSE;
	}

	HFONT hFont = (HFONT)GetStockObject(DEFAULT_GUI_FONT);
	if (hFont == NULL)
		hFont = (HFONT)GetStockObject(ANSI_VAR_FONT);

	m_SearchBox.SendMessage(WM_SETFONT, (WPARAM)hFont);

	if(!SetHorizontal())
		return FALSE;

	return TRUE;
}

BOOL CEditBar::SetHorizontal()
{
	m_bVertical = FALSE;

	SetBarStyle((GetBarStyle() & ~CBRS_ALIGN_ANY) | CBRS_ALIGN_TOP);

	SetButtonInfo(COMBOBOX_INDEX, IDC_EDITBAR_SEARCHBOX, TBBS_SEPARATOR, COMBOBOX_WIDTH);

	if (m_SearchBox.m_hWnd != NULL)
	{
		CRect rect;
		GetItemRect(COMBOBOX_INDEX, rect);

		m_SearchBox.SetWindowPos(NULL, rect.left, rect.top, 0, 0, SWP_NOZORDER|SWP_NOACTIVATE|SWP_NOSIZE|SWP_NOCOPYBITS);
		m_SearchBox.ShowWindow(SW_SHOW);
	}

	return TRUE;
}

BOOL CEditBar::SetVertical()
{
	m_bVertical = TRUE;

	SetButtonInfo(COMBOBOX_INDEX, ID_EDIT_FIND, TBBS_BUTTON, COMBOBOX_BITMAP);

	if (m_SearchBox.m_hWnd != NULL)
		m_SearchBox.ShowWindow(SW_HIDE);

	return TRUE;
}

BOOL CEditBar::SetColor(BOOL bColor)
{
	m_bColor=bColor;

	if (m_bColor)
		return LoadBitmap(IDR_COLOR_EDITBAR);
	else
		return LoadBitmap(IDR_MONO_EDITBAR);
}

CSize CEditBar::CalcDynamicLayout(int nLength, DWORD dwMode)
{
	// if we're committing set the buttons appropriately
	if (dwMode & LM_COMMIT)
	{
		if (dwMode & LM_VERTDOCK)
		{
			if (!m_bVertical)
				SetVertical();
		}
		else
		{
			if (m_bVertical)
				SetHorizontal();
		}

		return CToolBar::CalcDynamicLayout(nLength, dwMode);
	}
	else
	{
		BOOL bOld = m_bVertical;
		BOOL bSwitch = (dwMode & LM_HORZ) ? bOld : !bOld;

		if (bSwitch)
		{
			if (bOld)
				SetHorizontal();
			else
				SetVertical();
		}


		CSize sizeResult = CToolBar::CalcDynamicLayout(nLength, dwMode);

		if (bSwitch)
		{
			if (bOld)
				SetHorizontal();
			else
				SetVertical();
		}

		return sizeResult;
	}
}

//CSize CEditBar::CalcFixedLayout(BOOL bStretch, BOOL bHorz)
//{
//      if (!bHorz && (m_dwStyle & CBRS_SIZE_DYNAMIC) && !(m_dwStyle & CBRS_FLOATING))
//  {
//      CSize size;
//
//      size = CControlBar::CalcFixedLayout(bStretch, bHorz);
//
//      CRect rect;
//      rect.SetRectEmpty();
//
//      CalcInsideRect(rect, bHorz);
//
//      size.cx = m_sizeVert.cx + (m_rectInsideVert.Width() - rect.Width());
//      size.cy = m_sizeVert.cy + (m_rectInsideVert.Height() - rect.Height());
//      return size;
//  }
//  else
//  {
//      if (m_bVertical)
//          SetHorizontal();
//
//      return CToolBar::CalcFixedLayout(bStretch, bHorz);
//  }
//}

BEGIN_MESSAGE_MAP(CEditBar, CToolBar)
	//{{AFX_MSG_MAP(CEditBar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CEditBar message handlers
