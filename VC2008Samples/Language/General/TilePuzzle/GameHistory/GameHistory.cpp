//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


// GameHistory.cpp : Implementation of DLL Exports.

// Note: Proxy/Stub Information
//      To build a separate proxy/stub DLL, 
//      run nmake -f GameHistoryps.mk in the project directory.

#include "stdafx.h"

#include "resource.h"
#include "GameHistory.h"

// The module attribute is specified in order to implement DllMain, DllRegisterServer and DllUnregisterServer
[ module(dll, name = "GameHistory", helpstring = "GameHistory 1.0 Type Library") ];

HRESULT STDMETHODCALLTYPE  CGameHistory::Test(int x, int y, int* retval)
{
#ifdef _DEBUGMSG
	cout << "Just a test" << endl;
	cout << "GameHistory: Test() " << x << " + " << y << " = " << x + y << endl;
#endif //_DEBUGMSG
	*retval = x + y;
	return S_OK;
}

HRESULT STDMETHODCALLTYPE  CGameHistory::InitGame( BSTR boardstate, int cols, int rows )
{
	try 
	{
#ifdef _DEBUGMSG
		cout << "GameHistory: InitGame(BSTR boardstate, int cols, int rows)" <<endl;
#endif //_DEBUGMSG
		m_gamehistory.reset();
		m_boardstate = boardstate;
		m_cols = cols;
		m_rows = rows;
	}
	GAMEHISTORY_CATCH("CGameHistory::InitGame()");
	return S_OK;
}

HRESULT STDMETHODCALLTYPE  CGameHistory::PushMove( eDirection dir )
{
#ifdef _DEBUGMSG
	cout << "\nGameHistory: PushMove Called!\n";
#endif //_DEBUGMSG
	try 
	{
#ifdef _DEBUGMSG
		cout << "GameHistory: PushMove(eDirection dir): dir == " << dir << endl;
#endif // _DEBUGMSG
		return m_gamehistory.push(dir);
	}
	GAMEHISTORY_CATCH("CGameHistory::PushMove()")		
}

HRESULT STDMETHODCALLTYPE  CGameHistory::PopMove( eDirection * dir)
{
	try 
	{
#ifdef _DEBUGMSG
		cout << "GameHistory: PopMove( eDirection * dir): *dir == " << *dir << endl;
#endif //_DEBUGMSG
		return m_gamehistory.pop(dir);
	}
	GAMEHISTORY_CATCH("CGameHistory::PopMove()")		
}

HRESULT STDMETHODCALLTYPE  CGameHistory::RedoMove( eDirection * dir)
{
	try 
	{
#ifdef _DEBUGMSG
		cout << "GameHistory: RedoMove( eDirection *dir): *dir == " << *dir << endl;
#endif //_DEBUGMSG
		return m_gamehistory.redo(dir);
	}
	GAMEHISTORY_CATCH("CGameHistory::RedoMove()")		
}

HRESULT STDMETHODCALLTYPE  CGameHistory::CanUndo(boolean * yes_no)
{
	try 
	{
#ifdef _DEBUGMSG
		cout << "GameHistory: CanUndo()" << endl;
#endif // _DEBUGMSG
		*yes_no = m_gamehistory.can_undo();
		return S_OK;
	}
	GAMEHISTORY_CATCH("CGameHistory::CanUndo()")		
}

HRESULT STDMETHODCALLTYPE  CGameHistory::CanRedo(boolean * yes_no)
{
	try 
	{
#ifdef _DEBUGMSG
		cout << "GameHistory: CanRedo()" << endl;
#endif // _DEBUGMSG
		*yes_no = m_gamehistory.can_redo();
		return S_OK;
	}
	GAMEHISTORY_CATCH("CGameHistory::CanRedo()")		
}

