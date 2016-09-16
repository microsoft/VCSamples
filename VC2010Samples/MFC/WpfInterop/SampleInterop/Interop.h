#pragma once

#include <msclr\marshal.h>
#include <msclr\marshal_atl.h>
#include <msclr\marshal_windows.h>

namespace msclr
{
	namespace interop
	{
		template <>
		inline System::IntPtr marshal_as(const HWND& _from_object)
		{
			return System::IntPtr(_from_object);
		}

		template <>
		inline HWND marshal_as(System::IntPtr _from_object)
		{
			return static_cast<HWND>(_from_object.ToPointer());
		}
	}
}
