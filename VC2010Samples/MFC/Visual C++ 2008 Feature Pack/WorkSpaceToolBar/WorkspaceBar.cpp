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
#include "WorkSpaceToolBar.h"
#include "WorkspaceBar.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar

BEGIN_MESSAGE_MAP(CWorkspaceBar, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_COMMAND_1, OnCommand1)
	ON_COMMAND(ID_COMMAND_2, OnCommand2)
	ON_COMMAND(ID_COMMAND_3, OnCommand3)
	ON_UPDATE_COMMAND_UI(ID_COMMAND_3, OnUpdateCommand3)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar construction/destruction

CWorkspaceBar::CWorkspaceBar()
{
	// TODO: add one-time construction code here

}

CWorkspaceBar::~CWorkspaceBar()
{
}

/////////////////////////////////////////////////////////////////////////////
// CWorkspaceBar message handlers

int CWorkspaceBar::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// Create toolbar:
	if (!m_wndToolBar.Create (this, AFX_DEFAULT_TOOLBAR_STYLE, AFX_IDW_TOOLBAR + 1) ||
		!m_wndToolBar.LoadToolBar(IDR_WORKSPACE_TOOLBAR, 0, 0, TRUE /* Is locked */))
	{
		TRACE0("Failed to create toolbar\n");
		return -1; // fail to create
	}

	m_wndToolBar.SetPaneStyle(m_wndToolBar.GetPaneStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);
		
	m_wndToolBar.SetPaneStyle (
		m_wndToolBar.GetPaneStyle () & 
			~(CBRS_GRIPPER | CBRS_SIZE_DYNAMIC | CBRS_BORDER_TOP | CBRS_BORDER_BOTTOM | CBRS_BORDER_LEFT | CBRS_BORDER_RIGHT));

	m_wndToolBar.SetOwner (this);

	// All commands will be routed via this control , not via the parent frame:
	m_wndToolBar.SetRouteCommandsViaFrame (FALSE);


	CRect rectDummy;
	rectDummy.SetRectEmpty ();

	// Create tabs window:
	if (!m_wndTabs.Create (CMFCTabCtrl::STYLE_3D, rectDummy, this, 1))
	{
		TRACE0("Failed to create workspace tab window\n");
		return -1;      // fail to create
	}

	m_wndTabs.SetImageList (IDB_WORKSPACE, 16, RGB (255, 0, 255));

	// Create tree windows.
	// TODO: create your own tab windows here:
	const DWORD dwViewStyle =	WS_CHILD | WS_VISIBLE | TVS_HASLINES | 
								TVS_LINESATROOT | TVS_HASBUTTONS;
	
	if (!m_wndTree1.Create (dwViewStyle, rectDummy, &m_wndTabs, 2) ||
		!m_wndTree2.Create (dwViewStyle, rectDummy, &m_wndTabs, 3))
	{
		TRACE0("Failed to create workspace view\n");
		return -1;      // fail to create
	}

	// Setup trees content:
	HTREEITEM hRoot1 = m_wndTree1.InsertItem (_T("Root 1"));
	m_wndTree1.InsertItem (_T("Item 1"), hRoot1);
	m_wndTree1.InsertItem (_T("Item 2"), hRoot1);

	HTREEITEM hRoot2 = m_wndTree2.InsertItem (_T("Root 2"));
	m_wndTree2.InsertItem (_T("Item 1"), hRoot2);
	m_wndTree2.InsertItem (_T("Item 2"), hRoot2);

	// Attach tree windows to tab:
	m_wndTabs.AddTab (&m_wndTree1, _T("First View"), 0 /* Image number */);
	m_wndTabs.AddTab (&m_wndTree2, _T("Second View"), 1 /* Image number */);

	return 0;
}

void CWorkspaceBar::OnSize(UINT nType, int cx, int cy) 
{
	CDockablePane::OnSize(nType, cx, cy);
	AdjustLayout ();
}

void CWorkspaceBar::OnCommand1() 
{
	MessageBox (_T("One!"));
}

void CWorkspaceBar::OnCommand2() 
{
	MessageBox (_T("Two!"));
}

static BOOL bIsThree = TRUE;

void CWorkspaceBar::OnCommand3() 
{
	MessageBox (_T("Three!"));
	bIsThree = !bIsThree;
}

void CWorkspaceBar::OnUpdateCommand3(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck (bIsThree);
}

void CWorkspaceBar::AdjustLayout ()
{
	CRect rectClient;
	GetClientRect (rectClient);

	int cyTlb = m_wndToolBar.CalcFixedLayout (FALSE, TRUE).cy;

	m_wndToolBar.SetWindowPos (NULL, 0, 0, 
								rectClient.Width (), cyTlb,
								SWP_NOACTIVATE | SWP_NOZORDER);
	m_wndTabs.SetWindowPos (NULL, 0, cyTlb, rectClient.Width (), rectClient.Height () - cyTlb,
							SWP_NOACTIVATE | SWP_NOZORDER);
}

void CWorkspaceToolBar::AdjustLayout ()
{
	CMFCToolBar::AdjustLayout ();

	((CWorkspaceBar*) GetParent ())->AdjustLayout ();
}
