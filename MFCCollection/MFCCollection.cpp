// MFCCollection.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//ɾ��ȫ������
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
