// File: MethInfo.Cpp
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

CMethodParamInfo::CMethodParamInfo() :
   m_vt( VT_EMPTY )
{
}

CMethodParamInfo::~CMethodParamInfo()
{
}

CString CMethodParamInfo::GetName() const
{
   return( m_strName );
}

VARTYPE CMethodParamInfo::GetType() const
{
   return( m_vt );
}

HRESULT CMethodParamInfo::Init( LPCOLESTR pszName, const ELEMDESC* pElemDesc )
{
   m_strName = pszName;
   m_vt = pElemDesc->tdesc.vt;

   return( S_OK );
}


CMethodInfo::CMethodInfo() :
   m_tLog( TRUE ),
   m_tLogEditRequests( TRUE ),
   m_eRequestEditResponse( REQUESTEDIT_ALWAYS )
{
}

CMethodInfo::~CMethodInfo()
{
   int iParam;

   for( iParam = 0; iParam < m_apParamInfo.GetSize(); iParam++ )
   {
	  delete m_apParamInfo[iParam];
   }
}

void CMethodInfo::EnableEditRequestLogging( BOOL tEnable )
{
   m_tLogEditRequests = tEnable;
}

void CMethodInfo::EnableLogging( BOOL tEnable )
{
   m_tLog = tEnable;
}

DISPID CMethodInfo::GetID() const
{
   return( m_dispid );
}

INVOKEKIND CMethodInfo::GetInvokeKind() const
{
   return( m_invkind );
}

CString CMethodInfo::GetName() const
{
   return( m_strName );
}

int CMethodInfo::GetNumParams() const
{
   return( (int)m_apParamInfo.GetSize() );
}

CMethodParamInfo* CMethodInfo::GetParam( int iParam ) const
{
   return( m_apParamInfo[iParam] );
}

int CMethodInfo::GetRequestEditResponse() const
{
   return( m_eRequestEditResponse );
}

HRESULT CMethodInfo::Init( ITypeInfo* pTypeInfo, const FUNCDESC* pFuncDesc )
{

   USES_CONVERSION_EX;
   HRESULT hResult;
   UINT nNames;
   int iParam;
   UINT iName;
   LPCOLESTR pszParamName;
   CString strPropertyValue;

   ENSURE( pTypeInfo != NULL );
   ENSURE( pFuncDesc != NULL );

   m_dispid = pFuncDesc->memid;
   m_invkind = pFuncDesc->invkind;
   m_tBindable = pFuncDesc->wFuncFlags&FUNCFLAG_FBINDABLE;
   m_tRequestEdit = pFuncDesc->wFuncFlags&FUNCFLAG_FREQUESTEDIT;

   m_apParamInfo.SetSize( pFuncDesc->cParams );
   for( iParam = 0; iParam < m_apParamInfo.GetSize(); iParam++ )
   {
	  m_apParamInfo[iParam] = new CMethodParamInfo;
	  if( m_apParamInfo[iParam] == NULL )
	  {
		 return( E_OUTOFMEMORY );
	  }
   }

   ::ATL::CAutoStackPtr<BSTR> pbstrNames((BSTR*)_malloca( (pFuncDesc->cParams+1)*sizeof( BSTR ) ));
   for( iName = 0; iName < UINT( pFuncDesc->cParams+1 ); iName++ )
   {
	  pbstrNames[iName] = NULL;
   }

   hResult = pTypeInfo->GetNames( m_dispid, pbstrNames, pFuncDesc->cParams+1,
	  &nNames );
    if( FAILED( hResult ) )
   {
	return( hResult );
   }
   ASSERT( nNames > 0 );

   m_strName = pbstrNames[0];
   TRACE( "  Method: %s ", LPCTSTR( m_strName ) );
   switch( m_invkind )
   {
   case INVOKE_FUNC:
	  ASSERT( nNames == UINT( pFuncDesc->cParams+1 ) );
	  break;

   case INVOKE_PROPERTYGET:
	  ASSERT( nNames == UINT( pFuncDesc->cParams+1 ) );
	  break;

   case INVOKE_PROPERTYPUT:
	  ASSERT( nNames == UINT( pFuncDesc->cParams ) );
	  break;

   case INVOKE_PROPERTYPUTREF:
	  ASSERT( nNames == UINT( pFuncDesc->cParams ) );
	  break;

   default:
	  ASSERT( FALSE );
	  break;
   }
   for( iParam = 0; iParam < m_apParamInfo.GetSize(); iParam++ )
   {
	  if( pbstrNames[iParam+1] == NULL )
	  {
		 // This must be the right-hand side of a property put or putref.
		 LOAD_STRING_FROM_RESOURCE( strPropertyValue, IDS_PROPERTYVALUE );
		 pszParamName = T2OLE_EX_DEF( LPCTSTR( strPropertyValue ) );
	  }
	  else
	  {
		 pszParamName = pbstrNames[iParam+1];
	  }
	  m_apParamInfo[iParam]->Init( pszParamName,
		 &pFuncDesc->lprgelemdescParam[iParam] );
   }

   for( iName = 0; iName < UINT( pFuncDesc->cParams+1 ); iName++ )
   {
	  if( pbstrNames[iName] != NULL )
	  {
		 ::SysFreeString( pbstrNames[iName] );
	  }
   }
   return( S_OK );
}

