// File: TCSplit.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_TCSPLITTER_H__5808BFE0_5166_11D1_8E54_00C04FB68D60__INCLUDED_)
#define AFX_TCSPLITTER_H__5808BFE0_5166_11D1_8E54_00C04FB68D60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TCSplitter.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CTCSplitter class

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CTCSplitter : public CSplitterWnd
{
	DECLARE_DYNAMIC( CTCSplitter )

public:
	CTCSplitter();           // protected constructor used by dynamic creation

// Attributes
protected:
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTCSplitter)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTCSplitter();

	// Generated message map functions
	//{{AFX_MSG(CTCSplitter)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

   afx_msg HBRUSH OnCtlColor( CDC* pDC, CWnd* pWnd, UINT nCtlColor );

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TCSPLITTER_H__5808BFE0_5166_11D1_8E54_00C04FB68D60__INCLUDED_)
