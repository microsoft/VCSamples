

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for duck.idl:
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

#ifndef __duck_h__
#define __duck_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

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


#ifndef __IDuckInt_INTERFACE_DEFINED__
#define __IDuckInt_INTERFACE_DEFINED__

/* interface IDuckInt */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDuckInt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("120B72AE-65BF-11D0-9DDC-00A0C9034892")
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
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDuckInt * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDuckInt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDuckInt * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Quack )( 
            IDuckInt * This,
            BSTR szWhosCalling);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Flap )( 
            IDuckInt * This,
            BSTR szWhosCalling);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Paddle )( 
            IDuckInt * This,
            BSTR szWhosCalling);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Walk )( 
            IDuckInt * This,
            BSTR szWhosCalling);
        
        END_INTERFACE
    } IDuckIntVtbl;

    interface IDuckInt
    {
        CONST_VTBL struct IDuckIntVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDuckInt_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDuckInt_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDuckInt_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IDuckInt_Quack(This,szWhosCalling)	\
    ( (This)->lpVtbl -> Quack(This,szWhosCalling) ) 

#define IDuckInt_Flap(This,szWhosCalling)	\
    ( (This)->lpVtbl -> Flap(This,szWhosCalling) ) 

#define IDuckInt_Paddle(This,szWhosCalling)	\
    ( (This)->lpVtbl -> Paddle(This,szWhosCalling) ) 

#define IDuckInt_Walk(This,szWhosCalling)	\
    ( (This)->lpVtbl -> Walk(This,szWhosCalling) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




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

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


