//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


//Board.cpp

#include "stdafx.h"
#include "Board.h"
#using <TilePuzzle.dll>


using namespace TileDriver;

Board::Board(unsigned int sizeCol, unsigned int sizeRow) : m_boardSize(sizeCol * sizeRow), m_sizeRow(sizeRow), m_sizeCol(sizeCol)
{
	//initialize the array
	m_rgBoard = new unsigned int[m_boardSize];

	unsigned int sizeBoardMinusOne = m_boardSize -1;
	for(unsigned int c=0; c<sizeBoardMinusOne; c++)
	{
		m_rgBoard[c] = c+1;
	}
	m_rgBoard[sizeBoardMinusOne] = 0;
	
	m_iBlank  = sizeBoardMinusOne;//The last piece is assumed to be the blank one.
}

Board::~Board() {
}

bool Board::Randomize(int Difficulty)
{
	array<int> ^rgnGoalBoard = gcnew array<int> (m_boardSize);

	for(unsigned int c=0; c<m_boardSize; c++)
	{
		rgnGoalBoard[c] = c+1;
	}
	rgnGoalBoard[m_boardSize-1]=0;
	
	//note in the next call, that the number of columns is the 'size' of the row.
	array<int> ^rgnRandomBoard = TilePuzzle::Engine::GenerateRandomBoard( (int)(DateTime::Now.Second), m_boardSize * Difficulty, GetRowSize(), GetColSize(), rgnGoalBoard);
	unsigned int c;	
	for(c=0; c<m_boardSize; c++)
	{
		m_rgBoard[c] = rgnRandomBoard[c];
	}
	
	//find blank
	c = 0;
	while(m_rgBoard[c++] != 0);
	
	m_iBlank = c-1;

	Debug::Assert( m_iBlank < m_boardSize, L"m_iBlank < m_boardSize", L"TileDriver::Board::Randomize() - Blank tile not found from TilePuzzle::Engine::GenerateRandomBoard()");
	
	return true;
}


bool Board::SetStringBoard(String ^ strBoardstate, int nCols, int nRows)
{
	Debug::Assert(strBoardstate->Length == nCols * nRows, L"strBoardstate->Length == nCols * nRows", L"Bad input string, or col row data");
	Debug::Assert(nCols > 0, L"valid number of columns", L"Invalid Number of columns");
	Debug::Assert(nRows > 0, L"valid number of rows", L"Invalid Number of rows");

	return true;
}

String ^ Board::GetStringBoard()
{
	return "";
}

unsigned int * Board::GetBoard()
{
	return m_rgBoard;
}

unsigned int Board::GetSize()
{
	return m_boardSize;
}

unsigned int Board::GetBlank()
{
	return m_iBlank;
}

unsigned int Board::GetRowSize()
{
	return m_sizeRow;
}

unsigned int Board::GetColSize()
{
	return m_sizeCol;
}

bool Board::Move(unsigned int uPositionClicked, char * pchDirection, unsigned int * puPositionToMoveTo)
{
	//Assert if uPositionClicked > m_sizeBoard;
	Debug::Assert(uPositionClicked <= m_boardSize, L"uPositionClicked is within board", L"Clicked outside board");

	unsigned int tempPosition = *puPositionToMoveTo;
	*puPositionToMoveTo = m_iBlank;
	
	if( (uPositionClicked == (m_iBlank + 1)) && //Checks for 'Left'
		((uPositionClicked) % m_sizeRow) )      //if user didn't click first block on a row 
	{
		*pchDirection = 'L';//Valid left move
		return true;
	}
	if( (uPositionClicked == (m_iBlank -1)) &&//Checks for 'Right'
		((m_iBlank) % m_sizeRow) )            //if blank space isn't first block on a row
	{
		*pchDirection = 'R';//Valid right move
		return true;
	}
	if(uPositionClicked == (m_iBlank + m_sizeRow))//Checks for 'Up'
	{
		*pchDirection = 'U';
		return true;
	}
	if(uPositionClicked == (m_iBlank - m_sizeRow))//Checks for 'Down'
	{
		*pchDirection = 'D';
		return true;
	}
	
	*puPositionToMoveTo = tempPosition;//safety - we don't alter their outparam unless we fail.
	
	return false;//only return true if the move is valid.
}

bool Board::Move(char chMoveDirection, unsigned int * puPositionClicked, unsigned int * puPositionToMoveTo)
{
	unsigned int tempPosition = *puPositionToMoveTo;
	*puPositionToMoveTo = m_iBlank;
	
	switch(chMoveDirection)
	{
		case 'L':
			//ok, so long as blank isn't last on a row
			if(((m_iBlank + 1) % m_sizeRow) == 0)
				break;
			*puPositionClicked  = m_iBlank + 1;
			return true;
		case 'R':
			//ok, so long as blank isn't first on a row
			if((!m_iBlank) || (!(m_iBlank % m_sizeRow)))
				break;
			*puPositionClicked = m_iBlank - 1;
			return true;
		case 'U':
			//ok, so long as blank isn't in last row
			if(m_iBlank >= (m_boardSize - m_sizeRow))
				break;
			*puPositionClicked = m_iBlank + m_sizeRow;
			return true;
		case 'D':
			//ok, so long as blank isn't in top row
			if(m_iBlank < m_sizeRow)
				break;
			*puPositionClicked = m_iBlank - m_sizeRow;	
			return true;
		default:
			Debug::Assert(false, L"Only 4 possible move directions", L"not an expected move direction");
			;
	}
	
	//we return false now
	*puPositionToMoveTo = tempPosition;//safety - we don't alter their outparam unless we succeed.
	
	return false;//only return true if the move is valid.			
}
		

//This function assumes the validity of the move has already been confirmed
bool Board::CommitMove(unsigned int uPositionClicked, bool * pfFinishesPuzzle)
{
	unsigned int iPrevBlank = m_iBlank;
	m_iBlank = uPositionClicked;
	
	m_rgBoard[iPrevBlank] 	= m_rgBoard[uPositionClicked];
	m_rgBoard[m_iBlank] 	= 0;
	
	//now see if it finishes the puzzle, assuming the caller cares
	if(pfFinishesPuzzle ==0)
		return true;
	
	*pfFinishesPuzzle = true;
	//check everything but the blank piece, since by process of elimination it must be there.

	unsigned int sizeBoardMinusOne = m_boardSize-1;

	for(unsigned int c=0; c<(sizeBoardMinusOne); c++)
	{
		if(m_rgBoard[c] != c+1)
		{
			*pfFinishesPuzzle = false;
			break;
		}
	}
		
	return true;
}
