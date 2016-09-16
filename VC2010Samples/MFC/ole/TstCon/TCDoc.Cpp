// CTestContainer98Doc.cpp : implementation of the CTestContainer98Doc class
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
// CTestContainer98Doc

IMPLEMENT_DYNCREATE( CTestContainer98Doc, COleDocument )

BEGIN_MESSAGE_MAP(CTestContainer98Doc, COleDocument)
	//{{AFX_MSG_MAP(CTestContainer98Doc)
	ON_COMMAND(ID_OPTIONS_FREEZEEVENTS, OnOptionsFreezeEvents)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_FREEZEEVENTS, OnUpdateOptionsFreezeEvents)
	ON_COMMAND(ID_OPTIONS_SLOWDRAWING, OnOptionsSlowDrawing)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_SLOWDRAWING, OnUpdateOptionsSlowDrawing)
	ON_COMMAND(ID_OPTIONS_TWOPASSDRAWING, OnOptionsTwoPassDrawing)
	ON_UPDATE_COMMAND_UI(ID_OPTIONS_TWOPASSDRAWING, OnUpdateOptionsTwoPassDrawing)
	ON_COMMAND(ID_OPTIONS_LOGGING, OnOptionsLogging)
	ON_COMMAND(ID_CONTAINER_OPTIONS, OnContainerOptions)
	ON_COMMAND(ID_CONTAINER_AMBIENTPROPERTIES, OnContainerAmbientProperties)
	ON_COMMAND(ID_CONTAINER_INFO, OnContainerInfo)
	ON_COMMAND(ID_EDIT_DELETEALL, OnEditDeleteAll)
	ON_UPDATE_COMMAND_UI(ID_EDIT_DELETEALL, OnUpdateEditDeleteAll)
	ON_COMMAND(ID_CONTAINER_TABORDER, OnContainerTabOrder)
	ON_COMMAND(ID_TOOLS_MACROS, OnToolsMacros)
	ON_COMMAND(ID_RUNMACRO, OnRunMacro)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
   ON_UPDATE_COMMAND_UI_RANGE( ID_OLE_VERB_FIRST, ID_OLE_VERB_LAST, COleDocument::OnUpdateObjectVerbMenu )
END_MESSAGE_MAP()

BEGIN_CONNECTION_MAP( CTestContainer98Doc, COleDocument )
   CONNECTION_PART( CTestContainer98Doc, __uuidof( ITestContainer98Events ), TC98CP )
END_CONNECTION_MAP()

BEGIN_DISPATCH_MAP( CTestContainer98Doc, COleDocument )
	//{{AFX_DISPATCH_MAP(CTestContainer98Doc)
	DISP_PROPERTY_EX(CTestContainer98Doc, "PrimarySelection", GetPrimarySelection, SetPrimarySelection, VT_DISPATCH)
	DISP_FUNCTION(CTestContainer98Doc, "FindControl", FindControl, VT_DISPATCH, VTS_BSTR)
	DISP_FUNCTION(CTestContainer98Doc, "Log", Log, VT_EMPTY, VTS_BSTR)
	DISP_FUNCTION(CTestContainer98Doc, "InsertControl", InsertControl, VT_DISPATCH, VTS_BSTR VTS_BSTR)
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

BEGIN_INTERFACE_MAP( CTestContainer98Doc, COleDocument )
	INTERFACE_PART( CTestContainer98Doc, __uuidof( ITestContainer98 ), Dispatch )
   INTERFACE_PART( CTestContainer98Doc, IID_IConnectionPointContainer, ConnPtContainer )
END_INTERFACE_MAP()

const IID LIBID_TestContainer98 = {0x198184FB,0xB837,0x11D0,{0x8D,0xF1,0x00,0xC0,0x4F,0xB6,0x8D,0x60}};

IMPLEMENT_OLETYPELIB( CTestContainer98Doc, LIBID_TestContainer98, 1, 0 )

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98Doc construction/destruction

CTestContainer98Doc::CTestContainer98Doc() :
   m_pFontHolder( NULL ),
   m_tUserMode( FALSE ),
   m_tFreezeEvents( FALSE ),
   m_tAllowWindowless( TRUE ),
   m_tTwoPassDrawing( TRUE ),
   m_tSlowDrawing( FALSE ),
   m_tHonorIgnoreActivateWhenVisible( TRUE ),
   m_tUseIPointerInactive( TRUE ),
   m_tUseQuickActivation( TRUE ),
   m_tIOleInPlaceSiteWindowless( TRUE ),
   m_tIOleInPlaceSiteEx( TRUE ),
   m_tIAdviseSinkEx( TRUE ),
   m_tSBindHost( TRUE ),
   m_pLog( NULL ),
   m_pScriptManager( NULL )
{
   m_descFont.lpstrName = NULL;

	// Use OLE compound files
	EnableCompoundFile();

   EnableConnections();

	EnableAutomation();

	AfxOleLockApp();
}

CTestContainer98Doc::~CTestContainer98Doc()
{
   Cleanup();

	AfxOleUnlockApp();
}

void CTestContainer98Doc::Cleanup()
{
   int iProp;

   if( m_pScriptManager != NULL )
   {
	  delete m_pScriptManager;
	  m_pScriptManager = NULL;
   }

   delete m_pLog;
   m_pLog = NULL;

   for( iProp = 0; iProp < m_apAmbientProperties.GetSize(); iProp++ )
   {
	  delete m_apAmbientProperties[iProp];
   }
   m_apAmbientProperties.SetSize( 0 );

   delete m_pFontHolder;
   m_pFontHolder = NULL;

   delete[] m_descFont.lpstrName;
   m_descFont.lpstrName = NULL;
}

