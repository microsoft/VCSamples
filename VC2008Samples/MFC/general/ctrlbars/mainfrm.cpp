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
#include "ctrlbars.h"

#include "mainfrm.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_VIEW_DLGBARTOP, OnViewDlgbarTop)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DLGBARTOP, OnUpdateViewDlgbartop)
	ON_COMMAND(ID_VIEW_SHORT, OnViewShort)
	ON_COMMAND(ID_VIEW_LONG, OnViewLong)
	ON_COMMAND(ID_TOGGLE_INSERT, OnToggleInsert)
	ON_UPDATE_COMMAND_UI(ID_INDICATOR_OVR, OnUpdateInsert)
	ON_COMMAND_EX(IDW_STYLES, OnViewBar)
	ON_UPDATE_COMMAND_UI(IDW_STYLES, OnUpdateBarMenu)
	ON_COMMAND(IDM_VIEWPALETTE, OnViewPalette)
	ON_UPDATE_COMMAND_UI(IDM_VIEWPALETTE, OnUpdatePaletteMenu)
	ON_COMMAND(IDM_PALETTE_2COLUMN, OnPalette2column)
	ON_COMMAND(IDM_PALETTE_3COLUMN, OnPalette3column)
	ON_UPDATE_COMMAND_UI(IDM_PALETTE_3COLUMN, OnUpdatePalette3column)
	ON_UPDATE_COMMAND_UI(IDM_PALETTE_2COLUMN, OnUpdatePalette2column)
	ON_CBN_SELCHANGE(IDC_PALETTE, OnSelChangePalette)
	//}}AFX_MSG_MAP
	ON_COMMAND_RANGE(ID_STYLE_LEFT, ID_STYLE_JUSTIFIED, OnChangeStyle)
	ON_UPDATE_COMMAND_UI_RANGE(ID_STYLE_LEFT, ID_STYLE_JUSTIFIED, OnUpdateStyle)
	ON_COMMAND_RANGE(ID_PALETTEERASE, ID_PALETTEOVAL, OnPalette)
	ON_UPDATE_COMMAND_UI_RANGE(ID_PALETTEERASE, ID_PALETTEOVAL, OnUpdatePalette)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// arrays of IDs used to initialize control bars

static UINT BASED_CODE styles[] =
{
	// same order as in the bitmap 'styles.bmp'
	ID_SEPARATOR,           // for combo box (placeholder)
	ID_SEPARATOR,
	ID_STYLE_LEFT,
	ID_STYLE_CENTERED,
	ID_STYLE_RIGHT,
	ID_STYLE_JUSTIFIED,
};

static UINT BASED_CODE palette[] =
{
	// same order as in the bitmap 'palette.bmp'
	ID_PALETTEERASE,
	ID_PALETTEPEN,
	ID_PALETTESELECT,
	ID_PALETTEBRUSH,
	ID_PALETTESPRAY,
	ID_PALETTEPAINT,
	ID_PALETTELINE,
	ID_PALETTEEYEDROP,
	ID_PALETTEMAG,
	ID_PALETTERECT,
	ID_PALETTEROUND,
	ID_PALETTEOVAL
};

static UINT BASED_CODE indicators[] =
{
	ID_SEPARATOR,           // status line indicator
	ID_INDICATOR_OVR,
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_bInsert = FALSE;      // default to over-strke mode
	m_bDialogTop = FALSE;
	m_nPaletteCol = 3;
}

CMainFrame::~CMainFrame()
{
}

// We override PreCreateWindow to specify a different window class (WNDCLASS),
//   one with a different background and without the CS_VREDRAW/CS_HREDRAW
//   style so all the frame window's control bars will not be repainted
//   when the window is resized.
BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = AfxRegisterWndClass(CS_DBLCLKS,
		AfxGetApp()->LoadStandardCursor(IDC_ARROW), (HBRUSH)(COLOR_WINDOW+1),
		AfxGetApp()->LoadIcon(IDR_MAINFRAME));

	return TRUE;
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	EnableDocking(CBRS_ALIGN_ANY);

	if (!CreateToolBar())
		return -1;
	if (!CreateStyleBar())
		return -1;
	if (!CreatePaletteBar())
		return -1;
	if (!CreateStatusBar())
		return -1;

	if (!m_wndDlgBar.Create(this, IDD_VIEWSELECT,
		CBRS_LEFT|CBRS_TOOLTIPS|CBRS_FLYBY, IDD_VIEWSELECT))
	{
		TRACE0("Failed to create DlgBar\n");
		return -1;      // fail to create
	}

	return 0;
}

