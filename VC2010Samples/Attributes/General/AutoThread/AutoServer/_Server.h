

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for _Server.idl:
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

#ifndef ___Server_h__
#define ___Server_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAutoServ_FWD_DEFINED__
#define __IAutoServ_FWD_DEFINED__
typedef interface IAutoServ IAutoServ;

#endif 	/* __IAutoServ_FWD_DEFINED__ */


#ifndef __CAutoServ_FWD_DEFINED__
#define __CAutoServ_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAutoServ CAutoServ;
#else
typedef struct CAutoServ CAutoServ;
#endif /* __cplusplus */

#endif 	/* __CAutoServ_FWD_DEFINED__ */


/* header files for imported files */
#include "docobj.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IAutoServ_INTERFACE_DEFINED__
#define __IAutoServ_INTERFACE_DEFINED__

/* interface IAutoServ */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAutoServ;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1E2BF8D5-BF3B-4E35-BB79-90949E6A7349")
    IAutoServ : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Sleep( 
            /* [in] */ long delay) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAutoServVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoServ * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoServ * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoServ * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoServ * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoServ * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoServ * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoServ * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Sleep )( 
            IAutoServ * This,
            /* [in] */ long delay);
        
        END_INTERFACE
    } IAutoServVtbl;

    interface IAutoServ
    {
        CONST_VTBL struct IAutoServVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoServ_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoServ_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoServ_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoServ_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoServ_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoServ_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoServ_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAutoServ_Sleep(This,delay)	\
    ( (This)->lpVtbl -> Sleep(This,delay) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAutoServ_INTERFACE_DEFINED__ */



#ifndef __AutoServerLib_LIBRARY_DEFINED__
#define __AutoServerLib_LIBRARY_DEFINED__

/* library AutoServerLib */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_AutoServerLib;

EXTERN_C const CLSID CLSID_CAutoServ;

#ifdef __cplusplus

class DECLSPEC_UUID("3CD5B892-A27C-445D-AF50-8841D67F371E")
CAutoServ;
#endif
#endif /* __AutoServerLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