void CTestContainer98Doc::CreateUniqueItemName( CTestContainer98Item* pItem,
   LPCTSTR pszBaseName, CString& strUniqueName )
{
   POSITION posItem;
   CTestContainer98Item* pSearchItem;
   ULONG nTag;
   BOOL tCollisionFound;

   ASSERT( pszBaseName != NULL );

   // Assume the name is already unique
   strUniqueName = pszBaseName;

   nTag = 1;
   do
   {
	  tCollisionFound = FALSE;
	  posItem = GetStartPosition();
	  while( (posItem != NULL) && !tCollisionFound )
	  {
		 pSearchItem = (CTestContainer98Item*)GetNextItem( posItem );
		 if( pSearchItem != pItem )
		 {
			if( strUniqueName == pSearchItem->GetDisplayName() )
			{
			   // This name is already in use.
			   tCollisionFound = TRUE;
			   strUniqueName.Format( "%s%u", pszBaseName, nTag );
			   nTag++;
			}
		 }
	  }
   } while( tCollisionFound );
}

BOOL CTestContainer98Doc::Initialize()
{

   CLSID clsid;
   HRESULT hResult;
   CMainFrame* pMainFrame;
   CTestContainer98App* pApp;
   CFileLog* pFileLog;
   BOOL tSuccess;

   pApp = (CTestContainer98App*)AfxGetApp();

   m_tUserMode = pApp->m_options.m_tUserMode;
   m_tFreezeEvents = FALSE;
   m_tAllowWindowless = pApp->m_options.m_tAllowWindowless;
   m_tTwoPassDrawing = pApp->m_options.m_tTwoPassDrawing;
   m_tSlowDrawing = FALSE;
   m_tHonorIgnoreActivateWhenVisible =
	  pApp->m_options.m_tHonorIgnoreActivateWhenVisible;
   m_tUseIPointerInactive = pApp->m_options.m_tUseIPointerInactive;
   m_tUseQuickActivation = pApp->m_options.m_tQuickActivation;
   m_tIOleInPlaceSiteWindowless = pApp->m_options.m_tIOleInPlaceSiteWindowless;
   m_tIOleInPlaceSiteEx = pApp->m_options.m_tIOleInPlaceSiteEx;
   m_tIAdviseSinkEx = pApp->m_options.m_tIAdviseSinkEx;
   m_tSBindHost = pApp->m_options.m_tSBindHost;
   m_pLog = NULL;

   pMainFrame = DYNAMIC_DOWNCAST( CMainFrame, AfxGetMainWnd() );

   switch( pApp->m_options.m_iLogType )
   {
   case TCLOG_NULL:
	  m_pLog = new CNullLog;
	  break;

   case TCLOG_OUTPUTWINDOW:
	  m_pLog = new COutputWindowLog( GetOutputEditControl() );
	  break;

   case TCLOG_DEBUG:
	  m_pLog = new CDebugLog;
	  break;

   case TCLOG_FILE:
	  pFileLog = new CFileLog;
	  tSuccess = pFileLog->Create( pApp->m_options.m_strLogFileName );
	  if( !tSuccess )
	  {
		 delete pFileLog;
	  }
	  m_pLog = pFileLog;
	  break;

   default:
	  ASSERT( FALSE );
	  break;
   }
   if( m_pLog == NULL )
   {
	  return( FALSE );
   }

   hResult = InitDefaultAmbientProperties();
   if( FAILED( hResult ) )
   {
	  return( FALSE );
   }

   if( !pApp->m_options.m_strProgID.IsEmpty() )
   {
	  try
	  {
		 hResult = CLSIDFromProgID( CT2COLE( pApp->m_options.m_strProgID ), &clsid );
		 if( FAILED( hResult ) )
		 {
			AfxThrowOleException( hResult );
		 }
		 AddControl( clsid, NULL );
	  }
	  catch( CException* pException )
	  {
		 pException->Delete();
		 TCTrace( TRACELEVEL_NORMAL, "Failed to load control.\n" );
	  }
	  pApp->m_options.m_strProgID.Empty();
   }

	return( TRUE );
}

BOOL CTestContainer98Doc::OnNewDocument()
{
	if( !COleDocument::OnNewDocument() )
   {
	  return( FALSE );
   }

   return( Initialize() );
}


/////////////////////////////////////////////////////////////////////////////
// CTestContainer98Doc serialization

void CTestContainer98Doc::Serialize( CArchive& ar )
{
   POSITION posScript;
   CScript* pScript;
   int nScripts;
   int iScript;
   CString strScriptName;
   CString strScriptPath;
   CScriptManager* pScriptManager;
   CString strErrorMessage;
   HRESULT hResult;
   int iProp;
   CAmbientProperty* pUserMode;

   if( ar.IsLoading() )
   {
	  Initialize();

	  for( iProp = 0; iProp < m_apAmbientProperties.GetSize(); iProp++ )
	  {
		 delete m_apAmbientProperties[iProp];
	  }
	  m_apAmbientProperties.SetSize( 0 );

	  m_apAmbientProperties.Serialize( ar );

	  pUserMode = FindAmbientProperty( DISPID_AMBIENT_USERMODE );
	  if( pUserMode != NULL )
	  {
		 if( pUserMode->GetValue().vt == VT_BOOL )
		 {
			m_tUserMode = pUserMode->GetValue().boolVal;
		 }
	  }
   }
   else
   {
	  m_apAmbientProperties.Serialize( ar );
   }

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
	COleDocument::Serialize( ar );

   if( ar.IsStoring() )
   {
	  pScriptManager = GetScriptManager( FALSE );
	  if( pScriptManager != NULL )
	  {
		 ar<<pScriptManager->GetNumScripts();

		 posScript = pScriptManager->GetFirstScriptPosition();
		 while( posScript != NULL )
		 {
			pScript = pScriptManager->GetNextScript( posScript );
			ar<<pScript->GetName();
		 }
	  }
	  else
	  {
		 ar<<int( 0 );
	  }
   }
   else
   {
	  ar>>nScripts;
	  if( nScripts > 0 )
	  {
		 pScriptManager = GetScriptManager();
		 if( pScriptManager != NULL )
		 {
			for( iScript = 0; iScript < nScripts; iScript++ )
			{
			   ar>>strScriptName;
			   strScriptPath = m_strDirectory+strScriptName+_T( ".dsm" );
			   hResult = pScriptManager->LoadScript( strScriptPath,
				  strScriptName );
			   if( FAILED( hResult ) )
			   {
				  _com_error error( hResult );

				  AfxFormatString2( strErrorMessage, IDS_ERRORLOADINGSCRIPT,
					 strScriptName, error.ErrorMessage() );
				  AfxMessageBox( strErrorMessage );
			   }
			}
		 }
	  }
   }
}

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98Doc diagnostics

