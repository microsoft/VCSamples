// consoleio.h
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.
#pragma once

#pragma warning( disable : 4244)

int select( char* pszPrompt, int nOptionsCount, int nFirstOption = 1 )
{
	int option = -1;
	char buffer[80];
	while( true )
	{
		printf( "%s", pszPrompt );
		if( gets_s( buffer,80 ) == NULL )
			return -1;

		option = atoi( buffer );

		printf( "\n" );
		if( option >= nFirstOption && option <= ( nFirstOption + nOptionsCount - 1 ) )
			return option;
	}
}

template<class ctype>
void prompt( ctype& data, const char* pszPrompt )
{
	char buffer[80];
	printf( "%s", pszPrompt );
	if( gets_s( buffer, 80 ) == NULL )
		ATLASSERT(FALSE); // invalid input
	data = atoi( buffer );
}

template<>
void prompt<float>( float& data, const char* pszPrompt )
{
	char buffer[80];
	printf( "%s", pszPrompt );
	if( gets_s( buffer,80 ) == NULL )
		ATLASSERT(FALSE); // invalid input
	data = (float)(atof( buffer ));
}

template<>
void prompt<double>( double& data, const char* pszPrompt )
{
	char buffer[80];
	printf( "%s", pszPrompt );
	if( gets_s( buffer,80 ) == NULL )
		ATLASSERT(FALSE); // invalid input
	data = atof( buffer );
}

template<>
void prompt<DBTIMESTAMP>( DBTIMESTAMP& data, const char* pszPrompt )
{
	printf( "%s", pszPrompt );
	data.year  = (SHORT)select( "Enter year (0-9999): ", 10000, 0 );
	data.month = (USHORT)select( "Enter month (1-12):     ", 12 );
	data.day   = (USHORT)select( "Enter day (1-31):       ", 31 );
	data.hour =  (USHORT)select( "Enter hour (0-23):      ", 24, 0 );
	data.minute = (USHORT)select( "Enter minute (0-59):   ", 60, 0 );
	data.second = (USHORT)select( "Enter second (0-59):   ", 60, 0 );
	data.fraction = 0;
}

template<>
void prompt<DBDATE>( DBDATE& data, const char* pszPrompt )
{
	printf( "%s", pszPrompt );
	data.year  = (SHORT)select( "Enter year (0-9999): ", 10000, 0 );
	data.month = (USHORT)select( "Enter month (1-12):     ", 12 );
	data.day   = (USHORT)select( "Enter day (1-31):       ", 31 );
}

template<>
void prompt<DBTIME>( DBTIME& data, const char* pszPrompt )
{
	printf( "%s", pszPrompt );
	data.hour =  (USHORT)select( "Enter hour (0-23):      ", 24, 0 );
	data.minute = (USHORT)select( "Enter minute (0-59):   ", 60, 0 );
	data.second = (USHORT)select( "Enter second (0-59):   ", 60, 0 );
}


void promptStr( CHAR* pszData, const char* pszPrompt )
{
	ATLASSERT( pszData != NULL );
	printf( "%s", pszPrompt );
	if( gets_s( pszData, 80 ) == NULL )
		ATLASSERT(FALSE); // invalid input
}

void promptStr( WCHAR* pwszData, const char* pszPrompt )
{
	ATLASSERT( pwszData != NULL );
	printf( "%s", pszPrompt );
	if( _getws_s( pwszData, 80 ) == NULL )
		ATLASSERT(FALSE); // invalid input
}

