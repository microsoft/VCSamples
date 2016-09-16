/******************************************************************************
DESCRIPTION: This is the implementation file for the pop up that shows up 
			when the user clicks Delete Element button under the Doubly Linked
			List tab.			
******************************************************************************/

#include "StdAfx.h"
#include "DelElem.h"
#include "Error.h"
#include "List.h"
#include "Form1.h"
using namespace My32to64;


extern List* l;

System::Void DelElem::button1_Click(System::Object^  , System::EventArgs^  ){
	int pos = 0;
	// if the user has entered an input
	if(textBox2->Text != ""){
		try{
			// get the position that the user wants to delete the element from
			pos = Int32::Parse(textBox2->Text);			
			// if the user entered a invalid position then show a error message
			if(pos >= l->totElements || pos < 0){
				Error^ e = gcnew Error(String::Concat("Please enter a position greater than 0 or less than or equal to ", l->totElements.ToString()));
				e->ShowDialog(this);				
				
			}
			else{
				l->delElement(pos);
			}
			textBox2->Text = "";			
		}
		catch(Exception^){
			
			
			// if the user has entered an invalid input like a string instead of a number
			// then give this error message.
			Error^ e = gcnew Error("Please enter a number not a string");
			e->ShowDialog(this);
			textBox2->Text = "";
		}
	}	
	// redraw
	((My32to64::Form1^)(this->Owner))->drawList();
}

// if the user has hit close, then just close this pop up
System::Void DelElem::button2_Click_1(System::Object^  , System::EventArgs^  ){
	Close();
}

