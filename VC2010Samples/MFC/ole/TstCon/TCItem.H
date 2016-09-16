// CTestContainer98Item.h : interface of the CTestContainer98Item class
//
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#if !defined(AFX_CTESTCONTAINER98ITEM_H__1981850D_B837_11D0_8DF1_00C04FB68D60__INCLUDED_)
#define AFX_CTESTCONTAINER98ITEM_H__1981850D_B837_11D0_8DF1_00C04FB68D60__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#define IMPLTYPE_MASK (IMPLTYPEFLAG_FDEFAULT|IMPLTYPEFLAG_FSOURCE|\
   IMPLTYPEFLAG_FRESTRICTED)

#define IMPLTYPE_DEFAULTSOURCE (IMPLTYPEFLAG_FDEFAULT|IMPLTYPEFLAG_FSOURCE)
#define IMPLTYPE_DEFAULTINTERFACE (IMPLTYPEFLAG_FDEFAULT)

const int MARGIN_PIXELS = 5;

class CTestContainer98Doc;
class CTestContainer98View;

#include "TCDoc.H"

class CTestContainer98Item : public COleClientItem
{
   DECLARE_SERIAL( CTestContainer98Item )

// Constructors
public:
   CTestContainer98Item( CTestContainer98Doc* pContainer = NULL );
	  // Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
	  //  IMPLEMENT_SERIALIZE requires the class have a constructor with
	  //  zero arguments.  Normally, OLE items are constructed with a
	  //  non-NULL document pointer.

// Attributes
public:
   CTestContainer98Doc* GetDocument()
   {
	  return( (CTestContainer98Doc*)COleClientItem::GetDocument() );
   }
   CTestContainer98View* GetActiveView()
   {
	  return( GetDocument()->GetView() );
   }
   CString GetDisplayName();
   BOOL IsInsideOut() const;

   // ClassWizard generated virtual function overrides
   //{{AFX_VIRTUAL(CTestContainer98Item)
   public:
   virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
   virtual void OnActivate();
   protected:
   virtual void OnGetItemPosition(CRect& rPosition);
   virtual void OnGetClipRect(CRect& rPosition);
   virtual void OnDeactivateUI(BOOL bUndoable);
   virtual BOOL OnChangeItemPosition(const CRect& rectPos);
   //}}AFX_VIRTUAL

// Implementation
public:
   void CopyToClipboard( CArchive& ar, IStorage* pStorage );
   BOOL Create( REFCLSID clsid, LPCTSTR pszName = NULL );
   BOOL CreateOrLoad( REFCLSID clsid, LPCTSTR pszName,
	  REFIID iidPersistanceMedium, IUnknown* pPeristanceMedium );
//   BOOL CreateFromClipboard();
   BOOL CreateFromClipboard( CArchive& ar, IStorage* pStorage );
//   BOOL CreateFromData( COleDataObject* pData );
   BOOL QuickActivate();
   CInterfaceInfo* GetEventInfo();
   CInterfaceInfo* GetMethodInfo();
   BOOL GetPropertyPageCLSIDs( CArray< CLSID, CLSID& >& aclsidPages );
   DWORD HitTest( CPoint point );
   void DisplayAsDefault( BOOL tDefault );
   BOOL Draw( CDC* pDC, LPCRECT prectBounds, DVASPECT nDrawAspect = DVASPECT(
	  -1 ) );
   BOOL DrawBackToFront( CDC* pDC, LPCRECT prectBounds );
   BOOL DrawFrontToBack( CDC* pDC, LPCRECT prectBounds );
   void FreezeEvents( BOOL tFreeze );
   DWORD GetActivationPolicy() const;
   void OnDeselect();
   void OnSelect();
   BOOL OnWindowlessDragEnter( COleDataObject* pDataObject, DWORD dwKeyState,
	  CPoint point, DWORD* pdwDropEffect );
   void OnWindowlessDragOver( DWORD dwKeyState, CPoint point,
	  DWORD* pdwDropEffect );
   void OnWindowlessDragLeave();
   void OnWindowlessDrop( COleDataObject* pDataObject, DWORD dwKeyState,
	  CPoint point, DWORD* pdwDropEffect );
   DWORD OnPointerInactiveMove( CPoint point, DWORD dwKeyState );
   DWORD OnPointerInactiveSetCursor( CPoint point, DWORD dwMouseMessage,
	  BOOL* ptHandled );
   void Prepare();
   BOOL ActsLikeButton() const;
   BOOL ShouldActivateWhenVisible();
   void UpdateStatusBar();
   BOOL OnWindowMessage( const MSG* pMessage );
   BOOL HasUIActiveState() const;
   BOOL IsWindowless() const;
   BOOL SupportsIPointerInactive() const;
   HRESULT SaveToStorage( IStorage* pStorage );
   HRESULT SaveToStream( IStream* pStream );
   HRESULT SaveToPropertyBag( IPropertyBag* pPropertyBag );
   COleDataSource* OnGetClipboardData( BOOL tIncludeLink, LPPOINT pptOffset,
	  LPSIZE pSize );

