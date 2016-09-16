/******************************************************************************
DESCRIPTION: This is the implementation file to store the elements entered by 
			the user into a 2D Array. 
******************************************************************************/

#include "stdafx.h"
#include "List.h"
#include "Array2D.h"

using namespace System;
using namespace MS::Internal::Xml;

// Create a 2D Array of char*s and allocate some space to it.
// This is called by the main() function in 32to64.cpp to declare and initialize a 2D array
Array2D::Array2D(){
	size = 10;	

#ifndef _WIN64
	if((this->elem = (char ***)malloc(sizeof(int) * size)) == NULL)
		exit(1);
	for(int i = 0; i < size; ++i){
		if((this->elem[i] = (char **)malloc(sizeof(int) * size)) == NULL)
			exit(1);				
		for(int j = 0; j < size; ++j){
			if((this->elem[i][j] = (char *)malloc(sizeof(int) * size)) == NULL)
				exit(1);
			memset(this->elem[i][j], '\0', 10);	
		}
	
	}		

#else 
	if((this->elem = (char ***)malloc(sizeof(char **) * size)) == NULL)
		exit(1);
	for(int i = 0; i < size; ++i){
		if((this->elem[i] = (char **)malloc(sizeof(char *) * size)) == NULL)
			exit(1);				
		for(int j = 0; j < size; ++j){
			if((this->elem[i][j] = (char *)malloc(sizeof(char) * size)) == NULL)
				exit(1);
			memset(this->elem[i][j], '\0', size);	
		}
	
	}

#endif

}

// adds an element into the two dimensional array
#ifndef _WIN64
void Array2D::addElement(int value, int row, int col)
#else
void Array2D::addElement(char* value, int row, int col)
#endif
{		
	strcpy_s(this->elem[row][col], 10, (char*)value);

}

// deletes an element into the two dimensional array
void Array2D::delElement(int row, int col){
	this->elem[row][col] = "";
}

// sorts the rows in the two dimensional array using bubble sort
// sorting happens based on the length of the elements in the array
// this sorts each row individually
void Array2D::sortRow(){

	char* temp = (char*) malloc(sizeof(char) * 10);
	memset(temp, '\0', 10);
	int len1 = 0;
	int len2 = 0;
	// for each row
	for(int k = 0; k < size; k++){
		// sort the elements in the row using bubble sort based on their lengths
		for(int i = 0; i < size-1; i++){
			for(int j = 0; j < size-1-i; j++){
				if(this->elem[k][j+1] == NULL){
					len1 = 0;
					if(this->elem[k][j] == NULL){
						len2 = 0;
					}
					else{
						len2 = strlen(this->elem[k][j]);
					}

				}
				else{
					len1 = strlen(this->elem[k][j+1]);
					if(this->elem[k][j] == NULL){
						len2 = 0;
					}
					else{
						len2 = strlen(this->elem[k][j]);
					}

				}
				// call the compare function to check if the two elements need a swap
				if(compare(len1, len2)){			
	
					strcpy_s(temp, 10, this->elem[k][j]); 					
					strcpy_s(this->elem[k][j], 10, this->elem[k][j+1]); 
					strcpy_s(this->elem[k][j+1], 10, temp); 
				
					memset(temp, '\0', 10);

				}
			}
		}
	}
	
}

// sorts the rows in the two dimensional array using bubble sort
// sorting happens based on the length of the elements in the array
// this sorts each row individually
void Array2D::sortCol(){

	char* temp = (char*) malloc(sizeof(char) * 10);
	memset(temp, '\0', 10);
	int len1 = 0;
	int len2 = 0;
	// for each row
	for(int k = 0; k < size; k++){
		// sort the elements in the row using bubble sort based on their lengths
		for(int i = 0; i < size-1; i++){
			for(int j = 0; j < size-1-i; j++){
				if(this->elem[j+1][k] == NULL){
					len1 = 0;
					if(this->elem[j][k] == NULL){
						len2 = 0;
					}
					else{
						len2 = strlen(this->elem[j][k]);
					}

				}
				else{
					len1 = strlen(this->elem[j+1][k]);
					if(this->elem[j][k] == NULL){
						len2 = 0;
					}
					else{
						len2 = strlen(this->elem[j][k]);
					}

				}
				// call the compare function to check if the two elements need a swap
				if(compare(len1, len2)){								
					// this is used to show the alignment fault over the IA 64 bit machine
#ifndef _WIN64
					int *xVal;				
#else 
					__unaligned int *xVal;
#endif
										
					for(unsigned int p = 0; p < strlen(this->elem[j][k]); p++){
						xVal = (int *)&this->elem[j][k][p];
						temp[p] = (char)*xVal;

					}					 					

					strcpy_s(this->elem[j][k], 10, this->elem[j+1][k]); 
					strcpy_s(this->elem[j+1][k], 10, temp); 
				
					memset(temp, '\0', 10);

				}
			}
		}
	}
	
}

int Array2D::getSize(){
	return this->size;
}

char* Array2D::getElem(int row, int col){
	return elem[row][col];
}

#ifndef _WIN64
bool Array2D::compare(int size1, int size2)
#else 
bool Array2D::compare(size_t size1, size_t size2)
#endif
{
	if(size1 >= size2) return false;
	else 
		return true;
}
