// RegisterControlsDlg.Cpp : implementation file
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
// CRegisterControlsDlg dialog


CRegisterControlsDlg::CRegisterControlsDlg( CWnd* pParent ) :
   CDialog( CRegisterControlsDlg::IDD, pParent )
{
	//{{AFX_DATA_INIT(CRegisterControlsDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CRegisterControlsDlg::DoDataExchange( CDataExchange* pDX )
{
	CDialog::DoDataExchange( pDX );

	//{{AFX_DATA_MAP(CRegisterControlsDlg)
	DDX_Control(pDX, IDC_REREGISTER, m_butReregister);
	DDX_Control(pDX, IDC_UNREGISTER, m_butUnregister);
	DDX_Control(pDX, IDC_REGISTEREDCONTROLS, m_lvRegisteredControls);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegisterControlsDlg, CDialog)
	//{{AFX_MSG_MAP(CRegisterControlsDlg)
	ON_BN_CLICKED(IDC_UNREGISTER, OnUnregister)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_REGISTEREDCONTROLS, OnRegisteredControlsItemChanged)
	ON_BN_CLICKED(IDC_REREGISTER, OnReregister)
	ON_BN_CLICKED(IDC_REGISTER, OnRegister)
	ON_WM_HELPINFO()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRegisterControlsDlg message handlers

