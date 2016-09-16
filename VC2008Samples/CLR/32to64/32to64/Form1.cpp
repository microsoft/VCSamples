/******************************************************************************
DESCRIPTION: This is the implementation file for the main GUI window that the 
			user sees when the application starts up. It provides access to two 
			types of data structures namely, doubly linked list and 2D array 
			along with various things that one can do to these data structures.
******************************************************************************/

#include "stdafx.h"
#include "Form1.h"
#include "DelElem.h"
#include "AddElem.h"
#include "List.h"
#include "AddArray.h"
#include "DelArray.h"
#include "Array2D.h"
#include <string>
#include <time.h>

using namespace std;
using namespace My32to64;

extern List* l;
extern Array2D* arr;

// based on what tab is clicked, draw that data structure
System::Void Form1::tabPage1_Click(System::Object^  sender, System::Windows::Forms::TabControlEventArgs^  )
{
	if(((System::Windows::Forms::TabControl^)sender)->SelectedIndex == 0){
		drawList();
	}
	else if(((System::Windows::Forms::TabControl^)sender)->SelectedIndex == 1){
		drawArray();
	}
}

// show the pop up for add element to a doubly linked list
// then redraw
System::Void Form1::button1_Click(System::Object^ , System::EventArgs^  )
{			 
	AddElem^ a = gcnew AddElem();
	a->ShowDialog(this);
	drawList();	
}

// show the pop up for delete element from a doubly linked list
// then redraw
System::Void Form1::button2_Click(System::Object^ , System::EventArgs^ )
{
	DelElem^ d = gcnew DelElem();
	d->ShowDialog(this);
	drawList();
}

// sort the elements in the doubly linked list
// then redraw
System::Void Form1::button3_Click(System::Object^ , System::EventArgs^  )
{
	//sort the list
	l->sortList();
	drawList();
}

// left shift the elements in the doubly linked list
// then redraw
System::Void Form1::button4_Click(System::Object^  , System::EventArgs^  )
{
	l->shiftElems();	
	drawList();
}

// show the pop up for add element to a 2D Array
// then redraw
System::Void Form1::button5_Click(System::Object^  , System::EventArgs^  )
{
	AddArray^ a = gcnew AddArray();
	a->ShowDialog(this);
	drawArray();
}

// show the pop up for delete element from a 2D Array
// then redraw
System::Void Form1::button6_Click(System::Object^  , System::EventArgs^  )
{
	DelArray^ d = gcnew DelArray();
	d->ShowDialog(this);
	drawArray();
}

// sort all the rows in the 2D Array
// then redraw
System::Void Form1::button7_Click(System::Object^  , System::EventArgs^  )
{
	//sort the rows
	arr->sortRow();
	drawArray();
}

// sort all the columns in the 2D Array
// then redraw
System::Void Form1::button8_Click(System::Object^  , System::EventArgs^  )
{
	//sort the columns
	arr->sortCol();
	drawArray();
}

// if the mouse enters the time label then get the current time
// then show the current time
System::Void Form1::label1_Enter(System::Object^  , System::EventArgs^  )
{
	//show time
	/*************************
	__time32_t t;
	struct tm *localt;
	_time32(&t);
	localt = _localtime32(&t);
	**************************/
	
	time_t t;
	struct tm *localt;
	time(&t);
	localt = localtime(&t);	// get the current time
	
	/*************************
	__time64_t t;
	struct tm *localt;
	_time64(&t);
	localt = _localtime64(&t);
	**************************/

	// format the date and time
	String^ hrStr = localt->tm_hour.ToString();
	String^ minStr = localt->tm_min.ToString();
	String^ secStr = localt->tm_sec.ToString();	
	String^ mStr = (1+localt->tm_mon).ToString();
	String^ dStr = localt->tm_mday.ToString();
	String^ yStr = (1900+localt->tm_year).ToString();

	// show the date and time
	this->label1->Text = String::Concat(mStr, "/", dStr, "/", yStr, "    ", hrStr, ":", minStr, ":", secStr);
	
}

// if the mouse leaves the time label then change the label back to "Time"
System::Void Form1::label1_Leave(System::Object^  , System::EventArgs^  )
{
	//show time
	this->label1->Text = L"Time";
	

}

