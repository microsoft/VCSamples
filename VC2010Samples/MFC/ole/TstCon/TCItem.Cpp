// CTestContainer98Item.cpp : implementation of the CTestContainer98Item class
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
// CTestContainer98Item implementation

IMPLEMENT_SERIAL( CTestContainer98Item, COleClientItem, 0 )

CTestContainer98Item::CTestContainer98Item( CTestContainer98Doc* pContainer ) :
   COleClientItem( pContainer ),
   m_rect( 10, 10, 210, 210 ),
   m_dwEventCookie( 0 ),
   m_dwPropertyCookie( 0 ),
   m_tInsideOut( FALSE ),
   m_pDC( NULL ),
   m_tWindowless( FALSE ),
   m_tExtendedControl( FALSE ),
   m_tDisplayAsDefault( FALSE ),
   m_dwAspectPass2( DVASPECT_CONTENT )
{
   m_dpLastParams.cArgs = 0;
   m_dpLastParams.cNamedArgs = 0;
   m_dpLastParams.rgvarg = NULL;
   m_dpLastParams.rgdispidNamedArgs = NULL;

   m_tracker.m_nHandleSize = MARGIN_PIXELS+1;
   m_tracker.m_sizeMin.cx = 8;  // +MARGIN_PIXELS
   m_tracker.m_sizeMin.cy = 8;  // +MARGIN_PIXELS
   m_tracker.m_nStyle = CRectTracker::solidLine;
}

CTestContainer98Item::~CTestContainer98Item()
{
   ASSERT( m_pDC == NULL );

   CleanupParams();
}

IUnknown* CTestContainer98Item::GetInterfaceHook( const void* pv )
{
   const IID* piid;

#ifdef _DEBUG
   // The standard MFC implementation of QueryInterface doesn't switch module
   // states, since most objects just use static data to implement QI.  Since
   // we're calling GetDocument(), though, we wind up calling ASSERT_VALID on
   // a bunch of MFC objects, and that requires the correct module state.
   // Because ASSERT_VALID doesn't do anything in release builds, we only need
   // to switch module states in debug builds.
   AFX_MANAGE_STATE( m_pModuleState );
#endif  // _DEBUG

   piid = (const IID*)pv;

   if( *piid == m_infoEvents.GetIID() )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this, "QI for event handler.\n" );
	  return( &m_xEventHandler );
   }
   else if( *piid == IID_IOleInPlaceSiteEx )
   {
	  if( GetDocument()->SupportsInterface( IID_IOleInPlaceSiteEx ) )
	  {
		 TCControlTrace( TRACELEVEL_NORMAL, this,
			"QI for IOleInPlaceSiteEx.\n" );
		 return( &m_xOleInPlaceSiteWindowless );
	  }
   }
   else if( *piid == IID_IOleInPlaceSiteWindowless )
   {
	  if( GetDocument()->SupportsInterface( IID_IOleInPlaceSiteWindowless ) )
	  {
		 TCControlTrace( TRACELEVEL_NORMAL, this,
			"QI for IOleInPlaceSiteWindowless.\n" );
		 return( &m_xOleInPlaceSiteWindowless );
	  }
   }
   else if( *piid == IID_IAdviseSinkEx )
   {
	  if( GetDocument()->SupportsInterface( IID_IAdviseSinkEx ) )
	  {
		 TCControlTrace( TRACELEVEL_NORMAL, this, "QI for IAdviseSinkEx.\n" );
		 return( &m_xAdviseSinkEx );
	  }
   }

   return( NULL );
}

BOOL CTestContainer98Item::CreateFromClipboard( CArchive& ar,
   IStorage* pStorage )
{
   HRESULT hResult;
   CString strName;
   CLSID clsid;

   ASSERT( !ar.IsStoring() );
   ASSERT( pStorage != NULL );

   ar>>strName;
   ar>>m_rect;

   hResult = ReadClassStg( pStorage, &clsid );
   if( FAILED( hResult ) )
   {
	  return( FALSE );
   }

   return( CreateOrLoad( clsid, strName, IID_IStorage, pStorage ) );
}

BOOL CTestContainer98Item::CreateOrLoad( REFCLSID clsid, LPCTSTR pszName,
   REFIID iidPersistanceMedium, IUnknown* pPersistanceMedium )
{
   HRESULT hResult;
   BOOL tSuccess;
   BOOL tQuickActivated;
   IPersistStreamInitPtr pPersistStreamInit;
   IPersistStreamPtr pPersistStream;
   IPersistStoragePtr pPersistStorage;
   IStreamPtr pStream;
   IStoragePtr pStorage;

   ASSERT( m_lpObject == NULL );
   ASSERT( m_pDocument != NULL );

   m_dwItemNumber = GetNewItemNumber();
   GetItemStorage();
   ASSERT( m_lpStorage != NULL );

   m_tExtendedControl = TRUE;
   hResult = CExtendedControl::CreateInstance( clsid, this, NULL,
	  IID_IOleObject, (void**)&m_lpObject );
   if( FAILED( hResult ) )
   {
	  m_tExtendedControl = FALSE;
	  // The control may not like being aggregated on, so just try to create it
	  // directly and punt the extended control stuff.
	  hResult = CoCreateInstance( clsid, NULL, CLSCTX_INPROC_SERVER|
		CLSCTX_INPROC_HANDLER|CLSCTX_LOCAL_SERVER, IID_IOleObject,
		 (void**)&m_lpObject );
	  if( SUCCEEDED( hResult ) )
	  {
		 TCControlTrace( TRACELEVEL_NORMAL, this,
			"Could not aggregate on the control, so it won't support extended properties.\n" );
	  }
   }
   if( SUCCEEDED( hResult ) )
   {
	  CString strUserType;

	  if( pszName == NULL )
	  {
		 GetUserType( USERCLASSTYPE_SHORT, strUserType );
		 GetDocument()->CreateUniqueItemName( this, strUserType,
			m_strDisplayName );
	  }
	  else
	  {
		 GetDocument()->CreateUniqueItemName( this, pszName,
			m_strDisplayName );
	  }
   }

   if( m_tExtendedControl )
   {
	  CString strName;

	  strName = GetDisplayName();
	  m_pExtendedControl = m_lpObject;
	  ASSERT( m_pExtendedControl != NULL );
	  m_pExtendedControl->Name = _bstr_t( strName );
   }

   if( SUCCEEDED( hResult ) )
   {
	  hResult = InitControlInfo();
   }

   tQuickActivated = FALSE;
   if( SUCCEEDED( hResult ) )
   {
	  tQuickActivated = QuickActivate();

	  if( !tQuickActivated )
	  {
		 m_lpObject->GetMiscStatus( DVASPECT_CONTENT, &m_dwMiscStatus );
		 if( m_dwMiscStatus&OLEMISC_SETCLIENTSITEFIRST )
		 {
			hResult = m_lpObject->SetClientSite( GetClientSite() );
			if( FAILED( hResult ) )
			{
			   TCControlTrace( TRACELEVEL_NORMAL, this,
				  "SetClientSite failed.\n" );
			}
		 }
	  }
   }

   // Initialize or load the object's state.
   if( SUCCEEDED( hResult ) )
   {
	  if( iidPersistanceMedium == IID_NULL )
	  {
		 pPersistStreamInit = m_lpObject;
		 if( pPersistStreamInit != NULL )
		 {
			hResult = pPersistStreamInit->InitNew();
			if( hResult == E_NOTIMPL )
			{
			   // Not implementing InitNew is OK.
			   hResult = S_OK;
			}
		 }
		 else
		 {
			pPersistStorage = m_lpObject;
			if( pPersistStorage != NULL )
			{
			   hResult = pPersistStorage->InitNew( m_lpStorage );
			}
			else
			{
			// Assume the control doesn't care about persistance.
			   hResult = S_OK;
			}
		 }
	  }
	  else if( iidPersistanceMedium == IID_IStream )
	  {
		 pStream = pPersistanceMedium;
		 ASSERT( pStream != NULL );

		 pPersistStreamInit = m_lpObject;
		 if( pPersistStreamInit != NULL )
		 {
			hResult = pPersistStreamInit->Load( pStream );
		 }
		 else
		 {
			pPersistStream = m_lpObject;
			if( pPersistStream != NULL )
			{
			   hResult = pPersistStream->Load( pStream );
			}
			else
			{
			   hResult = E_NOINTERFACE;
			}
		 }
	  }
	  else if( iidPersistanceMedium == IID_IStorage )
	  {
		 pStorage = pPersistanceMedium;
		 ASSERT( pStorage != NULL );

		 pPersistStorage = m_lpObject;
		 if( pPersistStorage != NULL )
		 {
			hResult = pStorage->CopyTo( 0, NULL, NULL, m_lpStorage );
			if( SUCCEEDED( hResult ) )
			{
			   hResult = pPersistStorage->Load( m_lpStorage );
			}
		 }
		 else
		 {
			hResult = E_NOINTERFACE;
		 }
	  }
   }

   if( SUCCEEDED( hResult ) )
   {
	  if( !tQuickActivated )
	  {
		 if( !(m_dwMiscStatus&OLEMISC_SETCLIENTSITEFIRST) )
		 {
			hResult = m_lpObject->SetClientSite( GetClientSite() );
			if( FAILED( hResult ) )
			{
			   TCControlTrace( TRACELEVEL_NORMAL, this,
				  "SetClientSite failed.\n" );
			}
		 }
	  }
   }

   tSuccess = FinishCreate( hResult );

   return( tSuccess );
}

BOOL CTestContainer98Item::Create( REFCLSID clsid, LPCTSTR pszName )
{
   return( CreateOrLoad( clsid, pszName, IID_NULL, NULL ) );
}

void CTestContainer98Item::CleanupParams()
{
   UINT iArg;
   DISPPARAMS* pdpParams;

   ASSERT_VALID( this );

   pdpParams = &m_dpLastParams;
   if( pdpParams->rgvarg != NULL )
   {
	  for( iArg = 0; iArg < pdpParams->cArgs; iArg++ )
	  {
		 VariantClear( &pdpParams->rgvarg[iArg] );
	  }

	  delete[] (COleVariant*)pdpParams->rgvarg;
	  pdpParams->rgvarg = NULL;
   }

   if( pdpParams->rgdispidNamedArgs != NULL )
   {
	  delete[] pdpParams->rgdispidNamedArgs;
	  pdpParams->rgdispidNamedArgs = NULL;
   }
}

void CTestContainer98Item::CopyParams( DISPPARAMS* pdpParams )
{
   UINT iArg;

   if( pdpParams == NULL )
   {
	  return;  // Can't copy bogus params.
   }

   if( m_dpLastParams.cArgs > 0 )
   {
	  CleanupParams();
   }

   // Change state information about incoming.
   m_dpLastParams.cArgs = pdpParams->cArgs;
   if( pdpParams->cArgs == 0 )
   {
	  m_dpLastParams.rgvarg = NULL;
   }
   else
   {
	  m_dpLastParams.rgvarg = new COleVariant[pdpParams->cArgs];
   }

   m_dpLastParams.cNamedArgs = pdpParams->cNamedArgs;
   if( pdpParams->cNamedArgs == 0 )
   {
	  m_dpLastParams.rgdispidNamedArgs = NULL;
   }
   else
   {
	  m_dpLastParams.rgdispidNamedArgs = new DISPID[m_dpLastParams.cNamedArgs];
	  for( iArg = 0; iArg < m_dpLastParams.cNamedArgs; iArg++ )
	  {
		 m_dpLastParams.rgdispidNamedArgs[iArg] =
			pdpParams->rgdispidNamedArgs[iArg];
	  }
   }

   for( iArg = 0; iArg < m_dpLastParams.cArgs; iArg++ )
   {
	  HRESULT hr = VariantCopy( &m_dpLastParams.rgvarg[iArg], &pdpParams->rgvarg[iArg] );
	  if(FAILED(hr)) return; //not safe to continue
   }
}

class QAAMBIENTENTRY
{
public:
   DISPID dispid;
   DWORD dwQAFlag;
};

static const QAAMBIENTENTRY g_aQAAmbients[] =
{
   { DISPID_AMBIENT_SHOWHATCHING, QACONTAINER_SHOWHATCHING },
   { DISPID_AMBIENT_SHOWGRABHANDLES, QACONTAINER_SHOWGRABHANDLES },
   { DISPID_AMBIENT_USERMODE, QACONTAINER_USERMODE },
   { DISPID_AMBIENT_DISPLAYASDEFAULT, QACONTAINER_DISPLAYASDEFAULT },
   { DISPID_AMBIENT_UIDEAD, QACONTAINER_UIDEAD },
   { DISPID_AMBIENT_AUTOCLIP, QACONTAINER_AUTOCLIP },
   { DISPID_AMBIENT_MESSAGEREFLECT, QACONTAINER_MESSAGEREFLECT },
   { DISPID_AMBIENT_SUPPORTSMNEMONICS, QACONTAINER_SUPPORTSMNEMONICS }
};

const int NUM_QAAMBIENTS = sizeof( g_aQAAmbients )/sizeof( g_aQAAmbients[0] );