   BOOL m_tDisplayAsDefault;
   BOOL m_tExtendedControl;
   BOOL m_tWindowless;
   DWORD m_dwAspectPass2;
   DISPID m_dispidEvent;
   DISPPARAMS m_dpLastParams;
   IConnectionPointPtr m_pEventCP;
   DWORD m_dwEventCookie;
   IConnectionPointPtr m_pPropertyCP;
   DWORD m_dwPropertyCookie;
   CRect m_rect;
   IDispatchPtr m_pCtlDispatch;
   ITCExtendedControlPtr m_pExtendedControl;
   IOleControlPtr m_pOleControl;
   IOleInPlaceObjectWindowlessPtr m_pOleInPlaceObjectWindowless;
   IViewObjectExPtr m_pViewObjectEx;
   IPointerInactivePtr m_pPointerInactive;
   IDropTargetPtr m_pDropTarget;
   DWORD m_dwMiscStatus;
   DWORD m_dwViewStatus;
   CInterfaceInfo m_infoEvents;
   CInterfaceInfo m_infoMethods;

   IUnknown* GetInterfaceHook( const void* pv );
   void InvalidateItem();
   void InvokeMethods();
   void SetLoggingOptions();
   BOOL IsInPlaceActive() const;
   BOOL IsInvisibleAtRuntime() const;
   BOOL IsUIActive() const;
   void Move( const CRect& rect );
   void OnAmbientPropertyChange( DISPID dispid );
   void OnActivateUI();
   void OnDeactivate();
   void OnDeactivate( BOOL tNoRedraw );
   virtual void OnEvent( DISPID dispid, DISPPARAMS* pdpParams );
   void ReadItem( CArchive& ar );
   void WriteItem( CArchive& ar );
   void CommitItem( BOOL bSuccess );
   void UpdateFromServerExtent();
   ~CTestContainer98Item();

protected:
   CONTROLINFO m_infoControl;
   CString m_strDisplayName;
   BOOL m_tInsideOut;
   CRectTracker m_tracker;
   CDC* m_pDC;
   IBindHostPtr m_pBindHost;
   void CleanupParams();
   void CopyParams( DISPPARAMS* pdpParams );
   HRESULT GetControlInfo();
   BOOL FinishCreate( HRESULT hr );
   HRESULT InitControlInfo();
   void OnFocus( BOOL tGotFocus );
   void Release( OLECLOSE dwCloseOption = OLECLOSE_NOSAVE );
   IBindHost* GetBindHost();

   BEGIN_INTERFACE_PART( ServiceProvider, IServiceProvider )
	  STDMETHOD( QueryService )( REFGUID guidService, REFIID iid,
		 void** ppService );
   END_INTERFACE_PART( ServiceProvider )

   BEGIN_INTERFACE_PART( EventHandler, IDispatch )
	  STDMETHOD( GetIDsOfNames )( REFIID iid, LPOLESTR* ppszNames, UINT nNames,
		 LCID lcid, DISPID* pDispIDs );
	  STDMETHOD( GetTypeInfo )( UINT iTypeInfo, LCID lcid,
		 ITypeInfo** ppTypeInfo );
	  STDMETHOD( GetTypeInfoCount )( UINT* pnInfoCount );
	  STDMETHOD( Invoke )( DISPID dispidMember, REFIID iid, LCID lcid,
		 WORD wFlags, DISPPARAMS* pdpParams, VARIANT* pvarResult,
		 EXCEPINFO* pExceptionInfo, UINT* piArgError );
   END_INTERFACE_PART( EventHandler )

   BEGIN_INTERFACE_PART( PropertyNotifySink, IPropertyNotifySink )
	  STDMETHOD( OnChanged )( DISPID dispid );
	  STDMETHOD( OnRequestEdit )( DISPID dispid );
   END_INTERFACE_PART( PropertyNotifySink )

