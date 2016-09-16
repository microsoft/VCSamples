// timectl.h : Declaration of the CTimeCtrl OLE control class.
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
// Numeric constants

const int DEFAULT_INTERVAL  = 1000;


/////////////////////////////////////////////////////////////////////////////
// CTimeCtrl : See timectl.cpp for implementation.

class CTimeCtrl : public COleControl
{
	DECLARE_DYNCREATE(CTimeCtrl)

// Constructor
public:
	CTimeCtrl();

// Overrides

	// Drawing function
	virtual void OnDraw(
				CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);

	// Persistence
	virtual void DoPropExchange(CPropExchange* pPX);

	// Reset control state
	virtual void OnResetState();

	virtual void OnAmbientPropertyChange(DISPID dispid);

	virtual void OnEnabledChanged();

// Implementation
protected:
	~CTimeCtrl();

	DECLARE_OLECREATE_EX(CTimeCtrl) // Class factory and guid
	DECLARE_OLETYPELIB(CTimeCtrl)       // GetTypeInfo
	DECLARE_PROPPAGEIDS(CTimeCtrl)      // Property page IDs
	DECLARE_OLECTLTYPE(CTimeCtrl)       // Type name and misc status

// Message maps
	//{{AFX_MSG(CTimeCtrl)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CTimeCtrl)
	short m_interval;
	afx_msg void OnIntervalChanged();
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CTimeCtrl)
	void FireTimer()
		{FireEvent(eventidTimer,EVENT_PARAM(VTS_NONE));}
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CTimeCtrl)
	dispidInterval = 1L,
	eventidTimer = 1L,
	//}}AFX_DISP_ID
	};

protected:

	void OnSetClientSite();
	void StartTimer();
	void StopTimer();
};
