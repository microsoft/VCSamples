// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#include "stdafx.h"
#include "ComSpyCtl.h"
#include "ComSpyAudit.h"
#include "SysLCESub.h"		// Include our base class.
#include "CComSpy.h"
#include "evtstoresub.h"


STDMETHODIMP CEvtStoreSub::ChangedSubscription
   (/* [in] */ EOC_ChangeType changeType,
	/* [in] */ BSTR bstrSubscriptionID)
{

	LONGLONG perfCount = 0;
	::QueryPerformanceCounter( (LARGE_INTEGER *)&perfCount );
	LPOLESTR lpOperation;
	switch (changeType)
	{
		case EOC_NewObject:
			lpOperation = OLESTR("New Subscription");
			break;
		case EOC_ModifiedObject:
			lpOperation = OLESTR("Modified Subscription");
			break;
		case EOC_DeletedObject:
			lpOperation = OLESTR("Deleted Subscription");
			break;
	}
	m_pSpy -> AddEventToList(perfCount, lpOperation, OLESTR("COM+ Event Store"));
	m_pSpy -> AddParamValueToList(L"Subscription ID", bstrSubscriptionID);
	//TODO: Add Auditing code for subscription change
	AddSubscriptionInfo( m_pSpy, bstrSubscriptionID );
	return S_OK;
}

STDMETHODIMP CEvtStoreSub::ChangedEventClass
   (/* [in] */ EOC_ChangeType changeType,
	/* [in] */ BSTR bstrEventClassID)
{
	LONGLONG perfCount = 0;
	::QueryPerformanceCounter( (LARGE_INTEGER *)&perfCount );
	LPOLESTR lpOperation;
	switch (changeType)
	{
		case EOC_NewObject:
			lpOperation = OLESTR("New Event Class");
			break;
		case EOC_ModifiedObject:
			lpOperation = OLESTR("Modified Event Class");
			break;
		case EOC_DeletedObject:
			lpOperation = OLESTR("Deleted Event Class");
			break;
	}
	m_pSpy -> AddEventToList(perfCount, lpOperation, OLESTR("COM+ Event Store"));
	m_pSpy -> AddParamValueToList(L"Event Class ID", bstrEventClassID);
	
	//TODO: Add Auditing code for event class change
	AddEventClassInfo( m_pSpy, bstrEventClassID );
	return S_OK;
}

STDMETHODIMP CEvtStoreSub::ChangedPublisher
   (/* [in] */ EOC_ChangeType changeType,
	/* [in] */ BSTR bstrPublisherID)
{
	LONGLONG perfCount = 0;
	::QueryPerformanceCounter( (LARGE_INTEGER *)&perfCount );
	LPOLESTR lpOperation;
	switch (changeType)
	{
		case EOC_NewObject:
			lpOperation = OLESTR("New Publisher");
			break;
		case EOC_ModifiedObject:
			lpOperation = OLESTR("Modified Publisher");
			break;
		case EOC_DeletedObject:
			lpOperation = OLESTR("Deleted Publisher");
			break;
	}
	m_pSpy -> AddEventToList(perfCount, lpOperation, OLESTR("COM+ Event Store"));
	m_pSpy -> AddParamValueToList(L"Publisher ID", bstrPublisherID);
	//TODO: Add Auditing code for Publisher Change
	AddPublisherInfo( m_pSpy, bstrPublisherID );
	return S_OK;
}



///////////
STDMETHODIMP CEvtStoreSub::AddSubscriptionInfo
//-----------------------------------------------------------------
// Function Description:
//
//	Given a subscription ID, query the Event Store for information.
//
// Return Value:
//
//  Arguments:
   (/* [in] */ CComSpy* pSpy,
	/* [in] */ BSTR bstrSubscriptionID)
//	
//-----------------------------------------------------------------
{
	HRESULT hr = S_OK;
	// Variables initialized to NULL here to ensure error returns are valid.
	CComPtr<IEventSystem> spIEventSystem = NULL;

	hr = CoCreateInstance(CLSID_CEventSystem,
						  NULL,
						  CLSCTX_SERVER,
						  IID_IEventSystem,
						  (void**)&spIEventSystem);
	if (FAILED(hr))
	{
		ATLTRACE(L"Failed to create CEventSystem");
		return hr;
	}

	// ----------------------------------------------
	// Query for the subscription info
	// ----------------------------------------------

	int errorIndex;
	
	CComBSTR bstrCriteria;
	bstrCriteria = "SubscriptionID=";
	bstrCriteria += bstrSubscriptionID;

	CComPtr<IUnknown> pUnk = NULL;
	hr = spIEventSystem->Query(PROGID_EventSubscription, bstrCriteria, &errorIndex, &pUnk);
	if (FAILED(hr)) 
	{
		ATLTRACE(L"Query for SubcriptionID failed");
		return hr;
	}

	// Got something - now get the info and blast it to Spy.
	CComQIPtr<IEventSubscription, &IID_IEventSubscription> spIEventSubscription;
	spIEventSubscription = pUnk;
	if (!spIEventSubscription) 
	{
		ATLTRACE(L"QI for IEventSubscription failed");
		return hr;
	}

	CComBSTR bstrSubscriptionName;
	CComBSTR bstrEventClassID;
	CComBSTR bstrDescription;

	spIEventSubscription->get_SubscriptionName( &bstrSubscriptionName );
	spIEventSubscription->get_EventClassID( &bstrEventClassID );
	spIEventSubscription->get_Description( &bstrDescription );
	if (FAILED(hr)) 
	{
		ATLTRACE(L"Get of Subscription EventClass failed");
		return hr;
	} else
	{
		pSpy -> AddParamValueToList(L"Subscription Name", bstrSubscriptionName);
		pSpy -> AddParamValueToList(L"Event Class ID", bstrEventClassID);
		pSpy -> AddParamValueToList(L"Description", bstrDescription);
		//TODO: Add Auditing code for subscription change
	}

	return hr;
	
}

