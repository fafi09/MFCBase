// MFCSerialize.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <afxwin.h>
#include <conio.h>

class CAnimal : public CObject
{
public:
	CAnimal( int nLeg = 4 ) { m_nLegs = nLeg; }
	int m_nLegs;
	int m_nEyes;
	DECLARE_SERIAL( CAnimal )
	/*_DECLARE_DYNCREATE(CAnimal)
		AFX_API friend CArchive& AFXAPI operator>>(CArchive& ar, CAnimal* &pOb);*/
public:
	virtual void Serialize(CArchive& ar);
};

IMPLEMENT_SERIAL( CAnimal, CObject, VERSIONABLE_SCHEMA | 2 )

//CObject* PASCAL CAnimal::CreateObject()
//{ 
//	return new CAnimal; 
//}
//
//extern AFX_CLASSINIT _init_CAnimal;
//
//_IMPLEMENT_RUNTIMECLASS(CAnimal, CObject, 2,
//	CAnimal::CreateObject, &_init_CAnimal)
//
//AFX_CLASSINIT _init_CAnimal(RUNTIME_CLASS(CAnimal));
//
//CArchive& AFXAPI operator>>(CArchive& ar, CAnimal* &pOb)
//{ 
//	pOb = (CAnimal*) ar.ReadObject(RUNTIME_CLASS(CAnimal));
//	return ar; 
//}

void CAnimal::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	UINT nSchema = ar.GetObjectSchema();

	printf("load=%d, nSchema=%d\n", ar.IsLoading(), nSchema);

	if(ar.IsLoading())
	{
		ar>>m_nLegs;
		ar>>m_nEyes;
	}
	else
	{
		ar<<m_nLegs;
		ar<<m_nEyes;
	}
}


void StoreArray( )
{
	CObArray arAnimal;
	for(int i = 0; i < 10; i++)
	{
		arAnimal.Add( new CAnimal(i) );
	}
	CFile file;
	if( FALSE == file.Open(TEXT("d:\\arObj.dat"), CFile::modeCreate | CFile::modeWrite))
	{
		printf("open file fail\n");
		return;
	}

	CArchive ar(&file, CArchive::store);

	ar << &arAnimal;

	ar.Close();
	file.Close();
}

void LoadArray( )
{
	CFile file;
	if( FALSE == file.Open(TEXT("d:\\arObj.dat"), CFile::modeRead))
	{
		printf("open file fail\n");
		return;
	}

	CArchive ar(&file, CArchive::load);
	
	CObArray* arAnimal = NULL;
	ar >> arAnimal;

	ar.Close();
	file.Close();

	int nSize = arAnimal->GetSize();
	printf("coarray size:%d\n", nSize);
	for(int i = 0; i < nSize; i++ )
	{
		CAnimal* animal = (CAnimal*)arAnimal->GetAt(i);
		printf("animal %d leg: %d\n", i, animal->m_nLegs);
	}
}


void StoreObject()
{
	CFile file;
	if( FALSE == file.Open(TEXT("d:\\animal.dat"), CFile::modeCreate | CFile::modeWrite))
	{
		printf("open file fail\n");
		return;
	}

	CArchive ar(&file, CArchive::store);

	//调用内部函数
	/*CAnimal animal(2);
	animal.Serialize(ar);*/

	/*CAnimal* animal = new CAnimal(5);
	ar << animal;*/

	CAnimal animal(6);
	ar << &animal;

	ar.Close();
	file.Close();
}

void LoadObject()
{
	CFile file;
	if( FALSE == file.Open(TEXT("d:\\animal.dat"), CFile::modeRead))
	{
		printf("open file fail\n");
		return;
	}
	
	CArchive ar(&file, CArchive::load);

	//调用内部函数
	/*CAnimal animal;
	animal.Serialize(ar);*/

	CAnimal* animal = NULL;
	ar >> animal;

	ar.Close();
	file.Close();

	//printf("leg=%d\n",animal.m_nLegs);
	printf("leg=%d\n",animal->m_nLegs);
}

void store( )
{
	CFile file;
	if( FALSE == file.Open(TEXT("d:\\serial.dat"),CFile::modeCreate | CFile::modeWrite))
	{
		printf("file open fail\n");
		return;
	}
	DWORD nNum = 120;
	BYTE nNum2 = 10;
	//CHAR szText[] = "hello archive";
	CString szText("hello archive");

	CArchive ar(&file, CArchive::store);
	ar<<nNum;
	ar<<szText;
	ar<<nNum2;

	ar.Close();
	file.Close();
}

void load( )
{
	CFile file;
	if( FALSE == file.Open(TEXT("d:\\serial.dat"), CFile::modeRead))
	{
		printf("file open fail\n");
		return;
	}
	DWORD nNum;
	BYTE nNum2= 0;
	CString szText;
	
	try
	{
		CArchive ar(&file, CArchive::load);
		ar>>nNum;
		ar>>szText;
		ar>>nNum2;
		ar.Close();
	}
	catch (CArchiveException* e)
	{
		if(e->m_cause == CArchiveException::endOfFile)
		{
			printf("CArchiveException::endOfFile\n");
		}
		e->ReportError();
	}
	catch (CMemoryException* e)
	{
		
	}
	catch (CFileException* e)
	{
	}
	catch (CException* e)
	{
	}
	

	printf("%d %d\n", nNum, nNum2);
	wprintf(TEXT("%s\n"), (LPCTSTR)szText);

	
	file.Close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	//store();
	//load();

	//StoreObject();
	//LoadObject();

	StoreArray();
	LoadArray();

	getch();
	return 0;
}

