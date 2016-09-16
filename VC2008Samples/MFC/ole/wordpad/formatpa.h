// formatpa.h : header file
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
// CFormatParaDlg dialog

class CFormatParaDlg : public CCSDialog
{
// Construction
public:
	CFormatParaDlg(PARAFORMAT2& pf, CWnd* pParent = NULL);   // standard constructor
	PARAFORMAT2 m_pf;

// Attributes
	int m_nWordWrap;

// Dialog Data
	//{{AFX_DATA(CFormatParaDlg)
	enum { IDD = IDD_FORMAT_PARA };
	int     m_nAlignment;
	int     m_nFirst;
	int     m_nLeft;
	int     m_nRight;
	BOOL	m_bPageBreak;
	int		m_nAfter;
	int		m_nBefore;
	//}}AFX_DATA

// Implementation
protected:
	static const DWORD m_nHelpIDs[];
	virtual const DWORD* GetHelpIDs() {return m_nHelpIDs;}
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnOK();

	// Generated message map functions
	//{{AFX_MSG(CFormatParaDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnDeltaposSpinBefore(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinAfter(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
