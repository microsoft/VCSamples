// tree.cpp
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
#include "tree.h"
#include "util.h"

#define MAX_NAMES   64

IMPLEMENT_DYNCREATE(CTreeItem, CObject)
CTreeItem::CTreeItem(CTreeCtrl* pTree )
{
	ASSERT(pTree) ;
	m_pTree = pTree ;
	m_punk = NULL ;
	m_Type = typeUnknown ;
	m_uiMemid = 0 ;
}

CTreeItem::~CTreeItem()
{
	if (m_punk )
		m_punk->Release()  ;
}

BOOL CTreeItem::Expand( HTREEITEM hitem )
{
	BOOL fExpand = FALSE ;

	switch(m_Type)
	{
	case typeUnknown:
	case typeUnknown2:
	break ;

	case typeTypeLib:
		fExpand = ExpandTypeLib( hitem );
	break ;

	case typeTypeLib2:
	{
		// CTypeLibWnd::m_fGroupByType == TRUE
		CTreeItem* pItem ;

		TV_INSERTSTRUCT tvis ;
		tvis.hParent = hitem ;
		tvis.hInsertAfter = TVI_LAST ;
		tvis.item.mask = TVIF_TEXT | TVIF_CHILDREN | TVIF_PARAM | TVIF_IMAGE | TVIF_SELECTEDIMAGE ;
		tvis.item.iImage = CTreeItem::typeUnknown ;
		tvis.item.iSelectedImage = tvis.item.iImage + 1 ;
		tvis.item.cChildren = 1 ;

		#pragma warning (suppress: 6211) // Not Leaking. pItem is inserted into m_pTree
		pItem = new CTreeItem(m_pTree) ;
		pItem->SetTypeLib( GetTypeLib() ) ;
		GetTypeLib()->AddRef() ;
		pItem->m_Type = CTreeItem::typeEnums ;
		tvis.item.lParam = (LPARAM)pItem ;
		tvis.item.pszText = _T("Enums") ;
		m_pTree->InsertItem(&tvis) ;

		pItem = new CTreeItem(m_pTree) ;
		pItem->SetTypeLib( GetTypeLib() ) ;
		GetTypeLib()->AddRef() ;
		pItem->m_Type = CTreeItem::typeRecords ;
		tvis.item.lParam = (LPARAM)pItem ;
		tvis.item.pszText = _T("Structs") ;
		m_pTree->InsertItem(&tvis) ;

		pItem = new CTreeItem(m_pTree) ;
		pItem->SetTypeLib( GetTypeLib() ) ;
		GetTypeLib()->AddRef() ;
		pItem->m_Type = CTreeItem::typeModules ;
		tvis.item.lParam = (LPARAM)pItem ;
		tvis.item.pszText = _T("Modules") ;
		m_pTree->InsertItem(&tvis) ;

		pItem = new CTreeItem(m_pTree) ;
		pItem->SetTypeLib( GetTypeLib() ) ;
		GetTypeLib()->AddRef() ;
		pItem->m_Type = CTreeItem::typeInterfaces ;
		tvis.item.lParam = (LPARAM)pItem ;
		tvis.item.pszText = _T("Interfaces") ;
		m_pTree->InsertItem(&tvis) ;

		pItem = new CTreeItem(m_pTree) ;
		pItem->SetTypeLib( GetTypeLib() ) ;
		GetTypeLib()->AddRef() ;
		pItem->m_Type = CTreeItem::typeDispinterfaces ;
		tvis.item.lParam = (LPARAM)pItem ;
		tvis.item.pszText = _T("Dispinterfaces") ;
		m_pTree->InsertItem(&tvis) ;

		pItem = new CTreeItem(m_pTree) ;
		pItem->SetTypeLib( GetTypeLib() ) ;
		GetTypeLib()->AddRef() ;
		pItem->m_Type = CTreeItem::typeCoClasses ;
		tvis.item.lParam = (LPARAM)pItem ;
		tvis.item.pszText = _T("CoClasses") ;
		m_pTree->InsertItem(&tvis) ;

		pItem = new CTreeItem(m_pTree) ;
		pItem->SetTypeLib( GetTypeLib() ) ;
		GetTypeLib()->AddRef() ;
		pItem->m_Type = CTreeItem::typeAliases ;
		tvis.item.lParam = (LPARAM)pItem ;
		tvis.item.pszText = _T("Typedefs") ;
		m_pTree->InsertItem(&tvis) ;

		pItem = new CTreeItem(m_pTree) ;
		pItem->SetTypeLib( GetTypeLib() ) ;
		GetTypeLib()->AddRef() ;
		pItem->m_Type = CTreeItem::typeUnions ;
		tvis.item.lParam = (LPARAM)pItem ;
		tvis.item.pszText = _T("Unions") ;
		m_pTree->InsertItem(&tvis) ;

		fExpand = TRUE ;
	}
	break ;

	case typeEnums:
	case typeRecords:
	case typeModules:
	case typeInterfaces:
	case typeDispinterfaces:
	case typeCoClasses:
	case typeAliases:
	case typeUnions:
		fExpand = ExpandTypeLib( hitem ) ;
	break ;

	case typeTypeInfo:
	case typeTypeInfo2:
	case typeEnum:
	case typeRecord:
	case typeModule:
	case typeInterface:
	case typeDispinterface:
	case typeCoClass:
	case typeAlias:
	case typeUnion:
		fExpand = ExpandTypeInfo( hitem ) ;
	break ;

	case typeMethods:
	case typeMethods2:
		fExpand = ExpandFuncs( hitem ) ;
	break ;

	case typeProperties:
	case typeProperties2:
	case typeConstants:
	case typeConstants2:
		fExpand = ExpandVars( hitem ) ;
	break ;

	case typeImplTypes:
	case typeImplTypes2:
		fExpand = ExpandImplTypes( hitem ) ;
	break ;

	case typeMethod:
	case typeProperty:
	case typeConstant:
	default:
	break ;
	}

	return fExpand ;
}

