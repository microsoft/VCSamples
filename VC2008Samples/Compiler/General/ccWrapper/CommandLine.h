/************************************************
Name: CC2CL
File: CommandLine.h
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
#include <vector>
using namespace std;

class CommandLine
{
public:
	CommandLine() {pos = 0;}
	~CommandLine() {};
	string GetNextWord();
	int ReadCommandLine(int argc, char const * const line[]);
private:
	vector<string> commandLine;
	int pos;
};