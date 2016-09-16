// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __IDENTITYSUB_H__
#define __IDENTITYSUB_H__

#include "resource.h"       // main symbols

CComBSTR GuidToBstr(REFGUID guid);

class CComSpy;

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
Class:   CIdentitySub
Summary: Identity Events Subscriber 
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/ 
class ATL_NO_VTABLE CIdentitySub : 
	public CSysLCESub,
	public IComIdentityEvents
{
public:
	CIdentitySub(CComSpy * pSpy)
	{
		m_pSpy = pSpy;
	}

	CIdentitySub()
	{
		m_pSpy = NULL;
	}

	DECLARE_NOT_AGGREGATABLE(CIdentitySub)
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CIdentitySub)
		COM_INTERFACE_ENTRY(IComIdentityEvents)
		COM_INTERFACE_ENTRY_CHAIN(CSysLCESub)
	END_COM_MAP()

	STDMETHODIMP GetEventType(EventEnum * e){*e = Identity;return S_OK;}
	STDMETHODIMP GetEventClass(LPGUID guid){*guid = CLSID_ComServiceEvents;return S_OK;}
	STDMETHODIMP GetInterface(IID* iid){*iid = IID_IComIdentityEvents;return S_OK;}

	STDMETHODIMP OnIISRequestInfo(
							 COMSVCSEVENTINFO * pInfo,
							 ULONG64 ObjId,
							 LPCOLESTR pszClientIP,
							 LPCOLESTR pszServerIP,
							 LPCOLESTR pszURL
							)
	{	
		m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnIISRequestInfo"), GuidToBstr(pInfo->guidApp));

		WCHAR szObjectID[32];
		wsprintfW(szObjectID, L"0x%016X", ObjId);
		m_pSpy -> AddParamValueToList(L"ObjectID", szObjectID);

		m_pSpy -> AddParamValueToList(L"ClientIP", pszClientIP);
		m_pSpy -> AddParamValueToList(L"ServerIP", pszServerIP);
		m_pSpy -> AddParamValueToList(L"URL", pszURL);


		IF_AUDIT_DO(OnIISRequestInfo)(pInfo->perfCount, GuidToBstr(pInfo->guidApp),							
									szObjectID,						
									pszClientIP,						
									pszServerIP,
									pszURL
									);

		return S_OK;
	}

};

#endif //__IDENTITYSUB_H__
