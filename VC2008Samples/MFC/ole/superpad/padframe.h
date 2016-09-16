// padframe.h : header file
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
// CPadFrame frame

class CPadFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CPadFrame)
protected:

// Attributes
public:

// Operations
public:
	static void Initialize();
	static void Terminate();

// Implementation
protected:
	void ActivateFrame(int nCmdShow);

	// Generated message map functions
	//{{AFX_MSG(CPadFrame)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	static int m_nDefCmdShow;
	static int m_nDefCmdShowOld;
};

/////////////////////////////////////////////////////////////////////////////
