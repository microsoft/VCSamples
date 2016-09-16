// typelib.cpp : implementation file
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
#include "iviewers.h"
#include "typelib.h"
#include "iview.h"
#include "iviewer.h"
#include "util.h"
#include "tlbtree.h"
#include "tlblist.h"
#include "tlbodl.h"
#include "util.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#define LOAD_STRING_FROM_RESOURCE(s, r) \
if(s.LoadString(r) == FALSE) { AfxThrowResourceException(); }



/////////////////////////////////////////////////////////////////////////////
// CTypeLibViewer

IMPLEMENT_DYNCREATE(CTypeLibViewer, CInterfaceViewer)

CTypeLibViewer::CTypeLibViewer()
{
}

CTypeLibViewer::~CTypeLibViewer()
{
}

BEGIN_MESSAGE_MAP(CTypeLibViewer, CInterfaceViewer)
	//{{AFX_MSG_MAP(CTypeLibViewer)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

IMPLEMENT_OLECREATE(CTypeLibViewer, "Ole2View.ITypeLib.1", 0x57efbf49, 0x4a8b, 0x11ce, 0x87, 0xb, 0x8, 0x0, 0x36, 0x8d, 0x23, 0x2)

/////////////////////////////////////////////////////////////////////////////
// CTypeLibViewer View imp.
HRESULT CTypeLibViewer::OnView(HWND hwndParent, REFIID riid, LPUNKNOWN punk)
{
	SCODE sc = NOERROR ;

	ASSERT(punk);

	if (riid != IID_ITypeLib)
	{
		AfxMessageBox( _T("ITypeLib interface viewer only supports IID_ITypeLib") ) ;
		return E_INVALIDARG ;
	}

	CTypeLibWnd wnd(CWnd::FromHandle(hwndParent)) ;
	if (punk)
	{
		sc = punk->QueryInterface( riid, (void**)&wnd.m_ptlb ) ;
		if (FAILED(sc))
		{
			AfxMessageBox( _T("Object does not support ITypeLib") ) ;
			return E_UNEXPECTED ;
		}
	}

	if (wnd.LoadFrame(IDR_TYPELIBWND, WS_OVERLAPPEDWINDOW, CWnd::FromHandle(hwndParent), NULL ) == FALSE)
	{
		TRACE(_T("LoadFrame failed\n") );
		return E_UNEXPECTED ;
	}
	ASSERT(wnd.m_hWnd);
	if (hwndParent)
		::EnableWindow( hwndParent, FALSE ) ;

	wnd.InitialUpdateFrame( NULL, FALSE ) ;
	wnd.RestorePosition() ;
	wnd.UpdateWindow() ;

	// Go into a wait/peekmessage loop
	MSG msg ;
	for (;;)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// We post a WM_CLOSE to force us out of the loop
			if (msg.hwnd == wnd.m_hWnd && msg.message == WM_CLOSE)
				goto done ;
			TranslateMessage(&msg) ;
			DispatchMessage(&msg) ;
		}
		WaitMessage() ;
	}
done:
	TRACE(_T("Exit from waitmessage loop\n") ) ;

	if (hwndParent)
		::EnableWindow( hwndParent, TRUE ) ;
	wnd.DestroyWindow() ;

	return sc ;
}

/////////////////////////////////////////////////////////////////////////////
// CTypeLibWnd dialog

IMPLEMENT_DYNCREATE(CTypeLibWnd, CFrameWnd)
BEGIN_MESSAGE_MAP(CTypeLibWnd, CFrameWnd)
	//{{AFX_MSG_MAP(CTypeLibWnd)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_FILE_CLOSE, OnFileClose)
	ON_COMMAND(ID_VIEW_GROUPBYTYPEKIND, OnViewGroupKind)
	ON_UPDATE_COMMAND_UI(ID_VIEW_GROUPBYTYPEKIND, OnUpdateViewGroupByKind)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

CTypeLibWnd::CTypeLibWnd(CWnd* /*pParent =NULL*/)
{
	m_pSelectedItem = NULL ;
	m_ptlb = NULL ;

	CString szSection ;
	CString szKey ;

	LOAD_STRING_FROM_RESOURCE( szSection, IDS_REG_TYPELIB ) ;
	LOAD_STRING_FROM_RESOURCE( szKey, IDS_REG_GROUPBYKIND ) ;
	m_fGroupByKind = AfxGetApp()->GetProfileInt(szSection, szKey, FALSE ) ;

}

