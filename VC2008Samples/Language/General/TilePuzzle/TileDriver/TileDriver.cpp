//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


//	Code for main driving of the TilePuzzle application

#include "stdafx.h"
#include "winerror.h"
#include "Board.h"
#include "SolverThreads.h"
#include "TileDriver.h"

using namespace TileDriver;

//Driver::Driver
//	Constructor
Driver::Driver()
{
	m_pBoard 			= gcnew Board(3, 3);//9 is just the expected default - the object will be deleted/recreated if this is not true
	m_pSolverThreads 	= gcnew SolverThreads;
	m_pHistory			= gcnew GameHistory::CGameHistoryClass;
	m_fHistoryDirty		= true;
}

//Driver::ClearHistory()
//
// Clear all move history, and set current status as Initial state.
//
bool Driver::ClearHistory()
{
	m_pHistory->InitGame(m_pBoard->GetStringBoard(), m_pBoard->GetRowSize(), m_pBoard->GetColSize());
	return true;
}

//Driver::NewGame
//	params:
//		[in]  sizeCol: number of tiles in a column
//		[in]  sizeRow: number of tiles in a row
//	returns:
//		[out] a 1 dimensional array containing (sizeCol * sizeRow) integers.
//

/* ENTRY FROM UI */

array<int> ^ Driver::NewGame(int sizeCol, int sizeRow, int Difficulty)
{
	m_nDifficulty = Difficulty;

	const unsigned int sizeBoard = sizeCol * sizeRow;
	unsigned int * rguBoard = new unsigned int[sizeBoard];
	Driver::NewGame(sizeCol, sizeRow, rguBoard);
	array<int> ^rgOut = gcnew array<int> (sizeBoard);
	
	for(unsigned int c=0; c<sizeBoard; c++)
	{
		rgOut[c] = rguBoard[c];
	}
	
	delete[] rguBoard;
	return rgOut;
}

//Driver::NewGame
//	params:
//		[in]  sizeCol: number of tiles in a column
//		[in]  sizeRow: number of tiles in a row
//	returns:
//		[out] a 1 dimensional array containing (sizeCol * sizeRow) integers.
//
bool Driver::NewGame(unsigned int sizeCol, unsigned int sizeRow, unsigned int * rgintBoard)
{
	Debug::Assert(m_pBoard != nullptr, L"m_pBoard", L"TileDriver::Driver.m_pBoard - uninitialized!");
	
	if( (m_pBoard->GetColSize() != sizeCol) || 
		(m_pBoard->GetRowSize() != sizeRow) )
	{
		delete m_pBoard;
		m_pBoard = gcnew Board(sizeCol, sizeRow);
	}
	m_pBoard->Randomize(m_nDifficulty);
	
	//Tell the history object now
	m_pHistory->InitGame(m_pBoard->GetStringBoard(), m_pBoard->GetRowSize(), m_pBoard->GetColSize());
	
	unsigned int * rgTemp = m_pBoard->GetBoard();
	
	for (unsigned int c=0; c<(sizeCol * sizeRow); c++)
	{
		rgintBoard[c] = rgTemp[c];
	}
		
	//Note: don't free rgTemp, its just a peek into m_pBoard
	return true;
}


bool Driver::CanUndo()
{
	if (m_fHistoryDirty)
		return false;
	
	signed char chRet = 'Z';
	try{
		m_pHistory->CanUndo2(chRet);
	}
	catch(...)
	{
		Console::WriteLine(L"Driver::CanUndo - Caught Exception from m_pHistory->CanUndo2, returning true");
		return true;
	}

	
	Text::StringBuilder ^ strBld = gcnew Text::StringBuilder;
	strBld->Append('R');//82
	strBld->Append(chRet);

#ifdef _DEBUG
	String ^ strTemp = strBld->ToString();
	Console::WriteLine( String::Concat(L"m_pHistory->CanUndo sets chRet to ", strTemp) );
#endif // _DEBUG
	
	return chRet ? true : false;	
}

bool Driver::CanRedo()
{
	if (m_fHistoryDirty)
		return false;
	signed char chRet;
	m_pHistory->CanRedo2(chRet);
	return chRet ? true : false;
}


//CreateDefaultBoard
//	Handy function that fills an array
inline void Driver::CreateDefaultBoard(unsigned int * rgBoard, signed int iSize)
{
	const unsigned int * ptr = rgBoard;
	while( *rgBoard++ = (rgBoard-ptr < iSize-1) ? (unsigned int)(rgBoard-ptr)+1 : 0);
}

void Driver::CancelSolve()
{
	if(m_pSolverThreads)
		m_pSolverThreads->StopSolve();
}

