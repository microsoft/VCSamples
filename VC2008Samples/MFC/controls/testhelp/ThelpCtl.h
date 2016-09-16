// ThelpCtl.h : Declaration of the CTesthelpCtrl OLE control class.

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

/////////////////////////////////////////////////////////////////////////////
// CTesthelpCtrl : See ThelpCtl.cpp for implementation.
class CTesthelpCtrl : public COleControl
{
	 DECLARE_DYNCREATE(CTesthelpCtrl)

// Constructor
public:

	 void RelayEvent(UINT message, WPARAM wParam, LPARAM lParam);
	 CToolTipCtrl m_ttip;
	 LRESULT OnHelpCommand(UINT_PTR wParam, LONG_PTR lParam);

	 CTesthelpCtrl();
// Overrides

	 // Drawing function
	 virtual void OnDraw(
					CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);

	 // Persistence
	 virtual void DoPropExchange(CPropExchange* pPX);

	 // Reset control state
	 virtual void OnResetState();

// Implementation
protected:
	 ~CTesthelpCtrl();

	 DECLARE_OLECREATE_EX(CTesthelpCtrl)    // Class factory and guid
	 DECLARE_OLETYPELIB(CTesthelpCtrl)      // GetTypeInfo
	 DECLARE_PROPPAGEIDS(CTesthelpCtrl)     // Property page IDs
	 DECLARE_OLECTLTYPE(CTesthelpCtrl)          // Type name and misc status

// Message maps
	 //{{AFX_MSG(CTesthelpCtrl)
	 afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	 afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	 afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	 afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	 DECLARE_MESSAGE_MAP()

// Dispatch maps
	 //{{AFX_DISPATCH(CTesthelpCtrl)
	CString m_szName1;
	afx_msg void OnName1Changed();
	CString m_szName2;
	afx_msg void OnName2Changed();
	CString m_szName3;
	afx_msg void OnName3Changed();
	BOOL m_bUseMyHelp;
	afx_msg void OnUseMyHelpChanged();
	BOOL m_bShowToolTip;
	afx_msg void OnShowToolTipChanged();
	CString m_szToolTipText;
	afx_msg void OnToolTipTextChanged();
	short m_nUsePopupHelp;
	afx_msg void OnUsePopupHelpChanged();
	//}}AFX_DISPATCH
	 DECLARE_DISPATCH_MAP()

	 afx_msg void AboutBox();

// Event maps
	 //{{AFX_EVENT(CTesthelpCtrl)
	//}}AFX_EVENT
	 DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	 enum {
	 //{{AFX_DISP_ID(CTesthelpCtrl)
	dispidName1 = 1L,
	dispidName2 = 2L,
	dispidName3 = 3L,
	dispidUseMyHelp = 4L,
	dispidShowToolTip = 5L,
	dispidToolTipText = 6L,
	dispidUsePopupHelp = 7L,
	//}}AFX_DISP_ID
	 };


};