BOOL CTestContainer98Item::QuickActivate()
{
   HRESULT hResult;
   IQuickActivatePtr pQuickActivate;
   IDispatch* pFontDispatch;
   QACONTAINER qaContainer;
   QACONTROL qaControl;
   CTestContainer98Doc* pDoc;
   CAmbientProperty* pProperty;
   int iQAAmbient;

   pDoc = GetDocument();
   if( !pDoc->UseQuickActivation() )
   {
	  // The container doesn't want to use quick activation.
	  return( FALSE );
   }

   hResult = m_lpObject->QueryInterface( IID_IQuickActivate,
	  (void**)&pQuickActivate );
   if( FAILED( hResult ) )
   {
	  // The control doesn't support quick activation.
	  return( FALSE );
   }

   qaContainer.cbSize = sizeof( qaContainer );
   qaContainer.pClientSite = GetClientSite();
   qaContainer.pAdviseSink = NULL;
   qaContainer.pPropertyNotifySink = &m_xPropertyNotifySink;
   qaContainer.pUnkEventSink = &m_xEventHandler;
   qaContainer.dwAmbientFlags = 0;

   for( iQAAmbient = 0; iQAAmbient < NUM_QAAMBIENTS; iQAAmbient++ )
   {
	  pProperty = pDoc->FindAmbientProperty(
		 g_aQAAmbients[iQAAmbient].dispid );
	  if( pProperty != NULL )
	  {
		 ASSERT( pProperty->GetValue().vt == VT_BOOL );
		 if( pProperty->GetValue().bVal )
		 {
			qaContainer.dwAmbientFlags |= g_aQAAmbients[iQAAmbient].dwQAFlag;
		 }
	  }
   }

   qaContainer.colorFore = 0;
   pProperty = pDoc->FindAmbientProperty( DISPID_AMBIENT_FORECOLOR );
   if( pProperty != NULL )
   {
	  ASSERT( pProperty->GetValue().vt == VT_COLOR );
	  qaContainer.colorFore = pProperty->GetValue().lVal;
   }

   qaContainer.colorBack = 0;
   pProperty = pDoc->FindAmbientProperty( DISPID_AMBIENT_BACKCOLOR );
   if( pProperty != NULL )
   {
	  ASSERT( pProperty->GetValue().vt == VT_COLOR );
	  qaContainer.colorBack = pProperty->GetValue().lVal;
   }

   qaContainer.pFont = NULL;
   pProperty = pDoc->FindAmbientProperty( DISPID_AMBIENT_FONT );
   if( pProperty != NULL )
   {
	  ASSERT( pProperty->GetValue().vt == VT_DISPATCH );
	  pFontDispatch = pProperty->GetValue().pdispVal;
	  hResult = pFontDispatch->QueryInterface( IID_IFont,
		 (void**)&qaContainer.pFont );
	  ASSERT( SUCCEEDED( hResult ) );
   }

   qaContainer.pUndoMgr = NULL;

   qaContainer.dwAppearance = 0;
   pProperty = pDoc->FindAmbientProperty( DISPID_AMBIENT_APPEARANCE );
   if( pProperty != NULL )
   {
	  ASSERT( pProperty->GetValue().vt == VT_I4 );
	  qaContainer.dwAppearance = pProperty->GetValue().lVal;
   }

   qaContainer.lcid = 0;
   pProperty = pDoc->FindAmbientProperty( DISPID_AMBIENT_LOCALEID );
   if( pProperty != NULL )
   {
	  ASSERT( pProperty->GetValue().vt == VT_I4 );
	  qaContainer.lcid = pProperty->GetValue().lVal;
   }

   qaContainer.hpal = NULL;
   qaContainer.pBindHost = GetBindHost();

   memset( &qaControl, 0, sizeof( qaControl ) );
   qaControl.cbSize = sizeof( qaControl );

   hResult = pQuickActivate->QuickActivate( &qaContainer, &qaControl );
   if( FAILED( hResult ) )
   {
	  return( FALSE );
   }

   m_dwMiscStatus = qaControl.dwMiscStatus;
   m_dwViewStatus = qaControl.dwViewStatus;
   m_dwEventCookie = qaControl.dwEventCookie;
   m_dwPropertyCookie = qaControl.dwPropNotifyCookie;

   TCControlTrace( TRACELEVEL_NORMAL, this, "Quick activation successful.\n" );

   return( TRUE );
}

BOOL CTestContainer98Item::FinishCreate( HRESULT hr )
{
   BOOL tSuccess;
   IConnectionPointContainerPtr pCPContainer;
   HRESULT hResult;

   tSuccess = COleClientItem::FinishCreate( hr );
   if( !tSuccess )
   {
	  return( tSuccess );
   }

   hResult = m_lpObject->QueryInterface( IID_IOleControl,
	  (void**)&m_pOleControl );
   if( FAILED( hResult ) )
   {
	  // That's OK, it might not be a control
	  TCControlTrace( TRACELEVEL_NORMAL, this,
		 "Could not get object's IOleControl interface\n" );
   }

   hResult = m_lpObject->QueryInterface( IID_IConnectionPointContainer,
	  (void**)&pCPContainer );
   if( SUCCEEDED( hResult ) )
   {
	  if( m_dwEventCookie == 0 )
	  {
		 hResult = pCPContainer->FindConnectionPoint( m_infoEvents.GetIID(),
			&m_pEventCP );
		 if( SUCCEEDED( hResult ) )
		 {
			m_pEventCP->Advise( &m_xEventHandler, &m_dwEventCookie );
		 }
	  }

	  if( m_dwPropertyCookie == 0 )
	  {
		 hResult = pCPContainer->FindConnectionPoint( IID_IPropertyNotifySink,
			&m_pPropertyCP );
		 if( SUCCEEDED( hResult ) )
		 {
			m_pPropertyCP->Advise( &m_xPropertyNotifySink,
			   &m_dwPropertyCookie );
		 }
	  }
   }

   m_lpObject->GetMiscStatus( DVASPECT_CONTENT, &m_dwMiscStatus );
   if( m_dwMiscStatus&OLEMISC_INSIDEOUT )
   {
	  TCControlTrace( TRACELEVEL_VERBOSE, this, "Control is inside-out\n" );
	  m_tInsideOut = TRUE;
   }

   hResult = m_lpObject->QueryInterface( IID_IPointerInactive,
	  (void**)&m_pPointerInactive );
   if( SUCCEEDED( hResult ) )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this,
		 "Control supports IPointerInactive.\n" );
   }

   hResult = m_lpObject->QueryInterface( IID_IViewObjectEx,
	  (void**)&m_pViewObjectEx );
   if( SUCCEEDED( hResult ) )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this,
		 "Control supports IViewObjectEx.\n" );
	  m_pViewObjectEx->GetViewStatus( &m_dwViewStatus );
   }
   else
   {
	  m_dwViewStatus = 0;
   }

   UpdateFromServerExtent();

   // Activate the item if it wants to be active all the time.
   if( ShouldActivateWhenVisible() )
   {
	  if( GetDocument()->GetUserMode() && IsInvisibleAtRuntime() )
	  {
		 DoVerb( OLEIVERB_HIDE, GetDocument()->GetView() );
	  }
	  else
	  {
		 DoVerb( OLEIVERB_SHOW, GetDocument()->GetView() );
	  }
   }

   return( TRUE );
}

CString CTestContainer98Item::GetDisplayName()
{
   CString strName;

   if( m_pExtendedControl != NULL )
   {
	  strName = BSTR( m_pExtendedControl->Name );
   }
   else
   {
	  strName = m_strDisplayName;
   }

   return( strName );
}

HRESULT CTestContainer98Item::GetControlInfo()
{
   HRESULT hResult;

   m_infoControl.cb = sizeof( m_infoControl );
   m_infoControl.hAccel = NULL;
   m_infoControl.cAccel = 0;
   m_infoControl.dwFlags = 0;
   hResult = m_pOleControl->GetControlInfo( &m_infoControl );
   if( FAILED( hResult ) )
   {
	  if( hResult == E_NOTIMPL )
	  {
		 TCControlTrace( TRACELEVEL_NORMAL, this,
			"IOleControl::GetControlInfo() not implemented\n" );
	  }
	  else
	  {
		 return( hResult );
	  }
   }

   return( S_OK );
}

COleDataSource* CTestContainer98Item::OnGetClipboardData( BOOL tIncludeLink,
   LPPOINT pptOffset, LPSIZE pSize )
{
   COleDataSource* pSource;
   IStreamPtr pStream;
   HRESULT hResult;
   IPersistStreamInitPtr pPSI;
   ULONG nStringLength;
   CString strDisplayName;
   CLSID clsid;

   ASSERT_VALID( this );

   pSource = new COleDataSource;
   try
   {
	  hResult = CreateStreamOnHGlobal( NULL, TRUE, &pStream );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }
	  pPSI = m_lpObject;
	  if( pPSI == NULL )
	  {
		 AfxThrowOleException( E_NOINTERFACE );
	  }
	  strDisplayName = GetDisplayName();
	  nStringLength = strDisplayName.GetLength();
	  hResult = pStream->Write( &nStringLength, sizeof( ULONG ), NULL );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }
	  hResult = pStream->Write( LPCTSTR( strDisplayName ), nStringLength*
		 sizeof( TCHAR ), NULL );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  pPSI->GetClassID( &clsid );
	  hResult = WriteClassStm( pStream, clsid );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }
	  hResult = pPSI->Save( pStream, FALSE );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  LARGE_INTEGER nMove;

	  nMove.QuadPart = 0;
	  pStream->Seek( nMove, STREAM_SEEK_SET, NULL );

	  CLIPFORMAT cf = CLIPFORMAT( ::RegisterClipboardFormat( _T(
		 "TC98 Control" ) ) );
	  STGMEDIUM stgmedium;

	  stgmedium.tymed = TYMED_ISTREAM;
	  stgmedium.pstm = pStream;
	  stgmedium.pstm->AddRef();
	  stgmedium.pUnkForRelease = NULL;

	  pSource->CacheData( cf, &stgmedium );

	  GetClipboardData( pSource, tIncludeLink, pptOffset, pSize );
   }
   catch( ... )
   {
	  delete pSource;
	  throw;
   }

   ASSERT_VALID( pSource );

   return( pSource );
}

BOOL CTestContainer98Item::GetPropertyPageCLSIDs( CArray< CLSID,
   CLSID& >& aclsidPages )
{
   ISpecifyPropertyPagesPtr pSpecify;
   CAUUID pages;
   HRESULT hResult;
   ULONG iPage;
   CLSID clsid;

   pSpecify = m_lpObject;
   if( pSpecify != NULL )
   {
	  pages.cElems = 0;
	  pages.pElems = NULL;
	  hResult = pSpecify->GetPages( &pages );
	  if( FAILED( hResult ) )
	  {
		 TCControlTrace( TRACELEVEL_NORMAL, this,
			"ISpecifyPropertyPages::GetPages() failed\n" );
		 return( FALSE );
	  }

	  for( iPage = 0; iPage < pages.cElems; iPage++ )
	  {
		 aclsidPages.Add( pages.pElems[iPage] );
	  }

	  CoTaskMemFree( pages.pElems );
   }

   if( m_pExtendedControl != NULL )
   {
	  clsid = __uuidof( TCExtPage );
	  aclsidPages.Add( clsid );
   }

   return( TRUE );
}


HRESULT CTestContainer98Item::InitControlInfo()
{
   IProvideClassInfoPtr pPCI;
   ITypeInfoPtr pClassInfo;
   ITypeInfoPtr pTypeInfo;
   HRESULT hResult;
   UINT iType;
   int iFlags;
   HREFTYPE hRefType;
   BOOL tFoundDefaultSource;
   BOOL tFoundDefaultInterface;

   hResult = m_lpObject->QueryInterface( IID_IProvideClassInfo,
	  (void**)&pPCI );
   if( FAILED( hResult ) )
   {
	 TCControlTrace( TRACELEVEL_NORMAL, this,
		"Control doesn't support IProvideClassInfo" );
	  return( S_OK );
   }

   hResult = pPCI->GetClassInfo( &pClassInfo );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   CSmartTypeAttr pTypeAttr( pClassInfo );

   hResult = pClassInfo->GetTypeAttr( &pTypeAttr );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }
   ASSERT( pTypeAttr->typekind == TKIND_COCLASS );

   tFoundDefaultSource = FALSE;
   tFoundDefaultInterface = FALSE;
   for( iType = 0; (iType < pTypeAttr->cImplTypes) && !(tFoundDefaultSource &&
	  tFoundDefaultInterface); iType++ )
   {
	  hResult = pClassInfo->GetImplTypeFlags( iType, &iFlags );
	  if( SUCCEEDED( hResult ) )
	  {
		 if( (iFlags&IMPLTYPE_MASK) == IMPLTYPE_DEFAULTSOURCE )
		 {
			ASSERT( !tFoundDefaultSource );
			tFoundDefaultSource = TRUE;
			hResult = pClassInfo->GetRefTypeOfImplType( iType, &hRefType );
			if( FAILED( hResult ) )
			{
			   return( hResult );
			}
			hResult = pClassInfo->GetRefTypeInfo( hRefType, &pTypeInfo );
			if( FAILED( hResult ) )
			{
			   return( hResult );
			}
			TRACE( "Events:\n" );
			hResult = m_infoEvents.Init( pTypeInfo );
			if( FAILED( hResult ) )
			{
			   return( hResult );
			}
			pTypeInfo.Release();
		 }
		 else if( (iFlags&IMPLTYPE_MASK) == IMPLTYPE_DEFAULTINTERFACE )
		 {
			ASSERT( !tFoundDefaultInterface );
			tFoundDefaultInterface = TRUE;
			hResult = pClassInfo->GetRefTypeOfImplType( iType, &hRefType );
			if( FAILED( hResult ) )
			{
			   return( hResult );
			}
			hResult = pClassInfo->GetRefTypeInfo( hRefType, &pTypeInfo );
			if( FAILED( hResult ) )
			{
			   return( hResult );
			}
			TRACE( "Methods\n" );
			hResult = m_infoMethods.Init( pTypeInfo );
			if( FAILED( hResult ) )
			{
			   return( hResult );
			}
			pTypeInfo.Release();
		 }
	  }
   }
   if( !tFoundDefaultSource )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this,
		 "Could not find control's default source\n" );
   }
   if( !tFoundDefaultInterface )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this,
		 "Could not find control's default interface\n" );
	  return( E_FAIL );
   }

   return( S_OK );
}

