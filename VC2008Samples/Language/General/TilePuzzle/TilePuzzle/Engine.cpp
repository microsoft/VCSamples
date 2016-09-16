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
#include "Engine.h"


/************************************************************
*
* TilePuzzle::Engine::ctor
*
************************************************************/

TilePuzzle::Engine::Engine(AlgorithmType eAlgType, int ColSize, int RowSize, array<int> ^StartState , array<int> ^EndState) {

	m_InitNode = Node(StartState);
	m_GoalNode = Node(EndState);
	m_pGameTree = gcnew GameTree(eAlgType, m_GoalNode.State, ColSize, RowSize);
	m_pTreeHash = gcnew TreeHash;

	m_eAlgType = eAlgType;
	m_Columns = ColSize;
	m_Rows = RowSize;

	Debug::Assert( (ColSize >= 0 && RowSize >= 0), "(ColSize >= 0 && RowSize >= 0)", "TilePuzzle::Engine::Solve() board size, cannot have negative or 0");
	Debug::Assert( (ColSize * RowSize) == StartState->Length, "(ColSize * RowSize) == StartState->Length", "TilePuzzle::Engine::Solve() dimensions passed in not equal to StartState area");
	Debug::Assert( (ColSize * RowSize) == EndState->Length, "(ColSize * RowSize) == EndState->Length", "TilePuzzle::Engine::Solve() dimensions passed in not equal to EndState area");
}


/************************************************************
*
* TilePuzzle::Engine::SolvePuzzle
*
* run all 4 algorithms and return soln of the one that finds it first
*
************************************************************/

String^ TilePuzzle::Engine::SolvePuzzle(array<int> ^start , array<int> ^end ) {

	if(m_SolveAlgType < 4) {
		Engine^ e = gcnew Engine( static_cast<AlgorithmType>(20+m_SolveAlgType), m_Columns, m_Rows, start, end);
		e->Solve();
		return e->m_Solution;
	}

	array<Engine^> ^e  = gcnew array<Engine^> (4);

	e[0] = gcnew Engine(AlgorithmType::BREADTH_FIRST_SEARCH, m_Columns, m_Rows, start, end);
	e[1] = gcnew Engine(AlgorithmType::DEPTH_FIRST_SEARCH,   m_Columns, m_Rows, start, end);
	e[2] = gcnew Engine(AlgorithmType::A1_HEURISTIC_SEARCH,  m_Columns, m_Rows, start, end);
	e[3] = gcnew Engine(AlgorithmType::A2_HEURISTIC_SEARCH,  m_Columns, m_Rows, start, end);

	array<Thread^> ^tArray = gcnew array<Thread^> (4);

	for(int i=0; i < 4; i++)
		tArray[i] = gcnew Thread( gcnew ThreadStart(e[i], &Engine::Solve) );

#ifdef _DEBUG
	Console::WriteLine(L"Starting threads...");
#endif // _DEBUG

	Int64 starttime = DateTime::Now.Ticks;

	//call the Solve method for each Algorithm thread
	for(int i=0; i < 4; i++) {
		e[i]->m_iTimeSlice = 0;
		e[i]->m_iNumNodes = 0;
		tArray[i]->Start();
	}

	int iFound = -1;

#ifdef _DEBUG
	Console::WriteLine("Solving...");
#endif // _DEBUG

	//loop through all 4 threads, check if any are done
	while((!Engine::CancelThreads) && (iFound == -1)) {

		for(int i=0; i < 4; i++) {

			e[i]->m_SolveAlgType = m_SolveAlgType;

			if( ! tArray[i]->IsAlive ) {
				iFound = i;
				break;
			}
		}
	}


	Int64 endtime = DateTime::Now.Ticks;

	//kill all the threads, because one is done
	for(int i=0; i < 4; i++) {
//		tArray[i]->Stop();
		tArray[i]->Abort();

#ifdef _DEBUG
		Console::WriteLine(L"Stopped thread.");
#endif // _DEBUG

	}

#ifdef _DEBUG
	Console::WriteLine( String::Concat("Algorithm that found soln first: ", AlgorithmTypeToString(iFound)));
	Console::Write("Seconds elapsed: ");
	Console::WriteLine( (double)(endtime - starttime) / (double)10000000);
#endif // _DEBUG

	if(Engine::CancelThreads)
		return "I";	//empty solution
	else {

#ifdef _DEBUG
		
		for(int j=0;j<4;j++) {
			Console::Write( String::Concat(AlgorithmTypeToString(j), " got hit = \t"));
			Console::Write(e[j]->m_iTimeSlice);
			Console::Write(" times,");
			Console::Write("\tand created = ");
			Console::Write(e[j]->m_iNumNodes);
			Console::WriteLine(" nodes.");
		}
#endif // _DEBUG

		m_SolveAlgType = iFound;	//Set the algorithm type to the one that found it in case the UI would like to display it
		return e[iFound]->m_Solution;
	}

}


