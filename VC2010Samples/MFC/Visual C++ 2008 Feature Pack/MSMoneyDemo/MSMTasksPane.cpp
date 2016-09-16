// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// MSMTasksPane.cpp : implementation file
//

#include "stdafx.h"
#include "msmoneydemo.h"
#include "MSMTasksPane.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMSMTasksPane

IMPLEMENT_DYNAMIC(CMSMTasksPane, CMFCTasksPane)

CMSMTasksPane::CMSMTasksPane()
{
	m_bWrapTasks = TRUE;
	m_bWrapLabels = TRUE;
}

CMSMTasksPane::~CMSMTasksPane()
{
}


BEGIN_MESSAGE_MAP(CMSMTasksPane, CMFCTasksPane)
	ON_WM_CREATE()
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMSMTasksPane message handlers

int CMSMTasksPane::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CMFCTasksPane::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	int nGroup = AddGroup (_T(""));

	COleDateTime now = COleDateTime::GetCurrentTime ();
	CString strDate = now.Format (_T("%B %d, %Y"));

	AddLabel (nGroup, strDate, -1, TRUE);

	AddLabel (nGroup, _T(" "));
	AddLabel (nGroup, _T(" "));
	
	AddLabel (nGroup, _T("Common tasks"), -1, TRUE);
	AddSeparator (nGroup);

	AddTask (nGroup, _T("Learn more about new MFC cool and fresh features"), -1, ID_HELP_MICROSOFT);

	return 0;
}
