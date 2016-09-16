// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __USERSUB_H__
#define __USERSUB_H__

#include "resource.h"       // main symbols

CComBSTR GuidToBstr(REFGUID guid);

class CComSpy;

/*C+C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C+++C
Class:   CUserSub
Summary: User Events Subscriber 
C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C---C-C*/ 
class ATL_NO_VTABLE CUserSub : 
	public CSysLCESub,
	public IComUserEvent
{
public:

	CUserSub(CComSpy * pSpy)
	{
		m_pSpy = pSpy;
	}
	CUserSub()
	{
		m_pSpy = NULL;
	}

	DECLARE_NOT_AGGREGATABLE(CUserSub)
	DECLARE_GET_CONTROLLING_UNKNOWN()

	BEGIN_COM_MAP(CUserSub)
		COM_INTERFACE_ENTRY(IComUserEvent)
		COM_INTERFACE_ENTRY_CHAIN(CSysLCESub)
	END_COM_MAP()

	STDMETHODIMP GetEventType(EventEnum * e){*e = User;return S_OK;}
	STDMETHODIMP GetEventClass(LPGUID guid){*guid = CLSID_ComServiceEvents;return S_OK;}
	STDMETHODIMP GetInterface(IID* iid){*iid = IID_IComUserEvent;return S_OK;}

	STDMETHODIMP OnUserEvent(COMSVCSEVENTINFO * pInfo, VARIANT * var)
	{
		if (var -> vt == VT_BSTR)
		{
			m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnUserEvent"), GuidToBstr(pInfo->guidApp));
			m_pSpy -> AddParamValueToList(L"String Value",  var->bstrVal);	
		}
		else if (var -> vt == VT_UNKNOWN)
		{
			IMtsEventInfo * pEvtInfo = NULL;
			
			var -> punkVal -> QueryInterface(IID_IMtsEventInfo, (void **)&pEvtInfo);  
			if(pEvtInfo)
			{
				CComBSTR s;
				pEvtInfo -> get_DisplayName(&s.m_str);
				m_pSpy -> AddEventToList(pInfo->perfCount, s.m_str, GuidToBstr(pInfo->guidApp));	

				long lCount;
				pEvtInfo -> get_Count(&lCount);
				if (lCount)
				{
					VARIANT var1;
					LPOLESTR * pKeys = new LPOLESTR[lCount+1];
					IUnknown * pUnk = NULL;
					pEvtInfo -> get_Names(&pUnk);
					_ASSERTE(pUnk);
					IEnumString * pEnum;
					pUnk -> QueryInterface(IID_IEnumString, (void **)&pEnum);
					_ASSERTE(pEnum);
					pUnk -> Release();
					ULONG lFetched;
					pEnum -> Next(lCount, pKeys, &lFetched);
					pEnum -> Release();				
					_ASSERTE(lFetched == lCount);
					UINT i;
					for (i=0; i<lFetched; i++)
					{
						s = pKeys[i];
						pEvtInfo -> get_Value(s, &var1);
						if (var1.vt == VT_BSTR)
						{
							m_pSpy -> AddParamValueToList(pKeys[i],  var1.bstrVal);	
							VariantClear(&var1);
						}
					}
					for (i=0; i< static_cast<UINT>(lCount); i++)
						CoTaskMemFree(pKeys[i]);

					delete pKeys;
				}
				pEvtInfo -> Release();
			}
		}
		else
			m_pSpy -> AddEventToList(pInfo->perfCount, _TEXT("OnUserEvent"), GuidToBstr(pInfo->guidApp));


		return S_OK;
	}

};

#endif //__USERSUB_H__