/************************************************************
*
* TilePuzzle::Engine::Solve
*
************************************************************/

void TilePuzzle::Engine::Solve() {

	try {

		m_pGameTree->Push(m_InitNode);

		m_pTreeHash->AddState(m_InitNode);

		Node CurrNode = m_pGameTree->Top();

		while( (!CurrNode.EqualsState(m_GoalNode.State)) && (!Engine::CancelThreads) ) {

			m_pGameTree->Pop();

			AddLegalMovesToTree(GetLegalMoves(FindRobot(CurrNode)), CurrNode);

			if(m_SolveAlgType == 5) Thread::CurrentThread->Sleep(0);	//force the current thread to give up its timeslice
																		//(i.e. let the other threads do some solving too)
																		//favors shorter solutions
			m_iTimeSlice++;

			CurrNode = m_pGameTree->Top();
		}

		m_Solution = m_pTreeHash->GetMoves(CurrNode.State);
	}

	catch(Exception ^e) {
		
		if(!e->GetType()->ToString()->Equals("System.Threading.ThreadStopException")) { //ignore this type of exception since it means the thread is terminating
			
#ifdef _DEBUG
			Console::Write( String::Concat(AlgorithmTypeToString(m_eAlgType), " caught exception: \""));
			Console::WriteLine( String::Concat(e->GetType()->ToString(), "\""));
			Console::WriteLine(e->ToString());
#endif // _DEBUG

			//dont let the thread die if one of our algorithms threw, our loop depends on thread dying only if it found the soln
			(Thread::CurrentThread)->Sleep(Timeout::Infinite);
		}
	}
}


/************************************************************
*
* TilePuzzle::Engine::AddLegalMovesToTree
*
************************************************************/

void TilePuzzle::Engine::AddLegalMovesToTree(String^ LegalMoves, Node CurrNode) {

	//Maximum deepening: stop making new nodes at depth MAX_TREE_DEPTH
	if( (m_eAlgType == AlgorithmType::DEPTH_FIRST_SEARCH) && (m_pTreeHash->GetMoves(CurrNode.State)->Length > MAX_TREE_DEPTH ) ) {
		return;
	}

	Node NewNode;

	for(int i=0; i < LegalMoves->Length; i++) {

		//don't create any loops
		if(IsOppositeMove(LegalMoves->default[i], CurrNode.Move))
			continue;

		NewNode = MakeLegalMove(CurrNode, LegalMoves->default[i]);

		//don't add a state if it is already on the tree
		if(m_pTreeHash->StateExists(NewNode.State))
			continue;

		m_pGameTree->Push(NewNode);
		m_pTreeHash->AddState(NewNode);

		m_iNumNodes++;
	}
}

/************************************************************
*
* TilePuzzle::Engine::GetLegalMoves
*
************************************************************/

String^	TilePuzzle::Engine::GetLegalMoves(int RobotPosition) {

	String^ tmpMoves = String::Empty;

	//legal spots for an Up move
	if( RobotPosition >= m_Columns )
		tmpMoves = String::Concat(tmpMoves, "U");

	//legal spots for a Left move
	if( (RobotPosition % m_Columns) != 0 )
		tmpMoves = String::Concat(tmpMoves, "L");

	//legal spots for a Down move
	if( RobotPosition < (m_Columns * (m_Rows -1)) )
		tmpMoves = String::Concat(tmpMoves, "D");	

	//legal spots for a Right move
	if( ((RobotPosition+1) % m_Columns) != 0 )
		tmpMoves = String::Concat(tmpMoves, "R");

	return tmpMoves;
}


/************************************************************
*
* TilePuzzle::Engine::MakeLegalMove
*
************************************************************/

TilePuzzle::Node TilePuzzle::Engine::MakeLegalMove(Node BeforeMoveNode, Char Direction) {

	Node AfterMoveNode;
	int RobotPos = FindRobot(BeforeMoveNode);

	int delta = 0;

	switch(Direction) {
	case L'L':
		delta = -1;
		break;
	case L'R':
		delta = +1;
		break;
	case L'U':
		delta = -m_Columns;
		break;
	case L'D':
		delta = +m_Columns;
		break;
	default:
		Debug::Assert(false, "switch(Direction)", "TilePuzzle::Engine::MakeLegalMove() got an invalid direction to move, not one of LRUD");
		break;
	};

	//Copy the original state
	//probably the slowest part of the code
	AfterMoveNode.State = gcnew array<int> (BeforeMoveNode.State->Length);
	BeforeMoveNode.State->CopyTo(AfterMoveNode.State, 0);

	//Change the state "swap the tiles" without using a temp
	AfterMoveNode.State[RobotPos] = AfterMoveNode.State[RobotPos] + AfterMoveNode.State[RobotPos + delta];
	AfterMoveNode.State[RobotPos + delta] = AfterMoveNode.State[RobotPos] - AfterMoveNode.State[RobotPos + delta];
	AfterMoveNode.State[RobotPos] = AfterMoveNode.State[RobotPos] - AfterMoveNode.State[RobotPos + delta];

	//Link node to its parent
	AfterMoveNode.Parent = BeforeMoveNode.State;
	AfterMoveNode.Move = Direction;

	return AfterMoveNode;
}


