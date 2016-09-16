// CmnCtrl3Dlg.h : header file
//

#pragma once


// CCmnCtrl3Dlg dialog
class CCmnCtrl3Dlg : public CDialog
{
// Construction
public:
	CCmnCtrl3Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_CMNCTRL3_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
