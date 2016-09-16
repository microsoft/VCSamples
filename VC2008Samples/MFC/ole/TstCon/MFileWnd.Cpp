// MetaFileWnd.Cpp : implementation file
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
// CMetaFileWnd

CMetaFileWnd::CMetaFileWnd() :
   m_hMetaFile( NULL )
{
}

CMetaFileWnd::~CMetaFileWnd()
{
   if( m_hMetaFile != NULL )
   {
	  DeleteMetaFile( m_hMetaFile );
   }
}


BEGIN_MESSAGE_MAP(CMetaFileWnd, CFrameWnd)
	//{{AFX_MSG_MAP(CMetaFileWnd)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


STDAPI_(HDC) OleStdCreateDC(DVTARGETDEVICE FAR* ptd)
{
	HDC hdc=NULL;
	LPDEVNAMES lpDevNames;
	LPDEVMODE lpDevMode;
	LPTSTR lpszDriverName;
	LPTSTR lpszDeviceName;
	LPTSTR lpszPortName;

	if (ptd == NULL) {
		hdc = CreateDC(_T("DISPLAY"), NULL, NULL, NULL);
		goto errReturn;
	}

	lpDevNames = (LPDEVNAMES) ptd; // offset for size field

	if (ptd->tdExtDevmodeOffset == 0) {
		lpDevMode = NULL;
	}else{
		lpDevMode  = (LPDEVMODE) ((LPTSTR)ptd + ptd->tdExtDevmodeOffset);
	}

	lpszDriverName = (LPTSTR) lpDevNames + ptd->tdDriverNameOffset;
	lpszDeviceName = (LPTSTR) lpDevNames + ptd->tdDeviceNameOffset;
	lpszPortName   = (LPTSTR) lpDevNames + ptd->tdPortNameOffset;

	hdc = CreateDC(lpszDriverName, lpszDeviceName, lpszPortName, lpDevMode);

errReturn:
	return hdc;
}


void CMetaFileWnd::SetObject( IUnknown* pObject )
{
   SIZE size;
   RECTL rect;
   BOOL tSuccess;
   CMetaFileDC dc;
   HDC hAttribDC;

   _ASSERTE( pObject != NULL );

   m_pOleObject = pObject;
   m_pViewObject = pObject;

   m_pOleObject->GetExtent( DVASPECT_CONTENT, &size );

   tSuccess = dc.Create();
   if( !tSuccess )
   {
	  return;
   }

   hAttribDC = ::OleStdCreateDC( NULL );
   dc.SetAttribDC( hAttribDC );

   m_size.cx = size.cx;
   m_size.cy = size.cy;
   dc.HIMETRICtoDP( &m_size );

   rect.left = 0;
   rect.top = 0;
   rect.right = m_size.cx;
   rect.bottom = m_size.cy;

   m_pViewObject->Draw( DVASPECT_CONTENT, -1, NULL, NULL, hAttribDC, dc.m_hDC,
	  &rect, &rect, NULL, 0 );

   dc.SetAttribDC( NULL );
   DeleteDC( hAttribDC );

   m_hMetaFile = dc.Close();
   if( m_hMetaFile == NULL )
   {
	  return;
   }

   InvalidateRect( NULL );
}

/////////////////////////////////////////////////////////////////////////////
// CMetaFileWnd message handlers

void CMetaFileWnd::OnPaint()
{
   CRect rect;
	CPaintDC dc( this ); // device context for painting

   if( m_hMetaFile != NULL )
   {
	  GetClientRect( &rect );
	  dc.SetMapMode( MM_ANISOTROPIC );
	  dc.SetWindowOrg( 0, 0 );
	  dc.SetWindowExt( m_size );
	  dc.SetViewportOrg( 0, 0 );
	  dc.SetViewportExt( rect.right, rect.bottom );
	  dc.PlayMetaFile( m_hMetaFile );
   }
}
