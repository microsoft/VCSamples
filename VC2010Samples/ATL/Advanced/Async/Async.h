

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for Async.idl:
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

#ifndef __Async_h__
#define __Async_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IATLAsync_FWD_DEFINED__
#define __IATLAsync_FWD_DEFINED__
typedef interface IATLAsync IATLAsync;

#endif 	/* __IATLAsync_FWD_DEFINED__ */


#ifndef __CATLAsync_FWD_DEFINED__
#define __CATLAsync_FWD_DEFINED__

#ifdef __cplusplus
typedef class CATLAsync CATLAsync;
#else
typedef struct CATLAsync CATLAsync;
#endif /* __cplusplus */

#endif 	/* __CATLAsync_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IATLAsync_INTERFACE_DEFINED__
#define __IATLAsync_INTERFACE_DEFINED__

/* interface IATLAsync */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IATLAsync;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("012F24D5-35B0-11D0-BF2D-0000E8D0D146")
    IATLAsync : public IUnknown
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_URL( 
            /* [in] */ BSTR strURL) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_URL( 
            /* [retval][out] */ BSTR *pstrURL) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IATLAsyncVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IATLAsync * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IATLAsync * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IATLAsync * This);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_URL )( 
            IATLAsync * This,
            /* [in] */ BSTR strURL);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            IATLAsync * This,
            /* [retval][out] */ BSTR *pstrURL);
        
        END_INTERFACE
    } IATLAsyncVtbl;

    interface IATLAsync
    {
        CONST_VTBL struct IATLAsyncVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IATLAsync_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IATLAsync_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IATLAsync_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IATLAsync_put_URL(This,strURL)	\
    ( (This)->lpVtbl -> put_URL(This,strURL) ) 

#define IATLAsync_get_URL(This,pstrURL)	\
    ( (This)->lpVtbl -> get_URL(This,pstrURL) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IATLAsync_INTERFACE_DEFINED__ */



#ifndef __ASYNCLib_LIBRARY_DEFINED__
#define __ASYNCLib_LIBRARY_DEFINED__

/* library ASYNCLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ASYNCLib;

EXTERN_C const CLSID CLSID_CATLAsync;

#ifdef __cplusplus

class DECLSPEC_UUID("012F24D4-35B0-11D0-BF2D-0000E8D0D146")
CATLAsync;
#endif
#endif /* __ASYNCLib_LIBRARY_DEFINED__ */

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


