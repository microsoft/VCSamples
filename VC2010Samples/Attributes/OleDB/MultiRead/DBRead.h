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
class CProduct
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
};



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