STDMETHODIMP CEvtStoreSub::AddEventClassInfo
//-----------------------------------------------------------------
// Function Description:
//
//	Given an Event Class ID, query the Event Store for information.
//
// Return Value:
//
//  Arguments:
   (/* [in] */ CComSpy* pSpy,
	/* [in] */ BSTR bstrEventClassID)
//	
//-----------------------------------------------------------------
{
	HRESULT hr = S_OK;
	// Variables initialized to NULL here to ensure error returns are valid.
	CComPtr<IEventSystem> spIEventSystem = NULL;

	hr = CoCreateInstance(CLSID_CEventSystem,
						  NULL,
						  CLSCTX_SERVER,
						  IID_IEventSystem,
						  (void**)&spIEventSystem);
	if (FAILED(hr))
	{
		ATLTRACE(L"Failed to create CEventSystem");
		return hr;
	}

	// ----------------------------------------------
	// Query for the EventClass info
	// ----------------------------------------------

	int errorIndex;

	CComBSTR bstrCriteria;
	bstrCriteria = "EventClassID=";
	bstrCriteria += bstrEventClassID;

	CComPtr<IUnknown> pUnk = NULL;
	hr = spIEventSystem->Query(PROGID_EventClass, bstrCriteria, &errorIndex, &pUnk);
	if (FAILED(hr)) 
	{
		ATLTRACE(L"Query for SubcriptionID failed");
		return hr;
	}

	// Got something - now get the info and blast it to Spy.
	CComQIPtr<IEventClass, &IID_IEventClass> spIEventClass;
	spIEventClass = pUnk;
	if (!spIEventClass) 
	{
		ATLTRACE(L"QI for IEventClass failed");
		return hr;
	}

	CComBSTR bstrEventClassName;
	CComBSTR bstrFiringInterfaceID;
	CComBSTR bstrOwnerSID;
	CComBSTR bstrDescription;

	spIEventClass->get_EventClassName( &bstrEventClassName );
	spIEventClass->get_FiringInterfaceID( &bstrFiringInterfaceID );
	spIEventClass->get_Description( &bstrDescription );
	spIEventClass->get_OwnerSID( &bstrOwnerSID );
	if (FAILED(hr)) 
	{
		ATLTRACE(L"Get of EventClass EventClass failed");
		return hr;
	} else
	{
		pSpy -> AddParamValueToList(L"EventClass Name", bstrEventClassName);
		pSpy -> AddParamValueToList(L"Firing Interface ID", bstrFiringInterfaceID);
		pSpy -> AddParamValueToList(L"Description", bstrDescription);
		pSpy -> AddParamValueToList(L"Owner SID", bstrOwnerSID);
		//TODO: Add Auditing code for EventClass change
	}

	
	return hr;

}

STDMETHODIMP CEvtStoreSub::AddPublisherInfo
//-----------------------------------------------------------------
// Function Description:
//
//	Given a Publisher ID, query the Event Store for information.
//
// Return Value:
//
//  Arguments:
   (/* [in] */ CComSpy* pSpy,
	/* [in] */ BSTR bstrPublisherID)
//	
//-----------------------------------------------------------------
{
	HRESULT hr = S_OK;
	// Variables initialized to NULL here to ensure error returns are valid.
	CComPtr<IEventSystem> spIEventSystem = NULL;

	hr = CoCreateInstance(CLSID_CEventSystem,
						  NULL,
						  CLSCTX_SERVER,
						  IID_IEventSystem,
						  (void**)&spIEventSystem);
	if (FAILED(hr))
	{
		ATLTRACE(L"Failed to create CEventSystem");
		return hr;
	}

	// ----------------------------------------------
	// Query for the Publisher info
	// ----------------------------------------------

	int errorIndex;

	CComBSTR bstrCriteria;
	bstrCriteria = "PublisherID=";
	bstrCriteria += bstrPublisherID;

	CComPtr<IUnknown> pUnk = NULL;
	hr = spIEventSystem->Query(PROGID_EventPublisher, bstrCriteria, &errorIndex, &pUnk);
	if (FAILED(hr)) 
	{
		ATLTRACE(L"Query for SubcriptionID failed");
		return hr;
	}

	// Got something - now get the info and blast it to Spy.
	CComQIPtr<IEventPublisher, &IID_IEventPublisher> spIEventPublisher;
	spIEventPublisher = pUnk;
	if (!spIEventPublisher) 
	{
		ATLTRACE(L"QI for IEventPublisher failed");
		return hr;
	}

	CComBSTR bstrPublisherName;
	CComBSTR bstrPublisherType;
	CComBSTR bstrDescription;
	CComBSTR bstrOwnerSID;

	spIEventPublisher->get_PublisherName( &bstrPublisherName );
	spIEventPublisher->get_PublisherType( &bstrPublisherType );
	spIEventPublisher->get_Description( &bstrDescription );
	spIEventPublisher->get_OwnerSID( &bstrOwnerSID );
	if (FAILED(hr)) 
	{
		ATLTRACE(L"Get of Publisher Publisher failed");
		return hr;
	} else
	{
		pSpy -> AddParamValueToList(L"Publisher Name", bstrPublisherName);
		pSpy -> AddParamValueToList(L"Publisher Type", bstrPublisherType);
		pSpy -> AddParamValueToList(L"Description", bstrDescription);
		pSpy -> AddParamValueToList(L"Owner SID", bstrOwnerSID);
		//TODO: Add Auditing code for Publisher change
	}

	return hr;

}
