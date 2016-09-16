// THIS CODE AND INFORMATION IS PROVIDED "AS IS" WITHOUT WARRANTY OF
// ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO
// THE IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
// PARTICULAR PURPOSE.
//
// Copyright (c) Microsoft Corporation. All rights reserved.

#ifndef __SysLCESub_H_
#define __SysLCESub_H_

#include "resource.h"       // main symbols

class CComSpy;
/////////////////////////////////////////////////////////////////////////////
// CSysLCESub
class ATL_NO_VTABLE CSysLCESub : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public ICOMSysLCE
{
private:
	OLECHAR*	EventName( EventEnum e );

protected:
	GUID	m_SubscriptionGuid;
	CComSpy * m_pSpy;

public:
	CSysLCESub()
	{
		CoCreateGuid( &m_SubscriptionGuid );
	}

	void SetSpyObj(CComSpy * pSpy)
	{
		m_pSpy = pSpy;
	}

DECLARE_GET_CONTROLLING_UNKNOWN()

BEGIN_COM_MAP(CSysLCESub)
	COM_INTERFACE_ENTRY(ICOMSysLCE)
END_COM_MAP()

// Virtual Methods
public:
	STDMETHOD(GetEventType)(EventEnum * e) = 0;
	STDMETHOD(GetEventClass)(LPGUID EventClass) = 0;
	STDMETHOD(GetInterface)(IID* iid) = 0;

// ISysLCESub Methods
public:
	STDMETHOD(Install)(BSTR* PropertyName, VARIANT PropertyValue);
	STDMETHOD(Uninstall)();
};

#endif //__SysLCESub_H_
