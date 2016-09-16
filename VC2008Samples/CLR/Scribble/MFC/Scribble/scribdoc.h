#pragma once
// ScribDoc.h : interface of the CScribbleDoc class
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


// Forward declaration of data structure class
class CScribbleItem;

/////////////////////////////////////////////////////////////////////////////
// class CStroke
//
// A stroke is a series of connected points in the scribble drawing.
// A scribble document may have multiple strokes.

class CStroke : public CObject
{
public:
	CStroke(UINT nPenWidth, UINT penColor);

protected:
	CStroke();
	DECLARE_SERIAL(CStroke)

// Attributes
protected:
	UINT                   m_nPenWidth;    // one pen width applies to entire stroke
	UINT				   m_penColor;     // the pen color of the stroke
public:
	CArray<CPoint,CPoint>  m_pointArray;   // series of connected points
	CRect               m_rectBounding; // smallest rect that surrounds all
										// of the points in the stroke
										// measured in MM_LOENGLISH units
										// (0.01 inches, with Y-axis inverted)
public:
	CRect& GetBoundingRect() { return m_rectBounding; }

// Operations
public:
	BOOL DrawStroke(CDC* pDC);
	void FinishStroke();

public:
	virtual void Serialize(CArchive& ar);
};



class CScribbleDoc : public COleServerDoc
{
protected: // create from serialization only
	CScribbleDoc();
	DECLARE_DYNCREATE(CScribbleDoc)

// Attributes
protected:
	// The document keeps track of the current pen width on
	// behalf of all views. We'd like the user interface of
	// Scribble to be such that if the user chooses the Draw
	// Thick Line command, it will apply to all views, not just
	// the view that currently has the focus.

	UINT            m_nPenWidth;        // current user-selected pen width
	BOOL            m_bThickPen;        // TRUE if current pen is thick
	UINT            m_nThinWidth;
	UINT            m_nThickWidth;
	CPen            m_penCur;           // pen created according to
										// user-selected pen style (width)
public:
	CTypedPtrList<CObList,CStroke*>     m_strokeList;   
	CPen*           GetCurrentPen() { return &m_penCur; }
	void			SetPenColor(COLORREF c);
	COLORREF		GetPenColor() { return m_penColor; }
protected:
	CSize           m_sizeDoc;
	UINT			m_penColor; 
public:
	CSize GetDocSize() { return m_sizeDoc; }
	CScribbleItem* GetEmbeddedItem()
		{ return (CScribbleItem*)COleServerDoc::GetEmbeddedItem(); }

// Operations
public:
	CStroke* NewStroke();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScribbleDoc)
	protected:
	virtual COleServerItem* OnGetEmbeddedItem();
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void DeleteContents();
	//}}AFX_VIRTUAL

// Implementation
protected:
	void ReplacePen();
	void OnSetItemRects(LPCRECT lpPosRect, LPCRECT lpClipRect);

public:
	virtual ~CScribbleDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void            InitDocument();

// Generated message map functions
protected:
	//{{AFX_MSG(CScribbleDoc)
	afx_msg void OnEditClearAll();
	afx_msg void OnPenThickOrThin();
	afx_msg void OnUpdateEditClearAll(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePenThickOrThin(CCmdUI* pCmdUI);
	afx_msg void OnPenWidths();
	afx_msg void OnEditCopy();
	afx_msg void OnSelectPlugin(UINT menuID);
	afx_msg void OnUpdatePlugin(CCmdUI* pCmdUI);
	afx_msg void OnSelectWebServiceAddRec();
	afx_msg void OnUpdateWebServiceAddRec(CCmdUI* pCmdUI);
	afx_msg void OnSelectWebServiceAddCir();
	afx_msg void OnUpdateWebServiceAddCir(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

