// threads.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// This sample application is derived from the Mutex application
// distributed with Jeffrey Richter's "Advanced Windows" programming book
// (Microsoft Press).  See the book for more information about Win32
// programming topics, including thread synchronization.

class CMutexesDlg;

class CExampleThread : public CWinThread
{
	DECLARE_DYNCREATE(CExampleThread)
protected:
	CExampleThread();

public:
	CMutexesDlg* m_pOwner;
	BOOL m_bDone;
	void SetOwner(CMutexesDlg* pOwner) { m_pOwner = pOwner; };
};

/////////////////////////////////////////////////////////////////////////////
// CCounterThread thread

class CCounterThread : public CExampleThread
{
	DECLARE_DYNCREATE(CCounterThread)
protected:
	CCounterThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCounterThread)
	public:
	virtual BOOL InitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CCounterThread();

	// Generated message map functions
	//{{AFX_MSG(CCounterThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////
// CDisplayThread thread

class CDisplayThread : public CExampleThread
{
	DECLARE_DYNCREATE(CDisplayThread)
protected:
	CDisplayThread();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisplayThread)
	public:
	virtual BOOL InitInstance();
	virtual int Run();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDisplayThread();

	// Generated message map functions
	//{{AFX_MSG(CDisplayThread)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
