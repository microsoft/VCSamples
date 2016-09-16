// TraceToolDlg.h : header file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma once

typedef struct tagTRACESETTINGS
{
	DWORD_PTR dwHandle;
	ATLTRACESETTINGS ts;
	BOOL bModified;
} TRACESETTINGS;

typedef struct tagPROCESSSETTINGS
{
	DWORD_PTR dwProcess;
	ATLTRACEPROCESSSETTINGS ps;
	BOOL bModified;
} PROCESSSETTINGS;

// CTraceToolDlg dialog
class CTraceToolDlg : public CDialog
{
// Construction
public:
	CTraceToolDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_TRACETOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	void PopulateTree();
	void UpdateControls();
	void Cleanup();
	void InitVariables();
	static DWORD WINAPI NotifyThread( void* pContext );
	void UpdateProcess();
	void UpdateModule();
	void UpdateCategory();
	void RefreshProcess(DWORD_PTR dwProcess);
	void UpdateSelectedItem(HTREEITEM hItem);

public:
	CTreeCtrl m_tree;
	int m_nProcessLevel;
	void OnSelchangedTraceTree(NMHDR *pNMHDR, LRESULT *pResult);
	int m_nModuleLevel;
	int m_nCategoryLevel;
	int m_iModuleStatus;
	int m_iCategoryStatus;
	CSliderCtrl m_sliderProcessLevel;
	CSliderCtrl m_sliderModuleLevel;
	CSliderCtrl m_sliderCategoryLevel;

private:
	PROCESSSETTINGS *m_pPS;	
	TRACESETTINGS *m_pTSModule;	
	TRACESETTINGS *m_pTSCategory;	
	CAtlArray< ATL::CHandle > m_ahProcesses;
	ATL::CEvent m_hShutdownEvent;
	ATL::CHandle m_hNotifyThread;
	BOOL m_bDeleting;
	BOOL m_bDirty;

public:
	afx_msg void OnClickedApply(void);
	BOOL m_bFuncAndCategory;
	BOOL m_bFileAndLine;
	BOOL m_bProcessEnabled;
	afx_msg void OnClickedClose(void);
	afx_msg void OnProcessChanged();
	afx_msg void OnModuleChanged();
	afx_msg void OnCategoryChanged();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedRefresh();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	virtual BOOL OnWndMsg( UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult );
	virtual void OnCancel();
};
