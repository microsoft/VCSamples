// pushctl.h : Declaration of the CPushCtrl OLE control class.
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
// CPushCtrl : See pushctl.cpp for implementation.

class CPushCtrl : public COleControl
{
	DECLARE_DYNCREATE(CPushCtrl)

// Constructor
public:
	CPushCtrl();

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
	~CPushCtrl();

	DECLARE_OLECREATE_EX(CPushCtrl) // Class factory and guid
	DECLARE_OLETYPELIB(CPushCtrl)       // GetTypeInfo
	DECLARE_PROPPAGEIDS(CPushCtrl)      // Property page IDs
	DECLARE_OLECTLTYPE(CPushCtrl)       // Type name and misc status

	// Subclassed control support
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);


	LRESULT OnOcmDrawItem(WPARAM wParam, LPARAM lParam);
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);

// Message maps
	//{{AFX_MSG(CPushCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CPushCtrl)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CPushCtrl)
	void FireCustomClick(LPCTSTR lpstrCaption, short cchCaption)
		{FireEvent(eventidCustomClick,EVENT_PARAM(VTS_BSTR  VTS_I2), lpstrCaption, cchCaption);}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CPushCtrl)
	eventidCustomClick = 1L,
	//}}AFX_DISP_ID
	};

};
