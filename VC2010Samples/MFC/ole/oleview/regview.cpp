// regview.cpp : implementation file
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
#include "oleview.h"
#include "regview.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

BOOL RegToListBox( CTreeCtrl* pTree, const CString& strKey, HKEY hk, HTREEITEM htreeParent ) ;
HICON GetIconFromReg( HKEY hk, LPTSTR szKey ) ;

int const MAX_KEYLEN    =   256 ;
int const MAX_VALLEN    =   (_MAX_PATH + MAX_KEYLEN) ;

class CRegEntry
{
public:
	CRegEntry( const CString& rstrKey,  const CString& rstrValue ) ;
	virtual ~CRegEntry() ;

public:
	CString     m_strKey ;
	CString     m_strValue ;
	TCHAR*      m_pszText ;
} ;

CRegEntry::CRegEntry( const CString& rstrKey,  const CString& rstrValue )
{
	m_strKey = rstrKey ;
	m_strValue = rstrValue ;
	m_pszText = NULL ;
}

CRegEntry::~CRegEntry( )
{
	if (m_pszText != NULL)
		delete []m_pszText ;
	m_pszText = NULL ;
}

/////////////////////////////////////////////////////////////////////////////
// CRegistryView

IMPLEMENT_DYNCREATE(CRegistryView, CFormView)

CRegistryView::CRegistryView()
	: CFormView(CRegistryView::IDD)
{
	//{{AFX_DATA_INIT(CRegistryView)
	//}}AFX_DATA_INIT
}

#ifdef _DEBUG

COle2ViewDoc* CRegistryView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COle2ViewDoc)));
	return (COle2ViewDoc*) m_pDocument;
}

#endif //_DEBUG


CRegistryView::~CRegistryView()
{
}

void CRegistryView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CRegistryView)
	DDX_Control(pDX, IDC_OBJECTNAME, m_Name);
	DDX_Control(pDX, IDC_OBJECTCLSID, m_CLSID);
	DDX_Control(pDX, IDC_OBJICON, m_icon);
	DDX_Control(pDX, IDC_TREEVIEW, m_tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CRegistryView, CFormView)
	//{{AFX_MSG_MAP(CRegistryView)
	ON_WM_SIZE()
	ON_BN_CLICKED(IDC_UNREGISTER, OnUnregister)
	ON_NOTIFY(TVN_ITEMEXPANDING, IDC_TREEVIEW, OnTreeViewItemExpanding)
	ON_NOTIFY(TVN_GETDISPINFO, IDC_TREEVIEW, OnGetDispInfoTreeView)
	ON_NOTIFY(TVN_SETDISPINFO, IDC_TREEVIEW, OnSetDispInfoTreeView)
	ON_NOTIFY(TVN_DELETEITEM, IDC_TREEVIEW, OnDeleteItemTreeView)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CRegistryView diagnostics

#ifdef _DEBUG
void CRegistryView::AssertValid() const
{
	CFormView::AssertValid();
}

void CRegistryView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRegistryView message handlers

void CRegistryView::OnSize(UINT nType, int cx, int cy)
{
	CFormView::OnSize(nType, cx, cy);

	if (m_tree.GetSafeHwnd())
	{
		CRect rc ;
		m_tree.GetWindowRect( &rc ) ;
		ScreenToClient( &rc ) ;
		m_tree.SetWindowPos( NULL, 4, rc.top, cx-8, cy - rc.top - 4,
							SWP_NOACTIVATE|SWP_NOZORDER ) ;
	}
}

void CRegistryView::OnUnregister()
{
	// TODO: Add your control notification handler code here

}

void CRegistryView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CRect rc ;
	CRect rcClient ;
	GetWindowRect( &rcClient ) ;
	//GetParent()->ScreenToClient( &rcClient ) ;
	m_tree.GetWindowRect( &rc ) ;
	ScreenToClient( &rc ) ;

	m_tree.SetWindowPos( NULL, 4, rc.top, rcClient.Width() - 8,
						 rcClient.Height() - rc.top - 4,
						 SWP_NOACTIVATE|SWP_NOREDRAW|SWP_NOZORDER ) ;

	m_tree.SetFocus() ;

	m_tree.SetIndent( 0 ) ;

	SetScrollSizes( MM_TEXT, CSize(1,1) ) ;
}

