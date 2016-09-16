// mtbounce.h : Declares the class interfaces for the Bounce
//              user interface thread.
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
// CBounceThread thread

class CBounceThread : public CWinThread
{
	DECLARE_DYNCREATE(CBounceThread)
protected:
	CBounceThread();           // protected constructor used by dynamic creation
public:
	CBounceThread(HWND hwndParent);
	void operator delete(void* p);

// Attributes
public:
	static HANDLE m_hEventBounceThreadKilled;

protected:
	HWND m_hwndParent;
	CBounceWnd m_wndBounce;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBounceThread)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBounceThread();

	// Generated message map functions
	//{{AFX_MSG(CBounceThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
