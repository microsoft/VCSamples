// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// StringCollection.h : Declaration of the CStringCollection

#ifndef __STRINGCOLLECTION_H_
#define __STRINGCOLLECTION_H_

#include "resource.h"       // main symbols

#pragma warning (disable : 4530)

#include <vector>
#include <string>

#include "Reuse\VCUE_CopyString.h"

namespace StringColl
{
	// Store our data in a vector of std::strings
	typedef std::vector< std::string >				ContainerType;

	// Use IEnumVARIANT as the enumerator for VB compatibility
	typedef VARIANT									EnumeratorExposedType;
	typedef IEnumVARIANT							EnumeratorInterface;

	// Our collection interface exposes the data as BSTRs
	typedef BSTR									CollectionExposedType;
	typedef IWords									CollectionInterface;

	// Typedef the copy classes using existing typedefs
	typedef VCUE::GenericCopy<EnumeratorExposedType, ContainerType::value_type>		EnumeratorCopyType;
	typedef VCUE::GenericCopy<CollectionExposedType, ContainerType::value_type>		CollectionCopyType;

	// Now we have all the information we need to fill in the template arguments on the implementation classes
	typedef CComEnumOnSTL< EnumeratorInterface, &__uuidof(EnumeratorInterface), EnumeratorExposedType,
							EnumeratorCopyType, ContainerType > EnumeratorType;

	typedef ICollectionOnSTLImpl< CollectionInterface, ContainerType, CollectionExposedType,
							CollectionCopyType, EnumeratorType > CollectionType;

}; // namespace StringColl;

/////////////////////////////////////////////////////////////////////////////
// CWords
class ATL_NO_VTABLE CWords : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CWords, &CLSID_Words>,
	public IDispatchImpl<StringColl::CollectionType, &IID_IWords, &LIBID_ATLCOLLECTIONSLib>
{
public:
	CWords()
	{
		m_coll.push_back("this");
		m_coll.push_back("is");
		m_coll.push_back("a");
		m_coll.push_back("test");
	}

DECLARE_REGISTRY_RESOURCEID(IDR_STRINGCOLLECTION)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CWords)
	COM_INTERFACE_ENTRY(IWords)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IWords
public:
};

#endif //__STRINGCOLLECTION_H_
