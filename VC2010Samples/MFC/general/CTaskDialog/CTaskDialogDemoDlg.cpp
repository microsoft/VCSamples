// TaskDialogTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CTaskDialogDemo.h"
#include "CTaskDialogDemoDlg.h"

#include <afxtaskdialog.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CTaskDialogTestDlg::CTaskDialogTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTaskDialogTestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTaskDialogTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTaskDialogTestDlg, CDialog)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, &CTaskDialogTestDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CTaskDialogTestDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CTaskDialogTestDlg::OnBnClickedButton3)	
	ON_STN_CLICKED(IDC_RADIO_ID, &CTaskDialogTestDlg::OnStnClickedRadioId)
	ON_BN_CLICKED(IDC_BUTTON6, &CTaskDialogTestDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON4, &CTaskDialogTestDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CTaskDialogTestDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CTaskDialogTestDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CTaskDialogTestDlg::OnBnClickedButton8)	
END_MESSAGE_MAP()


// CTaskDialogTestDlg message handlers

BOOL CTaskDialogTestDlg::OnInitDialog()
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

void CTaskDialogTestDlg::OnPaint()
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
HCURSOR CTaskDialogTestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTaskDialogTestDlg::OnBnClickedButton1()
{
	CTaskDialog dlg(_T("A CTaskDialog presents information in a clear and consistent way."), 
			_T("How much do you like CTaskDialog?"), _T("Sample CTaskDialog"), 
				TDCBF_YES_BUTTON | TDCBF_NO_BUTTON, TDF_ENABLE_HYPERLINKS | TDF_ALLOW_DIALOG_CANCELLATION, _T("I hope you like it very much!"));
		
	INT_PTR nResult = dlg.DoModal();

	SetControls(nResult, dlg.GetSelectedRadioButtonID(), dlg.GetVerificationCheckboxState());	
}

void CTaskDialogTestDlg::OnBnClickedButton2()
{
	CProgressBarTaskDialog dlg;
	INT_PTR nResult = dlg.DoModal();

	SetControls(nResult, dlg.GetSelectedRadioButtonID(), dlg.GetVerificationCheckboxState());	
}

void CTaskDialogTestDlg::OnBnClickedButton3()
{

	CTaskDialog dlg(_T("A CTaskDialog presents information in a clear and consistent way."),
			_T("How much do you like CTaskDialog?"), _T("Sample CTaskDialog"), 0, 
			TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS , _T("I hope you like it!"));

	dlg.AddCommandControl( 10, _T("&Use it!\nIt's the best dialog you can have!"));
	dlg.AddCommandControl( 20, _T("&Maybe?\nDon't you want to try it?"));
	dlg.AddCommandControl( 25, _T("&No way!\nI'm not going to use it!"));
	
	dlg.AddRadioButton( 3, _T("Lots"));
	dlg.AddRadioButton( 7, _T("A little"));
	dlg.AddRadioButton( 4, _T("Not at all"));
	
    dlg.SetMainIcon(TD_SHIELD_ICON);
	dlg.SetFooterIcon(TD_INFORMATION_ICON);
	
	INT_PTR nResult = dlg.DoModal();

	SetControls(nResult, dlg.GetSelectedRadioButtonID(), dlg.GetVerificationCheckboxState());	
}


void CTaskDialogTestDlg::OnStnClickedRadioId()
{
	// TODO: Add your control notification handler code here
}

void CTaskDialogTestDlg::OnBnClickedButton6()
{
	CTaskDialog dlg(_T("Should we replace MessageBox by CTaskDialog?"), _T(""), _T("Usage as MessageBox"), 
	 TDCBF_YES_BUTTON, TDF_ENABLE_HYPERLINKS);

	INT_PTR nResult = dlg.DoModal();

	SetControls(nResult, dlg.GetSelectedRadioButtonID(), dlg.GetVerificationCheckboxState());	
}

void CTaskDialogTestDlg::OnBnClickedButton4()
{
	CTaskDialog dlg(_T("A CTaskDialog presents information in a clear and consistent way and if you want to get more information go to <a href=\"http://microsoft.com\">http://microsoft.com</a>. Where can you get some useful information?"), 
		_T("How much do you like CTaskDialog?"), _T("Loading from resources"), 
		IDS_BUTTON, IDS_END_BUTTON , 0, TDF_ENABLE_HYPERLINKS | TDF_USE_COMMAND_LINKS, 
		_T("I hope you like it!"));
	
	dlg.SetFooterIcon(TD_INFORMATION_ICON);
	dlg.SetMainIcon(TD_INFORMATION_ICON);
	dlg.LoadRadioButtons(IDS_RADIO_START, IDS_RADIO_END);

	INT_PTR nResult = dlg.DoModal();

	SetControls(nResult, dlg.GetSelectedRadioButtonID(), dlg.GetVerificationCheckboxState());	
}

void CTaskDialogTestDlg::OnBnClickedButton5()
{
	CMargueeTaskDialog dlg;		
	INT_PTR nResult = dlg.DoModal();

	SetControls(nResult, dlg.GetSelectedRadioButtonID(), dlg.GetVerificationCheckboxState());	
}

void CTaskDialogTestDlg::OnBnClickedButton8()
{
	CWizardDialog dlg;
	
	INT_PTR nResult = dlg.DoModal();	

	SetControls(nResult, dlg.GetSelectedRadioButtonID(), dlg.GetVerificationCheckboxState());		
}

void CTaskDialogTestDlg::OnBnClickedButton7()
{
	INT_PTR nResult = CTaskDialog::ShowDialog(
			_T("Don't spend to much time on code, write only one line and get your CTaskDialog!"), 
			_T("Where do you like to go?"), 
			_T("One line command"), IDS_RADIO_START, IDS_RADIO_START + 3, TDCBF_CANCEL_BUTTON);
		
	SetControls(nResult, 0, FALSE);		
}

void CTaskDialogTestDlg::SetControls(INT_PTR nResult, int nRadioButtonId, BOOL bChecked)
{
	CString strTmp;
	strTmp.Format(_T("%d"), nResult);
	SetDlgItemText(IDC_NEW_BUTTON, strTmp);

	strTmp.Format(_T("%d"), nRadioButtonId);
	SetDlgItemText(IDC_RADIO_ID, strTmp);

	CheckDlgButton(IDC_CHECK, bChecked ? BST_CHECKED : BST_UNCHECKED);
}