BOOL CTestContainer98Item::IsInvisibleAtRuntime() const
{
   return( m_dwMiscStatus&OLEMISC_INVISIBLEATRUNTIME );
}

BOOL CTestContainer98Item::IsWindowless() const
{
   return( m_tWindowless );
}

BOOL CTestContainer98Item::SupportsIPointerInactive() const
{
   return( m_pPointerInactive != NULL );
}

BOOL CTestContainer98Item::OnWindowlessDragEnter( COleDataObject* pDataObject,
   DWORD dwKeyState, CPoint point, DWORD* pdwDropEffect )
{
   HRESULT hResult;
   POINTL pointl;

   TRACE( "OnWindowlessDragEnter()\n" );

   ENSURE( pdwDropEffect != NULL );
   *pdwDropEffect = DROPEFFECT_NONE;

   if( m_pDropTarget == NULL )
   {
	  // We haven't tried to drop on this control yet, or the control doesn't
	  // support IDropTarget.
	  hResult = m_pOleInPlaceObjectWindowless->GetDropTarget( &m_pDropTarget );
	  if( FAILED( hResult ) )
	  {
		 // The control doesn't support IDropTarget.
		 return( FALSE );
	  }
   }

   pointl.x = point.x;
   pointl.y = point.y;
   hResult = m_pDropTarget->DragEnter( pDataObject->m_lpDataObject, dwKeyState,
	  pointl, pdwDropEffect );
   ASSERT( SUCCEEDED( hResult ) );
   if( hResult == S_FALSE )
   {
	  // The control doesn't support any of the object's data formats.
	  return( FALSE );
   }

   return( TRUE );
}

void CTestContainer98Item::OnWindowlessDragLeave()
{
   HRESULT hResult;

   TRACE( "OnWindowlessDragLeave()\n" );

   ASSERT( m_pDropTarget != NULL );

   hResult = m_pDropTarget->DragLeave();
   ASSERT( SUCCEEDED( hResult ) );
}

void CTestContainer98Item::OnWindowlessDragOver( DWORD dwKeyState,
   CPoint point, DWORD* pdwDropEffect )
{
   HRESULT hResult;
   POINTL pointl;

   ENSURE( pdwDropEffect != NULL );
   *pdwDropEffect = DROPEFFECT_NONE;

   ASSERT( m_pDropTarget != NULL );

   pointl.x = point.x;
   pointl.y = point.y;
   hResult = m_pDropTarget->DragOver( dwKeyState, pointl, pdwDropEffect );
   ASSERT( SUCCEEDED( hResult ) );
}

void CTestContainer98Item::OnWindowlessDrop( COleDataObject* pDataObject,
   DWORD dwKeyState, CPoint point, DWORD* pdwDropEffect )
{
   HRESULT hResult;
   POINTL pointl;

   TRACE( "OnWindowlessDrop()\n" );

   ASSERT( m_pDropTarget != NULL );

   pointl.x = point.x;
   pointl.y = point.y;
   hResult = m_pDropTarget->Drop( pDataObject->m_lpDataObject, dwKeyState,
	  pointl, pdwDropEffect );
   ASSERT( SUCCEEDED( hResult ) );
}

BOOL CTestContainer98Item::ActsLikeButton() const
{
   return( m_dwMiscStatus&OLEMISC_ACTSLIKEBUTTON );
}

DWORD CTestContainer98Item::GetActivationPolicy() const
{
   DWORD dwPolicy;
   HRESULT hResult;

   ASSERT( m_pPointerInactive != NULL );
   ASSERT( !IsInPlaceActive() );

   hResult = m_pPointerInactive->GetActivationPolicy( &dwPolicy );
   if( FAILED( hResult ) )
   {
	  return( 0 );
   }

   return( dwPolicy );
}

DWORD CTestContainer98Item::OnPointerInactiveMove( CPoint point,
   DWORD dwKeyState )
{
   DWORD dwPolicy;

   ASSERT( m_pPointerInactive != NULL );
   ASSERT( !IsInPlaceActive() );

   dwPolicy = GetActivationPolicy();

   if( dwPolicy&POINTERINACTIVE_ACTIVATEONENTRY )
   {
	  return( dwPolicy );
   }

   m_pPointerInactive->OnInactiveMouseMove( &m_rect, point.x, point.y,
	  dwKeyState );

   return( 0 );
}

DWORD CTestContainer98Item::OnPointerInactiveSetCursor( CPoint point,
   DWORD dwMouseMessage, BOOL* ptHandled )
{
   HRESULT hResult;
   DWORD dwPolicy;

   ENSURE( ptHandled != NULL );
   *ptHandled = FALSE;

   ASSERT( m_pPointerInactive != NULL );
   ASSERT( !IsInPlaceActive() );

   dwPolicy = GetActivationPolicy();

   if( dwPolicy&POINTERINACTIVE_ACTIVATEONENTRY )
   {
	  return( dwPolicy );
   }

   hResult = m_pPointerInactive->OnInactiveSetCursor( &m_rect, point.x,
	  point.y, dwMouseMessage, FALSE );
   if( hResult == S_OK )
   {
	  *ptHandled = TRUE;
   }

   return( 0 );
}

void CTestContainer98Item::OnChange( OLE_NOTIFICATION nCode, DWORD dwParam )
{
	ASSERT_VALID( this );

	COleClientItem::OnChange( nCode, dwParam );

	// When an item is being edited (either in-place or fully open), it sends
   // OnChange notifications for changes in the state of the item or visual
   // appearance of its content.

   switch( nCode )
   {
   case OLE_CHANGED:
	  InvalidateItem();
	  // Check for valid m_lpViewObject since controls like Windows Media Player
	  // call IAdviseSink::OnViewChange before we're done initializing.
	  if (m_lpViewObject)
		  UpdateFromServerExtent();
	  break;

   case OLE_CHANGED_STATE:
   case OLE_CHANGED_ASPECT:
	  InvalidateItem();
	  break;
   }
}

BOOL CTestContainer98Item::OnChangeItemPosition( const CRect& rectPos )
{
	ASSERT_VALID( this );

	// During in-place activation CTestContainer98Item::OnChangeItemPosition
	//  is called by the server to change the position of the in-place
	//  window.  Usually, this is a result of the data in the server
	//  document changing such that the extent has changed or as a result
	//  of in-place resizing.
	//
	// The default here is to call the base class, which will call
	//  COleClientItem::SetItemRects to move the item
	//  to the new position.

	if( !COleClientItem::OnChangeItemPosition( rectPos ) )
   {
		return( FALSE );
   }

   InvalidateItem();
   m_rect = rectPos;
   InvalidateItem();

   // Mark document as dirty.
   GetDocument()->SetModifiedFlag();

	return( TRUE );
}

void CTestContainer98Item::OnGetClipRect( CRect& rectClip )
{
   ASSERT_VALID( this );

   rectClip = m_rect;
}

void CTestContainer98Item::OnGetItemPosition( CRect& rectPosition )
{
	ASSERT_VALID( this );

	// During in-place activation, CTestContainer98Item::OnGetItemPosition
	//  will be called to determine the location of this item.  The default
	//  implementation created from AppWizard simply returns a hard-coded
	//  rectangle.  Usually, this rectangle would reflect the current
	//  position of the item relative to the view used for activation.
	//  You can obtain the view by calling CTestContainer98Item::GetActiveView.

   rectPosition = m_rect;
}

void CTestContainer98Item::OnActivate()
{
   TCControlTrace( TRACELEVEL_NORMAL, this, "Activating control\n" );

   COleClientItem::OnActivate();

   UpdateStatusBar();
}

void CTestContainer98Item::OnActivateUI()
{
   CTestContainer98Item* pItem;
   CTestContainer98Doc* pDoc;
   POSITION posItem;

   TCControlTrace( TRACELEVEL_NORMAL, this, "UIActivating control\n" );

   // Allow only one UIActive item per frame.
   pDoc = GetDocument();
   posItem = pDoc->GetStartPosition();
   while( posItem != NULL )
   {
	  pItem = (CTestContainer98Item*)pDoc->GetNextItem( posItem );
	  if( pItem->IsUIActive() )
	  {
		 ASSERT( pItem != this );
		 pItem->DeactivateUI();
	  }
   }

//   GetActiveView()->SetSelection( this );

   COleClientItem::OnActivateUI();

   UpdateStatusBar();
}

void CTestContainer98Item::OnDeactivateUI( BOOL bUndoable )
{
   COleClientItem::OnDeactivateUI( bUndoable );

   TCControlTrace( TRACELEVEL_NORMAL, this, "UIDeactivating control\n" );

   // Also InPlaceDeactivate the object if it doesn't have the
   // ACTIVATEWHENVISIBLE flag set.
   if( !ShouldActivateWhenVisible() )
   {
	  Close();
   }

   UpdateStatusBar();
}

BOOL CTestContainer98Item::ShouldActivateWhenVisible()
{
   DWORD dwMiscStatus;

   dwMiscStatus = 0;
   m_lpObject->GetMiscStatus( GetDrawAspect(), &dwMiscStatus );

   if( !(dwMiscStatus&OLEMISC_ACTIVATEWHENVISIBLE) )
   {
	  return( FALSE );
   }

   if( (dwMiscStatus&OLEMISC_IGNOREACTIVATEWHENVISIBLE) &&
	  (GetDocument()->HonorIgnoreActivateWhenVisible()) )
   {
	  return( FALSE );
   }

   return( TRUE );
}

void CTestContainer98Item::Release( OLECLOSE dwCloseOption )
{
   UINT eState;
   IConnectionPointContainerPtr pConnectionPointContainer;
   HRESULT hResult;

   eState = GetItemState();
   if( (eState == activeUIState) || (eState == activeState) || (eState ==
	  openState) )
   {
	  Close( OLECLOSE_NOSAVE );
   }

   if( m_pDropTarget != NULL )
   {
	  m_pDropTarget.Release();
   }

   if( m_pPointerInactive != NULL )
   {
	  m_pPointerInactive.Release();
   }

   if( m_pOleInPlaceObjectWindowless != NULL )
   {
	  m_pOleInPlaceObjectWindowless.Release();
   }

   if( m_pViewObjectEx != NULL )
   {
	  m_pViewObjectEx.Release();
   }

   if( m_pOleControl != NULL )
   {
	  m_pOleControl.Release();
   }

   if( m_pCtlDispatch != NULL )
   {
	  m_pCtlDispatch.Release();
   }

   if( m_pExtendedControl != NULL )
   {
	  // Salvage the display name from the extended control before it goes
	  // away.
	  m_strDisplayName = BSTR( m_pExtendedControl->Name );
	  m_pExtendedControl.Release();
   }

   if( (m_lpObject != NULL) && ((m_dwEventCookie != 0) ||
	  (m_dwPropertyCookie != 0)) )
   {
	  m_lpObject->QueryInterface( IID_IConnectionPointContainer,
		 (void**)&pConnectionPointContainer );
   }

   if( m_dwEventCookie != 0 )
   {
	  if( m_pEventCP == NULL )
	  {
		 // We must have quick activated
		 hResult = pConnectionPointContainer->FindConnectionPoint(
			m_infoEvents.GetIID(), &m_pEventCP );
		 if( FAILED( hResult ) )
		 {
			TCControlTrace( TRACELEVEL_NORMAL, this,
			   "QuickActivated control connected to event sink, but doesn't support that connection point.\n" );
		 }
	  }
	  if( m_pEventCP != NULL )
	  {
		 m_pEventCP->Unadvise( m_dwEventCookie );
		 m_dwEventCookie = 0;
		 m_pEventCP.Release();
	  }
   }

   if( m_dwPropertyCookie != 0 )
   {
	  if( m_pPropertyCP == NULL )
	  {
		 // We must have quick activated
		 hResult = pConnectionPointContainer->FindConnectionPoint(
			IID_IPropertyNotifySink, &m_pPropertyCP );
		 if( FAILED( hResult ) )
		 {
			TCControlTrace( TRACELEVEL_NORMAL, this,
			   "QuickActivated control connected to property notify sink, but doesn't support that connection point.\n" );
		 }
	  }
	  if( m_pPropertyCP != NULL )
	  {
		 m_pPropertyCP->Unadvise( m_dwPropertyCookie );
		 m_dwPropertyCookie = 0;
		 m_pPropertyCP.Release();
	  }
   }

   if( pConnectionPointContainer != NULL )
   {
	  pConnectionPointContainer.Release();
   }

   COleClientItem::Release( dwCloseOption );

   CoFreeUnusedLibraries();
}

