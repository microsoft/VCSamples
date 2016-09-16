// DynamicConsumer.cpp : Defines the entry point for the console application.
//
// This is a part of the ActiveX Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// ActiveX Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// ActiveX Template Library product.

#include "stdafx.h"
#include "ConsoleIO.h"
#include "PrintData.h"

#pragma warning( disable : 4100 )

struct CSchemaTableInfo
{
	CString csSchema;
	CString csName;

	CSchemaTableInfo()
	{
	}

	CSchemaTableInfo( const CSchemaTableInfo& other )
	{
		csSchema = other.csSchema;
		csName = other.csName;
	}

	CSchemaTableInfo& operator=( const CSchemaTableInfo& other )
	{
		if( &other != this )
		{
			csSchema = other.csSchema;
			csName = other.csName;
		}
		return *this;
	}
};

void d2h( BYTE n, char* pszHex )
{
	ATLENSURE( pszHex != NULL );
	pszHex[0] = n / 16;
	pszHex[1] = n % 16;

	if( pszHex[0] > 9 )
		pszHex[0] += 'a' - 10;
	else
		pszHex[0] += '0';

	if( pszHex[1] > 9 )
		pszHex[1] += 'a' - 10;
	else
		pszHex[1] += '0';
}

void GetProviderInfo( CDataSource& ds, CString& csQuote, bool& bSQLServer )
{
	HRESULT hr;
	CComPtr<IDBInfo> spDBInfo;

	bSQLServer = false;
	CComVariant var;
	hr = ds.GetProperty( DBPROPSET_DATASOURCEINFO, DBPROP_PROVIDERNAME, &var );
	if( SUCCEEDED(hr) )
	{
		if( _wcsicmp( var.bstrVal, L"sqloledb.dll" ) == 0 )
			bSQLServer = true;
	}

	//  get the quote literal
	csQuote = "\"";
	hr = ds.m_spInit->QueryInterface( &spDBInfo );
	if( SUCCEEDED( hr ) )
	{
		CComHeapPtr<DBLITERALINFO> spLiteralInfo;
		CComHeapPtr<OLECHAR> spStringBuffer;
		DBLITERAL rgLiteral[1];
		ULONG nDummy = 0;

		hr = spDBInfo->GetLiteralInfo( 1, rgLiteral, &nDummy, &spLiteralInfo, &spStringBuffer );
		if( SUCCEEDED(hr) )
		{
			csQuote = spLiteralInfo->pwszLiteralValue;
		}
	}
}

HRESULT SelectProcedure( CDataSource& ds, CSession& ss, CString& csSQL )
{
	CString csQuote;
	bool bSQLServer = false;

	GetProviderInfo( ds, csQuote, bSQLServer );

	CAtlArray< CSchemaTableInfo > objectsList;
	int nCount = 0;

	CProcedures rs;
	HRESULT hr = rs.Open( ss );
	if( FAILED(hr) )
	{
		printf( "Unable to open the PROCEDURES schema to get the list of available procedures\n" );
		return E_FAIL;
	}

	hr = rs.MoveFirst();
	printf( "#\tschema\tname\tdescription\n" );
	while( SUCCEEDED( hr ) && hr != DB_S_ENDOFROWSET )
	{
		CSchemaTableInfo info;
		info.csSchema = rs.m_szSchema;
		info.csName = rs.m_szName;
		objectsList.Add( info );
		nCount++;

		printf( "%d\t%s\t%s\t%s\n", nCount, rs.m_szSchema, rs.m_szName, rs.m_szDescription );
		hr = rs.MoveNext();
	}

	if( nCount == 0 )
	{
		printf( "No procedures are available\n" );
		return E_FAIL;
	}

	char szPrompt[30];
	sprintf_s( szPrompt, 30, "Enter 1-%d to continue: ", nCount );
	int nObjectIndex = select( szPrompt, nCount );
	if( nObjectIndex < 0 )
		return E_FAIL;

	nObjectIndex--;

	CString csSchema;
	CString csName;
	CString csObjectName;

	if( objectsList[nObjectIndex].csSchema.Find( ' ' ) >= 0 )
		csSchema = csQuote + objectsList[nObjectIndex].csSchema + csQuote;
	else
		csSchema = objectsList[nObjectIndex].csSchema;

	if( objectsList[nObjectIndex].csName.Find( ' ' ) >= 0 )
		csName += csQuote + objectsList[nObjectIndex].csName + csQuote;
	else
		csName += objectsList[nObjectIndex].csName;

	if( ! csSchema.IsEmpty() )
	{
			csObjectName = csSchema + '.';
	}
	csObjectName += csName;

	CString csRetVal;
	CString csParams;
	CProcedureParameters rs2;
	hr = rs2.Open( ss, NULL, csSchema, csName );
	if( FAILED(hr) )
	{
		printf( "Unable to open the PROCEDURE_PARAMETERS schema to get the procedure parameters\n" );
		return E_FAIL;
	}
	hr = rs2.MoveFirst();
	while( SUCCEEDED(hr) && hr != DB_S_ENDOFROWSET )
	{
		if( rs2.m_nType == DBPARAMTYPE_RETURNVALUE )
		{
			csRetVal = " ? = ";
			hr = rs2.MoveNext();
			continue;
		}

		if( csParams.IsEmpty() )
			csParams = "?";
		else
			csParams += ", ?";

		hr = rs2.MoveNext();
	}

	if( bSQLServer )
	{
		csSQL.Format( "{%sCALL %s( %s )}", csRetVal, csObjectName, csParams );
	}
	else
	{
		csSQL.Format( "EXEC %s", csObjectName );
	}

	return S_OK;
}

