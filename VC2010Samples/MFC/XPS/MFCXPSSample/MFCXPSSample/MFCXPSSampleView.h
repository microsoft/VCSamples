
// MFCXPSSampleView.h : interface of the CMFCXPSSampleView class
//


#pragma once


class CMFCXPSSampleView : public CHtmlView
{
protected: // create from serialization only
	CMFCXPSSampleView();
	DECLARE_DYNCREATE(CMFCXPSSampleView)

// Attributes
public:
	CMFCXPSSampleDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // called first time after construct
	void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);

// Implementation
public:
	virtual ~CMFCXPSSampleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnFilePrint();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()

	void UpdateView();
};

#ifndef _DEBUG  // debug version in MFCXPSSampleView.cpp
inline CMFCXPSSampleDoc* CMFCXPSSampleView::GetDocument() const
   { return reinterpret_cast<CMFCXPSSampleDoc*>(m_pDocument); }
#endif

