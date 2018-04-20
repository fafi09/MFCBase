// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
#include "ImpMath.h"
#include "math_i.c"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

IUnknown* CreateInstance()
{
	CImpMath* pMath = new CImpMath;
	IUnknown* piUnknown = NULL;
	pMath->QueryInterface(IID_IUnknown, (LPVOID*)&piUnknown);

	return piUnknown;
}

IUnknown* CreateInstanceEx(CLSID clsId)
{
	if(clsId == CLSID_Math)
	{
		CImpMath* pMath = new CImpMath;
		IUnknown* piUnknown = NULL;
		pMath->QueryInterface(IID_IUnknown, (LPVOID*)&piUnknown);
		return piUnknown;
	}
	return NULL;
}