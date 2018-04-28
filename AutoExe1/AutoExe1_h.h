

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Apr 28 08:48:08 2018
 */
/* Compiler settings for AutoExe1.idl:
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


#ifndef __AutoExe1_h_h__
#define __AutoExe1_h_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IAutoExe1_FWD_DEFINED__
#define __IAutoExe1_FWD_DEFINED__
typedef interface IAutoExe1 IAutoExe1;
#endif 	/* __IAutoExe1_FWD_DEFINED__ */


#ifndef __CAutoExe1Doc_FWD_DEFINED__
#define __CAutoExe1Doc_FWD_DEFINED__

#ifdef __cplusplus
typedef class CAutoExe1Doc CAutoExe1Doc;
#else
typedef struct CAutoExe1Doc CAutoExe1Doc;
#endif /* __cplusplus */

#endif 	/* __CAutoExe1Doc_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __AutoExe1_LIBRARY_DEFINED__
#define __AutoExe1_LIBRARY_DEFINED__

/* library AutoExe1 */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_AutoExe1;

#ifndef __IAutoExe1_DISPINTERFACE_DEFINED__
#define __IAutoExe1_DISPINTERFACE_DEFINED__

/* dispinterface IAutoExe1 */
/* [uuid] */ 


EXTERN_C const IID DIID_IAutoExe1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("ED925030-AE8A-4FEC-B775-EFFA64A325CF")
    IAutoExe1 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IAutoExe1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IAutoExe1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IAutoExe1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IAutoExe1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IAutoExe1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IAutoExe1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IAutoExe1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IAutoExe1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } IAutoExe1Vtbl;

    interface IAutoExe1
    {
        CONST_VTBL struct IAutoExe1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IAutoExe1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IAutoExe1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IAutoExe1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IAutoExe1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IAutoExe1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IAutoExe1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IAutoExe1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IAutoExe1_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_CAutoExe1Doc;

#ifdef __cplusplus

class DECLSPEC_UUID("68B5C7A5-7407-4C06-A50F-6809CB0026EC")
CAutoExe1Doc;
#endif
#endif /* __AutoExe1_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