HRESULT SelectTable( CDataSource& ds, CSession& ss, CString& csSQL )
{
	CString csQuote;
	bool bSQLServer = false;

	GetProviderInfo( ds, csQuote, bSQLServer );

	CAtlArray< CSchemaTableInfo > objectsList;
	int nCount = 0;

	CTables rs;
	HRESULT hr = rs.Open( ss, NULL, NULL, NULL, "TABLE" );
	if( FAILED(hr) )
	{
		printf( "Unable to open the TABLES schema to get the list of available tables\n" );
		return E_FAIL;
	}

	hr = rs.MoveFirst();
	printf( "#\tschema\tname\tdescription\n" );
	while( SUCCEEDED( hr ) && hr != DB_S_ENDOFROWSET )
	{
		CSchemaTableInfo info;
		info.csSchema = rs.m_szSchema;
		info.csName = rs.m_szName;
		objectsList.Add( info );
		nCount++;

		printf( "%d\t%s\t%s\t%s\n", nCount, rs.m_szSchema, rs.m_szName, rs.m_szDescription );
		hr = rs.MoveNext();
	}

	if( nCount == 0 )
	{
		printf( "No tables are available\n" );
		return E_FAIL;
	}

	char szPrompt[30];
	sprintf_s( szPrompt, 30, "Enter 1-%d to continue: ", nCount );
	int nObjectIndex = select( szPrompt, nCount );
	if( nObjectIndex < 0 )
		return E_FAIL;

	nObjectIndex--;

	CString csObjectName;
	if( ! objectsList[nObjectIndex].csSchema.IsEmpty() )
	{
		if( objectsList[nObjectIndex].csSchema.Find( ' ' ) >= 0 )
			csObjectName = csQuote + objectsList[nObjectIndex].csSchema + csQuote + '.';
		else
			csObjectName = objectsList[nObjectIndex].csSchema + '.';
	}
	if( objectsList[nObjectIndex].csName.Find( ' ' ) >= 0 )
		csObjectName += csQuote + objectsList[nObjectIndex].csName + csQuote;
	else
		csObjectName += objectsList[nObjectIndex].csName;

	csSQL.Format( "SELECT * FROM %s", csObjectName );

	return S_OK;
}

