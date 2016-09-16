// xlistctl.h : Declaration of the CXlistCtrl OLE control class.
//
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.



///////////////////////////////////////////////////////////////////////////
// CItemData : See xlistctl.cpp for implementation.

class CItemData : public CObject
{
public:

// Constructor/destructor

	CItemData(const TCHAR *pstrText, LPFONTDISP lpFontDisp, LPPICTUREDISP lpPicDisp);
	~CItemData();

 // Implementation

	OLE_COLOR *GetBackColor();
	void SetBackColor(OLE_COLOR *newValue);
	OLE_COLOR *GetForeColor();
	void SetForeColor(OLE_COLOR *newValue);
	void GetText(LPTSTR buffer, short szBuffer);
	void SetText(const TCHAR *newValue);
	CFontHolder *GetFont();
	void SetFont(LPFONTDISP newValue);
	CPictureHolder *GetPicture();
	void SetPicture(LPPICTUREDISP newValue);

protected:
	OLE_COLOR *pBack;
	OLE_COLOR *pFore;
	CString *pText;
	CFontHolder *pFontHolder;
	CPictureHolder *pPicHolder;
};


/////////////////////////////////////////////////////////////////////////////
// CXlistCtrl : See xlistctl.cpp for implementation.

class CXlistCtrl : public COleControl
{
	DECLARE_DYNCREATE(CXlistCtrl)

// Constructor
public:
	CXlistCtrl();

// Overrides

	// Drawing function
	virtual void OnDraw(
				CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);

	// Persistence
	virtual void DoPropExchange(CPropExchange* pPX);

	// Reset control state
	virtual void OnResetState();

	// Notification of extended object available
	virtual void OnSetClientSite();

// Implementation
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	~CXlistCtrl();

	DECLARE_OLECREATE_EX(CXlistCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CXlistCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CXlistCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CXlistCtrl)      // Type name and misc status

	// Subclassed control support
	BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

	virtual void OnAmbientPropertyChange(DISPID dispid);

	LRESULT OnOcmDrawItem(WPARAM wParam, LPARAM lParam);
	LRESULT OnOcmMeasureItem(WPARAM wParam, LPARAM lParam);

	virtual void AddItem(short nIndex, LPCTSTR lpstrText, LPFONTDISP lpFontDisp,
		LPPICTUREDISP lpPicDisp);

	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	virtual void SelectItemBackColor(CItemData *pItemData, LPRECT rect, CDC *pdc);
	virtual void DrawItemPicture(CItemData *pItemData, LPRECT rect, CDC *pdc);
	virtual void DrawItemText(CItemData *pItemData, LPRECT rect, CDC *pdc);
	virtual void SelectItemForeColor(CItemData *pItemData, CDC *pdc);
	virtual CFont* SelectItemFont(CItemData *pItemData, CDC *pdc,
		CFontHolder& fontHolder);

	virtual void MeasureItem(LPMEASUREITEMSTRUCT lpMI);
	virtual int GetItemTextHeight(CItemData *pItemData);
	virtual int GetItemPictureHeight(CItemData *pItemData);

	virtual void UpdateItems();
	virtual void UpdateDefHeight();

// Message maps
	//{{AFX_MSG(CXlistCtrl)
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CXlistCtrl)
	BOOL m_invertFlag;
	afx_msg void OnInvertFlagChanged();
	afx_msg void RemoveItem(short nIndex);
	afx_msg void Clear();
	afx_msg void AddTextFontItem(short nIndex, LPCTSTR lpstrText, LPFONTDISP font);
	afx_msg void AddTextItem(short nIndex, LPCTSTR lpstrText);
	afx_msg void AddPicItem(short nIndex, LPPICTUREDISP pic);
	afx_msg OLE_COLOR GetItemBackColor(short nIndex);
	afx_msg void SetItemBackColor(short nIndex, OLE_COLOR newValue);
	afx_msg OLE_COLOR GetItemForeColor(short nIndex);
	afx_msg void SetItemForeColor(short nIndex, OLE_COLOR newValue);
	afx_msg BSTR GetItemText(short nIndex);
	afx_msg void SetItemText(short nIndex, LPCTSTR lpszNewValue);
	afx_msg LPFONTDISP GetItemFont(short nIndex);
	afx_msg void SetItemFont(short nIndex, LPFONTDISP newValue);
	afx_msg LPPICTUREDISP GetItemPicture(short nIndex);
	afx_msg void SetItemPicture(short nIndex, LPPICTUREDISP newValue);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// Event maps
	//{{AFX_EVENT(CXlistCtrl)
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CXlistCtrl)
	dispidInvertFlag = 1L,
	dispidItemBackColor = 7L,
	dispidItemForeColor = 8L,
	dispidItemText = 9L,
	dispidItemFont = 10L,
	dispidItemPicture = 11L,
	dispidRemoveItem = 2L,
	dispidClear = 3L,
	dispidAddTextFontItem = 4L,
	dispidAddTextItem = 5L,
	dispidAddPicItem = 6L,
	//}}AFX_DISP_ID
	};

// Data members
protected:
	CObArray m_itemData;
	short m_itemDefHeight;
};
