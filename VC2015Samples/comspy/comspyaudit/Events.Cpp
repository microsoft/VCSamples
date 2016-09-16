// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#include "stdafx.h"
#include "ComSpyAudit.h"
#ifndef DBNTWIN32
#define DBNTWIN32
#include <SQL.h>
#include <SQLEXT.h>
#include <ODBCINST.h>
#endif // DBNTWIN32 
#include <ODBCINST.h>
#include "ComSpySqlAudit.h"
#include <strsafe.h>

#define SQL_EXEC(x)													\
	{																\
		RETCODE rc;													\
		rc = SQLExecDirect(m_hstmt, x, lstrlen(x));					\
	    if( rc != SQL_SUCCESS && rc != SQL_SUCCESS_WITH_INFO )		\
		{															\
			CComBSTR msg;											\
			GetError( m_henv, m_hdbc, m_hstmt, &msg.m_str);			\
			ATLTRACE(L"Warning! SQlExecDirec failed! Msg: ");		\
			ATLTRACE(msg.m_str);									\
			ATLTRACE(L"\n");										\
		}															\
	}



long CComSpySqlAudit::PerfCountToTickCount(LONGLONG perfCount)
{
	long TickCount = 0;
    if (m_PerformanceFrequency != 0)
        TickCount = (long)((1000 * perfCount) / m_PerformanceFrequency);

	return TickCount;
}





//////////////////////////Thread Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnThreadStart(
                LONGLONG perfCount,
                LPCOLESTR pszGuidApp,
				LPCOLESTR pszThreadID,
				LPCOLESTR pszW2KThreadID,
				DWORD dwThreadCnt)
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ThreadID, W2KThreadID, ThreadCnt) values ('%s',%d,'%s','%s','%s', %d)",
			 L"OnThreadStart",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 pszW2KThreadID,
			 dwThreadCnt);

	SQL_EXEC(m_sSQL);	
	return S_OK;
}


STDMETHODIMP CComSpySqlAudit::OnThreadTerminate(
                LONGLONG perfCount,
                LPCOLESTR pszGuidApp,
				LPCOLESTR pszThreadID,
				LPCOLESTR pszW2KThreadID,
				DWORD dwThreadCnt
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ThreadID, W2KThreadID, ThreadCnt) values ('%s',%d,'%s','%s','%s', %d)",
			 L"OnThreadTerminate",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 pszW2KThreadID,
			 dwThreadCnt);


	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnThreadBindToApartment(
							LONGLONG perfCount,
							LPCOLESTR pszGuidApp,
							LPCOLESTR pszThreadID,					
							LPCOLESTR pszAptID,	
							DWORD dwActivityCnt)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ThreadID, ApartmentID, ActivityCnt) values ('%s', %d,'%s','%s','%s', %d)",
			 L"OnThreadBindToApartment",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 pszAptID,
			 dwActivityCnt);


	SQL_EXEC(m_sSQL);
	return S_OK;
}


STDMETHODIMP CComSpySqlAudit::OnThreadUnBind(
							 LONGLONG perfCount,
							 LPCOLESTR pszGuidApp,
							 LPCOLESTR pszThreadID,					
							 LPCOLESTR pszAptID,	
							 DWORD dwActivityCnt
				)
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, Threadid, ApartmentID, ActivityCnt) values ('%s',%d,'%s','%s','%s', %d)",
			 L"OnThreadUnBind",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 pszAptID,
			 dwActivityCnt);

	SQL_EXEC(m_sSQL);
	return S_OK;
}


STDMETHODIMP CComSpySqlAudit::OnThreadAssignApartment(
							LONGLONG perfCount,
							LPCOLESTR pszGuidApp,
							LPCOLESTR pszGuidActivityID,
							LPCOLESTR pszAptID	)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ActivityID, ApartmentID) values ('%s',%d,'%s','%s','%s')",
			 L"OnThreadAssignApartment",
			 TickCount,
			 pszGuidApp,
			 pszGuidActivityID,
			 pszAptID);			


	SQL_EXEC(m_sSQL);
	return S_OK;
}



STDMETHODIMP CComSpySqlAudit::OnThreadUnassignApartment(
					 LONGLONG perfCount,
					 LPCOLESTR pszGuidApp,				
					 LPCOLESTR pszAptID	)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ApartmentID) values ('%s', %d,'%s','%s')",
			 L"OnThreadUnAssignApartment",
			 TickCount,
			 pszGuidApp,			 
			 pszAptID);			


	SQL_EXEC(m_sSQL);
	return S_OK;
}	
			

STDMETHODIMP CComSpySqlAudit::OnThreadWorkEnque(
					 LONGLONG perfCount,
					 LPCOLESTR pszGuidApp,
					 LPCOLESTR pszThreadID,					
					 LPCOLESTR MsgWorkID,	
					 DWORD dwQueueLen)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ThreadID, MsgWorkID,QueueLen) values ('%s', %d,'%s','%s','%s', %d)",
			 L"OnThreadWorkEnque",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 MsgWorkID,
			 dwQueueLen);			


	SQL_EXEC(m_sSQL);
	return S_OK;
}
				
