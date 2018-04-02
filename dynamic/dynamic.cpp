// dynamic.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "dynamic.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp theApp;

using namespace std;

class CAnimal : public CObject
{
public:
	CAnimal( );
	int m_nleg;

	DECLARE_DYNAMIC( CAnimal )
};

IMPLEMENT_DYNAMIC( CAnimal, CObject )

CAnimal::CAnimal( )
{
	m_nleg = 4;
}

class CDog : public CAnimal
{
public:
	DECLARE_DYNAMIC( CDog )
};

IMPLEMENT_DYNAMIC( CDog, CAnimal )

void PrintAnimal( CObject* pObject )
{
	if( pObject->IsKindOf( RUNTIME_CLASS(CDog)))
	{
		CDog* pDog = (CDog*)pObject;
		cout << pDog->m_nleg <<	endl;
	}
	if( pObject->GetRuntimeClass()->IsDerivedFrom(RUNTIME_CLASS(CAnimal))) 
	{
		cout << "derived from" <<endl;
	}
}

void Print( )
{
	CAnimal animal;
	CDog dog;
	CWnd wnd;
	PrintAnimal( &animal );
	PrintAnimal( &dog );
	PrintAnimal( &wnd );
}

// Ψһ��Ӧ�ó������


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