BOOL CTreeItem::ExpandTypeLib( HTREEITEM hitem )
{
	ASSERT(hitem) ;
	CTreeItem*  pNewItem = NULL ;

	UINT            uiTypeInfoCount = GetTypeLib()->GetTypeInfoCount() ;
	HRESULT         hr = S_OK ;
	TV_INSERTSTRUCT tvis ;
	CString         strError = "Enumerating typeinfos";
	TYPEATTR*       pattr = NULL ;
	BOOL            fExpand = FALSE ;

	tvis.hParent = hitem  ;
	tvis.hInsertAfter = TVI_LAST ;
	tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_CHILDREN ;
	tvis.item.cChildren = 1 ;
	TRY
	{
		for (UINT n = 0 ; n < uiTypeInfoCount ; n++)
		{
			#pragma warning (suppress: 6014)
			pNewItem = new CTreeItem( m_pTree ) ;
			pNewItem->m_Type = typeTypeInfo ;
			ASSERT(pNewItem) ;

			tvis.item.lParam = (LPARAM)pNewItem ;
			hr = GetTypeLib()->GetTypeInfo( n, (ITypeInfo**)&pNewItem->m_punk ) ;
			if (FAILED(hr))
			{
				strError.Format(_T("Could not get TypeInfo #%u"), n ) ;
				AfxThrowOleException(hr) ;
			}
			ASSERT(pNewItem->m_punk) ;

			hr = pNewItem->GetTypeInfo()->GetTypeAttr(&pattr) ;
			if FAILED(hr)
			{
				strError.Format(_T("ITypeInfo::GetTypeAttr() failed") ) ;
				AfxThrowOleException(hr) ;
			}

			if ((m_Type == typeTypeLib) ||
				(m_Type == (TypeKindToItemType(pattr->typekind) + 8)))
			{
				tvis.item.iImage = pattr->typekind + typeEnum ;
				tvis.item.iSelectedImage = tvis.item.iImage ;
				CString sName;
				pNewItem->GetName(sName, TRUE );
				tvis.item.pszText = sName.GetBuffer(0);
				m_pTree->InsertItem( &tvis ) ;
				sName.ReleaseBuffer();
				pNewItem->GetTypeInfo()->ReleaseTypeAttr( pattr ) ;
				fExpand = TRUE ;
			}
			else
			{
				pNewItem->GetTypeInfo()->ReleaseTypeAttr( pattr ) ;
				delete pNewItem ;
			}
	   }
	}
	CATCH(CException, pException)
	{
		if (pException->IsKindOf(RUNTIME_CLASS(COleException)))
			ErrorMessage( strError, ((COleException*)pException)->m_sc ) ;
		else
			ErrorMessage( strError, hr ) ;

		if (pNewItem)
			delete pNewItem ;
		return FALSE ;
	}
	END_CATCH

	return fExpand ;
}


