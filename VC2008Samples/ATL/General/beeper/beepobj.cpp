// beepobj.cpp : Implementation of CBeeperApp and DLL registration.
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "prebeep.h"
#include "beeper.h"
#include "beepobj.h"


LPCOLESTR arr[] = {OLESTR("Hello"), OLESTR("World"),
	OLESTR("From"), OLESTR("Beeper")};

/////////////////////////////////////////////////////////////////////////////
//

CBeeper::CBeeper()
{
	m_nCnt = 0;
	for (int i = 0; i < 4; i++)
		m_var[i] = arr[i];
}

STDMETHODIMP CBeeper::Beep()
{
	if (m_nCnt++ == 5)
	{
		m_nCnt = 0;
		return Error(L"Too many beeps");
	}
	MessageBeep(0);
	return S_OK;
}

STDMETHODIMP CBeeper::get_Count(long* retval)
{
	if (retval == NULL)
		return E_POINTER;
	*retval = 4;
	return S_OK;
}

STDMETHODIMP CBeeper::get_Item(long Index, BSTR* pbstr)
{
	if (pbstr == NULL)
		return E_POINTER;
	if (Index > 4)
		*pbstr = NULL;
	else
		*pbstr = SysAllocString(arr[Index-1]);
	return S_OK;
}

STDMETHODIMP CBeeper::get__NewEnum(IUnknown** retval)
{
	if (retval == NULL)
		return E_POINTER;
	*retval = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT,
		_Copy<VARIANT> > > enumvar;
	HRESULT hRes = S_OK;
#pragma warning(suppress:6014)
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
