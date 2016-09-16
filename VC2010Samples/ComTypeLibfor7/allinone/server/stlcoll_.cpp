// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Visual C++ Language  Reference and related
// electronic documentation provided with Microsoft Visual C++.
// See these sources for detailed information regarding the
// Microsoft Visual C++ product.

#include "stdafx.h"
#include "stlcoll_.h"
#include <algorithm>


// Maps
STDMETHODIMP CStlMapStringToMyObject::get_Map(BSTR str, IMyStruct** obj)
{
	*obj = static_cast<IMyStruct*> (m_map[str]);
	return S_OK;
}

STDMETHODIMP CStlMapStringToMyObject::put_Map(BSTR str, IMyStruct* obj)
{
	m_map[str] = static_cast<CMyObject*> (obj);
	return S_OK;
}

STDMETHODIMP CStlMapStringToMyObject::Lookup(BSTR str, IMyStruct** obj, VARIANT_BOOL* b)
{
	m_mapiter = m_map.find(str);
	if (m_mapiter == m_map.end())
		*b = VARIANT_FALSE;
	else
	{
		*b = VARIANT_TRUE;
		*obj = static_cast<IMyStruct*> (m_mapiter->second);
	}

	return S_OK;
}

STDMETHODIMP CStlMapStringToMyObject::First()
{
	m_mapiter = m_map.begin();
	return S_OK;
}