BOOL CTreeItem::ExpandTypeInfo( HTREEITEM hitem )
{
	ASSERT(m_pTree) ;
	ASSERT(hitem) ;

	CTreeItem*  pNewItem = NULL ;
	HRESULT         hr = S_OK ;
	TV_INSERTSTRUCT tvis ;
	CString         strError = "Enumerating TypeInfo" ;
	TYPEATTR*       pattr = NULL ;
	ITypeInfo*      pti = GetTypeInfo() ;
	ASSERT(pti) ;
	BOOL            fExpand = FALSE ;

	tvis.hParent = hitem  ;
	tvis.hInsertAfter = TVI_LAST ;
	tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_CHILDREN ;
	tvis.item.iImage = typeUnknown ;
	tvis.item.iSelectedImage = tvis.item.iImage + 1 ;

	TRY
	{
		ENSURE(pti);
		hr = pti->GetTypeAttr(&pattr) ;
		if FAILED(hr)
		{
			strError.Format(_T("ITypeInfo::GetTypeAttr() failed"), hr ) ;
			AfxThrowMemoryException() ;
		}

		switch(pattr->typekind)
		{
		// typedef [attributes] enum [tag] {
		//      enumlist
		// } enumname;
		//
		// "typedef enum enumname"
		case TKIND_ENUM:
			fExpand = ExpandVars( hitem ) ;
		break ;

		// typedef [attributes]
		//  struct [tag] {
		//      memberlist
		//  } structname;
		//
		// "typedef struct structname"
		case TKIND_RECORD:
			fExpand = ExpandVars( hitem ) ;
		break ;

		// [attributes]
		//  module modulename {
		//      elementlist
		// };
		case TKIND_MODULE:
			if (pattr->cVars)
			{
				// Add "Constants" folder
				//
				#pragma warning (suppress: 6211)
				#pragma warning (suppress: 6014)
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->m_Type = typeProperties ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				tvis.item.cChildren = pattr->cVars ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.pszText = _T("Constants") ;
				tvis.item.iImage = typeConstants ;
				tvis.item.iSelectedImage = tvis.item.iImage + 1 ;
				m_pTree->InsertItem( &tvis ) ;
				fExpand = TRUE ;
			}
			if (pattr->cFuncs)
			{
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->m_Type = typeMethods ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				tvis.item.cChildren = pattr->cFuncs ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.pszText = _T("Functions") ;
				tvis.item.iImage = typeMethods ;
				tvis.item.iSelectedImage = tvis.item.iImage + 1 ;
				m_pTree->InsertItem( &tvis ) ;
				fExpand = TRUE ;
			}
		break ;

		// [attributes]
		//  interface interfacename  [:baseinterface] {
		//      functionlist
		// };
		case TKIND_INTERFACE:
			fExpand = ExpandFuncs( hitem) ;
			if (pattr->cImplTypes)
			{
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->m_Type = typeImplTypes ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				tvis.item.pszText = _T("Inherited Interfaces") ;
				tvis.item.iImage = typeInterface ;
				tvis.item.cChildren = pattr->cImplTypes ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.iSelectedImage = tvis.item.iImage ;
				m_pTree->InsertItem( &tvis ) ;
				fExpand = TRUE ;
			}
		break ;

		// [attributes]
		//  dispinterface intfname {
		//      interface interfacename
		// };
		case TKIND_DISPATCH :
			if (pattr->cVars)
			{
				// Add "Constants" folder
				//
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->m_Type = typeConstants ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				tvis.item.cChildren = pattr->cVars ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.pszText = _T("Constants") ;
				tvis.item.iImage = typeConstants ;
				tvis.item.iSelectedImage = tvis.item.iImage + 1 ;
				m_pTree->InsertItem( &tvis ) ;

				// Add "Properties" folder
				//
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->m_Type = typeProperties ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				tvis.item.cChildren = pattr->cVars ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.pszText = _T("Properties") ;
				tvis.item.iImage = typeProperties ;
				tvis.item.iSelectedImage = tvis.item.iImage + 1 ;
				m_pTree->InsertItem( &tvis ) ;
				fExpand = TRUE ;
			 }
			if (pattr->cFuncs)
			{
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->m_Type = typeMethods ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				tvis.item.cChildren = pattr->cFuncs ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.pszText = _T("Methods") ;
				tvis.item.iImage = typeMethods ;
				tvis.item.iSelectedImage = tvis.item.iImage + 1 ;
				m_pTree->InsertItem( &tvis ) ;
				fExpand = TRUE ;
			}
			if (pattr->cImplTypes)
			{
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->m_Type = typeImplTypes ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				tvis.item.pszText = _T("Inherited Interfaces") ;
				tvis.item.iImage = typeInterface ;
				tvis.item.cChildren = pattr->cImplTypes ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.iSelectedImage = tvis.item.iImage ;
				m_pTree->InsertItem( &tvis ) ;
				fExpand = TRUE ;
			}
		break ;

		// [attributes]
		//  coclass classname {
		//      [attributes2] [interface | dispinterface] interfacename;
		//      ...
		// };
		case TKIND_COCLASS:
			fExpand = ExpandImplTypes( hitem ) ;
		break ;

		// typedef [attributes] basetype aliasname;
		case TKIND_ALIAS:
			if (pattr->tdescAlias.vt == VT_USERDEFINED)
			{
				ITypeInfo* ptiRefType = NULL ;

				#pragma warning (suppress: 6246)
				HRESULT hr = pti->GetRefTypeInfo( pattr->tdescAlias.hreftype, &ptiRefType ) ;
				if (FAILED(hr))
					AfxThrowOleException( hr ) ;

				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->SetTypeInfo( ptiRefType ) ;
				pNewItem->m_Type = TypeKindToItemType( pNewItem->GetTypeKind() ) ;
				tvis.item.iImage = TypeKindToItemType( pNewItem->GetTypeKind() ) ;
				tvis.item.cChildren = 1 ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.iSelectedImage = tvis.item.iImage ;
				CString sName;
				pNewItem->GetName(sName, TRUE );
				tvis.item.pszText = sName.GetBuffer(0) ;
				m_pTree->InsertItem( &tvis ) ;
				sName.ReleaseBuffer();
				fExpand = TRUE ;
			}
		break ;

		// typedef [attributes] union [tag] {
		//      memberlist
		// } unionname;
		case TKIND_UNION:
			fExpand = ExpandVars( hitem ) ;
		break ;

		default:
		break ;
		}

		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		ErrorMessage( strError, hr ) ;
		if (pNewItem)
			delete pNewItem ;

		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		return FALSE ;
	}
	END_CATCH
	return fExpand ;
}

