// MyListCtrl.h : header file
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
// CMyListCtrl window
#ifndef INC_MYLISTCTRL_H
#define INC_MYLISTCTRL_H


class CMyListCtrl : public CListCtrl
{
// Construction
public:
	CMyListCtrl();

// Attributes
public:

	BOOL            m_bDragging;
	int             m_iItemDrag;
	int             m_iItemDrop;
	CPoint          m_ptHotSpot;
	CPoint          m_ptOrigin;
	CSize           m_sizeDelta;
	DWORD			m_oldDNDStyle;
	CImageList      *m_pimageListDrag;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyListCtrl)
	public:
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyListCtrl();
	void    OnButtonUp(CPoint point);

	// Generated message map functions
protected:
	//{{AFX_MSG(CMyListCtrl)
	afx_msg void OnBeginDrag(LPNMHDR pnmhdr, LRESULT *pResult);
	afx_msg void OnEndLabelEdit(LPNMHDR pnmhdr, LRESULT *pResult);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
#endif
