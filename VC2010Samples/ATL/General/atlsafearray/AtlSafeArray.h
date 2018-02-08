

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for AtlSafeArray.idl:
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

#ifndef __AtlSafeArray_h__
#define __AtlSafeArray_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IArrayManager_FWD_DEFINED__
#define __IArrayManager_FWD_DEFINED__
typedef interface IArrayManager IArrayManager;

#endif 	/* __IArrayManager_FWD_DEFINED__ */


#ifndef __ArrayManager_FWD_DEFINED__
#define __ArrayManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class ArrayManager ArrayManager;
#else
typedef struct ArrayManager ArrayManager;
#endif /* __cplusplus */

#endif 	/* __ArrayManager_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IArrayManager_INTERFACE_DEFINED__
#define __IArrayManager_INTERFACE_DEFINED__

/* interface IArrayManager */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IArrayManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("029D6142-B334-4C05-80EF-ECDE5DF6BE82")
    IArrayManager : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetArray( 
            /* [retval][out] */ VARIANT *pvar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ BSTR bstr) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ ULONG nIndex) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Change( 
            /* [in] */ ULONG nIndex,
            /* [in] */ BSTR bstr) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IArrayManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IArrayManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IArrayManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IArrayManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IArrayManager * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IArrayManager * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IArrayManager * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IArrayManager * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetArray )( 
            IArrayManager * This,
            /* [retval][out] */ VARIANT *pvar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IArrayManager * This,
            /* [in] */ BSTR bstr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IArrayManager * This,
            /* [in] */ ULONG nIndex);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Change )( 
            IArrayManager * This,
            /* [in] */ ULONG nIndex,
            /* [in] */ BSTR bstr);
        
        END_INTERFACE
    } IArrayManagerVtbl;

    interface IArrayManager
    {
        CONST_VTBL struct IArrayManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IArrayManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IArrayManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IArrayManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IArrayManager_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IArrayManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IArrayManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IArrayManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IArrayManager_GetArray(This,pvar)	\
    ( (This)->lpVtbl -> GetArray(This,pvar) ) 

#define IArrayManager_Add(This,bstr)	\
    ( (This)->lpVtbl -> Add(This,bstr) ) 

#define IArrayManager_Remove(This,nIndex)	\
    ( (This)->lpVtbl -> Remove(This,nIndex) ) 

#define IArrayManager_Change(This,nIndex,bstr)	\
    ( (This)->lpVtbl -> Change(This,nIndex,bstr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IArrayManager_INTERFACE_DEFINED__ */



#ifndef __AtlSafeArrayLib_LIBRARY_DEFINED__
#define __AtlSafeArrayLib_LIBRARY_DEFINED__

/* library AtlSafeArrayLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_AtlSafeArrayLib;

EXTERN_C const CLSID CLSID_ArrayManager;

#ifdef __cplusplus

class DECLSPEC_UUID("3875AE6F-6B3B-497E-871F-B5FAEE689D30")
ArrayManager;
#endif
#endif /* __AtlSafeArrayLib_LIBRARY_DEFINED__ */

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


