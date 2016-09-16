#include "stdafx.h"
#include <map>
#include <list>
#include <vector>
#include <deque>
#include <set>

using namespace std;

#define _USEME_
#include "stlcoll.h"

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// StlMaps

class CStlMapStringToMyObject :
	public IStlMapStringToMyObject,
	public CComObjectRoot,
	public CComCoClass<CStlMapStringToMyObject,&CLSID_CStlMapStringToMyObject>
{
public:
	CStlMapStringToMyObject() {}
BEGIN_COM_MAP(CStlMapStringToMyObject)
	COM_INTERFACE_ENTRY(IStlMapStringToMyObject)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlMapStringToMyObject)

	map<CString, CMyObject*> m_map;
	map<CString, CMyObject*>::iterator m_mapiter;

	STDMETHOD(get_Map)(BSTR str, IMyStruct** obj);
	STDMETHOD(put_Map)(BSTR str, IMyStruct* obj);
	STDMETHOD(Lookup)(BSTR str, IMyStruct** obj, VARIANT_BOOL* b);
	STDMETHOD(First)();
	STDMETHOD(Next)(BSTR* str, IMyStruct** obj, VARIANT_BOOL* b);
	STDMETHOD(get_Remove)(BSTR* str);
	STDMETHOD(RemoveAll)();
	STDMETHOD(get_Count)(UINT* dw);
};

class CStlMapDWordToMyStruct :
	public IStlMapDWordToMyStruct,
	public CComObjectRoot,
	public CComCoClass<CStlMapDWordToMyStruct,&CLSID_CStlMapDWordToMyStruct>
{
public:
	CStlMapDWordToMyStruct() {}
BEGIN_COM_MAP(CStlMapDWordToMyStruct)
	COM_INTERFACE_ENTRY(IStlMapDWordToMyStruct)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlMapDWordToMyStruct)

	multimap<DWORD, CMyStruct*> m_map;
	multimap<DWORD, CMyStruct*>::iterator m_mapiter;

	STDMETHOD(get_Map)(DWORD dw, IMyStruct** str);
	STDMETHOD(put_Map)(DWORD dw, IMyStruct* str);
	STDMETHOD(Lookup)(DWORD dw, IMyStruct** str, VARIANT_BOOL* b);
	STDMETHOD(First)();
	STDMETHOD(Next)(DWORD* dw, IMyStruct** str, VARIANT_BOOL* b);
	STDMETHOD(get_Remove)(DWORD* str);
	STDMETHOD(RemoveAll)();
	STDMETHOD(get_Count)(UINT* dw);
};

class CStlMapStringToString :
	public IStlMapStringToString,
	public CComObjectRoot,
	public CComCoClass<CStlMapStringToString,&CLSID_CStlMapStringToString>
{
public:
	CStlMapStringToString() {}
BEGIN_COM_MAP(CStlMapStringToString)
	COM_INTERFACE_ENTRY(IStlMapStringToString)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlMapStringToString)

	map<CString, CString> m_map;
	map<CString, CString>::iterator m_mapiter;

	STDMETHOD(get_Map)(BSTR str1, BSTR* str2);
	STDMETHOD(put_Map)(BSTR str1, BSTR str2);
	STDMETHOD(Lookup)(BSTR str1, BSTR* str2, VARIANT_BOOL* b);
	STDMETHOD(First)();
	STDMETHOD(Next)(BSTR* str1, BSTR* str2, VARIANT_BOOL* b);
	STDMETHOD(get_Remove)(BSTR* str);
	STDMETHOD(RemoveAll)();
	STDMETHOD(get_Count)(UINT* dw);
};

