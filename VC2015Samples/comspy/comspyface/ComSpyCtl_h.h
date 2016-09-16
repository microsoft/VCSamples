

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.00.0603 */
/* at Wed Feb 04 17:32:24 2015
 */
/* Compiler settings for ComSpyCtl.idl:
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

#ifndef __ComSpyCtl_h_h__
#define __ComSpyCtl_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IComSpy_FWD_DEFINED__
#define __IComSpy_FWD_DEFINED__
typedef interface IComSpy IComSpy;

#endif 	/* __IComSpy_FWD_DEFINED__ */


#ifndef __ICOMSysLCE_FWD_DEFINED__
#define __ICOMSysLCE_FWD_DEFINED__
typedef interface ICOMSysLCE ICOMSysLCE;

#endif 	/* __ICOMSysLCE_FWD_DEFINED__ */


#ifndef __ComSpy_FWD_DEFINED__
#define __ComSpy_FWD_DEFINED__

#ifdef __cplusplus
typedef class ComSpy ComSpy;
#else
typedef struct ComSpy ComSpy;
#endif /* __cplusplus */

#endif 	/* __ComSpy_FWD_DEFINED__ */


#ifndef __ComSpyPropPage_FWD_DEFINED__
#define __ComSpyPropPage_FWD_DEFINED__

#ifdef __cplusplus
typedef class ComSpyPropPage ComSpyPropPage;
#else
typedef struct ComSpyPropPage ComSpyPropPage;
#endif /* __cplusplus */

#endif 	/* __ComSpyPropPage_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_ComSpyCtl_0000_0000 */
/* [local] */ 

#define DISPID_LOGFILE		5
#define DISPID_GRIDLINES	6
#define DISPID_COLWIDTH		8
#define DISPID_AUDIT		17
typedef /* [public][public] */ 
enum __MIDL___MIDL_itf_ComSpyCtl_0000_0000_0001
    {
        Application	= 0,
        Thread	= ( Application + 1 ) ,
        Instance	= ( Thread + 1 ) ,
        Transaction	= ( Instance + 1 ) ,
        Method	= ( Transaction + 1 ) ,
        Object	= ( Method + 1 ) ,
        Resource	= ( Object + 1 ) ,
        User	= ( Resource + 1 ) ,
        Security	= ( User + 1 ) ,
        ObjectPool	= ( Security + 1 ) ,
        ObjectPool2	= ( ObjectPool + 1 ) ,
        ObjectConstruction	= ( ObjectPool2 + 1 ) ,
        Activity	= ( ObjectConstruction + 1 ) ,
        Identity	= ( Activity + 1 ) ,
        QC	= ( Identity + 1 ) ,
        Exception	= ( QC + 1 ) ,
        CRM	= ( Exception + 1 ) ,
        EventStore	= ( CRM + 1 ) ,
        LoadBalancing	= ( EventStore + 1 ) 
    } 	EventEnum;



extern RPC_IF_HANDLE __MIDL_itf_ComSpyCtl_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ComSpyCtl_0000_0000_v0_0_s_ifspec;

#ifndef __IComSpy_INTERFACE_DEFINED__
#define __IComSpy_INTERFACE_DEFINED__

