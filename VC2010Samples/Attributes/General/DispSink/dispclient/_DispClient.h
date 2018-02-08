

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for _DispClient.idl:
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

#ifndef ___DispClient_h__
#define ___DispClient_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDispServ_FWD_DEFINED__
#define __IDispServ_FWD_DEFINED__
typedef interface IDispServ IDispServ;

#endif 	/* __IDispServ_FWD_DEFINED__ */


#ifndef __IDispCtl_FWD_DEFINED__
#define __IDispCtl_FWD_DEFINED__
typedef interface IDispCtl IDispCtl;

#endif 	/* __IDispCtl_FWD_DEFINED__ */


#ifndef ___IDispServEvents_FWD_DEFINED__
#define ___IDispServEvents_FWD_DEFINED__
typedef interface _IDispServEvents _IDispServEvents;

#endif 	/* ___IDispServEvents_FWD_DEFINED__ */


#ifndef __CDispCtl_FWD_DEFINED__
#define __CDispCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CDispCtl CDispCtl;
#else
typedef struct CDispCtl CDispCtl;
#endif /* __cplusplus */

#endif 	/* __CDispCtl_FWD_DEFINED__ */


#ifndef ____Impl__IDispServEvents_FWD_DEFINED__
#define ____Impl__IDispServEvents_FWD_DEFINED__

#ifdef __cplusplus
typedef class __Impl__IDispServEvents __Impl__IDispServEvents;
#else
typedef struct __Impl__IDispServEvents __Impl__IDispServEvents;
#endif /* __cplusplus */

#endif 	/* ____Impl__IDispServEvents_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf__DispClient_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf__DispClient_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf__DispClient_0000_0000_v0_0_s_ifspec;

#ifndef __IDispServ_INTERFACE_DEFINED__
#define __IDispServ_INTERFACE_DEFINED__

/* interface IDispServ */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IDispServ;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b7d047ab-e688-4c9b-a956-31d6cee5db51")
    IDispServ : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ VARIANT data) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDispServVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDispServ * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDispServ * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDispServ * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDispServ * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDispServ * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDispServ * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDispServ * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            IDispServ * This,
            /* [in] */ VARIANT data);
        
        END_INTERFACE
    } IDispServVtbl;

    interface IDispServ
    {
        CONST_VTBL struct IDispServVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDispServ_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDispServ_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDispServ_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDispServ_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDispServ_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDispServ_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDispServ_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDispServ_Send(This,data)	\
    ( (This)->lpVtbl -> Send(This,data) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDispServ_INTERFACE_DEFINED__ */


#ifndef __IDispCtl_INTERFACE_DEFINED__
#define __IDispCtl_INTERFACE_DEFINED__

/* interface IDispCtl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDispCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0F4098BD-0318-4F89-A505-A954211198CE")
    IDispCtl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Send( 
            /* [in] */ VARIANT data) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDispCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDispCtl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDispCtl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDispCtl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDispCtl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDispCtl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDispCtl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDispCtl * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Connect )( 
            IDispCtl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IDispCtl * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Send )( 
            IDispCtl * This,
            /* [in] */ VARIANT data);
        
        END_INTERFACE
    } IDispCtlVtbl;

    interface IDispCtl
    {
        CONST_VTBL struct IDispCtlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDispCtl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDispCtl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDispCtl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDispCtl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IDispCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IDispCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IDispCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IDispCtl_Connect(This)	\
    ( (This)->lpVtbl -> Connect(This) ) 

#define IDispCtl_Disconnect(This)	\
    ( (This)->lpVtbl -> Disconnect(This) ) 

#define IDispCtl_Send(This,data)	\
    ( (This)->lpVtbl -> Send(This,data) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDispCtl_INTERFACE_DEFINED__ */



#ifndef __DispClient_LIBRARY_DEFINED__
#define __DispClient_LIBRARY_DEFINED__

/* library DispClient */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_DispClient;

#ifndef ___IDispServEvents_DISPINTERFACE_DEFINED__
#define ___IDispServEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IDispServEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__IDispServEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("06b96b46-4f91-4087-a81f-7f20904e9a45")
    _IDispServEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IDispServEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _IDispServEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _IDispServEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _IDispServEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _IDispServEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _IDispServEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _IDispServEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _IDispServEvents * This,
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
    } _IDispServEventsVtbl;

    interface _IDispServEvents
    {
        CONST_VTBL struct _IDispServEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IDispServEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _IDispServEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _IDispServEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _IDispServEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _IDispServEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _IDispServEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _IDispServEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IDispServEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CDispCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("A40B4D20-27B8-4387-A494-5D7F0D0A81C3")
CDispCtl;
#endif

EXTERN_C const CLSID CLSID___Impl__IDispServEvents;

#ifdef __cplusplus

class DECLSPEC_UUID("E3993B51-4AED-38D5-8050-045614FED827")
__Impl__IDispServEvents;
#endif
#endif /* __DispClient_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


