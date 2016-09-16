// obj_vw.cpp
//
// Implementation of the CObjTreeView class
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
#include "shadow.h"
#include "obj_vw.h"
#include <winnls.h>

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CObjectData

IMPLEMENT_DYNCREATE(CObjectData, CObject)

CObjectData::CObjectData()
{
	m_nType = typeUnknown ;
	m_pcf = NULL ;
	m_punk = NULL ;
	m_uiBitmap = NULL ;

}

CObjectData::~CObjectData()
{
}

BOOL CObjectData::Release()
{
	if (m_pcf)
		m_pcf->Release() ;

	if (m_punk)
		m_punk->Release() ;

	m_pcf = NULL ;
	m_punk = NULL ;

	CoFreeUnusedLibraries();

	return TRUE ;
}

HRESULT CObjectData::CreateInstance( DWORD clsctx )
{
	Release() ;

	HRESULT hr = NOERROR ;
	CString strError ;
	IUnknown* punk = NULL ;
	TRY
	{
		hr = CoGetClassObject( m_clsid, clsctx, NULL, IID_IUnknown, (void**)&punk ) ;
		if (FAILED(hr))
		{
			strError = "CoGetClassObject failed." ;
			AfxThrowOleException(hr) ;
		}
		ENSURE(punk) ;

		hr = punk->QueryInterface( IID_IClassFactory, (void**)&m_pcf ) ;
		if (FAILED(hr))
		{
			strError = "QueryInterface on class factory for IClassFactory failed." ;
			AfxThrowOleException(hr) ;
		}
		ASSERT(m_pcf) ;

		punk->Release() ;
		punk = NULL ;

		hr = m_pcf->CreateInstance( NULL, IID_IUnknown, (void**)&m_punk ) ;
		if (FAILED(hr))
		{
			strError = "IClassFactory::CreateInstance failed." ;
			AfxThrowOleException(hr) ;
		}

		m_pcf->Release() ;
		m_pcf = NULL ;
	}
	CATCH(COleException, pException)
	{
		if (punk)
			punk->Release() ;
		Release() ;

		ErrorMessage( strError, hr ) ;
	}
	END_CATCH ;

	return hr ;
}

/////////////////////////////////////////////////////////////////////////////
// CObjTreeView

IMPLEMENT_DYNCREATE(CObjTreeView, CTreeView)

BEGIN_MESSAGE_MAP(CObjTreeView, CTreeView)
	//{{AFX_MSG_MAP(CObjTreeView)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_OBJECT_DELETE, OnObjectDelete)
	ON_COMMAND(ID_OBJECT_VERIFY, OnObjectVerify)
	//}}AFX_MSG_MAP
	ON_NOTIFY_REFLECT(TVN_SELCHANGED,OnTreeSelchanged)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDING, OnTreeItemExpanding)
	ON_NOTIFY_REFLECT(TVN_ITEMEXPANDED,OnTreeItemExpanded)
	ON_NOTIFY_REFLECT(TVN_DELETEITEM,OnTreeDeleteItem)
	ON_MESSAGE( WM_COMMANDHELP, OnCommandHelp)
	ON_NOTIFY_REFLECT(NM_RETURN, OnTreeReturn)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CObjTreeView construction/destruction

CObjTreeView::CObjTreeView()
{
	m_hObjects = NULL ;
	m_hTypeLibs= NULL ;
	m_hInterfaces = NULL ;

	m_hInsertable = NULL ;
	m_hControls= NULL ;
	m_hInternal= NULL ;
#ifdef SHOW_CONTAINERS
	m_hContainers= NULL ;
#endif
	m_hOLE1= NULL ;
	m_hUnclassified= NULL ;
}

CObjTreeView::~CObjTreeView()
{
}

LRESULT CObjTreeView::OnCommandHelp(WPARAM, LPARAM lParam)
{
	theApp.WinHelp( lParam, HELP_CONTEXT ) ;
	return TRUE ;
}

BOOL CObjTreeView::PreCreateWindow(CREATESTRUCT& cs)
{
	if (!CTreeView::PreCreateWindow(cs))
		return FALSE;

	cs.style = WS_CHILD | WS_VISIBLE | WS_BORDER | TVS_LINESATROOT |
		TVS_HASLINES | TVS_HASBUTTONS | TVS_DISABLEDRAGDROP;
	return TRUE;
}


int CObjTreeView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CTreeView::OnCreate(lpCreateStruct) == -1)
		return -1;
#ifdef _MARCOC_OLD
	RECT rect ;
	rect.top = lpCreateStruct->y ;
	rect.left = lpCreateStruct->x ;
	rect.bottom = lpCreateStruct->cy ;
	rect.right = lpCreateStruct->cx ;

	if (!GetTreeCtrl().Create( WS_CHILD | WS_VISIBLE |
								WS_BORDER |
								TVS_LINESATROOT |
								TVS_HASLINES |
//                                TVS_SHOWSELALWAYS |
								TVS_HASBUTTONS |
								TVS_DISABLEDRAGDROP,
								rect, this, ID_TREEVIEW ))
	{
		TRACE( _T("Tree control failed to create!") ) ;
		return -1 ;
	}
#endif
	return 0;
}

