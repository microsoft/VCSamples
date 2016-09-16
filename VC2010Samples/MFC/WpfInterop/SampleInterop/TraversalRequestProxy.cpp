#include "StdAfx.h"
#include "TraversalRequestProxy.h"

using namespace System;
using namespace System::Windows::Input;

CTraversalRequestProxy::CTraversalRequestProxy(Interop::FocusNavigationDirection focusNavigationDirection)
	: CManagedObjectProxy(gcnew TraversalRequest(static_cast<System::Windows::Input::FocusNavigationDirection>(focusNavigationDirection)))
{
}

CTraversalRequestProxy::CTraversalRequestProxy(Interop::FocusNavigationDirection focusNavigationDirection, bool wrapped)
	: CManagedObjectProxy(gcnew TraversalRequest(static_cast<System::Windows::Input::FocusNavigationDirection>(focusNavigationDirection)))
{
	SetWrapped(wrapped);
}

Interop::FocusNavigationDirection CTraversalRequestProxy::GetFocusNavigationDirection() const
{
	return static_cast<Interop::FocusNavigationDirection>((*this)->FocusNavigationDirection);
}

bool CTraversalRequestProxy::GetWrapped() const
{
	return (*this)->Wrapped;
}

void CTraversalRequestProxy::SetWrapped(bool wrapped) const
{
	(*this)->Wrapped = wrapped;
}
