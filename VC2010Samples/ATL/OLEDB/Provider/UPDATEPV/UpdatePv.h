

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Mon Jan 18 19:14:07 2038
 */
/* Compiler settings for UpdatePv.idl:
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


#ifndef __UpdatePv_h__
#define __UpdatePv_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __UpProv_FWD_DEFINED__
#define __UpProv_FWD_DEFINED__

#ifdef __cplusplus
typedef class UpProv UpProv;
#else
typedef struct UpProv UpProv;
#endif /* __cplusplus */

#endif 	/* __UpProv_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __UPDATEPVLib_LIBRARY_DEFINED__
#define __UPDATEPVLib_LIBRARY_DEFINED__

/* library UPDATEPVLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_UPDATEPVLib;

EXTERN_C const CLSID CLSID_UpProv;

#ifdef __cplusplus

class DECLSPEC_UUID("90C57963-C443-11D1-8F0F-0060083E4509")
UpProv;
#endif
#endif /* __UPDATEPVLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


