// File: ScrMngr.Cpp
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


IMPLEMENT_DYNAMIC( CScriptManager, CObject );

CScriptManager::CScriptManager( CTestContainer98Doc* pDoc ) :
   m_pDoc( pDoc )
{
   ASSERT( m_pDoc != NULL );
}

CScriptManager::~CScriptManager()
{
   CScript* pScript;
   IDispatch* pDispatch;
   POSITION posNamedItem;
   CString strItemName;

   while( !m_lpScripts.IsEmpty() )
   {
	  pScript = m_lpScripts.RemoveHead();
	  delete pScript;
   }

   posNamedItem = m_mapNamedItems.GetStartPosition();
   while( posNamedItem != NULL )
   {
	  m_mapNamedItems.GetNextAssoc( posNamedItem, strItemName, pDispatch );
	  pDispatch->Release();
   }
}

HRESULT CScriptManager::AddNamedItem( LPCTSTR pszItemName,
   IDispatch* pDispatch )
{

   POSITION posScript;
   CScript* pScript;
   HRESULT hResult;

   m_mapNamedItems.SetAt( pszItemName, pDispatch );
   pDispatch->AddRef();

   CT2COLE pszItemNameO( pszItemName );
   posScript = GetFirstScriptPosition();
   while( posScript != NULL )
   {
	  pScript = GetNextScript( posScript );
	  ENSURE( pScript != NULL );
	  hResult = pScript->AddNamedItem( pszItemName );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
   }

   return( S_OK );
}

HRESULT CScriptManager::AddNamedItems( IActiveScript* pScript )
{
   HRESULT hResult;
   POSITION posNamedItem;
   IDispatch* pDispatch;
   CString strItemName;
   BSTR bstrItemName;

   ENSURE( pScript != NULL );

   hResult = pScript->AddNamedItem( L"TCForm", SCRIPTITEM_ISVISIBLE|
	  SCRIPTITEM_ISSOURCE );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   posNamedItem = m_mapNamedItems.GetStartPosition();
   while( posNamedItem != NULL )
   {
	  m_mapNamedItems.GetNextAssoc( posNamedItem, strItemName, pDispatch );
	  bstrItemName = strItemName.AllocSysString();
	  hResult = pScript->AddNamedItem( bstrItemName, SCRIPTITEM_ISVISIBLE|
		 SCRIPTITEM_ISSOURCE );
	  SysFreeString( bstrItemName );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
   }

   return( S_OK );
}

CScript* CScriptManager::FindMacro( LPCTSTR pszMacroName )
{
   POSITION posScript;
   CScript* pScript;

   ASSERT( pszMacroName != NULL );

   posScript = GetFirstScriptPosition();
   while( posScript != NULL )
   {
	  pScript = GetNextScript( posScript );
	  if( pScript->FindMacro( pszMacroName ) )
	  {
		 return( pScript );
	  }
   }

   return( NULL );
}

POSITION CScriptManager::GetFirstScriptPosition() const
{
   return( m_lpScripts.GetHeadPosition() );
}

HRESULT CScriptManager::GetItemDispatch( LPCTSTR pszItemName,
   IUnknown** ppDispatch )
{
   IDispatch* pDispatch;
   BOOL tFound;

   ENSURE( pszItemName != NULL );
   ENSURE( ppDispatch != NULL );

   *ppDispatch = NULL;

   if( strcmp( pszItemName, "TCForm" ) == 0 )
   {
	  *ppDispatch = m_pDoc->GetIDispatch( TRUE );
	  return( S_OK );
   }
   else
   {
	  tFound = m_mapNamedItems.Lookup( pszItemName, pDispatch );
	  if( tFound )
	  {
		 *ppDispatch = pDispatch;
		 (*ppDispatch)->AddRef();
		 return( S_OK );
	  }
   }

   return( TYPE_E_ELEMENTNOTFOUND );
}

HRESULT CScriptManager::GetItemTypeInfo( LPCTSTR pszItemName,
   ITypeInfo** ppTypeInfo )
{
   IProvideClassInfoPtr pProvideClassInfo;
   IDispatch* pDispatch;
   HRESULT hResult;
   BOOL tFound;

   ENSURE( pszItemName != NULL );
   ENSURE( ppTypeInfo != NULL );

   *ppTypeInfo = NULL;

   if( strcmp( pszItemName, "TCForm" ) == 0 )
   {
	  hResult = m_pDoc->GetTypeInfoOfGuid( GetUserDefaultLCID(),
		 __uuidof( Document ), ppTypeInfo );
	  if( SUCCEEDED( hResult ) )
	  {
		 return( S_OK );
	  }
   }
   else
   {
	  tFound = m_mapNamedItems.Lookup( pszItemName, pDispatch );
	  if( tFound )
	  {
		 pProvideClassInfo = pDispatch;
		 if( pProvideClassInfo != NULL )
		 {
			hResult = pProvideClassInfo->GetClassInfo( ppTypeInfo );
			if( SUCCEEDED( hResult ) )
			{
			   return( S_OK );
			}
		 }
	  }
   }

   return( TYPE_E_ELEMENTNOTFOUND );
}

CScript* CScriptManager::GetNextScript( POSITION& posScript )
{
   return( m_lpScripts.GetNext( posScript ) );
}

int CScriptManager::GetNumScripts() const
{
   return( (int)m_lpScripts.GetCount() );
}

HRESULT CScriptManager::LoadScript( LPCTSTR pszFileName,
   LPCTSTR pszScriptName, CScript** ppScript )
{
   CScript* pScript;
   HRESULT hResult;
   POSITION posScript;

   ASSERT( pszFileName != NULL );
   ASSERT( pszScriptName != NULL );

   if( ppScript != NULL )
   {
	  *ppScript = NULL;
   }

   pScript = new CScript( this );
   if( pScript == NULL )
   {
	  return( E_OUTOFMEMORY );
   }

   posScript = m_lpScripts.AddHead( pScript );

   hResult = pScript->LoadScript( pszFileName, pszScriptName );
   if( FAILED( hResult ) )
   {
	  m_lpScripts.RemoveAt( posScript );
	  delete pScript;
	  return( hResult );
   }

   if( ppScript != NULL )
   {
	  *ppScript = pScript;
   }

   return( S_OK );
}