void CRegistryView::OnUpdate(CView* /* pSender */, LPARAM lHint, CObject* /*pHint*/)
{
	if (lHint & UPD_NOINTERFACEVIEW || lHint & UPD_NOOBJECTVIEW)
		return ;

	COle2ViewDoc* pDoc = GetDocument() ;

	BeginWaitCursor() ;
	m_tree.SetRedraw(FALSE) ;
	m_tree.DeleteAllItems() ;
	if (IsEqualCLSID( pDoc->m_clsidCur, CLSID_NULL ))
	{
		m_Name.SetWindowText("") ;
		m_CLSID.SetWindowText("") ;
		m_icon.SetIcon( theApp.LoadIcon( IDR_MAINFRAME ) ) ;
		m_tree.SetRedraw(TRUE) ;
		EndWaitCursor() ;
		return ;
	}

	// Fill the listbox with useful info about the class
	//
	HICON   hicon = NULL ;
	HKEY    hk ;

	OLECHAR szOleCLSID[64];
	::StringFromGUID2( pDoc->m_clsidCur, szOleCLSID,
		sizeof(szOleCLSID)/sizeof(OLECHAR) ) ;
	COLE2T lpszCLSID(szOleCLSID);
	m_CLSID.SetWindowText( lpszCLSID ) ;
	m_Name.SetWindowText( pDoc->m_szObjectCur ) ;

	TCHAR           szKey[MAX_VALLEN] ;
	TCHAR           szBuf[MAX_VALLEN] ;

	TV_INSERTSTRUCT tvis ;
	tvis.hParent = TVI_ROOT ;
	tvis.hInsertAfter = TVI_LAST ;
	tvis.item.mask = TVIF_TEXT | TVIF_PARAM ;

	if (pDoc->m_fTypeLib)
	{
		// HKEY_CLASSES_ROOT\TypeLib
		_stprintf_s( szBuf, MAX_VALLEN, _T("TypeLib\\%s"), lpszCLSID ) ;
		if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hk) == ERROR_SUCCESS)
		{
			LONG cb ;
			cb = sizeof(szBuf) ;
			RegQueryValue( HKEY_CLASSES_ROOT, (LPTSTR)_T("TypeLib"), szBuf, &cb) ;
			tvis.hParent = TVI_ROOT ;
			_stprintf_s(szKey, MAX_VALLEN, _T("%s = %s"), (LPCTSTR)_T("TypeLib"), (LPCTSTR)szBuf ) ;
			tvis.item.pszText = szKey ;
			#pragma warning(suppress: 6014) // unexpected prefast leaking memory warning
			tvis.item.lParam = (LPARAM)new CRegEntry( _T("TypeLib"), szBuf ) ;
			HTREEITEM htree = m_tree.InsertItem( &tvis ) ;
			RegToListBox( &m_tree, (LPTSTR)lpszCLSID, hk, htree ) ;
			m_tree.Expand( htree, TVE_EXPAND ) ;
			m_icon.SetIcon( theApp.LoadIcon( IDI_AUTOMATION ) ) ;

			RegCloseKey( hk ) ;
		}
		else
			m_icon.SetIcon( theApp.LoadIcon( IDI_NOICON ) ) ;
	}
	else if (pDoc->m_fInterface)
	{
		// HKEY_CLASSES_ROOT\Interface
		_stprintf_s( szBuf, MAX_VALLEN, _T("Interface\\%s"), lpszCLSID ) ;
		if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hk) == ERROR_SUCCESS)
		{
			LONG cb = sizeof(szBuf) ;
			RegQueryValue( HKEY_CLASSES_ROOT, (LPTSTR)_T("Interface"), szBuf, &cb) ;

			tvis.hParent = TVI_ROOT ;
			_stprintf_s(szKey, MAX_VALLEN, _T("%s = %s"), (LPCTSTR)_T("Interface"), (LPCTSTR)szBuf ) ;
			tvis.item.pszText = szKey ;
			tvis.item.lParam = (LPARAM)new CRegEntry( _T("Interface"), szBuf ) ;
			HTREEITEM htree = m_tree.InsertItem( &tvis ) ;
			RegToListBox( &m_tree, (LPTSTR) lpszCLSID, hk, htree ) ;
			m_tree.Expand( htree, TVE_EXPAND ) ;

			cb = sizeof(szBuf) ;
			if (RegQueryValue( hk, (LPTSTR)_T("BaseInterface"), szBuf, &cb) == ERROR_SUCCESS &&
				*szBuf != '\0')
			{
				HKEY hk2 ;
				if (RegOpenKey( HKEY_CLASSES_ROOT, CString("Interface\\") + szBuf, &hk2) == ERROR_SUCCESS)
				{
					RegToListBox( &m_tree, szBuf, hk2, htree ) ;
					RegCloseKey( hk2 ) ;
				}
			}

			cb = sizeof(szBuf) ;
			LONG cb2 = sizeof(szBuf) ;
			if (RegQueryValue( hk, (LPTSTR)_T("ProxyStubClsid32"), szBuf, &cb) == ERROR_SUCCESS ||
				RegQueryValue( hk, (LPTSTR)_T("ProxyStubClsid"), szBuf, &cb2) == ERROR_SUCCESS)
			{
				cb = sizeof(szBuf) ;
				*szBuf = '\0' ;
				RegQueryValue( HKEY_CLASSES_ROOT, (LPTSTR)"CLSID", szBuf, &cb) ;
				_stprintf_s(szKey, MAX_VALLEN, _T("%s = %s"), (LPCTSTR)_T("CLSID"), (LPCTSTR)szBuf ) ;
				tvis.item.pszText = szKey ;
				tvis.item.lParam = (LPARAM)new CRegEntry( "CLSID", szBuf ) ;
				HTREEITEM htreeCLSID = m_tree.InsertItem( &tvis ) ;
				HKEY hk2 ;
				if (RegOpenKey( HKEY_CLASSES_ROOT, "CLSID", &hk2) == ERROR_SUCCESS)
				{
					cb = sizeof(szBuf) ;
					if (RegQueryValue( hk, (LPTSTR)_T("ProxyStubClsid32"), szBuf, &cb) == ERROR_SUCCESS)
					{
						HKEY hk3 ;
						if (RegOpenKey( hk2, szBuf, &hk3) == ERROR_SUCCESS)
							RegToListBox( &m_tree, szBuf, hk3, htreeCLSID ) ;
						RegCloseKey( hk3 ) ;
					}

					cb = sizeof(szKey) ;
					if (RegQueryValue( hk, (LPTSTR)_T("ProxyStubClsid"), szKey, &cb) == ERROR_SUCCESS)
					{
						if (lstrcmpi(szKey,szBuf) != 0)
						{
							HKEY hk3 ;
							if (RegOpenKey( hk2, szKey, &hk3) == ERROR_SUCCESS)
								RegToListBox( &m_tree, szKey, hk3, htreeCLSID ) ;
							RegCloseKey( hk3 ) ;
						}
					}

					RegCloseKey( hk2 ) ;
				}
				m_tree.Expand( htreeCLSID, TVE_EXPAND ) ;
			}

			cb = sizeof(szBuf) ;
			if (RegQueryValue( hk, (LPTSTR)_T("TypeLib"), szBuf, &cb) == ERROR_SUCCESS)
			{
				_stprintf_s(szKey, MAX_VALLEN, _T("%s = %s"), (LPCTSTR)_T("TypeLib"), (LPCTSTR)szBuf ) ;
				tvis.item.pszText = szKey ;
				tvis.item.lParam = (LPARAM)new CRegEntry( "TypeLib", szBuf ) ;
				htree = m_tree.InsertItem( &tvis ) ;

				HKEY hk2 ;
				if (RegOpenKey( HKEY_CLASSES_ROOT, CString("TypeLib\\") + szBuf, &hk2) == ERROR_SUCCESS)
				{
					RegToListBox( &m_tree, szBuf, hk2, htree ) ;
					RegCloseKey( hk2 ) ;
				}
				m_tree.Expand( htree, TVE_EXPAND ) ;
			}

			RegCloseKey( hk ) ;

			m_icon.SetIcon( theApp.LoadIcon( IDI_INTERFACE ) ) ;
		}
		else
			m_icon.SetIcon( theApp.LoadIcon( IDI_NOICON ) ) ;
	}
	else
	{
		LONG cb = sizeof( szBuf );
		*szBuf = '\0' ;
		RegQueryValue( HKEY_CLASSES_ROOT, (LPTSTR)"CLSID", szBuf, &cb) ;
		_stprintf_s(szKey, MAX_VALLEN, _T("%s = %s"), (LPCTSTR)_T("CLSID"), (LPCTSTR)szBuf ) ;
		tvis.item.pszText = szKey ;
		tvis.item.lParam = (LPARAM)new CRegEntry( "CLSID", szBuf) ;
		HTREEITEM htreeCLSID = m_tree.InsertItem( &tvis ) ;

		_stprintf_s(szKey, MAX_VALLEN, _T("CLSID\\%s"), lpszCLSID ) ;
		if (RegOpenKey( HKEY_CLASSES_ROOT, szKey, &hk) == ERROR_SUCCESS)
		{
			TCHAR    szValue[MAX_VALLEN] ;

			cb = sizeof( szBuf );
			if (RegQueryValue( hk, (LPTSTR)_T("DefaultIcon"), szValue, &cb) == ERROR_SUCCESS)
			{
				LPTSTR p ;
				int   nIndex = 0 ;

				p = PointerToNthField( szValue, 2, ',' ) ;
				if (p && *p)
				{
					*(p-1) = '\0' ;
					nIndex = (int)*p - (int)'0' ;
				}
				if (*szValue == '"')
				{
					_tcscpy_s( szValue, MAX_VALLEN, szValue+1 ) ;
					p = strrchr( szValue, '"' ) ;
					if (p) *p = '\0' ;
				}
				hicon = ExtractIcon( AfxGetInstanceHandle(), szValue, nIndex ) ;
			}

			if ((INT_PTR)hicon <= 1)
			{
				// try local server
				hicon = GetIconFromReg( hk, _T("LocalServer32") ) ;
				if ((INT_PTR)hicon <= 1)
					hicon = GetIconFromReg( hk, _T("LocalServer") ) ;
			}

			if ((INT_PTR)hicon <= 1)
			{
				// try inproc server
				hicon = GetIconFromReg( hk, _T("InprocServer32") ) ;
				if ((INT_PTR)hicon <= 1)
					hicon = GetIconFromReg( hk, _T("InprocServer") ) ;
			}

			if ((INT_PTR)hicon <= 1)
			{
				// try inproc handler
				hicon = GetIconFromReg( hk, _T("InprocHandler32") ) ;
				if ((INT_PTR)hicon <= 1)
					hicon = GetIconFromReg( hk, _T("InprocHandler") ) ;
			}

			// Now fill list box with all other stuff in the HKEY_CLASSES_ROOT\CLSID key
			//
			RegToListBox( &m_tree, (LPTSTR) lpszCLSID, hk, htreeCLSID ) ;
			m_tree.Expand( htreeCLSID, TVE_EXPAND ) ;

			HKEY hkNext ;

			// HKEY_CLASSES_ROOT\ProgID\ key
			cb = sizeof( szValue ) ;
			if (RegQueryValue( hk, (LPTSTR)_T("ProgID"), szValue, &cb) != ERROR_SUCCESS)
				*szValue = '\0' ;
			if (*szValue && (RegOpenKey( HKEY_CLASSES_ROOT, szValue, &hkNext) == ERROR_SUCCESS))
			{
				cb = sizeof(szKey) ;
				RegToListBox( &m_tree, szValue, hkNext, TVI_ROOT ) ;

				if ((INT_PTR)hicon <= 1)
				{
					szBuf[0] = '\0' ;
					cb = sizeof(szBuf) ;
					if (RegQueryValue( hkNext, (LPTSTR)_T("Protocol\\StdFileEditing\\Server"), szBuf, &cb ) == ERROR_SUCCESS)
					{
						LPTSTR p ;
						if (*szBuf == '"')
						{
							_tcscpy_s( szBuf, MAX_VALLEN, szBuf+1 ) ;
							p = strrchr( szBuf, '"' ) ;
							if (p) *p = '\0' ;
						}

						hicon = ExtractIcon( AfxGetInstanceHandle(), szBuf, 0 ) ;
					}

				}

				RegCloseKey( hkNext ) ;
			}

			_stprintf_s(szBuf, MAX_VALLEN, _T("FileType\\%s"), lpszCLSID ) ;
			if (lpszCLSID && (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hkNext) == ERROR_SUCCESS))
			{
				tvis.hParent = TVI_ROOT ;
				*szBuf = '\0' ;
				cb = sizeof(szBuf) ;
				RegQueryValue( HKEY_CLASSES_ROOT, (LPTSTR)"FileType", szBuf, &cb) ;
				_stprintf_s(szKey, MAX_VALLEN, _T("%s = %s"), (LPCTSTR)_T("FileType"), (LPCTSTR)szBuf ) ;
				tvis.item.pszText = szKey ;
				tvis.item.lParam = (LPARAM)new CRegEntry( "FileType", szBuf) ;
				HTREEITEM htree = m_tree.InsertItem( &tvis ) ;
				RegToListBox( &m_tree, (LPTSTR) lpszCLSID, hkNext, htree ) ;
				m_tree.Expand( htree, TVE_EXPAND ) ;
				RegCloseKey( hkNext ) ;
			}

			// HKEY_CLASSES_ROOT\TypeLib
			cb = sizeof( szValue ) ;
			if (RegQueryValue( hk, (LPTSTR)_T("TypeLib"), szValue, &cb) == ERROR_SUCCESS)
			{
				_stprintf_s(szBuf, MAX_VALLEN, _T("TypeLib\\%s"), szValue ) ;
				if (RegOpenKey( HKEY_CLASSES_ROOT, szBuf, &hkNext) == ERROR_SUCCESS)
				{
					tvis.hParent = TVI_ROOT ;
					*szBuf = '\0' ;
					cb = sizeof(szBuf) ;
					RegQueryValue( HKEY_CLASSES_ROOT, (LPTSTR)"TypeLib", szBuf, &cb) ;

					_stprintf_s(szKey, MAX_VALLEN, _T("%s = %s"), (LPCTSTR)_T("TypeLib"), (LPCTSTR)szBuf ) ;
					tvis.item.pszText = szKey ;
					tvis.item.lParam = (LPARAM)new CRegEntry( "TypeLib", szBuf) ;
					HTREEITEM htree = m_tree.InsertItem( &tvis ) ;
					RegToListBox( &m_tree, szValue, hkNext, htree ) ;
					m_tree.Expand( htree, TVE_EXPAND ) ;
					RegCloseKey( hkNext ) ;
				}
			}

			RegCloseKey( hk ) ;

			if ((INT_PTR)hicon > 1)
				m_icon.SetIcon( hicon ) ;
			else
				m_icon.SetIcon( theApp.LoadIcon( IDI_NOICON ) ) ;

			m_tree.EnsureVisible( htreeCLSID ) ;
		}
	}

	m_tree.SetRedraw(TRUE) ;
	EndWaitCursor() ;

}

