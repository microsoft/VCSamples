// splitter.h : custom splitter control and frame that contains it
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CSplitterFrame frame with splitter/wiper

class CSplitterFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CSplitterFrame)
protected:
	CSplitterFrame();   // protected constructor used by dynamic creation

// Attributes
protected:
	CSplitterWnd m_wndSplitter;

// Implementation
public:
	virtual ~CSplitterFrame();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

	// Generated message map functions
	//{{AFX_MSG(CSplitterFrame)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
//

class CViewExSplitWnd : public CSplitterWnd
{
	DECLARE_DYNAMIC(CViewExSplitWnd)

// Implementation
public:
	CViewExSplitWnd();
	~CViewExSplitWnd();
	CWnd* GetActivePane(int* pRow = NULL, int* pCol = NULL);
};


/////////////////////////////////////////////////////////////////////////////
//

class C3WaySplitterFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(C3WaySplitterFrame)
protected:
	C3WaySplitterFrame();   // protected constructor used by dynamic creation

// Attributes
protected:
	CViewExSplitWnd m_wndSplitter;
	CViewExSplitWnd m_wndSplitter2;        // embedded in the first

// Implementation
public:
	virtual ~C3WaySplitterFrame();
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);

	// Generated message map functions
	//{{AFX_MSG(C3WaySplitterFrame)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
