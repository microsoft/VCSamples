// beepobj.h : main header file for BEEPER.DLL
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Beeper

class CBeeper;

class CBeeper2 :
	public ISupportErrorInfo,
	public CComTearOffObjectBase<CBeeper>
{
public:
	CBeeper2() {}
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid)
	{
		return (InlineIsEqualGUID(IID_IBeeper,riid)) ? S_OK : S_FALSE;
	}

BEGIN_COM_MAP(CBeeper2)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()
};

class CBeeper :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CBeeper, &CLSID_Beeper>,
	public IDispatchImpl<IBeeper, &IID_IBeeper, &LIBID_BeeperLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:

DECLARE_NOT_AGGREGATABLE(CBeeper)
DECLARE_GET_CONTROLLING_UNKNOWN()
#ifdef _WINDLL
	DECLARE_REGISTRY_RESOURCEID(IDR_BEEPER)
#else
	DECLARE_REGISTRY_RESOURCEID(IDR_BEEPEREXE)
#endif

BEGIN_COM_MAP(CBeeper)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IBeeper)
	COM_INTERFACE_ENTRY_TEAR_OFF(IID_ISupportErrorInfo, CBeeper2)
END_COM_MAP()

// IBeeper
public:
	CBeeper();
	STDMETHOD(Beep)();
	STDMETHOD(get_Count)(long* retval);
	STDMETHOD(get_Item)(long Index, BSTR* pbstr);
	STDMETHOD(get__NewEnum)(IUnknown** retval);
private:
	int m_nCnt;
	CComVariant m_var[4];
};

OBJECT_ENTRY_AUTO(CLSID_Beeper, CBeeper)
