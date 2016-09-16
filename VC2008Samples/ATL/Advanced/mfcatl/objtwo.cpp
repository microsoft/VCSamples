// ObjTwo.cpp : implementation file
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

/////////////////////////////////////////////////////////////////////////////
// CObjectTwo methods

#include "premfcat.h"
#include "MfcAtl.h"
#include "ObjTwo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

STDMETHODIMP CObjectTwo::get_SayHello(BSTR* bstr)
{
	*bstr = SysAllocString(OLESTR("Hello from Object Two!"));
	return S_OK;
}
