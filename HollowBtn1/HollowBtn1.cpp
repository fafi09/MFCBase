// HollowBtn1.cpp : CHollowBtn1App �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "HollowBtn1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CHollowBtn1App theApp;

const GUID CDECL _tlid = { 0xAE444F3D, 0x3863, 0x44B7, { 0xB2, 0xE, 0x7, 0x8B, 0xA4, 0x43, 0x1F, 0x93 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CHollowBtn1App::InitInstance - DLL ��ʼ��

BOOL CHollowBtn1App::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO: �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CHollowBtn1App::ExitInstance - DLL ��ֹ

int CHollowBtn1App::ExitInstance()
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