/* interface IComSpy */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IComSpy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A9B39080-AAD0-11D0-B183-00AA00BA3258")
    IComSpy : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Window( 
            /* [retval][out] */ LONG_PTR *phwnd) = 0;
        
        virtual /* [id][propputref] */ HRESULT STDMETHODCALLTYPE putref_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Font( 
            /* [in] */ IFontDisp *pFont) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Font( 
            /* [retval][out] */ IFontDisp **ppFont) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogFile( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowGridLines( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowGridLines( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ColWidth( 
            short nColumn,
            /* [retval][out] */ long *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ColWidth( 
            short nColumn,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SelectApplications( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveToFile( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ClearAllEvents( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE About( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_LogToFile( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_LogToFile( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseFont( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ShowOnScreen( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ShowOnScreen( 
            /* [in] */ BOOL newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ChooseLogFile( 
            /* [out] */ BSTR *sLogFileName,
            /* [out] */ BOOL *bCanceled) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Audit( 
            /* [retval][out] */ BOOL *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Audit( 
            /* [in] */ BOOL newVal) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IComSpyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IComSpy * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IComSpy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IComSpy * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IComSpy * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IComSpy * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IComSpy * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IComSpy * This,
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
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Window )( 
            IComSpy * This,
            /* [retval][out] */ LONG_PTR *phwnd);
        
        /* [id][propputref] */ HRESULT ( STDMETHODCALLTYPE *putref_Font )( 
            IComSpy * This,
            /* [in] */ IFontDisp *pFont);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Font )( 
            IComSpy * This,
            /* [in] */ IFontDisp *pFont);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Font )( 
            IComSpy * This,
            /* [retval][out] */ IFontDisp **ppFont);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogFile )( 
            IComSpy * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogFile )( 
            IComSpy * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowGridLines )( 
            IComSpy * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowGridLines )( 
            IComSpy * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ColWidth )( 
            IComSpy * This,
            short nColumn,
            /* [retval][out] */ long *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ColWidth )( 
            IComSpy * This,
            short nColumn,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SelectApplications )( 
            IComSpy * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveToFile )( 
            IComSpy * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ClearAllEvents )( 
            IComSpy * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *About )( 
            IComSpy * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogToFile )( 
            IComSpy * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LogToFile )( 
            IComSpy * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChooseFont )( 
            IComSpy * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ShowOnScreen )( 
            IComSpy * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ShowOnScreen )( 
            IComSpy * This,
            /* [in] */ BOOL newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ChooseLogFile )( 
            IComSpy * This,
            /* [out] */ BSTR *sLogFileName,
            /* [out] */ BOOL *bCanceled);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Audit )( 
            IComSpy * This,
            /* [retval][out] */ BOOL *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Audit )( 
            IComSpy * This,
            /* [in] */ BOOL newVal);
        
        END_INTERFACE
    } IComSpyVtbl;

    interface IComSpy
    {
        CONST_VTBL struct IComSpyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IComSpy_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IComSpy_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IComSpy_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IComSpy_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IComSpy_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IComSpy_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IComSpy_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IComSpy_get_Window(This,phwnd)	\
    ( (This)->lpVtbl -> get_Window(This,phwnd) ) 

#define IComSpy_putref_Font(This,pFont)	\
    ( (This)->lpVtbl -> putref_Font(This,pFont) ) 

#define IComSpy_put_Font(This,pFont)	\
    ( (This)->lpVtbl -> put_Font(This,pFont) ) 

#define IComSpy_get_Font(This,ppFont)	\
    ( (This)->lpVtbl -> get_Font(This,ppFont) ) 

#define IComSpy_get_LogFile(This,pVal)	\
    ( (This)->lpVtbl -> get_LogFile(This,pVal) ) 

#define IComSpy_put_LogFile(This,newVal)	\
    ( (This)->lpVtbl -> put_LogFile(This,newVal) ) 

#define IComSpy_get_ShowGridLines(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowGridLines(This,pVal) ) 

#define IComSpy_put_ShowGridLines(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowGridLines(This,newVal) ) 

#define IComSpy_get_ColWidth(This,nColumn,pVal)	\
    ( (This)->lpVtbl -> get_ColWidth(This,nColumn,pVal) ) 

#define IComSpy_put_ColWidth(This,nColumn,newVal)	\
    ( (This)->lpVtbl -> put_ColWidth(This,nColumn,newVal) ) 

#define IComSpy_SelectApplications(This)	\
    ( (This)->lpVtbl -> SelectApplications(This) ) 

#define IComSpy_SaveToFile(This)	\
    ( (This)->lpVtbl -> SaveToFile(This) ) 

#define IComSpy_ClearAllEvents(This)	\
    ( (This)->lpVtbl -> ClearAllEvents(This) ) 

#define IComSpy_About(This)	\
    ( (This)->lpVtbl -> About(This) ) 

#define IComSpy_get_LogToFile(This,pVal)	\
    ( (This)->lpVtbl -> get_LogToFile(This,pVal) ) 

#define IComSpy_put_LogToFile(This,newVal)	\
    ( (This)->lpVtbl -> put_LogToFile(This,newVal) ) 

#define IComSpy_ChooseFont(This)	\
    ( (This)->lpVtbl -> ChooseFont(This) ) 

#define IComSpy_get_ShowOnScreen(This,pVal)	\
    ( (This)->lpVtbl -> get_ShowOnScreen(This,pVal) ) 

#define IComSpy_put_ShowOnScreen(This,newVal)	\
    ( (This)->lpVtbl -> put_ShowOnScreen(This,newVal) ) 

#define IComSpy_ChooseLogFile(This,sLogFileName,bCanceled)	\
    ( (This)->lpVtbl -> ChooseLogFile(This,sLogFileName,bCanceled) ) 

#define IComSpy_get_Audit(This,pVal)	\
    ( (This)->lpVtbl -> get_Audit(This,pVal) ) 

#define IComSpy_put_Audit(This,newVal)	\
    ( (This)->lpVtbl -> put_Audit(This,newVal) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IComSpy_INTERFACE_DEFINED__ */


#ifndef __ICOMSysLCE_INTERFACE_DEFINED__
#define __ICOMSysLCE_INTERFACE_DEFINED__

/* interface ICOMSysLCE */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ICOMSysLCE;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0243D433-3849-11d2-89BB-00C04F99140F")
    ICOMSysLCE : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEventType( 
            /* [out] */ EventEnum *e) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEventClass( 
            /* [out] */ LPGUID guid) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Install( 
            /* [in] */ BSTR *PropertyName,
            /* [in] */ VARIANT PropertyValue) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Uninstall( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct ICOMSysLCEVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICOMSysLCE * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICOMSysLCE * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICOMSysLCE * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventType )( 
            ICOMSysLCE * This,
            /* [out] */ EventEnum *e);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEventClass )( 
            ICOMSysLCE * This,
            /* [out] */ LPGUID guid);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Install )( 
            ICOMSysLCE * This,
            /* [in] */ BSTR *PropertyName,
            /* [in] */ VARIANT PropertyValue);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Uninstall )( 
            ICOMSysLCE * This);
        
        END_INTERFACE
    } ICOMSysLCEVtbl;

    interface ICOMSysLCE
    {
        CONST_VTBL struct ICOMSysLCEVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICOMSysLCE_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICOMSysLCE_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICOMSysLCE_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICOMSysLCE_GetEventType(This,e)	\
    ( (This)->lpVtbl -> GetEventType(This,e) ) 

#define ICOMSysLCE_GetEventClass(This,guid)	\
    ( (This)->lpVtbl -> GetEventClass(This,guid) ) 

#define ICOMSysLCE_Install(This,PropertyName,PropertyValue)	\
    ( (This)->lpVtbl -> Install(This,PropertyName,PropertyValue) ) 

#define ICOMSysLCE_Uninstall(This)	\
    ( (This)->lpVtbl -> Uninstall(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICOMSysLCE_INTERFACE_DEFINED__ */



#ifndef __COMSPYCTLLib_LIBRARY_DEFINED__
#define __COMSPYCTLLib_LIBRARY_DEFINED__

/* library COMSPYCTLLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_COMSPYCTLLib;

EXTERN_C const CLSID CLSID_ComSpy;

#ifdef __cplusplus

class DECLSPEC_UUID("A9B39081-AAD0-11D0-B183-00AA00BA3258")
ComSpy;
#endif

EXTERN_C const CLSID CLSID_ComSpyPropPage;

#ifdef __cplusplus

class DECLSPEC_UUID("AAF6270D-AC5E-11D0-B185-00AA00BA3258")
ComSpyPropPage;
#endif
#endif /* __COMSPYCTLLib_LIBRARY_DEFINED__ */

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


