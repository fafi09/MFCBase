

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Sat Apr 28 15:09:42 2018
 */
/* Compiler settings for BtnActiveX.idl:
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


#ifndef __BtnActiveXidl_h__
#define __BtnActiveXidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DBtnActiveX_FWD_DEFINED__
#define ___DBtnActiveX_FWD_DEFINED__
typedef interface _DBtnActiveX _DBtnActiveX;
#endif 	/* ___DBtnActiveX_FWD_DEFINED__ */


#ifndef ___DBtnActiveXEvents_FWD_DEFINED__
#define ___DBtnActiveXEvents_FWD_DEFINED__
typedef interface _DBtnActiveXEvents _DBtnActiveXEvents;
#endif 	/* ___DBtnActiveXEvents_FWD_DEFINED__ */


#ifndef __BtnActiveX_FWD_DEFINED__
#define __BtnActiveX_FWD_DEFINED__

#ifdef __cplusplus
typedef class BtnActiveX BtnActiveX;
#else
typedef struct BtnActiveX BtnActiveX;
#endif /* __cplusplus */

#endif 	/* __BtnActiveX_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __BtnActiveXLib_LIBRARY_DEFINED__
#define __BtnActiveXLib_LIBRARY_DEFINED__

/* library BtnActiveXLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_BtnActiveXLib;

#ifndef ___DBtnActiveX_DISPINTERFACE_DEFINED__
#define ___DBtnActiveX_DISPINTERFACE_DEFINED__

/* dispinterface _DBtnActiveX */
/* [uuid] */ 


EXTERN_C const IID DIID__DBtnActiveX;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("84AADE30-6172-4082-9BDE-81DF5A356D05")
    _DBtnActiveX : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DBtnActiveXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DBtnActiveX * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DBtnActiveX * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DBtnActiveX * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DBtnActiveX * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DBtnActiveX * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DBtnActiveX * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DBtnActiveX * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DBtnActiveXVtbl;

    interface _DBtnActiveX
    {
        CONST_VTBL struct _DBtnActiveXVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DBtnActiveX_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DBtnActiveX_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DBtnActiveX_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DBtnActiveX_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DBtnActiveX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DBtnActiveX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DBtnActiveX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DBtnActiveX_DISPINTERFACE_DEFINED__ */


#ifndef ___DBtnActiveXEvents_DISPINTERFACE_DEFINED__
#define ___DBtnActiveXEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DBtnActiveXEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DBtnActiveXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("EDA4C9AC-6883-4D73-82D8-C596B59A8232")
    _DBtnActiveXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DBtnActiveXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DBtnActiveXEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DBtnActiveXEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DBtnActiveXEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DBtnActiveXEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DBtnActiveXEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DBtnActiveXEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DBtnActiveXEvents * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _DBtnActiveXEventsVtbl;

    interface _DBtnActiveXEvents
    {
        CONST_VTBL struct _DBtnActiveXEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DBtnActiveXEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DBtnActiveXEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DBtnActiveXEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DBtnActiveXEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DBtnActiveXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DBtnActiveXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DBtnActiveXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DBtnActiveXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_BtnActiveX;

#ifdef __cplusplus

class DECLSPEC_UUID("A0A55F2E-2C98-4D8B-8E29-700A303D71B7")
BtnActiveX;
#endif
#endif /* __BtnActiveXLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