#ifdef _DEBUG
void CTestContainer98Doc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CTestContainer98Doc::Dump( CDumpContext& dc ) const
{
	COleDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98Doc commands

void CTestContainer98Doc::BringToFront( CDocItem* pItem )
{
   POSITION posItem;

   ASSERT( pItem != NULL );

   posItem = m_docItemList.Find( pItem );
   ASSERT( posItem != NULL );

   m_docItemList.RemoveAt( posItem );
   m_docItemList.AddHead( pItem );
}

void CTestContainer98Doc::SendToBack( CDocItem* pItem )
{
   POSITION posItem;

   ASSERT( pItem != NULL );

   posItem = m_docItemList.Find( pItem );
   ASSERT( posItem != NULL );

   m_docItemList.RemoveAt( posItem );
   m_docItemList.AddTail( pItem );
}

HRESULT CTestContainer98Doc::InitDefaultAmbientProperties()
{
   CString strName;
   LPCOLESTR pszFaceName;
   CAmbientProperty* pProp;
   VARIANT_BOOL tUserMode;

   if( m_tUserMode )
   {
	  tUserMode = VAR_TRUE;
   }
   else
   {
	  tUserMode = VAR_FALSE;
   }

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_USERMODE);
   pProp = new CAmbientProperty( DISPID_AMBIENT_USERMODE, strName, COleVariant(
	  tUserMode, VT_BOOL ), VTI_BOOL, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_UIDEAD);
   pProp = new CAmbientProperty( DISPID_AMBIENT_UIDEAD, strName, COleVariant(
	  VARIANT_FALSE, VT_BOOL ), VTI_BOOL, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_SHOWHATCHING);
   pProp = new CAmbientProperty( DISPID_AMBIENT_SHOWHATCHING, strName,
	  COleVariant( VARIANT_BOOL( -1 ), VT_BOOL ), VTI_BOOL, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_SHOWGRABHANDLES);
   pProp = new CAmbientProperty( DISPID_AMBIENT_SHOWGRABHANDLES, strName,
	  COleVariant( VARIANT_BOOL( -1 ), VT_BOOL ), VTI_BOOL, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_TEXTALIGN);
   pProp = new CAmbientProperty( DISPID_AMBIENT_TEXTALIGN, strName,
	  COleVariant( short( 0 ), VT_I2 ), VTI_I2, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_BACKCOLOR);
   pProp = new CAmbientProperty( DISPID_AMBIENT_BACKCOLOR, strName,
	  COleVariant( long( GetSysColor( COLOR_WINDOW ) ), VT_I4 ), VTI_COLOR,
	  TRUE );
   m_apAmbientProperties.Add( pProp );

   delete m_pFontHolder;
   m_pFontHolder = new CFontHolder( NULL );
   if( m_pFontHolder == NULL )
   {
	  AfxThrowMemoryException();
   }
   m_descFont.cbSizeofstruct = sizeof( m_descFont );
   pszFaceName = L"MS Sans Serif";
   delete[] m_descFont.lpstrName;
   size_t len = wcslen( pszFaceName )+1;
   m_descFont.lpstrName = new OLECHAR[len];
   if( m_descFont.lpstrName == NULL )
   {
	  AfxThrowMemoryException();
   }
   ATL_CRT_ERRORCHECK(wcscpy_s(m_descFont.lpstrName, len, pszFaceName));
   m_descFont.cySize.Lo = 80000L;
   m_descFont.cySize.Hi = 0;
   m_descFont.sWeight = FW_BOLD;
   m_descFont.sCharset = 0;
   m_descFont.fItalic = FALSE;
   m_descFont.fUnderline = FALSE;
   m_descFont.fStrikethrough = FALSE;
   m_pFontHolder->InitializeFont( &m_descFont );

   COleVariant varFont;
   varFont.vt = VT_DISPATCH;
   varFont.pdispVal = m_pFontHolder->GetFontDispatch();

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_FONT);
   pProp = new CAmbientProperty( DISPID_AMBIENT_FONT, strName, varFont,
	  VTI_FONT, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_FORECOLOR);
   pProp = new CAmbientProperty( DISPID_AMBIENT_FORECOLOR, strName,
	  COleVariant( long( GetSysColor( COLOR_WINDOWTEXT ) ), VT_I4 ), VTI_COLOR,
	  TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_SCALEUNITS);
   pProp = new CAmbientProperty( DISPID_AMBIENT_SCALEUNITS, strName,
	  COleVariant( _T( "" ), VT_BSTR ), VTI_BSTR, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_DISPLAYNAME);
   pProp = new CAmbientProperty( DISPID_AMBIENT_DISPLAYNAME, strName,
	  COleVariant( _T( "" ), VT_BSTR ), VTI_BSTR, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_LOCALEID);
   pProp = new CAmbientProperty( DISPID_AMBIENT_LOCALEID, strName, COleVariant(
	  long( GetUserDefaultLCID() ), VT_I4 ), VTI_I4, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_MESSAGEREFLECT);
   pProp = new CAmbientProperty( DISPID_AMBIENT_MESSAGEREFLECT, strName,
	  COleVariant( VARIANT_FALSE, VT_BOOL ), VTI_BOOL, TRUE );
   m_apAmbientProperties.Add( pProp );

   LOAD_STRING_FROM_RESOURCE(strName, IDS_APROPNAME_SUPPORTSMNEMONICS);
   pProp = new CAmbientProperty( DISPID_AMBIENT_SUPPORTSMNEMONICS, strName,
	  COleVariant( VARIANT_BOOL( -1 ), VT_BOOL ), VTI_BOOL, TRUE );
   m_apAmbientProperties.Add( pProp );

   return( S_OK );
}