void CTestContainer98Item::CommitItem( BOOL bSuccess )
{
   IPersistStoragePtr pPersistStorage;

   if( !m_bNeedCommit )
   {
	  return;
   }

   if( (m_lpNewStorage != NULL) && !bSuccess )
   {
	  m_lpNewStorage->Release();
	  m_lpNewStorage = NULL;
   }

   pPersistStorage = m_lpObject;
   // If the object doesn't support IPersistStorage, then we used
   // IPersistStreamInit in a stream inside the storage.
   if( pPersistStorage != NULL )
   {
	  VERIFY( pPersistStorage->SaveCompleted( m_lpNewStorage ) == S_OK );
   }

   if( m_lpNewStorage != NULL )
   {
		m_lpStorage->Release();
		m_lpStorage = m_lpNewStorage;
		m_lpNewStorage = NULL;
   }

   m_bNeedCommit = FALSE;
}

void CTestContainer98Item::WriteItem( CArchive& ar )
{
   IStoragePtr pStorage;
   IStreamPtr pStream;
   IPersistStreamInitPtr pPSI;
   TCHAR szItemName[64];
   HRESULT hResult;
   IPersistStoragePtr pPersistStorage;
   CTestContainer98Doc* pDoc;
   CLSID clsid;

   (void)ar;

   pDoc = GetDocument();
   ENSURE( pDoc );
   ENSURE( pDoc->m_lpRootStg != NULL );
   ASSERT( pDoc->m_bCompoundFile );
   ASSERT( m_lpStorage != NULL );
   ASSERT( !ar.m_bForceFlat );

   GetItemName( szItemName, _countof(szItemName) );

   if( !pDoc->m_bSameAsLoad )
   {
	  hResult = pDoc->m_lpRootStg->CreateStorage( CT2COLE( szItemName ),
		 STGM_CREATE|STGM_READWRITE|STGM_TRANSACTED|STGM_SHARE_EXCLUSIVE, 0, 0,
		 &pStorage );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }
	  m_lpNewStorage = pStorage;
	  m_lpNewStorage->AddRef();
	  m_bNeedCommit = TRUE;
   }
   else
   {
	  pStorage = m_lpStorage;
   }

   pPersistStorage = m_lpObject;
   if( pPersistStorage != NULL )
   {
	  pPersistStorage->GetClassID( &clsid );
	  hResult = WriteClassStg( pStorage, clsid );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  hResult = pPersistStorage->Save( pStorage, pDoc->m_bSameAsLoad );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }
   }
   else
   {
	  pPSI = m_lpObject;
	  if( pPSI == NULL )
	  {
		 AfxThrowOleException( E_NOINTERFACE );
	  }

	  // Set the storage's CLSID to CLSID_NULL, so we know that we actually
	  // used a stream
	  hResult = WriteClassStg( pStorage, CLSID_NULL );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  hResult = pStorage->CreateStream( L"Contents", STGM_CREATE|
		 STGM_READWRITE|STGM_SHARE_EXCLUSIVE, 0, 0, &pStream );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  pPSI->GetClassID( &clsid );
	  hResult = WriteClassStm( pStream, clsid );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  hResult = pPSI->Save( pStream, TRUE );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  pStream.Release();
   }

   m_bNeedCommit = TRUE;
   pStorage->Commit( STGC_ONLYIFCURRENT );
}

void CTestContainer98Item::ReadItem( CArchive& ar )
{

   BOOL tUsedStream;
   IStoragePtr pStorage;
   IPersistStreamInitPtr pPSI;
   IStreamPtr pStream;
	TCHAR szItemName[64];
   HRESULT hResult;
   BOOL tQuickActivated;
   IPersistStoragePtr pPersistStorage;
   CLSID clsid;

   (void)ar;

	CTestContainer98Doc* pDoc = GetDocument();
	ENSURE(pDoc);
	ENSURE(pDoc->m_lpRootStg != NULL);
	ENSURE(pDoc->m_bCompoundFile);
	ASSERT(m_lpStorage == NULL);
	ASSERT(m_lpLockBytes == NULL);
   ASSERT( !ar.m_bForceFlat );

	// get item name
	GetItemName( szItemName, _countof(szItemName) );

	// open storage for this item
	hResult = pDoc->m_lpRootStg->OpenStorage( CT2COLE( szItemName ), NULL,
		STGM_READWRITE|STGM_TRANSACTED|STGM_SHARE_EXCLUSIVE, 0, 0, &pStorage );
	if( hResult != S_OK )
	{
		TRACE1( "Warning: unable to open child storage %s.\n", szItemName );
		// upon failure throw file exception (item will be cleaned up)
		AfxThrowOleException( hResult );
	}
	ASSERT(pStorage != NULL);

	// remember the storage
	m_lpStorage = pStorage;
	ASSERT(m_lpStorage != NULL);
   m_lpStorage->AddRef();

	// attempt to load the object from the storage

   hResult = ReadClassStg( m_lpStorage, &clsid );
   if( FAILED( hResult ) )
   {
	  AfxThrowOleException( hResult );
   }

   tUsedStream = FALSE;
   if( clsid == CLSID_NULL )
   {
	  hResult = m_lpStorage->OpenStream( L"Contents", NULL, STGM_READ|
		 STGM_SHARE_EXCLUSIVE, 0, &pStream );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  hResult = ReadClassStm( pStream, &clsid );
	  if( FAILED( hResult ) )
	  {
		 AfxThrowOleException( hResult );
	  }

	  tUsedStream = TRUE;
   }

   m_tExtendedControl = TRUE;
   hResult = CExtendedControl::CreateInstance( clsid, this, NULL,
	  IID_IOleObject, (void**)&m_lpObject );
   if( FAILED( hResult ) )
   {
	  m_tExtendedControl = FALSE;
	  // The control may not like being aggregated on, so just try to create it
	  // directly and punt the extended control stuff.
	  hResult = CoCreateInstance( clsid, NULL, CLSCTX_INPROC_SERVER|
		CLSCTX_INPROC_HANDLER|CLSCTX_LOCAL_SERVER, IID_IOleObject,
		(void**)&m_lpObject );
	  if( SUCCEEDED( hResult ) )
	  {
		 TCControlTrace( TRACELEVEL_NORMAL, this,
			"Could not aggregate on the control, so it won't support extended properties.\n" );
	  }
   }
   if( SUCCEEDED( hResult ) )
   {
	  CString strUserType;

	  GetUserType( USERCLASSTYPE_SHORT, strUserType );
	  GetDocument()->CreateUniqueItemName( this, strUserType,
		 m_strDisplayName );
   }

   if( m_tExtendedControl )
   {
	  m_pExtendedControl = m_lpObject;
	  ASSERT( m_pExtendedControl != NULL );
	  m_pExtendedControl->Name = _bstr_t( m_strDisplayName );
   }

   if( SUCCEEDED( hResult ) )
   {
	  hResult = InitControlInfo();
   }

   tQuickActivated = FALSE;
   if( SUCCEEDED( hResult ) )
   {
	  tQuickActivated = QuickActivate();

	  if( !tQuickActivated )
	  {
		 m_lpObject->GetMiscStatus( DVASPECT_CONTENT, &m_dwMiscStatus );
		 if( m_dwMiscStatus&OLEMISC_SETCLIENTSITEFIRST )
		 {
			hResult = m_lpObject->SetClientSite( GetClientSite() );
			if( FAILED( hResult ) )
			{
			   TCControlTrace( TRACELEVEL_NORMAL, this,
				  "SetClientSite failed.\n" );
			}
		 }
	  }
   }

   if( SUCCEEDED( hResult ) )
   {
	  pPersistStorage = m_lpObject;
	  if( pPersistStorage != NULL )
	  {
		 hResult = pPersistStorage->Load( m_lpStorage );
	  }
	 else
	 {
		if( !tUsedStream )
		{
		   hResult = E_NOINTERFACE;
		}
		else
		{
		   pPSI = m_lpObject;
		   if( pPSI == NULL )
		   {
			  hResult = E_NOINTERFACE;
		   }
		   else
		   {
			  hResult = pPSI->Load( pStream );
		   }
		}
	 }
   }

   if( SUCCEEDED( hResult ) )
   {
	  if( !tQuickActivated )
	  {
		 if( !(m_dwMiscStatus&OLEMISC_SETCLIENTSITEFIRST) )
		 {
			hResult = m_lpObject->SetClientSite( GetClientSite() );
			if( FAILED( hResult ) )
			{
			   TCControlTrace( TRACELEVEL_NORMAL, this,
				  "SetClientSite failed.\n" );
			}
		 }
	  }
   }

	CheckGeneral(hResult);
}

void CTestContainer98Item::CopyToClipboard( CArchive& ar, IStorage* pStorage )
{
   IPersistStoragePtr pPersistStorage;
   CLSID clsid;
   HRESULT hResult;

   ASSERT_VALID( this );
   ASSERT( ar.IsStoring() );

   ar<<GetDisplayName();
   ar<<m_rect;

   pPersistStorage = m_lpObject;
   if( pPersistStorage == NULL )
   {
	  AfxThrowOleException( E_NOINTERFACE );
   }

   pPersistStorage->GetClassID( &clsid );
   hResult = WriteClassStg( pStorage, clsid );
   if( FAILED( hResult ) )
   {
	  AfxThrowOleException( hResult );
   }

   hResult = pPersistStorage->Save( pStorage, FALSE );
   if( FAILED( hResult ) )
   {
	  AfxThrowOleException( hResult );
   }

   hResult = pPersistStorage->SaveCompleted( NULL );
   if( FAILED( hResult ) )
   {
	  AfxThrowOleException( hResult );
   }
}

