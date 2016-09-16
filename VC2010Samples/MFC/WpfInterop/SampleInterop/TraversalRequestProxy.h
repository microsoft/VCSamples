#pragma once

#include "ImportExport.h"
#include "ManagedObjectProxy.h"
#include "InputEnums.h"

//
// CTraversalRequestProxy - Proxy for System::Windows::Input::TraversalRequest
//
class CTraversalRequestProxy : public CManagedObjectProxy
{
	DECLARE_MANAGED_PROXY(CTraversalRequestProxy, CManagedObjectProxy, System::Windows::Input::TraversalRequest);
public:
	InteropDll_ImportExport CTraversalRequestProxy(Interop::FocusNavigationDirection focusNavigationDirection);
	InteropDll_ImportExport CTraversalRequestProxy(Interop::FocusNavigationDirection focusNavigationDirection, bool wrapped);

	__declspec(property(get=GetFocusNavigationDirection)) Interop::FocusNavigationDirection FocusNavigationDirection;
	InteropDll_ImportExport Interop::FocusNavigationDirection GetFocusNavigationDirection() const;

	__declspec(property(get=GetWrapped, put=SetWrapped)) bool Wrapped;
	InteropDll_ImportExport bool GetWrapped() const;
	InteropDll_ImportExport void SetWrapped(bool wrapped) const;
};