BOOL CTreeItem::ExpandFuncs( HTREEITEM hitem )
{
	ASSERT(hitem) ;

	CTreeItem*  pNewItem = NULL ;
	HRESULT         hr = S_OK ;
	TV_INSERTSTRUCT tvis ;
	CString         strError ;
	TYPEATTR*       pattr = NULL ;
	ITypeInfo*      pti = GetTypeInfo() ;
	ASSERT(pti) ;
	FUNCDESC*       pfuncdesc = NULL ;
	BSTR            bstrParams = NULL ;
	BOOL            fExpand = FALSE ;

	tvis.hParent = hitem  ;
	tvis.hInsertAfter = TVI_LAST ;
	tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_CHILDREN ;

	TRY
	{
		ENSURE(pti);
		hr = pti->GetTypeAttr(&pattr) ;
		if FAILED(hr)
		{
			strError.Format(_T("ITypeInfo::GetTypeAttr() failed: %x"), hr);
			AfxThrowMemoryException() ;
		}

		BSTR  rgbstrNames[MAX_NAMES] ;
		int   cNames ;

		//
		// Enumerate through all FUNCDESCS
		for ( int iIndex = 0 ; iIndex < pattr->cFuncs ; iIndex++)
		{
			hr = pti->GetFuncDesc( iIndex, &pfuncdesc ) ;
			if (FAILED(hr))
			{
				strError.Format(_T("GetVarDesc failed for function #%u"), iIndex) ;
				AfxThrowMemoryException() ;
			}

			//int cParams = pfuncdesc->cParams ;
			//int cParamsOpt = abs(pfuncdesc->cParamsOpt) ;

			// Get the names of the function and it's parameters into rgbstrNames.
			// cNames gets the number of parameters + 1.
			//
			hr = pti->GetNames( pfuncdesc->memid, rgbstrNames, 1, (UINT*)&cNames) ; //MAX_NAMES, (UINT FAR*)&cNames );
			if (FAILED(hr))
			{
				strError.Format(_T("GetNames failed for function #%u"), iIndex) ;
				AfxThrowMemoryException() ;
			}

			// rgbstrNames[0] is the name of the function
			if (cNames > 0)
			{
				#pragma warning (suppress: 6014)
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				pNewItem->m_Type = typeMethod ;
				pNewItem->m_uiMemid = iIndex ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.iImage = typeMethod ;
				tvis.item.iSelectedImage = tvis.item.iImage ;
				tvis.item.cChildren = 0 ;
				COLE2T lpszText(rgbstrNames[0]);
				tvis.item.pszText = lpszText;
				m_pTree->InsertItem( &tvis ) ;
				SysFreeString( rgbstrNames[0] ) ;
			}

			SysFreeString( bstrParams ) ;

			pti->ReleaseFuncDesc( pfuncdesc ) ;
			fExpand = TRUE ;
		}
		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		ErrorMessage( strError, hr ) ;
		if (pNewItem)
			delete pNewItem ;

		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		if (pfuncdesc)
			pti->ReleaseFuncDesc( pfuncdesc ) ;

		if (bstrParams)
			SysFreeString(bstrParams) ;

		return FALSE ;
	}
	END_CATCH
	return fExpand ;
}

