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
#include "OleView.h"
#include "mainfrm.h"
#include "shadow.h"
#include "obj_vw.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CMainFrame
// Create a splitter window which splits an output text view and an input view
//                               |
//    OBJECT VIEW (CObjTreeView)  | INTERFACE VIEW (CRegistryView)
//                               |

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_COMMAND(ID_FILE_RUNREGEDIT, OnFileRunREGEDIT)
	ON_COMMAND(ID_VIEW_REFRESH, OnViewRefresh)
	ON_UPDATE_COMMAND_UI(ID_VIEW_REFRESH, OnUpdateViewRefresh)
	ON_WM_SYSCOLORCHANGE()
	ON_COMMAND(ID_OBJECT_DELETE, OnObjectDelete)
	ON_UPDATE_COMMAND_UI(ID_OBJECT_DELETE, OnUpdateObjectDelete)
	ON_COMMAND(ID_OBJECT_VERIFY, OnObjectVerify)
	ON_UPDATE_COMMAND_UI(ID_OBJECT_VERIFY, OnUpdateObjectVerify)
	ON_COMMAND(ID_FILE_VIEWTYPELIB, OnFileViewTypeLib)
	ON_COMMAND(ID_IFACES_USEINPROCSERVER, OnUseInProcServer)
	ON_UPDATE_COMMAND_UI(ID_IFACES_USEINPROCSERVER, OnUpdateUseInProcServer)
	ON_COMMAND(ID_IFACES_USEINPROCHANDLER, OnUseInProcHandler)
	ON_UPDATE_COMMAND_UI(ID_IFACES_USEINPROCHANDLER, OnUpdateUseInProcHandler)
	ON_COMMAND(ID_IFACES_USELOCALSERVER, OnUseLocalServer)
	ON_UPDATE_COMMAND_UI(ID_IFACES_USELOCALSERVER, OnUpdateUseLocalServer)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// arrays of IDs used to initialize control bars

// toolbar buttons - IDs are command buttons
static UINT BASED_CODE buttons[] =
{
	// same order as in the bitmap 'toolbar.bmp'
	ID_FILE_BINDTOAFILE,
	ID_FILE_VIEWTYPELIB,
	ID_SEPARATOR,
	ID_FILE_RUNREGEDIT,
	ID_SEPARATOR,
	ID_OBJECT_DELETE,
	ID_OBJECT_VERIFY,
	ID_SEPARATOR,
	ID_IFACES_USEINPROCSERVER,
	ID_IFACES_USEINPROCHANDLER,
	ID_IFACES_USELOCALSERVER,
	ID_SEPARATOR,
	ID_APP_ABOUT
};

static UINT BASED_CODE indicators[] =
{
	  ID_SEPARATOR,             // status line indicator
//    ID_INDICATOR_CAPS,
//    ID_INDICATOR_NUM,
//    ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	m_pObjTreeView = NULL ;
	m_pObjectView = NULL ;
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle,
				CWnd* pParentWnd, CCreateContext* pContext)
{
	// Turn off auto update of title bar
	dwDefaultStyle &= ~((DWORD)FWS_ADDTOTITLE) ;
	BOOL f = CFrameWnd::LoadFrame(nIDResource, dwDefaultStyle,
				pParentWnd, pContext);

	return f ;
}
/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
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

//    m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
//    EnableDocking(CBRS_ALIGN_ANY);
//    DockControlBar(&m_wndToolBar);

	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle() |
		CBRS_TOOLTIPS | CBRS_FLYBY);

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT)) )
	{
		TRACE(_T("Failed to create status bar\n"));
		return -1;      // fail to create
	}

	UINT nID, nStyle ;
	int cxWidth ;
	m_wndStatusBar.GetPaneInfo( 0, nID, nStyle, cxWidth ) ;
	m_wndStatusBar.SetPaneInfo( 0, ID_SEPARATOR, nStyle | SBPS_POPOUT, cxWidth ) ;

	// When CStatusBar is created, a font is created and stored
	// internally in AFX.  But AFX will clean that font up during
	// shutdown, so we don't need to delete it.
	m_wndStatusBar.SetFont( theApp.m_pFont ) ;

	DragAcceptFiles( TRUE ) ;

	return 0;
}

