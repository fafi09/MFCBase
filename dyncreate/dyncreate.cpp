// dyncreate.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "dyncreate.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ψһ��Ӧ�ó������

CWinApp theApp;

using namespace std;

class CAnimal : public CObject
{
public:
	int m_nleg;
	DECLARE_DYNCREATE( CAnimal )
};

IMPLEMENT_DYNCREATE( CAnimal, CObject )

CObject* Factory( CRuntimeClass* pClass )
{
	return pClass->CreateObject( );
}

void Print( )
{
	CAnimal* pAnimal = (CAnimal*)Factory( RUNTIME_CLASS( CAnimal ) );
	cout << pAnimal->m_nleg << endl;
}
int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// ��ʼ�� MFC ����ʧ��ʱ��ʾ����
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: ���Ĵ�������Է���������Ҫ
			_tprintf(_T("����: MFC ��ʼ��ʧ��\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: �ڴ˴�ΪӦ�ó������Ϊ��д���롣
		}
	}
	else
	{
		// TODO: ���Ĵ�������Է���������Ҫ
		_tprintf(_T("����: GetModuleHandle ʧ��\n"));
		nRetCode = 1;
	}

	Print( );

	return nRetCode;
}
