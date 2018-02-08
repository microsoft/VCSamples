// Created by Microsoft (R) C/C++ Compiler Version 14.11.25507.1
//
// c:\temp\vcsamples\vc2010samples\attributes\oledb\multiread\dbread.mrg.h
// compiler-generated file created 09/15/17 at 22:56:30
//
// This C++ source file is intended to be a representation of the
// source code injected by the compiler.  It may not compile or
// run exactly as the original source file.
//


//+++ Start Injected Code
[no_injected_text(true)];      // Suppress injected text, it has already been injected
#pragma warning(disable: 4543) // Suppress warnings about skipping injected text
#pragma warning(disable: 4199) // Suppress warnings from attribute providers

#pragma message("\n\nNOTE: This merged source file should be visually inspected for correctness.\n\n")
//--- End Injected Code

// File: DBRead.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include <atldbcli.h>

[
	db_source("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MultiRead.mdb"),
	db_table("Products")
]
class /*+++ symbol was renamed:  CProduct
 :---*/ _CProductAccessor  :
    /*+++ Added Baseclass */ public ATL::CDataConnection
{
public:
	[db_column(ordinal="1")] long		nProductID;
	[db_column(ordinal="2")] TCHAR	pName[80];
	[db_column(ordinal="3")] TCHAR	PhoneNumber[50];
	[db_column(ordinal="4")] TCHAR	Location[50];
	[db_column(ordinal="5")] TCHAR	Title[50];
	[db_column(ordinal="6")] TCHAR	Company[50];
	[db_column(ordinal="7")] TCHAR	Email[50];

	void GetRowsetProperties(CDBPropSet* pPropSet)
	{
		pPropSet->AddProperty(DBPROP_CANHOLDROWS, true);
	}

	//+++ Start Injected Code For Attribute 'db_table'
#injected_line 31 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\oledb\\multiread\\DBRead.h"
    HRESULT OpenDataSource() 
    {
        return CDataConnection::Open(OLESTR("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MultiRead.mdb"));
    }
#injected_line 14 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\oledb\\multiread\\DBRead.h"

    BEGIN_ACCESSOR_MAP(_CProductAccessor, 1)
        BEGIN_ACCESSOR(0, true)
        _COLUMN_ENTRY_CODE(1, _OLEDB_TYPE(nProductID),  _SIZE_TYPE(nProductID), 0, 0, offsetbuf(nProductID), 0, 0)
        _COLUMN_ENTRY_CODE(2, _OLEDB_TYPE(pName),  _SIZE_TYPE(pName), 0, 0, offsetbuf(pName), 0, 0)
        _COLUMN_ENTRY_CODE(3, _OLEDB_TYPE(PhoneNumber),  _SIZE_TYPE(PhoneNumber), 0, 0, offsetbuf(PhoneNumber), 0, 0)
        _COLUMN_ENTRY_CODE(4, _OLEDB_TYPE(Location),  _SIZE_TYPE(Location), 0, 0, offsetbuf(Location), 0, 0)
        _COLUMN_ENTRY_CODE(5, _OLEDB_TYPE(Title),  _SIZE_TYPE(Title), 0, 0, offsetbuf(Title), 0, 0)
        _COLUMN_ENTRY_CODE(6, _OLEDB_TYPE(Company),  _SIZE_TYPE(Company), 0, 0, offsetbuf(Company), 0, 0)
        _COLUMN_ENTRY_CODE(7, _OLEDB_TYPE(Email),  _SIZE_TYPE(Email), 0, 0, offsetbuf(Email), 0, 0)
    END_ACCESSOR()
    END_ACCESSOR_MAP()
        					

	//--- End Injected Code For Attribute 'db_table'
}

//+++ Start Injected Code For Attribute 'db_table'
#injected_line 14 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\oledb\\multiread\\DBRead.h"

class CProduct;

//--- End Injected Code For Attribute 'db_table'


