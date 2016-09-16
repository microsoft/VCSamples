// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#include "stdafx.h"
#include "ComSpyCtl.h"
#include <comsvcs.h>
#include "SysLCESub.h"
#include "ComSpyAudit.h"

#include "CComSpy.h"
#include "crmsub.h"
#include <strsafe.h>


STDMETHODIMP CCRMSub::OnCRMRecoveryStart(
			COMSVCSEVENTINFO * pInfo,
			GUID guidApp)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMRecoveryStart"), GuidToBstr(pInfo->guidApp));

	IF_AUDIT_DO(OnCRMRecoveryStart)(pInfo->perfCount, GuidToBstr(pInfo->guidApp));																				
	
	return S_OK;

} // CCRMSub::OnCRMRecoveryStart


STDMETHODIMP CCRMSub::OnCRMRecoveryDone(
			COMSVCSEVENTINFO * pInfo,
			GUID guidApp)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMRecoveryDone"), GuidToBstr(pInfo->guidApp));

	IF_AUDIT_DO(OnCRMRecoveryDone)(pInfo->perfCount, GuidToBstr(pInfo->guidApp));

	return S_OK;

} // CCRMSub::OnCRMRecoveryDone


STDMETHODIMP CCRMSub::OnCRMCheckpoint(
			COMSVCSEVENTINFO * pInfo,
			GUID guidApp)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMCheckpoint"), GuidToBstr(pInfo->guidApp));

	IF_AUDIT_DO(OnCRMCheckpoint)(pInfo->perfCount, GuidToBstr(pInfo->guidApp));

	return S_OK;

} // CCRMSub::OnCRMCheckpoint


STDMETHODIMP CCRMSub::OnCRMBegin(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID,
			GUID guidActivity,
			GUID guidTx,
			WCHAR szProgIdCompensator[64],			// NOTE: hardcoded
			WCHAR szDescription[64])				// NOTE: hardcoded
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMBegin"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));
	m_pSpy->AddParamValueToList(L"Activity ID", GuidToBstr(guidActivity));
	m_pSpy->AddParamValueToList(L"Transaction UOW ID", GuidToBstr(guidTx));
	m_pSpy->AddParamValueToList(L"Compensator Prog ID", szProgIdCompensator);
	m_pSpy->AddParamValueToList(L"Description", szDescription);

	IF_AUDIT_DO(OnCRMBegin)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
								 GuidToBstr(guidClerkCLSID),
								 GuidToBstr(guidActivity),
								 GuidToBstr(guidTx),
								 szProgIdCompensator,
								 szDescription
								 );

	return S_OK;

} // CCRMSub::OnCRMBegin


STDMETHODIMP CCRMSub::OnCRMPrepare(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMPrepare"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	IF_AUDIT_DO(OnCRMPrepare)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
							 GuidToBstr(guidClerkCLSID)							 
							 );


	return S_OK;

} // CCRMSub::OnCRMPrepare


STDMETHODIMP CCRMSub::OnCRMCommit(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMCommit"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	IF_AUDIT_DO(OnCRMCommit)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
							 GuidToBstr(guidClerkCLSID)							 
							 );


	return S_OK;

} // CCRMSub::OnCRMCommit



STDMETHODIMP CCRMSub::OnCRMAbort(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMAbort"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	IF_AUDIT_DO(OnCRMAbort)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
							 GuidToBstr(guidClerkCLSID)							 
							 );


	return S_OK;

} // CCRMSub::OnCRMAbort


STDMETHODIMP CCRMSub::OnCRMIndoubt(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMIndoubt"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	IF_AUDIT_DO(OnCRMIndoubt)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
							 GuidToBstr(guidClerkCLSID)							 
							 );


	return S_OK;

} // CCRMSub::OnCRMIndoubt


STDMETHODIMP CCRMSub::OnCRMDone(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMDone"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	IF_AUDIT_DO(OnCRMDone)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
							 GuidToBstr(guidClerkCLSID)							 
							 );

	return S_OK;

} // CCRMSub::OnCRMDone


