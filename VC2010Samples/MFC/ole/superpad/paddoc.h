// paddoc.h : interface of the CPadDoc class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#ifndef __PADDOC_H__
#define __PADDOC_H__

class CEmbeddedItem;

class CPadDoc : public COleServerDoc
{
	DECLARE_DYNCREATE(CPadDoc)

// Constructors
public:
	CPadDoc();

//Operations
public:
	void SetSelection(int nBeg, int nEnd);

// Implementation
public:
	virtual COleServerItem* OnGetEmbeddedItem();
	virtual COleServerItem* OnGetLinkedItem(LPCTSTR lpszItemName);

protected:
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
	virtual void DeleteContents();
	virtual ~CPadDoc();

	//{{AFX_MSG(CPadDoc)
	afx_msg void OnViewUpdatenow();
	afx_msg void OnCancelInplace();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	friend class CEmbeddedItem;
};

#endif  // __PADDOC_H__

/////////////////////////////////////////////////////////////////////////////
