//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


//SolverThreads.cpp

#include "stdafx.h"
#include "SolverThreads.h"

using namespace TilePuzzle;

//Constructor
TileDriver::SolverThreads::SolverThreads() 
{
}

String ^ TileDriver::SolverThreads::SolveIt(interior_ptr<int> AlgType, unsigned int sizeCol, unsigned int sizeRow	, unsigned int * rgStartBoard, unsigned int * rgEndBoard)
{

	String ^ strSolution = gcnew String("");

	const unsigned int uSize = sizeCol * sizeRow;
	array<int> ^rgmStart  = gcnew array<int> (uSize);
	array<int> ^rgmEnd    = gcnew array<int> (uSize);
	for(unsigned int c=0; c<uSize; c++)
	{
		rgmStart[c] = rgStartBoard[c];
		rgmEnd[c]   = rgEndBoard[c];
	}
	try{

	Engine::CancelThreads = false; //make sure we reset this in case a solve was cacelled previously

	m_SolveEngine = gcnew Engine(sizeCol, sizeRow);
	m_SolveEngine->m_SolveAlgType = *AlgType;
	String ^ strTemp = m_SolveEngine->SolvePuzzle(rgmStart, rgmEnd);
	*AlgType = m_SolveEngine->m_SolveAlgType;
	
	strTemp = strTemp->Remove(0, 1);//remove the first character, which is an L'I' for the initial move

	strSolution = ReverseDirectionsInString(strTemp);
	
	}
	catch(Exception ^engineThread) {

		Console::WriteLine(engineThread->Message);
		Console::WriteLine("TileDriver::SolverThreads::SolveIt() -- TilePuzzle::Engine threw an exception!");

	}

	return strSolution;
}


void TileDriver::SolverThreads::StopSolve()
{
	if(m_SolveEngine)
		Engine::CancelThreads = true;
}

String ^ TileDriver::SolverThreads::ReverseDirectionsInString(String ^ strDirections)
{
	array<__wchar_t> ^rgChars = strDirections->ToCharArray();
	int length = strDirections->Length;
	
	for(int c=0; c<length; c++)
	{
		switch(rgChars[c])
		{
		case(L'U'): rgChars[c]=L'D'; break;
		case(L'D'): rgChars[c]=L'U'; break;
		case(L'R'): rgChars[c]=L'L'; break;
		case(L'L'): rgChars[c]=L'R'; break;
		}
	}
	
	String ^ strOut = gcnew String(rgChars);
	return strOut;
}