// MFCSerialize.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <afxwin.h>
#include <conio.h>

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
	store();
	load();

	getch();
	return 0;
}

