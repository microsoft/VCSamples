

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Feb 04 17:32:22 2015
 */
/* Compiler settings for ComSpyAudit.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __ComSpyAudit_h_h__
#define __ComSpyAudit_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IComSpyAudit_FWD_DEFINED__
#define __IComSpyAudit_FWD_DEFINED__
typedef interface IComSpyAudit IComSpyAudit;

#endif 	/* __IComSpyAudit_FWD_DEFINED__ */


#ifndef __ComSpyAudit_FWD_DEFINED__
#define __ComSpyAudit_FWD_DEFINED__

#ifdef __cplusplus
typedef class ComSpyAudit ComSpyAudit;
#else
typedef struct ComSpyAudit ComSpyAudit;
#endif /* __cplusplus */

#endif 	/* __ComSpyAudit_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IComSpyAudit_INTERFACE_DEFINED__
#define __IComSpyAudit_INTERFACE_DEFINED__

/* interface IComSpyAudit */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IComSpyAudit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AFCF0622-1429-11D1-B1B8-00AA00BA3258")
    IComSpyAudit : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnThreadStart( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR pszW2KThreadID,
            /* [in] */ DWORD dwThreadCnt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadTerminate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR pszW2KThreadID,
            /* [in] */ DWORD dwThreadCnt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadBindToApartment( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR pszAptID,
            /* [in] */ DWORD dwActivityCnt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadUnBind( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR pszAptID,
            /* [in] */ DWORD dwActivityCnt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadAssignApartment( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszAptID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadUnassignApartment( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszAptID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadWorkEnque( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID,
            /* [in] */ DWORD dwQueueLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadWorkPrivate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadWorkPublic( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID,
            /* [in] */ DWORD dwQueueLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadWorkRedirect( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID,
            /* [in] */ DWORD dwQueueLen,
            /* [in] */ LPCOLESTR pszThreadNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnThreadWorkReject( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID,
            /* [in] */ DWORD dwQueueLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAppActivation( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAppShutdown( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjectCreate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszTSID,
            /* [in] */ LPCOLESTR pszContextID,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjectDestroy( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTransactionStart( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidTxID,
            /* [in] */ LPCOLESTR pszGuidTSID,
            /* [in] */ BOOL bRoot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTransactionPrepared( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidTxID,
            /* [in] */ BOOL bVoteYes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTransactionAborted( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidTxID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTransactionCommit( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidTxID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMethodCall( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidClassID,
            /* [in] */ LPCOLESTR pszGuidInterfaceID,
            /* [in] */ LPCOLESTR pszMethod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMethodReturn( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidClassID,
            /* [in] */ LPCOLESTR pszGuidInterfaceID,
            /* [in] */ LPCOLESTR pszMethod,
            /* [in] */ HRESULT hr,
            /* [in] */ LPCOLESTR pszCallTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMethodException( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidClassID,
            /* [in] */ LPCOLESTR pszGuidInterfaceID,
            /* [in] */ LPCOLESTR pszMethod) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjectActivate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjectDeactivate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDisableCommit( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEnableCommit( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnSetComplete( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnSetAbort( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnResourceCreate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId,
            /* [in] */ BOOL bEnlisted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnResourceAllocate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId,
            /* [in] */ BOOL bEnlisted,
            /* [in] */ LPCOLESTR pszNumRated,
            /* [in] */ LPCOLESTR pszRating) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnResourceRecycle( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnResourceDestroy( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ HRESULT hResult,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnResourceTrack( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId,
            /* [in] */ BOOL bEnlisted) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAuthenticate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivity,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidIID,
            /* [in] */ LPCOLESTR pszMethod,
            /* [in] */ LPCOLESTR pszOriginalUser,
            /* [in] */ LPCOLESTR pszDirectUser,
            /* [in] */ BOOL bCurrentUserInpersonatingInProc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAuthenticateFail( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivity,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidIID,
            /* [in] */ LPCOLESTR pszMethod,
            /* [in] */ LPCOLESTR pszOriginalUser,
            /* [in] */ LPCOLESTR pszDirectUser,
            /* [in] */ BOOL bCurrentUserInpersonatingInProc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolPutObject( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ int nReason,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolGetObject( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolRecycleToTx( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszGuidTx,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolGetFromTx( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszGuidTx,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolCreateObject( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolDestroyObject( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolCreateDecision( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ DWORD dwThreadsWaiting,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ DWORD dwCreatedObjs,
            /* [in] */ DWORD dwMin,
            /* [in] */ DWORD dwMax) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolTimeout( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ DWORD dwTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjPoolCreatePool( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ DWORD dwMin,
            /* [in] */ DWORD dwMax,
            /* [in] */ DWORD dwTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnObjectConstruct( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszConstructString,
            /* [in] */ LPCOLESTR pszObjectID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnActivityCreate( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnActivityDestroy( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnActivityEnter( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ LPCOLESTR pszGuidEnteredApp,
            /* [in] */ LPCOLESTR pszW2KThreadID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnActivityTimeout( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ LPCOLESTR pszGuidEnteredApp,
            /* [in] */ LPCOLESTR pszW2KThreadID,
            /* [in] */ DWORD dwTimeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnActivityReenter( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ LPCOLESTR pszW2KThreadID,
            /* [in] */ DWORD dwCallDepth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnActivityLeave( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ LPCOLESTR pszGuidLeftApp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnActivityLeaveSame( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ DWORD dwCallDepth) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnIISRequestInfo( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszClientIP,
            /* [in] */ LPCOLESTR pszServerIP,
            /* [in] */ LPCOLESTR pszURL) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQCRecord( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszQueueName,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQCQueueOpen( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszQueueName,
            /* [in] */ LPCOLESTR pszQueueID,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQCReceive( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszQueueID,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQCReceiveFail( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszQueueID,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQCMoveToReTryQueue( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID,
            /* [in] */ ULONG RetryIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQCMoveToDeadQueue( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnQCPlayback( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnExceptionUser( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszCode,
            /* [in] */ LPCOLESTR pszAddress,
            /* [in] */ LPCOLESTR pszStackTrace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMRecoveryStart( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMRecoveryDone( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMCheckpoint( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMBegin( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszGuidTxUOWID,
            /* [in] */ LPCOLESTR pszProgIdCompensator,
            /* [in] */ LPCOLESTR pszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMPrepare( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMCommit( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMAbort( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMIndoubt( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMDone( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMRelease( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMAnalyze( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID,
            /* [in] */ LPCOLESTR pszCrmRecordType,
            /* [in] */ DWORD dwRecordSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMWrite( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID,
            /* [in] */ BOOL bVariants,
            /* [in] */ DWORD dwRecordSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMForget( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMForce( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnCRMDeliver( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID,
            /* [in] */ BOOL bVariants,
            /* [in] */ DWORD dwRecordSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TargetUp( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszServerName,
            /* [in] */ LPCOLESTR pszClsidEng) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TargetDown( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszServerName,
            /* [in] */ LPCOLESTR pszClsidEng) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EngineDefined( 
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ VARIANT *varPropValue,
            /* [in] */ LPCOLESTR pszClsidEng) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            LPCOLESTR sDSN,
            LPCOLESTR sUser,
            LPCOLESTR sPw) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComSpyAuditVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComSpyAudit * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComSpyAudit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComSpyAudit * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadStart )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR pszW2KThreadID,
            /* [in] */ DWORD dwThreadCnt);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadTerminate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR pszW2KThreadID,
            /* [in] */ DWORD dwThreadCnt);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadBindToApartment )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR pszAptID,
            /* [in] */ DWORD dwActivityCnt);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadUnBind )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR pszAptID,
            /* [in] */ DWORD dwActivityCnt);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadAssignApartment )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszAptID);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadUnassignApartment )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszAptID);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadWorkEnque )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID,
            /* [in] */ DWORD dwQueueLen);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadWorkPrivate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadWorkPublic )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID,
            /* [in] */ DWORD dwQueueLen);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadWorkRedirect )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID,
            /* [in] */ DWORD dwQueueLen,
            /* [in] */ LPCOLESTR pszThreadNum);
        
        HRESULT ( STDMETHODCALLTYPE *OnThreadWorkReject )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszThreadID,
            /* [in] */ LPCOLESTR MsgWorkID,
            /* [in] */ DWORD dwQueueLen);
        
        HRESULT ( STDMETHODCALLTYPE *OnAppActivation )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp);
        
        HRESULT ( STDMETHODCALLTYPE *OnAppShutdown )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjectCreate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszTSID,
            /* [in] */ LPCOLESTR pszContextID,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjectDestroy )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID);
        
        HRESULT ( STDMETHODCALLTYPE *OnTransactionStart )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidTxID,
            /* [in] */ LPCOLESTR pszGuidTSID,
            /* [in] */ BOOL bRoot);
        
        HRESULT ( STDMETHODCALLTYPE *OnTransactionPrepared )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidTxID,
            /* [in] */ BOOL bVoteYes);
        
        HRESULT ( STDMETHODCALLTYPE *OnTransactionAborted )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidTxID);
        
        HRESULT ( STDMETHODCALLTYPE *OnTransactionCommit )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidTxID);
        
        HRESULT ( STDMETHODCALLTYPE *OnMethodCall )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidClassID,
            /* [in] */ LPCOLESTR pszGuidInterfaceID,
            /* [in] */ LPCOLESTR pszMethod);
        
        HRESULT ( STDMETHODCALLTYPE *OnMethodReturn )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidClassID,
            /* [in] */ LPCOLESTR pszGuidInterfaceID,
            /* [in] */ LPCOLESTR pszMethod,
            /* [in] */ HRESULT hr,
            /* [in] */ LPCOLESTR pszCallTime);
        
        HRESULT ( STDMETHODCALLTYPE *OnMethodException )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidClassID,
            /* [in] */ LPCOLESTR pszGuidInterfaceID,
            /* [in] */ LPCOLESTR pszMethod);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjectActivate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjectDeactivate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnDisableCommit )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID);
        
        HRESULT ( STDMETHODCALLTYPE *OnEnableCommit )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID);
        
        HRESULT ( STDMETHODCALLTYPE *OnSetComplete )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID);
        
        HRESULT ( STDMETHODCALLTYPE *OnSetAbort )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszContextID);
        
        HRESULT ( STDMETHODCALLTYPE *OnResourceCreate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId,
            /* [in] */ BOOL bEnlisted);
        
        HRESULT ( STDMETHODCALLTYPE *OnResourceAllocate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId,
            /* [in] */ BOOL bEnlisted,
            /* [in] */ LPCOLESTR pszNumRated,
            /* [in] */ LPCOLESTR pszRating);
        
        HRESULT ( STDMETHODCALLTYPE *OnResourceRecycle )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId);
        
        HRESULT ( STDMETHODCALLTYPE *OnResourceDestroy )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ HRESULT hResult,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId);
        
        HRESULT ( STDMETHODCALLTYPE *OnResourceTrack )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszType,
            /* [in] */ LPCOLESTR pszResId,
            /* [in] */ BOOL bEnlisted);
        
        HRESULT ( STDMETHODCALLTYPE *OnAuthenticate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivity,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidIID,
            /* [in] */ LPCOLESTR pszMethod,
            /* [in] */ LPCOLESTR pszOriginalUser,
            /* [in] */ LPCOLESTR pszDirectUser,
            /* [in] */ BOOL bCurrentUserInpersonatingInProc);
        
        HRESULT ( STDMETHODCALLTYPE *OnAuthenticateFail )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivity,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidIID,
            /* [in] */ LPCOLESTR pszMethod,
            /* [in] */ LPCOLESTR pszOriginalUser,
            /* [in] */ LPCOLESTR pszDirectUser,
            /* [in] */ BOOL bCurrentUserInpersonatingInProc);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolPutObject )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ int nReason,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolGetObject )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolRecycleToTx )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszGuidTx,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolGetFromTx )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszGuidTx,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolCreateObject )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolDestroyObject )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolCreateDecision )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ DWORD dwThreadsWaiting,
            /* [in] */ DWORD dwAvailableObjs,
            /* [in] */ DWORD dwCreatedObjs,
            /* [in] */ DWORD dwMin,
            /* [in] */ DWORD dwMax);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolTimeout )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ DWORD dwTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjPoolCreatePool )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ DWORD dwMin,
            /* [in] */ DWORD dwMax,
            /* [in] */ DWORD dwTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *OnObjectConstruct )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszClassID,
            /* [in] */ LPCOLESTR pszConstructString,
            /* [in] */ LPCOLESTR pszObjectID);
        
        HRESULT ( STDMETHODCALLTYPE *OnActivityCreate )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID);
        
        HRESULT ( STDMETHODCALLTYPE *OnActivityDestroy )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidActivityID);
        
        HRESULT ( STDMETHODCALLTYPE *OnActivityEnter )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ LPCOLESTR pszGuidEnteredApp,
            /* [in] */ LPCOLESTR pszW2KThreadID);
        
        HRESULT ( STDMETHODCALLTYPE *OnActivityTimeout )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ LPCOLESTR pszGuidEnteredApp,
            /* [in] */ LPCOLESTR pszW2KThreadID,
            /* [in] */ DWORD dwTimeout);
        
        HRESULT ( STDMETHODCALLTYPE *OnActivityReenter )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ LPCOLESTR pszW2KThreadID,
            /* [in] */ DWORD dwCallDepth);
        
        HRESULT ( STDMETHODCALLTYPE *OnActivityLeave )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ LPCOLESTR pszGuidLeftApp);
        
        HRESULT ( STDMETHODCALLTYPE *OnActivityLeaveSame )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidCurrentApp,
            /* [in] */ DWORD dwCallDepth);
        
        HRESULT ( STDMETHODCALLTYPE *OnIISRequestInfo )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszClientIP,
            /* [in] */ LPCOLESTR pszServerIP,
            /* [in] */ LPCOLESTR pszURL);
        
        HRESULT ( STDMETHODCALLTYPE *OnQCRecord )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszQueueName,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *OnQCQueueOpen )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszQueueName,
            /* [in] */ LPCOLESTR pszQueueID,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *OnQCReceive )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszQueueID,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *OnQCReceiveFail )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszQueueID,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *OnQCMoveToReTryQueue )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID,
            /* [in] */ ULONG RetryIndex);
        
        HRESULT ( STDMETHODCALLTYPE *OnQCMoveToDeadQueue )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID);
        
        HRESULT ( STDMETHODCALLTYPE *OnQCPlayback )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszObjectID,
            /* [in] */ LPCOLESTR pszGuidMsgID,
            /* [in] */ LPCOLESTR pszGuidWorkFlowID,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *OnExceptionUser )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszCode,
            /* [in] */ LPCOLESTR pszAddress,
            /* [in] */ LPCOLESTR pszStackTrace);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMRecoveryStart )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMRecoveryDone )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMCheckpoint )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMBegin )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID,
            /* [in] */ LPCOLESTR pszGuidActivityID,
            /* [in] */ LPCOLESTR pszGuidTxUOWID,
            /* [in] */ LPCOLESTR pszProgIdCompensator,
            /* [in] */ LPCOLESTR pszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMPrepare )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMCommit )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMAbort )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMIndoubt )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMDone )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMRelease )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMAnalyze )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID,
            /* [in] */ LPCOLESTR pszCrmRecordType,
            /* [in] */ DWORD dwRecordSize);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMWrite )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID,
            /* [in] */ BOOL bVariants,
            /* [in] */ DWORD dwRecordSize);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMForget )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMForce )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID);
        
        HRESULT ( STDMETHODCALLTYPE *OnCRMDeliver )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszGuidApp,
            /* [in] */ LPCOLESTR pszGuidClerkCLSID,
            /* [in] */ BOOL bVariants,
            /* [in] */ DWORD dwRecordSize);
        
        HRESULT ( STDMETHODCALLTYPE *TargetUp )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszServerName,
            /* [in] */ LPCOLESTR pszClsidEng);
        
        HRESULT ( STDMETHODCALLTYPE *TargetDown )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszServerName,
            /* [in] */ LPCOLESTR pszClsidEng);
        
        HRESULT ( STDMETHODCALLTYPE *EngineDefined )( 
            IComSpyAudit * This,
            /* [in] */ LONGLONG perfCount,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ VARIANT *varPropValue,
            /* [in] */ LPCOLESTR pszClsidEng);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IComSpyAudit * This,
            LPCOLESTR sDSN,
            LPCOLESTR sUser,
            LPCOLESTR sPw);
        
        END_INTERFACE
    } IComSpyAuditVtbl;

    interface IComSpyAudit
    {
        CONST_VTBL struct IComSpyAuditVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComSpyAudit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComSpyAudit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComSpyAudit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComSpyAudit_OnThreadStart(This,perfCount,pszGuidApp,pszThreadID,pszW2KThreadID,dwThreadCnt)	\
    ( (This)->lpVtbl -> OnThreadStart(This,perfCount,pszGuidApp,pszThreadID,pszW2KThreadID,dwThreadCnt) ) 

#define IComSpyAudit_OnThreadTerminate(This,perfCount,pszGuidApp,pszThreadID,pszW2KThreadID,dwThreadCnt)	\
    ( (This)->lpVtbl -> OnThreadTerminate(This,perfCount,pszGuidApp,pszThreadID,pszW2KThreadID,dwThreadCnt) ) 

#define IComSpyAudit_OnThreadBindToApartment(This,perfCount,pszGuidApp,pszThreadID,pszAptID,dwActivityCnt)	\
    ( (This)->lpVtbl -> OnThreadBindToApartment(This,perfCount,pszGuidApp,pszThreadID,pszAptID,dwActivityCnt) ) 

#define IComSpyAudit_OnThreadUnBind(This,perfCount,pszGuidApp,pszThreadID,pszAptID,dwActivityCnt)	\
    ( (This)->lpVtbl -> OnThreadUnBind(This,perfCount,pszGuidApp,pszThreadID,pszAptID,dwActivityCnt) ) 

#define IComSpyAudit_OnThreadAssignApartment(This,perfCount,pszGuidApp,pszGuidActivityID,pszAptID)	\
    ( (This)->lpVtbl -> OnThreadAssignApartment(This,perfCount,pszGuidApp,pszGuidActivityID,pszAptID) ) 

#define IComSpyAudit_OnThreadUnassignApartment(This,perfCount,pszGuidApp,pszAptID)	\
    ( (This)->lpVtbl -> OnThreadUnassignApartment(This,perfCount,pszGuidApp,pszAptID) ) 

#define IComSpyAudit_OnThreadWorkEnque(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID,dwQueueLen)	\
    ( (This)->lpVtbl -> OnThreadWorkEnque(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID,dwQueueLen) ) 

#define IComSpyAudit_OnThreadWorkPrivate(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID)	\
    ( (This)->lpVtbl -> OnThreadWorkPrivate(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID) ) 

#define IComSpyAudit_OnThreadWorkPublic(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID,dwQueueLen)	\
    ( (This)->lpVtbl -> OnThreadWorkPublic(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID,dwQueueLen) ) 

#define IComSpyAudit_OnThreadWorkRedirect(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID,dwQueueLen,pszThreadNum)	\
    ( (This)->lpVtbl -> OnThreadWorkRedirect(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID,dwQueueLen,pszThreadNum) ) 

#define IComSpyAudit_OnThreadWorkReject(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID,dwQueueLen)	\
    ( (This)->lpVtbl -> OnThreadWorkReject(This,perfCount,pszGuidApp,pszThreadID,MsgWorkID,dwQueueLen) ) 

#define IComSpyAudit_OnAppActivation(This,perfCount,pszGuidApp)	\
    ( (This)->lpVtbl -> OnAppActivation(This,perfCount,pszGuidApp) ) 

#define IComSpyAudit_OnAppShutdown(This,perfCount,pszGuidApp)	\
    ( (This)->lpVtbl -> OnAppShutdown(This,perfCount,pszGuidApp) ) 

#define IComSpyAudit_OnObjectCreate(This,perfCount,pszGuidApp,pszGuidActivityID,pszClassID,pszTSID,pszContextID,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjectCreate(This,perfCount,pszGuidApp,pszGuidActivityID,pszClassID,pszTSID,pszContextID,pszObjectID) ) 

#define IComSpyAudit_OnObjectDestroy(This,perfCount,pszGuidApp,pszContextID)	\
    ( (This)->lpVtbl -> OnObjectDestroy(This,perfCount,pszGuidApp,pszContextID) ) 

#define IComSpyAudit_OnTransactionStart(This,perfCount,pszGuidApp,pszGuidTxID,pszGuidTSID,bRoot)	\
    ( (This)->lpVtbl -> OnTransactionStart(This,perfCount,pszGuidApp,pszGuidTxID,pszGuidTSID,bRoot) ) 

#define IComSpyAudit_OnTransactionPrepared(This,perfCount,pszGuidApp,pszGuidTxID,bVoteYes)	\
    ( (This)->lpVtbl -> OnTransactionPrepared(This,perfCount,pszGuidApp,pszGuidTxID,bVoteYes) ) 

#define IComSpyAudit_OnTransactionAborted(This,perfCount,pszGuidApp,pszGuidTxID)	\
    ( (This)->lpVtbl -> OnTransactionAborted(This,perfCount,pszGuidApp,pszGuidTxID) ) 

#define IComSpyAudit_OnTransactionCommit(This,perfCount,pszGuidApp,pszGuidTxID)	\
    ( (This)->lpVtbl -> OnTransactionCommit(This,perfCount,pszGuidApp,pszGuidTxID) ) 

#define IComSpyAudit_OnMethodCall(This,perfCount,pszGuidApp,pszObjectID,pszGuidClassID,pszGuidInterfaceID,pszMethod)	\
    ( (This)->lpVtbl -> OnMethodCall(This,perfCount,pszGuidApp,pszObjectID,pszGuidClassID,pszGuidInterfaceID,pszMethod) ) 

#define IComSpyAudit_OnMethodReturn(This,perfCount,pszGuidApp,pszObjectID,pszGuidClassID,pszGuidInterfaceID,pszMethod,hr,pszCallTime)	\
    ( (This)->lpVtbl -> OnMethodReturn(This,perfCount,pszGuidApp,pszObjectID,pszGuidClassID,pszGuidInterfaceID,pszMethod,hr,pszCallTime) ) 

#define IComSpyAudit_OnMethodException(This,perfCount,pszGuidApp,pszObjectID,pszGuidClassID,pszGuidInterfaceID,pszMethod)	\
    ( (This)->lpVtbl -> OnMethodException(This,perfCount,pszGuidApp,pszObjectID,pszGuidClassID,pszGuidInterfaceID,pszMethod) ) 

#define IComSpyAudit_OnObjectActivate(This,perfCount,pszGuidApp,pszContextID,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjectActivate(This,perfCount,pszGuidApp,pszContextID,pszObjectID) ) 

#define IComSpyAudit_OnObjectDeactivate(This,perfCount,pszGuidApp,pszContextID,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjectDeactivate(This,perfCount,pszGuidApp,pszContextID,pszObjectID) ) 

#define IComSpyAudit_OnDisableCommit(This,perfCount,pszGuidApp,pszContextID)	\
    ( (This)->lpVtbl -> OnDisableCommit(This,perfCount,pszGuidApp,pszContextID) ) 

#define IComSpyAudit_OnEnableCommit(This,perfCount,pszGuidApp,pszContextID)	\
    ( (This)->lpVtbl -> OnEnableCommit(This,perfCount,pszGuidApp,pszContextID) ) 

#define IComSpyAudit_OnSetComplete(This,perfCount,pszGuidApp,pszContextID)	\
    ( (This)->lpVtbl -> OnSetComplete(This,perfCount,pszGuidApp,pszContextID) ) 

#define IComSpyAudit_OnSetAbort(This,perfCount,pszGuidApp,pszContextID)	\
    ( (This)->lpVtbl -> OnSetAbort(This,perfCount,pszGuidApp,pszContextID) ) 

#define IComSpyAudit_OnResourceCreate(This,perfCount,pszGuidApp,pszObjectID,pszType,pszResId,bEnlisted)	\
    ( (This)->lpVtbl -> OnResourceCreate(This,perfCount,pszGuidApp,pszObjectID,pszType,pszResId,bEnlisted) ) 

#define IComSpyAudit_OnResourceAllocate(This,perfCount,pszGuidApp,pszObjectID,pszType,pszResId,bEnlisted,pszNumRated,pszRating)	\
    ( (This)->lpVtbl -> OnResourceAllocate(This,perfCount,pszGuidApp,pszObjectID,pszType,pszResId,bEnlisted,pszNumRated,pszRating) ) 

#define IComSpyAudit_OnResourceRecycle(This,perfCount,pszGuidApp,pszObjectID,pszType,pszResId)	\
    ( (This)->lpVtbl -> OnResourceRecycle(This,perfCount,pszGuidApp,pszObjectID,pszType,pszResId) ) 

#define IComSpyAudit_OnResourceDestroy(This,perfCount,pszGuidApp,pszObjectID,hResult,pszType,pszResId)	\
    ( (This)->lpVtbl -> OnResourceDestroy(This,perfCount,pszGuidApp,pszObjectID,hResult,pszType,pszResId) ) 

#define IComSpyAudit_OnResourceTrack(This,perfCount,pszGuidApp,pszObjectID,pszType,pszResId,bEnlisted)	\
    ( (This)->lpVtbl -> OnResourceTrack(This,perfCount,pszGuidApp,pszObjectID,pszType,pszResId,bEnlisted) ) 

#define IComSpyAudit_OnAuthenticate(This,perfCount,pszGuidApp,pszGuidActivity,pszObjectID,pszGuidIID,pszMethod,pszOriginalUser,pszDirectUser,bCurrentUserInpersonatingInProc)	\
    ( (This)->lpVtbl -> OnAuthenticate(This,perfCount,pszGuidApp,pszGuidActivity,pszObjectID,pszGuidIID,pszMethod,pszOriginalUser,pszDirectUser,bCurrentUserInpersonatingInProc) ) 

#define IComSpyAudit_OnAuthenticateFail(This,perfCount,pszGuidApp,pszGuidActivity,pszObjectID,pszGuidIID,pszMethod,pszOriginalUser,pszDirectUser,bCurrentUserInpersonatingInProc)	\
    ( (This)->lpVtbl -> OnAuthenticateFail(This,perfCount,pszGuidApp,pszGuidActivity,pszObjectID,pszGuidIID,pszMethod,pszOriginalUser,pszDirectUser,bCurrentUserInpersonatingInProc) ) 

#define IComSpyAudit_OnObjPoolPutObject(This,perfCount,pszGuidApp,pszClassID,nReason,dwAvailableObjs,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjPoolPutObject(This,perfCount,pszGuidApp,pszClassID,nReason,dwAvailableObjs,pszObjectID) ) 

#define IComSpyAudit_OnObjPoolGetObject(This,perfCount,pszGuidApp,pszGuidActivityID,pszClassID,dwAvailableObjs,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjPoolGetObject(This,perfCount,pszGuidApp,pszGuidActivityID,pszClassID,dwAvailableObjs,pszObjectID) ) 

#define IComSpyAudit_OnObjPoolRecycleToTx(This,perfCount,pszGuidApp,pszGuidActivityID,pszClassID,pszGuidTx,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjPoolRecycleToTx(This,perfCount,pszGuidApp,pszGuidActivityID,pszClassID,pszGuidTx,pszObjectID) ) 

#define IComSpyAudit_OnObjPoolGetFromTx(This,perfCount,pszGuidApp,pszGuidActivityID,pszClassID,pszGuidTx,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjPoolGetFromTx(This,perfCount,pszGuidApp,pszGuidActivityID,pszClassID,pszGuidTx,pszObjectID) ) 

#define IComSpyAudit_OnObjPoolCreateObject(This,perfCount,pszGuidApp,pszClassID,dwAvailableObjs,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjPoolCreateObject(This,perfCount,pszGuidApp,pszClassID,dwAvailableObjs,pszObjectID) ) 

#define IComSpyAudit_OnObjPoolDestroyObject(This,perfCount,pszGuidApp,pszClassID,dwAvailableObjs,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjPoolDestroyObject(This,perfCount,pszGuidApp,pszClassID,dwAvailableObjs,pszObjectID) ) 

#define IComSpyAudit_OnObjPoolCreateDecision(This,perfCount,pszGuidApp,dwThreadsWaiting,dwAvailableObjs,dwCreatedObjs,dwMin,dwMax)	\
    ( (This)->lpVtbl -> OnObjPoolCreateDecision(This,perfCount,pszGuidApp,dwThreadsWaiting,dwAvailableObjs,dwCreatedObjs,dwMin,dwMax) ) 

#define IComSpyAudit_OnObjPoolTimeout(This,perfCount,pszGuidApp,pszClassID,pszGuidActivityID,dwTimeout)	\
    ( (This)->lpVtbl -> OnObjPoolTimeout(This,perfCount,pszGuidApp,pszClassID,pszGuidActivityID,dwTimeout) ) 

#define IComSpyAudit_OnObjPoolCreatePool(This,perfCount,pszGuidApp,pszClassID,dwMin,dwMax,dwTimeout)	\
    ( (This)->lpVtbl -> OnObjPoolCreatePool(This,perfCount,pszGuidApp,pszClassID,dwMin,dwMax,dwTimeout) ) 

#define IComSpyAudit_OnObjectConstruct(This,perfCount,pszGuidApp,pszClassID,pszConstructString,pszObjectID)	\
    ( (This)->lpVtbl -> OnObjectConstruct(This,perfCount,pszGuidApp,pszClassID,pszConstructString,pszObjectID) ) 

#define IComSpyAudit_OnActivityCreate(This,perfCount,pszGuidApp,pszGuidActivityID)	\
    ( (This)->lpVtbl -> OnActivityCreate(This,perfCount,pszGuidApp,pszGuidActivityID) ) 

#define IComSpyAudit_OnActivityDestroy(This,perfCount,pszGuidApp,pszGuidActivityID)	\
    ( (This)->lpVtbl -> OnActivityDestroy(This,perfCount,pszGuidApp,pszGuidActivityID) ) 

#define IComSpyAudit_OnActivityEnter(This,perfCount,pszGuidApp,pszGuidCurrentApp,pszGuidEnteredApp,pszW2KThreadID)	\
    ( (This)->lpVtbl -> OnActivityEnter(This,perfCount,pszGuidApp,pszGuidCurrentApp,pszGuidEnteredApp,pszW2KThreadID) ) 

#define IComSpyAudit_OnActivityTimeout(This,perfCount,pszGuidApp,pszGuidCurrentApp,pszGuidEnteredApp,pszW2KThreadID,dwTimeout)	\
    ( (This)->lpVtbl -> OnActivityTimeout(This,perfCount,pszGuidApp,pszGuidCurrentApp,pszGuidEnteredApp,pszW2KThreadID,dwTimeout) ) 

#define IComSpyAudit_OnActivityReenter(This,perfCount,pszGuidApp,pszGuidCurrentApp,pszW2KThreadID,dwCallDepth)	\
    ( (This)->lpVtbl -> OnActivityReenter(This,perfCount,pszGuidApp,pszGuidCurrentApp,pszW2KThreadID,dwCallDepth) ) 

#define IComSpyAudit_OnActivityLeave(This,perfCount,pszGuidApp,pszGuidCurrentApp,pszGuidLeftApp)	\
    ( (This)->lpVtbl -> OnActivityLeave(This,perfCount,pszGuidApp,pszGuidCurrentApp,pszGuidLeftApp) ) 

#define IComSpyAudit_OnActivityLeaveSame(This,perfCount,pszGuidApp,pszGuidCurrentApp,dwCallDepth)	\
    ( (This)->lpVtbl -> OnActivityLeaveSame(This,perfCount,pszGuidApp,pszGuidCurrentApp,dwCallDepth) ) 

#define IComSpyAudit_OnIISRequestInfo(This,perfCount,pszGuidApp,pszObjectID,pszClientIP,pszServerIP,pszURL)	\
    ( (This)->lpVtbl -> OnIISRequestInfo(This,perfCount,pszGuidApp,pszObjectID,pszClientIP,pszServerIP,pszURL) ) 

#define IComSpyAudit_OnQCRecord(This,perfCount,pszGuidApp,pszObjectID,pszQueueName,pszGuidMsgID,pszGuidWorkFlowID,hr)	\
    ( (This)->lpVtbl -> OnQCRecord(This,perfCount,pszGuidApp,pszObjectID,pszQueueName,pszGuidMsgID,pszGuidWorkFlowID,hr) ) 

#define IComSpyAudit_OnQCQueueOpen(This,perfCount,pszGuidApp,pszQueueName,pszQueueID,hr)	\
    ( (This)->lpVtbl -> OnQCQueueOpen(This,perfCount,pszGuidApp,pszQueueName,pszQueueID,hr) ) 

#define IComSpyAudit_OnQCReceive(This,perfCount,pszGuidApp,pszQueueID,pszGuidMsgID,pszGuidWorkFlowID,hr)	\
    ( (This)->lpVtbl -> OnQCReceive(This,perfCount,pszGuidApp,pszQueueID,pszGuidMsgID,pszGuidWorkFlowID,hr) ) 

#define IComSpyAudit_OnQCReceiveFail(This,perfCount,pszGuidApp,pszQueueID,hr)	\
    ( (This)->lpVtbl -> OnQCReceiveFail(This,perfCount,pszGuidApp,pszQueueID,hr) ) 

#define IComSpyAudit_OnQCMoveToReTryQueue(This,perfCount,pszGuidApp,pszGuidMsgID,pszGuidWorkFlowID,RetryIndex)	\
    ( (This)->lpVtbl -> OnQCMoveToReTryQueue(This,perfCount,pszGuidApp,pszGuidMsgID,pszGuidWorkFlowID,RetryIndex) ) 

#define IComSpyAudit_OnQCMoveToDeadQueue(This,perfCount,pszGuidApp,pszGuidMsgID,pszGuidWorkFlowID)	\
    ( (This)->lpVtbl -> OnQCMoveToDeadQueue(This,perfCount,pszGuidApp,pszGuidMsgID,pszGuidWorkFlowID) ) 

#define IComSpyAudit_OnQCPlayback(This,perfCount,pszGuidApp,pszObjectID,pszGuidMsgID,pszGuidWorkFlowID,hr)	\
    ( (This)->lpVtbl -> OnQCPlayback(This,perfCount,pszGuidApp,pszObjectID,pszGuidMsgID,pszGuidWorkFlowID,hr) ) 

#define IComSpyAudit_OnExceptionUser(This,perfCount,pszGuidApp,pszCode,pszAddress,pszStackTrace)	\
    ( (This)->lpVtbl -> OnExceptionUser(This,perfCount,pszGuidApp,pszCode,pszAddress,pszStackTrace) ) 

#define IComSpyAudit_OnCRMRecoveryStart(This,perfCount,pszGuidApp)	\
    ( (This)->lpVtbl -> OnCRMRecoveryStart(This,perfCount,pszGuidApp) ) 

#define IComSpyAudit_OnCRMRecoveryDone(This,perfCount,pszGuidApp)	\
    ( (This)->lpVtbl -> OnCRMRecoveryDone(This,perfCount,pszGuidApp) ) 

#define IComSpyAudit_OnCRMCheckpoint(This,perfCount,pszGuidApp)	\
    ( (This)->lpVtbl -> OnCRMCheckpoint(This,perfCount,pszGuidApp) ) 

#define IComSpyAudit_OnCRMBegin(This,perfCount,pszGuidApp,pszGuidClerkCLSID,pszGuidActivityID,pszGuidTxUOWID,pszProgIdCompensator,pszDescription)	\
    ( (This)->lpVtbl -> OnCRMBegin(This,perfCount,pszGuidApp,pszGuidClerkCLSID,pszGuidActivityID,pszGuidTxUOWID,pszProgIdCompensator,pszDescription) ) 

#define IComSpyAudit_OnCRMPrepare(This,perfCount,pszGuidApp,pszGuidClerkCLSID)	\
    ( (This)->lpVtbl -> OnCRMPrepare(This,perfCount,pszGuidApp,pszGuidClerkCLSID) ) 

#define IComSpyAudit_OnCRMCommit(This,perfCount,pszGuidApp,pszGuidClerkCLSID)	\
    ( (This)->lpVtbl -> OnCRMCommit(This,perfCount,pszGuidApp,pszGuidClerkCLSID) ) 

#define IComSpyAudit_OnCRMAbort(This,perfCount,pszGuidApp,pszGuidClerkCLSID)	\
    ( (This)->lpVtbl -> OnCRMAbort(This,perfCount,pszGuidApp,pszGuidClerkCLSID) ) 

#define IComSpyAudit_OnCRMIndoubt(This,perfCount,pszGuidApp,pszGuidClerkCLSID)	\
    ( (This)->lpVtbl -> OnCRMIndoubt(This,perfCount,pszGuidApp,pszGuidClerkCLSID) ) 

#define IComSpyAudit_OnCRMDone(This,perfCount,pszGuidApp,pszGuidClerkCLSID)	\
    ( (This)->lpVtbl -> OnCRMDone(This,perfCount,pszGuidApp,pszGuidClerkCLSID) ) 

#define IComSpyAudit_OnCRMRelease(This,perfCount,pszGuidApp,pszGuidClerkCLSID)	\
    ( (This)->lpVtbl -> OnCRMRelease(This,perfCount,pszGuidApp,pszGuidClerkCLSID) ) 

#define IComSpyAudit_OnCRMAnalyze(This,perfCount,pszGuidApp,pszGuidClerkCLSID,pszCrmRecordType,dwRecordSize)	\
    ( (This)->lpVtbl -> OnCRMAnalyze(This,perfCount,pszGuidApp,pszGuidClerkCLSID,pszCrmRecordType,dwRecordSize) ) 

#define IComSpyAudit_OnCRMWrite(This,perfCount,pszGuidApp,pszGuidClerkCLSID,bVariants,dwRecordSize)	\
    ( (This)->lpVtbl -> OnCRMWrite(This,perfCount,pszGuidApp,pszGuidClerkCLSID,bVariants,dwRecordSize) ) 

#define IComSpyAudit_OnCRMForget(This,perfCount,pszGuidApp,pszGuidClerkCLSID)	\
    ( (This)->lpVtbl -> OnCRMForget(This,perfCount,pszGuidApp,pszGuidClerkCLSID) ) 

#define IComSpyAudit_OnCRMForce(This,perfCount,pszGuidApp,pszGuidClerkCLSID)	\
    ( (This)->lpVtbl -> OnCRMForce(This,perfCount,pszGuidApp,pszGuidClerkCLSID) ) 

#define IComSpyAudit_OnCRMDeliver(This,perfCount,pszGuidApp,pszGuidClerkCLSID,bVariants,dwRecordSize)	\
    ( (This)->lpVtbl -> OnCRMDeliver(This,perfCount,pszGuidApp,pszGuidClerkCLSID,bVariants,dwRecordSize) ) 

#define IComSpyAudit_TargetUp(This,perfCount,pszServerName,pszClsidEng)	\
    ( (This)->lpVtbl -> TargetUp(This,perfCount,pszServerName,pszClsidEng) ) 

#define IComSpyAudit_TargetDown(This,perfCount,pszServerName,pszClsidEng)	\
    ( (This)->lpVtbl -> TargetDown(This,perfCount,pszServerName,pszClsidEng) ) 

#define IComSpyAudit_EngineDefined(This,perfCount,pszPropName,varPropValue,pszClsidEng)	\
    ( (This)->lpVtbl -> EngineDefined(This,perfCount,pszPropName,varPropValue,pszClsidEng) ) 

#define IComSpyAudit_Init(This,sDSN,sUser,sPw)	\
    ( (This)->lpVtbl -> Init(This,sDSN,sUser,sPw) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComSpyAudit_INTERFACE_DEFINED__ */



#ifndef __COMSPYAUDITLib_LIBRARY_DEFINED__
#define __COMSPYAUDITLib_LIBRARY_DEFINED__

/* library COMSPYAUDITLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_COMSPYAUDITLib;

EXTERN_C const CLSID CLSID_ComSpyAudit;

#ifdef __cplusplus

class DECLSPEC_UUID("AFCF0623-1429-11D1-B1B8-00AA00BA3258")
ComSpyAudit;
#endif
#endif /* __COMSPYAUDITLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


