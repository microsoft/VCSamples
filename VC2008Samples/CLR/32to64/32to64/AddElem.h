/******************************************************************************
DESCRIPTION: This is the header file for the pop up that comes when the user 
			clicks on the Add Element button under the Doubly Linked List tab.
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
	/// Summary for AddElem
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class AddElem : public System::Windows::Forms::Form
	{
	public: 
		AddElem(void)
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
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;


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
			this->label1 = gcnew System::Windows::Forms::Label();
			this->label2 = gcnew System::Windows::Forms::Label();
			this->textBox1 = gcnew System::Windows::Forms::TextBox();
			this->textBox2 = gcnew System::Windows::Forms::TextBox();
			this->button1 = gcnew System::Windows::Forms::Button();
			this->button2 = gcnew System::Windows::Forms::Button();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
			this->label1->Location = System::Drawing::Point(27, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Number";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
			this->label2->Location = System::Drawing::Point(27, 81);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(54, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Position";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(116, 30);
			this->textBox1->Name = L"textBox1";
			this->textBox1->TabIndex = 2;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(116, 78);
			this->textBox2->Name = L"textBox2";
			this->textBox2->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(27, 123);
			this->button1->MouseOverBackColor = System::Drawing::Color::Tan;
			this->button1->Name = L"button1";
			this->button1->TabIndex = 4;
			this->button1->Text = L"OK";
			this->button1->Click += gcnew System::EventHandler(this, &AddElem::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(188, 123);
			this->button2->Name = L"button2";
			this->button2->TabIndex = 5;
			this->button2->Text = L"Close";
			this->button2->Click += gcnew System::EventHandler(this, &AddElem::button2_Click);
			// 
			// AddElem
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->BackColor = System::Drawing::Color::BurlyWood;
			this->ClientSize = System::Drawing::Size(292, 158);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AddElem";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Add Element";
			this->ResumeLayout(false);
			this->PerformLayout();

		}		
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
	

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
		 

};
}