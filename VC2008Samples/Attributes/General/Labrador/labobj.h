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
#ifndef _LABOBJ_H_
#define _LABOBJ_H_

#include "labres.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// Beeper

//[emitidl];

#define MAX_MY_BSTR_LEN 32
typedef [string] WCHAR MY_BSTR[MAX_MY_BSTR_LEN];
/////////////////////////////////////////////////////////////////////////////
// Iserviceobj
[
		object,
		uuid(8CC00B42-2860-4D28-88D9-DD3A6F92896E),
		helpstring("IMammal Interface")
]
__interface IMammal 
{
	[helpstring("method GetSpeciesName")]HRESULT GetSpeciesName([out, string] MY_BSTR p);
	[helpstring("method IsAlive")]HRESULT IsAlive([out] BOOL* pBool);
};

[
		object,
		uuid(B9688DC3-9B57-4C37-A7D7-078BECD52FA6),
		helpstring("IDog Interface")
]
__interface IDog 
{
	[helpstring("method GetPetName")]HRESULT GetPetName([out, string] MY_BSTR p);
	[helpstring("method SetPetName")]HRESULT SetPetName([in, string] MY_BSTR p);
	[helpstring("method IsBarking")]HRESULT IsBarking([out] BOOL* pBool);
};


/////////////////////////////////////////////////////////////////////////////
// CLabrador
[
	coclass,
	threading(apartment),
	progid("LABRADOR.Labrador.1"),
	vi_progid("LABRADOR.Labrador"),
	aggregatable(never),
	version(1.0),
	uuid("CE8E837C-7A09-4C98-82D3-844D9BBF4AAD"),
	default("IMammal")
	
]
class CLabrador :
	public IMammal,
	public IDog
{
public:
	CLabrador();

// IDog
	STDMETHOD(GetPetName)(MY_BSTR pStr);
	STDMETHOD(SetPetName)(MY_BSTR pStr);
	STDMETHOD(IsBarking)(BOOL* pBool);

// IMammal
	STDMETHOD(GetSpeciesName)(MY_BSTR pStr);
	STDMETHOD(IsAlive)(BOOL* pBool);

private:
	WCHAR   m_szPetName[32];
	WCHAR   m_szSpeciesName[32];
	BOOL    m_bIsBarking;
	BOOL    m_bIsAlive;
};

#endif
