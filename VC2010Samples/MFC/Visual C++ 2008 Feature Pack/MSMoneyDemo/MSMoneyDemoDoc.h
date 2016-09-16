// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
// MSMoneyDemoDoc.h : interface of the CMSMoneyDemoDoc class
//
/////////////////////////////////////////////////////////////////////////////

#pragma once

#define FIRST_HISTORY_COMMAND	0x1000
#define HISTORY_LEN	10

class CMSMoneyDemoDoc : public CDocument
{
protected: // create from serialization only
	CMSMoneyDemoDoc();
	DECLARE_DYNCREATE(CMSMoneyDemoDoc)

// Attributes
public:
// Operations
public:
	BOOL IsBackAvailable () const
	{
		return TRUE;
	}

	BOOL IsFrwdAvailable ()
	{
		return TRUE;
	}

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CMSMoneyDemoDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg void OnGoBack();
	afx_msg void OnUpdateGoBack(CCmdUI* pCmdUI);
	afx_msg void OnGoForward();
	afx_msg void OnUpdateGoForward(CCmdUI* pCmdUI);
	afx_msg void OnGoAddress();
	afx_msg void OnUpdateGoAddress(CCmdUI* pCmdUI);
	afx_msg void OnViewStop();
	afx_msg void OnUpdateViewStop(CCmdUI* pCmdUI);
	afx_msg void OnViewRefresh();
	afx_msg void OnUpdateViewRefresh(CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};
