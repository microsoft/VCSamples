// OBJECTS.H : declarations for CMyCircle, CMyCircleCollection
//          and CMyCircleCollectionContainer
//
// This is a part of the Active Template Library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Active Template Library product.

#ifndef __OBJECTS_H__
#define __OBJECTS_H__

#include "circcres.h"

[ emitidl ];
[
	object,
	uuid(956ADD2D-4BFB-4CA3-A4B4-C87F204B5A48),
	dual,
	helpstring("IMyCircle Interface"),
	pointer_default(unique)
]
__interface IMyCircle : IDispatch
{
	// center coordinates
	[propget, id(1)] HRESULT XCenter([out, retval] double* pXCenter);
	[propput, id(1)] HRESULT XCenter([in] double xCenter);
	[propget, id(2)] HRESULT YCenter([out, retval] double* pYCenter);
	[propput, id(2)] HRESULT YCenter([in] double YCenter);
	// radius
	[propget, id(3)] HRESULT Radius([out, retval] double* pRadius);
	[propput, id(3)] HRESULT Radius([in] double Radius);
	// label
	[propget, id(4)] HRESULT Label([out,retval] BSTR* pbstrLabel);
	[propput, id(4)] HRESULT Label([in] BSTR bstrLabel); 
};

///////////////////////////////////////////////////////
[
	object,
	uuid(EE86680D-E2CB-4C35-A6A3-3A2C5AD5A7E0),
	dual,
	helpstring("IMyCircleCollection Interface"),
	pointer_default(unique)
]
__interface IMyCircleCollection : IDispatch
{
	[propget, helpstring("Returns number of items in collection.")]
		HRESULT Count([out, retval] long* retval);

	[propget, id(DISPID_VALUE), helpstring("Given an index, returns an item in the collection.")]
		HRESULT Item([in] long Index, [out, retval] VARIANT* retval);

	[propget, restricted, id(DISPID_NEWENUM),
		helpstring("returns an enumerator for the collection.")]	// Must be propget. 
		HRESULT _NewEnum([out, retval] IUnknown** retval);	
};

///////////////////////////////////////////////////////
[
	object,
	uuid(C7FBF950-9080-448E-B5AE-58334E21E4A7),
	dual,
	helpstring("IMyCircleCollectionCreator Interface"),
	pointer_default(unique)
]
__interface IMyCircleCollectionCreator : IDispatch
{
	[id(1), helpstring("Returns a collection of Circles.")]
	HRESULT GetCircles([in] short n, [out, retval] VARIANT* retval);
};

/////////////////////////////////////////////////////////////////////////////
// class CMyCircle : user defined object for enumeration

[
	coclass,
	threading(apartment),
	uuid("4C0CF699-6487-4707-8A63-E51DB3643516"),
	noncreatable,
	aggregatable(never),
	default("IMyCircle"),
	support_error_info("IMyCircle")
]
class ATL_NO_VTABLE CMyCircle :
	public IMyCircle
{
public:
	CMyCircle();

// IMyCircle
	STDMETHOD(get_XCenter)(double* pXCenter);
	STDMETHOD(put_XCenter)(double xCenter);
	STDMETHOD(get_YCenter)(double* pYCenter);
	STDMETHOD(put_YCenter)(double yCenter);
	STDMETHOD(get_Radius)(double* pRadius);
	STDMETHOD(put_Radius)(double Radius);
	STDMETHOD(get_Label)(BSTR* bstrLabel);
	STDMETHOD(put_Label)(BSTR bstrLAbel);

// Attributes
protected:
	double          m_xCenter;
	double          m_yCenter;
	double          m_Radius;
	CComBSTR        m_bstrLabel;

	friend class CMyCircleCollection;
};

///////////////////////////////////////////////////////////////////////////
// class CMyCircleCollectionCreator

[
	coclass,
	threading(both),
	aggregatable(never),
	uuid("4CC32AC1-AD28-4255-8533-CE71D7E4FD71"),
	progid("CircColl.MyCircleCollectionAttrib"),
	version("1.0"),
	default("IMyCircleCollectionCreator"),
	support_error_info("IMyCircleCollectionCreator")
]
class ATL_NO_VTABLE CMyCircleCollectionCreator :
	public IMyCircleCollectionCreator
{
public:
// IMyCircleCollectionCreator
	STDMETHOD(GetCircles)(short n, VARIANT* retval);
};


///////////////////////////////////////////////////////////////////////////
// class CMyCircleCollection

[
	coclass,
	threading(apartment),
	uuid("5537CB2B-5F39-405F-A2B7-8B55FA8B4D42"),
	noncreatable,
	aggregatable(never),
	default("IMyCircleCollection"),
	support_error_info("IMyCircleCollection")
]
class ATL_NO_VTABLE CMyCircleCollection :
	public IMyCircleCollection
{
public:
	CMyCircleCollection()
	{
		m_VarVect = NULL;
		m_nSize = 0;
	}
	~CMyCircleCollection()
	{
		delete [] m_VarVect;
	}

// IMyCircleCollection methods
	STDMETHOD(get_Count)(long* retval);
	STDMETHOD(get_Item)(long Index, VARIANT* retval);
	STDMETHOD(get__NewEnum)(IUnknown** retval);

	// helpers
public:
	void Init(short n);
protected:
// internal data
	CComVariant* m_VarVect;
	int m_nSize;
};

///////////////////////////////////////////////////////////////////////////

#endif // __OBJECTS_H__
