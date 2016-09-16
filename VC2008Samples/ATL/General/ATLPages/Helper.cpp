// Helper.cpp : Implementation of CHelper

// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "ATLPages7.h"
#include "Helper.h"


// Helper to create a property frame for a single property page and a single object
STDMETHODIMP CHelper::ShowPage(BSTR bstrCaption, BSTR bstrID, IUnknown* pUnk)
{
	// Ensure that we can take the address of pUnk
	if (!pUnk)
		return E_INVALIDARG;

	// First, assume bstrID is a string representing the CLSID 
	CLSID theCLSID = {0};
	HRESULT hr = CLSIDFromString(bstrID, &theCLSID);
	if (FAILED(hr))
	{
		// Now assume bstrID is a ProgID
		hr = CLSIDFromProgID(bstrID, &theCLSID);
		if (FAILED(hr))
			return hr;
	}

	// Use the system-supplied property frame
	return OleCreatePropertyFrame(
				GetActiveWindow(),	// Parent window of the property frame
				0,					// Horizontal position of the property frame
				0,					// Vertical position of the property frame
				bstrCaption,		// Property frame caption
				1,					// Number of objects
				&pUnk,				// Array of IUnknown pointers for objects
				1,					// Number of property pages
				&theCLSID,			// Array of CLSIDs for property pages
				NULL,				// Locale identifier
				0,					// Reserved - 0
				NULL				// Reserved - 0
				);
}

// Helper to create property pages for objects supporting ISpecifyPropertyPages
STDMETHODIMP CHelper::ShowSpecifiedPages(BSTR bstrCaption, IUnknown* pUnk)
{
	// Ensure that we can take the address of pUnk
	if (!pUnk)
		return E_INVALIDARG;

	// Query object for ISpecifyPropertyPages interface
	CComQIPtr<ISpecifyPropertyPages> spSpec(pUnk);
	if (!spSpec)
		return E_NOINTERFACE;
	
	// Get list of property pages
	CAUUID cauuid = {0};
	HRESULT hr = spSpec->GetPages(&cauuid);

	// Use the system-supplied property frame
	if (SUCCEEDED(hr) && (cauuid.cElems != 0))
	{
		hr = OleCreatePropertyFrame(
				GetActiveWindow(),	// Parent window of the property frame
				0,					// Horizontal position of the property frame
				0,					// Vertical position of the property frame
				bstrCaption,		// Property frame caption
				1,					// Number of objects
				&pUnk,				// Array of IUnknown pointers for objects
				cauuid.cElems,		// Number of property pages
				cauuid.pElems,		// Array of CLSIDs for property pages
				NULL,				// Locale identifier
				0,					// Reserved - 0
				NULL				// Reserved - 0
				);

		// Free array allocated by GetPages
		CoTaskMemFree(cauuid.pElems);
	}

	return hr;
}
