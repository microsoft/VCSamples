//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


#ifndef __STACK_H__
#define __STACK_H__

#include "stdafx.h"
#include "IHistory.h"		// for eDirection declaration.

using namespace std;

#define STACK_CATCH(msg)  \
	catch(...)		      \
	{                     \
		cout << msg;      \
		throw;            \
		return S_FALSE;   \
	}

class stacknode
{
	friend class stack;

	stacknode(eDirection dir, stacknode * prev)
			: m_dir(dir), m_prev(prev), m_next(0){;}

	~stacknode()
	{
		// this should delete and entire chain below this node.
		if(m_next != 0) 
			delete m_next;
	}

	eDirection get_dir(void){ return m_dir; }

	stacknode * m_prev;
	stacknode * m_next;
	eDirection m_dir;
};


class stack
{
public:
	stack(): m_current(0){};
	
	~stack(){ m_current = stack::m_head; delete m_current; }

	HRESULT push( eDirection dir );
	HRESULT pop( eDirection * dir );
	HRESULT redo( eDirection * dir );
	
	HRESULT reset();

	boolean can_redo(){ return !end_of_redo_flag; } 
	boolean can_undo() {  
#ifdef _DEBUGMSG		
							cout << (0!=m_current);
#endif //_DEBUGMSG
							return (0!=m_current); }

private:
	stacknode * m_current;
	static stacknode * m_head;
	static boolean end_of_redo_flag;
};

#endif	//__STACK_H__