STDMETHODIMP CComSpySqlAudit::OnThreadWorkPrivate(
					 LONGLONG perfCount,
					 LPCOLESTR pszGuidApp,
					 LPCOLESTR pszThreadID,					
					 LPCOLESTR MsgWorkID)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ThreadID, MsgWorkID) values ('%s', %d, '%s','%s','%s')",
			 L"OnThreadWorkPrivate",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 MsgWorkID);			

	SQL_EXEC(m_sSQL);
	return S_OK;
}					
				
STDMETHODIMP CComSpySqlAudit::OnThreadWorkPublic(
							 LONGLONG perfCount,
							 LPCOLESTR pszGuidApp,
							 LPCOLESTR pszThreadID,					
							 LPCOLESTR MsgWorkID,	
							 DWORD dwQueueLen)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ThreadID, MsgWorkID,QueueLen) values ('%s', %d,'%s','%s','%s', %d)",
			 L"OnThreadWorkPublic",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 MsgWorkID,
			 dwQueueLen);			


	SQL_EXEC(m_sSQL);
	return S_OK;
}
				
STDMETHODIMP CComSpySqlAudit::OnThreadWorkRedirect(
							LONGLONG perfCount,
							LPCOLESTR pszGuidApp,
							LPCOLESTR pszThreadID,					
							LPCOLESTR MsgWorkID,	
							DWORD dwQueueLen,
							LPCOLESTR pszThreadNum)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ThreadID, MsgWorkID,QueueLen, ThreadNum) values ('%s',%d,'%s','%s','%s', %d, '%s')",
			 L"OnThreadWorkPublic",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 MsgWorkID,
			 dwQueueLen,
			 pszThreadNum);			


	SQL_EXEC(m_sSQL);
	return S_OK;
}
				
STDMETHODIMP CComSpySqlAudit::OnThreadWorkReject(
							 LONGLONG perfCount,
							 LPCOLESTR pszGuidApp,
							 LPCOLESTR pszThreadID,					
							 LPCOLESTR MsgWorkID,	
							 DWORD dwQueueLen)				
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ThreadEvents (Event, TickCount, Application, ThreadID, MsgWorkID,QueueLen) values ('%s', %d,'%s','%s','%s', %d)",
			 L"OnThreadWorkPublic",
			 TickCount,
			 pszGuidApp,
			 pszThreadID,
			 MsgWorkID,
			 dwQueueLen);			

	SQL_EXEC(m_sSQL);
	return S_OK;

}			

//////////////////////////Application Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnAppActivation(
                LONGLONG perfCount,
                LPCOLESTR pszGuidApp                
            )
{
   long TickCount = PerfCountToTickCount(perfCount);
	
	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE,
			 L"insert into AppEvents values ('%s',%d,'%s')",
			 L"OnAppActivation",
			 TickCount, 
			 pszGuidApp);

	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnAppShutdown(
                LONGLONG perfCount,
                LPCOLESTR pszGuidApp               
            )
{
    long TickCount = PerfCountToTickCount(perfCount);
	
	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into AppEvents values ('%s',%d,'%s')",
			 L"OnAppShutdown",
			 TickCount, 
			 pszGuidApp);

	SQL_EXEC(m_sSQL);
	return S_OK;
}

//////////////////////////Transaction Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnTransactionStart(
                LONGLONG perfCount,			
                LPCOLESTR pszGuidApp,				
                LPCOLESTR pszGuidTxID,			
                LPCOLESTR pszGuidTSID,
				BOOL bRoot
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into TransactionEvents (Event,TickCount,Application, TransactionID, TSID, Root) \
				values ('%s',%d,'%s','%s','%s','%s' )",
			 L"OnTransactionStart",
			 TickCount, 
			 pszGuidApp,
			 pszGuidTxID,
			 pszGuidTSID,
			 (bRoot ? L"Yes" : L"No")
			 );

	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnTransactionPrepared(
                LONGLONG perfCount,			
                LPCOLESTR pszGuidApp,				
                LPCOLESTR pszGuidTxID,
				BOOL bVoteYes
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into TransactionEvents (Event,TickCount,Application, TransactionID, VoteYes) \
				values ('%s',%d,'%s','%s','%s' )",
			 L"OnTransactionPrepared",
			 TickCount, 
			 pszGuidApp,
			 pszGuidTxID,		
			 (bVoteYes ? L"Yes" : L"No")
			 );

	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnTransactionCommit(
                LONGLONG perfCount,			
                LPCOLESTR pszGuidApp,
				LPCOLESTR pszGuidTxID
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into TransactionEvents (Event,TickCount,Application, TransactionID) \
				values ('%s',%d,'%s','%s')",
			 L"OnTransactionCommit",
			 TickCount, 
			 pszGuidApp,
			 pszGuidTxID			 
			 );


	SQL_EXEC(m_sSQL);
	return S_OK;
}


STDMETHODIMP CComSpySqlAudit::OnTransactionAborted(
                LONGLONG perfCount,			
                LPCOLESTR pszGuidApp,
				LPCOLESTR pszGuidTxID
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into TransactionEvents (Event,TickCount,Application, TransactionID) \
				values ('%s',%d,'%s','%s')",
			 L"OnTransactionAborted",
			 TickCount, 
			 pszGuidApp,
			 pszGuidTxID			 
			 );


	SQL_EXEC(m_sSQL);
	return S_OK;
}


