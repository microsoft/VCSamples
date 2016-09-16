/******************************************************************************
DESCRIPTION: This is the implementation file for the pop up that shows up 
			when the user clicks Add Element button under the 2D Array tab.			
******************************************************************************/

#include "stdafx.h"
#include "AddArray.h"
#include "Error.h"
#include "Form1.h"
using namespace My32to64;
using namespace System::Runtime::InteropServices;

#include "Array2D.h"
extern Array2D* arr; 

// This method is called when the user clicks the OK button
System::Void AddArray::button1_Click(System::Object^  , System::EventArgs^  ){
	char* val= NULL;
	int row = 0;
	int col = 0;
	
	// if the user has entered some input
	if(textBox1->Text != "" && textBox2->Text != "" && textBox3->Text != ""){
		try{			
			// get the char* version of the string input from the string text box.
			val = (char*)(void*)Marshal::StringToHGlobalAnsi(textBox1->Text);
			
			// get the row X col to which the input has to be added.
			row = Int32::Parse(textBox2->Text);				
			col = Int32::Parse(textBox3->Text);

			//should call this only if we get good input			
			if(row < 10 && col < 10){
#ifndef _WIN64
				arr->addElement((int)val, row, col);
#else
				arr->addElement(val, row, col);
#endif
				textBox1->Text = "";
				textBox2->Text = "";
				textBox3->Text = "";	
			}
			else{
				// since the 2D array is a 10 X 10 array, tell the user to enter
				// the row and column values to be less than 10.
				// This error message shows up only if the user has entered bad input
				// in the form of bad row/col
				Error^ e = gcnew Error("Enter row and column to be less than 10");
				e->ShowDialog(this);
				textBox1->Text = "";
				textBox2->Text = "";
				textBox3->Text = "";
			}

		}
		catch(Exception^){
			
			// if the user has entered an invalid input like a string instead of a number
			// then give this error message.
			Error^ e = gcnew Error("Please enter a number not a string"); 
			e->ShowDialog(this);
			textBox1->Text = "";
			textBox2->Text = "";
			textBox3->Text = "";
		}
	}
	Marshal::FreeHGlobal((IntPtr)val);
	
	// redraw
	((My32to64::Form1^)(this->Owner))->drawArray();
}

// if the user has hit close, then just close this pop up
System::Void AddArray::button2_Click(System::Object^  , System::EventArgs^  ){
	Close();
}
			 
