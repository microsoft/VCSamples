// calcdriv.cpp : Defines the class behaviors for the application.
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
#include "calcdriv.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCalcDrivApp

BEGIN_MESSAGE_MAP(CCalcDrivApp, CWinApp)
	//{{AFX_MSG_MAP(CCalcDrivApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard file based document commands
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalcDrivApp construction

CCalcDrivApp::CCalcDrivApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CCalcDrivApp object

CCalcDrivApp NEAR theApp;

/////////////////////////////////////////////////////////////////////////////
// CCalcDrivApp initialization

BOOL CCalcDrivApp::InitInstance()
{
#ifdef _DEBUG
	// turn on extra memory tracking
	afxMemDF |= checkAlwaysMemDF;
#endif

	// Initialize OLE 2.0 libraries
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	// Simple application that simply invokes a dialog
	CDriverDlg dlg;
	m_pMainWnd = &dlg;
	dlg.DoModal();

	return FALSE;   // don't run after the dialog is done
}

/////////////////////////////////////////////////////////////////////////////
// CDriverDlg dialog

CDriverDlg::CDriverDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDriverDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDriverDlg)
	//}}AFX_DATA_INIT
}

CDriverDlg::~CDriverDlg()
{
	TRY
	{
		// shut down the calculator
		//  (since calculator shows its user-interface, it would stay active
		//  if we didn't shut it down with a call to its Quit method)
		m_calc.Close();
	}
	END_TRY
}

void CDriverDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDriverDlg)
	DDX_Control(pDX, IDD_LAST_OPERATOR, m_stcOperator);
	DDX_Control(pDX, IDD_LAST_OPERAND, m_stcOperand);
	DDX_Control(pDX, IDC_LAST_ACCUM, m_stcAccum);
	DDX_Control(pDX, IDC_EXPRESSION, m_editExpression);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDriverDlg, CDialog)
	//{{AFX_MSG_MAP(CDriverDlg)
	ON_BN_CLICKED(IDC_GO, OnGo)
	ON_BN_CLICKED(IDC_SINGLE_STEP, OnSingleStep)
	ON_BN_CLICKED(IDC_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDriverDlg message handlers

void CDriverDlg::OnGo()
{
	// get current expression from the edit control
	CString strExpression;
	m_editExpression.GetWindowText(strExpression);
	LPCTSTR psz = strExpression;

	// send all characters in the edit control from start to end
	int nLen = strExpression.GetLength();
	int nStart, nEnd;
	m_editExpression.GetSel(nStart, nEnd);
	if (nStart == nLen)
		nStart = 0;
	psz += nStart;
	while (*psz != '\0')
	{
		TCHAR szTemp[2];
		szTemp[0] = *psz;
		szTemp[1] = '\0';
		m_calc.Button(szTemp);
		++psz;
	}
	m_editExpression.SetSel(nLen, nLen);

	OnRefresh();    // refresh after all button commands sent
	m_calc.Evaluate();
	m_calc.Display();
}

void CDriverDlg::OnSingleStep()
{
	// get current expression from the edit control
	CString strExpression;
	m_editExpression.GetWindowText(strExpression);
	LPCTSTR psz = strExpression;

	// send first character in selection, then move selection to next
	int nStart, nEnd;
	m_editExpression.GetSel(nStart, nEnd);
	psz += nStart;
	if (*psz != '\0')
	{
		TCHAR szTemp[2];
		szTemp[0] = *psz;
		szTemp[1] = '\0';
		m_calc.Button(szTemp);

		OnRefresh();        // refresh after each step

		// move to next character for next single-step
		m_editExpression.SetSel(nStart+1,
			min(strExpression.GetLength(), nStart+2));
	}
	else
	{
		m_calc.Evaluate();
		m_calc.Display();
		// stepping from end will start at beginning next time
		m_editExpression.SetSel(0, min(strExpression.GetLength(), 1));
	}
	OnRefresh();    // refresh after all button commands sent
}

void CDriverDlg::OnRefresh()
{
	TCHAR buf[64];
	long lResult = m_calc.GetOperand();
	_stprintf_s(buf, 64, _T("%ld"), lResult);
	m_stcOperand.SetWindowText(buf);

	long lAccum = m_calc.GetAccum();
	_stprintf_s(buf, 64, _T("%ld"), lAccum);
	m_stcAccum.SetWindowText(buf);

	short nOp = m_calc.GetOperation();
	static TCHAR operators[5] = { '?', '+', '-', '*', '/'};
	if (nOp < 0 || nOp > 4)
		nOp = 0;
	_stprintf_s(buf, 64, _T("%c"), operators[nOp]);
	m_stcOperator.SetWindowText(buf);
}

BOOL CDriverDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// create the calculator object that we'll drive through OLE automation
	COleException e;
	CLSID clsid;
	if (CLSIDFromProgID(OLESTR("mfccalc.calculator"), &clsid) != NOERROR)
	{
		AfxMessageBox(IDP_UNABLE_TO_CREATE);
		EndDialog(IDABORT);
		return FALSE;
	}

	// try to get the active calculator before creating a new one
	LPUNKNOWN lpUnk;
	LPDISPATCH lpDispatch;
	if (GetActiveObject(clsid, NULL, &lpUnk) == NOERROR)
	{
		HRESULT hr = lpUnk->QueryInterface(IID_IDispatch,
			(LPVOID*)&lpDispatch);
		lpUnk->Release();
		if (hr == NOERROR)
			m_calc.AttachDispatch(lpDispatch, TRUE);
	}

	// if not dispatch ptr attached yet, need to create one
	if (m_calc.m_lpDispatch == NULL &&
		!m_calc.CreateDispatch(clsid, &e))
	{
		AfxMessageBox(IDP_UNABLE_TO_CREATE);
		EndDialog(IDABORT);
		return FALSE;
	}

	// attempt to make it visible
	m_calc.SetVisible(TRUE);
	if (!m_calc.GetVisible())
	{
		AfxMessageBox(IDP_UNABLE_TO_SHOW);
		EndDialog(IDABORT);
		return FALSE;
	}

	// refresh display to contents of the automation calculator
	OnRefresh();

	return TRUE;  // return TRUE  unless you set the focus to a control
}
