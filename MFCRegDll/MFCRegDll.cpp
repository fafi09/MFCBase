// MFCRegDll.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "stdafx.h"
#include "MFCRegDll.h"

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

// CMFCRegDllApp

BEGIN_MESSAGE_MAP(CMFCRegDllApp, CWinApp)
END_MESSAGE_MAP()


// CMFCRegDllApp ����

CMFCRegDllApp::CMFCRegDllApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CMFCRegDllApp ����

CMFCRegDllApp theApp;


// CMFCRegDllApp ��ʼ��

BOOL CMFCRegDllApp::InitInstance()
{
	CWinApp::InitInstance();

	return TRUE;
}

#include "RegDlg.h"

void ShowDlg()
{
	/*
	��DLL�У�
	MFC������Դ����Ҫ��ȡ��ԴHINSTANCEʱ��
	Ĭ�ϻ��õ�ǰEXE��HINSTANCE�����ԣ�
	�����EXE��HINSTANCE�У�����DLL
	��Դ��ID�������ʧ�ܻ��߻�ȡ�����
	��Դ���ݡ�
	��ˣ���Ҫ��DLL�ĺ�����ʼ������

	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	�����ǽ���ǰ��Ĭ����ԴHINSTANCE����
	ԭ����EXE�滻Ϊ��ǰ����DLL��HINSTANCE��
	*/
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	RegDlg dlg;
	dlg.DoModal();

}