BOOL CMainFrame::CreateToolBar()
{
	if (!m_wndToolBar.Create(this,
			CBRS_TOP|CBRS_TOOLTIPS|CBRS_FLYBY|WS_VISIBLE) ||
		!m_wndToolBar.LoadBitmap(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;       // fail to create
	}

	OnViewShort();
	return TRUE;
}

BOOL CMainFrame::CreatePaletteBar()
{
	if (!m_wndPaletteBar.Create(this, WS_CHILD | WS_VISIBLE | CBRS_SIZE_FIXED |
		CBRS_TOP | CBRS_TOOLTIPS, ID_PALETTEBAR) ||
		!m_wndPaletteBar.LoadBitmap(IDB_PALETTE) ||
		!m_wndPaletteBar.SetButtons(palette,
		  sizeof(palette)/sizeof(UINT)))
	{
		TRACE0("Failed to create toolbar\n");
		return FALSE;       // fail to create
	}

	m_wndPaletteBar.SetWindowText(_T("Palette"));
	m_wndPaletteBar.EnableDocking(0);

	// Create the Palette.  We are using hardcoded numbers for ease here
	// normally the location would be read in from an ini file.
	CPoint pt(GetSystemMetrics(SM_CXSCREEN) - 100,
		GetSystemMetrics(SM_CYSCREEN) / 3);

	m_wndPaletteBar.SetColumns(3);
	FloatControlBar(&m_wndPaletteBar, pt);

	return TRUE;
}

BOOL CMainFrame::CreateStyleBar()
{
	const int nDropHeight = 100;

	if (!m_wndStyleBar.Create(this, WS_CHILD|WS_VISIBLE|CBRS_TOP|
			CBRS_TOOLTIPS|CBRS_FLYBY, IDW_STYLES) ||
		!m_wndStyleBar.LoadBitmap(IDB_STYLES) ||
		!m_wndStyleBar.SetButtons(styles, sizeof(styles)/sizeof(UINT)))
	{
		TRACE0("Failed to create stylebar\n");
		return FALSE;       // fail to create
	}

	// Create the combo box
	m_wndStyleBar.SetButtonInfo(0, IDW_COMBO, TBBS_SEPARATOR, 100);

	// Design guide advises 12 pixel gap between combos and buttons
	m_wndStyleBar.SetButtonInfo(1, ID_SEPARATOR, TBBS_SEPARATOR, 12);
	CRect rect;
	m_wndStyleBar.GetItemRect(0, &rect);
	rect.top = 3;
	rect.bottom = rect.top + nDropHeight;
	if (!m_wndStyleBar.m_comboBox.Create(
			CBS_DROPDOWNLIST|WS_VISIBLE|WS_TABSTOP,
			rect, &m_wndStyleBar, IDW_COMBO))
	{
		TRACE0("Failed to create combo-box\n");
		return FALSE;
	}

	//  Fill the combo box
	CString szStyle;
	if (szStyle.LoadString(IDS_LEFT))
		m_wndStyleBar.m_comboBox.AddString((LPCTSTR)szStyle);
	if (szStyle.LoadString(IDS_CENTERED))
		m_wndStyleBar.m_comboBox.AddString((LPCTSTR)szStyle);
	if (szStyle.LoadString(IDS_RIGHT))
		m_wndStyleBar.m_comboBox.AddString((LPCTSTR)szStyle);
	if (szStyle.LoadString(IDS_JUSTIFIED))
		m_wndStyleBar.m_comboBox.AddString((LPCTSTR)szStyle);

	//  Create a font for the combobox
	LOGFONT logFont;
	memset(&logFont, 0, sizeof(logFont));

	if (!::GetSystemMetrics(SM_DBCSENABLED))
	{
		// Since design guide says toolbars are fixed height so is the font.
		logFont.lfHeight = -12;
		logFont.lfWeight = FW_BOLD;
		logFont.lfPitchAndFamily = VARIABLE_PITCH | FF_SWISS;
		CString strDefaultFont;
		strDefaultFont.LoadString(IDS_DEFAULT_FONT);
		_tcscpy_s(logFont.lfFaceName, LF_FACESIZE, strDefaultFont);
		if (!m_wndStyleBar.m_font.CreateFontIndirect(&logFont))
			TRACE0("Could Not create font for combo\n");
		else
			m_wndStyleBar.m_comboBox.SetFont(&m_wndStyleBar.m_font);
	}
	else
	{
		m_wndStyleBar.m_font.Attach(::GetStockObject(SYSTEM_FONT));
		m_wndStyleBar.m_comboBox.SetFont(&m_wndStyleBar.m_font);
	}

	return TRUE;
}

BOOL CMainFrame::CreateStatusBar()
{
	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return FALSE;       // fail to create
	}

	UINT nID, nStyle;
	int cxWidth;

	m_wndStatusBar.GetPaneInfo( 0, nID, nStyle, cxWidth);
	m_wndStatusBar.SetPaneInfo( 0, nID, SBPS_STRETCH|SBPS_NORMAL, cxWidth);
	return TRUE;
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

void CMainFrame::OnViewShort()
{
	// Set the toolbar to show only partial commmand list
	m_wndToolBar.SetButtons(NULL, 7);
	m_wndToolBar.SetButtonInfo(0, ID_VIEW_LONG,TBBS_BUTTON, 10);
	m_wndToolBar.SetButtonInfo(1, ID_SEPARATOR,TBBS_SEPARATOR, 6);
	m_wndToolBar.SetButtonInfo(2, ID_FILE_OPEN,TBBS_BUTTON, 1);
	m_wndToolBar.SetButtonInfo(3, ID_FILE_NEW,TBBS_BUTTON, 0);
	m_wndToolBar.SetButtonInfo(4, ID_FILE_SAVE,TBBS_BUTTON, 2);
	m_wndToolBar.SetButtonInfo(5, ID_SEPARATOR,TBBS_SEPARATOR, 6);
	m_wndToolBar.SetButtonInfo(6, ID_APP_ABOUT,TBBS_BUTTON, 7);

	// invalidate the call update handlers before painting
	m_wndToolBar.Invalidate();
	AfxGetApp()->OnIdle(-1);
}

void CMainFrame::OnViewLong()
{
	// Set the toolbar to show all commmands
	m_wndToolBar.SetButtons(NULL, 13);
	m_wndToolBar.SetButtonInfo(0, ID_VIEW_SHORT,TBBS_BUTTON, 9);
	m_wndToolBar.SetButtonInfo(1, ID_SEPARATOR,TBBS_SEPARATOR, 6);
	m_wndToolBar.SetButtonInfo(2, ID_FILE_OPEN,TBBS_BUTTON, 1);
	m_wndToolBar.SetButtonInfo(3, ID_FILE_NEW,TBBS_BUTTON, 0);
	m_wndToolBar.SetButtonInfo(4, ID_FILE_SAVE,TBBS_BUTTON, 2);
	m_wndToolBar.SetButtonInfo(5, ID_SEPARATOR,TBBS_SEPARATOR, 6);
	m_wndToolBar.SetButtonInfo(6, ID_APP_ABOUT,TBBS_BUTTON, 7);
	m_wndToolBar.SetButtonInfo(7, ID_SEPARATOR,TBBS_SEPARATOR, 6);
	m_wndToolBar.SetButtonInfo(8, ID_EDIT_CUT,TBBS_BUTTON, 3);
	m_wndToolBar.SetButtonInfo(9, ID_EDIT_COPY,TBBS_BUTTON, 4);
	m_wndToolBar.SetButtonInfo(10, ID_EDIT_PASTE,TBBS_BUTTON, 5);
	m_wndToolBar.SetButtonInfo(11, ID_FILE_PRINT,TBBS_BUTTON, 6);
	m_wndToolBar.SetButtonInfo(12, ID_CONTEXT_HELP,TBBS_BUTTON, 8);

	// invalidate then call update handlers before painting
	m_wndToolBar.Invalidate();
	AfxGetApp()->OnIdle(-1);
}

void CMainFrame::OnViewDlgbarTop()
{
	if (m_bDialogTop)
		m_wndDlgBar.SetWindowPos(&m_wndStatusBar, 0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);
	else
		m_wndDlgBar.SetWindowPos(&wndTop, 0,0,0,0,SWP_NOSIZE|SWP_NOMOVE);

	RecalcLayout();
	m_bDialogTop = !m_bDialogTop;
}

void CMainFrame::OnUpdateViewDlgbartop(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_bDialogTop);
}

