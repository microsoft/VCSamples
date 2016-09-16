// view.cpp
//

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

// Implements CDropTargetView which is an override of CView with appropriate
// COleDropTarget support.
//
// CDropTargetView, CObjTreeView, and CInterfaceView all are derived from this class
//

// This class is never used.....but it is interesting

#include "stdafx.h"
#include "OleView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDropTargetView

IMPLEMENT_DYNAMIC(CDropTargetView, CView)

BEGIN_MESSAGE_MAP(CDropTargetView, CView)
	//{{AFX_MSG_MAP(CDropTargetView)
	ON_WM_CREATE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDropTargetView construction/destruction

CDropTargetView::CDropTargetView()
{
}

int CDropTargetView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
#if _MFC_VER > 0x0210
	m_dropTarget.Register( this ) ;
#endif
	return 0;
}

#if _MFC_VER > 0x0210
DROPEFFECT CDropTargetView::OnDragEnter(COleDataObject* pDataObject, DWORD dwKeyState, CPoint point)
{
	return OnDragOver(pDataObject, dwKeyState, point);
}


DROPEFFECT CDropTargetView::OnDragOver(COleDataObject*, DWORD dwKeyState, CPoint)
{
	DROPEFFECT de = DROPEFFECT_NONE;

	// check for force link
	if ((dwKeyState & (MK_CONTROL|MK_SHIFT)) == (MK_CONTROL|MK_SHIFT))
		de = DROPEFFECT_LINK;
	// check for force copy
	else if ((dwKeyState & MK_CONTROL) == MK_CONTROL)
		de = DROPEFFECT_COPY;
	// check for force move
	else if ((dwKeyState & MK_ALT) == MK_ALT)
		de = DROPEFFECT_MOVE;
	// default -- recommended action is move
	else
		de = DROPEFFECT_MOVE;

	return de;
}

void CDropTargetView::OnDragLeave()
{
	CView::OnDragLeave() ;
}

#pragma warning(disable : 4189)
BOOL CDropTargetView::OnDrop(COleDataObject* pDataObject,DROPEFFECT dropEffect, CPoint point)
{
/*
	LPDATAOBJECT    pDO = pDataObject->m_lpDataObject ;

	pDO->AddRef() ;
	IDisplayInterface( theApp.m_pMainWnd->GetSafeHwnd(),
					   pDO,
					   (LPIID)&IID_IDataObject,
					   (LPTSTR)(LPCSTR)"Drag and Drop data object" ) ;
	pDO->Release() ;
*/

	COle2ViewDoc*   pDoc = GetDocument() ;

#if 0
	pDoc->m_clsidCur = CLSID_NULL ;

	HRESULT hr = pDataObject->m_lpDataObject->QueryInterface( IID_IUnknown, (LPVOID*)&pDoc->m_pIUnknown );
	if (FAILED(hr))
	{
		ErrorMessage( _T("QueryInterface( IID_IUnknown ) failed on the data object."), hr ) ;
		pDoc->m_pIUnknown = NULL ;
	}

	pDoc->m_pIUnknown->AddRef() ;

	pDoc->m_fTypeLib = FALSE ;
	((CMainFrame*)theApp.m_pMainWnd)->m_pObjListView->m_lb.SetCurSel( -1 ) ;
	pDoc->m_szObjectCur = "Drag and Drop data object" ;
	pDoc->UpdateAllViews( NULL, UPD_NOOBJECTVIEW | UPD_NORELOAD ) ;

#endif

	return CView::OnDrop( pDataObject, dropEffect, point ) ;
}
#pragma warning(default : 4189)
#endif
#ifdef _DEBUG

COle2ViewDoc* CDropTargetView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COle2ViewDoc)));
	return (COle2ViewDoc*) m_pDocument;
}

#endif //_DEBUG
