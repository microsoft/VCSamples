// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "drawobj.h"
#include "summinfo.h"

class CDrawView;

class CDrawDoc : public COleDocument
{
protected: // create from serialization only
	CDrawDoc();
	DECLARE_DYNCREATE(CDrawDoc)

// Attributes
public:
	CDrawObjList* GetObjects() { return &m_objects; }
	const CSize& GetSize() const { return m_size; }
	void ComputePageSize();
	int GetMapMode() const { return m_nMapMode; }
	COLORREF GetPaperColor() const { return m_paperColor; }
	CSummInfo *m_pSummInfo;

	BOOL CanDeactivateInplace() const
	{
		return m_bCanDeactivateInplace;
	}

// Operations
public:
	CDrawObj* ObjectAt(const CPoint& point);
	void Draw(CDC* pDC, CDrawView* pView);
	// ------ Draw called for live icon and Win7 taskbar thumbnails
	void Draw (CDC* pDC);
	void FixUpObjectPositions();
	CRect m_rectDocumentBounds;
	// ------

	void Add(CDrawObj* pObj);
	void Remove(CDrawObj* pObj);

	void SetPreviewColor(COLORREF clr);

#ifdef SHARED_HANDLERS
	// Search support
	virtual void InitializeSearchContent();

	// Set properties for search
	void SetTitle(const CString& value);
	void SetAuthor(const CString& value);
	void SetCompany(const CString& value);
	void SetComment(const CString& value);
	void SetCopyright(const CString& value);
	void SetKeywords(const CString& value);
	void SetLastAuthor(const CString& value);
	void SetSearchContents(const CString& value);
#endif

// Implementation
public:
	virtual ~CDrawDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnNewDocument();
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
	virtual void OnUnloadHandler();

	BOOL m_bCanDeactivateInplace;

	CDrawObjList m_objects;
	CSize m_size;
	int m_nMapMode;
	COLORREF m_paperColor;
	COLORREF m_paperColorLast;

protected:
	//{{AFX_MSG(CDrawDoc)
	afx_msg void OnViewPaperColor();
	afx_msg void OnFileSummaryInfo();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
