// TestContainer98.cpp : Defines the class behaviors for the application.
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

CTCOptions::CTCOptions() :
   m_iLogType( TCLOG_OUTPUTWINDOW ),
   m_tUserMode( FALSE ),
   m_tAllowWindowless( TRUE ),
   m_tQuickActivation( TRUE ),
   m_tTwoPassDrawing( TRUE ),
   m_tUseIPointerInactive( TRUE ),
   m_tHonorIgnoreActivateWhenVisible( TRUE ),
   m_tIOleInPlaceSiteEx( TRUE ),
   m_tIOleInPlaceSiteWindowless( TRUE ),
   m_tIAdviseSinkEx( TRUE ),
   m_tSBindHost( TRUE )
{
	m_strDSMFile = _T("");
}

CTCCommandLineInfo::CTCCommandLineInfo( CTCOptions* pOptions ) :
   m_pOptions( pOptions ),
   m_tExpectingLogFileName( FALSE ),
   m_tExpectingDSMFile(FALSE),
   m_tExpectingProgID( FALSE )
{
   ASSERT( m_pOptions != NULL );
}

/*
   TestContainer98 command line switches:

   -C <progid>    ProgID of control to initially load

   -D <DSM File> path to .dsm file for running scripts
	
   -Ln            No logging
   -Lo            Log to output window
   -Ld            Log to debugger
   -Lf <filename> Log to file <filename>

   -IOleInPlaceSiteEx+  Support IOleInPlaceSiteEx
   -IOleInPlaceSiteEx-  Don't support IOleInPlaceSiteEx

   -IOleInPlaceSiteWindowless+ Support IOleInPlaceSiteWindowless
   -IOleInPlaceSiteWindowless- Don't support IOleInPlaceSiteWindowless

   -IAdviseSinkEx+   Support IAdviseSinkEx
   -IAdviseSinkEx-   Don't support IAdviseSinkEx

   -SBindHost+    Support SBindHost
   -SBindHost-    Don't support SBindHost

   -OQ+           Use quick activation
   -OQ-           Do not use quick activation

   -OT+           Use two-pass drawing
   -OT-           Do not use two-pass drawing

   -OI+           Support inactive controls
   -OI-           Do not support inactive controls

   -OH+           Honor OLEMISC_IGNOREACTIVATEWHENVISIBLE
   -OH-           Don't honor OLEMISC_IGNOREACTIVATEWHENVISIBLE

   -OW+           Allow windowless activation
   -OW-           Disallow windowless activation

   -U+            User mode
   -U-            Design mode
*/

void CTCCommandLineInfo::ParseServiceFlag( LPCTSTR pszParam )
{
   BOOL* ptService;
   const TCHAR* pcFlag;

   ENSURE( pszParam != NULL );
   ASSERT( pszParam[0] == 'S' );

   ptService = NULL;
   pcFlag = NULL;
   if( strncmp( pszParam, _T( "SBindHost" ), strlen( _T( "SBindHost" ) ) ) ==
	  0 )
   {
	  ptService = &m_pOptions->m_tSBindHost;
	  pcFlag = &pszParam[strlen( _T( "SBindHost" ) )];
   }

   if( ptService == NULL )
   {
	  TCTrace( TRACELEVEL_NORMAL, "Unrecognized command line parameter %s\n",
		 pszParam );
   }
   else
   {
	  if( *pcFlag == _T( '+' ) )
	  {
		 *ptService = TRUE;
	  }
	  else if( *pcFlag == _T( '-' ) )
	  {
		 *ptService = FALSE;
	  }
	  else
	  {
		 TCTrace( TRACELEVEL_NORMAL,
			"Command line option %s: Expected + or -\n", pszParam );
	  }
   }
}

