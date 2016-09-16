// CustomString.cpp : Defines the entry point for the console application.
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "StdAfx.H"
#include "CustomString.H"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma warning ( disable : 4100 )

// The one and only application object

CWinApp theApp;

DWORD g_dwTLSIndex = 0;
CAtlArray< CPath > g_astrFileNames;
LONG g_iNextFileName = -1;
const int kThreads = 4;

IAtlStringMgr* GetThreadStringMgr() throw()
{
	return( static_cast< IAtlStringMgr* >( ::TlsGetValue( g_dwTLSIndex ) ) );
}

void ProcessFile( const CPath& strFileName )
{
	CPath strOutputFileName = strFileName;
	strOutputFileName.RenameExtension( _T( ".utxt" ) );

	CFile fileInput( strFileName, CFile::modeRead|CFile::shareDenyWrite|CFile::osSequentialScan );
	CFile fileOutput( strOutputFileName, CFile::modeCreate|CFile::modeWrite|CFile::shareExclusive|CFile::osSequentialScan );

	CString strInput( GetThreadStringMgr() );  // Use the thread's string manager
	// Read the input string from the input file
	{
		int nFileLength = int( fileInput.GetLength() );
		CStrBuf pszBuffer( strInput, nFileLength, CStrBufA::SET_LENGTH );

		fileInput.Read( pszBuffer, nFileLength );
	}

	CString strOutput( GetThreadStringMgr() );  // Use the thread's string manager
	int iStart = 0;
	while( iStart != -1 )
	{
		CString strToken = strInput.Tokenize( _T( "\r\n" ), iStart );
		if( iStart >= 0 )
		{
			strOutput += strToken;
			strOutput += _T( '\n' );
		}
	}

	fileOutput.Write( strOutput.GetString(), strOutput.GetLength()*sizeof( TCHAR ) );
}

DWORD WINAPI ThreadProc( void* pContext )
{
	(void)pContext;

	// Create a non-thread-safe heap just for this thread
	CWin32Heap heap( HEAP_NO_SERIALIZE, 0 );
	// Create a string manager for this thread, using the thread-specific heap
	CAtlStringMgr mgr( &heap );
	// Set this thread's TLS slot to point to the thread's string manager
	::TlsSetValue( g_dwTLSIndex, static_cast< IAtlStringMgr* >( &mgr ) );

	bool bDone = false;
	while( !bDone )
	{
		ULONG iFileName = ::InterlockedIncrement( &g_iNextFileName );
		if( iFileName >= g_astrFileNames.GetCount() )
		{
			bDone = true;
		}
		else
		{
			ProcessFile( g_astrFileNames[iFileName] );
		}
	}

	return( 0 );
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	// initialize MFC and print and error on failure
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		fprintf( stderr, _T("Fatal Error: MFC initialization failed\n") );
		nRetCode = 1;
	}
	else
	{
		g_dwTLSIndex = ::TlsAlloc();

		CFileFind finder;
		BOOL bFound = finder.FindFile( argv[1] );
		while( bFound )
		{
			bFound = finder.FindNextFile();
			g_astrFileNames.Add( CPath( finder.GetFileName() ) );
		}

		HANDLE ahThreads[kThreads];
		for( int iThread = 0; iThread < kThreads; iThread++ )
		{
			ahThreads[iThread] = 0;
		}

		// Spin up the worker threads.
		for( int iThread = 0; iThread < kThreads; iThread++ )
		{
			DWORD idThread;
			ahThreads[iThread] = ::CreateThread( NULL, 0, ThreadProc, NULL, 0, &idThread );
		}

		// Wait for all of the worker threads to terminate
		::WaitForMultipleObjects( kThreads, ahThreads, TRUE, INFINITE );

		::TlsFree( g_dwTLSIndex );
		g_dwTLSIndex = 0;
	}

	return nRetCode;
}
