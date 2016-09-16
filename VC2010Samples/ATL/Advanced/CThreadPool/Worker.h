// File: Worker.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once

LONG g_lCurrId = -1;

class CMyWorker
{
public:
    typedef DWORD_PTR RequestType;

	CMyWorker() : m_dwExecs( 0 )
	{
		m_lId = InterlockedIncrement( &g_lCurrId );
	}

    virtual BOOL Initialize(void *pvParam)
    {
		printf("[%d]: CMyWorker.Initialize(%d)\n", (DWORD_PTR)::GetCurrentThreadId(), (DWORD_PTR)pvParam );
		return TRUE;
    }

    virtual void Terminate(void* /*pvParam*/)
    {
		printf( "CMyWorker #%d exec'd %d times.\n", m_lId, m_dwExecs );
	}

	void Execute(RequestType dw, void *pvParam, OVERLAPPED* pOverlapped) throw()
    {
        ATLASSERT(pvParam != NULL);

		printf("[%d] CMyWorker::Execute(dw=%d, pvParam=%d, pOverlapped=%d\n", 
			::GetCurrentThreadId(), dw, (DWORD_PTR)pvParam, (DWORD_PTR)pOverlapped);

		CTaskBase* pTask = (CTaskBase*)(DWORD_PTR)dw;
		pTask->DoTask(pvParam, pOverlapped);

		m_dwExecs++;
	}

    virtual BOOL GetWorkerData(DWORD /*dwParam*/, void ** /*ppvData*/)
    {
        return FALSE;
    }

protected:
	DWORD	m_dwExecs;
	LONG	m_lId;
}; // CMyWorker
