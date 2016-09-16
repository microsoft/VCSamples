// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

/////////////////////////////////////////////////////////////////////////////
// CCustomToolTipCtrl window

class CCustomToolTipCtrl : public CMFCToolTipCtrl
{
// Construction
public:
	CCustomToolTipCtrl();

// Attributes
public:
	int	m_nCurrID;

// Operations
public:

// Overrides

	virtual CSize GetIconSize ()
	{
		return CSize (32, 32);
	}

	virtual BOOL OnDrawIcon (CDC* pDC, CRect rectImage);

// Implementation
public:
	virtual ~CCustomToolTipCtrl();

protected:
	afx_msg void OnShow(NMHDR* pNMHDR, LRESULT* pResult);

	DECLARE_MESSAGE_MAP()
};
