// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

// MSMCategoryBar.h : header file
//

#include "MSMToolBar.h"

/////////////////////////////////////////////////////////////////////////////
// CMSMCategoryBar window

class CMSMCategoryBar : public CMSMToolBar
{
	DECLARE_DYNCREATE(CMSMCategoryBar)
// Construction
public:
	CMSMCategoryBar ();

	virtual ~CMSMCategoryBar ();

// Attributes
public:

	virtual BOOL RestoreOriginalstate ();

// Operations
public:

// Implementation
public:
	virtual int GetRowHeight () const
				{
					return 1;
				}

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()
};
