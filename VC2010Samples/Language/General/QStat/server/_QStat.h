

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for _QStat.idl:
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

#ifndef ___QStat_h__
#define ___QStat_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMeanCalc_FWD_DEFINED__
#define __IMeanCalc_FWD_DEFINED__
typedef interface IMeanCalc IMeanCalc;

#endif 	/* __IMeanCalc_FWD_DEFINED__ */


#ifndef __CMeanCalc_FWD_DEFINED__
#define __CMeanCalc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMeanCalc CMeanCalc;
#else
typedef struct CMeanCalc CMeanCalc;
#endif /* __cplusplus */

#endif 	/* __CMeanCalc_FWD_DEFINED__ */


/* header files for imported files */
#include "prsht.h"
#include "MsHTML.h"
#include "MsHtmHst.h"
#include "ExDisp.h"
#include "ObjSafe.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMeanCalc_INTERFACE_DEFINED__
#define __IMeanCalc_INTERFACE_DEFINED__

/* interface IMeanCalc */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IMeanCalc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9AD3BE25-ABF9-4D0B-BC56-4219FC79BBF8")
    IMeanCalc : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ short nMaxEntries) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Clear( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddDataPoint( 
            /* [in] */ short i) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ArithmeticMean( 
            /* [retval][out] */ double *pArithmeticMean) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GeometricMean( 
            /* [retval][out] */ double *pGeometricMean) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HarmonicMean( 
            /* [retval][out] */ double *pHarmonicMean) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE QuadraticMean( 
            /* [retval][out] */ double *pQuadraticMean) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IMeanCalcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMeanCalc * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMeanCalc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMeanCalc * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IMeanCalc * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IMeanCalc * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IMeanCalc * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IMeanCalc * This,
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
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IMeanCalc * This,
            /* [in] */ short nMaxEntries);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Clear )( 
            IMeanCalc * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *AddDataPoint )( 
            IMeanCalc * This,
            /* [in] */ short i);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ArithmeticMean )( 
            IMeanCalc * This,
            /* [retval][out] */ double *pArithmeticMean);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GeometricMean )( 
            IMeanCalc * This,
            /* [retval][out] */ double *pGeometricMean);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *HarmonicMean )( 
            IMeanCalc * This,
            /* [retval][out] */ double *pHarmonicMean);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *QuadraticMean )( 
            IMeanCalc * This,
            /* [retval][out] */ double *pQuadraticMean);
        
        END_INTERFACE
    } IMeanCalcVtbl;

    interface IMeanCalc
    {
        CONST_VTBL struct IMeanCalcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMeanCalc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMeanCalc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMeanCalc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMeanCalc_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IMeanCalc_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IMeanCalc_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IMeanCalc_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IMeanCalc_Initialize(This,nMaxEntries)	\
    ( (This)->lpVtbl -> Initialize(This,nMaxEntries) ) 

#define IMeanCalc_Clear(This)	\
    ( (This)->lpVtbl -> Clear(This) ) 

#define IMeanCalc_AddDataPoint(This,i)	\
    ( (This)->lpVtbl -> AddDataPoint(This,i) ) 

#define IMeanCalc_ArithmeticMean(This,pArithmeticMean)	\
    ( (This)->lpVtbl -> ArithmeticMean(This,pArithmeticMean) ) 

#define IMeanCalc_GeometricMean(This,pGeometricMean)	\
    ( (This)->lpVtbl -> GeometricMean(This,pGeometricMean) ) 

#define IMeanCalc_HarmonicMean(This,pHarmonicMean)	\
    ( (This)->lpVtbl -> HarmonicMean(This,pHarmonicMean) ) 

#define IMeanCalc_QuadraticMean(This,pQuadraticMean)	\
    ( (This)->lpVtbl -> QuadraticMean(This,pQuadraticMean) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMeanCalc_INTERFACE_DEFINED__ */



#ifndef __QStat_LIBRARY_DEFINED__
#define __QStat_LIBRARY_DEFINED__

/* library QStat */
/* [helpstring][uuid][version] */ 


EXTERN_C const IID LIBID_QStat;

EXTERN_C const CLSID CLSID_CMeanCalc;

#ifdef __cplusplus

class DECLSPEC_UUID("5B8E7812-8AF8-4EC3-A559-5C5011597C6B")
CMeanCalc;
#endif
#endif /* __QStat_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


