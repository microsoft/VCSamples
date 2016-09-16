// ConfigDlg.cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "stdafx.h"
#include "DllScreenCap.h"
#include "ConfigDlg.h"


// CConfigDlg dialog

IMPLEMENT_DYNAMIC(CConfigDlg, CDialog)
CConfigDlg::CConfigDlg(BOOL bFullScreen, LPCTSTR szPath, CWnd* pParent /*=NULL*/)
	: CDialog(CConfigDlg::IDD, pParent)
	, m_strPath(szPath)
	, m_nFullScreen(bFullScreen)
{
}

CConfigDlg::~CConfigDlg()
{
}

void CConfigDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_PATH, m_strPath);
	DDV_MaxChars(pDX, m_strPath, 255);
	DDX_Radio(pDX, IDC_WINDOW, m_nFullScreen);
}


BEGIN_MESSAGE_MAP(CConfigDlg, CDialog)
ON_BN_CLICKED(IDC_BROWSE, OnBnClickedBrowse)
END_MESSAGE_MAP()


// CConfigDlg message handlers

void CConfigDlg::OnBnClickedBrowse(void)
{
	HRESULT hr;
	LPITEMIDLIST pItemList;
	BROWSEINFO browseinfo;
	TCHAR path[MAX_PATH];
	hr = ::CoInitializeEx(NULL, COINIT_APARTMENTTHREADED);
	if (FAILED(hr)) {
		TRACE("CoInitEx failed: %x\n", hr);
		return;
	}

	IMalloc *pMalloc = NULL;
	hr = SHGetMalloc(&pMalloc);
	if (FAILED(hr)) {
		TRACE("Can't retrieve system's IMalloc interface: %x\n", hr);
		return;
	}
	ENSURE(pMalloc);

	memset(&browseinfo, 0, sizeof(BROWSEINFO));
	CString strCaption;
	browseinfo.hwndOwner = GetSafeHwnd();
	browseinfo.pszDisplayName = path;
	browseinfo.ulFlags = BIF_NEWDIALOGSTYLE | BIF_RETURNONLYFSDIRS;
	strCaption.LoadString(IDS_CONFIG_CAPTION);
	browseinfo.lpszTitle = strCaption;

	pItemList = ::SHBrowseForFolder(&browseinfo);
	if (pItemList) {
		// Behold the elegance of CStrBuf!
		::SHGetPathFromIDList(pItemList, CStrBuf(m_strPath, MAX_PATH));
		pMalloc->Free(pItemList);
		UpdateData(FALSE);
	}
	pMalloc->Release();
	pMalloc = NULL;
	::CoUninitialize();
}
