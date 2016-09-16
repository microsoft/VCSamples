// enumvar.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "inproc.h"
#include "enumvar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CEnumVariant

IMPLEMENT_DYNCREATE(CEnumVariant, CCmdTarget)

CEnumVariant::CEnumVariant()
{
	m_nIndex = 0;
	m_nCount = 0;
	m_pContents = NULL;

	m_pClonedFrom = NULL;

	// To keep the application running as long as an OLE automation
	//  object is active, the constructor calls AfxOleLockApp.

	AfxOleLockApp();
}

CEnumVariant::~CEnumVariant()
{
	if (m_pClonedFrom != NULL)
	{
		m_pClonedFrom->ExternalRelease();
	}
	else
	{
		for (int i = 0; i < m_nCount; ++i)
			VariantClear(&m_pContents[i]);
		delete[] m_pContents;
	}

	// To terminate the application when all objects created with
	//  with OLE automation, the destructor calls AfxOleUnlockApp.

	AfxOleUnlockApp();
}

void CEnumVariant::OnFinalRelease()
{
	// When the last reference for an automation object is released
	//  OnFinalRelease is called.  This implementation deletes the
	//  object.  Add additional cleanup required for your object before
	//  deleting it from memory.

	delete this;
}

void CEnumVariant::SetContents(VARIANT* pContents, int nCount, int nIndex)
{
	ASSERT(nIndex < nCount);
	ASSERT(nCount == 0 || pContents != NULL);
	ASSERT(pContents == NULL ||
		AfxIsValidAddress(pContents, sizeof(VARIANT)*nCount, FALSE));

	m_nCount = nCount;
	m_pContents = pContents;
	m_nIndex = nIndex;
}

BEGIN_MESSAGE_MAP(CEnumVariant, CCmdTarget)
	//{{AFX_MSG_MAP(CEnumVariant)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CEnumVariant interfaces

static void CopyVariantArray(VARIANT* pDest, VARIANT* pSrc, int nCount)
{
	int i;
	for (i = 0; i < nCount; ++i)
		VariantInit(&pDest[i]);
	for (i = 0; i < nCount; ++i)
	{
		SCODE sc = GetScode(VariantCopy(&pDest[i], &pSrc[i]));
		if (sc != NOERROR)
		{
			while (--i >= 0)
				VariantClear(&pDest[i]);
			AfxThrowMemoryException();
		}
	}
}

BEGIN_INTERFACE_MAP(CEnumVariant, CCmdTarget)
	INTERFACE_PART(CEnumVariant, IID_IEnumVARIANT, EnumVARIANT)
END_INTERFACE_MAP()

STDMETHODIMP_(ULONG) CEnumVariant::XEnumVARIANT::AddRef()
{
	METHOD_PROLOGUE(CEnumVariant, EnumVARIANT)
	return pThis->ExternalAddRef();
}

STDMETHODIMP_(ULONG) CEnumVariant::XEnumVARIANT::Release()
{
	METHOD_PROLOGUE(CEnumVariant, EnumVARIANT)
	return pThis->ExternalRelease();
}

STDMETHODIMP CEnumVariant::XEnumVARIANT::QueryInterface(REFIID iid, void** ppvObj)
{
	METHOD_PROLOGUE(CEnumVariant, EnumVARIANT)
	return (HRESULT)pThis->ExternalQueryInterface(&iid, ppvObj) ;
}

STDMETHODIMP CEnumVariant::XEnumVARIANT::Next(ULONG celt, VARIANT* rgvar, ULONG* pceltFetched)
{
	METHOD_PROLOGUE(CEnumVariant, EnumVARIANT)

	ASSERT(celt > 0);
	ASSERT(celt == 1 || pceltFetched != NULL);

	if (pceltFetched != NULL)
		*pceltFetched = 0;

	int nFetched = min(pThis->m_nCount - pThis->m_nIndex, (int)celt);

	TRY
	{
		CopyVariantArray(rgvar, pThis->m_pContents + pThis->m_nIndex, nFetched);
	}
	CATCH_ALL(e)
	{
		return E_OUTOFMEMORY;
	}
	END_CATCH_ALL

	pThis->m_nIndex += nFetched;
	if (pceltFetched != NULL)
		*pceltFetched = nFetched;

	return nFetched == (int)celt ? NOERROR : S_FALSE;
}

STDMETHODIMP CEnumVariant::XEnumVARIANT::Skip(unsigned long celt)
{
	METHOD_PROLOGUE(CEnumVariant, EnumVARIANT)

	int nSkip = (int)celt;
	if (nSkip + pThis->m_nIndex > pThis->m_nCount)
		nSkip = pThis->m_nCount - pThis->m_nIndex;
	pThis->m_nIndex += nSkip;

	return nSkip == (int)celt ? NOERROR : S_FALSE;
}

STDMETHODIMP CEnumVariant::XEnumVARIANT::Reset()
{
	METHOD_PROLOGUE(CEnumVariant, EnumVARIANT)

	pThis->m_nIndex = 0;

	return NOERROR;
}

STDMETHODIMP CEnumVariant::XEnumVARIANT::Clone(IEnumVARIANT** ppenum)
{
	METHOD_PROLOGUE(CEnumVariant, EnumVARIANT)

	CEnumVariant* pClone;
	TRY
	{
		#pragma warning (suppress: 6014)
		pClone = new CEnumVariant;
		pClone->SetContents(pThis->m_pContents, pThis->m_nCount, pThis->m_nIndex);

		pClone->m_pClonedFrom = pThis;
		pThis->ExternalAddRef();
	}
	CATCH_ALL(e)
	{
		return E_OUTOFMEMORY;
	}
	END_CATCH_ALL
	*ppenum = &pClone->m_xEnumVARIANT;

	return NOERROR;
}

/////////////////////////////////////////////////////////////////////////////
// CEnumVariant message handlers