void CObjTreeView::OnInitialUpdate()
{
	GetTreeCtrl().SetImageList( &theApp.m_images, TVSIL_NORMAL ) ;

	TV_INSERTSTRUCT tvis ;
	tvis.hParent = TVI_ROOT ;
	tvis.hInsertAfter = TVI_LAST ;
	tvis.item.mask = TVIF_TEXT | TVIF_PARAM | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_CHILDREN ;
	tvis.item.lParam = 0 ;
	tvis.item.cChildren = 1 ;

	tvis.item.pszText = "Objects" ;
	tvis.item.iImage = BMINDEX(IDB_OBJECTFOLDER) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_OBJECTFOLDER) ;
	m_hObjects = GetTreeCtrl().InsertItem( &tvis ) ;

	tvis.hParent = m_hObjects ;
	tvis.item.pszText = "OLE Document Objects" ;
	tvis.item.iImage = BMINDEX(IDB_OBJECT_INSERTABLE) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_OBJECT_INSERTABLE) ;
	m_hInsertable = GetTreeCtrl().InsertItem( &tvis ) ;

	tvis.item.pszText = "OLE Controls" ;
	tvis.item.iImage = BMINDEX(IDB_OBJECT_CONTROL) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_OBJECT_CONTROL) ;
	m_hControls = GetTreeCtrl().InsertItem( &tvis ) ;

	tvis.item.pszText = "Unclassified Objects" ;
	tvis.item.iImage = BMINDEX(IDB_OBJECT) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_OBJECT) ;
	m_hUnclassified = GetTreeCtrl().InsertItem( &tvis ) ;

#ifdef SHOW_CONTAINERS
	tvis.item.pszText = "Containers" ;
	tvis.item.iImage = BMINDEX(IDB_CONTAINER) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_CONTAINER) ;
	m_hContainers = GetTreeCtrl().InsertItem( &tvis ) ;
#endif

	tvis.item.pszText = "OLE 1.0 Objects" ;
	tvis.item.iImage = BMINDEX(IDB_OBJECT_INSERTABLE10) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_OBJECT_INSERTABLE10) ;
	m_hOLE1 = GetTreeCtrl().InsertItem( &tvis ) ;

	tvis.item.pszText = "Internal OLE Objects" ;
	tvis.item.iImage = BMINDEX(IDB_QUESTION) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_QUESTION) ;
	m_hInternal = GetTreeCtrl().InsertItem( &tvis ) ;

	GetTreeCtrl().Expand( m_hObjects, TVE_EXPAND ) ;

	tvis.hParent = TVI_ROOT ;
	tvis.item.pszText = "Type Libraries" ;
	tvis.item.iImage = BMINDEX(IDB_TYPELIBFOLDER) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_TYPELIBFOLDER) ;
	m_hTypeLibs = GetTreeCtrl().InsertItem( &tvis ) ;

	tvis.item.pszText = "Interfaces" ;
	tvis.item.iImage = BMINDEX(IDB_IFACEFOLDER) ;
	tvis.item.iSelectedImage = BMINDEX(IDB_IFACEFOLDER) ;
	m_hInterfaces = GetTreeCtrl().InsertItem( &tvis ) ;
}

void CObjTreeView::OnDestroy()
{
	DeleteTreeContents() ;
	CTreeView::OnDestroy();
}


void CObjTreeView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	UINT hitflags ;
	HTREEITEM hitem ;

	hitem = GetTreeCtrl().HitTest( point, &hitflags ) ;
	if (hitflags & (TVHT_ONITEM | TVHT_ONITEMBUTTON))
	{
		NM_TREEVIEW nm ;
		nm.itemNew.mask = TVIF_PARAM  ;
		nm.itemNew.hItem = hitem ;
		if (GetTreeCtrl().GetItem( &nm.itemNew ))
		{
			CObjectData* pObjectData = (CObjectData*)nm.itemNew.lParam;
			CallInterfaceViewer(pObjectData, nm.itemNew.hItem);
		}
	}
	CTreeView::OnLButtonDblClk(nFlags, point);
}


/////////////////////////////////////////////////////////////////////////////
// CObjTreeView drawing

BOOL HasServer32( HKEY hkCLSID )
{
	HKEY hkTemp ;
	if ((RegOpenKey( hkCLSID, _T("InprocServer32"), &hkTemp ) == ERROR_SUCCESS) ||
		(RegOpenKey( hkCLSID, _T("InprocHandler32"), &hkTemp ) == ERROR_SUCCESS) ||
		(RegOpenKey( hkCLSID, _T("LocalServer32"), &hkTemp ) == ERROR_SUCCESS))
	{
		RegCloseKey( hkTemp ) ;
		return TRUE ;
	}

	return FALSE ;
}

BOOL HasServer16( HKEY hkCLSID )
{
	HKEY hkTemp ;
	if ((RegOpenKey( hkCLSID, _T("InprocServer"), &hkTemp ) == ERROR_SUCCESS) ||
		(RegOpenKey( hkCLSID, _T("InprocHandler"), &hkTemp ) == ERROR_SUCCESS) ||
		(RegOpenKey( hkCLSID, _T("LocalServer"), &hkTemp ) == ERROR_SUCCESS))
	{
		RegCloseKey( hkTemp ) ;
		return TRUE ;
	}

	return FALSE ;
}

void CObjTreeView::DeleteTreeItems( HTREEITEM htree )
{
	HTREEITEM       hItem, hItemNext ;

	hItem = GetTreeCtrl().GetChildItem( htree ) ;
	while( hItem )
	{
		hItemNext = GetTreeCtrl().GetNextSiblingItem( hItem ) ;
		GetTreeCtrl().DeleteItem( hItem ) ;
		hItem = hItemNext ;
	}
}

void CObjTreeView::DeleteTreeContents()
{
	// Delete current contents
	//
	if ((int)GetTreeCtrl().GetCount() > 0)
	{
		DeleteTreeItems( m_hInsertable ) ;
		DeleteTreeItems( m_hControls ) ;
		DeleteTreeItems( m_hInternal ) ;
#ifdef SHOW_CONTAINERS
		DeleteTreeItems( m_hContainers ) ;
#endif
		DeleteTreeItems( m_hOLE1 ) ;
		DeleteTreeItems( m_hUnclassified ) ;

		DeleteTreeItems( m_hTypeLibs ) ;
		DeleteTreeItems( m_hInterfaces ) ;
	}
}