HRESULT STDMETHODCALLTYPE  CGameHistory::SaveGame(BSTR gamename, BSTR boardstate)
{
	HRESULT hr = S_OK;
	ULONG numbytes = 0;
	UINT len = SysStringLen(boardstate);
	IStorage* pOpenStorage = 0;
	IStream * pDataStream = 0;

	try 
	{
#ifdef _DEBUGMSG
		cout << "GameHistory: SaveGame(BSTR gamename, BSTR boardstate): gamename= "<< (_bstr_t)gamename << "  boardstate= " << (_bstr_t)boardstate << endl;
#endif // _DEBUGMSG
	
// Create storage object.	
		hr = StgCreateDocfile(gamename, STGM_DIRECT|STGM_CREATE|STGM_READWRITE|STGM_SHARE_EXCLUSIVE, 0, &pOpenStorage);
		IF_FAILED_RETURN(hr);
	
//Create BoardStateDataLen stream.
		hr = pOpenStorage->CreateStream(L"BoardStateDataLen", STGM_DIRECT|STGM_CREATE|STGM_WRITE|STGM_SHARE_EXCLUSIVE, 0, 0, &pDataStream);
		IF_FAILED_RETURN(hr);
	
//Write data to new stream.
		hr = pDataStream->Write(&len, sizeof(UINT), &numbytes);
		IF_FAILED_MESSAGE_RELEASE_RETURN(hr, pDataStream, "SaveGame() FAILED: pDataStream->Write() to BoardStateDataLen");
		pDataStream->Release();
	
//Create BoardState stream.
		hr = pOpenStorage->CreateStream(L"BoardState", STGM_DIRECT|STGM_CREATE|STGM_WRITE|STGM_SHARE_EXCLUSIVE, 0, 0, &pDataStream);
		IF_FAILED_RETURN(hr);
	
//Write data to new stream.
		hr = pDataStream->Write(boardstate, len, &numbytes);
		IF_FAILED_MESSAGE_RELEASE_RETURN(hr, pDataStream, "SaveGame() FAILED: pDataStream->Write() to BoardState");
		pDataStream->Release();
	
//Create BoardColumns stream.
		hr = pOpenStorage->CreateStream(L"BoardColumns", STGM_DIRECT|STGM_CREATE|STGM_WRITE|STGM_SHARE_EXCLUSIVE, 0, 0, &pDataStream);
		IF_FAILED_RETURN(hr);
	
//Write data to new stream.
		hr = pDataStream->Write(&m_cols, sizeof(UINT), &numbytes);
		IF_FAILED_MESSAGE_RELEASE_RETURN(hr, pDataStream, "SaveGame() FAILED: pDataStream->Write() to BoardColumns");
		pDataStream->Release();
	
//Create BoardRows stream.
		hr = pOpenStorage->CreateStream(L"BoardRows", STGM_DIRECT|STGM_CREATE|STGM_WRITE|STGM_SHARE_EXCLUSIVE, 0, 0, &pDataStream);
		IF_FAILED_RETURN(hr);
	
//Write data to new stream.
		hr = pDataStream->Write(&m_rows, sizeof(UINT), &numbytes);
		IF_FAILED_MESSAGE_RELEASE_RETURN(hr, pDataStream, "SaveGame() FAILED: pDataStream->Write() to BoardRows");
		pDataStream->Release();
	
// Release storage object.
		pOpenStorage->Release();
	}
	GAMEHISTORY_CATCH("CGameHistory::SaveGame()")		
		
	return hr;
}

HRESULT STDMETHODCALLTYPE  CGameHistory::LoadSavedGame(BSTR gamename, BSTR * boardstate, int * cols, int * rows)
{
	HRESULT hr = S_OK;
	ULONG numbytes = 0;
	UINT board_state_data_len = 0;
	IStorage* pOpenStorage = 0;
	IStream * pDataStream = 0;

	try 
	{
// Open storage doc.
		hr = StgOpenStorage( gamename, 0, STGM_DIRECT | STGM_READ | STGM_SHARE_EXCLUSIVE, 0, 0, &pOpenStorage);
		IF_FAILED_RETURN(hr);
		
	
// retrieve the number of bytes of board state data.	
		hr = pOpenStorage->OpenStream(L"BoardStateDataLen", 0, STGM_DIRECT|STGM_READ|STGM_SHARE_EXCLUSIVE, 0, &pDataStream);
		IF_FAILED_RETURN(hr);
	
		hr = pDataStream->Read(&board_state_data_len, sizeof(UINT), &numbytes);
		IF_FAILED_MESSAGE_RELEASE_RETURN(hr, pDataStream, "LoadSavedGame() FAILED: pDataStream->Read() from BoardStateDataLen");
		pDataStream->Release();
	
// retrieve the number of bytes of board state data returned in board_state_data_len.
		hr = pOpenStorage->OpenStream(L"BoardState", 0, STGM_DIRECT|STGM_READ|STGM_SHARE_EXCLUSIVE, 0, &pDataStream);
		IF_FAILED_RETURN(hr);
	
		hr = pDataStream->Read((wchar_t*)m_boardstate, board_state_data_len, &numbytes);
		IF_FAILED_MESSAGE_RELEASE_RETURN(hr, pDataStream, "LoadSavedGame() FAILED: pDataStream->Read() from BoardState");
// Re-Alloc enough storage for the data.
		SysReAllocStringLen( boardstate, m_boardstate, numbytes);
		pDataStream->Release();
	
// retrieve number of columns.
		hr = pOpenStorage->OpenStream(L"BoardColumns", 0, STGM_DIRECT|STGM_READ|STGM_SHARE_EXCLUSIVE, 0, &pDataStream);
		IF_FAILED_RETURN(hr);
	
		hr = pDataStream->Read(&m_cols, sizeof(UINT), &numbytes);
		IF_FAILED_MESSAGE_RELEASE_RETURN(hr, pDataStream, "LoadSavedGame() FAILED: pDataStream->Read() from BoardColumns");
		*cols = m_cols;
		pDataStream->Release();
	
	
// retrieve number of rows
		hr = pOpenStorage->OpenStream(L"BoardRows", 0, STGM_DIRECT|STGM_READ|STGM_SHARE_EXCLUSIVE, 0, &pDataStream);
		IF_FAILED_RETURN(hr);
	
		hr = pDataStream->Read(&m_rows, sizeof(UINT), &numbytes);
		IF_FAILED_MESSAGE_RELEASE_RETURN(hr, pDataStream, "LoadSavedGame() FAILED: pDataStream->Read() from BoardRows");
		*rows = m_rows;
		pDataStream->Release();
	
// release IStorage object.
		pOpenStorage->Release();

#ifdef _DEBUGMSG
		cout << "GameHistory: LoadSavedGame(BSTR gamename, BSTR * boardstate, int * cols, int * rows): gamename= "<< (_bstr_t)gamename 
			<< " boardstate= " << (BSTR)boardstate << " cols= " << *cols << " rows= " << *rows << endl;
#endif // _DEBUGMSG
		}
	GAMEHISTORY_CATCH("CGameHistory::LoadSavedGame()")		
		
	return hr;
}