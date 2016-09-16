// This is part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// mfcieVw.h : interface of the CMfcieView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MFCIEVIEW_H__47FF4085_CE1B_11D0_BEB6_00C04FC99F83__INCLUDED_)
#define AFX_MFCIEVIEW_H__47FF4085_CE1B_11D0_BEB6_00C04FC99F83__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

class CMfcieView : public CHtmlView
{
protected: // create from serialization only
	CMfcieView();
	DECLARE_DYNCREATE(CMfcieView)

// Attributes
public:
	CMfcieDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMfcieView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	//}}AFX_VIRTUAL
	void OnTitleChange(LPCTSTR lpszText);
	void OnDocumentComplete(LPCTSTR lpszUrl);
	void OnBeforeNavigate2(LPCTSTR lpszURL, DWORD nFlags,
		LPCTSTR lpszTargetFrameName, CByteArray& baPostedData,
		LPCTSTR lpszHeaders, BOOL* pbCancel);

// Implementation
public:
	virtual ~CMfcieView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMfcieView)
	afx_msg void OnGoBack();
	afx_msg void OnGoForward();
	afx_msg void OnGoSearchTheWeb();
	afx_msg void OnGoStartPage();
	afx_msg void OnViewStop();
	afx_msg void OnViewRefresh();
	afx_msg void OnHelpWebTutorial();
	afx_msg void OnHelpOnlineSupport();
	afx_msg void OnHelpMicrosoftOnTheWebFreeStuff();
	afx_msg void OnHelpMicrosoftOnTheWebFrequentlyAskedQuestions();
	afx_msg void OnHelpMicrosoftOnTheWebGetFasterInternetAccess();
	afx_msg void OnHelpMicrosoftOnTheWebMicrosoftHomePage();
	afx_msg void OnHelpMicrosoftOnTheWebSearchTheWeb();
	afx_msg void OnHelpMicrosoftOnTheWebSendFeedback();
	afx_msg void OnHelpMicrosoftOnTheWebInternetStartPage();
	afx_msg void OnHelpMicrosoftOnTheWebBestOfTheWeb();
	afx_msg void OnViewFontsLargest();
	afx_msg void OnViewFontsLarge();
	afx_msg void OnViewFontsMedium();
	afx_msg void OnViewFontsSmall();
	afx_msg void OnViewFontsSmallest();
	afx_msg void OnFileOpen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in mfcieView.cpp
inline CMfcieDoc* CMfcieView::GetDocument()
   { return (CMfcieDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCIEVIEW_H__47FF4085_CE1B_11D0_BEB6_00C04FC99F83__INCLUDED_)