void CObjTreeView::OnDraw( CDC* /*pdc */ )
{
}

void CObjTreeView::OnUpdate( CView* pSender, LPARAM lHint, CObject* pHint )
{
	pSender; pHint ;
	if (lHint & UPD_NOOBJECTVIEW)
		return ;

	BeginWaitCursor() ;
	GetTreeCtrl().SetRedraw( FALSE ) ;
	GetTreeCtrl().SelectItem( NULL ) ;

	if ((int)GetTreeCtrl().GetCount() > 0)
	{
		BOOL fExpanded = FALSE ;
		TV_ITEM tvi ;
		tvi.mask = TVIF_STATE ;

		tvi.hItem = m_hInsertable ;
		if (GetTreeCtrl().GetItem( &tvi ))
		{
			fExpanded = (tvi.state & TVIS_EXPANDED) ;
			GetTreeCtrl().Expand( tvi.hItem, TVE_COLLAPSE ) ;
			DeleteTreeItems( tvi.hItem ) ;
			tvi.state &= ~TVIS_EXPANDEDONCE ;
			GetTreeCtrl().SetItem( &tvi ) ;
			if (fExpanded)
				GetTreeCtrl().Expand( tvi.hItem, TVE_EXPAND ) ;
		}

		tvi.hItem = m_hControls ;
		if (GetTreeCtrl().GetItem( &tvi ))
		{
			fExpanded = (tvi.state & TVIS_EXPANDED) ;
			GetTreeCtrl().Expand( tvi.hItem, TVE_COLLAPSE ) ;
			DeleteTreeItems( tvi.hItem ) ;
			tvi.state &= ~TVIS_EXPANDEDONCE ;
			GetTreeCtrl().SetItem( &tvi ) ;
			if (fExpanded)
				GetTreeCtrl().Expand( tvi.hItem, TVE_EXPAND ) ;
		}

		tvi.hItem = m_hInternal ;
		if (GetTreeCtrl().GetItem( &tvi ))
		{
			fExpanded = (tvi.state & TVIS_EXPANDED) ;
			GetTreeCtrl().Expand( tvi.hItem, TVE_COLLAPSE ) ;
			DeleteTreeItems( tvi.hItem ) ;
			tvi.state &= ~TVIS_EXPANDEDONCE ;
			GetTreeCtrl().SetItem( &tvi ) ;
			if (fExpanded)
				GetTreeCtrl().Expand( tvi.hItem, TVE_EXPAND ) ;
		}

		tvi.hItem = m_hOLE1 ;
		if (GetTreeCtrl().GetItem( &tvi ))
		{
			fExpanded = (tvi.state & TVIS_EXPANDED) ;
			GetTreeCtrl().Expand( tvi.hItem, TVE_COLLAPSE ) ;
			DeleteTreeItems( tvi.hItem ) ;
			tvi.state &= ~TVIS_EXPANDEDONCE ;
			GetTreeCtrl().SetItem( &tvi ) ;
			if (fExpanded)
				GetTreeCtrl().Expand( tvi.hItem, TVE_EXPAND ) ;
		}

		tvi.hItem = m_hUnclassified ;
		if (GetTreeCtrl().GetItem( &tvi ))
		{
			fExpanded = (tvi.state & TVIS_EXPANDED) ;
			GetTreeCtrl().Expand( tvi.hItem, TVE_COLLAPSE ) ;
			DeleteTreeItems( tvi.hItem ) ;
			tvi.state &= ~TVIS_EXPANDEDONCE ;
			GetTreeCtrl().SetItem( &tvi ) ;
			if (fExpanded)
				GetTreeCtrl().Expand( tvi.hItem, TVE_EXPAND ) ;
		}

		tvi.hItem = m_hTypeLibs ;
		if (GetTreeCtrl().GetItem( &tvi ))
		{
			fExpanded = (tvi.state & TVIS_EXPANDED) ;
			GetTreeCtrl().Expand( tvi.hItem, TVE_COLLAPSE ) ;
			DeleteTreeItems( tvi.hItem ) ;
			tvi.state &= ~TVIS_EXPANDEDONCE ;
			GetTreeCtrl().SetItem( &tvi ) ;
			if (fExpanded)
				GetTreeCtrl().Expand( tvi.hItem, TVE_EXPAND ) ;
		}

		tvi.hItem = m_hInterfaces ;
		if (GetTreeCtrl().GetItem( &tvi ))
		{
			fExpanded = (tvi.state & TVIS_EXPANDED) ;
			GetTreeCtrl().Expand( tvi.hItem, TVE_COLLAPSE ) ;
			DeleteTreeItems( tvi.hItem ) ;
			tvi.state &= ~TVIS_EXPANDEDONCE ;
			GetTreeCtrl().SetItem( &tvi ) ;
			if (fExpanded)
				GetTreeCtrl().Expand( tvi.hItem, TVE_EXPAND ) ;
		}
	}

	GetTreeCtrl().SetRedraw( TRUE ) ;
	EndWaitCursor() ;
}


/////////////////////////////////////////////////////////////////////////////
// CObjTreeView diagnostics

#ifdef _DEBUG
void CObjTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CObjTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CObjTreeView message handlers

