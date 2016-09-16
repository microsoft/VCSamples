// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#include "stdafx.h"
#include "Adminwrap.h"
#include <comadmin.h>
#include <assert.h>

#define SAFERELEASE(p)	if (p) \
			{ p->Release();\
			p = 0;}

#define exit(hr)	if FAILED(hr)	\
					goto exit;	

//*********************************************
// Globals

BSTR g_bstrPUBID = L"PublisherID";
BSTR g_bstrNAME = L"Name";
BSTR g_bstrVALUE = L"Value";
BSTR g_bstrECID = L"EventCLSID";
BSTR g_bstrIID = L"InterfaceID";
BSTR g_bstrMETHOD = L"MethodName";
BSTR g_bstrCRITERIA = L"FilterCriteria";
BSTR g_bstrTRANSSUB = L"TransientSubscriptions";
BSTR g_bstrSUBINT = L"SubscriberInterface";
BSTR g_bstrTRANSPUBPROP = L"TransientPublisherProperties";

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name			: AddTransientSubscription
// Purppose		: Adds a Persistent Subscription
// Parameters	:
//				:ICOMAdminCatalog* pICat -interface pointer to admin catelog object
//				: WCHAR* pwzSubName		- Name of the subscription
//				: WCHAR* pwzECID		- EventClass ID
//				: WCHAR* pwzPubID		- Name of the Publisher
//				: WCHAR* pwzIID         - Interface Name (in string form)
//				: IUnknown* punk		- IUnknown* of the subscriber
//				: WCHAR* pwzMethod		- Method in the interface to subscribe
//				: WCHAR* pwzCriteria	- Filter Criteria (used in parameterized filtering)
//				: WCHAR* pwzPubProp		- Publisher Property Name
//				: WCHAR* pwzPubVal		- Publisher Property Value
// Return Value : HRESULT
////////////////////////////////////////////////////////////////////////////////////////////////////