HRESULT CMethodInfo::InitPropertyGet( ITypeInfo* pTypeInfo,
   const VARDESC* pVarDesc )
{
   HRESULT hResult;
   BSTR bstrName;
   UINT nNames;

   ENSURE( pTypeInfo != NULL );
   ENSURE( pVarDesc != NULL );

   m_dispid = pVarDesc->memid;
   m_invkind = INVOKE_PROPERTYGET;
   m_tBindable = pVarDesc->wVarFlags&VARFLAG_FBINDABLE;
   m_tRequestEdit = pVarDesc->wVarFlags&FUNCFLAG_FREQUESTEDIT;

   bstrName = NULL;
   hResult = pTypeInfo->GetNames( m_dispid, &bstrName, 1, &nNames );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }
   ASSERT( nNames == 1 );

   m_strName = bstrName;
   SysFreeString( bstrName );

   return( S_OK );
}

HRESULT CMethodInfo::InitPropertyPut( ITypeInfo* pTypeInfo,
   const VARDESC* pVarDesc )
{

   CString strPropertyValue;
   HRESULT hResult;
   BSTR bstrName;
   UINT nNames;

   ENSURE( pTypeInfo != NULL );
   ENSURE( pVarDesc != NULL );

   m_dispid = pVarDesc->memid;
   m_invkind = INVOKE_PROPERTYPUT;
   m_tBindable = pVarDesc->wVarFlags&VARFLAG_FBINDABLE;
   m_tRequestEdit = pVarDesc->wVarFlags&FUNCFLAG_FREQUESTEDIT;

   bstrName = NULL;
   hResult = pTypeInfo->GetNames( m_dispid, &bstrName, 1, &nNames );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }
   ASSERT( nNames == 1 );

   m_strName = bstrName;
   SysFreeString( bstrName );

   m_apParamInfo.SetSize( 1 );
   m_apParamInfo[0] = new CMethodParamInfo;
   if( m_apParamInfo[0] == NULL )
   {
	  return( E_OUTOFMEMORY );
   }

   LOAD_STRING_FROM_RESOURCE( strPropertyValue, IDS_PROPERTYVALUE );

   m_apParamInfo[0]->Init( CT2COLE( LPCTSTR( strPropertyValue ) ),
	  &pVarDesc->elemdescVar );

   return( S_OK );
}

BOOL CMethodInfo::IsBindable() const
{
   return( m_tBindable );
}

BOOL CMethodInfo::IsLogged() const
{
   return( m_tLog );
}

BOOL CMethodInfo::LogEditRequests() const
{
   return( m_tLogEditRequests );
}

void CMethodInfo::LogEvent( CLog& log, DISPPARAMS* pdpParams )
{
   int iParam;
   CMethodParamInfo* pParamInfo;
   COleVariant varParamValue;

   log<<m_strName<<_T( " " );

   if( pdpParams->cArgs != UINT( m_apParamInfo.GetSize() ) )
   {
	  log<<_T( "(Wrong number of arguments)\n" );
   }
   else
   {
	  for( iParam = 0; iParam < m_apParamInfo.GetSize(); iParam++ )
	  {
		 pParamInfo = m_apParamInfo[iParam];
		 log<<_T( "{" )<<pParamInfo->GetName()<<_T( "=" );
	   try
	   {
		   varParamValue = pdpParams->rgvarg[pdpParams->cArgs-iParam-1];
		 log<<varParamValue;
	   }
	   catch( COleException* pException )
	   {
		  pException->Delete();
	   }
		 log<<_T( "}" );
	  }
	  log<<_T( "\n" );
   }
}

BOOL CMethodInfo::RequestsEdit() const
{
   return( m_tRequestEdit );
}

void CMethodInfo::SetRequestEditResponse( int eResponse )
{
   m_eRequestEditResponse = eResponse;
}


CInterfaceInfo::CInterfaceInfo() :
   m_iid( IID_NULL )
{
}

CInterfaceInfo::~CInterfaceInfo()
{
   int iMethod;

   for( iMethod = 0; iMethod < m_apMethodInfo.GetSize(); iMethod++ )
   {
	  delete m_apMethodInfo[iMethod];
   }
}

CMethodInfo* CInterfaceInfo::FindMethod( DISPID dispid ) const
{
   int iMethod;

   for( iMethod = 0; iMethod < m_apMethodInfo.GetSize(); iMethod++ )
   {
	  if( m_apMethodInfo[iMethod]->GetID() == dispid )
	  {
		 return( m_apMethodInfo[iMethod] );
	  }
   }

   return( NULL );
}