void CObjTreeView::OnTreeSelchanged(NMHDR* pNMHDR, LRESULT* pResult)
{
	COle2ViewDoc*   pDoc = GetDocument() ;
	NM_TREEVIEW* pnmtv = (NM_TREEVIEW*)pNMHDR;
	CObjectData*    lpOD ;

	lpOD = (CObjectData*)pnmtv->itemNew.lParam ;

	// special case typelibs because there may be multiple entries (versions)
	// for a given TYPELIBID
	//
	if (lpOD && (!IsEqualCLSID( lpOD->m_clsid, pDoc->m_clsidCur ) || pDoc->m_fTypeLib))
	{
		pDoc->m_fTypeLib = (lpOD->m_uiBitmap == BMINDEX(IDB_AUTOMATION)) ;
		pDoc->m_fInterface = (lpOD->m_uiBitmap == BMINDEX(IDB_INTERFACE)) ;
		pDoc->m_clsidCur = lpOD->m_clsid ;

		TV_ITEM tvi ;
		tvi.hItem = pnmtv->itemNew.hItem ;
		tvi.mask = TVIF_TEXT ;
		tvi.cchTextMax = 256 ;
		tvi.pszText = new TCHAR[256] ;
		if (GetTreeCtrl().GetItem( &tvi ))
		{
			pDoc->m_szObjectCur = tvi.pszText ;
		}
		else
			pDoc->m_szObjectCur = "ERROR" ;
		delete tvi.pszText ;
	}
	else
	{
		pDoc->m_fTypeLib = FALSE ;
		pDoc->m_fInterface = FALSE ;
		pDoc->m_clsidCur =  GUID_NULL;
		pDoc->m_szObjectCur = "" ;
	}
	pDoc->UpdateAllViews( this, UPD_NOOBJECTVIEW ) ;
	*pResult = 0;
}

void CObjTreeView::OnTreeItemExpanding(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = 0;
	NM_TREEVIEW* pnmtv = (NM_TREEVIEW*)pNMHDR;
	if (pnmtv->action == TVE_EXPAND && pnmtv->itemNew.hItem != m_hObjects)
	{
		if (pnmtv->itemNew.state & TVIS_EXPANDEDONCE)
			return ;

		BeginWaitCursor() ;
		GetTreeCtrl().SetRedraw( FALSE ) ;

		if (pnmtv->itemNew.hItem == m_hInterfaces)
			ExpandInterfaces( pnmtv ) ;
		else if (pnmtv->itemNew.hItem == m_hTypeLibs)
			ExpandTypeLibs( pnmtv ) ;
		else if (pnmtv->itemNew.lParam != NULL)
			ExpandObject( pnmtv ) ;
		else
			ExpandClassification( pnmtv ) ;

		GetTreeCtrl().SetRedraw( TRUE ) ;
		EndWaitCursor() ;
	}
}