BOOL CTestContainer98Doc::CanWindowlessActivate() const
{
   return( m_tAllowWindowless );
}

BOOL CTestContainer98Doc::UseIPointerInactive() const
{
   return( m_tUseIPointerInactive );
}

BOOL CTestContainer98Doc::UseQuickActivation() const
{
   return( m_tUseQuickActivation );
}

BOOL CTestContainer98Doc::UseSlowDrawing() const
{
   return( m_tSlowDrawing );
}

BOOL CTestContainer98Doc::UseTwoPassDrawing() const
{
   return( m_tTwoPassDrawing );
}

BOOL CTestContainer98Doc::HonorIgnoreActivateWhenVisible() const
{
   return( m_tHonorIgnoreActivateWhenVisible );
}

int CTestContainer98Doc::AddAmbientProperty( DISPID dispid, LPCTSTR pszName,
   const VARIANT& var, int vti )
{
   CAmbientProperty* pProp;
   int iProp;

   pProp = new CAmbientProperty( dispid, pszName, var, vti );
   if( pProp == NULL )
   {
	  AfxThrowMemoryException();
   }

   iProp = (int)m_apAmbientProperties.Add( pProp );

   return( iProp );
}

CAmbientProperty* CTestContainer98Doc::FindAmbientProperty( DISPID dispid )
{
   int iProp;

   for( iProp = 0; iProp < m_apAmbientProperties.GetSize(); iProp++ )
   {
	  if( m_apAmbientProperties[iProp]->GetID() == dispid )
	  {
		 return( m_apAmbientProperties[iProp] );
	  }
   }

   // We didn't find the property.
   return( NULL );
}

CAmbientProperty* CTestContainer98Doc::FindAmbientProperty( LPCOLESTR pszName )
{

   int iProp;

   COLE2CT pszNameT( pszName );
   for( iProp = 0; iProp < m_apAmbientProperties.GetSize(); iProp++ )
   {
	  if( m_apAmbientProperties[iProp]->GetName() == pszNameT )
	  {
		 return( m_apAmbientProperties[iProp] );
	  }
   }

   // We didn't find the property.
   return( NULL );
}

CAmbientProperty* CTestContainer98Doc::GetAmbientProperty( int iProp )
{
   return( m_apAmbientProperties[iProp] );
}

int CTestContainer98Doc::GetNumAmbientProperties() const
{
   return( (int)m_apAmbientProperties.GetSize() );
}

POSITION CTestContainer98Doc::FindItem( CDocItem* pItem ) const
{
   return( m_docItemList.Find( pItem ) );
}

POSITION CTestContainer98Doc::GetTailPosition() const
{
   return( m_docItemList.GetTailPosition() );
}

CDocItem* CTestContainer98Doc::GetPrevItem( POSITION& pos ) const
{
   return( (CDocItem*)m_docItemList.GetPrev( pos ) );
}

CTestContainer98Item* CTestContainer98Doc::GetNextTabItem(
   CTestContainer98Item* pItem ) const
{
   POSITION posItem;

   if( pItem == NULL )
   {
	  if( m_lpTabOrder.IsEmpty() )
	  {
		 return( NULL );
	  }

	  return( m_lpTabOrder.GetHead() );
   }

   posItem = m_lpTabOrder.Find( pItem );
   ASSERT( posItem != NULL );
   m_lpTabOrder.GetNext( posItem );
   if( posItem == NULL )
   {
	  // Wrap around to the beginning of the list.
	  return( m_lpTabOrder.GetHead() );
   }

   return( m_lpTabOrder.GetAt( posItem ) );
}

void CTestContainer98Doc::SetItemTabOrder( CTestContainer98Item* pItem,
   int iTabOrder )
{
   POSITION posItem;

   ASSERT( pItem != NULL );

   posItem = FindItem( pItem );
   ASSERT( posItem != NULL );

   posItem = m_lpTabOrder.Find( pItem );
   ASSERT( posItem != NULL );

   m_lpTabOrder.RemoveAt( posItem );
   posItem = m_lpTabOrder.FindIndex( iTabOrder );
   if( posItem == NULL )
   {
	  // We went off the end of the list.
	  m_lpTabOrder.AddTail( pItem );
   }
   else
   {
	  m_lpTabOrder.InsertBefore( posItem, pItem );
   }
}

BOOL CTestContainer98Doc::GetUserMode() const
{
   return( m_tUserMode );
}

void CTestContainer98Doc::SetUserMode( BOOL tUserMode )
{
   CAmbientProperty* pProp;

   if( (m_tUserMode && tUserMode) || (!m_tUserMode && !tUserMode) )
   {
	  // No change
	  return;
   }

   m_tUserMode = tUserMode;
   pProp = FindAmbientProperty( DISPID_AMBIENT_USERMODE );
   ENSURE( pProp != NULL );

   if( m_tUserMode )
   {
	  pProp->SetValue( COleVariant( VARIANT_BOOL( -1 ), VT_BOOL ) );
   }
   else
   {
	  pProp->SetValue( COleVariant( VARIANT_FALSE, VT_BOOL ) );
   }

   if( pProp->IsEnabled() )
   {
	  BroadcastAmbientPropertyChange( pProp->GetID() );
   }
}

