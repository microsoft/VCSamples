// ArrayManager.cpp : Implementation of CArrayManager

// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "AtlSafeArray.h"
#include "ArrayManager.h"


// CArrayManager


STDMETHODIMP CArrayManager::GetArray(VARIANT* pvar)
{
	CComVariant var(m_sa);
	var.Detach(pvar);

	return S_OK;
}

STDMETHODIMP CArrayManager::Add(BSTR bstr)
{
	m_sa.Add(CComVariant(bstr));

	return S_OK;
}

STDMETHODIMP CArrayManager::Remove(ULONG nIndex)
{
	// if removing last item, just resize
	if (nIndex == m_sa.GetCount()-1)
		m_sa.Resize(m_sa.GetCount()-1);
	else
	{
		CComSafeArray<VARIANT> saTemp;
		// copy all items except the one to be removed
		for (ULONG nCntr = 0; nCntr < m_sa.GetCount(); nCntr++)
		{
			if (nCntr != nIndex)
				// call CComSafeArray<>::operator[]
				saTemp.Add(m_sa[static_cast<LONG>(nCntr)]);
		}
		m_sa = saTemp;
	}

	return S_OK;
}

STDMETHODIMP CArrayManager::Change(ULONG nIndex, BSTR bstr)
{
	m_sa.SetAt(nIndex, CComVariant(bstr));

	return S_OK;
}
