/************************************************
Name: CC2CL
File: Input.h
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
#include <vector>
#include <utility>
#include <string>
#include "ReturnItem.h"
#include "VCOption.h"

using namespace std;
/* There are two states.  
CCSTATE means that we are reading information about the "other" compiler switches.
VCSTATE means that we are reading information about the VC switches. */
#define CCSTATE (0)
#define VCSTATE (1)
#define LINESIZE (80)

class Input
{
public:
	Input() {};
	~Input() {};
	int ReadInputFile(char const *fileName);
	int CreatePairsFromCode();
	ReturnItem BestMapping(string &origOpt);
private:
	bool AddPair(string other, string vc, bool space = true);
	bool AddPair(string other, string vc, ERRTYPE error);
	vector<pair<string, VCOption> > optionPairs;
};