void CMainFrame::OnDestroy()
{
	SavePosition() ;
	CFrameWnd::OnDestroy();
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	 CCreateContext* pContext)
{
	// create a splitter with 1 row, 2 columns
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE(_T("Failed to CreateStaticSplitter\n"));
		return FALSE;
	}

	// add the first splitter pane - the default view in column 0
	if (!m_wndSplitter.CreateView(0, 0,
		pContext->m_pNewViewClass, CSize(240, 0), pContext))
	{
		TRACE(_T("Failed to create first pane\n"));
		return FALSE;
	}

	if (!m_wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CRegistryView), CSize(0, 0), pContext))
	{
		TRACE(_T("Failed to create second pane\n"));
		return FALSE;
	}

	m_pObjTreeView = (CObjTreeView*)m_wndSplitter.GetPane(0, 0) ;
	m_pObjectView = (CRegistryView*)m_wndSplitter.GetPane(0,1) ;

	// activate the input view
	SetActiveView((CView*)m_wndSplitter.GetPane(0, 0));
	m_wndSplitter.SetColumnInfo( 0, 240, 0 ) ;

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


BOOL CMainFrame::SavePosition()
{
	CString szSection ;
	CString szKey ;

	#pragma warning(suppress: 6031)
	szSection.LoadString( IDS_INI_CONFIG ) ;
	ASSERT(szSection != "");
	#pragma warning(suppress: 6031)
	szKey.LoadString( IDS_INI_WNDPOS ) ;
	ASSERT(szKey != "");

	WINDOWPLACEMENT wp;
	CString szValue ;

	wp.length = sizeof( WINDOWPLACEMENT );
	GetWindowPlacement( &wp );

	int nWidth, n ;
	m_wndSplitter.GetColumnInfo( 0, nWidth, n ) ;

	LPTSTR p = szValue.GetBuffer( 255 ) ;
	_stprintf_s( p, 255, _T("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d"),
		wp.showCmd, wp.ptMinPosition.x, wp.ptMinPosition.y,
		wp.ptMaxPosition.x, wp.ptMaxPosition.y,
		wp.rcNormalPosition.left, wp.rcNormalPosition.top,
		wp.rcNormalPosition.right, wp.rcNormalPosition.bottom,
		nWidth,
		(m_wndToolBar.GetStyle() & WS_VISIBLE) ? TRUE : FALSE,
		(m_wndStatusBar.GetStyle() & WS_VISIBLE) ? TRUE : FALSE);

	szValue.ReleaseBuffer() ;
	theApp.WriteProfileString( szSection, szKey, szValue );
	return TRUE ;
}

BOOL CMainFrame::RestorePosition(int nCmdShow)
{
	CString sz ;
	CString szSection ;
	CString szKey ;
	BOOL fToolBar = TRUE ;
	BOOL fStatusBar = TRUE ;
	int  nWidth ;

	#pragma warning(suppress: 6031)
	szSection.LoadString( IDS_INI_CONFIG ) ;
	ASSERT(szSection != "");
	#pragma warning(suppress: 6031)
	szKey.LoadString( IDS_INI_WNDPOS ) ;
	ASSERT(szKey != "");

	WINDOWPLACEMENT wp;
	int     nConv;

	wp.length = sizeof( WINDOWPLACEMENT );
	wp.flags = 0 ;

	TRY
	{
		sz = theApp.GetProfileString(szSection, szKey, _T("") ) ;
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

		nWidth = (int)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		fToolBar = (BOOL)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		fStatusBar = (BOOL)ParseOffNumber( (LPTSTR FAR *)&lp, &nConv );
		if (!nConv)
			AfxThrowMemoryException();

		// Always strip off minimize.
		//
		if (wp.showCmd == SW_SHOWMINIMIZED)
			wp.showCmd = SW_SHOWNORMAL ;

		if (nCmdShow != SW_SHOWNORMAL)
			wp.showCmd = nCmdShow ;

		m_wndSplitter.SetColumnInfo( 0, nWidth, 0 ) ;
	}
	CATCH(CException, pException)
	{
		fToolBar = TRUE ;
		fStatusBar = TRUE ;
		ShowControlBar( &m_wndToolBar, fToolBar, TRUE ) ;
		ShowControlBar( &m_wndStatusBar, fStatusBar, TRUE ) ;
		ShowWindow( SW_SHOWNORMAL );
		return FALSE ;
	}
	END_CATCH
	ShowControlBar( &m_wndToolBar, fToolBar, TRUE ) ;
	ShowControlBar( &m_wndStatusBar, fStatusBar, TRUE ) ;
	return (BOOL)SetWindowPlacement( &wp ) ;
}

