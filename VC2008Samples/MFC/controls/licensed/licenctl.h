// licenctl.h : Declaration of the CLicensedCtrl OLE control class.
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
// CLicensedCtrl : See licenctl.cpp for implementation.

class CLicensedCtrl : public COleControl
{
	DECLARE_DYNCREATE(CLicensedCtrl)

// Constructor
public:
	CLicensedCtrl();

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
	~CLicensedCtrl();

	BEGIN_OLEFACTORY(CLicensedCtrl)     // Class factory and guid
		virtual BOOL VerifyUserLicense();
		virtual BOOL GetLicenseKey(DWORD, BSTR FAR*);
	END_OLEFACTORY(CLicensedCtrl)

	DECLARE_OLETYPELIB(CLicensedCtrl)       // GetTypeInfo
	DECLARE_PROPPAGEIDS(CLicensedCtrl)      // Property page IDs
	DECLARE_OLECTLTYPE(CLicensedCtrl)       // Type name and misc status

// Message maps
	//{{AFX_MSG(CLicensedCtrl)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CLicensedCtrl)
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CLicensedCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CLicensedCtrl)
	//}}AFX_DISP_ID
	};
};
