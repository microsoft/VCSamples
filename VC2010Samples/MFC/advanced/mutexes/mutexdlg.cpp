// mutexesDlg.cpp : implementation file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.
//
// This sample application is derived from the Mutex application
// distributed with Jeffrey Richter's "Advanced Windows" programming book
// (Microsoft Press).  See the book for more information about Win32
// programming topics, including thread synchronization.

#include "stdafx.h"
#include "mutexes.h"
#include "mutexdlg.h"
#include "threads.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define MAX_DIGITS 6000
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
// CMutexesDlg dialog

CMutexesDlg::CMutexesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMutexesDlg::IDD, pParent),
	 m_mutex(FALSE, NULL)	 
{
	//{{AFX_DATA_INIT(CMutexesDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_pCounterThread = NULL;
	m_pDisplayThread = NULL;
	//Preallocate and lock large buffer to avoid MT problems:
	//CString is used without locking and reallocs by CounterThread, when
	//DisplayThread tries to access the freed buffer.
	m_strNumber.Preallocate(MAX_DIGITS);
	m_strNumber.LockBuffer();
	m_strNumber="0";
	
}
CMutexesDlg::~CMutexesDlg()
{
	m_strNumber.UnlockBuffer();
}
void CMutexesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMutexesDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMutexesDlg, CDialog)
	//{{AFX_MSG_MAP(CMutexesDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_CBN_SELCHANGE(IDC_PRIORITYCLASS, OnPriorityClassChange)
	ON_CBN_SELCHANGE(IDC_CNTRTHRDPRIORITY, OnPriorityChangeCntr)
	ON_CBN_SELCHANGE(IDC_DSPYTHRDPRIORITY, OnPriorityChangeDisp)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_PAUSE, OnPause)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CMutexesDlg message handlers

BOOL CMutexesDlg::OnInitDialog()
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

	// Fill the Process Priority Class combo box and select
	// Normal.

	CComboBox* pBox;
	pBox = (CComboBox*) GetDlgItem(IDC_PRIORITYCLASS);

	ASSERT(pBox != NULL);
	if (pBox != NULL)
	{
		pBox->AddString(_T("Idle"));
		pBox->AddString(_T("Normal"));
		pBox->AddString(_T("High"));
		pBox->AddString(_T("Realtime"));
		pBox->SetCurSel(1); // Normal
	}

	// Fill the Display Thread Priority
	// combo box and select Normal.

	pBox = (CComboBox*) GetDlgItem(IDC_DSPYTHRDPRIORITY);
	ASSERT(pBox != NULL);
	if (pBox != NULL)
	{
		pBox->AddString(_T("Idle"));
		pBox->AddString(_T("Lowest"));
		pBox->AddString(_T("Below normal"));
		pBox->AddString(_T("Normal"));
		pBox->AddString(_T("Above normal"));
		pBox->AddString(_T("Highest"));
		pBox->AddString(_T("Timecritical"));
		pBox->SetCurSel(3);  // Normal
	}

	// Fill the Counter Thread Priority
	// combo box and select Normal.

	pBox = (CComboBox*) GetDlgItem(IDC_CNTRTHRDPRIORITY);
	ASSERT(pBox != NULL);
	if (pBox != NULL)
	{
		pBox->AddString(_T("Idle"));
		pBox->AddString(_T("Lowest"));
		pBox->AddString(_T("Below normal"));
		pBox->AddString(_T("Normal"));
		pBox->AddString(_T("Above normal"));
		pBox->AddString(_T("Highest"));
		pBox->AddString(_T("Timecritical"));
		pBox->SetCurSel(3);  // Normal
	}

	// initialize the threads and let them start running!

	m_pDisplayThread = (CDisplayThread*)
		AfxBeginThread(RUNTIME_CLASS(CDisplayThread), THREAD_PRIORITY_NORMAL,
			0, CREATE_SUSPENDED);
	m_pDisplayThread->SetOwner(this);
	m_pDisplayThread->ResumeThread();

	m_pCounterThread = (CCounterThread*)
		AfxBeginThread(RUNTIME_CLASS(CCounterThread), THREAD_PRIORITY_NORMAL,
			0, CREATE_SUSPENDED);
	m_pCounterThread->SetOwner(this);
	m_pCounterThread->ResumeThread();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMutexesDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMutexesDlg::OnPaint()
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
HCURSOR CMutexesDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMutexesDlg::AddToListBox(LPCTSTR szBuffer)
{
	CListBox* pBox = (CListBox*) GetDlgItem(IDC_DATABOX);
	ASSERT(pBox != NULL);

	if (pBox != NULL)
	{
		int x = pBox->AddString(szBuffer);
		pBox->SetCurSel(x);

		if (pBox->GetCount() > 100)
			pBox->DeleteString(0);
	}
}

