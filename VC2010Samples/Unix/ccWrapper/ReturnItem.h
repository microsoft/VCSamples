/************************************************
Name: CC2CL
File: ReturnItem.h
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
#ifndef __RETURNITEM_H__
#define __RETURNITEM_H__

#include <string>
using namespace std;
#include "VCOption.h"
/* This class simply encapsulates the three string items we'd like to return. */
class ReturnItem
{
public:
	ReturnItem() {bestMatch = ""; bestMap = ""; remainingString = ""; space = true; error=NOERROR;}
	~ReturnItem() {} ;
	// ReturnItem& operator=(ReturnItem const *rhs);
	string bestMatch, bestMap, remainingString;
	bool space;
	ERRTYPE error;
};

#endif