void CObjTreeView::ExpandClassification( NM_TREEVIEW* pnmtv )
{
	HKEY    hkCLSID ;

	if (RegOpenKey( HKEY_CLASSES_ROOT, _T("CLSID"), &hkCLSID) == ERROR_SUCCESS)
	{
		CObjectData* lpOD ;
		LONG     cb ;
		TCHAR    szBuf[_MAX_PATH + 1] ;
		TCHAR    szName[64] ;
		TCHAR    szCLSID[64] ;
		DWORD   dwIndex ;

		for ( dwIndex = 0 ;
			  RegEnumKey( hkCLSID, dwIndex, szCLSID, sizeof(szCLSID)) == ERROR_SUCCESS ;
			  ++dwIndex )
		{
			lpOD = NULL ;
			cb = sizeof(szName);
			if (RegQueryValue( hkCLSID, (LPTSTR)szCLSID, szName, &cb) == ERROR_SUCCESS)
			{
				lpOD = new CObjectData ;
				lpOD->m_nType = CObjectData::typeObject ;
				ASSERT(lpOD) ;
				::CLSIDFromString( CT2OLE(szCLSID), &lpOD->m_clsid);
				lpOD->m_szProgID[0] = '\0' ;

				// Assume it's an object
				lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT) ;


				// Now find out more about it.
				//
				// #1 Look in CLSID\{clsid} for the \Control key
				// #2 Assume it is an 'non-embeddable' OLE 2.0 object
				// #3 If \<progid>\NotInsertable exists we're done
				// #4 if !#2 then if \<progid>\Insertable it's an insertable OLE 2.0 object
				//    and we're done
				// #5 if !#3 see if it's an OLE 1.0 object by checking Ole1Class
				//
				HKEY    hkClass, hkTemp ;

				if (RegOpenKey( hkCLSID, szCLSID, &hkClass ) == ERROR_SUCCESS)
				{
					BOOL    fHasServer32 = HasServer32( hkClass ) ;

					if (fHasServer32)
						lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT32) ;
					else
						lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT) ;

					// First determine if it is a system component
					//
					cb = sizeof(szBuf) ;
					LONG cb2 = sizeof(szBuf) ;
					if (RegQueryValue( hkClass, (LPTSTR)_T("InprocServer32"), szBuf, &cb ) == ERROR_SUCCESS)
					{
					   // RegQueryValue may not return a null terminated string.
					   szBuf[_MAX_PATH] = '\0';
					   if ((0 == _stricmp( szBuf, _T("ole32.dll") )) ||
							(0 == _stricmp( szBuf, _T("oleprx32.dll") )) ||
							(0 == _stricmp( szBuf, _T("ole2pr32.dll") )) ||
							(0 == _stricmp( szBuf, _T("olecnv32.dll") )) ||
							(0 == _stricmp( szBuf, _T("oleaut32.dll") )))
						{
							lpOD->m_uiBitmap = BMINDEX(IDB_QUESTION32) ;
						}
					} // Query InprocServer
					else if (RegQueryValue( hkClass, (LPTSTR)_T("InprocServer"), szBuf, &cb2 ) == ERROR_SUCCESS)
					{
						if ((0 == _stricmp( szBuf, _T("ole2prox.dll") )) ||
							(0 == _stricmp( szBuf, _T("ole2.dll") )) ||
							(0 == _stricmp( szBuf, _T("ole2disp.dll") )))
						{
							lpOD->m_uiBitmap = BMINDEX(IDB_QUESTION) ;
						}
					}

					// If it has "Ole1Class" then it's an OLE 1.0 object
					//
					_stprintf_s( szBuf, _MAX_PATH, _T("CLSID\\%s\\Ole1Class"), (LPTSTR)szCLSID) ;
					if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hkTemp ) == ERROR_SUCCESS)
					{
						// Is it 32 bit or 16 bit?
						if (fHasServer32)
							lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT_INSERTABLE1032) ;   // that succeeded.  This means we're insertable
						else
							lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT_INSERTABLE10) ;   // that succeeded.  This means we're insertable
						RegCloseKey( hkTemp ) ;
						goto lblInsertInList ;
					}
										// We now recognize the "Control" key which indicates it's
					// an OLE Custom Control.
					//
					_stprintf_s( szBuf, _MAX_PATH, _T("CLSID\\%s\\Control"), (LPTSTR)szCLSID) ;
					if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hkTemp ) == ERROR_SUCCESS)
					{
						// Is it 32 bit or 16 bit?
						if (fHasServer32)
							lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT_CONTROL32) ;
						else
							lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT_CONTROL) ;
						RegCloseKey( hkTemp ) ;
						goto lblInsertInList ;
					}

					// If it's not a control, but it's insertable it must be a CD object
					//
					_stprintf_s( szBuf, _MAX_PATH, _T("CLSID\\%s\\Insertable"), (LPTSTR)szCLSID) ;
					if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hkTemp ) == ERROR_SUCCESS)
					{
						// Is it 32 bit or 16 bit?
						if (fHasServer32)
							lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT_INSERTABLE32) ;   // that succeeded.  This means we're insertable
						else
							lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT_INSERTABLE) ;   // that succeeded.  This means we're insertable
						RegCloseKey( hkTemp ) ;
						goto lblInsertInList ;
					}


					cb = sizeof(lpOD->m_szProgID) ;
					if (RegQueryValue( hkClass, (LPTSTR)_T("ProgID"), lpOD->m_szProgID, &cb) == ERROR_SUCCESS)
					{
						HKEY    hkInsertable ;

						// Is it an OLE 1.0 object?
						//
						cb = 64 ;
						if (RegQueryValue( hkClass, (LPTSTR)"Ole1Class", szBuf, &cb ) == ERROR_SUCCESS)
						{
							if (fHasServer32)
								lpOD->m_uiBitmap = BMINDEX( IDB_OBJECT_INSERTABLE1032 ) ;
							else
								lpOD->m_uiBitmap = BMINDEX( IDB_OBJECT_INSERTABLE10 ) ;
							goto lblInsertInList ;
						}

						// Does the object force "NotInsertable"?
						//
						_stprintf_s( szBuf, _MAX_PATH, _T("%s\\NotInsertable"), (LPTSTR)lpOD->m_szProgID ) ;
						if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hkInsertable ) == ERROR_SUCCESS)
						{
							if (fHasServer32)
								lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT32) ;
							else
								lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT) ;

							RegCloseKey( hkInsertable ) ;
							goto lblInsertInList ;
						}

						// Is it insertable?
						//
						_stprintf_s( szBuf, _MAX_PATH, _T("%s\\Insertable"), (LPTSTR)lpOD->m_szProgID ) ;
						if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hkInsertable ) == ERROR_SUCCESS)
						{
							if (fHasServer32)
								lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT_INSERTABLE32) ;   // that succeeded.  This means we're insertable
							else
								lpOD->m_uiBitmap = BMINDEX(IDB_OBJECT_INSERTABLE) ;   // that succeeded.  This means we're insertable
							RegCloseKey( hkInsertable ) ;
							goto lblInsertInList ;
						}

#ifdef SHOW_CONTAINERS
						// Try HKEY_CLASSES_ROOT\szProgID\shell\open to see if it's
						// a container.
						//
						wsprintf( szBuf, _T("%s\\shell\\open"), (LPTSTR)lpOD->m_szProgID ) ;
						if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hkInsertable ) == ERROR_SUCCESS)
						{
							if (fHasServer32)
								lpOD->m_uiBitmap = BMINDEX(IDB_CONTAINER32) ;
							else
								lpOD->m_uiBitmap = BMINDEX(IDB_CONTAINER) ;
							RegCloseKey( hkInsertable ) ;
							goto lblInsertInList ;
						}
#endif
					}
					RegCloseKey( hkClass ) ;

				}  // if RegOpenKey( ... &hkClass )

