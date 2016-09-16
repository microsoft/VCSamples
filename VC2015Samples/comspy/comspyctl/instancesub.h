// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __INSTANCESUB_H__
#define __INSTANCESUB_H__

#include "resource.h"       // main symbols

CComBSTR GuidToBstr(REFGUID guid);

class CComSpy;

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
Class:   CInstanceSub
Summary: Instance Events Subscriber 
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/ 
class ATL_NO_VTABLE CInstanceSub : 
	public CSysLCESub,
	public IComInstanceEvents
{
public:
	CInstanceSub(CComSpy * pSpy)
	{
		m_pSpy = pSpy;
	}

	CInstanceSub()
	{
		m_pSpy = NULL;
	}

	DECLARE_NOT_AGGREGATABLE(CInstanceSub)
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CInstanceSub)
		COM_INTERFACE_ENTRY(IComInstanceEvents)
		COM_INTERFACE_ENTRY_CHAIN(CSysLCESub)
	END_COM_MAP()

	STDMETHODIMP GetEventType(EventEnum * e){*e = Instance;return S_OK;}
	STDMETHODIMP GetEventClass(LPGUID guid){*guid = CLSID_ComServiceEvents;return S_OK;}
	STDMETHODIMP GetInterface(IID* iid){*iid = IID_IComInstanceEvents;return S_OK;}

	STDMETHODIMP OnObjectCreate(COMSVCSEVENTINFO * pInfo, REFGUID guidActivity, REFCLSID clsid, REFGUID tsid, ULONG64 CtxtID, ULONG64 ObjectID)
	{

		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnObjectCreate"), GuidToBstr(pInfo->guidApp));

		CComBSTR sGuidActivity = GuidToBstr(guidActivity);
		CComBSTR sClsid = GuidToBstr(clsid);
		CComBSTR sTsid = GuidToBstr(tsid);

		m_pSpy -> AddParamValueToList(L"guidActivity", sGuidActivity);
		m_pSpy -> AddParamValueToList(L"clsid", sClsid);
		m_pSpy -> AddParamValueToList(L"tsid", sTsid);

		WCHAR szCtxtID[32];
		wsprintfW(szCtxtID,L"0x%016X", CtxtID);
		m_pSpy -> AddParamValueToList(L"CtxtID", szCtxtID);

		WCHAR szObjectID[32];
		wsprintfW(szObjectID,L"0x%016X", ObjectID);
		m_pSpy -> AddParamValueToList(L"ObjectID", szObjectID);

		

		IF_AUDIT_DO(OnObjectCreate)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),							
									sGuidActivity,						
									sClsid,						
									sTsid,
									szCtxtID,
									szObjectID);

		return S_OK;
	}

	STDMETHODIMP OnObjectDestroy(COMSVCSEVENTINFO * pInfo, ULONG64 CtxtID)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnObjectDestroy"),  GuidToBstr(pInfo->guidApp));

		WCHAR szCtxtID[32];
		wsprintfW(szCtxtID,L"0x%016X", CtxtID);
		m_pSpy -> AddParamValueToList(L"CtxtID", szCtxtID);

		IF_AUDIT_DO(OnObjectDestroy)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),														
									 szCtxtID);

		return S_OK;
	}

};

#endif //__INSTANCESUB_H__
