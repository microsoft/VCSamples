// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __ACTIVITYSUB_H__
#define __ACTIVITYSUB_H__

#include "resource.h"       // main symbols

CComBSTR GuidToBstr(REFGUID guid);

class CComSpy;


/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
Class:   CActivitySub
Summary: Activity Event Subscriber
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/ 
class ATL_NO_VTABLE CActivitySub : 
	public CSysLCESub,
	public IComActivityEvents
{
public:
	CActivitySub(CComSpy * pSpy)
	{
		m_pSpy = pSpy;
	}

	CActivitySub()
	{
		m_pSpy = NULL;
	}

	DECLARE_NOT_AGGREGATABLE(CActivitySub)
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CActivitySub)
		COM_INTERFACE_ENTRY(IComActivityEvents)
		COM_INTERFACE_ENTRY_CHAIN(CSysLCESub)
	END_COM_MAP()

	STDMETHODIMP GetEventType(EventEnum * e){*e = Activity;return S_OK;}
	STDMETHODIMP GetEventClass(LPGUID guid){*guid = CLSID_ComServiceEvents;return S_OK;}
	STDMETHODIMP GetInterface(IID* iid){*iid = IID_IComActivityEvents;return S_OK;}

	STDMETHODIMP OnActivityCreate(COMSVCSEVENTINFO * pInfo, REFGUID guidActivity)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnActivityCreate"), GuidToBstr(pInfo->guidApp));

		CComBSTR sGuidActivity = GuidToBstr(guidActivity);

		m_pSpy -> AddParamValueToList(L"guidActivity", sGuidActivity);

		IF_AUDIT_DO(OnActivityCreate)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),sGuidActivity);														
									 
		return S_OK;
	}

	STDMETHODIMP OnActivityDestroy(COMSVCSEVENTINFO * pInfo, REFGUID guidActivity)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnActivityDestroy"),  GuidToBstr(pInfo->guidApp));

		CComBSTR sGuidActivity = GuidToBstr(guidActivity);
		m_pSpy -> AddParamValueToList(L"guidActivity", sGuidActivity);

		IF_AUDIT_DO(OnActivityDestroy)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),sGuidActivity);
		return S_OK;

	}

	STDMETHODIMP OnActivityEnter(COMSVCSEVENTINFO * pInfo, REFGUID guidCurrent,REFGUID guidEntered,
		DWORD dwThread)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnActivityEnter"),  GuidToBstr(pInfo->guidApp));

		CComBSTR sGuidCurrent = GuidToBstr(guidCurrent);
		m_pSpy -> AddParamValueToList(L"guidCurrent", sGuidCurrent);
		CComBSTR sGuidEntered = GuidToBstr(guidEntered);
		m_pSpy -> AddParamValueToList(L"guidEntered", sGuidEntered);

		WCHAR szThread[16];
		wsprintfW(szThread,L"0x%08X", dwThread);
		m_pSpy -> AddParamValueToList(L"dwThread", szThread);

		IF_AUDIT_DO(OnActivityEnter)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),
									sGuidCurrent,
									sGuidEntered,
									szThread
									);

		return S_OK;
	}

	STDMETHODIMP OnActivityTimeout(COMSVCSEVENTINFO * pInfo,REFGUID guidCurrent,REFGUID guidEntered,DWORD dwThread,
		DWORD dwTimeout)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnActivityTimeout"),  GuidToBstr(pInfo->guidApp));

		CComBSTR sGuidCurrent = GuidToBstr(guidCurrent);
		m_pSpy -> AddParamValueToList(L"guidCurrent", sGuidCurrent);
		CComBSTR sGuidEntered = GuidToBstr(guidEntered);
		m_pSpy -> AddParamValueToList(L"guidEntered", sGuidEntered);

		WCHAR szThread[16];
		wsprintfW(szThread,L"0x%08X", dwThread);
		m_pSpy -> AddParamValueToList(L"dwThread", szThread);

		WCHAR szTimeout[16];
		wsprintfW(szTimeout,L"%d", dwTimeout);
		m_pSpy -> AddParamValueToList(L"dwTimeout", szTimeout);

		IF_AUDIT_DO(OnActivityTimeout)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),
									sGuidCurrent,
									sGuidEntered,
									szThread,
									dwTimeout
									);
		return S_OK;
	}

	STDMETHODIMP OnActivityReenter(COMSVCSEVENTINFO * pInfo,REFGUID guidCurrent,DWORD dwThread,DWORD dwCallDepth)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnActivityReEnter"),  GuidToBstr(pInfo->guidApp));

		CComBSTR sGuidCurrent = GuidToBstr(guidCurrent);
		m_pSpy -> AddParamValueToList(L"guidCurrent", sGuidCurrent);

		WCHAR szThread[16];
		wsprintfW(szThread,L"0x%08X", dwThread);
		m_pSpy -> AddParamValueToList(L"dwThread", szThread);

		WCHAR szCallDepth[16];
		wsprintfW(szCallDepth,L"%d", dwCallDepth);
		m_pSpy -> AddParamValueToList(L"dwCallDepth", szCallDepth);

		IF_AUDIT_DO(OnActivityReenter)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),
									sGuidCurrent,							
									szThread,
									dwCallDepth
									);
		return S_OK;
	}

	STDMETHODIMP OnActivityLeave(COMSVCSEVENTINFO * pInfo,REFGUID guidCurrent,REFGUID guidLeft)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnActivityLeave"),  GuidToBstr(pInfo->guidApp));

		CComBSTR sGuidCurrent = GuidToBstr(guidCurrent);
		m_pSpy -> AddParamValueToList(L"guidCurrent", sGuidCurrent);
		CComBSTR sGuidLeft = GuidToBstr(guidLeft);
		m_pSpy -> AddParamValueToList(L"guidLeft", sGuidLeft);

		IF_AUDIT_DO(OnActivityLeave)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),
									sGuidCurrent,							
									sGuidLeft						
									);
		return S_OK;
	}

	STDMETHODIMP OnActivityLeaveSame(COMSVCSEVENTINFO * pInfo,REFGUID guidCurrent,DWORD dwCallDepth)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnActivityLeaveSame"),  GuidToBstr(pInfo->guidApp));

		CComBSTR sGuidCurrent = GuidToBstr(guidCurrent);
		m_pSpy -> AddParamValueToList(L"guidCurrent", sGuidCurrent);
		WCHAR id[16];
		wsprintfW(id,L"%d", dwCallDepth);
		m_pSpy -> AddParamValueToList(L"dwCallDepth", id);

		IF_AUDIT_DO(OnActivityLeaveSame)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),
									sGuidCurrent,							
									dwCallDepth						
									);
		return S_OK;
	}

};

#endif //__ACTIVITYSUB_H__
