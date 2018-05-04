

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0555 */
/* at Fri May 04 16:05:46 2018
 */
/* Compiler settings for ToolHelp1.idl:
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

#ifndef __ToolHelp1_i_h__
#define __ToolHelp1_i_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IProcess_FWD_DEFINED__
#define __IProcess_FWD_DEFINED__
typedef interface IProcess IProcess;
#endif 	/* __IProcess_FWD_DEFINED__ */


#ifndef __IThread_FWD_DEFINED__
#define __IThread_FWD_DEFINED__
typedef interface IThread IThread;
#endif 	/* __IThread_FWD_DEFINED__ */


#ifndef __Tool_FWD_DEFINED__
#define __Tool_FWD_DEFINED__

#ifdef __cplusplus
typedef class Tool Tool;
#else
typedef struct Tool Tool;
#endif /* __cplusplus */

#endif 	/* __Tool_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IProcess_INTERFACE_DEFINED__
#define __IProcess_INTERFACE_DEFINED__

/* interface IProcess */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IProcess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01200AF2-B27C-4521-ADF8-35BF9C64CA1F")
    IProcess : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ProcessSnapshot( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ProcessFirst( 
            LONG *pnID,
            BYTE *pszName) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ProcessNext( 
            LONG *pnID,
            BYTE *pszName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IProcessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IProcess * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IProcess * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IProcess * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ProcessSnapshot )( 
            IProcess * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ProcessFirst )( 
            IProcess * This,
            LONG *pnID,
            BYTE *pszName);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ProcessNext )( 
            IProcess * This,
            LONG *pnID,
            BYTE *pszName);
        
        END_INTERFACE
    } IProcessVtbl;

    interface IProcess
    {
        CONST_VTBL struct IProcessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IProcess_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IProcess_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IProcess_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IProcess_ProcessSnapshot(This)	\
    ( (This)->lpVtbl -> ProcessSnapshot(This) ) 

#define IProcess_ProcessFirst(This,pnID,pszName)	\
    ( (This)->lpVtbl -> ProcessFirst(This,pnID,pszName) ) 

#define IProcess_ProcessNext(This,pnID,pszName)	\
    ( (This)->lpVtbl -> ProcessNext(This,pnID,pszName) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IProcess_INTERFACE_DEFINED__ */


#ifndef __IThread_INTERFACE_DEFINED__
#define __IThread_INTERFACE_DEFINED__

/* interface IThread */
/* [unique][uuid][object] */ 


EXTERN_C const IID IID_IThread;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3AF65A2D-66CB-4E37-8A22-7EC4676363A0")
    IThread : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ThreadSnapshot( void) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ThreadFirst( 
            LONG *pnID,
            LONG *pnProcID) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE ThreadNext( 
            LONG *pnID,
            LONG *pnProcID) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IThreadVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IThread * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            __RPC__deref_out  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IThread * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IThread * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ThreadSnapshot )( 
            IThread * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ThreadFirst )( 
            IThread * This,
            LONG *pnID,
            LONG *pnProcID);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *ThreadNext )( 
            IThread * This,
            LONG *pnID,
            LONG *pnProcID);
        
        END_INTERFACE
    } IThreadVtbl;

    interface IThread
    {
        CONST_VTBL struct IThreadVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IThread_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IThread_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IThread_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IThread_ThreadSnapshot(This)	\
    ( (This)->lpVtbl -> ThreadSnapshot(This) ) 

#define IThread_ThreadFirst(This,pnID,pnProcID)	\
    ( (This)->lpVtbl -> ThreadFirst(This,pnID,pnProcID) ) 

#define IThread_ThreadNext(This,pnID,pnProcID)	\
    ( (This)->lpVtbl -> ThreadNext(This,pnID,pnProcID) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IThread_INTERFACE_DEFINED__ */



#ifndef __ToolHelp1Lib_LIBRARY_DEFINED__
#define __ToolHelp1Lib_LIBRARY_DEFINED__

/* library ToolHelp1Lib */
/* [version][uuid] */ 


EXTERN_C const IID LIBID_ToolHelp1Lib;

EXTERN_C const CLSID CLSID_Tool;

#ifdef __cplusplus

class DECLSPEC_UUID("7D7C1337-ABBA-4819-8948-0BA28FB92168")
Tool;
#endif
#endif /* __ToolHelp1Lib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


