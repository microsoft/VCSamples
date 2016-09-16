#pragma once

#include "ImportExport.h"
#include "ManagedObjectProxy.h"
#include "IKeyboardInputSinkProxy.h"
#include "UIElementProxy.h"
#include "GotFocusEventHandlerProxy.h"

//
// CWpfElementHostProxy - Proxy for WpfSample::WpfElementHost
//
class CWpfElementHostProxy : public CManagedObjectProxy
{
	DECLARE_MANAGED_PROXY(CWpfElementHostProxy, CManagedObjectProxy, WpfSample::WpfElementHost);
public:
	InteropDll_ImportExport CWpfElementHostProxy();

	InteropDll_ImportExport HWND Create(int classStyle, int style, int exStyle, int x, int y, int width, int height, LPCTSTR name, HWND parent);

	__declspec(property(get=GetKeyboardInputSink)) IKeyboardInputSinkProxy KeyboardInputSink;
	InteropDll_ImportExport IKeyboardInputSinkProxy GetKeyboardInputSink() const;

	__declspec(property(get=GetElement, put=SetElement)) CUIElementProxy Element;
	InteropDll_ImportExport CUIElementProxy GetElement() const;
	InteropDll_ImportExport void SetElement(const CUIElementProxy &child) const;

	InteropDll_ImportExport void GotFocus_AddEventHandler(const CGotFocusEventHandlerProxy &gotFocusEventHandler) const;
	InteropDll_ImportExport void GotFocus_RemoveEventHandler(const CGotFocusEventHandlerProxy &gotFocusEventHandler) const;
};
