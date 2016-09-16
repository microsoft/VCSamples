// dispatch.cpp : implementation file
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
#include "iviewers.h"
#include "iview.h"
#include "iviewer.h"
#include "dispatch.h"
#include "util.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDispatchViewer

IMPLEMENT_DYNCREATE(CDispatchViewer, CInterfaceViewer)

CDispatchViewer::CDispatchViewer()
{
}

CDispatchViewer::~CDispatchViewer()
{
}

BEGIN_MESSAGE_MAP(CDispatchViewer, CInterfaceViewer)
//  //{{AFX_MSG_MAP(CDispatchViewer)
//      // NOTE - the ClassWizard will add and remove mapping macros here.
//  //}}AFX_MSG_MAP
END_MESSAGE_MAP()

IMPLEMENT_OLECREATE(CDispatchViewer, "Ole2View.IDispatch.1", 0xd2af7a60, 0x4c42, 0x11ce, 0xb2, 0x7d, 0x00, 0xaa, 0x00, 0x1f, 0x73, 0xc1) ;

/////////////////////////////////////////////////////////////////////////////
// CDispatchViewer View imp.

//

HRESULT CDispatchViewer::OnView(HWND hwndParent, REFIID riid, LPUNKNOWN punk)
{
	SCODE sc = NOERROR ;

	ASSERT(hwndParent);
	ENSURE(punk);

	if (riid != IID_IDispatch)
	{
		AfxMessageBox( _T("IDispatch interface viewer only supports IID_IDispatch") ) ;
		return E_INVALIDARG ;
	}

	CDispatchDlg dlg(CWnd::FromHandle(hwndParent)) ;

	sc = punk->QueryInterface( riid, (void**)&dlg.m_pdisp ) ;
	if (FAILED(sc))
	{
		ErrorMessage( "Object does not support IDispatch.", sc ) ;
		return E_UNEXPECTED ;
	}

	dlg.DoModal() ;

	dlg.m_pdisp->Release() ;

	return sc ;
}
/////////////////////////////////////////////////////////////////////////////
// CDispatchDlg dialog


CDispatchDlg::CDispatchDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDispatchDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDispatchDlg)
	m_uiTypeInfoCount = 0;
	//}}AFX_DATA_INIT
	m_pdisp = NULL ;
}


void CDispatchDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDispatchDlg)
	DDX_Control(pDX, IDC_VIEWTYPEINFO, m_btnViewTypeInfo);
	DDX_Text(pDX, IDC_TYPEINFOCOUNT, m_uiTypeInfoCount);
	//}}AFX_DATA_MAP

	m_btnViewTypeInfo.EnableWindow(m_uiTypeInfoCount != 0) ;
}


BEGIN_MESSAGE_MAP(CDispatchDlg, CDialog)
	//{{AFX_MSG_MAP(CDispatchDlg)
	ON_BN_CLICKED(IDC_VIEWTYPEINFO, OnViewTypeInfo)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CDispatchDlg message handlers

void CDispatchDlg::OnViewTypeInfo()
{
	// TODO:
	// if (m_uiTypeInfoCount > 0) // should never be > 1
	//    Call IDispatch::GetTypeInfo
	//    Pop up ITypeInfo Viewer in the resulting ITypeInfo*
	//    (note that there is currently no ITypeInfo viewer, but
	//     the ITypeLib viewer could easily be modified/extended
	//     to browse a specific ITypeInfo).

}

BOOL CDispatchDlg::OnInitDialog()
{
	ENSURE(m_pdisp);

	HRESULT hr ;
	hr = m_pdisp->GetTypeInfoCount( &m_uiTypeInfoCount ) ;
	if (FAILED(hr))
	{
		m_uiTypeInfoCount = 0 ;
		ErrorMessage( "IDispatch::GetTypeInfoCount failed.", hr ) ;
	}

	CDialog::OnInitDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}