BOOL CTreeItem::ExpandVars( HTREEITEM hitem )
{
	ASSERT(hitem) ;
	CTreeItem*  pNewItem = NULL ;
	HRESULT         hr = S_OK ;
	TV_INSERTSTRUCT tvis ;
	CString         strError ;
	TYPEATTR*       pattr = NULL ;
	ITypeInfo*      pti = GetTypeInfo() ;
	ASSERT(pti) ;
	LPVARDESC pvardesc = NULL ;
	BSTR            rgbstrNames[MAX_NAMES] ;
	int             cNames ;
	BOOL            fProperties = FALSE ;
	BOOL            fExpand = FALSE ;
	tvis.hParent = hitem  ;
	tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_CHILDREN ;
	tvis.item.cChildren = 0 ;

	TRY
	{
		ENSURE(pti);
		hr = pti->GetTypeAttr(&pattr) ;
		if FAILED(hr)
		{
			strError.Format(_T("ITypeInfo::GetTypeAttr() failed"), hr ) ;
			AfxThrowMemoryException() ;
		}

		// if it's a struct or an enum, order is important
		//
		if (pattr->typekind == TKIND_RECORD || pattr->typekind == TKIND_ENUM || pattr->typekind == TKIND_UNION)
			tvis.hInsertAfter = TVI_LAST ;
		else
		{
			tvis.hInsertAfter = TVI_LAST ;

			// are we doing constants or properties?
			TV_ITEM tvi ;
			TCHAR szBuf[80] ;
			tvi.hItem = hitem ;
			tvi.mask = TVIF_TEXT ;
			tvi.cchTextMax = 80 ;
			tvi.pszText = szBuf ;
			m_pTree->GetItem(&tvi) ;
			#pragma warning(suppress: 6054) // tvi.pszText will always be null terminated.
			if (_stricmp(tvi.pszText, _T("Properties")) == 0)
				fProperties = TRUE ;
		}

		for (int iIndex = 0 ; iIndex < pattr->cVars ; iIndex++)
		{
			hr = pti->GetVarDesc( iIndex, &pvardesc ) ;
			if (FAILED(hr))
			{
				strError.Format(_T("GetVarDesc failed for variable #%u"), iIndex) ;
				AfxThrowMemoryException() ;
			}
			hr = pti->GetNames( pvardesc->memid, rgbstrNames, 1, (UINT FAR*)&cNames );
			if (FAILED(hr))
			{
				strError.Format(_T("GetNames failed for variable #%u"), iIndex) ;
				AfxThrowMemoryException() ;
			}
			if (pvardesc->varkind == VAR_CONST && fProperties == FALSE)
			{
//				#pragma warning (suppress: 6263)
				CString str = TYPEDESCtoString( &pvardesc->elemdescVar.tdesc ) ;

				VARIANT varValue ;
				VariantInit( &varValue ) ;
				if (FAILED(hr = VariantChangeType( &varValue, pvardesc->lpvarValue, 0, VT_BSTR )))
				{
					if (pvardesc->lpvarValue->vt == VT_ERROR || pvardesc->lpvarValue->vt == VT_HRESULT)
					{
						varValue.vt = VT_BSTR ;
						varValue.bstrVal = SysAllocString(CT2OLE(_GetScodeString(pvardesc->lpvarValue->scode))) ;
						hr = S_OK ;
					}
					else
						AfxThrowOleException( hr ) ;
				}

				// const type name = expression
				UINT len = SysStringLen( varValue.bstrVal ) ;
				COLE2T lpszSource(varValue.bstrVal);
				TCHAR* pstrExpand = new TCHAR[(len+1) * sizeof(TCHAR) * 2] ;
				LPTSTR lpD, lpS = lpszSource ;
				lpD = pstrExpand;
				for (UINT n = 0 ; n < len ; n++)
				{
					#pragma warning(suppress: 6328) // unexpected type mismatch prefast warning
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
							lpD += _stprintf_s( lpD, (len+1) * sizeof(TCHAR) * 2, _T("x%02X"), (UINT)*lpS );
						break ;
						}
						lpS++;
					}
					else
						*lpD++ = *lpS++;
				}
				*lpD = '\0';

				if (pvardesc->lpvarValue->vt == VT_BSTR)
					strError.Format(_T("const %s %s = \"%s\""), (LPCTSTR)str, COLE2CT(rgbstrNames[0]), pstrExpand) ;
				else
					strError.Format(_T("const %s %s = %s"), (LPCTSTR)str, COLE2CT(rgbstrNames[0]), pstrExpand);
				//#pragma warning (suppress: 6211)
				delete []pstrExpand ;
				VariantClear( &varValue ) ;
				tvis.item.iImage = typeConstant ;
				tvis.item.iSelectedImage = tvis.item.iImage ;
				#pragma warning (suppress: 6211)
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				pNewItem->m_Type = typeConstant ;
				pNewItem->m_uiMemid = iIndex ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.pszText = strError.GetBuffer(0) ;
				m_pTree->InsertItem( &tvis ) ;
				strError.ReleaseBuffer(-1) ;
				fExpand = TRUE ;
			}
			else if (fProperties == TRUE ||
					(pattr->typekind == TKIND_RECORD ||
					 pattr->typekind == TKIND_UNION  ))
			{
				CString str ;
				static TCHAR szNameless[] = _T("(nameless)");
				if ((pvardesc->elemdescVar.tdesc.vt & 0x0FFF) == VT_CARRAY)
				{
					// type name[n]
					strError.Format(_T("%s "), TYPEDESCtoString( &pvardesc->elemdescVar.tdesc.lpadesc->tdescElem) );
					if (rgbstrNames[0])
					{
						COLE2CT tName (rgbstrNames[0]);
						strError += tName;
					}
					else
						strError += szNameless;
					// Allocate cDims * lstrlen("[123456]")
					for (USHORT n = 0 ; n < pvardesc->elemdescVar.tdesc.lpadesc->cDims ; n++)
					{
						str.Format( _T("[%d]"), pvardesc->elemdescVar.tdesc.lpadesc->rgbounds[n].cElements ) ;
						strError += str ;
					}
				}
				else
				{
					// type name
					strError.Format(_T("%s "),strError = TYPEDESCtoString( &pvardesc->elemdescVar.tdesc ));
					if (rgbstrNames[0]) {
					  COLE2CT tName (rgbstrNames[0]);
					  strError += tName;
					}
					else
						strError += szNameless;
				}
				tvis.item.iImage = typeProperty ;
				tvis.item.iSelectedImage = tvis.item.iImage ;
				pNewItem = new CTreeItem(m_pTree) ;
				pNewItem->SetTypeInfo(pti) ;
				pti->AddRef() ;
				pNewItem->m_Type = typeProperty ;
				pNewItem->m_uiMemid = iIndex ;
				tvis.item.lParam = (LPARAM)pNewItem ;
				tvis.item.pszText = strError.GetBuffer(0) ;
				m_pTree->InsertItem( &tvis ) ;
				strError.ReleaseBuffer(-1) ;
				fExpand = TRUE ;
			}
			SysFreeString( rgbstrNames[0] ) ;
			pti->ReleaseVarDesc( pvardesc ) ;
		}

		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;
	}
	CATCH(CException, pException)
	{
		ErrorMessage( strError, hr ) ;
		if (pNewItem)
			delete pNewItem ;

		if (pattr)
			pti->ReleaseTypeAttr( pattr ) ;

		if (pvardesc)
			pti->ReleaseVarDesc( pvardesc ) ;

		return FALSE ;
	}
	END_CATCH
	return fExpand ;
}

