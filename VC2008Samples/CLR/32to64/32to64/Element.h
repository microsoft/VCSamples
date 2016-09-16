/******************************************************************************
DESCRIPTION: This is the header file for storing the values of each element 
			along with the previous and next pointers of that element in the 
			doubly linked list. 
******************************************************************************/

// added now
#include "stdafx.h"

// A union of int and int*.
// This forms the element in the doubly linked list
union Mask
{
	
	int val;
	int *pval;
};

// A class that stores the element, its next and previous pointers to 
// other elements in the doubly linked list
public class Element{
private:
	Mask value;

	Element* next;
	Element* prev;

public:
	Element();
	
	int getValue();
	Element* getNext();
	Element* getPrev();

	
	void setValue(int value);
	void setNext(Element* next);
	void setPrev(Element* prev);
};

