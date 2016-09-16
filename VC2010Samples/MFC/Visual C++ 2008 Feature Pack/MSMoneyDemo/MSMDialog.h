// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#pragma once

// MSMDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMSMDialog dialog

class CMSMDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMSMDialog)

// Construction
public:
	CMSMDialog();
	CMSMDialog(UINT nIDTemplate, CWnd* pParentWnd = NULL);
	CMSMDialog(LPCTSTR lpszTemplateName, CWnd *pParentWnd = NULL);

// Implementation
protected:
	void CommonConstruct ();

	DECLARE_MESSAGE_MAP()
};
