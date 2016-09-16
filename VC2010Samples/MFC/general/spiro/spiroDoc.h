// spiroDoc.h : interface of the CSpiroDoc class
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

#if !defined(AFX_SPIRODOC_H__4417CF8C_AFA9_11D1_AB61_D9B80632F018__INCLUDED_)
#define AFX_SPIRODOC_H__4417CF8C_AFA9_11D1_AB61_D9B80632F018__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CSpiroDoc;

enum TRACE_COMMAND
{
	EMPTY_COMMAND = -1,
	SET_PEN_WIDTH,
	CHANGE_COLOR,
	MOVE_TO,
	LINE_TO
};

class CFigCommand
{
public:
	TRACE_COMMAND	m_type;

	union
	{
		int			m_nPenWidth;
		COLORREF	m_co;
	};

	CPoint	m_point;  // cannot be in the union  because the compiler chokes 
	CPoint	m_ptWheelPos;  // wheel position for drawing
	double	m_dWheelData;  // used to store any information the wheel wants to store
	double	m_dAnchorData;  // used to stroe any information the anchor wants to store (angle?)

public:
	// constructors and destructors
	CFigCommand() : m_point(0, 0) , m_ptWheelPos(0, 0)
	{
		m_type = EMPTY_COMMAND;
		m_dWheelData = 0.0;
		m_dAnchorData = 0.0;
	}

	virtual void Serialize(CArchive& ar);
};

class CFigure  // a complete figure created with an anchor and a wheel
{
public:

	CSpiroRect	m_rectBound;  // may be improved to store a region instead
	long		m_nTotalTraces;  // number of traces in the figure.
	long		m_nTotalDrawn;   // number of traces already drawn

	CArray<CFigCommand, CFigCommand&>  m_arrCommands;

	long	m_nTracesPerColor;   // how many traces with each color
	long	m_nTracesThisColor;  // trace counter for the current color

public:
	// constructors and destructors
	CFigure();  
	CFigure(CFigure* pFigure);
	~CFigure();

	//operations
	void AddCommand(TRACE_COMMAND com, int nWidth);
	void AddCommand(TRACE_COMMAND com, COLORREF co);
	void AddCommand(TRACE_COMMAND com, CPoint point, CPoint ptWheelPos,
											double dWheelData, double dAnchorData);

	void Clean();
	void Draw(CDC* pDC, long nZoomNumer, long nZoomDenom
											, CRgn* prgnWheel, CSpiroRect* prectClip) const;

	void GetBoundingRect(CRect* lpRect) const;

	// MoveFigure returns false if the figure is off the document (deleted)
	bool MoveFigure(CPoint ptCorner, CSpiroDoc* pDoc);  // new upper left corner for  the bounding rectangle

	void Serialize(CArchive& ar);
};

class CSpiroDoc : public CDocument
{
protected: // create from serialization only
	CSpiroDoc();
	DECLARE_DYNCREATE(CSpiroDoc)

// Attributes
public:
	CSize		m_sizeExtent;		// size of the drawing
	CFigure*	m_pFigureCurrent;  // figure being drawn
	CPtrArray	m_arrPFigures;		// array of figures in the document

// Operations
public:
	void	TransferCurrentFigure(); // move current figure to permanent array

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSpiroDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_bThickPen;
	virtual ~CSpiroDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSpiroDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPIRODOC_H__4417CF8C_AFA9_11D1_AB61_D9B80632F018__INCLUDED_)
