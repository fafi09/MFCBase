// MFCFile.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <afxwin.h>

void Create( )
{
	CFile file;
	if(FALSE == file.Open(TEXT("d:\\mfctext.txt"),CFile::modeCreate))
	{
		printf("file create fail\n");
	}
	file.Close();
}

void Data( )
{
	CFile file;
	if(FALSE == file.Open(TEXT("d:\\mfctext.txt"),CFile::modeReadWrite))
	{
		printf("file open fail\n");
	}

	try
	{
		//写数据
		CHAR szText[] = "hELLO MFC";
		file.Write(szText, sizeof(szText));
		file.Flush();
		//文件指针
		file.Seek(0, CFile::begin);
		CHAR szBuf[100] = {0};
		file.Read(szBuf, 100);
		printf("%s\n",szBuf);

	}
	catch (CMemoryException* e)
	{
		e->ReportError();
	}
	catch (CFileException* e)
	{
		e->ReportError();
	}
	catch (CException* e)
	{
		e->ReportError();
	}
	file.Close();
}

void Status( )
{
	//获取文件信息
	CFileStatus status;
	CFile::GetStatus(TEXT("d:\\mfctext.txt"), status);
	CString strTime = status.m_ctime.Format("%Y-%m-%d %H:%M:%S");
	printf("file size:%d\n", status.m_size);
	wprintf(TEXT("file name:%s\n"),status.m_szFullName);
	wprintf(TEXT("create time:%s\n"), strTime);

	//设置文件属性
	CTimeSpan span(1,0,0,0);
	status.m_ctime = status.m_ctime + span;
	CFile::SetStatus(TEXT("d:\\mfctext.txt"), status);
}


void Find( )
{
	CFileFind finder;
	BOOL bWorking = finder.FindFile(TEXT("D:\\barcode\\*.*"));
	while(bWorking)
	{
		bWorking = finder.FindNextFile();
		CString strName = finder.GetFileName( );
		if(finder.IsDots())
		{
			wprintf(TEXT("[%s]\n"),strName);
		}
		else if(finder.IsDirectory())
		{
			wprintf(TEXT("+[%s]\n"),strName);
		}
		else
		{
			wprintf(TEXT("%s\n"),strName);
		}

	}
	finder.Close();
}

int _tmain(int argc, _TCHAR* argv[])
{
	Create();
	Data();
	Status();
	Find();
	getch();
	return 0;
}

