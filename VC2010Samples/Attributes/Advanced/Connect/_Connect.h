

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for _Connect.idl:
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

#ifndef ___Connect_h__
#define ___Connect_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRandom_FWD_DEFINED__
#define __IRandom_FWD_DEFINED__
typedef interface IRandom IRandom;

#endif 	/* __IRandom_FWD_DEFINED__ */


#ifndef __IRandomEvent_FWD_DEFINED__
#define __IRandomEvent_FWD_DEFINED__
typedef interface IRandomEvent IRandomEvent;

#endif 	/* __IRandomEvent_FWD_DEFINED__ */


#ifndef __CRandom_FWD_DEFINED__
#define __CRandom_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRandom CRandom;
#else
typedef struct CRandom CRandom;
#endif /* __cplusplus */

#endif 	/* __CRandom_FWD_DEFINED__ */


/* header files for imported files */
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IRandom_INTERFACE_DEFINED__
#define __IRandom_INTERFACE_DEFINED__

/* interface IRandom */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRandom;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8903D31-78AD-4AB4-A543-D1405EE5C6BF")
    IRandom : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [out] */ long *pnID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            /* [in] */ long nID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopAll( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRandomVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRandom * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRandom * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRandom * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRandom * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRandom * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRandom * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRandom * This,
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
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IRandom * This,
            /* [out] */ long *pnID);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IRandom * This,
            /* [in] */ long nID);
        
        HRESULT ( STDMETHODCALLTYPE *StopAll )( 
            IRandom * This);
        
        END_INTERFACE
    } IRandomVtbl;

    interface IRandom
    {
        CONST_VTBL struct IRandomVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRandom_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRandom_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRandom_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRandom_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRandom_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRandom_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRandom_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRandom_Start(This,pnID)	\
    ( (This)->lpVtbl -> Start(This,pnID) ) 

#define IRandom_Stop(This,nID)	\
    ( (This)->lpVtbl -> Stop(This,nID) ) 

#define IRandom_StopAll(This)	\
    ( (This)->lpVtbl -> StopAll(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRandom_INTERFACE_DEFINED__ */


#ifndef __IRandomEvent_INTERFACE_DEFINED__
#define __IRandomEvent_INTERFACE_DEFINED__

/* interface IRandomEvent */
/* [object][unique][helpstring][dual][uuid] */ 


EXTERN_C const IID IID_IRandomEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E890B4C-3E95-4728-BED1-6C48FFB1071D")
    IRandomEvent : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Fire( 
            /* [in] */ long nID) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IRandomEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRandomEvent * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRandomEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRandomEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRandomEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRandomEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRandomEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRandomEvent * This,
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
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Fire )( 
            IRandomEvent * This,
            /* [in] */ long nID);
        
        END_INTERFACE
    } IRandomEventVtbl;

    interface IRandomEvent
    {
        CONST_VTBL struct IRandomEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRandomEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IRandomEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IRandomEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IRandomEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IRandomEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IRandomEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IRandomEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IRandomEvent_Fire(This,nID)	\
    ( (This)->lpVtbl -> Fire(This,nID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IRandomEvent_INTERFACE_DEFINED__ */



#ifndef __CONNECTAttrib_LIBRARY_DEFINED__
#define __CONNECTAttrib_LIBRARY_DEFINED__

/* library CONNECTAttrib */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_CONNECTAttrib;

EXTERN_C const CLSID CLSID_CRandom;

#ifdef __cplusplus

class DECLSPEC_UUID("0DC9A419-477C-453E-861E-F0DE3EB3E1DE")
CRandom;
#endif
#endif /* __CONNECTAttrib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


