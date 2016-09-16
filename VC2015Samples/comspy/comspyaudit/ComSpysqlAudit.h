// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __COMSPYSQLAUDIT_H_
#define __COMSPYSQLAUDIT_H_

#include "resource.h"       // main symbols
#define SQL_BUF_SIZE	1024

/////////////////////////////////////////////////////////////////////////////
// CComSpySqlAudit
class ATL_NO_VTABLE CComSpySqlAudit : 
	public CComObjectRootEx<CComMultiThreadModel>,
	public CComCoClass<CComSpySqlAudit, &CLSID_ComSpyAudit>,
	public IComSpyAudit
{

private:
		HENV m_henv;
		HDBC m_hdbc;
		HSTMT m_hstmt;
		LONGLONG m_PerformanceFrequency;
		WCHAR m_sSQL[SQL_BUF_SIZE];

		long PerfCountToTickCount(LONGLONG perfCount);

public:
	CComSpySqlAudit()
	{
		m_hdbc = m_henv = m_hstmt = NULL;
		m_PerformanceFrequency = 0;
		m_pUnkMarshaler = NULL;
	}

	void GetError(HENV henv, HDBC hdbc, HSTMT hstmt, BSTR *msg);

	DECLARE_REGISTRY_RESOURCEID(IDR_COMSPYSQLAUDIT)
	DECLARE_NOT_AGGREGATABLE(CComSpySqlAudit)
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CComSpySqlAudit)
		COM_INTERFACE_ENTRY(IComSpyAudit)
		COM_INTERFACE_ENTRY_AGGREGATE(IID_IMarshal, m_pUnkMarshaler.p)
	END_COM_MAP()

	HRESULT FinalConstruct()
	{
		
		QueryPerformanceFrequency((LARGE_INTEGER *)&m_PerformanceFrequency);
		return CoCreateFreeThreadedMarshaler(
			GetControllingUnknown(), &m_pUnkMarshaler.p);
	}

	void FinalRelease()
	{
		m_pUnkMarshaler.Release();
		RETCODE rc;
		if (m_hstmt)
		{
			SQLFreeStmt( m_hstmt, SQL_DROP );    
		}
		if (m_hdbc)
		{
		   rc = SQLDisconnect( m_hdbc);
		   SQLFreeConnect( m_hdbc);
		   SQLFreeEnv( m_henv );
		}
	}

	CComPtr<IUnknown> m_pUnkMarshaler;

