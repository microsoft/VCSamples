#pragma once

#include "ManagedObjectProxy.h"
#include "TraversalRequestProxy.h"
#include "InputEnums.h"

#pragma push_macro("TranslateAccelerator")
#undef TranslateAccelerator
#ifdef UNICODE
#define TranslateAccelerator_AorW  TranslateAcceleratorW
#else
#define TranslateAccelerator_AorW  TranslateAcceleratorA
#endif // !UNICODE

template <class PROXY_CLASS>
class IKeyboardInputSinkProxyImplBase
{
protected:
	MANAGED_ONLY_IMPL(
	System::Windows::Interop::IKeyboardInputSink^ GetIKeyboardInputSink() const
	{
		return safe_cast<System::Windows::Interop::IKeyboardInputSink^>(*GetObjectProxy(this));
	});

public:
	bool HasFocusWithin() const MANAGED_ONLY_IMPL(
	{
		return GetIKeyboardInputSink()->HasFocusWithin();
	});

	bool OnMnemonic(MSG *pMsg) const
	{
		return OnMnemonic(pMsg, GetSystemModifierKeys());
	}
	bool OnMnemonic(MSG *pMsg, Interop::ModifierKeys modifierKeys) const MANAGED_ONLY_IMPL(
	{
		System::Windows::Interop::MSG% msgRef = *reinterpret_cast<System::Windows::Interop::MSG*>(pMsg);
		return GetIKeyboardInputSink()->OnMnemonic(msgRef, static_cast<System::Windows::Input::ModifierKeys>(modifierKeys));
	});

	bool TabInto(const CTraversalRequestProxy &request) const
	{
		return GetIKeyboardInputSink()->TabInto(request);
	}

	bool TranslateAccelerator_AorW(MSG *pMsg) const
	{
		return TranslateAccelerator_AorW(pMsg, GetSystemModifierKeys());
	}
	bool TranslateAccelerator_AorW(MSG *pMsg, Interop::ModifierKeys modifierKeys) const MANAGED_ONLY_IMPL(
	{
		System::Windows::Interop::MSG% msgRef = *reinterpret_cast<System::Windows::Interop::MSG*>(pMsg);
		return GetIKeyboardInputSink()->TranslateAccelerator(msgRef, static_cast<System::Windows::Input::ModifierKeys>(modifierKeys));
	});

	bool TranslateChar(MSG *pMsg) const
	{
		return TranslateChar(pMsg, GetSystemModifierKeys());
	}
	bool TranslateChar(MSG *pMsg, Interop::ModifierKeys modifierKeys) const MANAGED_ONLY_IMPL(
	{
		System::Windows::Interop::MSG% msgRef = *reinterpret_cast<System::Windows::Interop::MSG*>(pMsg);
		return GetIKeyboardInputSink()->TranslateChar(msgRef, static_cast<System::Windows::Input::ModifierKeys>(modifierKeys));
	});

private:
	static Interop::ModifierKeys GetSystemModifierKeys()
	{
		Interop::ModifierKeys modifierKeys = Interop::ModifierKeys_None;

		short keyState = GetKeyState(VK_SHIFT);
		if((keyState & 0x8000) == 0x8000)
		{
			modifierKeys = static_cast<Interop::ModifierKeys>(modifierKeys | Interop::ModifierKeys_Shift);
		}

		keyState = GetKeyState(VK_CONTROL);
		if((keyState & 0x8000) == 0x8000)
		{
			modifierKeys = static_cast<Interop::ModifierKeys>(modifierKeys | Interop::ModifierKeys_Control);
		}

		keyState = GetKeyState(VK_MENU);
		if((keyState & 0x8000) == 0x8000)
		{
			modifierKeys = static_cast<Interop::ModifierKeys>(modifierKeys | Interop::ModifierKeys_Alt);
		}

		return modifierKeys;
	}
};

template <class PROXY_CLASS>
class InteropDll_ImportExport IKeyboardInputSinkProxyImpl : public IKeyboardInputSinkProxyImplBase<PROXY_CLASS>
{
};

//
// IKeyboardInputSinkProxy - Proxy for System::Windows::Interop::IKeyboardInputSink
//
class IKeyboardInputSinkProxy : public CManagedObjectProxy, public IKeyboardInputSinkProxyImpl<IKeyboardInputSinkProxy>
{
	DECLARE_MANAGED_PROXY(IKeyboardInputSinkProxy, CManagedObjectProxy, System::Windows::Interop::IKeyboardInputSink);
};

#pragma pop_macro("TranslateAccelerator")
