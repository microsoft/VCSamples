// PrintData.h
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

template<class T>
void PrintAccessorData( T& rs )
{
	// print column info
	for( DBORDINAL col = 1; col <= rs.GetColumnCount(); col++ )
	{
		DBTYPE dbtype;
		rs.GetColumnType( col, &dbtype );
		if( col > 1 )
			printf( ", " );
		printf( "%S [%d]", rs.GetColumnName( col ), dbtype );
	}

	printf( "\n" );

	// print rowset data
	HRESULT hr = rs.MoveNext();
	while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )
	{
		for( DBORDINAL col = 1; col <= rs.GetColumnCount(); col++ )
		{
			if( col > 1 )
				printf( ", " );

			DBTYPE dbtype;
			DBSTATUS status;
			rs.GetColumnType( col, &dbtype );
			rs.GetStatus( col, &status );

			if( FAILED( status ) )
			{
				printf( "<<ERROR>>" );
			}
			if( status == DBSTATUS_S_ISNULL )
			{
				printf( "<<NULL>>" );
			}
			else if( status == DBSTATUS_S_OK || status == DBSTATUS_S_TRUNCATED )
			{
				// the following case will handle BLOBs binded as ISequentialStream/IStream pointer
				if( dbtype == DBTYPE_IUNKNOWN )
				{
					// first we have to determine what was the column's type originally reported by the provider
					CComHeapPtr<DBCOLUMNINFO> spColumnInfo;
					CComHeapPtr<OLECHAR> spStringsBuffer;
					DBORDINAL nColumns = 0;
					HRESULT hres = rs.CDynamicAccessor::GetColumnInfo( rs.m_spRowset, &nColumns, &spColumnInfo, &spStringsBuffer );
					ATLASSERT( SUCCEEDED( hres ) );
					ATLASSERT( col <= nColumns );
					DBTYPE wType = spColumnInfo[col-1].wType;

                    IUnknown* pUnknown = *(IUnknown**)rs.GetValue( col );
					ATLENSURE( pUnknown != NULL );
					// First, try to obtain the ISequentialStream pointer
					CComPtr<ISequentialStream> spSequentialStream;
					hres = pUnknown->QueryInterface( __uuidof(ISequentialStream), (void**)&spSequentialStream );
					if( SUCCEEDED(hres) && spSequentialStream )
					{
						switch( wType )
						{
						case DBTYPE_STR:
							{
								CHAR buffer[101];
								ULONG cbRead = 0;
								hres = spSequentialStream->Read( (void*)buffer, 100, &cbRead );
								while( SUCCEEDED(hres) && cbRead > 0 )
								{
									buffer[cbRead] = 0;
									printf( "%s", buffer );
									hres = spSequentialStream->Read( (void*)buffer, 100, &cbRead );
								}
							}
						case DBTYPE_WSTR:
							{
								WCHAR buffer[101];
								ULONG cbRead = 0;
								hres = spSequentialStream->Read( (void*)buffer, 200, &cbRead );
								while( SUCCEEDED(hres) && cbRead > 0 )
								{
									buffer[cbRead/2] = 0;
									printf( "%S", buffer );
									hres = spSequentialStream->Read( (void*)buffer, 200, &cbRead );
								}
							}
						case DBTYPE_BYTES:
							{
								BYTE buffer[100];
								ULONG cbRead = 0;
								hres = spSequentialStream->Read( (void*)buffer, 100, &cbRead );
								while( SUCCEEDED(hres) && cbRead > 0 )
								{
									char szHex[3];
									szHex[2] = 0;
									for( ULONG n = 0; n < cbRead; n++ )
									{
										d2h( buffer[n], szHex );
										printf( "%s", szHex );
									}
									hres = spSequentialStream->Read( (void*)buffer, 100, &cbRead );
								}
							}
						}
					}
					else
					{
						// try to obtain the IStream pointer
						CComPtr<IStream> spStream;
						hres = pUnknown->QueryInterface( __uuidof(IStream), (void**)&spStream );
						ATLASSERT( SUCCEEDED( hres ) );
						switch( wType )
						{
						case DBTYPE_STR:
							{
								CHAR buffer[101];
								ULONG cbRead = 0;
								hres = spStream->Read( (void*)buffer, 100, &cbRead );
								while( SUCCEEDED(hres) && cbRead > 0 )
								{
									buffer[cbRead] = 0;
									printf( "%s", buffer );
									hres = spStream->Read( (void*)buffer, 100, &cbRead );
								}
							}
						case DBTYPE_WSTR:
							{
								WCHAR buffer[101];
								ULONG cbRead = 0;
								hres = spStream->Read( (void*)buffer, 200, &cbRead );
								while( SUCCEEDED(hres) && cbRead > 0 )
								{
									buffer[cbRead/2] = 0;
									printf( "%S", buffer );
									hres = spStream->Read( (void*)buffer, 200, &cbRead );
								}
							}
						case DBTYPE_BYTES:
							{
								BYTE buffer[100];
								ULONG cbRead = 0;
								hres = spStream->Read( (void*)buffer, 100, &cbRead );
								while( SUCCEEDED(hres) && cbRead > 0 )
								{
									char szHex[3];
									szHex[2] = 0;
									for( ULONG n = 0; n < cbRead; n++ )
									{
										d2h( buffer[n], szHex );
										printf( "%s", szHex );
									}
									hres = spStream->Read( (void*)buffer, 100, &cbRead );
								}
							}
						}
					}
				}
				// the following three cases will handle BLOBs binded by reference in provider allocated, user owned memory
				else if( dbtype == (DBTYPE_WSTR & DBTYPE_BYREF) )
				{
					WCHAR** ppData = (WCHAR**)rs.GetValue( col );
					ATLASSERT( *ppData != NULL );
					printf( "%S", *ppData );
				}
				else if( dbtype == (DBTYPE_STR & DBTYPE_BYREF) )
				{
					CHAR** ppData = (CHAR**)rs.GetValue( col );
					ATLASSERT( *ppData != NULL );
					printf( "%s", *ppData );
				}
				else if( dbtype == (DBTYPE_BYTES & DBTYPE_BYREF) )
				{
					char buffer[3];
					buffer[2] = 0;
					BYTE** ppData = (BYTE**)rs.GetValue( col );
					ATLASSERT( *ppData != NULL );
					BYTE* pData = *ppData;
					DBORDINAL nLength;
					rs.GetLength(col, &nLength);
					printf( "{%d bytes: ", nLength );
					for( DBORDINAL i = 0; i < nLength; i++ )
					{
						d2h( pData[i], buffer );
						printf( "%s", buffer );
					}
					printf( " }" );
				}
				else
				{
					switch( dbtype )
					{
					case DBTYPE_STR:
						{
							CHAR* pData = (CHAR*)rs.GetValue( col );
							if( pData != NULL )
								printf( "%s", pData );
							else
								printf( "<<N/A>>" ); // we did not bind the value
						}
						break;
					case DBTYPE_WSTR:
						{
							WCHAR* pData = (WCHAR*)rs.GetValue( col );
							if( pData != NULL )
								printf( "%S", pData );
							else
								printf( "<<N/A>>" ); // we did not bind the value
						}
						break;
					case DBTYPE_BYTES:
						{
							char buffer[3];
							buffer[2] = 0;
							BYTE* pData = (BYTE*)rs.GetValue( col );
							if( pData != NULL )
							{
								DBORDINAL nLength;
								rs.GetLength(col, &nLength);
								printf( "{%d bytes: ", nLength );
								for( DBORDINAL i = 0; i < nLength; i++ )
								{
									d2h( pData[i], buffer );
									printf( "%s", buffer );
								}
								printf( " }" );
							}
							else
								printf( "<<N/A>>" ); // we did not bind the value
						}
						break;
					case DBTYPE_I2:
						printf( "%d", *(SHORT*)rs.GetValue( col ) );
						break;
					case DBTYPE_I4:
						printf( "%d", *(LONG*)rs.GetValue( col ) );
						break;
					case DBTYPE_I1:
						printf( "%d", *(signed char*)rs.GetValue( col ) );
						break;
					case DBTYPE_UI2:
						printf( "%ud", *(USHORT*)rs.GetValue( col ) );
						break;
					case DBTYPE_UI4:
						printf( "%ud", *(ULONG*)rs.GetValue( col ) );
						break;
					case DBTYPE_I8:
						printf( "%I64d", *(__int64*)rs.GetValue( col ) );
						break;
					case DBTYPE_UI8:
						printf( "%I64ud", *(unsigned __int64*)rs.GetValue( col ) );
						break;
					case DBTYPE_R4:
						printf( "%f", *(float*)rs.GetValue( col ) );
						break;
					case DBTYPE_R8:
						printf( "%f", *(double*)rs.GetValue( col ) );
						break;
					case DBTYPE_CY:
						{
							CURRENCY* pCurrency = (CURRENCY*)rs.GetValue( col );
							printf( "%I64d", pCurrency->int64 );
						}
						break;
					case DBTYPE_BSTR:
						printf( "%S", *(BSTR*)rs.GetValue( col ) );
						break;
					case DBTYPE_IDISPATCH:
						printf( "%p", *(void**)rs.GetValue( col ) );
						break;
					case DBTYPE_BOOL:
						printf( "%d", *(BOOL*)rs.GetValue( col ) );
						break;
					case DBTYPE_VARIANT:
						{
							VARIANT var;
							if (S_OK == VariantChangeType(&var, (VARIANT*)rs.GetValue( col ), 0, VT_BSTR)) {
								printf( "%S", var.bstrVal );
							} else {
								printf( "<<failed>>" );
							}
						}
						break;
					case DBTYPE_DECIMAL:
						{
							VARIANT var1, var2;
							var1.decVal = *(DECIMAL*)rs.GetValue( col );
							var1.vt = VT_DECIMAL;
							if (S_OK == VariantChangeType(&var2, &var1, 0, VT_BSTR)) {
								printf( "%S", var2.bstrVal );
							} else {
								printf( "<<failed>>" );
							}
						}
						break;
					case DBTYPE_UI1:
						printf( "%ud", *(BYTE*)rs.GetValue( col ) );
						break;
					case DBTYPE_DBDATE:
						{
							DBDATE* pDate = (DBDATE*)rs.GetValue( col );
							printf( "%d/%d/%d", pDate->month, pDate->day, pDate->year );
						}
						break;
					case DBTYPE_DBTIME:
						{
							DBTIME* pTime = (DBTIME*)rs.GetValue( col );
							printf( "%d:%d:%d", pTime->hour, pTime->minute, pTime->second );
						}
						break;
					case DBTYPE_DBTIMESTAMP:
						{
							DBTIMESTAMP* pts = (DBTIMESTAMP*)rs.GetValue( col );
							printf( "%d/%d/%d@%d:%d:%d.%d", pts->month, pts->day, pts->year, pts->hour, pts->minute, pts->second, pts->fraction );
						}
						break;
						// the following case will handle BLOBs binded as STREAM
					default:
						printf( "<<unhandled>>" );
					} // switch
				} // if
			} // if
		} // for

		printf( "\n" );

		hr = rs.MoveNext();
	} // while

	printf( "\n" );
}

