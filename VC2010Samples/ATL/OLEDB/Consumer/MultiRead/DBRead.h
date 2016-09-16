// File: DBRead.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include <atldbcli.h>

class CProduct
{
public:
	long ProductID;
	char Name[80];
	char PhoneNumber[50];
	char Location[50];
	char Title[50];
	char Company[50];
	char Email[50];

	BEGIN_COLUMN_MAP(CProduct)
		COLUMN_ENTRY(1, ProductID)
		COLUMN_ENTRY(2, Name)
		COLUMN_ENTRY(3, PhoneNumber)
		COLUMN_ENTRY(4, Location)
		COLUMN_ENTRY(5, Title)
		COLUMN_ENTRY(6, Company)
		COLUMN_ENTRY(7, Email)
	END_COLUMN_MAP()
};

void ProcessRecord(CProduct& product);

template <class TAccessor>
class CMyRowset : public CRowset<TAccessor>
{
public:
	HRESULT MoveAndProcess()
	{
		CProduct product;
		HRESULT hr;
		hr = MoveNext();
		if (hr == S_OK)
		{
			hr = GetDataHere(&product);
			ATLASSERT(SUCCEEDED(hr));
			ProcessRecord(product);
		}
		return hr;
	}
};

ULONG WINAPI ReadTable(CTable<CAccessor<CProduct>, CMyRowset>* pProduct)
{
	CMyRowset<CAccessor<CProduct> > rowset = *((CMyRowset<CAccessor<CProduct> >*)pProduct);
	HRESULT   hr;
	ULONG     nRows = 0;

	while ((hr=rowset.MoveAndProcess()) == S_OK)
	{
		nRows++;
	}
	ATLTRACE("Thread %d processed %d records. Last HRESULT = %X\n", GetCurrentThreadId(), nRows, hr);
	return nRows;
}

#ifndef _DEBUG
	#define UNUSED_RELEASE(x) x
#else
	#define UNUSED_RELEASE(x)
#endif

void ProcessRecord(CProduct& product)
{
	DWORD dwThreadId = GetCurrentThreadId();
	ATLTRACE("%d, %4d, %s\n", dwThreadId, product.ProductID, product.Name);
	UNUSED_RELEASE(product);
	UNUSED_RELEASE(dwThreadId);
}

HRESULT ReadRecords(int nThreads, DWORD* pdwTime, DWORD* pRowsProcessed)
{
	CDataSource     db;
	CSession        session;
	CTable<CAccessor<CProduct>, CMyRowset>  product;
	HRESULT         hr;
	DWORD           dwTime;

	ATLTRACE("DoStuff: Started\n");
	hr = db.OpenFromInitializationString( L"Provider=Microsoft.Jet.OLEDB.4.0;Data Source=MultiRead.mdb" );
	ATLASSERT(SUCCEEDED(hr));
	if (FAILED(hr))
		return hr;

	hr = session.Open(db);
	ATLASSERT(SUCCEEDED(hr));
	if (FAILED(hr))
		return hr;

	CDBPropSet propset(DBPROPSET_ROWSET);
	propset.AddProperty(DBPROP_CANHOLDROWS, true);

	hr = product.Open(session, _T("Products"), &propset);
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
		*(phThread+i) = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ReadTable, &product, 0, &idThread);
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
