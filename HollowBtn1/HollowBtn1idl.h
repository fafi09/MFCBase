

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri May 04 13:58:55 2018
 */
/* Compiler settings for HollowBtn1.idl:
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


#ifndef __HollowBtn1idl_h__
#define __HollowBtn1idl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DHollowBtn1_FWD_DEFINED__
#define ___DHollowBtn1_FWD_DEFINED__
typedef interface _DHollowBtn1 _DHollowBtn1;
#endif 	/* ___DHollowBtn1_FWD_DEFINED__ */


#ifndef ___DHollowBtn1Events_FWD_DEFINED__
#define ___DHollowBtn1Events_FWD_DEFINED__
typedef interface _DHollowBtn1Events _DHollowBtn1Events;
#endif 	/* ___DHollowBtn1Events_FWD_DEFINED__ */


#ifndef __HollowBtn1_FWD_DEFINED__
#define __HollowBtn1_FWD_DEFINED__

#ifdef __cplusplus
typedef class HollowBtn1 HollowBtn1;
#else
typedef struct HollowBtn1 HollowBtn1;
#endif /* __cplusplus */

#endif 	/* __HollowBtn1_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __HollowBtn1Lib_LIBRARY_DEFINED__
#define __HollowBtn1Lib_LIBRARY_DEFINED__

/* library HollowBtn1Lib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_HollowBtn1Lib;

#ifndef ___DHollowBtn1_DISPINTERFACE_DEFINED__
#define ___DHollowBtn1_DISPINTERFACE_DEFINED__

/* dispinterface _DHollowBtn1 */
/* [uuid] */ 


EXTERN_C const IID DIID__DHollowBtn1;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("661B853F-8E12-4F9E-A369-1BAF99CC5326")
    _DHollowBtn1 : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DHollowBtn1Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DHollowBtn1 * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DHollowBtn1 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DHollowBtn1 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DHollowBtn1 * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DHollowBtn1 * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DHollowBtn1 * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DHollowBtn1 * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DHollowBtn1Vtbl;

    interface _DHollowBtn1
    {
        CONST_VTBL struct _DHollowBtn1Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DHollowBtn1_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DHollowBtn1_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DHollowBtn1_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DHollowBtn1_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DHollowBtn1_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DHollowBtn1_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DHollowBtn1_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DHollowBtn1_DISPINTERFACE_DEFINED__ */


#ifndef ___DHollowBtn1Events_DISPINTERFACE_DEFINED__
#define ___DHollowBtn1Events_DISPINTERFACE_DEFINED__

/* dispinterface _DHollowBtn1Events */
/* [uuid] */ 


EXTERN_C const IID DIID__DHollowBtn1Events;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("232480A8-C14C-44DA-99E9-066AA2DF415E")
    _DHollowBtn1Events : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DHollowBtn1EventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DHollowBtn1Events * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DHollowBtn1Events * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DHollowBtn1Events * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DHollowBtn1Events * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DHollowBtn1Events * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DHollowBtn1Events * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DHollowBtn1Events * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DHollowBtn1EventsVtbl;

    interface _DHollowBtn1Events
    {
        CONST_VTBL struct _DHollowBtn1EventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DHollowBtn1Events_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DHollowBtn1Events_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DHollowBtn1Events_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DHollowBtn1Events_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DHollowBtn1Events_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DHollowBtn1Events_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DHollowBtn1Events_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DHollowBtn1Events_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_HollowBtn1;

#ifdef __cplusplus

class DECLSPEC_UUID("C304FC76-C811-4745-BD11-B89E999690EB")
HollowBtn1;
#endif
#endif /* __HollowBtn1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


