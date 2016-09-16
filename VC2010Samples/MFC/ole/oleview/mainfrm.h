// mainfrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef _MAINFRM_H_
#define _MAINFRM_H_

// OnUpdate( lHint ) flags
#define UPD_ALL                0x00000000
#define UPD_NOOBJECTVIEW       0x00000001
#define UPD_NOINTERFACEVIEW    0x00000002
#define UPD_NOIFACELISTVIEW    0x00000004
#define UPD_NORELOAD           0x00000008

void WINAPI ViewInterface( HWND hwnd, REFIID riid, IUnknown *punk );

class CObjTreeView ;
class CRegistryView ;

class CMainFrame : public CFrameWnd
{
friend class COle2ViewApp ;
protected: // create from serialization only
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)
	BOOL SavePosition() ;
	BOOL RestorePosition(int nCmdShow) ;

// Implementation
public:
	virtual ~CMainFrame();
	virtual BOOL CMainFrame::LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE,
				CWnd* pParentWnd = NULL, CCreateContext* pContext = NULL);
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif


public:
	CSplitterWnd    m_wndSplitter ;
	CStatusBar      m_wndStatusBar;
	CToolBar        m_wndToolBar;

	CObjTreeView*   m_pObjTreeView ;
	CRegistryView*  m_pObjectView ;

// Generated message map functions
protected:
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnFileRunREGEDIT();
	afx_msg void OnViewRefresh();
	afx_msg void OnUpdateViewRefresh(CCmdUI* pCmdUI);
	afx_msg void OnSysColorChange();
	afx_msg void OnObjectDelete();
	afx_msg void OnUpdateObjectDelete(CCmdUI* pCmdUI);
	afx_msg void OnObjectVerify();
	afx_msg void OnUpdateObjectVerify(CCmdUI* pCmdUI);
	afx_msg void OnFileViewTypeLib();
	afx_msg void OnUseInProcServer();
	afx_msg void OnUpdateUseInProcServer(CCmdUI* pCmdUI);
	afx_msg void OnUseInProcHandler();
	afx_msg void OnUpdateUseInProcHandler(CCmdUI* pCmdUI);
	afx_msg void OnUseLocalServer();
	afx_msg void OnUpdateUseLocalServer(CCmdUI* pCmdUI);
	afx_msg void OnFileBind();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


#endif // _MAINFRM_H_
