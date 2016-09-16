// AutoServ.h : Declaration of the CAutoServ
//
// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __AUTOSERV_H_
#define __AUTOSERV_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutoServ
class ATL_NO_VTABLE CAutoServ : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CAutoServ, &CLSID_AutoServ>,
	public IDispatchImpl<IAutoServ, &IID_IAutoServ, &LIBID_AUTOSERVERLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CAutoServ()
	{
	}

	
//Must use this macro so the auto thread class
//factory is used.
//To remove the CAtlAutoThreadModule properties comment out the next line
//and remove "public CAtlAutoThreadModule" from CAutoSvrModule class definition
DECLARE_CLASSFACTORY_AUTO_THREAD()

DECLARE_REGISTRY_RESOURCEID(IDR_AUTOSERV)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CAutoServ)
	COM_INTERFACE_ENTRY(IAutoServ)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IAutoServ
public:
	STDMETHOD(Sleep)(long delay);
};

OBJECT_ENTRY_AUTO(__uuidof(AutoServ), CAutoServ)

#endif //__AUTOSERV_H_
