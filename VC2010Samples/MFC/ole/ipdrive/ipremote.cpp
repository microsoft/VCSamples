// Machine generated IDispatch wrapper class(es) created with ClassWizard
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
#include "ipremote.h"

/////////////////////////////////////////////////////////////////////////////
// CVariantMap properties

CString CVariantMap::GetStr1()
{
	CString result;
	GetProperty(0x1, VT_BSTR, (void*)&result);
	return result;
}

void CVariantMap::SetStr1(LPCTSTR propVal)
{
	SetProperty(0x1, VT_BSTR, propVal);
}

CString CVariantMap::GetStr2()
{
	CString result;
	GetProperty(0x3, VT_BSTR, (void*)&result);
	return result;
}

void CVariantMap::SetStr2(LPCTSTR propVal)
{
	SetProperty(0x3, VT_BSTR, propVal);
}

long CVariantMap::GetI1()
{
	long result;
	GetProperty(0x2, VT_I4, (void*)&result);
	return result;
}

void CVariantMap::SetI1(long propVal)
{
	SetProperty(0x2, VT_I4, propVal);
}

long CVariantMap::GetI2()
{
	long result;
	GetProperty(0x4, VT_I4, (void*)&result);
	return result;
}

void CVariantMap::SetI2(long propVal)
{
	SetProperty(0x4, VT_I4, propVal);
}

long CVariantMap::GetCount()
{
	long result;
	GetProperty(0x5, VT_I4, (void*)&result);
	return result;
}

void CVariantMap::SetCount(long propVal)
{
	SetProperty(0x5, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CVariantMap operations

void CVariantMap::SetAt(const VARIANT& from, const VARIANT& to)
{
	static BYTE BASED_CODE parms[] =
		VTS_VARIANT VTS_VARIANT;
	InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &from, &to);
}

void CVariantMap::RemoveAll()
{
	InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

void CVariantMap::RemoveKey(const VARIANT& key)
{
	static BYTE BASED_CODE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms,
		 &key);
}

BOOL CVariantMap::IsEmpty()
{
	BOOL result;
	InvokeHelper(0x9, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
	return result;
}

VARIANT CVariantMap::GetItem(const VARIANT& from)
{
	VARIANT result;
	static BYTE BASED_CODE parms[] =
		VTS_VARIANT;
	InvokeHelper(0xa, DISPATCH_PROPERTYGET, VT_VARIANT, (void*)&result, parms,
		&from);
	return result;
}

LPUNKNOWN CVariantMap::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

/////////////////////////////////////////////////////////////////////////////
// CStringCollect properties

long CStringCollect::GetCount()
{
	long result;
	GetProperty(0x1, VT_I4, (void*)&result);
	return result;
}

void CStringCollect::SetCount(long propVal)
{
	SetProperty(0x1, VT_I4, propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CStringCollect operations

CString CStringCollect::GetItem(long nIndex)
{
	CString result;
	static BYTE BASED_CODE parms[] =
		VTS_I4;
	InvokeHelper(0x6, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, parms,
		nIndex);
	return result;
}

void CStringCollect::SetItem(long nIndex, LPCTSTR lpszNewValue)
{
	static BYTE BASED_CODE parms[] =
		VTS_I4 VTS_BSTR;
	InvokeHelper(0x6, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nIndex, lpszNewValue);
}

long CStringCollect::Add(LPCTSTR newValue)
{
	long result;
	static BYTE BASED_CODE parms[] =
		VTS_BSTR;
	InvokeHelper(0x2, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		newValue);
	return result;
}

long CStringCollect::Find(LPCTSTR findValue)
{
	long result;
	static BYTE BASED_CODE parms[] =
		VTS_BSTR;
	InvokeHelper(0x3, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		findValue);
	return result;
}

long CStringCollect::Remove(const VARIANT& removeValue)
{
	long result;
	static BYTE BASED_CODE parms[] =
		VTS_VARIANT;
	InvokeHelper(0x4, DISPATCH_METHOD, VT_I4, (void*)&result, parms,
		&removeValue);
	return result;
}

void CStringCollect::RemoveAll()
{
	InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

LPUNKNOWN CStringCollect::Get_NewEnum()
{
	LPUNKNOWN result;
	InvokeHelper(0xfffffffc, DISPATCH_PROPERTYGET, VT_UNKNOWN, (void*)&result, NULL);
	return result;
}

/////////////////////////////////////////////////////////////////////////////
// CVariantAssoc properties

VARIANT CVariantAssoc::GetKey()
{
	VARIANT result;
	GetProperty(0x1, VT_VARIANT, (void*)&result);
	return result;
}

void CVariantAssoc::SetKey(const VARIANT& propVal)
{
	SetProperty(0x1, VT_VARIANT, &propVal);
}

VARIANT CVariantAssoc::GetValue()
{
	VARIANT result;
	GetProperty(0x2, VT_VARIANT, (void*)&result);
	return result;
}

void CVariantAssoc::SetValue(const VARIANT& propVal)
{
	SetProperty(0x2, VT_VARIANT, &propVal);
}

/////////////////////////////////////////////////////////////////////////////
// CVariantAssoc operations
