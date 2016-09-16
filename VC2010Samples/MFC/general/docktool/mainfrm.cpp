// mainfrm.cpp : implementation of the CMainFrame class
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
#include "tooldlg.h"

#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_TOOLS_TOOLBAR, OnToolsToolbar)
	ON_COMMAND(ID_BROWSE_CLASSGRAPH, OnMenuSelection)
	ON_WM_CLOSE()
	ON_COMMAND(ID_BROWSE_FILEOUTLINE, OnMenuSelection)
	ON_COMMAND(ID_BROWSE_GOTODEFINITION, OnMenuSelection)
	ON_COMMAND(ID_BROWSE_GOTOREFERENCE, OnMenuSelection)
	ON_COMMAND(ID_BROWSE_REVERSECLASSGRAPH, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_CALLSTACK, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_DISASSEMBLY, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_LOCALS, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_MEMORY, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_QUICKWATCH, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_REGISTERS, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_RESTART, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_RUNTOCURSOR, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_STEPINTO, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_STEPOUT, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_STEPOVER, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_STOPDEBUGGING, OnMenuSelection)
	ON_COMMAND(ID_DEBUG_WATCH, OnMenuSelection)
	ON_COMMAND(ID_EDIT_BM_CLEARALL, OnMenuSelection)
	ON_COMMAND(ID_EDIT_BM_NEXT, OnMenuSelection)
	ON_COMMAND(ID_EDIT_BM_PREV, OnMenuSelection)
	ON_COMMAND(ID_EDIT_BM_TOGGLE, OnMenuSelection)
	ON_COMMAND(ID_EDIT_COPY, OnMenuSelection)
	ON_COMMAND(ID_EDIT_CUT, OnMenuSelection)
	ON_COMMAND(ID_EDIT_FINDINFILES, OnMenuSelection)
	ON_COMMAND(ID_EDIT_INDENT, OnMenuSelection)
	ON_COMMAND(ID_EDIT_PASTE, OnMenuSelection)
	ON_COMMAND(ID_EDIT_UNDO, OnMenuSelection)
	ON_COMMAND(ID_EDIT_UNINDENT, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_AIRBRUSH, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_BRUSH, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_ERASE, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_EYEDROP, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_FILL, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_FRAME, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_LINE, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_OVAL, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_PEN, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_RECTANGLE, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_SELECT, OnMenuSelection)
	ON_COMMAND(ID_PALETTE_ZOOM, OnMenuSelection)
	ON_COMMAND(ID_RESOURCE_NEWACCELERATORTABLE, OnMenuSelection)
	ON_COMMAND(ID_RESOURCE_NEWBITMAP, OnMenuSelection)
	ON_COMMAND(ID_RESOURCE_NEWCURSOR, OnMenuSelection)
	ON_COMMAND(ID_RESOURCE_NEWICON, OnMenuSelection)
	ON_COMMAND(ID_RESOURCE_NEWMENU, OnMenuSelection)
	ON_COMMAND(ID_RESOURCE_NEWSTRINGTABLE, OnMenuSelection)
	ON_COMMAND(ID_RESOURCE_NEWVERSION, OnMenuSelection)
	ON_COMMAND(ID_EDIT_FIND, OnMenuSelection)
	//}}AFX_MSG_MAP
	// By making the Menu IDs that same as the ToolBar IDs
	// we can leverage off of code that is already provided
	// in MFCs implementation of CFrameWnd to check, uncheck
	// show and hide toolbars.
	ON_UPDATE_COMMAND_UI(IDW_BROWSE_BAR, OnUpdateControlBarMenu)
	ON_COMMAND_EX(IDW_BROWSE_BAR, OnBarCheck)
	ON_UPDATE_COMMAND_UI(IDW_DEBUG_BAR, OnUpdateControlBarMenu)
	ON_COMMAND_EX(IDW_DEBUG_BAR, OnBarCheck)
	ON_UPDATE_COMMAND_UI(IDW_EDIT_BAR, OnUpdateControlBarMenu)
	ON_COMMAND_EX(IDW_EDIT_BAR, OnBarCheck)
	ON_UPDATE_COMMAND_UI(IDW_PALETTE_BAR, OnUpdateControlBarMenu)
	ON_COMMAND_EX(IDW_PALETTE_BAR, OnBarCheck)
	ON_UPDATE_COMMAND_UI(IDW_RESOURCE_BAR, OnUpdateControlBarMenu)
	ON_COMMAND_EX(IDW_RESOURCE_BAR, OnBarCheck)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// arrays of IDs used to initialize control bars