void CTestContainer98Item::Serialize(CArchive& ar)
{
   CString strDisplayName;

	ASSERT_VALID( this );

   if( ar.IsStoring() )
   {
	  ar<<m_rect;
	  ar<<GetDisplayName();
   }
	else
	{
	  ar>>m_rect;
	  ar>>strDisplayName;
   }

	COleClientItem::Serialize( ar );

	if( !ar.IsStoring() )
	{
	  if( m_pExtendedControl != NULL )
	  {
		 m_pExtendedControl->Name = _bstr_t( strDisplayName );
	  }
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTestContainer98Item diagnostics

#ifdef _DEBUG
void CTestContainer98Item::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CTestContainer98Item::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////

IBindHost* CTestContainer98Item::GetBindHost()
{
   HRESULT hResult;

   if( m_pBindHost == NULL )
   {
	  hResult = CTCBindHost::CreateInstance( IID_IBindHost,
		 (void**)&m_pBindHost );
	  if( FAILED( hResult ) )
	  {
		 return( NULL );
	  }
   }
   ASSERT( m_pBindHost != NULL );

   return( m_pBindHost );
}

CInterfaceInfo* CTestContainer98Item::GetEventInfo()
{
   return( &m_infoEvents );
}

CInterfaceInfo* CTestContainer98Item::GetMethodInfo()
{
   return( &m_infoMethods );
}

void CTestContainer98Item::OnEvent( DISPID dispid, DISPPARAMS* pdpParams )
{
   CMethodInfo* pEventInfo;
   CLog* pLog;

   m_dispidEvent = dispid;
   CopyParams( pdpParams );

   pLog = GetDocument()->GetLog();
   if( pLog != NULL )
   {
	  // Find the event.
	  pEventInfo = m_infoEvents.FindMethod( m_dispidEvent );
	  if( pEventInfo == NULL )
	  {
		 (*pLog)<<GetDisplayName()<<_T( ": Unknown event (DISPID=" )<<dispid<<
			_T( ")\n" );
	  }
	  else
	  {
		 if( pEventInfo->IsLogged() )
		 {
			(*pLog)<<GetDisplayName()<<_T( ": " );
			pEventInfo->LogEvent( *pLog, pdpParams );
		 }
	  }
   }
}

void CTestContainer98Item::UpdateFromServerExtent()
{
   CSize size;

   if( GetCachedExtent( &size ) )
   {
	  // OLE returns the extent in HIMETRIC units -- we need pixels.
	  CClientDC dc( NULL );
	  dc.HIMETRICtoDP( &size );

	  // Only invalidate if it has actually changed and also only if it is not
	  // in-place active.
	  if( (size != m_rect.Size()) && !IsInPlaceActive() )
	  {
		 // Invalidate old, update, invalidate new.
		 InvalidateItem();
		 m_rect.bottom = m_rect.top+size.cy;
		 m_rect.right = m_rect.left+size.cx;
		 InvalidateItem();

		 // mark document as modified.
		 GetDocument()->SetModifiedFlag();
	  }
   }
}

void CTestContainer98Item::InvalidateItem()
{
   GetDocument()->UpdateAllViews( NULL, HINT_UPDATE_ITEM, this );
}

void CTestContainer98Item::SetLoggingOptions()
{
   CMethodInfo* pMethod;
   int iMethod;
   int iRequestEditProperty;
   int iBindableProperty;
   int nResult;
   CEventLoggingPage pageEventLogging;
   CPropertyChangesPage pagePropertyChanges;
   CPropertyEditRequestsPage pageEditRequests;
   CPropertySheet sheet( IDS_CONTROLLOGGINGOPTIONS );

   for( iMethod = 0; iMethod < m_infoEvents.GetNumMethods(); iMethod++ )
   {
	  pMethod = m_infoEvents.GetMethod( iMethod );
	  pageEventLogging.m_astrEventNames.Add( pMethod->GetName() );
	  pageEventLogging.m_atLogFlags.Add( pMethod->IsLogged() );
   }

   for( iMethod = 0; iMethod < m_infoMethods.GetNumMethods(); iMethod++ )
   {
	  pMethod = m_infoMethods.GetMethod( iMethod );
	  if( pMethod->GetInvokeKind() == INVOKE_PROPERTYGET )
	  {
		 if( pMethod->IsBindable() )
		 {
			pagePropertyChanges.m_astrPropertyNames.Add( pMethod->GetName() );
			pagePropertyChanges.m_atLogFlags.Add( pMethod->IsLogged() );
		 }
		 if( pMethod->RequestsEdit() )
		 {
			CPropertyEditRequestsPage::CPropertyInfo info( pMethod->GetName(),
			   pMethod->LogEditRequests(), pMethod->GetRequestEditResponse() );

			pageEditRequests.m_aProperties.Add( info );
		 }
	  }
   }

   sheet.AddPage( &pageEventLogging );
   sheet.AddPage( &pagePropertyChanges );
   sheet.AddPage( &pageEditRequests );

   sheet.m_psh.dwFlags &= ~PSH_HASHELP;
   sheet.m_psh.dwFlags |= PSH_NOAPPLYNOW;
   nResult = (int)sheet.DoModal();
   if( nResult != IDOK )
   {
	  return;
   }

   for( iMethod = 0; iMethod < m_infoEvents.GetNumMethods(); iMethod++ )
   {
	  pMethod = m_infoEvents.GetMethod( iMethod );
	  pMethod->EnableLogging( pageEventLogging.m_atLogFlags[iMethod] );
   }

   iBindableProperty = 0;
   iRequestEditProperty = 0;
   for( iMethod = 0; iMethod < m_infoMethods.GetNumMethods(); iMethod++ )
   {
	  pMethod = m_infoMethods.GetMethod( iMethod );
	  if( pMethod->GetInvokeKind() == INVOKE_PROPERTYGET )
	  {
		 if( pMethod->IsBindable() )
		 {
			pMethod->EnableLogging(
			   pagePropertyChanges.m_atLogFlags[iBindableProperty] );
			iBindableProperty++;
		 }
		 if( pMethod->RequestsEdit() )
		 {
			pMethod->EnableEditRequestLogging( pageEditRequests.m_aProperties[
			   iRequestEditProperty].m_tLogged );
			pMethod->SetRequestEditResponse( pageEditRequests.m_aProperties[
			   iRequestEditProperty].m_iResponse );
			iRequestEditProperty++;
		 }
	  }
   }
}

void CTestContainer98Item::InvokeMethods()
{
   HRESULT hResult;
   IDispatchPtr pDispatch;

   if( GetMethodInfo()->GetNumMethods() == 0 )
   {
	  AfxMessageBox( IDS_CONTROLHASNOMETHODS );
	  return;
   }

   hResult = m_lpObject->QueryInterface( IID_IDispatch, (void**)&pDispatch );
   if( FAILED( hResult ) )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this,
		 "Failed to get object's primary IDispatch interface.\n" );
	  return;
   }

   CMethodDlg dlg( NULL, pDispatch, &m_infoMethods );

   dlg.DoModal();
}

void CTestContainer98Item::OnFocus( BOOL tGotFocus )
{
   if( tGotFocus )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this, "Control got focus\n" );
   }
   else
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this, "Control lost focus\n" );
   }

   GetActiveView()->OnFocus( this, tGotFocus );
}

BEGIN_INTERFACE_MAP( CTestContainer98Item, COleClientItem )
   INTERFACE_PART( CTestContainer98Item, IID_IServiceProvider,
	  ServiceProvider )
   INTERFACE_PART( CTestContainer98Item, IID_IPropertyNotifySink,
	  PropertyNotifySink )
   INTERFACE_PART( CTestContainer98Item, IID_IDispatch, AmbientProperties )
   INTERFACE_PART( CTestContainer98Item, IID_IOleControlSite, OleControlSite )
//   INTERFACE_PART( CTestContainer98Item, IID_IOleInPlaceSiteEx,
//      OleInPlaceSiteWindowless )
//   INTERFACE_PART( CTestContainer98Item, IID_IOleInPlaceSiteWindowless,
//      OleInPlaceSiteWindowless )
END_INTERFACE_MAP()


///////////////////////////////////////////////////////////////////////////////
// CTestContainer98Item::XOleControlSite
///////////////////////////////////////////////////////////////////////////////

STDMETHODIMP_( ULONG ) CTestContainer98Item::XOleControlSite::AddRef()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   TCControlTrace( TRACELEVEL_NORMAL, pThis, "XOleControlSite::AddRef().\n" );

   return( pThis->ExternalAddRef() );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XOleControlSite::Release()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   TCControlTrace( TRACELEVEL_NORMAL, pThis, "XOleControlSite::Release().\n" );

   return( pThis->ExternalRelease() );
}

STDMETHODIMP CTestContainer98Item::XOleControlSite::QueryInterface( REFIID iid,
   LPVOID* ppvObj)
{
   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   return( pThis->ExternalQueryInterface( &iid, ppvObj ) );
}

STDMETHODIMP CTestContainer98Item::XOleControlSite::GetExtendedControl(
   IDispatch** ppExtendedControl )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   if( ppExtendedControl == NULL )
   {
	  return( E_POINTER );
   }

   *ppExtendedControl = pThis->m_pExtendedControl;
   if( *ppExtendedControl == NULL )
   {
	  return( E_NOTIMPL );
   }
   else
   {
	  (*ppExtendedControl)->AddRef();
   }

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleControlSite::LockInPlaceActive(
   BOOL tLock )
{
   (void)tLock;

   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   return( E_NOTIMPL );
}

STDMETHODIMP CTestContainer98Item::XOleControlSite::OnControlInfoChanged()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   return( E_NOTIMPL );
}

STDMETHODIMP CTestContainer98Item::XOleControlSite::OnFocus( BOOL tGotFocus )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   pThis->OnFocus( tGotFocus );

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleControlSite::ShowPropertyFrame()
{

   HRESULT hResult;
   ISpecifyPropertyPagesPtr pSpecify;
   CAUUID pages;
   CLSID* pclsidPages;
   ULONG nPages;
   ULONG iPage;
   IUnknown* pControl;
   CString strDisplayName;

   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   pControl = pThis->m_lpObject;
   pSpecify = pControl;
   if( pSpecify == NULL )
   {
	  return( E_NOINTERFACE );
   }

   pages.cElems = 0;
   pages.pElems = NULL;
   hResult = pSpecify->GetPages( &pages );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   nPages = pages.cElems;
   if( pThis->m_pExtendedControl != NULL )
   {
	  nPages++;
   }

   pclsidPages = (CLSID*)_malloca( nPages*sizeof( CLSID ) );
   for( iPage = 0; iPage < pages.cElems; iPage++ )
   {
	  pclsidPages[iPage] = pages.pElems[iPage];
   }
   if( pThis->m_pExtendedControl != NULL )
   {
	  pclsidPages[nPages-1] = __uuidof( TCExtPage );
   }
   CoTaskMemFree( pages.pElems );

   strDisplayName = pThis->GetDisplayName();
   hResult = OleCreatePropertyFrame( AfxGetMainWnd()->m_hWnd, 0, 0,
	  CT2COLE( strDisplayName ), 1, &pControl, nPages, pclsidPages,
	  GetUserDefaultLCID(), 0, NULL );

   _freea(pclsidPages);
   
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   //WINBUG: OleCreatePropertyFrame doesn't return focus to its parent when it
   // closes
   pThis->GetDocument()->GetView()->SetFocus();

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleControlSite::TransformCoords(
   POINTL* pptHiMetric, POINTF* pptContainer, DWORD dwFlags )
{
   (void)pptHiMetric;
   (void)pptContainer;
   (void)dwFlags;

   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   return( E_NOTIMPL );
}

STDMETHODIMP CTestContainer98Item::XOleControlSite::TranslateAccelerator(
   LPMSG pMessage, DWORD dwModifiers )
{
   (void)pMessage;
   (void)dwModifiers;

   METHOD_PROLOGUE( CTestContainer98Item, OleControlSite )

   return( E_NOTIMPL );
}


///////////////////////////////////////////////////////////////////////////////
// CTestContainer98Item::XServiceProvider
///////////////////////////////////////////////////////////////////////////////

STDMETHODIMP_( ULONG ) CTestContainer98Item::XServiceProvider::AddRef()
{
   METHOD_PROLOGUE( CTestContainer98Item, ServiceProvider )

   TCControlTrace( TRACELEVEL_NORMAL, pThis, "XServiceProvider::AddRef()\n" );

   return( pThis->ExternalAddRef() );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XServiceProvider::Release()
{
   METHOD_PROLOGUE( CTestContainer98Item, ServiceProvider )

   TCControlTrace( TRACELEVEL_NORMAL, pThis, "XServiceProvider::Release()\n" );

   return( pThis->ExternalRelease() );
}

STDMETHODIMP CTestContainer98Item::XServiceProvider::QueryInterface(
   REFIID iid, LPVOID* ppvObj)
{
   METHOD_PROLOGUE( CTestContainer98Item, ServiceProvider )

   return( pThis->ExternalQueryInterface( &iid, ppvObj ) );
}

STDMETHODIMP CTestContainer98Item::XServiceProvider::QueryService(
   REFGUID guidService, REFIID iid, void** ppService )
{
   IBindHost* pBindHost;

   METHOD_PROLOGUE( CTestContainer98Item, ServiceProvider );

   if( ppService == NULL )
   {
	  return( E_POINTER );
   }
   *ppService = NULL;

   if( IsEqualGUID( guidService, SID_SBindHost ) )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, pThis,
		 "QueryService for SID_SBindHost\n" );
	  if( !pThis->GetDocument()->SupportsService( guidService ) )
	  {
		 return( E_NOINTERFACE );
	  }
	  pBindHost = pThis->GetBindHost();
	  if( pBindHost == NULL )
	  {
		 return( E_NOINTERFACE );
	  }
	  else
	  {
		 return( pBindHost->QueryInterface( iid, ppService ) );
	  }
   }
   else
   {
	  TCControlTrace( TRACELEVEL_NORMAL, pThis,
		 "QueryService for unknown service\n" );
	  return( E_NOINTERFACE );
   }
}

///////////////////////////////////////////////////////////////////////////////
// CTestContainer98Item::XEventHandler
///////////////////////////////////////////////////////////////////////////////

