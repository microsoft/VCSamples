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

//This routine is used where you want to dump com exception info, 
//especially in catch blocks 
void dump_com_error(_com_error &e)
{
    _bstr_t bstrSource(e.Source());
    _bstr_t bstrDescription(e.Description());
    TCHAR szTemp[1024];
    CString csMsg = "Oops - hit an error!\n";
    _stprintf_s(szTemp, 1024, _T("Code = %08lx\n"), e.Error());
    csMsg += szTemp;
    _stprintf_s(szTemp, 1024, _T("Code meaning = %s\n"), e.ErrorMessage());
    csMsg += szTemp;
    _stprintf_s(szTemp, 1024, _T("Source = %s\n"), bstrSource.length() ? (LPCTSTR)bstrSource : _T("null"));
    csMsg += szTemp;
    _stprintf_s(szTemp, 1024, _T("Description = %s\n"), bstrDescription.length() ? (LPCTSTR)bstrDescription : _T("null"));
    csMsg += szTemp;
    AfxMessageBox(csMsg);
}

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

CCalcDrivApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CCalcDrivApp initialization

BOOL CCalcDrivApp::InitInstance()
{   
#ifdef _DEBUG
    #ifndef _MAC
        // turn on extra memory tracking
        afxMemDF |= checkAlwaysMemDF;
    #endif
#endif

    // Initialize OLE 2.0 libraries
    if (S_OK != OleInitialize(NULL))
    {
        AfxMessageBox(IDP_OLE_INIT_FAILED);
        return FALSE;
    }

    // Standard initialization
    // If you are not using these features and wish to reduce the size
    //  of your final executable, you should remove from the following
    //  the specific initialization routines you do not need.
#if _MFC_VER < 0x0700
	Enable3dControls();
#endif
    // Simple application that simply invokes a dialog
    CDriverDlg dlg;
    m_pMainWnd = &dlg;
    dlg.DoModal();

    return FALSE;   // don't run after the dialog is done
}

int CCalcDrivApp::ExitInstance()
{
    OleUninitialize();
    return CWinApp::ExitInstance();
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
    
    try {
        // shut down the calculator
        //  (since calculator shows its user-interface, it would stay active
        //  if we didn't shut it down with a call to its Quit method)
        m_calc->Close();
        m_calc.Release(); // decrement reference count and if 0, delete server
    } catch(_com_error& e) {
        dump_com_error(e);
    }
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
    int nStart=0, nEnd=0;
    m_editExpression.GetSel(nStart, nEnd);
    if (nStart == nLen)
        nStart = 0;
    psz += nStart;
    while (*psz != '\0')
    {
        TCHAR szTemp[2];
        szTemp[0] = *psz;
        szTemp[1] = '\0';
        m_calc->Button(szTemp);  //Call the Button method to pass the button to the server
        ++psz;
    }
    m_editExpression.SetSel(nLen, nLen);

    OnRefresh();    // refresh after all button commands sent
    m_calc->Evaluate();  //Tell the server to evaluate the expression
    m_calc->Display();
}

void CDriverDlg::OnSingleStep()
{
    // get current expression from the edit control
    CString strExpression;
    m_editExpression.GetWindowText(strExpression);
    LPCTSTR psz = strExpression;

    // send first character in selection, then move selection to next
    int nLen = strExpression.GetLength();
    int nStart=0, nEnd=0;
    m_editExpression.GetSel(nStart, nEnd);
    if (nStart == nLen)
        nStart = 0;
    psz += nStart;
    if (*psz != '\0')
    {
        TCHAR szTemp[2];
        szTemp[0] = *psz;
        szTemp[1] = '\0';
        m_calc->Button(szTemp);

        OnRefresh();        // refresh after each step

        // move to next character for next single-step
        m_editExpression.SetSel(nStart+1,
            min(strExpression.GetLength(), nStart+2));
    }
    else
    {
        m_calc->Evaluate();
        m_calc->Display();
        // stepping from end will start at beginning next time
        m_editExpression.SetSel(0, min(strExpression.GetLength(), 1));
    }
    OnRefresh();    // refresh after all button commands sent
}

void CDriverDlg::OnRefresh()
{
    TCHAR buf[64];
    long lResult = m_calc->Operand;  //Get the value of the Operand property
    _stprintf_s(buf, 64, _T("%ld"), lResult);
    m_stcOperand.SetWindowText(buf);

    long lAccum = m_calc->Accum;    //Get the value of the Accum property
    _stprintf_s(buf, 64, _T("%ld"), lAccum);
    m_stcAccum.SetWindowText(buf);

    short nOp = m_calc->Operation;  //Get the value of the Operation property
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
    // and init the COM object smart pointer

    try 
    {
        HRESULT hr = m_calc.GetActiveObject(__uuidof(CCCalcDlg));
        if (FAILED(hr))
        {
            hr = m_calc.CreateInstance(__uuidof(CCCalcDlg));
            if (FAILED(hr)) 
                _com_issue_error(hr);
        }
    }
    catch (_com_error& ce)
    {
        dump_com_error (ce);
        AfxMessageBox(IDP_UNABLE_TO_CREATE);
        EndDialog(IDABORT);
        return FALSE;
    }
    catch (...)
    {
        AfxMessageBox (_T("Unanticipated exception initializing ICalcDlgPtr object."));
        EndDialog(IDABORT);
        return FALSE;
    }

    // attempt to make it visible
    m_calc->Visible = VARIANT_TRUE;  //Set the Visible property
    if (!m_calc->Visible)   //If the object can't be made visible...
    {
        AfxMessageBox(IDP_UNABLE_TO_SHOW);
        EndDialog(IDABORT);
        return FALSE;
    }

    // refresh display to contents of the automation calculator
    OnRefresh();

    return TRUE;  // return TRUE  unless you set the focus to a control
}

