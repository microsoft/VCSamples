// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

// VCUE_Copy.h
//
// This file contains ATL-style copy policy classes
// ATL uses copy policy classes in its enumerator and collection interface implementations
//
//////////////////////////////////////////////////////////////////////

#if !defined(_GENERICCOPY_H___36A49827_B15B_11D2_BA63_00C04F8EC847___INCLUDED_)
#define _GENERICCOPY_H___36A49827_B15B_11D2_BA63_00C04F8EC847___INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#include <AtlCom.h>

namespace VCUE
{
	template <class DestinationType, class SourceType = DestinationType>
	class GenericCopy
	{
	public :
		typedef DestinationType	destination_type;
		typedef SourceType		source_type;

		static void init(destination_type* p)
		{
			_Copy<destination_type>::init(p);
		}
		static void destroy(destination_type* p)
		{
			_Copy<destination_type>::destroy(p);
		}
		static HRESULT copy(destination_type* pTo, const source_type* pFrom)
		{
			return _Copy<destination_type>::copy(pTo, const_cast<source_type*>(pFrom));
		}

	}; // class GenericCopy

	template <>
	class GenericCopy<BSTR>
	{
	public :
		typedef BSTR	destination_type;
		typedef BSTR	source_type;

		static void init(destination_type* p)
		{
			*p = NULL;
		}
		static void destroy(destination_type* p)
		{
			SysFreeString(*p);
			*p = NULL;
		}
		static HRESULT copy(destination_type* pTo, const source_type* pFrom)
		{
			*pTo = SysAllocStringByteLen(reinterpret_cast<const char*>(*pFrom), SysStringByteLen(*pFrom));
			if (*pTo)
				return S_OK;
			else
				return E_OUTOFMEMORY;
		}
	
	}; // class GenericCopy<BSTR>

	template <>
	class GenericCopy<VARIANT, BSTR>
	{
	public :
		typedef VARIANT	destination_type;
		typedef BSTR	source_type;

		static void init(destination_type* p)
		{
			GenericCopy<destination_type>::init(p);
		}
		static void destroy(destination_type* p)
		{
			GenericCopy<destination_type>::destroy(p);
		}
		static HRESULT copy(destination_type* pTo, const source_type* pFrom)
		{
			return CComVariant(*pFrom).Detach(pTo);
		}

	}; // class GenericCopy<VARIANT, BSTR>

	template <>
	class GenericCopy<BSTR, VARIANT>
	{
	public :
		typedef BSTR	destination_type;
		typedef VARIANT	source_type;

		static void init(destination_type* p)
		{
			GenericCopy<destination_type>::init(p);
		}
		static void destroy(destination_type* p)
		{
			GenericCopy<destination_type>::destroy(p);
		}
		static HRESULT copy(destination_type* pTo, const source_type* pFrom)
		{
			VARIANT var = {0};
			HRESULT hr = VariantChangeType(&var, const_cast<VARIANT*>(pFrom), 0, VT_BSTR);
			if (FAILED(hr))
				return hr;

			*pTo = var.bstrVal;
			return S_OK;
			// We deliberately do not free the variant.
		}

	}; // class GenericCopy<BSTR, VARIANT>

#if  _MSC_VER >= 1700
	template <class MapType, class DestinationType = typename MapType::mapped_type>
#else
	template <class MapType, class DestinationType = MapType::referent_type>
#endif
	class MapCopy
	{
	public :
		typedef DestinationType			destination_type;
		typedef typename MapType::value_type		source_type;
		
		typedef MapType					map_type;
#if  _MSC_VER >= 1700
		typedef typename MapType::mapped_type	pseudosource_type;
#else
		typedef typename MapType::referent_type	pseudosource_type;
#endif

		static void init(destination_type* p)
		{
			GenericCopy<destination_type, pseudosource_type>::init(p);
		}
		static void destroy(destination_type* p)
		{
			GenericCopy<destination_type, pseudosource_type>::destroy(p);
		}
		static HRESULT copy(destination_type* pTo, const source_type* pFrom)
		{
			return GenericCopy<destination_type, pseudosource_type>::copy(pTo, &(pFrom->second));
		}

	}; // class MapCopy

}; // namespace VCUE

#endif // !defined(_GENERICCOPY_H___36A49827_B15B_11D2_BA63_00C04F8EC847___INCLUDED_)
