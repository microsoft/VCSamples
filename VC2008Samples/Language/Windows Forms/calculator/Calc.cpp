/*=====================================================================
  File:     calc.cpp

  Summary:  The Calculator sample shows some basic user
            interface techniques, implementing a .NET version of a pocket calculator.
---------------------------------------------------------------------
  This file is part of the Microsoft VC++ Code Samples.

  Copyright (c) Microsoft Corporation.  All rights reserved.

This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.
=====================================================================*/

// This is the main project file for VC++ application project 
// generated using an Application Wizard.

#using <mscorlib.dll>
#using <System.dll>
#using <System.Windows.Forms.dll>
#using <System.Drawing.dll>

using namespace System;
using namespace System::IO;
using namespace System::Windows::Forms;
using namespace System::Drawing;

// Calculator class!
ref class Calc : public Form
{
public:
	Calc()
	{
		InitForm();
	}

public:
	enum class Operation
	{
		None = 0,
		Operand,
		Operator,
		CE,
		Cancel
	};

private:
	// Win controls, Icon & Menu
	TextBox^ CalcField;
	array<Button^>^ CalcButtons;
	static String^ s_strZero = String::Format("0{0}0", System::Globalization::NumberFormatInfo::CurrentInfo->NumberDecimalSeparator);
	
	System::Drawing::Icon^ m_pCalcIco;

	MainMenu^ m_pCalcMenu;
	MenuItem^ m_pFileMenu;
	MenuItem^ m_pAboutMenu;
	MenuItem^ m_pExitMenu;

	// Data variables
	double m_Op1, m_Op2;		// Previously input operand.
	int m_NumOps;				// Number of operands.
	Operation m_LastInput;	// Indicate type of last keypress event.
	char m_OpFlag;				// Indicate pending operation.
	char m_OpPrev;				// Previous operation
	String^ m_Minus;			// Just like a #define for "-"

private:
	void InitForm()
	{
		// Properties of form
		this->Text = "Calculator";
		this->MaximizeBox = false;
		this->StartPosition = FormStartPosition::CenterScreen;
		this->AutoScaleBaseSize = Drawing::Size(5, 13);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
		this->Font = gcnew System::Drawing::Font("Arial", 8);
		this->SizeGripStyle = System::Windows::Forms::SizeGripStyle::Hide;
		this->ClientSize = Drawing::Size(226, 211);

		// Assign the Calc icon to the form
		try
		{
			m_pCalcIco = gcnew System::Drawing::Icon("Calc.ico");
			this->Icon = m_pCalcIco;
		}
		catch(FileNotFoundException^ e)
		{
			MessageBox::Show(e->Message, "Calculator");
		}

		// Create the menu items!
		CreateCalcMenu();
		
		// Create the controls and lay them out properly
		CreateControls();

		Reset();

		m_Minus = "-";
	}

	// helper to create menus
	void CreateCalcMenu()
	{
		m_pAboutMenu = gcnew MenuItem("&About Calculator", gcnew EventHandler(this, &Calc::AboutMenu_Click));

		m_pExitMenu	= gcnew MenuItem("E&xit", gcnew EventHandler(this, &Calc::ExitMenu_Click));

		array<MenuItem^>^ rFileItems = gcnew array<MenuItem^>(2);
		
		rFileItems[0] = m_pAboutMenu;
		rFileItems[1] = m_pExitMenu;
		
		m_pFileMenu = gcnew MenuItem("&File", rFileItems);
		
		array<MenuItem^>^ rMainItems = gcnew array<MenuItem^>(1);

		rMainItems[0] = m_pFileMenu;
		
		m_pCalcMenu = gcnew MainMenu(rMainItems);
		
		this->Menu = m_pCalcMenu;
	}

	// helper to create the wincontrols!
	void CreateControls()
	{
		// Create the TextBox and set the properties!
		CalcField = gcnew TextBox();
		CalcField->Location = Point(16, 8);
		CalcField->ReadOnly = true;
		CalcField->TabIndex = 0;
		CalcField->BorderStyle = BorderStyle::FixedSingle;
		CalcField->BackColor = SystemColors::Window;
		CalcField->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		CalcField->TextAlign = HorizontalAlignment::Right;
		CalcField->Text = s_strZero;
		CalcField->Size = Drawing::Size(192, 20);
		CalcField->MaxLength = 0;
		CalcField->KeyPress += gcnew KeyPressEventHandler(this, &Calc::CalcField_KeyPress);
		this->Controls->Add(CalcField);
		
		// Create the buttons and set its props!
		CalcButtons = gcnew array<Button^>(20);
		for (int i = 0; i < 20; i++)
			CalcButtons[i] = gcnew Button();
		
		this->CreateButton(CalcButtons[6], Point(16, 48), 1, "7", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[7], Point(56, 48), 2, "8", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[8], Point(96, 48), 3, "9", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[3], Point(16, 88), 4, "4", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[4], Point(56, 88), 5, "5", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[5], Point(96, 88), 6, "6", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[0], Point(16, 128), 7, "1", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[1], Point(56, 128), 8, "2", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[2], Point(96, 128), 9, "3", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		this->CreateButton(CalcButtons[9], Point(16, 168), 10, "0", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		
		this->CreateButton(CalcButtons[10], Point(56, 168), 11, "+/-", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcSign_Click));
		this->CreateButton(CalcButtons[11], Point(96, 168), 12, System::Globalization::NumberFormatInfo::CurrentInfo->NumberDecimalSeparator, Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcNum_Click));
		CalcButtons[11]->Font = gcnew Drawing::Font("Microsoft Sans Serif", 12, FontStyle::Bold); // special for decimal separator to make it visible

		this->CreateButton(CalcButtons[12], Point(136, 48), 13, "/", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcRes_Click));
		this->CreateButton(CalcButtons[13], Point(136, 88), 14, "*", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcRes_Click));
		this->CreateButton(CalcButtons[14], Point(136, 128), 15, "-", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcRes_Click));
		this->CreateButton(CalcButtons[15], Point(136, 168), 16, "+", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcRes_Click));
		this->CreateButton(CalcButtons[16], Point(176, 48), 17, "CE", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcCE_Click));
		this->CreateButton(CalcButtons[17], Point(176, 88), 18, "C", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcCan_Click));
		this->CreateButton(CalcButtons[18], Point(176, 128), 19, "BS", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcBS_Click));
		this->CreateButton(CalcButtons[19], Point(176, 168), 20, "=", Drawing::Size(30, 30), gcnew EventHandler(this, &Calc::CalcRes_Click));
	}

	// helper to set the props for buttons!
	void CreateButton(Object^ obj, Point ptLoc, int tabIndex, String^ text, Drawing::Size ptSize, EventHandler^ ev)
	{
		Button^ CalcButton = (Button ^)obj;
		
		CalcButton->Location = ptLoc;
		CalcButton->TabIndex = tabIndex;
		CalcButton->Text = text;
		CalcButton->Size = ptSize;
		CalcButton->FlatStyle = FlatStyle::System;
		CalcButton->Click += ev;
		
		this->Controls->Add(CalcButton);
	}

	// helper to format the entry in the text box!
	void FormatEditField(Char newChar)
	{
		String^ strValue = CalcField->Text;
		
		if (strValue->CompareTo(s_strZero) == 0)
			strValue = newChar.ToString();
		else
		{
			// determine if there are more than one .'s
			if (newChar.ToString()->CompareTo(System::Globalization::NumberFormatInfo::CurrentInfo->NumberDecimalSeparator) == 0)
			{
				// if it's found, return
				if (strValue->IndexOf(newChar) != -1)
				{
					// don't do anything
					return;
				}
			}
			strValue = String::Concat(strValue, newChar.ToString());
		}
			
		CalcField->Text = strValue;
	}

	// helper to initialize the vals
	void Reset()
	{
		m_Op1 = 0;
   		m_Op2 = 0;
		
		m_NumOps = 0;
		m_LastInput = Operation::None;
		
		m_OpFlag = ' ';
		m_OpPrev = ' ';
			
		CalcField->Text = s_strZero;
	}

	// cancel click event!
	void CalcCan_Click(Object^, EventArgs^)
	{
		Reset();
	}

	// cancel entry click event!
	void CalcCE_Click(Object^, EventArgs^)
	{
		if (m_LastInput == Operation::Operand)
			CalcField->Text = s_strZero;
		else
			if (m_LastInput == Operation::Operator)
				m_OpFlag = m_OpPrev;
		
		m_LastInput = Operation::CE;
	}

	// +/- click event
	void CalcSign_Click(Object^, EventArgs^)
	{
        if (CalcField->Text[0] == '-')
			CalcField->Text = CalcField->Text->TrimStart(m_Minus->ToCharArray());
		else
			CalcField->Text = String::Concat(m_Minus, CalcField->Text);
		
		m_LastInput = Operation::Operand;
	}

	// BS click event
	void CalcBS_Click(Object^, EventArgs^)
	{
		String^ strValue = CalcField->Text;
		
		if ((strValue->CompareTo(s_strZero) != 0) && (strValue->Length != 0))
			strValue = strValue->Remove(strValue->Length - 1, 1);

		if ((strValue->Length == 0) || ((strValue->Length == 1) && (strValue[0] == '-')))
			strValue = s_strZero;
			
		CalcField->Text = strValue;
	}

	// +, -, *, /, = click event!
	void CalcRes_Click(Object^ sender, EventArgs^)
	{
		if (CalcField->Text->Length == 0)
			return;
				
		if (m_LastInput == Operation::Operand)
			m_NumOps = m_NumOps + 1;

		switch (m_NumOps)
		{
			case 1:
				m_Op1 = Convert::ToDouble(CalcField->Text);
				break;
			case 2:
				m_Op2 = Convert::ToDouble(CalcField->Text);
				switch (m_OpFlag)
				{
					case '+':
				        m_Op1 = m_Op1 + m_Op2;
						break;
						
					case '-':
				        m_Op1 = m_Op1 - m_Op2;
						break;
						
					case '*':
				        m_Op1 = m_Op1 * m_Op2;
						break;
						
					case '/':
				        if (m_Op2 == 0)
							MessageBox::Show("Can't divide by zero!", "Calculator");
				        else
				        	m_Op1 = m_Op1 / m_Op2;
						break;
						
					case '=':
				    	m_Op1 = m_Op2;
						break;
				}
				
				CalcField->Text = m_Op1.ToString();
				m_NumOps = 1;
				break;
		}

		m_LastInput = Operation::Operator;
		m_OpPrev = m_OpFlag;
		m_OpFlag = (char)(((Button^)sender)->Text[0]);
	}

	// 0 - 9, ., click event
	void CalcNum_Click(Object^ sender, EventArgs^)
	{
		if (m_LastInput != Operation::Operand)
			CalcField->Text = s_strZero;

		FormatEditField(((Button^)sender)->Text[0]);

		m_LastInput = Operation::Operand;
	}

	// edit field key press event
	void CalcField_KeyPress(Object^, KeyPressEventArgs^ e)
	{
		// I have made this field readonly...
		// so you can add only thru buttons in the calc!
	
		// don't let the user enter anything else
		// besides numerics & decimal
		 //if ((e->KeyChar >= 48 && e->KeyChar <= 57) || (e->KeyChar == 46))
		//	FormatEditField(e->KeyChar);
	
		e->Handled = true;
		return;
	}

	// About menu handler!
	void AboutMenu_Click(Object^, EventArgs^)
	{
		MessageBox::Show("Version 1.1\nDeveloped by Beta Support Group - Visual Studio .NET\nMicrosoft Corporation", "Calculator");
	}
	
	// Exit menu handler!
	void ExitMenu_Click(Object^, EventArgs^)
	{
		Application::Exit();
	}
};

// This is the entry point for this application
int main(void)
{
	Application::Run(gcnew Calc());

	return 0;
}
