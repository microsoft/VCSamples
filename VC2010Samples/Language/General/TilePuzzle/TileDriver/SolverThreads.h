//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


//SolverThreads.h
#using <TilePuzzle.dll>


namespace TileDriver 
{
	
public ref class SolverThreads
{

public:
	SolverThreads();
	String ^ SolveIt(interior_ptr<int> AlgType, unsigned int sizeCol, unsigned int sizeRow,
		unsigned int * rgStartBoard, unsigned int * rgEndBoard);

	void StopSolve();
private:
	String ^ ReverseDirectionsInString(String ^ strDirections);

	TilePuzzle::Engine ^ m_SolveEngine;
};

};
