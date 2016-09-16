/******************************************************************************
DESCRIPTION: This is the header file for the pop up that comes when the user 
			clicks on the Delete Element button under the 2D Array tab.
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
	/// Summary for DelArray
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class DelArray : public System::Windows::Forms::Form
	{
	public: 
		DelArray(void)
		{
			InitializeComponent();
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
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;

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
			this->label3 = gcnew System::Windows::Forms::Label();
			this->textBox3 = gcnew System::Windows::Forms::TextBox();
			this->button2 = gcnew System::Windows::Forms::Button();
			this->button1 = gcnew System::Windows::Forms::Button();
			this->textBox2 = gcnew System::Windows::Forms::TextBox();
			this->label2 = gcnew System::Windows::Forms::Label();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
			this->label3->Location = System::Drawing::Point(150, 46);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(14, 17);
			this->label3->TabIndex = 19;
			this->label3->Text = L"X";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(170, 45);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(27, 20);
			this->textBox3->TabIndex = 18;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(189, 90);
			this->button2->Name = L"button2";
			this->button2->TabIndex = 17;
			this->button2->Text = L"Close";
			this->button2->Click += gcnew System::EventHandler(this, &DelArray::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(28, 90);
			this->button1->MouseOverBackColor = System::Drawing::Color::Tan;
			this->button1->Name = L"button1";
			this->button1->TabIndex = 16;
			this->button1->Text = L"OK";
			this->button1->Click += gcnew System::EventHandler(this, &DelArray::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(117, 45);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(27, 20);
			this->textBox2->TabIndex = 15;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
			this->label2->Location = System::Drawing::Point(28, 48);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 17);
			this->label2->TabIndex = 14;
			this->label2->Text = L"Position";
			// 
			// DelArray
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->BackColor = System::Drawing::Color::BurlyWood;
			this->ClientSize = System::Drawing::Size(292, 158);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Name = L"DelArray";
			this->Text = L"DelArray";
			this->ResumeLayout(false);
			this->PerformLayout();

		}		
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
			 

private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
			 

};
}