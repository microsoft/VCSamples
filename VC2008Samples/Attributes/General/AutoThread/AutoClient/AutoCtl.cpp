// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.
// AutoCtl.cpp : Implementation of CAutoCtl

#include "stdafx.h"
#include "AutoCtl.h"

/////////////////////////////////////////////////////////////////////////////
// CAutoCtl


STDMETHODIMP CAutoCtl::get_Delay(long *pVal)
{
	*pVal = m_Delay;
	return S_OK;
}

STDMETHODIMP CAutoCtl::put_Delay(long newVal)
{
	m_Delay = newVal;
	return S_OK;
}