void CMainFrame::OnFileRunREGEDIT()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory( &si, sizeof(si) );
	si.cb = sizeof(si);
	ZeroMemory( &pi, sizeof(pi) );

	BOOL bFoundRegedit = FALSE;
	TCHAR szSysDirStr[ _MAX_PATH ];
	TCHAR szRegeditPath[ _MAX_PATH + _MAX_FNAME + 1];
	GetSystemDirectory(szSysDirStr, _MAX_PATH);	//Get system path

	//Search for regedit executable on system path
	memset (szRegeditPath, 0, sizeof (szRegeditPath));
	bFoundRegedit = SearchPath(szSysDirStr, _T("REGEDT32.EXE"), NULL, _MAX_PATH + _MAX_FNAME, szRegeditPath, NULL);
	if (!bFoundRegedit)
		bFoundRegedit = SearchPath(szSysDirStr, _T("REGEDIT.EXE"), NULL, _MAX_PATH + _MAX_FNAME, szRegeditPath, NULL);

	if (bFoundRegedit) {
		#pragma warning(suppress: 6054) // unexpected prefast warning
		CreateProcess( szRegeditPath, //path to regedit exe
			NULL,	// pointer to command line string
			NULL,	// Process handle not inheritable. 
			NULL,	// Thread handle not inheritable. 
			FALSE,	// Set handle inheritance to FALSE. 
			0,		// No creation flags. 
			NULL,	// Use parent's environment block. 
			NULL,	// Use parent's starting directory. 
			&si,	// Pointer to STARTUPINFO structure.
			&pi		// Pointer to PROCESS_INFORMATION structure.
		);


		CloseHandle( pi.hProcess );
		CloseHandle( pi.hThread );
	}
}

void CMainFrame::OnViewRefresh()
{
	COle2ViewDoc*   pDoc = (COle2ViewDoc*)GetActiveDocument() ;
	pDoc->UpdateAllViews( NULL, UPD_NORELOAD ) ;
}

void CMainFrame::OnUpdateViewRefresh(CCmdUI* /*pCmdUI*/)
{
}

void CMainFrame::OnSysColorChange()
{
//    Ctl3dColorChange() ;
	theApp.LoadBitmaps( TRUE ) ;
	CFrameWnd::OnSysColorChange();
}

void CMainFrame::OnObjectDelete()
{
	m_pObjTreeView->OnObjectDelete() ;
}

void CMainFrame::OnUpdateObjectDelete(CCmdUI* pCmdUI)
{
	pCmdUI->Enable( m_pObjTreeView->IsValidSel() ) ;
}

void CMainFrame::OnObjectVerify()
{
	m_pObjTreeView->OnObjectVerify() ;

}

void CMainFrame::OnUpdateObjectVerify(CCmdUI* pCmdUI)
{
	pCmdUI->Enable( m_pObjTreeView->IsValidSel() ) ;
}

void CMainFrame::OnFileViewTypeLib()
{
	static TCHAR szFilter[] = _T("TypeLib Files (*.tlb;*.olb;*.dll;*.ocx;*.exe)|*.tlb;*.olb;*.dll;*.ocx;*.exe|AllFiles(*.*)|*.*|") ;

	CFileDialog dlg(TRUE, _T("*.tlb"), NULL,
					OFN_FILEMUSTEXIST | OFN_HIDEREADONLY | OFN_PATHMUSTEXIST,
					szFilter, this);
	if (IDOK != dlg.DoModal())
		return ;

	// Call LoadTypeLib
	LPTYPELIB lpTypeLib;
	HRESULT hr = ::LoadTypeLib(CT2COLE(dlg.GetPathName()), &lpTypeLib);
	if (FAILED(hr))
	{
		CString szErrorMsg;
		szErrorMsg.Format(_T("LoadTypeLib( %s ) failed."),(LPCTSTR)dlg.GetPathName());
		ErrorMessage( szErrorMsg, hr );
		return ;
	}
	// call the interface wiewer
	ENSURE(lpTypeLib != NULL);
	ViewInterface( GetSafeHwnd(), IID_ITypeLib, (IUnknown*)lpTypeLib);
	VERIFY(0 == lpTypeLib->Release()) ;
}

