

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for mfcatl.idl:
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

#ifndef __mfcatl_h_h__
#define __mfcatl_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IObjectTwo_FWD_DEFINED__
#define __IObjectTwo_FWD_DEFINED__
typedef interface IObjectTwo IObjectTwo;

#endif 	/* __IObjectTwo_FWD_DEFINED__ */


#ifndef __IObjectOne_FWD_DEFINED__
#define __IObjectOne_FWD_DEFINED__
typedef interface IObjectOne IObjectOne;

#endif 	/* __IObjectOne_FWD_DEFINED__ */


#ifndef __ObjectOne_FWD_DEFINED__
#define __ObjectOne_FWD_DEFINED__

#ifdef __cplusplus
typedef class ObjectOne ObjectOne;
#else
typedef struct ObjectOne ObjectOne;
#endif /* __cplusplus */

#endif 	/* __ObjectOne_FWD_DEFINED__ */


#ifndef __ObjectTwo_FWD_DEFINED__
#define __ObjectTwo_FWD_DEFINED__

#ifdef __cplusplus
typedef class ObjectTwo ObjectTwo;
#else
typedef struct ObjectTwo ObjectTwo;
#endif /* __cplusplus */

#endif 	/* __ObjectTwo_FWD_DEFINED__ */


/* header files for imported files */
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IObjectTwo_INTERFACE_DEFINED__
#define __IObjectTwo_INTERFACE_DEFINED__

/* interface IObjectTwo */
/* [helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IObjectTwo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5D0CE851-D909-11CF-91FC-00A0C903976F")
    IObjectTwo : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SayHello( 
            /* [retval][out] */ BSTR *bstr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IObjectTwoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IObjectTwo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IObjectTwo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IObjectTwo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IObjectTwo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IObjectTwo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IObjectTwo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IObjectTwo * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SayHello )( 
            IObjectTwo * This,
            /* [retval][out] */ BSTR *bstr);
        
        END_INTERFACE
    } IObjectTwoVtbl;

    interface IObjectTwo
    {
        CONST_VTBL struct IObjectTwoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectTwo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IObjectTwo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IObjectTwo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IObjectTwo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IObjectTwo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IObjectTwo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IObjectTwo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IObjectTwo_get_SayHello(This,bstr)	\
    ( (This)->lpVtbl -> get_SayHello(This,bstr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IObjectTwo_INTERFACE_DEFINED__ */



#ifndef __MfcAtl_LIBRARY_DEFINED__
#define __MfcAtl_LIBRARY_DEFINED__

/* library MfcAtl */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_MfcAtl;

#ifndef __IObjectOne_DISPINTERFACE_DEFINED__
#define __IObjectOne_DISPINTERFACE_DEFINED__

/* dispinterface IObjectOne */
/* [uuid] */ 


EXTERN_C const IID DIID_IObjectOne;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("5D0CE84F-D909-11CF-91FC-00A0C903976F")
    IObjectOne : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IObjectOneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IObjectOne * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IObjectOne * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IObjectOne * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IObjectOne * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IObjectOne * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IObjectOne * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IObjectOne * This,
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
    } IObjectOneVtbl;

    interface IObjectOne
    {
        CONST_VTBL struct IObjectOneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IObjectOne_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IObjectOne_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IObjectOne_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IObjectOne_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IObjectOne_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IObjectOne_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IObjectOne_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IObjectOne_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ObjectOne;

#ifdef __cplusplus

class DECLSPEC_UUID("5D0CE850-D909-11CF-91FC-00A0C903976F")
ObjectOne;
#endif

EXTERN_C const CLSID CLSID_ObjectTwo;

#ifdef __cplusplus

class DECLSPEC_UUID("F933FD54-6E04-42D4-B82A-10B1820EEE3E")
ObjectTwo;
#endif
#endif /* __MfcAtl_LIBRARY_DEFINED__ */

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