void CTCCommandLineInfo::ParseInterfaceFlag( LPCTSTR pszParam )
{
   ENSURE( pszParam != NULL );
   ASSERT( pszParam[0] == 'I' );

   if( strncmp( pszParam, _T( "IOleInPlaceSiteEx" ), strlen( _T(
	  "IOleInPlaceSiteEx" ) ) ) == 0 )
   {
	  switch( pszParam[strlen( _T( "IOleInPlaceSiteEx" ) )] )
	  {
	  case _T( '+' ):
		 m_pOptions->m_tIOleInPlaceSiteEx = TRUE;
		 break;

	  case _T( '-' ):
		 m_pOptions->m_tIOleInPlaceSiteEx = FALSE;
		 break;

	  default:
		 TCTrace( 1, "Unrecognized command line parameter %s\n", pszParam );
		 break;
	  }
   }
   else if( strncmp( pszParam, _T( "IOleInPlaceSiteWindowless" ), strlen( _T(
	  "IOleInPlaceSiteWindowless" ) ) ) == 0 )
   {
	  switch( pszParam[strlen( _T( "IOleInPlaceSiteWindowless" ) )] )
	  {
	  case _T( '+' ):
		 m_pOptions->m_tIOleInPlaceSiteWindowless = TRUE;
		 break;

	  case _T( '-' ):
		 m_pOptions->m_tIOleInPlaceSiteWindowless = FALSE;
		 break;

	  default:
		 TCTrace( 1, "Unrecognized command line parameter %s\n", pszParam );
		 break;
	  }
   }
   else if( strncmp( pszParam, _T( "IAdviseSinkEx" ), strlen( _T(
	  "IAdviseSinkEx" ) ) ) == 0 )
   {
	  switch( pszParam[strlen( _T( "IAdviseSinkEx" ) )] )
	  {
	  case _T( '+' ):
		 m_pOptions->m_tIAdviseSinkEx = TRUE;
		 break;

	  case _T( '-' ):
		 m_pOptions->m_tIAdviseSinkEx = FALSE;
		 break;

	  default:
		 TCTrace( 1, "Unrecognized command line parameter %s\n", pszParam );
		 break;
	  }
   }
   else
   {
	  TCTrace( 1, "Unrecognized command line parameter %s\n", pszParam );
   }
}

void CTCCommandLineInfo::ParseOptionFlag( LPCTSTR pszParam )
{
   BOOL* ptOption;

   ENSURE( pszParam != NULL );
   ASSERT( pszParam[0] == 'O' );

   ptOption = NULL;
   switch( pszParam[1] )
   {
   case _T( 'Q' ):
	  ptOption = &m_pOptions->m_tQuickActivation;
	  break;

   case _T( 'T' ):
	  ptOption = &m_pOptions->m_tTwoPassDrawing;
	  break;

   case _T( 'W' ):
	  ptOption = &m_pOptions->m_tAllowWindowless;
	  break;

   case _T( 'H' ):
	  ptOption = &m_pOptions->m_tHonorIgnoreActivateWhenVisible;
	  break;

   case _T( 'I' ):
	  ptOption = &m_pOptions->m_tUseIPointerInactive;
	  break;

   default:
	  TCTrace( 1, "Unrecognized command line parameter %s\n", pszParam );
	  break;
   }

   if( ptOption != NULL )
   {
	  if( pszParam[2] == _T( '+' ) )
	  {
		 *ptOption = TRUE;
	  }
	  else if( pszParam[2] == _T( '-' ) )
	  {
		 *ptOption = FALSE;
	  }
	  else
	  {
		 TCTrace( TRACELEVEL_NORMAL,
			"Command line option %s: expected + or -\n", pszParam );
	  }
   }
}

