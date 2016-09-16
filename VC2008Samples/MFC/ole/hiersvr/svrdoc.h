// svrdoc.h : interface of the CServerDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#define MAX_LEVEL   20

class CServerNode;

class CServerDoc : public COleServerDoc
{
protected: // create from serialization only
	CServerDoc();
	DECLARE_DYNCREATE(CServerDoc)

// Attributes
public:
	LOGFONT m_logfont;          // font in use for the document
	COLORREF m_crText;
	CServerNode* m_pRoot;

	// private clipboard format
	static CLIPFORMAT NEAR m_cfPrivate;

// Operations
public:
	CFont* SelectDocFont(CDC* pDC, CFont& font);
	int CServerDoc::DrawTree(CDC* pDC, CPoint ptStart, CServerNode* pItemSel,
		CServerNode* pRoot = NULL);
	void CalcBounding(CDC* pDC, CServerNode* pItemStart,
		CPoint ptStart, CSize& sizeMax);

// Implementation
public:
	virtual COleServerItem* OnGetEmbeddedItem();
	virtual COleServerItem* OnGetLinkedItem(LPCTSTR lpszItemName);
	virtual ~CServerDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	void SerializeFontInfo(CArchive& ar);
	virtual void DeleteContents();
	virtual void OnSetItemRects(LPCRECT lpPosRect, LPCRECT lpClipRect);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:
	virtual BOOL    OnNewDocument();

// Generated message map functions
protected:
	//{{AFX_MSG(CServerDoc)
	afx_msg void OnOptionsFont();
	afx_msg void OnCancelInplace();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