void CMutexesDlg::OnClose()
{
	int nCount = 0;
	DWORD   dwStatus;

	CButton* pCheck = (CButton*) GetDlgItem(IDC_PAUSE);
	BOOL bPaused = ((pCheck->GetState() & 0x003) != 0);

	if (bPaused == TRUE)
	{
		pCheck->SetCheck(0);
		m_pCounterThread->ResumeThread();
		m_pDisplayThread->ResumeThread();
	}

	if (m_pCounterThread != NULL)
	{
		VERIFY(::GetExitCodeThread(m_pCounterThread->m_hThread, &dwStatus));
		if (dwStatus == STILL_ACTIVE)
		{
			nCount++;
			m_pCounterThread->m_bDone = TRUE;
		}
		else
		{
			delete m_pCounterThread;
			m_pCounterThread = NULL;
		}
	}

	if (m_pDisplayThread != NULL)
	{
		VERIFY(::GetExitCodeThread(m_pDisplayThread->m_hThread, &dwStatus));
		if (dwStatus == STILL_ACTIVE)
		{
			nCount++;
			m_pDisplayThread->m_bDone = TRUE;
		}
		else
		{
			delete m_pDisplayThread;
			m_pDisplayThread = NULL;
		}
	}

	if (nCount == 0)
		CDialog::OnClose();
	else
		PostMessage(WM_CLOSE, 0, 0);
}

void CMutexesDlg::OnPriorityClassChange()
{
	DWORD dw;
	CComboBox* pBox = (CComboBox*) GetDlgItem(IDC_PRIORITYCLASS);
	int nCurSel = pBox->GetCurSel();

	switch (nCurSel)
	{
	case 0:
		dw = IDLE_PRIORITY_CLASS;
		break;

	case 1:
	default:
		dw = NORMAL_PRIORITY_CLASS;
		break;

	case 2:
		dw = HIGH_PRIORITY_CLASS;
		break;

	case 3:
		dw = REALTIME_PRIORITY_CLASS;
		break;
	}

	SetPriorityClass(GetCurrentProcess(), dw);
}

void CMutexesDlg::OnPriorityChangeDisp()
{
	OnPriorityChange(IDC_DSPYTHRDPRIORITY);
}

void CMutexesDlg::OnPriorityChangeCntr()
{
	OnPriorityChange(IDC_CNTRTHRDPRIORITY);
}

void CMutexesDlg::OnPriorityChange(UINT nID)
{
	ASSERT(nID == IDC_CNTRTHRDPRIORITY || nID == IDC_DSPYTHRDPRIORITY);

	DWORD dw;
	CComboBox* pBox = (CComboBox*) GetDlgItem(nID);
	int nCurSel = pBox->GetCurSel();

	switch (nCurSel)
	{
	case 0:
		dw = (DWORD) THREAD_PRIORITY_IDLE;
		break;

	case 1:
		dw = (DWORD) THREAD_PRIORITY_LOWEST;
		break;

	case 2:
		dw = (DWORD) THREAD_PRIORITY_BELOW_NORMAL;
		break;

	case 3:
	default:
		dw = (DWORD) THREAD_PRIORITY_NORMAL;
		break;

	case 4:
		dw = (DWORD) THREAD_PRIORITY_ABOVE_NORMAL;
		break;

	case 5:
		dw = (DWORD) THREAD_PRIORITY_HIGHEST;
		break;

	case 6:
		dw = (DWORD) THREAD_PRIORITY_TIME_CRITICAL;
		break;
	}

	if (nID == IDC_CNTRTHRDPRIORITY)
		m_pCounterThread->SetThreadPriority(dw);
	else
		m_pDisplayThread->SetThreadPriority(dw);
}

void CMutexesDlg::OnPause()
{
	CButton* pCheck = (CButton*) GetDlgItem(IDC_PAUSE);
	BOOL bPaused = ((pCheck->GetState() & 0x003) != 0);

	if (bPaused)
	{
		m_pCounterThread->SuspendThread();
		m_pDisplayThread->SuspendThread();
	}
	else
	{
		m_pCounterThread->ResumeThread();
		m_pDisplayThread->ResumeThread();
	}
}
