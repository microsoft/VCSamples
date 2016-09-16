// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#include "stdafx.h"
#include "ComSpyCtl.h"
#include "ComSpyAudit.h"
#include <comsvcs.h>
#include "CComSpy.h"
#include "SysLCESub.h"
#include "TxSub.h"

CComBSTR GuidToBstr(REFGUID guid);

/////////////////////////////////////////////////////////////////////////////
// CTxSub

STDMETHODIMP CTxSub::OnTransactionStart(COMSVCSEVENTINFO * pInfo, REFGUID guidTx, REFGUID tsid, BOOL bRoot)
{
	m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnTransactionStart"), GuidToBstr(pInfo->guidApp));

    CComBSTR sGuidTx = GuidToBstr(guidTx);    
	m_pSpy -> AddParamValueToList(L"GuidTx", sGuidTx);	

	CComBSTR sTsid = GuidToBstr(tsid);
	m_pSpy -> AddParamValueToList(L"tsid", sTsid);	

	m_pSpy -> AddParamValueToList(L"Is a Root Tx?", bRoot ? L"Yes" : L"No");

	IF_AUDIT_DO(OnTransactionStart)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),							
									  sGuidTx,						
									  sTsid,
									  bRoot);
									  
	return S_OK;
}

STDMETHODIMP CTxSub::OnTransactionPrepare(COMSVCSEVENTINFO * pInfo, REFGUID guidTx, BOOL bVoteYes)
{
	m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnTransactionPrepare"), GuidToBstr(pInfo->guidApp));

    CComBSTR sguidTx = GuidToBstr(guidTx);
    m_pSpy -> AddParamValueToList(L"*guidTx", sguidTx);

	m_pSpy -> AddParamValueToList(L"Vote",  bVoteYes == TRUE ? L"Yes" : L"No");

	IF_AUDIT_DO(OnTransactionPrepared)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),							
									  sguidTx,						
									  bVoteYes);
	return S_OK;
}

STDMETHODIMP CTxSub::OnTransactionAbort(COMSVCSEVENTINFO * pInfo, REFGUID guidTx)
{
	m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnTransactionAbort"), GuidToBstr(pInfo->guidApp));

    CComBSTR sguidTx = GuidToBstr(guidTx);
    m_pSpy -> AddParamValueToList(L"*guidTx", sguidTx);

	IF_AUDIT_DO(OnTransactionAborted)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),sguidTx);

	return S_OK;
}

STDMETHODIMP CTxSub::OnTransactionCommit(COMSVCSEVENTINFO * pInfo, REFGUID guidTx)
{
	m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnTransactionCommit"), GuidToBstr(pInfo->guidApp));

	CComBSTR sguidTx = GuidToBstr(guidTx);
	m_pSpy -> AddParamValueToList(L"*guidTx", sguidTx);

	IF_AUDIT_DO(OnTransactionCommit)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),sguidTx);
	return S_OK;
}

