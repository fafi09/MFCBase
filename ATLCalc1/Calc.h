// Calc.h : CCalc ������

#pragma once
#include "resource.h"       // ������



#include "ATLCalc1_i.h"



#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Windows CE ƽ̨(�粻�ṩ��ȫ DCOM ֧�ֵ� Windows Mobile ƽ̨)���޷���ȷ֧�ֵ��߳� COM ���󡣶��� _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA ��ǿ�� ATL ֧�ִ������߳� COM ����ʵ�ֲ�����ʹ���䵥�߳� COM ����ʵ�֡�rgs �ļ��е��߳�ģ���ѱ�����Ϊ��Free����ԭ���Ǹ�ģ���Ƿ� DCOM Windows CE ƽ̨֧�ֵ�Ψһ�߳�ģ�͡�"
#endif

using namespace ATL;


// CCalc

class ATL_NO_VTABLE CCalc :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCalc, &CLSID_Calc>,
	public ICalc
{
public:
	CCalc()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CALC)


BEGIN_COM_MAP(CCalc)
	COM_INTERFACE_ENTRY(ICalc)
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




	
	STDMETHOD(Sub)(LONG nSub1, LONG nSub2, LONG* pnSub);
	STDMETHOD(Add)(long nAdd1, long nAdd2, long* pnAdd);
};

OBJECT_ENTRY_AUTO(__uuidof(Calc), CCalc)
