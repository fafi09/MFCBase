// HollowBtn1.cpp : CHollowBtn1App 和 DLL 注册的实现。

#include "stdafx.h"
#include "HollowBtn1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CHollowBtn1App theApp;

const GUID CDECL _tlid = { 0xAE444F3D, 0x3863, 0x44B7, { 0xB2, 0xE, 0x7, 0x8B, 0xA4, 0x43, 0x1F, 0x93 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CHollowBtn1App::InitInstance - DLL 初始化

BOOL CHollowBtn1App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CHollowBtn1App::ExitInstance - DLL 终止

int CHollowBtn1App::ExitInstance()
{
	// TODO: 在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
