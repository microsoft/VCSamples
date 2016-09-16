#include "StdAfx.h"
#include "SampleContentProxy.h"

using namespace WpfSample;

CSampleContentProxy::CSampleContentProxy()
	: CUIElementProxy(gcnew SampleContent)
{
}