array<int> ^ Driver::Solve(interior_ptr<int> AlgType)
{
	String ^ strSolution = gcnew String(L"");
	unsigned int * rgEndBoard = new unsigned int[m_pBoard->GetColSize() * m_pBoard->GetRowSize()];
	
	CreateDefaultBoard(rgEndBoard, m_pBoard->GetColSize() * m_pBoard->GetRowSize());
	
	strSolution = m_pSolverThreads->SolveIt(AlgType, m_pBoard->GetColSize(), m_pBoard->GetRowSize()
								, m_pBoard->GetBoard(), rgEndBoard);
	
#ifdef _DEBUG
	Console::WriteLine("Finished Solution, now converting to int array");
#endif // _DEBUG

	//convert from string to the out array
	int lenSolution = strSolution->Length;
	array<int> ^rgOut = gcnew array<int> (lenSolution+1);
	
	array<__wchar_t> ^rgwchOut = strSolution->ToCharArray();
	
	rgOut[0] = lenSolution;

#ifdef _DEBUG
	Console::WriteLine("Next line is strSolution");
	Console::WriteLine(String::Concat("\"", strSolution, "\""));
	Console::WriteLine("Prev line was strSolution");
#endif // _DEBUG

	for(int c=0; c<lenSolution; c++)
	{
		rgOut[c+1] = GetDirectionINT(rgwchOut[c]);
	}

#ifdef _DEBUG
	Console::WriteLine("Finished conversion, returning from Driver::Solve()");
#endif // _DEBUG
	
	delete[] rgEndBoard;
	return rgOut;
}

bool Driver::LoadSavedGame(String ^ strBoardName)
{
	
	String ^ strBoardstate = gcnew String(L"");
	int nCols, nRows;
	
	m_pHistory->LoadSavedGame(strBoardName, strBoardstate, nCols, nRows);
	m_pBoard->SetStringBoard(strBoardstate, nCols, nRows);

	return true;
}

char Driver::ReverseDirection(char chDirection)
{
	switch (chDirection)
	{
	case 'L':
		return 'R';
	case 'R':
		return 'L';
	case 'U':
		return 'D';
	case 'D':
		return 'U';
	default:
		Debug::Assert(false, L"ReverseDirection chDirection", L"unexpected");
	}
	return 'E';
}


//UndoMove
//	All parameters are 'out'
//	pchDirection - direction to move the tile (not the blank), in order to undo the move
//	puPositionClicked - what position would have been clicked to undo the move (not the position the user last clicked)
//	puPositionToMoveTo - The position of the blank space.
long Driver::UndoMove(char * pchDirection, unsigned int * puPositionClicked, unsigned int * puPositionToMoveTo)
{
	char chDirection ('E');
	
	//Tell history object to 'UndoMove', set chDirection.
	
	//Call the PopMove2 function
	GameHistory::eDirection eDir = GameHistory::eDirection::eError;
	m_pHistory->PopMove2(eDir);
	
	//convert from enum to CHAR
	chDirection = GetDirectionCHAR(eDir);
	
	//chDirection = GetDirectionCHAR(m_pHistory->PopMove());
	if(chDirection == 'E')
	{
		*pchDirection = 'E';
		return E_FAIL;
	}
		
	//reverse the direction - we need to 'undo' what was recorded.
	chDirection = *pchDirection = ReverseDirection(chDirection);
		
	//update internal state of the board, also calculate the outparams useful to the UI layer.
	//also, don't alter the outparams unless we are successful, they may be important to someone in the UI layer.
	unsigned int uPositionClickedTemp	(*puPositionClicked);
	unsigned int uPositionToMoveToTemp	(*puPositionToMoveTo);
	
	if(m_pBoard->Move(chDirection, puPositionClicked, puPositionToMoveTo))
	{
		m_pBoard->CommitMove(*puPositionClicked);//update the internal state of the board.
		if(Driver::CanUndo())
			return S_OK;//means that the undo was successful, and the next one should be too.
		else
			return S_FALSE;//means that this is the last one that can be undone.
	}
	else
	{
		Text::StringBuilder ^ strbldTemp = gcnew Text::StringBuilder;
		strbldTemp->Append('L');
		strbldTemp->Append('R');
		strbldTemp->Append('U');
		strbldTemp->Append('D');
		strbldTemp->Append('E');

		strbldTemp->Append(chDirection);
		String ^ strTemp = strbldTemp->ToString();
		
		Debug::Assert(false, L"Inside UndoMove, m_pBoard->Move failed", strTemp );
		*puPositionClicked = uPositionClickedTemp;
		*puPositionToMoveTo = uPositionToMoveToTemp;
		return E_FAIL;
	}
}

array<int> ^ Driver::RedoMove() 
{
	char chMove = 'E';
	
	GameHistory::eDirection eDir;
	m_pHistory->RedoMove2(eDir);
	chMove = GetDirectionCHAR(eDir);
		
	
	
	Debug::Assert(chMove != 'E', L"unexpected, RedoMove returned 'E'", L"Error from History Object");
	
	unsigned int uFromPosition;
	unsigned int uToPosition;
	
	if(m_pBoard->Move(chMove, &uFromPosition, &uToPosition))
	{
		unsigned long hr = m_pBoard->CommitMove(uFromPosition);
		return PackageOut(GetDirectionINT(chMove), uFromPosition, uToPosition, (hr==S_FALSE) ? 1 : 0);
	}
	
	Debug::Assert(false, L"unexpected", L"unexpected");
	return nullptr;
}

