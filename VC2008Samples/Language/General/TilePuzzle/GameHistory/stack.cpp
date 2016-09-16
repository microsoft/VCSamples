//Copyright (c) Microsoft Corporation.  All rights reserved.

//This source code is intended only as a supplement to Microsoft
//Development Tools and/or on-line documentation.  See these other
//materials for detailed information regarding Microsoft code samples.

//THIS CODE AND INFORMATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY
//KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
//IMPLIED WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//PARTICULAR PURPOSE.


// stack.cpp

#include "stdafx.h"
#include "stack.h"

stacknode * stack::m_head = 0;
boolean stack::end_of_redo_flag = true;

HRESULT stack::reset()
{
	stack::end_of_redo_flag = true;
	m_current = 0;
	return S_OK;
}

HRESULT stack::push(eDirection dir)
{
	try {
		stacknode * newnode = new stacknode(dir, m_current);

		if (m_current == 0)
		{
			if (stack::m_head)
				delete stack::m_head;
			
			m_current = stack::m_head = newnode;
		}
		else
		{
			if (m_current->m_next != 0)		//pushing a new move over an old undone one.
			{
				delete m_current->m_next;	//will cascade to entire chain
			}

			m_current->m_next = newnode;
			m_current = m_current->m_next;
		}
		// we can't redo anymore because the previous redo chain was destroyed.
		stack::end_of_redo_flag = true;
	}
	STACK_CATCH("stack::push: caught an exception!\n");
	return S_OK;
}

HRESULT stack::pop(eDirection * dir)
{
	HRESULT rval = S_OK;

	try {
		// if pop is called before anything has been push'd return error & failure.
		if(0 == m_current)
		{
			*dir = eError;
			return S_FALSE;
		}

		// if no more items on stack return S_FALSE
		if(0 == m_current->m_prev) 
			{ rval = S_FALSE; }

		//	set returned data value.
		*dir = m_current->get_dir();

		//  move the current position.
		m_current = m_current->m_prev;

		// we can redo this.
		stack::end_of_redo_flag = false;

	}
	STACK_CATCH("stack::pop: caught an exception!\n");
	return rval;
}
 
HRESULT stack::redo(eDirection * dir)
{
	HRESULT rval = S_OK;

	try {

// Can't redo anything if nothing is there or if we're at
// the top of the stack and can't redo any more.
		
		if (((0 == m_current) && (0 == stack::m_head)) ||
			(TRUE == stack::end_of_redo_flag))
		{
			*dir = eError;
			return S_FALSE;
		}
		
		if (0 == m_current)
		{
			m_current = stack::m_head;
		}
		else
			m_current = m_current->m_next;
		
		*dir = m_current->get_dir();
		
		if (0 == m_current->m_next)
			stack::end_of_redo_flag = true;
	}
	STACK_CATCH("stack::redo: caught an exception!\n");

	return rval;
}