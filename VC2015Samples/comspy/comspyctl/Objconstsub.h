// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __OBJCONSTSUB_H__
#define __OBJCONSTSUB_H__

#include "resource.h"       // main symbols

CComBSTR GuidToBstr(REFGUID guid);

class CComSpy;

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
Class:   CObjConstSub
Summary: Object Construction Events Subscriber 
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/ 
class ATL_NO_VTABLE CObjConstSub : 
	public CSysLCESub,
	public IComObjectConstructionEvents
{
public:
	CObjConstSub(CComSpy * pSpy)
	{
		m_pSpy = pSpy;
	}

	CObjConstSub()
	{
		m_pSpy = NULL;
	}

	DECLARE_NOT_AGGREGATABLE(CObjConstSub)
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CObjConstSub)
		COM_INTERFACE_ENTRY(IComObjectConstructionEvents)
		COM_INTERFACE_ENTRY_CHAIN(CSysLCESub)
	END_COM_MAP()

	STDMETHODIMP GetEventType(EventEnum * e){*e = ObjectConstruction;return S_OK;}
	STDMETHODIMP GetEventClass(LPGUID guid){*guid = CLSID_ComServiceEvents;return S_OK;}
	STDMETHODIMP GetInterface(IID* iid){*iid = IID_IComObjectConstructionEvents;return S_OK;}

	STDMETHODIMP OnObjectConstruct(COMSVCSEVENTINFO * pInfo,
									REFGUID guidClass,
									LPCOLESTR pszConstructString,
									ULONG64 ObjectID)
	{

		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnObjConstPutObject"), GuidToBstr(pInfo->guidApp));
		m_pSpy -> AddParamValueToList(L"guidClass", GuidToBstr( guidClass ));
		m_pSpy -> AddParamValueToList(L"sConstructString", pszConstructString);

		WCHAR szObjectID[32];
		wsprintfW(szObjectID, L"0x%016X", ObjectID);
		m_pSpy -> AddParamValueToList(L"ObjectID", szObjectID);

		IF_AUDIT_DO(OnObjectConstruct)(pInfo->perfCount,GuidToBstr(pInfo->guidApp),														
									  GuidToBstr( guidClass ),
									  pszConstructString,
									  szObjectID
									  );
		
		return S_OK;
	}

};

#endif //__OBJCONSTSUB_H__
