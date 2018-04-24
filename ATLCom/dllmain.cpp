// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "math.h"
#include "atlcom_i.c"


////增加类厂实现 添加用于组件的管理的变量
BEGIN_OBJECT_MAP(objectmap)
	OBJECT_ENTRY(CLSID_ComObj, CMath)
END_OBJECT_MAP()

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		_Module.Init(objectmap,NULL,NULL);
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

IUnknown* MyCreateInstance()
{
	IUnknown* piiUnknown = NULL;

	CComObject<CMath>* pMath = NULL;

	CComObject<CMath>::CreateInstance(&pMath);

	pMath->QueryInterface(IID_IUnknown,(void**)&piiUnknown);
	return piiUnknown;
}

IUnknown* MyCreateInstance2(CLSID clsid)
{
	IUnknown* piiUnknown = NULL;
	IClassFactory* piiClassFactory = NULL;

	_Module.GetClassObject(clsid, IID_IClassFactory, (LPVOID*)&piiClassFactory);

	piiClassFactory->CreateInstance(NULL, IID_IUnknown, (LPVOID*)&piiUnknown);

	return piiUnknown;
}