

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for _GameHistory.idl:
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

#ifndef ___GameHistory_h__
#define ___GameHistory_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHistory_FWD_DEFINED__
#define __IHistory_FWD_DEFINED__
typedef interface IHistory IHistory;

#endif 	/* __IHistory_FWD_DEFINED__ */


#ifndef __CGameHistory_FWD_DEFINED__
#define __CGameHistory_FWD_DEFINED__

#ifdef __cplusplus
typedef class CGameHistory CGameHistory;
#else
typedef struct CGameHistory CGameHistory;
#endif /* __cplusplus */

#endif 	/* __CGameHistory_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf__GameHistory_0000_0000 */
/* [local] */ 

typedef 
enum eDirection
    {
        eError	= 0,
        eLeft	= 1,
        eRight	= 2,
        eUp	= 3,
        eDown	= 4
    } 	eDirection;



extern RPC_IF_HANDLE __MIDL_itf__GameHistory_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf__GameHistory_0000_0000_v0_0_s_ifspec;

#ifndef __IHistory_INTERFACE_DEFINED__
#define __IHistory_INTERFACE_DEFINED__

/* interface IHistory */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID_IHistory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5C4ED402-0272-3008-8692-DA7A7EFC9D03")
    IHistory : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Test( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [retval][out] */ int *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitGame( 
            /* [in] */ BSTR boardstate,
            /* [in] */ int cols,
            /* [in] */ int rows) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PushMove( 
            /* [in] */ eDirection dir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PopMove( 
            /* [retval][out] */ eDirection *dir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RedoMove( 
            /* [retval][out] */ eDirection *dir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CanUndo( 
            /* [retval][out] */ boolean *yes_no) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CanRedo( 
            /* [retval][out] */ boolean *yes_no) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SaveGame( 
            /* [in] */ BSTR gamename,
            /* [in] */ BSTR boardstate) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LoadSavedGame( 
            /* [in] */ BSTR gamename,
            /* [out] */ BSTR *boardstate,
            /* [out] */ int *cols,
            /* [out] */ int *rows) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Test2( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [out] */ int *retval) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PopMove2( 
            /* [out] */ eDirection *dir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RedoMove2( 
            /* [out] */ eDirection *dir) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CanUndo2( 
            /* [out] */ boolean *yes_no) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CanRedo2( 
            /* [out] */ boolean *yes_no) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IHistoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHistory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHistory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHistory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IHistory * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IHistory * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IHistory * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IHistory * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Test )( 
            IHistory * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [retval][out] */ int *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *InitGame )( 
            IHistory * This,
            /* [in] */ BSTR boardstate,
            /* [in] */ int cols,
            /* [in] */ int rows);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PushMove )( 
            IHistory * This,
            /* [in] */ eDirection dir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PopMove )( 
            IHistory * This,
            /* [retval][out] */ eDirection *dir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RedoMove )( 
            IHistory * This,
            /* [retval][out] */ eDirection *dir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CanUndo )( 
            IHistory * This,
            /* [retval][out] */ boolean *yes_no);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CanRedo )( 
            IHistory * This,
            /* [retval][out] */ boolean *yes_no);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SaveGame )( 
            IHistory * This,
            /* [in] */ BSTR gamename,
            /* [in] */ BSTR boardstate);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LoadSavedGame )( 
            IHistory * This,
            /* [in] */ BSTR gamename,
            /* [out] */ BSTR *boardstate,
            /* [out] */ int *cols,
            /* [out] */ int *rows);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Test2 )( 
            IHistory * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [out] */ int *retval);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *PopMove2 )( 
            IHistory * This,
            /* [out] */ eDirection *dir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *RedoMove2 )( 
            IHistory * This,
            /* [out] */ eDirection *dir);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CanUndo2 )( 
            IHistory * This,
            /* [out] */ boolean *yes_no);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CanRedo2 )( 
            IHistory * This,
            /* [out] */ boolean *yes_no);
        
        END_INTERFACE
    } IHistoryVtbl;

    interface IHistory
    {
        CONST_VTBL struct IHistoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHistory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IHistory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IHistory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IHistory_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IHistory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IHistory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IHistory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IHistory_Test(This,x,y,retval)	\
    ( (This)->lpVtbl -> Test(This,x,y,retval) ) 

#define IHistory_InitGame(This,boardstate,cols,rows)	\
    ( (This)->lpVtbl -> InitGame(This,boardstate,cols,rows) ) 

#define IHistory_PushMove(This,dir)	\
    ( (This)->lpVtbl -> PushMove(This,dir) ) 

#define IHistory_PopMove(This,dir)	\
    ( (This)->lpVtbl -> PopMove(This,dir) ) 

#define IHistory_RedoMove(This,dir)	\
    ( (This)->lpVtbl -> RedoMove(This,dir) ) 

#define IHistory_CanUndo(This,yes_no)	\
    ( (This)->lpVtbl -> CanUndo(This,yes_no) ) 

#define IHistory_CanRedo(This,yes_no)	\
    ( (This)->lpVtbl -> CanRedo(This,yes_no) ) 

#define IHistory_SaveGame(This,gamename,boardstate)	\
    ( (This)->lpVtbl -> SaveGame(This,gamename,boardstate) ) 

#define IHistory_LoadSavedGame(This,gamename,boardstate,cols,rows)	\
    ( (This)->lpVtbl -> LoadSavedGame(This,gamename,boardstate,cols,rows) ) 

#define IHistory_Test2(This,x,y,retval)	\
    ( (This)->lpVtbl -> Test2(This,x,y,retval) ) 

#define IHistory_PopMove2(This,dir)	\
    ( (This)->lpVtbl -> PopMove2(This,dir) ) 

#define IHistory_RedoMove2(This,dir)	\
    ( (This)->lpVtbl -> RedoMove2(This,dir) ) 

#define IHistory_CanUndo2(This,yes_no)	\
    ( (This)->lpVtbl -> CanUndo2(This,yes_no) ) 

#define IHistory_CanRedo2(This,yes_no)	\
    ( (This)->lpVtbl -> CanRedo2(This,yes_no) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IHistory_INTERFACE_DEFINED__ */



#ifndef __GameHistory_LIBRARY_DEFINED__
#define __GameHistory_LIBRARY_DEFINED__

/* library GameHistory */
/* [uuid][helpstring][version] */ 


EXTERN_C const IID LIBID_GameHistory;

EXTERN_C const CLSID CLSID_CGameHistory;

#ifdef __cplusplus

class DECLSPEC_UUID("89694E8B-8B57-3F94-B4DA-3E933154A9E4")
CGameHistory;
#endif
#endif /* __GameHistory_LIBRARY_DEFINED__ */

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


