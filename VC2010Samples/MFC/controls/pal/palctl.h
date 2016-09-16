// palctl.h : Declaration of the CPalCtrl OLE control class.
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
// Error codes

#define PAL_E_CANTRESIZEPALETTE CUSTOM_CTL_SCODE(32002) // Can't resize palette


/////////////////////////////////////////////////////////////////////////////
// CPalCtrl : See palctl.cpp for implementation.

class CPalCtrl : public COleControl
{
	DECLARE_DYNCREATE(CPalCtrl)

// Constructor
public:
	CPalCtrl();

// Overrides

	// Drawing function
	virtual void OnDraw(
				CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);

	// Persistence
	virtual void DoPropExchange(CPropExchange* pPX);

	// Reset control state
	virtual void OnResetState();

	// Serialization
	virtual void Serialize(CArchive& ar);

	BOOL OnMapPropertyToPage(DISPID dispid, LPCLSID lpclsid, BOOL* pbPageOptional);

// Implementation
protected:
	~CPalCtrl();

	DECLARE_OLECREATE_EX(CPalCtrl)  // Class factory and guid
	DECLARE_OLETYPELIB(CPalCtrl)        // GetTypeInfo
	DECLARE_PROPPAGEIDS(CPalCtrl)       // Property page IDs
	DECLARE_OLECTLTYPE(CPalCtrl)        // Type name and misc status

// Message maps
	//{{AFX_MSG(CPalCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CPalCtrl)
	afx_msg short GetLength();
	afx_msg void SetLength(short nNewValue);
	afx_msg LPPICTUREDISP GetPicture();
	afx_msg void SetPicture(LPPICTUREDISP newValue);
	afx_msg OLE_COLOR GetEntry(short nIndex);
	afx_msg void SetEntry(short nIndex, OLE_COLOR newValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CPalCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CPalCtrl)
	dispidLength = 1L,
	dispidHandle = 2L,
	dispidPicture = 3L,
	dispidEntry = 4L,
	//}}AFX_DISP_ID
	};

// Data Members
	CPalette *m_iPalette;
};