// This method is used to draw the doubly linked list
void Form1::drawList(){
	
	// first clear the form
	removeList();	
	
	// get the location where the head is pointing to
	Element* temp = l->getHead();
	string listContents = "";
	
	int i = 0;
	int j = 0;
	int k = 0;
	
	while(temp != 0){
		// add the element from the list to the set of labels and draw it on the form
		drawLabel[k]->AutoSize = true;
		drawLabel[k]->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
		drawLabel[k]->Location = System::Drawing::Point(28+i, 72+j);
		drawLabel[k]->Name = L"label2";
		drawLabel[k]->Size = System::Drawing::Size(90, 17);
		drawLabel[k]->TabIndex = 7;		
		drawLabel[k]->BackColor = Color::Beige;
		String^ str = ((temp->getValue()).ToString());
		
		drawLabel[k]->Text = str;
		arrow[k]->BorderStyle = BorderStyle::Fixed3D;
		this->Controls->Add(drawLabel[k]);

		i += drawLabel[k]->Width + 10;

		// add the arrow 
		arrow[k]->AutoSize = true;
		arrow[k]->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
		arrow[k]->Location = System::Drawing::Point(28+i, 72+j);
		arrow[k]->Name = L"label3";
		arrow[k]->Size = System::Drawing::Size(30, 17);
		arrow[k]->TabIndex = 7;				
		arrow[k]->BorderStyle = BorderStyle::None;
		String^ arr = "<-->";
		arrow[k]->Text = arr; //L"<->";
		this->Controls->Add(arrow[k]);

		// to wrap around
		if(i >= 390) {
			i = 0;
			j += 25;
		}		
		else {
			i += arrow[k]->Width + 20;
		}
		temp = temp->getNext();
		k++;		
	}

	// add the null label at the end
	nullLabel->AutoSize = true;
	nullLabel->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
	nullLabel->Location = System::Drawing::Point(28+i, 72+j);
	nullLabel->Name = L"label4";
	nullLabel->Size = System::Drawing::Size(20, 17);
	nullLabel->TabIndex = 7;	
	nullLabel->BackColor = Color::Beige;
	nullLabel->BorderStyle = BorderStyle::Fixed3D;
	nullLabel->Text = L"/";
	this->Controls->Add(nullLabel);

	// set up the label which tells where the head is pointing to
	head->AutoSize = true;
	head->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
	head->Location = System::Drawing::Point(28, 72+j+40);
	head->Name = L"label5";
	head->Size = System::Drawing::Size(700, 17);
	head->TabIndex = 7;		
	head->BackColor = Color::Beige;
	head->BorderStyle = BorderStyle::Fixed3D;
	
	// set up the label which tells where the tail is pointing to
	tail->AutoSize = true;
	tail->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
	tail->Location = System::Drawing::Point(28, 72+j+80);
	tail->Name = L"label6";
	tail->Size = System::Drawing::Size(700, 17);
	tail->TabIndex = 7;		
	tail->BackColor = Color::Beige;
	tail->BorderStyle = BorderStyle::Fixed3D;
	
	// set up the label which tells where the difference between the head and tail 
	// pointing to locations
	diff->AutoSize = true;
	diff->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
	diff->Location = System::Drawing::Point(28, 72+j+120);
	diff->Name = L"label7";
	diff->Size = System::Drawing::Size(700, 17);
	diff->TabIndex = 7;		
	diff->BackColor = Color::Beige;
	diff->BorderStyle = BorderStyle::Fixed3D;
	
	char* headptr = (char*)malloc(sizeof(char) * 100);
	Element* h = l->getHead();
	char* tailptr = (char*)malloc(sizeof(char) * 100);
	Element* t = l->getTail();
	char* diffptr = (char*)malloc(sizeof(char) * 100);


	
#ifndef _WIN64
	int hadd = (int)&h;
	int tadd = (int)&t;		
	
	if(h == NULL) sprintf_s(headptr, 100, "Head is pointing to address: null and Address of head is: %x \0.", &h);	
	else sprintf_s(headptr, 100, "Head is pointing to address: %x and Address of head is: %x \0.", h, hadd);
	
	if(t == NULL) sprintf_s(tailptr, 100, "Tail is pointing to address: null and Address of tail is: %x .", tadd);	
	else sprintf_s(tailptr, 100, "Tail is pointing to address: %x and Address of tail is: %x .", t, tadd);

	int d = h-t;
	if(t == NULL && h == NULL) sprintf_s(diffptr, 100, "Difference between where head and tail pointers point to is: 0. \n");	
	else sprintf_s(diffptr, 100, "Difference between where head and tail pointers point to is: %x .", d);

#else 
	if(h == NULL) sprintf_s(headptr, 100, "Head is pointing to address: null and Address of head is: %p .", &h);	
	else sprintf_s(headptr, 100, "Head is pointing to address: %p and Address of head is: %p .", h, &h);
	
	if(t == NULL) sprintf_s(tailptr, 100, "Tail is pointing to address: null and Address of tail is: %p .", &t);	
	else sprintf_s(tailptr, 100, "Tail is pointing to address: %p and Address of tail is: %p .", t, &t);

	ptrdiff_t d = h-t;
	if(t == NULL && h == NULL) sprintf_s(diffptr, 100, "Difference between where head and tail pointers point to is: 0. \n");	
	else sprintf_s(diffptr, 100, "Difference between where head and tail pointers point to is: %p .", d);

#endif	
	
	// add text to the head, tail and diff labels
	String^ str1 = gcnew String(headptr);
	//String::Concat(str1, "hello");
	head->Text = str1;
	head->AutoSize = true;
	this->Controls->Add(head);

	String^ str2 = gcnew String(tailptr);
	tail->Text = str2;
	this->Controls->Add(tail);

	String^ str3 = gcnew String(diffptr);
	diff->Text = str3;
	this->Controls->Add(diff);

	free(headptr);
	free(tailptr);
	free(diffptr);
}