void CTCCommandLineInfo::ParseParam( LPCTSTR pszParam, BOOL tFlag, BOOL tLast )
{
   BOOL tHandled;

   TRACE( "%s\n", pszParam );

   tHandled = FALSE;

   if( m_tExpectingLogFileName )
   {
	  tHandled = TRUE;
	  m_tExpectingLogFileName = FALSE;
	  if( tFlag )
	  {
		 TCTrace( TRACELEVEL_NORMAL, "Bogus log filename\n" );
	  }
	  else
	  {
		 m_pOptions->m_strLogFileName = pszParam;
	  }
   }
   else if(m_tExpectingDSMFile)
   {
	  tHandled = TRUE;
	  m_tExpectingDSMFile = FALSE;
	  if( tFlag )
	  {
		 TCTrace( TRACELEVEL_NORMAL, "Bogus dsm filename\n" );
	  }
	  else
	  {
		 m_pOptions->m_strDSMFile = pszParam;
	  }
	
   }   
   else if( m_tExpectingProgID )
   {
	  tHandled = TRUE;
	  m_tExpectingProgID = FALSE;
	  if( tFlag )
	  {
		 TCTrace( TRACELEVEL_NORMAL, "Bogus ProgID\n" );
	  }
	  else
	  {
		 m_pOptions->m_strProgID = pszParam;
	  }
   }
   else
   {
	  if( tFlag )
	  {
		 tHandled = TRUE;
		 switch( pszParam[0] )
		 {
		 case _T( 'C' ):
			if( tLast )
			{
			   TCTrace( TRACELEVEL_NORMAL,
				  "No ProgID given for /C parameter\n" );
			}
			else
			{
			   m_tExpectingProgID = TRUE;
			}
			break;
		 case _T( 'D' ):
			if( tLast )
			{
			   TCTrace( TRACELEVEL_NORMAL,
				  "No filename given for /C parameter\n" );
			}
			else
			{
			   m_tExpectingDSMFile = TRUE;
			}
			break;
		 case _T( 'I' ):
			ParseInterfaceFlag( pszParam );
			break;

		 case _T( 'S' ):
			ParseServiceFlag( pszParam );
			break;

		 case _T( 'L' ):
			switch( pszParam[1] )
			{
			case _T( 'n' ):
			   m_pOptions->m_iLogType = TCLOG_NULL;
			   break;

			case _T( 'o' ):
			   m_pOptions->m_iLogType = TCLOG_OUTPUTWINDOW;
			   break;

			case _T( 'd' ):
			   m_pOptions->m_iLogType = TCLOG_DEBUG;
			   break;

			case _T( 'f' ):
			   if( tLast )
			   {
				  TCTrace( 1, "No filename given for /Lf parameter\n" );
			   }
			   else
			   {
				  m_tExpectingLogFileName = TRUE;
			   }
			   break;

			default:
			   TCTrace( 1, "Unrecognized command line parameter %s\n",
				  pszParam );
			   break;
			}
			break;

		 case _T( 'O' ):
			ParseOptionFlag( pszParam );
			break;

		 case _T( 'U' ):
			switch( pszParam[1] )
			{
			case _T( '-' ):
			   m_pOptions->m_tUserMode = FALSE;
			   break;

			case _T( '+' ):
			   m_pOptions->m_tUserMode = TRUE;
			   break;

			default:
			   TCTrace( 1, "Unrecognized command line parameter %s\n",
				  pszParam );
			   break;
			}
			break;

		 default:
			tHandled = FALSE;
			break;
		 }
	  }
   }

   if( !tHandled )
   {
	  CCommandLineInfo::ParseParam( pszParam, tFlag, tLast );
   }
}

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98App

BEGIN_MESSAGE_MAP(CTestContainer98App, CWinApp)
	//{{AFX_MSG_MAP(CTestContainer98App)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_OPTIONS_TRACELEVEL_NONE, OnOptionsTraceLevelNone)
	ON_COMMAND(ID_OPTIONS_TRACELEVEL_NORMAL, OnOptionsTraceLevelNormal)
	ON_COMMAND(ID_OPTIONS_TRACELEVEL_VERBOSE, OnOptionsTraceLevelVerbose)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_TRACELEVEL_NONE, OnUpdateOptionsTraceLevelNone)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_TRACELEVEL_NORMAL, OnUpdateOptionsTraceLevelNormal)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_TRACELEVEL_VERBOSE, OnUpdateOptionsTraceLevelVerbose)
	ON_COMMAND(ID_FILE_REGISTERCONTROLS, OnFileRegisterControls)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98App construction

