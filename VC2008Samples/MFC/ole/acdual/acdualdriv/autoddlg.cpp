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
#include "..\autoclik_i.c"

#include "autodriv.h"
#include "autoclik.h"
#include "autoddlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

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
	if (!m_pDualAutoClikObject)
	{
		m_bUseDispatch = TRUE;
		GetDlgItem(IDC_USEDISPATCH)->EnableWindow(FALSE);
	}

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

	if (!m_autoClikObject.CreateDispatch(_T("ACDual.Document")))
	{
		AfxMessageBox(IDP_CANNOT_CREATE_AUTOCLIK);
		return -1;  // fail
	}

	// Get the custom interface corresponding to this dispatch object
	ASSERT(m_pDualAutoClikObject == NULL);
	m_autoClikObject.m_lpDispatch->QueryInterface(IID_IDualAClick,
												  (LPVOID*)&m_pDualAutoClikObject);

	m_autoClikObject.ShowWindow();

	return 0;   // success
}

void CAutoDrivDlg::OnClose()
{
	if (m_pDualAutoClikObject)
	{
		m_pDualAutoClikObject->Release();
		m_pDualAutoClikObject = NULL;
	}
	EndDialog(0);
}

void CAutoDrivDlg::OnAnimateXY()
{
	if (m_bUseDispatch)
	{
		for (short i = 10; i <= 100; i += 5)
		{
			m_autoClikObject.SetX(i);
			m_autoClikObject.SetY(i);
		}
	}
	else
	{
		ENSURE(m_pDualAutoClikObject != NULL);
		for (short i = 10; i <= 100; i += 5)
		{
			m_pDualAutoClikObject->put_x(i);
			m_pDualAutoClikObject->put_y(i);
		}
	}
}

void CAutoDrivDlg::OnAnimatePos()
{
	if (m_bUseDispatch)
	{
		CClikPoint point;
		LPDISPATCH lpPointDispatch = m_autoClikObject.GetPosition();

		point.AttachDispatch(lpPointDispatch);
		for (short i = 10; i <= 100; i += 5)
		{
			point.SetX(i);
			point.SetY(i);
			m_autoClikObject.SetPosition(lpPointDispatch);
		}
	}
	else
	{
		ENSURE(m_pDualAutoClikObject != NULL);
		IDualAutoClickPoint* lpPoint = NULL;
		m_pDualAutoClikObject->get_Position(&lpPoint);
		if (lpPoint)
		{
			for (short i = 10; i <= 100; i += 5)
			{
				lpPoint->put_x(i);
				lpPoint->put_y(i);
				m_pDualAutoClikObject->put_Position(lpPoint);
			}
			lpPoint->Release();
		}
	}
}

void CAutoDrivDlg::OnSetAll()
{
	UpdateData(TRUE);

	if (m_bUseDispatch)
	{
		m_autoClikObject.SetAllProps((short)m_x, (short)m_y, m_szText);
	}
	else
	{
		ASSERT(m_pDualAutoClikObject != NULL);
		m_pDualAutoClikObject->SetAllProps((short)m_x, (short)m_y,
										   m_szText.AllocSysString());
	}

}

void CAutoDrivDlg::OnSetPosition()
{
	if (m_bUseDispatch)
	{
		CClikPoint point;
		point.AttachDispatch(m_autoClikObject.GetPosition());

		UpdateData(TRUE);
		point.SetX((short)m_x);
		point.SetY((short)m_y);
		m_autoClikObject.SetPosition(point.m_lpDispatch);
	}
	else
	{
		ENSURE(m_pDualAutoClikObject != NULL);
		IDualAutoClickPoint* lpPoint = NULL;
		m_pDualAutoClikObject->get_Position(&lpPoint);
		if (lpPoint)
		{
			UpdateData(TRUE);
			lpPoint->put_x((short)m_x);
			lpPoint->put_y((short)m_y);
			m_pDualAutoClikObject->put_Position(lpPoint);
			lpPoint->Release();
		}
	}
}

void CAutoDrivDlg::OnSetText()
{
	UpdateData(TRUE);

	if (m_bUseDispatch)
	{
		m_autoClikObject.SetText(m_szText);
	}
	else
	{
		ASSERT(m_pDualAutoClikObject != NULL);
		m_pDualAutoClikObject->put_text(m_szText.AllocSysString());
	}
}

void CAutoDrivDlg::OnSetX()
{
	UpdateData(TRUE);

	if (m_bUseDispatch)
	{
		m_autoClikObject.SetX((short)m_x);
	}
	else
	{
		ASSERT(m_pDualAutoClikObject != NULL);
		m_pDualAutoClikObject->put_x((short)m_x);
	}
}

void CAutoDrivDlg::OnSetY()
{
	UpdateData(TRUE);

	if (m_bUseDispatch)
	{
		m_autoClikObject.SetY((short)m_y);
	}
	else
	{
		ASSERT(m_pDualAutoClikObject != NULL);
		m_pDualAutoClikObject->put_y((short)m_y);
	}
}

void CAutoDrivDlg::OnRefresh()
{
	if (m_bUseDispatch)
	{
		m_autoClikObject.RefreshWindow();
	}
	else
	{
		ENSURE(m_pDualAutoClikObject != NULL);
		m_pDualAutoClikObject->RefreshWindow();
	}
}

void CAutoDrivDlg::OnGetAll()
{
	if (m_bUseDispatch)
	{
		m_x = m_autoClikObject.GetX();
		m_y = m_autoClikObject.GetY();
		m_szText = m_autoClikObject.GetText();
	}
	else
	{
		ENSURE(m_pDualAutoClikObject != NULL);
		short x, y;
		m_pDualAutoClikObject->get_x(&x); m_x = x;
		m_pDualAutoClikObject->get_y(&y); m_y = y;

		BSTR bstrText;
		m_pDualAutoClikObject->get_text(&bstrText);
		m_szText = bstrText;
		::SysFreeString(bstrText);
	}

	UpdateData(FALSE);
}

void CAutoDrivDlg::OnGetPosition()
{
	if (m_bUseDispatch)
	{
		CClikPoint point;
		point.AttachDispatch(m_autoClikObject.GetPosition());

		m_x = point.GetX();
		m_y = point.GetY();
	}
	else
	{
		ENSURE(m_pDualAutoClikObject != NULL);
		IDualAutoClickPoint* lpPoint = NULL;
		m_pDualAutoClikObject->get_Position(&lpPoint);
		if (lpPoint)
		{
			short x, y;
			lpPoint->get_x(&x); m_x = x;
			lpPoint->get_y(&y); m_y = y;
			lpPoint->Release();
		}
	}
	UpdateData(FALSE);
}

void CAutoDrivDlg::OnUseDispatch()
{
	UpdateData(TRUE);
}
