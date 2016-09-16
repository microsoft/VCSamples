// autoddlg.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
using namespace ACDual;
#include "autodriv.h"
#include "autoddlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

void dump_com_error(_com_error &e)
{
	_bstr_t bstrSource(e.Source());
	_bstr_t bstrDescription(e.Description());
	TCHAR szTemp[1024];
	CString csMsg = "Oops - hit an error!\n";
	wsprintf(szTemp, _T("Code = %08lx\n"), e.Error());
	csMsg += szTemp;
	wsprintf(szTemp, _T("Code meaning = %s\n"), e.ErrorMessage());
	csMsg += szTemp;
	wsprintf(szTemp, _T("Source = %s\n"), bstrSource.length() ? (LPCTSTR)bstrSource : _T("null"));
	csMsg += szTemp;
	wsprintf(szTemp, _T("Description = %s\n"), bstrDescription.length() ? (LPCTSTR)bstrDescription : _T("null"));
	csMsg += szTemp;
	AfxMessageBox(csMsg);
}

/////////////////////////////////////////////////////////////////////////////
// CAutoDrivDlg dialog

CAutoDrivDlg::CAutoDrivDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutoDrivDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutoDrivDlg)
	m_szText = _T("");
	m_x = 0;
	m_y = 0;
	m_bUseDispatch = TRUE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pDualAutoClikObject = NULL;
}


void CAutoDrivDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutoDrivDlg)
	DDX_Text(pDX, IDC_EDITTEXT, m_szText);
	DDX_Text(pDX, IDC_EDITX, m_x);
	DDX_Text(pDX, IDC_EDITY, m_y);
	DDX_Check(pDX, IDC_USEDISPATCH, m_bUseDispatch);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAutoDrivDlg, CDialog)
	//{{AFX_MSG_MAP(CAutoDrivDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CLOSE, OnClose)
	ON_WM_CREATE()
	ON_BN_CLICKED(IDC_ANIMATE_XY, OnAnimateXY)
	ON_BN_CLICKED(IDC_ANIMATEPOS, OnAnimatePos)
	ON_BN_CLICKED(IDC_SETALL, OnSetAll)
	ON_BN_CLICKED(IDC_SETPOS, OnSetPosition)
	ON_BN_CLICKED(IDC_SETTEXT, OnSetText)
	ON_BN_CLICKED(IDC_SETX, OnSetX)
	ON_BN_CLICKED(IDC_SETY, OnSetY)
	ON_BN_CLICKED(IDC_REFRESH, OnRefresh)
	ON_BN_CLICKED(IDC_GETALL, OnGetAll)
	ON_BN_CLICKED(IDC_GETPOS, OnGetPosition)
	ON_BN_CLICKED(IDC_USEDISPATCH, OnUseDispatch)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutoDrivDlg message handlers

BOOL CAutoDrivDlg::OnInitDialog()
{
	if (!bool(m_pDualAutoClikObject))
	{
		m_bUseDispatch = TRUE;
		GetDlgItem(IDC_USEDISPATCH)->EnableWindow(FALSE);
	}

	m_szText = _T("Foobar");
	m_x = 0;
	m_y = 0;
	CDialog::OnInitDialog();
	CenterWindow();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAutoDrivDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAutoDrivDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

int CAutoDrivDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDialog::OnCreate(lpCreateStruct) == -1)
		return -1;  // fail

	try
	{
		HRESULT hr = m_pAutoClikObject.CreateInstance(__uuidof(Document));
		if (FAILED(hr))
			_com_raise_error(hr);
	}
	catch (_com_error& e)
	{
		AfxMessageBox(IDP_CANNOT_CREATE_AUTOCLIK);
		dump_com_error(e);
		return -1;  // fail
	}

	// Get the dual interface corresponding to this dispatch object
	ASSERT(m_pDualAutoClikObject == NULL);
	try
	{
		m_pDualAutoClikObject = m_pAutoClikObject;
	}
	catch (_com_error& e)
	{
		AfxMessageBox(IDP_CANNOT_CREATE_AUTODUALCLIK);
		dump_com_error(e);
		return -1;  // fail
	}

	m_pAutoClikObject->ShowWindow();

	return 0;   // success
}

void CAutoDrivDlg::OnClose()
{
	if (m_pDualAutoClikObject)
	{
		try
		{
			m_pDualAutoClikObject.Release();
		}
		catch (_com_error ce)
		{
			AfxMessageBox(_T("We caught an exception releasing m_pDualAutoClikObject"));
			dump_com_error(ce);
		}
	}

	if (m_pAutoClikObject)
	{
		try
		{
			m_pAutoClikObject.Release();
		}
		catch(_com_error ce)
		{
			AfxMessageBox(_T("We caught an exception releasing m_pAutoClikObject"));
			dump_com_error(ce);
		}
	}
	EndDialog(0);
}

