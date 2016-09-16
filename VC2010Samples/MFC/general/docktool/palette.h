// palette.h : interface of the CPaletteBar class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

class CPaletteBar : public CToolBar
{
// Constructor
public:
	CPaletteBar();
	void SetColumns(UINT nColumns);
	UINT GetColumns() { return m_nColumns; };

// Attributes
public:

// Operations
public:

// Implementation
public:
	virtual ~CPaletteBar();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	UINT    m_nColumns;

// Generated message map functions
protected:
	//{{AFX_MSG(CPaletteBar)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
