// CustomFileDialog.cpp : implementation file
//

#include "stdafx.h"
#include "FileDlgWatcher.h"
#include "CustomFileDialog.h"


// CCustomFileDialog

IMPLEMENT_DYNAMIC(CCustomFileDialog, CFileDialog)

CCustomFileDialog::CCustomFileDialog(BOOL bOpenFileDialog,
									 BOOL bVistaStyle,
									 BOOL bEventPopups,
									 CString &strLog) :
	CFileDialog(bOpenFileDialog, NULL, NULL,
				OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, NULL, NULL, 0,
				bVistaStyle),
	m_bEventPopups(bEventPopups),
	m_strLog(strLog)
{
}

CCustomFileDialog::~CCustomFileDialog() { }

void CCustomFileDialog::LogEvent(LPCWSTR eventMsg)
{
	if (m_bEventPopups)
	{
		::MessageBox(this->m_hWnd, eventMsg, _T("Event Triggered"), 0);
	}
	m_strLog += _T("Event: ");
	m_strLog += eventMsg;
	m_strLog +=	_T("\r\n");
}

BEGIN_MESSAGE_MAP(CCustomFileDialog, CFileDialog)
END_MESSAGE_MAP()

void CCustomFileDialog::OnFileNameChange()
{
	LogEvent(_T("OnFileNameChange"));
	CFileDialog::OnFileNameChange();
}

BOOL CCustomFileDialog::OnFileNameOK()
{
	LogEvent(_T("OnFileNameOK"));
	return CFileDialog::OnFileNameOK();
}

void CCustomFileDialog::OnFolderChange()
{
	LogEvent(_T("OnFolderChange"));
	CFileDialog::OnFolderChange();
}

void CCustomFileDialog::OnInitDone()
{
	LogEvent(_T("OnInitDone"));
	CFileDialog::OnInitDone();
}

void CCustomFileDialog::OnLBSelChangedNotify(UINT nIDBox, UINT iCurSel,
											 UINT nCode)
{
	LogEvent(_T("OnLBSelChangedNotify"));
	CFileDialog::OnLBSelChangedNotify(nIDBox, iCurSel, nCode);
}

UINT CCustomFileDialog::OnShareViolation(LPCTSTR lpszPathName)
{
	LogEvent(_T("OnShareViolation"));
	return CFileDialog::OnShareViolation(lpszPathName);
}

void CCustomFileDialog::OnTypeChange()
{
	LogEvent(_T("OnTypeChange"));
	CFileDialog::OnTypeChange();
}

BOOL CCustomFileDialog::OnInitDialog()
{
	LogEvent(_T("OnInitDialog"));
	return CFileDialog::OnInitDialog();
}
void CCustomFileDialog::OnOK()
{
	LogEvent(_T("OnOK"));
	CFileDialog::OnOK();
}

void CCustomFileDialog::OnCancel()
{
	LogEvent(_T("OnCancel"));
	CFileDialog::OnCancel();
}

void CCustomFileDialog::OnSetFont(CFont *pFont)
{
	LogEvent(_T("OnSetFont"));
	CFileDialog::OnSetFont(pFont);
}

// CCustomFileDialog message handlers