void UseDynamicAccessor()
{
	HRESULT hr;
	CDataSource ds;
	CSession ss;
	CCommand<CDynamicAccessor> rs;
	CString csSQL;

	printf( "CDynamicAccessor example\n\n" );
	printf( "How do you want to handle BLOBs?\n" );
	printf( "1 - as ISequentialStream/IStream (default)\n" );
	printf( "2 - by reference in provider allocated, consumer owned memory\n" );
	printf( "3 - skip BLOBs\n" );

	int nBlobHandling = select( "Enter 1-3 to continue: ", 3 );
	if( nBlobHandling < 0 )
		return;

	// connect to the database
	hr = ds.Open();
	ATLASSERT( SUCCEEDED( hr ) );

	// get the access session
	hr = ss.Open( ds );
	ATLASSERT( SUCCEEDED( hr ) );

	hr = SelectTable( ds, ss, csSQL );
	if( FAILED( hr ) )
	{
		printf( "Failed to select a table and/or generate a SQL command\n" );
		return;
	}

	// Set the blob handling parameters:
	// rs.SetBlobSizeLimit() specifies the minimum size of a column to be treated as a BLOB
	// rs.SetBlobHandling() specifies how columns containing BLOBs are handled.

	// we use the default blob size limit, which is 8000
	switch( nBlobHandling )
	{
	case 1:
		rs.SetBlobHandling( DBBLOBHANDLING_DEFAULT );
		break;
	case 2:
		rs.SetBlobHandling( DBBLOBHANDLING_NOSTREAMS );
		break;
	case 3:
		rs.SetBlobHandling( DBBLOBHANDLING_SKIP );
		break;
	}

	CDBPropSet pset( DBPROPSET_ROWSET );
	pset.AddProperty( DBPROP_ISequentialStream, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_IStream, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL );
	hr = rs.Open( ss, csSQL, &pset );
	if( FAILED( hr ) )
	{
		printf( "Failed to open the rowset\n" );
		return;
	}

	PrintAccessorData( rs );
}

void UseDynamicStringAccessor()
{
	HRESULT hr;
	CDataSource ds;
	CSession ss;
	CCommand<CDynamicStringAccessor> rs;
	CString csSQL;

	printf( "CDynamicStringAccessor example\n\n" );

	// connect to the database
	hr = ds.Open();
	ATLASSERT( SUCCEEDED( hr ) );

	// get the access session
	hr = ss.Open( ds );
	ATLASSERT( SUCCEEDED( hr ) );

	hr = SelectTable( ds, ss, csSQL );
	if( FAILED( hr ) )
	{
		printf( "Failed to select a table and/or generate a SQL command\n" );
		return;
	}

	printf( "Executing \"%s\"\n", (LPCTSTR)csSQL );

	CDBPropSet pset( DBPROPSET_ROWSET );
	pset.AddProperty( DBPROP_ISequentialStream, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_IStream, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL );
	hr = rs.Open( ss, csSQL, &pset );
	if( FAILED( hr ) )
	{
		printf( "Failed to open the rowset\n" );
		return;
	}

	PrintAccessorData( rs );
}

void UseXMLAccessor()
{
	HRESULT hr;
	CDataSource ds;
	CSession ss;
	CCommand<CXMLAccessor> rs;
	CString csSQL;

	printf( "CXMLAccessor example\n\n" );

	// connect to the database
	hr = ds.Open();
	ATLASSERT( SUCCEEDED( hr ) );

	// get the access session
	hr = ss.Open( ds );
	ATLASSERT( SUCCEEDED( hr ) );

	hr = SelectTable( ds, ss, csSQL );
	if( FAILED( hr ) )
	{
		printf( "Failed to select a table and/or generate a SQL command\n" );
		return;
	}

	printf( "Executing \"%s\"\n", (LPCTSTR)csSQL );

	CDBPropSet pset( DBPROPSET_ROWSET );
	pset.AddProperty( DBPROP_ISequentialStream, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_IStream, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL );
	hr = rs.Open( ss, csSQL, &pset );
	if( FAILED( hr ) )
	{
		printf( "Failed to open the rowset\n" );
		return;
	}

	PrintAccessorData( rs );
}

