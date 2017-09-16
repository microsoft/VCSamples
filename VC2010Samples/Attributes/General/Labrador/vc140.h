

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

#ifndef __IMammal_FWD_DEFINED__
#define __IMammal_FWD_DEFINED__
typedef interface IMammal IMammal;

#endif 	/* __IMammal_FWD_DEFINED__ */


#ifndef __IDog_FWD_DEFINED__
#define __IDog_FWD_DEFINED__
typedef interface IDog IDog;

#endif 	/* __IDog_FWD_DEFINED__ */


#ifndef __CLabrador_FWD_DEFINED__
#define __CLabrador_FWD_DEFINED__

#ifdef __cplusplus
typedef class CLabrador CLabrador;
#else
typedef struct CLabrador CLabrador;
#endif /* __cplusplus */

#endif 	/* __CLabrador_FWD_DEFINED__ */


/* header files for imported files */
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_vc140_0000_0000 */
/* [local] */ 

typedef /* [string] */ WCHAR MY_BSTR[ 32 ];



extern RPC_IF_HANDLE __MIDL_itf_vc140_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vc140_0000_0000_v0_0_s_ifspec;

#ifndef __IMammal_INTERFACE_DEFINED__
#define __IMammal_INTERFACE_DEFINED__

/* interface IMammal */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMammal;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8CC00B42-2860-4D28-88D9-DD3A6F92896E")
    IMammal : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetSpeciesName( 
            /* [string][out] */ MY_BSTR p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsAlive( 
            /* [out] */ BOOL *pBool) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMammalVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMammal * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMammal * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMammal * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetSpeciesName )( 
            IMammal * This,
            /* [string][out] */ MY_BSTR p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsAlive )( 
            IMammal * This,
            /* [out] */ BOOL *pBool);
        
        END_INTERFACE
    } IMammalVtbl;

    interface IMammal
    {
        CONST_VTBL struct IMammalVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMammal_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMammal_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMammal_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMammal_GetSpeciesName(This,p)	\
    ( (This)->lpVtbl -> GetSpeciesName(This,p) ) 

#define IMammal_IsAlive(This,pBool)	\
    ( (This)->lpVtbl -> IsAlive(This,pBool) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMammal_INTERFACE_DEFINED__ */


#ifndef __IDog_INTERFACE_DEFINED__
#define __IDog_INTERFACE_DEFINED__

/* interface IDog */
/* [helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B9688DC3-9B57-4C37-A7D7-078BECD52FA6")
    IDog : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetPetName( 
            /* [string][out] */ MY_BSTR p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE SetPetName( 
            /* [string][in] */ MY_BSTR p) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE IsBarking( 
            /* [out] */ BOOL *pBool) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IDogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDog * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDog * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetPetName )( 
            IDog * This,
            /* [string][out] */ MY_BSTR p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *SetPetName )( 
            IDog * This,
            /* [string][in] */ MY_BSTR p);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *IsBarking )( 
            IDog * This,
            /* [out] */ BOOL *pBool);
        
        END_INTERFACE
    } IDogVtbl;

    interface IDog
    {
        CONST_VTBL struct IDogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDog_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDog_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDog_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDog_GetPetName(This,p)	\
    ( (This)->lpVtbl -> GetPetName(This,p) ) 

#define IDog_SetPetName(This,p)	\
    ( (This)->lpVtbl -> SetPetName(This,p) ) 

#define IDog_IsBarking(This,pBool)	\
    ( (This)->lpVtbl -> IsBarking(This,pBool) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDog_INTERFACE_DEFINED__ */



#ifndef __Labrador_LIBRARY_DEFINED__
#define __Labrador_LIBRARY_DEFINED__

/* library Labrador */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_Labrador;

EXTERN_C const CLSID CLSID_CLabrador;

#ifdef __cplusplus

class DECLSPEC_UUID("CE8E837C-7A09-4C98-82D3-844D9BBF4AAD")
CLabrador;
#endif
#endif /* __Labrador_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


