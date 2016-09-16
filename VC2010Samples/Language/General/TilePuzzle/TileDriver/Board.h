//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


//Board.h

namespace TileDriver 
{

public ref class Board
{

public:
	Board(unsigned int sizeCol, unsigned int sizeRow);
	~Board();
	bool Randomize(int Difficulty);
	
	String ^ 	   GetStringBoard();
	bool 		   SetStringBoard(String ^ strBoardstate, int nCols, int nRows);
	
	unsigned int * GetBoard();
	unsigned int   GetSize();
	unsigned int   GetBlank();
	unsigned int   GetRowSize();
	unsigned int   GetColSize();

	bool CommitMove(unsigned int uPositionClicked) {
		return CommitMove(uPositionClicked, 0);
	}
	bool CommitMove(unsigned int uPositionClicked, bool * pfFinishesPuzzle);
	bool Move(unsigned int uPositionClicked, char * pchDirection, unsigned int * puPositionToMoveTo);
	bool Move(char chMoveDirection, unsigned int * puPositionClicked, unsigned int * puPositionToMoveTo);

private:
	unsigned int * m_rgBoard;  //representation of the current board
	unsigned int   m_boardSize; //number of Tiles in the board (Row*Col)
	unsigned int   m_sizeRow;   //number of Tiles in a row
	unsigned int   m_sizeCol;   //number of Tiles in a col
	unsigned int   m_iBlank;    //location of the blank tile, (which would be the tile numbered m_sizeBoard - 1)
};
	
};