class CStlMaps :
	public IStlMaps,
	public CComObjectRoot,
	public CComCoClass<CStlMaps,&CLSID_CStlMaps>
{
public:
	CStlMaps() {}

	HRESULT FinalConstruct()
	{
	return CoCreateInstance(CLSID_CStlMapStringToMyObject, GetControllingUnknown(), CLSCTX_ALL, IID_IUnknown, (void**) &m_pUnkMapStringToMyObject);
	}

	void FinalRelease()
	{
		m_pUnkMapStringToMyObject.Release();
		m_pUnkMapDWordToMyStruct.Release();
		m_pUnkMapStringToString.Release();
	}

BEGIN_COM_MAP(CStlMaps)
	COM_INTERFACE_ENTRY(IStlMaps)
	COM_INTERFACE_ENTRY_AGGREGATE(IID_IStlMapStringToMyObject, m_pUnkMapStringToMyObject.p)
	COM_INTERFACE_ENTRY_AUTOAGGREGATE(IID_IStlMapDWordToMyStruct, m_pUnkMapDWordToMyStruct.p, CLSID_CStlMapDWordToMyStruct)
	COM_INTERFACE_ENTRY_AUTOAGGREGATE_BLIND(m_pUnkMapStringToString.p, CLSID_CStlMapStringToString)
	//COM_INTERFACE_ENTRY_AUTOAGGREGATE(IID_IStlMapStringToString, m_pUnkMapStringToString.p, CLSID_CStlMapStringToString)
END_COM_MAP()


DECLARE_REGISTRY_RESOURCEID(IDR_StlMaps)
DECLARE_GET_CONTROLLING_UNKNOWN()

CComPtr<IUnknown> m_pUnkMapStringToMyObject;
CComPtr<IUnknown> m_pUnkMapDWordToMyStruct;
CComPtr<IUnknown> m_pUnkMapStringToString;
};

/////////////////////////////////////////////////////////////////////////////
// StlLists

class CStlStringList :
	public IStlStringList,
	public CComTearOffObjectBase<CStlLists>
{
public:
	CStlStringList() {}
BEGIN_COM_MAP(CStlStringList)
	COM_INTERFACE_ENTRY(IStlStringList)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlStringList)

	//set<CString> m_list;
	//set<CString>::iterator m_listiter;

	list<CString> m_list;
	list<CString>::iterator m_listiter;

	STDMETHOD(Find)(BSTR str, VARIANT_BOOL* b);
	STDMETHOD(put_SetAt)(BSTR str);
	STDMETHOD(put_Add)(BSTR str);
	STDMETHOD(put_InsertBefore)(BSTR str);
	STDMETHOD(get_Remove)(BSTR* str);
	STDMETHOD(RemoveAll)();
	STDMETHOD(First)();
	STDMETHOD(Next)(BSTR* str, VARIANT_BOOL* b);
	STDMETHOD(get_Count)(UINT* dw);
};

class CStlintList :
	public IStlintList,
	public CComTearOffObjectBase<CStlLists>
{
public:
	CStlintList() {}
BEGIN_COM_MAP(CStlintList)
	COM_INTERFACE_ENTRY(IStlintList)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlintList)

	//multiset<int> m_list;
	//multiset<int>::iterator m_listiter;

	list<int> m_list;
	list<int>::iterator m_listiter;

	STDMETHOD(Find)(long n, VARIANT_BOOL* b);
	STDMETHOD(put_SetAt)(long n);
	STDMETHOD(put_Add)(long n);
	STDMETHOD(put_InsertBefore)(long n);
	STDMETHOD(get_Remove)(long* n);
	STDMETHOD(RemoveAll)();
	STDMETHOD(First)();
	STDMETHOD(Next)(long* n, VARIANT_BOOL* b);
	STDMETHOD(get_Count)(UINT* dw);
};

class CStlLists :
	public IStlLists,
	public IStlMyStructList,
	public CComObjectRoot,
	public CComCoClass<CStlLists,&CLSID_CStlLists>
{
public:
	CStlLists() {}

	void FinalRelease()
	{
		m_pUnkStringList.Release();
	}

BEGIN_COM_MAP(CStlLists)
	COM_INTERFACE_ENTRY(IStlLists)
	COM_INTERFACE_ENTRY_CACHED_TEAR_OFF(IID_IStlStringList, CStlStringList, m_pUnkStringList.p)
	COM_INTERFACE_ENTRY(IStlMyStructList)
	COM_INTERFACE_ENTRY_TEAR_OFF(IID_IStlintList, CStlintList)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlLists)
DECLARE_GET_CONTROLLING_UNKNOWN()

	list<CMyStruct*> m_list;
	list<CMyStruct*>::iterator m_listiter;

	STDMETHOD(Find)(IMyStruct* str, VARIANT_BOOL* b);
	STDMETHOD(put_SetAt)(IMyStruct* str);
	STDMETHOD(put_Add)(IMyStruct* str);
	STDMETHOD(put_InsertBefore)(IMyStruct* str);
	STDMETHOD(get_Remove)(IMyStruct** str);
	STDMETHOD(RemoveAll)();
	STDMETHOD(First)();
	STDMETHOD(Next)(IMyStruct** str, VARIANT_BOOL* b);
	STDMETHOD(get_Count)(UINT* dw);

	CComPtr<IUnknown> m_pUnkStringList;
};