/************************************************************
*
* TilePuzzle::Engine::FindRobot
*
************************************************************/

int TilePuzzle::Engine::FindRobot(Node SrcNode) {

	int i;
	for(i=0; (SrcNode.State[i] != 0) && (i < (m_Columns * m_Rows)); i++);
	
	Debug::Assert( (i < (m_Columns * m_Rows)), "i < (m_Columns * m_Rows)", "TilePuzzle::Engine::FindRobot() got an invalid board configuration, \"0\" not found");

	return i;
}


/************************************************************
*
* TilePuzzle::Engine::IsOppositeMove
*
************************************************************/

inline bool TilePuzzle::Engine::IsOppositeMove(Char NextMove, Char PrevMove) {

	return ((NextMove == L'U' && PrevMove == L'D') ||
			(NextMove == L'D' && PrevMove == L'U') ||
			(NextMove == L'R' && PrevMove == L'L') ||
			(NextMove == L'L' && PrevMove == L'R'));
}


/************************************************************
*
* TilePuzzle::Engine::GenerateRandomBoard
*
************************************************************/

array<int> ^	TilePuzzle::Engine::GenerateRandomBoard(int Seed, int NumRandomMoves, int Col, int Row, array<int> ^Board){

	if((Board->Length < 2) || (Col <=0) || (Row <=0))
		return Board;

	Engine^ e = gcnew Engine(Col, Row);

	//Create a Node and find the legal moves
	Node StartNode = Node(Board);
	String^ LegalMoves = e->GetLegalMoves(e->FindRobot(StartNode));

	Random^ r = gcnew Random(Seed);
	Seed = r->Next();

	//Get a good distribution of the random moves: 0, 1, 2, 3  {'L', 'R', 'U', 'D'}
	int randPos = r->Next(4);
	if(randPos >= LegalMoves->Length)
		randPos = LegalMoves->Length-1;

	if( NumRandomMoves <= 0 ) {
		//base case of the recursion, stop at NumRandomMoves random moves

#ifdef _DEBUG
		Console::WriteLine("Random board generated:");
		e->PrintState(Board);
#endif // _DEBUG

		return Board;
	}
	else {
		//use the random move to generate another state (Board)
		return GenerateRandomBoard( Seed, --NumRandomMoves, Col, Row, e->MakeLegalMove(StartNode, LegalMoves->default[randPos]).State );
	}
}


/************************************************************
*
* TilePuzzle::Engine::PrintState
*
************************************************************/

void TilePuzzle::Engine::PrintState(array<int> ^SrcState ) {

	for(int i=0; i <= ((m_Rows*m_Columns)-1); i += m_Columns) {

		Console::Write("\t\t");

		for(int j=0; j < m_Columns ; j++) {

			if(SrcState[i+j]<10) Console::Write(L" ");
			Console::Write(SrcState[i+j]);
			Console::Write(L" ");
		}

		Console::Write("\n");
	}

	Console::Write("\n");
}


/************************************************************
*
* TilePuzzle::Engine::PrintStateHist
*
************************************************************/

void TilePuzzle::Engine::PrintStateHist(ArrayList^ SrcList) {

	for(int i=0; i < SrcList->Count; i++)
		PrintState( static_cast< array<int> ^>(SrcList->default[i]) );
}


/************************************************************
*
* TilePuzzle::Engine::AlgorithmTypeToString
*
************************************************************/

String^	TilePuzzle::Engine::AlgorithmTypeToString(int i) {

	switch(i) {

	case 0:
		return "BREADTH_FIRST_SEARCH";

	case 1:
		return "DEPTH_FIRST_SEARCH";

	case 2:
		return "A1_HEURISTIC_SEARCH";

	case 3:
		return "A2_HEURISTIC_SEARCH";

	default:
		return "SOLVING_THREADS_CANCELED";
	};
}

/************************************************************
*
* TilePuzzle::Engine::AlgorithmTypeToString
*
************************************************************/

String^	TilePuzzle::Engine::AlgorithmTypeToString(AlgorithmType eAlgType) {

	switch(eAlgType) {

	case AlgorithmType::BREADTH_FIRST_SEARCH:
		return "BREADTH_FIRST_SEARCH";

	case AlgorithmType::DEPTH_FIRST_SEARCH:
		return "DEPTH_FIRST_SEARCH";

	case AlgorithmType::A1_HEURISTIC_SEARCH:
		return "A1_HEURISTIC_SEARCH";

	case AlgorithmType::A2_HEURISTIC_SEARCH:
		return "A2_HEURISTIC_SEARCH";

	default:
		return "SOLVING_THREADS_CANCELED";
	};
}
