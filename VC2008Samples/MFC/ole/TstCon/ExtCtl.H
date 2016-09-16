// File: ExtCtl.H
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

class CTestContainer98Item;
class CTestContainer98View;

extern const IID IID_ITC98ExtendedControl;

#define DISPID_EXT_NAME 0x80010000
#define DISPID_EXT_POSITIONX 0x80010001
#define DISPID_EXT_POSITIONY 0x80010002
#define DISPID_EXT_ACTIVATE 0x80010100
#define DISPID_EXT_DEACTIVATE 0x80010101
#define DISPID_EXT_UIACTIVATE 0x80010102
#define DISPID_EXT_UIDEACTIVATE 0x80010103

class CExtendedControl :
   public ITCExtendedControl
{
public:
   CExtendedControl();
   ~CExtendedControl();

   HRESULT Init( REFCLSID clsidControl, CTestContainer98Item* pItem );

   static HRESULT CreateInstance( REFCLSID clsidControl,
	  CTestContainer98Item* pItem, IUnknown* pOuterUnknown, REFIID iid,
	  void** ppInterface );

public:
   STDMETHOD_( ULONG, AddRef )();
   STDMETHOD_( ULONG, Release )();
   STDMETHOD( QueryInterface )( REFIID iid, void** ppInterface );

public:
   STDMETHOD( GetIDsOfNames )( REFIID iid, LPOLESTR* ppszNames, UINT nNames,
	  LCID lcid, DISPID* pDispIDs );
   STDMETHOD( GetTypeInfo )( UINT iTypeInfo, LCID lcid,
	  ITypeInfo** ppTypeInfo );
   STDMETHOD( GetTypeInfoCount )( UINT* pnInfoCount );
   STDMETHOD( Invoke )( DISPID dispidMember, REFIID iid, LCID lcid,
	  WORD wFlags, DISPPARAMS* pdpParams, VARIANT* pvarResult,
	  EXCEPINFO* pExceptionInfo, UINT* piArgError );

   STDMETHOD( get_Name )( BSTR* pbstrName );
   STDMETHOD( put_Name )( BSTR bstrName );
   STDMETHOD( get_PositionX )( long* px );
   STDMETHOD( put_PositionX )( long x );
   STDMETHOD( get_PositionY )( long* py );
   STDMETHOD( put_PositionY )( long y );
   STDMETHOD( get_SizeX )( long* px );
   STDMETHOD( put_SizeX )( long x );
   STDMETHOD( get_SizeY )( long* py );
   STDMETHOD( put_SizeY )( long y );

   STDMETHOD( raw_Activate )();
   STDMETHOD( raw_Deactivate )();
   STDMETHOD( raw_UIActivate )();
   STDMETHOD( raw_UIDeactivate )();

protected:
   HRESULT InternalInvoke( DISPID dispidMember, REFIID iid, LCID lcid,
	  WORD wFlags, DISPPARAMS* pdpParams, VARIANT* pvarResult,
	  EXCEPINFO* pExceptionInfo, UINT* piArgError );

protected:
   ULONG m_nRefCount;
   IUnknown* m_pControl;
   IDispatchPtr m_pInnerDispatch;
   ITypeInfoPtr m_pTypeInfo;
   CTestContainer98Item* m_pItem;
   CTestContainer98View* m_pView;
   VARIANT_BOOL m_tVisible;
   _bstr_t m_bstrName;
   CPoint m_ptPosition;
   CSize m_size;
};
