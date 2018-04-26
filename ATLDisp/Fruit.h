// Fruit.h : CFruit ������

#pragma once
#include "resource.h"       // ������



#include "ATLDisp_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
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