STDMETHODIMP_( ULONG ) CTestContainer98Item::XEventHandler::AddRef()
{
   METHOD_PROLOGUE( CTestContainer98Item, EventHandler )

   TCControlTrace( TRACELEVEL_NORMAL, pThis, "XEventHandler::AddRef()\n" );

   return( pThis->ExternalAddRef() );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XEventHandler::Release()
{
   METHOD_PROLOGUE( CTestContainer98Item, EventHandler )

   TCControlTrace( TRACELEVEL_NORMAL, pThis, "XEventHandler::Release()\n" );

   return( pThis->ExternalRelease() );
}

STDMETHODIMP CTestContainer98Item::XEventHandler::QueryInterface( REFIID iid,
   LPVOID* ppvObj)
{
   METHOD_PROLOGUE( CTestContainer98Item, EventHandler )

   if( IsEqualIID( iid, IID_IDispatch ) )
   {
	  // QI'ing for IID_IDispatch will get you the default dispinterface on an
	  // object.  In the case of the control site, that would be the ambient
	  // properties dispinterface.  Since the control's event sink connection
	  // point is exposed not as IID_IDispatch, but rather as the IID of the
	  // control's event dispinterface,
	  TCControlTrace( TRACELEVEL_NORMAL, pThis,
		 "Warning: QI for IID_IDispatch on event handler interface.\n"
		 "\tDid you really mean to QI for your specific event interface?\n" );
   }

   return( pThis->ExternalQueryInterface( &iid, ppvObj ) );
}

STDMETHODIMP CTestContainer98Item::XEventHandler::GetIDsOfNames( REFIID iid,
   LPOLESTR* ppszNames, UINT nNames, LCID lcid, DISPID* pDispIDs )
{
   (void)iid;
   (void)ppszNames;
   (void)nNames;
   (void)lcid;
   (void)pDispIDs;

   METHOD_PROLOGUE( CTestContainer98Item, EventHandler )
   ASSERT_VALID( pThis );

   return( E_NOTIMPL );
}

STDMETHODIMP CTestContainer98Item::XEventHandler::GetTypeInfo( UINT iTypeInfo,
   LCID lcid, ITypeInfo** ppTypeInfo )
{
   (void)iTypeInfo;
   (void)lcid;
   (void)ppTypeInfo;

   METHOD_PROLOGUE( CTestContainer98Item, EventHandler )
   ASSERT_VALID( pThis );

   return( E_NOTIMPL );
}

STDMETHODIMP CTestContainer98Item::XEventHandler::GetTypeInfoCount(
   UINT* pnInfoCount )
{
   METHOD_PROLOGUE( CTestContainer98Item, EventHandler )
   ASSERT_VALID( pThis );

   *pnInfoCount = 0;

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XEventHandler::Invoke( DISPID dispidMember,
   REFIID iid, LCID lcid, USHORT wFlags, DISPPARAMS* pdpParams,
   VARIANT* pvarResult, EXCEPINFO* pExceptionInfo, UINT* piArgErr )
{
   (void)iid;
   (void)lcid;
   (void)wFlags;
   (void)pvarResult;
   (void)pExceptionInfo;
   (void)piArgErr;

   METHOD_PROLOGUE( CTestContainer98Item, EventHandler )
   ASSERT_VALID( pThis );

   pThis->OnEvent( dispidMember, pdpParams );  // Call the event handler, who
	  // also cleans up.

   return( S_OK );
}


///////////////////////////////////////////////////////////////////////////////
// CTestContainer98Item::XAmbientProperties
///////////////////////////////////////////////////////////////////////////////

STDMETHODIMP_( ULONG ) CTestContainer98Item::XAmbientProperties::AddRef()
{
   METHOD_PROLOGUE( CTestContainer98Item, AmbientProperties )

   TCControlTrace( TRACELEVEL_NORMAL, pThis,
	  "XAmbientProperties::AddRef().\n" );

   return( pThis->ExternalAddRef() );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XAmbientProperties::Release()
{
   METHOD_PROLOGUE( CTestContainer98Item, AmbientProperties )

   TCControlTrace( TRACELEVEL_NORMAL, pThis,
	  "XAmbientProperties::Release().\n" );

   return( pThis->ExternalRelease() );
}

STDMETHODIMP CTestContainer98Item::XAmbientProperties::QueryInterface(
   REFIID iid, LPVOID* ppvObj)
{
   METHOD_PROLOGUE( CTestContainer98Item, AmbientProperties )

   return( pThis->ExternalQueryInterface( &iid, ppvObj ) );
}

STDMETHODIMP CTestContainer98Item::XAmbientProperties::GetIDsOfNames(
   REFIID iid, LPOLESTR* ppszNames, UINT nNames, LCID lcid, DISPID* pDispIDs )
{
   CTestContainer98Doc* pDoc;
   CAmbientProperty* pProp;
   UINT iName;
   HRESULT hResult;

   (void)lcid;

   METHOD_PROLOGUE( CTestContainer98Item, AmbientProperties )
   ASSERT_VALID( pThis );

   if( !IsEqualIID( iid, IID_NULL ) )
   {
	  return( E_INVALIDARG );
   }
   if( ppszNames == NULL )
   {
	  return( E_INVALIDARG );
   }
   if( nNames < 1 )
   {
	  return( E_INVALIDARG );
   }
   if( pDispIDs == NULL )
   {
	  return( E_POINTER );
   }

   hResult = S_OK;
   pDoc = pThis->GetDocument();
   pProp = pDoc->FindAmbientProperty( ppszNames[0] );
   if( pProp == NULL )
   {
	  pDispIDs[0] = DISPID_UNKNOWN;
	  hResult = DISP_E_UNKNOWNNAME;
   }
   ENSURE( pProp != NULL );
   pDispIDs[0] = pProp->GetID();

   if( nNames > 1 )
   {
	  for( iName = 1; iName < nNames; iName++ )
	  {
		 pDispIDs[iName] = DISPID_UNKNOWN;
	  }
	  hResult = DISP_E_UNKNOWNNAME;
   }

   return( hResult );
}

STDMETHODIMP CTestContainer98Item::XAmbientProperties::GetTypeInfo(
   UINT iTypeInfo, LCID lcid, ITypeInfo** ppTypeInfo )
{
   (void)iTypeInfo;
   (void)lcid;
   (void)ppTypeInfo;

   METHOD_PROLOGUE( CTestContainer98Item, AmbientProperties )
   ASSERT_VALID( pThis );

   return( E_NOTIMPL );
}

STDMETHODIMP CTestContainer98Item::XAmbientProperties::GetTypeInfoCount(
   UINT* pnInfoCount )
{
   METHOD_PROLOGUE( CTestContainer98Item, AmbientProperties )
   ASSERT_VALID( pThis );

   *pnInfoCount = 0;

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XAmbientProperties::Invoke(
   DISPID dispidMember, REFIID iid, LCID lcid, WORD wFlags,
   DISPPARAMS* pdpParams, VARIANT* pvarResult, EXCEPINFO* pExceptionInfo,
   UINT* piArgErr )
{
   CTestContainer98Doc* pDoc;
   CAmbientProperty* pProp;
   HRESULT hResult;
   COleVariant varValue;

   (void)iid;
   (void)lcid;
   (void)wFlags;
   (void)pdpParams;
   (void)pExceptionInfo;
   (void)piArgErr;

   METHOD_PROLOGUE( CTestContainer98Item, AmbientProperties )
   ASSERT_VALID( pThis );

   if( dispidMember == DISPID_AMBIENT_DISPLAYASDEFAULT )
   {
	  VariantClear( pvarResult );
	  pvarResult->vt = VT_BOOL;
	  if( pThis->m_tDisplayAsDefault )
	  {
		 pvarResult->boolVal = VAR_TRUE;
	  }
	  else
	  {
		 pvarResult->boolVal = VAR_FALSE;
	  }

	  return( S_OK );
   }

   pDoc = pThis->GetDocument();

   pProp = pDoc->FindAmbientProperty( dispidMember );
   if( pProp == NULL )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, pThis,
		 "Control asked for unknown ambient property.  DISPID=%d\n",
		 dispidMember );
	  return( DISP_E_MEMBERNOTFOUND );
   }

   if( !pProp->IsEnabled() )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, pThis,
		 "Control asked for ambient property %s, but the property was disabled.\n",
		 LPCTSTR( pProp->GetName() ) );
	  return( DISP_E_MEMBERNOTFOUND );
   }

   TCControlTrace( TRACELEVEL_NORMAL, pThis,
	  "Control got ambient property %s.\n", LPCTSTR( pProp->GetName() ) );

   varValue = pProp->GetValue();
   hResult = VariantCopy( pvarResult, &varValue );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   return( S_OK );
}


///////////////////////////////////////////////////////////////////////////////
// CTestContainer98Item::XPropertyNotifySink
///////////////////////////////////////////////////////////////////////////////

STDMETHODIMP_( ULONG ) CTestContainer98Item::XPropertyNotifySink::AddRef()
{
   METHOD_PROLOGUE( CTestContainer98Item, PropertyNotifySink )

   TCControlTrace( TRACELEVEL_NORMAL, pThis,
	  "XPropertyNotifySink::AddRef().\n" );

   return( pThis->ExternalAddRef() );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XPropertyNotifySink::Release()
{
   METHOD_PROLOGUE( CTestContainer98Item, PropertyNotifySink )

   TCControlTrace( TRACELEVEL_NORMAL, pThis,
	  "XPropertyNotifySink::Release().\n" );

   return( pThis->ExternalRelease() );
}

STDMETHODIMP CTestContainer98Item::XPropertyNotifySink::QueryInterface(
   REFIID iid, LPVOID* ppvObj )
{
   METHOD_PROLOGUE( CTestContainer98Item, PropertyNotifySink )

   return( pThis->ExternalQueryInterface( &iid, ppvObj ) );
}

STDMETHODIMP CTestContainer98Item::XPropertyNotifySink::OnChanged(
   DISPID dispid )
{
   CMethodInfo* pPropertyInfo;
   CLog* pLog;

   METHOD_PROLOGUE( CTestContainer98Item, PropertyNotifySink )

   pLog = pThis->GetDocument()->GetLog();
   if( pLog != NULL )
   {
	  pPropertyInfo = pThis->m_infoMethods.FindPropertyGet( dispid );
	  if( pPropertyInfo == NULL )
	  {
		 (*pLog)<<pThis->GetDisplayName()<<_T(
			": Property Change: Unknown property (DISPID=" )<<dispid<<_T(
			")\n" );
	  }
	  else
	  {
		 if( pPropertyInfo->IsLogged() )
		 {
			(*pLog)<<pThis->GetDisplayName()<<_T( ": Property Change: " )<<
			   pPropertyInfo->GetName()<<_T( "\n" );
		 }
	  }
	}

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XPropertyNotifySink::OnRequestEdit(
   DISPID dispid )
{
   CMethodInfo* pPropertyInfo;
   CLog* pLog;
   CString strFormat;
   CString strPrompt;
   CString strUserType;
   int nResult;
   HRESULT hrResponse = S_FALSE;

   METHOD_PROLOGUE( CTestContainer98Item, PropertyNotifySink )

   pPropertyInfo = pThis->m_infoMethods.FindMethod( dispid );
   if( pPropertyInfo == NULL )
   {
	  hrResponse = S_OK;
   }
   else
   {
	  switch( pPropertyInfo->GetRequestEditResponse() )
	  {
	  case REQUESTEDIT_ALWAYS:
		 hrResponse = S_OK;
		 break;

	  case REQUESTEDIT_NEVER:
		 hrResponse = S_FALSE;
		 break;

	  case REQUESTEDIT_PROMPT:
		 AfxFormatString2( strPrompt, IDS_PROPERTYEDITREQUESTFORMAT,
			pPropertyInfo->GetName(), pThis->GetDisplayName() );
		 nResult = AfxMessageBox( strPrompt, MB_YESNO );
		 if( nResult == IDYES )
		 {
			hrResponse = S_OK;
		 }
		 else
		 {
			hrResponse = S_FALSE;
		 }
		 break;

	  default:
		 ASSERT( FALSE );
		 break;
	  }
   }

   pLog = pThis->GetDocument()->GetLog();
   if( pLog != NULL )
   {
	  if( pPropertyInfo == NULL )
	  {
		 (*pLog)<<pThis->GetDisplayName()<<_T(
			"Property Edit Request: Unknown property (DISPID=" )<<dispid<<_T(
			")\n" );
	  }
	  else
	  {
		 if( pPropertyInfo->LogEditRequests() )
		 {
			(*pLog)<<pThis->GetDisplayName()<<_T(
			   ": Property Edit Request: " )<<pPropertyInfo->GetName()<<_T(
			   " (" );
			if( hrResponse == S_OK )
			{
			   (*pLog)<<_T( "Allowed)\n" );
			}
			else
			{
			   (*pLog)<<_T( "Denied)\n" );
			}
		 }
	  }
   }

   return( hrResponse );
}

void CTestContainer98Item::DisplayAsDefault( BOOL tDefault )
{
   BOOL tOldDisplayAsDefault;

   ASSERT( ActsLikeButton() );

   tOldDisplayAsDefault = m_tDisplayAsDefault;
   m_tDisplayAsDefault = tDefault;

   if( (tOldDisplayAsDefault && !m_tDisplayAsDefault) ||
	  (!tOldDisplayAsDefault && m_tDisplayAsDefault) )
   {
	  // The default setting changed.
	  m_pOleControl->OnAmbientPropertyChange(
		 DISPID_AMBIENT_DISPLAYASDEFAULT );
   }
}

void CTestContainer98Item::FreezeEvents( BOOL tFreeze )
{
   if( m_pOleControl != NULL )
   {
	  m_pOleControl->FreezeEvents( tFreeze );
   }
}

BOOL CTestContainer98Item::IsInPlaceActive() const
{
   UINT eState;

   eState = GetItemState();

   return( (eState == activeState) || (eState == activeUIState) );
}

BOOL CTestContainer98Item::IsUIActive() const
{
   return( GetItemState() == activeUIState );
}

void CTestContainer98Item::OnAmbientPropertyChange( DISPID dispid )
{
   m_pOleControl->OnAmbientPropertyChange( dispid );
}

void CTestContainer98Item::OnDeselect()
{
   CWnd* pStatusBarWnd;
   CWnd* pFrameWnd;
   CMainFrame* pFrame;
   CStatusBar* pStatusBar;

   pFrameWnd = AfxGetMainWnd();
   pFrame = STATIC_DOWNCAST( CMainFrame, pFrameWnd );

   pStatusBarWnd = pFrame->GetMessageBar();
   pStatusBar = STATIC_DOWNCAST( CStatusBar, pStatusBarWnd );

   pStatusBar->SetPaneText( 1, _T( "" ) );
   pStatusBar->SetPaneText( 2, _T( "" ) );
}

void CTestContainer98Item::UpdateStatusBar()
{
   CWnd* pStatusBarWnd;
   CWnd* pFrameWnd;
   CMainFrame* pFrame;
   CStatusBar* pStatusBar;

   pFrameWnd = AfxGetMainWnd();
	 // No Active window yet
	 if (pFrameWnd != NULL) {
		 pFrame = STATIC_DOWNCAST( CMainFrame, pFrameWnd );

		 pStatusBarWnd = pFrame->GetMessageBar();
		 pStatusBar = STATIC_DOWNCAST( CStatusBar, pStatusBarWnd );

		 switch( GetItemState() )
		 {
		 case activeState:
			pStatusBar->SetPaneText( 1, _T( "Active" ) );
			if( m_tWindowless )
			{
			 pStatusBar->SetPaneText( 2, _T( "Windowless" ) );
			}
			else
			{
			 pStatusBar->SetPaneText( 2, _T( "Windowed" ) );
			}
			break;

		 case activeUIState:
			pStatusBar->SetPaneText( 1, _T( "UIActive" ) );
			if( m_tWindowless )
			{
			 pStatusBar->SetPaneText( 2, _T( "Windowless" ) );
			}
			else
			{
			 pStatusBar->SetPaneText( 2, _T( "Windowed" ) );
			}
			break;

		 case openState:
			pStatusBar->SetPaneText( 1, _T( "Open" ) );
			pStatusBar->SetPaneText( 2, _T( "" ) );
			break;

		 case loadedState:
			pStatusBar->SetPaneText( 1, _T( "Loaded" ) );
			pStatusBar->SetPaneText( 2, _T( "" ) );
			break;

		 case emptyState:
			pStatusBar->SetPaneText( 1, _T( "Empty" ) );
			pStatusBar->SetPaneText( 2, _T( "" ) );
			break;

		 default:
			ASSERT( FALSE );
			break;
		 }
	 }

}

void CTestContainer98Item::OnSelect()
{
   UpdateStatusBar();
}

BOOL CTestContainer98Item::HasUIActiveState() const
{
   DWORD dwMiscStatus;

   dwMiscStatus = 0;
   m_lpObject->GetMiscStatus( DVASPECT_CONTENT, &dwMiscStatus );

   return( !(dwMiscStatus&OLEMISC_NOUIACTIVATE) );
}

BOOL CTestContainer98Item::IsInsideOut() const
{
   return( m_tInsideOut );
}

void CTestContainer98Item::Move( const CRect& rect )
{
   BOOL tSizeChanged;
   CRect rectOld;
   CSize size;
   BOOL tSuccess;

   tSizeChanged = (rect.Size() != m_rect.Size());

   InvalidateItem();
   rectOld = m_rect;
   m_rect = rect;

   if( IsInPlaceActive() )
   {
	  SetItemRects();
   }

   if( tSizeChanged )
   {
	  CClientDC dc( NULL );

	  tSuccess = TRUE;
	  size = m_rect.Size();
	  dc.DPtoHIMETRIC( &size );
	  TRY
	  {
		 SetExtent( size );
	  }
	  CATCH( CException, e )
	  {
		 tSuccess = FALSE;
	  }
	  END_CATCH

	  if( !tSuccess )
	  {
		 m_rect = rectOld;
		 if( IsInPlaceActive() )
		 {
			SetItemRects();
		 }
	  }
   }

   InvalidateItem();
}

void CTestContainer98Item::Prepare()
{
   m_tracker.m_rect = m_rect;
   m_tracker.m_rect.InflateRect( MARGIN_PIXELS, MARGIN_PIXELS );

   if( m_pView->IsSelected( this ) )
   {
	  m_tracker.m_nStyle |= CRectTracker::resizeInside;
   }
   else
   {
	  m_tracker.m_nStyle &= ~CRectTracker::resizeInside;
   }

   if( (GetItemState() == openState) || (GetItemState() == activeUIState) )
   {
	  m_tracker.m_nStyle |= CRectTracker::hatchInside;
   }
   else
   {
	  m_tracker.m_nStyle &= ~CRectTracker::hatchInside;
   }
}

HRESULT CTestContainer98Item::SaveToPropertyBag( IPropertyBag* pPropertyBag )
{
   HRESULT hResult;
   IPersistPropertyBagPtr pPersistPropertyBag;

   ENSURE( pPropertyBag != NULL );
   ENSURE( m_lpObject != NULL );

   hResult = m_lpObject->QueryInterface( IID_IPersistPropertyBag,
	  (void**)&pPersistPropertyBag );
   if( FAILED( hResult ) )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, this,
		 "Control does not support IPersistPropertyBag.\n" );
	  return( hResult );
   }

   hResult = pPersistPropertyBag->Save( pPropertyBag, TRUE, TRUE );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   return( S_OK );
}

