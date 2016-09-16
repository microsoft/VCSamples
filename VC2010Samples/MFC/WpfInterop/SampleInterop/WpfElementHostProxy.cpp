#include "StdAfx.h"
#include "WpfElementHostProxy.h"

using namespace msclr::interop;
using namespace System;
using namespace WpfSample;

CWpfElementHostProxy::CWpfElementHostProxy()
	: CManagedObjectProxy(gcnew WpfElementHost)
{
}

HWND CWpfElementHostProxy::Create(int classStyle, int style, int exStyle, int x, int y,
	int width, int height, LPCTSTR name, HWND parent)
{
	return marshal_as<HWND>((*this)->Create(classStyle, style, exStyle, x, y,
		width, height, marshal_as<String^>(name), marshal_as<IntPtr>(parent)));
}

IKeyboardInputSinkProxy CWpfElementHostProxy::GetKeyboardInputSink() const
{
	return (*this)->KeyboardInputSink;
}

CUIElementProxy CWpfElementHostProxy::GetElement() const
{
	return (*this)->Element;
}

void CWpfElementHostProxy::SetElement(const CUIElementProxy &element) const
{
	(*this)->Element = element;
}

void CWpfElementHostProxy::GotFocus_AddEventHandler(const CGotFocusEventHandlerProxy &gotFocusEventHandler) const
{
	(*this)->GotFocus += gotFocusEventHandler;
}

void CWpfElementHostProxy::GotFocus_RemoveEventHandler(const CGotFocusEventHandlerProxy &gotFocusEventHandler) const
{
	(*this)->GotFocus -= gotFocusEventHandler;
}