template<>
void PrintAccessorData< CCommand<CDynamicStringAccessor> >( CCommand<CDynamicStringAccessor>& rs )
{
	// print column info
	for( DBORDINAL col = 1; col <= rs.GetColumnCount(); col++ )
	{
		DBTYPE dbtype;
		rs.GetColumnType( col, &dbtype );
		if( col > 1 )
			printf( ", " );
		printf( "%S [%d]", rs.GetColumnName( col ), dbtype );
	}

	printf( "\n" );

	// print rowset data
	HRESULT hr = rs.MoveNext();
	while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )
	{
		for( DBORDINAL col = 1; col <= rs.GetColumnCount(); col++ )
		{
			DBSTATUS dStatus;
			DBLENGTH nLength;
			
			rs.GetStatus( col, &dStatus );
			rs.GetLength( col, &nLength );

			if( col > 1 )
				printf( ", " );

			if( FAILED( dStatus ) )
				printf( "<<ERROR>>" );
			else if( dStatus == DBSTATUS_S_ISNULL )
				printf( "<<NULL>>" );
			else
			{
				CHAR* pData = rs.GetString( col );
				ATLASSERT( pData != NULL );
				printf( "%s", pData );
			}
		}

		printf( "\n" );
		hr = rs.MoveNext();
	}
	printf( "\n" );
}

template<>
void PrintAccessorData< CCommand<CXMLAccessor> >( CCommand<CXMLAccessor>& rs )
{
	CStringW csBuffer;

	// print column info
	if( SUCCEEDED( rs.GetXMLColumnData( csBuffer ) ) )
		printf( "%S\n", (LPCWSTR)csBuffer );
	else
		printf( "Unable to retrieve column info\n" );

	// print rowset data
	HRESULT hr = rs.MoveNext();
	while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )
	{
		if( SUCCEEDED( rs.GetXMLRowData( csBuffer ) ) )
			printf( "%S\n", (LPCWSTR)csBuffer );
		else
			printf( "Unable to retrieve row data\n" );

		hr = rs.MoveNext();
	}
	printf( "\n" );
}

