// tlbodl.cpp : implementation file
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
#include "util.h"
#include "iviewers.h"
#include "iviewer.h"
#include "typelib.h"
#include "tree.h"
#include "tlbodl.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

#define MAX_NAMES   64     // max parameters to a function

IStream* CreateMemoryStream();
int StringFromGUID2T(REFGUID rguid, LPTSTR lpszGUID, int nSize, int cbMax);

// if defined, when typedefs are written out a tag is created
// by concatinating "tag" with the typedef name.
#define _WRITE_TAG 1

/////////////////////////////////////////////////////////////////////////////
// CTypeLibODLView

IMPLEMENT_DYNCREATE(CTypeLibODLView, CEditView)

CTypeLibODLView::CTypeLibODLView()
{
}

CTypeLibODLView::~CTypeLibODLView()
{
}


BEGIN_MESSAGE_MAP(CTypeLibODLView, CEditView)
	//{{AFX_MSG_MAP(CTypeLibODLView)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CTypeLibODLView drawing

void CTypeLibODLView::OnDraw(CDC* pDC)
{
}

/////////////////////////////////////////////////////////////////////////////
// CTypeLibODLView diagnostics

#ifdef _DEBUG
void CTypeLibODLView::AssertValid() const
{
	CEditView::AssertValid();
}

void CTypeLibODLView::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTypeLibODLView message handlers

BOOL CTypeLibODLView::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= ES_READONLY | ES_MULTILINE | WS_VSCROLL | WS_HSCROLL ;

	return CEditView::PreCreateWindow(cs);
}

void CTypeLibODLView::OnInitialUpdate()
{
	m_Font.CreateFont( -11, 0, 0, 0, 0, 0,
				0, 0, ANSI_CHARSET, 0, 0, 0,
				FIXED_PITCH | FF_DONTCARE, _T("Courier New") ) ;

	SetFont( &m_Font );
	CEditView::OnInitialUpdate();
}

void CTypeLibODLView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	CTypeLibWnd* pFrame = (CTypeLibWnd*)GetParent()->GetParent() ;
	ASSERT(pFrame->IsKindOf(RUNTIME_CLASS(CTypeLibWnd)));

	if (pFrame->m_pSelectedItem == NULL)
	{
		SetWindowText(_T("")) ;
		return ;
	}

	SetRedraw( FALSE ) ;
	BeginWaitCursor() ;

	CString     sText;
	HRESULT     hr = S_OK ;
	IStream*    pstm = NULL ;

	TRY
	{
		pstm = CreateMemoryStream() ;

		switch(pFrame->m_pSelectedItem->m_Type)
		{
		case CTreeItem::typeTypeLib:
		case CTreeItem::typeTypeLib2:
			 hr = DeCompileTypeLib( pstm, pFrame->m_pSelectedItem->GetTypeLib() ) ;
		break ;

		case CTreeItem::typeEnum:
		case CTreeItem::typeRecord:
		case CTreeItem::typeModule:
		case CTreeItem::typeInterface:
		case CTreeItem::typeDispinterface:
		case CTreeItem::typeCoClass:
		case CTreeItem::typeAlias:
		case CTreeItem::typeUnion:
		case CTreeItem::typeTypeInfo:
		case CTreeItem::typeTypeInfo2:
			switch(pFrame->m_pSelectedItem->GetTypeKind())
			{
			case TKIND_ENUM:
			case TKIND_RECORD:
			case TKIND_UNION:
			case TKIND_ALIAS:
				 hr = DeCompileTypedef( pstm, pFrame->m_pSelectedItem->GetTypeInfo() ) ;
			break ;

			case TKIND_MODULE:
				 hr = DeCompileModule( pstm, pFrame->m_pSelectedItem->GetTypeInfo() ) ;
			break ;

			case TKIND_INTERFACE:
				 hr = DeCompileInterface( pstm, pFrame->m_pSelectedItem->GetTypeInfo() ) ;
			break ;

			case TKIND_DISPATCH:
				 hr = DeCompileDispinterface( pstm, pFrame->m_pSelectedItem->GetTypeInfo() ) ;
			break ;

			case TKIND_COCLASS:
				 hr = DeCompileCoClass( pstm, pFrame->m_pSelectedItem->GetTypeInfo() ) ;
			break ;

			default:
				sText = _T("<<unclassified typeinfo>>");
			break ;
			}
		break ;

		case CTreeItem::typeMethod:
			 hr = DeCompileFunc( pstm, pFrame->m_pSelectedItem->GetTypeInfo(), pFrame->m_pSelectedItem->m_uiMemid ) ;
		break ;

		case CTreeItem::typeProperty:
			 hr = DeCompileVar( pstm, pFrame->m_pSelectedItem->GetTypeInfo(), pFrame->m_pSelectedItem->m_uiMemid ) ;
		break ;

		case CTreeItem::typeConstant:
			 hr = DeCompileConst( pstm, pFrame->m_pSelectedItem->GetTypeInfo(), pFrame->m_pSelectedItem->m_uiMemid ) ;
		break ;

		case CTreeItem::typeUnknown:
		case CTreeItem::typeUnknown2:
		case CTreeItem::typeEnums:
		case CTreeItem::typeRecords:
		case CTreeItem::typeModules:
		case CTreeItem::typeInterfaces:
		case CTreeItem::typeDispinterfaces:
		case CTreeItem::typeCoClasses:
		case CTreeItem::typeAliases:
		case CTreeItem::typeUnions:
		case CTreeItem::typeMethods:
		case CTreeItem::typeMethods2:
		case CTreeItem::typeProperties:
		case CTreeItem::typeProperties2:
		case CTreeItem::typeConstants:
		case CTreeItem::typeConstants2:
		case CTreeItem::typeImplTypes:
		case CTreeItem::typeImplTypes2:
		default:
			//bstr = ::SysAllocString(OLESTR(""));
		break ;
		}

		if (hr != S_OK)
			AfxThrowOleException( hr ) ;

		if (pstm)
		{
			STATSTG statstg ;
			if (FAILED(hr = pstm->Stat( &statstg,STATFLAG_NONAME )))
				AfxThrowOleException( hr ) ;

			// Seek to beginning
			LARGE_INTEGER li ;
			LISet32( li, 0 ) ;
			if (FAILED(hr = pstm->Seek( li, STREAM_SEEK_SET, NULL )))
				AfxThrowOleException( hr ) ;

			// Read into string
			LPSTR lpszBuf = sText.GetBuffer(statstg.cbSize.LowPart+1);
			if (FAILED(hr = pstm->Read( lpszBuf, statstg.cbSize.LowPart, NULL )))
				AfxThrowOleException( hr ) ;
			lpszBuf[statstg.cbSize.LowPart] = '\0';
			sText.ReleaseBuffer();
			SetWindowText(sText);
			pstm->Release() ;
		}
	}
	CATCH(CException, pException)
	{
		SetWindowText( _T("// Could not decompile selected item") ) ;
		if (pstm)
			pstm->Release() ;

		if (pException->IsKindOf(RUNTIME_CLASS(COleException)))
			hr = ((COleException*)pException)->m_sc ;
		else if (pException->IsKindOf(RUNTIME_CLASS(COleException)))
			hr = E_OUTOFMEMORY ;

		if (hr == S_OK)
			hr = GetLastError() ;

		ErrorMessage( "Could not decompile selected item", hr ) ;
	}
	END_CATCH

	SetRedraw( TRUE ) ;
	EndWaitCursor() ;
	SendMessage(EM_SETSEL, 0, 0)  ;
}

void CTypeLibODLView::OnDestroy()
{
	CEditView::OnDestroy();

	m_Font.DeleteObject() ;
}

// Write string s with no indent and no CR
#define WRITE( s )          WriteLine( pstm, s, 0, FALSE )

// Write string s with indent and no CR
#define WRITE1( s )         WriteLine( pstm, s, uiIndent, FALSE )
#define WRITE2( s, ui )     WriteLine( pstm, s, uiIndent+ui, FALSE )

