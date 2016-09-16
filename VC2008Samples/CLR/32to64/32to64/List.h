/******************************************************************************
DESCRIPTION: This is the header file that contains the head and tail pointers
			into the doubly linked list along with the total number of elements
			in the list.
			Using the head/tail pointers one can access all the elements in the
			list.
******************************************************************************/

#include "stdafx.h"
#include "Element.h"
#include <string.h>

//using namespace std;

public class List{
private:
	Element* head;	
	Element* tail;
	
public:
	static int totElements;

	List();
	Element* getHead();
	Element* getTail();
	bool addElement(int value, int pos);
	bool delElement(int pos);
	void sortList();	
	void shiftElems();
};
