// IMEDlg.h : header file
//

#if !defined(AFX_IMEDLG_H__8E60BE08_2516_11D4_8ABF_00B0D02D1522__INCLUDED_)
#define AFX_IMEDLG_H__8E60BE08_2516_11D4_8ABF_00B0D02D1522__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CIMEDlg dialog

class CIMEDlg : public CDialog
{
// Construction
public:
	CIMEDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CIMEDlg)
	enum { IDD = IDD_IME_DIALOG };
	CComboBox	m_FontList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIMEDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

protected:
	HIMC			m_hImc;
	CIMEEdit		m_IMEEdit;
	UINT			m_nSelectedID;

// Implementation
protected:
	void SetOption();
	void GetIMEMode(HWND hWnd);
	void SetIMEMode(HWND hWnd, DWORD dwNewConvMode, DWORD dwNewSentMode, BOOL fFlag);
	static BOOL CALLBACK AFX_EXPORT EnumFontFamExProc(
		ENUMLOGFONTEX* pelf, NEWTEXTMETRICEX* /*lpntm*/, int FontType,
		LPVOID pThis);
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CIMEDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRadioImeEnable();
	afx_msg void OnRadioImeDisable();
	afx_msg void OnOk();
	afx_msg void OnSelchangeComboFont();
	//}}AFX_MSG
	afx_msg LRESULT OnSetInputLang(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnReSetIME(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnSetIME(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnToggleJPNIME(WPARAM wParam, LPARAM lParam);
	afx_msg void OnChangeOption(UINT nID);
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMEDLG_H__8E60BE08_2516_11D4_8ABF_00B0D02D1522__INCLUDED_)
