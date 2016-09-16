
// UIAnimationTestDlg.h : header file
//

#pragma once

#include "UIAnimationWnd.h"

// CUIAnimationTestDlg dialog
class CUIAnimationTestDlg : public CDialogEx
{
// Construction
public:
    CUIAnimationTestDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
    enum { IDD = IDD_UIANIMATIONCONTROL_DIALOG };

    protected:
    virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
    HICON m_hIcon;

    // Generated message map functions
    virtual BOOL OnInitDialog();
    afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
    afx_msg void OnPaint();
    afx_msg HCURSOR OnQueryDragIcon();
    afx_msg void OnClickedCheck();
    afx_msg void OnClickedCheckSlideUp();
    afx_msg void OnClickedCheckSlideDown();
    afx_msg void OnClickedCheckSlideLeft();
    afx_msg void OnClickedCheckSlideRight();
    afx_msg void OnSelchangeComboDuration();
    DECLARE_MESSAGE_MAP()

private:
    CUIAnimationWnd m_wndAnimation;

    CButton m_btnCheckFade;
    CButton m_btnCheckSlideUp;
    CButton m_btnCheckSlideDown;
    CButton m_btnCheckSlideLeft;
    CButton m_btnCheckSlideRight;
    CButton m_btnCheckScale;
    CButton m_btnCheckUseBoth;
    CComboBox m_comboDuration;

    CImageList m_ilIcons16;
    CImageList m_ilIcons32;
};