BOOL CTreeItem::ExpandImplTypes( HTREEITEM hitem )
{
	ASSERT(hitem) ;

	BOOL fExpand = FALSE ;
	CTreeItem*  pNewItem = NULL ;
	HRESULT         hr = S_OK ;
	BSTR            bstrName = NULL ;
	BSTR            bstrDoc = NULL ;
	BSTR            bstrHelp = NULL ;
	DWORD           dwHelpID ;
	TV_INSERTSTRUCT tvis ;
	CString         strError ;
	TYPEATTR*       pattr = NULL ;
	ITypeInfo*      pti = GetTypeInfo() ;

	tvis.hParent = hitem  ;
	tvis.hInsertAfter = TVI_LAST ;
	tvis.item.mask = TVIF_PARAM | TVIF_TEXT | TVIF_IMAGE | TVIF_SELECTEDIMAGE | TVIF_CHILDREN ;
	tvis.item.cChildren = 1 ;
	TRY
	{
		hr = pti->GetTypeAttr(&pattr) ;
		if FAILED(hr)
		{
			//#pragma warning (suppress: 6014)
			strError.Format(_T("ITypeInfo::GetTypeAttr() failed (0x%x)"), hr ) ;
			AfxThrowMemoryException() ;
		}

		for (UINT n = 0 ; n <  pattr->cImplTypes; n++)
		{
			#pragma warning (suppress: 6014)
			pNewItem = new CTreeItem( m_pTree ) ;
			pNewItem->m_uiMemid = n ;
			ASSERT(pNewItem) ;

			tvis.item.lParam = (LPARAM)pNewItem ;
			HREFTYPE href = NULL ;
			hr = pti->GetRefTypeOfImplType(n, &href) ;
			if (FAILED(hr))
			{
				strError.Format(_T("Could not get RefTypeOfImplType #%u"), n ) ;
				AfxThrowMemoryException() ;
			}
			hr = pti->GetRefTypeInfo( href, (ITypeInfo**)&pNewItem->m_punk ) ;
			if (FAILED(hr))
			{
				strError.Format(_T("Could not get RefTypeInfo") ) ;
				AfxThrowMemoryException() ;
			}

			ASSERT(pNewItem->m_punk) ;

			TYPEATTR* pattrNew ;
			hr = pNewItem->GetTypeInfo()->GetTypeAttr(&pattrNew) ;
			if FAILED(hr)
			{
				strError.Format(_T("ITypeInfo::GetTypeAttr() failed") ) ;
				AfxThrowMemoryException() ;
			}
			pNewItem->m_Type = TypeKindToItemType( pNewItem->GetTypeKind() ) ;
			tvis.item.iImage = TypeKindToItemType( pNewItem->GetTypeKind() ) ;
			tvis.item.iSelectedImage = tvis.item.iImage ;
			pNewItem->GetTypeInfo()->ReleaseTypeAttr( pattrNew ) ;

			hr = pNewItem->GetTypeInfo()->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp ) ;
			if (FAILED(hr))
			{
				strError.Format(_T("ITypeInfo::GetDocumentation() failed")) ;
				AfxThrowMemoryException() ;
			}
			COLE2T lpszName(bstrName);
			tvis.item.pszText = lpszName  ;
			m_pTree->InsertItem( &tvis ) ;

			SysFreeString( bstrName ) ;
			bstrName = NULL ;
			SysFreeString( bstrDoc ) ;
			bstrDoc = NULL ;
			SysFreeString( bstrHelp ) ;
			bstrHelp = NULL ;

			fExpand = TRUE ;
		}
	}
	CATCH(CException, pException)
	{
		ErrorMessage( strError, hr ) ;
		if (pNewItem)
			delete pNewItem ;
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		return FALSE ;
	}
	END_CATCH

	if (pti && pattr)
		pti->ReleaseTypeAttr( pattr );
	return fExpand ;
}

