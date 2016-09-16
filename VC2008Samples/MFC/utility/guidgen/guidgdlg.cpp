// guidgdlg.cpp : implementation file
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
#include "guidgen.h"
#include "guidgdlg.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg message handlers

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	CenterWindow();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

/////////////////////////////////////////////////////////////////////////////
// CGuidGenDlg dialog

CGuidGenDlg::CGuidGenDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGuidGenDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGuidGenDlg)
	m_nGuidType = -1;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGuidGenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGuidGenDlg)
	DDX_Radio(pDX, IDC_RADIO1, m_nGuidType);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGuidGenDlg, CDialog)
	//{{AFX_MSG_MAP(CGuidGenDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_NEWGUID, OnNewguid)
	//}}AFX_MSG_MAP
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIO1, IDC_RADIO4, OnChangedSel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGuidGenDlg message handlers

static const TCHAR szOptions[] = _T("Options");
static const TCHAR szGuidType[] = _T("GuidType");

BOOL CGuidGenDlg::OnInitDialog()
{
	// start with guid type selected last time
	m_nGuidType = AfxGetApp()->GetProfileInt(szOptions, szGuidType, 0);

	// create random GUID
	m_guid = GUID_NULL;
	::CoCreateGuid(&m_guid);
	if (m_guid == GUID_NULL)
	{
		AfxMessageBox(IDP_ERR_CREATE_GUID);
		EndDialog(IDABORT);
	}

	CDialog::OnInitDialog();
	OnChangedSel(IDC_RADIO1+m_nGuidType);

	if (GetParent() != NULL)
		CenterWindow();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	ENSURE(strAboutMenu.LoadString(IDS_ABOUTBOX));
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGuidGenDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGuidGenDlg::OnPaint()
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
HCURSOR CGuidGenDlg::OnQueryDragIcon()
{
	return (HCURSOR)m_hIcon;
}

void CGuidGenDlg::OnChangedSel(UINT /*nID*/)
{
	// update m_nGuidType
	UpdateData(TRUE);
	ASSERT(m_nGuidType >= 0 && m_nGuidType <= 3);

	// update the result text
	CString strResult;
	GetFormattedGuid(strResult);
	SetDlgItemText(IDC_RESULTS, strResult);
}

void CGuidGenDlg::OnOK()
{
	UpdateData(TRUE);

	// save current type selected
	AfxGetApp()->WriteProfileInt(szOptions, szGuidType, m_nGuidType);

	// copy the string to the clipboard
	if (!OpenClipboard())
	{
		AfxMessageBox(IDP_ERR_OPEN_CLIP);
		return;
	}

	CString strResult;
	GetFormattedGuid(strResult);
	int nTextLen = (strResult.GetLength()+1)*sizeof(TCHAR);
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, nTextLen);
	if (hGlobal != NULL)
	{
		LPVOID lpText = GlobalLock(hGlobal);
		memcpy_s(lpText, nTextLen, strResult, nTextLen);

		EmptyClipboard();
		GlobalUnlock(hGlobal);
#ifdef _UNICODE
		SetClipboardData(CF_UNICODETEXT, hGlobal);
#else
		SetClipboardData(CF_TEXT, hGlobal);
#endif
	}
	CloseClipboard();
}

void CGuidGenDlg::GetFormattedGuid(CString& rString)
{
	// load appropriate formatting string
	CString strFormat;
	ENSURE(strFormat.LoadString(IDS_FORMATS+m_nGuidType));

	// then format into destination
	rString.Format(strFormat,
		// first copy...
		m_guid.Data1, m_guid.Data2, m_guid.Data3,
		m_guid.Data4[0], m_guid.Data4[1], m_guid.Data4[2], m_guid.Data4[3],
		m_guid.Data4[4], m_guid.Data4[5], m_guid.Data4[6], m_guid.Data4[7],
		// second copy...
		m_guid.Data1, m_guid.Data2, m_guid.Data3,
		m_guid.Data4[0], m_guid.Data4[1], m_guid.Data4[2], m_guid.Data4[3],
		m_guid.Data4[4], m_guid.Data4[5], m_guid.Data4[6], m_guid.Data4[7]);
}

void CGuidGenDlg::OnNewguid()
{
	// create random GUID using UuidCreate so that we 
	// can check for more error codes
	m_guid = GUID_NULL;
	HRESULT hr = ::UuidCreate(&m_guid);

	// Errors
	if (HRESULT_CODE(hr) != RPC_S_OK)
	{
		AfxMessageBox(IDP_ERR_NOT_OK);
		return;
	}

	if (m_guid == GUID_NULL)
	{
		AfxMessageBox(IDP_ERR_CREATE_GUID);
		return;
	}

	// Warnings
	if (HRESULT_CODE(hr) == RPC_S_UUID_NO_ADDRESS)
		AfxMessageBox(IDP_ERR_NO_ADDRESS);

	if (HRESULT_CODE(hr) == RPC_S_UUID_LOCAL_ONLY)
		AfxMessageBox(IDP_ERR_LOCAL_ONLY);

	// update dialog to match m_guid
	OnChangedSel(IDC_RADIO1+m_nGuidType);
}
