/************************************************
Name: CC2CL
File: Input.cpp
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

#include <fstream>
#include <iostream>
#include <string>
#include "Input.h"
#include "ReturnItem.h"
#include "VCOption.h"

/*
Function Name: AddPair
Parameters:
string other - This is the switch from the "other" compiler.
string vc - This is the switch that 'other' maps to on VC.
Return Value: true
Actions: This pushes the pair <other, vc> onto the vector optionPairs.
*/
bool Input::AddPair(string other, string vc, bool space)
{
	VCOption vcOption;
	vcOption.space = space;
	vcOption.vc = vc;
	vcOption.error = NOERROR;
	optionPairs.push_back(make_pair(other, vcOption));   
	return true;
}

bool Input::AddPair(string other, string vc, ERRTYPE error)
{
	VCOption vcOption;
	vcOption.space = true;
	vcOption.vc = vc;
	vcOption.error = error;
	optionPairs.push_back(make_pair(other, vcOption));   
	return true;
}

/*
Function Name: ReadInputFile
Parameters:
char const *fileName - The name of the input file we will be reading from.
Return Value: 
-1 if there is an error (unspecified what the error is)
1 if the function executes successfully
Actions: The Input::optionPairs vector is filled with the pairings as specified by the input
file named fileName.
*/
int Input::ReadInputFile(char const *fileName)
{
	
	if(fileName == NULL)
		return -1;
	string ccOption, vcOption;
	string option;
	char temp[LINESIZE];
	ifstream inputFile(fileName);
	if(!inputFile)
	{
		cerr << "No file named : " << fileName << endl;
		return -1;
	} 
	bool spaceState = false;
	int state = CCSTATE;
	while(inputFile >> option)
	{
		switch(state)
		{
		case CCSTATE:
			if(option == "@@@")
			{
				inputFile.getline(temp, LINESIZE);
				break;
			}
			if(option == "~~~")
			{
				return 1;
			}
			if(option == "***")
			{
				spaceState = false;
				state = VCSTATE;
			}
			else
			{
				if(spaceState)
				{
					ccOption += " ";
				}
				spaceState = true;
				ccOption += option; 
			}
			break;
		case VCSTATE:
			if(option == "!!!")
			{
				spaceState = false;
				state = CCSTATE;
				AddPair(ccOption, vcOption);
				ccOption = "";
				vcOption = "";
			}
			else if(option == "###")
			{
				spaceState = false;
				state = CCSTATE;
				AddPair(ccOption, vcOption, false);
				ccOption = "";
				vcOption = "";
			}
			else if(option == "EEE")
			{
				spaceState = false;
				state = CCSTATE;
				AddPair(ccOption, vcOption, FATAL);
				ccOption = "";
				vcOption = "";
			}
			else if(option == "^^^")
			{
				spaceState = false;
				state = CCSTATE;
				AddPair(ccOption, vcOption, WARNING);
				ccOption = "";
				vcOption = "";
			}
			else
			{
				if(spaceState)
				{
					vcOption += " ";
				}
				spaceState = true;
				vcOption += option;  
			}
			break;
		default:
			cerr << "Invalid State" << endl;
			return -1;
		}
	}
	return 1;
}

// This code here just loads the optionPairs from the code.  It acts like ReadInputFile.  
// This is only called if you define CCMEMORY
int Input::CreatePairsFromCode()
{
	AddPair("-Wall", "/Wall");
	AddPair("-O2", "/O2");
	AddPair("-c", "/c");
	AddPair("-S", "/s");
	AddPair("-E", "/EP");
	AddPair("-o", "/Fe", false);
	AddPair("--help", "/?");
	AddPair("-ansi", "/Za");
	AddPair("-funsigned-char", "/J");
	AddPair("-pedantic", "/Za");
	AddPair("-pedantic-errors", "/Za");
	AddPair("-w", "/W0");
	AddPair("-ggdb", "/Zi");
	AddPair("-gstabs", "/Zi");
	AddPair("-gstabs+", "/Zi");
	AddPair("-gcoff", "/Zi");
	AddPair("-gxcoff", "/Zi");
	AddPair("-O0", "/Od");
	AddPair("-O1", "/O2");
	AddPair("-O2", "/O2");
	AddPair("-O3", "/Ox");
	AddPair("-Os", "/O1");
	AddPair("-float-store", "/Op");
	AddPair("-fno-default-inline", "/Ob0");
	AddPair("-fomit-frame-pointer", "/Oy");
	AddPair("-fno-inline", "/Ob0");
	AddPair("-finline-functions", "/Ob2");
	AddPair("-include", "/FI");
	AddPair("-nostdinc", "/X" );
	AddPair("-undef", "/u" );
	AddPair("-C", "/C" );
	AddPair("-P", "/P" );
	AddPair("-D", "/D");
	AddPair("-U", "/U");
	AddPair("-nodefaultlibs", "/link /NODEFAULTLIB");
	AddPair("-nostdlib",  "/link /NODEFAULTLIB");
	AddPair("-I", "/I");
	AddPair("-L", "/link /LIBPATH:");
	AddPair("-fpack-struct", "/Zp1");
	AddPair("-fstack-check", "/GS");
	return 1;
}

/*
Function Name: BestMapping
Parameters:
string &origOpt - The switch to be mapped from.
Return Value: ReturnItem
This ReturnItem class contains the .bestMatch string which is the best matching switch.
The .bestMap string is the VC switch that .bestMatch maps too.
The .remainingString is what is left of the origOpt string after you remove the .bestMatch string.
Actions: This method finds the switch that best matches origOpt.
If there is more than one switch that matches origOpt then the longest match is selected.
*/
ReturnItem Input::BestMapping(string &origOpt)
{
	ReturnItem bestItem;
	string currentStr;
	string::size_type idx;
	vector<pair<string, VCOption> >::iterator iterOpt, endOpt;
	endOpt = optionPairs.end();
	bestItem.remainingString = origOpt;
	for(iterOpt = optionPairs.begin(); iterOpt != endOpt; ++iterOpt)
	{
		currentStr = iterOpt->first;
		idx = origOpt.find(currentStr, 0);
		if(idx == 0)
		{
			if(currentStr.size() > bestItem.bestMatch.size())
			{
				bestItem.bestMatch = currentStr;
				bestItem.bestMap = iterOpt->second.vc;
				bestItem.remainingString = origOpt.substr(currentStr.size());
				bestItem.space = iterOpt->second.space;
				bestItem.error = iterOpt->second.error;
			}
		}
	}
	
	return bestItem;
}