STDMETHODIMP CCRMSub::OnCRMRelease(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMRelease"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	IF_AUDIT_DO(OnCRMRelease)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
							 GuidToBstr(guidClerkCLSID)	
							 );
	

	return S_OK;

} // CCRMSub::OnCRMRelease


STDMETHODIMP CCRMSub::OnCRMAnalyze(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID,
			DWORD dwCrmRecordType,
			DWORD dwRecordSize)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMAnalyze"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));
	
	// internals info from CrmLogRecordFormat.h

	DWORD dwRecordTypeIndex = (dwCrmRecordType >= 0x20 ? dwCrmRecordType - 0x20 + 4 : dwCrmRecordType);

	TCHAR * aRecordType[] =
	{
		L"None",			// 0x00
		L"LogInfo",			// 0x01
		L"NewClerk",		// 0x02
		L"ClerkList",		// 0x03
		L"ClerkBegin",		// 0x20
		L"Write",			// 0x21
		L"Forget",			// 0x22
		L"ClerkEnd",		// 0x23
	};

	m_pSpy->AddParamValueToList(L"Record Type", aRecordType[dwRecordTypeIndex]);

	TCHAR szRecordSize[32];
	StringCchPrintf(szRecordSize, sizeof(szRecordSize)/sizeof(TCHAR), L"%d", dwRecordSize);
	m_pSpy->AddParamValueToList(L"Record Size", szRecordSize);

	IF_AUDIT_DO(OnCRMAnalyze)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
							 GuidToBstr(guidClerkCLSID),
							 aRecordType[dwRecordTypeIndex],
							 dwRecordSize
							 );
	

	return S_OK;

} // CCRMSub::OnCRMAnalyze


STDMETHODIMP CCRMSub::OnCRMWrite(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID,
			BOOL bVariants,
			DWORD dwRecordSize)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMWrite"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	m_pSpy->AddParamValueToList(L"Variants?",  (bVariants ? L"Yes" : L"No"));

	TCHAR szRecordSize[32];
	StringCchPrintf(szRecordSize, sizeof(szRecordSize)/sizeof(TCHAR), L"%d", dwRecordSize);
	m_pSpy->AddParamValueToList(L"Record Size", szRecordSize);

	IF_AUDIT_DO(OnCRMWrite)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
						 GuidToBstr(guidClerkCLSID),
						 bVariants,
						 dwRecordSize
						 );
	
	return S_OK;

} // CCRMSub::OnCRMWrite


STDMETHODIMP CCRMSub::OnCRMForget(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMForget"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	IF_AUDIT_DO(OnCRMForget)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
						 GuidToBstr(guidClerkCLSID)						 
						 );

	return S_OK;

} // CCRMSub::OnCRMForget


STDMETHODIMP CCRMSub::OnCRMForce(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMForce"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	IF_AUDIT_DO(OnCRMForce)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
						 GuidToBstr(guidClerkCLSID)						 
						 );


	return S_OK;

} // CCRMSub::OnCRMForce


STDMETHODIMP CCRMSub::OnCRMDeliver(
			COMSVCSEVENTINFO * pInfo,
			GUID guidClerkCLSID,
			BOOL bVariants,
			DWORD dwRecordSize)
{
	m_pSpy->AddEventToList(pInfo->perfCount, _TEXT("OnCRMDeliver"), GuidToBstr(pInfo->guidApp));

	m_pSpy->AddParamValueToList(L"Clerk CLSID", GuidToBstr(guidClerkCLSID));

	m_pSpy->AddParamValueToList(L"Variants?",  (bVariants ? L"Yes" : L"No"));

	TCHAR szRecordSize[32];
	StringCchPrintf(szRecordSize,sizeof(szRecordSize)/sizeof(TCHAR),  L"%d", dwRecordSize);
	m_pSpy->AddParamValueToList(L"Record Size", szRecordSize);

	
	IF_AUDIT_DO(OnCRMDeliver)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
						 GuidToBstr(guidClerkCLSID),
						 bVariants,
						 dwRecordSize
						 );


	return S_OK;

} // CCRMSub::OnCRMDeliver

