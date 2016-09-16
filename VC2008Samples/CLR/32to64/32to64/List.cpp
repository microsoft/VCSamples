/******************************************************************************
DESCRIPTION: This is the implementation file that contains the head and tail 
			pointers into the doubly linked list along with the total number of 
			elements in the list.
			Using the head/tail pointers one can access all the elements in the
			list.
******************************************************************************/
#include "stdafx.h"
#include "List.h"

using namespace System;
using namespace MS::Internal::Xml;


int List::totElements = 0;

// constructor
List::List(){
		
	this->head = (int)0;
	this->tail = (int)0;
	
}

// add an element to the list
bool List::addElement(int value, int pos){
	Element* e = new Element();
	e->setValue(value);
	bool add = false;

	if(NULL == head && pos == 0){	// if there are no elements in the list
	//if(0 == head && pos == 0){
		e->setNext(0);
		e->setPrev(0);
		head = e;
		tail = e;
		add = true;
		totElements++;
	}
	else if(NULL == head && (pos > 0 || pos < 0)){
	//else if(0 == head && (pos > 0 || pos < 0)){
		add = false;
	}
	else if(NULL != head ){
	//else if(0 != head ){
		if(pos > totElements+1 || pos < 0){
			add = false;
		}
		else{
			Element* temp = head;					

			if(pos != 0 && pos < totElements){ // to insert anywhere else
				for(int i = 0; i < pos-1; i++, temp = temp->getNext());

				Element* nextElem = temp->getNext(); 
				temp->setNext(e);
				e->setNext(nextElem);
				e->setPrev(temp);
				temp->getNext()->setPrev(e);
				
			}
			else if(pos == 0){ // to insert at the beginning of the list
				temp->setPrev(e);
				e->setNext(temp);				
				e->setPrev(0);
				head = e;
			}
			else if(pos == totElements){ // to insert at the end of the list
				for(int i = 0; i < pos-1; i++, temp = temp->getNext());
				e->setNext(0);
				e->setPrev(temp);
				temp->setNext(e);				
				tail = e;
			}
			add = true;
			totElements++;
			
		}
	}
	
	return add;	
}

// delete an element from the list
bool List::delElement(int pos){
	bool del = false;
	if(head == NULL || pos >= totElements){
		del = false;
	}
	else if(head->getNext() == NULL){ // there is only one element in the list
		
		head = NULL;
		tail = NULL;
		del = true;
		totElements--;
	}
	else{ // if there are more elements in the list
		if(pos < totElements && totElements != 0){
			Element* temp = head;
			if(pos == 0){ // delete the first element
				head = temp->getNext();
				head->setPrev(NULL);
				temp->setNext(NULL);
				
			}
			else if(pos == totElements-1){ // delete the last element
				for(int i = 0; i < pos; i++, temp = temp->getNext());
				
				tail = temp->getPrev();
				Element* prevElem = temp->getPrev();
				prevElem->setNext(NULL);
				temp->setPrev(NULL);				


			}
			else{ // for anything in the middle
				for(int i = 0; i < pos; i++, temp = temp->getNext());

				
				temp->getPrev()->setNext(temp->getNext());
				temp->getNext()->setPrev(temp->getPrev());
				temp->setPrev(NULL);
				temp->setNext(NULL);

			}
			del = true;
			totElements--;
			delete temp;
		}
	}
	
	return del;
}

// sort the list using bubble sort
void List::sortList(){
	Element *e1 = head;
	Element *e2 = head;

	
	int temp;


	for(int i = 0; i < totElements-1; i++){
		for(int j = 0; j < totElements-1-i; j++){
			if(e2->getNext()->getValue() < e2->getValue()){
				temp = e2->getValue();
				e2->setValue(e2->getNext()->getValue());
				e2->getNext()->setValue(temp);
			}
			e2 = e2->getNext();
		}
		e1 = e1->getNext();
		e2 = head;
	}	
	return;
}

// returns the head of the list
Element* List::getHead(){
	return head;
}

// returns the tail of the list
Element* List::getTail(){
	return tail;
}

// left shift the elements in the list
void List::shiftElems(){
	Element* temp = head;
	string listContents = "";
	
	int val;
	while(temp != NULL){
		val =  temp->getValue() << 1;
	
		temp->setValue(val);
		temp = temp->getNext();
	}	
}