HRESULT CTestContainer98Item::SaveToStorage( IStorage* pStorage )
{
   HRESULT hResult;
   IPersistStoragePtr pPersistStorage;
   CLSID clsid;

   ASSERT( pStorage != NULL );
   ASSERT( m_lpObject != NULL );

   pPersistStorage = m_lpObject;
   if( pPersistStorage == NULL )
   {
	  return( E_NOINTERFACE );
   }

   pPersistStorage->GetClassID( &clsid );
   hResult = WriteClassStg( pStorage, clsid );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   hResult = pPersistStorage->Save( pStorage, FALSE );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   pPersistStorage->SaveCompleted( NULL );

   return( S_OK );
}

HRESULT CTestContainer98Item::SaveToStream( IStream* pStream )
{
   HRESULT hResult;
   IPersistStreamPtr pPersistStream;
   IPersistStreamInitPtr pPersistStreamInit;
   IPersistPtr pPersist;
   CLSID clsid;

   ENSURE( pStream != NULL );
   ENSURE( m_lpObject != NULL );

   hResult = m_lpObject->QueryInterface( IID_IPersist, (void**)&pPersist );
   if( FAILED( hResult ) )
   {
	  // Some control implementers forget that the IPersist* interfaces are all
	  // derived from IPersist.  If they forget to allow a QI for IPersist, let
	  // them know the error of their ways, and just go for IPersistStorage to
	  // get the IPersist interface.
	  TCControlTrace( TRACELEVEL_NORMAL, this,
		 "Object doesn't support IPersist.\n" );
	  hResult = m_lpObject->QueryInterface( IID_IPersistStorage,
		 (void**)&pPersist );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
   }

   pPersist->GetClassID( &clsid );
   hResult = WriteClassStm( pStream, clsid );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   hResult = m_lpObject->QueryInterface( IID_IPersistStream,
	  (void**)&pPersistStream );
   if( SUCCEEDED( hResult ) )
   {
	  hResult = pPersistStream->Save( pStream, TRUE );
   }
   else
   {
	  hResult = m_lpObject->QueryInterface( IID_IPersistStreamInit,
		 (void**)&pPersistStreamInit );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
	  hResult = pPersistStreamInit->Save( pStream, TRUE );
   }
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   return( S_OK );
}

DWORD CTestContainer98Item::HitTest( CPoint point )
{
   HRESULT hResult;
   IViewObjectExPtr pViewObjectEx;
   DWORD dwHitResult;

   if( m_lpObject == NULL )
   {
	   return( HITRESULT_OUTSIDE );
   }
   if( !m_rect.PtInRect( point ) )
   {
	  // Trivially reject the point.
	  return( HITRESULT_OUTSIDE );
   }

   hResult = m_lpObject->QueryInterface( IID_IViewObjectEx,
	  (void**)&pViewObjectEx );
   if( SUCCEEDED( hResult ) )
   {
	  hResult = pViewObjectEx->QueryHitPoint( DVASPECT_CONTENT, &m_rect, point,
		 0, &dwHitResult );
	  if( SUCCEEDED( hResult ) )
	  {
		 return( dwHitResult );
	  }
   }

   // If we got here, either the object doesn't support hit testing, or the hit
   // test call failed.  Since we would have rejected the point if it didn't
   // lie within the object's bounding rect, we know that the point lies within
   // the object.

   return( HITRESULT_HIT );
}

BOOL CTestContainer98Item::DrawFrontToBack( CDC* pDC, LPCRECT prectBounds )
{
   HRESULT hResult;
   RECTL rclBounds;
   RECTL* prclBounds;
   DWORD dwViewStatus;
   RECTL rclClip;
   CRect rectClip;
   CSize size;

   if( (m_lpObject == NULL) || (m_lpViewObject == NULL) )
   {
	  return( FALSE );
   }

   if( IsInPlaceActive() && !m_tWindowless )
   {
	  return( FALSE );
   }

   if( m_pViewObjectEx == NULL )
   {
	  // The control doesn't understand two-pass drawing, so just draw it on
	  // pass 2.
	  return( FALSE );
   }

   if( GetDocument()->GetUserMode() && IsInvisibleAtRuntime() )
   {
	  // We are invisible.
	  return( FALSE );
   }

   // convert RECT lpBounds to RECTL rclBounds
   rclBounds.left = prectBounds->left;
   rclBounds.top = prectBounds->top;
   rclBounds.right = prectBounds->right;
   rclBounds.bottom = prectBounds->bottom;

   if( m_tWindowless )
   {
	  prclBounds = NULL;
   }
   else
   {
	  prclBounds = &rclBounds;
   }

   // Assume that we won't be able to draw the first pass.
   m_dwAspectPass2 = DVASPECT_CONTENT;

   m_pViewObjectEx->GetViewStatus( &dwViewStatus );
   ASSERT( m_dwViewStatus == dwViewStatus );
   if( !(m_dwViewStatus&VIEWSTATUS_DVASPECTOPAQUE) )
   {
	  return( FALSE );
   }

   hResult = m_pViewObjectEx->GetRect( DVASPECT_OPAQUE, &rclClip );
   if( FAILED( hResult ) )
   {
	  return( FALSE );
   }

   hResult = m_lpViewObject->Draw( DVASPECT_OPAQUE, -1, NULL, NULL, NULL,
	  pDC->m_hDC, prclBounds, NULL, NULL, 0 );
   if( SUCCEEDED( hResult ) )
   {
	  // Just draw the transparent part in pass 2.
	  m_dwAspectPass2 = DVASPECT_TRANSPARENT;
   }

   size = CSize( rclClip.left, rclClip.top );
   pDC->HIMETRICtoDP( &size );
   rectClip.left = m_rect.left+size.cx;
   rectClip.top = m_rect.top+size.cy;
   size = CSize( rclClip.right, rclClip.bottom );
   pDC->HIMETRICtoDP( &size );
   rectClip.right = m_rect.left+size.cx;
   rectClip.bottom = m_rect.top+size.cy;
   pDC->ExcludeClipRect( &rectClip );

   return( TRUE );
}

BOOL CTestContainer98Item::DrawBackToFront( CDC* pDC, LPCRECT prectBounds )
{
   RECTL rclBounds;
   RECTL* prclBounds;
   DWORD dwViewStatus;

   if( (m_lpObject == NULL) || (m_lpViewObject == NULL) )
   {
	  return( FALSE );
   }

   if( GetDocument()->GetUserMode() && IsInvisibleAtRuntime() )
   {
	  // We are invisible.
	  return( FALSE );
   }

   if( IsInPlaceActive() && !m_tWindowless )
   {
	  return( FALSE );
   }

   // convert RECT lpBounds to RECTL rclBounds
   rclBounds.left = prectBounds->left;
   rclBounds.top = prectBounds->top;
   rclBounds.right = prectBounds->right;
   rclBounds.bottom = prectBounds->bottom;

   if( m_tWindowless )
   {
	  prclBounds = NULL;
   }
   else
   {
	  prclBounds = &rclBounds;
   }

   if( m_pViewObjectEx != NULL )
   {
	  m_pViewObjectEx->GetViewStatus( &dwViewStatus );
	  ASSERT( dwViewStatus == m_dwViewStatus );
   }
   else
   {
	  ASSERT( m_dwViewStatus == 0 );
   }

   if( (m_dwAspectPass2 == DVASPECT_TRANSPARENT)&&(m_dwViewStatus&
	  VIEWSTATUS_DVASPECTTRANSPARENT) )
   {
	  m_lpViewObject->Draw( DVASPECT_TRANSPARENT, -1, NULL, NULL, NULL,
		 pDC->m_hDC, prclBounds, NULL, NULL, 0 );
   }
   else if( m_dwAspectPass2 == DVASPECT_CONTENT )
   {
	  m_lpViewObject->Draw( DVASPECT_CONTENT, -1, NULL, NULL, NULL, pDC->m_hDC,
		 prclBounds, NULL, NULL, 0 );
   }

   return( TRUE );
}

