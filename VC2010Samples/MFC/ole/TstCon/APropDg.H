// File: APropDg.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_CAMBIENTPROPERTIESDLG_H__4D06A27D_C318_11D0_8DFF_00C04FB68D60__INCLUDED_)
#define AFX_CAMBIENTPROPERTIESDLG_H__4D06A27D_C318_11D0_8DFF_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// CAmbientPropertiesDlg.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAmbientPropertiesDlg dialog

class CAmbientPropertiesDlg : public CDialog
{
// Construction
public:
	CAmbientPropertiesDlg( CWnd* pParent, CTestContainer98Doc* pDoc );

   BOOL GetChangedPropertyID( DISPID* pdispid ) const;

// Dialog Data
	//{{AFX_DATA(CAmbientPropertiesDlg)
	enum { IDD = IDD_AMBIENTPROPERTIES };
	CComboBox	m_cboxPropValue;
	CDateTimeCtrl	m_date;
	CStatic m_staticPropertyValue;
	CEdit   m_editDISPID;
	CButton m_butChooseFont;
	CButton m_butChooseColor;
	CComboBox   m_cboxPropName;
	CButton m_butSetValue;
	CEdit   m_editPropValue;
	CComboBox   m_cboxPropType;
	CButton m_checkEnabled;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAmbientPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   void DisplayPropValues( int iType );
   void OnPropertyChanged( DISPID id );

protected:
   CTestContainer98Doc* m_pDoc;
   CAmbientProperty* m_pProp;
   BOOL m_tChanged;
   DISPID m_dispidChanged;

	// Generated message map functions
	//{{AFX_MSG(CAmbientPropertiesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPropNameSelChange();
	afx_msg void OnPropTypeSelChange();
	afx_msg void OnSetValue();
	afx_msg void OnEnabled();
	afx_msg void OnChooseColor();
	afx_msg void OnChooseFont();
	afx_msg void OnNewProperty();
	afx_msg void OnPropValueSetFocus();
	afx_msg BOOL OnHelpInfo(HELPINFO* pHelpInfo);
	afx_msg void OnContextMenu(CWnd* , CPoint);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAMBIENTPROPERTIESDLG_H__4D06A27D_C318_11D0_8DFF_00C04FB68D60__INCLUDED_)
