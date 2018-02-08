

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for Aggreg.idl:
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

#ifndef __Aggreg_h__
#define __Aggreg_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAgg_FWD_DEFINED__
#define __IAgg_FWD_DEFINED__
typedef interface IAgg IAgg;

#endif 	/* __IAgg_FWD_DEFINED__ */


#ifndef __IAggBlind_FWD_DEFINED__
#define __IAggBlind_FWD_DEFINED__
typedef interface IAggBlind IAggBlind;

#endif 	/* __IAggBlind_FWD_DEFINED__ */


#ifndef __IAutoAgg_FWD_DEFINED__
#define __IAutoAgg_FWD_DEFINED__
typedef interface IAutoAgg IAutoAgg;

#endif 	/* __IAutoAgg_FWD_DEFINED__ */


#ifndef __IAutoAggB_FWD_DEFINED__
#define __IAutoAggB_FWD_DEFINED__
typedef interface IAutoAggB IAutoAggB;

#endif 	/* __IAutoAggB_FWD_DEFINED__ */


#ifndef __CAgg_FWD_DEFINED__
#define __CAgg_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAgg CAgg;
#else
typedef struct CAgg CAgg;
#endif /* __cplusplus */

#endif 	/* __CAgg_FWD_DEFINED__ */


#ifndef __CAggBlind_FWD_DEFINED__
#define __CAggBlind_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAggBlind CAggBlind;
#else
typedef struct CAggBlind CAggBlind;
#endif /* __cplusplus */

#endif 	/* __CAggBlind_FWD_DEFINED__ */


#ifndef __CAutoAgg_FWD_DEFINED__
#define __CAutoAgg_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAutoAgg CAutoAgg;
#else
typedef struct CAutoAgg CAutoAgg;
#endif /* __cplusplus */

#endif 	/* __CAutoAgg_FWD_DEFINED__ */


#ifndef __CAutoAggB_FWD_DEFINED__
#define __CAutoAggB_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAutoAggB CAutoAggB;
#else
typedef struct CAutoAggB CAutoAggB;
#endif /* __cplusplus */

#endif 	/* __CAutoAggB_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAgg_INTERFACE_DEFINED__
#define __IAgg_INTERFACE_DEFINED__

/* interface IAgg */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F9A68ED-DD9D-11CF-9462-00AA00BBAD7F")
    IAgg : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAggVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAgg * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAgg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAgg * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAgg * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAgg * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAgg * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAgg * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAgg * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } IAggVtbl;

    interface IAgg
    {
        CONST_VTBL struct IAggVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAgg_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAgg_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAgg_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAgg_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAgg_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAgg_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAgg_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAgg_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAgg_INTERFACE_DEFINED__ */


#ifndef __IAggBlind_INTERFACE_DEFINED__
#define __IAggBlind_INTERFACE_DEFINED__

/* interface IAggBlind */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAggBlind;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F9A68F2-DD9D-11CF-9462-00AA00BBAD7F")
    IAggBlind : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAggBlindVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAggBlind * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAggBlind * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAggBlind * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAggBlind * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAggBlind * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAggBlind * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAggBlind * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAggBlind * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } IAggBlindVtbl;

    interface IAggBlind
    {
        CONST_VTBL struct IAggBlindVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAggBlind_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAggBlind_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAggBlind_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAggBlind_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAggBlind_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAggBlind_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAggBlind_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAggBlind_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAggBlind_INTERFACE_DEFINED__ */


#ifndef __IAutoAgg_INTERFACE_DEFINED__
#define __IAutoAgg_INTERFACE_DEFINED__

/* interface IAutoAgg */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAutoAgg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F9A68F7-DD9D-11CF-9462-00AA00BBAD7F")
    IAutoAgg : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAutoAggVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoAgg * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoAgg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoAgg * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoAgg * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoAgg * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoAgg * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoAgg * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAutoAgg * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } IAutoAggVtbl;

    interface IAutoAgg
    {
        CONST_VTBL struct IAutoAggVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoAgg_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoAgg_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoAgg_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoAgg_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoAgg_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoAgg_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoAgg_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAutoAgg_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAutoAgg_INTERFACE_DEFINED__ */


#ifndef __IAutoAggB_INTERFACE_DEFINED__
#define __IAutoAggB_INTERFACE_DEFINED__

/* interface IAutoAggB */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAutoAggB;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4F9A68FC-DD9D-11CF-9462-00AA00BBAD7F")
    IAutoAggB : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAutoAggBVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoAggB * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoAggB * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoAggB * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoAggB * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoAggB * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoAggB * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoAggB * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IAutoAggB * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } IAutoAggBVtbl;

    interface IAutoAggB
    {
        CONST_VTBL struct IAutoAggBVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoAggB_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoAggB_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoAggB_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoAggB_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoAggB_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoAggB_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoAggB_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAutoAggB_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAutoAggB_INTERFACE_DEFINED__ */



#ifndef __AGGREGLib_LIBRARY_DEFINED__
#define __AGGREGLib_LIBRARY_DEFINED__

/* library AGGREGLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AGGREGLib;

EXTERN_C const CLSID CLSID_CAgg;

#ifdef __cplusplus

class DECLSPEC_UUID("4F9A68F1-DD9D-11CF-9462-00AA00BBAD7F")
CAgg;
#endif

EXTERN_C const CLSID CLSID_CAggBlind;

#ifdef __cplusplus

class DECLSPEC_UUID("4F9A68F6-DD9D-11CF-9462-00AA00BBAD7F")
CAggBlind;
#endif

EXTERN_C const CLSID CLSID_CAutoAgg;

#ifdef __cplusplus

class DECLSPEC_UUID("4F9A68FB-DD9D-11CF-9462-00AA00BBAD7F")
CAutoAgg;
#endif

EXTERN_C const CLSID CLSID_CAutoAggB;

#ifdef __cplusplus

class DECLSPEC_UUID("4F9A6900-DD9D-11CF-9462-00AA00BBAD7F")
CAutoAggB;
#endif
#endif /* __AGGREGLib_LIBRARY_DEFINED__ */

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


