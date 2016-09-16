// NotifyShowCase.cpp : implementation file
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
#include "CmnCtrl2.h"
#include "notifwdw.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNotifyShowCase

CNotifyShowCase::CNotifyShowCase()
{
	m_totalLines = 200;  // use this default
}

CNotifyShowCase::~CNotifyShowCase()
{
}

BEGIN_MESSAGE_MAP(CNotifyShowCase, CEdit)
	//{{AFX_MSG_MAP(CNotifyShowCase)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

notifDescrip CNotifyShowCase::m_rgNotifDescrip[NOTIFCOUNT] =
{
		// list control notifications
	{LVN_ITEMCHANGING, _T("LVN_ITEMCHANGING")},
	{LVN_ITEMCHANGED, _T("LVN_ITEMCHANGED")},
	{LVN_INSERTITEM, _T("LVN_INSERTITEM")},
	{LVN_DELETEITEM, _T("LVN_DELETEITEM")},
	{LVN_DELETEALLITEMS, _T("LVN_DELETEALLITEMS")},
	{LVN_BEGINLABELEDIT, _T("LVN_BEGINLABELEDIT")},
	{LVN_ENDLABELEDIT, _T("LVN_ENDLABELEDIT")},
	{LVN_BEGINDRAG, _T("LVN_BEGINDRAG")},
	{LVN_BEGINRDRAG, _T("LVN_BEGINRDRAG")},
	{LVN_COLUMNCLICK, _T("LVN_COLUMNCLICK")},
	{LVN_GETDISPINFO, _T("LVN_GETDISPINFO")},
	{LVN_SETDISPINFO, _T("LVN_SETDISPINFO")},
		// tree control notifications
	{TVN_ITEMEXPANDING, _T("TVN_ITEMEXPANDING")},
	{TVN_BEGINLABELEDIT, _T("TVN_BEGINLABELEDIT")},
	{TVN_ENDLABELEDIT, _T("TVN_ENDLABELEDIT")},
	{TVN_SELCHANGING, _T("TVN_SELCHANGING")},
	{TVN_SELCHANGED, _T("TVN_SELCHANGED")},
	{TVN_GETDISPINFO, _T("TVN_GETDISPINFO")},
	{TVN_SETDISPINFO, _T("TVN_SETDISPINFO")},
	{TVN_BEGINDRAG, _T("TVN_BEGINDRAG")},
	{TVN_KEYDOWN, _T("TVN_KEYDOWN")},
	{TVN_DELETEITEM, _T("TVN_DELETEITEM")},
	{TVN_ITEMEXPANDED, _T("TVN_ITEMEXPANDED")},
};


/////////////////////////////////////////////////////////////////////////////
// CNotifyShowCase message handlers
void CNotifyShowCase::AddLine(LPCTSTR lpsz)
{
	TCHAR   szt[50];
	int     nLastChar;
	int     cLines;

	if (GetLineCount() >= m_totalLines)
	{
		SetSel(0, LineLength(0), TRUE/*bNoScroll*/);  // select the first line
		Clear();  // and remove it
	}

	nLastChar = LineIndex((cLines = GetLineCount() - 1)) + LineLength(cLines);
	_stprintf_s(szt, 50, _T("%s\x0D\x0A"), lpsz);
	SetSel(nLastChar, nLastChar, TRUE/*bNoScroll*/);
	ReplaceSel(szt);
}

void CNotifyShowCase::ShowNotification(UINT nCode)
{
	int i;

	for (i = 0; i < NOTIFCOUNT; i++)    // linear search for few items is OK
		if (m_rgNotifDescrip[i].nCode == nCode)
			break;

	if (i == NOTIFCOUNT)
	{
		TCHAR szt[30];

		_stprintf_s(szt, 30, _T("UNKNOWN CODE (%d)"), nCode);
		AddLine(szt);
	}
	else
		AddLine(m_rgNotifDescrip[i]. sztCodeName);
}
