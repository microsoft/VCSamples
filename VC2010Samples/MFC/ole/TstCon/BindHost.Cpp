// File: BindHost.Cpp
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

CTCBindHost::CTCBindHost() :
   m_nRefCount( 0 )
{
}

CTCBindHost::~CTCBindHost()
{
}

HRESULT CTCBindHost::CreateInstance( REFIID iid, void** ppObject )
{
   CTCBindHost* pObject;
   HRESULT hResult;

   if( ppObject == NULL )
   {
	  return( E_POINTER );
   }
   *ppObject = NULL;

#pragma warning(push)
#pragma warning(disable: 6014)
   /* prefast noise VSW 489981 */
   pObject = new CTCBindHost;

   hResult = pObject->QueryInterface( iid, ppObject );
   if( FAILED( hResult ) )
   {
	  delete pObject;
	  return( hResult );
   }

   ASSERT( *ppObject != NULL );

   return( S_OK );
#pragma warning(pop)
}


///////////////////////////////////////////////////////////////////////////////
// IUnknown
///////////////////////////////////////////////////////////////////////////////

STDMETHODIMP_( ULONG ) CTCBindHost::AddRef()
{
   m_nRefCount++;

   return( m_nRefCount );
}

STDMETHODIMP_( ULONG ) CTCBindHost::Release()
{
   m_nRefCount--;

   if( m_nRefCount == 0 )
   {
	  delete this;
	  return( 0 );
   }

   return( m_nRefCount );
}

STDMETHODIMP CTCBindHost::QueryInterface( REFIID iid, void** ppInterface )
{
   if( ppInterface == NULL )
   {
	  return( E_POINTER );
   }
   *ppInterface = NULL;

   if( IsEqualIID( iid, IID_IUnknown ) || IsEqualIID( iid, IID_IBindHost ) )
   {
	  *ppInterface = (IBindHost*)this;
	  AddRef();
	  return( S_OK );
   }

   return( E_NOINTERFACE );
}


///////////////////////////////////////////////////////////////////////////////
// IBindHost
///////////////////////////////////////////////////////////////////////////////

STDMETHODIMP CTCBindHost::CreateMoniker( LPOLESTR pszName, IBindCtx* pBindCtx,
   IMoniker** ppMoniker, DWORD dwReserved )
{
   HRESULT hResult;

   (void)pBindCtx;
   (void)dwReserved;

   if( ppMoniker == NULL )
   {
	  return( E_POINTER );
   }
   *ppMoniker = NULL;

   if( pszName == NULL )
   {
	  return( E_INVALIDARG );
   }

   hResult = CreateURLMoniker( NULL, pszName, ppMoniker );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   ASSERT( *ppMoniker != NULL );

   return( S_OK );
}

STDMETHODIMP CTCBindHost::MonikerBindToObject( IMoniker* pMoniker,
   IBindCtx* pBindCtx, IBindStatusCallback* pBSC, REFIID iid, void** ppObject )
{
   (void)pMoniker;
   (void)pBindCtx;
   (void)pBSC;
   (void)iid;

   if( ppObject == NULL )
   {
	  return( E_POINTER );
   }
   *ppObject = NULL;

   return( E_NOTIMPL );
}

STDMETHODIMP CTCBindHost::MonikerBindToStorage( IMoniker* pMoniker,
   IBindCtx* pBindCtx, IBindStatusCallback* pBSC, REFIID iid, void** ppObject )
{
   HRESULT hResult;
   IBindCtxPtr pNewBindCtx;

   TCTrace( TRACELEVEL_NORMAL, "IBindHost::MonikerBindToStorage\n" );

   if( ppObject == NULL )
   {
	  return( E_POINTER );
   }
   *ppObject = NULL;

   if( pBindCtx != NULL )
   {
	  pNewBindCtx = pBindCtx;
	  if( pBSC )
	  {
		 hResult = RegisterBindStatusCallback( pBindCtx, pBSC, NULL, 0 );
		 if( FAILED( hResult ) )
		 {
			return( hResult );
		 }
	  }
   }
   else
   {
	  if( pBSC )
	  {
		 hResult = CreateAsyncBindCtx( 0, pBSC, NULL, &pNewBindCtx );
		 if( FAILED( hResult ) )
		 {
			return( hResult );
		 }
	  }
	  else
	  {
		 hResult = CreateBindCtx( 0, &pNewBindCtx );
		 if( FAILED( hResult ) )
		 {
			return( hResult );
		 }
	  }
   }
   ASSERT( pNewBindCtx != NULL );

   return( pMoniker->BindToStorage( pNewBindCtx, NULL, iid, ppObject ) );
}
