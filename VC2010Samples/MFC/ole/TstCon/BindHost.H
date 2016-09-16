// File: BindHost.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

class CTCBindHost :
   public IBindHost
{
public:
   CTCBindHost();
   ~CTCBindHost();

   static HRESULT CreateInstance( REFIID iid, void** ppObject );

public:
   STDMETHOD_( ULONG, AddRef )();
   STDMETHOD_( ULONG, Release )();
   STDMETHOD( QueryInterface )( REFIID iid, void** ppInterface );
   STDMETHOD( CreateMoniker )( LPOLESTR pszName, IBindCtx* pBindCtx,
	  IMoniker** ppMoniker, DWORD dwReserved );
   STDMETHOD( MonikerBindToObject )( IMoniker* pMoniker, IBindCtx* pBindCtx,
	  IBindStatusCallback* pBSC, REFIID iid, void** ppObject );
   STDMETHOD( MonikerBindToStorage )( IMoniker* pMoniker, IBindCtx* pBindCtx,
	  IBindStatusCallback* pBSC, REFIID iid, void** ppObject );

protected:
   ULONG m_nRefCount;
};