//+++ Start Injected Code For Attribute 'db_table'
#injected_line 14 "c:\\temp\\vcsamples\\vc2010samples\\attributes\\oledb\\multiread\\DBRead.h"

class CProduct : public CTable<CAccessor<_CProductAccessor> >
    			
{
public:
    HRESULT OpenAll()
            {
        HRESULT hr;
        hr = OpenDataSource();
        if (FAILED(hr))
            return hr;
        return OpenRowset(m_session);
    }
    void CloseAll()
            {
        Close();
        CloseDataSource();
    }
    HRESULT OpenRowset(const CSession& session, LPCWSTR szCommand=NULL)
            {
        DBPROPSET *pPropSet = NULL;
        CDBPropSet propset(DBPROPSET_ROWSET);
        __if_exists(HasBookmark)
            	
        {
            if( HasBookmark() )
		{
                propset.AddProperty(DBPROP_IRowsetLocate, true);
                pPropSet= &propset;
            }
        }	
        __if_exists(GetRowsetProperties)
            	
        {
            GetRowsetProperties(&propset);
            pPropSet= &propset;
        }
        if (szCommand == NULL)
            szCommand = L"Products";
        HRESULT hr = Open(session, szCommand,pPropSet);
#ifdef _DEBUG
        if(FAILED(hr))
            AtlTraceErrorRecords(hr);
#endif
        return hr;
    }

};

//--- End Injected Code For Attribute 'db_table'
;



void ProcessRecord(CProduct* product)
{
	ATLTRACE("%d, %4d, %s\n", GetCurrentThreadId(), product->nProductID, product->pName);
}

HRESULT MoveAndProcess(CProduct* product)
{
	HRESULT hr;
	hr = product->MoveNext();
	if (hr == S_OK)
	{
		hr = product->GetData();
		ATLASSERT(SUCCEEDED(hr));
		ProcessRecord(product);
	} 
	return hr;
}

ULONG WINAPI ReadTable(CProduct* pProduct)
{
	HRESULT   hr;
	ULONG     nRows = 0;

	while ((hr=MoveAndProcess(pProduct)) == S_OK)
	{
		nRows++;
	}
	ATLTRACE("Thread %d processed %d records. Last HRESULT = %X\n", GetCurrentThreadId(), nRows, hr);
	return nRows;
}



HRESULT ReadRecords(int nThreads, DWORD* pdwTime, DWORD* pRowsProcessed)
{
	CProduct		db;
	HRESULT         hr;
	DWORD           dwTime;

	ATLTRACE("DoStuff: Started\n");
	hr = db.OpenDataSource();
	ATLASSERT(SUCCEEDED(hr));
	if (FAILED(hr))
		return hr;

	hr = db.OpenRowset(db);
	ATLASSERT(SUCCEEDED(hr));
	if (FAILED(hr))
		return hr;

	DWORD  idThread;
	int i;
	HANDLE* phThread = new HANDLE[nThreads];
	if (phThread == NULL)
		return E_FAIL;

	dwTime = GetTickCount();
	for (i=0; i<nThreads; i++)
	{
		*(phThread+i) = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReadTable, &db, 0, &idThread);
		if (*(phThread+i) == NULL)
			ATLTRACE(_T("Couldn't create thread %d\n"), i);
	}

	// Ensure all threads are finished before we end
	WaitForMultipleObjects(nThreads, phThread, TRUE, INFINITE);
	// Return the total time
	*pdwTime = GetTickCount() - dwTime;

	DWORD nTotalRows = 0, nRows;
	for (i=0; i<nThreads; i++)
	{
		GetExitCodeThread(*(phThread + i), &nRows);
		nTotalRows += nRows;
		CloseHandle(*(phThread + i));
	}
	*pRowsProcessed = nTotalRows;
	ATLTRACE("DoStuff: Ended\n");
	return S_OK;
}