CString CTreeItem::TYPEDESCtoString( TYPEDESC* ptdesc )
{
	ASSERT(GetTypeInfo()) ;
	return ::TYPEDESCtoString( GetTypeInfo(), ptdesc ) ;
}

void CTreeItem::GetName(CString& szReturn, BOOL fIDLStyle /*= FALSE*/)
{
	BSTR    bstrName = NULL ;
	BSTR    bstrDoc = NULL ;
	BSTR    bstrHelp = NULL ;
	DWORD   dwHelpID ;
	HRESULT hr ;

	TRY
	{
		hr = GetTypeInfo()->GetDocumentation( MEMBERID_NIL, &bstrName, &bstrDoc, &dwHelpID, &bstrHelp ) ;
		if (FAILED(hr))
			AfxThrowOleException( hr ) ;

		SysFreeString( bstrDoc ) ;
		bstrDoc = NULL ;
		SysFreeString( bstrHelp ) ;
		bstrHelp = NULL ;
		LPCTSTR lpszName = COLE2CT(bstrName);
		::SysFreeString(bstrName);
		bstrName = NULL;
		if (fIDLStyle)
		{
			TYPEATTR* pattr ;
			hr = GetTypeInfo()->GetTypeAttr(&pattr) ;
			if FAILED(hr)
				AfxThrowOleException(hr) ;

			switch(pattr->typekind)
			{
			// typedef [attributes] enum [tag] {
			//      enumlist
			// } enumname;
			//
			// "typedef enum enumname"
			case TKIND_ENUM:
				szReturn.Format(_T("typedef enum %s"), lpszName ) ;
			break ;

			// typedef [attributes]
			//  struct [tag] {
			//      memberlist
			//  } structname;
			//
			// "typedef struct structname"
			case TKIND_RECORD:
				szReturn.Format(_T("typedef struct %s"), lpszName ) ;
			break ;

			// [attributes]
			//  module modulename {
			//      elementlist
			// };
			case TKIND_MODULE:
				szReturn.Format(_T("module %s"), lpszName ) ;
			break ;

			// [attributes]
			//  interface interfacename  [:baseinterface] {
			//      functionlist
			// };
			case TKIND_INTERFACE:
				// TODO:  enum base interfaces and append
				szReturn.Format(_T("interface %s"), lpszName ) ;
			break ;

			// [attributes]
			//  dispinterface intfname {
			//      interface interfacename
			// };
			case TKIND_DISPATCH :
				szReturn.Format(_T("dispinterface %s"), lpszName ) ;
			break ;

			// [attributes]
			//  coclass classname {
			//      [attributes2] [interface | dispinterface] interfacename;
			//      ...
			// };
			case TKIND_COCLASS:
				szReturn.Format(_T("coclass %s"), lpszName ) ;
			break ;

			// typedef [attributes] basetype aliasname;
			case TKIND_ALIAS:
				szReturn.Format(_T("typedef %s %s"),
					::TYPEDESCtoString(GetTypeInfo(), &pattr->tdescAlias), lpszName);
			break ;

			// typedef [attributes] union [tag] {
			//      memberlist
			// } unionname;
			case TKIND_UNION:
				szReturn.Format(_T("typedef union %s"), lpszName ) ;
			break ;

			default:
			break ;
			}
			GetTypeInfo()->ReleaseTypeAttr( pattr ) ;
		}
	}
	CATCH(CException, pException)
	{
		if (bstrName)
			SysFreeString( bstrName ) ;
		if (bstrDoc)
			SysFreeString( bstrDoc ) ;
		if (bstrHelp)
			SysFreeString( bstrHelp ) ;
		THROW_LAST();
	}
	END_CATCH

}

TYPEKIND CTreeItem::GetTypeKind()
{
	TYPEATTR* pattr ;
	TYPEKIND kind ;

	HRESULT hr = GetTypeInfo()->GetTypeAttr(&pattr) ;
	if FAILED(hr)
		AfxThrowOleException(hr) ;
	kind = pattr->typekind ;
	GetTypeInfo()->ReleaseTypeAttr(pattr) ;

	return kind ;
}

CTreeItem::ITEM_TYPE CTreeItem::TypeKindToItemType( TYPEKIND tkind )
{
	ITEM_TYPE t ;

	switch(tkind)
	{
	case TKIND_ENUM:        t = typeEnum ; break ;
	case TKIND_RECORD:      t = typeRecord ; break ;
	case TKIND_MODULE:      t = typeModule ;break ;
	case TKIND_INTERFACE:   t = typeInterface ;break ;
	case TKIND_DISPATCH :   t = typeDispinterface ; break ;
	case TKIND_COCLASS:     t = typeCoClass ; break ;
	case TKIND_ALIAS:       t = typeAlias ; break ;
	case TKIND_UNION:       t = typeUnion ; break ;
	default:                t = typeUnknown ; break ;
	}

	return t ;
}