void UseDynamicParameterAccessor()
{
	CDataSource ds;
	CSession ss;
	CCommand<CDynamicParameterAccessor> rs;
	CString csSQL;
	HRESULT hr;

	printf( "CDynamicParameterAccessor example\n\n" );

	// connect to the database
	hr = ds.Open();
	ATLASSERT( SUCCEEDED( hr ) );

	// get the access session
	hr = ss.Open( ds );
	ATLASSERT( SUCCEEDED( hr ) );

	hr = SelectProcedure( ds, ss, csSQL );
	if( FAILED( hr ) )
	{
		printf( "Failed to select a procedure and/or generate a SQL command\n" );
		return;
	}

	printf( "Executing \"%s\"\n", (LPCTSTR)csSQL );

	CDBPropSet pset( DBPROPSET_ROWSET );
	pset.AddProperty( DBPROP_ISequentialStream, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_IStream, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_CANFETCHBACKWARDS, true, DBPROPOPTIONS_OPTIONAL );
	pset.AddProperty( DBPROP_CANSCROLLBACKWARDS, true, DBPROPOPTIONS_OPTIONAL );
	//hr = rs.Open( ss, csSQL, &pset, NULL, DBGUID_DBSQL, false );
	hr = rs.Create( ss, csSQL );
	hr = rs.Prepare();

	void* pDummy;

	hr = rs.BindParameters( &(rs.m_hParameterAccessor), rs.m_spCommand, &pDummy, true, true );
	if( FAILED( hr ) )
	{
		printf( "Failed to bind parameters\n" );
		return;
	}

	DBORDINAL nParamCount = rs.GetParamCount();
	printf( "The procedure has %d parameters\n", nParamCount );

	for( DBORDINAL i = 1; i <= nParamCount; i++ )
	{
		DBTYPE dType;
		DBLENGTH dLength;
		DBPARAMIO dParamIO;

		rs.GetParamSize( i, &dLength );
		rs.GetParamType( i, &dType );
		rs.GetParamIO( i, &dParamIO );

		char* pszDescription = NULL;
		switch( dType )
		{
		case DBTYPE_STR:
			pszDescription = "CHAR[]";
			break;
		case DBTYPE_WSTR:
			pszDescription = "WCHAR[]";
			break;
		case DBTYPE_I1:
			pszDescription = "signed char";
			break;
		case DBTYPE_I2:
			pszDescription = "SHORT";
			break;
		case DBTYPE_I4:
			pszDescription = "LONG";
			break;
		case DBTYPE_I8:
			pszDescription = "__int64";
			break;
		case DBTYPE_UI1:
			pszDescription = "BYTE";
			break;
		case DBTYPE_UI2:
			pszDescription = "USHORT";
			break;
		case DBTYPE_UI4:
			pszDescription = "ULONG";
			break;
		case DBTYPE_UI8:
			pszDescription = "unsigned __int64";
			break;
		case DBTYPE_R4:
			pszDescription = "float";
			break;
		case DBTYPE_R8:
			pszDescription = "double";
			break;
		case DBTYPE_DBDATE:
			pszDescription = "DBDATE";
			break;
		case DBTYPE_DBTIME:
			pszDescription = "DBTIME";
			break;
		case DBTYPE_DBTIMESTAMP:
			pszDescription = "DBTIMESTAMP";
			break;
		default:
			pszDescription = "Unhandled";
		}

		if( (dParamIO & DBPARAMIO_INPUT) && (dParamIO & DBPARAMIO_OUTPUT) )
			printf( "Parameter %d \"%S\" (INPUT/OUTPUT) is of type %s\n", i, rs.GetParamName( i ), pszDescription );
		else if( dParamIO & DBPARAMIO_INPUT )
			printf( "Parameter %d \"%S\" (INPUT) is of type %s\n", i, rs.GetParamName( i ), pszDescription );
		else if( dParamIO & DBPARAMIO_OUTPUT )
			printf( "Parameter %d \"%S\" (OUTPUT) is of type %s\n", i, rs.GetParamName( i ), pszDescription );
		else
			printf( "Parameter %d \"%S\" (Unknown I/O) is of type %s\n", i, rs.GetParamName( i ), pszDescription );

		if( dParamIO  & DBPARAMIO_INPUT )
		{
			int option = 1;
			if( strcmp( pszDescription, "Unhandled" ) == 0 )
			{
				printf( "For simplicity, we do not support this data type in this sample.\n" );
				printf( "We will use the DEFAULT value here...\n" );
			}
			else
			{
				printf( "What value do you want to set the parameter to?\n" );
				printf( "1 - DEFAULT\n" );
				printf( "2 - NULL\n" );
				printf( "3 - IGNORE\n" );
				printf( "4 - User provided (default)\n" );
				option = select( "Enter 1-4 to continue: ", 4 );
			}

			switch( option )
			{
			case 1:
				rs.SetParamStatus( i, DBSTATUS_S_DEFAULT );
				break;
			case 2:
				rs.SetParamStatus( i, DBSTATUS_S_ISNULL );
				break;
			case 3:
				rs.SetParamStatus( i, DBSTATUS_S_IGNORE );
				break;
			case 4:
				DBLENGTH cbParamSize;
				rs.GetParamSize( i, &cbParamSize );
				switch( dType )
				{
				case DBTYPE_STR:
					{
						CHAR* pszBuffer = new CHAR[cbParamSize+10]; // we allocate extra 10 characters in 
																	// case the user enters a string that is too large
						char szPrompt[80];
						sprintf_s( szPrompt, 80, "Enter the string value (max %d characters)\n", cbParamSize-1 );
						promptStr( pszBuffer, szPrompt );
						rs.SetParamString( i, pszBuffer );
						delete [] pszBuffer;
					}
					break;
				case DBTYPE_WSTR:
					{
						WCHAR* pszBuffer = new WCHAR[cbParamSize/2+10]; // we allocate extra 10 characters in 
																		// case the user enters a string that is too large
						char szPrompt[80];
						sprintf_s( szPrompt, 80, "Enter the string value (max %d characters)\n", cbParamSize/2-1 );
						promptStr( pszBuffer, szPrompt );
						rs.SetParamString( i, pszBuffer );
						delete [] pszBuffer;
					}
					break;
				case DBTYPE_I1:
					{
						signed char nData;
						prompt( nData, "Enter the value (signed char): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_I2:
					{
						SHORT nData;
						prompt( nData, "Enter the value (SHORT): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_I4:
					{
						LONG nData;
						prompt( nData, "Enter the value (LONG): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_I8:
					{
						__int64 nData;
						prompt( nData, "Enter the value (__int64): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_UI1:
					{
						BYTE nData;
						prompt( nData, "Enter the value (BYTE): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_UI2:
					{
						USHORT nData;
						prompt( nData, "Enter the value (USHORT): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_UI4:
					{
						ULONG nData;
						prompt( nData, "Enter the value (ULONG): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_UI8:
					{
						unsigned __int64 nData;
						prompt( nData, "Enter the value (unsigned __int64): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_R4:
					{
						float nData;
						prompt( nData, "Enter the value (float): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_R8:
					{
						double nData;
						prompt( nData, "Enter the value (double): " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_DBDATE:
					{
						DBDATE nData;
						prompt( nData, "Enter the date: " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_DBTIME:
					{
						DBTIME nData;
						prompt( nData, "Enter the time: " );
						rs.SetParam( i, &nData );
					}
					break;
				case DBTYPE_DBTIMESTAMP:
					{
						DBTIMESTAMP nData;
						prompt( nData, "Enter the date/time: " );
						rs.SetParam( i, &nData );
					}
					break;
				default:
					ATLASSERT(FALSE); // we should never have got here...
				} // switch
				break;
			} // switch( option )
		}
		else
		{
			rs.SetParamStatus( i, DBSTATUS_S_IGNORE );
		} // if( dParamIO  & DBPARAMIO_INPUT )
	} // for( DBORDINAL i = 1; i <= nParamCount; i++ )

	// Execute the command
	hr=rs.Open(NULL,NULL,0);
	if( FAILED(hr) )
	{
		printf( "Failed to execute the command!\n" );
		return;
	}

	if( rs.m_spRowset != NULL )
	{
		hr = rs.Bind();
		if( FAILED(hr) )
		{
			printf( "Failed to bind the result rowset!\n" );
			return;
		}
		PrintAccessorData( rs );
	}
	else
	{
		printf( "The command did not return a result rowset\n" );
		printf( "nothing to display...\n" );
	}
}

int main(int argc, char* argv[])
{
	HRESULT hr;
	
	hr = CoInitialize(NULL);
	ATLASSERT( SUCCEEDED( hr ) );

	printf( "Dynamic Accessor Sample\n\n" );
	printf( "Which accessor do you want to use?\n" );
	printf( "1 - CDynamicAccessor\n" );
	printf( "2 - CDynamicStringAccessor\n" );
	printf( "3 - CXMLAccessor\n" );
	printf( "4 - CDynamicParameterAccessor\n" );

	int option = select( "Enter 1-4 to continue: ", 4 );
	switch( option )
	{
	case 1:
		UseDynamicAccessor();
		break;
	case 2:
		UseDynamicStringAccessor();
		break;
	case 3:
		UseXMLAccessor();
		break;
	case 4:
		UseDynamicParameterAccessor();
		break;
	}

	CoUninitialize();
	return 0;
}
