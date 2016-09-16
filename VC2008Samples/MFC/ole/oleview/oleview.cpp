// oleview.cpp : Defines the class behaviors for the application.
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
#include <winver.h>

#include <initguid.h>
#include "iviewers\\iviewers.h"

#include "OleView.h"

#include "mainfrm.h"
#include "doc.h"
#include "obj_vw.h"
#include "regview.h"
#include "shadow.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COle2ViewApp

BEGIN_MESSAGE_MAP(COle2ViewApp, CWinApp)
	//{{AFX_MSG_MAP(COle2ViewApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COle2ViewApp construction

COle2ViewApp::COle2ViewApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only COle2ViewApp object

COle2ViewApp theApp;
#if _MFC_VER >= 0x0300
OSVERSIONINFO  g_osvi ;
#endif

/////////////////////////////////////////////////////////////////////////////
// COle2ViewApp initialization

BOOL COle2ViewApp::InitInstance()
{
	if (!AfxOleInit()) //OleInitialize(NULL)))
	{
		AfxMessageBox( _T("OleInitialize failed.  Could not initialized OLE 2; Ole2View cannot run.") ) ;
		return FALSE;
	}

	SetRegistryKey( IDS_REGISTRYKEY );

	m_pFont = ReallyCreateFont( NULL, _T("MS Sans Serif"), _T("Regular"), 8, 0 ) ;
	m_pFontBold = ReallyCreateFont( NULL, _T("MS Sans Serif"), _T("Bold"), 8, 0 ) ;

	LoadBitmaps( FALSE ) ;

	TEXTMETRIC  tm ;
	CDC dc ;
	HDC hdc = GetDC( NULL ) ;
	dc.Attach( hdc ) ;

	m_pFont = dc.SelectObject( m_pFont ) ;
	dc.GetTextMetrics( &tm ) ;
	m_pFont = dc.SelectObject( m_pFont ) ;
	dc.Detach();
	ReleaseDC( NULL, hdc ) ;

	m_cyFont = tm.tmHeight + tm.tmExternalLeading ;

	// AutoRegister iviewers if not already registered
	//
//    char szBuf[80] ; LONG cb = sizeof(szBuf) ;
//    if (RegQueryValue(HKEY_CLASSES_ROOT, "Ole2View.ITypeLib.1", szBuf, &cb) != ERROR_SUCCESS)
//    {
		CString str ;
		CString str2 ;
		HINSTANCE hinst = LoadLibrary( "iviewers.dll" ) ;
		if (hinst > (HINSTANCE)HINSTANCE_ERROR)
		{
			// Get DllRegisterServer function
			HRESULT (FAR STDAPICALLTYPE * lpDllEntryPoint)(void);
			(FARPROC&)lpDllEntryPoint = GetProcAddress(hinst, "DllRegisterServer");
			#pragma warning(suppress: 6001) //unexpected uninitialized memory prefast warning
			ENSURE(lpDllEntryPoint);
			if (lpDllEntryPoint)
			{
				HRESULT hr ;
				if (FAILED(hr = (*lpDllEntryPoint)()))
				{
					#pragma warning(suppress: 6031)
					str.LoadString( IDS_AUTOREGFAILED ) ;
					ASSERT(str != "");
					#pragma warning(suppress: 6031)
					str2.LoadString( IDS_IVIEWERSNOTFOUND2 ) ;
					ASSERT(str2 != "");
					str += str2 ;
					AfxMessageBox( str ) ;
				}
			}
			else
			{
				#pragma warning(suppress: 6031)
				str.LoadString( IDS_IVIEWERSNOTFOUND3 ) ;
				ASSERT(str != "");
				#pragma warning(suppress: 6031)
				str2.LoadString( IDS_IVIEWERSNOTFOUND2 ) ;
				ASSERT(str2 != "");
				str += str2 ;
				AfxMessageBox( str ) ;
			}

			FreeLibrary( hinst ) ;
		}
		else
		{
			
			#pragma warning(suppress: 6031)
			str.LoadString( IDS_IVIEWERSNOTFOUND1 ) ;
			ASSERT(str != "");
			#pragma warning(suppress: 6031)
			str2.LoadString( IDS_IVIEWERSNOTFOUND2 ) ;
			ASSERT(str2 != "");
			str += str2 ;
			#pragma warning(suppress: 6031)
			str2.LoadString( IDS_IVIEWERSNOTFOUND4 ) ;
			ASSERT(str2 != "");
			str += str2 ;
			AfxMessageBox( str ) ;
		}
//    }

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.
	AddDocTemplate(new CSingleDocTemplate(IDR_MAINFRAME,
			RUNTIME_CLASS(COle2ViewDoc),
			RUNTIME_CLASS(CMainFrame),     // main SDI frame window
			RUNTIME_CLASS(CObjTreeView)));

	int nCmdShow = m_nCmdShow ;
	m_nCmdShow = SW_HIDE ;
	OnFileNew() ;
	((CMainFrame*)GetMainWnd())->RestorePosition(nCmdShow) ;

	// TODO: If there's something on the command line, try to
	// figure out if it's a
	//  - CLSID or a ProgID: CoCreateInstance the thing
	//  - A filename: Bind to the file, via a FileMoniker
	// Then enum the interfaces as normal.
	//
	if (m_lpCmdLine != NULL && *m_lpCmdLine != '\0')
	{
		AfxMessageBox( IDS_BADCOMMANDLINE ) ;
	}

	return TRUE;
}

