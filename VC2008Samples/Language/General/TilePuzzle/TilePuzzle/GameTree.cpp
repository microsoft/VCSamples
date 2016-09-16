//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


#include "stdafx.h"
#include "GameTree.h"

TilePuzzle::GameTree::GameTree(AlgorithmType eAlgType, array<int> ^GoalState , int Cols, int Rows) : m_eAlgType(eAlgType), m_GoalState(GoalState), m_Cols(Cols), m_Rows(Rows) {

	m_Random = gcnew Random;

	switch(m_eAlgType) {

	case AlgorithmType::BREADTH_FIRST_SEARCH:
		m_IDataStructure = gcnew Queue(INIT_QUEUE_SIZE, QUEUE_GROWTH_FACTOR);  //queue
		break;

	case AlgorithmType::DEPTH_FIRST_SEARCH:
		m_IDataStructure = gcnew ArrayList(INIT_STACK_SIZE);  //stack
		break;

	case AlgorithmType::A1_HEURISTIC_SEARCH: case AlgorithmType::A2_HEURISTIC_SEARCH:
		m_IDataStructure = gcnew SortedList;  //list sorted by cost
		break;

	default:
		Debug::Assert(false, "switch(m_eAlgType)", "TilePuzzle::GameTree::ctor() didn't get a valid Algorithm Type");
		break;
	};
	
}

void TilePuzzle::GameTree::Push(Node NewNode) {

	switch(m_eAlgType) {

	case AlgorithmType::BREADTH_FIRST_SEARCH:
		(dynamic_cast<Queue^>(m_IDataStructure))->Enqueue(NewNode);
		break;

	case AlgorithmType::DEPTH_FIRST_SEARCH:
		(dynamic_cast<ArrayList^>(m_IDataStructure))->Add(NewNode);
		break;

	case AlgorithmType::A1_HEURISTIC_SEARCH: case AlgorithmType::A2_HEURISTIC_SEARCH: {
		double cost = GetCost(NewNode);

#ifdef _DEBUG
		Debug::Assert( (cost >= 0), " (cost >= 0) ", "TilePuzzle::GameTree::Push() we shouldn't be here! A negative cost was calculated.");
		Debug::Assert( !(dynamic_cast<SortedList^>(m_IDataStructure))->ContainsKey(cost), " !(dynamic_cast<SortedList^>(m_IDataStructure))->ContainsKey(cost) ", "TilePuzzle::GameTree::Push() we shouldn't be here! A duplicate key was generated.");
#endif // _DEBUG

		(dynamic_cast<SortedList^>(m_IDataStructure))->Add( cost, NewNode);
		break;
	}

	default:
		Debug::Assert(false, "switch(m_eAlgType)","TilePuzzle::GameTree::Push() didn't get a valid Algorithm Type");
		break;
	};
}

TilePuzzle::Node TilePuzzle::GameTree::Pop() {

	switch(m_eAlgType) {

	case AlgorithmType::BREADTH_FIRST_SEARCH:

#ifdef _DEBUG
		Debug::Assert(m_IDataStructure->Count > 0, "m_IDataStructure->Count > 0", "TilePuzzle::GameTree::Pop() trying to pop an empty queue");
#endif // _DEBUG

		return UNBOX((dynamic_cast<Queue^>(m_IDataStructure))->Dequeue());
	
	case AlgorithmType::DEPTH_FIRST_SEARCH: {

#ifdef _DEBUG
		Debug::Assert(m_IDataStructure->Count > 0, "m_IDataStructure->Count > 0", "TilePuzzle::GameTree::Pop() trying to pop an empty stack");
#endif // _DEBUG

		// ArrayList adds its element to the end so I have to remove from end to emulate a stack
		Object^ tmp = (dynamic_cast<ArrayList^>(m_IDataStructure))->default[ m_IDataStructure->Count - 1 ];
		(dynamic_cast<ArrayList^>(m_IDataStructure))->RemoveAt( m_IDataStructure->Count - 1 );
		return UNBOX( tmp );
											}

	case AlgorithmType::A1_HEURISTIC_SEARCH: case AlgorithmType::A2_HEURISTIC_SEARCH: {
		
#ifdef _DEBUG
		Debug::Assert(m_IDataStructure->Count > 0, "m_IDataStructure->Count > 0", "TilePuzzle::GameTree::Pop() trying to pop an empty sorted list");
#endif // _DEBUG
		
		//Get the topmost element
		Object^ tmp = (dynamic_cast<SortedList^>(m_IDataStructure))->GetByIndex( 0 );
		(dynamic_cast<SortedList^>(m_IDataStructure))->RemoveAt( 0 );
		return UNBOX(tmp);
											 }

	default:
		Debug::Assert(false, "switch(m_eAlgType)", "TilePuzzle::GameTree::Pop() didn't get a valid Algorithm Type");
		return Node(1);
	};
}

