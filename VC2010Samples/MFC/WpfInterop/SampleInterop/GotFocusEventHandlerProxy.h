#pragma once

#include "ImportExport.h"
#include "ManagedObjectProxy.h"
#include "EventHandler.h"

//
// CGotFocusEventArgsProxy - Proxy for WpfSample::GotFocusEventArgs
//
class CGotFocusEventArgsProxy : public CManagedObjectProxy
{
	DECLARE_MANAGED_PROXY(CGotFocusEventArgsProxy, CManagedObjectProxy, WpfSample::GotFocusEventArgs);
public:
	__declspec(property(get=GetHwndLostFocus)) HWND HwndLostFocus;
	InteropDll_ImportExport HWND GetHwndLostFocus() const;
};

//
// CGotFocusEventHandler - Proxy used to invoke a native method from a managed delegate
//
class InteropDll_ImportExport CGotFocusEventHandler : public CNativeEventHandler<CGotFocusEventArgsProxy>
{
};

//
// CGotFocusEventHandlerProxy - Proxy for System::EventHandler<WpfSample::GotFocusEventArgs^>
//
class CGotFocusEventHandlerProxy : public CManagedObjectProxy
{
	DECLARE_MANAGED_PROXY(CGotFocusEventHandlerProxy, CManagedObjectProxy, System::EventHandler<WpfSample::GotFocusEventArgs^>);
public:
	InteropDll_ImportExport CGotFocusEventHandlerProxy(const CGotFocusEventHandler &nativeEventHandler);
};