BOOL RegToListBox( CTreeCtrl* pTree, const CString& strKey, HKEY hk, HTREEITEM htreeParent )
{
	TCHAR szKey[MAX_KEYLEN];
	TCHAR szValue[MAX_VALLEN];
	TCHAR szBuf[MAX_VALLEN + 4];
	LONG  cb ;
	DWORD dwIndex ;

	TRY
	{
		TV_INSERTSTRUCT tvis ;
		tvis.hParent = htreeParent ;
		tvis.hInsertAfter = TVI_LAST ;
		tvis.item.mask = TVIF_TEXT | TVIF_PARAM ;

		cb = MAX_KEYLEN ;
		RegQueryValue( hk, NULL, szValue, &cb) ;
		_stprintf_s( szBuf, MAX_VALLEN + 4, _T("%s = %s"), (LPCTSTR)strKey, (LPCTSTR)szValue ) ;
		tvis.item.pszText = szBuf ;
		#pragma warning(suppress: 6014)
		tvis.item.lParam = (LPARAM)new CRegEntry( strKey, szValue ) ;
		HTREEITEM htree = pTree->InsertItem( &tvis ) ;

		for ( dwIndex = 0 ;
			  RegEnumKey( hk, dwIndex, szKey, MAX_KEYLEN) == ERROR_SUCCESS ;
			  ++dwIndex )
		{
			cb = MAX_KEYLEN ;
			*szValue = '\0' ;
			RegQueryValue( hk, (LPTSTR)szKey, szValue, &cb) ;
			HKEY hkNext ;
			if (RegOpenKey( hk, szKey, &hkNext) == ERROR_SUCCESS)
			{
				RegToListBox( pTree, szKey, hkNext, htree ) ;
				RegCloseKey( hkNext ) ;
			}
		}

		pTree->Expand( htree, TVE_EXPAND ) ;
	}
	CATCH(CException, pException)
	{
		return FALSE ;
	}
	END_CATCH;

	return TRUE ;
}

