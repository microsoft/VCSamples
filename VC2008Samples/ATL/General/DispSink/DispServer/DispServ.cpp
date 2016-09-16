// DispServ.cpp : Implementation of CDispServ
//
// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "stdafx.h"
#include "DispServer.h"
#include "DispServ.h"

/////////////////////////////////////////////////////////////////////////////
// CDispServ


STDMETHODIMP CDispServ::Send(VARIANT data)
{
	Fire_Transfer(data);
	return S_OK;
}

STDMETHODIMP CDispServ::GetClassID(CLSID *pClassID)
{
	if (!pClassID)
		return E_FAIL;

	*pClassID = GetObjectCLSID();

	return S_OK;
}