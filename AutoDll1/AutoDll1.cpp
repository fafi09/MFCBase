// AutoDll1.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "AutoDll1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//
//TODO: ����� DLL ����� MFC DLL �Ƕ�̬���ӵģ�
//		��Ӵ� DLL �������κε���
//		MFC �ĺ������뽫 AFX_MANAGE_STATE ����ӵ�
//		�ú�������ǰ�档
//
//		����:
//
//		extern "C" BOOL PASCAL EXPORT ExportedFunction()
//		{
//			AFX_MANAGE_STATE(AfxGetStaticModuleState());
//			// �˴�Ϊ��ͨ������
//		}
//
//		�˺������κ� MFC ����
//		������ÿ��������ʮ����Ҫ������ζ��
//		��������Ϊ�����еĵ�һ�����
//		���֣������������ж������������
//		������Ϊ���ǵĹ��캯���������� MFC
//		DLL ���á�
//
//		�й�������ϸ��Ϣ��
//		����� MFC ����˵�� 33 �� 58��
//

// CAutoDll1App

BEGIN_MESSAGE_MAP(CAutoDll1App, CWinApp)
END_MESSAGE_MAP()


// CAutoDll1App ����

CAutoDll1App::CAutoDll1App()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CAutoDll1App ����

CAutoDll1App theApp;

const GUID CDECL _tlid = { 0x5858C220, 0xB062, 0x44EA, { 0x9A, 0x34, 0x98, 0xFA, 0x2A, 0x1E, 0xEF, 0x3 } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;


// CAutoDll1App ��ʼ��

BOOL CAutoDll1App::InitInstance()
{
	CWinApp::InitInstance();

	// ������ OLE ������(����)ע��Ϊ���С��⽫ʹ
	//  OLE ����Դ�����Ӧ�ó��򴴽�����
	COleObjectFactory::RegisterAll();

	return TRUE;
}

// DllGetClassObject - �����๤��

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllGetClassObject(rclsid, riid, ppv);
}


// DllCanUnloadNow - ���� COM ж�� DLL

STDAPI DllCanUnloadNow(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	return AfxDllCanUnloadNow();
}


// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll())
		return SELFREG_E_CLASS;

	return S_OK;
}


// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;

	return S_OK;
}
