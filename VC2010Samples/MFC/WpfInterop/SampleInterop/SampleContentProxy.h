#pragma once

#include "ImportExport.h"
#include "UIElementProxy.h"

//
// CSampleContentProxy - Proxy for WpfSample::SampleContent
//
class CSampleContentProxy : public CUIElementProxy
{
	DECLARE_MANAGED_PROXY(CSampleContentProxy, CUIElementProxy, WpfSample::SampleContent);

	InteropDll_ImportExport CSampleContentProxy();
};
