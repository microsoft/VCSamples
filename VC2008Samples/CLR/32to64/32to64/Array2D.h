/******************************************************************************
DESCRIPTION: This is the header file for the class that stores the elements 
			that are currently present in the 2D array.
******************************************************************************/

#include "stdafx.h"



public class Array2D{
private:

public:	
	char ***elem;
	int size;


	Array2D();
	int getSize();
	char* getElem(int row, int col);
	
#ifndef _WIN64
	void addElement(int value, int row, int col);
#else 
	void addElement(char* value, int row, int col);
#endif

	
	void delElement(int row, int col);
	void sortRow();
	void sortCol();

#ifndef _WIN64
	bool compare(int size1, int size2);
#else 
	bool compare(size_t size1, size_t size2);
#endif
	
};