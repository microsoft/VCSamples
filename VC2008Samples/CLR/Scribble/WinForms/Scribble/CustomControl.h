#ifndef _M_CEE_SAFE

#pragma once

#using <System.Windows.Forms.dll>
using namespace System::Windows::Forms;

public ref class ScribbleCustomControl : System::Windows::Forms::Control
{
public:
	virtual void OnPaint(PaintEventArgs ^e) new;
};

#endif