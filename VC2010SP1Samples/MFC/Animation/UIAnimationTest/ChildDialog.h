#pragma once


// CChildDialog dialog

class CChildDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CChildDialog)

public:
	CChildDialog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CChildDialog();

// Dialog Data
	enum { IDD = IDD_CHILD_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
    CComboBox m_wndCombo;
    CSliderCtrl m_wndSlider;
    CProgressCtrl m_wndProgress;
    afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
    virtual BOOL OnInitDialog();
};