//////////////////////////Method Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnMethodCall(
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,  
                LPCOLESTR pszObjectID,
                LPCOLESTR pszGuidClassID,
                LPCOLESTR pszGuidInterfaceID,
                LPCOLESTR pszMethod
            )
{
    long TickCount = PerfCountToTickCount(perfCount);
    
	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE,
			 L"insert into MethodEvents (Event,TickCount, Application, ObjectID, ClassID, InterfaceID, Method) values('%s',%ld, '%s','%s', '%s', '%s', '%s')",			   			
			 L"OnMethodCall",
			 TickCount,
			 pszGuidApp,
			 pszObjectID,
			 pszGuidClassID,
			 pszGuidInterfaceID,
			 pszMethod			 
			 );

	ATLTRACE(L"OnMethodCall: m_sSQL = %s", m_sSQL);
	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnMethodReturn(
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp, 
                LPCOLESTR pszObjectID,
                LPCOLESTR pszGuidClassID,
                LPCOLESTR pszGuidInterfaceID,
                LPCOLESTR pszMethod,
                HRESULT hr,
				LPCOLESTR pszCallTime
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into MethodEvents  values ('%s', %d, '%s', '%s', '%s', '%s', '%s', %d, '%s')",
			 L"OnMethodReturn",
			 TickCount,
			 pszGuidApp, 
			 pszObjectID,
			 pszGuidClassID,
			 pszGuidInterfaceID,
			 pszMethod,
			 hr,
			 pszCallTime);

	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnMethodException(
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp, 
                LPCOLESTR pszObjectID,
                LPCOLESTR pszGuidClassID,
                LPCOLESTR pszGuidInterfaceID,
                LPCOLESTR pszMethod
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into MethodEvents (Event,TickCount, Application, ObjectID, ClassID, InterfaceID, Method) \
				values ('%s', %d, '%s', '%s', '%s', '%s', '%s')",
			 L"OnMethodException",
			 TickCount,
			 pszGuidApp, 
			 pszObjectID,
			 pszGuidClassID,
			 pszGuidInterfaceID,
			 pszMethod);

	SQL_EXEC(m_sSQL);
	return S_OK;
}


//////////////////////////Object Construction Events///////////////////////////////////
//share table with Object Events 
STDMETHODIMP CComSpySqlAudit::OnObjectConstruct(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszClassID, 
			 LPCOLESTR pszConstructString, 
			 LPCOLESTR pszObjectID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectEvents (Event,TickCount,Application, ClassID,ConstructString,ObjectID) \
				values ('%s', %d, '%s', '%s', '%s', '%s')",
			 L"OnObjectConstruct",
			 TickCount,
			 pszGuidApp,
			 pszClassID,
			 pszConstructString,
			 pszObjectID);

	SQL_EXEC(m_sSQL);


	return S_OK;
}

//////////////////////////Instance Events///////////////////////////////////
//share table with Object Events 
STDMETHODIMP CComSpySqlAudit::OnObjectCreate(
							LONGLONG perfCount,
							LPCOLESTR pszGuidApp,
							LPCOLESTR pszGuidActivityID,
							LPCOLESTR pszClassID,
							LPCOLESTR pszTSID,
							LPCOLESTR pszContextID,
							LPCOLESTR pszObjectID)            
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));

	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectEvents (Event, TickCount,Application, ActivityID, ClassID, TSID, ContextID,ObjectID) \
				values ('%s',%d, '%s', '%s', '%s', '%s', '%s', '%s')",
			 L"OnObjectCreate",
			 TickCount,
			 pszGuidApp,
			 pszGuidActivityID,
			 pszClassID,
			 pszTSID,
			 pszContextID,
			 pszObjectID); 

	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnObjectDestroy(
							LONGLONG perfCount,
							LPCOLESTR pszGuidApp,
							LPCOLESTR pszContextID
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));

	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectEvents (Event,TickCount,Application,ContextID) \
				values ('%s',%d, '%s', '%s')",
			 L"OnObjectDestroy",
			 TickCount,
			 pszGuidApp,			 
			 pszContextID);
			 
	SQL_EXEC(m_sSQL);

	return S_OK;
}

//////////////////////////Object Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnObjectActivate(
				LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID,
				LPCOLESTR pszObjectID	                
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectEvents (Event, TickCount,Application, ContextID,ObjectId) \
				values ('%s', %d,  '%s', '%s','%s')",
			 L"OnObjectActivate",
			 TickCount,
			 pszGuidApp,
			 pszContextID,
			 pszObjectID);

	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnObjectDeactivate(
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID,
				LPCOLESTR pszObjectID
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectEvents (Event, TickCount,Application, ContextID,ObjectId) \
				values ('%s', %d,  '%s', '%s','%s')",
			 L"OnObjectDeactivate",
			 TickCount,
			 pszGuidApp,
			 pszContextID,
			 pszObjectID);

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnDisableCommit(
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID				
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectEvents (Event, TickCount,Application, ContextID) \
				values ('%s', %d,  '%s', '%s')",
			 L"OnDisableCommit",
			 TickCount,
			 pszGuidApp,
			 pszContextID);

	SQL_EXEC(m_sSQL);


	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnEnableCommit(
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID	
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			  L"insert into ObjectEvents (Event, TickCount,Application, ContextID) \
				values ('%s', %d,  '%s', '%s')",
			 L"OnEnableCommit",
			 TickCount,
			 pszGuidApp,
			 pszContextID);

	SQL_EXEC(m_sSQL);


	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnSetComplete(
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectEvents (Event, TickCount,Application, ContextID) \
				values ('%s', %d,  '%s', '%s')",
			 L"OnSetComplete",
			 TickCount,
			 pszGuidApp,
			 pszContextID);

	SQL_EXEC(m_sSQL);


	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnSetAbort(
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectEvents (Event, TickCount,Application, ContextID) \
				values ('%s', %d,  '%s', '%s')",
			 L"OnSetAbort",
			 TickCount,
			 pszGuidApp,
			 pszContextID);

	SQL_EXEC(m_sSQL);


	return S_OK;
}