void CTestContainer98Doc::BroadcastAmbientPropertyChange( DISPID dispid )
{
   POSITION posItem;
   CTestContainer98Item* pItem;

   TCTrace( TRACELEVEL_NORMAL,
	  "Broadcasting ambient property change.  DISPID=%d\n", dispid );

   posItem = GetStartPosition();
   while( posItem != NULL )
   {
	  pItem = (CTestContainer98Item*)GetNextItem( posItem );
	  pItem->OnAmbientPropertyChange( dispid );
   }

   if( (dispid == DISPID_AMBIENT_USERMODE) || (dispid == DISPID_UNKNOWN) )
   {
	  // Invalidate the view, since some objects need to be rendered
	  // differently in design mode vs. user mode.
	  UpdateAllViews( NULL );
   }
}

BOOL CTestContainer98Doc::SupportsInterface( REFIID iid )
{
   if( iid == IID_IOleInPlaceSiteEx )
   {
	  return( m_tIOleInPlaceSiteEx || m_tIOleInPlaceSiteWindowless );
   }
   else if( iid == IID_IOleInPlaceSiteWindowless )
   {
	  return( m_tIOleInPlaceSiteWindowless );
   }
   else if( iid == IID_IAdviseSinkEx )
   {
	  return( m_tIAdviseSinkEx );
   }

   return( FALSE );
}

BOOL CTestContainer98Doc::SupportsService( REFGUID sid )
{
   if( sid == SID_SBindHost )
   {
	  return( m_tSBindHost );
   }

   return( FALSE );
}

void CTestContainer98Doc::PreCloseFrame( CFrameWnd* pFrame )
{
   POSITION posItem;
   CTestContainer98Item* pItem;

   posItem = GetStartPosition();
   while( posItem != NULL )
   {
	  pItem = (CTestContainer98Item*)GetNextItem( posItem );
	  if( pItem != NULL )
	  {
		 if( pItem->IsInPlaceActive() )
		 {
			pItem->Deactivate();
		 }
	  }
   }

   COleDocument::PreCloseFrame( pFrame );
}

BOOL CTestContainer98Doc::CanCloseFrame( CFrameWnd* pFrame )
{
   return( COleDocument::CanCloseFrame( pFrame ) );
}

BOOL CTestContainer98Doc::OnSaveDocument( LPCTSTR pszPathName )
{
   return( COleDocument::OnSaveDocument( pszPathName ) );
}

void CTestContainer98Doc::AddItem( CDocItem* pItem )
{
	COleDocument::AddItem( pItem );

   m_lpTabOrder.AddTail( (CTestContainer98Item*)pItem );
}

CLog* CTestContainer98Doc::GetLog() const
{
   return( m_pLog );
}

void CTestContainer98Doc::DeleteContents()
{
   Cleanup();

	COleDocument::DeleteContents();
}

void CTestContainer98Doc::OnOptionsFreezeEvents()
{
   POSITION posItem;
   CTestContainer98Item* pItem;

   m_tFreezeEvents = !m_tFreezeEvents;

   posItem = GetStartPosition();
   while( posItem != NULL )
   {
	  // Set the item's FreezeEvents status.
	  pItem = (CTestContainer98Item*)GetNextItem( posItem );
	  pItem->FreezeEvents( m_tFreezeEvents );
   }
}

void CTestContainer98Doc::OnUpdateOptionsFreezeEvents( CCmdUI* pCmdUI )
{
   if( m_tFreezeEvents )
   {
	  pCmdUI->SetCheck( 1 );
   }
   else
   {
	  pCmdUI->SetCheck( 0 );
   }
}

void CTestContainer98Doc::OnOptionsSlowDrawing()
{
   m_tSlowDrawing = !m_tSlowDrawing;
}

void CTestContainer98Doc::OnUpdateOptionsSlowDrawing( CCmdUI* pCmdUI )
{
   pCmdUI->SetCheck( m_tSlowDrawing == TRUE );
}

void CTestContainer98Doc::OnOptionsTwoPassDrawing()
{
   m_tTwoPassDrawing = !m_tTwoPassDrawing;
}

void CTestContainer98Doc::OnUpdateOptionsTwoPassDrawing( CCmdUI* pCmdUI )
{
   pCmdUI->SetCheck( m_tTwoPassDrawing == TRUE );
}

void CTestContainer98Doc::OnOptionsLogging()
{
   CLoggingDlg dlg;
   CFileLog* pFileLog;
   int nResult;
   int iOldLogType;
   BOOL tSuccess;

   if( m_pLog->IsKindOf( RUNTIME_CLASS( CNullLog ) ) )
   {
	  dlg.m_iLogType = TCLOG_NULL;
   }
   else if( m_pLog->IsKindOf( RUNTIME_CLASS( COutputWindowLog ) ) )
   {
	  dlg.m_iLogType = TCLOG_OUTPUTWINDOW;
   }
   else if( m_pLog->IsKindOf( RUNTIME_CLASS( CDebugLog ) ) )
   {
	  dlg.m_iLogType = TCLOG_DEBUG;
   }
   else if( m_pLog->IsKindOf( RUNTIME_CLASS( CFileLog ) ) )
   {
	  pFileLog = DYNAMIC_DOWNCAST( CFileLog, m_pLog );
	  dlg.m_iLogType = TCLOG_FILE;
	  dlg.m_strFileName = pFileLog->GetFileName();
   }
   iOldLogType = dlg.m_iLogType;

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   switch( dlg.m_iLogType )
   {
   case TCLOG_NULL:
	  if( iOldLogType != TCLOG_NULL )
	  {
		 delete m_pLog;
		 m_pLog = new CNullLog;
	  }
	  break;

   case TCLOG_OUTPUTWINDOW:
	  if( iOldLogType != TCLOG_OUTPUTWINDOW )
	  {
		 CMainFrame* pMainFrame;

		 delete m_pLog;
		 pMainFrame = STATIC_DOWNCAST( CMainFrame, AfxGetMainWnd() );
		 m_pLog = new COutputWindowLog( GetOutputEditControl() );
	  }
	  break;

   case TCLOG_DEBUG:
	  if( iOldLogType != TCLOG_DEBUG )
	  {
		 delete m_pLog;
		 m_pLog = new CDebugLog;
	  }
	  break;

   case TCLOG_FILE:
	  if( (iOldLogType != TCLOG_FILE) || ((iOldLogType == TCLOG_FILE) &&
		 ((DYNAMIC_DOWNCAST( CFileLog, m_pLog ))->GetFileName() !=
		 dlg.m_strFileName)) )
	  {
		 delete m_pLog;
		 m_pLog = new CFileLog;
		 pFileLog = DYNAMIC_DOWNCAST( CFileLog, m_pLog );
		 tSuccess = pFileLog->Create( dlg.m_strFileName );
		 if( !tSuccess )
		 {
			TRACE( "Failed to create log file.\n" );
		 }
	  }
	  break;
   }
}