/////////////////////////////////////////////////////////////////////////////
// StlArrays

class CStlDWordArray :
	public IStlDWordArray,
	public CComObjectRoot,
	public CComCoClass<CStlDWordArray,&CLSID_CStlDWordArray>
{
public:
	CStlDWordArray() {}
BEGIN_COM_MAP(CStlDWordArray)
	COM_INTERFACE_ENTRY(IStlDWordArray)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlDWordArray)

	vector<DWORD> m_array;
	vector<DWORD>::iterator m_arrayiter;

	STDMETHOD(get_Array)(long idx, DWORD* dw);
	STDMETHOD(put_Array)(long idx, DWORD dw);
	STDMETHOD(put_Add)(DWORD dw);
	STDMETHOD(get_Remove)(long idx, DWORD* dw);
	STDMETHOD(RemoveAll)();
	STDMETHOD(First)();
	STDMETHOD(Next)(DWORD* pt, VARIANT_BOOL* b);
	STDMETHOD(get_Count)(UINT* dw);
};

class CStlMyObjectArray :
	public IStlMyObjectArray,
	public CComObjectRoot
{
public:
	CStlMyObjectArray() {}

	HRESULT FinalConstruct()
	{
	return CoCreateInstance(CLSID_CStlDWordArray, GetControllingUnknown(), CLSCTX_ALL, IID_IUnknown, (void**) &m_pUnkDWordArray);
	}

	void FinalRelease()
	{
		m_pUnkDWordArray.Release();
	}

BEGIN_COM_MAP(CStlMyObjectArray)
	COM_INTERFACE_ENTRY(IStlMyObjectArray)
	COM_INTERFACE_ENTRY_AGGREGATE_BLIND(m_pUnkDWordArray.p)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlMyObjectArray)
DECLARE_GET_CONTROLLING_UNKNOWN()

	vector<CMyObject*> m_array;
	vector<CMyObject*>::iterator m_arrayiter;

	STDMETHOD(get_Array)(long idx, IMyStruct** str);
	STDMETHOD(put_Array)(long idx, IMyStruct* str);
	STDMETHOD(put_Add)(IMyStruct* str);
	STDMETHOD(get_Remove)(long idx, IMyStruct** str);
	STDMETHOD(RemoveAll)();
	STDMETHOD(First)();
	STDMETHOD(Next)(IMyStruct** str, VARIANT_BOOL* b);
	STDMETHOD(get_Count)(UINT* dw);

	CComPtr<IUnknown> m_pUnkDWordArray;
};

class CStlPointArray :
	public IStlPointArray,
	public CComTearOffObjectBase<CStlArrays>
{
public:
	CStlPointArray() {}
BEGIN_COM_MAP(CStlPointArray)
	COM_INTERFACE_ENTRY(IStlPointArray)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlPointArray)

	deque<CPoint> m_array;
	deque<CPoint>::iterator m_arrayiter;

	STDMETHOD(get_Array)(long idx, POINT* pt);
	STDMETHOD(put_Array)(long idx, POINT pt);
	STDMETHOD(put_Add)(POINT pt);
	STDMETHOD(get_Remove)(long idx, POINT* pt);
	STDMETHOD(RemoveAll)();
	STDMETHOD(First)();
	STDMETHOD(Next)(POINT* pt, VARIANT_BOOL* b);
	STDMETHOD(get_Count)(UINT* dw);

};

class CStlArrays :
	public IStlArrays,
	public CStlMyObjectArray,
	public CComCoClass<CStlArrays,&CLSID_CStlArrays>
{
public:
	CStlArrays() {}

	void FinalRelease()
	{
		m_pUnkPointArray.Release();
	}

BEGIN_COM_MAP(CStlArrays)
	COM_INTERFACE_ENTRY(IStlArrays)
	COM_INTERFACE_ENTRY_CHAIN(CStlMyObjectArray)
	COM_INTERFACE_ENTRY_CACHED_TEAR_OFF(IID_IStlPointArray, CStlPointArray, m_pUnkPointArray.p)
END_COM_MAP()

DECLARE_REGISTRY_RESOURCEID(IDR_StlArrays)
DECLARE_GET_CONTROLLING_UNKNOWN()

	CComPtr<IUnknown> m_pUnkPointArray;
};
