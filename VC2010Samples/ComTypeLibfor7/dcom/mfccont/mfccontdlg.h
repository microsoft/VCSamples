// MFCContDlg.h : header file
//
//{{AFX_INCLUDES()
#include "drawctl.h"
//}}AFX_INCLUDES

#if !defined(AFX_MFCCONTDLG_H__29DC9F78_5706_11D0_9899_00C04FD7D06E__INCLUDED_)
#define AFX_MFCCONTDLG_H__29DC9F78_5706_11D0_9899_00C04FD7D06E__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CMFCContDlg dialog

class CMFCContDlg : public CDialog
{
// Construction
public:
    CMFCContDlg(CWnd* pParent = NULL);  // standard constructor

// Dialog Data
    //{{AFX_DATA(CMFCContDlg)
    enum { IDD = IDD_MFCCONT_DIALOG };
    CDrawCtl    m_DrawCtl;
    //}}AFX_DATA

    // ClassWizard generated virtual function overrides
    //{{AFX_VIRTUAL(CMFCContDlg)
    protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    //}}AFX_VIRTUAL

// Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    //{{AFX_MSG(CMFCContDlg)
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnClear();
    afx_msg void OnConnect();
    afx_msg void OnDisconnect();
    //}}AFX_MSG
    DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCCONTDLG_H__29DC9F78_5706_11D0_9899_00C04FD7D06E__INCLUDED_)