// toolbar buttons - IDs are command buttons
static UINT BASED_CODE MainButtons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_FILE_NEW,
	ID_FILE_OPEN,
	ID_FILE_SAVE,
		ID_SEPARATOR,
	ID_EDIT_CUT,
	ID_EDIT_COPY,
	ID_EDIT_PASTE,
};
static UINT BASED_CODE ResourceButtons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_RESOURCE_NEWMENU,
	ID_RESOURCE_NEWCURSOR,
	ID_RESOURCE_NEWICON,
	ID_RESOURCE_NEWBITMAP,
	ID_RESOURCE_NEWSTRINGTABLE,
	ID_RESOURCE_NEWACCELERATORTABLE,
	ID_RESOURCE_NEWVERSION,
};
static UINT BASED_CODE DebugButtons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_DEBUG_RESTART,
	ID_DEBUG_STOPDEBUGGING,
	ID_DEBUG_STEPINTO,
	ID_DEBUG_STEPOUT,
	ID_DEBUG_STEPOVER,
	ID_DEBUG_RUNTOCURSOR,
	ID_DEBUG_QUICKWATCH,
	ID_DEBUG_WATCH,
	ID_DEBUG_LOCALS,
	ID_DEBUG_REGISTERS,
	ID_DEBUG_MEMORY,
	ID_DEBUG_CALLSTACK,
	ID_DEBUG_DISASSEMBLY,
};
static UINT BASED_CODE BrowseButtons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_BROWSE_GOTODEFINITION,
	ID_BROWSE_GOTOREFERENCE,
	ID_BROWSE_FILEOUTLINE,
	ID_BROWSE_CLASSGRAPH,
	ID_BROWSE_REVERSECLASSGRAPH,
};

static UINT BASED_CODE PaletteButtons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_PALETTE_ERASE,
	ID_PALETTE_PEN,
	ID_PALETTE_SELECT,
	ID_PALETTE_BRUSH,
	ID_PALETTE_AIRBRUSH,
	ID_PALETTE_FILL,
	ID_PALETTE_LINE,
	ID_PALETTE_EYEDROP,
	ID_PALETTE_ZOOM,
	ID_PALETTE_RECTANGLE,
	ID_PALETTE_FRAME,
	ID_PALETTE_OVAL,
};

static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// Helpers for saving/restoring window state

static TCHAR BASED_CODE szSection[] = _T("Settings");
static TCHAR BASED_CODE szWindowPos[] = _T("WindowPos");
static TCHAR szFormat[] = _T("%u,%u,%d,%d,%d,%d,%d,%d,%d,%d");

static BOOL PASCAL NEAR ReadWindowPlacement(LPWINDOWPLACEMENT pwp)
{
	CString strBuffer = AfxGetApp()->GetProfileString(szSection, szWindowPos);
	if (strBuffer.IsEmpty())
		return FALSE;

	WINDOWPLACEMENT wp;
	int nRead = _stscanf_s(strBuffer, szFormat,
		&wp.flags, &wp.showCmd,
		&wp.ptMinPosition.x, &wp.ptMinPosition.y,
		&wp.ptMaxPosition.x, &wp.ptMaxPosition.y,
		&wp.rcNormalPosition.left, &wp.rcNormalPosition.top,
		&wp.rcNormalPosition.right, &wp.rcNormalPosition.bottom);

	if (nRead != 10)
		return FALSE;

	wp.length = sizeof wp;
	*pwp = wp;
	return TRUE;
}

