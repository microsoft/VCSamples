

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for atlduck.idl:
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

#ifndef __atlduck_h__
#define __atlduck_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDuckDoer_FWD_DEFINED__
#define __IDuckDoer_FWD_DEFINED__
typedef interface IDuckDoer IDuckDoer;

#endif 	/* __IDuckDoer_FWD_DEFINED__ */


#ifndef __DuckDoer_FWD_DEFINED__
#define __DuckDoer_FWD_DEFINED__

#ifdef __cplusplus
typedef class DuckDoer DuckDoer;
#else
typedef struct DuckDoer DuckDoer;
#endif /* __cplusplus */

#endif 	/* __DuckDoer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IDuckDoer_INTERFACE_DEFINED__
#define __IDuckDoer_INTERFACE_DEFINED__

/* interface IDuckDoer */
/* [object][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_IDuckDoer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("120B729F-65BF-11D0-9DDC-00A0C9034892")
    IDuckDoer : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IDuckDoerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDuckDoer * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDuckDoer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDuckDoer * This);
        
        END_INTERFACE
    } IDuckDoerVtbl;

    interface IDuckDoer
    {
        CONST_VTBL struct IDuckDoerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDuckDoer_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IDuckDoer_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IDuckDoer_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDuckDoer_INTERFACE_DEFINED__ */



#ifndef __ATLDUCKLib_LIBRARY_DEFINED__
#define __ATLDUCKLib_LIBRARY_DEFINED__

/* library ATLDUCKLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ATLDUCKLib;

EXTERN_C const CLSID CLSID_DuckDoer;

#ifdef __cplusplus

class DECLSPEC_UUID("120B72A0-65BF-11D0-9DDC-00A0C9034892")
DuckDoer;
#endif
#endif /* __ATLDUCKLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


