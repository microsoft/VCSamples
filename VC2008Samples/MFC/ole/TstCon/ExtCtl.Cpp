// File: ExtCtl.Cpp
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

// {FFC3C462-18DE-11d1-8E2F-00C04FB68D60}
const GUID LIBID_TCPROPSLib =
{ 0xffc3c462, 0x18de, 0x11d1, { 0x8e, 0x2f, 0x0, 0xc0, 0x4f, 0xb6, 0x8d, 0x60 } };

CExtendedControl::CExtendedControl() :
   m_nRefCount( 0 ),
   m_pControl( NULL ),
   m_tVisible( TRUE )
{
}

CExtendedControl::~CExtendedControl()
{
   if( m_pInnerDispatch != NULL )
   {
	  AddRef();  // Undo the artificial Release
	  m_pInnerDispatch.Release();
   }

   if( m_pControl != NULL )
   {
	  m_pControl->Release();
	  m_pControl = NULL;
   }
}

HRESULT CExtendedControl::Init( REFCLSID clsidControl,
   CTestContainer98Item* pItem )
{
   HRESULT hResult;
   ITypeLibPtr pTypeLib;
   LPOLESTR pszModuleO;
   TCHAR szModule[MAX_PATH];
   CString strTLBPath;

   ASSERT( m_pItem != NULL );
   ASSERT( m_pControl == NULL );

   hResult = CoCreateInstance( clsidControl, (IUnknown*)this,
	  CLSCTX_INPROC_SERVER|CLSCTX_INPROC_HANDLER, IID_IUnknown, (void**)&m_pControl );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   m_pInnerDispatch = m_pControl;
   if( m_pInnerDispatch == NULL )
   {
	  return( E_NOINTERFACE );
   }
   Release();  // Artificially release because we QI'd the aggregate.

   GetModuleFileName( NULL, szModule, MAX_PATH );
   strTLBPath = szModule;
   strTLBPath += _T( "\\2" );  // Load the second TLB from the executable

   pszModuleO = strTLBPath.AllocSysString();
   hResult = LoadTypeLib( pszModuleO, &pTypeLib );
   if( FAILED( hResult ) )
   {
	  TCTrace( TRACELEVEL_NORMAL,
		 "Failed to load typelib for extended control\n" );
	  return( hResult );
   }

   hResult = pTypeLib->GetTypeInfoOfGuid( __uuidof( ITCExtendedControl ),
	  &m_pTypeInfo );
   if( FAILED( hResult ) )
   {
	  return( hResult );
   }

   m_pItem = pItem;
   m_pView = m_pItem->GetDocument()->GetView();

   return( S_OK );
}

HRESULT CExtendedControl::CreateInstance( REFCLSID clsidControl,
   CTestContainer98Item* pItem, IUnknown* pOuterUnknown, REFIID iid,
   void** ppInterface )
{
   CExtendedControl* pObject;
   HRESULT hResult;

   (void)pOuterUnknown;

   ENSURE( pOuterUnknown == NULL );
   ENSURE( ppInterface != NULL );
   *ppInterface = NULL;

#pragma warning(push)
#pragma warning(disable: 6014)
   /* prefast noise VSW 489981 */
   pObject = new CExtendedControl;

   pObject->m_nRefCount++;  // Protect ourselves while we create the aggregate

   hResult = pObject->Init( clsidControl, pItem );
   if( FAILED( hResult ) )
   {
	  delete pObject;
	  return( hResult );
   }

   hResult = pObject->QueryInterface( iid, ppInterface );
   if( FAILED( hResult ) )
   {
	  delete pObject;
	  return( hResult );
   }

   pObject->m_nRefCount--;  // Undo the extra refcount we added to protect ourself
   ASSERT( pObject->m_nRefCount > 0 );

   return( S_OK );
#pragma warning(pop)
}

STDMETHODIMP_( ULONG ) CExtendedControl::AddRef()
{
   m_nRefCount++;

   return( m_nRefCount );
}

STDMETHODIMP_( ULONG ) CExtendedControl::Release()
{
   m_nRefCount--;
   if( m_nRefCount == 0 )
   {
	  m_nRefCount++;
	  delete this;
	  return( 0 );
   }

   return( m_nRefCount );
}

STDMETHODIMP CExtendedControl::QueryInterface( REFIID iid, void** ppInterface )
{
   HRESULT hResult;

   ENSURE( ppInterface != NULL );
   *ppInterface = NULL;


   if( iid == IID_IUnknown || iid == IID_IDispatch )
   {
	  *ppInterface = (IDispatch*)this;
	  AddRef();
   }
   else if( iid == __uuidof( ITCExtendedControl ) )
   {
	  *ppInterface = (ITCExtendedControl*)this;
	  AddRef();
   }
   else
   {
	  ASSERT( m_pControl != NULL );
	  if (m_pControl == NULL)
	  {
	 	 hResult = E_UNEXPECTED;
	  }
	  else
	  {
		 hResult = m_pControl->QueryInterface( iid, ppInterface );
	  }
	  
	  if( FAILED( hResult ) )
	  {
		 return( hResult );
	  }
   }

   return( S_OK );
}

