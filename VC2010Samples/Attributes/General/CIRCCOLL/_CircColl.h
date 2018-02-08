

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Fri Sep 15 22:32:55 2017
 */
/* Compiler settings for _CircColl.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.00.0603 
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
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef ___CircColl_h__
#define ___CircColl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMyCircle_FWD_DEFINED__
#define __IMyCircle_FWD_DEFINED__
typedef interface IMyCircle IMyCircle;

#endif 	/* __IMyCircle_FWD_DEFINED__ */


#ifndef __IMyCircleCollection_FWD_DEFINED__
#define __IMyCircleCollection_FWD_DEFINED__
typedef interface IMyCircleCollection IMyCircleCollection;

#endif 	/* __IMyCircleCollection_FWD_DEFINED__ */


#ifndef __IMyCircleCollectionCreator_FWD_DEFINED__
#define __IMyCircleCollectionCreator_FWD_DEFINED__
typedef interface IMyCircleCollectionCreator IMyCircleCollectionCreator;

#endif 	/* __IMyCircleCollectionCreator_FWD_DEFINED__ */


#ifndef __CMyCircle_FWD_DEFINED__
#define __CMyCircle_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMyCircle CMyCircle;
#else
typedef struct CMyCircle CMyCircle;
#endif /* __cplusplus */

#endif 	/* __CMyCircle_FWD_DEFINED__ */


#ifndef __CMyCircleCollectionCreator_FWD_DEFINED__
#define __CMyCircleCollectionCreator_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMyCircleCollectionCreator CMyCircleCollectionCreator;
#else
typedef struct CMyCircleCollectionCreator CMyCircleCollectionCreator;
#endif /* __cplusplus */

#endif 	/* __CMyCircleCollectionCreator_FWD_DEFINED__ */


#ifndef __CMyCircleCollection_FWD_DEFINED__
#define __CMyCircleCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMyCircleCollection CMyCircleCollection;
#else
typedef struct CMyCircleCollection CMyCircleCollection;
#endif /* __cplusplus */

#endif 	/* __CMyCircleCollection_FWD_DEFINED__ */


/* header files for imported files */
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMyCircle_INTERFACE_DEFINED__
#define __IMyCircle_INTERFACE_DEFINED__