CMethodInfo* CInterfaceInfo::FindPropertyGet( DISPID dispid ) const
{
   int iMethod;
   CMethodInfo* pMethodInfo;

   for( iMethod = 0; iMethod < m_apMethodInfo.GetSize(); iMethod++ )
   {
	  pMethodInfo = m_apMethodInfo[iMethod];
	  if( (pMethodInfo->GetID() == dispid) && (pMethodInfo->GetInvokeKind() ==
		 INVOKE_PROPERTYGET) )
	  {
		 return( pMethodInfo );
	  }
   }

   return( NULL );
}

IID CInterfaceInfo::GetIID() const
{
   return( m_iid );
}

CMethodInfo* CInterfaceInfo::GetMethod( int iMethod ) const
{
   return( m_apMethodInfo[iMethod] );
}

int CInterfaceInfo::GetNumMethods() const
{
   return( (int)m_apMethodInfo.GetSize() );
}

HRESULT CInterfaceInfo::Init( ITypeInfo* pTypeInfo )
{
   HRESULT hResult;
   CSmartTypeAttr pTypeAttr( pTypeInfo );
   CSmartFuncDesc pFuncDesc( pTypeInfo );
   CSmartVarDesc pVarDesc( pTypeInfo );
   int iVar;
   int iMethod;
   int iDestMethod;
   BOOL tFound;

   ASSERT( pTypeInfo != NULL );

   hResult = pTypeInfo->GetTypeAttr( &pTypeAttr );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   m_iid = pTypeAttr->guid;

   // Allocate enough space for the maximum number of methods that we could
   // possibly have, plus room for two methods for each property in case the
   // type info doesn't specify properties as put and set methods.
   m_apMethodInfo.SetSize( pTypeAttr->cFuncs+(2*pTypeAttr->cVars) );

   iDestMethod = 0;
   for( iMethod = 0; iMethod < pTypeAttr->cFuncs; iMethod++ )
   {
	  hResult = pTypeInfo->GetFuncDesc( iMethod, &pFuncDesc );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }

	  // Only add the function to our list if it is at least at nesting level
	  // 2 (i.e. defined in an interface derived from IDispatch).
	  if( !(pFuncDesc->wFuncFlags&FUNCFLAG_FRESTRICTED) &&
		 (pFuncDesc->funckind == FUNC_DISPATCH) )
	  {
		 m_apMethodInfo[iDestMethod] = new CMethodInfo;
		 if( m_apMethodInfo[iDestMethod] == NULL )
		 {
			return( E_OUTOFMEMORY );
		 }
		 hResult = m_apMethodInfo[iDestMethod]->Init( pTypeInfo, pFuncDesc );
		 if( FAILED( hResult ) )
		 {
			return( hResult );
		 }
		 iDestMethod++;
	  }
	  pFuncDesc.Release();
   }

   for( iVar = 0; iVar < pTypeAttr->cVars; iVar++ )
   {
	  hResult = pTypeInfo->GetVarDesc( iVar, &pVarDesc );
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }

	  if( (pVarDesc->varkind == VAR_DISPATCH) && !(pVarDesc->wVarFlags&
		 VARFLAG_FRESTRICTED) )
	  {
		 tFound = FALSE;
		 for( iMethod = 0; iMethod < iDestMethod; iMethod++ )
		 {
			if( (m_apMethodInfo[iMethod]->GetID() == pVarDesc->memid) &&
			   (m_apMethodInfo[iMethod]->GetInvokeKind() ==
			   INVOKE_PROPERTYGET) )
			{
			   tFound = TRUE;
			}
		 }

		 if( !tFound )
		 {
			// We haven't already added this one as a method, so do it now.

			m_apMethodInfo[iDestMethod] = new CMethodInfo;
			if( m_apMethodInfo[iDestMethod] == NULL )
			{
			   return( E_OUTOFMEMORY );
			}
			hResult = m_apMethodInfo[iDestMethod]->InitPropertyGet( pTypeInfo,
			   pVarDesc );
			if( FAILED( hResult ) )
			{
			   return( hResult );
			}
			iDestMethod++;
		 }

		 if( !(pVarDesc->wVarFlags&VARFLAG_FREADONLY) )
		 {
			tFound = FALSE;
			for( iMethod = 0; iMethod < iDestMethod; iMethod++ )
			{
			   if( (m_apMethodInfo[iMethod]->GetID() == pVarDesc->memid) &&
				  (m_apMethodInfo[iMethod]->GetInvokeKind() ==
				  INVOKE_PROPERTYPUT) )
			   {
				  tFound = TRUE;
			   }
			}

			if( !tFound )
			{
			   // We haven't already added this one as a method, so do it now.

			   m_apMethodInfo[iDestMethod] = new CMethodInfo;
			   if( m_apMethodInfo[iDestMethod] == NULL )
			   {
				  return( E_OUTOFMEMORY );
			   }
			   hResult = m_apMethodInfo[iDestMethod]->InitPropertyPut(
				  pTypeInfo, pVarDesc );
			   if( FAILED( hResult ) )
			   {
				  return( hResult );
			   }
			   iDestMethod++;
			}
		 }
	  }

	  pVarDesc.Release();
   }

   // Trim the array down to the actual size.
   m_apMethodInfo.SetSize( iDestMethod );

   return( S_OK );
}