//////////////////////////Resource Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnResourceCreate(
					LONGLONG perfCount,
					LPCOLESTR pszGuidApp,					
					LPCOLESTR pszObjectID,
					LPCOLESTR pszType,
					LPCOLESTR pszResId,
					BOOL bEnlisted	
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ResourceEvents (Event,TickCount,Application, ObjectID, Type, ResourceID, Enlisted) \
				values ('%s',%d, '%s', '%s', '%s', '%s', '%s')",
			 L"OnResourceCreate",
			 TickCount, 
			 pszGuidApp,
			 pszObjectID,
			 pszType,
			 pszResId,	
			 (bEnlisted ? L"TRUE" : L"FALSE")
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnResourceAllocate(
                LONGLONG perfCount,	
				LPCOLESTR pszGuidApp,	
                LPCOLESTR pszObjectID,	
                LPCOLESTR pszType,	
                LPCOLESTR pszResId,
				BOOL bEnlisted,
				LPCOLESTR pszNumRated,
				LPCOLESTR pszRating
            )
{
    long TickCount = PerfCountToTickCount(perfCount);
	
	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ResourceEvents (Event,TickCount,Application, ObjectID, Type, ResourceID, Enlisted, NumRated, Rating) \
				values ('%s',%d, '%s', '%s', '%s', '%s', '%s', '%s', '%s')",
			 L"OnResourceAllocate",
			 TickCount, 
			 pszGuidApp,
			 pszObjectID,
			 pszType,
			 pszResId,	
			 bEnlisted ? L"TRUE" : L"FALSE",
			 pszNumRated,
			 pszRating
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnResourceRecycle(
                LONGLONG perfCount,		
                LPCOLESTR pszGuidApp,		
                LPCOLESTR pszObjectID,		
                LPCOLESTR pszType,
				LPCOLESTR pszResId
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ResourceEvents (Event,TickCount,Application, ObjectID, Type, ResourceID) \
				values ('%s',%d, '%s', '%s', '%s', '%s')",
			 L"OnResourceRecycle",
			 TickCount, 
			 pszGuidApp,
			 pszObjectID,
			 pszType,
			 pszResId		
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnResourceDestroy(
                LONGLONG perfCount,		
                LPCOLESTR pszGuidApp,		
                LPCOLESTR pszObjectID,		
                HRESULT hResult,
				LPCOLESTR pszType,
				LPCOLESTR pszResId
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ResourceEvents (Event,TickCount,Application,ObjectID, Type, ResourceID,HResult) \
				values ('%s',%d, '%s','%s', '%s', '%s', %d)",
			 L"OnResourceDestroy",
			 TickCount, 
			 pszGuidApp,
			 pszObjectID,			 
			 pszType,
			 pszResId,
			 hResult
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}
	

STDMETHODIMP CComSpySqlAudit::OnResourceTrack(
					LONGLONG perfCount,
					LPCOLESTR pszGuidApp,					
					LPCOLESTR pszObjectID,
					LPCOLESTR pszType,
					LPCOLESTR pszResId,
					BOOL bEnlisted	
            )
{
    long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ResourceEvents (Event,TickCount,Application, ObjectID, Type, ResourceID, Enlisted) \
				values ('%s',%d, '%s', '%s', '%s', '%s', '%s')",
			 L"OnResourceTrack",
			 TickCount, 
			 pszGuidApp,
			 pszObjectID,
			 pszType,
			 pszResId,	
			 bEnlisted ? L"TRUE" : L"FALSE"
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}				

//////////////////////////Security Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnAuthenticate(
		          LONGLONG perfCount,
				  LPCOLESTR pszGuidApp,
				  LPCOLESTR pszGuidActivity,
				  LPCOLESTR pszObjectID,
				  LPCOLESTR pszGuidIID,
				  LPCOLESTR pszMethod,
				  LPCOLESTR pszOriginalUser,
				  LPCOLESTR pszDirectUser, 
				  BOOL bCurrentUserInpersonatingInProc
            )
{
    long TickCount = PerfCountToTickCount(perfCount);		

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into SecurityEvents (Event,TickCount,Application, ActivityID, ObjectID, InterfaceID, Method, OriginalUser, DirectUser,Impersonation) \
			  values ('%s', %d, '%s', '%s', '%s', '%s','%s', '%s', '%s', '%s')",
			 L"OnAuthenticate",
			 TickCount, 
			 pszGuidApp,
			 pszGuidActivity, 
			 pszObjectID,
			 pszGuidIID,
			 pszMethod,
			 pszOriginalUser,
			 pszDirectUser, 
			 (bCurrentUserInpersonatingInProc ? L"Yes" : L"NO"));


	ATLTRACE(L"OnAuthenticate: m_sSQL = %s\n", m_sSQL);


	SQL_EXEC(m_sSQL);
	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnAuthenticateFail(
		          LONGLONG perfCount,
				  LPCOLESTR pszGuidApp,
				  LPCOLESTR pszGuidActivity,
				  LPCOLESTR pszObjectID,
				  LPCOLESTR pszGuidIID,
				  LPCOLESTR pszMethod,
				  LPCOLESTR pszOriginalUser,
				  LPCOLESTR pszDirectUser, 
				  BOOL bCurrentUserInpersonatingInProc
            )
{
    long TickCount = PerfCountToTickCount(perfCount);
	
	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into SecurityEvents (Event,TickCount,Application, ActivityID, ObjectID, InterfaceID, Method, OriginalUser, DirectUser,Impersonation) \
			  values ('%s', %d, '%s', '%s', '%s', '%s','%s', '%s', '%s', '%s')",
			 L"OnAuthenticateFail",
			 TickCount, 
			 pszGuidApp,
			 pszGuidActivity, 
			 pszObjectID,
			 pszGuidIID,
			 pszMethod,
			 pszOriginalUser,
			 pszDirectUser, 
			 (bCurrentUserInpersonatingInProc ? L"Yes" : L"NO"));

	SQL_EXEC(m_sSQL);
	return S_OK;
}

