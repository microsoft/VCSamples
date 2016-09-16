/******************************************************************************
DESCRIPTION: This is the header file for the generic pop up that comes when a
			bad input is entered by the user. The error message is sent by the 
			calling method in the form of a string, which gets displayed in the
			pop-up.
******************************************************************************/

#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace My32to64
{
	/// <summary> 
	/// Summary for Error
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Error : public System::Windows::Forms::Form
	{
	public: 
		Error(String^ str)
		{
			InitializeComponent(str);
			//
			//TODO: Add the constructor code here
			//
		}
        
	protected: 
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
//				components->Dispose();
//				delete components;
			}
			__super::Dispose(disposing);
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;

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
		void InitializeComponent(String^ str)
		{
			this->button1 = gcnew System::Windows::Forms::Button();
			this->label1 = gcnew System::Windows::Forms::Label();
			this->SuspendLayout();
			// 
			// button1
			// 
			
			this->button1->AutoRelocate = true;
			this->button1->Name = L"button1";
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->Click += gcnew System::EventHandler(this, &Error::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.0F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0));
			this->label1->Location = System::Drawing::Point(34, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(174, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = str; //L"!! Please enter valid input !!";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Error
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->AutoSize = true;
			this->BackColor = System::Drawing::Color::BurlyWood;
			this->ClientSize = System::Drawing::Size(242, 116);
			this->Name = L"Error";
			this->Text = L"Invalid Input";			
			this->Controls->Add(this->label1);

			this->button1->Location = System::Drawing::Point(this->Right, this->Bottom); //System::Drawing::Point(81, 81);
			this->Controls->Add(this->button1);

			this->ResumeLayout(false);
			this->PerformLayout();

		}		
#pragma endregion
	private: System::Void button1_Click(System::Object^  , System::EventArgs^  )
			 {
				 Close();
			 }

	};
}