TilePuzzle::Node TilePuzzle::GameTree::Top() {

	switch(m_eAlgType) {

	case AlgorithmType::BREADTH_FIRST_SEARCH:

#ifdef _DEBUG
		Debug::Assert(m_IDataStructure->Count > 0, "m_IDataStructure->Count > 0", "TilePuzzle::GameTree::Top() trying get the top of an empty queue");
#endif // _DEBUG

		return UNBOX( (dynamic_cast<Queue^>(m_IDataStructure))->Peek() );

	case AlgorithmType::DEPTH_FIRST_SEARCH:

#ifdef _DEBUG
		Debug::Assert(m_IDataStructure->Count > 0, "m_IDataStructure->Count > 0", "TilePuzzle::GameTree::Pop() trying to pop an empty stack");
#endif // _DEBUG

		// ArrayList adds its element to the end so I have to get Top from end to emulate a stack
		return UNBOX( (dynamic_cast<ArrayList^>(m_IDataStructure))->default[ m_IDataStructure->Count - 1 ] );

	case AlgorithmType::A1_HEURISTIC_SEARCH: case AlgorithmType::A2_HEURISTIC_SEARCH:
		
#ifdef _DEBUG
		Debug::Assert(m_IDataStructure->Count > 0, "m_IDataStructure->Count > 0", "TilePuzzle::GameTree::Top() trying to get the top of an empty sorted list");
#endif // _DEBUG
		
		return UNBOX( (dynamic_cast<SortedList^>(m_IDataStructure))->GetByIndex( 0 ) );

	default:
		Debug::Assert(false, "switch(m_eAlgType)", "TilePuzzle::GameTree::Top() didn't get a valid Algorithm Type");
		return Node(1);
	};
}

bool TilePuzzle::GameTree::IsEmpty() {

	switch(m_eAlgType) {

	case AlgorithmType::BREADTH_FIRST_SEARCH:
	case AlgorithmType::DEPTH_FIRST_SEARCH:
	case AlgorithmType::A1_HEURISTIC_SEARCH:
	case AlgorithmType::A2_HEURISTIC_SEARCH:
		return ( m_IDataStructure->Count <= 0 );

	default:
		Debug::Assert(false, "switch(m_eAlgType)", "TilePuzzle::GameTree::IsEmpty() didn't get a valid Algorithm Type");
		return 0;
	};
}

double TilePuzzle::GameTree::GetCost(Node SrcNode) {

	if(m_eAlgType == AlgorithmType::A1_HEURISTIC_SEARCH) {

		//this is a simple heuristic = just get the total number of tiles that are in the wrong place
		double dTotalWrongPositions = 0;

		for(int i=0; i < (m_Cols*m_Rows); i++) {
			if(SrcNode.State[i] != m_GoalState[i])
				dTotalWrongPositions++;
		}

		//since the structure cannot contain duplicate key values, lets make sure we don't make any
		return dTotalWrongPositions + m_Random->NextDouble();

	}

	//AlgorithmType::A2_HEURISTIC_SEARCH

	//slightly more complicated heuristic - get the total cost for each tile (how far each is away from the goal state)

	int iCurrentPosition, iGoalPosition=0, j=0, moves=0, HeuristicTotal=0;

	//Get the sum of the distances of the tiles from their goal positions
	for(iCurrentPosition=0; iCurrentPosition < (m_Cols*m_Rows); iCurrentPosition++)
	{
		if(SrcNode.State[iCurrentPosition] != 0) //Skip the irrelavant "empty" tile position
		{
			//Find the goal position of the current tile
			for(j=0;j < (m_Cols*m_Rows);j++) {
				if(SrcNode.State[iCurrentPosition] == m_GoalState[j])
					{iGoalPosition = j; break;}
			}

			// GENERAL CASE = NxM BOARD
			
			//Current tile and goal tile are in opposite corners of the board: m_Cols + m_Rows - 2 moves away
			if( (iCurrentPosition == m_Cols-1) && (iGoalPosition == ((m_Cols*m_Rows)-m_Cols)) ||
				(iCurrentPosition == ((m_Cols*m_Rows)-m_Cols)) && (iGoalPosition == m_Cols-1) ) {

				HeuristicTotal += m_Cols + m_Rows - 2;
			}
			else {

				moves = Math::Abs( iCurrentPosition - iGoalPosition );

				//Tile is in the goal position
				if(moves == 0)
					HeuristicTotal += 0;
				//Tile is one move away from goal
				else if(moves == 1 || moves == m_Cols)
					HeuristicTotal += 1;
				//Current tile and goal tile are in the other opposite corners of the board
				else if(moves == (m_Cols*m_Rows)-1)
					HeuristicTotal += m_Cols + m_Rows - 2;
				//Tiles are some other distance away (to solve this we can think of this as a sub board within the current board)
				else {
					HeuristicTotal += moves;
				}
			}
		}
	}
	//Return the actual under-estimated cost: UCost  (using NextDouble so that we dont have any duplicate costs)	
	return HeuristicTotal + m_Random->NextDouble();
}
