

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for _circ.idl:
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

#ifndef ___circ_h__
#define ___circ_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICircCtl_FWD_DEFINED__
#define __ICircCtl_FWD_DEFINED__
typedef interface ICircCtl ICircCtl;

#endif 	/* __ICircCtl_FWD_DEFINED__ */


#ifndef ___CircEvents_FWD_DEFINED__
#define ___CircEvents_FWD_DEFINED__
typedef interface _CircEvents _CircEvents;

#endif 	/* ___CircEvents_FWD_DEFINED__ */


#ifndef __CCircCtl_FWD_DEFINED__
#define __CCircCtl_FWD_DEFINED__

#ifdef __cplusplus
typedef class CCircCtl CCircCtl;
#else
typedef struct CCircCtl CCircCtl;
#endif /* __cplusplus */

#endif 	/* __CCircCtl_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICircCtl_INTERFACE_DEFINED__
#define __ICircCtl_INTERFACE_DEFINED__

/* interface ICircCtl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICircCtl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0806E754-1256-45DE-A026-EFF47B37304E")
    ICircCtl : public IDispatch
    {
    public:
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Caption( 
            /* [in] */ BSTR pCaption) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Caption( 
            /* [retval][out] */ BSTR *ppCaption) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Enabled( 
            /* [in] */ VARIANT_BOOL vbool) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pbool) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_BackColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_BackColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ForeColor( 
            /* [in] */ OLE_COLOR clr) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ForeColor( 
            /* [retval][out] */ OLE_COLOR *pclr) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp **ppFont) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICircCtlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICircCtl * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICircCtl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICircCtl * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ICircCtl * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ICircCtl * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ICircCtl * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ICircCtl * This,
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
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Caption )( 
            ICircCtl * This,
            /* [in] */ BSTR pCaption);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Caption )( 
            ICircCtl * This,
            /* [retval][out] */ BSTR *ppCaption);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Enabled )( 
            ICircCtl * This,
            /* [in] */ VARIANT_BOOL vbool);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            ICircCtl * This,
            /* [retval][out] */ VARIANT_BOOL *pbool);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_BackColor )( 
            ICircCtl * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_BackColor )( 
            ICircCtl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ForeColor )( 
            ICircCtl * This,
            /* [in] */ OLE_COLOR clr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ForeColor )( 
            ICircCtl * This,
            /* [retval][out] */ OLE_COLOR *pclr);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            ICircCtl * This,
            /* [in] */ IFontDisp *pFont);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Font )( 
            ICircCtl * This,
            /* [in] */ IFontDisp *pFont);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            ICircCtl * This,
            /* [retval][out] */ IFontDisp **ppFont);
        
        END_INTERFACE
    } ICircCtlVtbl;

    interface ICircCtl
    {
        CONST_VTBL struct ICircCtlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICircCtl_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICircCtl_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICircCtl_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICircCtl_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define ICircCtl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define ICircCtl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define ICircCtl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define ICircCtl_put_Caption(This,pCaption)	\
    ( (This)->lpVtbl -> put_Caption(This,pCaption) ) 

#define ICircCtl_get_Caption(This,ppCaption)	\
    ( (This)->lpVtbl -> get_Caption(This,ppCaption) ) 

#define ICircCtl_put_Enabled(This,vbool)	\
    ( (This)->lpVtbl -> put_Enabled(This,vbool) ) 

#define ICircCtl_get_Enabled(This,pbool)	\
    ( (This)->lpVtbl -> get_Enabled(This,pbool) ) 

#define ICircCtl_put_BackColor(This,clr)	\
    ( (This)->lpVtbl -> put_BackColor(This,clr) ) 

#define ICircCtl_get_BackColor(This,pclr)	\
    ( (This)->lpVtbl -> get_BackColor(This,pclr) ) 

#define ICircCtl_put_ForeColor(This,clr)	\
    ( (This)->lpVtbl -> put_ForeColor(This,clr) ) 

#define ICircCtl_get_ForeColor(This,pclr)	\
    ( (This)->lpVtbl -> get_ForeColor(This,pclr) ) 

#define ICircCtl_put_Font(This,pFont)	\
    ( (This)->lpVtbl -> put_Font(This,pFont) ) 

#define ICircCtl_putref_Font(This,pFont)	\
    ( (This)->lpVtbl -> putref_Font(This,pFont) ) 

#define ICircCtl_get_Font(This,ppFont)	\
    ( (This)->lpVtbl -> get_Font(This,ppFont) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICircCtl_INTERFACE_DEFINED__ */



#ifndef __CIRCAttrib_LIBRARY_DEFINED__
#define __CIRCAttrib_LIBRARY_DEFINED__

/* library CIRCAttrib */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_CIRCAttrib;

#ifndef ___CircEvents_DISPINTERFACE_DEFINED__
#define ___CircEvents_DISPINTERFACE_DEFINED__

/* dispinterface _CircEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__CircEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("544B15ED-AB2F-479E-8AC7-1344CD4FC30E")
    _CircEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _CircEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _CircEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _CircEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _CircEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _CircEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _CircEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _CircEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _CircEvents * This,
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
    } _CircEventsVtbl;

    interface _CircEvents
    {
        CONST_VTBL struct _CircEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _CircEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _CircEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _CircEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _CircEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _CircEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _CircEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _CircEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___CircEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CCircCtl;

#ifdef __cplusplus

class DECLSPEC_UUID("BDB53AB2-6073-48DF-9974-0C0D8047A54F")
CCircCtl;
#endif
#endif /* __CIRCAttrib_LIBRARY_DEFINED__ */

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


