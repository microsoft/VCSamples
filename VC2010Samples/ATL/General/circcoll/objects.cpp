// objects.cpp : collection implementation
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "precircc.h"
#include "CircColl.h"
#include "objects.h"

/////////////////////////////////////////////////////////////////////////////
// class CMyCircle


CMyCircle::CMyCircle()
{
	m_xCenter = 0;
	m_yCenter = 0;
	m_Radius = 0;
}

// IMyCircle Implementation

STDMETHODIMP CMyCircle::get_XCenter(double* pXCenter)
{
	if (pXCenter == NULL)
		return E_POINTER;
	*pXCenter = m_xCenter;
	return S_OK;
}

STDMETHODIMP CMyCircle::put_XCenter(double xCenter)
{
	m_xCenter = xCenter;
	return S_OK;
}

STDMETHODIMP CMyCircle::get_YCenter(double* pYCenter)
{
	if (pYCenter == NULL)
		return E_POINTER;
	*pYCenter = m_yCenter;
	return S_OK;
}

STDMETHODIMP CMyCircle::put_YCenter(double yCenter)
{
	m_yCenter = yCenter;
	return S_OK;
}

STDMETHODIMP CMyCircle::get_Radius(double* pRadius)
{
	if (pRadius == NULL)
		return E_POINTER;
	*pRadius = m_Radius;
	return S_OK;
}


STDMETHODIMP CMyCircle::put_Radius(double Radius)
{
	m_Radius = Radius;
	return S_OK;
}

STDMETHODIMP CMyCircle::put_Label(BSTR bstrLabel)
{
	USES_CONVERSION;
	m_bstrLabel = bstrLabel;
	return S_OK;
}

STDMETHODIMP CMyCircle::get_Label(BSTR* pbstrLabel)
{
	USES_CONVERSION;
	if (pbstrLabel == NULL)
		return E_POINTER;
	*pbstrLabel = m_bstrLabel.Copy();
	return S_OK;
}

///////////////////////////////////////////////////////////////////////////
// class CMyCircleCollectionCreator

STDMETHODIMP CMyCircleCollectionCreator::GetCircles(short n, VARIANT* retval)
{
	VariantInit(retval);

#pragma warning(suppress: 6014)
	CComObject<CMyCircleCollection>* p = new CComObject<CMyCircleCollection>;
	p->Init(n);
	IDispatch* pDisp;
	p->QueryInterface(IID_IDispatch, (void**)&pDisp);
	ATLASSERT(pDisp);
	retval->vt = VT_DISPATCH;
	retval->pdispVal = pDisp;
	return S_OK;
}

///////////////////////////////////////////////////////////////////////////
// class CMyCircleCollection

STDMETHODIMP CMyCircleCollection::get_Count(long* retval)
{
	if (retval == NULL)
		return E_POINTER;
	*retval = m_nSize;
	return S_OK;
}

STDMETHODIMP CMyCircleCollection::get_Item(long Index, VARIANT* retval)
{
	if (retval == NULL)
		return E_POINTER;
	VariantInit(retval);
	retval->vt = VT_UNKNOWN;
	retval->punkVal = NULL;
	// use 1-based index, VB like
	if ((Index < 1) || (Index > m_nSize))
		return E_INVALIDARG;
	return VariantCopy(retval, &m_VarVect[Index-1]);
}

STDMETHODIMP CMyCircleCollection::get__NewEnum(IUnknown** retval)
{
	if (retval == NULL)
		return E_POINTER;
	*retval = NULL;
	typedef CComObject<CComEnum<IEnumVARIANT, &IID_IEnumVARIANT, VARIANT, _Copy<VARIANT> > > enumvar;
#pragma warning(suppress: 6014)
	enumvar* p = new enumvar;
	ATLASSERT(p);
	HRESULT hRes = p->Init(&m_VarVect[0], &m_VarVect[m_nSize], NULL, AtlFlagCopy);
	if (SUCCEEDED(hRes))
		hRes = p->QueryInterface(IID_IEnumVARIANT, (void**)retval);
	return hRes;
}


void CMyCircleCollection::Init(short n)
{
	if (m_VarVect != NULL)
		delete [] m_VarVect;
	m_nSize = n;
	m_VarVect = new CComVariant[n];
	for (int i=0; i<n; i++)
	{
		// create an object
		HRESULT hRes;
		CComObject<CMyCircle>* pCircle;
		
		hRes = CComObject<CMyCircle>::CreateInstance(&pCircle);
		ATLASSERT(SUCCEEDED(hRes));

		// set arbitrary values
		pCircle->m_Radius = 10*(i+1) + 50;
		pCircle->m_xCenter = pCircle->m_yCenter = 2*pCircle->m_Radius;
		TCHAR szBuf[100];
		_stprintf_s(szBuf,100,_T("Circle # %d"),i+1);  // start from 1, VB like
		pCircle->m_bstrLabel = szBuf;

		// get IDispatch pointer
		LPDISPATCH lpDisp = NULL;
		pCircle->QueryInterface(IID_IDispatch, (void**)&lpDisp);
		ATLASSERT(lpDisp);

		// create a variant and add it to the collection
		CComVariant& var = m_VarVect[i];
		var.vt = VT_DISPATCH;
		var.pdispVal = lpDisp;
	}
}
