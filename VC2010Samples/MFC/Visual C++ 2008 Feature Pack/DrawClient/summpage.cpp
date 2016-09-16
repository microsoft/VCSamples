// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

#include "stdafx.h"
#include "DrawClient.h"
#include "summpage.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CSummPage property page

IMPLEMENT_DYNCREATE(CSummPage, CPropertyPage)

CSummPage::CSummPage() : CPropertyPage(CSummPage::IDD)
{
	//{{AFX_DATA_INIT(CSummPage)
	m_strAuthor = _T("");
	m_strKeywd = _T("");
	m_strSubj = _T("");
	m_strCmt = _T("");
	m_strTempl = _T("");
	m_strTitle = _T("");
	m_strAppname = _T("");
	//}}AFX_DATA_INIT
}

CSummPage::~CSummPage()
{
}

void CSummPage::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSummPage)
	DDX_Text(pDX, IDC_AUTHOR, m_strAuthor);
	DDX_Text(pDX, IDC_KEYWORDS, m_strKeywd);
	DDX_Text(pDX, IDC_SUBJECT, m_strSubj);
	DDX_Text(pDX, IDC_COMMENTS, m_strCmt);
	DDX_Text(pDX, IDC_TEMPLATE, m_strTempl);
	DDX_Text(pDX, IDC_TITLE, m_strTitle);
	DDX_Text(pDX, IDC_APPNAME, m_strAppname);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSummPage, CPropertyPage)
	//{{AFX_MSG_MAP(CSummPage)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
