

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

#ifndef __IPolyCtl_FWD_DEFINED__
#define __IPolyCtl_FWD_DEFINED__
typedef interface IPolyCtl IPolyCtl;

#endif 	/* __IPolyCtl_FWD_DEFINED__ */


#ifndef ___IPolyCtlEvents_FWD_DEFINED__
#define ___IPolyCtlEvents_FWD_DEFINED__
typedef interface _IPolyCtlEvents _IPolyCtlEvents;

#endif 	/* ___IPolyCtlEvents_FWD_DEFINED__ */


#ifndef __CPolyProp_FWD_DEFINED__
#define __CPolyProp_FWD_DEFINED__

#ifdef __cplusplus
typedef class CPolyProp CPolyProp;
#else
typedef struct CPolyProp CPolyProp;
#endif /* __cplusplus */

#endif 	/* __CPolyProp_FWD_DEFINED__ */


#ifndef __CPolyCtl_FWD_DEFINED__
#define __CPolyCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CPolyCtl CPolyCtl;
#else
typedef struct CPolyCtl CPolyCtl;
#endif /* __cplusplus */

#endif 	/* __CPolyCtl_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IPolyCtl_INTERFACE_DEFINED__
#define __IPolyCtl_INTERFACE_DEFINED__

/* interface IPolyCtl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IPolyCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38CA75B5-7047-4E70-93F8-6597FD98C535")
    IPolyCtl : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_FillColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_FillColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Sides( 
            /* [retval][out] */ short *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Sides( 
            /* [in] */ short newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IPolyCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPolyCtl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPolyCtl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPolyCtl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IPolyCtl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IPolyCtl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IPolyCtl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IPolyCtl * This,
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
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_FillColor )( 
            IPolyCtl * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_FillColor )( 
            IPolyCtl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Sides )( 
            IPolyCtl * This,
            /* [retval][out] */ short *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Sides )( 
            IPolyCtl * This,
            /* [in] */ short newVal);
        
        END_INTERFACE
    } IPolyCtlVtbl;

    interface IPolyCtl
    {
        CONST_VTBL struct IPolyCtlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPolyCtl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IPolyCtl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IPolyCtl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IPolyCtl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IPolyCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IPolyCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IPolyCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IPolyCtl_put_FillColor(This,clr)	\
    ( (This)->lpVtbl -> put_FillColor(This,clr) ) 

#define IPolyCtl_get_FillColor(This,pclr)	\
    ( (This)->lpVtbl -> get_FillColor(This,pclr) ) 

#define IPolyCtl_get_Sides(This,pVal)	\
    ( (This)->lpVtbl -> get_Sides(This,pVal) ) 

#define IPolyCtl_put_Sides(This,newVal)	\
    ( (This)->lpVtbl -> put_Sides(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPolyCtl_INTERFACE_DEFINED__ */



#ifndef __POLYGONAttrib_LIBRARY_DEFINED__
#define __POLYGONAttrib_LIBRARY_DEFINED__

/* library POLYGONAttrib */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_POLYGONAttrib;

#ifndef ___IPolyCtlEvents_DISPINTERFACE_DEFINED__
#define ___IPolyCtlEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IPolyCtlEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IPolyCtlEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5284604A-3160-4FAE-A564-6E6A3372CA1A")
    _IPolyCtlEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IPolyCtlEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IPolyCtlEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IPolyCtlEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IPolyCtlEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IPolyCtlEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IPolyCtlEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IPolyCtlEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IPolyCtlEvents * This,
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
        
        END_INTERFACE
    } _IPolyCtlEventsVtbl;

    interface _IPolyCtlEvents
    {
        CONST_VTBL struct _IPolyCtlEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IPolyCtlEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IPolyCtlEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IPolyCtlEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IPolyCtlEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IPolyCtlEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IPolyCtlEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IPolyCtlEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IPolyCtlEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CPolyProp;

#ifdef __cplusplus

class DECLSPEC_UUID("E4AB4412-3A8B-4302-B395-EF041BBCCEA1")
CPolyProp;
#endif

EXTERN_C const CLSID CLSID_CPolyCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("44487B6B-DDC8-4A13-9B20-A8A892629026")
CPolyCtl;
#endif
#endif /* __POLYGONAttrib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