lblInsertInList:
				HTREEITEM htree = NULL ;
				switch( lpOD->m_uiBitmap )
				{
					case BMINDEX(IDB_QUESTION):
					case BMINDEX(IDB_QUESTION32):
						htree = m_hInternal ;
					break ;

					case BMINDEX(IDB_OBJECT_INSERTABLE10):
					case BMINDEX(IDB_OBJECT_INSERTABLE1032):
						htree = m_hOLE1 ;
					break ;

					case BMINDEX(IDB_OBJECT_INSERTABLE):
					case BMINDEX(IDB_OBJECT_INSERTABLE32):
						htree = m_hInsertable ;
					break ;

#ifdef SHOW_CONTAINERS
					case BMINDEX(IDB_CONTAINER):
					case BMINDEX(IDB_CONTAINER32):
						htree = m_hContainers ;
					break ;
#endif

					case BMINDEX(IDB_OBJECT_CONTROL):
					case BMINDEX(IDB_OBJECT_CONTROL32):
						htree = m_hControls ;
					break ;

					case BMINDEX(IDB_OBJECT):
					case BMINDEX(IDB_OBJECT32):
					default:
						htree = m_hUnclassified ;
					break ;

				}

				if (htree && htree == pnmtv->itemNew.hItem)
				{
					RegOpenKey( hkCLSID, szCLSID, &hkClass ) ;
					cb = sizeof(szBuf) ;
					if (RegQueryValue( hkClass, (LPTSTR)"ToolboxBitmap32", szBuf, &cb ) == ERROR_SUCCESS ||
						RegQueryValue( hkClass, (LPTSTR)"ToolboxBitmap", szBuf, &cb ) == ERROR_SUCCESS)
					{
						TCHAR * nextTok;
						TCHAR * pszBitmapModule = _tcstok_s(szBuf, _T(","), &nextTok);
						TCHAR * pszBitmapId = _tcstok_s(NULL, _T(","), &nextTok);
						HINSTANCE hinstBitmap;
						int nBitmapId;
						if ((pszBitmapModule != NULL) && (pszBitmapId != NULL))
						{
							LPTSTR p ;
							if (*pszBitmapModule == '"')
							{
								_tcscpy_s( pszBitmapModule, _MAX_PATH - (pszBitmapModule - szBuf), pszBitmapModule+1 ) ;
								p = strrchr( pszBitmapModule, '"' ) ;
								if (p) *p = '\0' ;
							}
							nBitmapId = _ttoi(pszBitmapId);
							hinstBitmap = LoadLibraryEx(pszBitmapModule, NULL, LOAD_LIBRARY_AS_DATAFILE);
							if (hinstBitmap && (nBitmapId > 0))
							{
								HBITMAP hbmGlyph = ::LoadBitmap(hinstBitmap, MAKEINTRESOURCE(nBitmapId));
								if (hbmGlyph)
								{
									lpOD->m_uiBitmap = theApp.m_images.Add( CBitmap::FromHandle(hbmGlyph), RGBLTGRAY ) ;
									::DeleteObject(hbmGlyph) ;
								}
								FreeLibrary( hinstBitmap ) ;
							}
						}
					}
					RegCloseKey( hkClass ) ;
					ASSERT(lpOD) ;

					TV_INSERTSTRUCT tvis ;
					tvis.hParent = htree ;
					tvis.hInsertAfter = TVI_SORT ;
					tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE |TVIF_CHILDREN ;
					tvis.item.cChildren = 1 ;
					tvis.item.lParam = (LPARAM)(LPVOID)lpOD ;
					tvis.item.pszText = szName ;
					tvis.item.iImage = tvis.item.iSelectedImage = lpOD->m_uiBitmap ;
					GetTreeCtrl().InsertItem( &tvis ) ;
				}
				else
					delete lpOD ;
			}
		}
		RegCloseKey( hkCLSID ) ;
	}
}

void CObjTreeView::ExpandTypeLibs( NM_TREEVIEW* /* pnmtv */ )
{
	HKEY    hkTypeLib ;
	if (RegOpenKey( HKEY_CLASSES_ROOT, _T("TypeLib"), &hkTypeLib) == ERROR_SUCCESS)
	{
		LONG    cb ;
		TCHAR    szVer[65] ;
		TCHAR    szName[64] ;
		TCHAR    szGUID[64] ;
		TCHAR    szBuf[256] ;
		DWORD   dwIndex, dwIndex2 ;
		HKEY    hkGUID ;

		// Enum \TypeInfo
		for ( dwIndex = 0 ;
			  RegEnumKey( hkTypeLib, dwIndex, szGUID, sizeof(szGUID)) == ERROR_SUCCESS ;
			  ++dwIndex )
		{
			// Gotta open \TypeInfo\szGUID
			if (RegOpenKey( hkTypeLib, szGUID, &hkGUID ) == ERROR_SUCCESS)
			{
				// Enum all at this level (major.minor = name)
				for (dwIndex2 = 0 ;
					RegEnumKey( hkGUID, dwIndex2, szVer, sizeof(szVer)) == ERROR_SUCCESS ;
					++dwIndex2 )
				{
					cb = sizeof(szName);
					if (RegQueryValue( hkGUID, (LPTSTR)szVer, szName, &cb) == ERROR_SUCCESS)
					{
						// RegQueryValue may not return a null terminated string
						szVer[64] = '\0';
						_stprintf_s( szBuf, 256, _T("%s (Ver %s)"), (LPTSTR)szName, (LPTSTR)szVer ) ;

						CObjectData* lpOD = new CObjectData ;
						lpOD->m_nType = CObjectData::typeTypeLib ;
						::CLSIDFromString(CT2OLE(szGUID), &lpOD->m_clsid);
						lpOD->m_szProgID[0] = '\0' ;

						lpOD->m_uiBitmap = BMINDEX(IDB_AUTOMATION) ;
						lpOD->m_wMajorVer = (WORD)atoi( szVer ) ;
						PTSTR p = strrchr( szVer, '.' ) ;
						if (p)
							lpOD->m_wMinorVer = (WORD)atoi( p+1 ) ;
						else
							lpOD->m_wMinorVer = 0 ;

						TV_INSERTSTRUCT tvis ;
						tvis.hParent = m_hTypeLibs ;
						tvis.hInsertAfter = TVI_SORT ;
						tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE;
						tvis.item.iImage = tvis.item.iSelectedImage = lpOD->m_uiBitmap ;
						tvis.item.lParam = (LPARAM)(LPVOID)lpOD ;
						tvis.item.pszText = szBuf ;
						GetTreeCtrl().InsertItem( &tvis ) ;
					}
				}
				RegCloseKey( hkGUID ) ;
			}
		}
		RegCloseKey( hkTypeLib ) ;
	}
}

