// splitter.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "viewex.h"
#include "splitter.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSplitterFrame

// Create a splitter window which splits an output text view and an input view
//                           |
//    TEXT VIEW (CTextView)  | INPUT VIEW (CInputView)
//                           |

IMPLEMENT_DYNCREATE(CSplitterFrame, CMDIChildWnd)

CSplitterFrame::CSplitterFrame()
{
}

CSplitterFrame::~CSplitterFrame()
{
}


BOOL CSplitterFrame::OnCreateClient(LPCREATESTRUCT,
	 CCreateContext* pContext)
{
	// create a splitter with 1 row, 2 columns
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStaticSplitter\n");
		return FALSE;
	}

	// add the first splitter pane - the default view in column 0
	if (!m_wndSplitter.CreateView(0, 0,
		pContext->m_pNewViewClass, CSize(130, 50), pContext))
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}

	// add the second splitter pane - an input view in column 1
	if (!m_wndSplitter.CreateView(0, 1,
		RUNTIME_CLASS(CInputView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create second pane\n");
		return FALSE;
	}

	// activate the input view
	SetActiveView((CView*)m_wndSplitter.GetPane(0,1));

	return TRUE;
}

BEGIN_MESSAGE_MAP(CSplitterFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CSplitterFrame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// C3WaySplitterFrame - just like CSplitterFrame except the input view is
//   the first pane, and there are two output views

//                             |  Text View (CTextView)
//    INPUT VIEW (CInputView)  |------------------------
//                             |  Color View (CColorView)

IMPLEMENT_DYNCREATE(C3WaySplitterFrame, CMDIChildWnd)

C3WaySplitterFrame::C3WaySplitterFrame()
{
}

C3WaySplitterFrame::~C3WaySplitterFrame()
{
}


BOOL C3WaySplitterFrame::OnCreateClient(LPCREATESTRUCT lpcs,
	 CCreateContext* pContext)
{
	// create a splitter with 1 row, 2 columns
	if (!m_wndSplitter.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to CreateStaticSplitter\n");
		return FALSE;
	}

	// add the first splitter pane - the default view in column 0
	if (!m_wndSplitter.CreateView(0, 0,
		pContext->m_pNewViewClass, CSize(200, 50), pContext))
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}

	// add the second splitter pane - which is a nested splitter with 2 rows
	if (!m_wndSplitter2.CreateStatic(
		&m_wndSplitter,     // our parent window is the first splitter
		2, 1,               // the new splitter is 2 rows, 1 column
		WS_CHILD | WS_VISIBLE | WS_BORDER,  // style, WS_BORDER is needed
		m_wndSplitter.IdFromRowCol(0, 1)
			// new splitter is in the first row, 2nd column of first splitter
	   ))
	{
		TRACE0("Failed to create nested splitter\n");
		return FALSE;
	}

	// now create the two views inside the nested splitter
	int cyText = max(lpcs->cy - 70, 20);    // height of text pane

	if (!m_wndSplitter2.CreateView(0, 0,
		RUNTIME_CLASS(CTextView), CSize(0, cyText), pContext))
	{
		TRACE0("Failed to create second pane\n");
		return FALSE;
	}
	if (!m_wndSplitter2.CreateView(1, 0,
		RUNTIME_CLASS(CColorView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create third pane\n");
		return FALSE;
	}

	// it all worked, we now have two splitter windows which contain
	//  three different views
	return TRUE;
}

BEGIN_MESSAGE_MAP(C3WaySplitterFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(C3WaySplitterFrame)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
//

IMPLEMENT_DYNAMIC(CViewExSplitWnd, CSplitterWnd)

CViewExSplitWnd::CViewExSplitWnd()
{
}

CViewExSplitWnd::~CViewExSplitWnd()
{
}

CWnd* CViewExSplitWnd::GetActivePane(int* /*pRow*/, int* /*pCol*/)
{
	ASSERT_VALID(this);

	// attempt to use active view of frame window
	CWnd* pView = NULL;
	CFrameWnd* pFrameWnd = GetParentFrame();
	ASSERT_VALID(pFrameWnd);
	pView = pFrameWnd->GetActiveView();

	// failing that, use the current focus
	if (pView == NULL)
		pView = GetFocus();

	return pView;
}
