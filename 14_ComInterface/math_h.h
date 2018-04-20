

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri Apr 20 22:43:14 2018
 */
/* Compiler settings for math.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 7.00.0555 
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

#ifndef __math_h_h__
#define __math_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IMath_FWD_DEFINED__
#define __IMath_FWD_DEFINED__
typedef interface IMath IMath;
#endif 	/* __IMath_FWD_DEFINED__ */


#ifndef __Math_FWD_DEFINED__
#define __Math_FWD_DEFINED__

#ifdef __cplusplus
typedef class Math Math;
#else
typedef struct Math Math;
#endif /* __cplusplus */

#endif 	/* __Math_FWD_DEFINED__ */


/* header files for imported files */
#include "objidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IMath_INTERFACE_DEFINED__
#define __IMath_INTERFACE_DEFINED__

/* interface IMath */
/* [uuid][object] */ 


EXTERN_C const IID IID_IMath;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("22C468C2-F5FA-499B-827A-9C0B5B9A0A56")
    IMath : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Add( 
            long nAdd1,
            long nAdd2,
            long *pnAdd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Sub( 
            long nSub1,
            long nSub2,
            long *pnSub) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMathVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMath * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMath * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMath * This);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IMath * This,
            long nAdd1,
            long nAdd2,
            long *pnAdd);
        
        HRESULT ( STDMETHODCALLTYPE *Sub )( 
            IMath * This,
            long nSub1,
            long nSub2,
            long *pnSub);
        
        END_INTERFACE
    } IMathVtbl;

    interface IMath
    {
        CONST_VTBL struct IMathVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMath_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IMath_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IMath_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IMath_Add(This,nAdd1,nAdd2,pnAdd)	\
    ( (This)->lpVtbl -> Add(This,nAdd1,nAdd2,pnAdd) ) 

#define IMath_Sub(This,nSub1,nSub2,pnSub)	\
    ( (This)->lpVtbl -> Sub(This,nSub1,nSub2,pnSub) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IMath_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