void CObjTreeView::ExpandObject( NM_TREEVIEW* pnmtv )
{
	COle2ViewDoc*   pDoc = GetDocument() ;
	TV_INSERTSTRUCT tvis ;
	CObjectData* pod = (CObjectData*)pnmtv->itemNew.lParam ;

	if (pod->m_nType == CObjectData::typeObject)
	{
		HRESULT hr = pod->CreateInstance( pDoc->m_dwClsCtx ) ;
		if (FAILED(hr))
			return ;

		tvis.hParent = pnmtv->itemNew.hItem  ;
		tvis.hInsertAfter = TVI_SORT ;
		tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE ;
		tvis.item.iImage = tvis.item.iSelectedImage = BMINDEX(IDB_INTERFACE) ;

		HKEY hk ;
		TCHAR szIID[80] ;
		IID  iid ;
		IUnknown* pfoo = NULL ;
		TCHAR szValue[256] ;
		if (RegOpenKey( HKEY_CLASSES_ROOT, _T("Interface"), &hk) == ERROR_SUCCESS)
		{
			for ( DWORD dwIndex = 0 ;
				  RegEnumKey( hk, dwIndex, szIID, sizeof(szIID)) == ERROR_SUCCESS ;
				  ++dwIndex )
			{
				LONG cb = sizeof(szValue);
				if (RegQueryValue( hk, (LPTSTR)szIID, szValue, &cb) == ERROR_SUCCESS)
				{
					::CLSIDFromString(CT2OLE(szIID), &iid ) ;
					if (SUCCEEDED(pod->m_punk->QueryInterface( iid, (void**)&pfoo )))
					{
						pfoo->Release() ;
						pfoo = NULL ;

						CObjectData* lpOD = new CObjectData ;
						lpOD->m_nType = CObjectData::typeInterface ;
						lpOD->m_clsid = iid ;
						lpOD->m_szProgID[0] = '\0' ;
						lpOD->m_uiBitmap = BMINDEX(IDB_INTERFACE) ;
						lpOD->m_wMajorVer =  lpOD->m_wMajorVer  = 0 ;
						tvis.item.lParam = (LPARAM)(LPVOID)lpOD ;
						tvis.item.pszText = szValue ;
						GetTreeCtrl().InsertItem( &tvis ) ;
					}
				}
			}
			RegCloseKey( hk ) ;
		}
	}
}

void CObjTreeView::ExpandInterfaces( NM_TREEVIEW* pnmtv )
{
	if (pnmtv->itemNew.hItem == m_hInterfaces)
	{
		TV_INSERTSTRUCT tvis ;
		tvis.hParent = pnmtv->itemNew.hItem  ;
		tvis.hInsertAfter = TVI_SORT ;
		tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE ;
		tvis.item.iImage = tvis.item.iSelectedImage = BMINDEX(IDB_INTERFACE) ;

		HKEY hk ;
		TCHAR szTypeLibID[80] ;
		TCHAR szValue[256] ;
		if (RegOpenKey( HKEY_CLASSES_ROOT, _T("Interface"), &hk) == ERROR_SUCCESS)
		{
			for ( DWORD dwIndex = 0 ;
				  RegEnumKey( hk, dwIndex, szTypeLibID, sizeof(szTypeLibID)) == ERROR_SUCCESS ;
				  ++dwIndex )
			{
				LONG cb = sizeof(szValue);
				if (RegQueryValue( hk, (LPTSTR)szTypeLibID, szValue, &cb) == ERROR_SUCCESS)
				{
					CObjectData* lpOD = new CObjectData ;
					lpOD->m_nType = CObjectData::typeStaticInterface ;
					::CLSIDFromString(CT2OLE(szTypeLibID), &lpOD->m_clsid );
					lpOD->m_szProgID[0] = '\0' ;
					lpOD->m_uiBitmap = BMINDEX(IDB_INTERFACE) ;
					lpOD->m_wMajorVer =  lpOD->m_wMajorVer  = 0 ;

					tvis.item.lParam = (LPARAM)(LPVOID)lpOD ;
					tvis.item.pszText = szValue ;
					GetTreeCtrl().InsertItem( &tvis ) ;
				}
			}
			RegCloseKey( hk ) ;
		}
		return ;
	}
}

void CObjTreeView::OnTreeItemExpanded(NMHDR* pNMHDR, LRESULT* pResult)
{
	*pResult = 0;
	NM_TREEVIEW* pnmtv = (NM_TREEVIEW*)pNMHDR;
	if ( pnmtv->itemNew.lParam != NULL &&
		 pnmtv->action == TVE_COLLAPSE)
	{
//        TV_INSERTSTRUCT tvis ;
		CObjectData* pod = (CObjectData*)pnmtv->itemNew.lParam ;

		switch(pod->m_nType)
		{
		case CObjectData::typeObject:
		{
			pod->Release() ;
			GetTreeCtrl().Expand( pnmtv->itemNew.hItem, TVE_COLLAPSERESET ) ;
		}
		break ;
		}
	}
 }

