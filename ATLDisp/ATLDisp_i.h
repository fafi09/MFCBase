

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Thu Apr 26 17:26:46 2018
 */
/* Compiler settings for ATLDisp.idl:
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

#ifndef __ATLDisp_i_h__
#define __ATLDisp_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFruit_FWD_DEFINED__
#define __IFruit_FWD_DEFINED__
typedef interface IFruit IFruit;
#endif 	/* __IFruit_FWD_DEFINED__ */


#ifndef __Fruit_FWD_DEFINED__
#define __Fruit_FWD_DEFINED__

#ifdef __cplusplus
typedef class Fruit Fruit;
#else
typedef struct Fruit Fruit;
#endif /* __cplusplus */

#endif 	/* __Fruit_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IFruit_INTERFACE_DEFINED__
#define __IFruit_INTERFACE_DEFINED__

/* interface IFruit */
/* [unique][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IFruit;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CD49CD3A-CCB7-4681-980F-9516F18DB67D")
    IFruit : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Add( 
            long nAdd1,
            long nAdd2,
            long *pnAdd) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_eye( 
            /* [retval][out] */ LONG *pVal) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_eye( 
            /* [in] */ LONG newVal) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowMsg( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFruitVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFruit * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFruit * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFruit * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IFruit * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IFruit * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IFruit * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IFruit * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Add )( 
            IFruit * This,
            long nAdd1,
            long nAdd2,
            long *pnAdd);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_eye )( 
            IFruit * This,
            /* [retval][out] */ LONG *pVal);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_eye )( 
            IFruit * This,
            /* [in] */ LONG newVal);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE *ShowMsg )( 
            IFruit * This);
        
        END_INTERFACE
    } IFruitVtbl;

    interface IFruit
    {
        CONST_VTBL struct IFruitVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFruit_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IFruit_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IFruit_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IFruit_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define IFruit_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define IFruit_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define IFruit_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 


#define IFruit_Add(This,nAdd1,nAdd2,pnAdd)	\
    ( (This)->lpVtbl -> Add(This,nAdd1,nAdd2,pnAdd) ) 

#define IFruit_get_eye(This,pVal)	\
    ( (This)->lpVtbl -> get_eye(This,pVal) ) 

#define IFruit_put_eye(This,newVal)	\
    ( (This)->lpVtbl -> put_eye(This,newVal) ) 

#define IFruit_ShowMsg(This)	\
    ( (This)->lpVtbl -> ShowMsg(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IFruit_INTERFACE_DEFINED__ */



#ifndef __ATLDispLib_LIBRARY_DEFINED__
#define __ATLDispLib_LIBRARY_DEFINED__

/* library ATLDispLib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ATLDispLib;

EXTERN_C const CLSID CLSID_Fruit;

#ifdef __cplusplus

class DECLSPEC_UUID("922557BC-F6BD-4958-9D91-116783987236")
Fruit;
#endif
#endif /* __ATLDispLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


