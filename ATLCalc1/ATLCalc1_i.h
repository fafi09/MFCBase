

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Apr 26 17:26:11 2018
 */
/* Compiler settings for ATLCalc1.idl:
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

#ifndef __ATLCalc1_i_h__
#define __ATLCalc1_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ICalc_FWD_DEFINED__
#define __ICalc_FWD_DEFINED__
typedef interface ICalc ICalc;
#endif 	/* __ICalc_FWD_DEFINED__ */


#ifndef __Calc_FWD_DEFINED__
#define __Calc_FWD_DEFINED__

#ifdef __cplusplus
typedef class Calc Calc;
#else
typedef struct Calc Calc;
#endif /* __cplusplus */

#endif 	/* __Calc_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __ICalc_INTERFACE_DEFINED__
#define __ICalc_INTERFACE_DEFINED__

/* interface ICalc */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_ICalc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("088136F6-E5F9-4F57-BAF1-3B3BAE6C1B7B")
    ICalc : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Sub( 
            /* [in] */ LONG nSub1,
            /* [in] */ LONG nSub2,
            /* [out] */ LONG *pnSub) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE Add( 
            long nAdd1,
            long nAdd2,
            long *pnAdd) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICalcVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ICalc * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ICalc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ICalc * This);
        
        HRESULT ( STDMETHODCALLTYPE *Sub )( 
            ICalc * This,
            /* [in] */ LONG nSub1,
            /* [in] */ LONG nSub2,
            /* [out] */ LONG *pnSub);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            ICalc * This,
            long nAdd1,
            long nAdd2,
            long *pnAdd);
        
        END_INTERFACE
    } ICalcVtbl;

    interface ICalc
    {
        CONST_VTBL struct ICalcVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICalc_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define ICalc_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define ICalc_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define ICalc_Sub(This,nSub1,nSub2,pnSub)	\
    ( (This)->lpVtbl -> Sub(This,nSub1,nSub2,pnSub) ) 

#define ICalc_Add(This,nAdd1,nAdd2,pnAdd)	\
    ( (This)->lpVtbl -> Add(This,nAdd1,nAdd2,pnAdd) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __ICalc_INTERFACE_DEFINED__ */



#ifndef __ATLCalc1Lib_LIBRARY_DEFINED__
#define __ATLCalc1Lib_LIBRARY_DEFINED__

/* library ATLCalc1Lib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLCalc1Lib;

EXTERN_C const CLSID CLSID_Calc;

#ifdef __cplusplus

class DECLSPEC_UUID("EF2739AC-79AA-4384-AD92-7EEB0F1326C0")
Calc;
#endif
#endif /* __ATLCalc1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


