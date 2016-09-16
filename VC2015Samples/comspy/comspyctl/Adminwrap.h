// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef _ADMINWRAP_H_
#define _ADMINWRAP_H_

#include <comadmin.h>

typedef enum
{
	APPLICATION=0,
	COMPONENT,
	SUBSCRIPTION,
	TRANSIENTSUB,
	PUBPROP,
	TRANSIENTPUBPROP,
} ADMINTYPE, *PADMINTYPE;


HRESULT AddTransientSubscription(ICOMAdminCatalog* pICat, WCHAR* pwzSubName, WCHAR* pwzECID, WCHAR* pwzPubID, WCHAR* pwzIID, IUnknown *punk,
			                         WCHAR* pwzMethod, WCHAR* pwzCriteria, WCHAR* pwzPubProp, WCHAR* pwzPubVal);
HRESULT RemoveTransientSubscription(ICOMAdminCatalog* pICat, WCHAR* pwzName);

// Catalogue access functions
HRESULT RemoveNamedObjectFromCollection(ICatalogCollection* pICol, BSTR szObjectName, ADMINTYPE type);
HRESULT GetNamedObjectFromCollection(ICatalogCollection* pICol, BSTR szObjName, ICatalogObject** ppICatObj, LONG* plIndex, ADMINTYPE type, BSTR bstrName=NULL);
HRESULT GetCollection(ICOMAdminCatalog* pICat, BSTR szCollName, ICatalogCollection** ppICol);
HRESULT GetCollection(ICatalogCollection* pIParentColl, ICatalogObject* pICatObj, BSTR szCollName, ICatalogCollection** ppICol);
HRESULT GetObjectNameProperty(ADMINTYPE type, BSTR* pbstr);
HRESULT SetStringProperty(ICatalogObject *pcat, BSTR bPROP, WCHAR* pval);
HRESULT SetIUnknownProperty(ICatalogObject *pcat, BSTR bPROP, IUnknown* punk);



#endif
