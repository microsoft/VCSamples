// FileDlgWatcherDlg.cpp : implementation file
//

#include "stdafx.h"
#include "FileDlgWatcher.h"
#include "FileDlgWatcherDlg.h"
#include "CustomFileDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFileDlgWatcherDlg dialog

CFileDlgWatcherDlg::CFileDlgWatcherDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFileDlgWatcherDlg::IDD, pParent),
	  m_bOpenFileDialog(TRUE),
	  m_bVistaStyle(FALSE),
	  m_bEventPopups(FALSE),
	  m_strLog()
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFileDlgWatcherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_OPEN_FILE_DLG, m_bOpenFileDialog);
	DDX_Check(pDX, IDC_VISTA_STYLE, m_bVistaStyle);
	DDX_Check(pDX, IDC_EVENT_POPUPS, m_bEventPopups);
	DDX_Text(pDX, IDC_LOG, m_strLog);
}

BEGIN_MESSAGE_MAP(CFileDlgWatcherDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_CREATE_DLG, &CFileDlgWatcherDlg::OnBnClickedCreateDlg)
	ON_BN_CLICKED(IDC_CLEAR_LOG, &CFileDlgWatcherDlg::OnBnClickedClearLog)
END_MESSAGE_MAP()


// CFileDlgWatcherDlg message handlers

BOOL CFileDlgWatcherDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFileDlgWatcherDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFileDlgWatcherDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFileDlgWatcherDlg::OnBnClickedCreateDlg()
{
	UpdateData(TRUE);		// to get current data from check boxes
	CreateLogPrologue();
	CCustomFileDialog cfd (m_bOpenFileDialog, m_bVistaStyle, m_bEventPopups,
						   m_strLog);
	cfd.DoModal();
	CreateLogEpilogue();
	UpdateData(FALSE);		// to get new data from text log
}

void CFileDlgWatcherDlg::OnBnClickedClearLog()
{
	m_strLog.Empty();
	UpdateData(FALSE);
}

void CFileDlgWatcherDlg::CreateLogPrologue()
{
	if (m_bOpenFileDialog)
	{
		m_strLog += _T("Open ");
	}
	else
	{
		m_strLog += _T("Save ");
	}
	m_strLog += _T("file dialog (");
	if (m_bVistaStyle)
	{
		m_strLog += _T("Vista ");
	}
	else
	{
		m_strLog += _T("XP ");
	}
	m_strLog += _T("style)\r\n");
	m_strLog += _T("-----\r\n");
}

void CFileDlgWatcherDlg::CreateLogEpilogue()
{
	m_strLog += _T("\r\n");
}