STDMETHODIMP CExtendedControl::GetIDsOfNames( REFIID iid, LPOLESTR* ppszNames,
   UINT nNames, LCID lcid, DISPID* pDispIDs )
{
   HRESULT hResult;

   hResult = m_pTypeInfo->GetIDsOfNames( ppszNames, nNames, pDispIDs );
   if( FAILED( hResult ) )
   {
	  hResult = m_pInnerDispatch->GetIDsOfNames( iid, ppszNames, nNames, lcid,
		 pDispIDs );
   }

   return( hResult );
}

STDMETHODIMP CExtendedControl::GetTypeInfo( UINT iTypeInfo, LCID lcid,
   ITypeInfo** ppTypeInfo )
{
   return( m_pInnerDispatch->GetTypeInfo( iTypeInfo, lcid, ppTypeInfo ) );
}

STDMETHODIMP CExtendedControl::GetTypeInfoCount( UINT* pnInfoCount )
{
   return( m_pInnerDispatch->GetTypeInfoCount( pnInfoCount ) );
}

HRESULT CExtendedControl::InternalInvoke( DISPID dispidMember, REFIID iid,
   LCID lcid, WORD wFlags, DISPPARAMS* pdpParams, VARIANT* pvarResult,
   EXCEPINFO* pExceptionInfo, UINT* piArgError )
{
   (void)iid;
   (void)lcid;

   return( m_pTypeInfo->Invoke( this, dispidMember, wFlags, pdpParams,
	  pvarResult, pExceptionInfo, piArgError ) );
}

STDMETHODIMP CExtendedControl::Invoke( DISPID dispidMember, REFIID iid,
   LCID lcid, WORD wFlags, DISPPARAMS* pdpParams, VARIANT* pvarResult,
   EXCEPINFO* pExceptionInfo, UINT* piArgError )
{
   HRESULT hResult;

   if( pdpParams == NULL )
   {
	  return( E_INVALIDARG );
   }

   hResult = DISP_E_MEMBERNOTFOUND;
   if( iid == IID_NULL )
   {
	  hResult = InternalInvoke( dispidMember, iid, lcid, wFlags, pdpParams,
		 pvarResult, pExceptionInfo, piArgError );
   }
   if( hResult == DISP_E_MEMBERNOTFOUND )
   {
	  hResult = m_pInnerDispatch->Invoke( dispidMember, iid, lcid, wFlags,
		 pdpParams, pvarResult, pExceptionInfo, piArgError );
   }

   return( hResult );
}

STDMETHODIMP CExtendedControl::get_Name( BSTR* pbstrName )
{
   ENSURE( pbstrName != NULL );

   *pbstrName = m_bstrName.copy();
   if( *pbstrName == NULL )
   {
	  return( E_OUTOFMEMORY );
   }

   return( S_OK );
}

STDMETHODIMP CExtendedControl::put_Name( BSTR bstrName )
{
   m_bstrName = bstrName;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::get_PositionX( long* px )
{
   if( px == NULL )
   {
	  return( E_POINTER );
   }

   *px = m_ptPosition.x;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::put_PositionX( long x )
{
   m_ptPosition.x = x;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::get_PositionY( long* py )
{
   if( py == NULL )
   {
	  return( E_POINTER );
   }

   *py = m_ptPosition.y;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::put_PositionY( long y )
{
   m_ptPosition.y = y;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::get_SizeX( long* px )
{
   if( px == NULL )
   {
	  return( E_POINTER );
   }

   *px = m_size.cx;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::put_SizeX( long x )
{
   m_size.cx = x;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::get_SizeY( long* py )
{
   if( py == NULL )
   {
	  return( E_POINTER );
   }

   *py = m_size.cy;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::put_SizeY( long y )
{
   m_size.cy = y;

   return( S_OK );
}

STDMETHODIMP CExtendedControl::raw_Activate()
{
   if( !m_pItem->IsInPlaceActive() )
   {
	  m_pItem->Activate( OLEIVERB_SHOW, m_pView );
   }

   return( S_OK );
}

STDMETHODIMP CExtendedControl::raw_Deactivate()
{
   if( m_pItem->IsInPlaceActive() )
   {
	  m_pItem->Deactivate();
   }

   return( S_OK );
}

STDMETHODIMP CExtendedControl::raw_UIActivate()
{
   if( !m_pItem->IsUIActive() )
   {
	  m_pItem->DoVerb( OLEIVERB_UIACTIVATE, m_pView );
   }

   return( S_OK );
}

STDMETHODIMP CExtendedControl::raw_UIDeactivate()
{
   if( m_pItem->IsUIActive() )
   {
	  m_pItem->DeactivateUI();
   }

   return( S_OK );
}
