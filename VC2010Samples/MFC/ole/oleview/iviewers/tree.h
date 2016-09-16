// tree.h

// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.

#ifndef __TREE_H__
#define __TREE_H__

// base class
class CTreeItem : public CObject
{
public:
	CTreeItem( CTreeCtrl* pTree = NULL) ;
	virtual ~CTreeItem();
	DECLARE_DYNCREATE(CTreeItem)

// Attributes
public:
	IUnknown*       m_punk ;
	CTreeCtrl*      m_pTree ;

	// enum of entry types.
	//
	typedef enum {
		typeUnknown         ,
		typeUnknown2        ,
		typeTypeLib         ,
		typeTypeLib2        ,
		typeTypeInfo        ,
		typeTypeInfo2       ,
		typeMethods         ,
		typeMethods2        ,
		typeProperties      ,
		typeProperties2     ,
		typeConstants       ,
		typeConstants2      ,
		typeImplTypes       ,
		typeImplTypes2      ,
		typeMethod          ,
		typeProperty        ,
		typeConstant        ,
		typeEnum            ,       // TKIND_ENUM
		typeRecord          ,       // TKIND_RECORD
		typeModule          ,       // TKIND_MODULE
		typeInterface       ,       // TKIND_INTERFACE
		typeDispinterface   ,       // TKIND_DISPATCH
		typeCoClass         ,       // TKIND_COCLASS
		typeAlias           ,       // TKIND_ALIAS
		typeUnion           ,       // TKIND_UNION
		typeEnums           ,
		typeRecords         ,
		typeModules         ,
		typeInterfaces      ,
		typeDispinterfaces  ,
		typeCoClasses       ,
		typeAliases         ,
		typeUnions          ,
	} ITEM_TYPE ;

	ITEM_TYPE       m_Type ;
	MEMBERID        m_uiMemid ;    // memid of the func/var/const

// Operations:
public:
	CString         TYPEDESCtoString( TYPEDESC* lptdesc ) ;
	TYPEKIND        GetTypeKind() ;
	ITEM_TYPE       TypeKindToItemType( TYPEKIND tkind) ;
	void            GetName(CString& szReturn, BOOL fIDLStyle = FALSE ) ;

	virtual ITypeLib* GetTypeLib()
		{return (ITypeLib*)m_punk;}
	virtual void SetTypeLib(ITypeLib* punk)
		{ASSERT(punk); m_punk = (IUnknown*)punk;}

	virtual ITypeInfo* GetTypeInfo()
		{return (ITypeInfo*)m_punk;}
	virtual void SetTypeInfo(ITypeInfo* punk)
		{ASSERT(punk); m_punk = (IUnknown*)punk;}

	virtual BOOL Expand( HTREEITEM hitem ) ;
	virtual BOOL ExpandTypeLib( HTREEITEM hitem ) ;
	virtual BOOL ExpandTypeInfo( HTREEITEM hitem ) ;
	virtual BOOL ExpandFuncs( HTREEITEM hitem ) ;
	virtual BOOL ExpandVars( HTREEITEM hitem ) ;
	virtual BOOL ExpandImplTypes( HTREEITEM hitem ) ;
};
#endif
