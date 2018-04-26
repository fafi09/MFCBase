// Fruit.h : CFruit 的声明

#pragma once
#include "resource.h"       // 主符号



#include "ATLDisp_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CFruit

class ATL_NO_VTABLE CFruit :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CFruit, &CLSID_Fruit>,
	public IDispatchImpl<IFruit, &IID_IFruit, &LIBID_ATLDispLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CFruit()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_FRUIT)


BEGIN_COM_MAP(CFruit)
	COM_INTERFACE_ENTRY(IFruit)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

public:



	STDMETHOD(Add)(long nAdd1, long nAdd2, long* pnAdd);
	STDMETHOD(get_eye)(LONG* pVal);
	STDMETHOD(put_eye)(LONG newVal);
	STDMETHOD(ShowMsg)(void);
public:
	LONG m_nEye;
};

OBJECT_ENTRY_AUTO(__uuidof(Fruit), CFruit)
