#pragma once
#include "CustomControl.h"
using namespace System;
using namespace System::ComponentModel;

using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


/// <summary> 
/// Summary for StringDialog
///
/// WARNING: If you change the name of this class, you will need to change the 
///          'Resource File Name' property for the managed resource compiler tool 
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
/// </summary>
public ref class StringDialog : public System::Windows::Forms::Form
{
public: 
	StringDialog(void)
	{
		InitializeComponent();
		//
		//TODO: Add the constructor code here
		//
	}

protected: 
	~StringDialog()
	{
		if (components)
		{
			delete components;
		}
	}

private: 
	System::Windows::Forms::Button^  button1;
#ifndef _M_CEE_SAFE
	ScribbleCustomControl^  scribbleCustomControl1;
#endif
	System::Windows::Forms::Label^  label1;




private:
	/// <summary>
	/// Required designer variable.
	/// </summary>
	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	/// <summary>
	/// Required method for Designer support - do not modify
	/// the contents of this method with the code editor.
	/// </summary>
	void InitializeComponent(void)
	{
		this->button1 = gcnew System::Windows::Forms::Button();
#ifndef _M_CEE_SAFE
		this->scribbleCustomControl1 = gcnew ScribbleCustomControl();
#endif
		this->label1 = gcnew System::Windows::Forms::Label();
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->button1->FlatStyle = System::Windows::Forms::FlatStyle::System;
		this->button1->Location = System::Drawing::Point(66, 102);
		this->button1->Name = L"button1";
		this->button1->TabIndex = 1;
		this->button1->Text = L"OK";

#ifndef _M_CEE_SAFE
		// 
		// scribbleCustomControl1
		// 
		this->scribbleCustomControl1->Location = System::Drawing::Point(29, 52);
		this->scribbleCustomControl1->Name = L"scribbleCustomControl1";
		this->scribbleCustomControl1->Size = System::Drawing::Size(146, 23);
		this->scribbleCustomControl1->TabIndex = 0;
		this->scribbleCustomControl1->Text = L"scribbleCustomControl1";
#endif
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0));
		this->label1->Location = System::Drawing::Point(13, 13);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(180, 21);
		this->label1->TabIndex = 2;
		this->label1->Text = L"The Unmanaged String:";
		this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
		// 
		// StringDialog
		// 
		this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
		this->ClientSize = System::Drawing::Size(207, 139);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->button1);
#ifndef _M_CEE_SAFE
		this->Controls->Add(this->scribbleCustomControl1);
#endif
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->Name = L"StringDialog";
		this->Text = L"StringDialog";
		this->ResumeLayout(false);
		this->PerformLayout();

	}		
#pragma endregion
};