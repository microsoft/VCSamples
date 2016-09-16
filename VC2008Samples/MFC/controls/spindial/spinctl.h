// spinctl.h : Declaration of the CSpindialCtrl OLE control class.
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
// CSpindialCtrl : See spinctl.cpp for implementation.

class CSpindialCtrl : public COleControl
{
	DECLARE_DYNCREATE(CSpindialCtrl)

// Constructor
public:
	CSpindialCtrl();

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
	~CSpindialCtrl();

	DECLARE_OLECREATE_EX(CSpindialCtrl) // Class factory and guid
	DECLARE_OLETYPELIB(CSpindialCtrl)       // GetTypeInfo
	DECLARE_PROPPAGEIDS(CSpindialCtrl)      // Property page IDs
	DECLARE_OLECTLTYPE(CSpindialCtrl)       // Type name and misc status

// Message maps
	//{{AFX_MSG(CSpindialCtrl)
			afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
		//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CSpindialCtrl)
	afx_msg short GetNeedlePosition();
	afx_msg void SetNeedlePosition(short nNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CSpindialCtrl)
	void FireSpinPositive()
		{FireEvent(eventidSpinPositive,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CSpindialCtrl)
	dispidNeedlePosition = 1L,
	eventidSpinPositive = 1L,
	//}}AFX_DISP_ID
	};

	virtual void SpinNeedlePosition();

protected:
	short   m_needlePosition;
};