CTypeLibWnd::~CTypeLibWnd()
{
	if (m_ptlb)
		m_ptlb->Release() ;
	m_ptlb = NULL ;

	CString szSection ;
	CString szKey ;
	LOAD_STRING_FROM_RESOURCE( szSection, IDS_REG_TYPELIB ) ;
	LOAD_STRING_FROM_RESOURCE( szKey, IDS_REG_GROUPBYKIND ) ;
	AfxGetApp()->WriteProfileInt(szSection, szKey, m_fGroupByKind ) ;

}

void CTypeLibViewer::OnFinalRelease()
{


	CInterfaceViewer::OnFinalRelease();
}

/////////////////////////////////////////////////////////////////////////////
// CTypeLibWnd message handlers

// toolbar buttons - IDs are command buttons
static UINT BASED_CODE buttons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_VIEW_GROUPBYTYPEKIND,
	ID_SEPARATOR,
	ID_APP_ABOUT
};

static UINT BASED_CODE indicators[] =
{
	  ID_SEPARATOR,             // status line indicator
};

int CTypeLibWnd::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadBitmap(IDR_MAINFRAME) ||
		!m_wndToolBar.SetButtons(buttons, sizeof(buttons)/sizeof(UINT)))
	{
		TRACE(_T("Failed to create toolbar\n"));
		return -1;      // fail to create
	}

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT)) )
	{
		TRACE(_T("Failed to create status bar\n"));
		return -1;      // fail to create
	}

	m_wndStatusBar.ShowWindow(SW_SHOWNORMAL) ;
	m_wndToolBar.ShowWindow(SW_SHOWNORMAL) ;

	return 0;
}

BOOL CTypeLibWnd::OnCreateClient( LPCREATESTRUCT /*lpcs*/, CCreateContext* pcc )
{

	CCreateContext context ;
	context.m_pNewViewClass = NULL ;
	context.m_pCurrentDoc = NULL ;
	context.m_pNewDocTemplate = NULL ;
	context.m_pLastView = NULL ;
	context.m_pCurrentFrame = NULL ;

	// create a splitter with 1 row, 2 columns
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE(_T("Failed to CreateStaticSplitter\n"));
		return FALSE;
	}

	// add the first splitter pane - the default view in column 0
	if (!m_wndSplitter.CreateView(0, 0,
		RUNTIME_CLASS(CTypeLibTreeView), CSize(240, 0), &context))
	{
		TRACE(_T("Failed to create first pane\n"));
		return FALSE;
	}
#ifdef _LIST_VIEW
	if (!m_wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CTypeLibListView), CSize(0, 0), &context))
	{
		TRACE(_T("Failed to create second pane\n"));
		return FALSE;
	}
#else
	if (!m_wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CTypeLibODLView), CSize(0, 0), &context))
	{
		TRACE(_T("Failed to create second pane\n"));
		return FALSE;
	}
#endif

	m_pTreeView = (CTypeLibTreeView*)m_wndSplitter.GetPane(0, 0) ;
#ifdef _LIST_VIEW
	m_pListView = (CTypeLibListView*)m_wndSplitter.GetPane(0,1) ;
#else
	m_pODLView = (CTypeLibODLView*)m_wndSplitter.GetPane(0,1) ;
#endif

	SetActiveView(m_pTreeView);
	m_wndSplitter.SetColumnInfo( 0, 240, 0 ) ;

	CRect rc ;
	GetWindowRect( &rc) ;
	SetWindowPos( NULL, 0, 0, rc.Width()+1, rc.Height()+1, SWP_NOZORDER |
					SWP_NOMOVE | SWP_NOACTIVATE | SWP_NOREDRAW) ;

	return TRUE ;
}

void CTypeLibWnd::OnDestroy()
{
	CString szSection ;
	CString szKey ;

	LOAD_STRING_FROM_RESOURCE( szSection, IDS_REG_TYPELIB ) ;
	LOAD_STRING_FROM_RESOURCE( szKey, IDS_REG_WNDPOS ) ;

	WINDOWPLACEMENT wp;
	CString szValue ;
	wp.length = sizeof( WINDOWPLACEMENT );
	GetWindowPlacement( &wp );
	int nWidth, n ;
	m_wndSplitter.GetColumnInfo( 0, nWidth, n ) ;
	szValue.Format( _T("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d"),
		wp.showCmd, wp.ptMinPosition.x, wp.ptMinPosition.y,
		wp.ptMaxPosition.x, wp.ptMaxPosition.y,
		wp.rcNormalPosition.left, wp.rcNormalPosition.top,
		wp.rcNormalPosition.right, wp.rcNormalPosition.bottom,
		nWidth,
		(m_wndToolBar.GetStyle() & WS_VISIBLE) ? TRUE : FALSE,
		(m_wndStatusBar.GetStyle() & WS_VISIBLE) ? TRUE : FALSE ) ;
	AfxGetApp()->WriteProfileString( szSection, szKey, szValue );

	CFrameWnd::OnDestroy();
}

