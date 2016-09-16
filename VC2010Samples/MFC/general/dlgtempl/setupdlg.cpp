// dlgtempDlg.cpp : implementation file
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
#include "dlgtemp.h"
#include "setupdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
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

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
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
// CDlgtempDlg dialog

CDlgtempDlg::CDlgtempDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgtempDlg::IDD, pParent)
{
	m_nActiveItem = -1;

	//{{AFX_DATA_INIT(CDlgtempDlg)
	m_strCaption = _T("");
	m_x = 0;
	m_y = 0;
	m_nWidth = 0;
	m_nHeight = 0;
	m_nItem = -1;
	m_strSelectedItem = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDlgtempDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgtempDlg)
	DDX_Text(pDX, IDC_CAPTION, m_strCaption);
	DDX_Text(pDX, IDC_XPOS, m_x);
	DDV_MinMaxUInt(pDX, m_x, 0, 300);
	DDX_Text(pDX, IDC_YPOS, m_y);
	DDV_MinMaxUInt(pDX, m_y, 0, 200);
	DDX_Text(pDX, IDC_WIDTH, m_nWidth);
	DDX_Text(pDX, IDC_HEIGHT, m_nHeight);
	DDX_Radio(pDX, IDC_BUTTON, m_nItem);
	DDX_Text(pDX, IDC_SELECTEDITEM, m_strSelectedItem);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDlgtempDlg, CDialog)
	//{{AFX_MSG_MAP(CDlgtempDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_DEMOIT, OnDemoIt)
	ON_BN_CLICKED(IDC_BUTTON, OnButtonInformation)
	ON_BN_CLICKED(IDC_STATICTEXT, OnStaticTextInformation)
	ON_BN_CLICKED(IDC_EDITCONTROL, OnEditControlInformation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgtempDlg message handlers

BOOL CDlgtempDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	CString strAboutMenu;
	strAboutMenu.LoadString(IDS_ABOUTBOX);
	if (!strAboutMenu.IsEmpty())
	{
		pSysMenu->AppendMenu(MF_SEPARATOR);
		pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);         // Set big icon
	SetIcon(m_hIcon, FALSE);        // Set small icon

	m_nItem = 0;        // select the BUTTON option
	OnButtonInformation();  // fill the edit fields with corresponding values

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDlgtempDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CDlgtempDlg::OnPaint()
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

void CDlgtempDlg::OnDemoIt()
{
	InfoToDialogHelper(m_nActiveItem, NULL);
	m_dlgTemplate.DemoIt();
}

void CDlgtempDlg::OnButtonInformation()
{
	// take the information about the button and send it to the edit
	// controls in the dialog.
	InfoToDialogHelper(IBUTTON, _T("BUTTON"));
}

void CDlgtempDlg::OnStaticTextInformation()
{
	InfoToDialogHelper(ISTATICTEXT, _T("STATIC TEXT"));
}

void CDlgtempDlg::OnEditControlInformation()
{
	InfoToDialogHelper(IEDITCONTROL, _T("EDIT CONTROL"));
}

void CDlgtempDlg::InfoToDialogHelper(int nItem, LPCTSTR lpszSelection)
{
	// first bring data from edit field and store in proper item
	if (m_nActiveItem != -1)
	{
		UpdateData(TRUE/*bSaveAndValidate*/);
#pragma warning(disable : 4244)
		m_dlgTemplate.m_rgDlgItem[m_nActiveItem].m_dlgItemTemplate.x = m_x;
		m_dlgTemplate.m_rgDlgItem[m_nActiveItem].m_dlgItemTemplate.y = m_y;
		m_dlgTemplate.m_rgDlgItem[m_nActiveItem].m_dlgItemTemplate.cx = m_nWidth;
		m_dlgTemplate.m_rgDlgItem[m_nActiveItem].m_dlgItemTemplate.cy = m_nHeight;
		m_dlgTemplate.m_rgDlgItem[m_nActiveItem].m_strCaption = m_strCaption;
#pragma warning(default : 4244)

	}

	// now bring data from item and send to edit fields
	if (m_nActiveItem != nItem)
	{
		ENSURE(nItem >= 0 && nItem < 3);
		m_x = m_dlgTemplate.m_rgDlgItem[nItem].m_dlgItemTemplate.x;
		m_y = m_dlgTemplate.m_rgDlgItem[nItem].m_dlgItemTemplate.y;
		m_nWidth = m_dlgTemplate.m_rgDlgItem[nItem].m_dlgItemTemplate.cx;
		m_nHeight = m_dlgTemplate.m_rgDlgItem[nItem].m_dlgItemTemplate.cy;
		m_strCaption = m_dlgTemplate.m_rgDlgItem[nItem].m_strCaption;
		ASSERT(lpszSelection != NULL);
		m_strSelectedItem = lpszSelection;
		m_nItem = nItem;
		m_nActiveItem = nItem;
		UpdateData(FALSE/*bSaveAndValidate*/);
	}

	CWnd*   pwnd = GetDlgItem(IDC_CAPTION);
	pwnd->EnableWindow(nItem != IEDITCONTROL);
}