//////////////////////////Identity Events///////////////////////////////////
//Share table security events
STDMETHODIMP CComSpySqlAudit::OnIISRequestInfo(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszObjectID,
			 LPCOLESTR pszClientIP,
			 LPCOLESTR pszServerIP,
			 LPCOLESTR pszURL
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into SecurityEvents (Event,TickCount,Application, ObjectID,ClientIP, ServerIP, URL) \
				values ('%s',%d, '%s', '%s','%s','%s','%s')",
			 L"OnIISRequestInfo",
			 TickCount, 
			 pszGuidApp,
			 pszObjectID,			 	
			 pszClientIP,
			 pszServerIP,
			 pszURL
			 );
	SQL_EXEC(m_sSQL);

	return S_OK;
}

//////////////////////////Object Pool Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnObjPoolPutObject(
						  LONGLONG perfCount,
						  LPCOLESTR pszGuidApp, 
						  LPCOLESTR pszClassID,
						  int nReason, 						 
						  DWORD dwAvailableObjs,
						  LPCOLESTR pszObjectID)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ClassID, Reason, AvailableObjs, ObjectID) \
				values ('%s',%d, '%s', '%s', %d, %d, '%s')",
			 L"OnObjPoolPutObject",
			 TickCount, 
			 pszGuidApp,
			 pszClassID,
			 nReason,
			 dwAvailableObjs,	
			 pszObjectID
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}

STDMETHODIMP CComSpySqlAudit::OnObjPoolGetObject(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,  
			 LPCOLESTR pszGuidActivityID, 
			 LPCOLESTR pszClassID, 						 
			 DWORD dwAvailableObjs,
			 LPCOLESTR pszObjectID)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ActivityID, ClassID, AvailableObjs, ObjectID) \
				values ('%s',%d, '%s', '%s', '%s', %d, '%s')",
			 L"OnObjPoolGetObject",
			 TickCount, 
			 pszGuidApp,
			 pszGuidActivityID,
			 pszClassID,
			 dwAvailableObjs,	
			 pszObjectID
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}

STDMETHODIMP CComSpySqlAudit::OnObjPoolRecycleToTx(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,  
			 LPCOLESTR pszGuidActivityID, 
			 LPCOLESTR pszClassID, 	 
			 LPCOLESTR pszGuidTx, 
			 LPCOLESTR pszObjectID)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ActivityID, ClassID, TransactionID, ObjectID) \
				values ('%s',%d, '%s', '%s', '%s', '%s', '%s')",
			 L"OnObjPoolRecycleToTx",
			 TickCount, 
			 pszGuidApp,
			 pszGuidActivityID,
			 pszClassID,
			 pszGuidTx,	
			 pszObjectID
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnObjPoolGetFromTx(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,  
			 LPCOLESTR pszGuidActivityID, 
			 LPCOLESTR pszClassID, 	 
			 LPCOLESTR pszGuidTx, 
			 LPCOLESTR pszObjectID)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ActivityID, ClassID, TransactionID, ObjectID) \
				values ('%s',%d, '%s', '%s', '%s', '%s', '%s')",
			 L"OnObjPoolGetFromTx",
			 TickCount, 
			 pszGuidApp,
			 pszGuidActivityID,
			 pszClassID,
			 pszGuidTx,	
			 pszObjectID
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}

