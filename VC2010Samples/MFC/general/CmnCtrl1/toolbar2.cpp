// ToolBar2.cpp : implementation file
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
#include "afxpriv.h"
#include "CmnCtrl1.h"
#include "Toolbar2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPaletteBar

CPaletteBar::CPaletteBar() : m_pTBButtons(NULL)
{

}

CPaletteBar::~CPaletteBar()
{
	delete []m_pTBButtons;
}

BEGIN_MESSAGE_MAP(CPaletteBar, CToolBarCtrl)
	//{{AFX_MSG_MAP(CPaletteBar)
	ON_NOTIFY_RANGE( TTN_NEEDTEXTA, 0, 0xFFFF, OnNeedTextA)
	ON_NOTIFY_RANGE( TTN_NEEDTEXTW, 0, 0xFFFF, OnNeedTextW)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


BOOL CPaletteBar::Create(DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID )
{
	BOOL bRet = CToolBarCtrl::Create(dwStyle, rect, pParentWnd, nID);

	m_nButtonCount = ID_ELLIPSE - ID_ERASE + 1;

	VERIFY(AddBitmap(m_nButtonCount,IDR_PALETTEBAR) != -1);

	m_pTBButtons = new TBBUTTON[m_nButtonCount];

	int nIndex;
	for (nIndex = 0; nIndex < m_nButtonCount; nIndex++)
	{
		CString string;
		string.LoadString(nIndex + ID_ERASE);

		// Add second '\0'
		int nStringLength = string.GetLength() + 1;
		TCHAR* pString = string.GetBufferSetLength(nStringLength);
		pString[nStringLength] = 0;

		VERIFY((m_pTBButtons[nIndex].iString = AddStrings(pString)) != -1);

		string.ReleaseBuffer();


		m_pTBButtons[nIndex].fsState = TBSTATE_ENABLED;
		m_pTBButtons[nIndex].fsStyle = TBSTYLE_CHECKGROUP;
		m_pTBButtons[nIndex].dwData = 0;
		m_pTBButtons[nIndex].iBitmap = nIndex;
		m_pTBButtons[nIndex].idCommand = nIndex + ID_ERASE;

	}


	for (nIndex = 0; nIndex < m_nButtonCount; nIndex++)
	{
		VERIFY(AddButtons(1,&m_pTBButtons[nIndex]));
	}


	return bRet;
}


/////////////////////////////////////////////////////////////////////////////
// CPaletteBar message handlers

// MFC routes the notifications sent to the parent of the control to
// the control before the parent can process the notification.
// The control object can handle the notification or ignore it.
// If the notification is handled then return TRUE. Otherwise MFC
// will route it to the parent of the control.

BOOL CPaletteBar::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult)
{
	if (message == WM_NOTIFY)
	{
		NMHDR *pNMHDR = (NMHDR *) lParam;
		switch (pNMHDR->code)
		{
		case TBN_BEGINADJUST :
			return BeginAdjust(wParam,  lParam,  pLResult);

		case TBN_BEGINDRAG:
			return BeginDrag(wParam,  lParam,  pLResult);

		case TBN_CUSTHELP:
			return CustomizeHelp(wParam,  lParam,  pLResult);

		case TBN_ENDADJUST:
			return EndAdjust(wParam,  lParam,  pLResult);

		case TBN_ENDDRAG:
			return EndDrag(wParam,  lParam,  pLResult);

		case TBN_GETBUTTONINFO:
			return GetButtonInfo(wParam,  lParam,  pLResult);

		case TBN_QUERYDELETE:
			return QueryDelete(wParam,  lParam,  pLResult);

		case TBN_QUERYINSERT:
			return QueryInsert(wParam,  lParam,  pLResult);

		case TBN_RESET:
			return Reset(wParam, lParam,  pLResult);

		case TBN_TOOLBARCHANGE:
			return ToolBarChange(wParam, lParam, pLResult);
		}
	}

	return CToolBarCtrl::OnChildNotify(message, wParam, lParam, pLResult);
}

BOOL CPaletteBar::BeginAdjust(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* /*pLResult*/)
{
	TRACE(_T("TBN_BEGINADJUST\n"));

	// the customize dialog box is about to be displayed

	// save toolbar state before customization using the dialog
	// Use this information to restore the state if reset button is pressed
	SaveState(HKEY_CURRENT_USER,_T("Software\\Microsoft\\VC70\\Samples\\CtrlDemo"),_T("Palette Tool Bar"));

	return TRUE;
}

BOOL CPaletteBar::BeginDrag(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* pLResult)
{
	TRACE(_T("TBN_BEGINDRAG\n"));

	// we are not implementing custon drag and drop
	* pLResult = FALSE;
	return FALSE;
}

BOOL CPaletteBar::CustomizeHelp(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* /*pLResult*/)
{
	TRACE(_T("TBN_CUSTHELP\n"));

	// Sample displays a message box but a valid help topic
	// can be displayed for the customize dialog for this toolbar
	AfxMessageBox(_T("Help not implemented!"));

	return TRUE;
}

BOOL CPaletteBar::EndAdjust(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* /*pLResult*/)
{
	TRACE(_T("TBN_ENDADJUST\n"));

	// the customize dialog box has been closed

	return TRUE;
}

