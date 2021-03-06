// Tool.h : CTool 的声明

#pragma once
#include "resource.h"       // 主符号



#include "ToolHelp1_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE 平台(如不提供完全 DCOM 支持的 Windows Mobile 平台)上无法正确支持单线程 COM 对象。定义 _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA 可强制 ATL 支持创建单线程 COM 对象实现并允许使用其单线程 COM 对象实现。rgs 文件中的线程模型已被设置为“Free”，原因是该模型是非 DCOM Windows CE 平台支持的唯一线程模型。"
#endif

using namespace ATL;


// CTool

class ATL_NO_VTABLE CTool :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CTool, &CLSID_Tool>,
	public IProcess,
	public IThread
{
public:
	CTool()
	{
		m_hProcess = NULL;
		m_hThread = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_TOOL)


BEGIN_COM_MAP(CTool)
	COM_INTERFACE_ENTRY(IProcess)
	COM_INTERFACE_ENTRY(IThread)
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



	STDMETHOD(ProcessSnapshot)(void);
	STDMETHOD(ProcessFirst)(LONG* pnID, BYTE* pszName);
	STDMETHOD(ProcessNext)(LONG* pnID, BYTE* pszName);
	STDMETHOD(ThreadSnapshot)(void);
	STDMETHOD(ThreadFirst)(LONG* pnID, LONG* pnProcID);
	STDMETHOD(ThreadNext)(LONG* pnID, LONG* pnProcID);
	HANDLE m_hProcess;
	HANDLE m_hThread;
};

OBJECT_ENTRY_AUTO(__uuidof(Tool), CTool)
