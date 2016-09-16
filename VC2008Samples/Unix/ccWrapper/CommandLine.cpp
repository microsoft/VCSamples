/************************************************
Name: CC2CL
File: CommandLine.cpp
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
#include "CommandLine.h"

int CommandLine::ReadCommandLine(int argc, char const * const line[])
{
	int i;
	for(i = 0; i < argc; ++i)
	{
		if(line[i])
			commandLine.push_back(line[i]);  // Reads each argument from the command line and pushes it on the vector
		else
			return i;
	}
	return i;
}

string CommandLine::GetNextWord()
{
	if((int)pos < (int)commandLine.size())
		return commandLine[pos++];   // Retrieves the next word from the command line vector.  
	else							 // State is maintained by 'pos'
		return "";
}

