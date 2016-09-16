/******************************************************************************
DESCRIPTION: This is the implementation file for storing the values of each element 
			along with the previous and next pointers of that element in the 
			doubly linked list. 
******************************************************************************/

#include "stdafx.h"
#include "Element.h"

// Constructor
Element::Element(){
	this->value.val = NULL;
	
	this->value.pval = (int*)malloc(sizeof(int));
}

// return the value of that particular element
int Element::getValue(){
	return this->value.val;
	
}

// return the next element that this element is pointing to
Element* Element::getNext(){
	return this->next;
}

// return the previous element that this element is pointing to
Element* Element::getPrev(){
	return this->prev;
}

// set the value of the element equal to the value of the passed in argument
void Element::setValue(int value){
	this->value.val = value;	
}

// make this element point to another element as its next element in the list
void Element::setNext(Element* next){
	this->next = next;
}

// make this element point to another element as its previous element in the list
void Element::setPrev(Element* prev){
	this->prev = prev;
}