void CAutoDrivDlg::OnAnimateXY()
{
	if (m_bUseDispatch)
	{
		for (short i = 10; i <= 100; i += 5)
		{
			m_pAutoClikObject->x = i;
			m_pAutoClikObject->y = i;
		}
	}
	else
	{
		for (short i = 10; i <= 100; i += 5)
		{
			m_pDualAutoClikObject->x = i;
			m_pDualAutoClikObject->y = i;
		}
	}
}

void CAutoDrivDlg::OnAnimatePos()
{
	if (m_bUseDispatch)
	{
		IAutoClickPointPtr point = m_pAutoClikObject->Position;

		for (short i = 10; i <= 100; i += 5)
		{
			point->x = i;
			point->y = i;
			m_pAutoClikObject->Position = point;
		}
	}
	else
	{
		IDualAutoClickPointPtr point = m_pDualAutoClikObject->Position;

		for (short i = 10; i <= 100; i += 5)
		{
			point->x = i;
			point->y = i;
			m_pDualAutoClikObject->Position = point;
		}
	}
}

void CAutoDrivDlg::OnSetAll()
{
	UpdateData(TRUE);
	_bstr_t bstr = (LPCTSTR) m_szText;

	if (m_bUseDispatch)
	{

		m_pAutoClikObject->SetAllProps(m_x, m_y, bstr);
	}
	else
	{
		m_pDualAutoClikObject->SetAllProps(m_x, m_y, bstr);
	}
}

void CAutoDrivDlg::OnSetPosition()
{
	UpdateData(TRUE);
	if (m_bUseDispatch)
	{
		IAutoClickPointPtr point = m_pAutoClikObject->Position;
		point->x = m_x;
		point->y = m_y;
		m_pAutoClikObject->Position = point;
	}
	else
	{
		IDualAutoClickPointPtr point = m_pDualAutoClikObject->Position;
		point->x = m_x;
		point->y = m_y;
		m_pDualAutoClikObject->Position = point;
	}
}

void CAutoDrivDlg::OnSetText()
{
	UpdateData(TRUE);
	_bstr_t bstr = (LPCTSTR) m_szText;
	try
	{
		if (m_bUseDispatch)
		{
			m_pAutoClikObject->text = bstr;
		}
		else
		{
			m_pDualAutoClikObject->text = bstr;
		}
	}
	catch(_com_error& e)
	{
		dump_com_error(e);
	}
}

void CAutoDrivDlg::OnSetX()
{
	UpdateData(TRUE);
	if (m_bUseDispatch)
	{
		m_pAutoClikObject->x = m_x;
	}
	else
	{
		m_pDualAutoClikObject->x = m_x;
	}
}

void CAutoDrivDlg::OnSetY()
{
	UpdateData(TRUE);
	if (m_bUseDispatch)
	{
		m_pAutoClikObject->y = m_y;
	}
	else
	{
		m_pDualAutoClikObject->y = m_y;
	}
}

void CAutoDrivDlg::OnRefresh()
{
	UpdateData(TRUE);
	if (m_bUseDispatch)
	{
		m_pAutoClikObject->RefreshWindow();
	}
	else
	{
		m_pDualAutoClikObject->RefreshWindow();
	}
}

void CAutoDrivDlg::OnGetAll()
{
	if (m_bUseDispatch)
	{
		m_x = m_pAutoClikObject->x;
		m_y = m_pAutoClikObject->y;
		m_szText = (LPCTSTR) m_pAutoClikObject->text;
	}
	else
	{
		m_x = m_pDualAutoClikObject->x;
		m_y = m_pDualAutoClikObject->y;
		m_szText = (LPCTSTR) m_pDualAutoClikObject->text;
	}
	UpdateData(FALSE);
}

void CAutoDrivDlg::OnGetPosition()
{
	if (m_bUseDispatch)
	{
		IAutoClickPointPtr point = m_pAutoClikObject->Position;
		m_x = point->x;
		m_y = point->y;

	}
	else
	{
		IDualAutoClickPointPtr point = m_pDualAutoClikObject->Position;
		m_x = point->x;
		m_y = point->y;

	}
	UpdateData(FALSE);
}

void CAutoDrivDlg::OnUseDispatch()
{
	UpdateData(TRUE);
}
