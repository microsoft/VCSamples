// varmap.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "inproc.h"
#include "enumvar.h"
#include "varassoc.h"
#include "varmap.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CVariantMap

IMPLEMENT_DYNCREATE(CVariantMap, CCmdTarget)

CVariantMap::CVariantMap()
{
	EnableAutomation();

	// To keep the application running as long as an OLE automation
	//  object is active, the constructor calls AfxOleLockApp.

	AfxOleLockApp();
}

CVariantMap::~CVariantMap()
{
	// To terminate the application when all objects created with
	//  with OLE automation, the destructor calls AfxOleUnlockApp.

	AfxOleUnlockApp();
}

void CVariantMap::OnFinalRelease()
{
	// When the last reference for an automation object is released
	//  OnFinalRelease is called.  This implementation deletes the
	//  object.  Add additional cleanup required for your object before
	//  deleting it from memory.

	delete this;
}

BEGIN_MESSAGE_MAP(CVariantMap, CCmdTarget)
	//{{AFX_MSG_MAP(CVariantMap)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// {7ACE7860-9A1C-11cd-9A90-00DD01113F12}
IMPLEMENT_OLECREATE(CVariantMap, "mfc.inproc.varmap",
	0x7ace7860, 0x9a1c, 0x11cd, 0x9a, 0x90, 0x0, 0xdd, 0x1, 0x11, 0x3f, 0x12);

BEGIN_DISPATCH_MAP(CVariantMap, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CVariantMap)
	DISP_PROPERTY(CVariantMap, "str1", m_str1, VT_BSTR)
	DISP_PROPERTY(CVariantMap, "i1", m_i1, VT_I4)
	DISP_PROPERTY_EX(CVariantMap, "str2", GetStr2, SetStr2, VT_BSTR)
	DISP_PROPERTY_EX(CVariantMap, "i2", GetI2, SetI2, VT_I4)
	DISP_PROPERTY_EX(CVariantMap, "Count", GetCount, SetNotSupported, VT_I4)
	DISP_FUNCTION(CVariantMap, "SetAt", SetAt, VT_EMPTY, VTS_VARIANT VTS_VARIANT)
	DISP_FUNCTION(CVariantMap, "RemoveAll", RemoveAll, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION(CVariantMap, "RemoveKey", RemoveKey, VT_EMPTY, VTS_VARIANT)
	DISP_FUNCTION(CVariantMap, "IsEmpty", IsEmpty, VT_BOOL, VTS_NONE)
	DISP_PROPERTY_PARAM(CVariantMap, "Item", GetItem, SetNotSupported, VT_VARIANT, VTS_VARIANT)
	//}}AFX_DISPATCH_MAP
	DISP_PROPERTY_EX_ID(CVariantMap, "_NewEnum", DISPID_NEWENUM, GetNewEnum, SetNotSupported, VT_UNKNOWN)
	DISP_DEFVALUE(CVariantMap, "Item")
END_DISPATCH_MAP()

// {747205C0-F9F0-11cd-8C3D-00AA004BB3B7}
static const IID IID_IVariantMap = { 0x747205c0, 0xf9f0, 0x11cd,
	{ 0x8c, 0x3d, 0x0, 0xaa, 0x0, 0x4b, 0xb3, 0xb7 } };

// Note: we add support for IID_IVariantMap to support typesafe binding
// from VBA.  This IID must match the GUID that is attached to the
// dispinterface in the .ODL file.

BEGIN_INTERFACE_MAP(CVariantMap, CCmdTarget)
	INTERFACE_PART(CVariantMap, IID_IVariantMap, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVariantMap message handlers

LPUNKNOWN CVariantMap::GetNewEnum()
{
	#pragma warning (suppress: 6211)
	CEnumVariant* pEnum = new CEnumVariant;
	int nCount = (int)m_map.GetCount();
	#pragma warning (suppress: 6211)
	VARIANT* pContents = new VARIANT[nCount];
	unsigned int i = 0;

	TRY
	{
		POSITION pos = m_map.GetStartPosition();
		while (pos != NULL)
		{
			ASSERT(i < (unsigned int)nCount);

			// get next value from the map and create a CVariantAssoc from it
			#pragma warning (suppress: 6014)
			CVariantAssoc* pAssoc = new CVariantAssoc;
			m_map.GetNextAssoc(pos, pAssoc->m_varKey, pAssoc->m_varValue);

			// stuff it into a variant
			pContents[i].pdispVal = pAssoc->GetIDispatch(FALSE);
			pContents[i].vt = VT_DISPATCH;
			++i;
		}
	}
	CATCH_ALL(e)
	{
		while (--i >= 0)
			VariantClear(&pContents[i]);
		delete [] pContents;

		THROW_LAST();
	}
	END_CATCH_ALL
	pEnum->SetContents(pContents, nCount);

	return pEnum->GetInterface(&IID_IUnknown);
}

void CVariantMap::SetAt(const VARIANT FAR& from, const VARIANT FAR& to)
{
	m_map.SetAt(from, to);
}

VARIANT CVariantMap::GetItem(const VARIANT FAR& from)
{
	COleVariant varResult;
	m_map.Lookup(from, varResult);
	return varResult.Detach();
}

void CVariantMap::RemoveAll()
{
	m_map.RemoveAll();
}

void CVariantMap::RemoveKey(const VARIANT FAR& key)
{
	m_map.RemoveKey(key);
}

long CVariantMap::GetCount()
{
	return (long)m_map.GetCount();
}

BOOL CVariantMap::IsEmpty()
{
	return m_map.IsEmpty();
}

BSTR CVariantMap::GetStr2()
{
	return m_str2.AllocSysString();
}

void CVariantMap::SetStr2(LPCTSTR lpszNewValue)
{
	m_str2 = lpszNewValue;
}

long CVariantMap::GetI2()
{
	return m_i2;
}

void CVariantMap::SetI2(long nNewValue)
{
	m_i2 = nNewValue;
}