// Write string s with indent and CR
#define WRITELINE( s )      WriteLine( pstm, s, uiIndent, TRUE )
#define WRITELINE2( s, ui ) WriteLine( pstm, s, uiIndent+ui, TRUE )
#define WRITECR( s )        WriteLine( pstm, s, 0, TRUE )

#define WRITERAW( p, len )     WriteRaw( pstm, p, len )
#define WRITEBSTR( p )         WriteBSTR( pstm, p )

inline void WriteRaw( IStream* pstm, const void* pv, UINT cb )
{
	HRESULT hr ;
	if (FAILED(hr = pstm->Write( pv, cb, NULL )))
		AfxThrowOleException( hr ) ;
}

inline void WriteLine( IStream* pstm, const CString &rstr, UINT uiIndent, BOOL fNewLine )
{
	while(uiIndent--)
	{
		WriteRaw( pstm, _T("    "), 4 * sizeof(TCHAR));
	}

	WriteRaw( pstm, rstr, rstr.GetLength() * sizeof(TCHAR)) ;

	if (fNewLine)
		WriteRaw(pstm, _T("\r\n"), 2 * sizeof(TCHAR)) ;
}

inline void WriteBSTR( IStream* pstm, BSTR bstr )
{
	UINT len = ::SysStringLen(bstr) ;
	if (!len)
		return ;

	COLE2T lpszSource(bstr);
	TCHAR *pstrTemp = new TCHAR[((len + 1) * sizeof(TCHAR)) * 2];
	LPTSTR lpD, lpS = lpszSource ;

	lpD = pstrTemp;
	for (UINT n = 0 ; n < len ; n++)
	{
		#pragma warning (suppress: 6328) // unexpected type mismatch warning
		if (!isprint(*lpS) || (*lpS) == '\"' || (*lpS) == '\\')
		{
			// \"  \\ \a  \b  \f  \n  \r  \t  \v
			*lpD++ = '\\' ;
			switch(*lpS)
			{
			case '\"':
				*lpD++ = '\"' ;
			break ;
			case '\\':
				*lpD++ = '\\' ;
			break ;
			case '\a':
				*lpD++ = 'a' ;
			break ;
			case '\b':
				*lpD++ = 'b' ;
			break ;
			case '\f':
				*lpD++ = 'f' ;
			break ;
			case '\n':
				*lpD++ = 'n' ;
			break ;
			case '\r':
				*lpD++ = 'r' ;
			break ;
			case '\t':
				*lpD++ = 't' ;
			break ;
			case '\v':
				*lpD++ = 'v' ;
			break ;
			case '\0':
				*lpD++ = '0' ;
			break ;
			default:
				lpD += _stprintf_s( lpD, ((len + 1) * sizeof(TCHAR)) * 2, _T("x%02X"), (UINT)*lpS );
			break ;
			}
			lpS++;
		}
		else
			*lpD++ = *lpS++;
	}
	*lpD = '\0';
	#pragma warning(suppress: 6387) // pstrTemp will always be null terminated.
	WriteRaw( pstm, pstrTemp, lstrlen(pstrTemp)*sizeof(TCHAR) ) ;
	delete []pstrTemp ;
}

//  // typelib.tlb
//  [
//    uuid(<00026b00-0000-0000-C000-000000000046>),
//    version (<major>.<minor>),
//    helpfile ("<helpfile.hlp>"),
//    helpstring("<helpstring>"),
//    helpcontext(<helpcontext>)
//  ]
//  library <libname>
//  {
//      importlib("<import.tlb>");
//
//  };
HRESULT CTypeLibODLView::DeCompileTypeLib( IStream* pstm, ITypeLib* ptlb, UINT uiIndent /* = 0 */ )
{
	HRESULT         hr = S_OK ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;
	TLIBATTR*       plibattr = NULL ;
	ITypeInfo*      pti = NULL ;
	TYPEATTR*       pattr = NULL ;

	ASSERT(ptlb) ;

	TRY
	{
		TCHAR szGUID[64] ;
		CString str;

		ENSURE(ptlb);
		hr = ptlb->GetLibAttr(&plibattr);
		if (FAILED(hr))
			AfxThrowOleException( hr ) ;

		// write header with library filename
		WRITELINE(_T("// Generated .ODL file (by Ole2View)"));
		WRITELINE(_T("// "));
		WRITE1(_T("// typelib filename: "));
		hr = ::QueryPathOfRegTypeLib(plibattr->guid, plibattr->wMajorVerNum, plibattr->wMinorVerNum, plibattr->lcid, &bstrName);
		if (SUCCEEDED(hr))
		{
			COLE2CT lpszName(bstrName);
			::SysFreeString(bstrName);
			bstrName = NULL;

			LPCTSTR p = _tcsrchr(lpszName, '\\');
			if (p != NULL && *p && *(p+1))
				WRITECR( p+1 ) ;
			else
				WRITECR( (LPCTSTR)lpszName ) ;
		}
		else
		{
			// It's possible we're viewing a type lib that was never registered
			WRITECR( _T("<could not determine filename>") ) ;
		}

		WRITELINE( _T("[") ) ;

		StringFromGUID2T( plibattr->guid, szGUID, 64, sizeof(szGUID) );
		WRITE1(_T("  uuid(")) ; WRITE(szGUID); WRITECR(_T("),"))  ;

		str.Format( _T("  version(%d.%d)"), plibattr->wMajorVerNum, plibattr->wMinorVerNum ) ;
		WRITE1(str) ;

		hr = ptlb->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp );
		if (FAILED(hr))
			AfxThrowOleException( hr ) ;

		if (bstrDoc && *bstrDoc)
		{
			WRITECR(_T(",")) ;
			WRITE1(_T("  helpstring(\"")) ;
			WRITEBSTR( bstrDoc ) ;
			WRITE(_T("\")")) ;
		}

		if (bstrHelp && *bstrHelp)
		{
			WRITECR(",") ;
			COLE2CT lpszHelp(bstrHelp);
			::SysFreeString(bstrHelp);
			bstrHelp = NULL;

			LPCTSTR p = _tcsrchr(lpszHelp, '\\');
			if (p != NULL && *p && *(p+1))
				str.Format( _T("  helpfile(\"%s\"),"), p+1 ) ;
			else
				str.Format( _T("  helpfile(\"%s\"),"), lpszHelp ) ;
			WRITELINE( str ) ;
			str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
			WRITE1( str ) ;
		}

		WRITECR(_T("")) ;
		WRITELINE(_T("]") ) ;

		WRITE1( _T("library ") ) ;
		WRITEBSTR(bstrName) ;
		WRITECR(_T("")) ;

		WRITELINE( _T("(") ) ;

		// TODO:  Grovel through all typeinfos for any referenced types
		// that are defined in imported libs
		//uiInfos = ptlb->GetTypeInfoCount() ;
		//for (UINT n = 0 ; n < uiInfos ; n++)
		//{
		//}
		WRITELINE(_T("// BUGBUG:  There most likely were \"importlib()\" statements in"));
		WRITELINE(_T("//          in the source.  While it appears possible to be able"));
		WRITELINE(_T("//          to identify them, it is non-trivial and is currently"));
		WRITELINE(_T("//          not supported."));
		WRITELINE(_T("// "));

		UINT uiInfos = ptlb->GetTypeInfoCount() ;
		for (UINT n = 0 ; n < uiInfos ; n++)
		{
			if (FAILED(hr = ptlb->GetTypeInfo( n, &pti )))
				AfxThrowOleException(hr) ;

			if (FAILED(hr = pti->GetTypeAttr( &pattr )))
				AfxThrowOleException(hr) ;

			switch(pattr->typekind)
			{
			case TKIND_ENUM:
			case TKIND_RECORD:
			case TKIND_UNION:
			case TKIND_ALIAS:
				 hr = DeCompileTypedef( pstm, pti, uiIndent + 1 ) ;
			break ;

			case TKIND_MODULE:
				 hr = DeCompileModule( pstm, pti, uiIndent + 1 ) ;
			break ;

			case TKIND_INTERFACE:
				 hr = DeCompileInterface( pstm, pti, uiIndent + 1 ) ;
			break ;

			case TKIND_DISPATCH:
				 hr = DeCompileDispinterface( pstm, pti, uiIndent + 1 ) ;
			break ;

			case TKIND_COCLASS:
				 hr = DeCompileCoClass( pstm, pti, uiIndent + 1 ) ;
			break ;
			}

			if (n != uiInfos - 1)
				WRITECR(_T("")) ;

			pti->ReleaseTypeAttr( pattr ) ;
			pti->Release() ;
			pti = NULL ;
			pattr = NULL ;
		}
		// Last line of the .ODL file
		WRITELINE( ");" ) ;

		SysFreeString( bstrName ) ;
		bstrName = NULL ;
		SysFreeString( bstrDoc ) ;
		bstrDoc = NULL ;
		SysFreeString( bstrHelp ) ;
		bstrHelp = NULL ;

		if (plibattr)
			ptlb->ReleaseTLibAttr( plibattr ) ;
	}
	CATCH(CException, pException)
	{
		if (pti)
		{
			if (pattr)
				pti->ReleaseTypeAttr( pattr ) ;
			pti->Release() ;
		}
		if (plibattr)
			ptlb->ReleaseTLibAttr( plibattr ) ;
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;

		THROW_LAST() ;
	}
	END_CATCH

	return hr ;
}