void CObjTreeView::CallInterfaceViewer(CObjectData* pObjectData, HTREEITEM hItem)
{
	if (pObjectData != NULL)
	{
		ASSERT_KINDOF(CObjectData,pObjectData);

		switch(pObjectData->m_nType)
		{
		case CObjectData::typeInterface:
		{
			CObjectData* podParent = NULL ;
			TV_ITEM tviParent ;
			tviParent.hItem = GetTreeCtrl().GetParentItem(hItem);
			ASSERT(tviParent.hItem) ;
			tviParent.mask = TVIF_PARAM ;
			GetTreeCtrl().GetItem( &tviParent ) ;
			if (tviParent.lParam)
			{
				podParent = (CObjectData*)tviParent.lParam ;

				ASSERT(podParent->m_punk) ;
				if (podParent->m_punk)
					ViewInterface( theApp.m_pMainWnd->GetSafeHwnd(), pObjectData->m_clsid, podParent->m_punk ) ;
			}
		}
		break ;

		case CObjectData::typeTypeLib:
		{
			ITypeLib* pTypeLib ;
			LCID      lcid = GetUserDefaultLCID() ;
			HRESULT hr = ::LoadRegTypeLib( pObjectData->m_clsid, pObjectData->m_wMajorVer,
							   pObjectData->m_wMinorVer, lcid, &pTypeLib ) ;
			if (FAILED(hr))
			{
				TCHAR szTemp[256] ;
				LPOLESTR lpStr;
				StringFromCLSID(pObjectData->m_clsid, &lpStr);
				_stprintf_s(szTemp, 256, _T("LoadRegTypeLib(%s, %u, %u, %lu, ...) failed."),
						(LPSTR)COLE2CT(lpStr), pObjectData->m_wMajorVer, pObjectData->m_wMinorVer,
						lcid);
				CoTaskMemFree(lpStr);
				ErrorMessage( szTemp, hr ) ;
			}
			else
			{
				ViewInterface( theApp.m_pMainWnd->GetSafeHwnd(), IID_ITypeLib, pTypeLib ) ;
				#ifdef _DEBUG
				ASSERT( 0 == pTypeLib->Release() ) ;
				#else
				pTypeLib->Release() ;
				#endif
			}
		}
		break ;
		}
	}
}

void CObjTreeView::OnTreeReturn(NMHDR* /*pNMHDR */, LRESULT* pResult)
{
	*pResult = (LRESULT)TRUE ;
	HTREEITEM hTreeItemSel = GetTreeCtrl().GetSelectedItem() ;

	if (hTreeItemSel)
		GetTreeCtrl().Expand( hTreeItemSel, TVE_TOGGLE ) ;
}

void CObjTreeView::OnTreeDeleteItem(NMHDR* pNMHDR, LRESULT*)
{
	NM_TREEVIEW* pnmtv = (NM_TREEVIEW*)pNMHDR;

	if (pnmtv->itemOld.lParam)
	{
		CObjectData* pod = (CObjectData*)pnmtv->itemOld.lParam ;
		ASSERT(pod->IsKindOf(RUNTIME_CLASS(CObjectData)));
		delete (CObjectData*)pnmtv->itemOld.lParam ;
		pnmtv->itemOld.lParam = NULL ;
	}
}

void CObjTreeView::OnObjectDelete()
{
	AfxMessageBox("Not implemented yet" ) ;

}

void CObjTreeView::OnObjectVerify()
{
	AfxMessageBox("Not implemented yet" ) ;

}

BOOL CObjTreeView::IsValidSel()
{
	return (GetTreeCtrl().GetSelectedItem() != NULL) ;
}

#ifdef _DEBUG

COle2ViewDoc* CObjTreeView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COle2ViewDoc)));
	return (COle2ViewDoc*) m_pDocument;
}

#endif //_DEBUG

void CObjTreeView::OnUseInProcServer()
{
	COle2ViewDoc*   pDoc = GetDocument() ;

	if (pDoc->m_dwClsCtx & CLSCTX_INPROC_SERVER)
		pDoc->m_dwClsCtx &= ~CLSCTX_INPROC_SERVER ;
	else
		pDoc->m_dwClsCtx |= CLSCTX_INPROC_SERVER ;
	if (pDoc->m_dwClsCtx == NULL)
		pDoc->m_dwClsCtx = CLSCTX_INPROC_SERVER ;
//    OnUpdate( this, NULL, NULL ) ;
}

void CObjTreeView::OnUpdateUseInProcServer(CCmdUI* pCmdUI)
{
	COle2ViewDoc*   pDoc = GetDocument() ;
	pCmdUI->SetCheck( pDoc->m_dwClsCtx & CLSCTX_INPROC_SERVER ? TRUE : FALSE  ) ;
}

void CObjTreeView::OnUseInProcHandler()
{
	COle2ViewDoc*   pDoc = GetDocument() ;
	if (pDoc->m_dwClsCtx & CLSCTX_INPROC_HANDLER)
		pDoc->m_dwClsCtx &= ~CLSCTX_INPROC_HANDLER ;
	else
		pDoc->m_dwClsCtx |= CLSCTX_INPROC_HANDLER ;
	if (pDoc->m_dwClsCtx == NULL)
		pDoc->m_dwClsCtx = CLSCTX_INPROC_HANDLER ;
//    OnUpdate( this, NULL, NULL ) ;
}

void CObjTreeView::OnUpdateUseInProcHandler(CCmdUI* pCmdUI)
{
	COle2ViewDoc*   pDoc = GetDocument() ;
	pCmdUI->SetCheck( pDoc->m_dwClsCtx & CLSCTX_INPROC_HANDLER ? TRUE : FALSE ) ;
}

void CObjTreeView::OnUseLocalServer()
{
	COle2ViewDoc*   pDoc = GetDocument() ;
	if (pDoc->m_dwClsCtx & CLSCTX_LOCAL_SERVER)
		pDoc->m_dwClsCtx &= ~CLSCTX_LOCAL_SERVER ;
	else
		pDoc->m_dwClsCtx |= CLSCTX_LOCAL_SERVER ;

	if (pDoc->m_dwClsCtx == NULL)
		pDoc->m_dwClsCtx = CLSCTX_LOCAL_SERVER ;

//    OnUpdate( this, NULL, NULL ) ;
}

void CObjTreeView::OnUpdateUseLocalServer(CCmdUI* pCmdUI)
{
	COle2ViewDoc*   pDoc = GetDocument() ;
	pCmdUI->SetCheck( pDoc->m_dwClsCtx & CLSCTX_LOCAL_SERVER ? TRUE : FALSE ) ;
}


void CObjTreeView::OnFileBind()
{
}
