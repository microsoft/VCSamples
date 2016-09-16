// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#include "stdafx.h"
#include "ComSpyCtl.h"
#include "SysLCESub.h"

#include "adminwrap.h"
#include <stdio.h>


/////////////////////////////////////////////////////////////////////////////
// CSysLCESub

STDMETHODIMP CSysLCESub::Install(BSTR* pPropertyName, VARIANT PropertyValue)
{
	EventEnum eEvent;
	GetEventType( &eEvent );
	CComBSTR bstrSubscriptionName (EventName( eEvent ));
	CComBSTR bstrSubscriptionID;
	IID iid;
	CComBSTR bstrInterfaceID;
	GUID EventClass;
	CComBSTR bstrEventClassID;
	HRESULT hr = S_OK;
	LPOLESTR strGUID;

	hr = StringFromIID(m_SubscriptionGuid, &strGUID);
	if (FAILED(hr))
	{
		ATLTRACE(L"Failed to Create String from IID");
		return hr;
	}

	bstrSubscriptionID = strGUID;
	CoTaskMemFree(strGUID);

	GetEventClass( &EventClass );
	hr = StringFromIID(EventClass, &strGUID);
	if (FAILED(hr))
	{
		ATLTRACE(L"Failed to Create String from IID");
		return hr;
	}

	bstrEventClassID = strGUID;
	CoTaskMemFree(strGUID);
	
	GetInterface( &iid );
	hr = StringFromIID(iid, &strGUID);
	if (FAILED(hr))
	{
		ATLTRACE(L"Failed to Create String from IID");
		return hr;
	}

	bstrInterfaceID = strGUID;
	CoTaskMemFree(strGUID);

	ICOMAdminCatalog* pICat;
	if (SUCCEEDED(hr = CoCreateInstance(__uuidof(COMAdminCatalog),
					      NULL,
						  CLSCTX_SERVER,
						  __uuidof(ICOMAdminCatalog),
						  (LPVOID*)&pICat)))
	{
		AddTransientSubscription(pICat,
								bstrSubscriptionName,
								bstrEventClassID,
								NULL,
								bstrInterfaceID,
								GetUnknown(),
								NULL,
								NULL,
								pPropertyName ? *pPropertyName : NULL,
								pPropertyName ? PropertyValue.bstrVal : NULL);


		pICat->Release();
	}
	return hr;

}

STDMETHODIMP CSysLCESub::Uninstall()
{
	HRESULT hr;
	EventEnum eEvent;
	GetEventType( &eEvent );
	CComBSTR bstrSubscriptionName (EventName( eEvent ));
	ICOMAdminCatalog* pICat;
	if (SUCCEEDED(hr = CoCreateInstance(__uuidof(COMAdminCatalog),
					      NULL,
						  CLSCTX_SERVER,
						  __uuidof(ICOMAdminCatalog),
						  (LPVOID*)&pICat)))
	{
		RemoveTransientSubscription(pICat,
								bstrSubscriptionName);
		pICat->Release();
	}
	return hr;
}

OLECHAR* CSysLCESub::EventName
//-----------------------------------------------------------------
// Function Description:
//
//	Translates from the EventEnum type to a text string
//
// Return Value:
//
//  Arguments:
   (EventEnum e)
//	
//-----------------------------------------------------------------
{
	switch (e)
	{
		case Application:
		{						
			return OLESTR("Application");
			break;
		}
		case Thread:
		{						
			return OLESTR("Thread");
			break;
		}
		case Instance:
		{						
			return OLESTR("Instance");
			break;
		}
		case Transaction:
		{
			return OLESTR("Transaction");
			break;
		}
		case Method:
		{						
			return OLESTR("Method");
			break;
		}
		case Object:
		{						
			return OLESTR("Object");
			break;
		}
		case Resource:
		{						
			return OLESTR("Resource");
			break;
		}
		case User:
		{						
			return OLESTR("User");
			break;
		}
		case Security:
		{						
			return OLESTR("Security");
			break;
		}
		case ObjectConstruction:
		{						
			return OLESTR("Construction");
			break;
		}
		case ObjectPool:
		{						
			return OLESTR("Pool");
			break;
		}
		case ObjectPool2:
		{						
			return OLESTR("Pool2");
			break;
		}
		case Activity:
		{						
			return OLESTR("Activity");
			break;
		}
		case Identity:
		{						
			return OLESTR("Identity");
			break;
		}
		case QC:
		{						
			return OLESTR("Queued Components");
			break;
		}
		case Exception:
		{						
			return OLESTR("Exception");
			break;
		}
		case CRM:
		{						
			return OLESTR("CRM");
			break;
		}
		case EventStore:
		{						
			return OLESTR("EventStore");
			break;
		}
		case LoadBalancing: 
		{						
			return OLESTR("LoadBalancing");
			break;
		}
		default:
			ATLTRACE(L"Object type not implemented in SysLCESub\n");
			_ASSERTE(0);
			break;
	}
	return NULL;
}
