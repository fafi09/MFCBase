// dynamic.cpp : 定义控制台应用程序的入口点。
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

// 唯一的应用程序对象


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。
		}
	}
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	Print( );
	return nRetCode;
}
