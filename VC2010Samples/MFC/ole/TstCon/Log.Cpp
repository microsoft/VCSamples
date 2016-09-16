// File: Log.Cpp
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


IMPLEMENT_DYNAMIC( CLog, CObject );

CLog::CLog()
{
}

CLog::~CLog()
{
}

CLog& CLog::operator<<( COleVariant& var )
{
   COleVariant varString;
   CString str;

   try
   {
	  varString.ChangeType( VT_BSTR, var );
	  str = varString.bstrVal;
   }
   catch( CException* pException )
   {
	  str = _T( "??????" );

	 pException->Delete();
   }

   (*this)<<str;

   return( *this );
}

CLog& CLog::operator<<( int n )
{
   CString str;

   str.Format( _T( "%d" ), n );

   (*this)<<str;

   return( *this );
}


IMPLEMENT_DYNAMIC( CNullLog, CLog );

CNullLog::CNullLog()
{
}

CNullLog::~CNullLog()
{
}

CLog& CNullLog::operator<<( LPCTSTR /* pszString */ )
{
   return( *this );
}


IMPLEMENT_DYNAMIC( CDebugLog, CLog );

CDebugLog::CDebugLog() :
   m_tStartOfLine( TRUE )
{
}

CDebugLog::~CDebugLog()
{
}

CLog& CDebugLog::operator<<( LPCTSTR pszString )
{
   CString strSpan;
   CString strString( pszString );

   while( strString.GetLength() > 0 )
   {
	  if( m_tStartOfLine )
	  {
		 OutputDebugString( _T( "TstCon Log: " ) );
		 m_tStartOfLine = FALSE;
	  }
	  strSpan = strString.SpanExcluding( _T( "\n" ) );
	  OutputDebugString( strSpan );
	  if( strString.GetLength() == strSpan.GetLength() )
	  {
		 strString.Empty();
	  }
	  else
	  {
		 ASSERT( strString[strSpan.GetLength()] == _T( '\n' ) );
		 OutputDebugString( _T( "\n" ) );
		 m_tStartOfLine = TRUE;
		 strString = strString.Mid( strSpan.GetLength()+1 );
	  }
   }

   return( *this );
}


IMPLEMENT_DYNAMIC( CFileLog, CLog );

CFileLog::CFileLog()
{
}

CFileLog::~CFileLog()
{
}

CLog& CFileLog::operator<<( LPCTSTR pszString )
{
   m_file.WriteString( pszString );

   return( *this );
}

BOOL CFileLog::Create( LPCTSTR pszFileName )
{
   BOOL tSuccess;

   tSuccess = m_file.Open( pszFileName, CFile::modeCreate|CFile::modeWrite|
	  CFile::shareExclusive|CFile::typeText );
   if( !tSuccess )
   {
	  return( FALSE );
   }

   return( TRUE );
}

CString CFileLog::GetFileName() const
{
   return( m_file.GetFileName() );
}


IMPLEMENT_DYNAMIC( COutputWindowLog, CLog );

COutputWindowLog::COutputWindowLog( CEdit* pEditBox ) :
   m_pEditBox( pEditBox )
{
   ASSERT( m_pEditBox != NULL );
}

COutputWindowLog::~COutputWindowLog()
{
}

CLog& COutputWindowLog::operator<<( LPCTSTR pszString )
{
   int iLastChar;
   CString strSpan;
   CString strString( pszString );

   while( strString.GetLength() > 0 )
   {
	  strSpan = strString.SpanExcluding( _T( "\n" ) );
	  iLastChar = m_pEditBox->GetWindowTextLength();
	  m_pEditBox->SetSel( iLastChar, iLastChar );
	  m_pEditBox->ReplaceSel( strSpan );
	  if( strString.GetLength() == strSpan.GetLength() )
	  {
		 strString.Empty();
	  }
	  else
	  {
		 ASSERT( strString[strSpan.GetLength()] == _T( '\n' ) );
		 iLastChar = m_pEditBox->GetWindowTextLength();
		 m_pEditBox->SetSel( iLastChar, iLastChar );
		 m_pEditBox->ReplaceSel( _T( "\r\n" ) );
		 strString = strString.Mid( strSpan.GetLength()+1 );
	  }
   }

   return( *this );
}
