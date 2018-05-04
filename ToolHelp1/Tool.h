// Tool.h : CTool ������

#pragma once
#include "resource.h"       // ������



#include "ToolHelp1_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
