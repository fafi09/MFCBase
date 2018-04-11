// MFCCollection.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MFCCollection.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif

//////////////////////////
//可以定位到发生内存泄露 所在的文件和具体那一行，用于检测 malloc 分配的内存
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>

//把分配内存的信息保存下来，可以定位到那一行发生了内存泄露。用于检测 new 分配的内存
#ifdef _DEBUG
//#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

//有用
inline void EnableMemLeakCheck()
{
	//该语句在程序退出时自动调用 _CrtDumpMemoryLeaks(),用于多个退出出口的情况.
	//如果只有一个退出位置，可以在程序退出之前调用 _CrtDumpMemoryLeaks()
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG) | _CRTDBG_LEAK_CHECK_DF);
}
//////////////////////////


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
	//删除全部数据 不delete可导致内存泄漏
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

void ObjectMap( )
{
	//定义map
	CMap<int, int, CAnimal, CAnimal&> mapIntToAnimal;

	mapIntToAnimal.InitHashTable(101);

	printf("map count : %d\n",mapIntToAnimal.GetCount());
	printf("map size : %d\n",mapIntToAnimal.GetSize());

	//添加元素
	mapIntToAnimal.SetAt(10, CAnimal(12));
	mapIntToAnimal[11] = CAnimal(13);

	//查找
	CAnimal animal10;
	mapIntToAnimal.Lookup(10, animal10);
	animal10.Print( );
	CAnimal animal11 = mapIntToAnimal[11];
	animal11.Print( );

	//遍历
	POSITION pos = mapIntToAnimal.GetStartPosition( );
	int key;
	CAnimal value;
	while(pos != NULL)
	{
		mapIntToAnimal.GetNextAssoc(pos, key, value);
		printf("key=%d, leg=%d\n", key, value.m_nLeg);
	}

	//获取数量
	printf("map count : %d\n",mapIntToAnimal.GetCount());
	printf("map size : %d\n",mapIntToAnimal.GetSize());

	//删除元素
	mapIntToAnimal.RemoveKey(10);

	printf("map count : %d\n",mapIntToAnimal.GetCount());
	printf("map size : %d\n",mapIntToAnimal.GetSize());

	//删除全部
	mapIntToAnimal.RemoveAll();

	if(mapIntToAnimal.IsEmpty())
	{
		printf("map is empty\n");
	}

	//new对象注意释放
	CMap<int, int, CAnimal*, CAnimal*> mapIntToAnimal2;
	mapIntToAnimal2.SetAt(0, new CAnimal(14));
	delete mapIntToAnimal2[0];
	printf("map count : %d\n",mapIntToAnimal2.GetCount());
	printf("map size : %d\n",mapIntToAnimal2.GetSize());
	mapIntToAnimal2.RemoveAll( ); //会产生内存泄漏
	printf("map count : %d\n",mapIntToAnimal2.GetCount());
	printf("map size : %d\n",mapIntToAnimal2.GetSize());
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	//检测内存泄漏
	EnableMemLeakCheck();
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

	printf("===========CMap==============\n");
	ObjectMap( );
	getch();
	return nRetCode;
}
