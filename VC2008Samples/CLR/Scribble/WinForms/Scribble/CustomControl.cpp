#ifndef _M_CEE_SAFE

#include <msclr\marshal.h>
#include "CustomControl.h"
#include "UnmanagedStringProvider.h"

using namespace System;
using namespace System::Drawing;
using namespace msclr::interop;

void ScribbleCustomControl::OnPaint(PaintEventArgs ^e)
{
	UnmanagedStringProvider *usp = new UnmanagedStringProvider;
	String ^Text = marshal_as<String ^>(usp->GetUnmanagedString());
	e->Graphics->DrawString(Text, Font, gcnew SolidBrush(ForeColor), ClientRectangle);
	delete usp;
}

#endif