HICON GetIconFromReg( HKEY hk, LPTSTR szKey )
{
	TCHAR szValue[MAX_VALLEN] ;
	LONG cb = MAX_VALLEN ;
	if (RegQueryValue( hk, szKey, szValue, &cb) == ERROR_SUCCESS)
	{
		LPTSTR p = szValue + lstrlen( szValue ) - 1 ;
		if (p && *p == ' ')
			*p = '\0' ;
		if (*szValue == '"')
		{
			_tcscpy_s( szValue, MAX_VALLEN, szValue+1 ) ;
			p = strrchr( szValue, '"' ) ;
			if (p) *p = '\0' ;
		}

		return ExtractIcon( AfxGetInstanceHandle(), szValue, 0 ) ;
	}
	else
		return (HICON)-1 ;
}

void CRegistryView::OnTreeViewItemExpanding(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	if (pNMTreeView->action == TVE_COLLAPSE)
		*pResult = 1 ; // prevent collapse
	else
		*pResult = 0 ;
}

void CRegistryView::OnGetDispInfoTreeView(NMHDR* /*pNMHDR*/, LRESULT* pResult)
{
/*
	TV_DISPINFO * pdispinfo = (TV_DISPINFO*)pNMHDR;
	CRegEntry* pentry = (CRegEntry*)pdispinfo->item.lParam ;
	if (pentry)
	{
		//if (pentry->m_pszText)
		//{
		//    delete []pentry->m_pszText ;
		//    pentry->m_pszText = NULL ;
		//}
		if (pdispinfo->item.mask & TVIF_TEXT)
		{
			if (pentry->m_pszText)
				pdispinfo->item.pszText = pentry->m_pszText ;
			else
			{
				pentry->m_pszText = new TCHAR[pentry->m_strKey.GetLength() + pentry->m_strKey.GetLength() + 4] ;
				wsprintf( pentry->m_pszText, _T("%s = %s"), (LPCTSTR)pentry->m_strKey, (LPCTSTR)pentry->m_strValue ) ;
				pdispinfo->item.pszText = pentry->m_pszText ;
				pdispinfo->item.mask = TVIF_TEXT ;
			}
		}
	}
*/
	*pResult = 0;
}

void CRegistryView::OnSetDispInfoTreeView(NMHDR* /*pNMHDR*/, LRESULT* pResult)
{
	// TV_DISPINFO * pdispinfo = (TV_DISPINFO*)pNMHDR;
	// TODO: Add your control notification handler code here

	*pResult = 0;
}

void CRegistryView::OnDeleteItemTreeView(NMHDR* pNMHDR, LRESULT* pResult)
{
	NM_TREEVIEW* pNMTreeView = (NM_TREEVIEW*)pNMHDR;

	if (pNMTreeView->itemOld.lParam)
	{
		delete (CRegEntry*)pNMTreeView->itemOld.lParam;
	}

	*pResult = 0;
}
