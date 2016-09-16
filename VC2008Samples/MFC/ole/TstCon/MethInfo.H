// File: MethInfo.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

class CMethodParamInfo
{
public:
   CMethodParamInfo();
   ~CMethodParamInfo();

   CString GetName() const;
   VARTYPE GetType() const;
   HRESULT Init( LPCOLESTR pszName, const ELEMDESC* pElemDesc );

public:
   CString m_strName;
   VARTYPE m_vt;
};


const int REQUESTEDIT_ALWAYS = 0;
const int REQUESTEDIT_NEVER = 1;
const int REQUESTEDIT_PROMPT = 2;

class CMethodInfo
{
public:
   CMethodInfo();
   ~CMethodInfo();

   friend CLog& operator<<( CLog& log, CMethodInfo* pMethodInfo );

   void EnableEditRequestLogging( BOOL tEnable );
   void EnableLogging( BOOL tEnable );
   DISPID GetID() const;
   INVOKEKIND GetInvokeKind() const;
   CString GetName() const;
   int GetNumParams() const;
   CMethodParamInfo* GetParam( int iParam ) const;
   int GetRequestEditResponse() const;
   HRESULT Init( ITypeInfo* pTypeInfo, const FUNCDESC* pFuncDesc );
   HRESULT InitPropertyGet( ITypeInfo* pTypeInfo, const VARDESC* pVarDesc );
   HRESULT InitPropertyPut( ITypeInfo* pTypeInfo, const VARDESC* pVarDesc );
   BOOL IsBindable() const;
   BOOL IsLogged() const;
   BOOL LogEditRequests() const;
   void LogEvent( CLog& log, DISPPARAMS* pdpParams );
   BOOL RequestsEdit() const;
   void SetRequestEditResponse( int eResponse );

public:
   CString m_strName;
   DISPID m_dispid;
   INVOKEKIND m_invkind;
   CTypedPtrArray< CPtrArray, CMethodParamInfo* > m_apParamInfo;
   BOOL m_tLog;
   BOOL m_tBindable;
   BOOL m_tRequestEdit;
   BOOL m_tLogEditRequests;
   int m_eRequestEditResponse;
};

CLog& operator<<( CLog& log, CMethodInfo* pMethodInfo );

class CInterfaceInfo
{
public:
   CInterfaceInfo();
   ~CInterfaceInfo();

   CMethodInfo* FindMethod( DISPID dispid ) const;
   CMethodInfo* FindPropertyGet( DISPID dispid ) const;
   IID GetIID() const;
   CMethodInfo* GetMethod( int iMethod ) const;
   int GetNumMethods() const;
   HRESULT Init( ITypeInfo* pTypeInfo );

public:
   CTypedPtrArray< CPtrArray, CMethodInfo* > m_apMethodInfo;
   IID m_iid;
};