//////////////////////////Object Pool Events 2///////////////////////////////////
//Share table with Object Pool
STDMETHODIMP CComSpySqlAudit::OnObjPoolCreateObject(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,  
			 LPCOLESTR pszClassID, 
			 DWORD dwAvailableObjs,
			 LPCOLESTR pszObjectID)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ClassID,AvailableObjs, ObjectID) \
				values ('%s',%d, '%s', '%s', %d, '%s')",
			 L"OnObjPoolCreateObject",
			 TickCount, 
			 pszGuidApp,		
			 pszClassID,
			 dwAvailableObjs,	
			 pszObjectID
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}

STDMETHODIMP CComSpySqlAudit::OnObjPoolDestroyObject(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,  
			 LPCOLESTR pszClassID, 
			 DWORD dwAvailableObjs,
			 LPCOLESTR pszObjectID)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ActivityID, ClassID, TransactionID, ObjectID) \
				values ('%s',%d, '%s', '%s', %d, '%s')",
			 L"OnObjPoolDestroyObject",
			 TickCount, 
			 pszGuidApp,		
			 pszClassID,
			 dwAvailableObjs,	
			 pszObjectID
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}

STDMETHODIMP CComSpySqlAudit::OnObjPoolCreateDecision(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp, 
			 DWORD dwThreadsWaiting, 
			 DWORD dwAvailableObjs, 
			 DWORD dwCreatedObjs, 
			 DWORD dwMin, 
			 DWORD dwMax)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ThreadsWaiting, AvailableObjs, CreatedObjs, Min, Max) \
				values ('%s',%d, '%s', %d, %d, %d, %d, %d)",
			 L"OnObjPoolCreateDecision",
			 TickCount, 
			 pszGuidApp,
			 dwThreadsWaiting,			 
			 dwAvailableObjs,
			 dwCreatedObjs,
			 dwMin,
			 dwMax
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}			 

STDMETHODIMP CComSpySqlAudit::OnObjPoolTimeout(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp, 
			 LPCOLESTR pszClassID, 
			 LPCOLESTR pszGuidActivityID, 
			 DWORD dwTimeout)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ClassID, ActivityID,Timeout) \
				values ('%s',%d, '%s', '%s', '%s',%d)",
			 L"OnObjPoolTimeout",
			 TickCount, 
			 pszGuidApp,
			 pszClassID,
			 pszGuidActivityID,			 			 
			 dwTimeout
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}	

STDMETHODIMP CComSpySqlAudit::OnObjPoolCreatePool(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp, 
			 LPCOLESTR pszClassID,
			 DWORD dwMin, 
			 DWORD dwMax, 
			 DWORD dwTimeout)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ObjectPoolEvents (Event,TickCount,Application, ClassID, Min, Max, Timeout) \
				values ('%s',%d, '%s', '%s', %d, %d, %d)",
			 L"OnObjPoolCreatePool",
			 TickCount, 
			 pszGuidApp,
			 pszClassID,			 			 
			 dwMin,
			 dwMax,
			 dwTimeout
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}			 


//////////////////////////Activity Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnActivityCreate(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidActivityID
		)
{ 
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ActivityEvents (Event,TickCount,Application, ActivityID) \
				values ('%s',%d, '%s', '%s')",
			 L"OnActivityCreate",
			 TickCount, 
			 pszGuidApp,
			 pszGuidActivityID			 			 			 
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;

}

