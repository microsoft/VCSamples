// btnctl.h : Declaration of the CButtonCtrl OLE control class.
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
// CButtonCtrl : See btnctl.cpp for implementation.

class CButtonCtrl : public COleControl
{
	DECLARE_DYNCREATE(CButtonCtrl)

// Constructor
public:
	CButtonCtrl();

// Overrides

	// Accelerator keys
	virtual BOOL PreTranslateMessage(MSG* pMsg);

	// Drawing function
	virtual void OnDraw(
				CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);

	// Persistence
	virtual void DoPropExchange(CPropExchange* pPX);

	// Reset control state
	virtual void OnResetState();

	virtual HMENU OnGetInPlaceMenu(void);

// Implementation
protected:
	~CButtonCtrl();

	CMenu m_menuInPlace;

	DECLARE_OLECREATE_EX(CButtonCtrl)   // Class factory and guid
	DECLARE_OLETYPELIB(CButtonCtrl)     // GetTypeInfo
	DECLARE_PROPPAGEIDS(CButtonCtrl)        // Property page IDs
	DECLARE_OLECTLTYPE(CButtonCtrl)     // Type name and misc status

	// Subclassed control support
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// Message maps
	//{{AFX_MSG(CButtonCtrl)
	afx_msg void CmdAbout();
	afx_msg void OnOptionsOption1();
	afx_msg void OnOptionsOption2();
	afx_msg void OnOptionsOption3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CButtonCtrl)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CButtonCtrl)
	void FireClick()
		{FireEvent(DISPID_CLICK,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CButtonCtrl)
	//}}AFX_DISP_ID
	};
};
