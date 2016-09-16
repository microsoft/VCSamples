#pragma once

#include "ManagedObjectProxy.h"

//
// CUIElementProxy - Proxy for System::Windows::UIElement
//
class CUIElementProxy : public CManagedObjectProxy
{
	DECLARE_MANAGED_PROXY(CUIElementProxy, CManagedObjectProxy, System::Windows::UIElement);
};