   BEGIN_INTERFACE_PART( AmbientProperties, IDispatch )
	  STDMETHOD( GetIDsOfNames )( REFIID iid, LPOLESTR* ppszNames, UINT nNames,
		 LCID lcid, DISPID* pDispIDs );
	  STDMETHOD( GetTypeInfo )( UINT iTypeInfo, LCID lcid,
		 ITypeInfo** ppTypeInfo );
	  STDMETHOD( GetTypeInfoCount )( UINT* pnInfoCount );
	  STDMETHOD( Invoke )( DISPID dispidMember, REFIID iid, LCID lcid,
		 WORD wFlags, DISPPARAMS* pdpParams, VARIANT* pvarResult,
		 EXCEPINFO* pExceptionInfo, UINT* piArgError );
   END_INTERFACE_PART( AmbientProperties )

   BEGIN_INTERFACE_PART( AdviseSinkEx, IAdviseSinkEx )
	  STDMETHOD_( void, OnClose )();
	  STDMETHOD_( void, OnDataChange )( FORMATETC* pFormatEtc,
		 STGMEDIUM* pStgMedium );
	  STDMETHOD_( void, OnRename )( IMoniker* pMoniker );
	  STDMETHOD_( void, OnSave )();
	  STDMETHOD_( void, OnViewChange )( DWORD dwAspect, LONG lindex );
	  STDMETHOD_( void, OnViewStatusChange )( DWORD dwViewStatus );
   END_INTERFACE_PART( AdviseSinkEx )

   BEGIN_INTERFACE_PART( OleControlSite, IOleControlSite )
	  STDMETHOD( GetExtendedControl )( IDispatch** ppExtendedControl );
	  STDMETHOD( LockInPlaceActive )( BOOL tLock );
	  STDMETHOD( OnControlInfoChanged )();
	  STDMETHOD( OnFocus )( BOOL tGotFocus );
	  STDMETHOD( ShowPropertyFrame )();
	  STDMETHOD( TransformCoords )( POINTL* pptHiMetric, POINTF* pptContainer,
		 DWORD dwFlags );
	  STDMETHOD( TranslateAccelerator )( LPMSG pMessage, DWORD dwModifiers );
   END_INTERFACE_PART( OleControlSite )

   BEGIN_INTERFACE_PART( OleInPlaceSiteWindowless, IOleInPlaceSiteWindowless )
	  STDMETHOD( ContextSensitiveHelp )( BOOL tEnterMode );
	  STDMETHOD( GetWindow )( HWND* phWnd );

	  STDMETHOD( CanInPlaceActivate )();
	  STDMETHOD( DeactivateAndUndo )();
	  STDMETHOD( DiscardUndoState )();
	  STDMETHOD( GetWindowContext )( IOleInPlaceFrame** ppFrame,
		 IOleInPlaceUIWindow** ppDoc, LPRECT prectPos, LPRECT prectClip,
		 LPOLEINPLACEFRAMEINFO pFrameInfo );
	  STDMETHOD( OnInPlaceActivate )();
	  STDMETHOD( OnInPlaceDeactivate )();
	  STDMETHOD( OnPosRectChange )( LPCRECT prectPos );
	  STDMETHOD( OnUIActivate )();
	  STDMETHOD( OnUIDeactivate )( BOOL tUndoable );
	  STDMETHOD( Scroll )( SIZE sizeExtent );

	  STDMETHOD( OnInPlaceActivateEx )( BOOL* ptNoRedraw, DWORD dwFlags );
	  STDMETHOD( OnInPlaceDeactivateEx )( BOOL tNoRedraw );
	  STDMETHOD( RequestUIActivate )();

	  STDMETHOD( AdjustRect )( LPRECT prect );
	  STDMETHOD( CanWindowlessActivate )();
	  STDMETHOD( GetCapture )();
	  STDMETHOD( GetDC )( LPCRECT prect, DWORD dwFlags, HDC* phDC );
	  STDMETHOD( GetFocus )();
	  STDMETHOD( InvalidateRect )( LPCRECT prect, BOOL tErase );
	  STDMETHOD( InvalidateRgn )( HRGN hRgn, BOOL tErase );
	  STDMETHOD( OnDefWindowMessage )( UINT nMessage, WPARAM wParam,
		 LPARAM lParam, LRESULT* plResult );
	  STDMETHOD( ReleaseDC )( HDC hDC );
	  STDMETHOD( ScrollRect )( int dx, int dy, LPCRECT prectScroll,
		 LPCRECT prectClip );
	  STDMETHOD( SetCapture )( BOOL tCapture );
	  STDMETHOD( SetFocus )( BOOL tFocus );
   END_INTERFACE_PART( OleInPlaceSiteWindowless );

   DECLARE_INTERFACE_MAP()

#ifdef _DEBUG
   virtual void AssertValid() const;
   virtual void Dump(CDumpContext& dc) const;
#endif
   virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CTESTCONTAINER98ITEM_H__1981850D_B837_11D0_8DF1_00C04FB68D60__INCLUDED_)
