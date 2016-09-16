/******************************************************************************
DESCRIPTION: This is the implementation file and acts as a start up for the 
			entire application. 
******************************************************************************/

#include "stdafx.h"
#include "Form1.h"
#include "List.h"
#include "Array2D.h"
using namespace My32to64;

// declaration of two global variables that can be used in the implementation
// of a list and a 2D array
List* l;
Array2D* arr;

[STAThreadAttribute]

int main()
{
	// initialize the doubly linked list
	l = new List();
	// initialize the 2D array
	arr = new Array2D();

	// start up the application
	Application::EnableVisualStyles();
	Application::EnableRTLMirroring();
	Application::Run(gcnew Form1());
	return 0;
}
