#include "StdAfx.h"
#include "GotFocusEventHandlerProxy.h"

using namespace msclr::interop;
using namespace System;

HWND CGotFocusEventArgsProxy::GetHwndLostFocus() const
{
	return marshal_as<HWND>((*this)->HwndLostFocus);
}

//
// CGotFocusEventHandlerProxy
//

CGotFocusEventHandlerProxy::CGotFocusEventHandlerProxy(const CGotFocusEventHandler &nativeEventHandler)
	: CManagedObjectProxy(gcnew System::EventHandler<WpfSample::GotFocusEventArgs^>(
		nativeEventHandler.ManagedEventHandler(), &ManagedEventHandler<CGotFocusEventArgsProxy>::OnEvent))
{
}