CTestContainer98App::CTestContainer98App()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	EnableHtmlHelp();
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CTestContainer98App object

CTestContainer98App theApp;

// This identifier was generated to be statistically unique for your app.
// You may change it if you prefer to choose a specific identifier.

// {198184FA-B837-11D0-8DF1-00C04FB68D60}
static const CLSID DOCTEMPLATE_CLSID =
{ 0x198184fa, 0xb837, 0x11d0, { 0x8d, 0xf1, 0x0, 0xc0, 0x4f, 0xb6, 0x8d, 0x60 } };

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98App initialization

static const LPCTSTR SETTINGS_KEY = _T( "Settings" );

void CTestContainer98App::LoadRegistrySettings()
{
   m_options.m_tUserMode = GetProfileInt( SETTINGS_KEY, _T( "UserMode" ),
	  FALSE );
   m_options.m_tAllowWindowless = GetProfileInt( SETTINGS_KEY, _T(
	  "AllowWindowless" ), TRUE );
   m_options.m_tQuickActivation = GetProfileInt( SETTINGS_KEY, _T(
	  "QuickActivation" ), TRUE );
   m_options.m_tTwoPassDrawing = GetProfileInt( SETTINGS_KEY, _T(
	  "TwoPassDrawing" ), TRUE );
   m_options.m_tHonorIgnoreActivateWhenVisible = GetProfileInt( SETTINGS_KEY,
	  _T( "HonorIgnoreActivateWhenVisible" ), TRUE );
   m_options.m_tUseIPointerInactive = GetProfileInt( SETTINGS_KEY, _T(
	  "UseIPointerInactive" ), TRUE );
   m_options.m_tIOleInPlaceSiteEx = GetProfileInt( SETTINGS_KEY, _T(
	  "IOleInPlaceSiteEx" ), TRUE );
   m_options.m_tIOleInPlaceSiteWindowless = GetProfileInt( SETTINGS_KEY, _T(
	  "IOleInPlaceSiteWindowless" ), TRUE );
   m_options.m_tIAdviseSinkEx = GetProfileInt( SETTINGS_KEY, _T(
	  "IAdviseSinkEx" ), TRUE );
   m_options.m_tSBindHost = GetProfileInt( SETTINGS_KEY, _T( "SBindHost" ),
	  TRUE );
}

void CTestContainer98App::SaveRegistrySettings()
{
   WriteProfileInt( SETTINGS_KEY, _T( "UserMode" ), m_options.m_tUserMode );
   WriteProfileInt( SETTINGS_KEY, _T( "AllowWindowless" ),
	  m_options.m_tAllowWindowless );
   WriteProfileInt( SETTINGS_KEY, _T( "QuickActivation" ),
	  m_options.m_tQuickActivation );
   WriteProfileInt( SETTINGS_KEY, _T( "TwoPassDrawing" ),
	  m_options.m_tTwoPassDrawing );
   WriteProfileInt( SETTINGS_KEY, _T( "UseIPointerInactive" ),
	  m_options.m_tUseIPointerInactive );
   WriteProfileInt( SETTINGS_KEY, _T( "HonorIgnoreActivateWhenVisible" ),
	  m_options.m_tHonorIgnoreActivateWhenVisible );
   WriteProfileInt( SETTINGS_KEY, _T( "IOleInPlaceSiteEx" ),
	  m_options.m_tIOleInPlaceSiteEx );
   WriteProfileInt( SETTINGS_KEY, _T( "IOleInPlaceSiteWindowless" ),
	  m_options.m_tIOleInPlaceSiteWindowless );
   WriteProfileInt( SETTINGS_KEY, _T( "IAdviseSinkEx" ),
	  m_options.m_tIAdviseSinkEx );
   WriteProfileInt( SETTINGS_KEY, _T( "SBindHost" ), m_options.m_tSBindHost );
}

