

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for AutoClient.idl:
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

#ifndef __AutoClient_h__
#define __AutoClient_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAutoCtl_FWD_DEFINED__
#define __IAutoCtl_FWD_DEFINED__
typedef interface IAutoCtl IAutoCtl;

#endif 	/* __IAutoCtl_FWD_DEFINED__ */


#ifndef __AutoCtl_FWD_DEFINED__
#define __AutoCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class AutoCtl AutoCtl;
#else
typedef struct AutoCtl AutoCtl;
#endif /* __cplusplus */

#endif 	/* __AutoCtl_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAutoCtl_INTERFACE_DEFINED__
#define __IAutoCtl_INTERFACE_DEFINED__

/* interface IAutoCtl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAutoCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6D89F2B-35F4-11D2-9375-00C04FD9757C")
    IAutoCtl : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Delay( 
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Delay( 
            /* [in] */ long newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAutoCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoCtl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoCtl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoCtl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoCtl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoCtl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoCtl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoCtl * This,
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
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Delay )( 
            IAutoCtl * This,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Delay )( 
            IAutoCtl * This,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IAutoCtlVtbl;

    interface IAutoCtl
    {
        CONST_VTBL struct IAutoCtlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoCtl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoCtl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoCtl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoCtl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAutoCtl_get_Delay(This,pVal)	\
    ( (This)->lpVtbl -> get_Delay(This,pVal) ) 

#define IAutoCtl_put_Delay(This,newVal)	\
    ( (This)->lpVtbl -> put_Delay(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAutoCtl_INTERFACE_DEFINED__ */



#ifndef __AUTOCLIENTLib_LIBRARY_DEFINED__
#define __AUTOCLIENTLib_LIBRARY_DEFINED__

/* library AUTOCLIENTLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AUTOCLIENTLib;

EXTERN_C const CLSID CLSID_AutoCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("A6D89F2C-35F4-11D2-9375-00C04FD9757C")
AutoCtl;
#endif
#endif /* __AUTOCLIENTLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