STDMETHODIMP CComSpySqlAudit::OnActivityDestroy(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidActivityID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ActivityEvents (Event,TickCount,Application, ActivityID) \
				values ('%s',%d, '%s', '%s')",
			 L"OnActivityDestroy",
			 TickCount, 
			 pszGuidApp,
			 pszGuidActivityID			 			 			 
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnActivityEnter(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidCurrentApp,
			 LPCOLESTR pszGuidEnteredApp,
			 LPCOLESTR pszW2KThreadID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ActivityEvents (Event,TickCount,Application, CurrentApp, EnteredApp,W2KThreadID) \
				values ('%s',%d, '%s', '%s','%s', '%s')",
			 L"OnActivityEnter",
			 TickCount, 
			 pszGuidApp,
			 pszGuidCurrentApp,
			 pszGuidEnteredApp,
			 pszW2KThreadID
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}


STDMETHODIMP CComSpySqlAudit::OnActivityTimeout(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidCurrentApp,
			 LPCOLESTR pszGuidEnteredApp,
			 LPCOLESTR pszW2KThreadID,		
			 DWORD dwTimeout
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ActivityEvents (Event,TickCount,Application, CurrentApp, EnteredApp,W2KThreadID,Timeout) \
				values ('%s',%d, '%s', '%s','%s', '%s',%d)",
			 L"OnActivityTimeout",
			 TickCount, 
			 pszGuidApp,
			 pszGuidCurrentApp,
			 pszGuidEnteredApp,
			 pszW2KThreadID,
			 dwTimeout
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnActivityReenter(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidCurrentApp,
			 LPCOLESTR pszW2KThreadID,
			 DWORD dwCallDepth
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ActivityEvents (Event,TickCount,Application, CurrentApp, W2KThreadID,CallDepth) \
				values ('%s',%d, '%s', '%s','%s',%d)",
			 L"OnActivityReenter",
			 TickCount, 
			 pszGuidApp,
			 pszGuidCurrentApp,			 
			 pszW2KThreadID,
			 dwCallDepth
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnActivityLeave(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidCurrentApp,
			 LPCOLESTR pszGuidLeftApp
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ActivityEvents (Event,TickCount,Application, CurrentApp, LeftApp) \
				values ('%s',%d, '%s', '%s','%s')",
			 L"OnActivityLeave",
			 TickCount, 
			 pszGuidApp,
			 pszGuidCurrentApp,
			 pszGuidLeftApp			
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnActivityLeaveSame(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidCurrentApp,
			 DWORD dwCallDepth
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ActivityEvents (Event,TickCount,Application, CurrentApp,CallDepth) \
				values ('%s',%d, '%s', '%s',%d)",
			 L"OnActivityLeaveSame",
			 TickCount, 
			 pszGuidApp,
			 pszGuidCurrentApp,			 	
			 dwCallDepth
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}



//////////////////////////Queued Components Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnQCRecord(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszObjectID,
			 LPCOLESTR pszQueueName,
			 LPCOLESTR pszGuidMsgID,
			 LPCOLESTR pszGuidWorkFlowID,
			 HRESULT hr
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into QCEvents (Event,TickCount,Application, ObjectID,QueueName, MsgID, WorkFlowID, HResult) \
				values ('%s',%d, '%s', '%s','%s','%s','%s',%d)",
			 L"OnQCRecord",
			 TickCount, 
			 pszGuidApp,
			 pszObjectID,			 	
			 pszQueueName,
			 pszGuidMsgID,
			 pszGuidWorkFlowID,
			 hr
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}
STDMETHODIMP CComSpySqlAudit::OnQCQueueOpen(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszQueueName,
			 LPCOLESTR pszQueueID,
			 HRESULT hr
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into QCEvents (Event,TickCount,Application, QueueName, QueueID, HResult) \
				values ('%s',%d, '%s', '%s','%s', %d)",
			 L"OnQCQueueOpen",
			 TickCount, 
			 pszGuidApp,
			 pszQueueName,			 	
			 pszQueueID,			 
			 hr
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnQCReceive(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszQueueID,
			 LPCOLESTR pszGuidMsgID,
			 LPCOLESTR pszGuidWorkFlowID,
			 HRESULT hr
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into QCEvents (Event,TickCount,Application, QueueID, MsgID, WrokFlowID, HResult) \
				values ('%s',%d, '%s', '%s','%s','%s', %d)",
			 L"OnQCReceive",
			 TickCount, 
			 pszGuidApp,						 	
			 pszQueueID,
			 pszGuidMsgID,
			 pszGuidWorkFlowID,
			 hr
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}
		
STDMETHODIMP CComSpySqlAudit::OnQCReceiveFail(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszQueueID,
			 HRESULT hr
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into QCEvents (Event,TickCount,Application, QueueID, HResult) \
				values ('%s',%d, '%s', '%s', %d)",
			 L"OnQCReceiveFail",
			 TickCount, 
			 pszGuidApp,						 	
			 pszQueueID,			 
			 hr
			 );
	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnQCMoveToReTryQueue(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidMsgID,
			 LPCOLESTR pszGuidWorkFlowID,
			 ULONG RetryIndex
		)
{

	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into QCEvents (Event,TickCount,Application, MsgID, WorkFlowID, RetryIndex) \
				values ('%s',%d, '%s', '%s', '%s',%d)",
			 L"OnQCMoveToReTryQueue",
			 TickCount, 
			 pszGuidApp,						 	
			 pszGuidMsgID,
			 pszGuidWorkFlowID,
			 RetryIndex
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnQCMoveToDeadQueue(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidMsgID,
			 LPCOLESTR pszGuidWorkFlowID
		)
{

	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into QCEvents (Event,TickCount,Application, MsgID, WorkFlowID) \
				values ('%s',%d, '%s', '%s', '%s')",
			 L"OnQCMoveToDeadQueue",
			 TickCount, 
			 pszGuidApp,						 	
			 pszGuidMsgID,
			 pszGuidWorkFlowID		
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnQCPlayback(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszObjectID,
			 LPCOLESTR pszGuidMsgID,
			 LPCOLESTR pszGuidWorkFlowID,
			 HRESULT hr
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into QCEvents (Event,TickCount,Application, ObjectID, MsgID, WorkFlowID, HResult) \
				values ('%s',%d, '%s', '%s', '%s','%s',%d)",
			 L"OnQCMoveToDeadQueue",
			 TickCount, 
			 pszGuidApp,
			 pszObjectID,
			 pszGuidMsgID,
			 pszGuidWorkFlowID,
			 hr
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

//////////////////////////Exception Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnExceptionUser(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszCode,
			 LPCOLESTR pszAddress,
			 LPCOLESTR pszStackTrace
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into ExceptionEvents (Event,TickCount,Application, Code,Address,StackTrace) \
				values ('%s',%d, '%s', '%s','%s','%s')",
			 L"OnExceptionUser",
			 TickCount, 
			 pszGuidApp,
			 pszCode,			 	
			 pszAddress,
			 pszStackTrace
			 );
	
	SQL_EXEC(m_sSQL);

	return S_OK;
}

//////////////////////////CRM Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::OnCRMRecoveryStart(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp
		)
{

	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application) \
				values ('%s',%d, '%s')",
			 L"OnCRMRecoveryStart",
			 TickCount, 
			 pszGuidApp			 
			 );
	
	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMRecoveryDone(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application) \
				values ('%s',%d, '%s')",
			 L"OnCRMRecoveryDone",
			 TickCount, 
			 pszGuidApp			 
			 );
	
	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMCheckpoint(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application) \
				values ('%s',%d, '%s')",
			 L"OnCRMCheckpoint",
			 TickCount, 
			 pszGuidApp			 
			 );
	
	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMBegin(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID,
			 LPCOLESTR pszGuidActivityID,
			 LPCOLESTR pszGuidTxUOWID,
			 LPCOLESTR pszProgIdCompensator,
			 LPCOLESTR pszDescription					
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID, ActivityID,TransactionUOWID,ProgIdCompensator,Description ) \
				values ('%s',%d, '%s','%s','%s','%s','%s','%s')",
				 L"OnCRMBegin",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID,
				 pszGuidActivityID,
				 pszGuidTxUOWID,
				 pszProgIdCompensator,
				 pszDescription		
			     );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMPrepare(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID
		)
{

	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID) \
				values ('%s',%d, '%s','%s')",
				 L"OnCRMPrepare",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID				 	
			     );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMCommit(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID) \
				values ('%s',%d, '%s','%s')",
				 L"OnCRMCommit",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID				 	
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMAbort(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID) \
				values ('%s',%d, '%s','%s')",
				 L"OnCRMAbort",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID				 	
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMIndoubt(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID) \
				values ('%s',%d, '%s','%s')",
				 L"OnCRMIndoubt",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID				 	
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMDone(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID) \
				values ('%s',%d, '%s','%s')",
				 L"OnCRMDone",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID				 	
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMRelease(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID) \
				values ('%s',%d, '%s','%s')",
				 L"OnCRMRelease",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID				 	
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMAnalyze(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID,				
			 LPCOLESTR pszCrmRecordType,
			 DWORD dwRecordSize
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID,CRMRecordType,RecordSize) \
				values ('%s',%d, '%s','%s','%s',%d)",
				 L"OnCRMAnalyze",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID,
				 pszCrmRecordType,
				 dwRecordSize
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMWrite(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID,
			 BOOL bVariants,
			 DWORD dwRecordSize)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID,Variants,RecordSize) \
				values ('%s',%d, '%s','%s','%s',%d)",
				 L"OnCRMWrite",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID,
				 (bVariants ? L"Yes" : L"No"),
				 dwRecordSize
			 );
	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMForget(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID) \
				values ('%s',%d, '%s','%s')",
				 L"OnCRMForget",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID				 	
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMForce(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID) \
				values ('%s',%d, '%s','%s')",
				 L"OnCRMForce",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID				 	
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::OnCRMDeliver(
			 LONGLONG perfCount,
			 LPCOLESTR pszGuidApp,
			 LPCOLESTR pszGuidClerkCLSID,
			 BOOL bVariants,
			 DWORD dwRecordSize
		)
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into CRMEvents (Event,TickCount,Application, ClerkID, Variants, RecordSize) \
				values ('%s',%d, '%s','%s','%s',%d)",
				 L"OnCRMDeliver",
				 TickCount, 
				 pszGuidApp,	
				 pszGuidClerkCLSID,
				 (bVariants ? L"Yes" : L"No"),
				 dwRecordSize
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