HRESULT AddTransientSubscription(ICOMAdminCatalog* pICat,
									   WCHAR* pwzSubName, WCHAR* pwzECID, WCHAR* pwzPubID, WCHAR* pwzIID, IUnknown *punk,
									   WCHAR* pwzMethod, WCHAR* pwzCriteria, WCHAR* pwzPubProp, WCHAR* pwzPubVal)
{
	HRESULT					hr =0;
	ICatalogObject			*pISub=0, *pIProp=0;
	ICatalogCollection		*pISubs=0, *pIProps=0;
	IDispatch				*pIDisp=0;
	long					lret=0;
	BOOL					fCreate=FALSE, fComplete = FALSE;
	
	if (!pICat || !pwzSubName || !punk)
		return E_INVALIDARG;

	hr = GetCollection(pICat, g_bstrTRANSSUB, &pISubs);
	exit(hr);

	hr = pISubs->Add(&pIDisp);
	exit(hr);

	hr = pIDisp->QueryInterface(__uuidof(ICatalogObject), (LPVOID*)&pISub);
	exit(hr);

	hr = SetStringProperty(pISub, g_bstrNAME, pwzSubName);
	exit(hr);

	hr = SetStringProperty(pISub, g_bstrECID, pwzECID);
	exit(hr);

	hr = SetStringProperty(pISub, g_bstrPUBID, pwzPubID);
	exit(hr);

	hr = SetStringProperty(pISub, g_bstrIID, pwzIID);
	exit(hr);

	hr = SetIUnknownProperty(pISub, g_bstrSUBINT, punk);
	exit(hr);

	hr = SetStringProperty(pISub, g_bstrMETHOD, pwzMethod);
	exit(hr);

	hr = SetStringProperty(pISub, g_bstrCRITERIA, pwzCriteria);
	exit(hr);

	hr = pISubs->SaveChanges(&lret);
	exit(hr);

	fCreate = TRUE;

	if (pwzPubProp && pwzPubVal)
	{

		hr = GetCollection(pISubs, pISub, g_bstrTRANSPUBPROP, &pIProps);
		exit(hr);

		SAFERELEASE(pIDisp);
		hr = pIProps->Add(&pIDisp);
		exit(hr);

		hr = pIDisp->QueryInterface(__uuidof(ICatalogObject), (LPVOID*)&pIProp);
		exit(hr);

		hr = SetStringProperty(pIProp, g_bstrNAME, pwzPubProp);
		exit(hr);
		
		hr = SetStringProperty(pIProp, g_bstrVALUE, pwzPubVal);
		exit(hr);

		hr = pIProps->SaveChanges(&lret);
		exit(hr);
	}

	fComplete = TRUE;
	
exit:
	if (fCreate && !fComplete)
		RemoveTransientSubscription(pICat, pwzSubName);
	SAFERELEASE(pIDisp);
	SAFERELEASE(pIProp);
	SAFERELEASE(pIProps);
	SAFERELEASE(pISub);
	SAFERELEASE(pISubs);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name			: RemoveTransientSubscription
// Purppose		: Remolves a Persistent Subscription
// Parameters	:
//				: WCHAR* pwzSubName		- Name of the subscription
// Return Value : HRESULT
////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT RemoveTransientSubscription(ICOMAdminCatalog* pICat, WCHAR* pwzName)
{
	HRESULT					hr =0;
	ICatalogCollection		*pISubs=0;

	if (!pICat || !pwzName)
		return E_INVALIDARG;

	hr = GetCollection(pICat, g_bstrTRANSSUB, &pISubs);
	exit(hr);

	hr = RemoveNamedObjectFromCollection(pISubs, BSTR(pwzName), TRANSIENTSUB);
exit:
	SAFERELEASE(pISubs);
	return hr;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
// Name			: GetCollection
// Purppose		: Gets a collection from the Catalogue
// Parameters	:
//				: ICOMAdminCatalog* pICat				- Admin Catalog object
//				: BSTR szCollName						- Collection Name
//				: ICatalogCollection** ppICol			- Collection returned
// Return Value : HRESULT
////////////////////////////////////////////////////////////////////////////////////////////////////
HRESULT GetCollection(ICOMAdminCatalog* pICat, BSTR szCollName, ICatalogCollection** ppICol)
{
	HRESULT hr = E_INVALIDARG;
	IDispatch* pIDisp = NULL;
	if (!pICat || !szCollName || !ppICol) 
		goto exit;
	
	hr = pICat->GetCollection(szCollName, &pIDisp);
	exit(hr);
	hr = pIDisp->QueryInterface(__uuidof(ICatalogCollection), (LPVOID*)ppICol);
	exit(hr);
	hr = (*ppICol)->Populate();
exit:
	SAFERELEASE(pIDisp);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name			: GetCollection
// Purppose		: Gets a collection from the Catalogue
// Parameters	:
//				: ICatalogCollection* pIParentColl		- Parent Collection
//				: ICatalogObject* pICatObj				- Parent Object
//				: BSTR szCollName						- Collection Name
//				: ICatalogCollection** ppICol			- Collection returned
// Return Value : HRESULT
////////////////////////////////////////////////////////////////////////////////////////////////////	
HRESULT GetCollection(ICatalogCollection* pIParentColl, ICatalogObject* pICatObj, BSTR szCollName, 
					  ICatalogCollection** ppICol)
{
	HRESULT hr = E_INVALIDARG;
	VARIANT var;
	IDispatch* pIDisp = NULL;
	VariantInit(&var);
	if (!pIParentColl || !pICatObj || !szCollName || !ppICol)
		goto exit;
	hr = pICatObj->get_Key(&var);
	exit(hr);
	hr = pIParentColl->GetCollection(szCollName, var, &pIDisp);
	exit(hr);
	hr = pIDisp->QueryInterface(__uuidof(ICatalogCollection), (LPVOID*)ppICol);
	exit(hr);
	hr = (*ppICol)->Populate();
exit:
	VariantClear(&var);
	if(pIDisp)
		pIDisp->Release();
	return hr;
}



///////////////////////////////////////////////////////////////////////////////////////////////////
// Name			: RemoveNamedObjectFromCollection
// Purppose		: Removes an object from a collection
// Parameters	:
//				: ICatalogCollection* pIParentColl		- Collection from the object has to be 
//														  removed
//				: BSTR szObjectName						- Object name
//				: ADMINTYPE type						- type of the object
// Return Value : HRESULT
////////////////////////////////////////////////////////////////////////////////////////////////////	
HRESULT RemoveNamedObjectFromCollection(ICatalogCollection* pICol, BSTR szObjectName, ADMINTYPE type)
{
	HRESULT hr = E_FAIL;
	ICatalogObject* pICatObj = NULL;
	LONG key, lTotal;

	if (wcscmp(szObjectName, SysAllocString(L"*"))) 
	{
		hr = GetNamedObjectFromCollection(pICol, szObjectName, &pICatObj, &key, type);
		exit(hr);
		hr = pICol->Remove(key);
		exit(hr);
		hr = pICol->SaveChanges(&key);
	}
	else
	{
		hr = pICol->get_Count(&lTotal);
		exit(hr);
		for (key=lTotal-1; key >= 0; key--)
		{
			hr = pICol->Remove(key);
			exit(hr);
			hr = pICol->SaveChanges(&key);
			exit(hr);
		}
	}

exit:
	if(pICatObj)
		pICatObj->Release();
	return hr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name			: GetNamedObjectFromCollection
// Purppose		: Gets an object from a collection
// Parameters	:
//				: ICatalogCollection* pIParentColl		- Collection from the object has to be 
//														  retrieved
//				: BSTR bstrObjName						- Object name
//				: ADMINTYPE type						- type of the object
//				: ICatalogObject** ppObj				- return Object
//				: LONG* plIndex							- Index of the object (-1, if not found)
//				: ADMINTYPE type						- type of the object
//				: BSTR bstrPropname						- name of the property
// Return Value : HRESULT
////////////////////////////////////////////////////////////////////////////////////////////////////	
HRESULT GetNamedObjectFromCollection(ICatalogCollection* pCol, BSTR bstrObjName, ICatalogObject** ppObj, 
									 LONG* plIndex, ADMINTYPE type, BSTR bstrPropname)
{
	HRESULT hr = E_FAIL;
	LONG lCount = 0;
	LONG i = 0;
	ICatalogObject* pObj = NULL;
	CComBSTR bstrName;
	VARIANT varProp;
	BOOL	fFound = FALSE;

	VariantInit(&varProp);
	if (!pCol || !bstrObjName || !ppObj)  	
		return E_INVALIDARG;
	
	if (!bstrPropname)
	{
		bstrName = g_bstrNAME;
	}
	else
		bstrName = bstrPropname;

	*ppObj = NULL;

	hr = pCol->Populate();
	exit(hr);

	hr = pCol->get_Count(&lCount);
	exit(hr);

	if (lCount == 0)
	{
		*plIndex = -1; // To indicate that the object is not found in the collection
		exit(hr=E_FAIL);
	}
	
	// Loop through 
	for (i = 0; i < lCount; i++)
	{
		VariantClear(&varProp);

		// Get the next item
		hr = pCol->get_Item(i, (IDispatch**)&pObj);
		exit(hr);
		
		// Retrieve it's name property
		hr = pObj->get_Value((BSTR)bstrName, &varProp);
		exit(hr);

		// Check it's name property for a match
		if (wcscmp(bstrObjName, varProp.bstrVal) == 0)
		{
			// Found it!
			*ppObj = pObj;
			pObj->AddRef();
			VariantClear(&varProp);
			// does user want index of the just-found object?
			if (plIndex)
				*plIndex = i;
			fFound = TRUE;
			hr = S_OK;
			goto exit;
		}
	    SAFERELEASE(pObj);
	}
	
	// If we got here then we didn't find it
	if (plIndex)
		*plIndex = -1; // To indicate that the object is not found in the collection
exit:
	SAFERELEASE(pObj);
	return hr;
}


///////////////////////////////////////////////////////////////////////////////////////////////////
// Name			: SetStringProperty
// Purppose		: Gets the property name of the object
// Parameters	:
//				: ICatalogObject *pcat			-  Pointer to the object
//				: BSTR bstrPROP					-  Name of the property
//              : WCHAR* pval					-  Value of the property
// Return Value : HRESULT
////////////////////////////////////////////////////////////////////////////////////////////////////	
HRESULT SetStringProperty(ICatalogObject *pcat, BSTR bstrPROP, WCHAR* pval)
{
	HRESULT hr;
	VARIANT var;
	if (!pcat)
		return E_INVALIDARG;

	if (!pval)
		return S_FALSE;

	VariantClear(&var);

	var.bstrVal = SysAllocString(pval);
	if (!var.bstrVal)
		exit(hr=E_OUTOFMEMORY);
	var.vt = VT_BSTR;

	hr = pcat->put_Value(bstrPROP, var);
	exit(hr);

exit:
	VariantClear(&var);
	return hr;
}

///////////////////////////////////////////////////////////////////////////////////////////////////
// Name			: SetIUnknownProperty
// Purppose		: Gets the property name of the object
// Parameters	:
//				: ICatalogObject *pcat			-  Pointer to the object
//				: BSTR bstrPROP					-  Name of the property
//              : IUnknown* punk				-  Value of the property
// Return Value : HRESULT
////////////////////////////////////////////////////////////////////////////////////////////////////	
HRESULT SetIUnknownProperty(ICatalogObject *pcat, BSTR bstrPROP, IUnknown* punk)
{
	HRESULT hr;
	VARIANT var;
	if (!punk || !pcat)
		return E_INVALIDARG;

	VariantClear(&var);

	var.punkVal = punk;
	var.vt = VT_UNKNOWN;
	punk->AddRef();	// We'll be caling VariantClear

	hr = pcat->put_Value(bstrPROP, var);
	exit(hr);

exit:
	VariantClear(&var);
	return hr;
}

