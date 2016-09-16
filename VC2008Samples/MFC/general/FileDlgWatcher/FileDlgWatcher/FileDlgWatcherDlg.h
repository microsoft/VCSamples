// FileDlgWatcherDlg.h : header file
//

#pragma once


// CFileDlgWatcherDlg dialog
class CFileDlgWatcherDlg : public CDialog
{
// Construction
public:
	CFileDlgWatcherDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_FILEDLGWATCHER_DIALOG };

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
public:
	afx_msg void OnBnClickedCreateDlg();
	afx_msg void OnBnClickedClearLog();
private:
	// Creates the log prologue based on the current settings
	void CreateLogPrologue();
	// Creates the log epilogue based on current settings
	void CreateLogEpilogue();

	BOOL m_bOpenFileDialog;
	BOOL m_bVistaStyle;
	BOOL m_bEventPopups;
	CString m_strLog;
};