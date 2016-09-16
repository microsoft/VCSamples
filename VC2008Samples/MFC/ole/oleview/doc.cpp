// doc.cpp : implementation of the COle2ViewDoc class
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#include "stdafx.h"
#include "OleView.h"

#include "doc.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COle2ViewDoc

IMPLEMENT_DYNCREATE(COle2ViewDoc, CDocument)

BEGIN_MESSAGE_MAP(COle2ViewDoc, CDocument)
	//{{AFX_MSG_MAP(COle2ViewDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COle2ViewDoc construction/destruction

COle2ViewDoc::COle2ViewDoc()
{
	m_clsidCur = GUID_NULL ;
	m_szObjectCur = "" ;
	m_fTypeLib = FALSE ;

	CString szSection ;
	CString szKey ;
	#pragma warning(suppress: 6031)
	szSection.LoadString( IDS_INI_CONFIG ) ;
	ASSERT(szSection != "");

	#pragma warning(suppress: 6031)
	szKey.LoadString( IDS_INI_CLSCTX ) ;
	ASSERT(szKey != "");
	m_dwClsCtx = (DWORD)theApp.GetProfileInt( szSection, szKey, CLSCTX_LOCAL_SERVER | CLSCTX_INPROC_SERVER ) ;

}

COle2ViewDoc::~COle2ViewDoc()
{

	CString szSection ;
	CString szKey ;
	#pragma warning(suppress: 6031)
	szSection.LoadString( IDS_INI_CONFIG ) ;
	ASSERT(szSection != "");

	#pragma warning(suppress: 6031)
	szKey.LoadString( IDS_INI_CLSCTX ) ;
	ASSERT(szKey != "");
	theApp.WriteProfileInt( szSection, szKey, (WORD)m_dwClsCtx ) ;

}

BOOL COle2ViewDoc::OnNewDocument()
{
//    if (!CDocument::OnNewDocument())
//        return FALSE;
	return TRUE;
}

void COle2ViewDoc::OnCloseDocument()
{
	CDocument::OnCloseDocument();
}


/////////////////////////////////////////////////////////////////////////////
// COle2ViewDoc diagnostics

#ifdef _DEBUG
void COle2ViewDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COle2ViewDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COle2ViewDoc commands