//////////////////////////Load Balancing Events///////////////////////////////////
STDMETHODIMP CComSpySqlAudit::TargetUp(
							 LONGLONG perfCount,
							 LPCOLESTR pszServerName, 
							 LPCOLESTR pszClsidEng)	
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into LBEvents (Event,TickCount,Application, ServerName, ClsidEng) \
				values ('%s',%d, '%s','%s','%s')",
				 L"TargetUp",
				 TickCount, 
				 L"COM+ Load Balancing",	
				 pszServerName,
				 pszClsidEng				 
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit::TargetDown(
							 LONGLONG perfCount,
							 LPCOLESTR pszServerName, 
							 LPCOLESTR pszClsidEng)							
{
	long TickCount = PerfCountToTickCount(perfCount);

	ZeroMemory(m_sSQL, SQL_BUF_SIZE * sizeof(WCHAR));
	StringCchPrintf(m_sSQL, SQL_BUF_SIZE, 
			 L"insert into LBEvents (Event,TickCount,Application, ServerName, ClsidEng) \
				values ('%s',%d, '%s','%s','%s')",
				 L"TargetDown",
				 TickCount, 
				 L"COM+ Load Balancing",	
				 pszServerName,
				 pszClsidEng				 
			 );

	SQL_EXEC(m_sSQL);

	return S_OK;
}

STDMETHODIMP CComSpySqlAudit:: EngineDefined(
							 LONGLONG perfCount,
							 LPCOLESTR pszPropName, 
							 VARIANT *varPropValue, 
							 LPCOLESTR pszClsidEng)
{
	UNREFERENCED_PARAMETER(perfCount);
	UNREFERENCED_PARAMETER(pszPropName);
	UNREFERENCED_PARAMETER(varPropValue);
	UNREFERENCED_PARAMETER(pszClsidEng);
	
	return S_OK;
}