STDMETHODIMP CStlMapStringToMyObject::Next(BSTR* str, IMyStruct** obj, VARIANT_BOOL* b)
{
	if (m_mapiter == m_map.end())
		*b = VARIANT_FALSE;
	else
	{
		*str = m_mapiter->first.AllocSysString();
		*obj = static_cast<IMyStruct*> (m_mapiter->second);
		++m_mapiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlMapStringToMyObject::get_Remove(BSTR* str)
{
	*str = m_mapiter->first.AllocSysString();
	m_map.erase(m_mapiter);
	return S_OK;
}

STDMETHODIMP CStlMapStringToMyObject::RemoveAll()
{
	m_map.clear();
	return S_OK;
}

STDMETHODIMP CStlMapStringToMyObject::get_Count(UINT* dw)
{
	*dw = (UINT)m_map.size();
	return S_OK;
}


STDMETHODIMP CStlMapDWordToMyStruct::get_Map(DWORD dw, IMyStruct** str)
{
	m_mapiter = m_map.find(dw);
	if (m_mapiter == m_map.end())
	{
		*str = NULL;
		m_map.insert(pair<const DWORD, CMyStruct*>(dw, static_cast<CMyStruct*> (*str)));
	}
	else
		*str = m_mapiter->second;
	return S_OK;
}

STDMETHODIMP CStlMapDWordToMyStruct::put_Map(DWORD dw, IMyStruct* str)
{
	m_mapiter = m_map.find(dw);
	if (m_mapiter == m_map.end())
		m_map.insert(pair<const DWORD, CMyStruct*>(dw, static_cast<CMyStruct*> (str)));
	else
		m_mapiter->second = static_cast<CMyStruct*> (str);
	return S_OK;
}

STDMETHODIMP CStlMapDWordToMyStruct::Lookup(DWORD dw, IMyStruct** str, VARIANT_BOOL* b)
{
	m_mapiter = m_map.find(dw);
	if (m_mapiter == m_map.end())
		*b = VARIANT_FALSE;
	else
	{
		*b = VARIANT_TRUE;
		*str = m_mapiter->second;
	}

	return S_OK;
}

STDMETHODIMP CStlMapDWordToMyStruct::First()
{
	m_mapiter = m_map.begin();
	return S_OK;
}

STDMETHODIMP CStlMapDWordToMyStruct::Next(DWORD* dw, IMyStruct** str, VARIANT_BOOL* b)
{
	if (m_mapiter == m_map.end())
		*b = VARIANT_FALSE;
	else
	{
		*dw = m_mapiter->first;
		*str = m_mapiter->second;
		++m_mapiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlMapDWordToMyStruct::get_Remove(DWORD* dw)
{
	*dw = m_mapiter->first;
	m_map.erase(m_mapiter);
	return S_OK;
}

STDMETHODIMP CStlMapDWordToMyStruct::RemoveAll()
{
	m_map.clear();
	return S_OK;
}

STDMETHODIMP CStlMapDWordToMyStruct::get_Count(UINT* dw)
{
	*dw = (UINT)m_map.size();
	return S_OK;
}


STDMETHODIMP CStlMapStringToString::get_Map(BSTR str1, BSTR* str2)
{
	*str2 = m_map[str1].AllocSysString();
	return S_OK;
}

STDMETHODIMP CStlMapStringToString::put_Map(BSTR str1, BSTR str2)
{
	m_map[str1] = str2;
	return S_OK;
}

STDMETHODIMP CStlMapStringToString::Lookup(BSTR str1, BSTR* str2, VARIANT_BOOL* b)
{
	m_mapiter = m_map.find(str1);
	if (m_mapiter == m_map.end())
		*b = VARIANT_FALSE;
	else
	{
		*b = VARIANT_TRUE;
		*str2 = m_mapiter->second.AllocSysString();
	}

	return S_OK;
}

STDMETHODIMP CStlMapStringToString::First()
{
	m_mapiter = m_map.begin();
	return S_OK;
}

STDMETHODIMP CStlMapStringToString::Next(BSTR* str1, BSTR* str2, VARIANT_BOOL* b)
{
	if (m_mapiter == m_map.end())
		*b = VARIANT_FALSE;
	else
	{
		*str1 = m_mapiter->first.AllocSysString();
		*str2 = m_mapiter->second.AllocSysString();
		++m_mapiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlMapStringToString::get_Remove(BSTR* str)
{
	*str = m_mapiter->first.AllocSysString();
	m_map.erase(m_mapiter);
	return S_OK;
}

STDMETHODIMP CStlMapStringToString::RemoveAll()
{
	m_map.clear();
	return S_OK;
}

STDMETHODIMP CStlMapStringToString::get_Count(UINT* dw)
{
	*dw = (UINT)m_map.size();
	return S_OK;
}


// Lists
STDMETHODIMP CStlStringList::Find(BSTR str, VARIANT_BOOL* b)
{
	m_listiter = find(m_list.begin(), m_list.end(), str);
	if (m_listiter == m_list.end())
		*b = VARIANT_FALSE;
	else
		*b = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CStlStringList::put_SetAt(BSTR str)
{
	*m_listiter = str;
	return S_OK;
}

STDMETHODIMP CStlStringList::put_Add(BSTR str)
{
	m_list.push_back(str);
	return S_OK;
}

STDMETHODIMP CStlStringList::put_InsertBefore(BSTR str)
{
	m_list.insert(m_listiter, str);
	return S_OK;
}

STDMETHODIMP CStlStringList::get_Remove(BSTR* str)
{
	*str = m_listiter->AllocSysString();
	m_list.erase(m_listiter);
	return S_OK;
}

STDMETHODIMP CStlStringList::RemoveAll()
{
	m_list.clear();
	return S_OK;
}

STDMETHODIMP CStlStringList::First()
{
	m_listiter = m_list.begin();
	return S_OK;
}

STDMETHODIMP CStlStringList::Next(BSTR* str, VARIANT_BOOL* b)
{
	if (m_listiter == m_list.end())
		*b = VARIANT_FALSE;
	else
	{
		*str = m_listiter->AllocSysString();
		++m_listiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlStringList::get_Count(UINT* dw)
{
	*dw = (UINT)m_list.size();
	return S_OK;
}


STDMETHODIMP CStlLists::Find(IMyStruct* str, VARIANT_BOOL* b)
{
	m_listiter = find(m_list.begin(), m_list.end(), str);
	if (m_listiter == m_list.end())
		*b = VARIANT_FALSE;
	else
		*b = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CStlLists::put_SetAt(IMyStruct* str)
{
	*m_listiter = static_cast<CMyStruct*> (str);
	return S_OK;
}

STDMETHODIMP CStlLists::put_Add(IMyStruct* str)
{
	m_list.push_back(static_cast<CMyStruct*> (str));
	return S_OK;
}

STDMETHODIMP CStlLists::put_InsertBefore(IMyStruct* str)
{
	m_list.insert(m_listiter, static_cast<CMyStruct*> (str));
	return S_OK;
}

STDMETHODIMP CStlLists::get_Remove(IMyStruct** str)
{
	*str = *m_listiter;
	m_list.erase(m_listiter);
	return S_OK;
}

STDMETHODIMP CStlLists::RemoveAll()
{
	m_list.clear();
	return S_OK;
}

STDMETHODIMP CStlLists::First()
{
	m_listiter = m_list.begin();
	return S_OK;
}

STDMETHODIMP CStlLists::Next(IMyStruct** str, VARIANT_BOOL* b)
{
	if (m_listiter == m_list.end())
		*b = VARIANT_FALSE;
	else
	{
		*str = *m_listiter;
		++m_listiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlLists::get_Count(UINT* dw)
{
	*dw = (UINT)m_list.size();
	return S_OK;
}


STDMETHODIMP CStlintList::Find(long n, VARIANT_BOOL* b)
{
	m_listiter = find(m_list.begin(), m_list.end(), n);
	if (m_listiter == m_list.end())
		*b = VARIANT_FALSE;
	else
		*b = VARIANT_TRUE;
	return S_OK;
}

STDMETHODIMP CStlintList::put_SetAt(long n)
{
	*m_listiter = n;
	return S_OK;
}

STDMETHODIMP CStlintList::put_Add(long n)
{
	m_list.push_back(n);
	return S_OK;
}

STDMETHODIMP CStlintList::put_InsertBefore(long n)
{
	m_list.insert(m_listiter, n);
	return S_OK;
}

STDMETHODIMP CStlintList::get_Remove(long* n)
{
	*n = *m_listiter;
	m_list.erase(m_listiter);
	return S_OK;
}

STDMETHODIMP CStlintList::RemoveAll()
{
	m_list.clear();
	return S_OK;
}

STDMETHODIMP CStlintList::First()
{
	m_listiter = m_list.begin();
	return S_OK;
}

STDMETHODIMP CStlintList::Next(long* n, VARIANT_BOOL* b)
{
	if (m_listiter == m_list.end())
		*b = VARIANT_FALSE;
	else
	{
		*n = *m_listiter;
		++m_listiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlintList::get_Count(UINT* dw)
{
	*dw = (UINT)m_list.size();
	return S_OK;
}


// Arrays
STDMETHODIMP CStlDWordArray::get_Array(long idx, DWORD* dw)
{
	*dw = m_array[idx];
	return S_OK;
}

STDMETHODIMP CStlDWordArray::put_Array(long idx, DWORD dw)
{
	m_array[idx] = dw;
	return S_OK;
}

STDMETHODIMP CStlDWordArray::put_Add(DWORD dw)
{
	m_array.push_back(dw);
	return S_OK;
}

STDMETHODIMP CStlDWordArray::get_Remove(long idx, DWORD* dw)
{
	*dw = *(m_array.begin() + idx);
	m_array.erase(m_array.begin() + idx);
	return S_OK;
}

STDMETHODIMP CStlDWordArray::RemoveAll()
{
	m_array.clear();
	return S_OK;
}

STDMETHODIMP CStlDWordArray::First()
{
	m_arrayiter = m_array.begin();
	return S_OK;
}

STDMETHODIMP CStlDWordArray::Next(DWORD* dw, VARIANT_BOOL* b)
{
	if (m_arrayiter == m_array.end())
		*b = VARIANT_FALSE;
	else
	{
		*dw = *m_arrayiter;
		++m_arrayiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlDWordArray::get_Count(UINT* dw)
{
	*dw = (UINT)m_array.size();
	return S_OK;
}


STDMETHODIMP CStlMyObjectArray::get_Array(long idx, IMyStruct** str)
{
	*str = static_cast<IMyStruct*> (m_array[idx]);
	return S_OK;
}

STDMETHODIMP CStlMyObjectArray::put_Array(long idx, IMyStruct* str)
{
	m_array[idx] = static_cast<CMyObject*> (str);
	return S_OK;
}

STDMETHODIMP CStlMyObjectArray::put_Add(IMyStruct* str)
{
	m_array.push_back(static_cast<CMyObject*> (str));
	return S_OK;
}

STDMETHODIMP CStlMyObjectArray::get_Remove(long idx, IMyStruct** str)
{
	*str = static_cast<IMyStruct*> (*(m_array.begin() + idx));
	m_array.erase(m_array.begin() + idx);
	return S_OK;
}

STDMETHODIMP CStlMyObjectArray::RemoveAll()
{
	m_array.clear();
	return S_OK;
}

STDMETHODIMP CStlMyObjectArray::First()
{
	m_arrayiter = m_array.begin();
	return S_OK;
}

STDMETHODIMP CStlMyObjectArray::Next(IMyStruct** str, VARIANT_BOOL* b)
{
	if (m_arrayiter == m_array.end())
		*b = VARIANT_FALSE;
	else
	{
		*str = *m_arrayiter;
		++m_arrayiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlMyObjectArray::get_Count(UINT* dw)
{
	*dw = (UINT)m_array.size();
	return S_OK;
}


STDMETHODIMP CStlPointArray::get_Array(long idx, POINT* pt)
{
	*pt = m_array[idx];
	return S_OK;
}

STDMETHODIMP CStlPointArray::put_Array(long idx, POINT pt)
{
	m_array[idx] = pt;
	return S_OK;
}

STDMETHODIMP CStlPointArray::put_Add(POINT pt)
{
	m_array.push_back(pt);
	return S_OK;
}

STDMETHODIMP CStlPointArray::get_Remove(long idx, POINT* pt)
{
	*pt = *(m_array.begin() + idx);
	m_array.erase(m_array.begin() + idx);
	return S_OK;
}

STDMETHODIMP CStlPointArray::RemoveAll()
{
	m_array.clear();
	return S_OK;
}

STDMETHODIMP CStlPointArray::First()
{
	m_arrayiter = m_array.begin();
	return S_OK;
}

STDMETHODIMP CStlPointArray::Next(POINT* pt, VARIANT_BOOL* b)
{
	if (m_arrayiter == m_array.end())
		*b = VARIANT_FALSE;
	else
	{
		*pt = *m_arrayiter;
		++m_arrayiter;
		*b = VARIANT_TRUE;
	}
	return S_OK;
}

STDMETHODIMP CStlPointArray::get_Count(UINT* dw)
{
	*dw = (UINT)m_array.size();
	return S_OK;
}
