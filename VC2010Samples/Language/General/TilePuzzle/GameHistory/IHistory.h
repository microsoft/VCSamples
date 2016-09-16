//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


//
// IHistory interface declaration
#ifndef __IHISTORY_H__
#define __IHISTORY_H__

#pragma warning( disable : 4321 )

[export]typedef enum
{
	eError = 0,
	eLeft,
	eRight,
	eUp,
	eDown
} eDirection;

[ dual ]
__interface IHistory 
{ // auto inheritance from IUnknown
	[id(1), helpstring("A test function. Returns the sum of x & y.")]HRESULT Test([in] int x, [in] int y, [out, retval] int* retval);
	[id(2), helpstring("InitGame")]HRESULT InitGame( [in] BSTR boardstate, [in] int cols, [in] int rows );
	[id(3), helpstring("Add a move to the game history")]HRESULT PushMove( [in] eDirection dir );
	[id(4), helpstring("Undo the last move")]HRESULT PopMove( [out, retval] eDirection * dir );
	[id(5), helpstring("Redo the last undone move")]HRESULT RedoMove( [out, retval] eDirection * dir );
	[id(6), helpstring("Is there a move to undo?")]HRESULT CanUndo( [out, retval] boolean * yes_no );
	[id(7), helpstring("Is there a move to redo?")]HRESULT CanRedo( [out, retval] boolean * yes_no );
	[id(8), helpstring("saves a tile game's state")]HRESULT SaveGame( [in] BSTR gamename, [in] BSTR boardstate );
	[id(9), helpstring("retrieves saved tile game state")]HRESULT LoadSavedGame( [in] BSTR gamename, [out] BSTR * boardstate, [out] int * cols, [out] int * rows);
	
	[id(10), helpstring("Test without using retval.")]HRESULT Test2([in] int x, [in] int y, [out] int* retval);
	[id(11), helpstring("PopMove without using retval.")]HRESULT PopMove2( [out] eDirection * dir );
	[id(12), helpstring("RedoMove without using retval.")]HRESULT RedoMove2( [out] eDirection * dir );
	[id(13), helpstring("CanUndo without using retval.")]HRESULT CanUndo2( [out] boolean * yes_no );
	[id(14), helpstring("CanRedo without using retval.")]HRESULT CanRedo2( [out] boolean * yes_no );
};

#endif //__IHISTORY_H__