void WINAPI ViewInterface( HWND hwnd, REFIID riid, IUnknown *punk )
{
	IInterfaceViewer* piv = NULL ;
	SCODE sc ;

	// Look in the registry for the "Ole2ViewIViewer=" key for this iid
	//
	TCHAR szKey[128] ;
	TCHAR szValue[80] ;
	TCHAR szInterface[80] ;

	// get the string from CLSID in TCHAR format
	LPOLESTR lpszOleIID = NULL;
	::StringFromCLSID(riid, &lpszOleIID);
	ASSERT(lpszOleIID != NULL);

	COLE2T lpszIID(lpszOleIID);
	ENSURE(lpszIID != NULL);
	IMalloc* pmal = NULL ;
	::CoGetMalloc( MEMCTX_TASK, &pmal ) ;
	pmal->Free( lpszOleIID ) ;
	pmal->Release() ;

	_stprintf_s(szKey, 128, _T("Interface\\%s"), lpszIID) ;

	LONG cb = sizeof(szValue);
	if (::RegQueryValue(HKEY_CLASSES_ROOT, szKey, szInterface, &cb) != ERROR_SUCCESS)
	{
		_tcscpy_s( szInterface, 80, "<no name>" ) ;
	}

	_stprintf_s(szKey, 128, _T("Interface\\%s\\Ole2ViewIViewerCLSID"), lpszIID );

	cb = sizeof(szValue) ;
	if (::RegQueryValue(HKEY_CLASSES_ROOT, szKey, szValue, &cb) != ERROR_SUCCESS)
	{
		CString str;
		str.Format(_T("There is no interface viewer for %s installed."), szInterface);
		ErrorMessage( str, E_FAIL ) ;
		return ;
	}

	CLSID clsid ;
	sc = ::CLSIDFromString( CT2OLE(szValue), &clsid ) ;
	if (FAILED(sc))
	{
		CString str;
		str.Format(_T("Could not convert the CLSID of the %s interface viewer."), szInterface);
		ErrorMessage( str, sc ) ;
		return ;
	}

	sc = ::CoCreateInstance( clsid, NULL, CLSCTX_SERVER, IID_IInterfaceViewer, (void**)&piv ) ;
	if (SUCCEEDED(sc))
	{
		IUnknown* ptemp = NULL ;
		HRESULT hr = punk->QueryInterface( riid, (void**)&ptemp ) ;
		if (SUCCEEDED(hr))
		{
			piv->View( hwnd, riid, ptemp ) ;
			piv->Release() ;
			ptemp->Release() ;
		}
	}
	else
	{
		CString str;
		str.Format(_T("The %s interface viewer failed to load."), szInterface);
		ErrorMessage( str, sc ) ;
	}
}

void CMainFrame::OnUseInProcServer()
{
	m_pObjTreeView->OnUseInProcServer();
}

void CMainFrame::OnUpdateUseInProcServer(CCmdUI* pCmdUI)
{
	m_pObjTreeView->OnUpdateUseInProcServer( pCmdUI );
}

void CMainFrame::OnUseInProcHandler()
{
   m_pObjTreeView->OnUseInProcHandler();
}

void CMainFrame::OnUpdateUseInProcHandler(CCmdUI* pCmdUI)
{
	m_pObjTreeView->OnUpdateUseInProcHandler( pCmdUI ) ;
}

void CMainFrame::OnUseLocalServer()
{
	m_pObjTreeView->OnUseLocalServer() ;
}

void CMainFrame::OnUpdateUseLocalServer(CCmdUI* pCmdUI)
{
	m_pObjTreeView->OnUpdateUseLocalServer( pCmdUI ) ;
}

void CMainFrame::OnFileBind()
{
	m_pObjTreeView->OnFileBind() ;
}
