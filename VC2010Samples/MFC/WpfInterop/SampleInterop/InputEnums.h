#pragma once

//
// Native versions of enums in System::Windows::Input
//

namespace Interop {

	enum ModifierKeys
	{
		ModifierKeys_None = 0,
		ModifierKeys_Alt = 1,
		ModifierKeys_Control = 2,
		ModifierKeys_Shift = 4,
		ModifierKeys_Windows = 8
	};

	enum FocusNavigationDirection
	{
		FocusNavigationDirection_Next,
		FocusNavigationDirection_Previous,
		FocusNavigationDirection_First,
		FocusNavigationDirection_Last,
		FocusNavigationDirection_Left,
		FocusNavigationDirection_Right,
		FocusNavigationDirection_Up,
		FocusNavigationDirection_Down
	};

}