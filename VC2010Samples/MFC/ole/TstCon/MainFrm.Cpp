// CMainFrame.cpp : implementation of the CMainFrame class
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "StdAfx.H"
#include "TestCon.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
   //{{AFX_MSG_MAP(CMainFrame)
   ON_WM_CREATE()
   ON_WM_DESTROY()
   ON_COMMAND(ID_VIEW_MACROBAR, OnViewMacroBar)
   ON_UPDATE_COMMAND_UI(ID_VIEW_MACROBAR, OnUpdateViewMacroBar)
	//}}AFX_MSG_MAP
   ON_COMMAND( ID_HELP_FINDER, CFrameWnd::OnHelpFinder )
   ON_COMMAND( ID_HELP, CFrameWnd::OnHelp )
   ON_COMMAND( ID_CONTEXT_HELP, CFrameWnd::OnContextHelp )
   ON_COMMAND( ID_DEFAULT_HELP, CFrameWnd::OnHelpFinder )
END_MESSAGE_MAP()

static UINT indicators[] =
{
   ID_SEPARATOR,  // Status line indicator
   ID_SEPARATOR,  // Activation state
   ID_SEPARATOR,  // Windowed/windowless state
   ID_INDICATOR_CAPS,
   ID_INDICATOR_NUM,
   ID_INDICATOR_SCRL,
};

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
   CString strOutputWindowTitle;
   UINT nID;
   UINT nStyle;
   int nWidth;

   if( CFrameWnd::OnCreate( lpCreateStruct ) == -1 )
   {
	  return( -1 );
   }

   if( !m_wndStatusBar.Create( this ) || !m_wndStatusBar.SetIndicators(
	  indicators, sizeof( indicators )/sizeof( UINT ) ) )
   {
	  TRACE( "Failed to create status bar\n" );
	  return( -1 );
   }

   // Shrink the windowed/windowless and activation state status bar panes to a
   // more reasonable size
   m_wndStatusBar.GetPaneInfo( 1, nID, nStyle, nWidth );
   m_wndStatusBar.SetPaneInfo( 1, nID, nStyle, nWidth/3 );

   m_wndStatusBar.GetPaneInfo( 2, nID, nStyle, nWidth );
   m_wndStatusBar.SetPaneInfo( 2, nID, nStyle, nWidth/3 );

   // Start out assuming that the latest comctl32.dll is installed
   BOOL bHaveIE40 = TRUE;

   // Create the rebar. If the creation goes through then
   // add an instance of a CReToolBar to the rebar
   if( !m_wndReBar.Create( this ) )
   {
	  TRACE( "Failed to create rebar\n" );
	  bHaveIE40 = FALSE;
   }

   // Create the toolbar
   if( !m_wndToolBar.CreateEx( this, TBSTYLE_FLAT, WS_CHILD|WS_VISIBLE|
	  CBRS_ALIGN_TOP|CBRS_TOOLTIPS|CBRS_FLYBY ) || !m_wndToolBar.LoadToolBar(
	  IDR_MAINFRAME ) )
   {
	  TRACE( "Failed to create toolbar\n" );
	  return( -1 );
   }

   if( !m_wndMacroBar.Create( this, CBRS_SIZE_FIXED|CBRS_ALIGN_TOP, IDC_MACROBAR ) )
   {
	  TRACE( "Failed to create macro bar\n" );
	  return( -1 );
   }

   if( bHaveIE40 ) // Do the rebar
   {
	  if( !m_wndReBar.AddBar( &m_wndToolBar ) )
	  {
		 TRACE( "Failed to add toolbar to rebar\n" );
		 return( -1 );
	  }
	  if( !m_wndReBar.AddBar( &m_wndMacroBar ) )
	  {
		 TRACE( "Failed to add macro bar to rebar\n" );
		 return( -1 );
	  }

	  EnableDocking( CBRS_ALIGN_ANY );
   }
   else  // Do a regular toolbar
   {
	  m_wndToolBar.EnableDocking( CBRS_ORIENT_VERT|CBRS_ALIGN_TOP );
	  m_wndMacroBar.EnableDocking( CBRS_ORIENT_VERT|CBRS_ALIGN_TOP );

	  EnableDocking( CBRS_ALIGN_ANY );
	  DockControlBar( &m_wndToolBar );
	  DockControlBar( &m_wndMacroBar );
   }

   return( 0 );
}

BOOL CMainFrame::PreCreateWindow( CREATESTRUCT& cs )
{
	WNDCLASS wc;

	if( !CFrameWnd::PreCreateWindow( cs ) )
	{
		return( FALSE );
	}

	GetClassInfo( AfxGetInstanceHandle(), cs.lpszClass, &wc );
	cs.lpszClass = AfxRegisterWndClass( 0, wc.hCursor, wc.hbrBackground, 
		wc.hIcon );

	cs.style |= WS_CLIPCHILDREN;

	return( TRUE );
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

void CMainFrame::OnDestroy()
{
   CFrameWnd::OnDestroy();
}

void CMainFrame::OnViewMacroBar()
{
   CControlBar* pControlBar;

   pControlBar = GetControlBar( IDC_MACROBAR );
   if( pControlBar != NULL )
   {
	  ShowControlBar( pControlBar, (pControlBar->GetStyle()&WS_VISIBLE) == 0,
		 FALSE );
   }
}

void CMainFrame::OnUpdateViewMacroBar( CCmdUI* pCmdUI )
{
   CControlBar* pControlBar;

   pControlBar = GetControlBar( IDC_MACROBAR );
   if( pControlBar != NULL )
   {
	  pCmdUI->SetCheck( (pControlBar->GetStyle()&WS_VISIBLE) != 0 );
   }
}

BOOL CMainFrame::OnCreateClient( LPCREATESTRUCT /* pcs */,
   CCreateContext* pContext )
{
   CSize size;
   CRect rect;

   GetClientRect( &rect );
   size = rect.Size();

   // Create a static splitter with two panes.  The top pane is the actual
   // CTestContainer98View, and the bottom pane is the output window.
   m_wndSplitter.CreateStatic( this, 2, 1 );
   m_wndSplitter.CreateView( 0, 0, RUNTIME_CLASS( CTestContainer98View ),
	  CSize( size.cx, 2*size.cy/3 ), pContext );
   m_wndSplitter.CreateView( 1, 0, RUNTIME_CLASS( COutputWindowView ), CSize(
	  size.cx, size.cy-(2*size.cy/3) ), pContext );

   return( TRUE );
}

BOOL CMainFrame::OnCmdMsg( UINT nID, int nCode, void* pExtra,
   AFX_CMDHANDLERINFO* pHandlerInfo )
{
   BOOL tHandled;
   CWnd* pView;

   // First, try the default routing scheme.
   tHandled = CFrameWnd::OnCmdMsg( nID, nCode, pExtra, pHandlerInfo );
   if( tHandled )
   {
	  return( TRUE );
   }

   // If nobody handled it, and the main view isn't active, try the main view.
   pView = m_wndSplitter.GetPane( 0, 0 );
   if( pView != GetActiveView() )
   {
	  tHandled = pView->OnCmdMsg( nID, nCode, pExtra, pHandlerInfo );
	  if( tHandled )
	  {
		 return( TRUE );
	  }
   }

   return( FALSE );
}
