//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


/* MIDL: this ALWAYS GENERATED file contains the definitions for the interfaces */

#ifndef __GAMEHISTORY_H__
#define __GAMEHISTORY_H__

#pragma warning( disable : 4323 )

#include "IHistory.h"	//IHistory Declaration
#include "stack.h"

#define IF_FAILED_RETURN(hr) if(FAILED(hr)) return hr;
#define IF_FAILED_MESSAGE_RELEASE_RETURN(hr, ptr, msg)					\
						if(FAILED(hr))									\
						{												\
							cout << "GameHistory: " << msg << endl;		\
							ptr->Release();								\
							return hr;									\
						}
#define GAMEHISTORY_CATCH(msg)                   \
	catch(_com_error &e)                         \
	{                                            \
		printf("%s: COM Exception!\n", msg);     \
        dump_com_error(e);                       \
		return S_FALSE;                          \
    }                                            \
	catch(...)                                   \
	{                                            \
		printf("%s: Unknown Exception!\n", msg); \
		return S_FALSE;                          \
    }


void dump_com_error(_com_error &e)
{
    printf("COM Exception!\n");
    printf("\a\tCode = %08lx\n", e.Error());
    printf("\a\tCode meaning = %s\n", e.ErrorMessage());
    _bstr_t bstrSource(e.Source());
    _bstr_t bstrDescription(e.Description());
    printf("\a\tSource = %s\n", (LPCTSTR) bstrSource);
    printf("\a\tDescription = %s\n", (LPCTSTR) bstrDescription);
}

[ coclass ] 			// automatically implements IUnknown for IHistory using ATL
struct CGameHistory : IHistory 
{
	// IHistory
	STDMETHOD(Test)(int x, int y, int* retval);
	STDMETHOD(InitGame)( BSTR boardstate, int cols, int rows );
	STDMETHOD(PushMove)( eDirection dir);
	STDMETHOD(PopMove)( eDirection * dir);
	STDMETHOD(RedoMove)( eDirection * dir );
	STDMETHOD(CanUndo)( boolean * yes_no );
	STDMETHOD(CanRedo)( boolean * yes_no );
	STDMETHOD(SaveGame)( BSTR gamename, BSTR boardstate );
	STDMETHOD(LoadSavedGame)( BSTR gamename, BSTR * boardstate, int * cols, int * rows);

	STDMETHOD(Test2)(int x, int y, int* z){ try { return Test(x,y,z); } GAMEHISTORY_CATCH("Test2()"); };
	STDMETHOD(PopMove2)( eDirection * dir){ try { return PopMove(dir); } GAMEHISTORY_CATCH("PopMove2()"); };
	STDMETHOD(RedoMove2)( eDirection * dir ){ try { return RedoMove(dir); } GAMEHISTORY_CATCH("RedoMove2()"); };
	STDMETHOD(CanUndo2)( boolean * yes_no ){ try { return CanUndo(yes_no); } GAMEHISTORY_CATCH("CanUndo2()"); };
	STDMETHOD(CanRedo2)( boolean * yes_no ){ try { return CanRedo(yes_no); } GAMEHISTORY_CATCH("CanRedo2()"); };
	
	CGameHistory() : m_cRef(1), m_boardstate(L""), m_cols(0), m_rows(0){;}
	~CGameHistory() { 

#ifdef _DEBUGMSG	
		cout << "GameHistory: ~CGameHistory()" << endl; 
#endif // _DEBUGMSG
	
	}

private:
	ULONG m_cRef;
	stack m_gamehistory;
	_bstr_t m_boardstate;
	int m_cols;
	int m_rows;
};
#endif //__GAMEHISTORY_H__