// LabObj.h : Declaration of the CLabrador
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#include "Resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Labrador

class CLabrador :
	public IMammal,
	public IDog,
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CLabrador, &CLSID_Labrador>
{
public:
	CLabrador();

BEGIN_COM_MAP(CLabrador)
	COM_INTERFACE_ENTRY(IMammal)
	COM_INTERFACE_ENTRY(IDog)
END_COM_MAP()

DECLARE_NOT_AGGREGATABLE(CLabrador)
DECLARE_REGISTRY_RESOURCEID(IDR_LABRADOR)

// IDog
	STDMETHOD(GetPetName)(MY_BSTR pStr);
	STDMETHOD(SetPetName)(MY_BSTR pStr);
	STDMETHOD(IsBarking)(BOOL* pBool);

// IMammal
	STDMETHOD(GetSpeciesName)(MY_BSTR pStr);
	STDMETHOD(IsAlive)(BOOL* pBool);

private:
	MY_BSTR m_szPetName;
	MY_BSTR m_szSpeciesName;
	BOOL    m_bIsBarking;
	BOOL    m_bIsAlive;
};