bool Driver::Move(unsigned int uPositionClicked, bool * pfValid, char * pchDirection, unsigned int * puPositionToMoveTo, bool * pfFinishesBoard)
{
	bool fValid = m_pBoard->Move(uPositionClicked, pchDirection, puPositionToMoveTo);
	*pfValid = fValid;
	
	if(!fValid)
		return false;
	
	// Every time the UI calls MoveByDir, m_pHistory will not be in sync, and m_fHistoryDirty will set to true
	// So, before we push anything, we need to re-initialize history object
	if (m_fHistoryDirty)
	{
		ClearHistory();
		m_fHistoryDirty = false;
	}
		
	m_pHistory->PushMove(GetDirectionENUM(*pchDirection));
	
	//update the board
	return m_pBoard->CommitMove(uPositionClicked, pfFinishesBoard);
}

bool Driver::Move(char chMoveDirection, bool * pfValid, unsigned int * puPositionClicked, unsigned int * puPositionToMoveTo, bool * pfFinishesBoard)
{
	bool fValid = m_pBoard->Move(chMoveDirection, puPositionClicked, puPositionToMoveTo);
	*pfValid = fValid;
	
	if(!fValid)
		return false;

	// Every time UI call MoveByDir, m_pHistory will not in sync, and m_fHistoryDirty will set to true
	// So, before push anything, we need to re-initialize history object
	m_fHistoryDirty = true;

	//update the board
	return m_pBoard->CommitMove(*puPositionClicked, pfFinishesBoard);
}


int Driver::GetDirectionINT(char chDirection)
{
	switch(chDirection)
	{
	case ('U'):	return UI_DIRECTION_UP;
	case ('R'): return UI_DIRECTION_RIGHT;
	case ('D'): return UI_DIRECTION_DOWN;
	case ('L'): return UI_DIRECTION_LEFT;
	case ('E'): return UI_DIRECTION_ERROR;
	default:
		Debug::Assert(false, L"unexpected GetDirectionINT", L"unexpected");
		return UI_DIRECTION_ERROR;
	}
}

int Driver::GetDirectionINT(__wchar_t chDirection)
{
	switch(chDirection)
	{
	case (L'U'):	return UI_DIRECTION_UP;
	case (L'R'): return UI_DIRECTION_RIGHT;
	case (L'D'): return UI_DIRECTION_DOWN;
	case (L'L'): return UI_DIRECTION_LEFT;
	case (L'E'): return UI_DIRECTION_ERROR;
	default:
		Debug::Assert(false, L"unexpected GetDirectionINT", L"unexpected");
		return UI_DIRECTION_ERROR;
	}
}


GameHistory::eDirection Driver::GetDirectionENUM(char chDirection)
{
	switch(chDirection)
	{
	case ('U'):	return GameHistory::eDirection::eUp;
	case ('R'): return GameHistory::eDirection::eRight;
	case ('D'): return GameHistory::eDirection::eDown;
	case ('L'): return GameHistory::eDirection::eLeft;
	case ('E'): return GameHistory::eDirection::eError;
	default:
		Debug::Assert(false, L"unexpecte GetDirectionENUM", L"unexpecte");
	}
	return GameHistory::eDirection::eError;

}


__wchar_t Driver::GetDirectionWCHAR(GameHistory::eDirection eDir)
{
	switch (eDir)
	{
	case GameHistory::eDirection::eLeft:
		return L'L';
	case GameHistory::eDirection::eRight:
		return L'R';
	case GameHistory::eDirection::eUp:
		return L'U';
	case GameHistory::eDirection::eDown:
		return L'D';
	default:
		Debug::Assert(false, L"unexpect GetDirectionWCHAR", L"unexpecte");
	}
	
	return L'E';
}

__wchar_t Driver::GetDirectionWCHAR(char chDir)
{
	switch (chDir)
	{
		case 'L':
			return L'L';
		case 'R':
			return L'R';
		case 'U':
			return L'U';
		case 'P':
			return L'D';
		default:
			Debug::Assert(false, L"unexpecte GetDirectionWCHAR chDir", L"unexpecte");
	}
	
	return L'E';
}

char Driver::GetDirectionCHAR(int nDirection)
{
	const int cChars = 5;
	char rgChars[cChars] = {'U', 'R', 'D', 'L', 'E'};
	Debug::Assert(nDirection < cChars, L"GetDirectionCHAR nDirection", L"Bad value for n");
	return rgChars[nDirection];
}

char Driver::GetDirectionCHAR(GameHistory::eDirection eDir)
{
	switch (eDir)
	{
	case GameHistory::eDirection::eLeft:
		return 'L';
	case GameHistory::eDirection::eRight:
		return 'R';
	case GameHistory::eDirection::eUp:
		return 'U';
	case GameHistory::eDirection::eDown:
		return 'D';
	case GameHistory::eDirection::eError:
		return 'E';
	default:
		Debug::Assert(false, L"switch on GameHistory::eDirection", L"unexpected value");
	}
	
	return 'E';
}
