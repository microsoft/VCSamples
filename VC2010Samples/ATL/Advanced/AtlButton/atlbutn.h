

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for atlbutn.idl:
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


#ifndef __atlbutn_h__
#define __atlbutn_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAtlButton_FWD_DEFINED__
#define __IAtlButton_FWD_DEFINED__
typedef interface IAtlButton IAtlButton;

#endif 	/* __IAtlButton_FWD_DEFINED__ */


#ifndef ___ATLButton_FWD_DEFINED__
#define ___ATLButton_FWD_DEFINED__
typedef interface _ATLButton _ATLButton;

#endif 	/* ___ATLButton_FWD_DEFINED__ */


#ifndef __CAtlButton_FWD_DEFINED__
#define __CAtlButton_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAtlButton CAtlButton;
#else
typedef struct CAtlButton CAtlButton;
#endif /* __cplusplus */

#endif 	/* __CAtlButton_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_atlbutn_0000_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_atlbutn_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_atlbutn_0000_0000_v0_0_s_ifspec;


#ifndef __ATLBUTNLib_LIBRARY_DEFINED__
#define __ATLBUTNLib_LIBRARY_DEFINED__

/* library ATLBUTNLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ATLBUTNLib;

#ifndef __IAtlButton_INTERFACE_DEFINED__
#define __IAtlButton_INTERFACE_DEFINED__

/* interface IAtlButton */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IAtlButton;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2499388F-3A64-11D0-BFAB-080000185165")
    IAtlButton : public IDispatch
    {
    public:
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_PictureStatic( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PictureStatic( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PictureStatic( 
            /* [retval][out] */ IPictureDisp **ppPicture) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_PictureHover( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PictureHover( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PictureHover( 
            /* [retval][out] */ IPictureDisp **ppPicture) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_PicturePush( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PicturePush( 
            /* [in] */ IPictureDisp *pPicture) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PicturePush( 
            /* [retval][out] */ IPictureDisp **ppPicture) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE _OnTimer( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IAtlButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAtlButton * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAtlButton * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAtlButton * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAtlButton * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAtlButton * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAtlButton * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAtlButton * This,
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
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_PictureStatic )( 
            IAtlButton * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PictureStatic )( 
            IAtlButton * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PictureStatic )( 
            IAtlButton * This,
            /* [retval][out] */ IPictureDisp **ppPicture);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_PictureHover )( 
            IAtlButton * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PictureHover )( 
            IAtlButton * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PictureHover )( 
            IAtlButton * This,
            /* [retval][out] */ IPictureDisp **ppPicture);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_PicturePush )( 
            IAtlButton * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PicturePush )( 
            IAtlButton * This,
            /* [in] */ IPictureDisp *pPicture);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PicturePush )( 
            IAtlButton * This,
            /* [retval][out] */ IPictureDisp **ppPicture);
        
        HRESULT ( STDMETHODCALLTYPE *_OnTimer )( 
            IAtlButton * This);
        
        END_INTERFACE
    } IAtlButtonVtbl;

    interface IAtlButton
    {
        CONST_VTBL struct IAtlButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAtlButton_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAtlButton_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAtlButton_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAtlButton_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAtlButton_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAtlButton_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAtlButton_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IAtlButton_putref_PictureStatic(This,pPicture)	\
    ( (This)->lpVtbl -> putref_PictureStatic(This,pPicture) ) 

#define IAtlButton_put_PictureStatic(This,pPicture)	\
    ( (This)->lpVtbl -> put_PictureStatic(This,pPicture) ) 

#define IAtlButton_get_PictureStatic(This,ppPicture)	\
    ( (This)->lpVtbl -> get_PictureStatic(This,ppPicture) ) 

#define IAtlButton_putref_PictureHover(This,pPicture)	\
    ( (This)->lpVtbl -> putref_PictureHover(This,pPicture) ) 

#define IAtlButton_put_PictureHover(This,pPicture)	\
    ( (This)->lpVtbl -> put_PictureHover(This,pPicture) ) 

#define IAtlButton_get_PictureHover(This,ppPicture)	\
    ( (This)->lpVtbl -> get_PictureHover(This,ppPicture) ) 

#define IAtlButton_putref_PicturePush(This,pPicture)	\
    ( (This)->lpVtbl -> putref_PicturePush(This,pPicture) ) 

#define IAtlButton_put_PicturePush(This,pPicture)	\
    ( (This)->lpVtbl -> put_PicturePush(This,pPicture) ) 

#define IAtlButton_get_PicturePush(This,ppPicture)	\
    ( (This)->lpVtbl -> get_PicturePush(This,ppPicture) ) 

#define IAtlButton__OnTimer(This)	\
    ( (This)->lpVtbl -> _OnTimer(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IAtlButton_INTERFACE_DEFINED__ */


#ifndef ___ATLButton_DISPINTERFACE_DEFINED__
#define ___ATLButton_DISPINTERFACE_DEFINED__

/* dispinterface _ATLButton */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__ATLButton;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("24993891-3A64-11D0-BFAB-080000185165")
    _ATLButton : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _ATLButtonVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _ATLButton * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _ATLButton * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _ATLButton * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _ATLButton * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _ATLButton * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _ATLButton * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _ATLButton * This,
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
    } _ATLButtonVtbl;

    interface _ATLButton
    {
        CONST_VTBL struct _ATLButtonVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ATLButton_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _ATLButton_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _ATLButton_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _ATLButton_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _ATLButton_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _ATLButton_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _ATLButton_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___ATLButton_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CAtlButton;

#ifdef __cplusplus

class DECLSPEC_UUID("2499388E-3A64-11D0-BFAB-080000185165")
CAtlButton;
#endif
#endif /* __ATLBUTNLib_LIBRARY_DEFINED__ */

/* interface __MIDL_itf_atlbutn_0000_0001 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_atlbutn_0000_0001_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_atlbutn_0000_0001_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


