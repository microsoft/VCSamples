// ImageCtl.h : Declaration of the CImageCtrl OLE control class.
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
// CImageCtrl : See ImageCtl.cpp for implementation.

class CImageCtrl : public COleControl
{
	DECLARE_DYNCREATE(CImageCtrl)

// Constructor
public:
	CImageCtrl();

	void AutoSize();
	void InformSize();
	void InformDlStatus(CBitmapProperty::DLState dlState);

	CBitmapProperty m_bitprop;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	virtual DWORD GetControlFlags();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CImageCtrl();

	DECLARE_OLECREATE_EX(CImageCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CImageCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CImageCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CImageCtrl)      // Type name and misc status

// Message maps
	//{{AFX_MSG(CImageCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CImageCtrl)
	BOOL m_bAutoSize;
	afx_msg void OnAutoSizeChanged();
	afx_msg BSTR GetImagePath();
	afx_msg void SetImagePath(LPCTSTR lpszNewValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CImageCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CImageCtrl)
	dispidAutoSize = 1L,
	dispidImagePath = 2L,
	//}}AFX_DISP_ID
	};
};
