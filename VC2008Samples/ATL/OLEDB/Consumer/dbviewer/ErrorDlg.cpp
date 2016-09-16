// ErrorDlg.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes and
// Templates (MFC&T).
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// MFC&T Reference and related electronic documentation provided
// with the library.  See these sources for detailed information
// regarding the MFC&T product.
//

#include "stdafx.h"
#include "dbviewer.h"
#include "ErrorDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CErrorsDialog dialog


CErrorsDialog::CErrorsDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CErrorsDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(CErrorsDialog)
	//}}AFX_DATA_INIT
	m_nSelectedItem = -1;
}


void CErrorsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CErrorsDialog)
	DDX_Control(pDX, IDC_EDIT_GUID, m_ctlGUID);
	DDX_Control(pDX, IDC_LIST_SOURCE, m_ctlListSource);
	DDX_Control(pDX, IDC_EDIT_DESCRIPTION, m_ctlDescription);
	DDX_Control(pDX, IDHELP, m_ctlHelp);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CErrorsDialog, CDialog)
	//{{AFX_MSG_MAP(CErrorsDialog)
	ON_BN_CLICKED(IDHELP, OnHelp)
	ON_LBN_SELCHANGE(IDC_LIST_SOURCE, OnSelChange)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CErrorsDialog message handlers

BOOL CErrorsDialog::OnInitDialog()
{

	CDialog::OnInitDialog();

	// Set the help button to be inactive
	m_ctlHelp.EnableWindow(FALSE);

	// Read in the error information from IErrorRecords
	CDBErrorInfo errInfo;
	ULONG ulRecords = 0;
	HRESULT hr;

	hr = errInfo.GetErrorRecords(m_spUnk, m_iid, &ulRecords);
	if (FAILED(hr) || hr == S_FALSE || ulRecords == 0)
	{
		CString strError;
		if( strError.LoadString(IDS_NOSPECIFIED_SOURCE) == FALSE)
		{
			AfxThrowResourceException();
		}
		m_ctlListSource.AddString(strError);
	}
	else
	{
		LCID lcid = GetUserDefaultLCID();
		for (ULONG l=0; l<ulRecords; l++)
		{
			// Get the error information from the source
			struct MYERRORINFO* pInfo = new MYERRORINFO;
			#pragma warning(disable: 6011) // unexpected null dereference prefast warning
			hr = errInfo.GetAllErrorInfo(l, lcid, &pInfo->bstrDescription,
				&pInfo->bstrSource, &pInfo->guid, &pInfo->dwHelpContext,
				&pInfo->bstrHelpFile);
			#pragma warning(default: 6011) // unexpected null dereference prefast warning
			if (FAILED(hr))
			{
				delete pInfo;
				continue;
			}

			m_listErrorInfo.AddTail(pInfo);

			// Add the information to the list view
			if (pInfo->bstrSource)
				m_ctlListSource.AddString(COLE2T(pInfo->bstrSource));
			else
				m_ctlListSource.AddString(_T("Unspecified error."));
		}
	}
	m_ctlListSource.SetCurSel(0);
	SelectSource(0);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CErrorsDialog::OnHelp()
{
	USES_CONVERSION;

	if (m_nSelectedItem != -1)
	{
		POSITION pos = m_listErrorInfo.FindIndex(m_nSelectedItem);
		struct MYERRORINFO* pInfo = (MYERRORINFO*)m_listErrorInfo.GetAt(pos);

		// Call WinHelp
		::WinHelp(GetSafeHwnd(), COLE2T(pInfo->bstrHelpFile), HELP_CONTEXT,
			pInfo->dwHelpContext);
	}
}

void CErrorsDialog::OnSelChange()
{
	m_nSelectedItem = m_ctlListSource.GetCurSel();
	SelectSource(m_nSelectedItem);
}

void CErrorsDialog::SelectSource(int nSel)
{

	if (m_listErrorInfo.IsEmpty())
	{
		CString strError;
		if( strError.LoadString(IDS_NOSPECIFIED_ERROR) == FALSE)
		{
			AfxThrowResourceException();
		}
		
		m_ctlDescription.SetWindowText(strError);
		m_ctlGUID.SetWindowText(_T(""));
	}
	else
	{
		OLECHAR szGUID[40];
		POSITION pos = m_listErrorInfo.FindIndex(nSel);
		struct MYERRORINFO* pInfo = (MYERRORINFO*)m_listErrorInfo.GetAt(pos);

		m_ctlDescription.SetWindowText(COLE2T(pInfo->bstrDescription));
		::StringFromGUID2(pInfo->guid, szGUID, 40);
		m_ctlGUID.SetWindowText(COLE2T(szGUID));
	}
}
