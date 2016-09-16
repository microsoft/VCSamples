// File: MFileWnd.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_METAFILEWND_H__E1CB782F_3AB4_11D1_8E47_00C04FB68D60__INCLUDED_)
#define AFX_METAFILEWND_H__E1CB782F_3AB4_11D1_8E47_00C04FB68D60__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MetaFileWnd.H : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMetaFileWnd window

class CMetaFileWnd : public CFrameWnd
{
// Construction
public:
	CMetaFileWnd();

// Attributes
public:

// Operations
public:
   void SetObject( IUnknown* pObject );

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMetaFileWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMetaFileWnd();

protected:
   HMETAFILE m_hMetaFile;
   IOleObjectPtr m_pOleObject;
   IViewObjectPtr m_pViewObject;
   CSize m_size;

	// Generated message map functions
protected:
	//{{AFX_MSG(CMetaFileWnd)
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_METAFILEWND_H__E1CB782F_3AB4_11D1_8E47_00C04FB68D60__INCLUDED_)
