// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// Client.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>

#import "..\ATLCollections.tlb"
using namespace ATLCOLLECTIONSLib;

// Outputs all the items in a collection using the Count and Item properties
template <class T>
HRESULT OutputLoopedItems(T sp)
{
	// Get the count of items
	long lCount = sp->GetCount();

	// The collection indexes are 1-based
	for (long i = 1; i <= lCount; ++i)
	{
		_bstr_t bstrTemp = static_cast<_variant_t>(sp->GetItem(i));
		std::cout << static_cast<const char*>(bstrTemp) << "\n";
	}
		
	return S_OK;
}

// Outputs all the items in a collection using the enumerator
template <class T>
HRESULT OutputEnumeratedItems(T sp)
{
	// Get the VARIANT enumerator from the collection
	IEnumVARIANTPtr spEnum = sp->Get_NewEnum();

	// nBatchSize is the number of items that we request in each call to IEnumVARIANT::Next. 
	// The actual number of items returned may not equal nBatchSize.
	const ULONG nBatchSize = 5;

	// nReturned will store the number of items returned by a call to IEnumVARIANT::Next
	ULONG nReturned = 0;

	// arrVariant is the array used to hold the returned items
	VARIANT arrVariant[nBatchSize] = {0};

	HRESULT hr = E_UNEXPECTED;
	do
	{
		hr = spEnum->Next(nBatchSize, &arrVariant[0], &nReturned);
		if (FAILED(hr))
			return hr;

		for (ULONG i = 0; i < nReturned; ++i)
		{
			_bstr_t bstrTemp = static_cast<_variant_t>(arrVariant[i]);
			std::cout << static_cast<const char*>(bstrTemp) << "\n";
			::VariantClear(&arrVariant[i]);
		}

	} while (hr != S_FALSE); // S_FALSE indicates end of collection

	return hr;
}

int main()
{
	CoInitialize(NULL);

	try
	{
		// Words is a read-only collection
		IWordsPtr spWords(__uuidof(Words));

		std::cout << "** The contents of the Words collection obtained via Count/Item **\n";
		OutputLoopedItems(spWords);

		std::cout << "** The contents of the Words collection obtained via the enumerator **\n";
		OutputEnumeratedItems(spWords);

		// Items is a read-write collection
		IItemsPtr spItems(__uuidof(Items));

		std::cout << "** The contents of the Items collection obtained via Count/Item ****\n";
		OutputLoopedItems(spItems);

		std::cout << "** The contents of the Items collection obtained via the enumerator **\n";
		OutputEnumeratedItems(spItems);

		// Update display
		std::cout << "** Testing Add, Remove and Clear methods **\n";
		
		// Get the current item count
		std::cout << "Count: " << spItems->GetCount() << "\n";

		// Define the key and the value for a new item
		const wchar_t* wszKey = L"a key";
		const wchar_t* wszValue = L"a value";

		// Add the item
		spItems->Add(wszKey, wszValue);

		// Get the item
		_bstr_t bstrItem = spItems->GetItem(wszKey);

		// Display the item
		std::cout << "Added item: " << static_cast<const char*>(bstrItem) << "\n";

		// Get the current item count
		std::cout << "Count: " << spItems->GetCount() << "\n";

		// Remove the item
		spItems->Remove(wszKey);

		// Update display
		std::cout << "Removed item: " << static_cast<const char*>(bstrItem) << "\n";

		// Get the current item count
		std::cout << "Count: " << spItems->GetCount() << "\n";

		// Clear all items
		spItems->Clear();

		// Update display
		std::cout << "Cleared all items\n";

		// Get the current item count
		std::cout << "Count: " << spItems->GetCount() << "\n";
	}
	catch (const _com_error& Err)
	{
		std::cout << "Error: " << Err.ErrorMessage() << "\n";
	}
	catch (...)
	{
		std::cout << "Unexpected Error\n";
	}

	CoUninitialize();

	return 0;
}
