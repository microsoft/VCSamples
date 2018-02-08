

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 04:14:07 2038
 */
/* Compiler settings for TCProps.idl:
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


#ifndef __TCProps_h__
#define __TCProps_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ITCExtendedControl_FWD_DEFINED__
#define __ITCExtendedControl_FWD_DEFINED__
typedef interface ITCExtendedControl ITCExtendedControl;

#endif 	/* __ITCExtendedControl_FWD_DEFINED__ */


#ifndef __TCExtPage_FWD_DEFINED__
#define __TCExtPage_FWD_DEFINED__

#ifdef __cplusplus
typedef class TCExtPage TCExtPage;
#else
typedef struct TCExtPage TCExtPage;
#endif /* __cplusplus */

#endif 	/* __TCExtPage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __TCPropsLib_LIBRARY_DEFINED__
#define __TCPropsLib_LIBRARY_DEFINED__

/* library TCPropsLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TCPropsLib;

#ifndef __ITCExtendedControl_INTERFACE_DEFINED__
#define __ITCExtendedControl_INTERFACE_DEFINED__

/* interface ITCExtendedControl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ITCExtendedControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3E6F10A8-E1D1-11d0-8E14-00C04FB68D60")
    ITCExtendedControl : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR bstrName) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pbstrName) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PositionX( 
            /* [in] */ long x) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PositionX( 
            /* [retval][out] */ long *px) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PositionY( 
            /* [in] */ long y) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PositionY( 
            /* [retval][out] */ long *py) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeX( 
            /* [in] */ long x) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeX( 
            /* [retval][out] */ long *px) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_SizeY( 
            /* [in] */ long y) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_SizeY( 
            /* [retval][out] */ long *py) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Activate( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Deactivate( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UIActivate( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE UIDeactivate( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ITCExtendedControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ITCExtendedControl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ITCExtendedControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ITCExtendedControl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ITCExtendedControl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ITCExtendedControl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ITCExtendedControl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ITCExtendedControl * This,
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
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Name )( 
            ITCExtendedControl * This,
            /* [in] */ BSTR bstrName);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            ITCExtendedControl * This,
            /* [retval][out] */ BSTR *pbstrName);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PositionX )( 
            ITCExtendedControl * This,
            /* [in] */ long x);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PositionX )( 
            ITCExtendedControl * This,
            /* [retval][out] */ long *px);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PositionY )( 
            ITCExtendedControl * This,
            /* [in] */ long y);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PositionY )( 
            ITCExtendedControl * This,
            /* [retval][out] */ long *py);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeX )( 
            ITCExtendedControl * This,
            /* [in] */ long x);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeX )( 
            ITCExtendedControl * This,
            /* [retval][out] */ long *px);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SizeY )( 
            ITCExtendedControl * This,
            /* [in] */ long y);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SizeY )( 
            ITCExtendedControl * This,
            /* [retval][out] */ long *py);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Activate )( 
            ITCExtendedControl * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *Deactivate )( 
            ITCExtendedControl * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UIActivate )( 
            ITCExtendedControl * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *UIDeactivate )( 
            ITCExtendedControl * This);
        
        END_INTERFACE
    } ITCExtendedControlVtbl;

    interface ITCExtendedControl
    {
        CONST_VTBL struct ITCExtendedControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ITCExtendedControl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ITCExtendedControl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ITCExtendedControl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ITCExtendedControl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ITCExtendedControl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ITCExtendedControl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ITCExtendedControl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ITCExtendedControl_put_Name(This,bstrName)	\
    ( (This)->lpVtbl -> put_Name(This,bstrName) ) 

#define ITCExtendedControl_get_Name(This,pbstrName)	\
    ( (This)->lpVtbl -> get_Name(This,pbstrName) ) 

#define ITCExtendedControl_put_PositionX(This,x)	\
    ( (This)->lpVtbl -> put_PositionX(This,x) ) 

#define ITCExtendedControl_get_PositionX(This,px)	\
    ( (This)->lpVtbl -> get_PositionX(This,px) ) 

#define ITCExtendedControl_put_PositionY(This,y)	\
    ( (This)->lpVtbl -> put_PositionY(This,y) ) 

#define ITCExtendedControl_get_PositionY(This,py)	\
    ( (This)->lpVtbl -> get_PositionY(This,py) ) 

#define ITCExtendedControl_put_SizeX(This,x)	\
    ( (This)->lpVtbl -> put_SizeX(This,x) ) 

#define ITCExtendedControl_get_SizeX(This,px)	\
    ( (This)->lpVtbl -> get_SizeX(This,px) ) 

#define ITCExtendedControl_put_SizeY(This,y)	\
    ( (This)->lpVtbl -> put_SizeY(This,y) ) 

#define ITCExtendedControl_get_SizeY(This,py)	\
    ( (This)->lpVtbl -> get_SizeY(This,py) ) 

#define ITCExtendedControl_Activate(This)	\
    ( (This)->lpVtbl -> Activate(This) ) 

#define ITCExtendedControl_Deactivate(This)	\
    ( (This)->lpVtbl -> Deactivate(This) ) 

#define ITCExtendedControl_UIActivate(This)	\
    ( (This)->lpVtbl -> UIActivate(This) ) 

#define ITCExtendedControl_UIDeactivate(This)	\
    ( (This)->lpVtbl -> UIDeactivate(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ITCExtendedControl_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_TCExtPage;

#ifdef __cplusplus

class DECLSPEC_UUID("AB39F080-0F5D-11D1-8E2F-00C04FB68D60")
TCExtPage;
#endif
#endif /* __TCPropsLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