static void PASCAL NEAR WriteWindowPlacement(LPWINDOWPLACEMENT pwp)
	// write a window placement to settings section of app's ini file
{
    CString strBuffer;

    strBuffer.Format(szFormat,
        pwp->flags, pwp->showCmd,
        pwp->ptMinPosition.x, pwp->ptMinPosition.y,
        pwp->ptMaxPosition.x, pwp->ptMaxPosition.y,
        pwp->rcNormalPosition.left, pwp->rcNormalPosition.top,
        pwp->rcNormalPosition.right, pwp->rcNormalPosition.bottom);

    AfxGetApp()->WriteProfileString(szSection, szWindowPos, strBuffer);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	WINDOWPLACEMENT wp;
	if (ReadWindowPlacement(&wp))
		SetWindowPlacement(&wp);

	m_bColor = (AfxGetApp()->GetProfileInt(_T("General"),_T("Color"),1)!=0);
	m_bToolTips = (AfxGetApp()->GetProfileInt(_T("General"),_T("ToolTips"),1)!=0);

	if (!m_wndMainBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_DYNAMIC |
			CBRS_TOP | ((m_bToolTips)?(CBRS_TOOLTIPS | CBRS_FLYBY):0), IDW_MAIN_BAR) ||
		!m_wndMainBar.LoadBitmap(
			(m_bColor)?IDR_COLOR_MAINBAR:IDR_MONO_MAINBAR) ||
		!m_wndMainBar.SetButtons(MainButtons, sizeof(MainButtons)/sizeof(UINT)))
	{
		TRACE0("Failed to create mainbar\n");
		return -1;      // fail to create
	}
	if (!m_wndResourceBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_DYNAMIC |
			CBRS_TOP | ((m_bToolTips)?(CBRS_TOOLTIPS | CBRS_FLYBY):0), IDW_RESOURCE_BAR) ||
		!m_wndResourceBar.LoadBitmap(
			(m_bColor)?IDR_COLOR_RESOURCEBAR:IDR_MONO_RESOURCEBAR) ||
		!m_wndResourceBar.SetButtons(ResourceButtons, sizeof(ResourceButtons)/sizeof(UINT)))
	{
		TRACE0("Failed to create resourcebar\n");
		return -1;      // fail to create
	}
	if (!m_wndDebugBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_DYNAMIC |
			CBRS_TOP | ((m_bToolTips)?(CBRS_TOOLTIPS | CBRS_FLYBY):0), IDW_DEBUG_BAR) ||
		!m_wndDebugBar.LoadBitmap(
			(m_bColor)?IDR_COLOR_DEBUGBAR:IDR_MONO_DEBUGBAR) ||
		!m_wndDebugBar.SetButtons(DebugButtons, sizeof(DebugButtons)/sizeof(UINT)))
	{
		TRACE0("Failed to create debugbar\n");
		return -1;      // fail to create
	}
	if (!m_wndEditBar.Init(this,m_bColor,m_bToolTips))
	{
		TRACE0("Failed to create editbar\n");
		return -1;      // fail to create
	}
	if (!m_wndBrowseBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_DYNAMIC |
			CBRS_TOP | ((m_bToolTips)?(CBRS_TOOLTIPS | CBRS_FLYBY):0), IDW_BROWSE_BAR) ||
		!m_wndBrowseBar.LoadBitmap(
			(m_bColor)?IDR_COLOR_BROWSEBAR:IDR_MONO_BROWSEBAR) ||
		!m_wndBrowseBar.SetButtons(BrowseButtons, sizeof(BrowseButtons)/sizeof(UINT)))
	{
		TRACE0("Failed to create browsebar\n");
		return -1;      // fail to create
	}

	if (!m_wndPaletteBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_FIXED |
			CBRS_TOP | ((m_bToolTips)?(CBRS_TOOLTIPS | CBRS_FLYBY):0), IDW_PALETTE_BAR) ||
		!m_wndPaletteBar.LoadBitmap(
			(m_bColor)?IDR_COLOR_PALETTEBAR:IDR_MONO_PALETTEBAR) ||
		!m_wndPaletteBar.SetButtons(PaletteButtons, sizeof(PaletteButtons)/sizeof(UINT)))
	{
		TRACE0("Failed to create palettebar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}

	m_wndMainBar.SetWindowText(_T("Standard"));
	m_wndMainBar.EnableDocking(CBRS_ALIGN_ANY);

	m_wndResourceBar.SetWindowText(_T("Resource"));
	m_wndResourceBar.EnableDocking(CBRS_ALIGN_ANY);

	m_wndDebugBar.SetWindowText(_T("Debug"));
	m_wndDebugBar.EnableDocking(CBRS_ALIGN_ANY);

	m_wndEditBar.SetWindowText(_T("Edit"));
	m_wndEditBar.EnableDocking(CBRS_ALIGN_ANY);

	m_wndBrowseBar.SetWindowText(_T("Browse"));
	m_wndBrowseBar.EnableDocking(CBRS_ALIGN_ANY);

	m_wndPaletteBar.SetWindowText(_T("Palette"));
	m_wndPaletteBar.EnableDocking(CBRS_ALIGN_ANY);

	EnableDocking(CBRS_ALIGN_ANY);

	DockControlBar(&m_wndMainBar,AFX_IDW_DOCKBAR_TOP);
	DockControlBarLeftOf(&m_wndEditBar,&m_wndMainBar);
	DockControlBarLeftOf(&m_wndBrowseBar,&m_wndEditBar);

	DockControlBar(&m_wndResourceBar,AFX_IDW_DOCKBAR_BOTTOM);
	DockControlBarLeftOf(&m_wndDebugBar,&m_wndResourceBar);

	DockControlBar(&m_wndPaletteBar,AFX_IDW_DOCKBAR_RIGHT);

	// LoadBarState loads everything but the number of Columns in the Palette
	// we need to do that ourseleves.
	m_wndPaletteBar.SetColumns(AfxGetApp()->GetProfileInt(_T("General"),_T("Columns"),3));
	LoadBarState(_T("General"));

	return 0;
}

void CMainFrame::DockControlBarLeftOf(CToolBar* Bar,CToolBar* LeftOf)
{
	CRect rect;
	DWORD dw;
	UINT n;

	// get MFC to adjust the dimensions of all docked ToolBars
	// so that GetWindowRect will be accurate
	RecalcLayout();
	LeftOf->GetWindowRect(&rect);
	rect.OffsetRect(1,0);
	dw=LeftOf->GetBarStyle();
	n = 0;
	n = (dw&CBRS_ALIGN_TOP) ? AFX_IDW_DOCKBAR_TOP : n;
	n = (dw&CBRS_ALIGN_BOTTOM && n==0) ? AFX_IDW_DOCKBAR_BOTTOM : n;
	n = (dw&CBRS_ALIGN_LEFT && n==0) ? AFX_IDW_DOCKBAR_LEFT : n;
	n = (dw&CBRS_ALIGN_RIGHT && n==0) ? AFX_IDW_DOCKBAR_RIGHT : n;

	// When we take the default parameters on rect, DockControlBar will dock
	// each Toolbar on a seperate line.  By calculating a rectangle, we in effect
	// are simulating a Toolbar being dragged to that location and docked.
	DockControlBar(Bar,n,&rect);
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnToolsToolbar()
{
	CToolDlg ToolDlg;
	UINT nColumns = m_wndPaletteBar.GetColumns();
	nColumns = (nColumns < 4) ? nColumns - 2: 3;

	// If the style says the ToolBar is visible then it is visible.
	ToolDlg.m_bMain = ((m_wndMainBar.GetStyle() & WS_VISIBLE) != 0);
	ToolDlg.m_bResource = ((m_wndResourceBar.GetStyle() & WS_VISIBLE) != 0);
	ToolDlg.m_bDebug = ((m_wndDebugBar.GetStyle() & WS_VISIBLE) != 0);
	ToolDlg.m_bEdit = ((m_wndEditBar.GetStyle() & WS_VISIBLE) != 0);
	ToolDlg.m_bBrowse = ((m_wndBrowseBar.GetStyle() & WS_VISIBLE) != 0);
	ToolDlg.m_bPalette = ((m_wndPaletteBar.GetStyle() & WS_VISIBLE) != 0);

	ToolDlg.m_nColumns = nColumns;

	ToolDlg.m_nColor = (m_bColor) ? 0 : 1;
	ToolDlg.m_nToolTips = (m_bToolTips) ? 0 : 1;

	if (IDOK == ToolDlg.DoModal())
	{
		ShowControlBar(&m_wndMainBar, ToolDlg.m_bMain, FALSE);
		ShowControlBar(&m_wndResourceBar, ToolDlg.m_bResource, FALSE);
		ShowControlBar(&m_wndDebugBar, ToolDlg.m_bDebug, FALSE);
		ShowControlBar(&m_wndEditBar, ToolDlg.m_bEdit, FALSE);
		ShowControlBar(&m_wndBrowseBar, ToolDlg.m_bBrowse, FALSE);
		ShowControlBar(&m_wndPaletteBar, ToolDlg.m_bPalette, FALSE);
		m_bToolTips = (ToolDlg.m_nToolTips==0);
		if (m_bToolTips)
		{
			m_wndMainBar.SetBarStyle(m_wndMainBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
			m_wndResourceBar.SetBarStyle(m_wndResourceBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
			m_wndDebugBar.SetBarStyle(m_wndDebugBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
			m_wndEditBar.SetBarStyle(m_wndEditBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
			m_wndBrowseBar.SetBarStyle(m_wndBrowseBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
			m_wndPaletteBar.SetBarStyle(m_wndPaletteBar.GetBarStyle() | CBRS_TOOLTIPS | CBRS_FLYBY);
		}
		else
		{
			m_wndMainBar.SetBarStyle(m_wndMainBar.GetBarStyle() & ~(CBRS_TOOLTIPS | CBRS_FLYBY));
			m_wndResourceBar.SetBarStyle(m_wndResourceBar.GetBarStyle() & ~( CBRS_TOOLTIPS | CBRS_FLYBY));
			m_wndDebugBar.SetBarStyle(m_wndDebugBar.GetBarStyle() & ~( CBRS_TOOLTIPS | CBRS_FLYBY));
			m_wndEditBar.SetBarStyle(m_wndEditBar.GetBarStyle() & ~( CBRS_TOOLTIPS | CBRS_FLYBY));
			m_wndBrowseBar.SetBarStyle(m_wndBrowseBar.GetBarStyle() & ~( CBRS_TOOLTIPS | CBRS_FLYBY));
			m_wndPaletteBar.SetBarStyle(m_wndPaletteBar.GetBarStyle() & ~( CBRS_TOOLTIPS | CBRS_FLYBY));
		}
		nColumns = (ToolDlg.m_nColumns < 3) ? ToolDlg.m_nColumns + 2 : 6;
		m_wndPaletteBar.SetColumns(nColumns);

		m_bColor = (ToolDlg.m_nColor==0);

		if (m_bColor)
		{
			m_wndMainBar.LoadBitmap(IDR_COLOR_MAINBAR);
			m_wndResourceBar.LoadBitmap(IDR_COLOR_RESOURCEBAR);
			m_wndDebugBar.LoadBitmap(IDR_COLOR_DEBUGBAR);
			m_wndBrowseBar.LoadBitmap(IDR_COLOR_BROWSEBAR);
			m_wndPaletteBar.LoadBitmap(IDR_COLOR_PALETTEBAR);
		}
		else
		{
			m_wndMainBar.LoadBitmap(IDR_MONO_MAINBAR);
			m_wndResourceBar.LoadBitmap(IDR_MONO_RESOURCEBAR);
			m_wndDebugBar.LoadBitmap(IDR_MONO_DEBUGBAR);
			m_wndBrowseBar.LoadBitmap(IDR_MONO_BROWSEBAR);
			m_wndPaletteBar.LoadBitmap(IDR_MONO_PALETTEBAR);
		}
		m_wndEditBar.SetColor(m_bColor);

		m_wndMainBar.Invalidate();
		m_wndResourceBar.Invalidate();
		m_wndDebugBar.Invalidate();
		m_wndBrowseBar.Invalidate();
		m_wndPaletteBar.Invalidate();
		m_wndEditBar.Invalidate();
	}
}

void CMainFrame::OnMenuSelection()
{
	// This sample doesn't do anything with button presses but a command handler
	// needs to be present for MFC to enable the buttons
}

void CMainFrame::OnClose()
{
	// SaveBarState saves everything but the number of Columns in the Palette
	// we need to do that ourseleves.
	SaveBarState(_T("General"));
	AfxGetApp()->WriteProfileInt(
		_T("General"),_T("Columns"),m_wndPaletteBar.GetColumns());
	AfxGetApp()->WriteProfileInt(
		_T("General"),_T("Color"),(m_bColor!=0));
	AfxGetApp()->WriteProfileInt(
		_T("General"),_T("ToolTips"),(m_bToolTips!=0));

	WINDOWPLACEMENT wp;
	wp.length = sizeof wp;
	if (GetWindowPlacement(&wp))
	{
		wp.flags = 0;
		if (IsZoomed())
			wp.flags |= WPF_RESTORETOMAXIMIZED;
		// and write it to the .INI file
		WriteWindowPlacement(&wp);
	}
	CFrameWnd::OnClose();
}

BOOL CMainFrame::PreTranslateMessage(MSG* pMsg)
{
	if (pMsg->message == WM_RBUTTONDOWN)
	{
		CWnd* pWnd = CWnd::FromHandlePermanent(pMsg->hwnd);
		CControlBar* pBar = DYNAMIC_DOWNCAST(CControlBar, pWnd);

		if (pBar != NULL)
		 {
			CMenu Menu;
			CPoint pt;

			pt.x = LOWORD(pMsg->lParam);
			pt.y = HIWORD(pMsg->lParam);
			pBar->ClientToScreen(&pt);

			if (Menu.LoadMenu(IDR_TOOLBAR))
			{
				CMenu* pSubMenu = Menu.GetSubMenu(0);

				if (pSubMenu!=NULL)
				{
					pSubMenu->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON,pt.x,pt.y,this);
				}
			}
		}
	}
	return CFrameWnd::PreTranslateMessage(pMsg);
}