int COle2ViewApp::ExitInstance()
{
	if (m_pFont)
		delete m_pFont ;

	if (m_pFontBold)
		delete m_pFontBold ;

//    FreeBitmaps() ;

	return CWinApp::ExitInstance() ;
}


void COle2ViewApp::LoadBitmaps( BOOL fFree )
{
#if 0
	COLORREF    rgbNorm, rgbHigh ;

	rgbNorm  = GetSysColor( COLOR_WINDOW ) ;
	rgbHigh = GetSysColor( COLOR_HIGHLIGHT ) ;

	if (fFree)
		FreeBitmaps() ;

	for (int i = IDB_FIRST ; i <= IDB_LAST ; i++)
	{
		m_rgbmNorm[BMINDEX(i)] = bmLoadAndTranslate( i, rgbNorm ) ;
		m_rgbmHigh[BMINDEX(i)] = bmLoadAndTranslate( i, rgbHigh ) ;
	}
#else
	if (fFree)
		m_images.DeleteImageList() ;

	if (0 == m_images.Create( IDB_IMAGELIST, 16, 100, RGBLTGREEN ))
	{
		AfxMessageBox("Could not load bitmaps" ) ;
	}
#endif
}

#if 0
void FreeABitmap( CBitmap* p )
{
	if (p)
		delete p ;
}
#endif

void COle2ViewApp::FreeBitmaps()
{
#if 0
	for (int i = IDB_FIRST ; i <= IDB_LAST ; i++)
	{
		FreeABitmap( m_rgbmNorm[BMINDEX(i)]) ;
		FreeABitmap( m_rgbmHigh[BMINDEX(i)]) ;
	}
#else
	m_images.DeleteImageList() ;
#endif
}

/////////////////////////////////////////////////////////////////////////////
// COle2ViewApp commands
// We override OnIdle so that we can ensure the right message is on the status
// bar.   Note we have to  call OnIdle alawys to make sure stuff like
// CoFreeUnusedLibraries actually works.   (Bug fixed in 1.13).

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CButton m_Cancel;
	CStatic m_WrittenBy;
	CStatic m_Group;
	CStatic m_Copyright;
	CStatic m_AppName;
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDCANCEL, m_Cancel);
	DDX_Control(pDX, IDC_WRITTENBY, m_WrittenBy);
	DDX_Control(pDX, IDC_GROUP, m_Group);
	DDX_Control(pDX, IDC_COPYRIGHT, m_Copyright);
	DDX_Control(pDX, IDC_APPNAME, m_AppName);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void COle2ViewApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}



typedef struct tagVS_VERSION
  {
	WORD wTotLen;
	WORD wValLen;
	TCHAR szSig[16];
	VS_FIXEDFILEINFO vffInfo;
  } VS_VERSION;


BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	DlgCenter( m_hWnd, ::GetParent( m_hWnd ), FALSE ) ;

	return TRUE;  // return TRUE  unless you set the focus to a control
}
