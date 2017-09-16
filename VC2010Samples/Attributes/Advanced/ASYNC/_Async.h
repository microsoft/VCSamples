

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for _Async.idl:
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

#ifndef ___Async_h__
#define ___Async_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IATLAsyncAttrib_FWD_DEFINED__
#define __IATLAsyncAttrib_FWD_DEFINED__
typedef interface IATLAsyncAttrib IATLAsyncAttrib;

#endif 	/* __IATLAsyncAttrib_FWD_DEFINED__ */


#ifndef __CATLAsyncAttrib_FWD_DEFINED__
#define __CATLAsyncAttrib_FWD_DEFINED__

#ifdef __cplusplus
typedef class CATLAsyncAttrib CATLAsyncAttrib;
#else
typedef struct CATLAsyncAttrib CATLAsyncAttrib;
#endif /* __cplusplus */

#endif 	/* __CATLAsyncAttrib_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IATLAsyncAttrib_INTERFACE_DEFINED__
#define __IATLAsyncAttrib_INTERFACE_DEFINED__

/* interface IATLAsyncAttrib */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IATLAsyncAttrib;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("12BFAE1F-0BF9-4170-BE6E-31723B61C033")
    IATLAsyncAttrib : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_URL( 
            /* [in] */ BSTR strURL) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_URL( 
            /* [retval][out] */ BSTR *pstrURL) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IATLAsyncAttribVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IATLAsyncAttrib * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IATLAsyncAttrib * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IATLAsyncAttrib * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IATLAsyncAttrib * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IATLAsyncAttrib * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IATLAsyncAttrib * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IATLAsyncAttrib * This,
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
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_URL )( 
            IATLAsyncAttrib * This,
            /* [in] */ BSTR strURL);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            IATLAsyncAttrib * This,
            /* [retval][out] */ BSTR *pstrURL);
        
        END_INTERFACE
    } IATLAsyncAttribVtbl;

    interface IATLAsyncAttrib
    {
        CONST_VTBL struct IATLAsyncAttribVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IATLAsyncAttrib_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IATLAsyncAttrib_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IATLAsyncAttrib_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IATLAsyncAttrib_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IATLAsyncAttrib_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IATLAsyncAttrib_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IATLAsyncAttrib_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IATLAsyncAttrib_put_URL(This,strURL)	\
    ( (This)->lpVtbl -> put_URL(This,strURL) ) 

#define IATLAsyncAttrib_get_URL(This,pstrURL)	\
    ( (This)->lpVtbl -> get_URL(This,pstrURL) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IATLAsyncAttrib_INTERFACE_DEFINED__ */



#ifndef __ASYNCATTRIBLib_LIBRARY_DEFINED__
#define __ASYNCATTRIBLib_LIBRARY_DEFINED__

/* library ASYNCATTRIBLib */
/* [uuid][version] */ 


EXTERN_C const IID LIBID_ASYNCATTRIBLib;

EXTERN_C const CLSID CLSID_CATLAsyncAttrib;

#ifdef __cplusplus

class DECLSPEC_UUID("F447C21A-5F8C-4E88-B2D9-B76027CACFA5")
CATLAsyncAttrib;
#endif
#endif /* __ASYNCATTRIBLib_LIBRARY_DEFINED__ */

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


