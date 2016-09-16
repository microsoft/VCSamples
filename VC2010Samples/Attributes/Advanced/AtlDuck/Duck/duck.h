// File: duck.h
// Copyright (c) Microsoft Corporation.  All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Classes Reference and related electronic
// documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft C++ Libraries products.

#pragma warning( disable: 4049 )  /* more than 64k source lines */

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 5.03.0280 */
/* at Tue Apr 11 14:53:00 2000
 */
/* Compiler settings for duck.idl:
    Os (OptLev=s), W1, Zp8, env=Win32 (32b run), ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __B9AE0649(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 45F
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __duck_h__
#define __duck_h__

/* Forward Declarations */ 

#ifndef __IDuckInt_FWD_DEFINED__
#define __IDuckInt_FWD_DEFINED__
typedef interface IDuckInt IDuckInt;
#endif 	/* __IDuckInt_FWD_DEFINED__ */


#ifndef __DuckInt_FWD_DEFINED__
#define __DuckInt_FWD_DEFINED__

#ifdef __cplusplus
typedef class DuckInt DuckInt;
#else
typedef struct DuckInt DuckInt;
#endif /* __cplusplus */

#endif 	/* __DuckInt_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IDuckInt_INTERFACE_DEFINED__
#define __IDuckInt_INTERFACE_DEFINED__

/* interface IDuckInt */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDuckInt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18194790-E672-4ff1-BFDF-830FB68B046F")
    IDuckInt : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Quack( 
            BSTR szWhosCalling) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Flap( 
            BSTR szWhosCalling) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Paddle( 
            BSTR szWhosCalling) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Walk( 
            BSTR szWhosCalling) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDuckIntVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IDuckInt __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IDuckInt __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IDuckInt __RPC_FAR * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Quack )( 
            IDuckInt __RPC_FAR * This,
            BSTR szWhosCalling);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Flap )( 
            IDuckInt __RPC_FAR * This,
            BSTR szWhosCalling);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Paddle )( 
            IDuckInt __RPC_FAR * This,
            BSTR szWhosCalling);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Walk )( 
            IDuckInt __RPC_FAR * This,
            BSTR szWhosCalling);
        
        END_INTERFACE
    } IDuckIntVtbl;

    interface IDuckInt
    {
        CONST_VTBL struct IDuckIntVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDuckInt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDuckInt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDuckInt_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDuckInt_Quack(This,szWhosCalling)	\
    (This)->lpVtbl -> Quack(This,szWhosCalling)

#define IDuckInt_Flap(This,szWhosCalling)	\
    (This)->lpVtbl -> Flap(This,szWhosCalling)

#define IDuckInt_Paddle(This,szWhosCalling)	\
    (This)->lpVtbl -> Paddle(This,szWhosCalling)

#define IDuckInt_Walk(This,szWhosCalling)	\
    (This)->lpVtbl -> Walk(This,szWhosCalling)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDuckInt_Quack_Proxy( 
    IDuckInt __RPC_FAR * This,
    BSTR szWhosCalling);


void __RPC_STUB IDuckInt_Quack_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDuckInt_Flap_Proxy( 
    IDuckInt __RPC_FAR * This,
    BSTR szWhosCalling);


void __RPC_STUB IDuckInt_Flap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDuckInt_Paddle_Proxy( 
    IDuckInt __RPC_FAR * This,
    BSTR szWhosCalling);


void __RPC_STUB IDuckInt_Paddle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IDuckInt_Walk_Proxy( 
    IDuckInt __RPC_FAR * This,
    BSTR szWhosCalling);


void __RPC_STUB IDuckInt_Walk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDuckInt_INTERFACE_DEFINED__ */



#ifndef __DUCKLib_LIBRARY_DEFINED__
#define __DUCKLib_LIBRARY_DEFINED__

/* library DUCKLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_DUCKLib;

EXTERN_C const CLSID CLSID_DuckInt;

#ifdef __cplusplus

class DECLSPEC_UUID("120B72AF-65BF-11D0-9DDC-00A0C9034892")
DuckInt;
#endif
#endif /* __DUCKLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


