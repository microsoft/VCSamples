// File: TypeAttr.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

class CSmartTypeAttr
{
public:
   CSmartTypeAttr( ITypeInfo* pTypeInfo );
   ~CSmartTypeAttr();

public:
   TYPEATTR* operator->();
   TYPEATTR** operator&();

public:
   void Release();

protected:
   TYPEATTR* m_pTypeAttr;
   ITypeInfoPtr m_pTypeInfo;
};

class CSmartVarDesc
{
public:
   CSmartVarDesc( ITypeInfo* pTypeInfo );
   ~CSmartVarDesc();

public:
   VARDESC* operator->();
   VARDESC** operator&();

   operator const VARDESC*() const;

public:
   void Release();

protected:
   VARDESC* m_pVarDesc;
   ITypeInfoPtr m_pTypeInfo;
};

class CSmartFuncDesc
{
public:
   CSmartFuncDesc( ITypeInfo* pTypeInfo );
   ~CSmartFuncDesc();

public:
   FUNCDESC* operator->();
   FUNCDESC** operator&();

   operator const FUNCDESC*() const;

public:
   void Release();

protected:
   FUNCDESC* m_pFuncDesc;
   ITypeInfoPtr m_pTypeInfo;
};
