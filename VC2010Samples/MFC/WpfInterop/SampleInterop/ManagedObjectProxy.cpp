// ManagedObjectProxy.h
//
// This code was originally based on that of Paul DiLascia in the April 2005 issue of MSDN Magazine
// http://msdn.microsoft.com/en-us/magazine/cc300632.aspx
//
#include "stdafx.h"
#include "ManagedObjectProxy.h"

CManagedObjectProxy::CManagedObjectProxy()
{
	// The constructor must be here and not inline to allow the gcroot<>
	// constructor to correctly initialize the GCHandle stored in m_handle.
}

CManagedObjectProxy::CManagedObjectProxy(const CManagedObjectProxy& o)
	: m_handle(o.m_handle)
{
	// See remarks above
}

CManagedObjectProxy::~CManagedObjectProxy()
{
	// The destructor must be here and not inline to allow the gcroot<>
	// destructor to correctly free the GCHandle stored in m_handle.
}

CManagedObjectProxy& CManagedObjectProxy::operator=(const CManagedObjectProxy& r)
{
	m_handle = r.m_handle;	// copies underlying GCHandle.Target
	return *this;
}

void CManagedObjectProxy::Dispose() const 
{
	delete m_handle;
}

bool CManagedObjectProxy::operator==(const CManagedObjectProxy& r) const
{
	return (*this)->Equals(r.ThisObject());
}

CString CManagedObjectProxy::ToString() const
{
	return (*this)->ToString();
}

CString CManagedObjectProxy::TypeName() const
{
	return (*this)->GetType()->Name;
}

bool CManagedObjectProxy::IsNull() const
{
	return ThisObject() == nullptr;
}
