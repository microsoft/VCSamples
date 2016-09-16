// Machine generated IDispatch driver class(es) created with ClassWizard
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CVariantMap wrapper class

class CVariantMap : public COleDispatchDriver
{
// Attributes
public:
	CString GetStr1();
	void SetStr1(LPCTSTR);
	CString GetStr2();
	void SetStr2(LPCTSTR);
	long GetI1();
	void SetI1(long);
	long GetI2();
	void SetI2(long);
	long GetCount();
	void SetCount(long);

// Operations
public:
	void SetAt(const VARIANT& from, const VARIANT& to);
	void RemoveAll();
	void RemoveKey(const VARIANT& key);
	BOOL IsEmpty();
	VARIANT GetItem(const VARIANT& from);
	LPUNKNOWN Get_NewEnum();
};

/////////////////////////////////////////////////////////////////////////////
// CStringCollect wrapper class

class CStringCollect : public COleDispatchDriver
{
// Attributes
public:
	long GetCount();
	void SetCount(long);

// Operations
public:
	CString GetItem(long nIndex);
	void SetItem(long nIndex, LPCTSTR lpszNewValue);
	long Add(LPCTSTR newValue);
	long Find(LPCTSTR findValue);
	long Remove(const VARIANT& removeValue);
	void RemoveAll();
	LPUNKNOWN Get_NewEnum();
};

/////////////////////////////////////////////////////////////////////////////
// CVariantAssoc wrapper class

class CVariantAssoc : public COleDispatchDriver
{
// Attributes
public:
	VARIANT GetKey();
	void SetKey(const VARIANT&);
	VARIANT GetValue();
	void SetValue(const VARIANT&);

// Operations
public:
};
