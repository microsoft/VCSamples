// beepobj.h : main header file for BEEPER.DLL
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "beepres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Beeper



[emitidl];

#ifndef DISPID_NEWENUM
#define DISPID_NEWENUM -4
#endif

[
	object,
	uuid(976508A0-849D-4BF0-9A3E-7ABC82A9F5A3),
	dual,
	helpstring("IBeeper Interface"),
	pointer_default(unique)
]

__interface IBeeper : IDispatch
{
		[id(1), helpstring("Play the current sound")] HRESULT Beep();

		[propget, id(2), helpstring("Returns number of strings in collection.")] HRESULT Count([out, retval] long* retval);

		[propget, id(0), helpstring("Given an index, returns a string in the collection")] HRESULT Item([in] long Index, [out, retval] BSTR* pbstr);

		[propget, id(DISPID_NEWENUM), restricted] HRESULT _NewEnum([out, retval] IUnknown** retval);
};

LPCOLESTR arr[] = 
{
	OLESTR("Hello"), 
	OLESTR("World"),
	OLESTR("From"), 
	OLESTR("Beeper")
};


[ 
	coclass,
	uuid("91C2292F-ECDF-42BF-BD00-288BC1C185DC"),
	progid("Acme.BeeperAttrib"),
	version("1.0"),
	threading(single),
	support_error_info("IBeeper"),
	default("IBeeper"),
	aggregatable(never)
]
class ATL_NO_VTABLE CBeeper :
	public IBeeper
{
public:
	CBeeper()
	{
		m_nCnt = 0;
		for (int i = 0; i < 4; i++)
			m_var[i] = arr[i];
	}


//	DECLARE_GET_CONTROLLING_UNKNOWN()
// IBeeper
public:
	STDMETHODIMP Beep()
	{
		if (m_nCnt++ == 5)
		{
			m_nCnt = 0;
			return Error(L"Too many beeps");
		}
		MessageBeep(0);
		return S_OK;
	}

	STDMETHODIMP get_Count(long* retval)
	{
		if (retval == NULL)
			return E_POINTER;
		*retval = 4;
		return S_OK;
	}

	STDMETHODIMP get_Item(long Index, BSTR* pbstr)
	{
		if (pbstr == NULL)
			return E_POINTER;
		if (Index > 4)
		{
			*pbstr = NULL;
			return ERROR_INVALID_INDEX;
		}
		*pbstr = SysAllocString(arr[Index-1]);
		return S_OK;
	}

	STDMETHODIMP get__NewEnum(IUnknown** retval)
	{
		if (retval == NULL)
			return E_POINTER;
		*retval = NULL;
		typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT,
			_Copy<VARIANT> > > enumvar;
		HRESULT hRes = S_OK;
		#pragma warning(suppress: 6014) // enumvar is returned through retval.
		enumvar* p = new enumvar;
		if (p == NULL)
			hRes = E_OUTOFMEMORY;
		else
		{
			hRes = p->FinalConstruct();
			if (hRes == S_OK)
			{
				hRes = p->Init(&m_var[0], &m_var[4], NULL, AtlFlagCopy);
				if (hRes == S_OK)
					hRes = p->QueryInterface(IID_IUnknown, (void**)retval);
			}
		}
		if (hRes != S_OK)
			delete p;
		return hRes;
	}
private:
	int m_nCnt;
	CComVariant m_var[4];
};
