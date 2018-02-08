

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for vc140.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __vc140_h__
#define __vc140_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IATLConPropertyBrowser_FWD_DEFINED__
#define __IATLConPropertyBrowser_FWD_DEFINED__
typedef interface IATLConPropertyBrowser IATLConPropertyBrowser;

#endif 	/* __IATLConPropertyBrowser_FWD_DEFINED__ */


#ifndef __CPropertyBrowseControl_FWD_DEFINED__
#define __CPropertyBrowseControl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CPropertyBrowseControl CPropertyBrowseControl;
#else
typedef struct CPropertyBrowseControl CPropertyBrowseControl;
#endif /* __cplusplus */

#endif 	/* __CPropertyBrowseControl_FWD_DEFINED__ */


/* header files for imported files */
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "prsht.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IATLConPropertyBrowser_INTERFACE_DEFINED__
#define __IATLConPropertyBrowser_INTERFACE_DEFINED__

/* interface IATLConPropertyBrowser */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IATLConPropertyBrowser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5AC61281-483A-4E01-B53D-CB3A3B4B0F60")
    IATLConPropertyBrowser : public IDispatch
    {
    public:
        virtual /* [helpstring][propput] */ HRESULT STDMETHODCALLTYPE put_Dispatch( 
            /* [in] */ IDispatch *pDispatch) = 0;
        
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Dispatch( 
            /* [retval][out] */ IDispatch **ppDispatch) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowDescription( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowDescription( 
            /* [in] */ BOOL newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IATLConPropertyBrowserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IATLConPropertyBrowser * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IATLConPropertyBrowser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IATLConPropertyBrowser * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IATLConPropertyBrowser * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IATLConPropertyBrowser * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IATLConPropertyBrowser * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IATLConPropertyBrowser * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        /* [helpstring][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Dispatch )( 
            IATLConPropertyBrowser * This,
            /* [in] */ IDispatch *pDispatch);
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Dispatch )( 
            IATLConPropertyBrowser * This,
            /* [retval][out] */ IDispatch **ppDispatch);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowDescription )( 
            IATLConPropertyBrowser * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowDescription )( 
            IATLConPropertyBrowser * This,
            /* [in] */ BOOL newVal);
        
        END_INTERFACE
    } IATLConPropertyBrowserVtbl;

    interface IATLConPropertyBrowser
    {
        CONST_VTBL struct IATLConPropertyBrowserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IATLConPropertyBrowser_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IATLConPropertyBrowser_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IATLConPropertyBrowser_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IATLConPropertyBrowser_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IATLConPropertyBrowser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IATLConPropertyBrowser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IATLConPropertyBrowser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IATLConPropertyBrowser_put_Dispatch(This,pDispatch)	\
    ( (This)->lpVtbl -> put_Dispatch(This,pDispatch) ) 

#define IATLConPropertyBrowser_get_Dispatch(This,ppDispatch)	\
    ( (This)->lpVtbl -> get_Dispatch(This,ppDispatch) ) 

#define IATLConPropertyBrowser_get_ShowDescription(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowDescription(This,pVal) ) 

#define IATLConPropertyBrowser_put_ShowDescription(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowDescription(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IATLConPropertyBrowser_INTERFACE_DEFINED__ */



#ifndef __ATLConAttrib_LIBRARY_DEFINED__
#define __ATLConAttrib_LIBRARY_DEFINED__

/* library ATLConAttrib */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_ATLConAttrib;

EXTERN_C const CLSID CLSID_CPropertyBrowseControl;

#ifdef __cplusplus

class DECLSPEC_UUID("553C1A15-0BBE-4694-B3CB-6672434C3D2B")
CPropertyBrowseControl;
#endif
#endif /* __ATLConAttrib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


