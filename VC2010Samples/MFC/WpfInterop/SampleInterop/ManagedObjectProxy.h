// ManagedObjectProxy.h - wrap .NET classes in purely native C++ wrappers.
//
// This code was originally based on that of Paul DiLascia in the April 2005 issue of MSDN Magazine
// http://msdn.microsoft.com/en-us/magazine/cc300632.aspx
//
#pragma once

#include "ImportExport.h"

#ifdef __cplusplus_cli
#define MANAGED_ONLY_IMPL(x) x
#else
#define MANAGED_ONLY_IMPL(x)
#endif

// Handle to managed object.
// Appears as msclr::gcroot<T> wrapper to managed code, intptr_t to native code.
#ifdef __cplusplus_cli
# define GCHANDLE(T) msclr::gcroot<T>
static_assert(sizeof(msclr::gcroot<System::Object^>) == sizeof(intptr_t), "msclr::gcroot<System::Object^> and intptr_t must be the same size.");
#else
# define GCHANDLE(T) intptr_t
#endif

// Wrapper for System::Object
// CManagedObjectProxy doesn't use DECLARE_MANAGED_PROXY because it has no base class.
class CManagedObjectProxy
{
public:
	InteropDll_ImportExport CManagedObjectProxy();
	InteropDll_ImportExport CManagedObjectProxy(const CManagedObjectProxy& o);
	InteropDll_ImportExport CManagedObjectProxy& operator=(const CManagedObjectProxy& r);
	InteropDll_ImportExport ~CManagedObjectProxy();
	InteropDll_ImportExport void Dispose() const;

#ifdef __cplusplus_cli
	CManagedObjectProxy(System::Object^ o) : m_handle(o) { }
	System::Object^ ThisObject() const { return static_cast<System::Object^>(m_handle); }
	System::Object^ operator->() const { return ThisObject(); }
	System::Object^ operator*() const { return ThisObject(); }
	operator System::Object^() const { return ThisObject(); }
#endif

	InteropDll_ImportExport bool operator==(const CManagedObjectProxy& r) const;
	InteropDll_ImportExport bool operator!=(const CManagedObjectProxy& r) const { return ! operator==(r); }
	InteropDll_ImportExport CString ToString() const;
	InteropDll_ImportExport CString TypeName() const;
	InteropDll_ImportExport bool IsNull() const;
	InteropDll_ImportExport operator bool() const { return !IsNull(); }
	InteropDll_ImportExport bool operator!() const { return IsNull(); }

protected:
	GCHANDLE(System::Object^) m_handle; // handle to underlying managed object
};


#ifdef __cplusplus_cli
// This declares the managed part of DECLARE_MANAGED_PROXY. For internal use
// only; use DECLARE_MANAGED_PROXY.
//
#define DECLARE_MANAGED_PROXY_HELPER(PROXY_CLASS, PROXY_BASE_CLASS, MANAGED_CLASS)	\
public:																				\
	typedef MANAGED_CLASS ManagedClassType;											\
	PROXY_CLASS(MANAGED_CLASS^ o) : PROXY_BASE_CLASS(o) { }							\
	MANAGED_CLASS^ ThisObject() const												\
	{																				\
		return safe_cast<MANAGED_CLASS^>(static_cast<System::Object^>(m_handle));	\
	}																				\
	MANAGED_CLASS^ operator->() const { return ThisObject(); }						\
	MANAGED_CLASS^ operator*() const { return ThisObject(); }						\
	operator MANAGED_CLASS^() const { return ThisObject(); }						\
	PROXY_CLASS& operator=(MANAGED_CLASS^ o)										\
	{																				\
		m_handle = o;																\
		return *this;																\
	}
#else // NOT __cplusplus_cli
// Native code doesn't see the managed stuff
#define DECLARE_MANAGED_PROXY_HELPER(PROXY_CLASS, PROXY_BASE_CLASS, MANAGED_CLASS)
#endif

// Use this to declare a wrapper class. Declares the basic constructors and
// operators needed for type-safe usage.
#define DECLARE_MANAGED_PROXY(PROXY_CLASS, PROXY_BASE_CLASS, MANAGED_CLASS)				\
public:																					\
	InteropDll_ImportExport PROXY_CLASS(const PROXY_CLASS& o) : PROXY_BASE_CLASS(o) { }	\
	InteropDll_ImportExport PROXY_CLASS& operator=(const PROXY_CLASS &r)				\
	{																					\
		PROXY_BASE_CLASS::operator=(r);													\
		return *this;																	\
	}																					\
	DECLARE_MANAGED_PROXY_HELPER(PROXY_CLASS, PROXY_BASE_CLASS, MANAGED_CLASS)

// Helper to downcast from a managed interface proxy template class to the CManagedObjectProxy class that derives from it
template <template<class> class INTERFACE_PROXY_CLASS, class PROXY_CLASS>
const PROXY_CLASS &GetObjectProxy(const INTERFACE_PROXY_CLASS<PROXY_CLASS>* pInterfaceProxy)
{
	return *static_cast<const PROXY_CLASS*>(pInterfaceProxy);
}
