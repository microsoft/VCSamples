// combobar.cpp : implementation of the CComboToolBar and CTBComboBox class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//

#include "stdafx.h"
#include "np.h"
#include "combobar.h"
#include "mainfrm.h"
#include "npdoc.h"
#include "npview.h"
#include "finddlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(CComboToolBar, CToolBar)
	//{{AFX_MSG_MAP(CComboToolBar)
	//}}AFX_MSG_MAP
	ON_CBN_SETFOCUS(IDW_COMBO, OnSetFocus)
END_MESSAGE_MAP()


void CComboToolBar::OnSetFocus()
{
	// combobox is gaining focus, highlight text in edit control
	m_toolBarCombo.SetEditSel(0,-1);
}

BOOL CComboToolBar::PreTranslateMessage(MSG* pMsg)
{
	// Note: there is only one control in the toolbar that accepts keyboard input,
	// this is the combobox.

	// user hit ENTER
	if (pMsg->wParam == VK_RETURN && GetKeyState(VK_RETURN) < 0)
	{
		// extract the text, update combobox lists, and do the search
		CString s1;
		m_toolBarCombo.GetWindowText(s1);

		if(s1.GetLength())
		{
			CNotepadView* pView = GetApplicationView();
			m_toolBarCombo.SetEditSel(0, -1);
			pView->m_searchHistory.AddString(s1);   // update combobox history list
			pView->m_pFindDialog->m_szText = s1;                // update last string
			pView->OnViewFindNext(s1);                      // find the string
			return TRUE;  // key processed
		}
		else
		{
			MessageBeep(MB_ICONEXCLAMATION);
			return TRUE;  // key processed
		}
	}

	// user hit ESC
	if (pMsg->wParam == VK_ESCAPE && GetKeyState(VK_ESCAPE) < 0)
	{
		GetApplicationView()->SetFocus();
		return TRUE; // key processed
	}

	// user hit DOWN-ARROW
	if (pMsg->wParam == VK_DOWN && GetKeyState(VK_DOWN) < 0 &&
		m_toolBarCombo.GetDroppedState() == FALSE)
	{
		m_toolBarCombo.ShowDropDown();
		return TRUE; // key processed
	}

	return  CToolBar::PreTranslateMessage(pMsg);
}

BEGIN_MESSAGE_MAP(CTBComboBox, CComboBox)
	//{{AFX_MSG_MAP(CTBComboBox)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

int CTBComboBox::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CComboBox::OnCreate(lpCreateStruct) == -1)
		return -1;

	LOGFONT logFont;
	TEXTMETRIC tm;
	CClientDC dc(this);

	dc.GetTextMetrics(&tm);
	::EnumFontFamilies(dc.m_hDC, _T("MS Sans Serif"),
						CTBComboBox::FontEnumProc, (LPARAM)&logFont);

	// change the weight and create the font
	logFont.lfWeight = FW_BOLD;
	if (m_font.CreateFontIndirect(&logFont))
		SetFont(&m_font);

	return 0;
}

int CALLBACK CTBComboBox::FontEnumProc(const LOGFONT *pLogFont, const TEXTMETRIC* /*pTextMetric*/, DWORD /*type*/, LPARAM pDestLogFont)
{
	memcpy_s((BYTE*)pDestLogFont, sizeof(LOGFONT), pLogFont, sizeof(LOGFONT));
	return FALSE; // return the first font in the family(i.e. smallest).
}
