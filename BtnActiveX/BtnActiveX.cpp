// BtnActiveX.cpp : CBtnActiveXApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "BtnActiveX.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CBtnActiveXApp theApp;

const GUID CDECL _tlid = { 0xCC9D93A9, 0x5C6A, 0x47DD, { 0x89, 0xFB, 0xA3, 0x24, 0xBC, 0xC7, 0xBF, 0x4 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CBtnActiveXApp::InitInstance - DLL ��ʼ��

BOOL CBtnActiveXApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CBtnActiveXApp::ExitInstance - DLL ��ֹ

int CBtnActiveXApp::ExitInstance()
{
	// TODO: �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
