/******************************************************************************
DESCRIPTION: This is the header file for the main GUI window that the user sees
			when the application starts up. It provides access to two types of 
			data structures namely, doubly linked list and 2D array along with 
			various things that one can do to these data structures.
******************************************************************************/

#pragma once


namespace My32to64
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary> 
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the 
	///          'Resource File Name' property for the managed resource compiler tool 
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{	
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			InitializeExtras();
		}
  
	protected:
		void Dispose(Boolean disposing)
		{
			if (disposing && components)
			{
				//components->Dispose();
//				delete components;
			}
			__super::Dispose(disposing);
		}		


	public: void drawList();
	public: void drawArray();
	private: void removeList(); 
	private: void removeArr();

	private: array<System::Windows::Forms::Label^>^ drawLabel;
	//private: array<System::Windows::Forms::TextBox^>^ drawLabel;
	private: array<System::Windows::Forms::TextBox^>^ arrLabel;
	private: array<System::Windows::Forms::Label^>^ arrow;
	private: System::Windows::Forms::Label^ head;
	private: System::Windows::Forms::Label^ tail;
	private: System::Windows::Forms::Label^ diff;
	private: System::Windows::Forms::Label^ nullLabel;

	private: System::Windows::Forms::TabControl^  tabControl1;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button5;
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
		void InitializeComponent(void)
		{
			this->tabControl1 = gcnew System::Windows::Forms::TabControl();
			this->tabPage1 = gcnew System::Windows::Forms::TabPage();
			this->button4 = gcnew System::Windows::Forms::Button();
			this->button3 = gcnew System::Windows::Forms::Button();
			this->button2 = gcnew System::Windows::Forms::Button();
			this->button1 = gcnew System::Windows::Forms::Button();
			this->tabPage2 = gcnew System::Windows::Forms::TabPage();
			this->button8 = gcnew System::Windows::Forms::Button();
			this->button7 = gcnew System::Windows::Forms::Button();
			this->button6 = gcnew System::Windows::Forms::Button();
			this->button5 = gcnew System::Windows::Forms::Button();
			this->label1 = gcnew System::Windows::Forms::Label();
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->SuspendLayout();
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Location = System::Drawing::Point(0, 5);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(491, 60);
			this->tabControl1->TabIndex = 0;
			this->tabControl1->Selected += gcnew System::Windows::Forms::TabControlEventHandler(this, &Form1::tabPage1_Click);
			this->tabPage1->Controls->Add(this->button4);
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->button2);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(483, 34);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Doubly Linked List";
			this->button4->Location = System::Drawing::Point(325, 6);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(151, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Left Shift Elements";
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			this->button3->Location = System::Drawing::Point(219, 6);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(87, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Sort the List";
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			this->button2->Location = System::Drawing::Point(105, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(92, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Delete Element";
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			this->button1->Location = System::Drawing::Point(8, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(80, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Add Element";
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			this->tabPage2->Controls->Add(this->button8);
			this->tabPage2->Controls->Add(this->button7);
			this->tabPage2->Controls->Add(this->button6);
			this->tabPage2->Controls->Add(this->button5);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(483, 34);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"2D Array";
			this->button8->Location = System::Drawing::Point(318, 5);
			this->button8->Name = L"button8";
			this->button8->TabIndex = 3;
			this->button8->Text = L"Sort Columns";
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			this->button7->Location = System::Drawing::Point(220, 5);
			this->button7->Name = L"button7";
			this->button7->TabIndex = 2;
			this->button7->Text = L"Sort Rows";
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			this->button6->Location = System::Drawing::Point(104, 5);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(92, 23);
			this->button6->TabIndex = 1;
			this->button6->Text = L"Delete Element";
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			this->button5->Location = System::Drawing::Point(8, 5);
			this->button5->Name = L"button5";
			this->button5->TabIndex = 0;
			this->button5->Text = L"Add Element";
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			this->label1->AutoSize = true;
			this->label1->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
			this->label1->Location = System::Drawing::Point(this->Bottom); 
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 14);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Time ";
			this->label1->MouseLeave += gcnew System::EventHandler(this, &Form1::label1_Leave);
			this->label1->MouseEnter += gcnew System::EventHandler(this, &Form1::label1_Enter);
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->BackColor = System::Drawing::Color::BurlyWood;
			this->ClientSize = System::Drawing::Size(492, 466);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage2->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();
			this->AutoSize = true;

		}	
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
		
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
		 
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
		 
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
		 
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
		 
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
		 
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
		 
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
		 
private: System::Void label1_Enter(System::Object^  sender, System::EventArgs^  e);		 

private: System::Void label1_Leave(System::Object^  sender, System::EventArgs^  e);		 

private: System::Void tabPage1_Click(System::Object^  sender, System::Windows::Forms::TabControlEventArgs^  e);
		
private: void InitializeExtras();
};
}


