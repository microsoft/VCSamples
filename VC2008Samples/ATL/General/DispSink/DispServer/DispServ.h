// DispServ.h : Declaration of the CDispServ
//
// This is a part of the Active Template Library. 
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __DISPSERV_H_
#define __DISPSERV_H_

#include "resource.h"       // main symbols
#include "DispServerCP.h"

/////////////////////////////////////////////////////////////////////////////
// CDispServ
class ATL_NO_VTABLE CDispServ : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDispServ, &CLSID_DispServ>,
	public IDispatchImpl<IDispServ, &IID_IDispServ, &LIBID_DISPSERVERLib, /*wMajor =*/ 1, /*wMinor =*/ 0>,
	public IConnectionPointContainerImpl<CDispServ>,
	public CProxy_IDispServEvents< CDispServ >,
	public IPersist
{
public:
	CDispServ()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DISPSERV)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CDispServ)
	COM_INTERFACE_ENTRY(IDispServ)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IPersist)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CDispServ)
CONNECTION_POINT_ENTRY(DIID__IDispServEvents)
END_CONNECTION_POINT_MAP()


//This macro means all clients will connect to the same 
//server.
DECLARE_CLASSFACTORY_SINGLETON(CDispServ);



// IDispServ
public:
	STDMETHOD(Send)(VARIANT data);
	STDMETHOD(GetClassID)(CLSID *pClassID);
};

OBJECT_ENTRY_AUTO(__uuidof(DispServ), CDispServ)

#endif //__DISPSERV_H_