void CTestContainer98Doc::OnContainerOptions()
{
   int nResult;
   CFeaturesPage pageFeatures;
   CInterfacesPage pageInterfaces;
   CServicesPage pageServices;
   CPropertySheet sheet( IDS_CONTAINEROPTIONS );

   pageFeatures.m_tAllowWindowless = m_tAllowWindowless;
   pageFeatures.m_tTwoPassDrawing = m_tTwoPassDrawing;
   pageFeatures.m_tHonorIgnoreActivateWhenVisible =
	  m_tHonorIgnoreActivateWhenVisible;
   pageFeatures.m_tUseIPointerInactive = m_tUseIPointerInactive;
   pageFeatures.m_tUseQuickActivation = m_tUseQuickActivation;
   sheet.AddPage( &pageFeatures );

   pageInterfaces.m_tIOleInPlaceSiteEx = m_tIOleInPlaceSiteEx;
   pageInterfaces.m_tIOleInPlaceSiteWindowless = m_tIOleInPlaceSiteWindowless;
   pageInterfaces.m_tIAdviseSinkEx = m_tIAdviseSinkEx;
   sheet.AddPage( &pageInterfaces );

   pageServices.m_tSBindHost = m_tSBindHost;
   sheet.AddPage( &pageServices );

   sheet.m_psh.dwFlags &= ~PSH_HASHELP;
   sheet.m_psh.dwFlags |= PSH_NOAPPLYNOW;
   nResult = (int)sheet.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   m_tAllowWindowless = pageFeatures.m_tAllowWindowless;
   m_tTwoPassDrawing = pageFeatures.m_tTwoPassDrawing;
   m_tHonorIgnoreActivateWhenVisible =
	  pageFeatures.m_tHonorIgnoreActivateWhenVisible;
   m_tUseIPointerInactive = pageFeatures.m_tUseIPointerInactive;
   m_tUseQuickActivation = pageFeatures.m_tUseQuickActivation;

   m_tIOleInPlaceSiteEx = pageInterfaces.m_tIOleInPlaceSiteEx;
   m_tIOleInPlaceSiteWindowless = pageInterfaces.m_tIOleInPlaceSiteWindowless;
   m_tIAdviseSinkEx = pageInterfaces.m_tIAdviseSinkEx;

   m_tSBindHost = pageServices.m_tSBindHost;
}

void CTestContainer98Doc::OnContainerAmbientProperties()
{
   DISPID dispidChanged;
   BOOL tChanged;
   CAmbientProperty* pProperty;

   CAmbientPropertiesDlg dlg( NULL, this );

   dlg.DoModal();

   // Check for changes.
   tChanged = dlg.GetChangedPropertyID( &dispidChanged );
   if( tChanged )
   {
	  if( (dispidChanged == DISPID_AMBIENT_USERMODE) || (dispidChanged ==
		 DISPID_UNKNOWN) )
	  {
		 // Update our cached version of the UserMode property.
		 pProperty = FindAmbientProperty( DISPID_AMBIENT_USERMODE );
		 ENSURE( pProperty != NULL );
		 ENSURE( pProperty->GetValue().vt == VT_BOOL );
		 m_tUserMode = pProperty->GetValue().bVal;
	  }
	  BroadcastAmbientPropertyChange( dispidChanged );
   }
}

void CTestContainer98Doc::OnContainerInfo()
{
   CContainerInfoDlg dlg( NULL, this );

   dlg.DoModal();
}

void CTestContainer98Doc::OnEditDeleteAll()
{
   CTestContainer98Item* pItem;
   POSITION posItem;
   POSITION posView;
   CTestContainer98View* pView;

   posView = GetFirstViewPosition();
   ASSERT( posView != NULL );
   pView = DYNAMIC_DOWNCAST( CTestContainer98View, GetNextView( posView ) );
   pView->ClearSelection();

   do
   {
	  posItem = GetStartPosition();
	  if( posItem != NULL )
	  {
		 pItem = (CTestContainer98Item*)GetNextItem( posItem );
		 ENSURE( pItem != NULL );
		 pItem->Delete();
	  }
   } while( posItem != NULL );

   UpdateAllViews( NULL );
}

void CTestContainer98Doc::OnUpdateEditDeleteAll( CCmdUI* pCmdUI )
{
   POSITION posItem;

   posItem = GetStartPosition();
   pCmdUI->Enable( posItem != NULL );
}

void CTestContainer98Doc::RemoveItem( CDocItem* pItem )
{
   POSITION posItem;

   posItem = m_lpTabOrder.Find( DYNAMIC_DOWNCAST( CTestContainer98Item,
	  pItem ) );
   ASSERT( posItem != NULL );
   m_lpTabOrder.RemoveAt( posItem );

	COleDocument::RemoveItem( pItem );
}

void CTestContainer98Doc::OnContainerTabOrder()
{
   POSITION posItem;
   CTabOrderDlg dlg;
   int nResult;
   CTestContainer98Item* pItem;

   posItem = m_lpTabOrder.GetHeadPosition();
   while( posItem != NULL )
   {
	  pItem = m_lpTabOrder.GetNext( posItem );
	  ASSERT( pItem != NULL );
	  dlg.m_lpTabOrder.AddTail( pItem );
   }

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   m_lpTabOrder.RemoveAll();
   posItem = dlg.m_lpTabOrder.GetHeadPosition();
   while( posItem != NULL )
   {
	  pItem = dlg.m_lpTabOrder.GetNext( posItem );
	  m_lpTabOrder.AddTail( pItem );
   }
}

