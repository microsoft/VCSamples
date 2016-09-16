#if !defined(CTLCOMMDLG_H__448D35FF_31CD_11D0_AE62_00C04FD7D06E__INCLUDED_)
#define CTLCOMMDLG_H__448D35FF_31CD_11D0_AE62_00C04FD7D06E__INCLUDED_

// ctlcommDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCtlcommDlg dialog

class CCtlcommDlg : public CDialog
{
// Construction
public:
    CCtlcommDlg(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
    //{{AFX_DATA(CCtlcommDlg)
    enum { IDD = IDD_CTLCOMM_DIALOG };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CCtlcommDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;
    IOuterPtr pOuter;

    // Generated message map functions
    //{{AFX_MSG(CCtlcommDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnCom1();
    afx_msg void OnCom2();
    afx_msg void OnCom3();
    afx_msg void OnCom4();
    afx_msg void OnCom5();
    afx_msg void OnCom6();
    afx_msg void OnCom7();
    afx_msg void OnCom8();
    afx_msg void OnClose();
    afx_msg void OnReset();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(CTLCOMMDLG_H__448D35FF_31CD_11D0_AE62_00C04FD7D06E__INCLUDED)
