/******************************************************************************
DESCRIPTION: This is the implementation file for the pop up that shows up 
			when the user clicks Add Element button under the Doubly Linked
			List tab.			
******************************************************************************/

#include "StdAfx.h"
#include "AddElem.h"
#include "Form1.h"
#include "Error.h"

#include "List.h"

using namespace My32to64;


extern List* l;

// This method is called when the user clicks the OK button
System::Void AddElem::button1_Click(System::Object^  , System::EventArgs^  ){


	int num = 0;
	int pos = 0;

	try{
		// if the user has entered a number/value to be added
		if(textBox1->Text != ""){
			
			// get the number the user has entered
			num = Int32::Parse(textBox1->Text);			

			// if the user has entered a position at which the number/value has to be added
			if(textBox2->Text != ""){
			
				// get the position the user has entered
				pos = Int32::Parse(textBox2->Text);	

				// if the user entered a invalid position then show a error message
				if(pos > l->totElements || pos < 0){
					Error^ e = gcnew Error(String::Concat("Please enter a position greater than 0 or less than or equal to ", l->totElements.ToString()));
					e->ShowDialog(this);
					textBox1->Text = "";
					textBox2->Text = "";
				}
			}	
			// if the user did not enter a position, then add the element to the end of the list
			else if(textBox2->Text == ""){
				pos = l->totElements;
			}
		
			//should call this only if we get good input
			l->addElement(num, pos);
		}

		textBox1->Text = "";
		textBox2->Text = "";
	}
	catch(Exception^){
		
		// if the user has entered an invalid input like a string instead of a number
		// then give this error message.
		
		Error^ e = gcnew Error("Please enter a number and not a string");
		e->ShowDialog(this);
		textBox1->Text = "";
		textBox2->Text = "";
	}	

	// redraw
	((My32to64::Form1^)(this->Owner))->drawList();
}

// if the user has hit close, then just close this pop up
System::Void AddElem::button2_Click(System::Object^  , System::EventArgs^  ){
	Close();
}
