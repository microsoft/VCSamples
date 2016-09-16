/******************************************************************************
DESCRIPTION: This is the implementation file for the pop up that shows up 
			when the user clicks Delete Element button under the 2D Array tab.			
******************************************************************************/

#include "stdafx.h"
#include "DelArray.h"
#include "Error.h"
#include "Form1.h"
using namespace My32to64;

#include "Array2D.h"
extern Array2D* arr;

// if the user has hit close, then just close this pop up
System::Void DelArray::button2_Click(System::Object^  , System::EventArgs^  ){
	Close();
}
			 
// This method is called when the user clicks the OK button
System::Void DelArray::button1_Click(System::Object^  , System::EventArgs^  ){
	
	int row = 0;
	int col = 0;
	
	// if the user has entered some input
	if(textBox2->Text != "" && textBox3->Text != ""){
		try{
			
			// get the row and the column from which the element has to be deleted.
			row = Int32::Parse(textBox2->Text);				
			col = Int32::Parse(textBox3->Text);
			if(row < 10 && col < 10){
				//should call this only if we get good input			
				arr->delElement(row, col);
			}
			else{
				// since the 2D array is a 10 X 10 array, tell the user to enter
				// the row and column values to be less than 10.
				// This error message shows up only if the user has entered bad input
				// in the form of bad row/col
				Error^ e = gcnew Error("Enter row and column to be less than 10");
				e->ShowDialog(this);
				textBox2->Text = "";
				textBox3->Text = "";
			}			
			textBox2->Text = "";
			textBox3->Text = "";		

		}
		catch(Exception^ ){
						
			// if the user has not entered a number for both row/column we give this error message
			Error^ e = gcnew Error("Please enter a number not a string");
			e->ShowDialog(this);
			
			textBox2->Text = "";
			textBox3->Text = "";
		}
	}
	// redraw
	((My32to64::Form1^)(this->Owner))->drawArray();
}