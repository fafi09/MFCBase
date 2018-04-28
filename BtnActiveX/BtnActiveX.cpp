// BtnActiveX.cpp : CBtnActiveXApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "BtnActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CBtnActiveXApp theApp;

const GUID CDECL _tlid = { 0xCC9D93A9, 0x5C6A, 0x47DD, { 0x89, 0xFB, 0xA3, 0x24, 0xBC, 0xC7, 0xBF, 0x4 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CBtnActiveXApp::InitInstance - DLL 初始化

BOOL CBtnActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: 在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CBtnActiveXApp::ExitInstance - DLL 终止

int CBtnActiveXApp::ExitInstance()
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