// This method is used to draw the 2D array
void Form1::drawArray(){

	removeArr();		
	int size = arr->getSize();
	int k = 0;
	int a = 0;
	int b = 0;

	char* charstr = (char *)malloc(sizeof(int) * 10);
	int maxWidth = 0;
	System::Windows::Forms::Label^ tempLabel = gcnew System::Windows::Forms::Label();	
	for(int p = 0; p < size; p++){
		for(int q = 0; q < size; q++){			
			strcpy_s(charstr, 10, arr->getElem(p, q));
			strcat_s(charstr, 10, " ");
			String^ str = gcnew String(charstr);
			tempLabel->Text = str;
			if(tempLabel->Width > maxWidth)
				maxWidth = tempLabel->Width;			
		}		
	}

	// draw the array
	for(int i = 0; i < size; i++){
		for(int j = 0; j < size; j++){			
			arrLabel[k]->AutoSize = true;
			arrLabel[k]->Font = gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10);
			arrLabel[k]->Location = System::Drawing::Point(28+a, 72+b);
			arrLabel[k]->Name = L"label2";
			arrLabel[k]->Size = System::Drawing::Size(60, 17);
			arrLabel[k]->TabIndex = 7;			
			arrLabel[k]->BackColor = Color::Beige;
			arrLabel[k]->BorderStyle = BorderStyle::Fixed3D;
			
			// get the element and make it as the text to be displayed
			strcpy_s(charstr, 10, arr->getElem(i, j));
			strcat_s(charstr, 10, " ");
			String^ str = gcnew String(charstr);
			arrLabel[k]->Text = str;
			

			this->Controls->Add(arrLabel[k]);						

			// to wrap around
			if(j%10 == 9){
				a = 0;
				b += 35;
			}
			else{
				a += maxWidth + 10; 
				
			}
			k++;
		}
	}
	free(charstr);
}

// clear up the form
void Form1::removeList(){
	for(int i = 0; i < 100; i++){
		this->Controls->Remove(drawLabel[i]);
		this->Controls->Remove(arrLabel[i]);
		this->Controls->Remove(arrow[i]);
		this->Controls->Remove(nullLabel);		
		this->Controls->Remove(head);
		this->Controls->Remove(tail);
		this->Controls->Remove(diff);
	}
}

// clear up the form
void Form1::removeArr(){
	for(int i = 0; i < 100; i++){
		this->Controls->Remove(drawLabel[i]);
		this->Controls->Remove(arrLabel[i]);
		this->Controls->Remove(arrow[i]);
		this->Controls->Remove(nullLabel);		
		this->Controls->Remove(head);
		this->Controls->Remove(tail);
		this->Controls->Remove(diff);
	}
}

// some other initializations
void Form1::InitializeExtras(){
	drawLabel = gcnew array<System::Windows::Forms::Label^>(100);
	for(int a = 0; a < 100; a++)
		drawLabel[a] = gcnew System::Windows::Forms::Label();

	arrLabel = gcnew array<System::Windows::Forms::TextBox^>(100);
	for(int a = 0; a < 100; a++)
		arrLabel[a] = gcnew System::Windows::Forms::TextBox();

	arrow = gcnew array<System::Windows::Forms::Label^>(100);
	for(int b = 0; b < 100; b++)
		arrow[b] = gcnew System::Windows::Forms::Label();

	nullLabel = gcnew System::Windows::Forms::Label();
	head = gcnew System::Windows::Forms::Label();	
	//head->AutoSize = true;
	tail = gcnew System::Windows::Forms::Label();
	diff = gcnew System::Windows::Forms::Label();
}
