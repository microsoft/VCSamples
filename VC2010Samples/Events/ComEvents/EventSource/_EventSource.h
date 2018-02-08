

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for _EventSource.idl:
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

#ifndef ___EventSource_h__
#define ___EventSource_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IJW_FWD_DEFINED__
#define __IJW_FWD_DEFINED__
typedef interface IJW IJW;

#endif 	/* __IJW_FWD_DEFINED__ */


#ifndef __IBase_FWD_DEFINED__
#define __IBase_FWD_DEFINED__
typedef interface IBase IBase;

#endif 	/* __IBase_FWD_DEFINED__ */


#ifndef __IEvent_FWD_DEFINED__
#define __IEvent_FWD_DEFINED__
typedef interface IEvent IEvent;

#endif 	/* __IEvent_FWD_DEFINED__ */


#ifndef __IEvent2_FWD_DEFINED__
#define __IEvent2_FWD_DEFINED__
typedef interface IEvent2 IEvent2;

#endif 	/* __IEvent2_FWD_DEFINED__ */


#ifndef __CSource_FWD_DEFINED__
#define __CSource_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSource CSource;
#else
typedef struct CSource CSource;
#endif /* __cplusplus */

#endif 	/* __CSource_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf__EventSource_0000_0000 */
/* [local] */ 


enum E
    {
        e	= 17
    } ;
typedef struct S_struct
    {
    int i;
    int j;
    } 	S;



extern RPC_IF_HANDLE __MIDL_itf__EventSource_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf__EventSource_0000_0000_v0_0_s_ifspec;

#ifndef __IJW_INTERFACE_DEFINED__
#define __IJW_INTERFACE_DEFINED__

/* interface IJW */
/* [object][uuid][dual] */ 


EXTERN_C const IID IID_IJW;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("b6d8ff58-8e84-4b1e-8fb8-68fd6158154e")
    IJW : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE event1( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IJWVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IJW * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IJW * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IJW * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IJW * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IJW * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IJW * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IJW * This,
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
        
        HRESULT ( STDMETHODCALLTYPE *event1 )( 
            IJW * This);
        
        END_INTERFACE
    } IJWVtbl;

    interface IJW
    {
        CONST_VTBL struct IJWVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IJW_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IJW_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IJW_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IJW_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IJW_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IJW_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IJW_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IJW_event1(This)	\
    ( (This)->lpVtbl -> event1(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IJW_INTERFACE_DEFINED__ */


#ifndef __IBase_INTERFACE_DEFINED__
#define __IBase_INTERFACE_DEFINED__

/* interface IBase */
/* [object][uuid][dual] */ 


EXTERN_C const IID IID_IBase;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("59fe2af1-cd5d-4845-9a99-d7b5500e45f5")
    IBase : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE doSomething( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IBaseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBase * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBase * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBase * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBase * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBase * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBase * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBase * This,
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
        
        HRESULT ( STDMETHODCALLTYPE *doSomething )( 
            IBase * This);
        
        END_INTERFACE
    } IBaseVtbl;

    interface IBase
    {
        CONST_VTBL struct IBaseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBase_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IBase_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IBase_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IBase_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IBase_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IBase_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IBase_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IBase_doSomething(This)	\
    ( (This)->lpVtbl -> doSomething(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IBase_INTERFACE_DEFINED__ */



#ifndef __EventSource_LIBRARY_DEFINED__
#define __EventSource_LIBRARY_DEFINED__

/* library EventSource */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_EventSource;

#ifndef __IEvent_DISPINTERFACE_DEFINED__
#define __IEvent_DISPINTERFACE_DEFINED__

/* dispinterface IEvent */
/* [uuid] */ 


EXTERN_C const IID DIID_IEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ae17a339-6571-4302-8a84-6b27196f1e21")
    IEvent : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEvent * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IEvent * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IEvent * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IEvent * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IEvent * This,
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
    } IEventVtbl;

    interface IEvent
    {
        CONST_VTBL struct IEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEvent_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEvent_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEvent_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEvent_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IEvent_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IEvent_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IEvent_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IEvent_DISPINTERFACE_DEFINED__ */


#ifndef __IEvent2_INTERFACE_DEFINED__
#define __IEvent2_INTERFACE_DEFINED__

/* interface IEvent2 */
/* [uuid][custom][object] */ 


EXTERN_C const IID IID_IEvent2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8e46b2ec-a8b2-4b37-a75a-069c4336966d")
    IEvent2 : public IUnknown
    {
    public:
        virtual int STDMETHODCALLTYPE event1( 
            /* [in] */ int __MIDL__IEvent20000) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE event2( 
            /* [in] */ int __MIDL__IEvent20001,
            /* [in] */ float __MIDL__IEvent20002) = 0;
        
        virtual void __cdecl event3( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IEvent2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IEvent2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IEvent2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IEvent2 * This);
        
        int ( STDMETHODCALLTYPE *event1 )( 
            IEvent2 * This,
            /* [in] */ int __MIDL__IEvent20000);
        
        HRESULT ( STDMETHODCALLTYPE *event2 )( 
            IEvent2 * This,
            /* [in] */ int __MIDL__IEvent20001,
            /* [in] */ float __MIDL__IEvent20002);
        
        void ( __cdecl *event3 )( 
            IEvent2 * This);
        
        END_INTERFACE
    } IEvent2Vtbl;

    interface IEvent2
    {
        CONST_VTBL struct IEvent2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IEvent2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IEvent2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IEvent2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IEvent2_event1(This,__MIDL__IEvent20000)	\
    ( (This)->lpVtbl -> event1(This,__MIDL__IEvent20000) ) 

#define IEvent2_event2(This,__MIDL__IEvent20001,__MIDL__IEvent20002)	\
    ( (This)->lpVtbl -> event2(This,__MIDL__IEvent20001,__MIDL__IEvent20002) ) 

#define IEvent2_event3(This)	\
    ( (This)->lpVtbl -> event3(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IEvent2_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CSource;

#ifdef __cplusplus

class DECLSPEC_UUID("530DF3AD-6936-3214-A83B-27B63C7997C4")
CSource;
#endif
#endif /* __EventSource_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


