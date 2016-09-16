
// MFCGdiInteropSampleDlg.h : header file
//

#pragma once

// CMFCGdiInteropSampleDlg dialog
class CMFCGdiInteropSampleDlg : public CDialogEx
{
// Construction
public:
	CMFCGdiInteropSampleDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_MFCGDIINTEROPSAMPLE_DIALOG };

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()

	CDCRenderTarget 		m_RenderTarget;
	CD2DSolidColorBrush*	m_pBlackBrush;
};
