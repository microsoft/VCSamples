// strcoll.cpp : implementation file
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
#include "strcoll.h"
#include "enumvar.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CStringCollect

IMPLEMENT_DYNCREATE(CStringCollect, CCmdTarget)

CStringCollect::CStringCollect()
{
	EnableAutomation();

	// To keep the application running as long as an OLE automation
	//  object is active, the constructor calls AfxOleLockApp.

	AfxOleLockApp();
}

CStringCollect::~CStringCollect()
{
	// To terminate the application when all objects created with
	//  with OLE automation, the destructor calls AfxOleUnlockApp.

	AfxOleUnlockApp();
}

void CStringCollect::OnFinalRelease()
{
	// When the last reference for an automation object is released
	//  OnFinalRelease is called.  This implementation deletes the
	//  object.  Add additional cleanup required for your object before
	//  deleting it from memory.

	delete this;
}

BEGIN_MESSAGE_MAP(CStringCollect, CCmdTarget)
	//{{AFX_MSG_MAP(CStringCollect)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// {BA0357C0-C377-11cd-9A90-00DD01113F12}
IMPLEMENT_OLECREATE(CStringCollect, "mfc.inproc.strcoll",
	0xba0357c0, 0xc377, 0x11cd, 0x9a, 0x90, 0x0, 0xdd, 0x1, 0x11, 0x3f, 0x12);

BEGIN_DISPATCH_MAP(CStringCollect, CCmdTarget)
	//{{AFX_DISPATCH_MAP(CStringCollect)
	DISP_PROPERTY_EX(CStringCollect, "Count", GetCount, SetNotSupported, VT_I4)
	DISP_FUNCTION(CStringCollect, "Add", Add, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CStringCollect, "Find", Find, VT_I4, VTS_BSTR)
	DISP_FUNCTION(CStringCollect, "Remove", Remove, VT_I4, VTS_VARIANT)
	DISP_FUNCTION(CStringCollect, "RemoveAll", RemoveAll, VT_EMPTY, VTS_NONE)
	DISP_PROPERTY_PARAM(CStringCollect, "Item", GetItem, SetItem, VT_BSTR, VTS_I4)
	//}}AFX_DISPATCH_MAP
	DISP_PROPERTY_EX_ID(CStringCollect, "_NewEnum", DISPID_NEWENUM, GetNewEnum, SetNotSupported, VT_UNKNOWN)
	DISP_DEFVALUE(CStringCollect, "Item")
END_DISPATCH_MAP()

// {0F098950-F9F0-11cd-8C3D-00AA004BB3B7}
static const IID IID_IStringCollect = { 0xf098950, 0xf9f0, 0x11cd,
	{ 0x8c, 0x3d, 0x0, 0xaa, 0x0, 0x4b, 0xb3, 0xb7 } };

// Note: we add support for IID_IStringCollect to support typesafe binding
// from VBA.  This IID must match the GUID that is attached to the
// dispinterface in the .ODL file.

BEGIN_INTERFACE_MAP(CStringCollect, CCmdTarget)
	INTERFACE_PART(CStringCollect, IID_IStringCollect, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CStringCollect message handlers

void CStringCollect::CheckIndex(long nIndex)
{
	if (nIndex <= 0 || nIndex > m_strArray.GetSize())
		AfxThrowOleException(E_INVALIDARG);
}

LPUNKNOWN CStringCollect::GetNewEnum()
{
	#pragma warning (suppress: 6211)
	CEnumVariant* pEnum = new CEnumVariant;
	int nCount = (int)m_strArray.GetSize();
	#pragma warning (suppress: 6211)
	VARIANT* pContents = new VARIANT[nCount];
	int i;

	TRY
	{
		for (i = 0; i < nCount; ++i)
		{
			VariantInit(&pContents[i]);
			pContents[i].bstrVal = m_strArray.ElementAt(i).AllocSysString();
			pContents[i].vt = VT_BSTR;
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

long CStringCollect::GetCount()
{
	return (long)m_strArray.GetSize();
}

BSTR CStringCollect::GetItem(long nIndex)
{
	CheckIndex(nIndex);
	return m_strArray.ElementAt((int)nIndex-1).AllocSysString();
}

void CStringCollect::SetItem(long nIndex, LPCTSTR lpszNewValue)
{
	CheckIndex(nIndex);
	m_strArray.ElementAt((int)nIndex-1) = lpszNewValue;
}

long CStringCollect::Add(LPCTSTR newValue)
{
	m_strArray.Add(newValue);
	return (long)m_strArray.GetSize();
}

long CStringCollect::Find(LPCTSTR findValue)
{
	int nCount = (int)m_strArray.GetSize();
	for (int i = 0; i < nCount; ++i)
	{
		if (m_strArray.ElementAt(i) == findValue)
			return i+1;
	}
	return -1;
}

long CStringCollect::Remove(const VARIANT FAR& removeValue)
{
	int nIndex = -1;

	VARIANT varTemp;
	VariantInit(&varTemp);
	const VARIANT* pvar = &removeValue;
	if (removeValue.vt != VT_BSTR)
	{
		if (VariantChangeType(&varTemp, (VARIANT*)&removeValue, 0, VT_I4) == NOERROR)
			pvar = &varTemp;
		else if (VariantChangeType(&varTemp, (VARIANT*)&removeValue, 0, VT_BSTR) == NOERROR)
			pvar = &varTemp;
		else
			AfxThrowOleException(DISP_E_TYPEMISMATCH);
	}
	if (pvar->vt == VT_BSTR)
		nIndex = (int)Find(CString(pvar->bstrVal));
	else if (pvar->vt == VT_I4)
		nIndex = (int)pvar->lVal;
	VariantClear(&varTemp);

	CheckIndex(nIndex);

	m_strArray.RemoveAt(nIndex);
	return (long)m_strArray.GetSize();
}

void CStringCollect::RemoveAll()
{
	m_strArray.RemoveAll();
}
