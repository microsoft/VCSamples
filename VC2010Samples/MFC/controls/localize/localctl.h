// localctl.h : Declaration of the CLocalizeCtrl OLE control class.
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
// CLocalizeCtrl : See localctl.cpp for implementation.

class CLocalizeCtrl : public COleControl
{
	DECLARE_DYNCREATE(CLocalizeCtrl)

// Constructor
public:
	CLocalizeCtrl();

// Overrides

	// Drawing function
	virtual void OnDraw(
				CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);

	// Persistence
	virtual void DoPropExchange(CPropExchange* pPX);

	// Reset control state
	virtual void OnResetState();

	virtual void OnAmbientPropertyChange(DISPID dispid);

// Implementation
protected:
	~CLocalizeCtrl();

	DECLARE_OLECREATE_EX(CLocalizeCtrl) // Class factory and guid
	DECLARE_OLETYPELIB(CLocalizeCtrl)       // GetTypeInfo
	DECLARE_PROPPAGEIDS(CLocalizeCtrl)      // Property page IDs
	DECLARE_OLECTLTYPE(CLocalizeCtrl)       // Type name and misc status

// Message maps
	//{{AFX_MSG(CLocalizeCtrl)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnCancelMode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CLocalizeCtrl)
	BOOL m_invert;
	afx_msg void OnInvertChanged();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CLocalizeCtrl)
	void FireClick()
		{FireEvent(DISPID_CLICK,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CLocalizeCtrl)
	dispidInvert = 1L,
	//}}AFX_DISP_ID
	};

protected:
	BOOL m_inverted;

	virtual void LoadCaption();
	virtual HINSTANCE GetResourceHandle(LCID lcid);
};