CEdit* CTestContainer98Doc::GetOutputEditControl()
{
   POSITION posView;
   CView* pView;

   posView = GetFirstViewPosition();
   ASSERT( posView != NULL );

   while( posView != NULL )
   {
	  pView = GetNextView( posView );
	  ENSURE( pView != NULL );
	  if( pView->IsKindOf( RUNTIME_CLASS( CEditView ) ) )
	  {
		 return( &(STATIC_DOWNCAST( CEditView, pView )->GetEditCtrl()) );
	  }
   }

   return( NULL );
}

CTestContainer98View* CTestContainer98Doc::GetView() const
{
   POSITION posView;
   CView* pView;

   posView = GetFirstViewPosition();
   ASSERT( posView != NULL );

   while( posView != NULL )
   {
	  pView = GetNextView( posView );
	  ENSURE( pView != NULL );
	  if( pView->IsKindOf( RUNTIME_CLASS( CTestContainer98View ) ) )
	  {
		 return( STATIC_DOWNCAST( CTestContainer98View, pView ) );
	  }
   }

   ASSERT( FALSE );

   return( NULL );
}

CTestContainer98Item* CTestContainer98Doc::AddControl( REFCLSID clsid,
   LPCTSTR pszName, REFIID iidPersistanceMedium, IUnknown* pPersistanceMedium )
{
   CTestContainer98Item* pItem;

   pItem = NULL;
   try
   {
	  pItem = new CTestContainer98Item( this );
	  ASSERT_VALID( pItem );

	  if( !pItem->CreateOrLoad( clsid, pszName, iidPersistanceMedium,
		 pPersistanceMedium ) )
	  {
		 AfxThrowOleException( E_FAIL );
	  }
	  ASSERT_VALID( pItem );

	  pItem->InvalidateItem();
   }
   catch( ... )
   {
	  ENSURE( pItem != NULL );
	  pItem->Delete();

	  throw;
   }
   ASSERT( pItem != NULL );

   return( pItem );
}

LPDISPATCH CTestContainer98Doc::InsertControl( LPCTSTR pszProgID,
   LPCTSTR pszName )
{

   CLSID clsid;
   HRESULT hResult;
   CTestContainer98Item* pItem;
   IDispatch* pDispatch;
   CScriptManager* pScriptManager;

   TRACE( "InsertControl: %s\n", pszProgID );

   hResult = CLSIDFromProgID( CT2COLE( pszProgID ), &clsid );
   if( FAILED( hResult ) )
   {
	  TRACE( "CLSIDFromProgID failed\n" );
	  return( NULL );
   }

   pItem = NULL;
   try
   {
	  pItem = AddControl( clsid, pszName );
	  ASSERT_VALID( pItem );

	  pItem->InvalidateItem();
   }
   catch( COleException* pException )
   {
	  ASSERT( pItem == NULL );

	  hResult = pException->m_sc;
	  pException->Delete();

	  return( NULL );
   }
   catch( CException* pException )
   {
	  ASSERT( pItem == NULL );

	  pException->Delete();

	  return( NULL );
   }
   ASSERT( pItem != NULL );

   pDispatch = NULL;
   hResult = pItem->m_lpObject->QueryInterface( IID_IDispatch,
	  (void**)&pDispatch );
   if( FAILED( hResult ) )
   {
	  pItem->Delete();
	  return( NULL );
   }
   ASSERT( pDispatch != NULL );

   pScriptManager = GetScriptManager( FALSE );
   if( pScriptManager != NULL )
   {
	  pScriptManager->AddNamedItem( pszName, pDispatch );
   }

   FireOnNewControl( pDispatch );

   return( pDispatch );
}

LPDISPATCH CTestContainer98Doc::GetPrimarySelection()
{
   IDispatch* pDispatch;
   POSITION posView;
   CTestContainer98View* pView;
   HRESULT hResult;

   posView = GetFirstViewPosition();
   ASSERT( posView != NULL );
   pView = (CTestContainer98View*)GetNextView( posView );
   ASSERT( posView == NULL );

   if( pView->m_pSelection == NULL )
   {
	  return( NULL );
   }

   pDispatch = NULL;
   hResult = pView->m_pSelection->m_lpObject->QueryInterface( IID_IDispatch,
	  (void**)&pDispatch );
   if( FAILED( hResult ) )
   {
	  return( NULL );
   }

   return( pDispatch );
}

void CTestContainer98Doc::SetPrimarySelection( LPDISPATCH pNewSelection )
{
   IUnknownPtr punkItem;
   IUnknownPtr punkNewSelection;
   POSITION posItem;
   CTestContainer98Item* pItem;

   if( pNewSelection == NULL )
   {
	  GetView()->ClearSelection();
   }
   else
   {
	  punkNewSelection = pNewSelection;
	  ASSERT( punkNewSelection != NULL );

	  posItem = GetStartPosition();
	  while( posItem != NULL )
	  {
		 pItem = (CTestContainer98Item*)GetNextItem( posItem );
		 punkItem = pItem->m_lpObject;
		 ASSERT( punkItem != NULL );

		 if( punkItem == punkNewSelection )
		 {
			GetView()->SetSelection( pItem );
			return;
		 }
	  }
   }
}

LPDISPATCH CTestContainer98Doc::FindControl( LPCTSTR pszName )
{
   POSITION posItem;
   CTestContainer98Item* pItem;
   IDispatch* pDispatch;
   HRESULT hResult;

   posItem = GetStartPosition();
   while( posItem != NULL )
   {
	  pItem = (CTestContainer98Item*)GetNextItem( posItem );
	  if( pItem->GetDisplayName() == pszName )
	  {
		 hResult = pItem->m_lpObject->QueryInterface( IID_IDispatch,
			(void**)&pDispatch );
		 if( FAILED( hResult ) )
		 {
			return( NULL );
		 }

		 return( pDispatch );
	  }
   }

	return( NULL );
}