BOOL CTestContainer98Item::Draw( CDC* pDC, LPCRECT prectBounds,
   DVASPECT nDrawAspect )
{
   RECTL rclBounds;
   RECTL* prclBounds;
   CRect rectClip;
   CSize size;

   if( (m_lpObject == NULL) || (m_lpViewObject == NULL) )
   {
	  return( FALSE );
   }

   if( GetDocument()->GetUserMode() && IsInvisibleAtRuntime() )
   {
	  // We are invisible.
	  return( FALSE );
   }

   // use current draw aspect if aspect is -1 (default)
   if( nDrawAspect == -1 )
   {
	  nDrawAspect = m_nDrawAspect;
   }

   // convert RECT lpBounds to RECTL rclBounds
   rclBounds.left = prectBounds->left;
   rclBounds.top = prectBounds->top;
   rclBounds.right = prectBounds->right;
   rclBounds.bottom = prectBounds->bottom;

   if( m_tWindowless )
   {
	  prclBounds = NULL;
   }
   else
   {
	  prclBounds = &rclBounds;
   }

   m_lpViewObject->Draw( DVASPECT_CONTENT, -1, NULL, NULL, NULL, pDC->m_hDC,
	  prclBounds, NULL, NULL, 0 );

   return( TRUE );
}

void CTestContainer98Item::OnDeactivate( BOOL tNoRedraw )
{
   TCControlTrace( TRACELEVEL_NORMAL, this, "Deactivating control\n" );

   if( m_tWindowless )
   {
	  if( GetActiveView()->GetItemWithFocus() == this )
	  {
		 GetActiveView()->OnWindowlessReleaseFocus();
	  }
	  m_tWindowless = FALSE;
	  m_pOleInPlaceObjectWindowless.Release();
   }

   if( !tNoRedraw )
   {
	  InvalidateItem();
   }

   COleClientItem::OnDeactivate();

   UpdateStatusBar();
}

void CTestContainer98Item::OnDeactivate()
{
   OnDeactivate( FALSE );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XOleInPlaceSiteWindowless::
   AddRef()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless )

   TCControlTrace( TRACELEVEL_NORMAL, pThis,
	  "XOleInPlaceSiteWindowless::AddRef().\n" );

   return( pThis->ExternalAddRef() );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XOleInPlaceSiteWindowless::
   Release()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless )

   TCControlTrace( TRACELEVEL_NORMAL, pThis,
	  "XOleInPlaceSiteWindowless::Release().\n" );

   return( pThis->ExternalRelease() );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::QueryInterface(
   REFIID iid, LPVOID* ppvObj )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless )

   return( pThis->ExternalQueryInterface( &iid, ppvObj ) );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   ContextSensitiveHelp( BOOL tEnterMode )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.ContextSensitiveHelp( tEnterMode ) );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::GetWindow(
   HWND* phWnd )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.GetWindow( phWnd ) );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   CanInPlaceActivate()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.CanInPlaceActivate() );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   DeactivateAndUndo()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.DeactivateAndUndo() );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   DiscardUndoState()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.DiscardUndoState() );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::GetWindowContext(
   IOleInPlaceFrame** ppFrame, IOleInPlaceUIWindow** ppDoc, LPRECT prectPos,
   LPRECT prectClip, LPOLEINPLACEFRAMEINFO pFrameInfo )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.GetWindowContext( ppFrame, ppDoc, prectPos,
	  prectClip, pFrameInfo ) );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   OnInPlaceActivate()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.OnInPlaceActivate() );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   OnInPlaceDeactivate()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.OnInPlaceDeactivate() );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::OnPosRectChange(
   LPCRECT prectPos )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.OnPosRectChange( prectPos ) );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless:: OnUIActivate()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.OnUIActivate() );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::OnUIDeactivate(
   BOOL tUndoable )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.OnUIDeactivate( tUndoable ) );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::Scroll(
   SIZE sizeExtent )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->m_xOleIPSite.Scroll( sizeExtent ) );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   OnInPlaceActivateEx( BOOL* ptNoRedraw, DWORD dwFlags )
{
   HRESULT hResult;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   ASSERT( ptNoRedraw != NULL );

   ASSERT( pThis->m_tWindowless == FALSE );

   if( dwFlags&ACTIVATE_WINDOWLESS )
   {
	  pThis->m_tWindowless = TRUE;
	  hResult = pThis->m_lpObject->QueryInterface(
		 IID_IOleInPlaceObjectWindowless,
		 (void**)&pThis->m_pOleInPlaceObjectWindowless );
	  ASSERT( SUCCEEDED( hResult ) );
   }

   hResult = pThis->m_xOleIPSite.OnInPlaceActivate();
   if( FAILED( hResult ) )
   {
      return( hResult );
   }

   if( ptNoRedraw != NULL )
   {
      ASSERT( pThis->GetActiveView() != NULL );
	  if( pThis->GetActiveView()->GetUpdateRect( NULL ) )
	  {
		 *ptNoRedraw = FALSE;
	  }
	  else
	  {
		 *ptNoRedraw = TRUE;
	  }
   }

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   OnInPlaceDeactivateEx( BOOL tNoRedraw )
{
   (void)tNoRedraw;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   pThis->OnDeactivate( tNoRedraw );

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::RequestUIActivate()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::AdjustRect(
   LPRECT prect )
{
   (void)prect;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( E_NOTIMPL );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   CanWindowlessActivate()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   TCControlTrace( TRACELEVEL_NORMAL, pThis,
	  "Control wants to be windowless.\n" );
   if( pThis->GetDocument()->CanWindowlessActivate() )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, pThis,
		 "Windowless activation is allowed.\n" );
	  return( S_OK );
   }
   else
   {
	  TCControlTrace( TRACELEVEL_NORMAL, pThis,
		 "You'll create a window and like it.\n" );
	  return( S_FALSE );
   }
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::GetCapture()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   if( pThis->GetActiveView()->GetItemWithCapture() == pThis )
   {
	  return( S_OK );
   }
   else
   {
	  return( S_FALSE );
   }
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::GetDC(
   LPCRECT prect, DWORD dwFlags, HDC* phDC )
{
   CView* pView;
   CRgn rgn;
   CRect rect;

   (void)dwFlags;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   ENSURE( phDC != NULL );
   *phDC = NULL;

   if( pThis->m_pDC != NULL )
   {
	  return( E_FAIL );
   }

   pView = pThis->GetActiveView();
   ENSURE( pView != NULL );

   pThis->m_pDC = pView->GetDC();
   if( pThis->m_pDC == NULL )
   {
	  return( E_FAIL );
   }

   if( prect == NULL )
   {
	  // The clipping rectangle is the object's extent rectangle.
	  rect = pThis->m_rect;
   }
   else
   {
	  // The clipping rectangle is the object's extent rectangle intersected
	  // with the rectangle requested by the object.
	  rect.IntersectRect( &pThis->m_rect, prect );
   }

   rgn.CreateRectRgnIndirect( &rect );
   pThis->m_pDC->SelectClipRgn( &rgn, RGN_AND );

   *phDC = pThis->m_pDC->GetSafeHdc();

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::GetFocus()
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   if( pThis->GetActiveView()->GetItemWithFocus() == pThis )
   {
	  return( S_OK );
   }
   else
   {
	  return( S_FALSE );
   }
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::InvalidateRect(
   LPCRECT prect, BOOL tErase )
{
   CRect rect;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   if( prect == NULL )
   {
	  rect = pThis->m_rect;
   }
   else
   {
	  // Intersect the given rectangle with the bounds of the object.
	  rect.IntersectRect( prect, &pThis->m_rect );

	  if( rect != *prect )
	  {
		 TCControlTrace( TRACELEVEL_NORMAL, pThis,
			"Object tried to invalidate pixels outside its bounds.\n" );
	  }
   }

   if( !rect.IsRectEmpty() )
   {
	  pThis->GetActiveView()->InvalidateRect( &rect, tErase );
	  pThis->GetActiveView()->UpdateWindow();
   }

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::InvalidateRgn(
   HRGN hRgn, BOOL tErase )
{
   CRgn rgn;
   CRgn* pRgn;
   CRect rectRgn;
   CRect rect;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   if( hRgn == NULL )
   {
	  // The object wants its full extent invalidated.  It's much easier to do
	  // this with a rect than a region.
	  return( InvalidateRect( NULL, tErase ) );
   }

   pRgn = CRgn::FromHandle( hRgn );
   pRgn->GetRgnBox( &rectRgn );
   rect.IntersectRect( &rectRgn, &pThis->m_rect );
   if( rect != rectRgn )
   {
	  TCControlTrace( TRACELEVEL_NORMAL, pThis,
		 "Object tried to invalidate pixels outside its bounds.\n" );
	  return( InvalidateRect( NULL, tErase ) );
   }

   pThis->GetActiveView()->InvalidateRgn( pRgn, tErase );

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::
   OnDefWindowMessage( UINT nMessage, WPARAM wParam, LPARAM lParam,
   LRESULT* plResult )
{
   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( pThis->GetActiveView()->OnWindowlessDefWindowMessage( nMessage,
	  wParam, lParam, plResult ) );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::ReleaseDC(
   HDC hDC )
{
   CView* pView;

   UNUSED( hDC );

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   pView = pThis->GetActiveView();
   ENSURE( pView != NULL );

   ASSERT( hDC == pThis->m_pDC->GetSafeHdc() );

   pView->ReleaseDC( pThis->m_pDC );

   pThis->m_pDC = NULL;

   return( S_OK );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::ScrollRect(
   int dx, int dy, LPCRECT prectScroll, LPCRECT prectClip )
{
   (void)dx;
   (void)dy;
   (void)prectScroll;
   (void)prectClip;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   return( E_NOTIMPL );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::SetCapture(
   BOOL tCapture )
{
   HRESULT hResult;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   if( tCapture )
   {
	  hResult = pThis->GetActiveView()->OnWindowlessSetCapture( pThis );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
   }
   else
   {
	  hResult = pThis->GetActiveView()->OnWindowlessReleaseCapture( pThis );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
   }

   return( hResult );
}

STDMETHODIMP CTestContainer98Item::XOleInPlaceSiteWindowless::SetFocus(
   BOOL tFocus )
{
   HRESULT hResult;

   METHOD_PROLOGUE( CTestContainer98Item, OleInPlaceSiteWindowless );

   if( tFocus )
   {
	  hResult = pThis->GetActiveView()->OnWindowlessSetFocus( pThis );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
   }
   else
   {
	  hResult = pThis->GetActiveView()->OnWindowlessReleaseFocus();
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
   }

   return( hResult );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XAdviseSinkEx::AddRef()
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx )

   TCControlTrace( TRACELEVEL_NORMAL, pThis, "XAdviseSinkEx::AddRef().\n" );

   return( pThis->ExternalAddRef() );
}

STDMETHODIMP_( ULONG ) CTestContainer98Item::XAdviseSinkEx::Release()
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx )

   TCControlTrace( TRACELEVEL_NORMAL, pThis, "XAdviseSinkEx::Release().\n" );

   return( pThis->ExternalRelease() );
}

STDMETHODIMP CTestContainer98Item::XAdviseSinkEx::QueryInterface( REFIID iid,
   LPVOID* ppvObj )
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx )

   return( pThis->ExternalQueryInterface( &iid, ppvObj ) );
}

void CTestContainer98Item::XAdviseSinkEx::OnClose()
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx );

   pThis->m_xAdviseSink.OnClose();
}

void CTestContainer98Item::XAdviseSinkEx::OnDataChange( FORMATETC* pFormatEtc,
   STGMEDIUM* pStgMedium )
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx );

   pThis->m_xAdviseSink.OnDataChange( pFormatEtc, pStgMedium );
}

void CTestContainer98Item::XAdviseSinkEx::OnRename( IMoniker* pMoniker )
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx );

   pThis->m_xAdviseSink.OnRename( pMoniker );
}

void CTestContainer98Item::XAdviseSinkEx::OnSave()
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx );

   pThis->m_xAdviseSink.OnSave();
}

void CTestContainer98Item::XAdviseSinkEx::OnViewChange( DWORD dwAspect,
   LONG lindex )
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx );

   pThis->m_xAdviseSink.OnViewChange( dwAspect, lindex );
}

void CTestContainer98Item::XAdviseSinkEx::OnViewStatusChange(
   DWORD dwViewStatus )
{
   METHOD_PROLOGUE( CTestContainer98Item, AdviseSinkEx );

   TRACE( "IAdviseSinkEx::OnViewStatusChange()\n" );

   ASSERT( pThis->m_pViewObjectEx != NULL );

   pThis->m_dwViewStatus = dwViewStatus;
}

BOOL CTestContainer98Item::OnWindowMessage( const MSG* pMessage )
{
   LRESULT lResult;
   HRESULT hResult;

   hResult = m_pOleInPlaceObjectWindowless->OnWindowMessage( pMessage->message,
	  pMessage->wParam, pMessage->lParam, &lResult );
   if( hResult == S_OK )
   {
	  return( TRUE );
   }
   else
   {
	  return( FALSE );
   }
}
