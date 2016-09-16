// This MFC Samples source code demonstrates using MFC Microsoft Office Fluent User Interface 
// (the "Fluent UI") and is provided only as referential material to supplement the 
// Microsoft Foundation Classes Reference and related electronic documentation 
// included with the MFC C++ library software.  
// License terms to copy, use or distribute the Fluent UI are available separately.  
// To learn more about our Fluent UI licensing program, please visit 
// http://msdn.microsoft.com/officeui.
//
// Copyright (C) Microsoft Corporation
// All rights reserved.

class CDrawView;
#include "drawobj.h"

#define ID_FORMAT_CONTEXT_TAB 1

class CMainFrame : public CMDIFrameWndEx
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	struct XStyle
	{
		COLORREF clrFill;
		COLORREF clrLine;
	};

public:
	CMainFrame();

	// Attributes
public:
	CMFCRibbonBar* GetRibbonBar() {return &m_wndRibbonBar;}

	// Operations
public:
	void UpdateUI(CDrawView* pCurrView);
	void UpdateContextTab(CDrawView* pCurrView);
	void UpdateContextTabFromObject(CDrawObjList& list);

	COLORREF GetColorFromColorButton(int nButtonID);
	int GetWeightFromLineWeight(int nButtonID);
	BOOL GetStyleFromStyles(XStyle& style);

	void SetRibbonContextCategory(UINT uiCategoryID);
	void ActivateRibbonContextCategory(UINT uiCategoryID);

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	// control bar embedded members
	CMFCRibbonStatusBar m_wndStatusBar;
	CMFCRibbonBar m_wndRibbonBar;
	CMFCRibbonApplicationButton m_MainButton;

	// panel images
	CMFCToolBarImages m_PanelImages;

	// Document colors for demo:
	CList<COLORREF,COLORREF> m_lstMainColors;
	CList<COLORREF,COLORREF> m_lstAdditionalColors;
	CList<COLORREF,COLORREF> m_lstStandardColors;

	// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnAppLook(UINT id);
	afx_msg void OnUpdateAppLook(CCmdUI* pCmdUI);
	afx_msg void OnWindowManager();
	afx_msg void OnMdiMoveToNextGroup();
	afx_msg void OnMdiMoveToPrevGroup();
	afx_msg void OnMdiNewHorzTabGroup();
	afx_msg void OnMdiNewVertGroup();
	afx_msg void OnMdiCancel();
	afx_msg LRESULT OnRibbonCustomize(WPARAM wp, LPARAM lp);
	afx_msg LRESULT OnHighlightRibbonListItem(WPARAM wp, LPARAM lp);
	afx_msg void OnToolsOptions();
	afx_msg void OnDummy();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

	virtual BOOL OnShowMDITabContextMenu(CPoint point, DWORD dwAllowedItems, BOOL bDrop);
	virtual BOOL OnShowPopupMenu(CMFCPopupMenu* pMenuPopup);

	void ShowOptions(int nPage);
	void CreateDocumentColors();

private:
	BOOL CreateRibbonBar();
	BOOL CreateStatusBar();

	void InitMainButton();
	void InitHomeCategory();
	void InitViewCategory();
	void InitTabButtons();

	void AddContextTab_Format();

	void AdjustObjectSubmenu(CMFCPopupMenu* pMenuPopup);
	void UpdateStatusBarCountPane(int nID, CString strText, int nCount);

	UINT m_nAppLook;
};


