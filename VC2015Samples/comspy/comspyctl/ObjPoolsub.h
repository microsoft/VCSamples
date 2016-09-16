// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __OBJPOOLSUB_H__
#define __OBJPOOLSUB_H__

#include "resource.h"       // main symbols

CComBSTR GuidToBstr(REFGUID guid);

class CComSpy;

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
Class:   CObjPoolSub
Summary: Object Pool Events Subscriber 
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/ 
class ATL_NO_VTABLE CObjPoolSub : 
	public CSysLCESub,
	public IComObjectPoolEvents
{
public:
	CObjPoolSub(CComSpy * pSpy)
	{
		m_pSpy = pSpy;
	}

	CObjPoolSub()
	{
		m_pSpy = NULL;
	}


	DECLARE_NOT_AGGREGATABLE(CObjPoolSub)
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CObjPoolSub)
		COM_INTERFACE_ENTRY(IComObjectPoolEvents)
		COM_INTERFACE_ENTRY_CHAIN(CSysLCESub)
	END_COM_MAP()

	STDMETHODIMP GetEventType(EventEnum * e){*e = ObjectPool;return S_OK;}
	STDMETHODIMP GetEventClass(LPGUID guid){*guid = CLSID_ComServiceEvents;return S_OK;}
	STDMETHODIMP GetInterface(IID* iid){*iid = IID_IComObjectPoolEvents;return S_OK;}

	STDMETHODIMP OnObjPoolPutObject(COMSVCSEVENTINFO * pInfo,
									REFGUID guidClass,
									int nReason,
									DWORD dwAvailable,
									ULONG64 ObjectID)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnObjPoolPutObject"), GuidToBstr(pInfo->guidApp));
		
		m_pSpy -> AddParamValueToList(L"guidClass", GuidToBstr( guidClass ));

		WCHAR p1[16];
		wsprintfW(p1, L"0x%08X", nReason);
		m_pSpy -> AddParamValueToList(L"nReason", p1);

		wsprintfW(p1, L"%lu", dwAvailable);
		m_pSpy -> AddParamValueToList(L"dwAvailable", p1);

		WCHAR szObjectID[32];
		wsprintfW(szObjectID, L"0x%016X", ObjectID);
		m_pSpy -> AddParamValueToList(L"ObjectID", szObjectID);

		IF_AUDIT_DO(OnObjPoolPutObject)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),							
										GuidToBstr( guidClass ),						
										nReason,						
										dwAvailable,								
										szObjectID);
		return S_OK;
	}


	STDMETHODIMP  OnObjPoolGetObject(COMSVCSEVENTINFO * pInfo,
								 REFGUID guidActivity,
								 REFGUID guidClass,
								 DWORD dwAvailable,
								 ULONG64 ObjectID)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnObjPoolGetObject"), GuidToBstr(pInfo->guidApp));

		m_pSpy -> AddParamValueToList(L"guidActivity", GuidToBstr( guidActivity ));
		m_pSpy -> AddParamValueToList(L"guidClass", GuidToBstr( guidClass ));

		WCHAR p1[16];
		wsprintfW(p1, L"%d", dwAvailable);
		m_pSpy -> AddParamValueToList(L"dwAvailable", p1);

		WCHAR szObjectID[32];
		wsprintfW(szObjectID, L"0x%016X", ObjectID);
		m_pSpy -> AddParamValueToList(L"ObjectID", szObjectID);

		IF_AUDIT_DO(OnObjPoolGetObject)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
										GuidToBstr( guidActivity ),
										GuidToBstr( guidClass ),
										dwAvailable,
										szObjectID);			

		return S_OK;
	}

	STDMETHODIMP  OnObjPoolRecycleToTx(COMSVCSEVENTINFO * pInfo, 
									   REFGUID guidActivity,
									   REFGUID guidClass,
									   REFGUID guidTx,
									   ULONG64 ObjectID)
	{
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnObjPoolRecycleToTx"), GuidToBstr(pInfo->guidApp));

		m_pSpy -> AddParamValueToList(L"guidActivity", GuidToBstr( guidActivity ));
		m_pSpy -> AddParamValueToList(L"guidClass", GuidToBstr( guidClass ));
		m_pSpy -> AddParamValueToList(L"guidTx", GuidToBstr( guidTx ));
		
		WCHAR szObjectID[32];
		wsprintfW(szObjectID, L"0x%016X", ObjectID);
		m_pSpy -> AddParamValueToList(L"ObjectID", szObjectID);

		IF_AUDIT_DO(OnObjPoolRecycleToTx)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
										GuidToBstr( guidActivity ),
										GuidToBstr( guidClass ),
										GuidToBstr( guidTx ),
										szObjectID);	

		return S_OK;
	}

	STDMETHODIMP  OnObjPoolGetFromTx(COMSVCSEVENTINFO * pInfo,
									 REFGUID guidActivity,
									 REFGUID guidClass,
									 REFGUID guidTx,
									 ULONG64 ObjectID)
	{

		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnObjPoolGetFromTx"), GuidToBstr(pInfo->guidApp));
		m_pSpy -> AddParamValueToList(L"guidActivity", GuidToBstr( guidActivity ));
		m_pSpy -> AddParamValueToList(L"guidClass", GuidToBstr( guidClass ));
		m_pSpy -> AddParamValueToList(L"guidTx", GuidToBstr( guidTx ));

		WCHAR szObjectID[32];
		wsprintfW(szObjectID, L"0x%016X", ObjectID);
		m_pSpy -> AddParamValueToList(L"ObjectID", szObjectID);

		IF_AUDIT_DO(OnObjPoolGetFromTx)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),
										GuidToBstr( guidActivity ),
										GuidToBstr( guidClass ),
										GuidToBstr( guidTx ),
										szObjectID);	


		return S_OK;
	}
};

#endif //__OBJPOOLSUB_H__