BOOL CMainFrame::OnViewBar(UINT nID)
{
	CWnd* pBar;
	if ((pBar = GetDlgItem(nID)) == NULL)
		return FALSE;   // not for us
	// toggle visible state
	pBar->ShowWindow((pBar->IsWindowVisible()) == 0);
	RecalcLayout();
	return TRUE;
}

void CMainFrame::OnUpdateBarMenu(CCmdUI* pCmdUI)
{
	CWnd* pBar;
	if ((pBar = GetDlgItem(pCmdUI->m_nID)) == NULL)
	{
		pCmdUI->ContinueRouting();
		return; // not for us
	}
	pCmdUI->SetCheck((pBar->IsWindowVisible()) != 0);
}

void CMainFrame::OnViewPalette()
{
	BOOL bVisible = ((m_wndPaletteBar.IsWindowVisible()) != 0);

	ShowControlBar(&m_wndPaletteBar, !bVisible, FALSE);
	RecalcLayout();
}

void CMainFrame::OnUpdatePaletteMenu(CCmdUI* pCmdUI)
{
	BOOL bVisible = ((m_wndPaletteBar.IsWindowVisible()) != 0);
	pCmdUI->SetCheck(bVisible);
}

void CMainFrame::OnChangeStyle(UINT nID)
{
	m_wndStyleBar.m_comboBox.SetCurSel((int)(nID-ID_STYLE_BASE));
}

