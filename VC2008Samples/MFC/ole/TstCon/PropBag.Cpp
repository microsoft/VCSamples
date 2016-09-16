// File: PropBag.Cpp
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

IMPLEMENT_DYNAMIC( CPropertyBagItem, CObject );

CPropertyBagItem::CPropertyBagItem( LPCOLESTR pszName, VARIANT* pvarValue )
{
   m_strName = pszName;
   m_varValue = pvarValue;
}


CPropertyBag::CPropertyBag() :
   m_nRefCount( 0 )
{
}

CPropertyBag::~CPropertyBag()
{
   CPropertyBagItem* pItem;

   while( !m_lpItems.IsEmpty() )
   {
	  pItem = m_lpItems.RemoveHead();
	  delete pItem;
   }
}

POSITION CPropertyBag::GetFirstItemPosition() const
{
   return( m_lpItems.GetHeadPosition() );
}

CPropertyBagItem* CPropertyBag::GetNextItem( POSITION& posItem ) const
{
   return( m_lpItems.GetNext( posItem ) );
}

STDMETHODIMP_( ULONG ) CPropertyBag::AddRef()
{
   m_nRefCount++;

   return( m_nRefCount );
}

STDMETHODIMP_( ULONG ) CPropertyBag::Release()
{
   m_nRefCount--;

   if( m_nRefCount == 0 )
   {
	  delete this;
	  return( 0 );
   }
   else
   {
	  return( m_nRefCount );
   }
}

STDMETHODIMP CPropertyBag::QueryInterface( REFIID iid, void** ppInterface )
{
   ENSURE( ppInterface != NULL );
   *ppInterface = NULL;

   if( iid == IID_IUnknown )
   {
	  *ppInterface = (IUnknown*)this;
   }
   else if( iid == IID_IPropertyBag )
   {
	  *ppInterface = (IPropertyBag*)this;
   }

   if( *ppInterface != NULL )
   {
	  AddRef();
	  return( S_OK );
   }
   else
   {
	  return( E_NOINTERFACE );
   }
}

STDMETHODIMP CPropertyBag::Read( LPCOLESTR pszPropName, VARIANT* pvarValue,
   IErrorLog* pErrorLog )
{
   POSITION posItem;
   CPropertyBagItem* pItem;
   HRESULT hResult;
   EXCEPINFO error;

   if( pszPropName == NULL )
   {
	  return( E_POINTER );
   }
   if( pvarValue == NULL )
   {
	  return( E_POINTER );
   }

   memset( &error, 0, sizeof( error ) );

   COLE2CT strPropName( pszPropName );

   posItem = m_lpItems.GetHeadPosition();
   while( posItem != NULL )
   {
	  pItem = m_lpItems.GetNext( posItem );
	  if( pItem->m_strName == strPropName )
	  {
		 // We found the property.
		 if( pvarValue->vt == VT_EMPTY )
		 {
			hResult = VariantCopy( pvarValue, &pItem->m_varValue );
			if( FAILED( hResult ) )
			{
			   if( pErrorLog != NULL )
			   {
				  error.scode = hResult;
				  pErrorLog->AddError( pszPropName, &error );
			   }
			   return( E_FAIL );
			}
		 }
		 else
		 {
			hResult = VariantChangeType( pvarValue, &pItem->m_varValue, 0,
			   pvarValue->vt );
			if( FAILED( hResult ) )
			{
			   if( pErrorLog != NULL )
			   {
				  error.scode = hResult;
				  pErrorLog->AddError( pszPropName, &error );
			   }
			   return( E_FAIL );
			}
		 }
		 return( S_OK );
	  }
   }

   return( E_INVALIDARG );
}

STDMETHODIMP CPropertyBag::Write( LPCOLESTR pszPropName, VARIANT* pvarValue )
{

   CPropertyBagItem* pItem;

   if( (pszPropName == NULL) || (pvarValue == NULL) )
   {
	  return( E_POINTER );
   }

   pItem = new CPropertyBagItem( pszPropName, pvarValue );
   if( pItem == NULL )
   {
	  return( E_OUTOFMEMORY );
   }

   m_lpItems.AddTail( pItem );

   return( S_OK );
}
