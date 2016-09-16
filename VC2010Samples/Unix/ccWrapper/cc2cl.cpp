/************************************************
Name: CC2CL
File: cc2cl.cpp
Description: CC Wrapper
Product: Microsoft Visual C++

Copyright (c) Microsoft Corporation.  All rights reserved.

This source code is intended only as a supplement to Microsoft
Development Tools and/or on-line documentation.  See these other
materials for detailed information regarding Microsoft code samples.

THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
PARTICULAR PURPOSE.

Notes:
	The users PATH must be set with where ever cl.exe is.

*************************************************/


#include <string>
#include <iostream>
#include <string.h>
#include <process.h>
#include "Input.h"
#include "CommandLine.h"
#include "ReturnItem.h"

using namespace std;


int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;

	string theOutput = "cl ";
	string currentArg;
	ReturnItem mapping;
	Input theInput;
	CommandLine theCommandLine;

#ifndef CCMEMORY  // if we compile to read from memory or to read from a file
	if(theInput.ReadInputFile("ccFile.cfg") == -1)  // the file name is fixed
		return -1;
#else
	theInput.CreatePairsFromCode();
#endif
	// here we read in the command line
	theCommandLine.ReadCommandLine(argc - 1, &argv[1]);  
	// iterate over each word in the command line
	while("" != (currentArg = theCommandLine.GetNextWord()))
	{
		// find the best mapping for each word
		mapping = theInput.BestMapping(currentArg);
		// create the output string
		if(mapping.error == FATAL)
		{
			cerr << "Error with flag " << mapping.bestMap << " -- ABORTING\n";
			return -1;
		}
		if(mapping.error == WARNING)
		{
			cerr << "Warning: Flag may not be properly supported: " << mapping.bestMap << endl;
		}
		theOutput += mapping.bestMap + mapping.remainingString;
		if(mapping.space)
			theOutput += " ";

	}
	cout << theOutput << endl;
	// execute the generated output string.  'cl.exe' will need to be in the users path
	system(theOutput.c_str());
	return 0;
}