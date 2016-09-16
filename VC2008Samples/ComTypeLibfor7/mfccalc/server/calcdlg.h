// calcdlg.h : header file
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CCalcDlg dialog

enum Operator { OpNone, OpAdd, OpSubtract, OpMultiply, OpDivide };
enum CalcError { ErrNone, ErrDivideByZero };

class CCalcDlg : public CDialog
{
// Construction
public:
    CCalcDlg(CWnd* pParent = NULL); // standard constructor

// Operations
    BOOL RegisterActive();

// Dialog Data
    //{{AFX_DATA(CCalcDlg)
    enum { IDD = IDD_MFCCALC_DIALOG };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CCalcDlg)
    public:
    virtual BOOL PreTranslateMessage(MSG* pMsg);
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    virtual void PostNcDestroy();
    //}}AFX_VIRTUAL

// Implementation
protected:
    virtual ~CCalcDlg();

    HICON m_hIcon;
    HACCEL m_hAccel;

    BOOL m_bAutoDelete;     // delete in PostNcDestroy
    DWORD m_dwRegister;     // active registration magic cookie

    // calculator state
    long m_accum;
    long m_operand;
    Operator m_operator;
    CalcError m_errorState;
    BOOL m_bOperandAvail;

    // helper functions
    void PerformOperation();
    void ClickedNumber(long lNum);
    void UpdateDisplay();

public: 
    // Generated message map functions
    //{{AFX_MSG(CCalcDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnClickedNumber(UINT nID);
    afx_msg void OnClickedClear();
    afx_msg void OnClickedDivide();
    afx_msg void OnClickedEqual();
    afx_msg void OnClickedMinus();
    afx_msg void OnClickedPlus();
    afx_msg void OnClickedTimes();
    virtual void OnCancel();
    virtual void OnOK();
    afx_msg void OnSetFocusAccum();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()

    // to be OLE creatable, it must be DYNCREATE and OLECREATE
    DECLARE_DYNCREATE(CCalcDlg)
    DECLARE_OLECREATE(CCalcDlg)

public:
    // Generated OLE dispatch map functions
    //{{AFX_DISPATCH(CCalcDlg)
    afx_msg long GetAccum();
    afx_msg void SetAccum(long nNewValue);
    afx_msg long GetOperand();
    afx_msg void SetOperand(long nNewValue);
    afx_msg short GetOperation();
    afx_msg void SetOperation(short nNewValue);
    afx_msg BOOL GetVisible();
    afx_msg void SetVisible(BOOL bNewValue);
    afx_msg BOOL Evaluate();
    afx_msg void Clear();
    afx_msg void Display();
    afx_msg void Close();
    afx_msg BOOL Button(LPCTSTR szButton);
    //}}AFX_DISPATCH
    DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()
};
