// File: MethodDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_CMETHODDLG_H__BA8090EB_BFF5_11D0_8DFA_00C04FB68D60__INCLUDED_)
#define AFX_CMETHODDLG_H__BA8090EB_BFF5_11D0_8DFA_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CMethodDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMethodDlg dialog

class CMethodDlg : public CDialog
{
// Construction
public:
   CMethodDlg( CWnd* pParent, IDispatch* pDispatch,
	  CInterfaceInfo* pInterfaceInfo );
   ~CMethodDlg();

// Dialog Data
	//{{AFX_DATA(CMethodDlg)
	enum { IDD = IDD_METHOD };
	CComboBox	m_cboxParamValue;
	CDateTimeCtrl	m_date;
	CStatic m_staticParameterValue;
	CEdit   m_editExceptionDesc;
	CEdit   m_editExceptionSource;
	CEdit   m_editReturnValue;
	CEdit   m_editParamValue;
	CListCtrl   m_listParams;
	CComboBox   m_cboxParamType;
	CComboBox   m_cboxMethodName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMethodDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   void DisplayExceptionInfo();
   void DisplayParamValueInList( int iParam );
	void DisplayParamValues( int iType );
   COleVariant* GetParam( int iParam );

protected:
   IDispatchPtr m_pDispatch;
   CInterfaceInfo* m_pInterfaceInfo;
   CMethodInfo* m_pMethodInfo;
   CMethodParamInfo* m_pParamInfo;
   CTypedPtrArray< CPtrArray, COleVariant* > m_apParams;
   int* m_piParamTypes;
   COleVariant* m_pvarParams;
   COleVariant* m_pvarCurrentParam;
   int m_iCurrentParam;
   COleVariant m_varResult;
   CExcepInfo m_excepInfo;
   BOOL m_tException;

	// Generated message map functions
	//{{AFX_MSG(CMethodDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnMethodNameSelChange();
	afx_msg void OnParamsItemChanged(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetValue();
	afx_msg void OnInvoke();
	afx_msg void OnParamValueSetFocus();
	afx_msg void OnParamValueChange();
	afx_msg void OnExceptionHelp();
	afx_msg void OnParamTypeSelChange();
	afx_msg void OnChooseColor();
	afx_msg void OnChooseFont();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMETHODDLG_H__BA8090EB_BFF5_11D0_8DFA_00C04FB68D60__INCLUDED_)
