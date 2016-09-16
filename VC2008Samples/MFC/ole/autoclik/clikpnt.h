// ClikPnt.h : header file
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
// CAutoClickPoint command target

class CAutoClickPoint : public CCmdTarget
{
	DECLARE_DYNCREATE(CAutoClickPoint)

	CAutoClickPoint();           // protected constructor used by dynamic creation

// Attributes
public:

// Operations
public:
	CPoint GetClickPoint() { return CPoint(m_x, m_y); }
	void SetClickPoint(CPoint point) { m_x = (short)point.x; m_y = (short)point.y; }

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoClickPoint)
	public:
	virtual void OnFinalRelease();
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CAutoClickPoint();

	// Generated message map functions
	//{{AFX_MSG(CAutoClickPoint)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

public:
	DECLARE_MESSAGE_MAP()
	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CAutoClickPoint)
	short m_x;
	short m_y;
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
