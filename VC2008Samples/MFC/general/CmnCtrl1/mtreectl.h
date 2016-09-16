// MyTreeCtrl.h : header file
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#ifndef INC_MYTREECTRL_H
#define INC_MYTREECTRL_H
/////////////////////////////////////////////////////////////////////////////
// CMyTreeCtrl window

class CMyTreeCtrl : public CTreeCtrl
{
// Construction
public:
	CMyTreeCtrl();

// Attributes
public:
	BOOL        m_bDragging;
	HTREEITEM   m_hitemDrag;
	HTREEITEM   m_hitemDrop;
	CImageList  *m_pimagelist;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyTreeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyTreeCtrl();
	void    SetNewStyle(long lStyleMask, BOOL bSetBits);
	BOOL    TransferItem(HTREEITEM hitem, HTREEITEM hNewParent);
	void    OnButtonUp(void);
	BOOL    IsChildNodeOf(HTREEITEM hitemChild, HTREEITEM hitemSuspectedParent);

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyTreeCtrl)
	afx_msg void OnEndLabelEdit(LPNMHDR pnmhdr, LRESULT *pLResult);
	afx_msg void OnBeginDrag(LPNMHDR pnmhdr, LRESULT *pLResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	//}}AFX_MSG

	void OnButtonUp(CPoint point);

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

#endif