void CTypeLibWnd::RestorePosition()
{
	CString sz ;
	CString szSection ;
	CString szKey ;
	BOOL fToolBar = TRUE ;
	BOOL fStatusBar = TRUE ;

	LOAD_STRING_FROM_RESOURCE( szSection, IDS_REG_TYPELIB ) ;
	LOAD_STRING_FROM_RESOURCE( szKey, IDS_REG_WNDPOS ) ;

	WINDOWPLACEMENT wp;
	memset(&wp, 0, sizeof(wp) ) ;
	int     nConv;
	wp.length = sizeof( WINDOWPLACEMENT );
	wp.flags = 0 ;

	TRY
	{
		sz = AfxGetApp()->GetProfileString(szSection, szKey, _T("") ) ;
		if (sz.IsEmpty())
			AfxThrowMemoryException();

		LPTSTR   lp = (LPTSTR)sz.GetBuffer( 255 );
		wp.showCmd = (WORD)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		wp.ptMinPosition.x = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		wp.ptMinPosition.y = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		wp.ptMaxPosition.x = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		wp.ptMaxPosition.y = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		wp.rcNormalPosition.left = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		wp.rcNormalPosition.top = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		wp.rcNormalPosition.right = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		wp.rcNormalPosition.bottom = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		int nWidth = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		m_wndSplitter.SetColumnInfo( 0, nWidth, 0 ) ;

		fToolBar = (BOOL)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		fStatusBar = (BOOL)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		if (!nConv)
			AfxThrowMemoryException();
		// Always strip off minimize.
		//
		if (wp.showCmd == SW_SHOWMINIMIZED)
			wp.showCmd = SW_SHOWNORMAL ;
	}
	CATCH(CException, pException)
	{
		fToolBar = TRUE ;
		fStatusBar = TRUE ;
		ShowControlBar( &m_wndToolBar, fToolBar, TRUE ) ;
		ShowControlBar( &m_wndStatusBar, fStatusBar, TRUE ) ;
		ShowWindow( SW_SHOWNORMAL );
		m_pTreeView->SetFocus() ;
		return ;
	}
	END_CATCH
	ShowControlBar( &m_wndToolBar, fToolBar, TRUE ) ;
	ShowControlBar( &m_wndStatusBar, fStatusBar, TRUE ) ;
	SetWindowPlacement( &wp ) ;
	m_pTreeView->SetFocus() ;
}


void CTypeLibWnd::PostNcDestroy()
{
	#if (defined(_USRDLL) || defined(_AFXDLL))
	// do nothing
	#else
	delete this ;
	#endif
}

void CTypeLibWnd::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

//    if (m_wndSplitter.GetSafeHwnd())
//        m_wndSplitter.SetWindowPos( NULL, 0, 0, cx, cy, SWP_NOZORDER ) ;
}


void CTypeLibWnd::OnClose()
{
	#if (defined(_USRDLL) || defined(_AFXDLL))
	// Post WM_CLOSE which will drop us out of our modal loop
	//
	PostMessage( WM_CLOSE ) ;
	#else
	PostQuitMessage(0) ;
	DestroyWindow() ;
	#endif
}

BOOL CTypeLibWnd::PreCreateWindow(CREATESTRUCT& cs)
{
	return CFrameWnd::PreCreateWindow(cs);
}


void CTypeLibWnd::OnAppAbout()
{
	AfxMessageBox(_T("TypeLib viewer by Charlie Kindel") ) ;

}

void CTypeLibWnd::OnFileClose()
{
	SendMessage( WM_CLOSE ) ;
}

void CTypeLibWnd::OnViewGroupKind()
{
	m_fGroupByKind = !m_fGroupByKind ;
	UpdateAllViews( NULL ) ;
}

void CTypeLibWnd::OnUpdateViewGroupByKind(CCmdUI* pCmdUI)
{
	pCmdUI->SetCheck( m_fGroupByKind ) ;
}


void CTypeLibWnd::UpdateAllViews( CView* pSender, LPARAM lHint, CObject* pHint )
{
	if (m_pTreeView)
		m_pTreeView->OnUpdate( pSender, lHint, pHint ) ;
#ifdef _LIST_VIEW
	if (m_pListView)
		m_pListView->OnUpdate( pSender, lHint, pHint  ) ;
#else
	if (m_pODLView)
		m_pODLView->OnUpdate( pSender, lHint, pHint  ) ;
#endif
}
