// trackdoc.h : interface of the CTrackerDoc class
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

class CTrackerDoc : public CDocument
{
protected: // create from serialization only
	CTrackerDoc();
	DECLARE_DYNCREATE(CTrackerDoc)

// Attributes
public:
	CRectTracker m_tracker;
	BOOL m_bAllowInvert;

// Operations
public:

// Implementation
public:
	virtual ~CTrackerDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	virtual BOOL    OnNewDocument();

// Generated message map functions
protected:
	//{{AFX_MSG(CTrackerDoc)
	afx_msg void OnEditDottedline();
	afx_msg void OnUpdateEditDottedline(CCmdUI* pCmdUI);
	afx_msg void OnEditHatchedborder();
	afx_msg void OnUpdateEditHatchedborder(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEditHatchedinside(CCmdUI* pCmdUI);
	afx_msg void OnEditHatchedinside();
	afx_msg void OnEditResizeinside();
	afx_msg void OnUpdateEditResizeinside(CCmdUI* pCmdUI);
	afx_msg void OnEditResizeoutside();
	afx_msg void OnUpdateEditResizeoutside(CCmdUI* pCmdUI);
	afx_msg void OnEditSolidline();
	afx_msg void OnUpdateEditSolidline(CCmdUI* pCmdUI);
	afx_msg void OnEditAllowInvert();
	afx_msg void OnUpdateEditAllowInvert(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
