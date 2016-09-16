// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

// MSMTasksPane.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMSMTasksPane window

class CMSMTasksPane : public CMFCTasksPane
{
	DECLARE_DYNAMIC(CMSMTasksPane)

// Construction
public:
	CMSMTasksPane();

// Attributes
public:

// Operations
public:

// Implementation
public:
	virtual ~CMSMTasksPane();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);

	DECLARE_MESSAGE_MAP()
};
