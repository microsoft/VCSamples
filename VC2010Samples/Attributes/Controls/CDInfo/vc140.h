

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

#ifndef __ICDInfo_FWD_DEFINED__
#define __ICDInfo_FWD_DEFINED__
typedef interface ICDInfo ICDInfo;

#endif 	/* __ICDInfo_FWD_DEFINED__ */


#ifndef __CDEvents_FWD_DEFINED__
#define __CDEvents_FWD_DEFINED__
typedef interface CDEvents CDEvents;

#endif 	/* __CDEvents_FWD_DEFINED__ */


#ifndef __CCDInfo_FWD_DEFINED__
#define __CCDInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CCDInfo CCDInfo;
#else
typedef struct CCDInfo CCDInfo;
#endif /* __cplusplus */

#endif 	/* __CCDInfo_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICDInfo_INTERFACE_DEFINED__
#define __ICDInfo_INTERFACE_DEFINED__

/* interface ICDInfo */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICDInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CD73CB20-85C3-4B0B-A1D4-EBB911AF3E68")
    ICDInfo : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Tracks( 
            /* [retval][out] */ short *pTracks) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Tracks( 
            /* [in] */ short Tracks) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Length( 
            /* [in] */ short Track,
            /* [retval][out] */ short *pLength) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Length( 
            /* [in] */ short Track,
            /* [in] */ short nLength) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TotalLength( 
            /* [retval][out] */ short *pLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Read( 
            /* [retval][out] */ short *pTracks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Redraw( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Play( 
            /* [in] */ short Track) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICDInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICDInfo * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICDInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICDInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICDInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICDInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICDInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICDInfo * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Tracks )( 
            ICDInfo * This,
            /* [retval][out] */ short *pTracks);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Tracks )( 
            ICDInfo * This,
            /* [in] */ short Tracks);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Length )( 
            ICDInfo * This,
            /* [in] */ short Track,
            /* [retval][out] */ short *pLength);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Length )( 
            ICDInfo * This,
            /* [in] */ short Track,
            /* [in] */ short nLength);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TotalLength )( 
            ICDInfo * This,
            /* [retval][out] */ short *pLength);
        
        HRESULT ( STDMETHODCALLTYPE *Read )( 
            ICDInfo * This,
            /* [retval][out] */ short *pTracks);
        
        HRESULT ( STDMETHODCALLTYPE *Redraw )( 
            ICDInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Play )( 
            ICDInfo * This,
            /* [in] */ short Track);
        
        END_INTERFACE
    } ICDInfoVtbl;

    interface ICDInfo
    {
        CONST_VTBL struct ICDInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICDInfo_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICDInfo_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICDInfo_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICDInfo_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICDInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICDInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICDInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICDInfo_get_Tracks(This,pTracks)	\
    ( (This)->lpVtbl -> get_Tracks(This,pTracks) ) 

#define ICDInfo_put_Tracks(This,Tracks)	\
    ( (This)->lpVtbl -> put_Tracks(This,Tracks) ) 

#define ICDInfo_get_Length(This,Track,pLength)	\
    ( (This)->lpVtbl -> get_Length(This,Track,pLength) ) 

#define ICDInfo_put_Length(This,Track,nLength)	\
    ( (This)->lpVtbl -> put_Length(This,Track,nLength) ) 

#define ICDInfo_get_TotalLength(This,pLength)	\
    ( (This)->lpVtbl -> get_TotalLength(This,pLength) ) 

#define ICDInfo_Read(This,pTracks)	\
    ( (This)->lpVtbl -> Read(This,pTracks) ) 

#define ICDInfo_Redraw(This)	\
    ( (This)->lpVtbl -> Redraw(This) ) 

#define ICDInfo_Play(This,Track)	\
    ( (This)->lpVtbl -> Play(This,Track) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICDInfo_INTERFACE_DEFINED__ */



#ifndef __CDINFOAttrib_LIBRARY_DEFINED__
#define __CDINFOAttrib_LIBRARY_DEFINED__

/* library CDINFOAttrib */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_CDINFOAttrib;

#ifndef __CDEvents_DISPINTERFACE_DEFINED__
#define __CDEvents_DISPINTERFACE_DEFINED__

/* dispinterface CDEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID_CDEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7A4C656C-EDC3-45FE-84CE-0D7C96C45B85")
    CDEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct CDEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            CDEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            CDEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            CDEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            CDEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            CDEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            CDEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            CDEvents * This,
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
    } CDEventsVtbl;

    interface CDEvents
    {
        CONST_VTBL struct CDEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CDEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define CDEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define CDEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define CDEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define CDEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define CDEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define CDEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __CDEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CCDInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("B091C2B4-ED17-491E-BFED-903EB209B26D")
CCDInfo;
#endif
#endif /* __CDINFOAttrib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