// if typekind == TKIND_ALIAS
//      typedef [attributes] basetype aliasname;
//
// if typekind == TKIND_ENUM
//  typedef [attributes] enum [tag] {
//      enumlist
//  } enumname;
// enumlist is made up of members of the form
//      name = value,
// or "= value" can be ommitted
//
// if typekind == TKIND_UNION or TKIND_RECORD
// typedef [attributes] union/struct [tag] {
//      memberlist
// } union/structname;
//
// attributes can be
//      [uuid(<00026b00-0000-0000-C000-000000000046>), version (<major>.<minor>),
//       helpstring("<helpstring>"), helpcontext(<id), hidden, restricted,
//       public]
//
// memberlist is made up of members of the form
//      type name[bounds];
//
HRESULT CTypeLibODLView::DeCompileTypedef( IStream* pstm, ITypeInfo* pti, UINT uiIndent /* = 0 */ )
{
	HRESULT     hr = S_OK ;
	TYPEATTR*   pattr = NULL ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;

	WRITE1("typedef ") ;

	TRY
	{
		if (FAILED(hr = pti->GetTypeAttr( &pattr)))
			AfxThrowOleException( hr ) ;

		BOOL    fAttributes = FALSE ;      // any attributes?
		BOOL    fAttribute = FALSE ;       // at least one (insert ",")

		// Was 'uuid' specified?
		if (!IsEqualGUID( pattr->guid, GUID_NULL ))
		{
			TCHAR szGUID[64] ;
			StringFromGUID2T( pattr->guid, szGUID, 64, sizeof(szGUID) ) ;
			fAttributes = TRUE ;
			WRITE("[uuid(") ;
			WRITE(szGUID) ;
			WRITE(")") ;
			fAttribute = TRUE ;
		}

		// was version specified
		if (pattr->wMajorVerNum || pattr->wMinorVerNum)
		{
			if (fAttributes == FALSE)
				WRITE("[") ;
			fAttributes = TRUE ;
			if (fAttribute)
				WRITE(", ") ;

			CString str ;
			str.Format(_T("version(%d.%d)"), pattr->wMajorVerNum, pattr->wMinorVerNum) ;
			WRITE(str) ;
			fAttribute = TRUE ;
		}

		if (SUCCEEDED(pti->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
		{
			CString str ;
			if (bstrDoc && *bstrDoc)
			{
				if (fAttributes == FALSE) WRITE("[") ;
				fAttributes = TRUE ;
				if (fAttribute)
					WRITE(", ") ;
				COLE2CT lpszDoc(bstrDoc);
				::SysFreeString(bstrDoc);
				bstrDoc = NULL;

				str.Format( _T("helpstring(\"%s\")"), lpszDoc );
				WRITE( str ) ;
				if (dwHelpID > 0)
				{
					str.Format( _T(", helpcontext(%#08.8x)"), dwHelpID ) ;
					WRITE( str ) ;
				}
			}
			else if (dwHelpID > 0)
			{
				if (fAttributes == FALSE) WRITE("[") ;
				fAttributes = TRUE ;
				if (fAttribute)
					WRITE(", ") ;
				str.Format( _T("helpcontext(%#08.8x)"), dwHelpID ) ;
				WRITE( str ) ;
				fAttribute = TRUE ;
			}
		}

		if (pattr->typekind == TKIND_ALIAS)
		{
			if (fAttributes == FALSE) WRITE("[") ;
			fAttributes = TRUE ;
			if (fAttribute)
				WRITE(", ") ;
			WRITE("public") ;       // if it's in the tlb it had public
		}

		if (fAttributes)
			WRITE("] ") ;

		switch(pattr->typekind)
		{
		case TKIND_RECORD:
			#ifdef _WRITE_TAG
			WRITE("struct tag") ;
			WRITEBSTR(bstrName) ;
			#else
			WRITE("struct ") ;
			#endif
			WRITECR(" {" );
		break ;

		case TKIND_UNION:
			#ifdef _WRITE_TAG
			WRITE("union tag") ;
			WRITEBSTR(bstrName) ;
			#else
			WRITE("union ") ;
			#endif
			WRITECR(" {" );
		break ;

		case TKIND_ALIAS:  //typedef
			// write base type
			WRITE(TYPEDESCtoString( pti, &pattr->tdescAlias )) ;
			WRITE(" ") ;

			// write aliasname
		break ;

		case TKIND_ENUM:
			WRITECR("enum {" );
		break ;

		default:
		ASSERT(0) ;
		break ;
		}

		if (pattr->typekind == TKIND_RECORD || pattr->typekind == TKIND_UNION)
		{
			for (UINT n = 0 ; n < pattr->cVars ; n++)
				DumpVar( pstm, pti, pattr, n, uiIndent + 1 ) ;
			WRITE1("} ");
		}

		if (pattr->typekind == TKIND_ENUM)
		{
			for (int n = 0 ; n < pattr->cVars ; n++)
			{
				DumpConst( pstm, pti, pattr, n, uiIndent + 1, FALSE ) ;
				if (n < pattr->cVars-1)
					WRITECR(",") ;
				else
					WRITECR("") ;
			}
			WRITE1("} ");
		}

		WRITEBSTR(bstrName) ;
		WRITECR(";") ;


		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;

		pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		THROW_LAST();
	}
	END_CATCH
	return hr ;
}

//  [
//    attributes
//  ]
//  module modulename {
//      elementlist
//  };
//  attributes are
//      uuid, version, helpstring, helpcontext, dllname
//      The dllname attribute is required.
//
//  [attributes] returntype [calling convention] funcname(params);
//  [attributes] const constname = constval;
//
HRESULT CTypeLibODLView::DeCompileModule( IStream* pstm, ITypeInfo* pti, UINT uiIndent /* = 0 */ )
{
	HRESULT     hr = S_OK ;
	TYPEATTR*   pattr = NULL ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;

	TRY
	{
		if (FAILED(hr = pti->GetTypeAttr( &pattr)))
			AfxThrowOleException( hr ) ;

		WRITELINE(_T("// BUGBUG:   There appears to be no way to retrieve the dllname of"));
		WRITELINE(_T("//           a module via ITypeInfo in a reliable way. "));
		WRITELINE(_T("//           ITypeInfo::GetDllEntry offers a possibility, but it will"));
		WRITELINE(_T("//           only work if the module has entries in it."));
		WRITELINE(_T("// "));

		WRITELINE(_T("[")) ;
		WRITE1( _T("  dllname(")) ;

		/*
		if (FAILED(hr = pti->GetDllEntry(MEMBERID_NIL, INVOKE_FUNC, &bstrName, NULL, NULL)))
			AfxThrowOleException( hr ) ;

		WRITEBSTR(bstrName) ;
		SysFreeString(bstrName) ;
		bstrName = NULL ;
		*/

		WRITE(_T(")")) ;

		// Was 'uuid' specified?
		if (!IsEqualGUID( pattr->guid, GUID_NULL ))
		{
			TCHAR szGUID[64] ;
			StringFromGUID2T( pattr->guid, szGUID, 64, sizeof(szGUID) ) ;
			WRITECR(",") ;
			WRITE1("  uuid(") ;
			WRITE(szGUID) ;
			WRITE(")") ;
		}

		// was version specified
		if (pattr->wMajorVerNum || pattr->wMinorVerNum)
		{
			WRITECR(",") ;
			CString str ;
			str.Format(_T("  version(%d.%d)"), pattr->wMajorVerNum, pattr->wMinorVerNum) ;
			WRITE1(str) ;
		}

		if (SUCCEEDED(pti->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
		{
			CString str ;
			if (bstrDoc && *bstrDoc)
			{
				WRITECR(",") ;
				COLE2CT lpszDoc(bstrDoc);
				::SysFreeString(bstrDoc);
				bstrDoc = NULL;
				str.Format( _T("  helpstring(\"%s\")"), lpszDoc ) ;
				WRITE1( str ) ;
				if (dwHelpID > 0)
				{
					WRITECR(",") ;
					str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
					WRITE1( str ) ;
				}
			}
			else if (dwHelpID > 0)
			{
				WRITECR(",") ;
				str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
				WRITE1( str ) ;
			}
		}

		WRITECR("") ;
		WRITELINE(_T("]")) ;
		WRITE1(_T("module ")) ;
		WRITEBSTR( bstrName ) ;
		WRITECR( _T(" {")) ;

		int n;
		for (n = 0 ; n < pattr->cFuncs ; n++)
			DumpFunc( pstm, pti, pattr, n, uiIndent + 1 ) ;

		for (n = 0 ; n < pattr->cVars ; n++)
			DumpConst( pstm, pti, pattr, n, uiIndent + 1, TRUE ) ;

		WRITELINE("};") ;


		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;

		pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		THROW_LAST();
	}
	END_CATCH
	return hr ;
}

//  [
//    attributes
//  ]
//  interface interfacename  [:baseinterface] {
//      functionlist
//  };
//
//  attributes include source, default, and restricted
//
HRESULT CTypeLibODLView::DeCompileInterface( IStream* pstm, ITypeInfo* pti, UINT uiIndent /* = 0 */ )
{
	HRESULT     hr = S_OK ;
	TYPEATTR*   pattr = NULL ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;
	ITypeInfo*      ptiImpl = NULL ;

	TRY
	{
		if (FAILED(hr = pti->GetTypeAttr( &pattr)))
			AfxThrowOleException( hr ) ;

		WRITELINE(_T("[")) ;
		WRITE1( _T("  odl")) ;

		TCHAR szGUID[64] ;
		StringFromGUID2T( pattr->guid, szGUID, 64, sizeof(szGUID) ) ;
		WRITECR(",") ;
		WRITE1("  uuid(") ;
		WRITE(szGUID) ;
		WRITE(")") ;

		// was version specified
		if (pattr->wMajorVerNum || pattr->wMinorVerNum)
		{
			WRITECR(",") ;
			CString str ;
			str.Format(_T("  version(%d.%d)"), pattr->wMajorVerNum, pattr->wMinorVerNum) ;
			WRITE1(str) ;
		}

		if (SUCCEEDED(pti->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
		{
			CString str ;
			if (bstrDoc && *bstrDoc)
			{
				WRITECR(",") ;
				COLE2CT lpszDoc(bstrDoc);
				::SysFreeString(bstrDoc);
				bstrDoc = NULL;
				str.Format( _T("  helpstring(\"%s\")"), lpszDoc ) ;
				WRITE1( str ) ;
				if (dwHelpID > 0)
				{
					WRITECR(",") ;
					str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
					WRITE1( str ) ;
				}
			}
			else if (dwHelpID > 0)
			{
				WRITECR(",") ;
				str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
				WRITE1( str ) ;
			}
		}

		// source, default, or restricted
		if (pattr->wTypeFlags == TYPEFLAG_FHIDDEN)
		{
			WRITECR(",") ;
			WRITE1("  hidden") ;
		}

	/*
		int    implflags = NULL ;
		if (FAILED(hr = pti->GetImplTypeFlags(0, &implflags )))
			AfxThrowOleException(hr) ;

		if (implflags & IMPLTYPEFLAG_FDEFAULT)
		{
			WRITECR(",") ;
			WRITE1("  default") ;
		}

		if (implflags & IMPLTYPEFLAG_FSOURCE)
		{
			WRITECR(",") ;
			WRITE1("  source") ;
		}

		if (implflags & IMPLTYPEFLAG_FRESTRICTED)
		{
			WRITECR(",") ;
			WRITE1("  restricted") ;
		}
	 */

		WRITECR("") ;
		WRITELINE(_T("]")) ;
		WRITE1(_T("interface ")) ;
		// interface name
		WRITEBSTR( bstrName ) ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		bstrName = bstrDoc = bstrHelp = NULL ;

		// is there a base interface?
		UINT n;
		for (n = 0 ; n <  pattr->cImplTypes; n++)
		{
			HREFTYPE href = NULL ;
			if (FAILED(hr = pti->GetRefTypeOfImplType(n, &href)))
				AfxThrowOleException(hr) ;

			if (FAILED(hr = pti->GetRefTypeInfo( href, &ptiImpl )))
				AfxThrowOleException(hr) ;

			if (FAILED(hr = ptiImpl->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
				AfxThrowOleException(hr) ;

			WRITE(_T(" : ")) ;
			WRITEBSTR( bstrName ) ;

			SysFreeString( bstrName ) ;
			bstrName = NULL ;
			SysFreeString( bstrDoc ) ;
			bstrDoc = NULL ;
			SysFreeString( bstrHelp ) ;
			bstrHelp = NULL ;

			ptiImpl->Release() ;
			ptiImpl = NULL ;
		}

		WRITECR(_T(" {")) ;

		for (n = 0 ; n < pattr->cFuncs ; n++)
			DumpFunc( pstm, pti, pattr, n, uiIndent + 1 ) ;

		WRITELINE("};") ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;

		pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		if (ptiImpl)
			ptiImpl->Release() ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		THROW_LAST();
	}
	END_CATCH
	return hr ;
}


//  Syntax 1
//
//  [
//    attributes
//  ]
//  dispinterface intfname {
//      properties:
//          proplist
//      methods:
//          methlist
//  };
//
//  Syntax 2
//
//  [
//    attributes
//  ]
//  dispinterface intfname {
//      interface interfacename
//  };
//
HRESULT CTypeLibODLView::DeCompileDispinterface( IStream* pstm, ITypeInfo* pti, UINT uiIndent /* = 0 */ )
{
	HRESULT     hr = S_OK ;
	TYPEATTR*   pattr = NULL ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;
	ITypeInfo*      ptiImpl = NULL ;

	TRY
	{
		if (FAILED(hr = pti->GetTypeAttr( &pattr)))
			AfxThrowOleException( hr ) ;

		WRITELINE(_T("[")) ;

		TCHAR szGUID[64] ;
		StringFromGUID2T( pattr->guid, szGUID, 64, sizeof(szGUID) ) ;
		WRITE1("  uuid(") ;
		WRITE(szGUID) ;
		WRITE(")") ;

		// was version specified
		if (pattr->wMajorVerNum || pattr->wMinorVerNum)
		{
			WRITECR(",") ;
			CString str ;
			str.Format(_T("  version(%d.%d)"), pattr->wMajorVerNum, pattr->wMinorVerNum) ;
			WRITE1(str) ;
		}

		if (SUCCEEDED(pti->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
		{
			CString str ;
			if (bstrDoc && *bstrDoc)
			{
				WRITECR(",") ;
				COLE2CT lpszDoc(bstrDoc);
				::SysFreeString(bstrDoc);
				bstrDoc = NULL;
				str.Format( _T("  helpstring(\"%s\")"), lpszDoc ) ;
				WRITE1( str ) ;
				if (dwHelpID > 0)
				{
					WRITECR(",") ;
					str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
					WRITE1( str ) ;
				}
			}
			else if (dwHelpID > 0)
			{
				WRITECR(",") ;
				str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
				WRITE1( str ) ;
			}
		}

		// source, default, or restricted
		if (pattr->wTypeFlags == TYPEFLAG_FHIDDEN)
		{
			WRITECR(",") ;
			WRITE1("  hidden") ;
		}

		if (pattr->wTypeFlags == TYPEFLAG_FDUAL)
		{
			WRITECR(",") ;
			WRITE1("  dual") ;
		}

		WRITECR("") ;
		WRITELINE(_T("]")) ;
		WRITE1(_T("dispinterface ")) ;
		// interface name
		WRITEBSTR( bstrName ) ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		bstrName = bstrDoc = bstrHelp = NULL ;

		WRITECR(_T(" {")) ;

		WRITELINE2(_T("properties:"), 1) ;
		UINT n;
		for (n = 0 ; n < pattr->cVars ; n++)
			DumpVar( pstm, pti, pattr, n, uiIndent + 2 ) ;

		WRITELINE2(_T("methods:"), 1) ;
		for (n = 0 ; n < pattr->cFuncs ; n++)
			DumpFunc( pstm, pti, pattr, n, uiIndent + 2 ) ;

		WRITELINE("};") ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;

		pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		if (ptiImpl)
			ptiImpl->Release() ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;
	}
	END_CATCH
	return hr ;
}

//  [
//    attributes
//  ]
//  coclass classname {
//      [attributes2] [interface | dispinterface] interfacename;
//      ...
//  };
//
//  attributes
//      uuid, helpstring, helpcontext, licensed, version, and appobject
//
HRESULT CTypeLibODLView::DeCompileCoClass( IStream* pstm, ITypeInfo* pti, UINT uiIndent /* = 0 */ )
{
	HRESULT     hr = S_OK ;
	TYPEATTR*   pattr = NULL ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;
	ITypeInfo*      ptiImpl = NULL ;
	TYPEATTR*       pattrImpl = NULL ;

	TRY
	{
		if (FAILED(hr = pti->GetTypeAttr( &pattr)))
			AfxThrowOleException( hr ) ;

		WRITELINE(_T("[")) ;

		TCHAR szGUID[64] ;
		StringFromGUID2T( pattr->guid, szGUID, 64, sizeof(szGUID) ) ;
		WRITE1("  uuid(") ;
		WRITE(szGUID) ;
		WRITE(")") ;

		// was version specified
		if (pattr->wMajorVerNum || pattr->wMinorVerNum)
		{
			WRITECR(",") ;
			CString str ;
			str.Format(_T("  version(%d.%d)"), pattr->wMajorVerNum, pattr->wMinorVerNum) ;
			WRITE1(str) ;
		}

		if (SUCCEEDED(pti->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
		{
			CString str ;
			if (bstrDoc && *bstrDoc)
			{
				WRITECR(",") ;
				COLE2CT lpszDoc(bstrDoc);
				::SysFreeString(bstrDoc);
				bstrDoc = NULL;
				str.Format( _T("  helpstring(\"%s\")"), lpszDoc ) ;
				WRITE1( str ) ;
				if (dwHelpID > 0)
				{
					WRITECR(",") ;
					str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
					WRITE1( str ) ;
				}
			}
			else if (dwHelpID > 0)
			{
				WRITECR(",") ;
				str.Format( _T("  helpcontext(%#08.8x)"), dwHelpID ) ;
				WRITE1( str ) ;
			}
		}

		if (pattr->wTypeFlags == TYPEFLAG_FAPPOBJECT)
		{
			WRITECR(",") ;
			WRITE1("  appobject") ;
		}
		if (pattr->wTypeFlags == TYPEFLAG_FHIDDEN)
		{
			WRITECR(",") ;
			WRITE1("  hidden") ;
		}
		if (pattr->wTypeFlags == TYPEFLAG_FLICENSED)
		{
			WRITECR(",") ;
			WRITE1("  licensed") ;
		}
		if (pattr->wTypeFlags == TYPEFLAG_FCONTROL)
		{
			WRITECR(",") ;
			WRITE1("  control") ;
		}

		WRITECR("") ;
		WRITELINE(_T("]")) ;
		WRITE1(_T("coclass ")) ;
		// coclass name
		WRITEBSTR( bstrName ) ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		bstrName = bstrDoc = bstrHelp = NULL ;

		WRITECR(_T(" {")) ;

		//  [attributes2] [interface | dispinterface] interfacename;
		for (UINT n = 0 ; n < pattr->cImplTypes ; n++)
		{
			HREFTYPE href = NULL ;

			int impltype = NULL ;
			if (FAILED(hr = pti->GetImplTypeFlags( n, &impltype )))
				AfxThrowOleException(hr) ;

			if (FAILED(hr = pti->GetRefTypeOfImplType(n, &href)))
				AfxThrowOleException(hr) ;

			if (FAILED(hr = pti->GetRefTypeInfo( href, &ptiImpl )))
				AfxThrowOleException(hr) ;

			if (FAILED(hr = ptiImpl->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
				AfxThrowOleException(hr) ;

			if (FAILED(hr = ptiImpl->GetTypeAttr( &pattrImpl)))
				AfxThrowOleException( hr ) ;

			WRITE2(_T(""), 1 ) ;

			if (impltype)
			{
				WRITE(_T("[")) ;
				BOOL    fComma = FALSE ;
				if (impltype & IMPLTYPEFLAG_FDEFAULT)
				{
					WRITE(_T("default")) ;
					fComma = TRUE ;
				}
				if (impltype & IMPLTYPEFLAG_FSOURCE)
				{
					if (fComma)
						WRITE(_T(", ")) ;
					WRITE(_T("source")) ;
					fComma = TRUE ;
				}
				if (impltype & IMPLTYPEFLAG_FRESTRICTED)
				{
					if (fComma)
						WRITE(_T(", ")) ;
					WRITE(_T("restricted")) ;
				}

				WRITE(_T("] "));
			}

			if (pattrImpl->typekind == TKIND_INTERFACE)
				WRITE(_T("interface ")) ;

			if (pattrImpl->typekind == TKIND_DISPATCH)
				WRITE(_T("dispinterface ")) ;

			WRITE( bstrName ) ;

			WRITECR(_T(";")) ;

			SysFreeString( bstrName ) ;
			bstrName = NULL ;
			SysFreeString( bstrDoc ) ;
			bstrDoc = NULL ;
			SysFreeString( bstrHelp ) ;
			bstrHelp = NULL ;

			ptiImpl->ReleaseTypeAttr( pattrImpl ) ;
			pattrImpl = NULL ;

			ptiImpl->Release() ;
			ptiImpl = NULL ;
		}

		WRITELINE("};") ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;

		pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		if (ptiImpl)
		{
			if (pattrImpl)
				ptiImpl->ReleaseTypeAttr( pattrImpl ) ;

			ptiImpl->Release() ;
		}
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		THROW_LAST();
	}
	END_CATCH
	return hr ;

}

HRESULT CTypeLibODLView::DeCompileFunc( IStream* pstm, ITypeInfo* pti, MEMBERID memid, UINT uiIndent /* = 0 */ )
{
	HRESULT     hr = S_OK ;
	TYPEATTR*   pattr = NULL ;
	ASSERT(pti) ;

	TRY
	{
		ENSURE(pti);
		if (FAILED(hr = pti->GetTypeAttr( &pattr)))
			AfxThrowOleException( hr ) ;

		if (FAILED(hr = DumpFunc( pstm, pti, pattr, memid, uiIndent )))
			AfxThrowOleException( hr ) ;

		pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		THROW_LAST();
	}
	END_CATCH

	return hr ;
}

HRESULT CTypeLibODLView::DumpFunc( IStream* pstm, ITypeInfo* pti, TYPEATTR* pattr, MEMBERID memid, UINT uiIndent /* = 0 */ )
{
	HRESULT     hr = S_OK ;
	FUNCDESC*   pfuncdesc = NULL ;
	BSTR            rgbstrNames[MAX_NAMES] ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;
	ASSERT(pti) ;

	for (UINT ui = 0 ; ui < MAX_NAMES ; ui++)
		rgbstrNames[ui] = NULL ;

	TRY
	{
		ENSURE(pti);
		if (FAILED(hr = pti->GetFuncDesc( memid, &pfuncdesc )))
			AfxThrowOleException( hr ) ;

		// If pattr->typekind == TKIND_DISPATCH (dispinterface)
		//    [attributes] returntype methname(params);
		// where attributes can be
		//      id(<id>), propput, propget,
		//      propputref, bindable, defaultbind, displaybind,
		//      requestedit, source, vararg, hidden, helpstring("<helpstring>"),
		//      helpcontext(<id>)
		//
		// If pattr->typekind == TKIND_INTERFACE || TKIND_MODULE
		//  [attributes] returntype [calling convention]  funcname(params);
		// where attributes can be
		//      restricted, bindable, defaultbind, displaybind,
		//      requestedit, source, vararg, hidden, helpstring("<helpstring>"),
		//      helpcontext(<id>)
		// and calling convention can be
		//      pascal, cdecl, stdcall
		//
		// Write [attributes]
		//
		BOOL    fAttributes = FALSE ;      // any attributes?
		BOOL    fAttribute = FALSE ;       // at least one (insert ",")
		WRITE1("") ;    // indent
		CString str ;
		if (pattr->typekind == TKIND_DISPATCH)
		{
			fAttributes = TRUE ;
			fAttribute = TRUE ;
			str.Format(_T("[id(%d)"), memid) ;
			WRITE(str) ;
		}
		else if (pattr->typekind == TKIND_MODULE)
		{
			fAttributes = TRUE ;
			fAttribute = TRUE ;
			str.Format(_T("[entry(%d)"), memid) ;
			WRITE(str) ;
		}
		else
			// if there are some attributes
			if ((pfuncdesc->invkind > 1)|| pfuncdesc->wFuncFlags || pfuncdesc->cParamsOpt == -1)
			{
				WRITE("[") ;
				fAttributes = TRUE ;
			}

		if (pfuncdesc->invkind & INVOKE_PROPERTYGET)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("propget") ;
		}
		if (pfuncdesc->invkind & INVOKE_PROPERTYPUT)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("propput") ;
		}
		if (pfuncdesc->invkind & INVOKE_PROPERTYPUTREF)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("propputref") ;
		}
		if (pfuncdesc->wFuncFlags & FUNCFLAG_FRESTRICTED)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("restricted") ;
		}
		if (pfuncdesc->wFuncFlags & FUNCFLAG_FSOURCE)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("source") ;
		}
		if (pfuncdesc->wFuncFlags & FUNCFLAG_FBINDABLE)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("bindable") ;
		}
		if (pfuncdesc->wFuncFlags & FUNCFLAG_FREQUESTEDIT)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("requestedit") ;
		}
		if (pfuncdesc->wFuncFlags & FUNCFLAG_FDISPLAYBIND)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("displaybind") ;
		}
		if (pfuncdesc->wFuncFlags & FUNCFLAG_FDEFAULTBIND)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("defaultbind") ;
		}
		if (pfuncdesc->wFuncFlags & FUNCFLAG_FHIDDEN)
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("hidden") ;
		}
		if (pfuncdesc->cParamsOpt == -1)    // cParamsOpt > 0 indicates VARIANT style
		{
			if (fAttribute)
				WRITE(", ") ;
			fAttribute = TRUE ;
			WRITE("vararg") ;         // optional params
		}

		if (SUCCEEDED(pti->GetDocumentation( pfuncdesc->memid, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
		{
			if (bstrDoc && *bstrDoc)
			{
				if (fAttributes == FALSE) WRITE("[") ;
				fAttributes = TRUE ;
				if (fAttribute)
					WRITE(", ") ;
				COLE2CT lpszDoc(bstrDoc);
				::SysFreeString(bstrDoc);
				bstrDoc = NULL;
				str.Format( _T("helpstring(\"%s\")"), lpszDoc ) ;
				WRITE( str ) ;
				if (dwHelpID > 0)
				{
					str.Format( _T(", helpcontext(%#08.8x)"), dwHelpID ) ;
					WRITE( str ) ;
				}
			}
			else if (dwHelpID > 0)
			{
				if (fAttributes == FALSE) WRITE("[") ;
				if (fAttribute)
					WRITE(", ") ;
				fAttributes = TRUE ;
				str.Format( _T("helpcontext(%#08.8x)"), dwHelpID ) ;
				WRITE( str ) ;
			}
		}
		if (fAttributes)
			WRITE("] ") ;

		// Write return type
		WRITE(TYPEDESCtoString( pti, &pfuncdesc->elemdescFunc.tdesc )) ;
		WRITE(" ") ;

		if (pattr->typekind != TKIND_DISPATCH)
		{   // Write calling convention
			switch(pfuncdesc->callconv)
			{
				case CC_CDECL:      WRITE("_cdecl ") ;           break ;
				//case CC_MSCPASCAL:  WRITE("_mspascal ") ;        break ;
				case CC_PASCAL:     WRITE("_pascal ") ;          break ;
				case CC_MACPASCAL:  WRITE("_macpascal ") ;       break ;
				case CC_STDCALL :   WRITE("_stdcall ") ;          break ;
				//case CC_RESERVED:   WRITE("_reserved ") ;         break ;
				case CC_SYSCALL:    WRITE("_syscall ") ;          break ;
				case CC_MPWCDECL:   WRITE("_mpwcdecl ") ;         break ;
				case CC_MPWPASCAL:  WRITE("_mpwpascal ") ;        break ;
			}
		}

		// Write methodname

		// Problem:  If a property has the propput or propputref attributes the
		// 'right hand side' (rhs) is *always* the last parameter and MkTypeLib
		// strips the parameter name.  Thus you will always get 1 less name
		// back from ::GetNames than normal.
		//
		// Thus for the example below
		//  [propput] void Color([in] VARIANT rgb, [in] VARIANT rgb2 );
		// without taking this into consderation the output would be
		//  [propput] void Color([in] VARIANT rgb, [in] VARIANT );
		// when it should be
		//  [propput] void Color([in] VARIANT rgb, [in] VARIANT rhs );
		//
		// Another weirdness comes from a bug (which will never be fixed)
		// where optional parameters on property functions were allowed.
		// Because they were allowed by accident people used them, so they
		// are still allowed.
		//

		UINT cNames = 0 ;
		if (FAILED( hr = pti->GetNames( pfuncdesc->memid, rgbstrNames, MAX_NAMES, &cNames )))
			AfxThrowOleException( hr ) ;

		// fix for 'rhs' problem
		if ((int)cNames < pfuncdesc->cParams + 1)
		{
			rgbstrNames[cNames] = ::SysAllocString(OLESTR("rhs")) ;
			cNames++ ;
		}

		ASSERT((int)cNames == pfuncdesc->cParams+1) ;
		WRITEBSTR( rgbstrNames[0] ) ;
		WRITE("(") ;

		// params have the format
		//   [attributes] type paramname
		// where attributes can be
		//   in, out, optional, string   (string is not valid for TKIND_MODULE)
		//
		if (pfuncdesc->cParams > 1)
			WRITECR("") ;
		for ( int n = 0 ; n < pfuncdesc->cParams ; n++ )
		{
			if (pfuncdesc->cParams > 1)
				WRITE2("", 4 ) ;    // indent 4
			fAttributes = FALSE ;
			fAttribute = FALSE ;

			if (pfuncdesc->lprgelemdescParam[n].idldesc.wIDLFlags)
			{
				WRITE("[") ;
				fAttributes = TRUE ;
			}

			if (pfuncdesc->lprgelemdescParam[n].idldesc.wIDLFlags & IDLFLAG_FIN)
			{
				if (fAttribute)
					WRITE(", ") ;
				WRITE("in") ;
				fAttribute = TRUE ;
			}
			if (pfuncdesc->lprgelemdescParam[n].idldesc.wIDLFlags & IDLFLAG_FOUT)
			{
				if (fAttribute)
					WRITE(", ") ;
				WRITE("out") ;
				fAttribute = TRUE ;
			}
			if (pfuncdesc->lprgelemdescParam[n].idldesc.wIDLFlags & IDLFLAG_FLCID)
			{
				if (fAttribute)
					WRITE(", ") ;
				WRITE("lcid") ;
				fAttribute = TRUE ;
			}
			if (pfuncdesc->lprgelemdescParam[n].idldesc.wIDLFlags & IDLFLAG_FRETVAL)
			{
				if (fAttribute)
					WRITE(", ") ;
				WRITE("retval") ;
				fAttribute = TRUE ;
			}

			// If we have an optional last parameter and we're on the last paramter
			// or we are into the optional parameters...
			if ((pfuncdesc->cParamsOpt == -1 && n == pfuncdesc->cParams - 1) ||
				(n > (pfuncdesc->cParams - pfuncdesc->cParamsOpt)))
			{
				if (fAttribute)
					WRITE(", ") ;
				if (!fAttributes)
					WRITE("[") ;
				WRITE("optional") ;
				fAttributes = TRUE ;
				fAttribute = TRUE ;
			}

			if (fAttributes)
				WRITE("] ") ;

			// type
			if ((pfuncdesc->lprgelemdescParam[n].tdesc.vt & 0x0FFF) == VT_CARRAY)
			{
				// type name[n]
				WRITE(TYPEDESCtoString( pti, &pfuncdesc->lprgelemdescParam[n].tdesc.lpadesc->tdescElem )) ;
				WRITE(" ") ;

				WRITEBSTR(rgbstrNames[n+1]) ;

				// Allocate cDims * lstrlen("[123456]")
				for (USHORT n1 = 0 ; n1 < pfuncdesc->lprgelemdescParam[n1].tdesc.lpadesc->cDims ; n1++)
				{
					str.Format( _T("[%d]"), pfuncdesc->lprgelemdescParam[n1].tdesc.lpadesc->rgbounds[n1].cElements ) ;
					WRITE(str) ;
				}
			}
			else
			{
				WRITE(TYPEDESCtoString( pti, &pfuncdesc->lprgelemdescParam[n].tdesc ) + " " ) ;
				WRITEBSTR(rgbstrNames[n+1]) ;
			}
			if (n < pfuncdesc->cParams - 1)
				WRITECR(", ") ;
		}

		WRITECR(");") ;

		for (UINT ui = 0 ; ui < MAX_NAMES ; ui++)
			if (rgbstrNames[ui])
				SysFreeString(rgbstrNames[ui]) ;
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;

		pti->ReleaseFuncDesc( pfuncdesc ) ;
	}
	CATCH(CException, pException)
	{
		for (UINT ui = 0 ; ui < MAX_NAMES ; ui++)
			if (rgbstrNames[ui])
				SysFreeString(rgbstrNames[ui]) ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		if (pfuncdesc)
			pti->ReleaseFuncDesc( pfuncdesc ) ;

		THROW_LAST();
	}
	END_CATCH

	return hr ;
}

HRESULT CTypeLibODLView::DeCompileVar( IStream* pstm, ITypeInfo* pti, MEMBERID memid, UINT uiIndent /* = 0 */)
{
	HRESULT     hr = S_OK ;
	TYPEATTR*   pattr = NULL ;
	ASSERT(pti) ;

	TRY
	{
		ENSURE(pti);
		if (FAILED(hr = pti->GetTypeAttr( &pattr)))
			AfxThrowOleException( hr ) ;

		if (FAILED(hr = DumpVar( pstm, pti, pattr, memid, uiIndent )))
			AfxThrowOleException( hr ) ;

		pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		THROW_LAST();
	}
	END_CATCH

	return hr ;
}

HRESULT CTypeLibODLView::DumpVar( IStream* pstm, ITypeInfo* pti, TYPEATTR* pattr, MEMBERID memid, UINT uiIndent /* = 0 */)
{
	HRESULT     hr = S_OK ;
	VARDESC*    pvardesc = NULL ;
	BSTR            rgbstrNames[1] ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;
	ASSERT(pti) ;

	TRY
	{
		ENSURE(pti);
		if (FAILED(hr = pti->GetVarDesc( memid, &pvardesc )))
			AfxThrowOleException( hr ) ;

		ASSERT(pvardesc->varkind != VAR_CONST) ;    // must not be a const

		// If pattr->typekind == TKIND_RECORD (struct) || TKIND_UNION
		//    type name[array];
		//
		// If pattr->typekind == TKIND_DISPATCH (dispinterface)
		//    [id(<id>), bindable, defaultbind, displaybind, readonly,
		//      requestedit, source, hidden, helpstring("<helpstring>"),
		//      helpcontext(<id>)] type name;
		//
		BOOL    fAttributes = FALSE ;
		WRITE1("") ;    // indent
		if (pattr->typekind == TKIND_DISPATCH)
		{
			CString str ;
			fAttributes = TRUE ;
			str.Format(_T("[id(%d)"), memid) ;
			WRITE(str) ;

			if (pvardesc->wVarFlags & VARFLAG_FREADONLY)
				WRITE(", readonly") ;
			if (pvardesc->wVarFlags & VARFLAG_FSOURCE)
				WRITE(", source") ;
			if (pvardesc->wVarFlags & VARFLAG_FBINDABLE)
				WRITE(", bindable") ;
			if (pvardesc->wVarFlags & VARFLAG_FREQUESTEDIT)
				WRITE(", requestedit") ;
			if (pvardesc->wVarFlags & VARFLAG_FDISPLAYBIND)
				WRITE(", displaybind") ;
			if (pvardesc->wVarFlags & VARFLAG_FDEFAULTBIND)
				WRITE(", defaultbind") ;
			if (pvardesc->wVarFlags & VARFLAG_FHIDDEN)
				WRITE(", hidden") ;
		}

		if (SUCCEEDED(pti->GetDocumentation( pvardesc->memid, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
		{
			CString str ;
			if (bstrDoc && *bstrDoc)
			{
				if (fAttributes == FALSE)
					WRITE("[") ;
				else
					WRITE(", ") ;
				fAttributes = TRUE ;
				COLE2CT lpszDoc(bstrDoc);
				::SysFreeString(bstrDoc);
				bstrDoc = NULL;
				str.Format( _T("helpstring(\"%s\")"), lpszDoc ) ;
				WRITE( str ) ;
				if (dwHelpID > 0)
				{
					str.Format( _T(", helpcontext(%#08.8x)"), dwHelpID ) ;
					WRITE( str ) ;
				}
			}
			else if (dwHelpID > 0)
			{
				if (fAttributes == FALSE)
					WRITE("[") ;
				else
					WRITE(", ") ;
				fAttributes = TRUE ;
				str.Format( _T("helpcontext(%#08.8x)"), dwHelpID ) ;
				WRITE( str ) ;
			}
		}

		if (fAttributes)
			WRITE("] ") ;
		UINT cNames ;
		if (FAILED( hr = pti->GetNames( pvardesc->memid, rgbstrNames, 1, (UINT FAR*)&cNames )))
			AfxThrowOleException( hr ) ;

		CString str ;
		if ((pvardesc->elemdescVar.tdesc.vt & 0x0FFF) == VT_CARRAY)
		{
			// type name[n]
			WRITE(TYPEDESCtoString( pti, &pvardesc->elemdescVar.tdesc.lpadesc->tdescElem )) ;
			WRITE(" ") ;
			if (rgbstrNames[0])
				WRITEBSTR(rgbstrNames[0]);
			else
				WRITE(_T("(nameless)")) ;
			// Allocate cDims * lstrlen("[123456]")
			for (USHORT n = 0 ; n < pvardesc->elemdescVar.tdesc.lpadesc->cDims ; n++)
			{
				str.Format( _T("[%d]"), pvardesc->elemdescVar.tdesc.lpadesc->rgbounds[n].cElements ) ;
				WRITE(str) ;
			}
		}
		else
		{
			WRITE(TYPEDESCtoString( pti, &pvardesc->elemdescVar.tdesc ) + _T(" "));
			if (rgbstrNames[0])
				WRITEBSTR(rgbstrNames[0]);
			else
				WRITE(_T("(nameless)")) ;
		}
		WRITECR(";") ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;

		pti->ReleaseVarDesc( pvardesc ) ;
	}
	CATCH(CException, pException)
	{
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		if (pvardesc)
			pti->ReleaseVarDesc( pvardesc ) ;

		THROW_LAST();
	}
	END_CATCH

	return hr ;
}

// if fConst ==  TURE
//  const type name = value ;
// else
//  name = value  (no commas)
//
HRESULT CTypeLibODLView::DeCompileConst( IStream* pstm, ITypeInfo* pti, MEMBERID memid, UINT uiIndent /* = 0 */, BOOL fConst /* = TRUE */  )
{
	HRESULT     hr = S_OK ;
	TYPEATTR*       pattr = NULL ;
	ASSERT(pti) ;

	TRY
	{
		ENSURE(pti);
		if (FAILED(hr = pti->GetTypeAttr( &pattr)))
			AfxThrowOleException( hr ) ;

		if (FAILED(hr = DumpConst( pstm, pti, pattr, memid, uiIndent, fConst )))
			AfxThrowOleException( hr ) ;

		pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;
		THROW_LAST();
	}
	END_CATCH

	return hr ;
}

HRESULT CTypeLibODLView::DumpConst( IStream* pstm, ITypeInfo* pti, TYPEATTR* pattr, MEMBERID memid, UINT uiIndent /* = 0 */, BOOL fConst /* = TRUE */  )
{
	HRESULT     hr = S_OK ;
	VARDESC*    pvardesc = NULL ;
	BSTR            rgbstrNames[1] ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;
	ASSERT(pti) ;
	VARIANT varValue ;
	VariantInit( &varValue ) ;

	TRY
	{
		ENSURE(pti);
		if (FAILED(hr = pti->GetVarDesc( memid, &pvardesc )))
			AfxThrowOleException( hr ) ;

		ASSERT(pvardesc->varkind == VAR_CONST) ;

		CString str = TYPEDESCtoString( pti, &pvardesc->elemdescVar.tdesc ) ;
		if (FAILED(hr = VariantChangeType( &varValue, pvardesc->lpvarValue, 0, VT_BSTR )))
		{
			if (pvardesc->lpvarValue->vt == VT_ERROR || pvardesc->lpvarValue->vt == VT_HRESULT)
			{
				varValue.vt = VT_BSTR ;
				varValue.bstrVal = ::SysAllocString(CT2OLE(_GetScodeString(pvardesc->lpvarValue->scode))) ;
				hr = S_OK ;
			}
			else
				AfxThrowOleException( hr ) ;
		}

		BOOL fIndent = FALSE ;
		if (fConst)
		{
			if (pattr->typekind == TKIND_MODULE)
			{
				str.Format(_T("[entry(%d)"), memid) ;
				WRITE1(str) ;
				fIndent = TRUE ;
			}

			// [helpstring("<helpstring>"), helpcontext(<id>)] const type name = expression ;
			if (SUCCEEDED(pti->GetDocumentation( pvardesc->memid, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp )))
			{
				if (bstrDoc && *bstrDoc)
				{
					if (!fIndent)
						WRITE1("[") ;
					else
						WRITE(", ") ;
					COLE2CT lpszDoc(bstrDoc);
					::SysFreeString(bstrDoc);
					bstrDoc = NULL;
					str.Format( _T("helpstring(\"%s\")"), lpszDoc ) ;
					WRITE( str ) ;
					if (dwHelpID > 0)
					{
						str.Format( _T(", helpcontext(%#08.8x)"), dwHelpID ) ;
						WRITE( str ) ;
					}
					WRITE("] ");
					fIndent = TRUE ;
				}
				else if (dwHelpID > 0)
				{
					if (!fIndent)
						WRITE1("[") ;
					else
						WRITE(", ") ;
					str.Format( _T("helpcontext(%#08.8x)] "), dwHelpID ) ;
					WRITE( str ) ;
					fIndent = TRUE ;
				}
			}
		}

		UINT cNames ;
		if (FAILED( hr = pti->GetNames( pvardesc->memid, rgbstrNames, 1, (UINT FAR*)&cNames )))
			AfxThrowOleException( hr ) ;

		if (fConst)
		{
			if (!fIndent)
				WRITE1(_T("")) ;
			WRITE("const ") ; WRITE( str ) ; WRITE( " " ) ;
		}
		else
			WRITE1("") ;

		WRITEBSTR( rgbstrNames[0] ) ; WRITE( " = " ) ;

		if (pvardesc->lpvarValue->vt == VT_BSTR)
		{
			WRITE( "\"" ) ;
			WRITEBSTR( varValue.bstrVal ) ;
			WRITE( "\"" ) ;
		}
		else
			WRITEBSTR( varValue.bstrVal) ;

		if (fConst)
			WRITECR(";") ;

		VariantClear( &varValue ) ;

		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		pti->ReleaseVarDesc( pvardesc ) ;
	}
	CATCH(CException, pException)
	{
		VariantClear( &varValue ) ;
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		if (pvardesc)
			pti->ReleaseVarDesc( pvardesc ) ;

		THROW_LAST();
	}
	END_CATCH

	return hr ;
}

IStream* CreateMemoryStream()
{
	LPSTREAM lpStream = NULL;

	// Create a stream object on a memory block.
	HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE|GMEM_SHARE, 0);
	if (hGlobal != NULL)
	{
		HRESULT hr ;
		if (FAILED(hr = CreateStreamOnHGlobal(hGlobal, TRUE, &lpStream)))
		{
			TRACE0("CreateStreamOnHGlobal failed.\n");
			GlobalFree(hGlobal);
			AfxThrowOleException( hr ) ;
		}
	}
	else
	{
		#pragma warning (suppress: 6255)
		TRACE0("Failed to allocate memory for stream.\n");
		AfxThrowMemoryException() ;
	}

	return lpStream;
}

int StringFromGUID2T(REFGUID rguid, LPTSTR lpszGUID, int nSize, int cbMax )
{
	OLECHAR* lpszOle = (OLECHAR*)_malloca(cbMax*sizeof(OLECHAR));
	int nCount = ::StringFromGUID2(rguid,lpszOle, cbMax*sizeof(OLECHAR));
	if (nCount == 0)
	{
		lpszGUID[0] = '\0';
		_freea(lpszOle);
		
		return 0; // buffer too small for the returned string
	}
	COLE2T lpszRes(lpszOle);
	_tcscpy_s(lpszGUID, nSize, lpszRes);
	_freea(lpszOle);
	return 0;
}
