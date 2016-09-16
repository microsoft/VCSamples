// CntrItem.h : interface of the CMFCBindCntrItem class
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#if !defined(AFX_CNTRITEM_H__C3B1822C_2457_11D1_A4EC_00C04FD91A9F__INCLUDED_)
#define AFX_CNTRITEM_H__C3B1822C_2457_11D1_A4EC_00C04FD91A9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CMFCBindDoc;
class CMFCBindView;

class CMFCBindCntrItem : public COleDocObjectItem
{
	DECLARE_SERIAL(CMFCBindCntrItem)

// Constructors
public:
	CMFCBindCntrItem(CMFCBindDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CMFCBindDoc* GetDocument()
		{ return (CMFCBindDoc*)COleDocObjectItem::GetDocument(); }
	CMFCBindView* GetActiveView()
		{ return (CMFCBindView*)COleDocObjectItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCBindCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	virtual void OnActivate();
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	void LoadFromMoniker(LPUNKNOWN pUnk, OLECHAR* swzName);
	BOOL FinishCreate(SCODE sc);
	void ProcessNewObject();

	static int m_nDocID;

	~CMFCBindCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CNTRITEM_H__C3B1822C_2457_11D1_A4EC_00C04FD91A9F__INCLUDED_)
