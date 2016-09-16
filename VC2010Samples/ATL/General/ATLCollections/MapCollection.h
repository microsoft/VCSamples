// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// MapCollection.h : Declaration of the CMapCollection

#ifndef __MAPCOLLECTION_H_
#define __MAPCOLLECTION_H_

#include "resource.h"       // main symbols

#pragma warning(push)
#pragma warning(disable:4702)
#include <map>
#pragma warning(pop)

#include "Reuse\VCUE_Collection.h"
#include "Reuse\VCUE_Copy.h"


// CItems shows how to create a COM collection using ATL's onSTL classes 
// and the classes defined in VCUE_Collection.h and VCUE_Copy.h.
// This class demonstrates how to implement methods for adding and removing items from the collection
// and how to implement get_Item to support both numeric and string indexing


namespace MapColl
{
	// We always need to provide the following information
	typedef std::map< CAdapt< CComBSTR >, CComVariant >				ContainerType;
	typedef VARIANT													ExposedType;
	typedef IEnumVARIANT											EnumeratorInterface;
	typedef IItems											CollectionInterface;

	// Typically the copy policy can be calculated from the typedefs defined above:
	// typedef VCUE::GenericCopy<ExposedType, ContainerType::value_type>		CopyType;

	// However, we may want to use a different class, as in this case:
	typedef VCUE::MapCopy<ContainerType, ExposedType>				CopyType;
	// (The advantage of MapCopy is that we don't need to provide implementations 
	//  of GenericCopy for all the different pairs of key and value types)

	// Now we have all the information we need to fill in the template arguments on the implementation classes
	typedef CComEnumOnSTL< EnumeratorInterface, &__uuidof(EnumeratorInterface), ExposedType,
							CopyType, ContainerType > EnumeratorType;

	typedef VCUE::ICollectionOnSTLCopyImpl< CollectionInterface, ContainerType, ExposedType,
							CopyType, EnumeratorType > CollectionType;
};

using namespace MapColl;

/////////////////////////////////////////////////////////////////////////////
// CItems
class ATL_NO_VTABLE CItems : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CItems, &CLSID_Items>,
	public IDispatchImpl<MapColl::CollectionType, &IID_IItems, &LIBID_ATLCOLLECTIONSLib>
{
public:
	CItems()
	{
		m_coll[CComBSTR("One")] = "One";
		m_coll[CComBSTR("OneHundred")] = "100";
		m_coll[CComBSTR("OneThousand")] = 1000;
		m_coll[CComBSTR("pi")] = 3.141592654f;
		m_coll[CComBSTR("ATL")] = "Active Template Library";
	}

DECLARE_REGISTRY_RESOURCEID(IDR_MAPCOLLECTION)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CItems)
	COM_INTERFACE_ENTRY(IItems)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IItems
public:
	
	// ATL's collection implementation only allows numeric indexing (due to container-independence)
	// so we have to provide our own implementation to allow string indexing into the map
	STDMETHOD(get_Item)(VARIANT Index, VARIANT* pVal)
	{
		if (pVal == NULL)
			return E_POINTER;

		HRESULT hr = S_OK;
		CComVariant var;

		if (Index.vt != VT_BSTR)
		{
			// If the index isn't a string, but can be converted to a long value, we use ATL's implementation
			hr = var.ChangeType(VT_I4, &Index);
			if (SUCCEEDED(hr))
				return CollectionType::get_Item(var.lVal, pVal);
		}

		// Otherwise, we assume index is a key into the map
		hr = var.ChangeType(VT_BSTR, &Index);

		// If we can't convert to a string, just return
		if (FAILED(hr))
			return hr;

		ContainerType::iterator it = m_coll.find(CComBSTR(var.bstrVal));

		// If item not found, just return
		if (it == m_coll.end())
			return E_FAIL;
			
		// If item was found, copy the variant to the out param
		return (CComVariant(it->second).Detach(pVal));
	}

	STDMETHOD(Add)(VARIANT Key, VARIANT Value)
	{
		// Get a BSTR from the VARIANT
		CComBSTR str;
		HRESULT hr = VCUE::GenericCopy<BSTR, VARIANT>::copy(&str, &Key);

		// If we can't convert to a string, just return
		if (FAILED(hr))
			return hr;

		// Check whether item already exists
		if (m_coll.find(str) != m_coll.end())
			return E_FAIL;	// item with this key already exists

		// Add the item to the map
		m_coll[str] = Value;
		return S_OK;
	}

	STDMETHOD(Remove)(VARIANT Index)
	{
		HRESULT hr = S_OK;
		CComVariant var;

		if (Index.vt != VT_BSTR)
		{
			// If the index isn't a string, but can be converted to a long value, we use the long implementation of Remove
			hr = var.ChangeType(VT_I4, &Index);
			if (SUCCEEDED(hr))
				return Remove(var.lVal);
		}

		// Otherwise, we assume index is a key into the map
		hr = var.ChangeType(VT_BSTR, &Index);

		// If we can't convert to a string, just return
		if (FAILED(hr))
			return hr;

		ContainerType::iterator it = m_coll.find(CComBSTR(var.bstrVal));

		// If item not found, just return
		if (it == m_coll.end())
			return E_FAIL;
			
		// If item was found, remove it from the map
		m_coll.erase(it);
		
		// (Could just use erase on the key, but it's not clear what erase does if the item isn't present.
		//  Our method is safer and allows us to inform the client of failure.)
		return S_OK;
	}

	STDMETHOD(Remove)(size_t Index)
	{
		// NOTE: This code can be used with most STL containers

		// Check that the 1-based index is in bounds
		if (Index <= 0 || Index > m_coll.size())
			return E_INVALIDARG;

		// Get the iterator and erase the item
		ContainerType::iterator it = m_coll.begin();
		std::advance(it, Index - 1);
		m_coll.erase(it);

		return S_OK;
	}

	STDMETHOD(Clear)()
	{
		// NOTE: This code can be used with most STL containers
		m_coll.clear();
		return S_OK;
	}
};

#endif //__MAPCOLLECTION_H_