void CMainFrame::OnUpdateStyle(CCmdUI* pCmdUI)
{
	UINT nIndex = m_wndStyleBar.m_comboBox.GetCurSel();
	pCmdUI->SetCheck((UINT)(ID_STYLE_BASE+nIndex) == pCmdUI->m_nID);
}

void CMainFrame::OnUpdateInsert(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(!m_bInsert);
}

void CMainFrame::OnToggleInsert()
{
	m_bInsert = !m_bInsert;
}

void CMainFrame::OnUpdatePalette(CCmdUI* pCmdUI)
{
	CComboBox* pCBox = (CComboBox*)m_wndDlgBar.GetDlgItem(IDC_PALETTE);
	UINT nIndex = pCBox->GetCurSel();
	pCmdUI->SetCheck((UINT)(ID_PALETTE_BASE + nIndex) == pCmdUI->m_nID);
}

void CMainFrame::OnPalette(UINT nID)
{
	CComboBox* pCBox = (CComboBox*)m_wndDlgBar.GetDlgItem(IDC_PALETTE);
	pCBox->SetCurSel((int)(nID - ID_PALETTE_BASE));
	OnSelChangePalette();
}

void CMainFrame::OnSelChangePalette()
{
	CString strText;
	CString strItem;
	CComboBox* pCBox = (CComboBox*)m_wndDlgBar.GetDlgItem(IDC_PALETTE);
	int nIndex = pCBox->GetCurSel();
	if (nIndex == CB_ERR)
		return;
	pCBox->GetLBText(nIndex, strItem);
	AfxFormatString1(strText, IDS_SELECTED_PROMPT, (LPCTSTR)strItem);
	SetMessageText(strText);
}

void CMainFrame::OnPalette2column()
{
	m_nPaletteCol = 2;
	m_wndPaletteBar.SetColumns(m_nPaletteCol);
}

void CMainFrame::OnPalette3column()
{
	m_nPaletteCol = 3;
	m_wndPaletteBar.SetColumns(m_nPaletteCol);
}

void CMainFrame::OnUpdatePalette2column(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nPaletteCol == 2);
}

void CMainFrame::OnUpdatePalette3column(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck(m_nPaletteCol == 3);
}
