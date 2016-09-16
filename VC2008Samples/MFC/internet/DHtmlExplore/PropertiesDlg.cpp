// PropertiesDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "DHtmlExplore.h"
#include "PropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg dialog


CPropertiesDlg::CPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDHtmlDialog(CPropertiesDlg::IDD, 0, pParent)
{
	//{{AFX_DATA_INIT(CPropertiesDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_dwFileAttributes = 0;
	m_nReadOnly = 0;
	m_nArchive = 0;
	m_nHidden = 0;
	m_nSystem = 0;
}


void CPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertiesDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
	DDX_DHtml_ElementInnerText(pDX, _T("filename"), m_strFileName);
	DDX_DHtml_ElementInnerText(pDX, _T("filetype"), m_strType);
	DDX_DHtml_ElementInnerText(pDX, _T("filesize"), m_strFileSize);
	DDX_DHtml_ElementInnerText(pDX, _T("createtime"), m_strCreationTime);
	DDX_DHtml_ElementInnerText(pDX, _T("modifiedtime"), m_strModificationTime);
	DDX_DHtml_ElementInnerText(pDX, _T("accessedtime"), m_strAccessTime);
	DDX_DHtml_CheckBox(pDX, _T("readonly"), m_nReadOnly);
	DDX_DHtml_CheckBox(pDX, _T("archive"), m_nArchive);
	DDX_DHtml_CheckBox(pDX, _T("hidden"), m_nHidden);
	DDX_DHtml_CheckBox(pDX, _T("system"), m_nSystem);
}


BEGIN_MESSAGE_MAP(CPropertiesDlg, CDHtmlDialog)
	//{{AFX_MSG_MAP(CPropertiesDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg message handlers

BOOL CPropertiesDlg::OnInitDialog() 
{
	SetHostFlags(DOCHOSTUIFLAG_FLAT_SCROLLBAR);

	CDHtmlDialog::OnInitDialog();
	
	// get the properties of the file
	WIN32_FIND_DATA finddata;
	HANDLE hFind = FindFirstFile(m_strFileName, &finddata);
	FindClose(hFind);

	if (hFind == INVALID_HANDLE_VALUE)
		// File was not found.
		return TRUE;

	// copy the file data to internal members
	m_strType = finddata.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ? 
		_T("Directory") : _T("File");
	m_strFileSize.Format(_T("%lu"), finddata.nFileSizeLow);
	m_strCreationTime = CTime(finddata.ftCreationTime).Format(_T("%A, %B %d, %Y"));
	m_strModificationTime = CTime(finddata.ftLastWriteTime).Format(_T("%A, %B %d, %Y"));
	m_strAccessTime = CTime(finddata.ftLastAccessTime).Format(_T("%A, %B %d, %Y"));
	m_dwFileAttributes = finddata.dwFileAttributes;

	m_nReadOnly = (m_dwFileAttributes & FILE_ATTRIBUTE_READONLY) ? BST_CHECKED : BST_UNCHECKED;
	m_nHidden = (m_dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) ? BST_CHECKED : BST_UNCHECKED;
	m_nArchive = (m_dwFileAttributes & FILE_ATTRIBUTE_ARCHIVE) ? BST_CHECKED : BST_UNCHECKED;
	m_nSystem = (m_dwFileAttributes & FILE_ATTRIBUTE_SYSTEM) ? BST_CHECKED : BST_UNCHECKED;
	
	LoadFromResource(IDR_PROPERTIES);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
