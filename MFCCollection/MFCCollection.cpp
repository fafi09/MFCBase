// MFCCollection.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MFCCollection.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp theApp;
using namespace std;

class CAnimal : public CObject
{
public:
	CAnimal( int nLeg = 4 );
	CAnimal( CAnimal& src );
public:
	void Print( ) { printf("leg = %d\n", m_nLeg); }
	CAnimal& operator= (CAnimal& src);
public:
	int m_nLeg;
};

CAnimal::CAnimal( int nLeg )
{
	m_nLeg = nLeg;
}

CAnimal::CAnimal( CAnimal& src )
{
	m_nLeg = src.m_nLeg;
}

CAnimal& CAnimal::operator=( CAnimal& src)
{
	m_nLeg = src.m_nLeg;
	return (*this);
}

void Array( )
{
	//定义整型数组
	CArray<int, int> arInt;
	arInt.Add( 10 );
	printf("size:%d Array[0] = %d\n", arInt.GetSize(), arInt.GetAt(0));

	//定义动物数组
	CArray<CAnimal, CAnimal&> arAnimal;

	//添加元素 add函数的参数为CAnimal&
	arAnimal.Add(CAnimal(3));
	arAnimal.Add(CAnimal(4));
	arAnimal.Add(CAnimal(5));

	//获取数据
	arAnimal[0].Print();
	CAnimal& animal = arAnimal.ElementAt(1);
	animal.Print( );
	CAnimal& animal1 = arAnimal.GetAt(2);
	animal1.Print( );

	CArray<CAnimal, CAnimal&> arAnimal1;
	arAnimal1.SetSize(10);
	printf("arAnimal1 size : %d\n", arAnimal1.GetSize());
	printf("arAnimal1 UpperBound: %d\n", arAnimal1.GetUpperBound());
	arAnimal1.SetAt(0, CAnimal(6));
	arAnimal1[1] = CAnimal(7);
	arAnimal1[0].Print( );
	arAnimal1[1].Print( );
	//删除全部数据
	arAnimal1.RemoveAll( );

	//定义指针类型的数组
	CArray<CAnimal*, CAnimal*> arAnimal2;
	arAnimal2.Add( new CAnimal(8) );
	arAnimal2[0]->Print( );
	//删除元素
	delete arAnimal2[0];
	//删除全部数据
	arAnimal2.RemoveAll( );

}

void StringArray( )
{
	CStringArray arString;
	arString.Add(TEXT("test1"));
	arString.Add(TEXT("test2"));

	cout<<arString[0]<<" "<<arString[1]<<endl;

	CString cstr = arString[0];
	
	printf("cstr = %d\n", cstr.GetLength());
}

void List( )
{
	//定义链表
	CList<CAnimal*, CAnimal*> plstAnimal;
	CList<CAnimal, CAnimal&> lstAnimal;

	lstAnimal.AddTail( CAnimal(9) );
	lstAnimal.AddTail( CAnimal(10) );
	lstAnimal.AddTail( CAnimal(11) );

	//遍历
	POSITION pos = lstAnimal.GetHeadPosition();
	while(pos != NULL)
	{
		CAnimal animal = lstAnimal.GetNext(pos);
		animal.Print( );
	}

	//查找
	pos = lstAnimal.FindIndex(1);
	CAnimal& animal = lstAnimal.GetAt(pos);
	animal.Print();

}

void StringMap( )
{
	CMapStringToString mpString;
	mpString.SetAt(TEXT("ATL"), TEXT("HELLO ATL"));
	mpString.SetAt(TEXT("WTL"), TEXT("HELLO WTL"));
	mpString.SetAt(TEXT("MFC"), TEXT("HELLO MFC"));

	CString strValue;
	mpString.Lookup(TEXT("WTL"),strValue);

	wprintf(TEXT("mapstr=%s\n"),(LPCTSTR)strValue);

}

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
	printf("===========CArray=============\n");
	Array( );
	printf("===========CStringArray=======\n");
	StringArray( );

	printf("===========CList==============\n");
	List( );

	printf("===========CMapStringToString\n");
	StringMap( );
	getch();
	return nRetCode;
}
