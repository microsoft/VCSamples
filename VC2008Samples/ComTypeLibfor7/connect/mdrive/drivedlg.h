// DriveDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMDriveDlg dialog

const int nMaxThreads = 10;

class CMDriveDlg : public CDialog
{
// Construction
public:
    CMDriveDlg(CWnd* pParent = NULL);   // standard constructor
    ~CMDriveDlg() { delete [] m_arrAdvise;}

// Dialog Data
    //{{AFX_DATA(CMDriveDlg)
    enum { IDD = IDD_MDRIVE_DIALOG };
        // NOTE: the ClassWizard will add data members here
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMDriveDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;
    IRandomPtr pRandom;
    long m_arrID[nMaxThreads];
//  int m_nThreadCnt;
    DWORD *m_arrAdvise;
    int m_nMaxAdvises;
    int m_nAdviseCnt;
    BOOL Unadvise();
    BOOL Stop();

    // Generated message map functions
    //{{AFX_MSG(CMDriveDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnStart();
    afx_msg void OnStop();
    afx_msg void OnStopAll();
    virtual void OnCancel();
    virtual void OnOK();
    afx_msg void OnAdvise();
    afx_msg void OnUnadvise();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};