void CTestContainer98Doc::OnToolsMacros()
{
   CMacroDlg dlg;
   int nResult;
   HRESULT hResult;
   CScriptManager* pScriptManager;

   pScriptManager = GetScriptManager();
   if( pScriptManager == NULL )
   {
	  return;
   }

   dlg.m_pScriptManager = m_pScriptManager;

   nResult = (int)dlg.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   hResult = dlg.m_pScript->RunMacro( dlg.m_strMacroName );
   if( FAILED( hResult ) )
   {
	  TRACE( "Script failed\n" );
	  return;
   }
}

HRESULT CTestContainer98Doc::InitScriptManager()
{
   POSITION posItem;
   CTestContainer98Item* pItem;
   IDispatchPtr pDispatch;

   m_pScriptManager = new CScriptManager( this );
   if( m_pScriptManager == NULL )
   {
	  return( E_OUTOFMEMORY );
   }

   posItem = GetStartPosition();
   while( posItem != NULL )
   {
	  pItem = (CTestContainer98Item*)GetNextItem( posItem );
	  pDispatch = pItem->m_lpObject;
	  if( pDispatch == NULL )
	  {
		 return( E_NOINTERFACE );
	  }
	  m_pScriptManager->AddNamedItem( pItem->GetDisplayName(), pDispatch );
   }

   return( S_OK );
}

void CTestContainer98Doc::Log( LPCTSTR pszMessage )
{
   CLog* pLog;

   pLog = GetLog();
   (*pLog)<<pszMessage;
}

void CTestContainer98Doc::FireOnNewControl( IDispatch* pControl )
{
   int iSink;
   IDispatch* pSink;
   COleDispatchDriver driver;

   const CPtrArray* pConnections = m_xTC98CP.GetConnections();
   ENSURE( pConnections != NULL );

   for( iSink = 0; iSink < pConnections->GetSize(); iSink++ )
   {
	  pSink = (IDispatch*)(pConnections->GetAt( iSink ));
	  ASSERT( pSink != NULL );

	  driver.AttachDispatch( pSink, FALSE );

	  try
	  {
		 driver.InvokeHelper( 1, DISPATCH_METHOD, VT_EMPTY, NULL, LPBYTE(
			VTS_DISPATCH ), pControl );
	  }
	  catch( CException* pException )
	  {
		 pException->Delete();
	  }
   }
}

BOOL CTestContainer98Doc::GetDispatchIID( IID* piid )
{
   ENSURE( piid != NULL );

   *piid = __uuidof( ITestContainer98 );

   return( TRUE );
}


BOOL CTestContainer98Doc::OnOpenDocument( LPCTSTR pszPathName )
{
   int iChar;

   ENSURE( pszPathName != NULL );

   iChar = lstrlen( pszPathName )-1;
   while( (iChar >= 0) && (pszPathName[iChar] != _T( '\\' )) )
   {
	  iChar--;
   }

   m_strDirectory = CString( pszPathName ).Left( iChar+1 );

	if( !COleDocument::OnOpenDocument( pszPathName ) )
   {
		return( FALSE );
   }

	return( TRUE );
}

CScriptManager* CTestContainer98Doc::GetScriptManager( BOOL tCreate )
{
   HRESULT hResult;

   if( m_pScriptManager == NULL )
   {
	  if( tCreate )
	  {
		 hResult = InitScriptManager();
		 if( FAILED( hResult ) )
		 {
			AfxMessageBox( IDS_NOSCRIPTING );
		 }
		 else
		 {
			ASSERT( m_pScriptManager != NULL );
		 }
	  }
   }

   return( m_pScriptManager );
}

void CTestContainer98Doc::OnRunMacro()
{
   CScript* pScript;
   CString strMacroName;
   CMainFrame* pMainFrame;
   CComboBox* pComboBox;
   HRESULT hResult;
   CScriptManager* pScriptManager;

   pScriptManager = GetScriptManager();
   if( pScriptManager == NULL )
   {
	  return;
   }

   pMainFrame = STATIC_DOWNCAST( CMainFrame, AfxGetMainWnd() );
   pComboBox = STATIC_DOWNCAST( CComboBox,
	  pMainFrame->m_wndMacroBar.GetDlgItem( IDC_MACRO ) );

   pComboBox->GetLBText( 0, strMacroName );
   TRACE( "Macro: %s\n", LPCTSTR( strMacroName ) );
   pScript = pScriptManager->FindMacro( strMacroName );
   if( pScript != NULL )
   {
	  hResult = pScript->RunMacro( strMacroName );
	  if( FAILED( hResult ) )
	  {
	  }
   }
}

void CTestContainer98Doc::RunAutomationScript(LPCTSTR szScriptFile)
{ 
	TRY
	{
		CScript * pScript = NULL;
		HRESULT hr = S_OK; 
		if(NULL == m_pScriptManager)
			InitScriptManager();

		hr = m_pScriptManager->LoadScript(szScriptFile, "RunTest");
		ASSERT(SUCCEEDED(hr));
		pScript = m_pScriptManager->FindMacro("RunTest");
		ENSURE(pScript);
		hr = pScript->RunMacro("RunTest");
		ASSERT(SUCCEEDED(hr));
	}
	CATCH(COleException, e)
	{
		char szErr[MAX_PATH];
		e->GetErrorMessage(szErr, MAX_PATH);
		AfxMessageBox(szErr);
	}
	END_CATCH
	
	AfxGetMainWnd()->PostMessage(WM_CLOSE);
}

BOOL CTestContainer98Doc::SaveModified()
{
	// TODO: Add your specialized code here and/or call the base class

	return TRUE;
}