// IComSpyAudit
public:
	STDMETHOD(Init)(LPCOLESTR sDSN, LPCOLESTR sUser, LPCOLESTR sPw);    

	/////////////////////Thread Events/////////////////////////
	STDMETHOD(OnThreadStart)(
					 LONGLONG perfCount,
					 LPCOLESTR pszGuidApp,
					 LPCOLESTR pszThreadID,
					 LPCOLESTR pszW2KThreadID,
					 DWORD dwThreadCnt 	
				);

	STDMETHOD(OnThreadTerminate)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszThreadID,
				 LPCOLESTR pszW2KThreadID,
				 DWORD dwThreadCnt 
			);

	STDMETHOD(OnThreadBindToApartment)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszThreadID,					
				 LPCOLESTR pszAptID,	
				 DWORD dwActivityCnt
			);

	STDMETHOD(OnThreadUnBind)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszThreadID,					
				 LPCOLESTR pszAptID,	
				 DWORD dwActivityCnt
			);

	STDMETHOD(OnThreadAssignApartment)(
				LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszGuidActivityID,
				LPCOLESTR pszAptID					 
			);
	STDMETHOD(OnThreadUnassignApartment)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,				
				 LPCOLESTR pszAptID					 
			);

	STDMETHOD(OnThreadWorkEnque)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszThreadID,					
				 LPCOLESTR MsgWorkID,	
				 DWORD dwQueueLen
			);
	STDMETHOD(OnThreadWorkPrivate)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszThreadID,					
				 LPCOLESTR MsgWorkID						
			);
	STDMETHOD(OnThreadWorkPublic)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszThreadID,					
				 LPCOLESTR MsgWorkID,	
				 DWORD dwQueueLen
			);
	STDMETHOD(OnThreadWorkRedirect)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszThreadID,					
				 LPCOLESTR MsgWorkID,	
				 DWORD dwQueueLen,
				 LPCOLESTR pszThreadNum
			);
	STDMETHOD(OnThreadWorkReject)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszThreadID,					
				 LPCOLESTR MsgWorkID,	
				 DWORD dwQueueLen				
			);

	/////////////////////Application Events/////////////////////////
    STDMETHOD(OnAppActivation)(				
                LONGLONG perfCount,				
                LPCOLESTR pszGuidApp			               			
            );

    STDMETHOD(OnAppShutdown)(				
                LONGLONG perfCount,				
                LPCOLESTR pszGuidApp               			
            );

	/////////////////////Transaction Events/////////////////////////
    STDMETHOD(OnTransactionStart)(			
                LONGLONG perfCount,			
                LPCOLESTR pszGuidApp,				
                LPCOLESTR pszGuidTxID,			
                LPCOLESTR pszGuidTSID,
				BOOL bRoot
            );

    STDMETHOD(OnTransactionPrepared)(		
                LONGLONG perfCount,			
                LPCOLESTR pszGuidApp,				
                LPCOLESTR pszGuidTxID,
				BOOL bVoteYes
            );

    STDMETHOD(OnTransactionAborted)(		
                LONGLONG perfCount,			
                LPCOLESTR pszGuidApp,
				LPCOLESTR pszGuidTxID
            );
	STDMETHOD(OnTransactionCommit)(		
                LONGLONG perfCount,			
                LPCOLESTR pszGuidApp,
				LPCOLESTR pszGuidTxID
            );
	
	/////////////////////Method Events/////////////////////////
    STDMETHOD(OnMethodCall)(				
                LONGLONG perfCount,	
				LPCOLESTR pszGuidApp,
                LPCOLESTR pszObjectID,				
                LPCOLESTR pszGuidClassID,			
                LPCOLESTR pszGuidInterfaceID,				
                LPCOLESTR pszMethod
            );

    STDMETHOD(OnMethodReturn)(				
                LONGLONG perfCount,	
				LPCOLESTR pszGuidApp,
                LPCOLESTR pszObjectID,				
                LPCOLESTR pszGuidClassID,			
                LPCOLESTR pszGuidInterfaceID,				
                LPCOLESTR pszMethod,				
                HRESULT hr,
				LPCOLESTR pszCallTime
            );

    STDMETHOD(OnMethodException)(			
                LONGLONG perfCount,	
				LPCOLESTR pszGuidApp,
                LPCOLESTR pszObjectID,					
                LPCOLESTR pszGuidClassID,				
                LPCOLESTR pszGuidInterfaceID,				
                LPCOLESTR pszMethod		
            );

	/////////////////////ObjectConstruction Events/////////////////////////
	STDMETHOD(OnObjectConstruct)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszClassID, 
				 LPCOLESTR pszConstructString, 
				 LPCOLESTR pszObjectID
			);

	/////////////////////Instance Events/////////////////////////
    STDMETHOD(OnObjectCreate)(			
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszGuidActivityID,
				LPCOLESTR pszClassID,
				LPCOLESTR pszTSID,
				LPCOLESTR pszContextID,
				LPCOLESTR pszObjectID
            );

    STDMETHOD(OnObjectDestroy)(				
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID		
            );

	/////////////////////Object Events/////////////////////////
    STDMETHOD(OnObjectActivate)(			
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID,
				LPCOLESTR pszObjectID		
            );

    STDMETHOD(OnObjectDeactivate)(			
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID,
				LPCOLESTR pszObjectID				
            );

    STDMETHOD(OnDisableCommit)(				
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID							
            );

    STDMETHOD(OnEnableCommit)(				
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID		
            );

    STDMETHOD(OnSetComplete)(				
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID
            );
	STDMETHOD(OnSetAbort)(				
                LONGLONG perfCount,
				LPCOLESTR pszGuidApp,
				LPCOLESTR pszContextID	
            );

   /////////////////////Resource Events/////////////////////////
   STDMETHOD(OnResourceCreate)(				
					LONGLONG perfCount,
					LPCOLESTR pszGuidApp,					
					LPCOLESTR pszObjectID,
					LPCOLESTR pszType,
					LPCOLESTR pszResId,
					BOOL bEnlisted			
            );   

    STDMETHOD(OnResourceAllocate)(		
                LONGLONG perfCount,	
				LPCOLESTR pszGuidApp,	
                LPCOLESTR pszObjectID,	
                LPCOLESTR pszType,	
                LPCOLESTR pszResId,
				BOOL bEnlisted,
				LPCOLESTR pszNumRated,
				LPCOLESTR pszRating
            );

    STDMETHOD(OnResourceRecycle)(		
                LONGLONG perfCount,		
                LPCOLESTR pszGuidApp,		
                LPCOLESTR pszObjectID,		
                LPCOLESTR pszType,
				LPCOLESTR pszResId
            );

    STDMETHOD(OnResourceDestroy)(		
                LONGLONG perfCount,		
                LPCOLESTR pszGuidApp,		
                LPCOLESTR pszObjectID,		
                HRESULT hResult,
				LPCOLESTR pszType,
				LPCOLESTR pszResId
            );

	STDMETHOD(OnResourceTrack)(				
					LONGLONG perfCount,
					LPCOLESTR pszGuidApp,					
					LPCOLESTR pszObjectID,
					LPCOLESTR pszType,
					LPCOLESTR pszResId,
					BOOL bEnlisted			
            );

	/////////////////////Security Events/////////////////////////
    STDMETHOD(OnAuthenticate)(										        
		          LONGLONG perfCount,
				  LPCOLESTR pszGuidApp,
				  LPCOLESTR pszGuidActivity,
				  LPCOLESTR pszObjectID,
				  LPCOLESTR pszGuidIID,
				  LPCOLESTR pszMethod,
				  LPCOLESTR pszOriginalUser,
				  LPCOLESTR pszDirectUser, 
				  BOOL bCurrentUserInpersonatingInProc
            );

	STDMETHOD(OnAuthenticateFail)(								
				  LONGLONG perfCount,
				  LPCOLESTR pszGuidApp,
				  LPCOLESTR pszGuidActivity,
				  LPCOLESTR pszObjectID,
				  LPCOLESTR pszGuidIID,
				  LPCOLESTR pszMethod,
				  LPCOLESTR pszOriginalUser,
				  LPCOLESTR pszDirectUser, 
				  BOOL bCurrentUserInpersonatingInProc
            );

	/////////////////////Identity Events///////////////////////// 
	STDMETHOD(OnIISRequestInfo)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszObjectID,
				 LPCOLESTR pszClientIP,
				 LPCOLESTR pszServerIP,
				 LPCOLESTR pszURL
			);

	/////////////////////ObjectPool Events/////////////////////////
	STDMETHOD(OnObjPoolPutObject)(
		          LONGLONG perfCount,
				  LPCOLESTR pszGuidApp, 
				  LPCOLESTR pszClassID,
				  int nReason, 						 
				  DWORD dwAvailableObjs,
				  LPCOLESTR pszObjectID
			);

	STDMETHOD(OnObjPoolGetObject)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,  
				 LPCOLESTR pszGuidActivityID, 
				 LPCOLESTR pszClassID, 						 
				 DWORD dwAvailableObjs,
				 LPCOLESTR pszObjectID
			);

	STDMETHOD(OnObjPoolRecycleToTx)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,  
				 LPCOLESTR pszGuidActivityID, 
				 LPCOLESTR pszClassID, 	 
				 LPCOLESTR pszGuidTx, 
				 LPCOLESTR pszObjectID
			);

	STDMETHOD(OnObjPoolGetFromTx)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,  
				 LPCOLESTR pszGuidActivityID, 
				 LPCOLESTR pszClassID, 	 
				 LPCOLESTR pszGuidTx, 
				 LPCOLESTR pszObjectID
			);

	/////////////////////ObjectPool2 Events/////////////////////////
	STDMETHOD(OnObjPoolCreateObject)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,  
				 LPCOLESTR pszClassID, 
				 DWORD dwAvailableObjs,
				 LPCOLESTR pszObjectID
			);

	STDMETHOD(OnObjPoolDestroyObject)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,  
				 LPCOLESTR pszClassID, 
				 DWORD dwAvailableObjs,
				 LPCOLESTR pszObjectID
			);

	STDMETHOD(OnObjPoolCreateDecision)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp, 
				 DWORD dwThreadsWaiting, 
				 DWORD dwAvailableObjs, 
				 DWORD dwCreatedObjs, 
				 DWORD dwMin, 
				 DWORD dwMax
			);

	STDMETHOD(OnObjPoolTimeout)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp, 
				 LPCOLESTR pszClassID, 
				 LPCOLESTR pszGuidActivityID, 
				 DWORD dwTimeout);

	STDMETHOD(OnObjPoolCreatePool)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp, 
				 LPCOLESTR pszClassID,
				 DWORD dwMin, 
				 DWORD dwMax, 
				 DWORD dwTimeout
			);
	
	/////////////////////Activity Events/////////////////////
	STDMETHOD(OnActivityCreate)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidActivityID
			);

	STDMETHOD(OnActivityDestroy)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidActivityID
			);

	STDMETHOD(OnActivityEnter)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidCurrentApp,
				 LPCOLESTR pszGuidEnteredApp,
				 LPCOLESTR pszW2KThreadID
			);

	STDMETHOD(OnActivityTimeout)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidCurrentApp,
				 LPCOLESTR pszGuidEnteredApp,
				 LPCOLESTR pszW2KThreadID,		
				 DWORD dwTimeout
			);

	STDMETHOD(OnActivityReenter)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidCurrentApp,
				 LPCOLESTR pszW2KThreadID,
				 DWORD dwCallDepth
			);

	STDMETHOD(OnActivityLeave)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidCurrentApp,
				 LPCOLESTR pszGuidLeftApp
			);

	STDMETHOD(OnActivityLeaveSame)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidCurrentApp,
				 DWORD dwCallDepth
			);



	/////////////////////Queued Components Events/////////////////////
	STDMETHOD(OnQCRecord)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszObjectID,
				 LPCOLESTR pszQueueName,
				 LPCOLESTR pszGuidMsgID,
				 LPCOLESTR pszGuidWorkFlowID,
				 HRESULT hr
			);
	STDMETHOD(OnQCQueueOpen)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszQueueName,
				 LPCOLESTR pszQueueID,
				 HRESULT hr
			);
	STDMETHOD(OnQCReceive)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszQueueID,
				 LPCOLESTR pszGuidMsgID,
				 LPCOLESTR pszGuidWorkFlowID,
				 HRESULT hr
			);
	STDMETHOD(OnQCReceiveFail)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszQueueID,
				 HRESULT hr
			);
	STDMETHOD(OnQCMoveToReTryQueue)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidMsgID,
				 LPCOLESTR pszGuidWorkFlowID,
				 ULONG RetryIndex
			);
	STDMETHOD(OnQCMoveToDeadQueue)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidMsgID,
				 LPCOLESTR pszGuidWorkFlowID
			);
	STDMETHOD(OnQCPlayback)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszObjectID,
				 LPCOLESTR pszGuidMsgID,
				 LPCOLESTR pszGuidWorkFlowID,
				 HRESULT hr
			);


	/////////////////////Exception Events/////////////////////
	STDMETHOD(OnExceptionUser)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszCode,
				 LPCOLESTR pszAddress,
				 LPCOLESTR pszStackTrace
			);


	/////////////////////CRM Events/////////////////////
	STDMETHOD(OnCRMRecoveryStart)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp
			);

	STDMETHOD(OnCRMRecoveryDone)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp
			);

	STDMETHOD(OnCRMCheckpoint)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp
			);

	STDMETHOD(OnCRMBegin)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID,
				 LPCOLESTR pszGuidActivityID,
				 LPCOLESTR pszGuidTxUOWID,
				 LPCOLESTR pszProgIdCompensator,
				 LPCOLESTR pszDescription					
			);				

	STDMETHOD(OnCRMPrepare)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID
			);

	STDMETHOD(OnCRMCommit)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID
			);

	STDMETHOD(OnCRMAbort)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID
			);

	STDMETHOD(OnCRMIndoubt)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID
			);

	STDMETHOD(OnCRMDone)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID
			);

	STDMETHOD(OnCRMRelease)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID
			);

	STDMETHOD(OnCRMAnalyze)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID,				
				 LPCOLESTR pszCrmRecordType,
				 DWORD dwRecordSize
			);

	STDMETHOD(OnCRMWrite)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID,
				 BOOL bVariants,
				 DWORD dwRecordSize);

	STDMETHOD(OnCRMForget)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID
			);

	STDMETHOD(OnCRMForce)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID
			);

	STDMETHOD(OnCRMDeliver)(
				 LONGLONG perfCount,
				 LPCOLESTR pszGuidApp,
				 LPCOLESTR pszGuidClerkCLSID,
				 BOOL bVariants,
				 DWORD dwRecordSize
			);

	/////////////////////Load Balancing Events/////////////////////
	STDMETHOD(TargetUp)(
			 LONGLONG perfCount,
			 LPCOLESTR pszServerName, 
			 LPCOLESTR pszClsidEng
		);

	STDMETHOD(TargetDown)(
			 LONGLONG perfCount,
			 LPCOLESTR pszServerName, 
			 LPCOLESTR pszClsidEng
		);

    STDMETHOD(EngineDefined)(
			 LONGLONG perfCount,
			 LPCOLESTR pszPropName, 
			 VARIANT *varPropValue, 
			 LPCOLESTR pszClsidEng
		);
};

#endif //__COMSPYSQLAUDIT_H_
