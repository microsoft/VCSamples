//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


//tweak for perfomance
#define INIT_QUEUE_SIZE 400
#define QUEUE_GROWTH_FACTOR 2.0
#define INIT_STACK_SIZE 400

//for depth first search
#define MAX_TREE_DEPTH 50
//utility macro
#define UNBOX(x) (*dynamic_cast<Node^>(x))




namespace TilePuzzle {


 enum struct AlgorithmType {

	BREADTH_FIRST_SEARCH = 20,
	DEPTH_FIRST_SEARCH,
	A1_HEURISTIC_SEARCH,
	A2_HEURISTIC_SEARCH

};  //__value enum AlgorithmType


value struct Node {

	Char Move;
	array<int> ^Parent;
	array<int> ^State;

	Node(array<int> ^InitState) : State(InitState), Parent(gcnew array<int> (0)), Move(L'I') {}
	Node(int) : State(gcnew array<int> (0)), Parent(gcnew array<int> (0)), Move(L'I') {}

	inline bool EqualsState(array<int> ^TargetState) {
		for( int i=0; i < State->Length; i++ )
			if(State[i] != TargetState[i])
				return false;
		return true;
	}

};  //__value struct Node


ref class GameTree {

public:
	GameTree(AlgorithmType eAlgType, array<int> ^GoalState, int Cols, int Rows);
	void Push(Node NewNode);
	Node Pop();
	Node Top();
	bool IsEmpty();
	
	property int TotalNodes 
	{
	int get() { return m_IDataStructure->Count; }
	}

private:
	double GetCost(Node SrcNode);

	array<int>		^m_GoalState;
	int				m_Cols;
	int				m_Rows;

	ICollection^	m_IDataStructure;
	AlgorithmType	m_eAlgType;

	Random^			m_Random;

}; //__gc class GameTree


//Can add states to a structure with no duplicates and have the ability to check if a state exists

ref struct TreeHash : public Hashtable {

	//Slow string concatenation
	void AddState(Node SrcNode) {
		if(SrcNode.Parent->Length <= 0)
			Add( StateToString(SrcNode.State), SrcNode.Move.ToString() );
		else
			Add( StateToString(SrcNode.State), String::Concat(GetMoves(SrcNode.Parent), SrcNode.Move.ToString()) ); //keeps appending moves
	}

	String^ GetMoves(array<int> ^SrcState) {
		return static_cast<String^>( default[StateToString(SrcState)]);
	}

	bool StateExists(array<int> ^SrcState) {
		return ContainsKey( StateToString(SrcState) );
	}

private:

	String^ StateToString(array<int> ^SrcState) {

		tmpStr = String::Empty;

		for(int i=0; i < SrcState->Length; i++) {
			tmpStr = String::Concat(tmpStr, ",", SrcState[i].ToString());
		}

		return tmpStr;
	}

	String^ tmpStr;

};  //__gc struct TreeHash


};  //namespace TilePuzzle