/* interface IMyCircle */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMyCircle;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("956ADD2D-4BFB-4CA3-A4B4-C87F204B5A48")
    IMyCircle : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_XCenter( 
            /* [retval][out] */ double *pXCenter) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_XCenter( 
            /* [in] */ double xCenter) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_YCenter( 
            /* [retval][out] */ double *pYCenter) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_YCenter( 
            /* [in] */ double YCenter) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Radius( 
            /* [retval][out] */ double *pRadius) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Radius( 
            /* [in] */ double Radius) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Label( 
            /* [retval][out] */ BSTR *pbstrLabel) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Label( 
            /* [in] */ BSTR bstrLabel) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMyCircleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMyCircle * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMyCircle * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMyCircle * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMyCircle * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMyCircle * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMyCircle * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMyCircle * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_XCenter )( 
            IMyCircle * This,
            /* [retval][out] */ double *pXCenter);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_XCenter )( 
            IMyCircle * This,
            /* [in] */ double xCenter);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_YCenter )( 
            IMyCircle * This,
            /* [retval][out] */ double *pYCenter);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_YCenter )( 
            IMyCircle * This,
            /* [in] */ double YCenter);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Radius )( 
            IMyCircle * This,
            /* [retval][out] */ double *pRadius);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Radius )( 
            IMyCircle * This,
            /* [in] */ double Radius);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Label )( 
            IMyCircle * This,
            /* [retval][out] */ BSTR *pbstrLabel);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Label )( 
            IMyCircle * This,
            /* [in] */ BSTR bstrLabel);
        
        END_INTERFACE
    } IMyCircleVtbl;

    interface IMyCircle
    {
        CONST_VTBL struct IMyCircleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMyCircle_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMyCircle_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMyCircle_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMyCircle_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMyCircle_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMyCircle_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMyCircle_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMyCircle_get_XCenter(This,pXCenter)	\
    ( (This)->lpVtbl -> get_XCenter(This,pXCenter) ) 

#define IMyCircle_put_XCenter(This,xCenter)	\
    ( (This)->lpVtbl -> put_XCenter(This,xCenter) ) 

#define IMyCircle_get_YCenter(This,pYCenter)	\
    ( (This)->lpVtbl -> get_YCenter(This,pYCenter) ) 

#define IMyCircle_put_YCenter(This,YCenter)	\
    ( (This)->lpVtbl -> put_YCenter(This,YCenter) ) 

#define IMyCircle_get_Radius(This,pRadius)	\
    ( (This)->lpVtbl -> get_Radius(This,pRadius) ) 

#define IMyCircle_put_Radius(This,Radius)	\
    ( (This)->lpVtbl -> put_Radius(This,Radius) ) 

#define IMyCircle_get_Label(This,pbstrLabel)	\
    ( (This)->lpVtbl -> get_Label(This,pbstrLabel) ) 

#define IMyCircle_put_Label(This,bstrLabel)	\
    ( (This)->lpVtbl -> put_Label(This,bstrLabel) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMyCircle_INTERFACE_DEFINED__ */


#ifndef __IMyCircleCollection_INTERFACE_DEFINED__
#define __IMyCircleCollection_INTERFACE_DEFINED__

/* interface IMyCircleCollection */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMyCircleCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EE86680D-E2CB-4C35-A6A3-3A2C5AD5A7E0")
    IMyCircleCollection : public IDispatch
    {
    public:
        virtual /* [helpstring][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *retval) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [in] */ long Index,
            /* [retval][out] */ VARIANT *retval) = 0;
        
        virtual /* [helpstring][id][restricted][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **retval) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMyCircleCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMyCircleCollection * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMyCircleCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMyCircleCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMyCircleCollection * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMyCircleCollection * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMyCircleCollection * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMyCircleCollection * This,
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
        
        /* [helpstring][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IMyCircleCollection * This,
            /* [retval][out] */ long *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Item )( 
            IMyCircleCollection * This,
            /* [in] */ long Index,
            /* [retval][out] */ VARIANT *retval);
        
        /* [helpstring][id][restricted][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IMyCircleCollection * This,
            /* [retval][out] */ IUnknown **retval);
        
        END_INTERFACE
    } IMyCircleCollectionVtbl;

    interface IMyCircleCollection
    {
        CONST_VTBL struct IMyCircleCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMyCircleCollection_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMyCircleCollection_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMyCircleCollection_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMyCircleCollection_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMyCircleCollection_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMyCircleCollection_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMyCircleCollection_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMyCircleCollection_get_Count(This,retval)	\
    ( (This)->lpVtbl -> get_Count(This,retval) ) 

#define IMyCircleCollection_get_Item(This,Index,retval)	\
    ( (This)->lpVtbl -> get_Item(This,Index,retval) ) 

#define IMyCircleCollection_get__NewEnum(This,retval)	\
    ( (This)->lpVtbl -> get__NewEnum(This,retval) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMyCircleCollection_INTERFACE_DEFINED__ */


#ifndef __IMyCircleCollectionCreator_INTERFACE_DEFINED__
#define __IMyCircleCollectionCreator_INTERFACE_DEFINED__

/* interface IMyCircleCollectionCreator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMyCircleCollectionCreator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C7FBF950-9080-448E-B5AE-58334E21E4A7")
    IMyCircleCollectionCreator : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCircles( 
            /* [in] */ short n,
            /* [retval][out] */ VARIANT *retval) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMyCircleCollectionCreatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMyCircleCollectionCreator * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMyCircleCollectionCreator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMyCircleCollectionCreator * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMyCircleCollectionCreator * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMyCircleCollectionCreator * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMyCircleCollectionCreator * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMyCircleCollectionCreator * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetCircles )( 
            IMyCircleCollectionCreator * This,
            /* [in] */ short n,
            /* [retval][out] */ VARIANT *retval);
        
        END_INTERFACE
    } IMyCircleCollectionCreatorVtbl;

    interface IMyCircleCollectionCreator
    {
        CONST_VTBL struct IMyCircleCollectionCreatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMyCircleCollectionCreator_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMyCircleCollectionCreator_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMyCircleCollectionCreator_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMyCircleCollectionCreator_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMyCircleCollectionCreator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMyCircleCollectionCreator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMyCircleCollectionCreator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMyCircleCollectionCreator_GetCircles(This,n,retval)	\
    ( (This)->lpVtbl -> GetCircles(This,n,retval) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMyCircleCollectionCreator_INTERFACE_DEFINED__ */



#ifndef __CIRCCOLLATTRIBLib_LIBRARY_DEFINED__
#define __CIRCCOLLATTRIBLib_LIBRARY_DEFINED__

/* library CIRCCOLLATTRIBLib */
/* [uuid][version] */ 


EXTERN_C const IID LIBID_CIRCCOLLATTRIBLib;

EXTERN_C const CLSID CLSID_CMyCircle;

#ifdef __cplusplus

class DECLSPEC_UUID("4C0CF699-6487-4707-8A63-E51DB3643516")
CMyCircle;
#endif

EXTERN_C const CLSID CLSID_CMyCircleCollectionCreator;

#ifdef __cplusplus

class DECLSPEC_UUID("4CC32AC1-AD28-4255-8533-CE71D7E4FD71")
CMyCircleCollectionCreator;
#endif

EXTERN_C const CLSID CLSID_CMyCircleCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("5537CB2B-5F39-405F-A2B7-8B55FA8B4D42")
CMyCircleCollection;
#endif
#endif /* __CIRCCOLLATTRIBLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


