// MFCCollection.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MFCCollection.h"

//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif

//////////////////////////
//���Զ�λ�������ڴ�й¶ ���ڵ��ļ��;�����һ�У����ڼ�� malloc ������ڴ�
#define _CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>

//�ѷ����ڴ����Ϣ�������������Զ�λ����һ�з������ڴ�й¶�����ڼ�� new ������ڴ�
#ifdef _DEBUG
//#define new   new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define new DEBUG_NEW
#endif

//����
inline void EnableMemLeakCheck()
{
	//������ڳ����˳�ʱ�Զ����� _CrtDumpMemoryLeaks(),���ڶ���˳����ڵ����.
	//���ֻ��һ���˳�λ�ã������ڳ����˳�֮ǰ���� _CrtDumpMemoryLeaks()
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
	//������������
	CArray<int, int> arInt;
	arInt.Add( 10 );
	printf("size:%d Array[0] = %d\n", arInt.GetSize(), arInt.GetAt(0));

	//���嶯������
	CArray<CAnimal, CAnimal&> arAnimal;

	//���Ԫ�� add�����Ĳ���ΪCAnimal&
	arAnimal.Add(CAnimal(3));
	arAnimal.Add(CAnimal(4));
	arAnimal.Add(CAnimal(5));

	//��ȡ����
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
	//ɾ��ȫ������
	arAnimal1.RemoveAll( );

	//����ָ�����͵�����
	CArray<CAnimal*, CAnimal*> arAnimal2;
	arAnimal2.Add( new CAnimal(8) );
	arAnimal2[0]->Print( );
	//ɾ��Ԫ��
	delete arAnimal2[0];
	//ɾ��ȫ������ ��delete�ɵ����ڴ�й©
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
	//��������
	CList<CAnimal*, CAnimal*> plstAnimal;
	CList<CAnimal, CAnimal&> lstAnimal;

	lstAnimal.AddTail( CAnimal(9) );
	lstAnimal.AddTail( CAnimal(10) );
	lstAnimal.AddTail( CAnimal(11) );

	//����
	POSITION pos = lstAnimal.GetHeadPosition();
	while(pos != NULL)
	{
		CAnimal animal = lstAnimal.GetNext(pos);
		animal.Print( );
	}

	//����
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
	//����map
	CMap<int, int, CAnimal, CAnimal&> mapIntToAnimal;

	mapIntToAnimal.InitHashTable(101);

	printf("map count : %d\n",mapIntToAnimal.GetCount());
	printf("map size : %d\n",mapIntToAnimal.GetSize());

	//���Ԫ��
	mapIntToAnimal.SetAt(10, CAnimal(12));
	mapIntToAnimal[11] = CAnimal(13);

	//����
	CAnimal animal10;
	mapIntToAnimal.Lookup(10, animal10);
	animal10.Print( );
	CAnimal animal11 = mapIntToAnimal[11];
	animal11.Print( );

	//����
	POSITION pos = mapIntToAnimal.GetStartPosition( );
	int key;
	CAnimal value;
	while(pos != NULL)
	{
		mapIntToAnimal.GetNextAssoc(pos, key, value);
		printf("key=%d, leg=%d\n", key, value.m_nLeg);
	}

	//��ȡ����
	printf("map count : %d\n",mapIntToAnimal.GetCount());
	printf("map size : %d\n",mapIntToAnimal.GetSize());

	//ɾ��Ԫ��
	mapIntToAnimal.RemoveKey(10);

	printf("map count : %d\n",mapIntToAnimal.GetCount());
	printf("map size : %d\n",mapIntToAnimal.GetSize());

	//ɾ��ȫ��
	mapIntToAnimal.RemoveAll();

	if(mapIntToAnimal.IsEmpty())
	{
		printf("map is empty\n");
	}

	//new����ע���ͷ�
	CMap<int, int, CAnimal*, CAnimal*> mapIntToAnimal2;
	mapIntToAnimal2.SetAt(0, new CAnimal(14));
	delete mapIntToAnimal2[0];
	printf("map count : %d\n",mapIntToAnimal2.GetCount());
	printf("map size : %d\n",mapIntToAnimal2.GetSize());
	mapIntToAnimal2.RemoveAll( ); //������ڴ�й©
	printf("map count : %d\n",mapIntToAnimal2.GetCount());
	printf("map size : %d\n",mapIntToAnimal2.GetSize());
}

int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	//����ڴ�й©
	EnableMemLeakCheck();
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
