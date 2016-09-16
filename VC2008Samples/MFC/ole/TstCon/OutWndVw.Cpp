// OutputWindowView.Cpp : implementation file
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#include "StdAfx.H"
#include "TestCon.H"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputWindowView

IMPLEMENT_DYNCREATE( COutputWindowView, CEditView )

COutputWindowView::COutputWindowView()
{
}

COutputWindowView::~COutputWindowView()
{
}


BEGIN_MESSAGE_MAP(COutputWindowView, CEditView)
	//{{AFX_MSG_MAP(COutputWindowView)
	ON_WM_CREATE()
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP
   ON_COMMAND( ID_OUTPUTLOGEDIT_CLEAR, OnClear )
   ON_COMMAND( ID_OUTPUTLOGEDIT_COPY, OnCopy )
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputWindowView drawing

void COutputWindowView::OnDraw( CDC* /* pDC */ )
{
}

/////////////////////////////////////////////////////////////////////////////
// COutputWindowView diagnostics

#ifdef _DEBUG
void COutputWindowView::AssertValid() const
{
	CEditView::AssertValid();
}

void COutputWindowView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COutputWindowView message handlers

int COutputWindowView::OnCreate( LPCREATESTRUCT pCreateStruct )
{
	if( CEditView::OnCreate( pCreateStruct ) == -1 )
   {
	  return( -1 );
   }

   m_font.CreatePointFont( 100, _T( "Courier" ) );
   SetFont( &m_font );

   SendMessage( EM_SETREADONLY, TRUE, 0 );

	return( 0 );
}

void COutputWindowView::OnContextMenu( CWnd* pWnd, CPoint point )
{
   CMenu menu;
   CMenu* pPopupMenu;
   int iStart;
   int iEnd;

   if( pWnd->m_hWnd != m_hWnd )
   {
	  return;
   }

   menu.LoadMenu( IDR_OUTPUTLOGEDIT_CONTEXT );
   pPopupMenu = menu.GetSubMenu( 0 );
   GetEditCtrl().GetSel( iStart, iEnd );
   if( iEnd == iStart )
   {
	  pPopupMenu->EnableMenuItem( ID_OUTPUTLOGEDIT_COPY, MF_GRAYED );
   }
   pPopupMenu->TrackPopupMenu( TPM_LEFTALIGN|TPM_RIGHTBUTTON, point.x, point.y,
	  this, NULL );
   menu.DestroyMenu();
}

void COutputWindowView::OnClear()
{
   DeleteContents();
}

void COutputWindowView::OnCopy()
{
   GetEditCtrl().Copy();
}
