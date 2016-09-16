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

#pragma once

class CPropertiesToolBar : public CMFCToolBar
{
public:	
	virtual void OnUpdateCmdUI(CFrameWnd* /*pTarget*/, BOOL bDisableIfNoHndler)	
	{		
		CMFCToolBar::OnUpdateCmdUI ((CFrameWnd*) GetOwner (), bDisableIfNoHndler);
	}

	virtual BOOL AllowShowOnList () const		{	return FALSE;	}
};

class CPropertiesViewBar : public CDockablePane  
{
public:
	CPropertiesViewBar(void);

	void AdjustLayout ();

// Attributes
public:
	void SetVSDotNetLook (BOOL bSet)
	{
		m_wndPropList.SetVSDotNetLook (bSet);
		m_wndPropList.SetGroupNameFullWidth (bSet);
	}

	CMFCPropertyGridCtrl* GetPropList () {return &m_wndPropList;}		

protected:
	CPropertiesToolBar	m_wndToolBar;
	CMFCPropertyGridCtrl		m_wndPropList;

// Attributes
protected:

// Implementation
public:
	virtual ~CPropertiesViewBar();

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnPropListTreeMode ();
	afx_msg void OnPropListAlphabetMode ();
	afx_msg void OnUpdatePropListTreeMode (CCmdUI* pCmdUI);
	afx_msg void OnUpdatePropListAlphabetMode (CCmdUI* pCmdUI);

	DECLARE_MESSAGE_MAP()
};