BOOL CTestContainer98App::InitInstance()
{
	// Initialize OLE libraries
	if( !AfxOleInit() )
	{
		AfxMessageBox( IDP_OLE_INIT_FAILED );
		return( FALSE );
	}

	AfxEnableControlContainer();

	// Change the registry key under which our settings are stored.
	// You should modify this string to be something appropriate
	// such as the name of your company or organization.
	SetRegistryKey( _T( "Microsoft" ) );

	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

   LoadRegistrySettings();

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate( IDR_MAINFRAME, RUNTIME_CLASS(
	  CTestContainer98Doc ), RUNTIME_CLASS( CMainFrame ), RUNTIME_CLASS(
	  CTestContainer98View ) );
	pDocTemplate->SetContainerInfo( IDR_TC98TYPE_CNTR_IP );
	AddDocTemplate( pDocTemplate );

	// Connect the COleTemplateServer to the document template.
	//  The COleTemplateServer creates new documents on behalf
	//  of requesting OLE containers by using information
	//  specified in the document template.
	m_server.ConnectTemplate( DOCTEMPLATE_CLSID, pDocTemplate, FALSE );
		// Note: SDI applications register server objects only if /Embedding
		//   or /Automation is present on the command line.
		
	COleTemplateServer::RegisterAll();	

   // Parse command line for standard shell commands, DDE, file open
	CTCCommandLineInfo cmdInfo( &m_options );
	ParseCommandLine( cmdInfo );

	// Check to see if launched as OLE server
	if( cmdInfo.m_bRunEmbedded || cmdInfo.m_bRunAutomated )
	{
		// Application was run with /Embedding or /Automation.  Don't show the
		//  main window in this case.
		return( TRUE );
	}

	// When a server application is launched stand-alone, it is a good idea
	//  to update the system registry in case it has been damaged.
	m_server.UpdateRegistry( OAT_DISPATCH_OBJECT );
	COleObjectFactory::UpdateRegistryAll();

	// Dispatch commands specified on the command line
	if( !ProcessShellCommand( cmdInfo ) )
   {
	  return( FALSE );
   }

	// The main window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow( SW_SHOW );
	m_pMainWnd->UpdateWindow();

	return( TRUE );
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
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
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CTestContainer98App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98App commands


void CTestContainer98App::OnOptionsTraceLevelNone()
{
   SetTraceLevel( TRACELEVEL_NONE );
}

void CTestContainer98App::OnOptionsTraceLevelNormal()
{
   SetTraceLevel( TRACELEVEL_NORMAL );
}

void CTestContainer98App::OnOptionsTraceLevelVerbose()
{
   SetTraceLevel( TRACELEVEL_VERBOSE );
}

void CTestContainer98App::OnUpdateOptionsTraceLevelNone( CCmdUI* pCmdUI )
{
   pCmdUI->SetRadio( GetTraceLevel() == TRACELEVEL_NONE );
}

void CTestContainer98App::OnUpdateOptionsTraceLevelNormal( CCmdUI* pCmdUI )
{
   pCmdUI->SetRadio( GetTraceLevel() == TRACELEVEL_NORMAL );
}

void CTestContainer98App::OnUpdateOptionsTraceLevelVerbose( CCmdUI* pCmdUI )
{
   pCmdUI->SetRadio( GetTraceLevel() == TRACELEVEL_VERBOSE );
}

void CTestContainer98App::OnFileRegisterControls()
{
   CRegisterControlsDlg dlg;

   dlg.DoModal();
}