BOOL CRegisterControlsDlg::OnInitDialog()
{
   CWaitCursor wait;

   CString strColumnTitle;

   CDialog::OnInitDialog();

   LOAD_STRING_FROM_RESOURCE(strColumnTitle, IDS_PROGID);
   m_lvRegisteredControls.InsertColumn( 0, strColumnTitle, LVCFMT_LEFT, 200 );
   LOAD_STRING_FROM_RESOURCE(strColumnTitle, IDS_PATH);
   m_lvRegisteredControls.InsertColumn( 1, strColumnTitle, LVCFMT_LEFT, 250 );

   RefreshRegisteredControls();

   return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

static BOOL IsAControl( HKEY hkClass )
{
   LONG lResult;
   HKEY hk;

   ASSERT( hkClass != NULL );

   lResult = RegOpenKeyEx( hkClass, _T( "InprocServer32" ), 0, KEY_READ, &hk );
   if( lResult != ERROR_SUCCESS )
   {
	  // It doesn't have an inproc server, so it's probably not a control.
	  return( FALSE );
   }
   RegCloseKey( hk );

   lResult = RegOpenKeyEx( hkClass, _T( "ProgID" ), 0, KEY_READ, &hk );
   if( lResult != ERROR_SUCCESS )
   {
	  // It doesn't have a ProgID, so it's not a control.
	  return( FALSE );
   }
   RegCloseKey( hk );

   lResult = RegOpenKeyEx( hkClass, _T( "Control" ), 0, KEY_READ, &hk );
   if( lResult == ERROR_SUCCESS )
   {
	  // It's definitely a control.
	  RegCloseKey( hk );
	  return( TRUE );
   }

   lResult = RegOpenKeyEx( hkClass, _T( "ToolboxBitmap32" ), 0, KEY_READ,
	  &hk );
   if( lResult == ERROR_SUCCESS )
   {
	  // It's definitely a control.
	  RegCloseKey( hk );
	  return( TRUE );
   }

   return( FALSE );
}

void CRegisterControlsDlg::RefreshRegisteredControls()
{
   HKEY hkCLSID;
   LONG lResult;
   DWORD iIndex;
   DWORD nSubkeyLength;
   FILETIME time;
   BOOL tStopEnumerating;
   DWORD dwType;
   DWORD nDataLength;
   TCHAR szProgID[80];
   TCHAR szInprocServer32[MAX_PATH];
   TCHAR szSubkey[MAX_PATH];
   HKEY hkSubkey;
   HKEY hkInprocServer32;
   HKEY hkProgID;
   int iItem;

   m_lvRegisteredControls.SetRedraw(FALSE);
   m_lvRegisteredControls.DeleteAllItems();

   lResult = RegOpenKeyEx( HKEY_CLASSES_ROOT, _T( "CLSID" ), 0, KEY_READ,
	  &hkCLSID );
   if( lResult != ERROR_SUCCESS )
   {
	  return;
   }

   iIndex = 0;
   tStopEnumerating = FALSE;
   while( !tStopEnumerating )
   {
	  nSubkeyLength = sizeof( szSubkey )/sizeof( szSubkey[0] );
	  lResult = RegEnumKeyEx( hkCLSID, iIndex, szSubkey, &nSubkeyLength, NULL,
		 NULL, NULL, &time );
	  if( lResult == ERROR_SUCCESS )
	  {
		 lResult = RegOpenKeyEx( hkCLSID, szSubkey, 0, KEY_READ, &hkSubkey );
		 if( lResult == ERROR_SUCCESS )
		 {
			if( IsAControl( hkSubkey ) )
			{
			   lResult = RegOpenKeyEx( hkSubkey, _T( "InprocServer32" ), 0,
				  KEY_READ, &hkInprocServer32 );
			   if( lResult == ERROR_SUCCESS )
			   {
				  nDataLength = sizeof( szInprocServer32 );
				  lResult = RegQueryValueEx( hkInprocServer32, NULL, NULL,
					 &dwType, LPBYTE( szInprocServer32 ), &nDataLength );
				  RegCloseKey( hkInprocServer32 );
				  if( (lResult == ERROR_SUCCESS) && (dwType == REG_SZ) )
				  {
					 lResult = RegOpenKeyEx( hkSubkey, _T( "ProgID" ), 0,
						KEY_READ, &hkProgID );
					 if( lResult == ERROR_SUCCESS )
					 {
						nDataLength = sizeof( szProgID );
						lResult = RegQueryValueEx( hkProgID, NULL, NULL,
						   &dwType, LPBYTE( szProgID ), &nDataLength );
						RegCloseKey( hkProgID );
						if( (lResult == ERROR_SUCCESS) && (dwType == REG_SZ) )
						{
						   iItem = m_lvRegisteredControls.InsertItem( 0,
							  szProgID );
						   m_lvRegisteredControls.SetItemText( iItem, 0,
							  szProgID );
						   m_lvRegisteredControls.SetItemText( iItem, 1,
							  szInprocServer32 );
						}
					 }
				  }
			   }
			}
		 }
	  }
	  else
	  {
		 tStopEnumerating = TRUE;
	  }
	  iIndex++;
   }

   m_lvRegisteredControls.SetRedraw(TRUE);
   m_lvRegisteredControls.Invalidate();
   UpdateButtons();
}

typedef HRESULT (STDAPICALLTYPE* PDLLREGISTERSERVER)( void );
typedef HRESULT (STDAPICALLTYPE* PDLLUNREGISTERSERVER)( void );

void CRegisterControlsDlg::OnUnregister()
{
   CWaitCursor wait;

   UINT nSelectedItems;
   int iItem;
   CString strPath;
   HINSTANCE hLibrary;
   PDLLUNREGISTERSERVER pDllUnregisterServer;
   HRESULT hResult;
   int nResult;

   iItem = -1;
   nSelectedItems = m_lvRegisteredControls.GetSelectedCount();
   while( nSelectedItems > 0 )
   {
	  iItem = m_lvRegisteredControls.GetNextItem( iItem, LVNI_SELECTED );
	  ASSERT( iItem != -1 );

	  strPath = m_lvRegisteredControls.GetItemText( iItem, 1 );
	  TCTrace( TRACELEVEL_NORMAL, "Unregistering %s\n", LPCTSTR( strPath ) );

	  hResult = S_OK;

	  hLibrary = LoadLibrary( strPath );
	  if( hLibrary == NULL )
	  {
		 TCTrace( TRACELEVEL_NORMAL, "Failed to load library %s.\n", LPCTSTR(
			strPath ) );
		 hResult = E_FAIL;
	  }
	  else
	  {
		 pDllUnregisterServer = PDLLUNREGISTERSERVER( GetProcAddress( hLibrary,
			_T( "DllUnregisterServer" ) ) );
		 if( pDllUnregisterServer == NULL )
		 {
			TCTrace( TRACELEVEL_NORMAL,
			   "Failed to get address of DllUnregisterServer.\n" );
			hResult = E_FAIL;
		 }
		 else
		 {
			hResult = pDllUnregisterServer();
			if( FAILED( hResult ) )
			{
			   TCTrace( TRACELEVEL_NORMAL,
				  "DllUnregisterServer failed hResult = 0x%x.\n", hResult );
			}
		 }
		 FreeLibrary( hLibrary );
	  }

	  if( FAILED( hResult ) )
	  {
		 nResult = AfxMessageBox( IDS_UNREGISTERSERVERFAILED, MB_YESNO );
		 if( nResult == IDYES )
		 {
		 }
	  }

	  nSelectedItems--;
   }

   RefreshRegisteredControls();
}

void CRegisterControlsDlg::UpdateButtons()
{
   if( m_lvRegisteredControls.GetSelectedCount() > 0 )
   {
	  m_butReregister.EnableWindow( TRUE );
	  m_butUnregister.EnableWindow( TRUE );
   }
   else
   {
	  m_butReregister.EnableWindow( FALSE );
	  m_butUnregister.EnableWindow( FALSE );
   }
}

void CRegisterControlsDlg::OnRegisteredControlsItemChanged( NMHDR* pNMHDR,
   LRESULT* pResult )
{
   (void)pNMHDR;

   UpdateButtons();

	*pResult = 0;
}

static void RegisterServer( LPCTSTR pszPathName )
{
   HINSTANCE hLibrary;
   PDLLREGISTERSERVER pDllRegisterServer;
   HRESULT hResult;

   TCTrace( TRACELEVEL_NORMAL, "Registering %s\n", pszPathName );
   hLibrary = LoadLibrary( pszPathName );
   if( hLibrary == NULL )
   {
	  TCTrace( TRACELEVEL_NORMAL, "Failed to load library %s.\n",
		 pszPathName );
   }
   else
   {
	  pDllRegisterServer = PDLLREGISTERSERVER( GetProcAddress( hLibrary, _T(
		 "DllRegisterServer" ) ) );
	  if( pDllRegisterServer == NULL )
	  {
		 TCTrace( TRACELEVEL_NORMAL,
			"Failed to get address of DllRegisterServer.\n" );
	  }
	  else
	  {
		 hResult = pDllRegisterServer();
		 if( FAILED( hResult ) )
		 {
			TCTrace( TRACELEVEL_NORMAL,
			   "DllRegisterServer failed hResult = 0x%x.\n", hResult );
		 }
	  }
	  FreeLibrary( hLibrary );
   }
}

void CRegisterControlsDlg::OnReregister()
{
   CWaitCursor wait;

   UINT nSelectedItems;
   int iItem;
   CString strPath;

   iItem = -1;
   nSelectedItems = m_lvRegisteredControls.GetSelectedCount();
   while( nSelectedItems > 0 )
   {
	  iItem = m_lvRegisteredControls.GetNextItem( iItem, LVNI_SELECTED );
	  ASSERT( iItem != -1 );
	  strPath = m_lvRegisteredControls.GetItemText( iItem, 1 );
	  RegisterServer( strPath );
	  nSelectedItems--;
   }

   RefreshRegisteredControls();
}

void CRegisterControlsDlg::OnRegister()
{
   POSITION posPathName;
   CString strPathName;
   int nResult;

   CFileDialog dlg( TRUE, _T( "dll" ), NULL, OFN_HIDEREADONLY|
	  OFN_FILEMUSTEXIST|OFN_ALLOWMULTISELECT, _T(
	  "ActiveX Controls|*.dll;*.ocx;*.ax||" ) );

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   CWaitCursor wait;

   posPathName = dlg.GetStartPosition();
   while( posPathName != NULL )
   {
	  strPathName = dlg.GetNextPathName( posPathName );
	  RegisterServer( strPathName );
   }

   RefreshRegisteredControls();
}


static DWORD rgmapCHID[] =
{
   IDC_REGISTEREDCONTROLS, HIDC_REGISTEREDCONTROLS,
   IDC_UNREGISTER, HIDC_UNREGISTER,
   IDC_REGISTER, HIDC_REGISTER,
   IDC_REREGISTER, HIDC_REREGISTER,
   0, 0
};

BOOL CRegisterControlsDlg::OnHelpInfo( HELPINFO* pHelpInfo )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	return ::HtmlHelp((HWND)pHelpInfo->hItemHandle, strPath, HH_TP_HELP_WM_HELP, DWORD(LPVOID(rgmapCHID))) != NULL;
}

void CRegisterControlsDlg::OnContextMenu( CWnd* pWnd, CPoint /* point */ )
{
	CString strPath = AfxGetApp()->m_pszHelpFilePath;
	strPath += _T("::/popups.txt");

	::HtmlHelp((HWND)*pWnd, strPath, HH_TP_HELP_CONTEXTMENU, DWORD(LPVOID(rgmapCHID)));
}