BOOL CPaletteBar::EndDrag(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* pLResult)
{
	TRACE(_T("TBN_ENDDRAG\n"));

	// Code to handle custom drag and drop. This message indicates that
	// the item is being dropped
	* pLResult = FALSE;
	return TRUE;
}

BOOL CPaletteBar::GetButtonInfo(WPARAM /*wParam*/, LPARAM  lParam, LRESULT* pLResult)
{
	// This notification message has to be handled correctly if
	// all operations in the custom dialogbox has to function correctly
	// We have to supply information for the button specified by pTBN->tbButton
	//
	// This notification is sent in the following cases
	//
	// After TBN_BEGINADJUST the control sends these notifications until
	// * pLResult is TRUE. We have to supply valid values when this value is
	// set to TRUE. Here the control is collecting information for all
	// the buttons that have to be displayed in the dialog box
	//
	// The control sends this notification to get information about
	// a button if the user is trying to add it to the toolbar or
	// rearranging the buttons on the toolbar from within the dialog

	TRACE(_T("TBN_GETBUTTONINFO\n"));

	TBNOTIFY *pTBN = (TBNOTIFY *) lParam;

	if (pTBN->iItem >= m_nButtonCount || pTBN->iItem < 0)
	{
		* pLResult = FALSE;
	}
	else
	{
		CString buffer;
		buffer.LoadString(pTBN->iItem + ID_ERASE);

		// set the string for the button
		// truncate the string if its length is greater than the buffer
		// supplied by the toolbar
		_tcsncpy_s(pTBN->pszText, pTBN->cchText, buffer, _TRUNCATE);
		pTBN->pszText[pTBN->cchText - 1] = '\0';

		// set the button info
		pTBN->tbButton = m_pTBButtons[pTBN->iItem];

		// valid values are structure
		*pLResult = TRUE;
	}

	return TRUE;
}

BOOL CPaletteBar::QueryDelete(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* pLResult)
{
	TRACE(_T("TBN_QUERYDELETE\n"));

	// in this sample any button can be deleted
	// if a particular button cannot be deleted set *pResult to FALSE for that item
	*pLResult = TRUE;
	return TRUE;
}

BOOL CPaletteBar::QueryInsert(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* pLResult)
{
	TRACE(_T("TBN_QUERYINSERT\n"));

	// in this sample buttons can be inserted at any location on the
	// toolbar
	*pLResult = TRUE;
	return TRUE;
}

BOOL CPaletteBar::Reset(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* pLResult)
{
	TRACE(_T("TBN_RESET\n"));

	// User has pressed the reset button
	// restore the state of the toolbar to the state it was before customization
	RestoreState(HKEY_CURRENT_USER,_T("Software\\Microsoft\\VC70\\Samples\\CtrlDemo"),_T("Palette Tool Bar"));

	*pLResult = TRUE;
	return TRUE;
}

BOOL CPaletteBar::ToolBarChange(WPARAM /*wParam*/, LPARAM  /*lParam*/, LRESULT* /*pLResult*/)
{
	TRACE(_T("TBN_TOOLBARCHANGE\n"));

	// the toolbar has changed
	return TRUE;
}


// Helper function for tooltips

CString CPaletteBar::NeedText(UINT nID, NMHDR* pNotifyStruct, LRESULT* /*lResult*/ )
{
	LPTOOLTIPTEXT lpTTT = (LPTOOLTIPTEXT)pNotifyStruct ;
	ASSERT(nID == lpTTT->hdr.idFrom);

	CString toolTipText;
	toolTipText.LoadString(nID);

	// szText length is 80
	int nLength = (toolTipText.GetLength() > 79) ? 79 : toolTipText.GetLength();

	toolTipText = toolTipText.Left(nLength);

	return toolTipText;
}


void CPaletteBar::OnNeedTextW(UINT /*nID*/, NMHDR* pNotifyStruct, LRESULT * lResult )
{
	size_t numchars;

	if (pNotifyStruct->idFrom >= ID_ERASE && pNotifyStruct->idFrom <= ID_ELLIPSE)
	{
		CString toolTipText = NeedText((UINT)pNotifyStruct->idFrom, pNotifyStruct, lResult);
		LPTOOLTIPTEXTW lpTTT = (LPTOOLTIPTEXTW)pNotifyStruct;
#ifdef _UNICODE
		_tcsncpy_s(lpTTT->szText, TTT_BUF_SIZE, (LPCTSTR)toolTipText, toolTipText.GetLength());
#else
		mbstowcs_s(&numchars, lpTTT->szText, TTT_BUF_SIZE, (LPCTSTR)toolTipText, toolTipText.GetLength());
#endif
	}
}

void CPaletteBar::OnNeedTextA(UINT /*nID*/, NMHDR* pNotifyStruct, LRESULT * lResult )
{
	if (pNotifyStruct->idFrom >= ID_ERASE && pNotifyStruct->idFrom <= ID_ELLIPSE)
	{
		CString toolTipText = NeedText((UINT)pNotifyStruct->idFrom, pNotifyStruct, lResult);
		LPTOOLTIPTEXT lpTTT = (LPTOOLTIPTEXT)pNotifyStruct;
		_tcscpy_s(lpTTT->szText, TTT_BUF_SIZE, (LPCTSTR)toolTipText);
	}
}


