

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


#ifndef __IOuter_FWD_DEFINED__
#define __IOuter_FWD_DEFINED__
typedef interface IOuter IOuter;

#endif 	/* __IOuter_FWD_DEFINED__ */


#ifndef __ITearOff1_FWD_DEFINED__
#define __ITearOff1_FWD_DEFINED__
typedef interface ITearOff1 ITearOff1;

#endif 	/* __ITearOff1_FWD_DEFINED__ */


#ifndef __ITearOff2_FWD_DEFINED__
#define __ITearOff2_FWD_DEFINED__
typedef interface ITearOff2 ITearOff2;

#endif 	/* __ITearOff2_FWD_DEFINED__ */


#ifndef __IChain_FWD_DEFINED__
#define __IChain_FWD_DEFINED__
typedef interface IChain IChain;

#endif 	/* __IChain_FWD_DEFINED__ */


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


#ifndef __CChain_FWD_DEFINED__
#define __CChain_FWD_DEFINED__

#ifdef __cplusplus
typedef class CChain CChain;
#else
typedef struct CChain CChain;
#endif /* __cplusplus */

#endif 	/* __CChain_FWD_DEFINED__ */


#ifndef __COuter_FWD_DEFINED__
#define __COuter_FWD_DEFINED__

#ifdef __cplusplus
typedef class COuter COuter;
#else
typedef struct COuter COuter;
#endif /* __cplusplus */

#endif 	/* __COuter_FWD_DEFINED__ */


/* header files for imported files */
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAgg_INTERFACE_DEFINED__
#define __IAgg_INTERFACE_DEFINED__

/* interface IAgg */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAgg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C38266AF-50F3-40B1-82D8-4AAF5EDA1BC7")
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
    
    MIDL_INTERFACE("0A0DDEDC-C422-4BB3-9869-4FED020B66C5")
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
    
    MIDL_INTERFACE("2D12F117-2C91-4385-A0E4-2E8E690C5EDF")
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
    
    MIDL_INTERFACE("5F77FE09-2289-4C0C-B435-9EDEE7FECEC8")
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


#ifndef __IOuter_INTERFACE_DEFINED__
#define __IOuter_INTERFACE_DEFINED__

/* interface IOuter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOuter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A2FFAC63-301D-48A0-BC0A-9B4954112E0C")
    IOuter : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [in] */ short n,
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IOuterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IOuter * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IOuter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IOuter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IOuter * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IOuter * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IOuter * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IOuter * This,
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
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IOuter * This,
            /* [in] */ short n,
            /* [retval][out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } IOuterVtbl;

    interface IOuter
    {
        CONST_VTBL struct IOuterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOuter_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IOuter_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IOuter_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IOuter_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IOuter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IOuter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IOuter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IOuter_GetName(This,n,pbstrName)	\
    ( (This)->lpVtbl -> GetName(This,n,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IOuter_INTERFACE_DEFINED__ */


#ifndef __ITearOff1_INTERFACE_DEFINED__
#define __ITearOff1_INTERFACE_DEFINED__

/* interface ITearOff1 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITearOff1;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DFF2676C-9DFA-4E89-A73A-6707AEE93936")
    ITearOff1 : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITearOff1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITearOff1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITearOff1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITearOff1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITearOff1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITearOff1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITearOff1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITearOff1 * This,
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
            ITearOff1 * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } ITearOff1Vtbl;

    interface ITearOff1
    {
        CONST_VTBL struct ITearOff1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITearOff1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITearOff1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITearOff1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITearOff1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITearOff1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITearOff1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITearOff1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITearOff1_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITearOff1_INTERFACE_DEFINED__ */


#ifndef __ITearOff2_INTERFACE_DEFINED__
#define __ITearOff2_INTERFACE_DEFINED__

/* interface ITearOff2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITearOff2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DC9000DA-F6B4-44C1-BF3C-75C28DE5F993")
    ITearOff2 : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITearOff2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITearOff2 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITearOff2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITearOff2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITearOff2 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITearOff2 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITearOff2 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITearOff2 * This,
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
            ITearOff2 * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } ITearOff2Vtbl;

    interface ITearOff2
    {
        CONST_VTBL struct ITearOff2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITearOff2_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITearOff2_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITearOff2_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITearOff2_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITearOff2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITearOff2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITearOff2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITearOff2_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITearOff2_INTERFACE_DEFINED__ */


#ifndef __IChain_INTERFACE_DEFINED__
#define __IChain_INTERFACE_DEFINED__

/* interface IChain */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IChain;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DCCD0C8A-7C0D-4FA2-A9CA-719219A51F45")
    IChain : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name2( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IChainVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IChain * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IChain * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IChain * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IChain * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IChain * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IChain * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IChain * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name2 )( 
            IChain * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } IChainVtbl;

    interface IChain
    {
        CONST_VTBL struct IChainVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IChain_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IChain_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IChain_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IChain_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IChain_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IChain_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IChain_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IChain_get_Name2(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name2(This,pbstrName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IChain_INTERFACE_DEFINED__ */



#ifndef __COMMapLib_LIBRARY_DEFINED__
#define __COMMapLib_LIBRARY_DEFINED__

/* library COMMapLib */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_COMMapLib;

EXTERN_C const CLSID CLSID_CAgg;

#ifdef __cplusplus

class DECLSPEC_UUID("B27F2CE1-D1B9-42B3-9E4C-9E7CA7767043")
CAgg;
#endif

EXTERN_C const CLSID CLSID_CAggBlind;

#ifdef __cplusplus

class DECLSPEC_UUID("A86DF044-ED8E-40AD-B00A-EAE3D6DE49AA")
CAggBlind;
#endif

EXTERN_C const CLSID CLSID_CAutoAgg;

#ifdef __cplusplus

class DECLSPEC_UUID("501153E5-FAD9-4E5C-9C3D-8CC815D4F60E")
CAutoAgg;
#endif

EXTERN_C const CLSID CLSID_CAutoAggB;

#ifdef __cplusplus

class DECLSPEC_UUID("4CA740C4-92B7-4F39-8309-C6DA39D7A255")
CAutoAggB;
#endif

EXTERN_C const CLSID CLSID_CChain;

#ifdef __cplusplus

class DECLSPEC_UUID("4E5DD450-3EA0-473D-9AB5-55E7EB597348")
CChain;
#endif

EXTERN_C const CLSID CLSID_COuter;

#ifdef __cplusplus

class DECLSPEC_UUID("CAE80FFC-E058-430B-AEC2-64C7585B5EBE")
COuter;
#endif
#endif /* __COMMapLib_LIBRARY_DEFINED__ */

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


