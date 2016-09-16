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
#include "explorer.h"
#include "FolderBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

const int idTree = 1;

#define SHCNF_ACCEPT_INTERRUPTS 0x0001
#define SHCNF_ACCEPT_NON_INTERRUPTS 0x0002

UINT UWM_NOTIFY_RECYCLE_BIN = ::RegisterWindowMessage(_T("UWM_NOTIFY_RECYCLE_BIN"));

/////////////////////////////////////////////////////////////////////////////
// CFolderBar

CFolderBar::CFolderBar()
{
	m_ulRecycleBin = 0;
}

CFolderBar::~CFolderBar()
{
}


BEGIN_MESSAGE_MAP(CFolderBar, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_SETFOCUS()
	ON_WM_ERASEBKGND()
	ON_REGISTERED_MESSAGE(UWM_NOTIFY_RECYCLE_BIN, OnNotifyRecycleBin)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CFolderBar message handlers

int CFolderBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	CRect rectDummy (0, 0, 0, 0);
	const DWORD dwViewStyle =	WS_CHILD | WS_VISIBLE | TVS_HASLINES | 
								TVS_LINESATROOT | TVS_HASBUTTONS;

	m_wndShellTree.Create(dwViewStyle, rectDummy, this, idTree);
	
	LPITEMIDLIST ppidl;
	if (SHGetSpecialFolderLocation(GetSafeHwnd(),CSIDL_BITBUCKET, &ppidl) != NOERROR)
	{
		return 0;
	}

	SHChangeNotifyEntry scnIDL;
	scnIDL.pidl = ppidl;
	scnIDL.fRecursive = TRUE;

	m_ulRecycleBin = SHChangeNotifyRegister(m_hWnd, SHCNF_ACCEPT_INTERRUPTS | SHCNF_ACCEPT_NON_INTERRUPTS, SHCNE_ALLEVENTS,  UWM_NOTIFY_RECYCLE_BIN, 1, &scnIDL);
	return 0;
}

void CFolderBar::OnSize(UINT nType, int cx, int cy) 
{
	CDockablePane::OnSize(nType, cx, cy);
	
	m_wndShellTree.SetWindowPos (NULL, 0, 0,
		cx, cy,
		SWP_NOACTIVATE | SWP_NOZORDER);
}

void CFolderBar::OnSetFocus(CWnd* pOldWnd)
{
	CDockablePane::OnSetFocus(pOldWnd);
	m_wndShellTree.SetFocus ();
}

BOOL CFolderBar::OnEraseBkgnd(CDC* /*pDC*/) 
{
	return TRUE;
}
LRESULT CFolderBar::OnNotifyRecycleBin(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(wParam);
	if (lParam == SHCNE_UPDATEIMAGE)
	{
		m_wndShellTree.Refresh();
	}

	if (lParam == SHCNE_FREESPACE)
	{
		LPITEMIDLIST ppidl;
		if (SHGetSpecialFolderLocation(GetSafeHwnd(), CSIDL_BITBUCKET, &ppidl) != NOERROR)
		{
			return TRUE;
		}

		m_wndShellTree.SelectPath(ppidl);

		CMFCShellListCtrl* pList = m_wndShellTree.GetRelatedList();
		ASSERT_VALID(pList);

		pList->Refresh();
	}

	return TRUE;
}
void CFolderBar::OnDestroy()
{
	CDockablePane::OnDestroy();

	if (m_ulRecycleBin != 0)
	{
		SHChangeNotifyDeregister(m_ulRecycleBin);
	}
}
