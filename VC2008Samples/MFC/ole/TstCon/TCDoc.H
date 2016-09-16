// CTestContainer98Doc.h : interface of the CTestContainer98Doc class
//
/////////////////////////////////////////////////////////////////////////////
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_CTESTCONTAINER98DOC_H__19818508_B837_11D0_8DF1_00C04FB68D60__INCLUDED_)
#define AFX_CTESTCONTAINER98DOC_H__19818508_B837_11D0_8DF1_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

const LPARAM HINT_UPDATE_WINDOW = 0;
const LPARAM HINT_UPDATE_ITEM = 1;

class CTestContainer98Doc : public COleDocument
{
protected: // create from serialization only
	CTestContainer98Doc();
	DECLARE_DYNCREATE(CTestContainer98Doc)

// Attributes
public:
   void BringToFront( CDocItem* pItem );
   void SendToBack( CDocItem* pItem );
   POSITION FindItem( CDocItem* pItem ) const;
   POSITION GetTailPosition() const;
   CDocItem* GetPrevItem( POSITION& pos ) const;
   BOOL GetUserMode() const;
   void SetUserMode( BOOL tUserMode );

// Operations
public:
   int AddAmbientProperty( DISPID dispid, LPCTSTR pszName, const VARIANT& var,
	  int vti );
   CTestContainer98Item* AddControl( REFCLSID clsid, LPCTSTR pszName,
	  REFIID iidPersistanceMedium = IID_NULL, IUnknown* pPersistanceMedium =
	  NULL );
   void CreateUniqueItemName( CTestContainer98Item* pItem, LPCTSTR pszBaseName,
	  CString& strUniqueName );
	CAmbientProperty* FindAmbientProperty( DISPID dispid );
   CAmbientProperty* FindAmbientProperty( LPCOLESTR pszName );
   CAmbientProperty* GetAmbientProperty( int iProp );
   int GetNumAmbientProperties() const;
   CEdit* GetOutputEditControl();
   CTestContainer98View* GetView() const;
   BOOL CanWindowlessActivate() const;
   BOOL HonorIgnoreActivateWhenVisible() const;
   BOOL UseIPointerInactive() const;
   BOOL UseSlowDrawing() const;
   BOOL UseTwoPassDrawing() const;
   BOOL UseQuickActivation() const;
   BOOL SupportsInterface( REFIID iid );
   BOOL SupportsService( REFGUID sid );
   void PreCloseFrame( CFrameWnd* pFrame );
   CLog* GetLog() const;
   void SetItemTabOrder( CTestContainer98Item* pItem, int iTabOrder );
   CTestContainer98Item* GetNextTabItem( CTestContainer98Item* pItem ) const;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestContainer98Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL CanCloseFrame(CFrameWnd* pFrame);
	virtual BOOL OnSaveDocument(LPCTSTR lpszPathName);
	virtual void AddItem(CDocItem* pItem);
	virtual void DeleteContents();
	virtual void RemoveItem(CDocItem* pItem);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestContainer98Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	
	void RunAutomationScript(LPCTSTR szScriptFile);

protected:
   CString m_strDirectory;
   CTypedPtrArray< CObArray, CAmbientProperty* > m_apAmbientProperties;
   CFontHolder* m_pFontHolder;
   FONTDESC m_descFont;
   BOOL m_tUserMode;
   BOOL m_tFreezeEvents;
   BOOL m_tAllowWindowless;
   BOOL m_tTwoPassDrawing;
   BOOL m_tSlowDrawing;
   BOOL m_tHonorIgnoreActivateWhenVisible;
   BOOL m_tUseIPointerInactive;
   BOOL m_tUseQuickActivation;
   BOOL m_tIOleInPlaceSiteWindowless;
   BOOL m_tIOleInPlaceSiteEx;
   BOOL m_tIAdviseSinkEx;
   BOOL m_tSBindHost;
   IStreamPtr m_pStream;
   IStoragePtr m_pStorage;
   CLog* m_pLog;
   CTypedPtrList< CObList, CTestContainer98Item* > m_lpTabOrder;
   IActiveScriptPtr m_pActiveScript;
   IActiveScriptParsePtr m_pActiveScriptParse;
   CScriptManager* m_pScriptManager;

// Generated message map functions
protected:
   void Cleanup();
   void BroadcastAmbientPropertyChange( DISPID dispid );
   void FireOnNewControl( IDispatch* pControl );
   CScriptManager* GetScriptManager( BOOL tCreate = TRUE );
	HRESULT InitDefaultAmbientProperties();
   BOOL Initialize();
   HRESULT InitScriptManager();
   BOOL GetDispatchIID( IID* piid );

	//{{AFX_MSG(CTestContainer98Doc)
	afx_msg void OnOptionsFreezeEvents();
	afx_msg void OnUpdateOptionsFreezeEvents(CCmdUI* pCmdUI);
	afx_msg void OnOptionsSlowDrawing();
	afx_msg void OnUpdateOptionsSlowDrawing(CCmdUI* pCmdUI);
	afx_msg void OnOptionsTwoPassDrawing();
	afx_msg void OnUpdateOptionsTwoPassDrawing(CCmdUI* pCmdUI);
	afx_msg void OnOptionsLogging();
	afx_msg void OnContainerOptions();
	afx_msg void OnContainerAmbientProperties();
	afx_msg void OnContainerInfo();
	afx_msg void OnEditDeleteAll();
	afx_msg void OnUpdateEditDeleteAll(CCmdUI* pCmdUI);
	afx_msg void OnContainerTabOrder();
	afx_msg void OnToolsMacros();
	afx_msg void OnRunMacro();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

   DECLARE_OLETYPELIB( CTestContainer98Doc )

   BEGIN_CONNECTION_PART( CTestContainer98Doc, TC98CP )
	  CONNECTION_IID( __uuidof( ITestContainer98Events ) )
   END_CONNECTION_PART( TC98CP )

   DECLARE_CONNECTION_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CTestContainer98Doc)
	afx_msg LPDISPATCH GetPrimarySelection();
	afx_msg void SetPrimarySelection(LPDISPATCH newValue);
	afx_msg LPDISPATCH FindControl(LPCTSTR pszName);
	afx_msg void Log(LPCTSTR pszMessage);
	afx_msg LPDISPATCH InsertControl(LPCTSTR pszProgID, LPCTSTR pszName);
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
	DECLARE_INTERFACE_MAP()

   friend class CTestContainer98Item;
   virtual BOOL SaveModified();
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTESTCONTAINER98DOC_H__19818508_B837_11D0_8DF1_00C04FB68D60__INCLUDED_)
