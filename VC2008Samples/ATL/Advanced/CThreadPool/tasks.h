// File: tasks.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once

///////////////////////////////////////////////////////////////////////////////
class CTaskBase
{
public:
	virtual void DoTask(void *pvParam, OVERLAPPED *pOverlapped)=0;
};

///////////////////////////////////////////////////////////////////////////////
class CTask1 : public CTaskBase
{
public:
	virtual void DoTask(void *pvParam, OVERLAPPED *pOverlapped)
	{
		printf("[%d]: CTask1::DoTask(pvParam=%d, pOverlapped=%d)\n",
			::GetCurrentThreadId(), (DWORD_PTR)pvParam, (DWORD_PTR)pOverlapped);
	}
};


///////////////////////////////////////////////////////////////////////////////
class CTask2 : public CTaskBase
{
public:
	virtual void DoTask(void *pvParam, OVERLAPPED *pOverlapped)
	{
		printf("[%d]: CTask2::DoTask(pvParam=%d, pOverlapped=%d)\n",
			::GetCurrentThreadId(), (DWORD_PTR)pvParam, (DWORD_PTR)pOverlapped);
	}
};

///////////////////////////////////////////////////////////////////////////////
typedef CSimpleArray<CTaskBase*> CTaskArray;

///////////////////////////////////////////////////////////////////////////////
bool CreateTasks(CTaskArray& tasks, DWORD dwCount)
{
	bool bOk = false;
	if ( 0 == tasks.GetSize() && dwCount > 0 ) {
		CTaskBase* pTask = NULL;
		for ( DWORD i = 0; i < dwCount; i++ ) {
			if ( i % 2 )
				pTask = new CTask1;
			else
				pTask = new CTask2;
			if ( !tasks.Add( pTask ))
				ATLASSERT( false );
		}
		bOk = true;
	}
	return bOk;
}
