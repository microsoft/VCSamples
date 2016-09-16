// File: Script.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_SCRIPT_H__5783EE7E_0DC5_11D1_8E2F_00C04FB68D60__INCLUDED_)
#define AFX_SCRIPT_H__5783EE7E_0DC5_11D1_8E2F_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000
// Script.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CScript command target

class CScriptManager;

class CScript :
   public CCmdTarget
{
	DECLARE_DYNAMIC( CScript )

// Attributes
public:
   CScript( CScriptManager* pManager );
   ~CScript();

// Operations
public:
   HRESULT AddNamedItem( LPCTSTR pszItemName );
   BOOL FindMacro( LPCTSTR pszMacroName );
   POSITION GetFirstMacroPosition();
   CString GetName();
   CString GetNextMacroName( POSITION& posMacro );
   HRESULT LoadScript( LPCTSTR pszFileName, LPCTSTR pszScriptName );
   HRESULT RunMacro( LPCTSTR pszMacroName );
   void Unload();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScript)
	//}}AFX_VIRTUAL

// Implementation
protected:
   CScriptManager* m_pManager;
   IDispatchPtr m_pDispatch;
   IActiveScriptPtr m_pActiveScript;
   IActiveScriptParsePtr m_pActiveScriptParse;
   CString m_strScriptText;
   CString m_strScriptName;
   CMap< CString, LPCTSTR, DISPID, DISPID > m_mapMacros;

	// Generated message map functions
	//{{AFX_MSG(CScript)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()

   BEGIN_INTERFACE_PART( ActiveScriptSite, IActiveScriptSite )
	  STDMETHOD( GetDocVersionString )( BSTR* pbstrVersion );
	  STDMETHOD( GetItemInfo )( LPCOLESTR pszName, DWORD dwReturnMask,
		 IUnknown** ppItem, ITypeInfo** ppTypeInfo );
	  STDMETHOD( GetLCID )( LCID* plcid );
	  STDMETHOD( OnEnterScript )();
	  STDMETHOD( OnLeaveScript )();
	  STDMETHOD( OnScriptError )( IActiveScriptError* pError );
	  STDMETHOD( OnScriptTerminate )( const VARIANT* pvarResult,
		 const EXCEPINFO* pExcepInfo );
	  STDMETHOD( OnStateChange )( SCRIPTSTATE eState );
   END_INTERFACE_PART( ActiveScriptSite )

   BEGIN_INTERFACE_PART( ActiveScriptSiteWindow, IActiveScriptSiteWindow )
	  STDMETHOD( EnableModeless )( BOOL tEnable );
	  STDMETHOD( GetWindow )( HWND* phWindow );
   END_INTERFACE_PART( ActiveScriptSiteWindow )

   DECLARE_INTERFACE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCRIPT_H__5783EE7E_0DC5_11D1_8E2F_00C04FB68D60__INCLUDED_)
